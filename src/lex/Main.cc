
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include "RegexProcessor.h"
#include "FA.h"

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](char c) { return !std::isspace(c); }));
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](char c) { return !std::isspace(c); }).base(), s.end());
}

static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

int main(int argc, char** argv) {
    std::cout << "Running lex ..." << std::endl;

    if(argc != 3)
    {
        std::cout << "ERROR: Insufficient number of arguments provided, requires <lex_file> <output_file>" << std::endl;
        return 1;
    }

    std::cout << "Using lex file " << argv[1] << " and outputting to " << argv[2] << std::endl;

    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]); 

    // Copy beginning to output
    std::string line;
    while(std::getline(in, line) && line != "%%")
    {
        out << line << std::endl;
    }

    RegexProcessor regex_processor;
    std::vector<std::pair<RegexNode, std::string>> rules;

    // Process rules
    // '\t' seperates patterns from actions
    std::string pattern;
    std::string action;
    while(std::getline(in, line))
    {
        if(line.empty()) continue;

        std::string::size_type tab_pos = line.find('\t');

        if(tab_pos == std::string::npos)
        {
            std::cout << "ERROR: Malformed rule \"" << line << "\" provided without tab separator" << std::endl;
            return 1;
        }

        pattern = line.substr(0, tab_pos);

        action = line.substr(tab_pos+1);
        trim(action);

        if(action.empty())
        {
            std::cout << "ERROR: Pattern \"" << pattern << "\" provided without action" << std::endl;
            return 1;
        }
        
        rules.emplace_back(regex_processor.process(pattern), action);
    }

    // TODO Convert RegexNodes to DFAs
    for(auto &it: rules)
    {
        it.first.print();
        std::cout << it.second << std::endl;
    }

    // Create an NFA that OR's together all the nfas and attaches rules to the accepting states
    NFA nfa = RegexNodeToNFA(&rules[0].first);
    populateRules(nfa, 0);
    for(size_t i = 1; i < rules.size(); i++)
    {
        NFA new_nfa = RegexNodeToNFA(&rules[i].first);
        populateRules(new_nfa, i);
        nfa = orNFA(nfa, new_nfa);
    }

    // printNFA(RegexNodeToNFA(&rules[0].first));
    // printNFA(nfa);
    // printNFA(NFAToDFA(nfa));

    generateWorkingDFA(NFAToDFA(nfa), rules, out);

    out.close();
}

// ((test\\?)|(1?)*)+[a-zV0-9]	  A
// a|(b[^a-b][ \t\n])*	              B
