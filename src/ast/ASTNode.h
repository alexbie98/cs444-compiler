#pragma once

#include <string>
#include <vector>

template<typename T> struct ASTNodeList;
struct Expression;
struct Statement;
struct Type;
struct Name;
struct SimpleName;
struct QualifiedName;
struct PrimitiveType;
struct QualifiedType;
struct ArrayType;
struct IntLiteral;
struct CharLiteral;
struct StringLiteral;
struct BooleanLiteral;
struct NullLiteral;
struct BinaryOperation;
struct PrefixOperation;
struct CastExpression;
struct AssignmentExpression;
struct ParenthesizedExpression;
struct ClassInstanceCreator;
struct ArrayCreator;
struct ChainableExpression;
struct MethodCall;
struct FieldAccess;
struct ArrayAccess;
struct ThisExpression;
struct VariableDeclarationExpression;
struct InstanceOfExpression;
struct ExpressionStatement;
struct EmptyStatement;
struct ReturnStatement;
struct IfStatement;
struct ForStatement;
struct WhileStatement;
struct Block;
struct PackageDeclaration;
struct ImportDeclaration;
struct Modifier;
struct TypeDeclaration;
struct MemberDeclaration;
struct ClassDeclaration;
struct InterfaceDeclaration;
struct FormalParameter;
struct ConstructorDeclaration;
struct FieldDeclaration;
struct MethodDeclaration;
struct CompilerUnit;

struct ASTNodeVisitor
{
    virtual void visit(ASTNodeList<Type>& node) {};
    virtual void visit(ASTNodeList<Modifier>& node) {};
    virtual void visit(ASTNodeList<Statement>& node) {};
    virtual void visit(ASTNodeList<Expression>& node) {};
    virtual void visit(ASTNodeList<FormalParameter>& node) {};
    virtual void visit(ASTNodeList<ImportDeclaration>& node) {};
    virtual void visit(ASTNodeList<MemberDeclaration>& node) {};

    virtual void visit(Expression& node) {};
    virtual void visit(Statement& node) {};
    virtual void visit(Type& node) {};
    virtual void visit(Name& node) {};
    virtual void visit(SimpleName& node) {};
    virtual void visit(QualifiedName& node) {};
    virtual void visit(PrimitiveType& node) {};
    virtual void visit(QualifiedType& node) {};
    virtual void visit(ArrayType& node) {};
    virtual void visit(IntLiteral& node) {};
    virtual void visit(CharLiteral& node) {};
    virtual void visit(StringLiteral& node) {};
    virtual void visit(BooleanLiteral& node) {};
    virtual void visit(NullLiteral& node) {};
    virtual void visit(BinaryOperation& node) {};
    virtual void visit(PrefixOperation& node) {};
    virtual void visit(CastExpression& node) {};
    virtual void visit(AssignmentExpression& node) {};
    virtual void visit(ParenthesizedExpression& node) {};
    virtual void visit(ClassInstanceCreator& node) {};
    virtual void visit(ArrayCreator& node) {};
    virtual void visit(ChainableExpression& node) {};
    virtual void visit(MethodCall& node) {};
    virtual void visit(FieldAccess& node) {};
    virtual void visit(ArrayAccess& node) {};
    virtual void visit(ThisExpression& node) {};
    virtual void visit(VariableDeclarationExpression& node) {};
    virtual void visit(InstanceOfExpression& node) {};
    virtual void visit(ExpressionStatement& node) {};
    virtual void visit(EmptyStatement& node) {};
    virtual void visit(ReturnStatement& node) {};
    virtual void visit(IfStatement& node) {};
    virtual void visit(ForStatement& node) {};
    virtual void visit(WhileStatement& node) {};
    virtual void visit(Block& node) {};
    virtual void visit(PackageDeclaration& node) {};
    virtual void visit(ImportDeclaration& node) {};
    virtual void visit(Modifier& node) {};
    virtual void visit(TypeDeclaration& node) {};
    virtual void visit(MemberDeclaration& node) {};
    virtual void visit(ClassDeclaration& node) {};
    virtual void visit(InterfaceDeclaration& node) {};
    virtual void visit(FormalParameter& node) {};
    virtual void visit(ConstructorDeclaration& node) {};
    virtual void visit(FieldDeclaration& node) {};
    virtual void visit(MethodDeclaration& node) {};
    virtual void visit(CompilerUnit& node) {};
};

struct ASTNode
{
    virtual ~ASTNode() = default;
    virtual void accept(ASTNodeVisitor& v) = 0;
    virtual void visitAll(ASTNodeVisitor& v) = 0;
};

template<typename T>
struct ASTNodeList : public ASTNode
{
    std::vector<T*> elements;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { for(T* e: elements) e->accept(v); }
};

