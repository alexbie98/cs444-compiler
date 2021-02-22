#include <vector>
#include <iostream>
#include "Tokenize.h"
#include "DFA.h"

using namespace std;

const vector<Token> munch(const string &s) {

    std::vector<Token> tokens;
    long i = 0;
    std::pair<TokenType, long> match;
    while (i < s.length()){
        match = longestPrefixRecognize(i, s);
        if (match.second == -1) {
            cout << s.substr(i) << endl;
            throw 42; // no prefix recognized by DFA
        }
        else {
            tokens.push_back({match.first, s.substr(i, match.second - i)});
            i = match.second;
        }
    }
    return tokens;
}


const string& preprocess(string &s){

    size_t i = 0;
    while (i < s.length()){
        if (s[i] == '\r' && i+1 < s.length() && s[i+1] == '\n'){
            s.erase(i, 1);
        }
        else{
            if (s[i] == '\r'){
                s[i] = '\n';
            }
            i++;
        }
    }
    return s;
}
