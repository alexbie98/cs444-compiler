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
    visitAllInner(v);
    v.leave(*this);
}

void ASTNode::visitAllInner(ASTNodeVisitor& v)
{
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

void QualifiedName::visitAllInner(ASTNodeVisitor& v)
{
    Name::visitAllInner(v);
    if (name)
    {
        name->visitAll(v);
    }

    if (simpleName)
    {
        simpleName->visitAll(v);
    }
}

QualifiedType::~QualifiedType()
{
    if (name)
    {
        delete name;
    }
}

std::string QualifiedType::getTypeName() const
{
    return dynamic_cast<const TypeDeclaration*>(name->refers_to)->fullyQualifiedName;
}

void QualifiedType::visitAllInner(ASTNodeVisitor& v)
{
    Type::visitAllInner(v);

    if (name)
    {
        name->visitAll(v);
    }
}

ArrayType::~ArrayType()
{
    if (elementType)
    {
        delete elementType;
    }
}

std::string ArrayType::getTypeName() const
{
    return elementType->getTypeName() + "[]";
}

void ArrayType::visitAllInner(ASTNodeVisitor& v)
{
    Type::visitAllInner(v);

    if (elementType)
    {
        elementType->visitAll(v);
    }  
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

void BinaryOperation::visitAllInner(ASTNodeVisitor& v)
{
    Expression::visitAllInner(v);

    if (lhs)
    {
        lhs->visitAll(v);
    }

    if (rhs)
    {
        rhs->visitAll(v);
    }
}

PrefixOperation::~PrefixOperation()
{
    if (operand)
    {
        delete operand;
    }
}

void PrefixOperation::visitAllInner(ASTNodeVisitor& v)
{
    Expression::visitAllInner(v);

    if (operand)
    {
        operand->visitAll(v);
    }
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

void CastExpression::visitAllInner(ASTNodeVisitor& v)
{
    Expression::visitAllInner(v);

    if (castType)
    {
        castType->visitAll(v);
    }

    if (expression)
    {
        expression->visitAll(v);
    }
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

void AssignmentExpression::visitAllInner(ASTNodeVisitor& v)
{
    Expression::visitAllInner(v);

    if (lhs)
    {
        lhs->visitAll(v);
    }

    if (rhs)
    {
        rhs->visitAll(v);
    } 
}

ParenthesizedExpression::~ParenthesizedExpression()
{
    if (expr)
    {
        delete expr;
    }
}

void ParenthesizedExpression::visitAllInner(ASTNodeVisitor& v)
{
    Expression::visitAllInner(v);

    if (expr)
    {
        expr->visitAll(v);
    }
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

void ClassInstanceCreator::visitAllInner(ASTNodeVisitor& v)
{
    Expression::visitAllInner(v);

    if (type)
    {
        type->visitAll(v);
    }

    if (arguments)
    {
        arguments->visitAll(v);
    }
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

void ArrayCreator::visitAllInner(ASTNodeVisitor& v)
{
    Expression::visitAllInner(v);

    if (type)
    {
        type->visitAll(v);
    }

    if (argument)
    {
        argument->visitAll(v);
    } 
}

ChainableExpression::~ChainableExpression()
{
    if (prevExpr)
    {
        delete prevExpr;
    }
}

void ChainableExpression::visitAllInner(ASTNodeVisitor& v)
{
    Expression::visitAllInner(v);

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

void MethodCall::visitAllInner(ASTNodeVisitor& v)
{
    ChainableExpression::visitAllInner(v);

    if (name)
    {
        name->visitAll(v);
    }

    if (arguments)
    {
        arguments->visitAll(v);
    } 
}

FieldAccess::~FieldAccess()
{
    if (name)
    {
        delete name;
    }
}

void FieldAccess::visitAllInner(ASTNodeVisitor& v)
{
    ChainableExpression::visitAllInner(v);

    if (name)
    {
        name->visitAll(v);
    } 
}

ArrayAccess::~ArrayAccess()
{
    if (indexExpr)
    {
        delete indexExpr;
    }
}

void ArrayAccess::visitAllInner(ASTNodeVisitor& v)
{
    ChainableExpression::visitAllInner(v);

    if (indexExpr)
    {
        indexExpr->visitAll(v);
    }
}

ThisExpression::~ThisExpression()
{
    if (expression)
    {
        delete expression;
    }
}

void ThisExpression::visitAllInner(ASTNodeVisitor& v)
{
    ChainableExpression::visitAllInner(v);

    if (expression)
    {
        expression->visitAll(v);
    }
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

void VariableDeclarationExpression::visitAllInner(ASTNodeVisitor& v)
{
    Expression::visitAllInner(v);

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

void InstanceOfExpression::visitAllInner(ASTNodeVisitor& v)
{
    Expression::visitAllInner(v);

    if (expression)
    {
        expression->visitAll(v);
    }

    if (type)
    {
        type->visitAll(v);
    }
}

ExpressionStatement::~ExpressionStatement()
{
    if (expression)
    {
        delete expression;
    }
}

void ExpressionStatement::visitAllInner(ASTNodeVisitor& v)
{
    Statement::visitAllInner(v);

    if (expression)
    {
        expression->visitAll(v);
    } 
}

ReturnStatement::~ReturnStatement()
{
    if (expression)
    {
        delete expression;
    }
}

void ReturnStatement::visitAllInner(ASTNodeVisitor& v)
{
    Statement::visitAllInner(v);

    if (expression)
    {
        expression->visitAll(v);
    } 
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

void IfStatement::visitAllInner(ASTNodeVisitor& v)
{
    Statement::visitAllInner(v);

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

void ForStatement::visitAllInner(ASTNodeVisitor& v)
{
    Statement::visitAllInner(v);

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

void WhileStatement::visitAllInner(ASTNodeVisitor& v)
{
    Statement::visitAllInner(v);

    if (condition)
    {
        condition->visitAll(v);
    }

    if (body)
    {
        body->visitAll(v);
    } 
}

Block::~Block()
{
    if (statements)
    {
        delete statements;
    }
}

void Block::visitAllInner(ASTNodeVisitor& v)
{
    Statement::visitAllInner(v);

    if (statements)
    {
        statements->visitAll(v);
    }
}

PackageDeclaration::~PackageDeclaration()
{
    if (name)
    {
        delete name;
    }
}

void PackageDeclaration::visitAllInner(ASTNodeVisitor& v)
{
    ASTNode::visitAllInner(v);

    if (name)
    {
        name->visitAll(v);
    }
}

ImportDeclaration::~ImportDeclaration()
{
    if (name)
    {
        delete name;
    }
}

void ImportDeclaration::visitAllInner(ASTNodeVisitor& v)
{
    ASTNode::visitAllInner(v);

    if (name)
    {
        name->visitAll(v);
    }
}

TypeDeclaration::~TypeDeclaration()
{
    if (modifiers)
    {
        delete modifiers;
    }
}

void TypeDeclaration::visitAllInner(ASTNodeVisitor& v)
{
    ASTNode::visitAllInner(v);

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

void MemberDeclaration::visitAllInner(ASTNodeVisitor& v)
{
    ASTNode::visitAllInner(v);

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

void ClassDeclaration::visitAllInner(ASTNodeVisitor& v)
{
    TypeDeclaration::visitAllInner(v);

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

void InterfaceDeclaration::visitAllInner(ASTNodeVisitor& v)
{
    TypeDeclaration::visitAllInner(v);

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

void FormalParameter::visitAllInner(ASTNodeVisitor& v)
{
    ASTNode::visitAllInner(v);

    if (type)
    {
        type->visitAll(v);
    }

    if (id)
    {
        id->visitAll(v);
    } 
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

std::string ConstructorDeclaration::getSignature() const
{
    std::string ret = "(";
    for (FormalParameter* param : parameters->elements)
    {
        ret += param->type->getTypeName() + " ";
    }
    ret += ")";
    return ret;
}

void ConstructorDeclaration::visitAllInner(ASTNodeVisitor& v)
{
    MemberDeclaration::visitAllInner(v);

    if (parameters)
    {
        parameters->visitAll(v);
    }

    if (body)
    {
        body->visitAll(v);
    }
}

FieldDeclaration::~FieldDeclaration()
{
    if (declaration)
    {
        delete declaration;
    }
}

void FieldDeclaration::visitAllInner(ASTNodeVisitor& v)
{
    MemberDeclaration::visitAllInner(v);

    if (declaration)
    {
        declaration->visitAll(v);
    }
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

std::string MethodDeclaration::getSignature() const
{
    std::string ret = name->getString() + "(";
    for (FormalParameter* param : parameters->elements)
    {
        ret += param->type->getTypeName() + " ";
    }
    ret += ")";
    return ret;
}

void MethodDeclaration::visitAllInner(ASTNodeVisitor& v)
{
    MemberDeclaration::visitAllInner(v);

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

void CompilerUnit::visitAllInner(ASTNodeVisitor& v)
{
    ASTNode::visitAllInner(v);

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
}

std::string PrimitiveType::getTypeName() const
{
    switch (type)
    {
    case BYTE: return "byte";
    case SHORT: return "shrrt";
    case INT: return "int";
    case CHAR: return "char";
    case BOOLEAN: return "boolean";
    case VOID: return "void";
    }
    return "";
}
