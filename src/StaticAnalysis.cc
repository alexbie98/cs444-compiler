#include "StaticAnalysis.h"
#include "NameResolution.h"
#include <assert.h>
#include <iostream>
#include <functional>

void ReachabilityVisitor::visit(MethodDeclaration& node)
{
    in[node.body] = MAYBE;
}

void ReachabilityVisitor::leave(MethodDeclaration& node)
{
    PrimitiveType* return_type = dynamic_cast<PrimitiveType*>(node.type);
    if(node.body
       && (!return_type || return_type->type != PrimitiveType::VOID)
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

        out[&node] = ((out[node.ifBody] == MAYBE || out[node.elseBody] == MAYBE) ? MAYBE : NO);
    }
}

void ReachabilityVisitor::visit(ForStatement& node)
{
    ASTNodeVisitor::visit(node);
    assert(in.find(&node) != in.end());

    if(node.forCheck)
    {
        ConstantExpressionVisitor v;
        node.forCheck->visitAll(v);
    }

    // No forCheck is equivalent to forCheck == true
    if(!node.forCheck || node.forCheck->constant_value)
    {
        if(!node.forCheck || node.forCheck->constant_value->value._bool == true)
        {
            if(node.body) in[node.body] = in[&node];
            out[&node] = NO;
        }
        else
        {
            if(node.body) in[node.body] = NO;
            out[&node] = in[&node];
        }
    }
    else
    {
        if(node.body) in[node.body] = in[&node];
        out[&node] = in[&node];
    }
}

