#include "ASTNode.h"

void ASTNode::visitAll(ASTNodeVisitor& v)
{
    accept(v);
}

QualifiedName::~QualifiedName()
{
    if (name)
    {
        delete name;
    }

    if (simpleName)
    {
        delete simpleName;
    }
}

void QualifiedName::visitAll(ASTNodeVisitor& v)
{
    Name::visitAll(v);
    if (name)
    {
        name->visitAll(v);
    }

    if (simpleName)
    {
        simpleName->visitAll(v);
    }

    v.leave(*this);
}

QualifiedType::~QualifiedType()
{
    if (name)
    {
        delete name;
    }
}

void QualifiedType::visitAll(ASTNodeVisitor& v)
{
    Type::visitAll(v);

    if (name)
    {
        name->visitAll(v);
    }

    v.leave(*this);
}

ArrayType::~ArrayType()
{
    if (elementType)
    {
        delete elementType;
    }
}

void ArrayType::visitAll(ASTNodeVisitor& v)
{
    ArrayType::visitAll(v);

    if (elementType)
    {
        elementType->visitAll(v);
    }

    v.leave(*this);
}

BinaryOperation::~BinaryOperation()
{
    if (lhs)
    {
        delete lhs;
    }

    if (rhs)
    {
        delete rhs;
    }
}

void BinaryOperation::visitAll(ASTNodeVisitor& v)
{
    Expression::visitAll(v);

    if (lhs)
    {
        lhs->visitAll(v);
    }

    if (rhs)
    {
        rhs->visitAll(v);
    }

    v.leave(*this);
}

PrefixOperation::~PrefixOperation()
{
    if (operand)
    {
        delete operand;
    }
}

void PrefixOperation::visitAll(ASTNodeVisitor& v)
{
    Expression::visitAll(v);

    if (operand)
    {
        operand->visitAll(v);
    }

    v.leave(*this);
}

CastExpression::~CastExpression()
{
    if (castType)
    {
        delete castType;
    }

    if (expression)
    {
        delete expression;
    }
}

void CastExpression::visitAll(ASTNodeVisitor& v)
{
    Expression::visitAll(v);

    if (castType)
    {
        castType->visitAll(v);
    }

    if (expression)
    {
        expression->visitAll(v);
    }

    v.leave(*this);
}

AssignmentExpression::~AssignmentExpression()
{
    if (lhs)
    {
        delete lhs;
    }

    if (rhs)
    {
        delete rhs;
    }
}

void AssignmentExpression::visitAll(ASTNodeVisitor& v)
{
    Expression::visitAll(v);

    if (lhs)
    {
        lhs->visitAll(v);
    }

    if (rhs)
    {
        rhs->visitAll(v);
    }

    v.leave(*this);
}

ParenthesizedExpression::~ParenthesizedExpression()
{
    if (expr)
    {
        delete expr;
    }
}

void ParenthesizedExpression::visitAll(ASTNodeVisitor& v)
{
    Expression::visitAll(v);

    if (expr)
    {
        expr->visitAll(v);
    }

    v.leave(*this);
}

ClassInstanceCreator::~ClassInstanceCreator()
{
    if (type)
    {
        delete type;
    }

    if (arguments)
    {
        delete arguments;
    }
}

void ClassInstanceCreator::visitAll(ASTNodeVisitor& v)
{
    Expression::visitAll(v);

    if (type)
    {
        type->visitAll(v);
    }

    if (arguments)
    {
        arguments->visitAll(v);
    }

    v.leave(*this);
}

ArrayCreator::~ArrayCreator()
{
    if (type)
    {
        delete type;
    }

    if (argument)
    {
        delete argument;
    }
}

void ArrayCreator::visitAll(ASTNodeVisitor& v)
{
    Expression::visitAll(v);

    if (type)
    {
        type->visitAll(v);
    }

    if (argument)
    {
        argument->visitAll(v);
    }

    v.leave(*this);
}

ChainableExpression::~ChainableExpression()
{
    if (prevExpr)
    {
        delete prevExpr;
    }
}

void ChainableExpression::visitAll(ASTNodeVisitor& v)
{
    Expression::visitAll(v);

    if (prevExpr)
    {
        prevExpr->visitAll(v);
    }
}

MethodCall::~MethodCall()
{
    if (name)
    {
        delete name;
    }

    if (arguments)
    {
        delete arguments;
    }
}

void MethodCall::visitAll(ASTNodeVisitor& v)
{
    ChainableExpression::visitAll(v);

    if (name)
    {
        name->visitAll(v);
    }

    if (arguments)
    {
        arguments->visitAll(v);
    }

    v.leave(*this);
}

FieldAccess::~FieldAccess()
{
    if (name)
    {
        delete name;
    }
}

