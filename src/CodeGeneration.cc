#include "CodeGeneration.h"

#include <unordered_map>

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
                    if(class_info.methods_prefix.find(method->getSignature()) == class_info.methods_prefix.end())
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

CodeGenerator::CodeGenerator(Environment& globalEnv)
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

    // Add all methods that match an interface signature, regardless of whether they did in fact implement an interface method.
    // Type checking should have already not allowed an interface method access from a class that doesnt implement that interface.
    for(auto it: globalEnv.classes)
    {
        // Create empty SIT column
        sit_table[it.second] = std::vector<MethodDeclaration*>(sit_column_size, nullptr);

        for(MemberDeclaration* member: it.second->classBody->elements)
        {
            MethodDeclaration* method = dynamic_cast<MethodDeclaration*>(member);

            if(method)
            {
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
}

std::string generateCommon()
{
    return "";
}

std::string generateFileCode(ASTNode* root)
{
    return "";
}