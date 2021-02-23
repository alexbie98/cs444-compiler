#include "LR1ParseTableGenerator.h"
#include <sstream>
#include <algorithm>

using namespace std;

LR1ParseTable generateParseTable(istream& input)
{
    LR1ParseTable parseTable;

    unsigned int count;
    string str;

    // Read in terminals
    input >> count;
    for (unsigned int i = 0; i < count; i++)
    {
        input >> str;
        parseTable.terminals.push_back(str);
    }

    // Read in nonterminals
    input >> count;
    for (unsigned int i = 0; i < count; i++)
    {
        input >> str;
        parseTable.nonterminals.push_back(str);
    }

    input >> str;
    parseTable.startSymbol = str;

    // Read in productions
    input >> count;
    input.ignore();
    for (unsigned int i = 0; i < count; i++)
    {
        getline(input, str);
        istringstream strStream(str);
        parseTable.productions.emplace_back();

        string symbol;
        strStream >> symbol;
        parseTable.productions.back().lhs = symbol;

        while (strStream >> symbol)
        {
            parseTable.productions.back().rhs.push_back(symbol);
        }
    }

    // Read in dfa states
    input >> count;
    parseTable.states = count;
    input >> count;

    for (unsigned int i = 0; i < count; i++)
    {
        int state, out;
        string symbol, type;
        input >> state >> symbol >> type >> out;
        
        LR1Action action = make_tuple(state, symbol, out);
        if (type == "shift")
        {
            parseTable.shiftRules.push_back(action);
        }
        else
        {
            parseTable.reduceRules.push_back(action);
        }
    }

    sort(parseTable.shiftRules.begin(), parseTable.shiftRules.end());
    sort(parseTable.reduceRules.begin(), parseTable.reduceRules.end());

    return parseTable;
}

void outputFunctionBody(const vector<LR1Action>& actions, ostream& output)
{
    output << "{" << endl
        << "\tswitch(currState) {" << endl;

    int prevState = -1;
    for (const LR1Action& action : actions)
    {
        if (get<0>(action) != prevState)
        {
            if (prevState >= 0)
            {
                output << "\t\t\t}" << endl
                    << "\t\t\tbreak;" << endl;
            }

            output << "\t\tcase " << get<0>(action) << ":" << endl
                << "\t\t\tswitch(symbol) {" << endl;

            prevState = get<0>(action);
        }

        output << "\t\t\t\tcase " << get<1>(action) << ": return " << get<2>(action) << ";" << endl;
    }
    if (prevState >= 0)
    {
        output << "\t\t\t}" << endl
            << "\t\t\tbreak;" << endl;
    }
    output << "\t}" << endl
        << "\treturn -1;" << endl
        << "}" << endl;
}

void outputParseTable(const LR1ParseTable& parseTable, ostream& output)
{
    // We'll make the assumption that the .h files are already populated with the terminals and non-terminals

    // Populate with rules
    output << "#include <utility>" << endl << endl;

    output << "const Production PRODUCTIONS[] = {" << endl;
    for (ProductionRule rule : parseTable.productions)
    {
        output << "\tstd::make_pair(" << rule.lhs << ", {";
        for (vector<string>::iterator it = rule.rhs.begin(); it != rule.rhs.end(); it++)
        {
            if (it != rule.rhs.begin())
            {
                output << ", ";
            }
            output << *it;
        }
        output << "})," << endl;
    }
    output << "};" << endl << endl;

    // Write out transition actions
    output << "int stateShift(int currState, int symbol)" << endl;
    outputFunctionBody(parseTable.shiftRules, output);
    output << endl;

    output << "int stateReduce(int currState, int symbol)" << endl;
    outputFunctionBody(parseTable.reduceRules, output);
}