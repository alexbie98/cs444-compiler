#include "Weeder.h"
#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>
#include <set>

using namespace std;

const set<TokenType> CLASS_ALLOWED_MODIFIERS = {PUBLIC, FINAL, ABSTRACT};
const set<TokenType> INTERFACE_ALLOWED_MODIFIERS = {PUBLIC, ABSTRACT};
const set<TokenType> CONSTRUCTOR_ALLOWED_MODIFIERS = {PUBLIC, PROTECTED};
const set<TokenType> FIELD_ALLOWED_MODIFIERS = {PUBLIC, PROTECTED, STATIC};
const set<TokenType> METHOD_ALLOWED_MODIFIERS = {PUBLIC, PROTECTED, STATIC, NATIVE, ABSTRACT, FINAL};
const set<TokenType> INTERFACE_METHOD_ALLOWED_MODIFIERS = {PUBLIC, PROTECTED, ABSTRACT};

set<TokenType> getModifiers(ParseTreeNode* modifiers)
{
    assert(modifiers->symbol == MODIFIERS);

    set<TokenType> modifierTypes;

    if (modifiers->children.size() == 2)
    {
        assert(modifiers->children[0]->symbol == MODIFIERS);
        assert(modifiers->children[1]->symbol == MODIFIER);

        modifierTypes = getModifiers(modifiers->children[0]);
        TokenType token = modifiers->children[1]->children[0]->token->first;

        if (modifierTypes.find(token) != modifierTypes.cend())
        {
            cout << "Same modifier cannot appear twice in the same modifier list" << endl;
            exit(42);
        }

        modifierTypes.insert(token);
    }
    else
    {
        assert(modifiers->children[0]->symbol == MODIFIER);
        modifierTypes.insert(modifiers->children[0]->children[0]->token->first);
    }

    return modifierTypes;
}

set<TokenType> getModifiersFromModifiersOpt(ParseTreeNode *modifiersOpt){

    assert(modifiersOpt->symbol == MODIFIERS_OPT);
    if (modifiersOpt->children.size() == 0){
        return set<TokenType>();
    }
    assert(modifiersOpt->children.size() == 1);
    return getModifiers(modifiersOpt->children[0]);
}


void checkAllowedModifiers(const set<TokenType>& modifiers, const set<TokenType>& allowed){
    for (auto m: modifiers){
        if (allowed.find(m) == allowed.end()){
            cout << "modifier '" << TOKEN_TYPE_STR[m] << "' not allowed here"<< endl;
            exit(42);
        }
    }
}

void checkValidModifiers(const set<TokenType>& modifiers){

    size_t access = 0;
    if (modifiers.find(PUBLIC) != modifiers.end()) access++;
    if (modifiers.find(PRIVATE) != modifiers.end()) access++;
    if (modifiers.find(PROTECTED) != modifiers.end()) access++;

    if (access > 1){
        cout << ">1 access modifier specified" << endl;
        exit(42);
    }

    if (access == 0){
        cout << "package private not allowed" << endl;
        exit(42);
    }    

    if (modifiers.find(ABSTRACT) != modifiers.end() && 
        (modifiers.find(FINAL) != modifiers.end() || modifiers.find(STATIC) != modifiers.end()))
    {    
        cout << "abstract can't be final/static" << endl;
        exit(42);
    }

    if (modifiers.find(FINAL) != modifiers.end() && 
        modifiers.find(STATIC) != modifiers.end())
    {    
        cout << "static can't be final" << endl;
        exit(42);
    }

    if (modifiers.find(NATIVE) != modifiers.end() &&
        modifiers.find(STATIC) == modifiers.end())
    {    
        cout << "native must be static" << endl;
        exit(42);
    }
}


void checkMethodDeclaration(ParseTreeNode * methodDecl, const set<TokenType>& modifiers, map<string,string>& context){
    assert(methodDecl->symbol == METHOD_DECLARATION);

    bool abstractOrNative = modifiers.find(ABSTRACT) != modifiers.end() || modifiers.find(NATIVE) != modifiers.end();
    if ((methodDecl->children[1]->symbol == BLOCK && abstractOrNative) ||
        (methodDecl->children[1]->symbol == SEMICOLON && !abstractOrNative))
    {
        cout << "no body iff abstract or native" << endl;
        exit(42);
    }
}

