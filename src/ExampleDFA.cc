#include "DFA.h"

#include <map>
// #include <iostream>

enum DFAState
{   
    START,
    ZERO,
    ONE,
    TWO,
    SPACE,
    REJECT
};

// accepting state -> token type map
const std::map<DFAState, TokenType> STATE_TTYPE = { {ZERO, ELSE}, {SPACE, WS}, {START, ID}};

const std::pair<TokenType, long> longestPrefixRecognize(size_t start, const std::string &s){

    DFAState currentState = START;
    std::pair<TokenType, long> matchSoFar = {ID, -1};
    long i = start;

    // implements binary number divisible by 3 DFA
    for ( ; i<s.length(); i++) {
        switch(currentState){
            case START: 
                switch(s[i]){
                    case '0': currentState = ZERO; break;
                    case '1': currentState = ONE; break;
                    case ' ': currentState = SPACE; break;
                    default: currentState = REJECT;
                }
                break;
            case ZERO: 
                switch(s[i]){
                    case '0': currentState = ZERO; break;
                    case '1': currentState = ONE; break;
                    default: currentState = REJECT;
                }
                break;
            case ONE: 
                switch(s[i]){
                    case '0': currentState = TWO; break;
                    case '1': currentState = ZERO; break;
                    default: currentState = REJECT;
                }
                break;
            case TWO: 
                switch(s[i]){
                    case '0': currentState = ONE; break;
                    case '1': currentState = TWO; break;
                    default: currentState = REJECT;
                }
                break;
            case SPACE: 
                switch(s[i]){
                    case '0': currentState = REJECT; break;
                    case '1': currentState = REJECT; break;
                    case ' ': currentState = SPACE; break;
                    default: currentState = REJECT;
                }
                break;
            case REJECT: break;
        }

        auto lookup = STATE_TTYPE.find(currentState);
        if (lookup != STATE_TTYPE.end()) {
            matchSoFar = {lookup->second, i+1};
        }
        if (currentState == REJECT) {
            break;
        }
    }

    // std::cout << matchSoFar.first << "  " << matchSoFar.second << std::endl;
    return matchSoFar;
}