#include <iostream>
#include <string>
#include "Tokenize.h"

void test_munch();

int main() {
    std::cout << "Running joosc ..." << std::endl;

    test_munch();
}

void test_munch(){

    std::string s = "11 0011111111011011    0011";
    std::vector<Token> tokens = munch(s);

    for (const auto & t: tokens) {
        std::cout << t.first << "  " << t.second << std::endl;
    }
}