void checkInterfaceBodyDeclaration(ParseTreeNode * interfaceBodyDecl, map<string,string>& context){
    assert(interfaceBodyDecl->symbol == INTERFACE_BODY_DECLARATION);

    if (interfaceBodyDecl->children.size() == 2){
        assert(interfaceBodyDecl->children[0]->symbol == MODIFIERS_OPT);

        // interface members are always interface methods
        set<TokenType> modifiers = getModifiersFromModifiersOpt(interfaceBodyDecl->children[0]);
        checkAllowedModifiers(modifiers, INTERFACE_METHOD_ALLOWED_MODIFIERS);
        checkValidModifiers(modifiers);
    }
}

void checkClassBodyDeclaration(ParseTreeNode * classBodyDecl, map<string,string>& context){
    assert(classBodyDecl->symbol == CLASS_BODY_DECLARATION);

    if (classBodyDecl->children.size() == 2){
        assert(classBodyDecl->children[0]->symbol == MODIFIERS_OPT);
        set<TokenType> modifiers = getModifiersFromModifiersOpt(classBodyDecl->children[0]);

        ParseTreeNode* classMember = classBodyDecl->children[1];
        switch (classMember->children[0]->symbol)
        {
            case FIELD_DECLARATION:
                checkAllowedModifiers(modifiers, FIELD_ALLOWED_MODIFIERS);
                break;
            case METHOD_DECLARATION:
                checkAllowedModifiers(modifiers, METHOD_ALLOWED_MODIFIERS);
                checkMethodDeclaration(classMember->children[0], modifiers, context);
                break;
            case CONSTRUCTOR_DECLARATION:
                checkAllowedModifiers(modifiers, CONSTRUCTOR_ALLOWED_MODIFIERS);
                break;
        }
        checkValidModifiers(modifiers);
    }
}

bool bodyDeclarationIsConstructor(ParseTreeNode* cBodyDecl){
    assert(cBodyDecl->symbol == CLASS_BODY_DECLARATION);
    return cBodyDecl->children.size() == 2 && cBodyDecl->children[1]->children[0]->symbol == CONSTRUCTOR_DECLARATION;
}

bool bodyDeclarationsHasConstructor(ParseTreeNode* cBodyDecls){
    assert(cBodyDecls->symbol == CLASS_BODY_DECLARATIONS);
    if(cBodyDecls->children.size() == 2)
    {
        return bodyDeclarationsHasConstructor(cBodyDecls->children[0]) || bodyDeclarationIsConstructor(cBodyDecls->children[1]);
    }
    else
    {
        return bodyDeclarationIsConstructor(cBodyDecls->children[0]);
    }
}

void checkClassDeclaration(ParseTreeNode * classDecl, map<string,string>& context){

    assert(classDecl->symbol == CLASS_DECLARATION);

    assert(classDecl->children[1]->symbol == ID);
    if (context["fileName"] != classDecl->children[1]->token->second)
    {
        cout << "filename: " << context["fileName"] << " does not match classname: " << classDecl->children[1]->token->second << endl;
        exit(42);
    }

    assert(classDecl->children[4]->symbol == CLASS_BODY);
    if (classDecl->children[4]->children.size() < 3 || !bodyDeclarationsHasConstructor(classDecl->children[4]->children[1]))
    {
        cout << "class no constructor" << endl;
        exit(42);
    }
}


void checkInterfaceDeclaration(ParseTreeNode * interfaceDecl, map<string,string>& context){

    assert(interfaceDecl->symbol == INTERFACE_DECLARATION);

    assert(interfaceDecl->children[1]->symbol == ID);
    if (context["fileName"] != interfaceDecl->children[1]->token->second)
    {
        cout << "filename: " << context["fileName"] << " does not match interfacename: " << interfaceDecl->children[1]->token->second << endl;
        exit(42);
    }
}

/**
 * checks validity of class/interface declaration
 * 
 */
void checkTypeDeclaration(ParseTreeNode* t, map<string,string>& context){
    assert(t->symbol == TYPE_DECLARATION);

    if (t->children.size() == 1){ 
        return; // TYPE_DECLARATION SEMICOLON
    }

    set<TokenType> modifiers = getModifiersFromModifiersOpt(t->children[0]);
    ParseTreeNode* declaration = t->children[1];

    if (declaration)
    {
        if (declaration->symbol == CLASS_DECLARATION) 
        {
            checkAllowedModifiers(modifiers, CLASS_ALLOWED_MODIFIERS);
            checkValidModifiers(modifiers);
            checkClassDeclaration(declaration, context);
        }
        else if (declaration->symbol == INTERFACE_DECLARATION) 
        {
            checkAllowedModifiers(modifiers, INTERFACE_ALLOWED_MODIFIERS);
            checkValidModifiers(modifiers);
            checkInterfaceDeclaration(declaration, context);
        }
    }
}