void FieldAccess::visitAll(ASTNodeVisitor& v)
{
    ChainableExpression::visitAll(v);

    if (name)
    {
        name->visitAll(v);
    }

    v.leave(*this);
}

ArrayAccess::~ArrayAccess()
{
    if (indexExpr)
    {
        delete indexExpr;
    }
}

void ArrayAccess::visitAll(ASTNodeVisitor& v)
{
    ChainableExpression::visitAll(v);

    if (indexExpr)
    {
        indexExpr->visitAll(v);
    }

    v.leave(*this);
}

ThisExpression::~ThisExpression()
{
    if (expression)
    {
        delete expression;
    }
}

void ThisExpression::visitAll(ASTNodeVisitor& v)
{
    ChainableExpression::visitAll(v);

    if (expression)
    {
        expression->visitAll(v);
    }

    v.leave(*this);
}

VariableDeclarationExpression::~VariableDeclarationExpression()
{
    if (type)
    {
        delete type;
    }

    if (name)
    {
        delete name;
    }

    if (initializer)
    {
        delete initializer;
    }
}

void VariableDeclarationExpression::visitAll(ASTNodeVisitor& v)
{
    Expression::visitAll(v);

    if (type)
    {
        type->visitAll(v);
    }

    if (name)
    {
        type->visitAll(v);
    }

    if (initializer)
    {
        initializer->visitAll(v);
    }

    v.leave(*this);
}

InstanceOfExpression::~InstanceOfExpression()
{
    if (expression)
    {
        delete expression;
    }

    if (type)
    {
        delete type;
    }
}

void InstanceOfExpression::visitAll(ASTNodeVisitor& v)
{
    Expression::visitAll(v);

    if (expression)
    {
        expression->visitAll(v);
    }

    if (type)
    {
        type->visitAll(v);
    }

    v.leave(*this);
}

ExpressionStatement::~ExpressionStatement()
{
    if (expression)
    {
        delete expression;
    }
}

void ExpressionStatement::visitAll(ASTNodeVisitor& v)
{
    Statement::visitAll(v);

    if (expression)
    {
        expression->visitAll(v);
    }

    v.leave(*this);
}

ReturnStatement::~ReturnStatement()
{
    if (expression)
    {
        delete expression;
    }
}

void ReturnStatement::visitAll(ASTNodeVisitor& v)
{
    Statement::visitAll(v);

    if (expression)
    {
        expression->visitAll(v);
    }

    v.leave(*this);
}

IfStatement::~IfStatement()
{
    if (ifCondition)
    {
        delete ifCondition;
    }

    if (ifBody)
    {
        delete ifBody;
    }

    if (elseBody)
    {
        delete elseBody;
    }
}

void IfStatement::visitAll(ASTNodeVisitor& v)
{
    Statement::visitAll(v);

    if (ifCondition)
    {
        ifCondition->visitAll(v);
    }

    if (ifBody)
    {
        ifBody->visitAll(v);
    }

    if (elseBody)
    {
        elseBody->visitAll(v);
    }

    v.leave(*this);
}

ForStatement::~ForStatement()
{
    if (forInit)
    {
        delete forInit;
    }

    if (forCheck)
    {
        delete forCheck;
    }

    if (forUpdate)
    {
        delete forUpdate;
    }

    if (body)
    {
        delete body;
    }
}

void ForStatement::visitAll(ASTNodeVisitor& v)
{
    Statement::visitAll(v);

    if (forInit)
    {
        forInit->visitAll(v);
    }

    if (forCheck)
    {
        forCheck->visitAll(v);
    }

    if (forUpdate)
    {
        forUpdate->visitAll(v);
    }

    if (body)
    {
        body->visitAll(v);
    }

    v.leave(*this);
}

WhileStatement::~WhileStatement()
{
    if (condition)
    {
        delete condition;
    }

    if (body)
    {
        delete body;
    }
}

void WhileStatement::visitAll(ASTNodeVisitor& v)
{
    Statement::visitAll(v);

    if (condition)
    {
        condition->visitAll(v);
    }

    if (body)
    {
        body->visitAll(v);
    }

    v.leave(*this);
}

Block::~Block()
{
    if (statements)
    {
        delete statements;
    }
}

void Block::visitAll(ASTNodeVisitor& v)
{
    Statement::visitAll(v);

    if (statements)
    {
        statements->visitAll(v);
    }

    v.leave(*this);
}

PackageDeclaration::~PackageDeclaration()
{
    if (name)
    {
        delete name;
    }
}

void PackageDeclaration::visitAll(ASTNodeVisitor& v)
{
    ASTNode::visitAll(v);

    if (name)
    {
        name->visitAll(v);
    }

    v.leave(*this);
}

