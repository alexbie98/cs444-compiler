#include "CodeGeneration.h"

#include <unordered_map>
#include <iostream>
#include <set>

void CodeGenerator::createMethodAndFieldPrefixes(ClassDeclaration* class_decl)
{
    if(class_infos.find(class_decl) == class_infos.end())
    {
        class_infos.insert({class_decl, ClassInfo()});
        ClassInfo& class_info = class_infos[class_decl];

        // If class extends another class, ensure its method and field prefixes are defined, then copy its method and field prefixes
        if(class_decl->baseClass)
        {
            ClassDeclaration* baseClass = dynamic_cast<ClassDeclaration*>(class_decl->baseClass);
            assert(baseClass);
            createMethodAndFieldPrefixes(baseClass);

            class_info.methods_prefix = class_infos[baseClass].methods_prefix;
            class_info.fields_prefix = class_infos[baseClass].fields_prefix;

            if(class_decl->containedConcreteMethods)
            {
                for(auto member_it: *class_decl->containedConcreteMethods)
                {
                    MethodDeclaration* method = member_it.second;
                    assert(method);
                    
                    if(class_info.methods_prefix.find(method->getSignature()) != class_info.methods_prefix.end())
                    {
                        // Replace existing method in method prefix, so index remains the same
                        method_prefix_indices[method] = class_info.methods_prefix[method->getSignature()].second;
                        class_info.methods_prefix[method->getSignature()].first = method;
                    }
                    else
                    {
                        // Add new method to method prefix
                        size_t index = class_info.methods_prefix.size();
                        method_prefix_indices[method] = index;
                        class_info.methods_prefix[method->getSignature()] = {method, index};
                    }
                }
            }
        }
        else
        {
            if(class_decl->containedConcreteMethods)
            {
                for(auto member_it: *class_decl->containedConcreteMethods)
                {
                    MethodDeclaration* method = member_it.second;
                    assert(method);
                    
                    // Add new method to method prefix
                    size_t index = class_info.methods_prefix.size();
                    method_prefix_indices[method] = index;
                    class_info.methods_prefix[method->getSignature()] = {method, index};
                }
            }
        }

        // Add new fields to field prefix
        for(MemberDeclaration* member: class_decl->classBody->elements)
        {
            FieldDeclaration* field = dynamic_cast<FieldDeclaration*>(member);
            if(field)
            {
                // Add new method to method prefix
                size_t index = class_info.fields_prefix.size();
                field_prefix_indices[field] = index;
                class_info.fields_prefix[field->declaration->name->getString()] = {field, index};
            }
        }
    }
}

void CodeGenerator::createSubtypeInfo(ClassDeclaration* class_decl, TypeDeclaration* subtype)
{
    if(subtype == nullptr) return;

    ClassDeclaration* class_subtype = dynamic_cast<ClassDeclaration*>(subtype);
    subtype_table[getObjectSubtypeIndex(class_decl)][getObjectSubtypeIndex(subtype)] = true;
    subtype_table[getArraySubtypeIndex(class_decl)][getArraySubtypeIndex(subtype)] = true;

    if(class_subtype)
    {
        createSubtypeInfo(class_decl, class_subtype->baseClass);
    }

    for(InterfaceDeclaration* interface: *subtype->interfaces)
    {
        createSubtypeInfo(class_decl, interface);
    } 
}

