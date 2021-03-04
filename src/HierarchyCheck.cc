#include "HierarchyCheck.h"
#include <cassert>
#include <iostream>
#include <unordered_set>

using namespace std;

void CheckClass(const ClassDeclaration* const classDecl, const Environment& env)
{
    if (classDecl->baseType != nullptr)
    {
        QualifiedType* baseClassType = dynamic_cast<QualifiedType*>(classDecl->baseType);
        
        assert(baseClassType != nullptr);        
        assert(baseClassType->name->refers_to != nullptr);
        
        const ClassDeclaration* baseClass = dynamic_cast<const ClassDeclaration*>(baseClassType->name->refers_to);
        if (baseClass == nullptr)
        {
            cout << "Class can only extend a class" << endl;
            exit(42);
        }

        if (baseClass->modifiers != nullptr)
        {
            for (const Modifier* mod : baseClass->modifiers->elements)
            {
                if (mod->type == Modifier::FINAL)
                {
                    cout << "Cannot extend a final class" << endl;
                    exit(42);
                }
            }
        }
    }

    if (classDecl->interfaces != nullptr)
    {
        unordered_set<const InterfaceDeclaration*> implemented;

        for (const Type* type: classDecl->interfaces->elements)
        {
            const QualifiedType* implementsType = dynamic_cast<const QualifiedType*>(type);
            assert(implementsType != nullptr);
            assert(implementsType->name->refers_to != nullptr);
            
            const InterfaceDeclaration* interface = dynamic_cast<const InterfaceDeclaration*>(implementsType->name->refers_to);
            if (interface == nullptr)
            {
                cout << "Class cannot implement a class, must implement interface" << endl;
                exit(42);
            }

            if (implemented.find(interface) != implemented.cend())
            {
                cout << "Class cannot implement the same interface twice" << endl;
                exit(42);
            }

            implemented.insert(interface);
        }
    }
}

void CheckInterface(const InterfaceDeclaration* const interfaceDecl, const Environment& env)
{
    if (interfaceDecl->extends)
    {
        unordered_set<const InterfaceDeclaration*> implemented;
        for (const Type* type : interfaceDecl->extends->elements)
        {
            const QualifiedType* extendsType = dynamic_cast<const QualifiedType*>(type);
            assert(extendsType != nullptr);
            assert(extendsType->name->refers_to != nullptr);

            const InterfaceDeclaration* interface = dynamic_cast<const InterfaceDeclaration*>(extendsType->name->refers_to);
            if (interface == nullptr)
            {
                cout << "Interface cannot extend a class, must extend interface" << endl;
                exit(42);
            }

            if (implemented.find(interface) != implemented.cend())
            {
                cout << "Interface cannot extend the same interface twice" << endl;
                exit(42);
            }

            implemented.insert(interface);
        }
    }
}

void CheckEnvironmentHierarchy(const Environment& env)
{
    for (const pair<string, ClassDeclaration*>& entry : env.classes)
    {
        CheckClass(entry.second, env);
    }

    for (const pair<string, InterfaceDeclaration*>& entry : env.interfaces)
    {
        CheckInterface(entry.second, env);
    }
}