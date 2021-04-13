#pragma once

#include <string>
#include <vector>

bool runIOTest(const std::string &testName,
               const std::vector<std::string> &testSourceFiles,
               const std::vector<std::string> &libSourceFiles,
               const std::vector<std::string> &libAssemblyFiles,
               int expect,
               int runtimeExpect,
               bool runCode,
               std::string expectFile,
               bool printPasses);

std::vector<std::string> ls(const std::string &path);