CodeGenerator::CodeGenerator(Environment& globalEnv): global_env{globalEnv}
{
    // Generate SIT indices
    std::unordered_map<std::string, size_t> unique_method_signatures;
    for(auto it: globalEnv.interfaces)
    {
        for(MemberDeclaration* member: it.second->interfaceBody->elements)
        {
            MethodDeclaration* method = dynamic_cast<MethodDeclaration*>(member);
            assert(method);
            if(unique_method_signatures.find(method->getSignature()) == unique_method_signatures.end())
            {
                unique_method_signatures[method->getSignature()] = sit_column_size;
                sit_column_size++;
            }
        }
    }

    // All interfaces implicitly define abstract versions of Object's methods
    assert(globalEnv.classes.find("java.lang.Object") != globalEnv.classes.end());
    object_class_decl = globalEnv.classes["java.lang.Object"];

    for(MemberDeclaration* member: object_class_decl->classBody->elements)
    {
        MethodDeclaration* method = dynamic_cast<MethodDeclaration*>(member);
        if(method && unique_method_signatures.find(method->getSignature()) == unique_method_signatures.end())
        {
            unique_method_signatures[method->getSignature()] = sit_column_size;
            sit_column_size++;
        }
    }

    // Add all methods that match an interface signature, regardless of whether they did in fact implement an interface method.
    // Type checking should have already not allowed an interface method access from a class that doesnt implement that interface.
    for(auto it: globalEnv.classes)
    {
        // Create empty SIT column
        sit_table[it.second] = std::vector<MethodDeclaration*>(sit_column_size, nullptr);

        if(it.second->containedConcreteMethods)
        {
            for(auto member_it: *it.second->containedConcreteMethods)
            {
                MethodDeclaration* method = dynamic_cast<MethodDeclaration*>(member_it.second);
                assert(method);

                if(unique_method_signatures.find(method->getSignature()) != unique_method_signatures.end())
                {
                    // If method is a plausable interface method, add to method -> index mapping and SIT table
                    size_t index = unique_method_signatures[method->getSignature()];
                    sit_indices[method] = index;
                    sit_table[it.second][index] = method;
                }
            }
        }
    }

    // Generate method prefix indices in initial ClassInfos
    for(auto it: globalEnv.classes)
    {
        createMethodAndFieldPrefixes(it.second);
    }

    // Generate subtype info
    for(auto it: globalEnv.classes)
    {
        subtype_table_object_index[it.second] = subtype_table_object_index.size();
    }
    for(auto it: globalEnv.interfaces)
    {
        subtype_table_object_index[it.second] = subtype_table_object_index.size();
    }
    // Make room for arrays with (* 2)
    // TODO Only make for arrays that are actually used?
    subtype_column_count = subtype_table_object_index.size() * 2;

    subtype_table_primitive_array_index[PrimitiveType::BYTE] = subtype_column_count++; 
    subtype_table_primitive_array_index[PrimitiveType::SHORT] = subtype_column_count++;
    subtype_table_primitive_array_index[PrimitiveType::INT] = subtype_column_count++;
    subtype_table_primitive_array_index[PrimitiveType::CHAR] = subtype_column_count++;
    subtype_table_primitive_array_index[PrimitiveType::BOOLEAN] = subtype_column_count++;

    for(size_t i = 0; i < subtype_column_count; i++)
    {
        // Allocate space in subtype_table_index
        subtype_table.push_back(std::vector<bool>(subtype_column_count, false));
    }

    for(auto it: globalEnv.classes)
    {
        createSubtypeInfo(it.second, it.second);
    }

    subtype_table[getPrimitiveArraySubtypeIndex(PrimitiveType::BYTE)][getPrimitiveArraySubtypeIndex(PrimitiveType::BYTE)] = true;

    for(PrimitiveType::BasicType t: std::vector<PrimitiveType::BasicType>{PrimitiveType::BYTE , PrimitiveType::SHORT, PrimitiveType::CHAR, PrimitiveType::INT})
    {
        subtype_table[getPrimitiveArraySubtypeIndex(t)][getPrimitiveArraySubtypeIndex(PrimitiveType::BYTE)] = true;
        subtype_table[getPrimitiveArraySubtypeIndex(t)][getPrimitiveArraySubtypeIndex(PrimitiveType::SHORT)] = true;
        subtype_table[getPrimitiveArraySubtypeIndex(t)][getPrimitiveArraySubtypeIndex(PrimitiveType::CHAR)] = true;
        subtype_table[getPrimitiveArraySubtypeIndex(t)][getPrimitiveArraySubtypeIndex(PrimitiveType::INT)] = true;
    }

    // Add subtype column index to each ClassInfo
    for(auto it: class_infos)
    {
        it.second.subtype_column = getObjectSubtypeIndex(it.first);
    }

    // Get static fields and methods
    for(auto it: globalEnv.classes)
    {
        for(MemberDeclaration* member: it.second->classBody->elements)
        {
            bool is_static = false;
            for(Modifier* modifier: member->modifiers->elements)
            {
                if(modifier->type == Modifier::ModifierType::STATIC) is_static = true;
            }

            if(is_static)
            {
                MethodDeclaration* method = dynamic_cast<MethodDeclaration*>(member);
                FieldDeclaration* field = dynamic_cast<FieldDeclaration*>(member);

                if(method)
                {
                    static_methods[method] = it.second;
                }
                else if(field)
                {
                    static_fields[field] = it.second;
                }
            }
        }
    }

    // Create array SIT columns
    // The interfaces java.io.Serializable and Cloneable are implemented by arrays
    // Since Serializable and Cloneable are empty, SIT column for all arrays is identical to Object's SIT column
    array_sit_column = sit_table[object_class_decl];
    
    // Create ClassInfos for object arrays
    for(auto it: globalEnv.classes)
    {
        ClassDeclaration* class_decl = it.second;
        array_class_infos.insert({class_decl, ClassInfo()});
        ClassInfo& class_info = array_class_infos[class_decl];

        class_info.subtype_column = getArraySubtypeIndex(class_decl);
        class_info.methods_prefix = class_infos[object_class_decl].methods_prefix;
        // Array prefixes will need the lenght and data fields added on during code gen
    }

    // Create ClassInfos for primitive arrays
    std::vector<PrimitiveType::BasicType> primitive_types = {PrimitiveType::BOOLEAN, PrimitiveType::BYTE , PrimitiveType::SHORT, PrimitiveType::CHAR, PrimitiveType::INT};
    for(PrimitiveType::BasicType t: primitive_types)
    {
        primitive_array_class_infos.insert({t, ClassInfo()});
        ClassInfo& class_info = primitive_array_class_infos[t];

        class_info.subtype_column = getPrimitiveArraySubtypeIndex(t);
        class_info.methods_prefix = class_infos[object_class_decl].methods_prefix;
    }
}

