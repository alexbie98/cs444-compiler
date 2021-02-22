#include "TestDFA.h"
#include <iostream>

size_t failed = 0;

void test(const std::string& s, TokenType t)
{
    const std::pair<TokenType, long> result = longestPrefixRecognize(0, s);
    if(result.first == t) std::cout << "SUCCESS: \"" << s << "\"" << std::endl;
    else
    {
        failed++;
        std::cout << "FAIL: \"" << s << "\" identified as " << result.first <<  std::endl;
    } 
}

void test(const std::string& s, TokenType t, size_t length)
{
    const std::pair<TokenType, long> result = longestPrefixRecognize(0, s);
    if(result.first == t && result.second == length) std::cout << "SUCCESS: \"" << s << "\"" << std::endl;
    else 
    {
        failed++;
        std::cout << "FAIL: \"" << s << "\" identified as " << result.first << " with length " << result.second << std::endl;
    }
}

int main(int argc, char** argv) {
    // TODO Add more tests
    test("g", A);
    test("xyz", C);
    test("abd", B);
    test("abf", REJECT);
    test("xyzyzyz", C, 7);
    test("kj", D);
    test("gj", D);
    test("hj", REJECT);
    test("ij", REJECT);
    test("gla", E);
    test("glg", E);
    test("gg", A, 1);
    test("mnononoppp", F, 10);
    test("/**/alala", ML_COMMENT, 4);
    test("/*alala*/", ML_COMMENT, 9);
    test("/*alala*/alala*/alala", ML_COMMENT, 9);
    test("*/", REJECT);
    test("tab\ttab", G);
    test(std::string("\n\r\t\v\f\0", 6), ESCAPES);
    test("\"\"", STRING_LIT);
    test("\"alalal\"", STRING_LIT);
    test("\"", REJECT);
    test("AA00", H);
    test("ZZ99", H);
    test("J05A", H);

    if(failed) std::cout << failed << " tests failed." << std::endl;
    else std::cout << "All tests succeeded!" << std::endl;
}