// implemented by grammar ------------

bool typeIsBasicOrArrayType(ParseTreeNode*type, map<string,string>& context)
{
    assert(type->symbol == TYPE);
    return type->children[0]->symbol == BASIC_TYPE || type->children[0]->children[0]->symbol == ARRAY_TYPE;
}

bool typeListHasBasicOrArrayType(ParseTreeNode* typeList, map<string,string>& context)
{
    assert(typeList->symbol == TYPE_LIST);

    if (typeList->children.size() == 1){
        return typeIsBasicOrArrayType(typeList->children[0], context);
    }
    else{
        assert(typeList->children.size() == 3);
        return typeListHasBasicOrArrayType(typeList->children[0], context) || typeIsBasicOrArrayType(typeList->children[2], context);
    }
}

void checkExtendsOpt(ParseTreeNode * extendsOpt, map<string,string> context){}

void checkInterfacesOpt(ParseTreeNode * inter, map<string,string> context){}

// ------------------------------------------

void checkUnaryExpression(ParseTreeNode * unaryExpr, map<string,string>& context)
{
    assert(unaryExpr->symbol == UNARY_EXPRESSION);
    if (unaryExpr->children.size()== 1){
        ParseTreeNode* unaryNotMinus = unaryExpr->children[0];
        ParseTreeNode* parent = unaryExpr->parent;

        if (unaryNotMinus->children[0]->symbol == PRIMARY &&
            unaryNotMinus->children[0]->children[0]->symbol == PRIMARY_NO_NEW_ARRAY &&
            unaryNotMinus->children[0]->children[0]->children[0]->symbol == LITERAL &&
            unaryNotMinus->children[0]->children[0]->children[0]->children[0]->symbol == INT_LIT &&
            unaryNotMinus->children[0]->children[0]->children[0]->children[0]->token->second == "2147483648" &&
            !(parent->symbol == UNARY_EXPRESSION && parent->children[0]->symbol == MINUS)
            )
        {
            cout << "non-negative 214738368 literal" << endl;
            exit(42);
        }
    }
}

void checkArrayAccess(ParseTreeNode* arrayAccess, map<string, string>& context)
{
    assert(arrayAccess->symbol == ARRAY_ACCESS);
    if (arrayAccess->children[0]->symbol == PRIMARY_NO_NEW_ARRAY &&
        arrayAccess->children[0]->children[0]->symbol == ARRAY_ACCESS)
    {
        cout << "No multi arrays, so we cannot do multi array access" << endl;
        exit(42);
    }
}

void checkCastExpression(ParseTreeNode* cast, map<string, string>& context)
{
    assert(cast->symbol == CAST_EXPRESSION);

    if (cast->children[1]->symbol == EXPRESSION)
    {
        ParseTreeNode* node = cast->children[1];

        while (node->symbol != NAME)
        {
            if (node->children.size() != 1)
            {
                cout << "Cannot cast to an expression, only a type name (NAME)" << endl;
                exit(42);
            }
            node = node->children[0];
        }
    }
}

void weed(ParseTreeNode *t, map<string,string>& context){

    if(t->symbol == UNARY_EXPRESSION)
    {
        checkUnaryExpression(t, context);
    }
    else if (t->symbol == TYPE_DECLARATION)
    {
        checkTypeDeclaration(t, context);
    }
    else if (t->symbol == INTERFACE_BODY_DECLARATION)
    {
        checkInterfaceBodyDeclaration(t, context);
    }
    else if (t->symbol == CLASS_BODY_DECLARATION)
    {
        checkClassBodyDeclaration(t, context);
    }
    else if (t->symbol == ARRAY_ACCESS) 
    {
        checkArrayAccess(t, context);
    }
    else if (t->symbol == CAST_EXPRESSION)
    {
        checkCastExpression(t, context);
    }

    for (auto* child: t->children){
        weed(child, context);
    }
}