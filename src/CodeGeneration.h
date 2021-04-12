#pragma once

#include <unordered_map>
#include <vector>
#include <set>
#include "ast/ASTNode.h"

struct ClassInfo
{
    // SIT column can be obtained using sit_table map in CodeGenerator 
    // TODO Link it here?
    // std::string sit_column; // Label corresponding to address of column
    size_t subtype_column; // Index of subtype column in the subtype table

    // Mapping from signature to MethodDeclaration and its index in the method list
    std::unordered_map<std::string, std::pair<MethodDeclaration*, size_t> > methods_prefix; // Methods could be abstract

    // Mapping from field name to index in fields prefix
    std::unordered_map<std::string, std::pair<FieldDeclaration*, size_t> > fields_prefix;
};

class CodeGenerator
{
    Environment& global_env;
    ClassDeclaration* object_class_decl;

    // Map from MethodDeclarations to the selector index they correspond to
    std::unordered_map<MethodDeclaration*, size_t> sit_indices;

    // Map from MethodDeclarations/FieldDeclarations to their index in the method/field list of their classes info
    std::unordered_map<MethodDeclaration*, size_t> method_prefix_indices;
    std::unordered_map<FieldDeclaration*, size_t> field_prefix_indices;

    // Structures to be turned into code during generation
    size_t sit_column_size = 0;
    std::unordered_map<ClassDeclaration*, std::vector<MethodDeclaration*> > sit_table;
    std::vector<MethodDeclaration*> array_sit_column;
    std::unordered_map<ClassDeclaration*, ClassInfo> class_infos;
    std::unordered_map<TypeDeclaration*, ClassInfo> array_class_infos;
    std::unordered_map<PrimitiveType::BasicType, ClassInfo> primitive_array_class_infos;
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
    size_t getArraySubtypeIndex(TypeDeclaration* type){ size_t i = subtype_table_object_index[type] + subtype_table_object_index.size(); assert(i < subtype_column_count); return i; }
    size_t getObjectSubtypeIndex(TypeDeclaration* type){ size_t i = subtype_table_object_index[type]; assert(i < subtype_column_count); return i; }
    size_t getPrimitiveArraySubtypeIndex(PrimitiveType::BasicType type){ size_t i = subtype_table_primitive_array_index[type]; assert(i < subtype_column_count); return i; }

    std::unordered_map<FieldDeclaration*, ClassDeclaration*> static_fields;
    std::unordered_map<MethodDeclaration*, ClassDeclaration*> static_methods;

    // Assembly helpers
    static const std::string SUBTYPE_COLUMN_COUNT_LABEL;
    static const std::string SUBTYPE_TABLE_LABEL;
    static const std::string EXCEPTION;
    static const std::string DEXIT;
    static const std::string MALLOC;
    static const size_t WORD_SIZE = 4;
    static const size_t CLASS_INFO_OFFSET = 0;
    static const size_t FIELDS_OFFSET = 4;
    static const size_t SIT_OFFSET = 0;
    static const size_t SUBTYPE_OFFSET = 4;
    static const size_t METHODS_OFFSET = 8;

    static const std::string TEXT_DIR;
    static const std::string DATA_DIR;

    size_t fresh_label_counter = 0;

    std::string labelAsm(std::string id){ defined_labels.insert(id); return id + ":\n"; }
    static std::string directiveAsm(std::string id){ return "section ." + id + "\n"; }
    static std::string wordAsm(int value){ return "dd " + std::to_string(value) + "\n"; }
    static std::string wordAsm(std::string label){ return "dd " + label + "\n"; }
    static std::string byteAsm(uint8_t value){ return "db " + std::to_string(value) + "\n"; }
    static std::string commentAsm(std::string comment){ return "; " + comment + "\n"; }

    static std::string externAsm(std::string id){ return "extern " + id + "\n"; }
    static std::string globalAsm(std::string id){ return "global " + id + "\n"; }

    // Performs a null check on eax
    std::string nullCheckAsm();
    std::string runtimeExternsAsm();

    // TODO Make helpers for generating assembly to access class data members
    std::string classDataLabel(TypeDeclaration* decl){ return "class_info_" + decl->fullyQualifiedName; }
    std::string classArrayDataLabel(TypeDeclaration* decl){ return "carray_info_" + decl->fullyQualifiedName; }
    std::string primitiveArrayDataLabel(PrimitiveType::BasicType type){ return "parray_info_" + PrimitiveType::basicTypeToString(type); }
    std::string classMethodLabel(MethodDeclaration* method)
    { 
        ClassDeclaration* containing_class = dynamic_cast<ClassDeclaration*>(containingType(method));
        assert(containing_class);
        return method->getSignature() + "_class_" + containing_class->fullyQualifiedName; 
    }
    std::string constructorLabel(ConstructorDeclaration* constructor)
    {
        ClassDeclaration* containing_class = dynamic_cast<ClassDeclaration*>(containingType(constructor));
        assert(containing_class);
        return constructor->getSignature() + "_class_" + containing_class->fullyQualifiedName;
    }
    std::string sitColumnClassLabel(ClassDeclaration* decl){ return "c_sit_column_" + decl->fullyQualifiedName; }
    std::string sitColumnClassArrayLabel(ClassDeclaration* decl){ return "carray_sit_column_" + decl->fullyQualifiedName; }
    std::string sitColumnPrimArrayLabel(PrimitiveType::BasicType type){ return "parray_sit_column_" + PrimitiveType::basicTypeToString(type); }
    std::string freshenLabel(std::string label){ return label + "_" + std::to_string(fresh_label_counter++); }

