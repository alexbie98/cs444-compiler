#include <iostream>
#include "Test.h"

using namespace std;

const string CHECKMARK = "\u2714";
const string XMARK = "\u2718";

bool runIOTest(const string& filePath, const string& name, int expect, bool regress){

    string command = "./joosc " + filePath + " s";
    int result = system(command.c_str());
    result = WEXITSTATUS(result);

    bool passed = result == expect;

    if (!regress || !passed){
        printTestMsg(name, passed, to_string(result), to_string(expect));
        cout << "----------------------------------------------------" << endl;
    }

    return passed;
}

void printTestMsg(const string& name, bool passed, const string& result, const string& expect){
    cout << "| Test: " << name;
    if (passed){
        cout << " " << CHECKMARK << endl;
    }
    else{
        cout << " " << XMARK  << " got \'" << result << "\', expected \'" << expect << "\'"<< endl;
    }
}