std::string CodeGenerator::generateCommon()
{
    std::string common_asm;

    common_asm += TEXT_DIR;

    common_asm += labelAsm(SUBTYPE_COLUMN_COUNT_LABEL);
    common_asm += wordAsm(subtype_column_count);

    common_asm += labelAsm(SUBTYPE_TABLE_LABEL);
    for(const std::vector<bool>& column: subtype_table)
    {
        for(bool b: column) 
        {
            common_asm += byteAsm(b);
        }

        common_asm += "\n";
    }

    return common_asm;
}

std::string CodeGenerator::generateObjectCode(ClassDeclaration* root, ObjectType otype, PrimitiveType::BasicType ptype)
{
    std::string class_asm;

    // TODO Change to defined_labels and make neccessary changes below
    std::set<std::string> externed_labels = {sitColumnClassLabel(object_class_decl)};

    std::vector<MethodDeclaration*>* column = nullptr;
    ClassInfo* class_info = nullptr;
    std::string column_label;
    std::string class_data_label;
    size_t subtype_index;

    if(root != object_class_decl) class_asm += externAsm(sitColumnClassLabel(object_class_decl));

    if(otype == ObjectType::OBJECT)
    {
        column_label = sitColumnClassLabel(root);
        column = &sit_table[root];
        class_info = &class_infos[root];
        class_data_label = classDataLabel(root);
        subtype_index = getObjectSubtypeIndex(root);
        class_asm += "\n" + commentAsm("================== OBJECT INFORMATION ==================");
    } 
    else if(otype == ObjectType::OBJECT_ARRAY)
    {
        column_label = sitColumnClassLabel(object_class_decl);
        column = &sit_table[object_class_decl];
        class_info = &array_class_infos[root];
        class_data_label = classArrayDataLabel(root);
        subtype_index = getArraySubtypeIndex(root);

        class_asm += "\n" + commentAsm("================== OBJECT ARRAY INFORMATION ==================");
    } 
    else if(otype == ObjectType::PRIMITIVE_ARRAY)
    {
        column_label = sitColumnClassLabel(object_class_decl);
        column = &sit_table[object_class_decl];
        class_info = &primitive_array_class_infos[ptype];
        class_data_label = primitiveArrayDataLabel(ptype);
        subtype_index = getPrimitiveArraySubtypeIndex(ptype);
        class_asm += "\n" + commentAsm("================== PRIMITIVE ARRAY INFORMATION ==================");
    } 
    else assert(false);

    // Generate SIT column if class
    if(otype == ObjectType::OBJECT) 
    {
        class_asm += labelAsm(column_label);

        for(MethodDeclaration* method: *column)
        {
            if(method)
            {
                if(containingType(method) != root && externed_labels.find(classMethodLabel(method)) == externed_labels.end())
                {
                    class_asm += externAsm(classMethodLabel(method));
                    externed_labels.insert(classMethodLabel(method));
                }
                class_asm += wordAsm(classMethodLabel(method));
            }
            else
            {
                class_asm += wordAsm(0);
            }
        }
    }

    class_asm += "\n";
    class_asm += externAsm(SUBTYPE_COLUMN_COUNT_LABEL);
    class_asm += externAsm(SUBTYPE_TABLE_LABEL);

    class_asm += labelAsm(class_data_label);
    class_asm += wordAsm(column_label);
    class_asm += wordAsm(subtype_index);

    size_t prefix_size = class_info->methods_prefix.size();
    std::vector<MethodDeclaration*> expanded_method_prefix(prefix_size, nullptr);
    for(auto it: class_info->methods_prefix)
    {
        assert(it.second.first);
        expanded_method_prefix[it.second.second] = it.second.first;
    }

    for(MethodDeclaration* method: expanded_method_prefix)
    {
        assert(method);
        if(containingType(method) != root && externed_labels.find(classMethodLabel(method)) == externed_labels.end())
        {
            class_asm += externAsm(classMethodLabel(method));
        }
        class_asm += wordAsm(classMethodLabel(method));
    }

    // Add entryType if object is an array
    if(otype == ObjectType::OBJECT_ARRAY)
    {
        class_asm += wordAsm(classDataLabel(root));
    } 
    else if(otype == ObjectType::PRIMITIVE_ARRAY)
    {
        class_asm += wordAsm(0);
    }

    // TEMP Define label for each method
    if(otype == ObjectType::OBJECT_ARRAY)
    {
        class_asm += "\n\n" + commentAsm("================== METHODS ==================");

        for(MemberDeclaration* member: root->classBody->elements)
        {
            MethodDeclaration* method = dynamic_cast<MethodDeclaration*>(member);
            if(method)
            {
                class_asm += globalAsm(classMethodLabel(method));
                class_asm += labelAsm(classMethodLabel(method));
            }
        }
    }

    return class_asm;
}

