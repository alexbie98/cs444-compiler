#pragma once

#include <string>
#include <set>

enum TokenType
{
    // WHITESPACE ------------------
    WS,
    // COMMENT ---------------------
    COMMENT,
    // SEPARATOR -------------------
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    LBRACKET,
    RBRACKET,
    SEMICOLON,
    COMMA,
    DOT,
    // KEYWORDS --------------------
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
    NEW,
    // modifier
    STATIC,
    PUBLIC,
    PRIVATE,
    PROTECTED,
    ABSTRACT,
    FINAL,
    NATIVE,
    // package
    PACKAGE,
    IMPORT,
    // method
    RETURN,
    VOID,
    // type
    INT,
    BOOLEAN,
    CHAR,
    BYTE,
    SHORT,
    ARRAY,
    // UNSUPPORTED KEYWORDS -----------
    // modifier
    CONST,
    STRICTFP,
    SYNCHRONIZED,
    TRANSIENT,
    VOLATILE,
    // type
    DOUBLE,
    FLOAT,
    LONG,
    // exception
    CATCH,
    FINALLY,
    THROW,
    THROWS,
    TRY,
    // class
    SUPER,
    // control flow
    BREAK,
    CASE,
    CONTINUE,
    DEFAULT,
    DO,
    GOTO,
    SWITCH,
    // LITERAL ---------------
    BOOLEAN_LIT,
    NULL_LIT,
    CHAR_LIT,
    STRING_LIT,
    INT_LIT,
    // OPERATOR --------------
    ASSIGN,
    GT,
    LT,
    NOT,
    BITWISE_NOT,  // unsupported
    TERNARY_IF,   // unsupported
    TERNARY_ELSE, // unsupported
    EQ,
    LEQ,
    GEQ,
    NEQ,
    AND,
    OR,
    INCR, // unsupported
    DECR, // unsupported
    PLUS,
    MINUS,
    MULT,
    DIV,
    EAGER_AND,
    EAGER_OR,
    XOR,
    REMAINDER,
    LSHIFT,                 // unsupported
    RSHIFT,                 // unsupported
    UNSIGNED_RSHIFT,        // unsupported
    PLUS_ASSIGN,            // unsupported
    MINUS_ASSIGN,           // unsupported
    MULT_ASSIGN,            // unsupported
    DIV_ASSIGN,             // unsupported
    BITWISE_AND_ASSIGN,     // unsupported
    BITWISE_OR_ASSIGN,      // unsupported
    BITWISE_XOR_ASSIGN,     // unsupported
    REMAINDER_ASSIGN,       // unsupported
    LSHIFT_ASSIGN,          // unsupported
    RSHIFT_ASSIGN,          // unsupported
    UNSIGNED_RSHIFT_ASSIGN, // unsupported
    // IDENTIFIER ------------
    ID,
    // TERMINALS USED FOR PARSING
    START_TERMINAL,
    END_TERMINAL,
    // REJECT (not an actual token, produced when there is not prefix match) --------------
    REJECT,

    COUNT // keep track of enum size
};
// A Token is a (TokenType, Lexeme) pair
typedef std::pair<TokenType, std::string> Token;

extern const std::string TOKEN_TYPE_STR[];

bool isUnsupported(const TokenType &t);