    TypeDeclaration* containingType(MethodDeclaration* method)
    {
        assert(dynamic_cast<TypeDeclaration*>(method->parent->parent));
        return dynamic_cast<TypeDeclaration*>(method->parent->parent);
    }

    TypeDeclaration* containingType(ConstructorDeclaration* constructor)
    {
        assert(dynamic_cast<TypeDeclaration*>(constructor->parent->parent));
        return dynamic_cast<TypeDeclaration*>(constructor->parent->parent);
    }

    enum class ObjectType
    {
        OBJECT,
        OBJECT_ARRAY,
        PRIMITIVE_ARRAY
    };

    std::set<std::string> used_labels;
    std::set<std::string> defined_labels;
    std::string useLabel(std::string label){ used_labels.insert(label); return label; };
    std::string writeExterns(); // Writes neccessary externs and resets

    std::string generateObjectCode(TypeDeclaration* root, ObjectType otype, PrimitiveType::BasicType ptype = PrimitiveType::BasicType(0));
    
public:

    class CodeGenVisitor : public ASTNodeVisitor
    {
        int thisOffset = 0;
        int formalParameterCount = 0;
        int localVariableCount = 0;

        bool inMethod = false;
        CodeGenerator& cg;

        std::string staticFieldInitializers;

    public:
        CodeGenVisitor(CodeGenerator& code_generator) : cg{ code_generator } {};

        virtual void visit(MethodDeclaration& node);
        virtual void visit(ConstructorDeclaration& node);
        virtual void visit(FormalParameter& node);
        virtual void visit(VariableDeclarationExpression& node);

        virtual void leave(IntLiteral& node);
        virtual void leave(CharLiteral& node);
        virtual void leave(StringLiteral& node);
        virtual void leave(BooleanLiteral& node);
        virtual void leave(NullLiteral& node);
        virtual void leave(NameExpression& node);
        virtual void leave(BinaryOperation& node);
        virtual void leave(PrefixOperation& node);
        virtual void leave(CastExpression& node);
        virtual void leave(AssignmentExpression& node);
        virtual void leave(ParenthesizedExpression& node);
        virtual void leave(ClassInstanceCreator& node);
        virtual void leave(ArrayCreator& node);
        virtual void leave(FieldAccess& node);
        virtual void leave(MethodCall& node);
        virtual void leave(ArrayAccess& node);
        virtual void leave(ThisExpression& node);
        virtual void leave(VariableDeclarationExpression& node);
        virtual void leave(InstanceOfExpression& node);
        virtual void leave(ExpressionStatement& node);
        virtual void leave(ReturnStatement& node);
        virtual void leave(IfStatement& node);
        virtual void leave(ForStatement& node);
        virtual void leave(WhileStatement& node);
        virtual void leave(Block& node);
        virtual void leave(ClassDeclaration& node);
        virtual void leave(InterfaceDeclaration& node);
        virtual void leave(ConstructorDeclaration& node);
        virtual void leave(FieldDeclaration& node);
        virtual void leave(MethodDeclaration& node);

    private:
        std::string ifFalse(ASTNode& node, const std::string& label);
        std::string ifTrue(ASTNode& node, const std::string& label);
        std::string evaluateTwoNodes(ASTNode& lhs, ASTNode& rhs); // lhs in ebx, rhs in eax
        std::string cmpOperation(ASTNode& lhs, ASTNode& rhs, const std::string& cmpJump, const std::string& labelA, const std::string& labelB);
        std::string addrVal();

        std::string addOffset(int offset);
        std::string frameOffsetAddr(int stackOffset);
        std::string thisAddr();
        std::string labelAddr(const std::string& label);

        std::string methodCallHeader();
        std::string methodCallReturn();
        std::string pushCalleeSaveRegs();
        std::string popCalleeSaveRegs();

        std::string getClassInfo();
        std::string getSubtypeColumn();

        std::string stringConversion(Expression& node);
        size_t getTypeSubtypeIndex(Type* type);

        std::string labelAsm(const std::string& id){ return cg.labelAsm(id); }
        std::string useLabel(const std::string& label){ return cg.useLabel(label); };

        std::string createFromConstructor(ClassDeclaration* classDecl, ConstructorDeclaration* constructor, std::vector<std::string> codeArgs);
        std::string createArrayFromLabel(const std::string& label, const std::string& argument);
        std::string callMethod(MethodDeclaration* method, const std::string& object, std::vector<std::string> codeArgs);
        std::string createStringFromLiteral(const std::u16string& string);
    };

    CodeGenerator(Environment& globalEnv);
    std::string generateCommon();
    std::string generateClassCode(ClassDeclaration* root); // Generates code for object and it's array
    std::string generatePrimitiveArrayCode(PrimitiveType::BasicType type);
    std::string generateInterfaceArrayCode(InterfaceDeclaration* root);
};