std::string CodeGenerator::generateClassCode(ClassDeclaration* root)
{
    return generateObjectCode(root, ObjectType::OBJECT) + "\n\n" + commentAsm("Object Array Information") + generateObjectCode(root, ObjectType::OBJECT_ARRAY);
}

std::string CodeGenerator::generatePrimitiveArrayCode(PrimitiveType::BasicType type)
{
    return generateObjectCode(0, ObjectType::PRIMITIVE_ARRAY, type);
}

void CodeGenerator::CodeGenVisitor::visit(MethodDeclaration& node)
{
    formalParameterCount = node.parameters->elements.size();
    thisOffset = (formalParameterCount + 2) * 4;
    localVariableCount = 0;
    inMethod = true;
}

void CodeGenerator::CodeGenVisitor::visit(ConstructorDeclaration& node)
{
    formalParameterCount = node.parameters->elements.size();
    thisOffset = (formalParameterCount + 2) * 4;
    localVariableCount = 0;
    inMethod = true;
}

void CodeGenerator::CodeGenVisitor::visit(FormalParameter& node)
{
    node.paramOffset = (formalParameterCount + 1) * 4;
    formalParameterCount--;
}

void CodeGenerator::CodeGenVisitor::visit(VariableDeclarationExpression& node)
{
    if (inMethod)
    {
        localVariableCount++;
        node.variableOffset = localVariableCount * -4;
    }
}

void CodeGenerator::CodeGenVisitor::leave(IntLiteral& node)
{
    node.code += "mov eax, " + std::to_string(node.value) + " " + comment("IntLiteral");
}

void CodeGenerator::CodeGenVisitor::leave(CharLiteral& node)
{
    node.code = "mov eax, " + std::to_string(node.value) + " " + comment("CharLiteral");
}

void CodeGenerator::CodeGenVisitor::leave(BooleanLiteral& node)
{
    node.code = "mov eax, ";
    
    if (node.value) node.code += '1';
    else node.code += '0';

    node.code += " " + comment("BooleanLiteral");
}

void CodeGenerator::CodeGenVisitor::leave(NullLiteral& node)
{
    node.code = "mov eax, 0 " + comment("NullLiteral");
}

