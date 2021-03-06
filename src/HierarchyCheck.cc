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
    if (classDecl->extends != nullptr)
    {
        QualifiedType* baseClassType = dynamic_cast<QualifiedType*>(classDecl->extends);
        const ClassDeclaration* baseClass = dynamic_cast<const ClassDeclaration*>(baseClassType->name->refers_to);
        CheckCycles(baseClass, visited);
    }

    if (classDecl->implements != nullptr)
    {
        for (const Type* type : classDecl->implements->elements)
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

void addMethodDeclaration(unordered_map<string,MethodDeclaration*>&m, 
                          const string& signature, MethodDeclaration* method, bool addingCurrentClassDecls=false){

    if (m.find(signature) == m.end()){ // brand new signature -- add it
        m[signature] = method;
    }
    else{
        MethodDeclaration *existingMethod = m[signature];
        if (existingMethod->type->getTypeName() != method->type->getTypeName()){
            cout << "Cannot contain two methods with same signature but different return type" << endl;
            exit(42);
        }

        if(modifiersContains(existingMethod->modifiers->elements, Modifier::STATIC) &&
           !modifiersContains(method->modifiers->elements,  Modifier::STATIC)){
            cout << "Cannot override static method with non-static method" << endl;
            exit(42);
        }

        if(!modifiersContains(existingMethod->modifiers->elements, Modifier::STATIC) &&
           modifiersContains(method->modifiers->elements,  Modifier::STATIC)){
            cout << "Cannot override non-static method with static method" << endl;
            exit(42);
        }

        if(modifiersContains(existingMethod->modifiers->elements, Modifier::PROTECTED) &&
           modifiersContains(method->modifiers->elements,  Modifier::PUBLIC)){
            cout << "Cannot override protected method with public" << endl;
            exit(42);
        }
        if(modifiersContains(existingMethod->modifiers->elements, Modifier::FINAL)){
            cout << "Cannot override final method" << endl;
            exit(42);
        }

        if (addingCurrentClassDecls)
        {
            method->overriding = existingMethod;
        }
        else{
            cout << "WARN: interface overriding interface or base class overriding interface share methods, update pointer to latest" << endl;
        }
        m[signature] = method;
    }
}

void linkTypeMemberMethodsHierarchy(InterfaceDeclaration *interfaceDecl){

    if (interfaceDecl->containedMethods == nullptr){
        assert(interfaceDecl->interfaces != nullptr);

        interfaceDecl->containedMethods = make_unique<unordered_map<string, MethodDeclaration *>>();

        // 用recursion来把父母containedMethods建起来
        for (auto * e: *interfaceDecl->interfaces){
            linkTypeMemberMethodsHierarchy(e);
            for (const auto& it: *e->containedMethods){
                addMethodDeclaration(*interfaceDecl->containedMethods, it.first, it.second);
            }
        }
        // go through declared methods and try to add them
        for (auto* member: interfaceDecl->interfaceBody->elements){
            auto *method = dynamic_cast<MethodDeclaration *>(member);
            // TODO: add abstract, public modifiers to interface functions
            // method->modifiers->elements.push_back(
            //     new Modifier
            // );
            if (method)
            { // successful cast
                addMethodDeclaration(*interfaceDecl->containedMethods, method->getSignature(), method, true);
            }
        }
    }

}

void linkTypeMemberMethodsHierarchy(ClassDeclaration* classDecl)
{

    if (classDecl->containedMethods == nullptr){
        assert(classDecl->interfaces != nullptr);
        assert((classDecl->extends == nullptr && classDecl->baseClass == nullptr) || 
               (classDecl->extends != nullptr && classDecl->baseClass != nullptr)
        );

        classDecl->containedMethods = make_unique<unordered_map<string, MethodDeclaration *>>();

        // 用recursion来把父母containedMethods建起来
        for (auto * e: *classDecl->interfaces){
            linkTypeMemberMethodsHierarchy(e);
            for (const auto& it: *e->containedMethods){
                addMethodDeclaration(*classDecl->containedMethods, it.first, it.second);
            }
        }
        if (classDecl->baseClass){
            linkTypeMemberMethodsHierarchy(classDecl->baseClass);
            for (const auto& it: *classDecl->baseClass->containedMethods){
                addMethodDeclaration(*classDecl->containedMethods, it.first, it.second);
            }
        }

        // go through declared methods and try to add them
        for (auto* member: classDecl->classBody->elements){
            auto *method = dynamic_cast<MethodDeclaration *>(member);
            if (method){ // successful cast
                addMethodDeclaration(*classDecl->containedMethods, method->getSignature(), method, true);
            }
        }


        if (!modifiersContains(classDecl->modifiers->elements,Modifier::ABSTRACT)){
            for (const auto& it: *classDecl->containedMethods){
                if (modifiersContains(it.second->modifiers->elements, Modifier::ABSTRACT)){
                    cout << "non-abstract class contains (inherits or declares) abstract methods" << endl;
                    exit(42);
                }
            }
        }

    }
}

void linkNullExtendsToObject(ClassDeclaration* classDecl, const Environment& env){
    if (classDecl->extends == nullptr && classDecl->name->getString() != "Object"){
        // TODO: set the extends to QualifiedType* for OBJECT OR just straightup set baseClass
        // will need to refactor checks
    }
}

void linkTypeHierarchy(InterfaceDeclaration* interfaceDecl){

    if (interfaceDecl->interfaces == nullptr)
    {
        interfaceDecl->interfaces = make_unique<vector<InterfaceDeclaration *>>();
        assert(interfaceDecl->extends != nullptr);
        for (auto * e: interfaceDecl->extends->elements){
            interfaceDecl->interfaces->push_back(
                dynamic_cast<InterfaceDeclaration *>(dynamic_cast<QualifiedType *>(e)->name->refers_to)
            );
        }
        for (auto * e: *interfaceDecl->interfaces){
            linkTypeHierarchy(e);
        }
    }
}


void linkTypeHierarchy(ClassDeclaration* classDecl){

    if (classDecl->extends != nullptr && classDecl->baseClass == nullptr){
        classDecl->baseClass = dynamic_cast<ClassDeclaration*>(
            dynamic_cast<QualifiedType*>(classDecl->extends)->name->refers_to
        );
        linkTypeHierarchy(classDecl->baseClass);
    }

    if (classDecl->interfaces == nullptr){
        classDecl->interfaces = make_unique<vector<InterfaceDeclaration *>>();
        assert(classDecl->implements != nullptr);
        for (auto *e : classDecl->implements->elements)
        {
            classDecl->interfaces->push_back(
                dynamic_cast<InterfaceDeclaration *>(dynamic_cast<QualifiedType *>(e)->name->refers_to)
            );
        }
        for (auto * e: *classDecl->interfaces){
            linkTypeHierarchy(e);
        }
    }
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
    if (classDecl->extends != nullptr)
    {
        QualifiedType* baseClassType = dynamic_cast<QualifiedType*>(classDecl->extends);
        
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

    if (classDecl->implements != nullptr)
    {
        unordered_set<const InterfaceDeclaration*> implemented;

        for (const Type* type: classDecl->implements->elements)
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
    // check classes and add Object extentsion
    for (const pair<string, ClassDeclaration *> &entry : env.classes)
    {
        CheckClass(entry.second, env);
        linkNullExtendsToObject(entry.second, env);
    }
    for (const pair<string, InterfaceDeclaration*>& entry : env.interfaces)
    {
        CheckInterface(entry.second, env);
    }

    // link type hierarchy
    for (const pair<string, ClassDeclaration*>& entry : env.classes)
    {
        linkTypeHierarchy(entry.second);
    }

    for (const pair<string, InterfaceDeclaration*>& entry : env.interfaces)
    {
        linkTypeHierarchy(entry.second);
    }

    // link methods
    for (const pair<string, ClassDeclaration*>& entry : env.classes)
    {
        linkTypeMemberMethodsHierarchy(entry.second);
    }

    for (const pair<string, InterfaceDeclaration*>& entry : env.interfaces)
    {
        linkTypeMemberMethodsHierarchy(entry.second);
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
