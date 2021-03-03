#pragma once

#include <string>
#include <vector>

template<typename T> struct ASTNodeList;
struct Expression; // abstract
struct Statement; // abstract
struct Type; // abstract
struct Name; // abstract
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
struct ChainableExpression; // abstract
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
struct TypeDeclaration;  // abstract
struct MemberDeclaration;  // abstract
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
    virtual void visit(ClassDeclaration& node) {};
    virtual void visit(InterfaceDeclaration& node) {};
    virtual void visit(FormalParameter& node) {};
    virtual void visit(ConstructorDeclaration& node) {};
    virtual void visit(FieldDeclaration& node) {};
    virtual void visit(MethodDeclaration& node) {};
    virtual void visit(CompilerUnit& node) {};
};

struct ASTNode // Abstract
{
    virtual ~ASTNode() = default;
    virtual void accept(ASTNodeVisitor& v) = 0;
    virtual void visitAll(ASTNodeVisitor& v);
};

template<typename T>
struct ASTNodeList : public ASTNode
{
    std::vector<T*> elements;

    virtual ~ASTNodeList()
    {
        for (T* e : elements)
        {
            delete e;
        }
    }
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) 
    {
        accept(v);
        for(T* e: elements) e->accept(v); 
    }
};

struct Expression : public ASTNode //abstract
{
    virtual ~Expression() = default;
};

struct Statement : public ASTNode // abstract
{
    virtual ~Statement() = default;
};

struct Type : public ASTNode // abstract
{
    virtual ~Type() = default;
};

struct Name : public Expression // abstract
{
    virtual ~Name() = default;
};

struct SimpleName : public Name
{
    std::string id;

    virtual ~SimpleName() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
};

struct QualifiedName : public Name
{
    Name* name;
    SimpleName* simpleName;

    virtual ~QualifiedName();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
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

    virtual ~PrimitiveType() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
};

struct QualifiedType : public Type
{
    Name* name;

    virtual ~QualifiedType();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ArrayType : public Type
{
    Type* elementType;

    virtual ~ArrayType();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct IntLiteral : public Expression
{
    int value;

    virtual ~IntLiteral() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
};

struct CharLiteral : public Expression
{
    char value;

    virtual ~CharLiteral() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
};

struct StringLiteral : public Expression
{
    std::string value;

    virtual ~StringLiteral() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
};

struct BooleanLiteral : public Expression
{
    bool value;

    virtual ~BooleanLiteral() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
};

struct NullLiteral : public Expression
{
    virtual ~NullLiteral() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
};

struct BinaryOperation : public Expression
{
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

    virtual ~BinaryOperation();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct PrefixOperation : public Expression
{
    enum OperatorType
    {
        MINUS,
        NOT
    };
    OperatorType op;
    Expression* operand;

    virtual ~PrefixOperation();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct CastExpression : public Expression
{
    Type* castType;
    Expression* expression;

    virtual ~CastExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct AssignmentExpression : public Expression
{
    Expression* lhs;
    Expression* rhs;

    virtual ~AssignmentExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ParenthesizedExpression : public Expression
{
    Expression* expr;

    virtual ~ParenthesizedExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ClassInstanceCreator : public Expression
{
    Type* type;
    ASTNodeList<Expression>* arguments;

    virtual ~ClassInstanceCreator();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ArrayCreator : public Expression
{
    ArrayType* type;
    Expression* argument;

    virtual ~ArrayCreator();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ChainableExpression : public Expression // abstract
{
    Expression* prevExpr;

    virtual ~ChainableExpression();
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct MethodCall : public ChainableExpression
{
    SimpleName* name;
    ASTNodeList<Expression>* arguments;

    virtual ~MethodCall();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct FieldAccess : public ChainableExpression
{
    SimpleName* name;

    virtual ~FieldAccess();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ArrayAccess : public ChainableExpression
{
    Expression* indexExpr;

    virtual ~ArrayAccess();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ThisExpression : public ChainableExpression
{
    Expression* expression;

    virtual ~ThisExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct VariableDeclarationExpression : public Expression
{
    Type* type;
    SimpleName* name;
    Expression* initializer;

    virtual ~VariableDeclarationExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct InstanceOfExpression : public Expression
{
    Expression* expression;
    Type* type;

    virtual ~InstanceOfExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ExpressionStatement : public Statement
{
    Expression* expression;

    virtual ~ExpressionStatement();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct EmptyStatement : public Statement
{
    virtual ~EmptyStatement() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
};

struct ReturnStatement : public Statement
{
    Expression* expression;

    virtual ~ReturnStatement();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct IfStatement : public Statement
{
    Expression* ifCondition;
    Statement* ifBody;
    Statement* elseBody;

    virtual ~IfStatement();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ForStatement : public Statement
{
    Expression* forInit;
    Expression* forCheck;
    Expression* forUpdate;
    Statement* body;

    virtual ~ForStatement();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct WhileStatement : public Statement
{
    Expression* condition;
    Statement* body;

    virtual ~WhileStatement();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct Block : public Statement
{
    ASTNodeList<Statement>* statements;

    virtual ~Block();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct PackageDeclaration : public ASTNode
{
    Name* name;

    virtual ~PackageDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ImportDeclaration : public ASTNode
{
    Name* name;
    bool declareAll;

    virtual ~ImportDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
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

    virtual ~Modifier() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
};

struct TypeDeclaration : public ASTNode // abstract
{
    ASTNodeList<Modifier>* modifiers;

    virtual ~TypeDeclaration();
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct MemberDeclaration : public ASTNode // abstract
{
    ASTNodeList<Modifier>* modifiers;

    virtual ~MemberDeclaration();
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ClassDeclaration : public TypeDeclaration
{
    SimpleName* name;
    Type* baseType;
    ASTNodeList<Type>* interfaces;
    ASTNodeList<MemberDeclaration>* classBody;

    virtual ~ClassDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct InterfaceDeclaration : public TypeDeclaration
{
    SimpleName* name;
    ASTNodeList<Type>* extends;
    ASTNodeList<MemberDeclaration>* interfaceBody;

    virtual ~InterfaceDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct FormalParameter : public ASTNode
{
    Type* type;
    Name* id;

    virtual ~FormalParameter();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct ConstructorDeclaration : public MemberDeclaration
{
    ASTNodeList<FormalParameter>* parameters;
    Block* body;

    virtual ~ConstructorDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct FieldDeclaration : public MemberDeclaration
{
    VariableDeclarationExpression* declaration;

    virtual ~FieldDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct MethodDeclaration : public MemberDeclaration
{
    Type* type;
    Name* name;
    ASTNodeList<FormalParameter>* parameters;
    Block* body;

    virtual ~MethodDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};

struct CompilerUnit : public ASTNode
{
    PackageDeclaration* packageDecl;
    ASTNodeList<ImportDeclaration>* importDecls;
    TypeDeclaration* typeDecl;

    virtual ~CompilerUnit();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
};
