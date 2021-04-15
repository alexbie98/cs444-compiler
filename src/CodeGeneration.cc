#include "CodeGeneration.h"

#include <unordered_map>
#include <iostream>
#include <set>

const std::string CodeGenerator::SUBTYPE_COLUMN_COUNT_LABEL = "SUBTYPE_COLUMN_COUNT";
const std::string CodeGenerator::SUBTYPE_TABLE_LABEL = "SUBTYPE_TABLE";
const std::string CodeGenerator::EXCEPTION = "__exception";
const std::string CodeGenerator::DEXIT = "__debexit";
const std::string CodeGenerator::MALLOC = "__malloc";
const std::string CodeGenerator::TEXT_DIR = CodeGenerator::directiveAsm("text");
const std::string CodeGenerator::DATA_DIR = CodeGenerator::directiveAsm("data");

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

            for(MemberDeclaration* member: class_decl->classBody->elements)
            {
                MethodDeclaration* method = dynamic_cast<MethodDeclaration*>(member);
                if(method)
                {
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
            for(MemberDeclaration* member: class_decl->classBody->elements)
            {
                MethodDeclaration* method = dynamic_cast<MethodDeclaration*>(member);
                if(method)
                {
                    assert(class_info.methods_prefix.find(method->getSignature()) == class_info.methods_prefix.end());

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
                class_info.fields_prefix.emplace_back(field);
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

CodeGenerator::CodeGenerator(Environment& globalEnv): global_env{globalEnv}, object_class_decl(nullptr)
{
    // Generate SIT indices
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
                    assert(index < sit_column_size);
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
        subtype_table.emplace_back(subtype_column_count, false);
    }

    assert(globalEnv.interfaces.find("java.lang.Cloneable") != globalEnv.interfaces.end());
    assert(globalEnv.interfaces.find("java.io.Serializable") != globalEnv.interfaces.end());
    InterfaceDeclaration* cloneable_decl = globalEnv.interfaces["java.lang.Cloneable"];
    InterfaceDeclaration* serializable_decl = globalEnv.interfaces["java.io.Serializable"];
    for(auto it: globalEnv.classes)
    {
        createSubtypeInfo(it.second, it.second);
        // Set array of class to inherit from Object
        subtype_table[getArraySubtypeIndex(it.second)][getArraySubtypeIndex(it.second)] = true;
        subtype_table[getArraySubtypeIndex(it.second)][getObjectSubtypeIndex(object_class_decl)] = true;
        subtype_table[getArraySubtypeIndex(it.second)][getObjectSubtypeIndex(cloneable_decl)] = true;
        subtype_table[getArraySubtypeIndex(it.second)][getObjectSubtypeIndex(serializable_decl)] = true;
    }
    for(auto it: globalEnv.interfaces)
    {
        // Set array of interface to inherit from Object
        subtype_table[getArraySubtypeIndex(it.second)][getArraySubtypeIndex(it.second)] = true;
        subtype_table[getArraySubtypeIndex(it.second)][getObjectSubtypeIndex(object_class_decl)] = true;
        subtype_table[getArraySubtypeIndex(it.second)][getObjectSubtypeIndex(cloneable_decl)] = true;
        subtype_table[getArraySubtypeIndex(it.second)][getObjectSubtypeIndex(serializable_decl)] = true;
    }
    for(PrimitiveType::BasicType t: PrimitiveType::all_prim_types)
    {
        subtype_table[getPrimitiveArraySubtypeIndex(t)][getPrimitiveArraySubtypeIndex(t)] = true;
        subtype_table[getPrimitiveArraySubtypeIndex(t)][getObjectSubtypeIndex(object_class_decl)] = true;
        subtype_table[getPrimitiveArraySubtypeIndex(t)][getObjectSubtypeIndex(cloneable_decl)] = true;
        subtype_table[getPrimitiveArraySubtypeIndex(t)][getObjectSubtypeIndex(serializable_decl)] = true;
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

    // Create ClassInfos for interface arrays
    for(auto it: globalEnv.interfaces)
    {
        InterfaceDeclaration* class_decl = it.second;
        array_class_infos.insert({class_decl, ClassInfo()});
        ClassInfo& class_info = array_class_infos[class_decl];

        class_info.subtype_column = getArraySubtypeIndex(class_decl);
        class_info.methods_prefix = class_infos[object_class_decl].methods_prefix;
    }

    // Create ClassInfos for primitive arrays
    for(PrimitiveType::BasicType t: PrimitiveType::all_prim_types)
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

    common_asm += globalAsm(SUBTYPE_TABLE_LABEL);
    common_asm += labelAsm(SUBTYPE_TABLE_LABEL);
    for(const std::vector<bool>& column: subtype_table)
    {
        for(bool b: column) 
        {
            common_asm += byteAsm(b);
        }

        common_asm += "\n";
    }

    // Reset labels
    writeExterns();

    return common_asm;
}

std::string CodeGenerator::generateStart(std::string static_field_initializers, MethodDeclaration* entry)
{
    std::string ret;
    ret += runtimeExternsAsm();
    ret += TEXT_DIR;
    ret += globalAsm("_start");
    ret += labelAsm("_start");
    ret += "mov ebp, esp\n";
    ret += static_field_initializers;
    ret += externAsm(classMethodLabel(entry));
    ret += "call " + classMethodLabel(entry) + "\n";
    ret += "jmp " + DEXIT + '\n';
    
    ret+= staticWriteExterns();

    return ret;
}

std::string CodeGenerator::writeExterns()
{
    std::string ret;

    //assert(used_labels.empty());
    for(auto& used: used_labels)
    {
        assert(!used_labels.empty());
        if(defined_labels.find(used) == defined_labels.end()) ret += externAsm(used); 
    }

    used_labels.clear();
    defined_labels.clear();

    return ret;
}


std::string CodeGenerator::staticWriteExterns()
{
    std::string ret = "\n" + commentAsm("Static Initializer Externs");

    //assert(used_labels.empty());
    for (auto& used : static_used_labels)
    {
        if (static_defined_labels.find(used) == static_defined_labels.end()) ret += externAsm(used);
    }

    static_used_labels.clear();
    static_defined_labels.clear();

    return ret;
}

std::string CodeGenerator::generateObjectCode(TypeDeclaration* root, ObjectType otype, PrimitiveType::BasicType ptype)
{
    std::string class_asm;

    std::vector<MethodDeclaration*>* column = nullptr;
    ClassInfo* class_info = nullptr;
    std::string column_label;
    std::string class_data_label;
    size_t subtype_index;

    if(otype == ObjectType::OBJECT)
    {
        ClassDeclaration* root_class = dynamic_cast<ClassDeclaration*>(root);
        column_label = sitColumnClassLabel(root_class);
        column = &sit_table[root_class];
        class_info = &class_infos[root_class];
        class_data_label = classDataLabel(root_class);
        subtype_index = getObjectSubtypeIndex(root);
        class_asm += runtimeExternsAsm();
        class_asm += "\n" + commentAsm("================== OBJECT INFORMATION ==================");
    } 
    else if(otype == ObjectType::OBJECT_ARRAY)
    {
        // Uses same sit column as object
        column_label = sitColumnClassLabel(object_class_decl);
        column = &sit_table[object_class_decl];
        class_info = &array_class_infos[root];
        class_data_label = classArrayDataLabel(root);
        subtype_index = getArraySubtypeIndex(root);

        class_asm += "\n" + commentAsm("================== OBJECT ARRAY INFORMATION ==================");
    } 
    else if(otype == ObjectType::PRIMITIVE_ARRAY)
    {
        // Uses same sit column as object
        column_label = sitColumnClassLabel(object_class_decl);
        column = &sit_table[object_class_decl];
        class_info = &primitive_array_class_infos[ptype];
        class_data_label = primitiveArrayDataLabel(ptype);
        subtype_index = getPrimitiveArraySubtypeIndex(ptype);
        class_asm += "\n" + commentAsm("================== PRIMITIVE ARRAY INFORMATION ==================");
    } 
    else assert(false);

    class_asm += TEXT_DIR; // Use .text for read only data

    // Generate SIT column if class
    if(otype == ObjectType::OBJECT) 
    {
        class_asm += globalAsm(column_label);
        class_asm += labelAsm(column_label);

        for(MethodDeclaration* method: *column)
        {
            if(method)
            {
                class_asm += wordAsm(useLabel(classMethodLabel(method)));
            }
            else
            {
                class_asm += wordAsm(0);
            }
        }
    }

    class_asm += "\n";

    class_asm += globalAsm(class_data_label);
    class_asm += labelAsm(class_data_label);
    class_asm += wordAsm(useLabel(column_label));
    class_asm += wordAsm(subtype_index);

    // Add entryType if object is an array
    if (otype == ObjectType::OBJECT_ARRAY)
    {
        // Store subtype index of entryType only
        class_asm += wordAsm(getObjectSubtypeIndex(root));
    }
    else
    {
        class_asm += wordAsm(0);
    }

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

        bool is_abstract = false;
        for (Modifier* modifier : method->modifiers->elements)
        {
            if (modifier->type == Modifier::ABSTRACT)
            {
                is_abstract = true;
            }
        }

        if(is_abstract)
        {
            class_asm += wordAsm(0);
        }
        else
        {
            class_asm += wordAsm(useLabel(classMethodLabel(method)));
        }
    }

    if(otype == ObjectType::OBJECT && dynamic_cast<ClassDeclaration*>(root))
    {
        class_asm += "\n\n" + commentAsm("================== METHODS ==================");

        CodeGenVisitor visitor(*this);
        root->visitAll(visitor);
        class_asm += root->code;

        static_field_initializers += visitor.getStaticFieldInitializers();
    }

    return class_asm;
}

std::string CodeGenerator::generateClassCode(ClassDeclaration* root)
{
    std::string ret =  generateObjectCode(root, ObjectType::OBJECT) 
           + "\n\n" 
           + commentAsm("Object Array Information") 
           + generateObjectCode(root, ObjectType::OBJECT_ARRAY);
    ret += writeExterns();
    return ret;
}

std::string CodeGenerator::generatePrimitiveArrayCode(PrimitiveType::BasicType type)
{   
    std::string ret = generateObjectCode(0, ObjectType::PRIMITIVE_ARRAY, type);
    ret += writeExterns();
    return ret;
}

std::string CodeGenerator::generateInterfaceArrayCode(InterfaceDeclaration* root)
{
    std::string ret = commentAsm("Interface Array Information") + generateObjectCode(root, ObjectType::OBJECT_ARRAY, {});
    ret += writeExterns();
    return ret;
}

std::string CodeGenerator::nullCheckAsm()
{
    return commentAsm("Null Check") +
        "cmp eax, 0\n" +
        "je " + useLabel(EXCEPTION) + "\n";
}

std::string CodeGenerator::runtimeExternsAsm()
{
    return externAsm("__malloc") +
        externAsm("__debexit") +
        externAsm("__exception");
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

void CodeGenerator::CodeGenVisitor::visit(FieldDeclaration& node)
{
    inStaticField = false;
    for (Modifier* mod : node.modifiers->elements)
    {
        if (mod->type == Modifier::STATIC)
        {
            inStaticField = true;
            break;
        }
    }
}

void CodeGenerator::CodeGenVisitor::leave(IntLiteral& node)
{
    node.code += "mov eax, " + std::to_string(node.value) + " " + commentAsm("IntLiteral");
}

void CodeGenerator::CodeGenVisitor::leave(CharLiteral& node)
{
    node.code = "mov eax, " + std::to_string(node.value) + " " + commentAsm("CharLiteral");
}

void CodeGenerator::CodeGenVisitor::leave(StringLiteral& node)
{
    node.code = createStringFromLiteral(node.value);
}

void CodeGenerator::CodeGenVisitor::leave(BooleanLiteral& node)
{
    node.code = "mov eax, ";
    
    if (node.value) node.code += '1';
    else node.code += '0';

    node.code += " " + commentAsm("BooleanLiteral");
}

void CodeGenerator::CodeGenVisitor::leave(NullLiteral& node)
{
    node.code = "mov eax, 0 " + commentAsm("NullLiteral");
}

void CodeGenerator::CodeGenVisitor::leave(NameExpression& node)
{
    if (node.name)
    {
        if (FormalParameter * param = dynamic_cast<FormalParameter*>(node.name->refers_to))
        {
            node.addr = frameOffsetAddr(param->paramOffset);

            node.code += node.addr + addrVal();

            node.addr = commentAsm("ParameterAccess Addr") + node.addr + commentAsm("ParameterAccess End");
            node.code = commentAsm("ParameterAccess Code") + node.code + commentAsm("ParameterAccess End");
        }
        else if (FieldDeclaration * field = dynamic_cast<FieldDeclaration*>(node.name->refers_to))
        {
            node.addr = "mov eax, ebp";
            node.addr += "add eax, " + std::to_string(thisOffset);

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
                node.addr = labelAddr(field->staticLabel);
                node.code = node.addr + addrVal();

                node.addr = commentAsm("Static FieldAccess Addr") + node.addr + commentAsm("Static FieldAccess End");
                node.code = commentAsm("Static FieldAccess Code") + node.code + commentAsm("Static FieldAccess End");
            }
            else
            {
                node.addr = thisAddr() + addrVal();
                node.addr += addOffset(cg.field_prefix_indices[field] * WORD_SIZE + FIELDS_OFFSET);

                node.code = node.addr + addrVal();

                node.addr = commentAsm("(Implicit This) FieldAccess Addr") + node.addr + commentAsm("(Implicit This) FieldAccess End");
                node.code = commentAsm("(Implicit This) FieldAccess Code") + node.code + commentAsm("(Implicit This) FieldAccess End");
            }
        }
        else if (VariableDeclarationExpression * var = dynamic_cast<VariableDeclarationExpression*>(node.name->refers_to))
        {
            if (FieldDeclaration * field = dynamic_cast<FieldDeclaration*>(var->parent))
            {
                node.addr = "mov eax, ebp";
                node.addr += "add eax, " + std::to_string(thisOffset);

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
                    node.addr = labelAddr(field->staticLabel);
                    node.code = node.addr + addrVal();

                    node.addr = commentAsm("Static FieldAccess Addr") + node.addr + commentAsm("Static FieldAccess End");
                    node.code = commentAsm("Static FieldAccess Code") + node.code + commentAsm("Static FieldAccess End");
                }
                else
                {
                    node.addr = thisAddr() + addrVal();
                    node.addr += addOffset(cg.field_prefix_indices[field] * WORD_SIZE + FIELDS_OFFSET);

                    node.code = node.addr + addrVal();

                    node.addr = commentAsm("(Implicit This) FieldAccess Addr") + node.addr + commentAsm("(Implicit This) FieldAccess End");
                    node.code = commentAsm("(Implicit This) FieldAccess Code") + node.code + commentAsm("(Implicit This) FieldAccess End");
                }
            }
            else
            {
                node.addr = frameOffsetAddr(var->variableOffset);

                node.code += node.addr + addrVal();

                node.addr = commentAsm("Local Var Access Addr") + node.addr + commentAsm("Local Var Access End");
                node.code = commentAsm("Local Var Access Code") + node.code + commentAsm("Local Var Access End");
            }
        }
    }
    else // node.field
    {
        node.addr = node.field->addr;
        node.code = node.field->code;
    }
}

void CodeGenerator::CodeGenVisitor::leave(BinaryOperation& node)
{
    node.code = commentAsm("BinaryOperation Begin");

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
                ClassDeclaration* classDecl = cg.global_env.classes["java.lang.String"];
                assert(classDecl);
                MethodDeclaration* concatMethod = nullptr;
                for (MemberDeclaration* member : classDecl->classBody->elements)
                {
                    if (MethodDeclaration * method = dynamic_cast<MethodDeclaration*>(member))
                    {
                        if (method->name->id == "concat")
                        {
                            concatMethod = method;
                            break;
                        }
                    }
                }
                assert(concatMethod);
                node.code += commentAsm("String Concatenation Start");
                node.code += callMethod(concatMethod, stringConversion(*node.lhs), std::vector<std::string>{stringConversion(*node.rhs)});
                node.code += commentAsm("String Concatenation End");
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
            node.code += "cmp eax, 0\n";
            node.code += "je " + useLabel(EXCEPTION) + "\n";
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
            std::string andLabel = useLabel("andEnd." + std::to_string(node.LABEL_NUM));
            node.LABEL_NUM++;
            node.code += ifFalse(*node.lhs, andLabel);
            node.code += node.rhs->code;
            node.code += labelAsm(andLabel);
        }
        break;
        case BinaryOperation::OR:
        {
            std::string orLabel = useLabel("orEnd." + std::to_string(node.LABEL_NUM));
            node.LABEL_NUM++;
            node.code += ifTrue(*node.lhs, orLabel);
            node.code += node.rhs->code;
            node.code += labelAsm(orLabel);
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
            std::string eqLabel = useLabel("eqTrue." + std::to_string(node.LABEL_NUM));
            std::string eqLabelEnd = useLabel("eqEnd." + std::to_string(node.LABEL_NUM));
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "je", eqLabel, eqLabelEnd);
        }
        break;
        case BinaryOperation::NEQ:
        {
            std::string neqLabel = useLabel("neqTrue." + std::to_string(node.LABEL_NUM));
            std::string neqLabelEnd = useLabel("neqEnd." + std::to_string(node.LABEL_NUM));
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "jne", neqLabel, neqLabelEnd);
        }
        break;
        case BinaryOperation::LEQ:
        {
            std::string leqLabel = useLabel("leqTrue." + std::to_string(node.LABEL_NUM));
            std::string leqLabelEnd = useLabel("leqEnd." + std::to_string(node.LABEL_NUM));
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "jle", leqLabel, leqLabelEnd);
        }
        break;
        case BinaryOperation::GEQ:
        {
            std::string geqLabel = useLabel("geqTrue." + std::to_string(node.LABEL_NUM));
            std::string geqLabelEnd = useLabel("geqEnd." + std::to_string(node.LABEL_NUM));
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "jge", geqLabel, geqLabelEnd);
        }
        break;
        case BinaryOperation::LT:
        {
            std::string ltLabel = useLabel("ltTrue." + std::to_string(node.LABEL_NUM));
            std::string ltLabelEnd = useLabel("ltEnd." + std::to_string(node.LABEL_NUM));
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "jl", ltLabel, ltLabelEnd);
        }
        break;
        case BinaryOperation::GT:
        {
            std::string gtLabel = useLabel("gtTrue." + std::to_string(node.LABEL_NUM));
            std::string gtLabelEnd = useLabel("gtEnd." + std::to_string(node.LABEL_NUM));
            node.LABEL_NUM++;

            node.code += cmpOperation(*node.lhs, *node.rhs, "jg", gtLabel, gtLabelEnd);
        }
        break;
    }

    node.code += commentAsm("BinaryOperation End");
}

