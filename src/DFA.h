#pragma once

#include <string>
#include <tuple>

enum TokenType
{   
    // WHITESPACE ---------------------

    LINE_TERMINATOR,
    INLINE_WS,

    // COMMENT ------------------------

    COMMENT,

    // KEYWORDS -----------------------

    // control flow
    IF,
    ELSE,
    WHILE,
    FOR,
    
    // class
    CLASS,
    EXTENDS,
    IMPLEMENTS,
    INTERFACE,
    THIS,
    INSTANCEOF,

    // modifier
    STATIC,
    PUBLIC,
    PRIVATE,
    PROTECTED,
    ABSTRACT,
    FINAL,
    NATIVE,

    // packages
    PACKAGE,
    IMPORT,

    // method
    RETURN,
    VOID,

    // types
    INT,
    BOOLEAN,
    CHAR,
    BYTE,
    SHORT,
    ARRAY,

    // LITERALS ----------------------

    INT_LIT,
    BOOLEAN_LIT,
    NULL_LIT,
    CHAR_LIT,
    STRING_LIT,

    // SEPARATORS --------------------

    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    LBRACKET,
    RBRACKET,
    SEMICOLON,
    COMMA,
    DOT,

    // OPERATORS ----------------------

    PLUS,
    SUB,
    MUL,
    DIV,
    MOD,
    INCR,
    DECR,
    EQ,
    LT,
    GT,
    OR,
    AND,
    EAGER_OR,
    EAGER_AND,

    // IDENTIFIER ----------------------
    ID,

    // REJECT (not an actual token, produced when there is not prefix match) --------------------------

    REJECT
};


/**
 * Runs DFA on s.substr(start)
 * 
 * @param start starting index in s
 * @param s program text
 * @return (tokenType, i) of longest prefix match. i-1 is last index of the match. Otherwise produce (-1. REJECT).
 */
const std::pair<TokenType, long> longestPrefixRecognize(size_t start, const std::string &s);
