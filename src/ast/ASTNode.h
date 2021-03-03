#pragma once

#include <string>
#include <vector>
#include <unordered_map>

struct ASTNode; // abstract
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
    // abstract visits
    virtual void visit(ASTNode& node);
    virtual void visit(Expression& node);
    virtual void visit(Statement& node);
    virtual void visit(Type& node);
    virtual void visit(Name& node);
    virtual void visit(ChainableExpression& node);
    virtual void visit(TypeDeclaration& node);
    virtual void visit(MemberDeclaration& node);

    virtual void visit(ASTNodeList<Type>& node);
    virtual void visit(ASTNodeList<Modifier>& node);
    virtual void visit(ASTNodeList<Statement>& node);
    virtual void visit(ASTNodeList<Expression>& node);
    virtual void visit(ASTNodeList<FormalParameter>& node);
    virtual void visit(ASTNodeList<ImportDeclaration>& node);
    virtual void visit(ASTNodeList<MemberDeclaration>& node);

    virtual void visit(SimpleName& node);
    virtual void visit(QualifiedName& node);
    virtual void visit(PrimitiveType& node);
    virtual void visit(QualifiedType& node);
    virtual void visit(ArrayType& node);
    virtual void visit(IntLiteral& node);
    virtual void visit(CharLiteral& node);
    virtual void visit(StringLiteral& node);
    virtual void visit(BooleanLiteral& node);
    virtual void visit(NullLiteral& node);
    virtual void visit(BinaryOperation& node);
    virtual void visit(PrefixOperation& node);
    virtual void visit(CastExpression& node);
    virtual void visit(AssignmentExpression& node);
    virtual void visit(ParenthesizedExpression& node);
    virtual void visit(ClassInstanceCreator& node);
    virtual void visit(ArrayCreator& node);
    virtual void visit(MethodCall& node);
    virtual void visit(FieldAccess& node);
    virtual void visit(ArrayAccess& node);
    virtual void visit(ThisExpression& node);
    virtual void visit(VariableDeclarationExpression& node);
    virtual void visit(InstanceOfExpression& node);
    virtual void visit(ExpressionStatement& node);
    virtual void visit(EmptyStatement& node);
    virtual void visit(ReturnStatement& node);
    virtual void visit(IfStatement& node);
    virtual void visit(ForStatement& node);
    virtual void visit(WhileStatement& node);
    virtual void visit(Block& node);
    virtual void visit(PackageDeclaration& node);
    virtual void visit(ImportDeclaration& node);
    virtual void visit(Modifier& node);
    virtual void visit(ClassDeclaration& node);
    virtual void visit(InterfaceDeclaration& node);
    virtual void visit(FormalParameter& node);
    virtual void visit(ConstructorDeclaration& node);
    virtual void visit(FieldDeclaration& node);
    virtual void visit(MethodDeclaration& node);
    virtual void visit(CompilerUnit& node);

    // abstract leaves
    virtual void leave(ASTNode& node);
    virtual void leave(Expression& node);
    virtual void leave(Statement& node);
    virtual void leave(Type& node);
    virtual void leave(Name& node);
    virtual void leave(ChainableExpression& node);
    virtual void leave(TypeDeclaration& node);
    virtual void leave(MemberDeclaration& node);

    virtual void leave(ASTNodeList<Type>& node);
    virtual void leave(ASTNodeList<Modifier>& node);
    virtual void leave(ASTNodeList<Statement>& node);
    virtual void leave(ASTNodeList<Expression>& node);
    virtual void leave(ASTNodeList<FormalParameter>& node);
    virtual void leave(ASTNodeList<ImportDeclaration>& node);
    virtual void leave(ASTNodeList<MemberDeclaration>& node);

    virtual void leave(SimpleName& node);
    virtual void leave(QualifiedName& node);
    virtual void leave(PrimitiveType& node);
    virtual void leave(QualifiedType& node);
    virtual void leave(ArrayType& node);
    virtual void leave(IntLiteral& node);
    virtual void leave(CharLiteral& node);
    virtual void leave(StringLiteral& node);
    virtual void leave(BooleanLiteral& node);
    virtual void leave(NullLiteral& node);
    virtual void leave(BinaryOperation& node);
    virtual void leave(PrefixOperation& node);
    virtual void leave(CastExpression& node);
    virtual void leave(AssignmentExpression& node);
    virtual void leave(ParenthesizedExpression& node);
    virtual void leave(ClassInstanceCreator& node);
    virtual void leave(ArrayCreator& node);
    virtual void leave(MethodCall& node);
    virtual void leave(FieldAccess& node);
    virtual void leave(ArrayAccess& node);
    virtual void leave(ThisExpression& node);
    virtual void leave(VariableDeclarationExpression& node);
    virtual void leave(InstanceOfExpression& node);
    virtual void leave(ExpressionStatement& node);
    virtual void leave(EmptyStatement& node);
    virtual void leave(ReturnStatement& node);
    virtual void leave(IfStatement& node);
    virtual void leave(ForStatement& node);
    virtual void leave(WhileStatement& node);
    virtual void leave(Block& node);
    virtual void leave(PackageDeclaration& node);
    virtual void leave(ImportDeclaration& node);
    virtual void leave(Modifier& node);
    virtual void leave(ClassDeclaration& node);
    virtual void leave(InterfaceDeclaration& node);
    virtual void leave(FormalParameter& node);
    virtual void leave(ConstructorDeclaration& node);
    virtual void leave(FieldDeclaration& node);
    virtual void leave(MethodDeclaration& node);
    virtual void leave(CompilerUnit& node);
};

