#pragma once

#include "ast/ASTNode.h"
#include "Parser.h"
#include <stack>

class ParentVisitor: public ASTNodeVisitor
{
    std::stack<ASTNode*> parents;

public:
    ParentVisitor(){ parents.push(nullptr); }

    virtual void visit(ASTNode& node) override;
    virtual void leave(ASTNode& node) override;
};

void setParents(ASTNode* ast);
ASTNode* buildAST(ParseTreeNode* root);
