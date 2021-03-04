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
        string baseClassName = baseClassType->name->getString();

        if (env.interfaces.find(baseClassName) != env.interfaces.cend())
        {
            cout << "Class cannot extend an interface" << endl;
            exit(42);
        }

        unordered_map<string, ClassDeclaration*>::const_iterator it = env.classes.find(baseClassName);
        if (it != env.classes.cend())
        {
            if (it->second->modifiers != nullptr)
            {
                for (const Modifier* mod : it->second->modifiers->elements)
                {
                    if (mod->type == Modifier::FINAL)
                    {
                        cout << "Cannot extend a final class" << endl;
                        exit(42);
                    }
                }
            }
        }
        else
        {
            cout << "Class extends something that is not a class" << endl;
            exit(42);
        }
    }

    if (classDecl->interfaces != nullptr)
    {
        unordered_set<string> implemented;

        for (const Type* type: classDecl->interfaces->elements)
        {
            const QualifiedType* interfaceType = dynamic_cast<const QualifiedType*>(type);
            assert(interfaceType != nullptr);
            string interfaceName = interfaceType->name->toString();

            if (env.classes.find(interfaceName) != env.classes.cend())
            {
                cout << "Class cannot implement a class" << endl;
                exit(42);
            }

            if (implemented.find(interfaceName) != implemented.cend())
            {
                cout << "Class cannot implement the same interface twice" << endl;
                exit(42);
            }

            implemented.insert(interfaceName);
        }
    }
}

void CheckInterface(const InterfaceDeclaration* const interfaceDecl, const Environment& env)
{

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