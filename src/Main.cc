#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <assert.h>
#include "Tokenize.h"

using namespace std;

void test_preprocess();
void test_munch();

int main(int argc, char *argv[])
{
    // cout << "Running joosc ..." << endl;

    assert(argc == 2);

    ifstream t(argv[1]);
    stringstream buffer;
    buffer << t.rdbuf();
    string text = buffer.str();

    preprocess(text);

    // test_preprocess();

    
    vector<Token> tokens = munch(text);
    // for (const auto & t: tokens) {
    //     printToken(t);
    // }

    postprocess(tokens);
    for (const auto & t: tokens) {
        printToken(t);
    }

}

void test_preprocess(){
    string text = "\r\nanc\n\n\rasda\n\r\n\n qqq \n\ra\r\n\r";
    preprocess(text);

    assert(text == "\nanc\n\n\nasda\n\n\n qqq \n\na\n\n");

    cout << "preprocess test passed" << endl;

}

void test_munch(){

    string s = "11 0011111111011011    0011";
    vector<Token> tokens = munch(s);

    for (const auto & t: tokens) {
        cout << TOKEN_TYPE_STR[t.first] << "  " << t.second << endl;
    }
}