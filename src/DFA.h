#ifndef DFA_H
#define DFA_H

#include <string>
#include <tuple>

enum TokenType
{
    ID,
    NUM,
    IF,
    ELSE,
    WS
};


/**
 * Runs DFA on s.substr(start)
 * 
 * @param start starting index in s
 * @param s program text
 * @return (tokenType, i) of longest prefix match. i-1 is last index of the match. Otherwise produce (-1. ID).
 */
const std::pair<TokenType, long> longestPrefixRecognize(const long start, const std::string &s);

#endif