#include <iostream>
#include "Test.h"

using namespace std;

const string CHECKMARK = "\u2714";
const string XMARK = "\u2718";

bool runIOTest(const string& filePath, const string& name, int expect){

    string command = "./joosc " + filePath + " s";
    int result = system(command.c_str());

    bool passed = result == expect;

    // MAKE SURE WE ARENT REJECTING ANYTHING THAT SHOULD BE VALID
    // if (expect == 0 && result == 6){
    //     printTestMsg(name, passed, to_string(result), to_string(expect));
    // }

    printTestMsg(name, passed, to_string(result), to_string(expect));

    return passed;
}

void printTestMsg(const string& name, bool passed, const string& result, const string& expect){
    cout << "| Test: " << name;
    if (passed){
        cout << " " << CHECKMARK << endl;
    }
    else{
        cout << " " << XMARK << endl;
        // cout << "| got \'" << result << "\', expected \'" << expect << "\'"<< endl;
    }
}