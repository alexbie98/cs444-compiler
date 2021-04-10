#include <unordered_map>
#include <vector>
#include "ast/ASTNode.h"

struct ClassInfo
{
    // std::string sit_column; // Label corresponding to address of column
    size_t subtype_column; // Index of subtype column in the subtype table

    // Mapping from signature to MethodDeclaration and its index in the method list
    std::unordered_map<std::string, std::pair<MethodDeclaration*, size_t> > methods_prefix; // Methods could be abstract

    // Mapping from field name to index in fields prefix
    std::unordered_map<std::string, std::pair<FieldDeclaration*, size_t> > fields_prefix;
};

class CodeGenerator
{
    // Map from MethodDeclarations to the selector index they correspond to
    std::unordered_map<MethodDeclaration*, size_t> sit_indices;

    // Map from MethodDeclarations/FieldDeclarations to their index in the method/field list of their classes info
    std::unordered_map<MethodDeclaration*, size_t> method_prefix_indices;
    std::unordered_map<FieldDeclaration*, size_t> field_prefix_indices;

    // Structures to be turned into code during generation
    size_t sit_column_size = 0;
    std::unordered_map<ClassDeclaration*, std::vector<MethodDeclaration*> > sit_table;
    std::unordered_map<ClassDeclaration*, ClassInfo> class_infos;
    size_t subtype_column_count = 0;
    std::vector< std::vector<bool> > subtype_table; // Interfaces in columns are not used, first index is columns.
    // Columns/rows are classes, interfaces (column unused), class arrays, interface arrays (column unused), primitive arrays in that order
    // Table is square for simplicity

    // Mappings from objects, arrays of objects, and arrays of primitives to their indices in the subtype_table
    std::unordered_map<TypeDeclaration*, size_t > subtype_table_object_index;
    std::unordered_map<PrimitiveType::BasicType, size_t > subtype_table_primitive_array_index;

    // Also creates ClassInfos
    void createMethodAndFieldPrefixes(ClassDeclaration* decl);

    void createSubtypeInfo(ClassDeclaration* class_decl, TypeDeclaration* subtype);
    size_t getArraySubtypeIndex(TypeDeclaration* type){ return subtype_table_object_index[type] + subtype_table_object_index.size(); }
    size_t getObjectSubtypeIndex(TypeDeclaration* type){ return subtype_table_object_index[type]; }
    size_t getPrimitiveArraySubtypeIndex(PrimitiveType::BasicType type){ return subtype_table_primitive_array_index[type]; }

    std::unordered_map<FieldDeclaration*, ClassDeclaration*> static_fields;
    std::unordered_map<MethodDeclaration*, ClassDeclaration*> static_methods;
    
public:
    CodeGenerator(Environment& globalEnv);

    std::string generateCommon();
    std::string generateFileCode(ASTNode* root);
};