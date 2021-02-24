#pragma once

#include <vector>
#include <utility>
#include "DFA.h"

using Production = std::pair<unsigned int, std::vector<unsigned int>>;

extern const Production PRODUCTIONS[];

enum SymbolType
{
    TERMINAL_TYPE = 0,
    NONTERMINAL_TYPE = TokenType::COUNT
};

enum NonterminalSymbols
{
    START_SYMBOL = SymbolType::NONTERMINAL_TYPE,
    LONG_IDENTIFIER,
    QUALIFIED_IDENTIFIER,
    LITERAL,
    EXPRESSION,
    EXPRESSION1,
    EXPRESSION2,
    EXPRESSION3,
    EXPRESSION1_REST,
    EXPRESSION_INFIX,
    EXPRESSION_LIST,
    EXPRESSION_OPT,
    ASSIGN_OP,
    TYPE,
    BASIC_TYPE,
    STATEMENT_EXPRESSION,
    INFIX_OP,
    PRIMARY,
    SELECTABLE_PRIMARY,
    SELECTOR,
    SELECTORS,
    IDENTIFIER_SUFFIX,
    ARGUMENTS_OPT,
    ARGUMENTS,
    BRACKETS_OPT,
    CREATOR,
    INNER_CREATOR,
    ARRAY_CREATOR_REST,
    CLASS_CREATOR_REST,
    VARIABLE_INITIALIZER,
    PAR_EXPRESSION,
    BLOCK,
    BLOCK_BODY,
    BLOCK_STATEMENTS,
    BLOCK_STATEMENT,
    LOCAL_VARIABLE_DECLARATION_STATEMENT,
    STATEMENT,
    OPEN_STATEMENT,
    CLOSED_STATEMENT,
    FOR_INIT,
    FOR_UPDATE,
    FOR_INIT_OPT,
    FOR_UPDATE_OPT,
    MODIFIERS_OPT,
    MODIFIER,
    MODIFIERS,
    VARIABLE_DECLARATOR_REST,
    VARIABLE_DECLARATOR,
    VARIABLE_DECLARATOR_ID,
    COMPILER_UNIT,
    PACKAGE_DECLARATION,
    IMPORT_DECLARATIONS_OPT,
    IMPORT_DECLARATIONS,
    TYPE_DECLARATIONS_OPT,
    IMPORT_DECLARATION,
    TYPE_DECLARATION,
    CLASS_OR_INTERFACE_DECLARATION,
    CLASS_DECLARATION,
    INTERFACE_DECLARATION,
    TYPE_LIST,
    CLASS_BODY,
    INTERFACE_BODY,
    CLASS_BODY_DECLARATIONS,
    CLASS_BODY_DECLARATION,
    MEMBER_DECLARATION,
    METHOD_OR_FIELD_DECLARATION,
    METHOD_OR_FIELD_REST,
    INTERFACE_BODY_DECLARATIONS,
    INTERFACE_BODY_DECLARATION,
    INTERFACE_MEMBER_DECLARATION,
    INTERFACE_METHOD_OR_FIELD_DECLARATION,
    INTERFACE_METHOD_OR_FIELD_REST,
    METHOD_DECLARATOR_REST,
    INTERFACE_METHOD_DECLARATOR_REST,
    CONSTRUCTOR_DECLARATOR_REST,
    QUALIFIED_IDENTIFIER_LIST,
    FORMAL_PARAMETERS,
    FORMAL_PARAMETERS_OPT,
    FORMAL_PARAMETER_LIST,
    FORMAL_PARAMETER,
    METHOD_BODY,
};

constexpr SymbolType getSymbolType(unsigned int value)
{
    return (value > NONTERMINAL_TYPE) ? NONTERMINAL_TYPE : TERMINAL_TYPE;
}



int stateShift(int currState, int symbol);
int stateReduce(int currState, int symbol);
