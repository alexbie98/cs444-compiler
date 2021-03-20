#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <filesystem>
#include "Tokenize.h"
#include "Parser.h"
#include "Weeder.h"
#include "ASTBuilder.h"
#include "NameResolution.h"
#include "HierarchyCheck.h"
#include "StaticAnalysis.h"

using namespace std;

void test_preprocess();
void test_munch();

int main(int argc, char *argv[])
{
    // cout << "Running joosc ..." << endl;

    // If last argument is "v", print full output
    bool verbose = argc > 2 && std::string(argv[argc-1]) == std::string("v");
    if(verbose) argc--;

    std::vector<ASTNode*> asts;

    for(size_t i = 1; i < argc; i++)
    {
        char* filename = argv[i];

        ifstream ts(filename);
        stringstream buffer;
        buffer << ts.rdbuf();
        string text = buffer.str();

        //test_preprocess();

        preprocess(text);
        vector<Token> tokens = munch(text);

        if (verbose){
            for (const auto & t: tokens) {
                printToken(t);
            }
            cout << "-----------------------------------" << endl;
        }

        postprocess(tokens);
        if (verbose){
            for (const auto & t: tokens) {
                printToken(t);
            }
            cout << "-----------------------------------" << endl;
        }

        const string &fileName = filesystem::path(filename).stem().string();
        ParseTreeNode *t = parse(tokens);

        if (verbose){
            printParseTree(t);
            cout << "-----------------------------------" << endl;
        }
        
        if (t == NULL){
            cout << "failed to parse program" << endl;
            exit(42);
        }

        map<string,string> context;
        context["fileName"] = fileName;

        weed(t, context);

        asts.push_back(buildAST(t));

        if (verbose)
        {
            printAST(asts.back());
        }
        setParents(asts.back());
    }

    removeDuplicateImports(asts);
    
    Environment globalEnv = resolveNames(asts);

    // Perform reachability analysis
    ReachabilityVisitor reachability_visitor;
    for (ASTNode* ast : asts) ast->visitAll(reachability_visitor);

    if (verbose){
        printEnvironment(globalEnv);
        cout << "---------------------------------------" << endl;
    }

    // clean up extras in environment
    for (auto it: globalEnv.extras){
        delete it.second;
    }

    return 0;
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