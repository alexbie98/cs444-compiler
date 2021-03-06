#include "HierarchyCheck.h"
#include <cassert>
#include <iostream>
#include <unordered_set>

using namespace std;

Environment *env_ptr;
ASTNodeList<MethodDeclaration> *objectMethodStubs;


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
    if (classDecl->baseClass != nullptr)
    {
        CheckCycles(classDecl->baseClass, visited);
    }

    if (classDecl->interfaces != nullptr)
    {
        for (const InterfaceDeclaration* interface : *classDecl->interfaces)
        {
            CheckCycles(interface, visited);
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
    if (interfaceDecl->interfaces != nullptr)
    {
        for (const InterfaceDeclaration* interface : *interfaceDecl->interfaces)
        {
            CheckCycles(interface, visited);
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

void modifiersAdd(vector<Modifier*>& modifiers, Modifier::ModifierType modType){
    if (modifiersContains(modifiers,modType)){
        return;
    }
    Modifier * m = new Modifier();
    m->type = modType;
    modifiers.push_back(m);
}

void addMethodDeclaration(unordered_map<string,MethodDeclaration*>&m, 
                          const string& signature, MethodDeclaration* method, bool addingCurrentClassDecls=false){

    if (m.find(signature) == m.end())
    { // brand new signature -- add it
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

        if(modifiersContains(existingMethod->modifiers->elements, Modifier::PUBLIC) &&
           modifiersContains(method->modifiers->elements,  Modifier::PROTECTED)){
            cout << "Cannot override public method with protected" << endl;
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

ASTNodeList<MethodDeclaration> * createObjectMethodStubs(){

    auto * stubs = new ASTNodeList<MethodDeclaration>();
    ClassDeclaration *objectDecl = env_ptr->classes["java.lang.Object"];
    for (auto & it : *objectDecl->containedMethods){
        // TODO clean this up
        MethodDeclaration* m = it.second;
        MethodDeclaration *copy = new MethodDeclaration();
        copy->type = m->type;
        copy->name = m->name;
        copy->parameters = m->parameters;


        copy->modifiers = new ASTNodeList<Modifier>();
        // copy->modifiers->elements.insert(copy->modifiers->elements.end(), 
        //                                  m->modifiers->elements.begin(),
        //                                  m->modifiers->elements.end());
        modifiersAdd(copy->modifiers->elements, Modifier::ABSTRACT);
        modifiersAdd(copy->modifiers->elements, Modifier::PUBLIC);

        stubs->elements.push_back(copy);
    }
    return stubs;
}

void linkTypeMemberMethodsHierarchy(ClassDeclaration *classDecl);

void linkTypeMemberMethodsHierarchy(InterfaceDeclaration *interfaceDecl)
{
    if (interfaceDecl->containedMethods == nullptr){
        assert(interfaceDecl->interfaces != nullptr);

        interfaceDecl->containedMethods = make_unique<unordered_map<string, MethodDeclaration *>>();

        // if (objectMethodStubs == nullptr){
        //     ClassDeclaration * objectDecl = env_ptr->classes["java.lang.Object"];
        //     if (objectDecl->containedMethods == nullptr){
        //         linkTypeMemberMethodsHierarchy(objectDecl);
        //     }
        //     objectMethodStubs = createObjectMethodStubs();
        // }

        if (interfaceDecl->interfaces->size() == 0){
            // for (auto *e : objectMethodStubs->elements)
            // {
            //     addMethodDeclaration(*interfaceDecl->containedMethods, e->getSignature(), e);
            // }
        }
        else {
        // 用recursion来把父母containedMethods建起来
            for (auto * e: *interfaceDecl->interfaces){
                linkTypeMemberMethodsHierarchy(e);
                for (const auto& it: *e->containedMethods){
                    addMethodDeclaration(*interfaceDecl->containedMethods, it.first, it.second);
                }
            }

        }
        // go through declared methods and try to add them
        unordered_set<string> signatures;
        for (auto* member: interfaceDecl->interfaceBody->elements){
            auto *method = dynamic_cast<MethodDeclaration *>(member);
            if (method)
            { // successful cast
                modifiersAdd(method->modifiers->elements, Modifier::ABSTRACT);
                modifiersAdd(method->modifiers->elements, Modifier::PUBLIC);
                addMethodDeclaration(*interfaceDecl->containedMethods, method->getSignature(), method, true);
                if (signatures.find(method->getSignature())!=signatures.end()){
                    cout << "Cannot declare same signature twice in interface" << endl;
                    exit(42);
                }
                signatures.insert(method->getSignature());
            }
        }

    }

    // cout << interfaceDecl->name->getString() << endl;
    // for (const auto &it : *interfaceDecl->containedMethods)
    // {
    //     cout << it.first << endl;
    // }
}

void linkTypeMemberMethodsHierarchy(ClassDeclaration* classDecl)
{

    if (classDecl->containedMethods == nullptr){
        assert(classDecl->interfaces != nullptr);
        assert(classDecl->baseClass != nullptr || classDecl->name->getString() == "Object");

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
        unordered_set<string> signatures;
        for (auto* member: classDecl->classBody->elements){
            auto *method = dynamic_cast<MethodDeclaration *>(member);
            if (method){ // successful cast
                addMethodDeclaration(*classDecl->containedMethods, method->getSignature(), method, true);
                if (signatures.find(method->getSignature())!=signatures.end()){
                    cout << "Cannot declare same signature twice in class" << endl;
                    exit(42);
                }
                signatures.insert(method->getSignature());
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
        // cout << classDecl->name->getString() << endl;
        // for (const auto &it : *classDecl->containedMethods)
        // {
        //     cout << it.first << endl;
        // }
    }
}

void linkNullExtendsToObject(ClassDeclaration* classDecl, Environment& env){
    if (classDecl->extends == nullptr && classDecl->name->getString() != "Object")
    {
        classDecl->baseClass = env.classes["java.lang.Object"];
    }
}

void linkTypeHierarchy(InterfaceDeclaration* interfaceDecl){

    if (interfaceDecl->interfaces == nullptr)
    {
        interfaceDecl->interfaces = make_unique<vector<InterfaceDeclaration *>>();
        assert(interfaceDecl->extends != nullptr);
        for (auto * e: interfaceDecl->extends->elements){

            InterfaceDeclaration *interface = dynamic_cast<InterfaceDeclaration *>(dynamic_cast<QualifiedType *>(e)->name->refers_to);
            if (interface == nullptr)
            {
                cout << "Interface can only implement an interface" << endl;
                exit(42);
            }
            interfaceDecl->interfaces->push_back(interface);
        }
        for (auto * e: *interfaceDecl->interfaces){
            linkTypeHierarchy(e);
        }
    }
}


void linkTypeHierarchy(ClassDeclaration* classDecl){

    if (classDecl->name->getString()!="Object" && classDecl->baseClass == nullptr){
        classDecl->baseClass = dynamic_cast<ClassDeclaration*>(
            dynamic_cast<QualifiedType*>(classDecl->extends)->name->refers_to
        );
        if (classDecl->baseClass == nullptr){
            cout << "Class can only extend a class" << endl;
            exit(42);
        }
        linkTypeHierarchy(classDecl->baseClass);
    }

    if (classDecl->interfaces == nullptr){
        classDecl->interfaces = make_unique<vector<InterfaceDeclaration *>>();
        assert(classDecl->implements != nullptr);
        for (auto *e : classDecl->implements->elements)
        {
            InterfaceDeclaration *interface = dynamic_cast<InterfaceDeclaration *>(dynamic_cast<QualifiedType *>(e)->name->refers_to);
            if (interface == nullptr)
            {
                cout << "Class can only implement an interface" << endl;
                exit(42);
            }
            classDecl->interfaces->push_back(interface);
        }
        for (auto * e: *classDecl->interfaces){
            linkTypeHierarchy(e);
        }
    }
}


void CheckClass(const ClassDeclaration* const classDecl, Environment& env)
{
    if (classDecl->baseClass != nullptr)
    {
        if (classDecl->baseClass->modifiers != nullptr && 
            modifiersContains(classDecl->baseClass->modifiers->elements, Modifier::FINAL)){

            cout << "Cannot extend a final class" << endl;
            exit(42);
        }
    }

    if (classDecl->interfaces != nullptr)
    {
        unordered_set<const InterfaceDeclaration*> implemented;

        for (const InterfaceDeclaration* interface: *classDecl->interfaces)
        {
            if (implemented.find(interface) != implemented.cend())
            {
                cout << "Class cannot implement the same interface twice" << endl;
                exit(42);
            }

            implemented.insert(interface);
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

void CheckInterface(const InterfaceDeclaration* const interfaceDecl, Environment& env)
{
    if (interfaceDecl->interfaces)
    {
        unordered_set<const InterfaceDeclaration*> implemented;
        for (const InterfaceDeclaration * interface : *interfaceDecl->interfaces)
        {
            if (implemented.find(interface) != implemented.cend())
            {
                cout << "Interface cannot extend the same interface twice" << endl;
                exit(42);
            }

            implemented.insert(interface);
        }
    }

    CheckCycles(interfaceDecl, unordered_set<const TypeDeclaration*>());
}


void CheckEnvironmentHierarchy(Environment& env)
{
    env_ptr = &env;
    // add implicit object extends
    for (const pair<string, ClassDeclaration*>& entry : env.classes){
        linkNullExtendsToObject(entry.second, env);
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

    // check classes
    for (const pair<string, ClassDeclaration *> &entry : env.classes)
    {
        CheckClass(entry.second, env);
    }
    
    for (const pair<string, InterfaceDeclaration*>& entry : env.interfaces)
    {
        CheckInterface(entry.second, env);
    }
    delete objectMethodStubs;

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
