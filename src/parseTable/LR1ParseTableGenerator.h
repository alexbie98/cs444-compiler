#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <iostream>

using LR1Action = std::tuple<int, std::string, int>;

struct ProductionRule
{
    std::string lhs;
    std::vector<std::string> rhs;
};

struct LR1ParseTable
{
    std::vector<std::string> terminals;
    std::vector<std::string> nonterminals;
    std::vector<ProductionRule> productions;
    int states;
    std::string startSymbol;
    std::vector<LR1Action> shiftRules;
    std::vector<LR1Action> reduceRules;
};

LR1ParseTable generateParseTable(std::istream& input);

void outputParseTable(const LR1ParseTable& parseTable, std::ostream& output);