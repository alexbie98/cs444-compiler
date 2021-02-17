#include <iostream>
#include "Test.h"

using namespace std;

const string CHECKMARK = "\u2714";
const string XMARK = "\u2718";

bool runIOTest(const string& filePath, const string& name, int expect){

    string command = "./joosc " + filePath;
    int result = system(command.c_str());

    bool passed = result == expect;

    cout << "| " << name;
    if (passed){
        cout << " " << CHECKMARK << endl;
    }
    else{
        cout << " " << XMARK;
        cout << " (got " << result << ", expected " << expect << ")" << endl;
    }

    return passed;
}
