#include <iostream>
#include "Test.h"

using namespace std;

const string CHECKMARK = "\u2714";
const string XMARK = "\u2718";

bool runIOTest(const string& testName,
               const vector<string>& testSourceFiles, 
               const vector<string>& libSourceFiles,
               int expect, bool regress){

    // build the command
    string command = "./joosc ";
    for (const string& s: testSourceFiles){
        command += s + " ";
    }
    for (const string& s: libSourceFiles){
        command += s + " ";
    }
    command += "s";


    int result = system(command.c_str());
    result = WEXITSTATUS(result);

    bool passed = result == expect;

    if (!regress || !passed){
        cout << command << endl; // COMMENT THIS LINE TO STOP PRINTING THE FULL TEST COMMAND
        printTestMsg(testName, passed, to_string(result), to_string(expect));
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
