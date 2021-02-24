#include "Parser.h"
#include "ParseTable.h"

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
        inputNodes.emplace_back();
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