void CodeGenerator::CodeGenVisitor::leave(NameExpression& node)
{
    if (node.name)
    {

    }
    else // node.field
    {
        node.addr = node.field->addr;
        node.code = node.field->code;
    }
}

void CodeGenerator::CodeGenVisitor::leave(BinaryOperation& node)
{
    node.code = comment("BinaryOperation Begin");

    switch (node.op)
    {
        case BinaryOperation::PLUS:
            // Numeric plus
            if (dynamic_cast<PrimitiveType*>(node.lhs->resolvedType) && dynamic_cast<PrimitiveType*>(node.rhs->resolvedType))
            {
                node.code += evaluateTwoNodes(*node.lhs, *node.rhs);
                node.code += "add eax, ebx\n";
            }
            else
            {
                // TODO: string concat
            }
            break;
        case BinaryOperation::MINUS:
            node.code += evaluateTwoNodes(*node.lhs, *node.rhs);
            node.code += "sub ebx, eax\n";
            node.code += "mov eax, ebx\n";
            break;
        case BinaryOperation::TIMES:
            node.code += evaluateTwoNodes(*node.lhs, *node.rhs);
            node.code += "imul eax, ebx\n";
            break;
        case BinaryOperation::DIVIDE:
        case BinaryOperation::REMAINDER:
            node.code += evaluateTwoNodes(*node.lhs, *node.rhs);
            node.code += "mov ecx, eax\n";
            node.code += "mov eax, ebx\n";
            node.code += "cdq\n";
            node.code += "idiv ecx\n";
            if (node.op == BinaryOperation::DIVIDE) break;
            // Move remainder
            node.code += "mov eax, edx\n";
            break;
        case BinaryOperation::AND:
        {
            std::string andLabel = "andEnd." + std::to_string(node.LABEL_NUM);
            node.LABEL_NUM++;
            node.code += ifFalse(*node.lhs, andLabel);
            node.code += node.rhs->code;
            node.code += setLabel(andLabel);
        }
        break;
        case BinaryOperation::OR:
        {
            std::string orLabel = "orEnd." + std::to_string(node.LABEL_NUM);
            node.LABEL_NUM++;
            node.code += ifTrue(*node.lhs, orLabel);
            node.code += node.rhs->code;
            node.code += setLabel(orLabel);
        }
        break;
        case BinaryOperation::EAGER_AND:
            node.code += evaluateTwoNodes(*node.lhs, *node.rhs);
            node.code += "and eax, ebx\n";
            break;
        case BinaryOperation::EAGER_OR:
            node.code += evaluateTwoNodes(*node.lhs, *node.rhs);
            node.code += "or eax, ebx\n";
            break;
        case BinaryOperation::XOR:
            node.code += evaluateTwoNodes(*node.lhs, *node.rhs);
            node.code += "xor eax, ebx\n";
            break;
        case BinaryOperation::EQ:
        {
            std::string eqLabel = "eqTrue." + std::to_string(node.LABEL_NUM);
            std::string eqLabelEnd = "eqEnd." + std::to_string(node.LABEL_NUM);
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "je", eqLabel, eqLabelEnd);
        }
        break;
        case BinaryOperation::NEQ:
        {
            std::string neqLabel = "neqTrue." + std::to_string(node.LABEL_NUM);
            std::string neqLabelEnd = "neqEnd." + std::to_string(node.LABEL_NUM);
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "jne", neqLabel, neqLabelEnd);
        }
        break;
        case BinaryOperation::LEQ:
        {
            std::string leqLabel = "leqTrue." + std::to_string(node.LABEL_NUM);
            std::string leqLabelEnd = "leqEnd." + std::to_string(node.LABEL_NUM);
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "jle", leqLabel, leqLabelEnd);
        }
        break;
        case BinaryOperation::GEQ:
        {
            std::string geqLabel = "geqTrue." + std::to_string(node.LABEL_NUM);
            std::string geqLabelEnd = "geqEnd." + std::to_string(node.LABEL_NUM);
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "jge", geqLabel, geqLabelEnd);
        }
        break;
        case BinaryOperation::LT:
        {
            std::string ltLabel = "gtTrue." + std::to_string(node.LABEL_NUM);
            std::string ltLabelEnd = "gtEnd." + std::to_string(node.LABEL_NUM);
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "jl", ltLabel, ltLabelEnd);
        }
        break;
        case BinaryOperation::GT:
        {
            std::string gtLabel = "gtTrue." + std::to_string(node.LABEL_NUM);
            std::string gtLabelEnd = "gtEnd." + std::to_string(node.LABEL_NUM);
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "jg", gtLabel, gtLabelEnd);
        }
        break;
    }

    node.code += comment("BinaryOperation End");
}

