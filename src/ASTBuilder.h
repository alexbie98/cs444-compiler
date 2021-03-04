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


class PrintVisitor : public ASTNodeVisitor
{
    int spaces = 0;
public:
    virtual void visit(ASTNode& node) override;
    virtual void leave(ASTNode& node) override;
};

void printAST(ASTNode* ast);
void setParents(ASTNode* ast);
void removeJavaLangDups(std::vector<ASTNode*> asts);
ASTNode* buildAST(ParseTreeNode* root);
