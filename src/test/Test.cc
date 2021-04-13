#include "Test.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <assert.h>
#include <filesystem>
#include <algorithm>

using namespace std;

const string CHECKMARK = "\u2714";
const string XMARK = "\u2718";

using namespace std;

vector<string> ls(const string& path){
	vector<string> paths;
	for (const auto & entry : filesystem::directory_iterator(path)){
		paths.push_back(entry.path());
	}
	sort(paths.begin(), paths.end());
	return paths;
}

string load(const string& file){

    assert(filesystem::exists(file));

    ifstream ts(file);
    stringstream buffer;
    buffer << ts.rdbuf();
    return buffer.str();
}



void printPassMsg(const string& name, bool printPass){
    if (printPass){
        cout << "| Test: " << name << " " << CHECKMARK << endl;
    }
}

void printCompileFailMsg(const string& name, int result, int expect){
    cout << "| Test: " << name << " " << XMARK << " (compile)";
    cout << " got \'" << result << "\', expected \'" << expect << "\'"<< endl;
}

void printLinkAssembleFailMsg(const string& name){
    cout << "| Test: " << name << " " << XMARK << " (link and assemble)";
}

void printRuntimeReturnCodeFailMsg(const string& name, int result, int expect){
    cout << "| Test: " << name << " " << XMARK << " (runtime return code)";
    cout << " got \'" << result << "\', expected \'" << expect << "\'"<< endl;
}

void printRuntimeOutputFailMsg(const string& name, const string& result, const string& expect){
    cout << "| Test: " << name << " " << XMARK << " (runtime output)";
    cout << " got \'" << result << "\', expected \'" << expect << "\'"<< endl;
}

bool runIOTest(const string& testName,
               const vector<string>& testSourceFiles, 
               const vector<string>& libSourceFiles,
               const vector<string>& libAssemblyFiles,
               int expect, 
               bool runCode,
               string expectFile,
               bool printPass){
    
    if (!runCode){
        assert(expectFile == "");
    }

    if (runCode){
        system("rm -rf output");
        system("mkdir output");
    }

    // build the command
    string command = "./joosc ";
    for (const string& s: testSourceFiles){
        command += s + " ";
    }
    for (const string& s: libSourceFiles){
        command += s + " ";
    }

    // compile
    int result = system(command.c_str());
    result = WEXITSTATUS(result);
    bool compilePass = (result == expect);

    if (!compilePass){
        printCompileFailMsg(testName, result, expect);
        return false;
    }

    if (expect == 42 || !runCode){
        printPassMsg(testName, printPass);
        return true;
    }

    // run code
    for (const auto&f: libAssemblyFiles){
       system(("cp " + f + " output/").c_str());
    }
    auto files = ls("output");
    for (const auto& f: files){
        result = system(("/u/cs444/bin/nasm -O1 -f elf -g -F dwarf " + f).c_str());
        if (WEXITSTATUS(result) != 0)
        {
            printLinkAssembleFailMsg(testName);
            cout << f << " filed to assemble" << endl;
            throw;
        }
    }
    result = system("ld -melf_i386 -o output/main output/*.o");
    if (WEXITSTATUS(result) != 0)
    {
        printLinkAssembleFailMsg(testName);
        cout << " failed to link" << endl;
        throw;
    }

    result = system("./output/main > output/out.txt");
    if (WEXITSTATUS(result) != 123)
    {
        printRuntimeReturnCodeFailMsg(testName, WEXITSTATUS(result), 123);
        return false;
    }
    //system("echo -n \"Hello, World!\n\" > output/out.txt");


    if (expectFile == ""){
        printPassMsg(testName, printPass);
        return true;
    }

    auto outStr = load("output/out.txt");
    auto expectStr = load(expectFile);

    if (outStr != expectStr){
        printRuntimeOutputFailMsg(testName, outStr, expectStr);
        return false;
    }

    printPassMsg(testName, printPass);
    return true;
}
