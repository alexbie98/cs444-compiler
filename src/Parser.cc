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
                symbolStack.back()->parent = node;
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
                //printParseTree(node);
                delete node;
            }
            cout << "Look Ahead: " << getSymbolName(node->symbol) << endl;
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
    "NAME",
    "SIMPLE_NAME",
    "QUALIFIED_NAME",
    "LITERAL",
    "TYPE",
    "REFERENCE_TYPE",
    "BASIC_TYPE",
    "NAMED_TYPE",
    "ARRAY_TYPE",
    "TYPE_LIST",
    "COMPILER_UNIT",
    "PACKAGE_DECLARATION",
    "IMPORT_DECLARATIONS_OPT",
    "IMPORT_DECLARATIONS",
    "IMPORT_DECLARATION",
    "TYPE_DECLARATION_OPT",
    "TYPE_DECLARATION",
    "MODIFIERS_OPT",
    "MODIFIERS",
    "MODIFIER",
    "CLASS_DECLARATION",
    "EXTENDS_OPT",
    "INTERFACES_OPT",
    "CLASS_BODY",
    "CLASS_BODY_DECLARATIONS",
    "CLASS_BODY_DECLARATION",
    "CLASS_MEMBER_DECLARATION",
    "FIELD_DECLARATION",
    "METHOD_DECLARATION",
    "METHOD_SIGNATURE",
    "CONSTRUCTOR_DECLARATION",
    "INTERFACE_DECLARATION",
    "INTERFACE_EXTENDS_OPT",
    "INTERFACE_BODY",
    "INTERFACE_BODY_DECLARATIONS",
    "INTERFACE_BODY_DECLARATION",
    "INTERFACE_METHOD_DECLARATION",
    "FORMAL_PARAMETERS",
    "FORMAL_PARAMETERS_OPT",
    "FORMAL_PARAMETER_LIST",
    "FORMAL_PARAMETER",
    "BLOCK",
    "BLOCK_BODY",
    "BLOCK_STATEMENTS",
    "BLOCK_STATEMENT",
    "LOCAL_VARIABLE_DECLARATION_STATEMENT",
    "LOCAL_VARIABLE_DECLARATION",
    "STATEMENT",
    "OPEN_STATEMENT",
    "CLOSED_STATEMENT",
    "PAR_EXPRESSION",
    "EXPRESSION_OPT",
    "STATEMENT_EXPRESSION",
    "FOR_INIT_OPT",
    "FOR_INIT",
    "FOR_UPDATE_OPT",
    "FOR_UPDATE",
    "PRIMARY",
    "PRIMARY_NO_NEW_ARRAY",
    "CLASS_INSTANCE_CREATION_EXPRESSION",
    "ARRAY_CREATION_EXPRESSION",
    "ARRAY_CREATOR_REST",
    "CLASS_CREATOR_REST",
    "ARGUMENTS_OPT",
    "ARGUMENTS",
    "EXPRESSION_LIST",
    "FIELD_ACCESS",
    "METHOD_CALL",
    "ARRAY_ACCESS",
    "UNARY_EXPRESSION",
    "UNARY_NOT_MINUS",
    "CAST_EXPRESSION",
    "MULTIPLICATIVE_EXPRESSION",
    "ADDITIVE_EXPRESSION",
    "RELATIONAL_EXPRESSION",
    "EQUALITY_EXPRESSION",
    "AND_EXPRESSION",
    "XOR_EXPRESSION",
    "OR_EXPRESSION",
    "EAGER_AND_EXPRESSION",
    "EAGER_OR_EXPRESSION",
    "ASSIGNMENT_EXPRESSION",
    "ASSIGNMENT",
    "EXPRESSION"
};


string getSymbolName(unsigned int value){
    return (value >= NONTERMINAL_TYPE) ? NT_SYMBOL_STR[value - START_SYMBOL] : TOKEN_TYPE_STR[value];
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
    else
    {
        cout << "Tree is NULL" << endl;
    }
};