void ReachabilityVisitor::visit(WhileStatement& node)
{
    ASTNodeVisitor::visit(node);
    assert(in.find(&node) != in.end());

    ConstantExpressionVisitor v;
    node.condition->visitAll(v);

    if(node.condition->constant_value)
    {
        if(node.condition->constant_value->value._bool == true)
        {
            if(node.body) in[node.body] = in[&node];
            out[&node] = NO;
        }
        else
        {
            if(node.body) in[node.body] = NO;
            out[&node] = in[&node];
        }
    }
    else
    {
        if(node.body) in[node.body] = in[&node];
        out[&node] = in[&node];
    }
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

void ReachabilityVisitor::visit(VariableDeclarationExpression& node)
{
    current_variable_decl = &node;
}

void ReachabilityVisitor::leave(VariableDeclarationExpression& node)
{
    current_variable_decl = nullptr;
}

void ReachabilityVisitor::visit(NameExpression& node)
{
    if(node.name && current_variable_decl && node.name->refers_to == current_variable_decl)
    {
        std::cout << "Local variable \"" << current_variable_decl->name->getString() << "\" occurs in its own initializer." << std::endl;
        exit(42);
    }
}

void ConstantExpressionVisitor::visit(MethodDeclaration& node)
{
    fullyQualifiedName = node.originatingClass->fullyQualifiedName;
    methodName = node.name->id;
}

void ConstantExpressionVisitor::leave(VariableDeclarationExpression& node)
{
    // Only do for local vars not fields
    if (dynamic_cast<FieldDeclaration*>(node.parent) == nullptr)
    {
        if (node.initializer->constant_value)
        {
            node.constant_value = node.initializer->constant_value;
        }
    }
}

void ConstantExpressionVisitor::leave(AssignmentExpression& node)
{
    if (NameExpression * nameLhs = dynamic_cast<NameExpression*>(node.lhs))
    {
        if (nameLhs->name)
        {
            if (VariableDeclarationExpression * var = dynamic_cast<VariableDeclarationExpression*>(nameLhs->name->refers_to))
            {
                if (dynamic_cast<FieldDeclaration*>(var->parent) == nullptr)
                {
                    var->constant_value = nullptr;
                }
            }
        }
    }
}

void ConstantExpressionVisitor::leave(IntLiteral& node)
{
    node.constant_value = new Expression::ConstantValue({ Expression::ConstantValue::INT });
    node.constant_value->value._int = (decltype(Expression::ConstantValue::ConstantValueContents::_int))node.value;
}

void ConstantExpressionVisitor::leave(CharLiteral& node)
{
    node.constant_value = new Expression::ConstantValue({ Expression::ConstantValue::CHAR });
    node.constant_value->value._char = node.value;
}

void ConstantExpressionVisitor::leave(StringLiteral& node)
{
    node.constant_value = new Expression::ConstantValue({ Expression::ConstantValue::STRING });
    node.constant_value->value._string = &node;
}

void ConstantExpressionVisitor::leave(BooleanLiteral& node)
{
    node.constant_value = new Expression::ConstantValue({ Expression::ConstantValue::BOOL });
    node.constant_value->value._bool = node.value;
}

void ConstantExpressionVisitor::leave(NullLiteral& node)
{
    node.constant_value = new Expression::ConstantValue({ Expression::ConstantValue::REF_TYPE });
}

void ConstantExpressionVisitor::leave(NameExpression& node)
{
    if (node.name)
    {
        if (VariableDeclarationExpression * var = dynamic_cast<VariableDeclarationExpression*>(node.name->refers_to))
        {
            if (dynamic_cast<FieldDeclaration*>(var->parent) == nullptr)
            {
                node.constant_value = var->constant_value;
            }
        }
    }
}

void ConstantExpressionVisitor::leave(BinaryOperation& node)
{ 
    using integer_type = decltype(Expression::ConstantValue::ConstantValueContents::_int);

    if(node.rhs->constant_value && node.lhs->constant_value)
    {
        bool both_bool = node.lhs->constant_value->type == Expression::ConstantValue::BOOL
                         && node.rhs->constant_value->type == Expression::ConstantValue::BOOL;
        bool both_numeric = node.lhs->constant_value->isNumeric() && node.rhs->constant_value->isNumeric();

        Expression::ConstantValue result;

        std::function<int(int,int)> arithmetic = nullptr;
        std::function<bool(int,int)> int_comparison = nullptr;
        std::function<bool(bool,bool)> bool_comparison = nullptr;

        switch(node.op)
        {
            // Conditional AND and OR (Not Eager) do not short circuit during constant expression evaluation.
            // (true || (a == 1)) does not evaluate to true during constant expression evaluation if a is not final.
            case BinaryOperation::AND: 
                result.type = Expression::ConstantValue::BOOL;
                result.value._bool = node.lhs->constant_value->value._bool && node.rhs->constant_value->value._bool;
                break;
            case BinaryOperation::EAGER_AND: 
                result.type = Expression::ConstantValue::BOOL;
                result.value._bool = node.lhs->constant_value->value._bool && node.rhs->constant_value->value._bool;
                break;
            case BinaryOperation::OR: 
                result.type = Expression::ConstantValue::BOOL;
                result.value._bool = node.lhs->constant_value->value._bool || node.rhs->constant_value->value._bool;
                break;
            case BinaryOperation::EAGER_OR: 
                result.type = Expression::ConstantValue::BOOL;
                result.value._bool = node.lhs->constant_value->value._bool || node.rhs->constant_value->value._bool;
                break;
            case BinaryOperation::XOR:
                result.type = Expression::ConstantValue::BOOL;
                result.value._bool = node.lhs->constant_value->value._bool != node.rhs->constant_value->value._bool;
                break;
            case BinaryOperation::PLUS:
                arithmetic = std::plus<integer_type>();
                break;
            case BinaryOperation::MINUS:
                arithmetic = std::minus<integer_type>();
                break;
            case BinaryOperation::TIMES:
                arithmetic = std::multiplies<integer_type>();
                break;
            case BinaryOperation::DIVIDE:
                arithmetic = std::divides<integer_type>();
                if (node.rhs->constant_value->asInt() == 0)
                {
                    std::cout << "Cannot divide by 0 (Static Analysis)" << std::endl;
                    exit(42);
                }
                break;
            case BinaryOperation::REMAINDER:
                arithmetic = std::modulus<integer_type>();
                if (node.rhs->constant_value->asInt() == 0)
                {
                    std::cout << "Cannot divide by 0 (Static Analysis)" << std::endl;
                    exit(42);
                }
                break;
            case BinaryOperation::EQ:
                if(both_bool) bool_comparison = std::equal_to<bool>();
                else int_comparison = std::equal_to<integer_type>();
                break;
            case BinaryOperation::NEQ:
                if(both_bool) bool_comparison = std::not_equal_to<bool>();
                else int_comparison = std::not_equal_to<integer_type>();
                break;
            case BinaryOperation::LEQ:
                int_comparison = std::less_equal<integer_type>();
                break;
            case BinaryOperation::GEQ:
                int_comparison = std::greater_equal<integer_type>();
                break;
            case BinaryOperation::LT:
                int_comparison = std::less<integer_type>();
                break;
            case BinaryOperation::GT:
                int_comparison = std::greater<integer_type>();
                break;
        }

        if (arithmetic)
        {
            // Section 15.18.2/5.6.2 Binary numeric promotion is performed, promoting both operands to ints (done for all additive and multiplicative operators)
            result.type = Expression::ConstantValue::INT;
            result.value._int = arithmetic(node.lhs->constant_value->asInt(), node.rhs->constant_value->asInt());
        }
        else if (int_comparison)
        {
            result.type = Expression::ConstantValue::BOOL;
            result.value._bool = int_comparison(node.lhs->constant_value->asInt(), node.rhs->constant_value->asInt());
        }
        else if (bool_comparison)
        {
            result.type = Expression::ConstantValue::BOOL;
            result.value._bool = bool_comparison(node.lhs->constant_value->value._bool, node.rhs->constant_value->value._bool);
        }

        // TODO Correct default behaviour due to type checking?
        node.constant_value = new Expression::ConstantValue(result);
    }
}

void ConstantExpressionVisitor::leave(PrefixOperation& node)
{
    if(node.operand->constant_value)
    {
        Expression::ConstantValue result;

        switch(node.op)
        {
            case PrefixOperation::NOT: 
                result.type = Expression::ConstantValue::BOOL;
                result.value._bool = !node.operand->constant_value->value._bool;
                break;
            case PrefixOperation::MINUS: 
                result.type = Expression::ConstantValue::INT;
                result.value._int = -node.operand->constant_value->asInt();
                break;
        }

        node.constant_value = new Expression::ConstantValue(result);
    }
}

void ConstantExpressionVisitor::leave(ClassInstanceCreator& node)
{
    node.constant_value = new Expression::ConstantValue({ Expression::ConstantValue::REF_TYPE });
    node.constant_value->refType = node.type;
}

void ConstantExpressionVisitor::leave(ArrayCreator& node)
{
    node.constant_value = new Expression::ConstantValue({ Expression::ConstantValue::REF_TYPE });
    node.constant_value->refType = node.type;
}

void ConstantExpressionVisitor::leave(CastExpression& node)
{
    if (node.expression->constant_value)
    {
        if (PrimitiveType * primitive = dynamic_cast<PrimitiveType*>(node.castType))
        {
            switch (primitive->type)
            {
            case PrimitiveType::BYTE:
                node.constant_value = new Expression::ConstantValue({ Expression::ConstantValue::BYTE });
                node.constant_value->value._byte = (decltype(Expression::ConstantValue::ConstantValueContents::_byte))node.expression->constant_value->asInt();
                break;
            case PrimitiveType::SHORT:
                node.constant_value = new Expression::ConstantValue({ Expression::ConstantValue::SHORT });
                node.constant_value->value._short = (decltype(Expression::ConstantValue::ConstantValueContents::_short))node.expression->constant_value->asInt();
                break;
            case PrimitiveType::INT:
                node.constant_value = new Expression::ConstantValue({ Expression::ConstantValue::INT });
                node.constant_value->value._int = (decltype(Expression::ConstantValue::ConstantValueContents::_int))node.expression->constant_value->asInt();
                break;
            case PrimitiveType::CHAR:
                node.constant_value = new Expression::ConstantValue({ Expression::ConstantValue::CHAR });
                node.constant_value->value._char = (decltype(Expression::ConstantValue::ConstantValueContents::_char))node.expression->constant_value->asInt();
                break;
            case PrimitiveType::BOOLEAN:
                // Must be identity conversion
                node.constant_value = new Expression::ConstantValue(*node.expression->constant_value);
                break;
            default:
                assert(false);
                break;
            }
        }
        else
        {
            if (node.expression->constant_value->refType != nullptr)
            {
                if (!isCastable(node.expression->constant_value->refType, node.castType))
                {
                    std::cout << "Cast will never succeed (Static Analysis)" << std::endl;
                    exit(42);
                }
            }
        }
    }
}

void ConstantExpressionVisitor::leave(ParenthesizedExpression& node)
{
    node.constant_value = node.expr->constant_value;
}