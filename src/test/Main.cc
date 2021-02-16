#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include "Test.h"

using namespace std;

vector<string> ls(const string& path){
	vector<string> paths;
	for (const auto & entry : filesystem::directory_iterator(path)){
		paths.push_back(entry.path());
	}
	sort(paths.begin(), paths.end());
	return paths;
}


void runMarmosetTests(const string& path){
	cout << "Running marmoset tests at: " << "\'" << path << "\'" << endl;

	auto filePaths = ls(path);
	auto numTests = filePaths.size();

	cout << numTests << " tests(s) in total:" << endl;

	int numPassedTests = 0;

	for (const string &f : filePaths){
		auto fileName = f.substr(f.rfind("/") + 1);
		size_t index = fileName.find("_");

		auto name = fileName.substr(index + 1, fileName.length()-8);
		int expect = fileName[index - 1] == 'e' ? 42 : 0;

		auto passed = runIOTest(f, name, expect);

		if (passed){
			numPassedTests++;
		}
	}

	cout << "Tests complete: " << numPassedTests << "/" << numTests << " passed" << endl;
}

int main() {

	auto paths = ls("assignment_testcases");

	cout << "Marmoset test cases found at: "<< endl;
	for (const string& path: paths){
		cout << "| " << path << endl;
	}

	// run a1 tests
	runMarmosetTests(paths[0]);
}



