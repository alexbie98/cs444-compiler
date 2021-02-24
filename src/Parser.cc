#include "Parser.h"
#include "ParseTable.h"
#include <iostream>

using namespace std;

ParseTreeNode::~ParseTreeNode()
{
    for(ParseTreeNode * node : children)
    {
        delete node;
    }
}

ParseTreeNode* parse(const vector<Token>& input)
{
    vector<ParseTreeNode*> inputNodes;
    // Create the leaf nodes of the parse tree

    inputNodes.push_back(new ParseTreeNode());
    inputNodes.back()->symbol = TokenType::START_TERMINAL;

    for (const Token& token : input)
    {
        inputNodes.push_back(new ParseTreeNode());
        inputNodes.back()->symbol = token.first;
        inputNodes.back()->token = &token;
    }
    inputNodes.push_back(new ParseTreeNode());
    inputNodes.back()->symbol = TokenType::END_TERMINAL;

    vector<ParseTreeNode*> symbolStack;
    vector<int> stateStack;
    stateStack.push_back(0);

    for (ParseTreeNode* node : inputNodes)
    {
        int ruleIndex;
        while ((ruleIndex = stateReduce(stateStack.back(), node->symbol)) >= 0)
        {
            const Production& rule = PRODUCTIONS[ruleIndex];

            ParseTreeNode* node = new ParseTreeNode();
            node->symbol = rule.first;
            node->children.resize(rule.second.size());

            // pop stack x times
            for (size_t i = 0; i < rule.second.size(); i++)
            {
                node->children[rule.second.size() - 1 - i] = symbolStack.back();
                symbolStack.pop_back();
                stateStack.pop_back();
            }

            // push to stack
            symbolStack.push_back(node);
            stateStack.push_back(stateShift(stateStack.back(), rule.first));
        }

        int nextState = stateShift(stateStack.back(), node->symbol);

        // Reject
        if (nextState < 0)
        {
            for (ParseTreeNode* node : symbolStack)
            {
                printParseTree(node);
                delete node;
            }
            return nullptr;
        }
        symbolStack.push_back(node);
        stateStack.push_back(nextState);
    }

    // At this point the stack is START_TERMINAL, START_SYMBOL, END_TERMINAL
    // delete terminal and return the start symbol
    delete symbolStack[0];
    delete symbolStack[2];

    return symbolStack[1];
}

const string NT_SYMBOL_STR [] = {
    "START_SYMBOL",
    "IDENTIFIER",
    "LONG_IDENTIFIER",
    "QUALIFIED_IDENTIFIER",
    "LITERAL",
    "EXPRESSION",
    "EXPRESSION1",
    "EXPRESSION2",
    "EXPRESSION1_REST",
    "EXPRESSION_INFIX",
    "EXPRESSION_LIST",
    "EXPRESSION_OPT",
    "ASSIGN_OP",
    "TYPE",
    "BASIC_TYPE",
    "STATEMENT_EXPRESSION",
    "INFIX_OP",
    "PRIMARY",
    "PREFIX_OP",
    "SELECTOR",
    "SELECTORS",
    "ARGUMENTS_OPT",
    "ARGUMENTS",
    "BRACKETS_OPT",
    "CREATOR",
    "INNER_CREATOR",
    "ARRAY_CREATOR_REST",
    "CLASS_CREATOR_REST",
    "VARIABLE_INITIALIZER",
    "PAR_EXPRESSION",
    "BLOCK",
    "BLOCK_BODY",
    "BLOCK_STATEMENTS",
    "BLOCK_STATEMENT",
    "LOCAL_VARIABLE_DECLARATION_STATEMENT",
    "STATEMENT",
    "FOR_INIT",
    "FOR_UPDATE",
    "FOR_INIT_OPT",
    "FOR_UPDATE_OPT",
    "MODIFIERS_OPT",
    "MODIFIER",
    "MODIFIERS",
    "VARIABLE_DECLARATOR_REST",
    "VARIABLE_DECLARATOR",
    "VARIABLE_DECLARATOR_ID",
    "COMPILER_UNIT",
    "PACKAGE_DECLARATION",
    "IMPORT_DECLARATIONS_OPT",
    "IMPORT_DECLARATIONS",
    "TYPE_DECLARATIONS_OPT",
    "IMPORT_DECLARATION",
    "TYPE_DECLARATION",
    "CLASS_OR_INTERFACE_DECLARATION",
    "CLASS_DECLARATION",
    "INTERFACE_DECLARATION",
    "TYPE_LIST",
    "CLASS_BODY",
    "INTERFACE_BODY",
    "CLASS_BODY_DECLARATIONS",
    "CLASS_BODY_DECLARATION",
    "MEMBER_DECLARATION",
    "METHOD_OR_FIELD_DECLARATION",
    "METHOD_OR_FIELD_REST",
    "INTERFACE_BODY_DECLARATIONS",
    "INTERFACE_BODY_DECLARATION",
    "INTERFACE_MEMBER_DECLARATION",
    "INTERFACE_METHOD_OR_FIELD_DECLARATION",
    "INTERFACE_METHOD_OR_FIELD_REST",
    "METHOD_DECLARATOR_REST",
    "INTERFACE_METHOD_DECLARATOR_REST",
    "CONSTRUCTOR_DECLARATOR_REST",
    "QUALIFIED_IDENTIFIER_LIST",
    "FORMAL_PARAMETERS",
    "FORMAL_PARAMETER_LIST",
    "FORMAL_PARAMETER",
    "METHOD_BODY",
};


string getSymbolName(unsigned int value){
    return NT_SYMBOL_STR[value - START_SYMBOL];
}

void printParseTree(ParseTreeNode *t, size_t spaces){
    SymbolType type = getSymbolType(t->symbol);
    if (type == TERMINAL_TYPE){
        for (size_t i = 0; i < spaces;i++){
            cout << " ";
        }
        if (t->token != NULL){
            printToken(*t->token);
        }
        else{
            switch (t->symbol){
                case START_TERMINAL: 
                    cout << "START_TERMINAL" << endl;
                    break;
                case END_TERMINAL: 
                    cout << "END_TERMINAL" << endl;
                    break;
                }
        }
    }
    else{
        for (size_t i = 0; i < spaces;i++){
            cout << " ";
        }
        cout << getSymbolName(t->symbol) << endl;
        for (ParseTreeNode* child: t->children){
            printParseTree(child, spaces + 1);
        }
    }
}

void printParseTree(ParseTreeNode *t){
    if (t!=NULL){
        printParseTree(t, 0);
    }
    cout << "Tree is NULL" << endl;
};