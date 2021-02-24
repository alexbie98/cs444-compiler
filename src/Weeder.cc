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



/**
 * check for a constructor
 */
void checkClassBody(ParseTreeNode * cBody){
    assert(cBody->symbol == CLASS_BODY);

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
        weed(child, context);
        // if (child->symbol == CLASS_BODY){
        //     checkClassBody(child);
        // }
    }

}

/**
 * 
 * 
 * 
 */
void checkInterfaceBody(ParseTreeNode * iBody){
    assert(iBody->symbol == INTERFACE_BODY);
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
        else{
            weed(child, context);
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


// void checkExpression3(ParseTreeNode * expression3){
//     assert(expression3->symbol == EXPRESSION3);
//     for (auto *child : expression3->children)
//     {
//         if (child->symbol == EXPRESSION2)
//         {
//             checkExpression2(child);
//         }
//     }

// }

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
        else{
            weed(expression3, context);
        }
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
        else{
            weed(child, context);
        }
    }
}