#pragma once

#include <utility>
#include <string>

enum TokenType
{
    A = 0, 
    B, 
    C, 
    D,
    E,
    F,
    G,
    H,
    ML_COMMENT,
    ESCAPES,
    REJECT, 
    STRING_LIT
};

const std::pair<TokenType, long> longestPrefixRecognize(size_t start, const std::string &s);
