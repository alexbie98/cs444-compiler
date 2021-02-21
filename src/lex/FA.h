#pragma once

#include "RegexProcessor.h"
#include <vector>
#include <tuple>
#include <fstream>
#include <limits>
#include <string>

enum class TransitionType
{
    EPSILON,
    CHAR,
    NOT_CHAR,
    ANY
};

using Transition = std::tuple<TransitionType, char, size_t>;
const size_t NO_RULE = std::numeric_limits<size_t>::max();

struct NFANode
{
    bool accept = false;
    std::vector<Transition> transitions;
    size_t rule = NO_RULE;

    NFANode(){};
    NFANode(bool accept): accept{accept} {};
    NFANode& operator=(const NFANode &src) = default;
    ~NFANode() = default;
};

// States are identified by their index in the vector
using NFA = std::vector<NFANode>;
    
NFA RegexNodeToNFA(const RegexNode* rnode);

// Add new_base to all transition destinations
void rebaseNFA(NFA& nfa, size_t new_base);

// Makes copy to modify internally
NFA NFAToDFA(NFA nfa);

void printNFA(const NFA& nfa);

void generateWorkingDFA(const NFA& dfa, const std::vector<std::pair<RegexNode, std::string>>& rules, std::ofstream& out);

void populateRules(NFA& nfa, int rule);

NFA orNFA(NFA& a, NFA& b);