struct Environment
{
    std::unordered_map<std::string, ClassDeclaration*> classes;
    std::unordered_map<std::string, InterfaceDeclaration*> interfaces;
    std::unordered_map<std::string, FieldDeclaration*> fields;
    std::unordered_map<std::string, MethodDeclaration*> methods;
    std::unordered_map<std::string, FormalParameter*> formal_params;
    std::unordered_map<std::string, VariableDeclarationExpression*> variables;
};

struct ASTNode // Abstract
{
    ASTNode* parent;

    virtual ~ASTNode() = default;
    virtual void accept(ASTNodeVisitor& v) = 0;
    virtual void visitAll(ASTNodeVisitor& v);

    virtual Environment* getEnvironment() { return nullptr; }
    virtual std::string toString(){ return "ASTNode"; }
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
        v.leave(*this);
    }
    virtual std::string toString(){ return "ASTNodeList"; }
};

struct Expression : public ASTNode //abstract
{
    virtual ~Expression() = default;
    virtual std::string toString(){ return "Expression"; }
};

struct Statement : public ASTNode // abstract
{
    virtual ~Statement() = default;
    virtual std::string toString(){ return "Statement"; }
};

struct Type : public ASTNode // abstract
{
    virtual ~Type() = default;
    virtual std::string toString(){ return "Type"; }
};

struct Name : public Expression // abstract
{
    virtual ~Name() = default;
    virtual const std::string& getString() = 0;
    virtual std::string toString(){ return "Name"; }
};

struct SimpleName : public Name
{
    std::string id;

    virtual ~SimpleName() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual const std::string& getString() { return id; }
    virtual std::string toString(){ return "SimpleName"; }
};

struct QualifiedName : public Name
{
    Name* name = nullptr;
    SimpleName* simpleName = nullptr;

    virtual ~QualifiedName();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual const std::string& getString() { return name->getString(); }
    virtual std::string toString(){ return "QualifiedName"; }
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
    virtual std::string toString(){ return "PrimitiveType"; }
};

struct QualifiedType : public Type
{
    Name* name = nullptr;

    virtual ~QualifiedType();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "QualifiedType"; }
};

struct ArrayType : public Type
{
    Type* elementType = nullptr;

    virtual ~ArrayType();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ArrayType"; }
};

