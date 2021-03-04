#pragma once

#include "ast/ASTNode.h"
#include <stack>

#define UNNAMED_PACKAGE "UNNAMED():.{}"

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
    virtual void visit(Block& node);
    virtual void visit(FormalParameter& node);
    virtual void visit(VariableDeclarationExpression& node);
    virtual void visit(FieldDeclaration& node);
    virtual void visit(CompilerUnit& node);

    virtual void leave(ClassDeclaration& node);
    virtual void leave(InterfaceDeclaration& node);
    virtual void leave(MethodDeclaration& node);
    virtual void leave(Block& node);
};

class TypeLinkingVisitor: public ASTNodeVisitor
{
    Environment* global;
    const std::vector<ASTNode*>& asts;

public: 
    TypeLinkingVisitor(Environment* global, const std::vector<ASTNode*>& asts): global{global}, asts{asts} {}
    virtual void visit(QualifiedType& node);
};

// Returns global environment
Environment resolveNames(std::vector<ASTNode*> asts);
