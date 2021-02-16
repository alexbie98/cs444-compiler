#include <iostream>
#include "Test.h"

using namespace std;

const string CHECKMARK = "\u2714";
const string XMARK = "\u2718";

bool runIOTest(const string& filePath, const string& name, int expect){
    cout << "| " << name;

    int result = 0;
    bool passed = result == expect;

    if (passed){
        cout << " " << CHECKMARK << endl;
    }
    else{
        cout << " " << XMARK;
        cout << " (got " << result << ", expected " << expect << ")" << endl;
    }

    return passed;
}
