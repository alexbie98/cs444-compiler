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


pair<int,int> runMarmosetTests(const string& path, bool regress = false){
	cout << "| Running marmoset tests at: " << "\'" << path << "\'" << endl;

	auto filePaths = ls(path);
	auto numTests = filePaths.size();

	cout <<"| "<< numTests << " tests(s) in total:" << endl;

	int numPassedTests = 0;

	for (const string &f : filePaths){
		auto fileName = f.substr(f.rfind("/") + 1);
		size_t index = fileName.find("_");

		fileName = fileName.substr(0, fileName.length()-5);

		int expect = fileName[index - 1] == 'e' ? 42 : 0;

		auto passed = runIOTest(f, fileName, expect, regress);

		if (passed){
			numPassedTests++;
		}
	}

	return {numPassedTests, numTests};

}

// TODO Add multi assignment check
int main(int argc, char *argv[]){

	auto paths = ls("assignment_testcases");

	cout << "| Marmoset test cases found at: "<< endl;
	for (const string& path: paths){
		cout << "| " << path << endl;
	}

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

	if (regress)
	{
		for (size_t i = 0; i < current; i++)
		{
			regRes.push_back(runMarmosetTests(paths[i], true));
		}
	}
	auto res = runMarmosetTests(paths[current]);

	for (int i = 0; i <regRes.size(); i++){
		cout << "| " << paths[i] <<" tests complete: " << regRes[i].first << "/" << regRes[i].second << " passed" << endl;
	}
	cout << "| " << paths[current] <<" tests complete: " << res.first << "/" << res.second << " passed" << endl;
}

