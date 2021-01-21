
#include <iostream>
#include "RegexProcessor.h"

int main() {
    std::cout << "Running lex ..." << std::endl;

    RegexProcessor regex_processor;
    regex_processor.process("((test\\?)|(1?)*)+[a-zV0-9]").print();
    regex_processor.process("a|(b[^a-b])*").print();
}