#include "TestDFA.h"
#include <iostream>

size_t failed = 0;

void test(const std::string& s, TokenType t, size_t & failed)
{
    const std::pair<TokenType, long> result = longestPrefixRecognize(0, s);
    if(result.first == t){
    //    std::cout << "SUCCESS: \"" << s << "\"" << std::endl;
    }
    else
    {
        failed++;
        std::cout << "| FAIL: \"" << s << "\" identified as " << result.first <<  std::endl;
    } 
}

void test(const std::string& s, TokenType t, size_t length, size_t& failed)
{
    const std::pair<TokenType, long> result = longestPrefixRecognize(0, s);
    if(result.first == t && result.second == length) {
        // std::cout << "SUCCESS: \"" << s << "\"" << std::endl;
    }
    else 
    {
        failed++;
        std::cout << "| FAIL: \"" << s << "\" identified as " << result.first << " with length " << result.second << std::endl;
    }
}

void runLexTests() {
    size_t failed = 0;

    // TODO Add more tests

    test("g", A, failed);
    test("xyz", C, failed);
    test("abd", B, failed);
    test("abf", REJECT, failed);
    test("xyzyzyz", C, 7, failed);
    test("kj", D, failed);
    test("gj", D, failed);
    test("hj", REJECT, failed);
    test("ij", REJECT, failed);
    test("gla", E, failed);
    test("glg", E, failed);
    test("gg", A, 1, failed);
    test("mnononoppp", F, 10, failed);
    test("/**/alala", ML_COMMENT, 4, failed);
    test("/*alala*/", ML_COMMENT, 9, failed);
    test("/*alala*/alala*/alala", ML_COMMENT, 9, failed);
    test("*/", REJECT, failed);
    test("tab\ttab", G, failed);
    test(std::string("\n\r\t\v\f\0", 6), ESCAPES, failed);
    test("\"\"", STRING_LIT, failed);
    test("\"alalal\"", STRING_LIT, failed);
    test("\"", REJECT, failed);
    test("AA00", H, failed);
    test("ZZ99", H, failed);
    test("J05A", H, failed);

    if(failed) std::cout << "| "<< failed << " lex tests failed." << std::endl;
    else std::cout << "| All lex tests succeeded!" << std::endl;
}