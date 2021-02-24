#include <iostream>
#include <fstream>
#include <string>
#include "LR1ParseTableGenerator.h"

using namespace std;

int main(int argc, char** argv) {
    cout << "Running Parse Table Generator" << endl;
    
    if (argc != 3)
    {
        cout << "ERROR: Insufficient number of arguments provided, requires <lr1_file> <output_file>" << endl;
        return 1;
    }

    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);

    LR1ParseTable parseTable = generateParseTable(inFile);
    
    cout << "ParseTable Generated" << endl;
    cout << "Outputting to " << argv[2] << endl;

    //string headerName = argv[2];
    //headerName = headerName.substr(0, headerName.find_last_of('.'));

    outFile << "#include \"../src/ParseTable.h\"" << endl;

    outputParseTable(parseTable, outFile);

    outFile.close();

    return 0;
}