struct Expression : public ASTNode
{
    virtual ~Expression() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct Statement : public ASTNode
{
    virtual ~Statement() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct Type : public ASTNode
{
    virtual ~Type() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct Name : public Expression
{
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct SimpleName : public Name
{
    virtual ~SimpleName() = default;
    std::string id;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct QualifiedName : public Name
{
    virtual ~QualifiedName() = default;
    Name* name;
    SimpleName* simpleName;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { name->visitAll(v); simpleName->visitAll(v); }
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
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct QualifiedType : public Type
{
    Name* name;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { name->visitAll(v); }
};

struct ArrayType : public Type
{
    Type* elementType;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { elementType->visitAll(v); }
};


struct IntLiteral : public Expression
{
    int value;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct CharLiteral : public Expression
{
    char value;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct StringLiteral : public Expression
{
    std::string value;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct BooleanLiteral : public Expression
{
    bool value;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct NullLiteral : public Expression
{
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
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
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { lhs->visitAll(v); rhs->visitAll(v); }
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
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { operand->visitAll(v); }
};

struct CastExpression : public Expression
{
    Type* castType;
    Expression* expression;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { castType->visitAll(v); expression->visitAll(v); }
};

struct AssignmentExpression : public Expression
{
    Expression* lhs;
    Expression* rhs;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { lhs->visitAll(v); rhs->visitAll(v); }
};

struct ParenthesizedExpression : public Expression
{
    Expression* expr;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { expr->visitAll(v); }
};

struct ClassInstanceCreator : public Expression
{
    Type* type;
    ASTNodeList<Expression>* arguments;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { type->visitAll(v); arguments->visitAll(v); }
};

struct ArrayCreator : public Expression
{
    ArrayType* type;
    Expression* argument;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { type->visitAll(v); argument->visitAll(v); }
};

struct ChainableExpression : public Expression
{
    Expression* prevExpr;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { prevExpr->visitAll(v); }
};

struct MethodCall : public ChainableExpression
{
    SimpleName* name;
    ASTNodeList<Expression>* arguments;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { name->visitAll(v); arguments->visitAll(v); }
};

struct FieldAccess : public ChainableExpression
{
    SimpleName* name;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { name->visitAll(v); }
};

struct ArrayAccess : public ChainableExpression
{
    Expression* indexExpr;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { indexExpr->visitAll(v); }
};

struct ThisExpression : public ChainableExpression
{
    Expression* expression;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { expression->visitAll(v); }
};

struct VariableDeclarationExpression : public Expression
{
    Type* type;
    SimpleName* name;
    Expression* initializer;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { type->visitAll(v); name->visitAll(v); initializer->visitAll(v); }
};

struct InstanceOfExpression : public Expression
{
    Expression* expression;
    Type* type;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { expression->visitAll(v); type->visitAll(v); }
};

struct ExpressionStatement : public Statement
{
    Expression* expression;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { expression->visitAll(v); }
};

struct EmptyStatement : public Statement
{
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct ReturnStatement : public Statement
{
    Expression* expression;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { expression->visitAll(v); }
};

struct IfStatement : public Statement
{
    Expression* ifCondition;
    Statement* ifBody;
    Statement* elseBody;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { ifCondition->visitAll(v); ifBody->visitAll(v); elseBody->visitAll(v); }
};

struct ForStatement : public Statement
{
    Expression* forInit;
    Expression* forCheck;
    Expression* forUpdate;

    Statement* body;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { forInit->visitAll(v); forCheck->visitAll(v); forUpdate->visitAll(v); body->visitAll(v); }
};

struct WhileStatement : public Statement
{
    Expression* condition;
    Statement* body;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { condition->visitAll(v); body->visitAll(v); }
};

struct Block : public Statement
{
    ASTNodeList<Statement>* statements;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { statements->visitAll(v); }
};

struct PackageDeclaration : public ASTNode
{
    Name* name;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { name->visitAll(v); }
};

struct ImportDeclaration : public ASTNode
{
    Name* name;
    bool declareAll;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { name->visitAll(v); }
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
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) {};
};

struct TypeDeclaration : public ASTNode
{
    ASTNodeList<Modifier>* modifiers;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { modifiers->visitAll(v); }
};

struct MemberDeclaration : public ASTNode
{
    ASTNodeList<Modifier>* modifiers;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { modifiers->visitAll(v); }
};

struct ClassDeclaration : public TypeDeclaration
{
    SimpleName* name;
    Type* baseType;
    ASTNodeList<Type>* interfaces;

    ASTNodeList<MemberDeclaration>* classBody;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { name->visitAll(v); baseType->visitAll(v); interfaces->visitAll(v); classBody->visitAll(v); }
};

struct InterfaceDeclaration : public TypeDeclaration
{
    SimpleName* name;
    ASTNodeList<Type>* extends;

    ASTNodeList<MemberDeclaration>* interfaceBody;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { name->visitAll(v); extends->visitAll(v); interfaceBody->visitAll(v); }
};

struct FormalParameter : public ASTNode
{
    Type* type;
    Name* id;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { type->visitAll(v); id->visitAll(v); }
};

struct ConstructorDeclaration : public MemberDeclaration
{
    ASTNodeList<FormalParameter>* parameters;
    Block* body;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { parameters->visitAll(v); body->visitAll(v);}
};

struct FieldDeclaration : public MemberDeclaration
{
    VariableDeclarationExpression* declaration;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { declaration->visitAll(v); }
};

struct MethodDeclaration : public MemberDeclaration
{
    Type* type;
    Name* name;
    ASTNodeList<FormalParameter>* parameters;
    Block* body;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { type->visitAll(v); name->visitAll(v); parameters->visitAll(v); body->visitAll(v);}
};

struct CompilerUnit : public ASTNode
{
    PackageDeclaration* packageDecl;
    ASTNodeList<ImportDeclaration>* importDecls;
    TypeDeclaration* typeDecl;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) { packageDecl->visitAll(v); importDecls->visitAll(v); typeDecl->visitAll(v); }
};
