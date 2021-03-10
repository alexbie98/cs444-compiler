#include "HierarchyCheck.h"
#include <cassert>
#include <iostream>
#include <unordered_set>

using namespace std;

Environment *env_ptr;

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

ASTNodeList<MethodDeclaration> * createObjectMethodStubs(){

    auto * stubs = new ASTNodeList<MethodDeclaration>();
    ClassDeclaration *objectDecl = env_ptr->classes["java.lang.Object"];
    for (auto & it : *objectDecl->containedConcreteMethods){
        MethodDeclaration* m = it.second;
        if (modifiersContains(m->modifiers->elements, Modifier::PUBLIC)){
            MethodDeclaration *copy = new MethodDeclaration();
            copy->type = m->type;
            copy->name = m->name;
            copy->parameters = m->parameters;
            copy->modifiers = new ASTNodeList<Modifier>();
            modifiersAdd(copy->modifiers->elements, Modifier::ABSTRACT);
            modifiersAdd(copy->modifiers->elements, Modifier::PUBLIC);
            stubs->elements.push_back(copy);
        }
    }
    return stubs;
}


unordered_map<string, vector<MethodDeclaration *>> merge(
    vector<unordered_map<string, vector<MethodDeclaration *>> *>& abstractMethodSets)
{
    unordered_map<string, vector<MethodDeclaration *>> abstractMethods;
    for (auto *s : abstractMethodSets)
    {
        for (const auto& [sig, ms]: *s){
            abstractMethods[sig].insert(abstractMethods[sig].end(), (*s)[sig].begin(), (*s)[sig].end());
        }
    }
    return abstractMethods;
}



unordered_map<string, vector<MethodDeclaration *>> merge(
    unordered_map<string, vector<MethodDeclaration *>>& abstractMethods,
    const unordered_map<string, MethodDeclaration *>& concreteMethods)
{
    unordered_map<string, vector<MethodDeclaration *>> methods;
    for (const auto &[sig, ms] : abstractMethods)
    {
        methods[sig].insert(methods[sig].end(), abstractMethods[sig].begin(), abstractMethods[sig].end());
    }
    for (const auto& [sig, m]: concreteMethods){
        methods[sig].push_back(m);
    }

    return methods;
}
void split(
    unordered_map<string, vector<MethodDeclaration *>>& abstractMethods,
    unordered_map<string, MethodDeclaration *>& concreteMethods,
    const unordered_map<string, vector<MethodDeclaration *>>& methods)
{
    for (const auto &[sig, ms] : methods)
    {
        for (MethodDeclaration * m: ms){
            if (modifiersContains(m->modifiers->elements, Modifier::ABSTRACT)){
                abstractMethods[sig].push_back(m);
            }
            else{
                assert(concreteMethods.find(sig) == concreteMethods.end());
                concreteMethods[sig] = m;
            }
        }
    }
}

unordered_map<string, vector<MethodDeclaration *>> replace(
    unordered_map<MethodDeclaration *, vector<MethodDeclaration *>>& replace,
    const unordered_map<string, MethodDeclaration *>& declaredMethods,
    unordered_map<string, vector<MethodDeclaration *>>& superMethods, string print)
{
    unordered_map<string, vector<MethodDeclaration *>> containedMethods;

    // cout << print << endl;
    // cout << "--------------" << endl;
    // for (const auto &[sig, m] : declaredMethods)
    // {
    //     cout << sig << endl;
    // }
    // cout << "--------------" << endl;
    // for (const auto &[sig, ms] : superMethods)
    // {
    //     cout << sig << " ";
    //     cout << ms.size() << endl;
    // }
    // cout << "--------------" << endl;

    for (const auto& [sig, m]: declaredMethods){
        if (superMethods.find(sig) != superMethods.end()){
            replace[m] = superMethods[sig];
        }
        containedMethods[sig].push_back(m);
    }

    for (const auto& [sig, ms]: superMethods){
        if (declaredMethods.find(sig) == declaredMethods.end()){
            bool allAbs = all_of(ms.begin(), ms.end(),
                                 [](MethodDeclaration *m) {
                                     return modifiersContains(m->modifiers->elements, Modifier::ABSTRACT);
                                 });
            if (allAbs){
                containedMethods[sig] = ms;
            }
            else{
                size_t count = 0;
                MethodDeclaration *concrete;
                for (auto *m : ms){
                    if(!modifiersContains(m->modifiers->elements, Modifier::ABSTRACT)){
                        count++;
                        concrete = m;
                    }
                }
                assert(count == 1);

                for (auto *m : ms){
                    if (m != concrete){
                        replace[concrete].push_back(m);
                    }
                }
                containedMethods[sig].push_back(concrete);
            }
        }
    }
    // for (const auto &[sig, ms] : containedMethods)
    // {
    //     cout << sig <<  " ";
    //     for (auto mod: ms[0]->modifiers->elements){
    //         cout << mod->type << " ";
    //     }
    //     cout << ms.size() << endl;
    // }
    return containedMethods;
}

