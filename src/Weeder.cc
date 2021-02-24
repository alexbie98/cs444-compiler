#include "Weeder.h"
#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

void weed(ParseTreeNode *t, const string& fileName){

}

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
void checkClassDeclaration(ParseTreeNode * cDecl, const string& fileName){

    assert(cDecl->symbol == CLASS_DECLARATION);
    assert(cDecl->children.size() >= 3);
    for (auto* child: cDecl->children){
        if (child->symbol == ID){
            assert(child->token != NULL);
            if (fileName != child->token->second){
                cout << "filename: " << fileName << " does not match classname: " << child->token->second;
                exit(42);
            }
        }
        if (child->symbol == CLASS_BODY){
            checkClassBody(child);
        }
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
void checkInterfaceDeclaration(ParseTreeNode * iDecl, const string& fileName){

    assert(iDecl->symbol == INTERFACE_DECLARATION);
    assert(iDecl->children.size() >= 3);

    for (auto* child: iDecl->children){
        if (child->symbol == ID){
            assert(child->token != NULL);
            if (fileName != child->token->second){
                cout << "filename: " << fileName << " does not match interfacename: " << child->token->second;
                exit(42);
            }
        }
        if (child->symbol == INTERFACE_BODY){
            checkInterfaceBody(child);
        }
    }
    string iName;

}

/**
 * checks validity of class/interface declaration
 * 
 */
void checkClassOrInterfaceDeclaration(ParseTreeNode* t, const string& fileName){
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
            checkClassDeclaration(declaration, fileName);
        }
        else if (declaration->symbol == INTERFACE_DECLARATION) {
            checkInterfaceDeclaration(declaration, fileName);

        }
    }
}
