#include "ASTBuilder.h"
#include <assert.h>
#include <iostream>

void ParentVisitor::visit(ASTNode& node)
{
    // std::cout << node.toString() << std::endl;
    node.parent = parents.top();
    parents.push(&node);
}

void ParentVisitor::leave(ASTNode& node)
{
    assert(parents.top() == &node); // TODO This assertion fails
    parents.pop();
}

void setParents(ASTNode* ast)
{
    ParentVisitor visitor;
    ast->visitAll(visitor);
}

ASTNode* buildAST(ParseTreeNode* node)
{
    switch (node->symbol)
    {
        case ID:
        {
            SimpleName* name = new SimpleName();
            name->id = node->token->second;
            return name;
        }
        case INT:
        {
            PrimitiveType* type = new PrimitiveType();
            type->type = PrimitiveType::INT;
            return type;
        }
        case BOOLEAN:
        {
            PrimitiveType* type = new PrimitiveType();
            type->type = PrimitiveType::BOOLEAN;
            return type;
        }
        case CHAR:
        {
            PrimitiveType* type = new PrimitiveType();
            type->type = PrimitiveType::CHAR;
            return type;
        }
        case BYTE:
        {
            PrimitiveType* type = new PrimitiveType();
            type->type = PrimitiveType::BYTE;
            return type;
        }
        case SHORT:
        {
            PrimitiveType* type = new PrimitiveType();
            type->type = PrimitiveType::SHORT;
            return type;
        }
        case VOID:
        {
            PrimitiveType* type = new PrimitiveType();
            type->type = PrimitiveType::VOID;
            return type;
        }
        case PUBLIC:
        {
            Modifier* modifier = new Modifier();
            modifier->type = Modifier::PUBLIC;
            return modifier;
        }
        case PROTECTED:
        {
            Modifier* modifier = new Modifier();
            modifier->type = Modifier::PROTECTED;
            return modifier;
        }
        case STATIC:
        {
            Modifier* modifier = new Modifier();
            modifier->type = Modifier::STATIC;
            return modifier;
        }
        case ABSTRACT:
        {
            Modifier* modifier = new Modifier();
            modifier->type = Modifier::ABSTRACT;
            return modifier;
        }
        case FINAL:
        {
            Modifier* modifier = new Modifier();
            modifier->type = Modifier::FINAL;
            return modifier;
        }
        case NATIVE:
        {
            Modifier* modifier = new Modifier();
            modifier->type = Modifier::PUBLIC;
            return modifier;
        }
        case INT_LIT:
        {
            IntLiteral* lit = new IntLiteral();
            lit->value = std::stoll(node->token->second);
            return lit;
        }
        case BOOLEAN_LIT:
        {
            BooleanLiteral* lit = new BooleanLiteral();
            lit->value = (node->token->second == "true") ? true : false;
            return lit;
        }
        case NULL_LIT:
        {
            NullLiteral* lit = new NullLiteral();
            return lit;
        }
        case CHAR_LIT:
        {
            CharLiteral* lit = new CharLiteral();
            lit->value = node->token->second[0];
            return lit;
        }
        case STRING_LIT:
        {
            StringLiteral* lit = new StringLiteral();
            lit->value = node->token->second;
            return lit;
        }
        case LONG_IDENTIFIER:
        {
            if (node->children[0]->symbol == ID)
            {
                return buildAST(node->children[0]);
            }
            else
            {
                QualifiedName* qualifiedName = new QualifiedName();
                qualifiedName->name = dynamic_cast<Name*>(buildAST(node->children[0]));
                qualifiedName->simpleName = dynamic_cast<SimpleName*>(buildAST(node->children[2]));
                return qualifiedName;
            } 
        }
        case TYPE:
        {
            Type* type = nullptr;
            if (node->children[0]->symbol == LONG_IDENTIFIER)
            {
                QualifiedType* qualType = new QualifiedType();
                qualType->name = dynamic_cast<Name*>(buildAST(node->children[0]));
                type = qualType;
            }
            else
            {
                type = dynamic_cast<Type*>(buildAST(node->children[0]));
            }

            if (node->children.size() == 2)
            {
                ArrayType* arrayType = new ArrayType();
                arrayType->elementType = type;
                type = arrayType;
            }
            return type;
        }
        case EXPRESSION:
        {
            if (node->children.size() > 1)
            {
                AssignmentExpression* assignExpr = new AssignmentExpression();
                assignExpr->lhs = dynamic_cast<Expression*>(buildAST(node->children[0]));
                assignExpr->rhs = dynamic_cast<Expression*>(buildAST(node->children[2]));
                return assignExpr;
            }
            return buildAST(node->children[0]);
        }
        case EXPRESSION1:
        {
            if (node->children.size() == 1)
            {
                return buildAST(node->children[0]);
            }
            return buildAST(node->children[1]);
        }
        case EXPRESSION1_REST:
        {
            if (node->children[0]->symbol == INSTANCEOF)
            {
                InstanceOfExpression* instance = new InstanceOfExpression();
                instance->type = dynamic_cast<Type*>(buildAST(node->children[1]));
                instance->expression = dynamic_cast<Expression*>(buildAST(node->parent->children[0]));
                return instance;
            }

            BinaryOperation* binaryOp = dynamic_cast<BinaryOperation*>(buildAST(node->children[0]));
            BinaryOperation* nestedOp = binaryOp;
            while (nestedOp->lhs != nullptr)
            {
                nestedOp = dynamic_cast<BinaryOperation*>(nestedOp->lhs);
            }
            nestedOp->lhs = dynamic_cast<Expression*>(buildAST(node->parent->children[0]));

            if (node->children.size() == 3)
            {
                InstanceOfExpression* instance = new InstanceOfExpression();
                instance->type = dynamic_cast<Type*>(buildAST(node->children[2]));
                instance->expression = binaryOp;
                return instance;
            }

            return binaryOp;
        }
        case EXPRESSION_INFIX:
        {
            BinaryOperation* binaryOp = new BinaryOperation();
            
            int op = 0;
            if (node->children.size() == 2)
            {
                op = node->children[0]->children[0]->symbol;
                binaryOp->rhs = dynamic_cast<Expression*>(buildAST(node->children[1]));
            }
            else
            {
                op = node->children[1]->children[0]->symbol;
                binaryOp->lhs = dynamic_cast<Expression*>(buildAST(node->children[0]));
                binaryOp->rhs = dynamic_cast<Expression*>(buildAST(node->children[2]));
            }
            
            switch (op)
            {
                case EAGER_OR:
                {
                    binaryOp->op = BinaryOperation::EAGER_OR;
                    break;
                }
                case EAGER_AND:
                {
                    binaryOp->op = BinaryOperation::EAGER_AND;
                    break;
                }
                case OR:
                {
                    binaryOp->op = BinaryOperation::OR;
                    break;
                }
                case AND:
                {
                    binaryOp->op = BinaryOperation::AND;
                    break;
                }
                case XOR:
                {
                    binaryOp->op = BinaryOperation::XOR;
                    break;
                }
                case EQ:
                {
                    binaryOp->op = BinaryOperation::EQ;
                    break;
                }
                case NEQ:
                {
                    binaryOp->op = BinaryOperation::NEQ;
                    break;
                }
                case LEQ:
                {
                    binaryOp->op = BinaryOperation::LEQ;
                    break;
                }
                case GEQ:
                {
                    binaryOp->op = BinaryOperation::GEQ;
                    break;
                }
                case GT:
                {
                    binaryOp->op = BinaryOperation::GT;
                    break;
                }
                case LT:
                {
                    binaryOp->op = BinaryOperation::LT;
                    break;
                }
                case PLUS:
                {
                    binaryOp->op = BinaryOperation::PLUS;
                    break;
                }
                case MINUS:
                {
                    binaryOp->op = BinaryOperation::MINUS;
                    break;
                }
                case MULT:
                {
                    binaryOp->op = BinaryOperation::TIMES;
                    break;
                }
                case DIV:
                {
                    binaryOp->op = BinaryOperation::DIVIDE;
                    break;
                }
                case REMAINDER:
                {
                    binaryOp->op = BinaryOperation::REMAINDER;
                    break;
                }
            }

            return binaryOp;
        }
        case EXPRESSION2:
        {
            if (node->children.size() == 2)
            {
                PrefixOperation* prefix = new PrefixOperation();
                prefix->op = PrefixOperation::MINUS;
                prefix->operand = dynamic_cast<Expression*>(buildAST(node->children[1]));
                return prefix;
            }
            return buildAST(node->children[0]);
        }
        case EXPRESSION3:
        {
            if (node->children[0]->symbol == NOT)
            {
                PrefixOperation* prefix = new PrefixOperation();
                prefix->op = PrefixOperation::NOT;
                prefix->operand = dynamic_cast<Expression*>(buildAST(node->children[1]));
                return prefix;
            }
            else if (node->children[0]->symbol == LPAREN)
            {
                CastExpression* castExpr = new CastExpression();

                Type* castType = nullptr;
                if (node->children[1]->symbol == BASIC_TYPE)
                {
                    castType = dynamic_cast<Type*>(buildAST(node->children[1]));
                }
                else
                {
                    QualifiedType* qualType = new QualifiedType();
                    qualType->name = dynamic_cast<Name*>(buildAST(node->children[1]));
                    castType = qualType;
                }

                if (node->children[2]->symbol == ARRAY)
                {
                    ArrayType* arrayType = new ArrayType();
                    arrayType->elementType = castType;

                    castExpr->castType = arrayType;
                    castExpr->expression = dynamic_cast<Expression*>(buildAST(node->children[4]));
                }
                else
                {
                    castExpr->castType = castType;
                    castExpr->expression = dynamic_cast<Expression*>(buildAST(node->children[3]));
                }

                return castExpr;
            }
            else if (node->children.size() == 2)
            {
                ChainableExpression* chainableExpr = dynamic_cast<ChainableExpression*>(buildAST(node->children[1]));
                ChainableExpression* nestedExpr = chainableExpr;
                while (nestedExpr->prevExpr != nullptr)
                {
                    nestedExpr = dynamic_cast<ChainableExpression*>(nestedExpr->prevExpr);
                }
                nestedExpr->prevExpr = dynamic_cast<Expression*>(buildAST(node->children[0]));
                return chainableExpr;
            }

            return buildAST(node->children[0]);
        }
        case EXPRESSION_LIST:
        {
            ASTNodeList<Expression>* exprList;
            if (node->children.size() == 1)
            {
                exprList = new ASTNodeList<Expression>();
                exprList->elements.push_back(dynamic_cast<Expression*>(buildAST(node->children[0])));
            }
            else
            {
                exprList = dynamic_cast<ASTNodeList<Expression>*>(buildAST(node->children[0]));
                exprList->elements.push_back(dynamic_cast<Expression*>(buildAST(node->children[2])));
            }
            return exprList;
        }
        case EXPRESSION_OPT:
        {
            if (node->children.size() == 0)
            {
                return new ASTNodeList<Expression>();
            }
            return buildAST(node->children[0]);
        }
        case SELECTABLE_PRIMARY:
        {
            switch (node->children[0]->symbol)
            {
                case LPAREN:
                {
                    ParenthesizedExpression* parExpr = new ParenthesizedExpression();
                    parExpr->expr = dynamic_cast<Expression*>(buildAST(node->children[1]));
                    return parExpr;
                }
                case THIS:
                {
                    ThisExpression* expr = new ThisExpression();
                    expr->expression = nullptr;
                    return expr;
                }
                case LITERAL:
                {
                    return buildAST(node->children[0]);
                }
                case NEW:
                {
                    return buildAST(node->children[1]);
                }
                case LONG_IDENTIFIER:
                {
                    return buildAST(node->children[1]);
                }
            }
            return nullptr;
        }
        case SELECTORS:
        {
            if (node->children.size() == 1)
            {
                return buildAST(node->children[0]);
            }
            ChainableExpression* chainable = dynamic_cast<ChainableExpression*>(buildAST(node->children[1]));
            chainable->prevExpr = dynamic_cast<ChainableExpression*>(buildAST(node->children[0]));
            return chainable;
        }
        case SELECTOR:
        {
            if (node->children[0]->symbol == LBRACKET)
            {
                ArrayAccess* arrayAccess = new ArrayAccess();
                arrayAccess->indexExpr = dynamic_cast<Expression*>(buildAST(node->children[1]));
                return arrayAccess;
            }
            else if (node->children[1]->symbol == ID)
            {
                ASTNode* argsOpt = buildAST(node->children[2]);
                if (argsOpt != nullptr)
                {
                    ASTNodeList<Expression>* arguments = dynamic_cast<ASTNodeList<Expression>*>(argsOpt);
                    MethodCall* methodCall = new MethodCall();
                    methodCall->arguments = arguments;
                    methodCall->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
                    return methodCall;
                }
                else
                {
                    FieldAccess* fieldAccess = new FieldAccess;
                    fieldAccess->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
                    return fieldAccess;
                }
            }
        }
        case IDENTIFIER_SUFFIX:
        {
            if (node->children[0]->symbol == ARGUMENTS)
            {
                MethodCall* methodCall = new MethodCall();
                Name* name = dynamic_cast<Name*>(buildAST(node->parent->children[0]));
                if (SimpleName * simple = dynamic_cast<SimpleName*>(name))
                {
                    methodCall->name = simple;
                }
                else if (QualifiedName * qualified = dynamic_cast<QualifiedName*>(name))
                {
                    methodCall->name = qualified->simpleName;
                    methodCall->prevExpr = qualified->name;

                    qualified->name = nullptr;
                    qualified->simpleName = nullptr;
                    delete qualified;
                }
                methodCall->arguments = dynamic_cast<ASTNodeList<Expression>*>(buildAST(node->children[0]));
                return methodCall;
            }
            else if (node->children[0]->symbol == LBRACKET)
            {
                ArrayAccess* arrayAccess = new ArrayAccess();
                arrayAccess->indexExpr = dynamic_cast<Expression*>(buildAST(node->children[1]));
                arrayAccess->prevExpr = dynamic_cast<Expression*>(buildAST(node->parent->children[0]));
                return arrayAccess;
            }
            return nullptr;
        }
        case ARGUMENTS_OPT:
        {
            if (node->children.size() == 1)
            {
                return buildAST(node->children[0]);
            }
            return nullptr;
        }
        case ARGUMENTS:
        {
            if (node->children.size() == 2)
            {
                return new ASTNodeList<Expression>();
            }
            else
            {
                return buildAST(node->children[1]);
            }
        }
        case CREATOR:
        {
            return buildAST(node->children[1]);
        }
        case ARRAY_CREATOR_REST:
        {
            ArrayCreator* arrayCreator = new ArrayCreator();
            arrayCreator->argument = dynamic_cast<Expression*>(buildAST(node->children[1]));
            arrayCreator->type = new ArrayType();

            ASTNode* typeNode = buildAST(node->parent->children[0]);
            if (Type * type = dynamic_cast<Type*>(typeNode))
            {
                arrayCreator->type->elementType = type;
            }
            else if (Name * name = dynamic_cast<Name*>(typeNode))
            {
                QualifiedType* qualType = new QualifiedType();
                qualType->name = name;
                arrayCreator->type->elementType = qualType;
            }
            return arrayCreator;
        }
        case CLASS_CREATOR_REST:
        {
            ClassInstanceCreator* classCreator = new ClassInstanceCreator();
            classCreator->arguments = dynamic_cast<ASTNodeList<Expression>*>(buildAST(node->children[0]));

            QualifiedType* qualType = new QualifiedType();
            qualType->name = dynamic_cast<Name*>(buildAST(node->parent->children[0]));
            classCreator->type = qualType;

            return classCreator;
        }
        case VARIABLE_INITIALIZER:
        {
            VariableDeclarationExpression* varDecl = new VariableDeclarationExpression();
            varDecl->initializer = dynamic_cast<Expression*>(buildAST(node->children[0]));
            return varDecl;
        }
        case PAR_EXPRESSION:
        {
            return buildAST(node->children[1]);
        }
        case BLOCK:
        {
            Block* block = new Block();
            block->statements = dynamic_cast<ASTNodeList<Statement>*>(buildAST(node->children[1]));
            return block;
        }
        case BLOCK_BODY:
        {
            if (node->children.size() == 0)
            {
                return new ASTNodeList<Statement>();
            }
            return buildAST(node->children[0]);
        }
        case BLOCK_STATEMENTS:
        {
            ASTNodeList<Statement>* statements;
            if (node->children.size() == 1)
            {
                statements = new ASTNodeList<Statement>();

                if (dynamic_cast<Statement*>(buildAST(node->children[0])) == nullptr)
                {
                    ASTNode* ast = buildAST(node->children[0]);
                    return statements;
                }

                statements->elements.push_back(dynamic_cast<Statement*>(buildAST(node->children[0])));
            }
            else
            {
                statements = dynamic_cast<ASTNodeList<Statement>*>(buildAST(node->children[0]));

                if (dynamic_cast<Statement*>(buildAST(node->children[1])) == nullptr)
                {
                    ASTNode* ast = buildAST(node->children[1]);

                    return statements;
                }

                statements->elements.push_back(dynamic_cast<Statement*>(buildAST(node->children[1])));
            }
            return statements;
        }
        case LOCAL_VARIABLE_DECLARATION_STATEMENT:
        {
            VariableDeclarationExpression* varDeclStatement = dynamic_cast<VariableDeclarationExpression*>(buildAST(node->children[1]));
            varDeclStatement->type = dynamic_cast<Type*>(buildAST(node->children[0]));

            ExpressionStatement* expression = new ExpressionStatement;
            expression->expression = varDeclStatement;

            return expression;
        }
        case OPEN_STATEMENT:
        {
            switch (node->children[0]->symbol)
            {
                case IF:
                {
                    IfStatement* ifStatement = new IfStatement();
                    ifStatement->ifCondition = dynamic_cast<Expression*>(buildAST(node->children[1]));
                    ifStatement->ifBody = dynamic_cast<Statement*>(buildAST(node->children[2]));
                    if (node->children.size() == 5)
                    {
                        ifStatement->elseBody = dynamic_cast<Statement*>(buildAST(node->children[4]));
                    }
                    return ifStatement;
                }
                case WHILE:
                {
                    WhileStatement* whileStatement = new WhileStatement();
                    whileStatement->condition = dynamic_cast<Expression*>(buildAST(node->children[1]));
                    whileStatement->body = dynamic_cast<Statement*>(buildAST(node->children[2]));
                    return whileStatement;
                }
                case FOR:
                {
                    ForStatement* forStatement = new ForStatement();
                    forStatement->forInit = dynamic_cast<Expression*>(buildAST(node->children[2]));
                    forStatement->forCheck = dynamic_cast<Expression*>(buildAST(node->children[4]));
                    forStatement->forUpdate = dynamic_cast<Expression*>(buildAST(node->children[6]));
                    forStatement->body = dynamic_cast<Statement*>(buildAST(node->children[8]));
                    return forStatement;
                }
            }
            return new EmptyStatement();
        }
        case CLOSED_STATEMENT:
        {
            switch (node->children[0]->symbol)
            {
                case BLOCK:
                    return buildAST(node->children[0]);
                case IF:
                {
                    IfStatement* ifStatement = new IfStatement();
                    ifStatement->ifCondition = dynamic_cast<Expression*>(buildAST(node->children[1]));
                    ifStatement->ifBody = dynamic_cast<Statement*>(buildAST(node->children[2]));
                    ifStatement->elseBody = dynamic_cast<Statement*>(buildAST(node->children[4]));
                    return ifStatement;
                }
                case WHILE:
                {
                    WhileStatement* whileStatement = new WhileStatement();
                    whileStatement->condition = dynamic_cast<Expression*>(buildAST(node->children[1]));
                    whileStatement->body = dynamic_cast<Statement*>(buildAST(node->children[2]));
                    return whileStatement;
                }
                case FOR:
                {
                    ForStatement* forStatement = new ForStatement();
                    forStatement->forInit = dynamic_cast<Expression*>(buildAST(node->children[2]));
                    forStatement->forCheck = dynamic_cast<Expression*>(buildAST(node->children[4]));
                    forStatement->forUpdate = dynamic_cast<Expression*>(buildAST(node->children[6]));
                    forStatement->body = dynamic_cast<Statement*>(buildAST(node->children[8]));
                    return forStatement;
                }
                case RETURN:
                {
                    ReturnStatement* returnStatement = new ReturnStatement();
                    if (node->children.size() == 3)
                    {
                        returnStatement->expression = dynamic_cast<Expression*>(buildAST(node->children[1]));
                    }
                    return returnStatement;
                }
                case SEMICOLON:
                    return new EmptyStatement();
                case STATEMENT_EXPRESSION:
                {
                    ExpressionStatement* exprStatement = new ExpressionStatement();
                    exprStatement->expression = dynamic_cast<Expression*>(buildAST(node->children[0]));
                    return exprStatement;
                }
            }
            return new EmptyStatement();
        }
        case FOR_INIT_OPT:
        {
            if (node->children.size() == 0)
            {
                return nullptr;
            }
            return buildAST(node->children[0]);
        }
        case FOR_UPDATE_OPT:
        {
            if (node->children.size() == 0)
            {
                return nullptr;
            }
            return buildAST(node->children[0]);
        }
        case FOR_INIT:
        {
            if (node->children.size() == 2)
            {
                VariableDeclarationExpression* varDeclStatement = dynamic_cast<VariableDeclarationExpression*>(buildAST(node->children[1]));
                varDeclStatement->type = dynamic_cast<Type*>(buildAST(node->children[0]));
                return varDeclStatement;
            }
            return buildAST(node->children[0]);
        }
        case MODIFIERS_OPT:
        {
            if (node->children.size() == 0)
            {
                return new ASTNodeList<Modifier>();
            }
            return buildAST(node->children[0]);
        }
        case MODIFIERS:
        {
            ASTNodeList<Modifier>* modifiers;
            if (node->children.size() == 1)
            {
                modifiers = new ASTNodeList<Modifier>();
                modifiers->elements.push_back(dynamic_cast<Modifier*>(buildAST(node->children[0])));
            }
            else
            {
                modifiers = dynamic_cast<ASTNodeList<Modifier>*>(buildAST(node->children[0]));
                modifiers->elements.push_back(dynamic_cast<Modifier*>(buildAST(node->children[1])));
            }
            return modifiers;
        }
        case VARIABLE_DECLARATOR:
        {
            VariableDeclarationExpression* variableDeclaration = dynamic_cast<VariableDeclarationExpression*>(buildAST(node->children[1]));
            variableDeclaration->name = dynamic_cast<SimpleName*>(buildAST(node->children[0]));
            return variableDeclaration;
        }
        case VARIABLE_DECLARATOR_REST:
        {
            if (node->children.size() == 0)
            {
                return new VariableDeclarationExpression();
            }
            return buildAST(node->children[1]);
        }
        case COMPILER_UNIT:
        {
            CompilerUnit* compilerUnit = new CompilerUnit();
            compilerUnit->packageDecl = dynamic_cast<PackageDeclaration*>(buildAST(node->children[0]));
            compilerUnit->importDecls = dynamic_cast<ASTNodeList<ImportDeclaration>*>(buildAST(node->children[1]));
            compilerUnit->typeDecl = dynamic_cast<TypeDeclaration*>(buildAST(node->children[2]));
            return compilerUnit;
        }
        case PACKAGE_DECLARATION:
        {
            if (node->children.size() == 0)
            {
                return nullptr;
            }
            PackageDeclaration* packageDecl = new PackageDeclaration();
            packageDecl->name = dynamic_cast<Name*>(buildAST(node->children[1]));
            return packageDecl;
        }
        case IMPORT_DECLARATIONS_OPT:
        {
            ASTNodeList<ImportDeclaration>* imports;
            if (node->children.size() == 0)
            {
                imports = new ASTNodeList<ImportDeclaration>();
            }
            else 
            {
                imports = dynamic_cast<ASTNodeList<ImportDeclaration>*>(buildAST(node->children[0]));
            }

            ImportDeclaration* implicit = new ImportDeclaration();
            implicit->declareAll = true;

            SimpleName* java = new SimpleName();
            java->id = "java";
            QualifiedName* javalang = new QualifiedName();
            javalang->name = java;
            javalang->simpleName = new SimpleName();
            javalang->simpleName->id = "lang";

            QualifiedName* all = new QualifiedName();
            all->name = javalang;
            all->simpleName = new SimpleName();
            all->simpleName->id = "*";
            
            implicit->name = all;

            imports->elements.push_back(implicit);
            return imports;
        }
        case IMPORT_DECLARATIONS:
        {
            ASTNodeList<ImportDeclaration>* imports;
            if (node->children.size() == 1)
            {
                imports = new ASTNodeList<ImportDeclaration>();
                imports->elements.push_back(dynamic_cast<ImportDeclaration*>(buildAST(node->children[0])));
            }
            else
            {
                imports = dynamic_cast<ASTNodeList<ImportDeclaration>*>(buildAST(node->children[0]));
                imports->elements.push_back(dynamic_cast<ImportDeclaration*>(buildAST(node->children[1])));
            }
            return imports;
        }
        case TYPE_DECLARATIONS_OPT:
        {
            if (node->children.size() == 0)
            {
                return nullptr;
            }
            return buildAST(node->children[0]);
        }
        case IMPORT_DECLARATION:
        {
            ImportDeclaration* importDecl = new ImportDeclaration();
            importDecl->name = dynamic_cast<Name*>(buildAST(node->children[1]));

            if (node->children.size() == 5)
            {
                importDecl->declareAll = true;

                QualifiedName* newName = new QualifiedName();
                newName->simpleName = new SimpleName();
                newName->simpleName->id = "*";
                newName->name = importDecl->name;
                importDecl->name = newName;
            }
            else
            {
                importDecl->declareAll = false;
            }

            return importDecl;
        }
        case CLASS_OR_INTERFACE_DECLARATION:
        {
            TypeDeclaration* typeDecl = dynamic_cast<TypeDeclaration*>(buildAST(node->children[1]));
            typeDecl->modifiers = dynamic_cast<ASTNodeList<Modifier>*>(buildAST(node->children[0]));
            return typeDecl;
        }
        case CLASS_DECLARATION:
        {
            ClassDeclaration* classDecl = new ClassDeclaration();
            classDecl->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
            if (node->children[2]->symbol == EXTENDS)
            {
                classDecl->baseType = dynamic_cast<Type*>(buildAST(node->children[3]));
                if (node->children.size() == 7)
                {
                    classDecl->interfaces = dynamic_cast<ASTNodeList<Type>*>(buildAST(node->children[5]));
                    classDecl->classBody = dynamic_cast<ASTNodeList<MemberDeclaration>*>(buildAST(node->children[6]));
                }
                else
                {
                    classDecl->interfaces = new ASTNodeList<Type>();
                    classDecl->classBody = dynamic_cast<ASTNodeList<MemberDeclaration>*>(buildAST(node->children[4]));
                }
            }
            else if (node->children[2]->symbol == IMPLEMENTS)
            {
                classDecl->interfaces = dynamic_cast<ASTNodeList<Type>*>(buildAST(node->children[3]));
                classDecl->classBody = dynamic_cast<ASTNodeList<MemberDeclaration>*>(buildAST(node->children[4]));
            }
            else
            {
                classDecl->interfaces = new ASTNodeList<Type>();
                classDecl->classBody = dynamic_cast<ASTNodeList<MemberDeclaration>*>(buildAST(node->children[2]));
            }
            return classDecl;
        }
        case INTERFACE_DECLARATION:
        {
            InterfaceDeclaration* interfaceDecl = new InterfaceDeclaration();
            interfaceDecl->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
            if (node->children.size() == 5)
            {
                interfaceDecl->extends = dynamic_cast<ASTNodeList<Type>*>(buildAST(node->children[3]));
                interfaceDecl->interfaceBody = dynamic_cast<ASTNodeList<MemberDeclaration>*>(buildAST(node->children[4]));
            }
            else
            {
                interfaceDecl->extends = new ASTNodeList<Type>();
                interfaceDecl->interfaceBody = dynamic_cast<ASTNodeList<MemberDeclaration>*>(buildAST(node->children[2]));
            }
            return interfaceDecl;
        }
        case TYPE_LIST:
        {
            ASTNodeList<Type>* types;
            if (node->children.size() == 1)
            {
                types = new ASTNodeList<Type>();
                types->elements.push_back(dynamic_cast<Type*>(buildAST(node->children[0])));
            }
            else
            {
                types = dynamic_cast<ASTNodeList<Type>*>(buildAST(node->children[0]));
                types->elements.push_back(dynamic_cast<Type*>(buildAST(node->children[2])));
            }
            return types;
        }
        case CLASS_BODY:
        case INTERFACE_BODY:
        {
            if (node->children.size() == 2)
            {
                return new ASTNodeList<MemberDeclaration>();
            }
            return buildAST(node->children[1]);
        }
        case CLASS_BODY_DECLARATIONS:
        case INTERFACE_BODY_DECLARATIONS:
        {
            ASTNodeList<MemberDeclaration>* members;
            if (node->children.size() == 1)
            {
                members = new ASTNodeList<MemberDeclaration>();
                if (MemberDeclaration * member = dynamic_cast<MemberDeclaration*>(buildAST(node->children[0])))
                {
                    members->elements.push_back(member);
                }
            }
            else
            {
                members = dynamic_cast<ASTNodeList<MemberDeclaration>*>(buildAST(node->children[0]));
                if (MemberDeclaration * member = dynamic_cast<MemberDeclaration*>(buildAST(node->children[1])))
                {
                    members->elements.push_back(member);
                }
            }
            return members;
        }
        case CLASS_BODY_DECLARATION:
        case INTERFACE_BODY_DECLARATION:
        {
            if (node->children.size() == 2)
            {
                MemberDeclaration* memberDecl = dynamic_cast<MemberDeclaration*>(buildAST(node->children[1]));
                memberDecl->modifiers = dynamic_cast<ASTNodeList<Modifier>*>(buildAST(node->children[0]));
                return memberDecl;
            }
            return nullptr;
        }
        case MEMBER_DECLARATION:
        case INTERFACE_MEMBER_DECLARATION:
        {
            if (node->children[0]->symbol == ID)
            {
                return buildAST(node->children[1]);
            }
            else if (node->children[0]->symbol == VOID)
            {
                MethodDeclaration* methodDecl = dynamic_cast<MethodDeclaration*>(buildAST(node->children[2]));
                methodDecl->type = dynamic_cast<Type*>(buildAST(node->children[0]));
                methodDecl->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
                return methodDecl;
            }
            return buildAST(node->children[0]);
        }
        case METHOD_OR_FIELD_DECLARATION:
        case INTERFACE_METHOD_OR_FIELD_DECLARATION:
        {
            MemberDeclaration* memberDecl = dynamic_cast<MemberDeclaration*>(buildAST(node->children[2]));
            if (FieldDeclaration * field = dynamic_cast<FieldDeclaration*>(memberDecl))
            {
                field->declaration->type = dynamic_cast<Type*>(buildAST(node->children[0]));
                field->declaration->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
            }
            if (MethodDeclaration * method = dynamic_cast<MethodDeclaration*>(memberDecl))
            {
                method->type = dynamic_cast<Type*>(buildAST(node->children[0]));
                method->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
            }

            return memberDecl;
        }
        case METHOD_OR_FIELD_REST:
        {
            if (node->children[0]->symbol == VARIABLE_DECLARATOR_REST)
            {
                FieldDeclaration* field = new FieldDeclaration();
                field->declaration = dynamic_cast<VariableDeclarationExpression*>(buildAST(node->children[0]));
                return field;
            }
            return buildAST(node->children[0]);
        }
        case METHOD_DECLARATOR_REST:
        case INTERFACE_METHOD_DECLARATOR_REST:
        {
            MethodDeclaration* method = new MethodDeclaration();
            method->parameters = dynamic_cast<ASTNodeList<FormalParameter>*>(buildAST(node->children[0]));
            if (node->children[1]->symbol == METHOD_BODY)
            {
                method->body = dynamic_cast<Block*>(buildAST(node->children[1]));
            }
            return method;
        }
        case CONSTRUCTOR_DECLARATOR_REST:
        {
            ConstructorDeclaration* constructor = new ConstructorDeclaration();
            constructor->parameters = dynamic_cast<ASTNodeList<FormalParameter>*>(buildAST(node->children[0]));
            constructor->body = dynamic_cast<Block*>(buildAST(node->children[1]));
            return constructor;
        }
        case FORMAL_PARAMETERS:
        {
            return buildAST(node->children[1]);
        }
        case FORMAL_PARAMETERS_OPT:
        {
            if (node->children.size() == 0)
            {
                return new ASTNodeList<FormalParameter>();
            }
            return buildAST(node->children[0]);
        }
        case FORMAL_PARAMETER_LIST:
        {
            ASTNodeList<FormalParameter>* params;
            if (node->children.size() == 1)
            {
                params = new ASTNodeList<FormalParameter>();
                params->elements.push_back(dynamic_cast<FormalParameter*>(buildAST(node->children[0])));
            }
            else
            {
                params = dynamic_cast<ASTNodeList<FormalParameter>*>(buildAST(node->children[0]));
                params->elements.push_back(dynamic_cast<FormalParameter*>(buildAST(node->children[2])));
            }
            return params;
        }
        case FORMAL_PARAMETER:
        {
            FormalParameter* param = new FormalParameter();
            param->type = dynamic_cast<Type*>(buildAST(node->children[0]));
            param->id = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
            return param;
        }
        default:
        {
            if (node->children.size() > 0)
            {
                return buildAST(node->children[0]);
            }
        }
    }
    return nullptr;
}