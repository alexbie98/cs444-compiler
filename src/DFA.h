#ifndef DFA_H
#define DFA_H

#include <string>
#include <tuple>

enum TokenType
{   
    WS,
    // control flow
    IF,
    ELSE,
    WHILE,
    FOR,
    // literals
    INT_LIT,
    BOOL_LIT,
    NULL_LIT,
    THIS_EXPR,
    // CHAR_LIT,
    // STRING_LIT,
    // CHAR_ESC
    ID,
    // comments
    COMMENT,
    
    IMPLEMENTS,
    REJECT
};


/**
 * Runs DFA on s.substr(start)
 * 
 * @param start starting index in s
 * @param s program text
 * @return (tokenType, i) of longest prefix match. i-1 is last index of the match. Otherwise produce (-1. ID).
 */
const std::pair<TokenType, long> longestPrefixRecognize(size_t start, const std::string &s);

#endif