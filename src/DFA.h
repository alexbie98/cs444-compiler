#pragma once

#include <string>
#include <tuple>
#include "Token.h"

/**
 * Runs DFA on s.substr(start)
 * 
 * @param start starting index in s
 * @param s program text
 * @return (tokenType, i) of longest prefix match. i-1 is last index of the match. Otherwise produce (-1. REJECT).
 */
const std::pair<TokenType, long> longestPrefixRecognize(size_t start, const std::string &s);