void CodeGenerator::CodeGenVisitor::leave(PrefixOperation& node)
{
    node.code = commentAsm("PrefixOperation Begin");

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

    node.code += commentAsm("PrefixOperation End");
}

void CodeGenerator::CodeGenVisitor::leave(CastExpression& node)
{
    node.code = commentAsm("CastExpression Begin");
    assert(node.castType);
    PrimitiveType* prim = dynamic_cast<PrimitiveType*>(node.castType);

    std::string& object = node.expression->code;
    node.code += object;

    if(prim)
    {
        switch (prim->type)
        {
        case PrimitiveType::BYTE:
            node.code += "movsx ecx, al\n";
            node.code += "mov eax, ecx\n";
            break;
        case PrimitiveType::SHORT:
            node.code += "movsx ecx, ax\n";
            node.code += "mov eax, ecx\n";
            break;
        case PrimitiveType::INT:
            break;
        case PrimitiveType::CHAR:
            node.code += "movzx ecx, ax\n";
            node.code += "mov eax, ecx\n";
            break;
        case PrimitiveType::BOOLEAN:
            break;
        default:
            assert(false);  
            break;
        }
    }
    else
    {
        // Similar to instanceof
        size_t type_offset = getTypeSubtypeIndex(node.castType);

        std::string cast_allowed = cg.freshenLabel("cast_allowed");

        node.code += "push eax\n";

        node.code += commentAsm("Check if object is null, allow cast if it is");
        node.code += "cmp eax, 0\n";
        node.code += "je " + cast_allowed + "\n";
        
        // Check if expression is instanceof castType
        node.code += getClassInfo();
        node.code += getSubtypeColumn();
        node.code += "mov ebx, " + std::to_string(type_offset) + '\n';
        node.code += "mov ecx, 0\n";
        node.code += "push eax\n";
        node.code += "imul eax, " + std::to_string(cg.subtype_column_count) + '\n';
        node.code += "mov cl, [" + useLabel(SUBTYPE_TABLE_LABEL) + "+ eax + ebx]\n";
        node.code += "pop eax\n";
        node.code += "cmp ecx, 0\n";
        node.code += "je " + useLabel(EXCEPTION) + "\n";

        node.code += labelAsm(cast_allowed);
        node.code += "pop eax\n";
    }

    node.code += commentAsm("CastExpression End");
}

