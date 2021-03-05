#include "Weeder.h"
#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>
#include <set>

using namespace std;

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

// get list of modifiers from MODIFIERS_OPT node
set<TokenType> getModifiersFromModifiersOpt(ParseTreeNode *modifiersOpt){

    assert(modifiersOpt->symbol == MODIFIERS_OPT);

    if (modifiersOpt->children.size() == 0){
        return set<TokenType>();
    }

    assert(modifiersOpt->children.size() == 1);
    return getModifiers(modifiersOpt->children[0]);
}

void checkMethodValidModifiers(const set<TokenType>& modifiers){

    if (modifiers.find(ABSTRACT) != modifiers.end() && 
        (modifiers.find(FINAL) != modifiers.end() || modifiers.find(STATIC) != modifiers.end()))
    {    
        cout << "abstract can't be final/static" << endl;
        exit(42);
    }

    if (modifiers.find(FINAL) != modifiers.end() && modifiers.find(STATIC) != modifiers.end())
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

    if (modifiers.find(PUBLIC) == modifiers.end() &&
        modifiers.find(PROTECTED) == modifiers.end() &&
        modifiers.find(PRIVATE) == modifiers.end())
    {
        cout << "method declaration can't be package private" << endl;
        exit(42);
    }
}

void checkMethodDeclaratorRest(ParseTreeNode * methodRest, const set<TokenType>& modifiers, map<string,string>& context){
    assert(methodRest->symbol == METHOD_DECLARATION);

    bool abstractOrNative = modifiers.find(ABSTRACT) != modifiers.end() || modifiers.find(NATIVE) != modifiers.end();
    if ((methodRest->children[1]->symbol == BLOCK && abstractOrNative) ||
        (methodRest->children[1]->symbol == SEMICOLON && !abstractOrNative))
    {
        cout << "no body iff abstract or native" << endl;
        exit(42);
    }
}

void checkInterfaceMethodDeclaratorRest(ParseTreeNode * iMethodRest, const set<TokenType>& modifiers, map<string,string>& context){
    assert(iMethodRest->symbol == INTERFACE_METHOD_DECLARATION);
}

void checkInterfaceBodyDeclaration(ParseTreeNode * iBodyDecl, map<string,string>& context){
    assert(iBodyDecl->symbol == INTERFACE_BODY_DECLARATION);

    if (iBodyDecl->children.size() == 2){
        assert(iBodyDecl->children[0]->symbol == MODIFIERS_OPT);
        set<TokenType> modifiers = getModifiersFromModifiersOpt(iBodyDecl->children[0]);

        checkMethodValidModifiers(modifiers);

        if (modifiers.find(STATIC) != modifiers.end() ||
            modifiers.find(FINAL) != modifiers.end() ||
            modifiers.find(NATIVE) != modifiers.end())
        {
            cout << "invalid interface member modifiers" << endl;
            exit(42);
        }
    }
}


void checkClassBodyDeclaration(ParseTreeNode * cBodyDecl, map<string,string>& context){
    assert(cBodyDecl->symbol == CLASS_BODY_DECLARATION);

    if (cBodyDecl->children.size() == 2){
        assert(cBodyDecl->children[0]->symbol == MODIFIERS_OPT);
        set<TokenType> modifiers = getModifiersFromModifiersOpt(cBodyDecl->children[0]);

        ParseTreeNode* classMember = cBodyDecl->children[1];
        switch (classMember->children[0]->symbol)
        {
            case FIELD_DECLARATION:
            {
                if (modifiers.find(FINAL) != modifiers.end()) 
                {
                    cout << "fields cannot be final" << endl;
                    exit(42);
                }
                if (modifiers.find(PUBLIC) == modifiers.end() &&
                    modifiers.find(PRIVATE) == modifiers.end() &&
                    modifiers.find(PROTECTED) == modifiers.end()) 
                {
                    cout << "fields declaration can't be package private" << endl;
                    exit(42);
                }
            }
            break;
            case METHOD_DECLARATION:
            {
                checkMethodValidModifiers(modifiers);
                checkMethodDeclaratorRest(classMember->children[0], modifiers, context);
            }
            break;
            case CONSTRUCTOR_DECLARATION:
            {
                // TODO: check modifiers for constructors
            }
            break;
        }
    }
}

/**
 * check for a constructor
 */
void checkClassBody(ParseTreeNode * cBody){
    assert(cBody->symbol == CLASS_BODY);

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

/**
 *  1. ID matches filename
 *  3. contains a constructor
 */
void checkClassDeclaration(ParseTreeNode * cDecl, map<string,string>& context){

    assert(cDecl->symbol == CLASS_DECLARATION);

    assert(cDecl->children[1]->symbol == ID);
    if (context["fileName"] != cDecl->children[1]->token->second)
    {
        cout << "filename: " << context["fileName"] << " does not match classname: " << cDecl->children[1]->token->second << endl;
        exit(42);
    }

    assert(cDecl->children[4]->symbol == CLASS_BODY);
    if (cDecl->children[4]->children.size() < 3 || !bodyDeclarationsHasConstructor(cDecl->children[4]->children[1]))
    {
        cout << "class no constructor" << endl;
        exit(42);
    }
}


/**
 *  1. ID matches filename
 *  3. contains a constructor
 */
void checkInterfaceDeclaration(ParseTreeNode * iDecl, map<string,string>& context){

    assert(iDecl->symbol == INTERFACE_DECLARATION);

    assert(iDecl->children[1]->symbol == ID);
    if (context["fileName"] != iDecl->children[1]->token->second)
    {
        cout << "filename: " << context["fileName"] << " does not match interfacename: " << iDecl->children[1]->token->second << endl;
        exit(42);
    }
}

/**
 * checks validity of class/interface declaration
 * 
 */
void checkTypeDeclaration(ParseTreeNode* t, map<string,string>& context){
    assert(t->symbol == TYPE_DECLARATION);
    assert(t->children.size() == 2);

    set<TokenType> modifiers = getModifiersFromModifiersOpt(t->children[0]);
    ParseTreeNode* declaration = t->children[1];

    if (declaration)
    {
        if (declaration->symbol == CLASS_DECLARATION) 
        {
            // cant be abstract final
            if (modifiers.find(ABSTRACT) != modifiers.end() &&
                modifiers.find(FINAL) != modifiers.end()) 
            {
                cout << "class declaration contains both abstract and final" << endl;
                exit(42);
            }
            if (modifiers.find(PUBLIC) == modifiers.end() ||
                modifiers.find(PRIVATE) != modifiers.end() ||
                modifiers.find(PROTECTED) != modifiers.end() )
            {
                cout << "class declaration must be public" << endl;
                exit(42);
            }
            checkClassDeclaration(declaration, context);
        }
        else if (declaration->symbol == INTERFACE_DECLARATION) 
        {
            if (modifiers.find(PUBLIC) == modifiers.end() ||
                modifiers.find(PRIVATE) != modifiers.end() ||
                modifiers.find(PROTECTED) != modifiers.end()) 
            {
                cout << "interface declaration must be public" << endl;
                exit(42);
            }
            checkInterfaceDeclaration(declaration, context);
        }
    }
}

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
    else if (t->symbol == UNARY_EXPRESSION)
    {
        checkUnaryExpression(t, context);
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