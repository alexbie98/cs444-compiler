#include "HierarchyCheck.h"
#include <cassert>
#include <iostream>
#include <unordered_set>

using namespace std;

void CheckCycles(const ClassDeclaration* const classDecl, unordered_set<const TypeDeclaration*> visited);
void CheckCycles(const InterfaceDeclaration* const classDecl, unordered_set<const TypeDeclaration*> visited);


void CheckCycles(const ClassDeclaration* const classDecl, unordered_set<const TypeDeclaration*> visited)
{
    if (visited.find(classDecl) != visited.cend())
    {
        cout << "Cannot have cycles in the type hierarchy" << endl;
        exit(42);
    }

    visited.insert(classDecl);
    if (classDecl->baseType != nullptr)
    {
        QualifiedType* baseClassType = dynamic_cast<QualifiedType*>(classDecl->baseType);
        const ClassDeclaration* baseClass = dynamic_cast<const ClassDeclaration*>(baseClassType->name->refers_to);
        CheckCycles(baseClass, visited);
    }

    if (classDecl->interfaces != nullptr)
    {
        for (const Type* type : classDecl->interfaces->elements)
        {
            const QualifiedType* implementsType = dynamic_cast<const QualifiedType*>(type);
            const InterfaceDeclaration* interfaceDecl = dynamic_cast<const InterfaceDeclaration*>(implementsType->name->refers_to);
            CheckCycles(interfaceDecl, visited);
        }
    }

    visited.erase(classDecl);
}

void CheckCycles(const InterfaceDeclaration* const interfaceDecl, unordered_set<const TypeDeclaration*> visited)
{
    if (visited.find(interfaceDecl) != visited.cend())
    {
        cout << "Cannot have cycles in the type hierarchy" << endl;
        exit(42);
    }

    visited.insert(interfaceDecl);
    if (interfaceDecl->extends != nullptr)
    {
        for (const Type* type : interfaceDecl->extends->elements)
        {
            const QualifiedType* extendsType = dynamic_cast<const QualifiedType*>(type);
            const InterfaceDeclaration* interfaceType = dynamic_cast<const InterfaceDeclaration*>(extendsType->name->refers_to);
            CheckCycles(interfaceType, visited);
        }
    }

    visited.erase(interfaceDecl);
}
bool modifiersContains(const vector<Modifier*>& modifiers, Modifier::ModifierType modType){
    bool containsModType = false;
    for (const Modifier* mod: modifiers){
        if (mod->type == modType){
            containsModType = true;
        }
    }
    return containsModType;
}

// typedef pair<string, ASTNodeList<Modifier> *> Signature;

// vector<Signature> getAndReplaceSignatures(const InterfaceDeclaration* const classDecl){
//     vector<Signature> signatures;

//     return signatures;
// }

// vector<Signature> getAndReplaceSignatures(const ClassDeclaration* const classDecl){

//     vector<Signature> signatures;

//     if (classDecl->baseType != nullptr)
//     {

//         QualifiedType* baseClassType = dynamic_cast<QualifiedType*>(classDecl->baseType);
//         assert(baseClassType != nullptr);        
//         assert(baseClassType->name->refers_to != nullptr);
//         const ClassDeclaration* baseClass = dynamic_cast<const ClassDeclaration*>(baseClassType->name->refers_to);

//         vector<Signature> inheritedSignatures = getAndReplaceSignatures(baseClass);

//     }

//     if (classDecl->interfaces!= nullptr){


//     }


//     for (const Type* type: classDecl->interfaces->elements)
//         {
//             const QualifiedType* implementsType = dynamic_cast<const QualifiedType*>(type);
//             assert(implementsType != nullptr);
//             assert(implementsType->name->refers_to != nullptr);

// }




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
            
            const InterfaceDeclaration* interfaceDecl = dynamic_cast<const InterfaceDeclaration*>(implementsType->name->refers_to);
            if (interfaceDecl == nullptr)
            {
                cout << "Class cannot implement a class, must implement interface" << endl;
                exit(42);
            }

            if (implemented.find(interfaceDecl) != implemented.cend())
            {
                cout << "Class cannot implement the same interface twice" << endl;
                exit(42);
            }

            implemented.insert(interfaceDecl);
        }
    }

    if (classDecl->classBody != nullptr)
    {
        unordered_set<string> constructors;
        for (const MemberDeclaration* member : classDecl->classBody->elements)
        {
            if (const ConstructorDeclaration * constructor = dynamic_cast<const ConstructorDeclaration*>(member))
            {
                if (constructors.find(constructor->getSignature()) != constructors.cend())
                {
                    cout << "Cannot define multiple constructors with the same signature" << endl;
                    exit(42);
                }
                constructors.insert(constructor->getSignature());
            }
        }
    }

    CheckCycles(classDecl, unordered_set<const TypeDeclaration*>());
    
    if (classDecl->classBody != nullptr){

        if (classDecl->modifiers != nullptr){

            if (!modifiersContains(classDecl->modifiers->elements, Modifier::ABSTRACT)){

                for (const MemberDeclaration* member: classDecl->classBody->elements){

                    if (modifiersContains(member->modifiers->elements, Modifier::ABSTRACT)){

                        cout << "non-abstract class contains abstract members" << endl;
                        exit(42);
                    }

                }
            }
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

            const InterfaceDeclaration* interfaceType = dynamic_cast<const InterfaceDeclaration*>(extendsType->name->refers_to);
            if (interfaceType == nullptr)
            {
                cout << "Interface cannot extend a class, must extend interface" << endl;
                exit(42);
            }

            if (implemented.find(interfaceType) != implemented.cend())
            {
                cout << "Interface cannot extend the same interface twice" << endl;
                exit(42);
            }

            implemented.insert(interfaceType);
        }
    }

    CheckCycles(interfaceDecl, unordered_set<const TypeDeclaration*>());
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


void printEnvironment(const Environment &env){
    cout << "classes " << env.classes.size() << " entries: " << endl;
    printASTNodeMap(env.classes);
    cout << "interfaces " << env.interfaces.size() << " entries: " << endl;
    printASTNodeMap(env.interfaces);
    cout << "methods " << env.methods.size() << " entries: " << endl;
    printASTNodeMap(env.methods);
    cout << "formal_params " << env.formal_params.size() << " entries: " << endl;
    printASTNodeMap(env.formal_params);
    cout << "variables " << env.variables.size() << " entries: " << endl;
    printASTNodeMap(env.variables);
}
