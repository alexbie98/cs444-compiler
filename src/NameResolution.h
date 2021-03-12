#pragma once

#include "ast/ASTNode.h"
#include <stack>

class EnvironmentVisitor: public ASTNodeVisitor
{
    void initEnvironment(ASTNode* node);

public:
    // TODO Create new program ASTNode to connect all ASTs?
    Environment global; 
    std::stack<Environment*> environments;
    std::string package = UNNAMED_PACKAGE;

    EnvironmentVisitor(){ environments.push(&global); }

    // ASTs that define a new scope
    virtual void visit(ClassDeclaration& node);
    virtual void visit(InterfaceDeclaration& node);
    virtual void visit(MethodDeclaration& node);
    virtual void visit(ConstructorDeclaration& node);
    virtual void visit(Block& node);
    virtual void visit(FormalParameter& node);
    virtual void visit(VariableDeclarationExpression& node);
    virtual void visit(FieldDeclaration& node);
    virtual void visit(CompilerUnit& node);

    virtual void leave(ClassDeclaration& node);
    virtual void leave(InterfaceDeclaration& node);
    virtual void leave(MethodDeclaration& node);
    virtual void leave(ConstructorDeclaration& node);
    virtual void leave(Block& node);
};

class TypeLinkingVisitor: public ASTNodeVisitor
{
    Environment* global;
    const std::vector<ASTNode*>& asts;
    CompilerUnit* ast_root;
    std::string package_name = UNNAMED_PACKAGE;
    ASTNodeList<ImportDeclaration>* imports;

public: 
    TypeLinkingVisitor(Environment* global, const std::vector<ASTNode*>& asts): global{global}, asts{asts} {}
    virtual void visit(QualifiedType& node);
    virtual void visit(CompilerUnit& node);
};

class DisambiguationVisitor: public ASTNodeVisitor
{
    Environment* global;
    const std::vector<ASTNode*>& asts;
    CompilerUnit* ast_root;
    std::string package_name = UNNAMED_PACKAGE;
    ASTNodeList<ImportDeclaration>* imports;

    bool disambiguate(const std::vector<Name*>& exp);
public:
    DisambiguationVisitor(Environment* global, const std::vector<ASTNode*>& asts): global{global}, asts{asts} {}
    virtual void visit(NameExpression& node);
    virtual void visit(CompilerUnit& node);
};

class TypeCheckingVisitor : public ASTNodeVisitor
{
    Environment* globalEnvironment;
    Environment* localEnvironment;
    ClassDeclaration* enclosingClass;
    Type* returnType;

    bool isStaticContext;
public:
    TypeCheckingVisitor(Environment* globalEnv);

    virtual void visit(ClassDeclaration& node);
    virtual void visit(MethodDeclaration& node);
    virtual void visit(ConstructorDeclaration& node);
    virtual void visit(Block& node);
    virtual void visit(NameExpression& node);
    virtual void visit(FieldDeclaration& node);

    virtual void leave(FieldDeclaration& node);


    virtual void leave(MethodDeclaration& node);
    virtual void leave(ConstructorDeclaration& node);
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

private:
    bool isAssignable(Type* lhs, Type* rhs) const;
    bool isDerived(TypeDeclaration* base, TypeDeclaration* derived) const;
    bool isBooleanType(Type* type) const;
    bool isVoidType(Type* type) const;
    bool isNumericType(Type* type) const;
    bool isStringType(Type* type) const;
    bool isRefType(Type* type) const;
    bool isNullType(Type* type) const;
    bool isInterfaceType(Type* type) const;

    bool isCastable(Type* baseType, Type* castType) const;

    bool validateMemberAccess(Expression* prevExpr, TypeDeclaration* accessingType, MemberDeclaration* member) const;
    bool validateConstructorAccess(ConstructorDeclaration* member) const;

};


// Returns global environment
Environment resolveNames(std::vector<ASTNode*> asts);
