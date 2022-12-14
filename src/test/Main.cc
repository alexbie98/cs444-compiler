#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <sstream>
#include <fstream>

#include "Test.h"
#include "LexTest.h"

#define PRINT_PASSES false

using namespace std;

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


pair<int,int> runMarmosetTests(const string& path, const string& libPath, bool runCode, bool regress = false){
	cout << "| Running tests at: " << "\'" << path << "\'" << endl;

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
	testPaths.erase(
		remove_if(testPaths.begin(), testPaths.end(),
				  [](const string &p) {
					  return p.substr(p.length() - 4, 4) == ".txt";
				  }),
		testPaths.end()
	);

	auto numTests = testPaths.size();
	cout <<"| "<< numTests << " tests(s) in total:" << endl;

	auto libAssemblyFiles = ls(libPath);
	libAssemblyFiles.erase(
		remove_if(libAssemblyFiles.begin(), libAssemblyFiles.end(),
				  [](const string &p) {
					  if (filesystem::is_directory(p)){
						  return true;
					  }
					  return p.substr(p.length() - 2, 2) != ".s";
				  }),
		libAssemblyFiles.end()
	);

	int numPassedTests = 0;
	for (const string &t : testPaths){
		auto testName = t.substr(t.rfind("/") + 1);
		int expect = testName[1] == 'e' ? 42 : 0;
		int runtimeExpect;
		switch (testName[2])
		{
			case 'e': runtimeExpect = 13; break;
			case 's': runtimeExpect = 139; break;
			default: runtimeExpect = 123; break;
		}

		string expectFile = "";

		if (filesystem::is_directory(t)){
			if (filesystem::exists(t+"/expect.txt")){
				expectFile = t + "/expect.txt";
			}
		}


		auto passed = runIOTest(testName,
								getSourceFiles(t),
								libSourceFiles,
								libAssemblyFiles,
								expect,
								runtimeExpect,
								runCode,
								expectFile,
								!regress && PRINT_PASSES);

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


string get_stdlib(const string& current, const vector<string>& libPaths){
	string lib;

	if (filesystem::exists(current + "/stdlib.txt")){
		ifstream ts(current + "/stdlib.txt");
		stringstream buffer;
		buffer << ts.rdbuf();
		lib = buffer.str();
		if (lib[lib.length()-1] == '\n'){
			lib = lib.substr(0, lib.length() - 1);
		}
		lib = "stdlib/" + lib;
	}
	else{
		auto i = current.rfind("/");
		string ver = current.substr(i + 2);
		ver = ver == "1" ? "2" : ver;
		lib = "stdlib/" + ver + ".0";
	}
	assert(find(libPaths.begin(), libPaths.end(), lib) != libPaths.end());

	return lib;
}

// TODO Add multi assignment check
int main(int argc, char *argv[]){

	auto paths = ls("assignment_testcases");
	cout << "| Assignment test cases found at: "<< endl;
	for (const string& path: paths){
		cout << "| " << path << endl;
	}

	auto custom_paths = ls("custom_testcases");
	cout << "| Custom test cases found at: "<< endl;
	for (const string& path: custom_paths){
		cout << "| " << path << endl;
	}

	auto libPaths = ls("stdlib");
	cout << "| Java Standard Library found at: "<< endl;
	for (const string& path: libPaths){
		cout << "| " << path << endl;
	}
	libPaths.insert(libPaths.begin(), libPaths[0]);

	assert(argc <= 3);
	string current = "a4";
	bool regress = false;
	if (argc == 3)
	{
		assert(string(argv[2])  == "r");
		regress = true;
		cout << "| Running regression tests" << endl;
	}
	if (argc != 1){
		current = argv[1];
	}

	if (find(paths.begin(), paths.end(), "assignment_testcases/" + current) != paths.end())
	{
		current = "assignment_testcases/" + current;
	}
	else if (find(custom_paths.begin(), custom_paths.end(), "custom_testcases/" + current) != custom_paths.end()){
		current = "custom_testcases/" + current;
	}
	else{
		cout << "Provided test suite not found" << endl;
	}

	vector<pair<string, string>> tests;

	if (regress){
		for (auto custom_path : custom_paths)
		{
			cout << current << endl;
			cout << custom_path << endl;
			if (custom_path != current)
			{
				tests.push_back({custom_path, get_stdlib(custom_path, libPaths)});
			}
		}
		if (current[0] == 'a'){
			for (auto path: paths){
				if (path != current){
					tests.push_back({path, get_stdlib(path, libPaths)});
				}
				else{
					break;
				}
			}
		}
	}

	tests.push_back({current, get_stdlib(current, libPaths)});


	vector<pair<int, int>> res;


	for (auto [path, stdlib]: tests)
	{
		bool regress = path != current;
		res.push_back(
			runMarmosetTests(
				path, 
				stdlib,
				true, 
				regress
			)
		);
	}
	
	if (regress){
		cout << "| Running unit tests" << endl;
		runUnitTests();
	}

	for (size_t i = 0; i < tests.size();i++)
	{
		cout << "| " << tests[i].first <<" tests complete: " << res[i].first << "/" << res[i].second << " passed" << endl;
	}

}