void checkContainedMethods(
    const unordered_map<string, vector<MethodDeclaration *>>& containedMethods,
    unordered_map<MethodDeclaration *, vector<MethodDeclaration *>>& replace)
{


    for (const auto&[sig, ms]: containedMethods){
        assert(ms.size() >= 1);
        string returnType = ms[0]->type->getTypeName();
        bool returnTypeMatches = all_of(ms.begin(), ms.end(),
                                        [returnType](MethodDeclaration *m) {
                                            return (m->type->getTypeName() == returnType);
                                        });

        if (!returnTypeMatches){
            cout << "cannot contain two methods with same signature but different return type" << endl;
            exit(42);
        }

        for (MethodDeclaration * m: ms){
            if (replace.find(m) != replace.end()){
                assert(ms.size() == 1);
                for (MethodDeclaration * replaced : replace[m]){

                    if(modifiersContains(replaced->modifiers->elements, Modifier::STATIC) &&
                       !modifiersContains(m->modifiers->elements,  Modifier::STATIC))
                    {
                        cout << "Cannot replace static method with non-static method" << endl;
                        exit(42);
                    }

                    if(!modifiersContains(replaced->modifiers->elements, Modifier::STATIC) &&
                       modifiersContains(m->modifiers->elements,  Modifier::STATIC))
                    {
                        cout << "Cannot replace non-static method with static method" << endl;
                        exit(42);
                    }

                    if(replaced->type->getTypeName() != m->type->getTypeName()){
                        cout << "Cannot replace method with different return type" << endl;
                        exit(42);
                    }
                    if(modifiersContains(replaced->modifiers->elements, Modifier::PUBLIC) &&
                       !modifiersContains(m->modifiers->elements, Modifier::PUBLIC))
                    {
                        cout << "Cannot replace public method with non-public" << endl;
                        exit(42);
                    }

                    if(modifiersContains(replaced->modifiers->elements, Modifier::FINAL)){
                        cout << "Cannot replace final method" << endl;
                        exit(42);
                    }
                }
            }
        }

    }

}


void linkTypeMemberMethodsHierarchy(ClassDeclaration *classDecl);

