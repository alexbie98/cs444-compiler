#pragma once

#include "ast/ASTNode.h"
#include <stack>

#define UNNAMED_PACKAGE ""

class EnvironmentVisitor: public ASTNodeVisitor
{
public:
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

// Returns global environment
Environment resolveNames(std::vector<ASTNode*> asts);
