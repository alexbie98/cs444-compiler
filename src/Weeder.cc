#include "Weeder.h"
#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;


vector<TokenType> getModifiers(ParseTreeNode *modifiers){
    assert(modifiers->symbol == MODIFIERS);

    vector<TokenType> modifierTokenTypes;
    TokenType modifier;

    for (ParseTreeNode* child : modifiers->children){
        if (child->symbol == MODIFIER){
            assert(child->children.size() == 1);
            assert(child->children[0]->token != NULL);
            modifier = child->children[0]->token->first;
        }
        else if (child->symbol == MODIFIERS){
            modifierTokenTypes = getModifiers(child);
        }
    }

    modifierTokenTypes.push_back(modifier);
    return modifierTokenTypes;
}


// get list of modifiers from MODIFIERS_OPT node
vector<TokenType> getModifiersFromModifiersOpt(ParseTreeNode *modifiersOpt){

    assert(modifiersOpt->symbol == MODIFIERS_OPT);

    if (modifiersOpt->children.size() == 0){
        return vector<TokenType>();
    }

    assert(modifiersOpt->children.size() == 1);
    return getModifiers(modifiersOpt->children[0]);
}

void checkMethodValidModifiers(const vector<TokenType>& modifiers){

    if (find(modifiers.begin(), modifiers.end(), ABSTRACT) != modifiers.end() &&
        (find(modifiers.begin(), modifiers.end(), FINAL) != modifiers.end() ||
         find(modifiers.begin(), modifiers.end(), STATIC) != modifiers.end())){
        
        cout << "abstract can't be final/static" << endl;
        exit(42);
    }

    if (find(modifiers.begin(), modifiers.end(), STATIC) != modifiers.end() &&
        find(modifiers.begin(), modifiers.end(), FINAL) != modifiers.end()){
        
        cout << "static can't be final" << endl;
        exit(42);
    }

    if (find(modifiers.begin(), modifiers.end(), NATIVE) != modifiers.end() &&
        !(find(modifiers.begin(), modifiers.end(), STATIC) != modifiers.end())){
        
        cout << "static can't be final" << endl;
        exit(42);
    }

}

void checkMethodDeclaratorRest(ParseTreeNode * methodRest, const vector<TokenType>& modifiers, map<string,string>& context){
    assert(methodRest->symbol == METHOD_DECLARATOR_REST);
    if ((methodRest->children[1]->symbol == METHOD_BODY && (find(modifiers.begin(), modifiers.end(), ABSTRACT)!=modifiers.end() || find(modifiers.begin(), modifiers.end(), NATIVE)!=modifiers.end())) ||
        (methodRest->children[1]->symbol == SEMICOLON && find(modifiers.begin(), modifiers.end(), ABSTRACT)==modifiers.end() && find(modifiers.begin(), modifiers.end(), NATIVE)==modifiers.end())){
        

        cout << "no body iff abstract or native" << endl;
        exit(42);
    }
}

void checkInterfaceMethodDeclaratorRest(ParseTreeNode * iMethodRest, const vector<TokenType>& modifiers, map<string,string>& context){
    assert(iMethodRest->symbol == INTERFACE_METHOD_DECLARATOR_REST);

}

void checkInterfaceBodyDeclaration(ParseTreeNode * iBodyDecl, map<string,string>& context){
    assert(iBodyDecl->symbol == INTERFACE_BODY_DECLARATION);

    if (iBodyDecl->children.size() == 2){
        assert(iBodyDecl->children[0]->symbol == MODIFIERS_OPT);
        auto modifiers = getModifiersFromModifiersOpt(iBodyDecl->children[0]);

        checkMethodValidModifiers(modifiers);
        if (find(modifiers.begin(), modifiers.end(), STATIC) != modifiers.end() ||
            find(modifiers.begin(), modifiers.end(), FINAL) != modifiers.end() ||
            find(modifiers.begin(), modifiers.end(), NATIVE) != modifiers.end()){

            cout << "invalid interface member modifiers" << endl;
            exit(42);
        }
    }
}


