#include "StaticAnalysis.h"
#include <assert.h>
#include <iostream>

void ReachabilityVisitor::visit(MethodDeclaration& node)
{
    in[node.body] = MAYBE;
}

void ReachabilityVisitor::leave(MethodDeclaration& node)
{
    PrimitiveType* return_type = dynamic_cast<PrimitiveType*>(node.type);
    if(node.body
       && return_type 
       && return_type->type != PrimitiveType::VOID
       && (out.find(node.body) == out.end() || out[node.body] == MAYBE))
       {
            std::cout << "Missing return statement in \"" << node.name->getString() << "\" " << std::endl;
            exit(42);
       }
}

void ReachabilityVisitor::visit(ConstructorDeclaration& node)
{
    in[node.body] = MAYBE;
}

void ReachabilityVisitor::visit(Statement& node)
{
    // If node does not have an in defined yet
    if(in.find(&node) == in.end())
    {
        Statement* last = lastStatement(&node);
        assert(last);
        in[&node] = out[last];
    }
    
    // Default reachability for statement
    out[&node] = in[&node];
}

// void ReachabilityVisitor::leave(ExpressionStatement& node)
// {
    
// }

// void ReachabilityVisitor::leave(EmptyStatement& node)
// {
    
// }

void ReachabilityVisitor::visit(ReturnStatement& node)
{
    ASTNodeVisitor::visit(node);
    out[&node] = NO;
}

void ReachabilityVisitor::visit(IfStatement& node)
{
    ASTNodeVisitor::visit(node);
    assert(in.find(&node) != in.end());

    if(node.elseBody)
    {
        in[node.ifBody] = in[&node];
        in[node.elseBody] = in[&node];
    }
    else
    {
        in[node.ifBody] = in[&node];
        out[&node] = in[&node];
    }
}

void ReachabilityVisitor::leave(IfStatement& node)
{
    if(node.elseBody)
    {
        assert(out.find(node.elseBody) != out.end());
        assert(out.find(node.ifBody) != out.end());

        out[&node] = (out[node.ifBody] == MAYBE || out[node.elseBody] == MAYBE) ? MAYBE : NO;
    }
}

void ReachabilityVisitor::visit(ForStatement& node)
{
    ASTNodeVisitor::visit(node);
    assert(in.find(&node) != in.end());

    in[node.body] = in[&node];
    out[&node] = in[&node];
}

void ReachabilityVisitor::visit(WhileStatement& node)
{
    ASTNodeVisitor::visit(node);
    assert(in.find(&node) != in.end());

    in[node.body] = in[&node];
    out[&node] = in[&node];
}

void ReachabilityVisitor::visit(Block& node)
{
    ASTNodeVisitor::visit(node);
    assert(in.find(&node) != in.end());

    if(node.statements->elements.size())
    {
        in[node.statements->elements[0]] = in[&node];
        
        if(node.statements->elements.size() >= 2)
        {
            // Push statments onto stack in reverse order
            for(int i = node.statements->elements.size() - 2; i >= 0; i--)
            {
                block_statements.push_back(node.statements->elements[i]);
            }
        }
    }
}

void ReachabilityVisitor::leave(Block& node)
{
    if(node.statements->elements.size())
    {
        assert(out.find(node.statements->elements.back()) != out.end());
        out[&node] = out[node.statements->elements.back()];
    }
    else
    {
        assert(in.find(&node) != in.end());
        out[&node] = in[&node];
    }
}

void ReachabilityVisitor::leave(CompilerUnit& node)
{
    for(auto it: in) 
    {
        if(it.second == NO)
        {
            std::cout << "Unreachable statement found (" << it.first->toString() << ")" << std::endl;
            exit(42);
        }
    }
}