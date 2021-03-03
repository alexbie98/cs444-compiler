#include "NameResolution.h"
#include <iostream>
#include <assert.h>

using namespace std;

void EnvironmentVisitor::visit(ClassDeclaration& node) 
{
    assert(environments.size() == 1);

    const std::string& class_name = package + "." + node.name->getString();
    if(environments.top()->classes.find(class_name) != environments.top()->classes.end())
    {
        cout << "Redefinition of class " << class_name << endl;
        exit(42);
    }
    else
    {
        environments.top()->classes[class_name] = &node;
    }
    environments.push(&node.environment); 
}

void EnvironmentVisitor::visit(InterfaceDeclaration& node) 
{ 
    environments.top()->interfaces[node.name->getString()] = &node;
    environments.push(&node.environment); 
}

void EnvironmentVisitor::visit(MethodDeclaration& node) 
{
    environments.top()->methods[node.name->getString()] = &node;
    environments.push(&node.environment); 
}

void EnvironmentVisitor::visit(Block& node) 
{ 
    environments.push(&node.environment); 
}

void EnvironmentVisitor::visit(FormalParameter& node) 
{
    environments.top()->formal_params[node.id->getString()] = &node;
}

void EnvironmentVisitor::visit(VariableDeclarationExpression& node) 
{  
    const std::string& name = node.name->getString();
    if(environments.top()->classes.find(name) != environments.top()->classes.end())
    {
        cout << "Redefinition of local variable " << name << endl;
        exit(42);
    }
    else
    {
        environments.top()->variables[name] = &node;
    }
}

void EnvironmentVisitor::visit(FieldDeclaration& node) 
{  
    const std::string& name = node.declaration->name->id;
    if(environments.top()->classes.find(name) != environments.top()->classes.end())
    {
        cout << "Redefinition of field " << name << endl;
        exit(42);
    }
    else
    {
        environments.top()->fields[name] = &node;
    }
}

void EnvironmentVisitor::visit(CompilerUnit& node)
{
    if(node.packageDecl)
    {
        package = node.packageDecl->name->getString();
    }
    else // Reset package name if a package declaration DNE
    {
        package = UNNAMED_PACKAGE;
    }
}

void EnvironmentVisitor::leave(ClassDeclaration& node) { environments.pop(); }
void EnvironmentVisitor::leave(InterfaceDeclaration& node) { environments.pop(); }
void EnvironmentVisitor::leave(MethodDeclaration& node) { environments.pop(); }
void EnvironmentVisitor::leave(Block& node) { environments.pop(); }

Environment resolveNames(std::vector<ASTNode*> asts)
{
    EnvironmentVisitor visitor;
    for(ASTNode* ast: asts) ast->visitAll(visitor);
    return visitor.global;
}