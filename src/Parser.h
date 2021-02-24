#pragma once

#include "DFA.h"
#include "Tokenize.h"
#include "ParseTable.h"
#include <vector>

struct ParseTreeNode
{
    ~ParseTreeNode();

    unsigned int symbol;
    const Token* token = nullptr; // Terminals will have a corresponding token from the input

    std::vector<ParseTreeNode*> children;
};

ParseTreeNode* parse(const std::vector<Token>& input);