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

    std::vector<MethodDeclaration *>* column;
    ClassInfo* class_info;
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

void CodeGenerator::CodeGenVisitor::leave(IntLiteral& node)
{
    node.code = "mov eax, " + std::to_string(node.value);
}

void CodeGenerator::CodeGenVisitor::leave(CharLiteral& node)
{
    node.code = "mov eax, " + std::to_string(node.value);
}

void CodeGenerator::CodeGenVisitor::leave(BooleanLiteral& node)
{
    node.code = "mov eax, " + node.value ? "1" : "0";
}

void CodeGenerator::CodeGenVisitor::leave(NullLiteral& node)
{
    node.code = "mov eax, 0";
}
