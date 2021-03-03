#include "ASTNode.h"

void ASTNodeVisitor::visit(ASTNode& node){}
void ASTNodeVisitor::visit(Expression& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(Statement& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(Type& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(Name& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(ChainableExpression& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(TypeDeclaration& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(MemberDeclaration& node){ visit(dynamic_cast<ASTNode&>(node)); }

void ASTNodeVisitor::visit(ASTNodeList<Type>& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(ASTNodeList<Modifier>& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(ASTNodeList<Statement>& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(ASTNodeList<Expression>& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(ASTNodeList<FormalParameter>& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(ASTNodeList<ImportDeclaration>& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(ASTNodeList<MemberDeclaration>& node){ visit(dynamic_cast<ASTNode&>(node)); }

void ASTNodeVisitor::visit(SimpleName& node){ visit(dynamic_cast<Name&>(node)); }
void ASTNodeVisitor::visit(QualifiedName& node){ visit(dynamic_cast<Name&>(node)); }
void ASTNodeVisitor::visit(PrimitiveType& node){ visit(dynamic_cast<Type&>(node)); }
void ASTNodeVisitor::visit(QualifiedType& node){ visit(dynamic_cast<Type&>(node)); }
void ASTNodeVisitor::visit(ArrayType& node){ visit(dynamic_cast<Type&>(node)); }
void ASTNodeVisitor::visit(IntLiteral& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(CharLiteral& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(StringLiteral& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(BooleanLiteral& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(NullLiteral& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(BinaryOperation& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(PrefixOperation& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(CastExpression& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(AssignmentExpression& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(ParenthesizedExpression& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(ClassInstanceCreator& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(ArrayCreator& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(MethodCall& node){ visit(dynamic_cast<ChainableExpression&>(node)); }
void ASTNodeVisitor::visit(FieldAccess& node){ visit(dynamic_cast<ChainableExpression&>(node)); }
void ASTNodeVisitor::visit(ArrayAccess& node){ visit(dynamic_cast<ChainableExpression&>(node)); }
void ASTNodeVisitor::visit(ThisExpression& node){ visit(dynamic_cast<ChainableExpression&>(node)); }
void ASTNodeVisitor::visit(VariableDeclarationExpression& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(InstanceOfExpression& node){ visit(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::visit(ExpressionStatement& node){ visit(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::visit(EmptyStatement& node){ visit(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::visit(ReturnStatement& node){ visit(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::visit(IfStatement& node){ visit(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::visit(ForStatement& node){ visit(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::visit(WhileStatement& node){ visit(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::visit(Block& node){ visit(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::visit(PackageDeclaration& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(ImportDeclaration& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(Modifier& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(ClassDeclaration& node){ visit(dynamic_cast<TypeDeclaration&>(node)); }
void ASTNodeVisitor::visit(InterfaceDeclaration& node){ visit(dynamic_cast<TypeDeclaration&>(node)); }
void ASTNodeVisitor::visit(FormalParameter& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(ConstructorDeclaration& node){ visit(dynamic_cast<MemberDeclaration&>(node)); }
void ASTNodeVisitor::visit(FieldDeclaration& node){ visit(dynamic_cast<MemberDeclaration&>(node)); }
void ASTNodeVisitor::visit(MethodDeclaration& node){ visit(dynamic_cast<MemberDeclaration&>(node)); }
void ASTNodeVisitor::visit(CompilerUnit& node){ visit(dynamic_cast<ASTNode&>(node)); }

void ASTNodeVisitor::leave(ASTNode& node){}
void ASTNodeVisitor::leave(Expression& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(Statement& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(Type& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(Name& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(ChainableExpression& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(TypeDeclaration& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(MemberDeclaration& node){ leave(dynamic_cast<ASTNode&>(node)); }

void ASTNodeVisitor::leave(ASTNodeList<Type>& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(ASTNodeList<Modifier>& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(ASTNodeList<Statement>& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(ASTNodeList<Expression>& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(ASTNodeList<FormalParameter>& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(ASTNodeList<ImportDeclaration>& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(ASTNodeList<MemberDeclaration>& node){ leave(dynamic_cast<ASTNode&>(node)); }

void ASTNodeVisitor::leave(SimpleName& node){ leave(dynamic_cast<Name&>(node)); }
void ASTNodeVisitor::leave(QualifiedName& node){ leave(dynamic_cast<Name&>(node)); }
void ASTNodeVisitor::leave(PrimitiveType& node){ leave(dynamic_cast<Type&>(node)); }
void ASTNodeVisitor::leave(QualifiedType& node){ leave(dynamic_cast<Type&>(node)); }
void ASTNodeVisitor::leave(ArrayType& node){ leave(dynamic_cast<Type&>(node)); }
void ASTNodeVisitor::leave(IntLiteral& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(CharLiteral& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(StringLiteral& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(BooleanLiteral& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(NullLiteral& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(BinaryOperation& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(PrefixOperation& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(CastExpression& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(AssignmentExpression& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(ParenthesizedExpression& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(ClassInstanceCreator& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(ArrayCreator& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(MethodCall& node){ leave(dynamic_cast<ChainableExpression&>(node)); }
void ASTNodeVisitor::leave(FieldAccess& node){ leave(dynamic_cast<ChainableExpression&>(node)); }
void ASTNodeVisitor::leave(ArrayAccess& node){ leave(dynamic_cast<ChainableExpression&>(node)); }
void ASTNodeVisitor::leave(ThisExpression& node){ leave(dynamic_cast<ChainableExpression&>(node)); }
void ASTNodeVisitor::leave(VariableDeclarationExpression& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(InstanceOfExpression& node){ leave(dynamic_cast<Expression&>(node)); }
void ASTNodeVisitor::leave(ExpressionStatement& node){ leave(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::leave(EmptyStatement& node){ leave(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::leave(ReturnStatement& node){ leave(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::leave(IfStatement& node){ leave(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::leave(ForStatement& node){ leave(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::leave(WhileStatement& node){ leave(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::leave(Block& node){ leave(dynamic_cast<Statement&>(node)); }
void ASTNodeVisitor::leave(PackageDeclaration& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(ImportDeclaration& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(Modifier& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(ClassDeclaration& node){ leave(dynamic_cast<TypeDeclaration&>(node)); }
void ASTNodeVisitor::leave(InterfaceDeclaration& node){ leave(dynamic_cast<TypeDeclaration&>(node)); }
void ASTNodeVisitor::leave(FormalParameter& node){ leave(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::leave(ConstructorDeclaration& node){ leave(dynamic_cast<MemberDeclaration&>(node)); }
void ASTNodeVisitor::leave(FieldDeclaration& node){ leave(dynamic_cast<MemberDeclaration&>(node)); }
void ASTNodeVisitor::leave(MethodDeclaration& node){ leave(dynamic_cast<MemberDeclaration&>(node)); }
void ASTNodeVisitor::leave(CompilerUnit& node){ leave(dynamic_cast<ASTNode&>(node)); }

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
