#pragma once

#include "ast/ASTNode.h"
#include <unordered_map>
#include <vector>
#include <iostream>

class ReachabilityVisitor : public ASTNodeVisitor
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
    VariableDeclarationExpression* current_variable_decl = nullptr;

    Statement* lastStatement(Statement* current)
    {
        if (block_statements.size())
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

    // For initializer check
    virtual void visit(VariableDeclarationExpression& node);
    virtual void leave(VariableDeclarationExpression& node);
    virtual void visit(NameExpression& node);
};

class ConstantExpressionVisitor : public ASTNodeVisitor
{
public:
    virtual void leave(IntLiteral& node);
    virtual void leave(CharLiteral& node);
    virtual void leave(StringLiteral& node);
    virtual void leave(BooleanLiteral& node);
    // virtual void leave(NameExpression& node);
    virtual void leave(BinaryOperation& node);
    virtual void leave(PrefixOperation& node);
    // virtual void leave(PrefixOperation& node);
    virtual void leave(CastExpression& node);
    virtual void leave(ParenthesizedExpression& node);
    // virtual void leave(ChainableExpression& node);
    // virtual void leave(ThisExpression& node);
};