void CodeGenerator::CodeGenVisitor::leave(AssignmentExpression& node)
{
    node.code = commentAsm("AssignmentExpression Begin");

    bool is_object_array_assignment = false;
    ArrayAccess* array_access = dynamic_cast<ArrayAccess*>(node.lhs);
    if(array_access)
    {
        assert(array_access->prevExpr->resolvedType);
        ArrayType* array_type = dynamic_cast<ArrayType*>(array_access->prevExpr->resolvedType);
        is_object_array_assignment = dynamic_cast<QualifiedType*>(array_type->elementType);
    }
    
    if(is_object_array_assignment)
    {
        // Load array (instead of object in array) into ebx
        // TODO Make more efficient by only doing index opperation after rather than entire array access again?
        node.code += getArray(*array_access);
        node.code += "push eax\n";
        node.code += node.rhs->code;
        node.code += "pop ebx\n";
        // eax is rhs, ebx is lhs

        // Save lhs and rhs
        node.code += "push eax\n";
        node.code += "push ebx\n";

        // Type check code for runtime assignability of array element
        // Get rhs subtype, put into ecx
        node.code += commentAsm("Type check runtime assignability of array element");

        // Get rhs subtype, put into edx
        node.code += getClassInfo();
        node.code += getSubtypeColumn();
        node.code += "mov edx, eax\n";

        // Get lhs subtype, put into ecx
        node.code += "mov eax, ebx\n";
        node.code += getClassInfo();
        node.code += getElementTypeColumn();
        node.code += "mov ecx, eax\n";
        
        // Check rhs is subtype of lhs (rhs column)
        // Get subtype table entry
        node.code += "mov eax, " + useLabel(SUBTYPE_TABLE_LABEL) + "\n";
        node.code += "imul edx, " + std::to_string(cg.subtype_column_count) + "\n";
        node.code += "add eax, edx\n";
        node.code += "add eax, ecx\n";
        node.code += "mov ecx, 0\n";
        node.code += "mov cl, [eax]\n";
        node.code += "mov eax, ecx\n";
        node.code += cg.nullCheckAsm();

        // Restore lhs and rhs
        node.code += "pop eax\n";
        node.code += indexArray(*array_access); // Equivelent to node.lhs->addr

        // Restore ebx and put lhs back into ebx
        node.code += "mov ebx, eax\n";
        node.code += "pop eax\n";
    }
    else
    {
        // rhs in eax, lhs in ebx
        node.code += node.lhs->addr;
        node.code += "push eax\n";
        node.code += node.rhs->code;
        node.code += "pop ebx\n";
    }

    node.code += "mov [ebx], eax\n";
    node.code += "mov eax, [ebx]\n";
    node.code += commentAsm("AssignmentExpression End");
}

