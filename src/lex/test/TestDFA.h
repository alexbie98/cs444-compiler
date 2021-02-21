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
    REJECT
};

const std::pair<TokenType, long> longestPrefixRecognize(size_t start, const std::string &s);
