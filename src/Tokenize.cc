#include <vector>
#include <iostream>
#include "Tokenize.h"
#include "DFA.h"

const std::vector<Token> munch(const std::string &s) {

    std::vector<Token> tokens;
    long i = 0;
    std::pair<TokenType, long> match;
    while (i < s.length()){
        match = longestPrefixRecognize(i, s);
        if (match.second == -1) {
            std::cout << s.substr(i) << std::endl;
            throw 42; // no prefix recognized by DFA
        }
        else {
            tokens.push_back({match.first, s.substr(i, match.second - i)});
            i = match.second;
        }

    }
    return tokens;
}


const std::string preprocess(const std::string &s){
    return s;
}