void CodeGenerator::CodeGenVisitor::leave(ParenthesizedExpression& node)
{
    node.code = commentAsm("ParenthesizedExpression Begin");
    node.code += node.expr->code;
    node.code += commentAsm("ParenthesizedExpression End");
}

void CodeGenerator::CodeGenVisitor::leave(ClassInstanceCreator& node)
{
    ClassDeclaration* classDecl = dynamic_cast<ClassDeclaration*>(node.type->name->refers_to);
    std::vector<std::string> args;
    for (Expression* arg : node.arguments->elements)
    {
        args.push_back(arg->code);
    }
    node.code = createFromConstructor(classDecl, node.matchedConstructor, args);
}

void CodeGenerator::CodeGenVisitor::leave(ArrayCreator& node)
{
    Type* elementType = node.type->elementType;
    std::string label;
    
    if (PrimitiveType * primType = dynamic_cast<PrimitiveType*>(elementType))
    {
        label = cg.primitiveArrayDataLabel(primType->type);
    }
    else if (QualifiedType * qualType = dynamic_cast<QualifiedType*>(elementType))
    {
        TypeDeclaration* typeDecl = dynamic_cast<TypeDeclaration*>(qualType->name->refers_to);
        label = cg.classArrayDataLabel(typeDecl);
    }

    node.code = createArrayFromLabel(label, node.argument->code);
}

void CodeGenerator::CodeGenVisitor::leave(FieldAccess& node)
{
    FieldDeclaration* field = dynamic_cast<FieldDeclaration*>(node.refersTo);

    if (field)
    {
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
            node.addr = labelAddr(field->staticLabel);
            node.code = node.addr + addrVal();

            node.addr = commentAsm("Static FieldAccess Addr") + node.addr + commentAsm("Static FieldAccess End");
            node.code = commentAsm("Static FieldAccess Code") + node.code + commentAsm("Static FieldAccess End");
        }
        else
        {
            node.addr = node.prevExpr->code;
            node.addr += cg.nullCheckAsm();
            node.addr += addOffset(cg.field_prefix_indices[field] * WORD_SIZE + FIELDS_OFFSET);

            node.code = node.addr + addrVal();

            node.addr = commentAsm("FieldAccess Addr") + node.addr + commentAsm("FieldAccess End");
            node.code = commentAsm("FieldAccess Code") + node.code + commentAsm("FieldAccess End");
        }
    }
    else
    {
        assert(node.name->id == "length");
        // Special case for array
        node.addr = node.prevExpr->code;
        node.addr += cg.nullCheckAsm();
        node.addr += addOffset(FIELDS_OFFSET);

        node.code = node.addr + addrVal();

        node.addr = commentAsm("FieldAccess Addr") + node.addr + commentAsm("FieldAccess End");
        node.code = commentAsm("FieldAccess Code") + node.code + commentAsm("FieldAccess End");
    }
}

void CodeGenerator::CodeGenVisitor::leave(MethodCall& node)
{
    MethodDeclaration* method = dynamic_cast<MethodDeclaration*>(node.name->refers_to);
    std::vector<std::string> args;
    for (Expression* arg : node.arguments->elements)
    {
        args.push_back(arg->code);
    }

    bool isStatic = false;
    for (Modifier* mod : method->modifiers->elements)
    {
        if (mod->type == Modifier::STATIC)
        {
            isStatic = true;
            break;
        }
    }

    if (isStatic)
    {
        node.code = callStaticMethod(method, args);
    }
    else
    {
        std::string object = node.prevExpr ? node.prevExpr->code : (thisAddr() + addrVal());
        node.code = callMethod(method, object, args);
    }
}

