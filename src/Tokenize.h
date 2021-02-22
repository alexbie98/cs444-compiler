#pragma once

#include "DFA.h"
#include <vector>
#include <string>

// A Token is a (TokenType, Lexeme) pair
typedef std::pair<TokenType, std::string> Token;

const std::vector<Token> munch(const std::string &s);

extern const std::string TOKEN_NAME [];

/**
 * Performs initial preprocessing to the input string
 *  1. convert line endings LF, CR, CRLF -> LF
 * 
 * @param s program text
 * @return new program text after processing
 */
const std::string& preprocess(std::string &s);

void printToken(const Token &t);