void checkClassBodyDeclaration(ParseTreeNode * cBodyDecl, map<string,string>& context){
    assert(cBodyDecl->symbol == CLASS_BODY_DECLARATION);

    if (cBodyDecl->children.size() == 2){
        assert(cBodyDecl->children[0]->symbol == MODIFIERS_OPT);
        auto modifiers = getModifiersFromModifiersOpt(cBodyDecl->children[0]);

        if (cBodyDecl->children[1]->children[0]->symbol == VOID ||
            (cBodyDecl->children[1]->children[0]->symbol == METHOD_OR_FIELD_DECLARATION &&
             cBodyDecl->children[1]->children[0]->children[2]->children[0]->symbol == METHOD_DECLARATOR_REST)){
             
            checkMethodValidModifiers(modifiers);
            
            if(cBodyDecl->children[1]->children[0]->symbol == VOID){
                checkMethodDeclaratorRest(cBodyDecl->children[1]->children[2], modifiers, context);
            }
            else{
                checkMethodDeclaratorRest(cBodyDecl->children[1]->children[0]->children[2]->children[0], modifiers, context);
            }
        }

        if (cBodyDecl->children[1]->children[0]->symbol == METHOD_OR_FIELD_DECLARATION &&
            cBodyDecl->children[1]->children[0]->children[2]->children[0]->symbol == VARIABLE_DECLARATOR_REST){

            if (find(modifiers.begin(), modifiers.end(), FINAL)!=modifiers.end()){
                cout << "fields cannot be final";
                exit(42);
            }
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
    if(cBodyDecl->children.size() == 2 &&
       cBodyDecl->children[1]->children[0]->symbol == ID){
        return true;
    }
    else{
        return false;
    }
}

bool bodyDeclarationsHasConstructor(ParseTreeNode* cBodyDecls){
    assert(cBodyDecls->symbol == CLASS_BODY_DECLARATIONS);
    if(cBodyDecls->children.size() == 2){
        return bodyDeclarationIsConstructor(cBodyDecls->children[1]) || bodyDeclarationsHasConstructor(cBodyDecls->children[0]);
    }
    else{
        return bodyDeclarationIsConstructor(cBodyDecls->children[0]);
    }
}

/**
 *  1. ID matches filename
 *  3. contains a constructor
 */
void checkClassDeclaration(ParseTreeNode * cDecl, map<string,string>& context){

    assert(cDecl->symbol == CLASS_DECLARATION);
    assert(cDecl->children.size() >= 3);
    for (auto* child: cDecl->children){
        if (child->symbol == ID){
            assert(child->token != NULL);
            if (context["fileName"] != child->token->second)
            {
                cout << "filename: " << context["fileName"] << " does not match classname: " << child->token->second;
                exit(42);
            }
        }

        //check class body for a contructor
        if (child->symbol == CLASS_BODY){
            if (child->children.size() < 3 ||
                !bodyDeclarationsHasConstructor(child->children[1])){

                cout << "class no constructor" << endl;
                exit(42);
            }
        }
    }

}


/**
 *  1. ID matches filename
 *  3. contains a constructor
 */
void checkInterfaceDeclaration(ParseTreeNode * iDecl, map<string,string>& context){

    assert(iDecl->symbol == INTERFACE_DECLARATION);
    assert(iDecl->children.size() >= 3);

    for (auto* child: iDecl->children){
        if (child->symbol == ID){
            assert(child->token != NULL);
            if (context["fileName"] != child->token->second){
                cout << "filename: " << context["fileName"] << " does not match interfacename: " << child->token->second;
                exit(42);
            }
        }
        //if (child->symbol == INTERFACE_BODY){
        //   checkInterfaceBody(child);
        //`}
    }    

}

/**
 * checks validity of class/interface declaration
 * 
 */
void checkClassOrInterfaceDeclaration(ParseTreeNode* t, map<string,string>& context){
    assert(t->symbol == CLASS_OR_INTERFACE_DECLARATION);
    assert(t->children.size() == 2);
    vector<TokenType> modifiers;
    ParseTreeNode* declaration = nullptr;
    for (auto *child : t->children)
    {
        if (child->symbol == MODIFIERS_OPT)
        {
            modifiers = getModifiersFromModifiersOpt(child);
        }
        else{
            assert(child->symbol == CLASS_DECLARATION || child->symbol == INTERFACE_DECLARATION);
            declaration = child;
        }
    }

    if (declaration)
    {
        if (declaration->symbol == CLASS_DECLARATION) {
            // cant be abstract final
            if (find(modifiers.begin(), modifiers.end(), ABSTRACT) != modifiers.end() &&
                find(modifiers.begin(), modifiers.end(), FINAL) != modifiers.end()) {

                cout << "class declaration contains both abstract and final" << endl;
                exit(42);
            }
            checkClassDeclaration(declaration, context);
        }
        else if (declaration->symbol == INTERFACE_DECLARATION) {
            checkInterfaceDeclaration(declaration, context);
        }
    }
}



void checkExpression2(ParseTreeNode * expression2, map<string,string>& context, bool has_minus = false){
    assert(expression2->symbol == EXPRESSION2);
    //cout << has_minus << endl;
    if (expression2->children.size() == 2)
    {
        checkExpression2(expression2->children[1], context, true);
    }
    else if (expression2->children.size()== 1){
        ParseTreeNode *expression3 = expression2->children[0];
        if (expression3->children[0]->symbol == PRIMARY &&
            expression3->children[0]->children[0]->symbol == SELECTABLE_PRIMARY &&
            expression3->children[0]->children[0]->children[0]->symbol == LITERAL &&
            expression3->children[0]->children[0]->children[0]->children[0]->symbol == INT_LIT &&
            expression3->children[0]->children[0]->children[0]->children[0]->token->second == "2147483648" &&
            !has_minus
            ){
            cout << "non-negative 214738368 literal" << endl;
            exit(42);
        }
    }
}

void checkExpression3(ParseTreeNode* expr3, map<string, string>& context)
{
    assert(expr3->symbol == EXPRESSION3);
    if(expr3->children[0]->symbol == SELECTABLE_PRIMARY &&
        expr3->children[0]->children[0]->symbol == NEW &&
        expr3->children[0]->children[1]->symbol == CREATOR &&
        expr3->children[0]->children[1]->children[1]->symbol == ARRAY_CREATOR_REST &&
        expr3->children[1]->symbol == SELECTORS)
    {
        ParseTreeNode* selector = expr3->children[1];
        while (selector->symbol == SELECTORS)
        {
            selector = selector->children[0];
        }
        assert(selector->symbol == SELECTOR);

        if (selector->children[0]->symbol == LBRACKET)
        {
            cout << "Trying to use[expr] after new type[], can't create multi-array" << endl;
            exit(42);
        }
    }
}

void checkExpression1Rest(ParseTreeNode* expr1Rest, map<string,string>& context){
    assert(expr1Rest->symbol == EXPRESSION1_REST);
    if (expr1Rest->children[0]->symbol == INSTANCEOF &&
        expr1Rest->children[1]->children[0]->symbol == BASIC_TYPE){
        
        cout << "can't instanceof basic type" << endl;
        exit(42);
    }
}

void weed(ParseTreeNode *t, map<string,string>& context){

    for (ParseTreeNode * child: t->children){
        if(child->symbol == EXPRESSION2){
            checkExpression2(child, context);
        }
        else if (child->symbol == CLASS_OR_INTERFACE_DECLARATION){
            checkClassOrInterfaceDeclaration(child, context);
        }
        else if (child->symbol == INTERFACE_BODY_DECLARATION){
            checkInterfaceBodyDeclaration(child, context);
        }
        else if (child->symbol == CLASS_BODY_DECLARATION){
            checkClassBodyDeclaration(child, context);
        }
        else if (child->symbol == EXPRESSION1_REST){
            checkExpression1Rest(child, context);
        }
        else if (child->symbol == EXPRESSION3) {
            checkExpression3(child, context);
        }
        weed(child, context);
    }
}