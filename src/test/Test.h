#pragma once

#include <string>

bool runIOTest(const std::string& filePath, const std::string& name, int expect);

void printTestMsg(const std::string &name, bool passed, const std::string &result, const std::string &expect);

