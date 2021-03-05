#pragma once

#include <string>
#include <vector>

bool runIOTest(const std::string& testName,
               const std::vector<std::string>& testSourceFiles, 
               const std::vector<std::string>& libSourceFiles,
               int expect, bool regress);

void printTestMsg(const std::string &testName, bool passed, const std::string &result, const std::string &expect);

void printTestMsg(const std::string &testName, bool passed);