void linkTypeMemberMethodsHierarchy(InterfaceDeclaration *interfaceDecl)
{
    if (interfaceDecl->containedAbstractMethods == nullptr){

        assert(interfaceDecl->interfaces != nullptr);

        interfaceDecl->replaceMethods = make_unique<unordered_map<MethodDeclaration *, vector<MethodDeclaration*>>>();
        interfaceDecl->containedAbstractMethods = make_unique<unordered_map<string, vector<MethodDeclaration *>>>();


        vector<unordered_map<string, vector<MethodDeclaration *>> *> superAbstractMethodSets;

        if (env_ptr->extras.find("objectMethodStubs") == env_ptr->extras.end()){
            ClassDeclaration * objectDecl = env_ptr->classes["java.lang.Object"];
            linkTypeMemberMethodsHierarchy(objectDecl);
            env_ptr->extras["objectMethodStubs"] = createObjectMethodStubs();
        }

        unordered_map<string, vector<MethodDeclaration *>> objectAbstractMethods;
        if (interfaceDecl->interfaces->size() == 0){
            auto * objectMethodStubs = dynamic_cast<ASTNodeList<MethodDeclaration> *>(env_ptr->extras["objectMethodStubs"]);
            assert(objectMethodStubs);

            for (auto *e : objectMethodStubs->elements)
            {
                objectAbstractMethods[e->getSignature()].push_back(e);
            }
            superAbstractMethodSets.push_back(&objectAbstractMethods);
        }

        for (auto * e: *interfaceDecl->interfaces){
            linkTypeMemberMethodsHierarchy(e);
            superAbstractMethodSets.push_back(e->containedAbstractMethods.get());
        }


        auto declaredMethods = unordered_map<string, MethodDeclaration *>{};
        for (auto* member: interfaceDecl->interfaceBody->elements){
            auto *m = dynamic_cast<MethodDeclaration *>(member);
            assert(m);

            string sig = m->getSignature();

            auto &objectContainedMethods = *(env_ptr->classes["java.lang.Object"]->containedConcreteMethods.get());
            if (objectContainedMethods.find(sig) != objectContainedMethods.end()){
                if (modifiersContains(objectContainedMethods[sig]->modifiers->elements,Modifier::FINAL)){
                    cout << "Interface declares method with the same signature as a public final method in java.lang.Object" << endl;
                    exit(42);
                }
            }

            if (declaredMethods.find(sig) != declaredMethods.end()){
                cout << "Cannot declare two methods with the same signature in an interface" << endl;
                exit(42);
            }

            modifiersAdd(m->modifiers->elements, Modifier::ABSTRACT);
            modifiersAdd(m->modifiers->elements, Modifier::PUBLIC);
            declaredMethods[sig] = m;
        }

        auto superAbstractMethods = merge(superAbstractMethodSets);

        auto containedMethods = replace(*interfaceDecl->replaceMethods, declaredMethods, superAbstractMethods, interfaceDecl->name->getString());
        checkContainedMethods(containedMethods, *interfaceDecl->replaceMethods);

        *interfaceDecl->containedAbstractMethods = containedMethods;
    }
}

void linkTypeMemberMethodsHierarchy(ClassDeclaration* classDecl)
{

    if (classDecl->containedConcreteMethods == nullptr || classDecl->containedAbstractMethods == nullptr){
        assert(classDecl->interfaces != nullptr);
        assert(classDecl->baseClass != nullptr || classDecl->name->getString() == "Object");
        assert(classDecl->containedConcreteMethods == nullptr && classDecl->containedAbstractMethods == nullptr);

        classDecl->containedConcreteMethods = make_unique<unordered_map<string, MethodDeclaration *>>();
        classDecl->containedAbstractMethods = make_unique<unordered_map<string, vector<MethodDeclaration *>>>();
        classDecl->replaceMethods = make_unique<unordered_map<MethodDeclaration *, vector<MethodDeclaration*>>>();

        vector<unordered_map<string, vector<MethodDeclaration *>> *> superAbstractMethodSets;

        for (auto * e: *classDecl->interfaces){
            linkTypeMemberMethodsHierarchy(e);
            superAbstractMethodSets.push_back(e->containedAbstractMethods.get());
        }

        if (classDecl->baseClass){
            linkTypeMemberMethodsHierarchy(classDecl->baseClass);
            superAbstractMethodSets.push_back(classDecl->baseClass->containedAbstractMethods.get());
        }

        auto declaredMethods = unordered_map<string, MethodDeclaration *>{};
        for (auto* member: classDecl->classBody->elements){
            auto *m = dynamic_cast<MethodDeclaration *>(member);
            if(m){
                string sig = m->getSignature();

                if (declaredMethods.find(sig) != declaredMethods.end()){
                    cout << "Cannot declare two methods with the same signature in a class" << endl;
                    exit(42);
                }
                declaredMethods[sig] = m;
            }
        }

        auto superAbstractMethods = merge(superAbstractMethodSets);
        unordered_map<string, vector<MethodDeclaration *>> superMethods;
        if (classDecl->baseClass){
            superMethods = merge(superAbstractMethods, *classDecl->baseClass->containedConcreteMethods);
        }
        else{
            superMethods = move(superAbstractMethods);
        }

        auto containedMethods = replace(*classDecl->replaceMethods, declaredMethods, superMethods, classDecl->name->getString());
        checkContainedMethods(containedMethods, *classDecl->replaceMethods);

        split(*classDecl->containedAbstractMethods, *classDecl->containedConcreteMethods, containedMethods);

        if (!modifiersContains(classDecl->modifiers->elements,Modifier::ABSTRACT)){
            if (classDecl->containedAbstractMethods->size() != 0){
                cout << "Non-abstract class cannot contain abstract methods" << endl;
                exit(42);
            }
        }
    }
}

