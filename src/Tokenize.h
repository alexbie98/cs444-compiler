#ifndef TOKENIZE_H
#define TOKENIZE_H

#include "DFA.h"
#include <vector>
#include <string>

// A Token is a (TokenType, Lexeme) pair
typedef std::pair<TokenType, std::string> Token;

const std::vector<Token> munch(const std::string &s);

#endif