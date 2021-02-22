#include <vector>
#include <iostream>
#include "Tokenize.h"
#include "DFA.h"

using namespace std;

const string TOKEN_NAME [] = {
    // WHITESPACE ------------------
    "WS",
    // COMMENT ---------------------
    "COMMENT",
    // SEPARATOR -------------------
    "LPAREN",
    "RPAREN",
    "LBRACE",
    "RBRACE",
    "LBRACKET",
    "RBRACKET",
    "SEMICOLON",
    "COMMA",
    "DOT",
    // KEYWORDS --------------------
    // control flow
    "IF",
    "ELSE",
    "WHILE",
    "FOR", 
    // class
    "CLASS",
    "EXTENDS",
    "IMPLEMENTS",
    "INTERFACE",
    "THIS",
    "INSTANCEOF",
    // modifier
    "STATIC",
    "PUBLIC",
    "PRIVATE",
    "PROTECTED",
    "ABSTRACT",
    "FINAL",
    "NATIVE",
    // package
    "PACKAGE",
    "IMPORT",
    // method
    "RETURN",
    "VOID",
    // type
    "INT",
    "BOOLEAN",
    "CHAR",
    "BYTE",
    "SHORT",
    "ARRAY",
    // UNSUPPORTED KEYWORDS -----------
    "CONST",
    "STRICTFP",
    "SYNCHRONIZED",
    "TRANSIENT",
    "VOLATILE",
    "DOUBLE",
    "FLOAT",
    "LONG",
    "CATCH",
    "FINALLY",
    "THROW",
    "THROWS",
    "TRY",
    "NEW",
    "SUPER",
    "BREAK",
    "CASE",
    "CONTINUE",
    "DEFAULT",
    "DO",
    "GOTO",
    "SWITCH",
    // LITERAL ---------------
    "BOOLEAN_LIT",
    "NULL_LIT",
    "CHAR_LIT",
    "STRING_LIT",
    "INT_LIT",
    // OPERATOR --------------
    "ASSIGN",
    "GT",
    "LT",
    "NOT",
    "BITWISE_NOT",  // unsupported
    "TERNARY_IF",   // unsupported
    "TERNARY_ELSE", // unsupported
    "EQ",
    "LEQ",
    "GEQ",
    "NEQ",
    "AND",
    "OR",
    "INCR", // unsupported
    "DECR", // unsupported
    "PLUS",
    "MINUS",
    "MULT",
    "DIV",
    "EAGER_AND",
    "EAGER_OR",
    "XOR",
    "REMAINDER",
    "LSHIFT",                 // unsupported
    "RSHIFT",                 // unsupported
    "UNSIGNED_RSHIFT",        // unsupported
    "PLUS_ASSIGN",            // unsupported
    "MINUS_ASSIGN",           // unsupported
    "MULT_ASSIGN",            // unsupported
    "DIV_ASSIGN",             // unsupported
    "BITWISE_AND_ASSIGN",     // unsupported
    "BITWISE_OR_ASSIGN",      // unsupported
    "BITWISE_XOR_ASSIGN",     // unsupported
    "REMAINDER_ASSIGN",       // unsupported
    "LSHIFT_ASSIGN",          // unsupported
    "RSHIFT_ASSIGN",          // unsupported
    "UNSIGNED_RSHIFT_ASSIGN", // unsupported
    // IDENTIFIER ------------
    "ID",
    // REJECT (not an actual token, produced when there is not prefix match) --------------
    "REJECT"
 };

const vector<Token> munch(const string &s) {

    std::vector<Token> tokens;
    long i = 0;
    std::pair<TokenType, long> match;
    while (i < s.length()){
        match = longestPrefixRecognize(i, s);
        //cout << i << " " << TOKEN_NAME[match.first] << " " << match.second << endl;

        if (match.first == REJECT) {
            cout << s.substr(i) << endl;
            throw 42; // no prefix recognized by DFA
        }
        else {
            tokens.push_back({match.first, s.substr(i, match.second - i)});
            i = match.second;
        }
    }
    return tokens;
}


const string& preprocess(string &s){

    size_t i = 0;
    while (i < s.length()){
        if (s[i] == '\r' && i+1 < s.length() && s[i+1] == '\n'){
            s.erase(i, 1);
        }
        else{
            if (s[i] == '\r'){
                s[i] = '\n';
            }
            i++;
        }
    }
    // add a newline to the end if necessary
    if (s[s.length()-1] != '\n'){
        s.insert(s.length(), "\n");
    }
    return s;
}

void printToken(const Token& t){
    string s = t.second;
    size_t i = 0;
    while (i<s.length()){
        if (s[i] == '\n' || s[i]=='\t' || s[i] == '\f' || s[i] == ' '){
            bool lf = false;

            switch(s[i]){
                case '\n': 
                    s.insert(i+1, "\033[1;33mLF\033[0m");
                    lf = true; break;
                case '\t': 
                    s.insert(i+1, "\033[1;43m\t\033[0m"); break;
                case '\f':
                    s.insert(i+1, "\033[1;43m\f\033[0m"); break;
                case ' ':
                    s.insert(i+1, "\033[1;43m \033[0m"); break;
            }
            s.erase(i, 1);
            i += (12 + (lf ? 1 : 0));

        }
        else{
            i++;
        }
    }
    cout << TOKEN_NAME[t.first] << " " << s << endl;
}