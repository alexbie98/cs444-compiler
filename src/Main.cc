#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <filesystem>
#include "Tokenize.h"
#include "Parser.h"
#include "Weeder.h"

using namespace std;

void test_preprocess();
void test_munch();

int main(int argc, char *argv[])
{
    // cout << "Running joosc ..." << endl;

    ifstream ts(argv[1]);
    stringstream buffer;
    buffer << ts.rdbuf();
    string text = buffer.str();

    //test_preprocess();

    preprocess(text);
    vector<Token> tokens = munch(text);

    if (!(argc > 2 && argv[2][0] == 's')){
        for (const auto & t: tokens) {
            printToken(t);
        }
        cout << "-----------------------------------" << endl;
    }

    postprocess(tokens);
    if (!(argc > 2 && argv[2][0] == 's')){
        for (const auto & t: tokens) {
            printToken(t);
        }
        cout << "-----------------------------------" << endl;
    }

    const string &fileName = filesystem::path(argv[1]).stem().string();
    cout << fileName << endl;
    cout << "----------------------------------------" << endl;

    ParseTreeNode *t = parse(tokens);
    if (!(argc > 2 && argv[2][0] == 's')){
        printParseTree(t);
        cout << "-----------------------------------" << endl;
    }
    //assert(t != NULL);

    // weed(t, fileName);

    // if (!(argc > 2 && argv[2][0] == 's')){
    //     printParseTree(t);
    // }
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