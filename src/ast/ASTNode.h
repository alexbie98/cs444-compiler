#pragma once

#include <string>
#include <vector>

struct ASTNode
{
    virtual ~ASTNode() = default;
};

template<typename T>
struct ASTNodeList : public ASTNode
{
    std::vector<T*> elements;
};

struct Expression : public ASTNode
{
    virtual ~Expression() = default;
};

struct Statement : public ASTNode
{
    virtual ~Statement() = default;
};

struct Type : public ASTNode
{
    virtual ~Type() = default;
};

struct Name : public Expression
{
};

struct SimpleName : public Name
{
    virtual ~SimpleName() = default;
    std::string id;
};

struct QualifiedName : public Name
{
    virtual ~QualifiedName() = default;
    Name* name;
    SimpleName* simpleName;
};

struct IntLiteral : public Expression
{
    int value;
};

struct CharLiteral : public Expression
{
    char value;
};

struct StringLiteral : public Expression
{
    std::string value;
};

struct BooleanLiteral : public Expression
{
    bool value;
};

struct NullLiteral : public Expression
{
};

struct BinaryOperation : public Expression
{
    virtual ~BinaryOperation() = default;

    enum OperatorType
    {
        PLUS,
        MINUS,
        TIMES,
        DIVIDE,
        REMAINDER,
        AND,
        OR,
        EAGER_AND,
        EAGER_OR,
        XOR,
        EQ,
        NEQ,
        LEQ,
        GEQ,
        LT,
        GT
    };

    Expression* lhs;
    Expression* rhs;
    OperatorType op;
};

struct PrefixOperation : public Expression
{
    virtual ~PrefixOperation() = default;

    enum OperatorType
    {
        MINUS,
        NOT
    };
    OperatorType op;
    Expression* operand;
};

struct CastExpression : public Expression
{
    Type* castType;
    Expression* expression;
};

struct AssignmentExpression : public Expression
{
    Expression* lhs;
    Expression* rhs;
};

struct ParenthesizedExpression : public Expression
{
    Expression* expr;
};

struct ClassInstanceCreator : public Expression
{
    Type* type;
    ASTNodeList<Expression>* arguments;
};

struct ArrayCreator : public Expression
{
    ArrayType* type;
    Expression argument;
};

struct ChainableExpression : public Expression
{
    Expression* prevExpr;
};

struct MethodCall : public ChainableExpression
{
    SimpleName* name;
    ASTNodeList<Expression>* arguments;
};

struct FieldAccess : public ChainableExpression
{
    SimpleName* name;
};

struct ArrayAccess : public ChainableExpression
{
    Expression* indexExpr;
};

struct ThisExpression : public ChainableExpression
{
    Expression* expression;
};

struct VariableDeclarationExpression : public Expression
{
    Type* type;
    SimpleName* name;
    Expression* initializer;
};

struct InstanceOfExpression : public Expression
{
    Expression* expression;
    Type* type;
};

struct ExpressionStatement : public Statement
{
    Expression* expression;
};

struct EmptyStatement : public Statement
{
};

struct ReturnStatement : public Statement
{
    Expression* expression;
};

struct IfStatement : public Statement
{
    Expression* ifCondition;
    Statement* ifBody;
    Statement* elseBody;
};

struct ForStatement : public Statement
{
    Expression* forInit;
    Expression* forCheck;
    Expression* forUpdate;

    Statement* body;
};

struct WhileStatement : public Statement
{
    Expression* condition;
    Statement* body;
};

struct Block : public Statement
{
    ASTNodeList<Statement>* statements;
};

struct PrimitiveType : public Type
{
    enum BasicType
    {
        BYTE,
        SHORT,
        INT,
        CHAR,
        BOOLEAN,
        VOID
    };

    BasicType type;
};

struct QualifiedType : public Type
{
    Name* name;
};

struct ArrayType : public Type
{
    Type* elementType;
};

struct PackageDeclaration : public ASTNode
{
    Name* name;
};

struct ImportDeclaration : public ASTNode
{
    Name* name;
    bool declareAll;
};

struct Modifier : public ASTNode
{
    enum ModifierType
    {
        PUBLIC,
        PROTECTED,
        ABSTRACT,
        FINAL,
        STATIC,
        NATIVE
    };
    ModifierType type;
};

struct TypeDeclaration : public ASTNode
{

};

struct MemberDeclaration : public ASTNode
{

};

struct ClassDeclaration : public TypeDeclaration
{
    SimpleName* name;
    Type* baseType;
    ASTNodeList<Type>* interfaces;

    ASTNodeList<MemberDeclaration>* classBody;
};

struct InterfaceDeclaration : public TypeDeclaration
{
    SimpleName* name;
    ASTNodeList<Type>* extends;

    ASTNodeList<MemberDeclaration>* interfaceBody;
};

struct FormalParameter : public ASTNode
{
    Type* type;
    Name* id;
};

struct ConstructorDeclaration : public MemberDeclaration
{
    ASTNodeList<FormalParameter>* parameters;
    Block* body;
};

struct FieldDeclaration : public MemberDeclaration
{
    VariableDeclarationExpression* declaration;
};

struct MethodDeclaration : public MemberDeclaration
{
    Type* type;
    Name* id;
    ASTNodeList<FormalParameter>* parameters;
    Block* body;
};