void CodeGenerator::CodeGenVisitor::leave(PrefixOperation& node)
{
    node.code = comment("PrefixOperation Begin");

    node.code += node.operand->code;

    switch (node.op)
    {
    case PrefixOperation::MINUS:
        node.code += "mov ebx, -1\n";
        node.code += "imul eax, ebx\n";
        break;
    case PrefixOperation::NOT:
        node.code += "xor eax, 1\n";
        break;
    }

    node.code += comment("PrefixOperation End");
}

void CodeGenerator::CodeGenVisitor::leave(AssignmentExpression& node)
{
    node.code = comment("AssignmentExpression Begin");
    node.code += node.lhs->addr;
    node.code += "push eax\n";
    node.code += node.rhs->code;
    node.code += "pop ebx\n";

    if (dynamic_cast<ArrayType*>(node.lhs->resolvedType))
    {
        // Todo type check code for runtime assignability of array element
    }

    node.code += "mov [ebx], eax\n";
    node.code += "mov eax, ebx\n";
    node.code += comment("AssignmentExpression End");
}

void CodeGenerator::CodeGenVisitor::leave(ParenthesizedExpression& node)
{
    node.code = comment("ParenthesizedExpression Begin");
    node.code += node.expr->code;
    node.code += comment("ParenthesizedExpression End");
}

void CodeGenerator::CodeGenVisitor::leave(FieldAccess& node)
{
    FieldDeclaration* field = dynamic_cast<FieldDeclaration*>(node.refersTo);

    bool isStatic = false;
    for (Modifier* modifier : field->modifiers->elements)
    {
        if (modifier->type == Modifier::STATIC)
        {
            isStatic = true;
        }
    }

    if (isStatic)
    {
        node.addr = "mov eax, "; // + label of static field
        node.code = node.addr + addrVal();

        node.addr = comment("Static FieldAccess Addr") + node.addr + comment("Static FieldAccess End");
        node.code = comment("Static FieldAccess Code") + node.code + comment("Static FieldAccess End");
    }
    else
    {
        node.addr += node.prevExpr->code;
        // TODO: Add null check
        node.addr += "add eax, " + std::to_string(field->declaration->variableOffset);

        node.code = node.addr + addrVal();

        node.addr += comment("FieldDeclaration End");
        node.code += comment("FieldDeclaration End");

        node.addr = comment("FieldAccess Addr") + node.addr + comment("FieldAccess End");
        node.code = comment("FieldAccess Code") + node.code + comment("FieldAccess End");
    }
}

void CodeGenerator::CodeGenVisitor::leave(ThisExpression& node)
{
    node.addr = "mov eax, ebp";
    node.addr += "add eax, " + std::to_string(thisOffset);
    
    node.code += node.addr + addrVal();

    node.addr = comment("ThisExpression Addr") + node.addr + comment("ThisExpression End");
    node.code = comment("ThisExpression Code") + node.code + comment("ThisExpression End");
}

void CodeGenerator::CodeGenVisitor::leave(ReturnStatement& node)
{
    node.code = comment("ReturnStatement Begin");

    if (node.expression) node.code += node.expression->code;
    node.code += popCalleeSaveRegs();
    node.code += methodCallReturn();

    node.code += comment("ReturnStatement End");
}

void CodeGenerator::CodeGenVisitor::leave(IfStatement& node)
{
    std::string elseLabel = "else." + std::to_string(node.LABEL_NUM);
    std::string endLabel = "end." + std::to_string(node.LABEL_NUM);
    node.LABEL_NUM++;

    node.code = comment("IfStatement Begin");
    node.code += ifFalse(*node.ifCondition, elseLabel);
    node.code += node.ifBody->code;
    node.code += "jmp " + endLabel + "\n";
    node.code += setLabel(elseLabel);
    
    if (node.elseBody) node.code += node.elseBody->code;

    node.code += setLabel(endLabel);
    node.code += comment("IfStatement End");
}

