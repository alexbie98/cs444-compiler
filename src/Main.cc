#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
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

    const string& processedText = preprocess(text);

    cout << processedText << endl;

    test_preprocess();
}

void test_preprocess(){
    string text = "\r\nanc\n\n\rasda\n\r\n\n qqq \n\ra\r\n\r";
    const string& processedText = preprocess(text);

    assert(processedText == "\nanc\n\n\nasda\n\n\n qqq \n\na\n\n");

    cout << "preprocess test passed" << endl;

}

void test_munch(){

    string s = "11 0011111111011011    0011";
    vector<Token> tokens = munch(s);

    for (const auto & t: tokens) {
        cout << t.first << "  " << t.second << endl;
    }
}