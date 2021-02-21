#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Tokenize.h"

using namespace std;

int main(int argc, char *argv[])
{
    // cout << "Running joosc ..." << endl;

    assert(argc == 2);

    ifstream t(argv[1]);
    stringstream buffer;
    buffer << t.rdbuf();
    const string s = buffer.str();
    cout << s << endl;
}

void test_munch(){

    std::string s = "11 0011111111011011    0011";
    std::vector<Token> tokens = munch(s);

    for (const auto & t: tokens) {
        std::cout << t.first << "  " << t.second << std::endl;
    }
}