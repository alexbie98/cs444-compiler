#pragma once

#include "DFA.h"
#include "Tokenize.h"
#include "ParseTable.h"
#include <vector>

struct ParseTreeNode
{
    ~ParseTreeNode();

    unsigned int symbol = 0;
    const Token* token = nullptr; // Terminals will have a corresponding token from the input

    std::vector<ParseTreeNode*> children;
};

ParseTreeNode* parse(const std::vector<Token>& input);

void printParseTree(ParseTreeNode *t);

extern const std::string NT_SYMBOL_STR[];

std::string getSymbolName(unsigned int value);