void CodeGenerator::CodeGenVisitor::leave(ForStatement& node)
{
    std::string forBeginLabel = "forBegin." + std::to_string(node.LABEL_NUM);
    std::string forEndLabel = "forEnd." + std::to_string(node.LABEL_NUM);

    node.LABEL_NUM++;

    node.code = comment("ForStatement Begin");

    if (node.forInit) node.code += node.forInit->code;
    
    node.code += setLabel(forBeginLabel);

    if (node.forCheck) node.code += ifFalse(*node.forCheck, forEndLabel);

    node.code += node.body->code;

    if (node.forUpdate) node.code += node.forUpdate->code;

    node.code += "jmp " + forBeginLabel;
    node.code += setLabel(forEndLabel);
    node.code += comment("ForStatement End");
}

void CodeGenerator::CodeGenVisitor::leave(WhileStatement& node)
{
    std::string whileBeginLabel = "whileBegin." + std::to_string(node.LABEL_NUM);
    std::string whileEndLabel = "whileEnd." + std::to_string(node.LABEL_NUM);

    node.LABEL_NUM++;

    node.code = comment("WhileStatement Begin");
    node.code += setLabel(whileBeginLabel);
    node.code += ifFalse(*node.condition, whileEndLabel);
    node.code += node.body->code;
    node.code += "jmp " + whileBeginLabel;
    node.code += setLabel(whileEndLabel);
    node.code += comment("WhileStatement End");
}

void CodeGenerator::CodeGenVisitor::leave(Block& node)
{
    node.code = comment("Block Start");
    for (Statement* stmt : node.statements->elements)
    {
        node.code += stmt->code;
    }
    node.code += comment("Block End");
}

void CodeGenerator::CodeGenVisitor::leave(ConstructorDeclaration& node)
{
    // TODO: implementation

    inMethod = false;
}

void CodeGenerator::CodeGenVisitor::leave(MethodDeclaration& node)
{
    // TODO: implementation

    inMethod = false;
}

std::string CodeGenerator::CodeGenVisitor::ifFalse(ASTNode& node, const std::string& label)
{
    std::string ret = node.code;
    ret += "cmp eax, 0\n";
    ret += "je " + label + '\n';

    return ret;
}

std::string CodeGenerator::CodeGenVisitor::ifTrue(ASTNode& node, const std::string& label)
{
    std::string ret = node.code;
    ret += "cmp eax, 0\n";
    ret += "jne " + label + '\n';

    return ret;
}

std::string CodeGenerator::CodeGenVisitor::setLabel(const std::string& label)
{
    return label + ":\n";
}

std::string CodeGenerator::CodeGenVisitor::comment(const std::string& comment)
{
    return "; " + comment + "\n";
}

std::string CodeGenerator::CodeGenVisitor::evaluateTwoNodes(ASTNode& lhs, ASTNode& rhs)
{
    std::string ret = lhs.code;
    ret += "push eax\n";
    ret += rhs.code;
    ret += "pop ebx\n";

    return ret;
}

std::string CodeGenerator::CodeGenVisitor::cmpOperation(ASTNode& lhs, ASTNode& rhs, const std::string& cmpJump, const std::string& labelA, const std::string& labelB)
{
    std::string ret = evaluateTwoNodes(lhs, rhs);
    ret += "cmp eax, ebx\n";
    ret += cmpJump + " " + labelA + "\n";
    ret += "mov eax, 0\n";
    ret += "jmp " + labelB + "\n";
    ret += setLabel(labelA);
    ret += "mov eax, 1\n";
    ret += setLabel(labelB);
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::addrVal()
{
    return "mov eax, [eax]\n";
}

std::string CodeGenerator::CodeGenVisitor::methodCallHeader()
{
    std::string ret = comment("Method Header");
    ret += "push ebp\n";
    ret += "mov ebp, esp\n";
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::methodCallReturn()
{
    std::string ret = comment("Method Return");
    ret += "mov esp, ebp\n";
    ret += "pop ebp\n";
    ret += "ret\n";
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::pushCalleeSaveRegs()
{
    std::string ret = comment("Pushing Callee Regs");
    ret += "push ebx\n";
    ret += "push esi\n";
    ret += "push edi\n";
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::popCalleeSaveRegs()
{
    std::string ret = comment("Popping Callee Regs");
    ret += "pop edi\n";
    ret += "pop esi\n";
    ret += "pop ebx\n";
    return ret;
}