struct IntLiteral : public Expression
{
    long long int value;

    virtual ~IntLiteral() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual std::string toString(){ return "IntLiteral"; }
};

struct CharLiteral : public Expression
{
    char value;

    virtual ~CharLiteral() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual std::string toString(){ return "CharLiteral"; }
};

struct StringLiteral : public Expression
{
    std::string value;

    virtual ~StringLiteral() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual std::string toString(){ return "StringLiteral"; }
};

struct BooleanLiteral : public Expression
{
    bool value;

    virtual ~BooleanLiteral() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual std::string toString(){ return "BooleanLiteral"; }
};

struct NullLiteral : public Expression
{
    virtual ~NullLiteral() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual std::string toString(){ return "NullLiteral"; }
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

    Expression* lhs = nullptr;
    Expression* rhs = nullptr;
    OperatorType op;

    virtual ~BinaryOperation();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "BinaryOperation"; }
};

struct PrefixOperation : public Expression
{
    enum OperatorType
    {
        MINUS,
        NOT
    };
    OperatorType op;
    Expression* operand = nullptr;

    virtual ~PrefixOperation();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "PrefixOperation"; }
};

struct CastExpression : public Expression
{
    Type* castType = nullptr;
    Expression* expression = nullptr;

    virtual ~CastExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "CastExpression"; }
};

struct AssignmentExpression : public Expression
{
    Expression* lhs = nullptr;
    Expression* rhs = nullptr;

    virtual ~AssignmentExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "AssignmentExpression"; }
};

struct ParenthesizedExpression : public Expression
{
    Expression* expr = nullptr;

    virtual ~ParenthesizedExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ParenthesizedExpression"; }
};

struct ClassInstanceCreator : public Expression
{
    Type* type = nullptr;
    ASTNodeList<Expression>* arguments = nullptr;

    virtual ~ClassInstanceCreator();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ClassInstanceCreator"; }
};

struct ArrayCreator : public Expression
{
    ArrayType* type = nullptr;
    Expression* argument = nullptr;

    virtual ~ArrayCreator();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ArrayCreator"; }
};

struct ChainableExpression : public Expression // abstract
{
    Expression* prevExpr = nullptr;

    virtual ~ChainableExpression();
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ChainableExpression"; }
};

struct MethodCall : public ChainableExpression
{
    SimpleName* name = nullptr;
    ASTNodeList<Expression>* arguments = nullptr;

    virtual ~MethodCall();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "MethodCall"; }
};

struct FieldAccess : public ChainableExpression
{
    SimpleName* name = nullptr;

    virtual ~FieldAccess();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "FieldAccess"; }
};

struct ArrayAccess : public ChainableExpression
{
    Expression* indexExpr = nullptr;

    virtual ~ArrayAccess();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ArrayAccess"; }
};

struct ThisExpression : public ChainableExpression
{
    Expression* expression = nullptr;

    virtual ~ThisExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ThisExpression"; }
};

struct VariableDeclarationExpression : public Expression
{
    Type* type = nullptr;
    SimpleName* name = nullptr;
    Expression* initializer = nullptr;

    virtual ~VariableDeclarationExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "VariableDeclarationExpression"; }
};

struct InstanceOfExpression : public Expression
{
    Expression* expression = nullptr;
    Type* type = nullptr;

    virtual ~InstanceOfExpression();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "InstanceOfExpression"; }
};

struct ExpressionStatement : public Statement
{
    Expression* expression = nullptr;

    virtual ~ExpressionStatement();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ExpressionStatement"; }
};

struct EmptyStatement : public Statement
{
    virtual ~EmptyStatement() = default;
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual std::string toString(){ return "EmptyStatement"; }
};

struct ReturnStatement : public Statement
{
    Expression* expression = nullptr;

    virtual ~ReturnStatement();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ReturnStatement"; }
};

