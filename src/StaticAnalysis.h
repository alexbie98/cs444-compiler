#pragma once

#include "ast/ASTNode.h"
#include <unordered_map>
#include <vector>
#include <iostream>

class ReachabilityVisitor: public ASTNodeVisitor
{
    enum Reachable
    {
        UNDEF = 0,
        MAYBE,
        NO,
    };

    std::unordered_map<Statement*, Reachable> in;
    std::unordered_map<Statement*, Reachable> out;

    std::vector<Statement*> block_statements;

    Statement* lastStatement(Statement* current)
    {
        if(block_statements.size())
        {
            Statement* result = block_statements.back();
            block_statements.pop_back();
            return result; 
        }

        return nullptr;
    }

public: 
    virtual void visit(MethodDeclaration& node);
    virtual void visit(ConstructorDeclaration& node);
    virtual void visit(Statement& node);
    virtual void visit(IfStatement& node);
    virtual void visit(ForStatement& node);
    virtual void visit(WhileStatement& node);
    virtual void visit(Block& node);
    virtual void visit(ReturnStatement& node);

    virtual void leave(MethodDeclaration& node);
    virtual void leave(IfStatement& node);
    virtual void leave(Block& node);
    virtual void leave(CompilerUnit& node);

    // virtual void leave(ExpressionStatement& node);
    // virtual void leave(EmptyStatement& node);
};