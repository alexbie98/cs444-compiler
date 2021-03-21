#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Tokenize.h"
#include <cctype>
#include <cassert>
#include "DFA.h"

using namespace std;

unsigned long LONG_INT_MAX = 2147483647;
unsigned long LONG_UINT_MAX = 0xffffffff;

vector<Token> munch(const string &s) {

    std::vector<Token> tokens;
    long i = 0;
    std::pair<TokenType, long> match;
    while (i < s.length()){
        match = longestPrefixRecognize(i, s);
        //cout << i << " " << TOKEN_NAME[match.first] << " " << match.second << endl;

        if (match.first == REJECT) {
            cout << s.substr(i) << endl;
            exit(42); // no prefix recognized by DFA
        }
        else {
            tokens.push_back({match.first, s.substr(i, match.second - i)});
            i = match.second;
        }
    }
    return tokens;
}


void preprocess(string &s){

    size_t i = 0;
    while (i < s.length()){
        if(!(s[i] >= '\0' && s[i] <= '\177')){
            cout << "non-ascii program text" << endl;
            exit(42);
        }
        if (s[i] == '\r' && i + 1 < s.length() && s[i + 1] == '\n'){
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
    cout << TOKEN_TYPE_STR[t.first] << " " << s << endl;
}

string parseHex(string& s){
    // HEX is unsupported
    exit(42);

    transform(s.begin(), s.end(), s.begin(),
              [](char c) { return tolower(c); });

    unsigned long val = 0;
    for (char c : s){
        val = 16 * val + (('0' <= c && c <= '9') ? (c - '0') : (c - 'a' + 10));
        if (val > LONG_UINT_MAX){
            cout << "Parse hex int exceeds bounds: " << s << endl;
            exit(42);
        }
    }
    return to_string((int) val);
}

string parseOct(const string& s){

    // OCT is unsupported
    exit(42);

    unsigned long val = 0;
    for (char c: s){
        val = 8 * val + (c - '0');
        if (val>LONG_UINT_MAX){
            cout << "Parse oct int exceeds bounds: " << s << endl;
            exit(42);
        }
    }
    return to_string((int) val);
}

string parseDec(const string& s){
    unsigned long val = 0;
    for (char c: s){
        val = 10 * val + (c - '0');
        if (val>LONG_INT_MAX+1){ //  2147483648 could have a preceding -, in which case it is actually
            cout << "Parse decimal int exceeds bounds: " << s << endl;
            exit(42);
        }
    }
    return to_string(val);
}

Token& processToken(Token& t){
    if (t.first == INT_LIT){
        if (t.second.length()>2 && t.second[0]=='0' && (t.second[1] == 'X' || t.second[1]=='x')){
            string hexString = t.second.substr(2);
            t.second = parseHex(hexString);
        }
        else if (t.second[0] == '0' && t.second.length()>1){
            t.second = parseOct(t.second.substr(1));
        }
        else {
            t.second = parseDec(t.second);
        }
    }
    else if (t.first == CHAR_LIT){
        string stripped = t.second.substr(1, t.second.length() - 2);
        if (stripped[0] == '\\'){
            auto [c, l] = processEscape(stripped.substr(1));
            t.second = string{c};
        }
    }
    else if (t.first == STRING_LIT){
        string stripped = t.second.substr(1, t.second.length() - 2);
        vector<char> cs;
        size_t i = 0;
        while (i < stripped.length()){
            if (stripped[i] == '\\'){
                auto [c, l] = processEscape(stripped.substr(i+1));
                cs.push_back(c);
                i += (l + 1);
            }
            else{
                cs.push_back(stripped[i]);
                i++;
            }
        }
        t.second = string{cs.begin(), cs.end()};
    }

    return t;
}
/**
 * prefix: 1 or more characters that follow \ of a valid escape sequence
 * 
 **/
pair<char, size_t> processEscape(const string& prefix){
    char res;
    size_t length = 1;
    //cout << prefix.length() << endl;

    switch (prefix[0]) {
        case 'b': res = '\b'; break;
        case 't': res = '\t'; break;
        case 'n': res = '\n'; break;
        case 'f': res = '\f'; break;
        case 'r': res = '\r'; break;
        case '"': res = '"'; break;
        case '\'': res = '\''; break;
        case '\\': res = '\\'; break;
        default:
            // must be oct
            if (prefix.length() >= 3 && 
                prefix[0]-'0' >= 0 && prefix[0]-'0' <= 3 &&
                prefix[1]-'0' >= 0 && prefix[1]-'0' <= 7 &&
                prefix[2]-'0' >= 0 && prefix[2]-'0' <= 7){

                length = 3;
                res = (char) ((prefix[0] - '0') * 64 + (prefix[1] - '0') * 8 + (prefix[2] - '0'));
                //cout << (int) res << endl;
            }
            else if (prefix.length() >= 2 && 
                prefix[0]-'0' >= 0 && prefix[0]-'0' <= 7 &&
                prefix[1]-'0' >= 0 && prefix[1]-'0' <= 7){

                length = 2;
                res = (char)((prefix[0] - '0') * 8 + (prefix[1] - '0'));
            }
            else if (
                prefix[0]-'0' >= 0 && prefix[0]-'0' <= 7){

                res = (char) (prefix[0] - '0');
            }
            else{
                cout << "unrecognized escape sequence in string/char literal" << endl;
            }
    }
    return {res, length};
}

void postprocess(vector<Token>& tokens){

    for (const Token& t: tokens)
            {
                if (isUnsupported(t.first))
                {
                    cout << "unsupported token ";
                    printToken(t);
                    exit(42);
                }
            }

    // 1. filter WS, COMMENT tokens
    auto it = remove_if(tokens.begin(), tokens.end(),
                        [](const Token &t) { /*cout << TOKEN_TYPE_STR[t.first] << endl;*/return (t.first == WS || t.first == COMMENT); });
    tokens.erase(it, tokens.end());

    transform(tokens.begin(), tokens.end(), tokens.begin(), processToken);
        }