struct IfStatement : public Statement
{
    Expression* ifCondition = nullptr;
    Statement* ifBody = nullptr;
    Statement* elseBody = nullptr;

    virtual ~IfStatement();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "IfStatement"; }
};

struct ForStatement : public Statement
{
    Expression* forInit = nullptr;
    Expression* forCheck = nullptr;
    Expression* forUpdate = nullptr;
    Statement* body = nullptr;

    virtual ~ForStatement();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ForStatement"; }
};

struct WhileStatement : public Statement
{
    Expression* condition = nullptr;
    Statement* body = nullptr;

    virtual ~WhileStatement();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "WhileStatement"; }
};

struct Block : public Statement
{
    Environment environment;

    ASTNodeList<Statement>* statements = nullptr;

    virtual ~Block();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    Environment* getEnvironment() override { return &environment; }
    virtual std::string toString(){ return "Block"; }
};

struct PackageDeclaration : public ASTNode
{
    Name* name = nullptr;

    virtual ~PackageDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "PackageDeclaration"; }
};

struct ImportDeclaration : public ASTNode
{
    Name* name = nullptr;
    bool declareAll;

    virtual ~ImportDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ImportDeclaration"; }
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
    virtual std::string toString(){ return "Modifier"; }
};

struct TypeDeclaration : public ASTNode // abstract
{
    ASTNodeList<Modifier>* modifiers = nullptr;

    virtual ~TypeDeclaration();
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "TypeDeclaration"; }
};

struct MemberDeclaration : public ASTNode // abstract
{
    ASTNodeList<Modifier>* modifiers = nullptr;

    virtual ~MemberDeclaration();
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "MemberDeclaration"; }
};

struct ClassDeclaration : public TypeDeclaration
{
    Environment environment;

    SimpleName* name = nullptr;
    Type* baseType = nullptr;
    ASTNodeList<Type>* interfaces = nullptr;
    ASTNodeList<MemberDeclaration>* classBody = nullptr;

    virtual ~ClassDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    Environment* getEnvironment() override { return &environment; }
    virtual std::string toString(){ return "ClassDeclaration"; }
};

struct InterfaceDeclaration : public TypeDeclaration
{
    Environment environment;

    SimpleName* name = nullptr;
    ASTNodeList<Type>* extends = nullptr;
    ASTNodeList<MemberDeclaration>* interfaceBody = nullptr;

    virtual ~InterfaceDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    Environment* getEnvironment() override { return &environment; }
    virtual std::string toString(){ return "InterfaceDeclaration"; }
};

struct FormalParameter : public ASTNode
{
    Type* type = nullptr;
    Name* id = nullptr;

    virtual ~FormalParameter();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "FormalParameter"; }
};

struct ConstructorDeclaration : public MemberDeclaration
{
    ASTNodeList<FormalParameter>* parameters = nullptr;
    Block* body = nullptr;

    virtual ~ConstructorDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "ConstructorDeclaration"; }
};

struct FieldDeclaration : public MemberDeclaration
{
    VariableDeclarationExpression* declaration = nullptr;

    virtual ~FieldDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "FieldDeclaration"; }
};

struct MethodDeclaration : public MemberDeclaration
{
    Environment environment;

    Type* type = nullptr;
    Name* name = nullptr;
    ASTNodeList<FormalParameter>* parameters = nullptr;
    Block* body = nullptr;

    virtual ~MethodDeclaration();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    Environment* getEnvironment() override { return &environment; }
    virtual std::string toString(){ return "MethodDeclaration"; }
};

struct CompilerUnit : public ASTNode
{
    PackageDeclaration* packageDecl = nullptr;
    ASTNodeList<ImportDeclaration>* importDecls = nullptr;
    TypeDeclaration* typeDecl = nullptr;

    virtual ~CompilerUnit();
    virtual void accept(ASTNodeVisitor& v) override { v.visit(*this); }
    virtual void visitAll(ASTNodeVisitor& v) override;
    virtual std::string toString(){ return "CompilerUnit"; }
};
