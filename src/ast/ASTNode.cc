#include "ASTNode.h"

void ASTNodeVisitor::visit(ASTNode& node){}
void ASTNodeVisitor::visit(Expression& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(Statement& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(Type& node){ visit(dynamic_cast<ASTNode&>(node)); }
void ASTNodeVisitor::visit(Name& node){ visit(dynamic_cast<ASTNode&>(node)); }
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
void ASTNodeVisitor::visit(NameExpression& node) { visit(dynamic_cast<Expression&>(node)); }
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
void ASTNodeVisitor::leave(Name& node){ leave(dynamic_cast<ASTNode&>(node)); }
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
void ASTNodeVisitor::leave(NameExpression& node) { leave(dynamic_cast<Expression&>(node)); }
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
    visitChildren(v);
    leave(v);
}

void ASTNode::visitChildren(ASTNodeVisitor& v)
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

void QualifiedName::visitChildren(ASTNodeVisitor& v)
{
    Name::visitChildren(v);
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

void QualifiedType::visitChildren(ASTNodeVisitor& v)
{
    Type::visitChildren(v);

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
    return elementType->getTypeName() + "_array";
}

void ArrayType::visitChildren(ASTNodeVisitor& v)
{
    Type::visitChildren(v);

    if (elementType)
    {
        elementType->visitAll(v);
    }  
}

NameExpression::~NameExpression()
{
    if (name)
    {
        delete name;
    }

    if (field)
    {
        delete field;
    }
}

void NameExpression::visitChildren(ASTNodeVisitor& v)
{
    Expression::visitChildren(v);

    if (name)
    {
        name->visitAll(v);
    }

    if (field)
    {
        field->visitAll(v);
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

void BinaryOperation::visitChildren(ASTNodeVisitor& v)
{
    Expression::visitChildren(v);

    if (lhs)
    {
        lhs->visitAll(v);
    }

    if (rhs)
    {
        rhs->visitAll(v);
    }
}

int BinaryOperation::LABEL_NUM = 0;

PrefixOperation::~PrefixOperation()
{
    if (operand)
    {
        delete operand;
    }
}

void PrefixOperation::visitChildren(ASTNodeVisitor& v)
{
    Expression::visitChildren(v);

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

void CastExpression::visitChildren(ASTNodeVisitor& v)
{
    Expression::visitChildren(v);

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

void AssignmentExpression::visitChildren(ASTNodeVisitor& v)
{
    Expression::visitChildren(v);

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

void ParenthesizedExpression::visitChildren(ASTNodeVisitor& v)
{
    Expression::visitChildren(v);

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

void ClassInstanceCreator::visitChildren(ASTNodeVisitor& v)
{
    Expression::visitChildren(v);

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

void ArrayCreator::visitChildren(ASTNodeVisitor& v)
{
    Expression::visitChildren(v);

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

void ChainableExpression::visitChildren(ASTNodeVisitor& v)
{
    Expression::visitChildren(v);

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

void MethodCall::visitChildren(ASTNodeVisitor& v)
{
    ChainableExpression::visitChildren(v);

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

void FieldAccess::visitChildren(ASTNodeVisitor& v)
{
    ChainableExpression::visitChildren(v);

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

void ArrayAccess::visitChildren(ASTNodeVisitor& v)
{
    ChainableExpression::visitChildren(v);

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

void ThisExpression::visitChildren(ASTNodeVisitor& v)
{
    ChainableExpression::visitChildren(v);

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

void VariableDeclarationExpression::visitChildren(ASTNodeVisitor& v)
{
    Expression::visitChildren(v);

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

void InstanceOfExpression::visitChildren(ASTNodeVisitor& v)
{
    Expression::visitChildren(v);

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

void ExpressionStatement::visitChildren(ASTNodeVisitor& v)
{
    Statement::visitChildren(v);

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

void ReturnStatement::visitChildren(ASTNodeVisitor& v)
{
    Statement::visitChildren(v);

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

void IfStatement::visitChildren(ASTNodeVisitor& v)
{
    Statement::visitChildren(v);

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

int IfStatement::LABEL_NUM = 0;

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

void ForStatement::visitChildren(ASTNodeVisitor& v)
{
    Statement::visitChildren(v);

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

int ForStatement::LABEL_NUM = 0;

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

void WhileStatement::visitChildren(ASTNodeVisitor& v)
{
    Statement::visitChildren(v);

    if (condition)
    {
        condition->visitAll(v);
    }

    if (body)
    {
        body->visitAll(v);
    } 
}

int WhileStatement::LABEL_NUM = 0;

Block::~Block()
{
    if (statements)
    {
        delete statements;
    }
}

void Block::visitChildren(ASTNodeVisitor& v)
{
    Statement::visitChildren(v);

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

void PackageDeclaration::visitChildren(ASTNodeVisitor& v)
{
    ASTNode::visitChildren(v);

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

void ImportDeclaration::visitChildren(ASTNodeVisitor& v)
{
    ASTNode::visitChildren(v);

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

void TypeDeclaration::visitChildren(ASTNodeVisitor& v)
{
    ASTNode::visitChildren(v);

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

void MemberDeclaration::visitChildren(ASTNodeVisitor& v)
{
    ASTNode::visitChildren(v);

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

    if (extends)
    {
        delete extends;
    }

    if (implements)
    {
        delete implements;
    }

    if (classBody)
    {
        delete classBody;
    }
}

void ClassDeclaration::visitChildren(ASTNodeVisitor& v)
{
    TypeDeclaration::visitChildren(v);

    if (name)
    {
        name->visitAll(v);
    }

    if (extends)
    {
        extends->visitAll(v);
    }

    if (implements)
    {
        implements->visitAll(v);
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

void InterfaceDeclaration::visitChildren(ASTNodeVisitor& v)
{
    TypeDeclaration::visitChildren(v);

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

void FormalParameter::visitChildren(ASTNodeVisitor& v)
{
    ASTNode::visitChildren(v);

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
    std::string ret = "constructor_args_";
    for (FormalParameter* param : parameters->elements)
    {
        ret += "_" + param->type->getTypeName();
    }
    return ret;
}

void ConstructorDeclaration::visitChildren(ASTNodeVisitor& v)
{
    MemberDeclaration::visitChildren(v);

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

void FieldDeclaration::visitChildren(ASTNodeVisitor& v)
{
    MemberDeclaration::visitChildren(v);

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
    // To be complient with NASM labels, use letters, numbers, _, $, #, @, ~, ., and ? and start with letter
    std::string ret = "method_" + name->getString() + "_args";
    for (FormalParameter* param : parameters->elements)
    {
        ret += "_" + param->type->getTypeName();
    }
    return ret;
}

void MethodDeclaration::visitChildren(ASTNodeVisitor& v)
{
    MemberDeclaration::visitChildren(v);

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

void CompilerUnit::visitChildren(ASTNodeVisitor& v)
{
    ASTNode::visitChildren(v);

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

Expression::~Expression()
{
    if (resolvedType)
    {
        delete resolvedType;
    }
}
