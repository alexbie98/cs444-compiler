#include "ASTBuilder.h"
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <set>

void ParentVisitor::visit(ASTNode& node)
{
    // std::cout << node.toString() << std::endl;
    node.parent = parents.top();
    
    if (parents.top() == &node)
    {
        std::cout << "WTF" << std::endl;
    }
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


void PrintVisitor::visit(ASTNode& node)
{
    std::cout << std::string(spaces * 2, ' ');
    std::cout << node.toString() << ' ' << &node << std::endl;
    spaces++;
}

void PrintVisitor::leave(ASTNode& node)
{
    spaces--;
}

void printAST(ASTNode* ast)
{
    PrintVisitor printer;
    ast->visitAll(printer);
}

void removeDuplicateImports(std::vector<ASTNode*> asts)
{
    for (ASTNode *ast : asts)
    {
        std::set<std::string> found_imports;

        ASTNodeList<ImportDeclaration> *imports = dynamic_cast<CompilerUnit *>(ast)->importDecls;
        std::vector<ImportDeclaration*> new_imports;
        const CompilerUnit *cunit = dynamic_cast<const CompilerUnit *>(ast);

        if (imports)
        {
            for (ImportDeclaration *import : imports->elements)
            {
                if (found_imports.find(import->name->getString()) == found_imports.end())
                {
                    new_imports.push_back(import);
                    found_imports.insert(import->name->getString());
                }
                else
                {
                    delete import;
                }
            }
        }

        imports->elements = new_imports;
    }
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
        case THIS:
        {
            ThisExpression* expr = new ThisExpression();
            expr->expression = nullptr;
            return expr;
        }
        case QUALIFIED_NAME:
        {
            QualifiedName* qualifiedName = new QualifiedName();
            qualifiedName->name = dynamic_cast<Name*>(buildAST(node->children[0]));
            qualifiedName->simpleName = dynamic_cast<SimpleName*>(buildAST(node->children[2]));
            return qualifiedName;
        }
        case NAMED_TYPE:
        {
            QualifiedType* qualType = new QualifiedType();
            qualType->name = dynamic_cast<Name*>(buildAST(node->children[0]));
            return qualType;
        }
        case ARRAY_TYPE:
        {
            ArrayType* arrayType = new ArrayType();
            arrayType->elementType = dynamic_cast<Type*>(buildAST(node->children[0]));
            return arrayType;
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
            // Always define a PackageDeclaration node.
            // Make it UNNAMED package if a package declaration does not exist.
            PackageDeclaration* packageDecl = new PackageDeclaration();
            if (node->children.size() == 0)
            {
                SimpleName* unnamed = new SimpleName();
                unnamed->id = UNNAMED_PACKAGE;
                packageDecl->name = unnamed;
            }
            else
            {
                packageDecl->name = dynamic_cast<Name*>(buildAST(node->children[1]));
            }
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

            // Hacky way to add java.lang.* that every file implicit imports
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
        case TYPE_DECLARATION_OPT:
        {
            if (node->children.size() == 0)
            {
                return nullptr;
            }
            return buildAST(node->children[0]);
        }
        case TYPE_DECLARATION:
        {
            if (node->children.size() == 2)
            {
                TypeDeclaration* typeDecl = dynamic_cast<TypeDeclaration*>(buildAST(node->children[1]));
                typeDecl->modifiers = dynamic_cast<ASTNodeList<Modifier>*>(buildAST(node->children[0]));
                return typeDecl;
            }
            return nullptr;
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
        case CLASS_DECLARATION:
        {
            ClassDeclaration* classDecl = new ClassDeclaration();
            classDecl->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
            classDecl->extends = dynamic_cast<Type*>(buildAST(node->children[2]));
            classDecl->implements = dynamic_cast<ASTNodeList<Type>*>(buildAST(node->children[3]));
            classDecl->classBody = dynamic_cast<ASTNodeList<MemberDeclaration>*>(buildAST(node->children[4]));

            return classDecl;
        }
        case INTERFACE_DECLARATION:
        {
            InterfaceDeclaration* interfaceDecl = new InterfaceDeclaration();
            interfaceDecl->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
            interfaceDecl->extends = dynamic_cast<ASTNodeList<Type>*>(buildAST(node->children[2]));
            interfaceDecl->interfaceBody = dynamic_cast<ASTNodeList<MemberDeclaration>*>(buildAST(node->children[3]));

            return interfaceDecl;
        }
        case EXTENDS_OPT:
        {
            if (node->children.size() == 0)
            {
                return nullptr;
            }
            return buildAST(node->children[1]);
        }
        case INTERFACES_OPT:
        case INTERFACE_EXTENDS_OPT:
        {
            if (node->children.size() == 0)
            {
                return new ASTNodeList<Type>();
            }
            return buildAST(node->children[1]);
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
        case FIELD_DECLARATION:
        {
            FieldDeclaration* field = new FieldDeclaration();
            field->declaration = new VariableDeclarationExpression();
            field->declaration->type = dynamic_cast<Type*>(buildAST(node->children[0]));
            field->declaration->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
            if (node->children[2]->symbol == ASSIGN)
            {
                field->declaration->initializer = dynamic_cast<Expression*>(buildAST(node->children[3]));
            }
            return field;
        }
        case METHOD_DECLARATION:
        {
            MethodDeclaration* methodDecl = dynamic_cast<MethodDeclaration*>(buildAST(node->children[0]));
            if (node->children[1]->symbol == BLOCK)
            {
                methodDecl->body = dynamic_cast<Block*>(buildAST(node->children[1]));
            }
            return methodDecl;
        }
        case METHOD_SIGNATURE:
        {
            MethodDeclaration* methodDecl = new MethodDeclaration();
            methodDecl->type = dynamic_cast<Type*>(buildAST(node->children[0]));
            methodDecl->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
            methodDecl->parameters = dynamic_cast<ASTNodeList<FormalParameter>*>(buildAST(node->children[2]));
            return methodDecl;
        }
        case CONSTRUCTOR_DECLARATION:
        {
            ConstructorDeclaration* constructor = new ConstructorDeclaration();
            constructor->parameters = dynamic_cast<ASTNodeList<FormalParameter>*>(buildAST(node->children[1]));
            constructor->body = dynamic_cast<Block*>(buildAST(node->children[2]));
            
            if (SimpleName * name = dynamic_cast<SimpleName*>(buildAST(node->children[0])))
            {
                constructor->id = name->id;
                delete name;
            }

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
        case BLOCK:
        {
            Block* block = new Block();
            block->statements = dynamic_cast<ASTNodeList<Statement>*>(buildAST(node->children[1]));

            // Create explicit scopes (blocks) for each VariableDeclarationExpression
            std::vector<Statement*> original_statements = block->statements->elements;
            Block* current_block = block;
            block->statements->elements.clear();

            // Skip the first statement in the block if its already a VariableDeclarationExpression
            if(original_statements.size() > 0 && 
               dynamic_cast<ExpressionStatement*>(original_statements[0]) &&
               dynamic_cast<VariableDeclarationExpression*>(dynamic_cast<ExpressionStatement*>(original_statements[0])->expression))
               {
                   current_block->statements->elements.push_back(original_statements[0]);
                   original_statements.erase(original_statements.begin());
               }

            for(Statement* statement: original_statements)
            {
                ExpressionStatement* exp_statement = dynamic_cast<ExpressionStatement*>(statement);
                if(exp_statement)
                {
                    VariableDeclarationExpression* var_exp = dynamic_cast<VariableDeclarationExpression*>(exp_statement);
                    if(var_exp)
                    {
                        // Create a new block with the variable declaration at the start and add it to the current blocks statements
                        Block* new_block = new Block();
                        ExpressionStatement* var_statement = new ExpressionStatement();
                        var_statement->expression = var_exp;
                        new_block->statements->elements.push_back(var_statement);
                        current_block->statements->elements.push_back(new_block);

                        // Set the current block to the new block to continue inserting statements into the deepest block
                        current_block = new_block;

                        continue;
                    }
                }
                current_block->statements->elements.push_back(statement);
            }

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
                statements->elements.push_back(dynamic_cast<Statement*>(buildAST(node->children[0])));
            }
            else
            {
                statements = dynamic_cast<ASTNodeList<Statement>*>(buildAST(node->children[0]));
                statements->elements.push_back(dynamic_cast<Statement*>(buildAST(node->children[1])));
            }
            return statements;
        }
        case LOCAL_VARIABLE_DECLARATION_STATEMENT:
        {
            ExpressionStatement* expression = new ExpressionStatement();
            expression->expression = dynamic_cast<VariableDeclarationExpression*>(buildAST(node->children[0]));

            return expression;
        }
        case LOCAL_VARIABLE_DECLARATION:
        {            
            VariableDeclarationExpression* varDecl = new VariableDeclarationExpression();
            varDecl->type = dynamic_cast<Type*>(buildAST(node->children[0]));
            varDecl->name = dynamic_cast<SimpleName*>(buildAST(node->children[1]));
            varDecl->initializer = dynamic_cast<Expression*>(buildAST(node->children[3]));
            return varDecl;
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
            case SEMICOLON: return new EmptyStatement();
            case STATEMENT_EXPRESSION:
            {
                ExpressionStatement* exprStatement = new ExpressionStatement();
                exprStatement->expression = dynamic_cast<Expression*>(buildAST(node->children[0]));
                return exprStatement;
            }
            }
            return new EmptyStatement();
        }
        case PAR_EXPRESSION:
        {
            return buildAST(node->children[1]);
        }
        case PRIMARY_NO_NEW_ARRAY:
        {
            if (node->children.size() == 3)
            {
                return buildAST(node->children[1]);
            }
            return buildAST(node->children[0]);
        }
        case CLASS_INSTANCE_CREATION_EXPRESSION:
        {
            ClassInstanceCreator* classCreator = dynamic_cast<ClassInstanceCreator*>(buildAST(node->children[2]));
            classCreator->type = dynamic_cast<QualifiedType*>(buildAST(node->children[1]));
            return classCreator;
        }
        case ARRAY_CREATION_EXPRESSION:
        {
            ArrayCreator* arrayCreator = dynamic_cast<ArrayCreator*>(buildAST(node->children[2]));
            arrayCreator->type = new ArrayType();
            arrayCreator->type->elementType = dynamic_cast<Type*>(buildAST(node->children[1]));
            return arrayCreator;
        }
        case ARRAY_CREATOR_REST:
        {
            ArrayCreator* arrayCreator = new ArrayCreator();
            arrayCreator->argument = dynamic_cast<Expression*>(buildAST(node->children[1]));
            return arrayCreator;
        }
        case CLASS_CREATOR_REST:
        {
            ClassInstanceCreator* classCreator = new ClassInstanceCreator();
            classCreator->arguments = dynamic_cast<ASTNodeList<Expression>*>(buildAST(node->children[0]));
            return classCreator;
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
        case FIELD_ACCESS:
        {
            FieldAccess* fieldAccess = new FieldAccess();
            fieldAccess->prevExpr = dynamic_cast<Expression*>(buildAST(node->children[0]));
            fieldAccess->name = dynamic_cast<SimpleName*>(buildAST(node->children[2]));
            return fieldAccess;
        }
        case METHOD_CALL:
        {
            MethodCall* methodCall = new MethodCall();

            if (node->children.size() == 2)
            {
                Name* name = dynamic_cast<Name*>(buildAST(node->children[0]));
                if (SimpleName * simple = dynamic_cast<SimpleName*>(name))
                {
                    methodCall->name = simple;
                }
                else if (QualifiedName * qualified = dynamic_cast<QualifiedName*>(name))
                {
                    methodCall->name = qualified->simpleName;
                    NameExpression* nameExpr = new NameExpression();
                    nameExpr->name = qualified->name;
                    methodCall->prevExpr = nameExpr;

                    qualified->name = nullptr;
                    qualified->simpleName = nullptr;
                    delete qualified;
                }
                methodCall->arguments = dynamic_cast<ASTNodeList<Expression>*>(buildAST(node->children[1]));
            }
            else
            {
                methodCall->prevExpr = dynamic_cast<Expression*>(buildAST(node->children[0]));
                methodCall->name = dynamic_cast<SimpleName*>(buildAST(node->children[2]));
                methodCall->arguments = dynamic_cast<ASTNodeList<Expression>*>(buildAST(node->children[3]));
            }

            return methodCall;
        }
        case ARRAY_ACCESS:
        {
            ArrayAccess* arrayAccess = new ArrayAccess();
            
            if (node->children[0]->symbol == NAME)
            {
                NameExpression* nameExpr = new NameExpression();
                nameExpr->name = dynamic_cast<Name*>(buildAST(node->children[0]));
                arrayAccess->prevExpr = nameExpr;
            }
            else
            {
                arrayAccess->prevExpr = dynamic_cast<Expression*>(buildAST(node->children[0]));
            }
            arrayAccess->indexExpr = dynamic_cast<Expression*>(buildAST(node->children[2]));

            return arrayAccess;
        }
        case UNARY_EXPRESSION:
        case UNARY_NOT_MINUS:
        {
            if (node->children.size() == 2)
            {
                PrefixOperation* prefix = new PrefixOperation();
                switch (node->children[0]->symbol)
                {
                case MINUS: prefix->op = PrefixOperation::MINUS;
                case NOT:   prefix->op = PrefixOperation::NOT;
                }
                prefix->operand = dynamic_cast<Expression*>(buildAST(node->children[1]));
                return prefix;
            }
            else if (node->children[0]->symbol == NAME)
            {
                NameExpression* nameExpr = new NameExpression();
                nameExpr->name = dynamic_cast<Name*>(buildAST(node->children[0]));
                return nameExpr;
            }
            return buildAST(node->children[0]);
        }
        case CAST_EXPRESSION:
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
                if (NameExpression * nameExpr = dynamic_cast<NameExpression*>(buildAST(node->children[1])))
                {
                    qualType->name = nameExpr->name;
                    nameExpr->name = nullptr;
                    delete nameExpr;
                }

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
        case MULTIPLICATIVE_EXPRESSION:
        case ADDITIVE_EXPRESSION:
        case RELATIONAL_EXPRESSION:
        case EQUALITY_EXPRESSION:
        case AND_EXPRESSION:
        case XOR_EXPRESSION:
        case OR_EXPRESSION:
        case EAGER_AND_EXPRESSION:
        case EAGER_OR_EXPRESSION:
        {
            if (node->children.size() == 3)
            {
                if (node->children[1]->symbol == INSTANCEOF)
                {
                    InstanceOfExpression* instance = new InstanceOfExpression();
                    instance->expression = dynamic_cast<Expression*>(buildAST(node->children[0]));
                    instance->type = dynamic_cast<Type*>(buildAST(node->children[2]));
                    return instance;
                }

                BinaryOperation* binaryOp = new BinaryOperation();
                binaryOp->lhs = dynamic_cast<Expression*>(buildAST(node->children[0]));
                binaryOp->rhs = dynamic_cast<Expression*>(buildAST(node->children[2]));

                switch (node->children[1]->symbol)
                {
                case EAGER_OR:  binaryOp->op = BinaryOperation::EAGER_OR; break;
                case EAGER_AND: binaryOp->op = BinaryOperation::EAGER_AND; break;
                case OR:        binaryOp->op = BinaryOperation::OR; break;
                case AND:       binaryOp->op = BinaryOperation::AND; break;
                case XOR:       binaryOp->op = BinaryOperation::XOR; break;
                case EQ:        binaryOp->op = BinaryOperation::EQ; break;
                case NEQ:       binaryOp->op = BinaryOperation::NEQ; break;
                case LEQ:       binaryOp->op = BinaryOperation::LEQ; break;
                case GEQ:       binaryOp->op = BinaryOperation::GEQ; break;
                case GT:        binaryOp->op = BinaryOperation::GT; break;
                case LT:        binaryOp->op = BinaryOperation::LT; break;
                case PLUS:      binaryOp->op = BinaryOperation::PLUS; break;
                case MINUS:     binaryOp->op = BinaryOperation::MINUS; break;
                case MULT:      binaryOp->op = BinaryOperation::TIMES; break;
                case DIV:       binaryOp->op = BinaryOperation::DIVIDE; break;
                case REMAINDER: binaryOp->op = BinaryOperation::REMAINDER; break;
                }

                return binaryOp;
            }
            return buildAST(node->children[0]);
        }
        case ASSIGNMENT:
        {
            AssignmentExpression* assignExpr = new AssignmentExpression();
            if (node->children[0]->symbol == NAME)
            {
                NameExpression* nameExpr = new NameExpression();
                nameExpr->name = dynamic_cast<Name*>(buildAST(node->children[0]));
                assignExpr->lhs = nameExpr;
            }
            else
            {
                assignExpr->lhs = dynamic_cast<Expression*>(buildAST(node->children[0]));
            }

            assignExpr->rhs = dynamic_cast<Expression*>(buildAST(node->children[2]));
            return assignExpr;
        }
        default:
        {
            if (node->children.size() > 0)
            {
                return buildAST(node->children[0]);
            }
            return nullptr;
        }
    }
}