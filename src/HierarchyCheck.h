#pragma once

#include <iostream>
#include <set>
#include "ast/ASTNode.h"

void CheckEnvironmentHierarchy(Environment& env);

template <class T>
void printASTNodeMap(const std::unordered_map<std::string, T*>& m) {
    for (const std::pair<std::string, T*>& entry : m){
        std::cout << entry.first << " " << entry.second->toString() << std::endl;
    }
}
void printEnvironment(const Environment &env);

void linkClassHierarchy(ClassDeclaration* classDecl);
void linkInterfaceHierarchy(InterfaceDeclaration* interfaceDecl);