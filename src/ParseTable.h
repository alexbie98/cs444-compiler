#pragma once

#include <vector>
#include <utility>

using Production = std::pair<int, std::vector<int>>;

extern const Production PRODUCTIONS[];

enum SymbolType
{
    TERMINAL_TYPE = 0,
    NONTERMINAL_TYPE = TokenType::COUNT
};

enum NonterminalSymbols
{
    START_SYMBOL = SymbolType::NONTERMINAL_TYPE,

};

constexpr SymbolType getSymbolType(unsigned int value)
{
    return (value > NONTERMINAL_TYPE) ? NONTERMINAL_TYPE : TERMINAL_TYPE;
}

int stateShift(int currState, int symbol);
int stateReduce(int currState, int symbol);