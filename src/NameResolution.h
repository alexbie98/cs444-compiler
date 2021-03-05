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
    std::string package = UNNAMED_PACKAGE;
    ASTNodeList<ImportDeclaration>* imports;
    PackageDeclaration* current_package_decl;

public: 
    TypeLinkingVisitor(Environment* global, const std::vector<ASTNode*>& asts): global{global}, asts{asts} {}
    virtual void visit(QualifiedType& node);
    virtual void visit(CompilerUnit& node);
};

// Returns global environment
Environment resolveNames(std::vector<ASTNode*> asts);
