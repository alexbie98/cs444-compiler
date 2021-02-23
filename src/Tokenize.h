#pragma once

#include "DFA.h"
#include <vector>
#include <string>
#include "Token.h"

std::vector<Token> munch(const std::string &s);

/**
 * Performs initial preprocessing to the input string
 *  1. convert line endings LF, CR, CRLF -> LF
 *  2. check all input is ASCII 0-127
 * 
 * @param s program text
 */
void preprocess(std::string &s);

/**
 * Performs postprocessing on scanned tokens 
 * 1. filter out WS, COMMENT tokens
 * 2. parse INT_LIT token lexemes and check bounds within [INT_MIN, INT_MAX]
 * 
 * NOTE that for every INT_LIT lexeme L EXCEPT '2147483648', L is within range iff -L is within range
 * We run into a problem for '2147483648' since:
 * 
 * int a = -2147483648;   COMPILES
 * int a = 0-2147483648;  ERROR
 * 
 * so we need the parse tree to understand if - is being used for subtraction or negation.
 * 2147483648 is the sole unhandled INT_LIT
 * 
 * 3. process escape sequences in CHAR_INT and STRING_INT
 */
void postprocess(std::vector<Token>& tokens);

void printToken(const Token &t);