std::string CodeGenerator::CodeGenVisitor::getArray(ArrayAccess& node)
{
    std::string ret;
    ret += node.prevExpr->code;
    ret += cg.nullCheckAsm();
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::indexArray(ArrayAccess& node)
{
    std::string ret;
    ret += "push eax\n";
    ret += node.indexExpr->code;
    ret += "pop ebx\n";
    ret += "cmp eax, 0\n";
    ret += "jl " + useLabel(EXCEPTION) + "\n";
    ret += "mov ecx, [ebx + " + std::to_string(FIELDS_OFFSET) + "]\n";
    ret += "cmp eax, ecx\n";
    ret += "jge " + useLabel(EXCEPTION) + "\n";
    ret += "add eax, 2\n";
    ret += "imul eax, " + std::to_string(WORD_SIZE) + "\n";
    ret += "add eax, ebx\n";
    return ret;
}

void CodeGenerator::CodeGenVisitor::leave(ArrayAccess& node)
{
    node.addr += getArray(node);
    node.addr += indexArray(node);

    node.code = node.addr + addrVal();

    node.addr = commentAsm("ArrayAccess Addr") + node.addr + commentAsm("ArrayAccess End");
    node.code = commentAsm("ArrayAccess Code") + node.code + commentAsm("ArrayAccess End");
}

void CodeGenerator::CodeGenVisitor::leave(ThisExpression& node)
{
    node.addr = thisAddr();

    node.code += node.addr + addrVal();

    node.addr = commentAsm("ThisExpression Addr") + node.addr + commentAsm("ThisExpression End");
    node.code = commentAsm("ThisExpression Code") + node.code + commentAsm("ThisExpression End");
}

void CodeGenerator::CodeGenVisitor::leave(VariableDeclarationExpression& node)
{
    if (FieldDeclaration* field = dynamic_cast<FieldDeclaration*>(node.parent))
    {
        if (node.initializer)
        {
            node.code = commentAsm("Field VariableDeclarationExpression Start");
            node.code += node.initializer->code;
            node.code += commentAsm("Field VariableDeclarationExpression End");
        }
    }
    else // Local variable declaration
    {
        node.code = commentAsm("Local VariableDeclarationExpression Start");
        node.code += node.initializer->code;
        node.code += "push eax\n";
        node.code += frameOffsetAddr(node.variableOffset);
        node.code += "pop ebx\n";
        node.code += "mov [eax], ebx\n";
        node.code += commentAsm("Local VariableDeclarationExpression End");
    }
}

void CodeGenerator::CodeGenVisitor::leave(InstanceOfExpression& node)
{
    node.code = commentAsm("InstanceOfExpression Begin");
    size_t type_offset = getTypeSubtypeIndex(node.type);

    std::string& object = node.expression->code;

    std::string finished = cg.freshenLabel("instanceof_result");

    node.code = commentAsm("Check if object is null");
    node.code += object;
    node.code += "cmp eax, 0\n";
    node.code += "je " + useLabel(finished) + "\n";

    node.code += getClassInfo();
    node.code += getSubtypeColumn();
    node.code += "mov ecx, 0\n";
    node.code += "imul eax, " + std::to_string(cg.subtype_column_count) + '\n';
    node.code += "mov cl, [" + useLabel(SUBTYPE_TABLE_LABEL) + "+ eax + " + std::to_string(type_offset) + "]\n";
    node.code += "mov eax, ecx\n";

    node.code += labelAsm(finished);
    node.code += commentAsm("InstanceOfExpression End");
}

void CodeGenerator::CodeGenVisitor::leave(ExpressionStatement& node)
{
    node.code = commentAsm("ExpressionStatement Begin") + node.expression->code + commentAsm("ExpressionStatement End");
}

void CodeGenerator::CodeGenVisitor::leave(ReturnStatement& node)
{
    node.code = commentAsm("ReturnStatement Begin");

    if (node.expression) node.code += node.expression->code;
    node.code += popCalleeSaveRegs();
    node.code += methodCallReturn();

    node.code += commentAsm("ReturnStatement End");
}

void CodeGenerator::CodeGenVisitor::leave(IfStatement& node)
{
    std::string elseLabel = useLabel("else." + std::to_string(node.LABEL_NUM));
    std::string endLabel = useLabel("end." + std::to_string(node.LABEL_NUM));
    node.LABEL_NUM++;

    node.code = commentAsm("IfStatement Begin");
    node.code += ifFalse(*node.ifCondition, elseLabel);
    node.code += node.ifBody->code;
    node.code += "jmp " + endLabel + "\n";
    node.code += labelAsm(elseLabel);
    
    if (node.elseBody) node.code += node.elseBody->code;

    node.code += labelAsm(endLabel);
    node.code += commentAsm("IfStatement End");
}

void CodeGenerator::CodeGenVisitor::leave(ForStatement& node)
{
    std::string forBeginLabel = useLabel("forBegin." + std::to_string(node.LABEL_NUM));
    std::string forEndLabel = useLabel("forEnd." + std::to_string(node.LABEL_NUM));

    node.LABEL_NUM++;

    node.code = commentAsm("ForStatement Begin");

    if (node.forInit) node.code += node.forInit->code;
    
    node.code += labelAsm(forBeginLabel);

    if (node.forCheck) node.code += ifFalse(*node.forCheck, forEndLabel);

    node.code += node.body->code;

    if (node.forUpdate) node.code += node.forUpdate->code;

    node.code += "jmp " + forBeginLabel + "\n";
    node.code += labelAsm(forEndLabel);
    node.code += commentAsm("ForStatement End");
}

void CodeGenerator::CodeGenVisitor::leave(WhileStatement& node)
{
    std::string whileBeginLabel = useLabel("whileBegin." + std::to_string(node.LABEL_NUM));
    std::string whileEndLabel = useLabel("whileEnd." + std::to_string(node.LABEL_NUM));

    node.LABEL_NUM++;

    node.code = commentAsm("WhileStatement Begin");
    node.code += labelAsm(whileBeginLabel);
    node.code += ifFalse(*node.condition, whileEndLabel);
    node.code += node.body->code;
    node.code += "jmp " + whileBeginLabel + "\n";
    node.code += labelAsm(whileEndLabel);
    node.code += commentAsm("WhileStatement End");
}

void CodeGenerator::CodeGenVisitor::leave(Block& node)
{
    node.code = commentAsm("Block Start");
    for (Statement* stmt : node.statements->elements)
    {
        node.code += stmt->code;
    }
    node.code += commentAsm("Block End");
}

void CodeGenerator::CodeGenVisitor::leave(ClassDeclaration& node)
{
    // Finish constructor code gen
    // Do this here because we need to have generated code for all Field initializers

    std::string constructorHeader;
    std::string constructorSuper;
    std::string constructorInitializers;
    std::string constructorSuffix;

    ConstructorDeclaration* super = nullptr;

    if (node.baseClass)
    {
        for (MemberDeclaration* member : node.baseClass->classBody->elements)
        {
            if (ConstructorDeclaration * constructor = dynamic_cast<ConstructorDeclaration*>(member))
            {
                if (constructor->parameters->elements.size() == 0)
                {
                    super = constructor;
                    break;
                }
            }
        }
    }

    constructorSuffix = popCalleeSaveRegs();
    constructorSuffix += methodCallReturn();
    constructorSuffix += commentAsm("ConstructorDeclaration End");

    for (MemberDeclaration* member : node.classBody->elements)
    {
        if (ConstructorDeclaration * constructor = dynamic_cast<ConstructorDeclaration*>(member))
        {
            constructorHeader = commentAsm("ConstructorDeclaration Start");
            constructorHeader += globalAsm(cg.constructorLabel(constructor));
            constructorHeader += labelAsm(cg.constructorLabel(constructor));
            constructorHeader += methodCallHeader();
            constructorHeader += commentAsm("Push local vars to stack");
            for (int i = 0; i < constructor->localVarCount; i++)
            {
                constructorHeader += "push 0\n";
            }
            constructorHeader += pushCalleeSaveRegs();

            thisOffset = (constructor->parameters->elements.size() + 2) * WORD_SIZE; // Manually calculate because we are no longer in constructor context

            if (super)
            {
                constructorSuper = commentAsm("Super Constructor Call Start");
                constructorSuper += thisAddr(); // This is why we need to do this here
                constructorSuper += addrVal();
                constructorSuper += "push eax\n";
                constructorSuper += labelAddr(cg.constructorLabel(super));
                constructorSuper += "call eax\n";
                constructorSuper += "add esp, " + std::to_string(WORD_SIZE) + '\n';
                constructorSuper += commentAsm("Super Constructor Call End");
            }

            for (MemberDeclaration* member : node.classBody->elements)
            {
                if (FieldDeclaration * field = dynamic_cast<FieldDeclaration*>(member))
                {
                    bool isStatic = false;
                    for (Modifier* modifier : field->modifiers->elements)
                    {
                        if (modifier->type == Modifier::STATIC)
                        {
                            isStatic = true;
                        }
                    }

                    if (!isStatic)
                    {
                        // Regen code, because this reference is different 
                        field->visitAll(*this);
                        constructorInitializers += field->code;
                    }
                }
            }
            if (constructorInitializers != "")
            {
                constructorInitializers = commentAsm("Field Initializers Start")
                    + constructorInitializers + commentAsm("Field Initializers End");
            }


            constructor->code = constructorHeader + constructorSuper + constructorInitializers
                + constructor->code + constructorSuffix;
        }
    }

    std::string staticFields = commentAsm("================== STATIC FIELDS ==================");
    staticFields += DATA_DIR;

    node.code = TEXT_DIR;
    for (MemberDeclaration* member : node.classBody->elements)
    {
        if (FieldDeclaration * field = dynamic_cast<FieldDeclaration*>(member))
        {
            for (Modifier* modifier : field->modifiers->elements)
            {
                if (modifier->type == Modifier::STATIC)
                {
                    staticFields += field->code;
                }
            }
        }
        else
        {
            node.code += member->code;
        }
    }

    node.code += staticFields;
}

void CodeGenerator::CodeGenVisitor::leave(InterfaceDeclaration& node)
{
    for (MemberDeclaration* member : node.interfaceBody->elements)
    {
        node.code += member->code;
    }
}

void CodeGenerator::CodeGenVisitor::leave(ConstructorDeclaration& node)
{
    // Only body for now, the rest of the method call will be made in ClassDeclaration
    node.code = node.body->code;
    node.localVarCount = localVariableCount;

    inMethod = false;
}

void CodeGenerator::CodeGenVisitor::leave(FieldDeclaration& node)
{
    bool isStatic = false;
    for (Modifier* modifier : node.modifiers->elements)
    {
        if (modifier->type == Modifier::STATIC)
        {
            isStatic = true;
        }
    }

    if (isStatic)
    {
        node.code += globalAsm(node.staticLabel);
        node.code += labelAsm(node.staticLabel);
        cg.defined_labels.insert(node.staticLabel); // Make sure static fields aren't externed in their source file
        node.code += "dd 0\n";
        
        // We need to run all the static field initializers once in a seperate location at start of execution
        staticFieldInitializers += commentAsm("Static FieldDeclaration Init Start");
        staticFieldInitializers += node.declaration->code;
        staticFieldInitializers += externAsm(node.staticLabel);
        staticFieldInitializers += "mov ebx, " + node.staticLabel + '\n';
        staticFieldInitializers += "mov [ebx], eax\n";
        staticFieldInitializers += commentAsm("Static FieldDeclaration Init End") + "\n";
    }
    else
    {
        if (node.declaration->initializer)
        {
            node.code = commentAsm("FieldDeclaration Start");
            node.code += thisAddr() + addrVal();
            node.code += addOffset(cg.field_prefix_indices[&node] * WORD_SIZE + FIELDS_OFFSET);
            node.code += "push eax\n";
            node.code += node.declaration->code;
            node.code += "pop ebx\n";
            node.code += "mov [ebx], eax\n";
            node.code += commentAsm("FieldDeclaration End");
        }
    }

    inStaticField = false;
}

void CodeGenerator::CodeGenVisitor::leave(MethodDeclaration& node)
{
    if (node.body)
    {
        node.code = commentAsm("MethodDeclaration Start");
        node.code += globalAsm(cg.classMethodLabel(&node));
        node.code += labelAsm(cg.classMethodLabel(&node));
        node.code += methodCallHeader();

        node.code += commentAsm("Push local vars to stack");
        for (int i = 0; i < localVariableCount; i++)
        {
            node.code += "push 0\n";
        }

        node.code += pushCalleeSaveRegs();
        node.code += node.body->code;
        node.code += popCalleeSaveRegs();
        node.code += methodCallReturn();
        node.code += commentAsm("MethodDeclaration End");
    }
    else
    {
        bool isNative = false;

        for (Modifier* mod : node.modifiers->elements)
        {
            if (mod->type == Modifier::NATIVE)
            {
                isNative = true;
                break;
            }
        }

        if (isNative)
        {
            node.code = commentAsm("MethodDeclaration Start");
            node.code += globalAsm(cg.classMethodLabel(&node));
            node.code += labelAsm(cg.classMethodLabel(&node));
            node.code += methodCallHeader();

            node.code += commentAsm("Push local vars to stack");
            for (int i = 0; i < localVariableCount; i++)
            {
                node.code += "push 0\n";
            }

            node.code += pushCalleeSaveRegs();

            assert(node.parameters->elements.size() == 1);

            node.code += frameOffsetAddr(node.parameters->elements[0]->paramOffset);
            node.code += addrVal();
            node.code += "call " + useLabel("NATIVE" + node.originatingClass->fullyQualifiedName + '.' + node.name->id);

            node.code += popCalleeSaveRegs();
            node.code += methodCallReturn();
            node.code += commentAsm("MethodDeclaration End");
        }

    }
    inMethod = false;
}

std::string CodeGenerator::CodeGenVisitor::ifFalse(ASTNode& node, const std::string& label)
{
    std::string ret = node.code;
    ret += "cmp eax, 0\n";
    ret += "je " + useLabel(label) + '\n';

    return ret;
}

std::string CodeGenerator::CodeGenVisitor::ifTrue(ASTNode& node, const std::string& label)
{
    std::string ret = node.code;
    ret += "cmp eax, 0\n";
    ret += "jne " + useLabel(label) + '\n';

    return ret;
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
    ret += "cmp ebx, eax\n";
    ret += cmpJump + " " + labelA + "\n";
    ret += "mov eax, 0\n";
    ret += "jmp " + labelB + "\n";
    ret += labelAsm(labelA);
    ret += "mov eax, 1\n";
    ret += labelAsm(labelB);
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::addrVal()
{
    return "mov eax, [eax]\n";
}

std::string CodeGenerator::CodeGenVisitor::thisAddr()
{
    return frameOffsetAddr(thisOffset);
}

std::string CodeGenerator::CodeGenVisitor::labelAddr(const std::string& label)
{
    return "mov eax, " + useLabel(label) + "\n";
}

std::string CodeGenerator::CodeGenVisitor::addOffset(int offset)
{
    return "add eax, " + std::to_string(offset) + '\n';
}

std::string CodeGenerator::CodeGenVisitor::frameOffsetAddr(int stackOffset)
{
    std::string ret = "mov eax, ebp\n";
    ret += "add eax, " + std::to_string(stackOffset) + '\n';
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::methodCallHeader()
{
    std::string ret = commentAsm("Method Header");
    ret += "push ebp\n";
    ret += "mov ebp, esp\n";
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::methodCallReturn()
{
    std::string ret = commentAsm("Method Return");
    ret += "mov esp, ebp\n";
    ret += "pop ebp\n";
    ret += "ret\n";
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::pushCalleeSaveRegs()
{
    std::string ret = commentAsm("Pushing Callee Regs");
    ret += "push ebx\n";
    ret += "push esi\n";
    ret += "push edi\n";
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::popCalleeSaveRegs()
{
    std::string ret = commentAsm("Popping Callee Regs");
    ret += "pop edi\n";
    ret += "pop esi\n";
    ret += "pop ebx\n";
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::getClassInfo()
{
    return "mov eax, [eax + " + std::to_string(CLASS_INFO_OFFSET) + "]\n";
}

std::string CodeGenerator::CodeGenVisitor::getSubtypeColumn()
{
    return "mov eax, [eax + " + std::to_string(SUBTYPE_OFFSET) + "]\n";
}

std::string CodeGenerator::CodeGenVisitor::getElementTypeColumn()
{
    return "mov eax, [eax + " + std::to_string(ELEMENT_TYPE_OFFSET) + "]\n";
}

std::string CodeGenerator::CodeGenVisitor::stringConversion(Expression& node)
{
    std::string ret = node.code;

    if (PrimitiveType * primType = dynamic_cast<PrimitiveType*>(node.resolvedType))
    {
        ClassDeclaration* classDecl = nullptr;
        ConstructorDeclaration* constructor = nullptr;
        switch (primType->type)
        {
        case PrimitiveType::BYTE:
            classDecl = cg.global_env.classes["java.lang.Byte"];
            for (MemberDeclaration* member : classDecl->classBody->elements)
            {
                if (ConstructorDeclaration * c = dynamic_cast<ConstructorDeclaration*>(member))
                {
                    if (c->parameters->elements.size() == 1)
                    {
                        FormalParameter* param = c->parameters->elements[0];
                        if (PrimitiveType * arrayType = dynamic_cast<PrimitiveType*>(c->parameters->elements[0]->type))
                        {
                            if (primType->type == PrimitiveType::BYTE)
                            {
                                constructor = c;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case PrimitiveType::SHORT:
            classDecl = cg.global_env.classes["java.lang.Short"];
            for (MemberDeclaration* member : classDecl->classBody->elements)
            {
                if (ConstructorDeclaration * c = dynamic_cast<ConstructorDeclaration*>(member))
                {
                    if (c->parameters->elements.size() == 1)
                    {
                        FormalParameter* param = c->parameters->elements[0];
                        if (PrimitiveType * arrayType = dynamic_cast<PrimitiveType*>(c->parameters->elements[0]->type))
                        {
                            if (primType->type == PrimitiveType::SHORT)
                            {
                                constructor = c;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case PrimitiveType::INT:
            classDecl = cg.global_env.classes["java.lang.Integer"];
            for (MemberDeclaration* member : classDecl->classBody->elements)
            {
                if (ConstructorDeclaration * c = dynamic_cast<ConstructorDeclaration*>(member))
                {
                    if (c->parameters->elements.size() == 1)
                    {
                        FormalParameter* param = c->parameters->elements[0];
                        if (PrimitiveType * arrayType = dynamic_cast<PrimitiveType*>(c->parameters->elements[0]->type))
                        {
                            if (primType->type == PrimitiveType::INT)
                            {
                                constructor = c;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case PrimitiveType::CHAR:
            classDecl = cg.global_env.classes["java.lang.Character"];
            for (MemberDeclaration* member : classDecl->classBody->elements)
            {
                if (ConstructorDeclaration * c = dynamic_cast<ConstructorDeclaration*>(member))
                {
                    if (c->parameters->elements.size() == 1)
                    {
                        FormalParameter* param = c->parameters->elements[0];
                        if (PrimitiveType * arrayType = dynamic_cast<PrimitiveType*>(c->parameters->elements[0]->type))
                        {
                            if (primType->type == PrimitiveType::CHAR)
                            {
                                constructor = c;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case PrimitiveType::BOOLEAN:
            classDecl = cg.global_env.classes["java.lang.Boolean"];
            for (MemberDeclaration* member : classDecl->classBody->elements)
            {
                if (ConstructorDeclaration * c = dynamic_cast<ConstructorDeclaration*>(member))
                {
                    if (c->parameters->elements.size() == 1)
                    {
                        FormalParameter* param = c->parameters->elements[0];
                        if (PrimitiveType * arrayType = dynamic_cast<PrimitiveType*>(c->parameters->elements[0]->type))
                        {
                            if (primType->type == PrimitiveType::BOOLEAN)
                            {
                                constructor = c;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case PrimitiveType::NULL_TYPE:
            // special case
            return commentAsm("String Conversion Start") + createStringFromLiteral(u"null") + commentAsm(" String Conversion End");

        }
        assert(classDecl);
        assert(constructor);

        ret = createFromConstructor(classDecl, constructor, std::vector<std::string>{node.code});
    }

    TypeDeclaration* type = dynamic_cast<TypeDeclaration*>(node.resolvedType);
    if (!type || type->fullyQualifiedName != "java.lang.String")
    {
        std::string nullLabel = cg.freshenLabel("null.to_string");
        std::string endConversion = cg.freshenLabel("to_string.end");

        ret += "cmp eax, 0\n";
        ret += "je " + useLabel(nullLabel) + "\n";

        ClassDeclaration* classDecl = cg.global_env.classes["java.lang.Object"];
        MethodDeclaration* toStringMethod = nullptr;
        for (MemberDeclaration* member : classDecl->classBody->elements)
        {
            if (MethodDeclaration * method = dynamic_cast<MethodDeclaration*>(member))
            {
                if (method->name->id == "toString")
                {
                    toStringMethod = method;
                    break;
                }
            }
        }
        assert(toStringMethod);
        ret += callMethod(toStringMethod, "", std::vector<std::string>());
        ret += "jmp " + useLabel(endConversion) + "\n";
        ret += labelAsm(nullLabel);
        ret += createStringFromLiteral(u"null");
        ret += labelAsm(endConversion) + "\n";
    }
    return commentAsm("String Conversion Start") + ret + commentAsm(" String Conversion End");
}

size_t CodeGenerator::CodeGenVisitor::getTypeSubtypeIndex(Type* type)
{
    QualifiedType* qualified = dynamic_cast<QualifiedType*>(type);
    ArrayType* array = dynamic_cast<ArrayType*>(type);

    size_t type_offset;

    if(qualified)
    {
        TypeDeclaration* decl = dynamic_cast<TypeDeclaration*>(qualified->name->refers_to);
        type_offset = cg.getObjectSubtypeIndex(decl);
    }
    else if (array)
    {
        QualifiedType* carray = dynamic_cast<QualifiedType*>(array->elementType);
        PrimitiveType* parray = dynamic_cast<PrimitiveType*>(array->elementType);

        if(carray)
        {
            TypeDeclaration* decl = dynamic_cast<TypeDeclaration*>(carray->name->refers_to);
            type_offset = cg.getArraySubtypeIndex(decl);
        }
        else if(parray)
        {
            type_offset = cg.getPrimitiveArraySubtypeIndex(parray->type);
        }
        else assert(false);
    }
    else assert(false);

    return type_offset;
}

std::string CodeGenerator::CodeGenVisitor::labelAsm(const std::string& id)
{
    if (!inStaticField)
    {
        return cg.labelAsm(id);
    }
    else
    {
        return cg.staticLabelAsm(id);
    }
}

std::string CodeGenerator::CodeGenVisitor::useLabel(const std::string& label)
{
    if (!inStaticField)
    {
        return cg.useLabel(label);
    }
    else
    {
        return cg.staticUseLabel(label);
    }
}

std::string CodeGenerator::CodeGenVisitor::createFromConstructor(ClassDeclaration* classDecl, ConstructorDeclaration* constructor, std::vector<std::string> codeArgs)
{
    ClassInfo& classInfo = cg.class_infos[classDecl];

    int objSize = (classInfo.fields_prefix.size() + 1) * WORD_SIZE;

    std::string ret = commentAsm("ClassInstanceCreator Start");
    ret += "mov eax, " + std::to_string(objSize) + "\n";
    ret += "call " + useLabel(MALLOC) + "\n";
    ret += "mov dword [eax + " + std::to_string(CLASS_INFO_OFFSET) + "], " + useLabel(cg.classDataLabel(classDecl)) + "\n";

    ret += "push eax\n";

    int object_offset = 0;
    for (std::string code : codeArgs)
    {
        ret += code;
        ret += "push eax\n";
        object_offset += WORD_SIZE;
    }
    ret += labelAddr(cg.constructorLabel(constructor));
    ret += "call eax\n";
    ret += "add esp, " + std::to_string(object_offset) + '\n';
    ret += "pop eax\n";
    ret += commentAsm("ClassInstanceCreator End");
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::createArrayFromLabel(const std::string& label, const std::string& argument)
{
    std::string ret = commentAsm("ArrayCreator Start");
    ret += argument;
    ret += "push eax\n";
    ret += "imul eax, " + std::to_string(WORD_SIZE) + '\n';
    ret += "add eax, 8\n"; // Add 2 words one for class info and 1 for length

    ret += "call " + useLabel(MALLOC) + "\n";
    ret += "mov dword [eax + " + std::to_string(CLASS_INFO_OFFSET) + "], " + useLabel(label) + "\n";
    ret += "pop ebx\n";
    ret += "mov dword [eax + " + std::to_string(FIELDS_OFFSET) + "], ebx\n";
    ret += commentAsm("ArrayCreator End");
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::callMethod(MethodDeclaration* method, const std::string& object, std::vector<std::string> codeArgs)
{
    assert(method);
    std::string ret; 

    if (cg.method_prefix_indices.find(method) != cg.method_prefix_indices.end())
    {
        size_t method_prefix_index = cg.method_prefix_indices[method] * WORD_SIZE + METHODS_OFFSET;

        ret = commentAsm("MethodCall Start");
        ret += commentAsm("Calling " + method->originatingClass->fullyQualifiedName + '.' + method->name->id);
        ret += object;
        ret += cg.nullCheckAsm();
        ret += "push eax\n";

        size_t object_offset = 0;

        for (std::string code : codeArgs)
        {
            ret += code;
            ret += "push eax\n";
            object_offset += WORD_SIZE;
        }

        ret += "mov eax, [esp + " + std::to_string(object_offset) + "]\n";
        ret += "mov eax, [eax + " + std::to_string(CLASS_INFO_OFFSET) + "]\n";
        ret += "mov eax, [eax + " + std::to_string(method_prefix_index) + "]\n";
        ret += "call eax\n";
        ret += "add esp, " + std::to_string(object_offset + WORD_SIZE) + '\n';
        ret += commentAsm("MethodCall End");
    }
    else
    {
        assert(cg.unique_method_signatures.find(method->getSignature()) != cg.unique_method_signatures.end());
        size_t sit_index = cg.unique_method_signatures[method->getSignature()];

        ret = commentAsm("MethodCall Start (Interface method)");
        // NOTE: method->originatingClass may be nullptr
        ret += commentAsm("Calling " + (method->originatingClass ? method->originatingClass->fullyQualifiedName : "Object") + '.' + method->name->id);
        ret += object;
        ret += cg.nullCheckAsm();
        ret += "push eax\n";

        size_t object_offset = 0;

        for (std::string code : codeArgs)
        {
            ret += code;
            ret += "push eax\n";
            object_offset += WORD_SIZE;
        }

        ret += "mov eax, [esp + " + std::to_string(object_offset) + "]\n";
        ret += "mov eax, [eax + " + std::to_string(CLASS_INFO_OFFSET) + "]\n";
        ret += "mov eax, [eax + " + std::to_string(SIT_OFFSET) + "]\n";
        ret += "mov eax, [eax + " + std::to_string(sit_index * WORD_SIZE) + "]\n";
        ret += "call eax\n";
        ret += "add esp, " + std::to_string(object_offset + WORD_SIZE) + '\n';
        ret += commentAsm("MethodCall End");
    }
    
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::callStaticMethod(MethodDeclaration* method, std::vector<std::string> codeArgs)
{
    assert(method);
    assert(cg.method_prefix_indices.find(method) != cg.method_prefix_indices.end());
    size_t method_prefix_index = cg.method_prefix_indices[method] * WORD_SIZE + METHODS_OFFSET;

    std::string ret = commentAsm("StaticMethodCall Start");
    ret += commentAsm("Calling " + (method->originatingClass ? method->originatingClass->fullyQualifiedName : "Object") + '.' + method->name->id);

    size_t object_offset = 0;

    for (std::string code : codeArgs)
    {
        ret += code;
        ret += "push eax\n";
        object_offset += WORD_SIZE;
    }

    ret += "mov eax, " + useLabel(cg.classMethodLabel(method)) + "\n";
    ret += "call eax\n";
    ret += "add esp, " + std::to_string(object_offset) + '\n';
    ret += commentAsm("StaticMethodCall End");
    return ret;
}

std::string CodeGenerator::CodeGenVisitor::createStringFromLiteral(const std::u16string& str)
{
    std::string label = cg.primitiveArrayDataLabel(PrimitiveType::CHAR);
    // Find the char[] constructor of String
    ClassDeclaration* classDecl = dynamic_cast<ClassDeclaration*>(cg.global_env.classes["java.lang.String"]);
    assert(classDecl);
    ClassInfo& classInfo = cg.class_infos[classDecl];

    ConstructorDeclaration* constructor = nullptr;
    for (MemberDeclaration* member : classDecl->classBody->elements)
    {
        if (ConstructorDeclaration * c = dynamic_cast<ConstructorDeclaration*>(member))
        {
            if (c->parameters->elements.size() == 1)
            {
                FormalParameter* param = c->parameters->elements[0];
                if (ArrayType * arrayType = dynamic_cast<ArrayType*>(param->type))
                {
                    if (PrimitiveType * primType = dynamic_cast<PrimitiveType*>(arrayType->elementType))
                    {
                        if (primType->type == PrimitiveType::CHAR)
                        {
                            constructor = c;
                            break;
                        }
                    }
                }
            }
        }
    }
    assert(constructor);

    std::string charArrayCode = commentAsm("Creating Char[]");
    charArrayCode += createArrayFromLabel(cg.primitiveArrayDataLabel(PrimitiveType::CHAR), "mov eax, " + std::to_string(str.size()) + "\n");
    for (int i = 0; i < str.size(); i++)
    {
        charArrayCode += "mov dword [eax + " + std::to_string((i + 1) * WORD_SIZE + FIELDS_OFFSET) + "], " + std::to_string(str[i]) + "\n";
    }
    charArrayCode += commentAsm("Char[] End");

    std::string ret = commentAsm("StringLiteral Start");
    ret += createFromConstructor(classDecl, constructor, std::vector<std::string>{ charArrayCode });
    ret += commentAsm("StringLiteral End");
    return ret;
}
