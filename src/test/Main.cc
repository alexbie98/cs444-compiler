#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>

#include "Test.h"
#include "LexTest.h"

using namespace std;

vector<string> ls(const string& path){
	vector<string> paths;
	for (const auto & entry : filesystem::directory_iterator(path)){
		paths.push_back(entry.path());
	}
	sort(paths.begin(), paths.end());
	return paths;
}

vector<string> getSourceFiles(const string& path){
	vector<string> sourceFiles;

	if (filesystem::is_directory(path)){
		auto children = ls(path);
		for (const string& c: children){
			auto childSourceFiles = getSourceFiles(c);
			sourceFiles.insert(sourceFiles.end(), childSourceFiles.begin(), childSourceFiles.end());
		}
	}
	else{
		if (path.substr(path.length()-5, 5) == ".java"){
			sourceFiles.push_back(path);
		}
	}
	return sourceFiles;
}


pair<int,int> runMarmosetTests(const string& path, const string& libPath, bool regress = false){
	cout << "| Running marmoset tests at: " << "\'" << path << "\'" << endl;

	vector<string> libSourceFiles;
	if (libPath != "")
	{
		cout << "| Using stdlib at: " << "\'" << libPath << "\'" << endl;
		libSourceFiles = getSourceFiles(libPath);
	}
	else{
		cout << "| Not using any stdlib" << endl;
	}

	auto testPaths = ls(path);
	auto numTests = testPaths.size();
	cout <<"| "<< numTests << " tests(s) in total:" << endl;
	
	int numPassedTests = 0;
	for (const string &t : testPaths){
		auto testName = t.substr(t.rfind("/") + 1);
		size_t index = testName.find("_");
		int expect = testName[index - 1] == 'e' ? 42 : 0;

		auto passed = runIOTest(testName, getSourceFiles(t), libSourceFiles, expect, regress);

		if (passed){
			numPassedTests++;
		}
	}

	return {numPassedTests, numTests};

}

void runUnitTests(){
	// run lex unit tests
	cout << "| Running lex tests" << endl;
	runLexTests();
}


// TODO Add multi assignment check
int main(int argc, char *argv[]){

	auto paths = ls("assignment_testcases");
	cout << "| Marmoset test cases found at: "<< endl;
	for (const string& path: paths){
		cout << "| " << path << endl;
	}

	auto libPaths = ls("stdlib");
	cout << "| Java Standard Library found at: "<< endl;
	for (const string& path: libPaths){
		cout << "| " << path << endl;
	}
	libPaths.insert(libPaths.begin(), libPaths[0]);
	//libPaths.insert(libPaths.begin(), "");

	assert(argc <= 2);
	size_t current = 1;
	bool regress = false;
	if (argc == 2)
	{
		if (argv[1][0] == 'a' && (argv[1][2] == 0 || (argv[1][2] == 'r' && argv[1][3] == 0)))
		{
			current = argv[1][1] - '1';
			regress = ('r' == argv[1][2]);
		}
	}

	vector<pair<int, int>> regRes;

	if (regress){

		cout << "| Running unit tests" << endl;
		runUnitTests();

		for (size_t i = 0; i < current; i++)
		{
			regRes.push_back(runMarmosetTests(paths[i], libPaths[i], true));
		}
	}
	auto res = runMarmosetTests(paths[current], libPaths[current]);

	for (int i = 0; i <regRes.size(); i++){
		cout << "| " << paths[i] <<" tests complete: " << regRes[i].first << "/" << regRes[i].second << " passed" << endl;
	}
	cout << "| " << paths[current] <<" tests complete: " << res.first << "/" << res.second << " passed" << endl;
}