ImportDeclaration::~ImportDeclaration()
{
    if (name)
    {
        delete name;
    }
}

void ImportDeclaration::visitAll(ASTNodeVisitor& v)
{
    ASTNode::visitAll(v);

    if (name)
    {
        name->visitAll(v);
    }

    v.leave(*this);
}

TypeDeclaration::~TypeDeclaration()
{
    if (modifiers)
    {
        delete modifiers;
    }
}

void TypeDeclaration::visitAll(ASTNodeVisitor& v)
{
    ASTNode::visitAll(v);

    if (modifiers)
    {
        modifiers->visitAll(v);
    }
}

MemberDeclaration::~MemberDeclaration()
{
    if (modifiers)
    {
        delete modifiers;
    }
}

void MemberDeclaration::visitAll(ASTNodeVisitor& v)
{
    ASTNode::visitAll(v);

    if (modifiers)
    {
        modifiers->visitAll(v);
    }
}

ClassDeclaration::~ClassDeclaration()
{
    if (name)
    {
        delete name;
    }

    if (baseType)
    {
        delete baseType;
    }

    if (interfaces)
    {
        delete interfaces;
    }

    if (classBody)
    {
        delete classBody;
    }
}

void ClassDeclaration::visitAll(ASTNodeVisitor& v)
{
    TypeDeclaration::visitAll(v);

    if (name)
    {
        name->visitAll(v);
    }

    if (baseType)
    {
        baseType->visitAll(v);
    }

    if (interfaces)
    {
        interfaces->visitAll(v);
    }

    if (classBody)
    {
        classBody->visitAll(v);
    }
}

InterfaceDeclaration::~InterfaceDeclaration()
{
    if (name)
    {
        delete name;
    }

    if (extends)
    {
        delete extends;
    }

    if (interfaceBody)
    {
        delete interfaceBody;
    }
}

void InterfaceDeclaration::visitAll(ASTNodeVisitor& v)
{
    TypeDeclaration::visitAll(v);

    if (name)
    {
        name->visitAll(v);
    }

    if (extends)
    {
        extends->visitAll(v);
    }

    if (interfaceBody)
    {
        interfaceBody->visitAll(v);
    }

    v.leave(*this);
}

FormalParameter::~FormalParameter()
{
    if (type)
    {
        delete type;
    }

    if (id)
    {
        delete id;
    }
}

void FormalParameter::visitAll(ASTNodeVisitor& v)
{
    ASTNode::visitAll(v);

    if (type)
    {
        type->visitAll(v);
    }

    if (id)
    {
        id->visitAll(v);
    }

    v.leave(*this);
}

ConstructorDeclaration::~ConstructorDeclaration()
{
    if (parameters)
    {
        delete parameters;
    }

    if (body)
    {
        delete body;
    }
}

void ConstructorDeclaration::visitAll(ASTNodeVisitor& v)
{
    MemberDeclaration::visitAll(v);

    if (parameters)
    {
        parameters->visitAll(v);
    }

    if (body)
    {
        body->visitAll(v);
    }

    v.leave(*this);
}

FieldDeclaration::~FieldDeclaration()
{
    if (declaration)
    {
        delete declaration;
    }
}

void FieldDeclaration::visitAll(ASTNodeVisitor& v)
{
    MemberDeclaration::visitAll(v);

    if (declaration)
    {
        declaration->visitAll(v);
    }

    v.leave(*this);
}

MethodDeclaration::~MethodDeclaration()
{
    if (type)
    {
        delete type;
    }

    if (name)
    {
        delete name;
    }

    if (parameters)
    {
        delete parameters;
    }

    if (body)
    {
        delete body;
    }
}

void MethodDeclaration::visitAll(ASTNodeVisitor& v)
{
    MemberDeclaration::visitAll(v);

    if (type)
    {
        type->visitAll(v);
    }

    if (name)
    {
        name->visitAll(v);
    }

    if (parameters)
    {
        parameters->visitAll(v);
    }

    if (body)
    {
        body->visitAll(v);
    }

    v.leave(*this);
}

CompilerUnit::~CompilerUnit()
{
    if (packageDecl)
    {
        delete packageDecl;
    }

    if (importDecls)
    {
        delete importDecls;
    }

    if (typeDecl)
    {
        delete typeDecl;
    }
}

void CompilerUnit::visitAll(ASTNodeVisitor& v)
{
    ASTNode::visitAll(v);

    if (packageDecl)
    {
        packageDecl->visitAll(v);
    }

    if (importDecls)
    {
        importDecls->visitAll(v);
    }

    if (typeDecl)
    {
        typeDecl->visitAll(v);
    }

    v.leave(*this);
}