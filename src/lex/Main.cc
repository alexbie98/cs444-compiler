
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include "RegexProcessor.h"

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
    while(std::getline(in, pattern, '\t'))
    {
        if(!std::getline(in, action))
        {
            std::cout << "ERROR: Pattern \"" << pattern << "\" provided without action" << std::endl;
            return 1;
        }
        
        trim(action);
        rules.emplace_back(regex_processor.process(pattern), action);
    }

    // TODO Convert RegexNodes to DFAs
    for(auto &it: rules)
    {
        it.first.print();
        std::cout << it.second << std::endl;
    }

    out.close();
}