void linkTypeMemberFieldsHierarchy(ClassDeclaration* classDecl)
{

    if (classDecl->containedFields == nullptr){
        assert(classDecl->baseClass != nullptr || classDecl->name->getString() == "Object");

        classDecl->containedFields = make_unique<unordered_map<string, FieldDeclaration *>>();
        classDecl->replaceFields = make_unique<unordered_map<FieldDeclaration *, FieldDeclaration *>>();

        unordered_map<string, FieldDeclaration *> superFields;
        if (classDecl->baseClass)
        {
            linkTypeMemberFieldsHierarchy(classDecl->baseClass);
            superFields = *classDecl->baseClass->containedFields;
        }

        auto declaredFields = unordered_map<string, FieldDeclaration *>{};
        for (auto* member: classDecl->classBody->elements){
            auto * f= dynamic_cast<FieldDeclaration *>(member);
            if(f){
                string name = f->declaration->name->getString();

                if (declaredFields.find(name) != declaredFields.end()){
                    cout << "Cannot declare two fields with the same name in a class" << endl;
                    exit(42);
                }
                declaredFields[name] = f;
            }
        }

        for (const auto& [name, f]: declaredFields){
            if (superFields.find(name) != superFields.end()){
                assert(classDecl->replaceFields->find(f) == classDecl->replaceFields->end());
                (*classDecl->replaceFields)[f] = superFields[name];
            }
            (*classDecl->containedFields)[name] = f;
        }
        for (const auto& [name, f]: superFields){
            if (declaredFields.find(name) == declaredFields.end()){
                (*classDecl->containedFields)[name] = f;
            }
        }
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
            linkTypeHierarchy(interface);
        }
    }
    modifiersAdd(interfaceDecl->modifiers->elements, Modifier::PUBLIC);
    modifiersAdd(interfaceDecl->modifiers->elements, Modifier::ABSTRACT);
}

void linkTypeHierarchy(ClassDeclaration* classDecl){

    if (classDecl->baseClass == nullptr && classDecl->name->getString()!="Object"){

        if (classDecl->extends == nullptr){
            classDecl->baseClass = env_ptr->classes["java.lang.Object"];
        }
        else{
            classDecl->baseClass = dynamic_cast<ClassDeclaration*>(
                dynamic_cast<QualifiedType*>(classDecl->extends)->name->refers_to
            );
        }

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
            linkTypeHierarchy(interface);
        }
    }
}


void CheckClass(const ClassDeclaration* const classDecl, Environment& env)
{
    assert (classDecl->baseClass != nullptr || classDecl->name->getString() == "Object");
    if (classDecl->baseClass){
        if (modifiersContains(classDecl->baseClass->modifiers->elements, Modifier::FINAL)){

            cout << "Cannot extend a final class" << endl;
            exit(42);
        }
    }

    assert(classDecl->interfaces);
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

    assert(classDecl->classBody);
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

    CheckCycles(classDecl, unordered_set<const TypeDeclaration*>());

}

void CheckInterface(const InterfaceDeclaration* const interfaceDecl, Environment& env)
{
    assert(interfaceDecl->interfaces);
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

    CheckCycles(interfaceDecl, unordered_set<const TypeDeclaration*>());
}


void CheckEnvironmentHierarchy(Environment& env)
{
    env_ptr = &env;

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

    // check types
    for (const pair<string, ClassDeclaration *> &entry : env.classes)
    {
        CheckClass(entry.second, env);
    }
    // check interfaces
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
