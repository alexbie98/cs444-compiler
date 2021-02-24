#include "../src/ParseTable.h"
#include <utility>
#include <vector>

const Production PRODUCTIONS[] = {
	std::make_pair(START_SYMBOL, std::vector<unsigned int>{START_TERMINAL, COMPILER_UNIT, END_TERMINAL}),
	std::make_pair(LONG_IDENTIFIER, std::vector<unsigned int>{ID}),
	std::make_pair(LONG_IDENTIFIER, std::vector<unsigned int>{LONG_IDENTIFIER, DOT, ID}),
	std::make_pair(QUALIFIED_IDENTIFIER, std::vector<unsigned int>{LONG_IDENTIFIER}),
	std::make_pair(LITERAL, std::vector<unsigned int>{INT_LIT}),
	std::make_pair(LITERAL, std::vector<unsigned int>{CHAR_LIT}),
	std::make_pair(LITERAL, std::vector<unsigned int>{STRING_LIT}),
	std::make_pair(LITERAL, std::vector<unsigned int>{BOOLEAN_LIT}),
	std::make_pair(LITERAL, std::vector<unsigned int>{NULL_LIT}),
	std::make_pair(TYPE, std::vector<unsigned int>{LONG_IDENTIFIER}),
	std::make_pair(TYPE, std::vector<unsigned int>{LONG_IDENTIFIER, ARRAY}),
	std::make_pair(TYPE, std::vector<unsigned int>{BASIC_TYPE}),
	std::make_pair(TYPE, std::vector<unsigned int>{BASIC_TYPE, ARRAY}),
	std::make_pair(ASSIGN_OP, std::vector<unsigned int>{ASSIGN}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{EAGER_OR}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{EAGER_AND}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{OR}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{AND}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{XOR}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{EQ}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{NEQ}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{LEQ}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{GEQ}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{GT}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{LT}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{PLUS}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{MINUS}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{MULT}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{DIV}),
	std::make_pair(INFIX_OP, std::vector<unsigned int>{REMAINDER}),
	std::make_pair(EXPRESSION, std::vector<unsigned int>{EXPRESSION1}),
	std::make_pair(EXPRESSION, std::vector<unsigned int>{EXPRESSION1, ASSIGN_OP, EXPRESSION1}),
	std::make_pair(STATEMENT_EXPRESSION, std::vector<unsigned int>{EXPRESSION}),
	std::make_pair(EXPRESSION1, std::vector<unsigned int>{EXPRESSION2}),
	std::make_pair(EXPRESSION1, std::vector<unsigned int>{EXPRESSION2, EXPRESSION1_REST}),
	std::make_pair(EXPRESSION1_REST, std::vector<unsigned int>{EXPRESSION_INFIX}),
	std::make_pair(EXPRESSION_INFIX, std::vector<unsigned int>{INFIX_OP, EXPRESSION2}),
	std::make_pair(EXPRESSION_INFIX, std::vector<unsigned int>{EXPRESSION_INFIX, INFIX_OP, EXPRESSION2}),
	std::make_pair(EXPRESSION1_REST, std::vector<unsigned int>{INSTANCEOF, TYPE}),
	std::make_pair(EXPRESSION2, std::vector<unsigned int>{MINUS, EXPRESSION2}),
	std::make_pair(EXPRESSION2, std::vector<unsigned int>{EXPRESSION3}),
	std::make_pair(EXPRESSION3, std::vector<unsigned int>{NOT, EXPRESSION2}),
	std::make_pair(EXPRESSION3, std::vector<unsigned int>{LPAREN, EXPRESSION, RPAREN, EXPRESSION3}),
	std::make_pair(EXPRESSION3, std::vector<unsigned int>{LPAREN, BASIC_TYPE, RPAREN, EXPRESSION2}),
	std::make_pair(EXPRESSION3, std::vector<unsigned int>{PRIMARY}),
	std::make_pair(EXPRESSION3, std::vector<unsigned int>{SELECTABLE_PRIMARY, SELECTORS}),
	std::make_pair(EXPRESSION_LIST, std::vector<unsigned int>{EXPRESSION}),
	std::make_pair(EXPRESSION_LIST, std::vector<unsigned int>{EXPRESSION_LIST, COMMA, EXPRESSION}),
	std::make_pair(EXPRESSION_OPT, std::vector<unsigned int>{EXPRESSION}),
	std::make_pair(EXPRESSION_OPT, std::vector<unsigned int>{}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{SELECTABLE_PRIMARY}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{LONG_IDENTIFIER}),
	std::make_pair(SELECTABLE_PRIMARY, std::vector<unsigned int>{LPAREN, EXPRESSION, RPAREN}),
	std::make_pair(SELECTABLE_PRIMARY, std::vector<unsigned int>{THIS}),
	std::make_pair(SELECTABLE_PRIMARY, std::vector<unsigned int>{LITERAL}),
	std::make_pair(SELECTABLE_PRIMARY, std::vector<unsigned int>{NEW, CREATOR}),
	std::make_pair(SELECTABLE_PRIMARY, std::vector<unsigned int>{LONG_IDENTIFIER, IDENTIFIER_SUFFIX}),
	std::make_pair(SELECTORS, std::vector<unsigned int>{SELECTOR}),
	std::make_pair(SELECTORS, std::vector<unsigned int>{SELECTORS, SELECTOR}),
	std::make_pair(SELECTOR, std::vector<unsigned int>{DOT, ID, ARGUMENTS_OPT}),
	std::make_pair(SELECTOR, std::vector<unsigned int>{LBRACKET, EXPRESSION, RBRACKET}),
	std::make_pair(IDENTIFIER_SUFFIX, std::vector<unsigned int>{LBRACKET, EXPRESSION, RBRACKET}),
	std::make_pair(IDENTIFIER_SUFFIX, std::vector<unsigned int>{ARGUMENTS}),
	std::make_pair(BASIC_TYPE, std::vector<unsigned int>{BYTE}),
	std::make_pair(BASIC_TYPE, std::vector<unsigned int>{SHORT}),
	std::make_pair(BASIC_TYPE, std::vector<unsigned int>{CHAR}),
	std::make_pair(BASIC_TYPE, std::vector<unsigned int>{INT}),
	std::make_pair(BASIC_TYPE, std::vector<unsigned int>{BOOLEAN}),
	std::make_pair(ARGUMENTS_OPT, std::vector<unsigned int>{ARGUMENTS}),
	std::make_pair(ARGUMENTS_OPT, std::vector<unsigned int>{}),
	std::make_pair(ARGUMENTS, std::vector<unsigned int>{LPAREN, RPAREN}),
	std::make_pair(ARGUMENTS, std::vector<unsigned int>{LPAREN, EXPRESSION_LIST, RPAREN}),
	std::make_pair(CREATOR, std::vector<unsigned int>{QUALIFIED_IDENTIFIER, LPAREN, ARRAY_CREATOR_REST, RPAREN}),
	std::make_pair(CREATOR, std::vector<unsigned int>{QUALIFIED_IDENTIFIER, LPAREN, CLASS_CREATOR_REST, RPAREN}),
	std::make_pair(INNER_CREATOR, std::vector<unsigned int>{ID, CLASS_CREATOR_REST}),
	std::make_pair(ARRAY_CREATOR_REST, std::vector<unsigned int>{LBRACKET, EXPRESSION, RBRACKET}),
	std::make_pair(CLASS_CREATOR_REST, std::vector<unsigned int>{ARGUMENTS}),
	std::make_pair(CLASS_CREATOR_REST, std::vector<unsigned int>{ARGUMENTS, CLASS_BODY}),
	std::make_pair(VARIABLE_INITIALIZER, std::vector<unsigned int>{EXPRESSION}),
	std::make_pair(PAR_EXPRESSION, std::vector<unsigned int>{LPAREN, EXPRESSION, RPAREN}),
	std::make_pair(BLOCK, std::vector<unsigned int>{LBRACE, BLOCK_BODY, RBRACE}),
	std::make_pair(BLOCK_BODY, std::vector<unsigned int>{BLOCK_STATEMENTS}),
	std::make_pair(BLOCK_BODY, std::vector<unsigned int>{}),
	std::make_pair(BLOCK_STATEMENTS, std::vector<unsigned int>{BLOCK_STATEMENT}),
	std::make_pair(BLOCK_STATEMENTS, std::vector<unsigned int>{BLOCK_STATEMENTS, BLOCK_STATEMENT}),
	std::make_pair(BLOCK_STATEMENT, std::vector<unsigned int>{LOCAL_VARIABLE_DECLARATION_STATEMENT}),
	std::make_pair(BLOCK_STATEMENT, std::vector<unsigned int>{STATEMENT}),
	std::make_pair(LOCAL_VARIABLE_DECLARATION_STATEMENT, std::vector<unsigned int>{TYPE, VARIABLE_DECLARATOR, SEMICOLON}),
	std::make_pair(STATEMENT, std::vector<unsigned int>{OPEN_STATEMENT}),
	std::make_pair(STATEMENT, std::vector<unsigned int>{CLOSED_STATEMENT}),
	std::make_pair(OPEN_STATEMENT, std::vector<unsigned int>{IF, PAR_EXPRESSION, STATEMENT}),
	std::make_pair(OPEN_STATEMENT, std::vector<unsigned int>{IF, PAR_EXPRESSION, CLOSED_STATEMENT, ELSE, OPEN_STATEMENT}),
	std::make_pair(OPEN_STATEMENT, std::vector<unsigned int>{WHILE, PAR_EXPRESSION, OPEN_STATEMENT}),
	std::make_pair(OPEN_STATEMENT, std::vector<unsigned int>{FOR, LPAREN, FOR_INIT_OPT, SEMICOLON, EXPRESSION_OPT, SEMICOLON, FOR_UPDATE_OPT, RPAREN, OPEN_STATEMENT}),
	std::make_pair(CLOSED_STATEMENT, std::vector<unsigned int>{BLOCK}),
	std::make_pair(CLOSED_STATEMENT, std::vector<unsigned int>{IF, PAR_EXPRESSION, CLOSED_STATEMENT, ELSE, CLOSED_STATEMENT}),
	std::make_pair(CLOSED_STATEMENT, std::vector<unsigned int>{FOR, LPAREN, FOR_INIT_OPT, SEMICOLON, EXPRESSION_OPT, SEMICOLON, FOR_UPDATE_OPT, RPAREN, CLOSED_STATEMENT}),
	std::make_pair(CLOSED_STATEMENT, std::vector<unsigned int>{WHILE, PAR_EXPRESSION, CLOSED_STATEMENT}),
	std::make_pair(CLOSED_STATEMENT, std::vector<unsigned int>{RETURN, SEMICOLON}),
	std::make_pair(CLOSED_STATEMENT, std::vector<unsigned int>{RETURN, EXPRESSION, SEMICOLON}),
	std::make_pair(CLOSED_STATEMENT, std::vector<unsigned int>{SEMICOLON}),
	std::make_pair(CLOSED_STATEMENT, std::vector<unsigned int>{STATEMENT_EXPRESSION, SEMICOLON}),
	std::make_pair(FOR_INIT_OPT, std::vector<unsigned int>{FOR_INIT}),
	std::make_pair(FOR_INIT_OPT, std::vector<unsigned int>{}),
	std::make_pair(FOR_INIT, std::vector<unsigned int>{STATEMENT_EXPRESSION}),
	std::make_pair(FOR_INIT, std::vector<unsigned int>{TYPE, VARIABLE_DECLARATOR}),
	std::make_pair(FOR_UPDATE_OPT, std::vector<unsigned int>{FOR_UPDATE}),
	std::make_pair(FOR_UPDATE_OPT, std::vector<unsigned int>{}),
	std::make_pair(FOR_UPDATE, std::vector<unsigned int>{STATEMENT_EXPRESSION}),
	std::make_pair(MODIFIERS_OPT, std::vector<unsigned int>{MODIFIERS}),
	std::make_pair(MODIFIERS_OPT, std::vector<unsigned int>{}),
	std::make_pair(MODIFIERS, std::vector<unsigned int>{MODIFIER}),
	std::make_pair(MODIFIERS, std::vector<unsigned int>{MODIFIERS, MODIFIER}),
	std::make_pair(MODIFIER, std::vector<unsigned int>{PUBLIC}),
	std::make_pair(MODIFIER, std::vector<unsigned int>{PROTECTED}),
	std::make_pair(MODIFIER, std::vector<unsigned int>{STATIC}),
	std::make_pair(MODIFIER, std::vector<unsigned int>{ABSTRACT}),
	std::make_pair(MODIFIER, std::vector<unsigned int>{FINAL}),
	std::make_pair(MODIFIER, std::vector<unsigned int>{NATIVE}),
	std::make_pair(VARIABLE_DECLARATOR, std::vector<unsigned int>{ID, VARIABLE_DECLARATOR_REST}),
	std::make_pair(VARIABLE_DECLARATOR_REST, std::vector<unsigned int>{}),
	std::make_pair(VARIABLE_DECLARATOR_REST, std::vector<unsigned int>{ASSIGN, VARIABLE_INITIALIZER}),
	std::make_pair(VARIABLE_DECLARATOR_ID, std::vector<unsigned int>{ID}),
	std::make_pair(COMPILER_UNIT, std::vector<unsigned int>{PACKAGE_DECLARATION, IMPORT_DECLARATIONS_OPT, TYPE_DECLARATIONS_OPT}),
	std::make_pair(PACKAGE_DECLARATION, std::vector<unsigned int>{PACKAGE, QUALIFIED_IDENTIFIER, SEMICOLON}),
	std::make_pair(PACKAGE_DECLARATION, std::vector<unsigned int>{}),
	std::make_pair(IMPORT_DECLARATIONS_OPT, std::vector<unsigned int>{IMPORT_DECLARATIONS}),
	std::make_pair(IMPORT_DECLARATIONS_OPT, std::vector<unsigned int>{}),
	std::make_pair(IMPORT_DECLARATIONS, std::vector<unsigned int>{IMPORT_DECLARATION}),
	std::make_pair(IMPORT_DECLARATIONS, std::vector<unsigned int>{IMPORT_DECLARATIONS, IMPORT_DECLARATION}),
	std::make_pair(TYPE_DECLARATIONS_OPT, std::vector<unsigned int>{TYPE_DECLARATION}),
	std::make_pair(TYPE_DECLARATIONS_OPT, std::vector<unsigned int>{}),
	std::make_pair(IMPORT_DECLARATION, std::vector<unsigned int>{IMPORT, LONG_IDENTIFIER, SEMICOLON}),
	std::make_pair(IMPORT_DECLARATION, std::vector<unsigned int>{IMPORT, LONG_IDENTIFIER, DOT, MULT, SEMICOLON}),
	std::make_pair(TYPE_DECLARATION, std::vector<unsigned int>{CLASS_OR_INTERFACE_DECLARATION}),
	std::make_pair(TYPE_DECLARATION, std::vector<unsigned int>{SEMICOLON}),
	std::make_pair(CLASS_OR_INTERFACE_DECLARATION, std::vector<unsigned int>{MODIFIERS_OPT, CLASS_DECLARATION}),
	std::make_pair(CLASS_OR_INTERFACE_DECLARATION, std::vector<unsigned int>{MODIFIERS_OPT, INTERFACE_DECLARATION}),
	std::make_pair(CLASS_DECLARATION, std::vector<unsigned int>{CLASS, ID, CLASS_BODY}),
	std::make_pair(CLASS_DECLARATION, std::vector<unsigned int>{CLASS, ID, EXTENDS, TYPE, CLASS_BODY}),
	std::make_pair(CLASS_DECLARATION, std::vector<unsigned int>{CLASS, ID, IMPLEMENTS, TYPE_LIST, CLASS_BODY}),
	std::make_pair(CLASS_DECLARATION, std::vector<unsigned int>{CLASS, ID, EXTENDS, TYPE, IMPLEMENTS, TYPE_LIST, CLASS_BODY}),
	std::make_pair(INTERFACE_DECLARATION, std::vector<unsigned int>{INTERFACE, ID, INTERFACE_BODY}),
	std::make_pair(INTERFACE_DECLARATION, std::vector<unsigned int>{INTERFACE, ID, EXTENDS, TYPE_LIST, INTERFACE_BODY}),
	std::make_pair(TYPE_LIST, std::vector<unsigned int>{TYPE}),
	std::make_pair(TYPE_LIST, std::vector<unsigned int>{TYPE_LIST, COMMA, TYPE}),
	std::make_pair(CLASS_BODY, std::vector<unsigned int>{LBRACE, RBRACE}),
	std::make_pair(CLASS_BODY, std::vector<unsigned int>{LBRACE, CLASS_BODY_DECLARATIONS, RBRACE}),
	std::make_pair(INTERFACE_BODY, std::vector<unsigned int>{LBRACE, RBRACE}),
	std::make_pair(INTERFACE_BODY, std::vector<unsigned int>{LBRACE, INTERFACE_BODY_DECLARATIONS, RBRACE}),
	std::make_pair(CLASS_BODY_DECLARATIONS, std::vector<unsigned int>{CLASS_BODY_DECLARATION}),
	std::make_pair(CLASS_BODY_DECLARATIONS, std::vector<unsigned int>{CLASS_BODY_DECLARATIONS, CLASS_BODY_DECLARATION}),
	std::make_pair(CLASS_BODY_DECLARATION, std::vector<unsigned int>{SEMICOLON}),
	std::make_pair(CLASS_BODY_DECLARATION, std::vector<unsigned int>{MODIFIERS_OPT, MEMBER_DECLARATION}),
	std::make_pair(MEMBER_DECLARATION, std::vector<unsigned int>{METHOD_OR_FIELD_DECLARATION}),
	std::make_pair(MEMBER_DECLARATION, std::vector<unsigned int>{VOID, ID, METHOD_DECLARATOR_REST}),
	std::make_pair(MEMBER_DECLARATION, std::vector<unsigned int>{ID, CONSTRUCTOR_DECLARATOR_REST}),
	std::make_pair(METHOD_OR_FIELD_DECLARATION, std::vector<unsigned int>{TYPE, ID, METHOD_OR_FIELD_REST}),
	std::make_pair(METHOD_OR_FIELD_REST, std::vector<unsigned int>{VARIABLE_DECLARATOR_REST, SEMICOLON}),
	std::make_pair(METHOD_OR_FIELD_REST, std::vector<unsigned int>{METHOD_DECLARATOR_REST}),
	std::make_pair(INTERFACE_BODY_DECLARATIONS, std::vector<unsigned int>{INTERFACE_BODY_DECLARATION}),
	std::make_pair(INTERFACE_BODY_DECLARATIONS, std::vector<unsigned int>{INTERFACE_BODY_DECLARATIONS, INTERFACE_BODY_DECLARATION}),
	std::make_pair(INTERFACE_BODY_DECLARATION, std::vector<unsigned int>{SEMICOLON}),
	std::make_pair(INTERFACE_BODY_DECLARATION, std::vector<unsigned int>{MODIFIERS_OPT, INTERFACE_MEMBER_DECLARATION}),
	std::make_pair(INTERFACE_MEMBER_DECLARATION, std::vector<unsigned int>{INTERFACE_METHOD_OR_FIELD_DECLARATION}),
	std::make_pair(INTERFACE_MEMBER_DECLARATION, std::vector<unsigned int>{VOID, ID, INTERFACE_METHOD_DECLARATOR_REST}),
	std::make_pair(INTERFACE_METHOD_OR_FIELD_DECLARATION, std::vector<unsigned int>{TYPE, ID, INTERFACE_METHOD_OR_FIELD_REST}),
	std::make_pair(INTERFACE_METHOD_OR_FIELD_REST, std::vector<unsigned int>{INTERFACE_METHOD_DECLARATOR_REST}),
	std::make_pair(METHOD_DECLARATOR_REST, std::vector<unsigned int>{FORMAL_PARAMETERS, METHOD_BODY}),
	std::make_pair(METHOD_DECLARATOR_REST, std::vector<unsigned int>{FORMAL_PARAMETERS, SEMICOLON}),
	std::make_pair(INTERFACE_METHOD_DECLARATOR_REST, std::vector<unsigned int>{FORMAL_PARAMETERS, SEMICOLON}),
	std::make_pair(CONSTRUCTOR_DECLARATOR_REST, std::vector<unsigned int>{FORMAL_PARAMETERS, METHOD_BODY}),
	std::make_pair(FORMAL_PARAMETERS, std::vector<unsigned int>{LPAREN, FORMAL_PARAMETERS_OPT, RPAREN}),
	std::make_pair(FORMAL_PARAMETERS_OPT, std::vector<unsigned int>{FORMAL_PARAMETER_LIST}),
	std::make_pair(FORMAL_PARAMETERS_OPT, std::vector<unsigned int>{}),
	std::make_pair(FORMAL_PARAMETER_LIST, std::vector<unsigned int>{FORMAL_PARAMETER}),
	std::make_pair(FORMAL_PARAMETER_LIST, std::vector<unsigned int>{FORMAL_PARAMETER_LIST, COMMA, FORMAL_PARAMETER}),
	std::make_pair(FORMAL_PARAMETER, std::vector<unsigned int>{TYPE, VARIABLE_DECLARATOR_ID}),
	std::make_pair(METHOD_BODY, std::vector<unsigned int>{BLOCK}),
};

int stateShift(int currState, int symbol)
{
	switch(currState) {
		case 0:
			switch(symbol) {
				case START_TERMINAL: return 667;
			}
			break;
		case 1:
			switch(symbol) {
				case CREATOR: return 224;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 573;
			}
			break;
		case 2:
			switch(symbol) {
				case ID: return 910;
			}
			break;
		case 6:
			switch(symbol) {
				case BOOLEAN_LIT: return 136;
				case CHAR_LIT: return 48;
				case EXPRESSION2: return 1147;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 8:
			switch(symbol) {
				case ARGUMENTS: return 794;
				case DOT: return 1017;
				case IDENTIFIER_SUFFIX: return 5;
				case LBRACKET: return 1055;
				case LPAREN: return 818;
			}
			break;
		case 13:
			switch(symbol) {
				case LPAREN: return 1309;
			}
			break;
		case 14:
			switch(symbol) {
				case LPAREN: return 499;
				case PAR_EXPRESSION: return 700;
			}
			break;
		case 16:
			switch(symbol) {
				case CREATOR: return 597;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 236;
			}
			break;
		case 17:
			switch(symbol) {
				case RBRACKET: return 394;
			}
			break;
		case 21:
			switch(symbol) {
				case ARGUMENTS: return 1236;
				case DOT: return 671;
				case IDENTIFIER_SUFFIX: return 271;
				case LBRACKET: return 450;
				case LPAREN: return 122;
			}
			break;
		case 23:
			switch(symbol) {
				case BOOLEAN_LIT: return 136;
				case CHAR_LIT: return 48;
				case EXPRESSION2: return 1047;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 28:
			switch(symbol) {
				case CREATOR: return 1286;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 963;
			}
			break;
		case 29:
			switch(symbol) {
				case RPAREN: return 258;
			}
			break;
		case 33:
			switch(symbol) {
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case EXPRESSION2: return 202;
				case EXPRESSION3: return 55;
				case ID: return 15;
				case INT_LIT: return 96;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case PRIMARY: return 242;
				case SELECTABLE_PRIMARY: return 278;
				case STRING_LIT: return 155;
				case THIS: return 25;
			}
			break;
		case 36:
			switch(symbol) {
				case BOOLEAN_LIT: return 136;
				case CHAR_LIT: return 48;
				case EXPRESSION2: return 981;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 37:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 128;
				case CLASS_CREATOR_REST: return 646;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 38:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION2: return 1153;
				case EXPRESSION3: return 220;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 39:
			switch(symbol) {
				case RBRACKET: return 50;
			}
			break;
		case 44:
			switch(symbol) {
				case BASIC_TYPE: return 1264;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 1203;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 47:
			switch(symbol) {
				case LPAREN: return 923;
			}
			break;
		case 54:
			switch(symbol) {
				case ASSIGN: return 831;
				case ASSIGN_OP: return 946;
			}
			break;
		case 56:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case EXPRESSION1_REST: return 763;
				case EXPRESSION_INFIX: return 710;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 1100;
				case INSTANCEOF: return 513;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 59:
			switch(symbol) {
				case ID: return 348;
			}
			break;
		case 62:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION2: return 1034;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 64:
			switch(symbol) {
				case BASIC_TYPE: return 460;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 332;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 68:
			switch(symbol) {
				case ARGUMENTS: return 507;
				case DOT: return 889;
				case IDENTIFIER_SUFFIX: return 421;
				case LBRACKET: return 866;
				case LPAREN: return 1028;
			}
			break;
		case 70:
			switch(symbol) {
				case ASSIGN: return 831;
				case ASSIGN_OP: return 625;
			}
			break;
		case 71:
			switch(symbol) {
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case EXPRESSION: return 771;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case ID: return 15;
				case INT_LIT: return 96;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case PRIMARY: return 242;
				case SELECTABLE_PRIMARY: return 278;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case VARIABLE_INITIALIZER: return 1299;
			}
			break;
		case 72:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case EXPRESSION1_REST: return 1094;
				case EXPRESSION_INFIX: return 1292;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 295;
				case INSTANCEOF: return 1103;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 74:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BOOLEAN: return 383;
				case BYTE: return 409;
				case CHAR: return 515;
				case FORMAL_PARAMETER: return 1197;
				case FORMAL_PARAMETERS_OPT: return 1166;
				case FORMAL_PARAMETER_LIST: return 101;
				case ID: return 586;
				case INT: return 416;
				case LONG_IDENTIFIER: return 663;
				case SHORT: return 527;
				case TYPE: return 695;
			}
			break;
		case 76:
			switch(symbol) {
				case BASIC_TYPE: return 876;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 1177;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 78:
			switch(symbol) {
				case ARRAY: return 1162;
				case DOT: return 892;
			}
			break;
		case 79:
			switch(symbol) {
				case DOT: return 1019;
				case LBRACKET: return 1059;
				case SELECTOR: return 990;
				case SELECTORS: return 1139;
			}
			break;
		case 86:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 815;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 90:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 493;
				case CLASS_CREATOR_REST: return 1078;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 93:
			switch(symbol) {
				case BLOCK: return 562;
				case LBRACE: return 397;
				case METHOD_BODY: return 501;
				case SEMICOLON: return 844;
			}
			break;
		case 94:
			switch(symbol) {
				case DOT: return 830;
				case LBRACKET: return 907;
				case SELECTOR: return 1164;
			}
			break;
		case 97:
			switch(symbol) {
				case BASIC_TYPE: return 1242;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 1182;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 100:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 862;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 101:
			switch(symbol) {
				case COMMA: return 1150;
			}
			break;
		case 104:
			switch(symbol) {
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case EXPRESSION2: return 949;
				case EXPRESSION3: return 55;
				case ID: return 15;
				case INT_LIT: return 96;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case PRIMARY: return 242;
				case SELECTABLE_PRIMARY: return 278;
				case STRING_LIT: return 155;
				case THIS: return 25;
			}
			break;
		case 105:
			switch(symbol) {
				case BASIC_TYPE: return 925;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 1116;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 112:
			switch(symbol) {
				case ABSTRACT: return 284;
				case CLASS_BODY_DECLARATION: return 478;
				case CLASS_BODY_DECLARATIONS: return 780;
				case FINAL: return 12;
				case MODIFIER: return 647;
				case MODIFIERS: return 398;
				case MODIFIERS_OPT: return 462;
				case NATIVE: return 350;
				case PROTECTED: return 110;
				case PUBLIC: return 356;
				case RBRACE: return 1251;
				case SEMICOLON: return 390;
				case STATIC: return 176;
			}
			break;
		case 113:
			switch(symbol) {
				case DOT: return 1213;
				case LBRACKET: return 1044;
				case SELECTOR: return 321;
				case SELECTORS: return 227;
			}
			break;
		case 116:
			switch(symbol) {
				case BOOLEAN_LIT: return 311;
				case CHAR_LIT: return 326;
				case EXPRESSION2: return 748;
				case EXPRESSION3: return 749;
				case ID: return 524;
				case INT_LIT: return 465;
				case LITERAL: return 372;
				case LONG_IDENTIFIER: return 68;
				case LPAREN: return 76;
				case MINUS: return 116;
				case NEW: return 16;
				case NOT: return 387;
				case NULL_LIT: return 49;
				case PRIMARY: return 639;
				case SELECTABLE_PRIMARY: return 172;
				case STRING_LIT: return 540;
				case THIS: return 260;
			}
			break;
		case 119:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case EXPRESSION1_REST: return 672;
				case EXPRESSION_INFIX: return 512;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 1199;
				case INSTANCEOF: return 1198;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 120:
			switch(symbol) {
				case ASSIGN: return 831;
				case ASSIGN_OP: return 1194;
			}
			break;
		case 122:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 1173;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 486;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 126:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION2: return 1279;
				case EXPRESSION3: return 220;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 128:
			switch(symbol) {
				case RPAREN: return 1124;
			}
			break;
		case 130:
			switch(symbol) {
				case ID: return 775;
			}
			break;
		case 131:
			switch(symbol) {
				case BOOLEAN_LIT: return 538;
				case CHAR_LIT: return 183;
				case EXPRESSION2: return 972;
				case EXPRESSION3: return 53;
				case ID: return 454;
				case INT_LIT: return 574;
				case LITERAL: return 40;
				case LONG_IDENTIFIER: return 511;
				case LPAREN: return 186;
				case MINUS: return 131;
				case NEW: return 426;
				case NOT: return 477;
				case NULL_LIT: return 380;
				case PRIMARY: return 265;
				case SELECTABLE_PRIMARY: return 457;
				case STRING_LIT: return 66;
				case THIS: return 75;
			}
			break;
		case 132:
			switch(symbol) {
				case ID: return 595;
			}
			break;
		case 133:
			switch(symbol) {
				case DOT: return 1067;
				case LBRACKET: return 530;
				case SELECTOR: return 1226;
				case SELECTORS: return 281;
			}
			break;
		case 134:
			switch(symbol) {
				case ASSIGN: return 71;
				case VARIABLE_DECLARATOR_REST: return 1189;
			}
			break;
		case 135:
			switch(symbol) {
				case CREATOR: return 589;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 285;
			}
			break;
		case 137:
			switch(symbol) {
				case BOOLEAN_LIT: return 87;
				case CHAR_LIT: return 334;
				case EXPRESSION2: return 986;
				case EXPRESSION3: return 607;
				case ID: return 660;
				case INT_LIT: return 299;
				case LITERAL: return 46;
				case LONG_IDENTIFIER: return 261;
				case LPAREN: return 305;
				case MINUS: return 139;
				case NEW: return 1;
				case NOT: return 137;
				case NULL_LIT: return 496;
				case PRIMARY: return 446;
				case SELECTABLE_PRIMARY: return 399;
				case STRING_LIT: return 349;
				case THIS: return 402;
			}
			break;
		case 138:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 389;
				case EXPRESSION2: return 243;
				case EXPRESSION3: return 244;
				case ID: return 188;
				case INT_LIT: return 124;
				case LITERAL: return 18;
				case LONG_IDENTIFIER: return 269;
				case LPAREN: return 97;
				case MINUS: return 138;
				case NEW: return 676;
				case NOT: return 616;
				case NULL_LIT: return 759;
				case PRIMARY: return 533;
				case SELECTABLE_PRIMARY: return 152;
				case STRING_LIT: return 89;
				case THIS: return 455;
			}
			break;
		case 139:
			switch(symbol) {
				case BOOLEAN_LIT: return 87;
				case CHAR_LIT: return 334;
				case EXPRESSION2: return 622;
				case EXPRESSION3: return 607;
				case ID: return 660;
				case INT_LIT: return 299;
				case LITERAL: return 46;
				case LONG_IDENTIFIER: return 261;
				case LPAREN: return 305;
				case MINUS: return 139;
				case NEW: return 1;
				case NOT: return 137;
				case NULL_LIT: return 496;
				case PRIMARY: return 446;
				case SELECTABLE_PRIMARY: return 399;
				case STRING_LIT: return 349;
				case THIS: return 402;
			}
			break;
		case 142:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 568;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 143:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 1306;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 147:
			switch(symbol) {
				case LPAREN: return 499;
				case PAR_EXPRESSION: return 977;
			}
			break;
		case 149:
			switch(symbol) {
				case ID: return 911;
			}
			break;
		case 150:
			switch(symbol) {
				case ARRAY: return 817;
			}
			break;
		case 152:
			switch(symbol) {
				case DOT: return 896;
				case LBRACKET: return 661;
				case SELECTOR: return 541;
				case SELECTORS: return 487;
			}
			break;
		case 153:
			switch(symbol) {
				case IMPORT: return 274;
				case IMPORT_DECLARATION: return 1250;
				case IMPORT_DECLARATIONS: return 1087;
				case IMPORT_DECLARATIONS_OPT: return 901;
			}
			break;
		case 154:
			switch(symbol) {
				case RBRACE: return 529;
			}
			break;
		case 159:
			switch(symbol) {
				case BASIC_TYPE: return 1079;
				case BOOLEAN: return 318;
				case BYTE: return 502;
				case CHAR: return 984;
				case ID: return 937;
				case INT: return 593;
				case LONG_IDENTIFIER: return 835;
				case SHORT: return 1042;
				case TYPE: return 950;
			}
			break;
		case 160:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 1113;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 693;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 164:
			switch(symbol) {
				case CREATOR: return 1021;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 222;
			}
			break;
		case 165:
			switch(symbol) {
				case SEMICOLON: return 1223;
			}
			break;
		case 167:
			switch(symbol) {
				case CLASS_BODY: return 401;
				case LBRACE: return 1052;
			}
			break;
		case 172:
			switch(symbol) {
				case DOT: return 211;
				case LBRACKET: return 365;
				case SELECTOR: return 644;
				case SELECTORS: return 1039;
			}
			break;
		case 173:
			switch(symbol) {
				case CREATOR: return 649;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 1254;
			}
			break;
		case 175:
			switch(symbol) {
				case ARGUMENTS: return 995;
				case DOT: return 177;
				case IDENTIFIER_SUFFIX: return 1023;
				case LBRACKET: return 807;
				case LPAREN: return 620;
			}
			break;
		case 177:
			switch(symbol) {
				case ID: return 1302;
			}
			break;
		case 182:
			switch(symbol) {
				case DOT: return 855;
				case LBRACKET: return 668;
				case SELECTOR: return 665;
				case SELECTORS: return 718;
			}
			break;
		case 186:
			switch(symbol) {
				case BASIC_TYPE: return 1287;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 424;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 189:
			switch(symbol) {
				case BOOLEAN_LIT: return 320;
				case CHAR_LIT: return 20;
				case EXPRESSION2: return 857;
				case EXPRESSION3: return 476;
				case ID: return 275;
				case INT_LIT: return 594;
				case LITERAL: return 250;
				case LONG_IDENTIFIER: return 277;
				case LPAREN: return 230;
				case MINUS: return 189;
				case NEW: return 420;
				case NOT: return 429;
				case NULL_LIT: return 247;
				case PRIMARY: return 168;
				case SELECTABLE_PRIMARY: return 182;
				case STRING_LIT: return 270;
				case THIS: return 592;
			}
			break;
		case 190:
			switch(symbol) {
				case ARGUMENTS: return 887;
				case DOT: return 415;
				case IDENTIFIER_SUFFIX: return 587;
				case LBRACKET: return 431;
				case LPAREN: return 1002;
			}
			break;
		case 191:
			switch(symbol) {
				case BASIC_TYPE: return 1291;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 1121;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 193:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION2: return 364;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 194:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 1265;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 255;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 195:
			switch(symbol) {
				case ARGUMENTS: return 548;
				case DOT: return 847;
				case IDENTIFIER_SUFFIX: return 1188;
				case LBRACKET: return 1276;
				case LPAREN: return 613;
			}
			break;
		case 198:
			switch(symbol) {
				case CREATOR: return 1122;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 212;
			}
			break;
		case 199:
			switch(symbol) {
				case SEMICOLON: return 330;
			}
			break;
		case 200:
			switch(symbol) {
				case RBRACKET: return 491;
			}
			break;
		case 201:
			switch(symbol) {
				case ARRAY: return 971;
			}
			break;
		case 203:
			switch(symbol) {
				case ARGUMENTS: return 691;
				case ARGUMENTS_OPT: return 1114;
				case LPAREN: return 620;
			}
			break;
		case 204:
			switch(symbol) {
				case BOOLEAN_LIT: return 114;
				case CHAR_LIT: return 696;
				case EXPRESSION2: return 813;
				case EXPRESSION3: return 803;
				case ID: return 140;
				case INT_LIT: return 709;
				case LITERAL: return 328;
				case LONG_IDENTIFIER: return 272;
				case LPAREN: return 105;
				case MINUS: return 204;
				case NEW: return 444;
				case NOT: return 425;
				case NULL_LIT: return 557;
				case PRIMARY: return 291;
				case SELECTABLE_PRIMARY: return 422;
				case STRING_LIT: return 197;
				case THIS: return 653;
			}
			break;
		case 208:
			switch(symbol) {
				case BOOLEAN_LIT: return 67;
				case CHAR_LIT: return 505;
				case EXPRESSION2: return 959;
				case EXPRESSION3: return 598;
				case ID: return 9;
				case INT_LIT: return 636;
				case LITERAL: return 158;
				case LONG_IDENTIFIER: return 618;
				case LPAREN: return 719;
				case MINUS: return 741;
				case NEW: return 173;
				case NOT: return 208;
				case NULL_LIT: return 742;
				case PRIMARY: return 223;
				case SELECTABLE_PRIMARY: return 680;
				case STRING_LIT: return 99;
				case THIS: return 547;
			}
			break;
		case 209:
			switch(symbol) {
				case LPAREN: return 373;
			}
			break;
		case 211:
			switch(symbol) {
				case ID: return 1266;
			}
			break;
		case 212:
			switch(symbol) {
				case LPAREN: return 933;
			}
			break;
		case 214:
			switch(symbol) {
				case ABSTRACT: return 284;
				case CLASS_BODY_DECLARATION: return 935;
				case FINAL: return 12;
				case MODIFIER: return 647;
				case MODIFIERS: return 398;
				case MODIFIERS_OPT: return 462;
				case NATIVE: return 350;
				case PROTECTED: return 110;
				case PUBLIC: return 356;
				case RBRACE: return 1091;
				case SEMICOLON: return 390;
				case STATIC: return 176;
			}
			break;
		case 218:
			switch(symbol) {
				case LPAREN: return 871;
			}
			break;
		case 219:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case EXPRESSION1_REST: return 1020;
				case EXPRESSION_INFIX: return 698;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 580;
				case INSTANCEOF: return 798;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 221:
			switch(symbol) {
				case ASSIGN: return 831;
				case ASSIGN_OP: return 744;
			}
			break;
		case 222:
			switch(symbol) {
				case LPAREN: return 1035;
			}
			break;
		case 225:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 366;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 227:
			switch(symbol) {
				case DOT: return 1213;
				case LBRACKET: return 1044;
				case SELECTOR: return 1083;
			}
			break;
		case 228:
			switch(symbol) {
				case BASIC_TYPE: return 1080;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 1169;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 230:
			switch(symbol) {
				case BASIC_TYPE: return 565;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 930;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 231:
			switch(symbol) {
				case BOOLEAN_LIT: return 215;
				case CHAR_LIT: return 456;
				case EXPRESSION2: return 1233;
				case EXPRESSION3: return 686;
				case ID: return 621;
				case INT_LIT: return 148;
				case LITERAL: return 217;
				case LONG_IDENTIFIER: return 175;
				case LPAREN: return 461;
				case MINUS: return 413;
				case NEW: return 392;
				case NOT: return 231;
				case NULL_LIT: return 345;
				case PRIMARY: return 371;
				case SELECTABLE_PRIMARY: return 358;
				case STRING_LIT: return 626;
				case THIS: return 370;
			}
			break;
		case 234:
			switch(symbol) {
				case BASIC_TYPE: return 201;
				case BOOLEAN: return 103;
				case BYTE: return 1130;
				case CHAR: return 584;
				case ID: return 564;
				case INT: return 645;
				case LONG_IDENTIFIER: return 404;
				case SHORT: return 550;
				case TYPE: return 559;
				case TYPE_LIST: return 821;
			}
			break;
		case 236:
			switch(symbol) {
				case LPAREN: return 1270;
			}
			break;
		case 237:
			switch(symbol) {
				case BOOLEAN_LIT: return 232;
				case CHAR_LIT: return 561;
				case EXPRESSION2: return 480;
				case EXPRESSION3: return 57;
				case ID: return 585;
				case INT_LIT: return 254;
				case LITERAL: return 239;
				case LONG_IDENTIFIER: return 340;
				case LPAREN: return 228;
				case MINUS: return 237;
				case NEW: return 642;
				case NOT: return 630;
				case NULL_LIT: return 312;
				case PRIMARY: return 526;
				case SELECTABLE_PRIMARY: return 113;
				case STRING_LIT: return 522;
				case THIS: return 781;
			}
			break;
		case 240:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 1231;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 245:
			switch(symbol) {
				case ABSTRACT: return 284;
				case FINAL: return 12;
				case INTERFACE_BODY_DECLARATION: return 675;
				case MODIFIER: return 647;
				case MODIFIERS: return 398;
				case MODIFIERS_OPT: return 881;
				case NATIVE: return 350;
				case PROTECTED: return 110;
				case PUBLIC: return 356;
				case RBRACE: return 80;
				case SEMICOLON: return 1066;
				case STATIC: return 176;
			}
			break;
		case 246:
			switch(symbol) {
				case BASIC_TYPE: return 581;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 726;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 253:
			switch(symbol) {
				case RPAREN: return 767;
			}
			break;
		case 258:
			switch(symbol) {
				case BOOLEAN_LIT: return 238;
				case CHAR_LIT: return 376;
				case EXPRESSION3: return 1084;
				case ID: return 233;
				case INT_LIT: return 19;
				case LITERAL: return 171;
				case LONG_IDENTIFIER: return 362;
				case LPAREN: return 359;
				case NEW: return 707;
				case NOT: return 712;
				case NULL_LIT: return 762;
				case PRIMARY: return 289;
				case SELECTABLE_PRIMARY: return 717;
				case STRING_LIT: return 129;
				case THIS: return 443;
			}
			break;
		case 259:
			switch(symbol) {
				case ID: return 134;
				case VARIABLE_DECLARATOR: return 1074;
			}
			break;
		case 261:
			switch(symbol) {
				case ARGUMENTS: return 73;
				case DOT: return 777;
				case IDENTIFIER_SUFFIX: return 655;
				case LBRACKET: return 579;
				case LPAREN: return 427;
			}
			break;
		case 266:
			switch(symbol) {
				case DOT: return 750;
				case LBRACKET: return 834;
				case SELECTOR: return 1001;
				case SELECTORS: return 1129;
			}
			break;
		case 268:
			switch(symbol) {
				case RBRACKET: return 705;
			}
			break;
		case 269:
			switch(symbol) {
				case ARGUMENTS: return 1301;
				case DOT: return 657;
				case IDENTIFIER_SUFFIX: return 1258;
				case LBRACKET: return 1101;
				case LPAREN: return 678;
			}
			break;
		case 272:
			switch(symbol) {
				case ARGUMENTS: return 329;
				case DOT: return 1282;
				case IDENTIFIER_SUFFIX: return 1076;
				case LBRACKET: return 1111;
				case LPAREN: return 335;
			}
			break;
		case 274:
			switch(symbol) {
				case ID: return 571;
				case LONG_IDENTIFIER: return 293;
			}
			break;
		case 277:
			switch(symbol) {
				case ARGUMENTS: return 1120;
				case DOT: return 310;
				case IDENTIFIER_SUFFIX: return 943;
				case LBRACKET: return 86;
				case LPAREN: return 333;
			}
			break;
		case 278:
			switch(symbol) {
				case DOT: return 1109;
				case LBRACKET: return 459;
				case SELECTOR: return 302;
				case SELECTORS: return 407;
			}
			break;
		case 280:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 1220;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 281:
			switch(symbol) {
				case DOT: return 1067;
				case LBRACKET: return 530;
				case SELECTOR: return 517;
			}
			break;
		case 282:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 1245;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 264;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 283:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 899;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 285:
			switch(symbol) {
				case LPAREN: return 466;
			}
			break;
		case 286:
			switch(symbol) {
				case BOOLEAN_LIT: return 322;
				case CHAR_LIT: return 287;
				case EXPRESSION2: return 339;
				case EXPRESSION3: return 338;
				case ID: return 34;
				case INT_LIT: return 448;
				case LITERAL: return 117;
				case LONG_IDENTIFIER: return 482;
				case LPAREN: return 452;
				case MINUS: return 488;
				case NEW: return 463;
				case NOT: return 470;
				case NULL_LIT: return 583;
				case PRIMARY: return 406;
				case SELECTABLE_PRIMARY: return 266;
				case STRING_LIT: return 161;
				case THIS: return 178;
			}
			break;
		case 288:
			switch(symbol) {
				case BOOLEAN_LIT: return 114;
				case CHAR_LIT: return 696;
				case EXPRESSION2: return 804;
				case EXPRESSION3: return 803;
				case ID: return 140;
				case INT_LIT: return 709;
				case LITERAL: return 328;
				case LONG_IDENTIFIER: return 272;
				case LPAREN: return 105;
				case MINUS: return 204;
				case NEW: return 444;
				case NOT: return 425;
				case NULL_LIT: return 557;
				case PRIMARY: return 291;
				case SELECTABLE_PRIMARY: return 422;
				case STRING_LIT: return 197;
				case THIS: return 653;
			}
			break;
		case 290:
			switch(symbol) {
				case ARGUMENTS: return 809;
				case DOT: return 1170;
				case IDENTIFIER_SUFFIX: return 308;
				case LBRACKET: return 956;
				case LPAREN: return 414;
			}
			break;
		case 292:
			switch(symbol) {
				case ID: return 63;
			}
			break;
		case 293:
			switch(symbol) {
				case DOT: return 694;
				case SEMICOLON: return 1058;
			}
			break;
		case 295:
			switch(symbol) {
				case BOOLEAN_LIT: return 215;
				case CHAR_LIT: return 456;
				case EXPRESSION2: return 1224;
				case EXPRESSION3: return 686;
				case ID: return 621;
				case INT_LIT: return 148;
				case LITERAL: return 217;
				case LONG_IDENTIFIER: return 175;
				case LPAREN: return 461;
				case MINUS: return 413;
				case NEW: return 392;
				case NOT: return 231;
				case NULL_LIT: return 345;
				case PRIMARY: return 371;
				case SELECTABLE_PRIMARY: return 358;
				case STRING_LIT: return 626;
				case THIS: return 370;
			}
			break;
		case 300:
			switch(symbol) {
				case LPAREN: return 499;
				case PAR_EXPRESSION: return 1311;
			}
			break;
		case 303:
			switch(symbol) {
				case RPAREN: return 602;
			}
			break;
		case 305:
			switch(symbol) {
				case BASIC_TYPE: return 766;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 535;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 307:
			switch(symbol) {
				case SEMICOLON: return 1051;
			}
			break;
		case 310:
			switch(symbol) {
				case ID: return 852;
			}
			break;
		case 314:
			switch(symbol) {
				case BOOLEAN_LIT: return 238;
				case CHAR_LIT: return 376;
				case EXPRESSION2: return 1293;
				case EXPRESSION3: return 343;
				case ID: return 233;
				case INT_LIT: return 19;
				case LITERAL: return 171;
				case LONG_IDENTIFIER: return 362;
				case LPAREN: return 359;
				case MINUS: return 314;
				case NEW: return 707;
				case NOT: return 712;
				case NULL_LIT: return 762;
				case PRIMARY: return 289;
				case SELECTABLE_PRIMARY: return 717;
				case STRING_LIT: return 129;
				case THIS: return 443;
			}
			break;
		case 319:
			switch(symbol) {
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case EXPRESSION: return 842;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case EXPRESSION_OPT: return 786;
				case ID: return 15;
				case INT_LIT: return 96;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case PRIMARY: return 242;
				case SELECTABLE_PRIMARY: return 278;
				case STRING_LIT: return 155;
				case THIS: return 25;
			}
			break;
		case 323:
			switch(symbol) {
				case EXTENDS: return 234;
				case INTERFACE_BODY: return 982;
				case LBRACE: return 745;
			}
			break;
		case 324:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 953;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 1112;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 331:
			switch(symbol) {
				case FORMAL_PARAMETERS: return 423;
				case INTERFACE_METHOD_DECLARATOR_REST: return 115;
				case INTERFACE_METHOD_OR_FIELD_REST: return 1268;
				case LPAREN: return 560;
			}
			break;
		case 332:
			switch(symbol) {
				case RPAREN: return 992;
			}
			break;
		case 333:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 843;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 728;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 335:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 551;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 704;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 340:
			switch(symbol) {
				case ARGUMENTS: return 1151;
				case DOT: return 732;
				case IDENTIFIER_SUFFIX: return 276;
				case LBRACKET: return 882;
				case LPAREN: return 435;
			}
			break;
		case 342:
			switch(symbol) {
				case ID: return 556;
			}
			break;
		case 348:
			switch(symbol) {
				case ARGUMENTS: return 1249;
				case ARGUMENTS_OPT: return 552;
				case LPAREN: return 623;
			}
			break;
		case 351:
			switch(symbol) {
				case DOT: return 438;
				case LBRACKET: return 441;
				case SELECTOR: return 210;
				case SELECTORS: return 1135;
			}
			break;
		case 355:
			switch(symbol) {
				case RPAREN: return 908;
			}
			break;
		case 358:
			switch(symbol) {
				case DOT: return 830;
				case LBRACKET: return 907;
				case SELECTOR: return 1161;
				case SELECTORS: return 94;
			}
			break;
		case 359:
			switch(symbol) {
				case BASIC_TYPE: return 434;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 29;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 360:
			switch(symbol) {
				case SEMICOLON: return 673;
			}
			break;
		case 362:
			switch(symbol) {
				case ARGUMENTS: return 353;
				case DOT: return 1288;
				case IDENTIFIER_SUFFIX: return 1032;
				case LBRACKET: return 1192;
				case LPAREN: return 282;
			}
			break;
		case 363:
			switch(symbol) {
				case BOOLEAN_LIT: return 320;
				case CHAR_LIT: return 20;
				case EXPRESSION3: return 1304;
				case ID: return 275;
				case INT_LIT: return 594;
				case LITERAL: return 250;
				case LONG_IDENTIFIER: return 277;
				case LPAREN: return 230;
				case NEW: return 420;
				case NOT: return 429;
				case NULL_LIT: return 247;
				case PRIMARY: return 168;
				case SELECTABLE_PRIMARY: return 182;
				case STRING_LIT: return 270;
				case THIS: return 592;
			}
			break;
		case 365:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 532;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 366:
			switch(symbol) {
				case RBRACKET: return 874;
			}
			break;
		case 367:
			switch(symbol) {
				case RBRACKET: return 1232;
			}
			break;
		case 368:
			switch(symbol) {
				case BOOLEAN_LIT: return 481;
				case CHAR_LIT: return 163;
				case EXPRESSION2: return 337;
				case EXPRESSION3: return 341;
				case ID: return 111;
				case INT_LIT: return 123;
				case LITERAL: return 504;
				case LONG_IDENTIFIER: return 290;
				case LPAREN: return 697;
				case MINUS: return 708;
				case NEW: return 384;
				case NOT: return 410;
				case NULL_LIT: return 141;
				case PRIMARY: return 298;
				case SELECTABLE_PRIMARY: return 375;
				case STRING_LIT: return 743;
				case THIS: return 169;
			}
			break;
		case 373:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BOOLEAN: return 383;
				case BOOLEAN_LIT: return 85;
				case BYTE: return 409;
				case CHAR: return 515;
				case CHAR_LIT: return 92;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR_INIT: return 213;
				case FOR_INIT_OPT: return 861;
				case ID: return 428;
				case INT: return 416;
				case INT_LIT: return 96;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 590;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case PRIMARY: return 242;
				case SELECTABLE_PRIMARY: return 278;
				case SHORT: return 527;
				case STATEMENT_EXPRESSION: return 327;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case TYPE: return 1157;
			}
			break;
		case 375:
			switch(symbol) {
				case DOT: return 132;
				case LBRACKET: return 280;
				case SELECTOR: return 640;
				case SELECTORS: return 756;
			}
			break;
		case 377:
			switch(symbol) {
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case EXPRESSION: return 440;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case ID: return 15;
				case INT_LIT: return 96;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case PRIMARY: return 242;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 957;
				case STRING_LIT: return 155;
				case THIS: return 25;
			}
			break;
		case 379:
			switch(symbol) {
				case ARRAY: return 1045;
			}
			break;
		case 384:
			switch(symbol) {
				case CREATOR: return 1060;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 1093;
			}
			break;
		case 387:
			switch(symbol) {
				case BOOLEAN_LIT: return 311;
				case CHAR_LIT: return 326;
				case EXPRESSION2: return 1277;
				case EXPRESSION3: return 749;
				case ID: return 524;
				case INT_LIT: return 465;
				case LITERAL: return 372;
				case LONG_IDENTIFIER: return 68;
				case LPAREN: return 76;
				case MINUS: return 116;
				case NEW: return 16;
				case NOT: return 387;
				case NULL_LIT: return 49;
				case PRIMARY: return 639;
				case SELECTABLE_PRIMARY: return 172;
				case STRING_LIT: return 540;
				case THIS: return 260;
			}
			break;
		case 388:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BLOCK: return 88;
				case BLOCK_STATEMENT: return 567;
				case BOOLEAN: return 383;
				case BOOLEAN_LIT: return 85;
				case BYTE: return 409;
				case CHAR: return 515;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 316;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 209;
				case ID: return 428;
				case IF: return 14;
				case INT: return 416;
				case INT_LIT: return 96;
				case LBRACE: return 442;
				case LITERAL: return 296;
				case LOCAL_VARIABLE_DECLARATION_STATEMENT: return 485;
				case LONG_IDENTIFIER: return 590;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 174;
				case PRIMARY: return 242;
				case RETURN: return 474;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 313;
				case SHORT: return 527;
				case STATEMENT: return 702;
				case STATEMENT_EXPRESSION: return 165;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case TYPE: return 259;
				case WHILE: return 300;
			}
			break;
		case 391:
			switch(symbol) {
				case DOT: return 683;
			}
			break;
		case 392:
			switch(symbol) {
				case CREATOR: return 730;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 1038;
			}
			break;
		case 393:
			switch(symbol) {
				case RPAREN: return 1137;
			}
			break;
		case 395:
			switch(symbol) {
				case BOOLEAN_LIT: return 232;
				case CHAR_LIT: return 561;
				case EXPRESSION2: return 605;
				case EXPRESSION3: return 57;
				case ID: return 585;
				case INT_LIT: return 254;
				case LITERAL: return 239;
				case LONG_IDENTIFIER: return 340;
				case LPAREN: return 228;
				case MINUS: return 237;
				case NEW: return 642;
				case NOT: return 630;
				case NULL_LIT: return 312;
				case PRIMARY: return 526;
				case SELECTABLE_PRIMARY: return 113;
				case STRING_LIT: return 522;
				case THIS: return 781;
			}
			break;
		case 396:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 389;
				case EXPRESSION3: return 1007;
				case ID: return 188;
				case INT_LIT: return 124;
				case LITERAL: return 18;
				case LONG_IDENTIFIER: return 269;
				case LPAREN: return 97;
				case NEW: return 676;
				case NOT: return 616;
				case NULL_LIT: return 759;
				case PRIMARY: return 533;
				case SELECTABLE_PRIMARY: return 152;
				case STRING_LIT: return 89;
				case THIS: return 455;
			}
			break;
		case 397:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BLOCK: return 88;
				case BLOCK_BODY: return 811;
				case BLOCK_STATEMENT: return 506;
				case BLOCK_STATEMENTS: return 388;
				case BOOLEAN: return 383;
				case BOOLEAN_LIT: return 85;
				case BYTE: return 409;
				case CHAR: return 515;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 316;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 209;
				case ID: return 428;
				case IF: return 14;
				case INT: return 416;
				case INT_LIT: return 96;
				case LBRACE: return 442;
				case LITERAL: return 296;
				case LOCAL_VARIABLE_DECLARATION_STATEMENT: return 485;
				case LONG_IDENTIFIER: return 590;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 174;
				case PRIMARY: return 242;
				case RETURN: return 474;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 313;
				case SHORT: return 527;
				case STATEMENT: return 702;
				case STATEMENT_EXPRESSION: return 165;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case TYPE: return 259;
				case WHILE: return 300;
			}
			break;
		case 398:
			switch(symbol) {
				case ABSTRACT: return 284;
				case FINAL: return 12;
				case MODIFIER: return 1228;
				case NATIVE: return 350;
				case PROTECTED: return 110;
				case PUBLIC: return 356;
				case STATIC: return 176;
			}
			break;
		case 399:
			switch(symbol) {
				case DOT: return 2;
				case LBRACKET: return 225;
				case SELECTOR: return 546;
				case SELECTORS: return 528;
			}
			break;
		case 400:
			switch(symbol) {
				case RPAREN: return 1148;
			}
			break;
		case 403:
			switch(symbol) {
				case RBRACKET: return 757;
			}
			break;
		case 404:
			switch(symbol) {
				case ARRAY: return 1107;
				case DOT: return 1217;
			}
			break;
		case 405:
			switch(symbol) {
				case ID: return 1062;
			}
			break;
		case 407:
			switch(symbol) {
				case DOT: return 1109;
				case LBRACKET: return 459;
				case SELECTOR: return 797;
			}
			break;
		case 410:
			switch(symbol) {
				case BOOLEAN_LIT: return 481;
				case CHAR_LIT: return 163;
				case EXPRESSION2: return 500;
				case EXPRESSION3: return 341;
				case ID: return 111;
				case INT_LIT: return 123;
				case LITERAL: return 504;
				case LONG_IDENTIFIER: return 290;
				case LPAREN: return 697;
				case MINUS: return 708;
				case NEW: return 384;
				case NOT: return 410;
				case NULL_LIT: return 141;
				case PRIMARY: return 298;
				case SELECTABLE_PRIMARY: return 375;
				case STRING_LIT: return 743;
				case THIS: return 169;
			}
			break;
		case 413:
			switch(symbol) {
				case BOOLEAN_LIT: return 215;
				case CHAR_LIT: return 456;
				case EXPRESSION2: return 685;
				case EXPRESSION3: return 686;
				case ID: return 621;
				case INT_LIT: return 148;
				case LITERAL: return 217;
				case LONG_IDENTIFIER: return 175;
				case LPAREN: return 461;
				case MINUS: return 413;
				case NEW: return 392;
				case NOT: return 231;
				case NULL_LIT: return 345;
				case PRIMARY: return 371;
				case SELECTABLE_PRIMARY: return 358;
				case STRING_LIT: return 626;
				case THIS: return 370;
			}
			break;
		case 414:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 974;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 853;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 415:
			switch(symbol) {
				case ID: return 841;
			}
			break;
		case 417:
			switch(symbol) {
				case CLASS_BODY: return 951;
				case IMPLEMENTS: return 799;
				case LBRACE: return 112;
			}
			break;
		case 418:
			switch(symbol) {
				case CLASS_BODY: return 674;
				case EXTENDS: return 1284;
				case IMPLEMENTS: return 849;
				case LBRACE: return 112;
			}
			break;
		case 420:
			switch(symbol) {
				case CREATOR: return 235;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 1095;
			}
			break;
		case 422:
			switch(symbol) {
				case DOT: return 940;
				case LBRACKET: return 473;
				case SELECTOR: return 102;
				case SELECTORS: return 436;
			}
			break;
		case 423:
			switch(symbol) {
				case SEMICOLON: return 796;
			}
			break;
		case 424:
			switch(symbol) {
				case RPAREN: return 510;
			}
			break;
		case 425:
			switch(symbol) {
				case BOOLEAN_LIT: return 114;
				case CHAR_LIT: return 696;
				case EXPRESSION2: return 1072;
				case EXPRESSION3: return 803;
				case ID: return 140;
				case INT_LIT: return 709;
				case LITERAL: return 328;
				case LONG_IDENTIFIER: return 272;
				case LPAREN: return 105;
				case MINUS: return 204;
				case NEW: return 444;
				case NOT: return 425;
				case NULL_LIT: return 557;
				case PRIMARY: return 291;
				case SELECTABLE_PRIMARY: return 422;
				case STRING_LIT: return 197;
				case THIS: return 653;
			}
			break;
		case 426:
			switch(symbol) {
				case CREATOR: return 447;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 913;
			}
			break;
		case 427:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 1026;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 936;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 429:
			switch(symbol) {
				case BOOLEAN_LIT: return 320;
				case CHAR_LIT: return 20;
				case EXPRESSION2: return 669;
				case EXPRESSION3: return 476;
				case ID: return 275;
				case INT_LIT: return 594;
				case LITERAL: return 250;
				case LONG_IDENTIFIER: return 277;
				case LPAREN: return 230;
				case MINUS: return 189;
				case NEW: return 420;
				case NOT: return 429;
				case NULL_LIT: return 247;
				case PRIMARY: return 168;
				case SELECTABLE_PRIMARY: return 182;
				case STRING_LIT: return 270;
				case THIS: return 592;
			}
			break;
		case 431:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 367;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 433:
			switch(symbol) {
				case RBRACKET: return 939;
			}
			break;
		case 434:
			switch(symbol) {
				case RPAREN: return 1031;
			}
			break;
		case 435:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 1180;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 619;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 436:
			switch(symbol) {
				case DOT: return 940;
				case LBRACKET: return 473;
				case SELECTOR: return 1064;
			}
			break;
		case 437:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 656;
				case CLASS_CREATOR_REST: return 303;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 438:
			switch(symbol) {
				case ID: return 1313;
			}
			break;
		case 440:
			switch(symbol) {
				case SEMICOLON: return 249;
			}
			break;
		case 441:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 747;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 442:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BLOCK: return 88;
				case BLOCK_BODY: return 154;
				case BLOCK_STATEMENT: return 506;
				case BLOCK_STATEMENTS: return 388;
				case BOOLEAN: return 383;
				case BOOLEAN_LIT: return 85;
				case BYTE: return 409;
				case CHAR: return 515;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 316;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 209;
				case ID: return 428;
				case IF: return 14;
				case INT: return 416;
				case INT_LIT: return 96;
				case LBRACE: return 442;
				case LITERAL: return 296;
				case LOCAL_VARIABLE_DECLARATION_STATEMENT: return 485;
				case LONG_IDENTIFIER: return 590;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 174;
				case PRIMARY: return 242;
				case RETURN: return 474;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 313;
				case SHORT: return 527;
				case STATEMENT: return 702;
				case STATEMENT_EXPRESSION: return 165;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case TYPE: return 259;
				case WHILE: return 300;
			}
			break;
		case 444:
			switch(symbol) {
				case CREATOR: return 1310;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 1036;
			}
			break;
		case 450:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 787;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 452:
			switch(symbol) {
				case BASIC_TYPE: return 1132;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 1218;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 457:
			switch(symbol) {
				case DOT: return 868;
				case LBRACKET: return 539;
				case SELECTOR: return 664;
				case SELECTORS: return 479;
			}
			break;
		case 459:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 1085;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 460:
			switch(symbol) {
				case RPAREN: return 23;
			}
			break;
		case 461:
			switch(symbol) {
				case BASIC_TYPE: return 793;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 701;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 462:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BOOLEAN: return 383;
				case BYTE: return 409;
				case CHAR: return 515;
				case ID: return 791;
				case INT: return 416;
				case LONG_IDENTIFIER: return 663;
				case MEMBER_DECLARATION: return 1195;
				case METHOD_OR_FIELD_DECLARATION: return 1183;
				case SHORT: return 527;
				case TYPE: return 837;
				case VOID: return 1278;
			}
			break;
		case 463:
			switch(symbol) {
				case CREATOR: return 1143;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 218;
			}
			break;
		case 466:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 839;
				case CLASS_CREATOR_REST: return 1285;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 467:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BLOCK: return 88;
				case BLOCK_BODY: return 733;
				case BLOCK_STATEMENT: return 506;
				case BLOCK_STATEMENTS: return 388;
				case BOOLEAN: return 383;
				case BOOLEAN_LIT: return 85;
				case BYTE: return 409;
				case CHAR: return 515;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 316;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 209;
				case ID: return 428;
				case IF: return 14;
				case INT: return 416;
				case INT_LIT: return 96;
				case LBRACE: return 442;
				case LITERAL: return 296;
				case LOCAL_VARIABLE_DECLARATION_STATEMENT: return 485;
				case LONG_IDENTIFIER: return 590;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 174;
				case PRIMARY: return 242;
				case RETURN: return 474;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 313;
				case SHORT: return 527;
				case STATEMENT: return 702;
				case STATEMENT_EXPRESSION: return 165;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case TYPE: return 259;
				case WHILE: return 300;
			}
			break;
		case 468:
			switch(symbol) {
				case RPAREN: return 931;
			}
			break;
		case 470:
			switch(symbol) {
				case BOOLEAN_LIT: return 322;
				case CHAR_LIT: return 287;
				case EXPRESSION2: return 1006;
				case EXPRESSION3: return 338;
				case ID: return 34;
				case INT_LIT: return 448;
				case LITERAL: return 117;
				case LONG_IDENTIFIER: return 482;
				case LPAREN: return 452;
				case MINUS: return 488;
				case NEW: return 463;
				case NOT: return 470;
				case NULL_LIT: return 583;
				case PRIMARY: return 406;
				case SELECTABLE_PRIMARY: return 266;
				case STRING_LIT: return 161;
				case THIS: return 178;
			}
			break;
		case 471:
			switch(symbol) {
				case ARRAY: return 627;
			}
			break;
		case 473:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 1175;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 474:
			switch(symbol) {
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case EXPRESSION: return 307;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case ID: return 15;
				case INT_LIT: return 96;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case PRIMARY: return 242;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 1267;
				case STRING_LIT: return 155;
				case THIS: return 25;
			}
			break;
		case 477:
			switch(symbol) {
				case BOOLEAN_LIT: return 538;
				case CHAR_LIT: return 183;
				case EXPRESSION2: return 1014;
				case EXPRESSION3: return 53;
				case ID: return 454;
				case INT_LIT: return 574;
				case LITERAL: return 40;
				case LONG_IDENTIFIER: return 511;
				case LPAREN: return 186;
				case MINUS: return 131;
				case NEW: return 426;
				case NOT: return 477;
				case NULL_LIT: return 380;
				case PRIMARY: return 265;
				case SELECTABLE_PRIMARY: return 457;
				case STRING_LIT: return 66;
				case THIS: return 75;
			}
			break;
		case 479:
			switch(symbol) {
				case DOT: return 868;
				case LBRACKET: return 539;
				case SELECTOR: return 451;
			}
			break;
		case 482:
			switch(symbol) {
				case ARGUMENTS: return 1049;
				case DOT: return 342;
				case IDENTIFIER_SUFFIX: return 1190;
				case LBRACKET: return 1219;
				case LPAREN: return 324;
			}
			break;
		case 483:
			switch(symbol) {
				case ARRAY: return 336;
				case DOT: return 1210;
			}
			break;
		case 487:
			switch(symbol) {
				case DOT: return 896;
				case LBRACKET: return 661;
				case SELECTOR: return 315;
			}
			break;
		case 488:
			switch(symbol) {
				case BOOLEAN_LIT: return 322;
				case CHAR_LIT: return 287;
				case EXPRESSION2: return 419;
				case EXPRESSION3: return 338;
				case ID: return 34;
				case INT_LIT: return 448;
				case LITERAL: return 117;
				case LONG_IDENTIFIER: return 482;
				case LPAREN: return 452;
				case MINUS: return 488;
				case NEW: return 463;
				case NOT: return 470;
				case NULL_LIT: return 583;
				case PRIMARY: return 406;
				case SELECTABLE_PRIMARY: return 266;
				case STRING_LIT: return 161;
				case THIS: return 178;
			}
			break;
		case 489:
			switch(symbol) {
				case BOOLEAN_LIT: return 215;
				case CHAR_LIT: return 456;
				case EXPRESSION3: return 768;
				case ID: return 621;
				case INT_LIT: return 148;
				case LITERAL: return 217;
				case LONG_IDENTIFIER: return 175;
				case LPAREN: return 461;
				case NEW: return 392;
				case NOT: return 231;
				case NULL_LIT: return 345;
				case PRIMARY: return 371;
				case SELECTABLE_PRIMARY: return 358;
				case STRING_LIT: return 626;
				case THIS: return 370;
			}
			break;
		case 492:
			switch(symbol) {
				case BOOLEAN_LIT: return 322;
				case CHAR_LIT: return 287;
				case EXPRESSION3: return 346;
				case ID: return 34;
				case INT_LIT: return 448;
				case LITERAL: return 117;
				case LONG_IDENTIFIER: return 482;
				case LPAREN: return 452;
				case NEW: return 463;
				case NOT: return 470;
				case NULL_LIT: return 583;
				case PRIMARY: return 406;
				case SELECTABLE_PRIMARY: return 266;
				case STRING_LIT: return 161;
				case THIS: return 178;
			}
			break;
		case 493:
			switch(symbol) {
				case RPAREN: return 628;
			}
			break;
		case 494:
			switch(symbol) {
				case LPAREN: return 499;
				case PAR_EXPRESSION: return 1185;
			}
			break;
		case 497:
			switch(symbol) {
				case ID: return 323;
			}
			break;
		case 499:
			switch(symbol) {
				case BOOLEAN_LIT: return 136;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 688;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 510:
			switch(symbol) {
				case BOOLEAN_LIT: return 538;
				case CHAR_LIT: return 183;
				case EXPRESSION3: return 840;
				case ID: return 454;
				case INT_LIT: return 574;
				case LITERAL: return 40;
				case LONG_IDENTIFIER: return 511;
				case LPAREN: return 186;
				case NEW: return 426;
				case NOT: return 477;
				case NULL_LIT: return 380;
				case PRIMARY: return 265;
				case SELECTABLE_PRIMARY: return 457;
				case STRING_LIT: return 66;
				case THIS: return 75;
			}
			break;
		case 511:
			switch(symbol) {
				case ARGUMENTS: return 472;
				case DOT: return 1108;
				case IDENTIFIER_SUFFIX: return 964;
				case LBRACKET: return 1281;
				case LPAREN: return 194;
			}
			break;
		case 512:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 1240;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 513:
			switch(symbol) {
				case BASIC_TYPE: return 820;
				case BOOLEAN: return 294;
				case BYTE: return 1312;
				case CHAR: return 927;
				case ID: return 945;
				case INT: return 826;
				case LONG_IDENTIFIER: return 483;
				case SHORT: return 772;
				case TYPE: return 962;
			}
			break;
		case 521:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION3: return 187;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 528:
			switch(symbol) {
				case DOT: return 2;
				case LBRACKET: return 225;
				case SELECTOR: return 1179;
			}
			break;
		case 530:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 542;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 532:
			switch(symbol) {
				case RBRACKET: return 1211;
			}
			break;
		case 535:
			switch(symbol) {
				case RPAREN: return 1289;
			}
			break;
		case 536:
			switch(symbol) {
				case BOOLEAN_LIT: return 136;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 782;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case FOR_UPDATE: return 430;
				case FOR_UPDATE_OPT: return 870;
				case ID: return 181;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case STATEMENT_EXPRESSION: return 386;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 539:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 784;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 542:
			switch(symbol) {
				case RBRACKET: return 864;
			}
			break;
		case 545:
			switch(symbol) {
				case LPAREN: return 879;
			}
			break;
		case 549:
			switch(symbol) {
				case BLOCK: return 88;
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 1171;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 209;
				case ID: return 15;
				case IF: return 14;
				case INT_LIT: return 96;
				case LBRACE: return 442;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 205;
				case PRIMARY: return 242;
				case RETURN: return 474;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 313;
				case STATEMENT_EXPRESSION: return 165;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case WHILE: return 300;
			}
			break;
		case 551:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 1193;
			}
			break;
		case 553:
			switch(symbol) {
				case CLASS_BODY: return 806;
				case COMMA: return 850;
				case LBRACE: return 112;
			}
			break;
		case 555:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 1239;
			}
			break;
		case 558:
			switch(symbol) {
				case CLASS_BODY: return 1255;
				case COMMA: return 850;
				case LBRACE: return 112;
			}
			break;
		case 560:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BOOLEAN: return 383;
				case BYTE: return 409;
				case CHAR: return 515;
				case FORMAL_PARAMETER: return 1197;
				case FORMAL_PARAMETERS_OPT: return 569;
				case FORMAL_PARAMETER_LIST: return 101;
				case ID: return 586;
				case INT: return 416;
				case LONG_IDENTIFIER: return 663;
				case SHORT: return 527;
				case TYPE: return 695;
			}
			break;
		case 563:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 253;
				case CLASS_CREATOR_REST: return 711;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 565:
			switch(symbol) {
				case RPAREN: return 1234;
			}
			break;
		case 568:
			switch(symbol) {
				case RBRACKET: return 378;
			}
			break;
		case 569:
			switch(symbol) {
				case RPAREN: return 534;
			}
			break;
		case 573:
			switch(symbol) {
				case LPAREN: return 996;
			}
			break;
		case 575:
			switch(symbol) {
				case RBRACKET: return 498;
			}
			break;
		case 577:
			switch(symbol) {
				case RPAREN: return 368;
			}
			break;
		case 579:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 976;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 580:
			switch(symbol) {
				case BOOLEAN_LIT: return 114;
				case CHAR_LIT: return 696;
				case EXPRESSION2: return 1214;
				case EXPRESSION3: return 803;
				case ID: return 140;
				case INT_LIT: return 709;
				case LITERAL: return 328;
				case LONG_IDENTIFIER: return 272;
				case LPAREN: return 105;
				case MINUS: return 204;
				case NEW: return 444;
				case NOT: return 425;
				case NULL_LIT: return 557;
				case PRIMARY: return 291;
				case SELECTABLE_PRIMARY: return 422;
				case STRING_LIT: return 197;
				case THIS: return 653;
			}
			break;
		case 581:
			switch(symbol) {
				case RPAREN: return 1115;
			}
			break;
		case 590:
			switch(symbol) {
				case ARGUMENTS: return 1236;
				case ARRAY: return 273;
				case DOT: return 692;
				case IDENTIFIER_SUFFIX: return 271;
				case LBRACKET: return 450;
				case LPAREN: return 122;
			}
			break;
		case 595:
			switch(symbol) {
				case ARGUMENTS: return 121;
				case ARGUMENTS_OPT: return 769;
				case LPAREN: return 414;
			}
			break;
		case 599:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case EXPRESSION1_REST: return 699;
				case EXPRESSION_INFIX: return 779;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 902;
				case INSTANCEOF: return 689;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 604:
			switch(symbol) {
				case BOOLEAN_LIT: return 320;
				case CHAR_LIT: return 20;
				case EXPRESSION2: return 1241;
				case EXPRESSION3: return 476;
				case ID: return 275;
				case INT_LIT: return 594;
				case LITERAL: return 250;
				case LONG_IDENTIFIER: return 277;
				case LPAREN: return 230;
				case MINUS: return 189;
				case NEW: return 420;
				case NOT: return 429;
				case NULL_LIT: return 247;
				case PRIMARY: return 168;
				case SELECTABLE_PRIMARY: return 182;
				case STRING_LIT: return 270;
				case THIS: return 592;
			}
			break;
		case 609:
			switch(symbol) {
				case ID: return 381;
			}
			break;
		case 613:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 555;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 453;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 614:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 1159;
				case CLASS_CREATOR_REST: return 928;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 616:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 389;
				case EXPRESSION2: return 941;
				case EXPRESSION3: return 244;
				case ID: return 188;
				case INT_LIT: return 124;
				case LITERAL: return 18;
				case LONG_IDENTIFIER: return 269;
				case LPAREN: return 97;
				case MINUS: return 138;
				case NEW: return 676;
				case NOT: return 616;
				case NULL_LIT: return 759;
				case PRIMARY: return 533;
				case SELECTABLE_PRIMARY: return 152;
				case STRING_LIT: return 89;
				case THIS: return 455;
			}
			break;
		case 618:
			switch(symbol) {
				case ARGUMENTS: return 1168;
				case DOT: return 130;
				case IDENTIFIER_SUFFIX: return 961;
				case LBRACKET: return 283;
				case LPAREN: return 623;
			}
			break;
		case 620:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 1033;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 888;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 623:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 739;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 91;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 624:
			switch(symbol) {
				case RBRACKET: return 27;
			}
			break;
		case 625:
			switch(symbol) {
				case BOOLEAN_LIT: return 238;
				case CHAR_LIT: return 376;
				case EXPRESSION1: return 800;
				case EXPRESSION2: return 801;
				case EXPRESSION3: return 343;
				case ID: return 233;
				case INT_LIT: return 19;
				case LITERAL: return 171;
				case LONG_IDENTIFIER: return 362;
				case LPAREN: return 359;
				case MINUS: return 314;
				case NEW: return 707;
				case NOT: return 712;
				case NULL_LIT: return 762;
				case PRIMARY: return 289;
				case SELECTABLE_PRIMARY: return 717;
				case STRING_LIT: return 129;
				case THIS: return 443;
			}
			break;
		case 630:
			switch(symbol) {
				case BOOLEAN_LIT: return 232;
				case CHAR_LIT: return 561;
				case EXPRESSION2: return 1069;
				case EXPRESSION3: return 57;
				case ID: return 585;
				case INT_LIT: return 254;
				case LITERAL: return 239;
				case LONG_IDENTIFIER: return 340;
				case LPAREN: return 228;
				case MINUS: return 237;
				case NEW: return 642;
				case NOT: return 630;
				case NULL_LIT: return 312;
				case PRIMARY: return 526;
				case SELECTABLE_PRIMARY: return 113;
				case STRING_LIT: return 522;
				case THIS: return 781;
			}
			break;
		case 635:
			switch(symbol) {
				case BOOLEAN_LIT: return 87;
				case CHAR_LIT: return 334;
				case EXPRESSION2: return 805;
				case EXPRESSION3: return 607;
				case ID: return 660;
				case INT_LIT: return 299;
				case LITERAL: return 46;
				case LONG_IDENTIFIER: return 261;
				case LPAREN: return 305;
				case MINUS: return 139;
				case NEW: return 1;
				case NOT: return 137;
				case NULL_LIT: return 496;
				case PRIMARY: return 446;
				case SELECTABLE_PRIMARY: return 399;
				case STRING_LIT: return 349;
				case THIS: return 402;
			}
			break;
		case 638:
			switch(symbol) {
				case ID: return 543;
			}
			break;
		case 642:
			switch(symbol) {
				case CREATOR: return 1016;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 13;
			}
			break;
		case 643:
			switch(symbol) {
				case RPAREN: return 412;
			}
			break;
		case 646:
			switch(symbol) {
				case RPAREN: return 722;
			}
			break;
		case 652:
			switch(symbol) {
				case ID: return 1172;
			}
			break;
		case 656:
			switch(symbol) {
				case RPAREN: return 725;
			}
			break;
		case 657:
			switch(symbol) {
				case ID: return 958;
			}
			break;
		case 661:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 1104;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 663:
			switch(symbol) {
				case ARRAY: return 273;
				case DOT: return 609;
			}
			break;
		case 666:
			switch(symbol) {
				case ARGUMENTS: return 1229;
				case ARGUMENTS_OPT: return 508;
				case LPAREN: return 818;
			}
			break;
		case 667:
			switch(symbol) {
				case COMPILER_UNIT: return 947;
				case PACKAGE: return 988;
				case PACKAGE_DECLARATION: return 153;
			}
			break;
		case 668:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 17;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 671:
			switch(symbol) {
				case ID: return 1015;
			}
			break;
		case 676:
			switch(symbol) {
				case CREATOR: return 1191;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 679;
			}
			break;
		case 678:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 1174;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 1248;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 679:
			switch(symbol) {
				case LPAREN: return 1247;
			}
			break;
		case 680:
			switch(symbol) {
				case DOT: return 59;
				case LBRACKET: return 240;
				case SELECTOR: return 608;
				case SELECTORS: return 1009;
			}
			break;
		case 683:
			switch(symbol) {
				case ID: return 1156;
			}
			break;
		case 687:
			switch(symbol) {
				case RBRACKET: return 650;
			}
			break;
		case 688:
			switch(symbol) {
				case RPAREN: return 819;
			}
			break;
		case 689:
			switch(symbol) {
				case BASIC_TYPE: return 997;
				case BOOLEAN: return 1128;
				case BYTE: return 991;
				case CHAR: return 578;
				case ID: return 612;
				case INT: return 382;
				case LONG_IDENTIFIER: return 1261;
				case SHORT: return 681;
				case TYPE: return 637;
			}
			break;
		case 690:
			switch(symbol) {
				case ID: return 418;
			}
			break;
		case 692:
			switch(symbol) {
				case ID: return 684;
			}
			break;
		case 694:
			switch(symbol) {
				case ID: return 63;
				case MULT: return 858;
			}
			break;
		case 695:
			switch(symbol) {
				case ID: return 633;
				case VARIABLE_DECLARATOR_ID: return 785;
			}
			break;
		case 697:
			switch(symbol) {
				case BASIC_TYPE: return 577;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 400;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 698:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 288;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 700:
			switch(symbol) {
				case BLOCK: return 297;
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 983;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 47;
				case ID: return 15;
				case IF: return 147;
				case INT_LIT: return 96;
				case LBRACE: return 467;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 174;
				case PRIMARY: return 242;
				case RETURN: return 377;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 525;
				case STATEMENT: return 509;
				case STATEMENT_EXPRESSION: return 199;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case WHILE: return 494;
			}
			break;
		case 701:
			switch(symbol) {
				case RPAREN: return 489;
			}
			break;
		case 703:
			switch(symbol) {
				case ID: return 788;
			}
			break;
		case 707:
			switch(symbol) {
				case CREATOR: return 827;
				case ID: return 196;
				case LONG_IDENTIFIER: return 391;
				case QUALIFIED_IDENTIFIER: return 545;
			}
			break;
		case 708:
			switch(symbol) {
				case BOOLEAN_LIT: return 481;
				case CHAR_LIT: return 163;
				case EXPRESSION2: return 520;
				case EXPRESSION3: return 341;
				case ID: return 111;
				case INT_LIT: return 123;
				case LITERAL: return 504;
				case LONG_IDENTIFIER: return 290;
				case LPAREN: return 697;
				case MINUS: return 708;
				case NEW: return 384;
				case NOT: return 410;
				case NULL_LIT: return 141;
				case PRIMARY: return 298;
				case SELECTABLE_PRIMARY: return 375;
				case STRING_LIT: return 743;
				case THIS: return 169;
			}
			break;
		case 710:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 604;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 711:
			switch(symbol) {
				case RPAREN: return 1243;
			}
			break;
		case 712:
			switch(symbol) {
				case BOOLEAN_LIT: return 238;
				case CHAR_LIT: return 376;
				case EXPRESSION2: return 1131;
				case EXPRESSION3: return 343;
				case ID: return 233;
				case INT_LIT: return 19;
				case LITERAL: return 171;
				case LONG_IDENTIFIER: return 362;
				case LPAREN: return 359;
				case MINUS: return 314;
				case NEW: return 707;
				case NOT: return 712;
				case NULL_LIT: return 762;
				case PRIMARY: return 289;
				case SELECTABLE_PRIMARY: return 717;
				case STRING_LIT: return 129;
				case THIS: return 443;
			}
			break;
		case 713:
			switch(symbol) {
				case RBRACKET: return 662;
			}
			break;
		case 717:
			switch(symbol) {
				case DOT: return 812;
				case LBRACKET: return 755;
				case SELECTOR: return 1118;
				case SELECTORS: return 1244;
			}
			break;
		case 718:
			switch(symbol) {
				case DOT: return 855;
				case LBRACKET: return 668;
				case SELECTOR: return 1187;
			}
			break;
		case 719:
			switch(symbol) {
				case BASIC_TYPE: return 764;
				case BOOLEAN: return 257;
				case BOOLEAN_LIT: return 136;
				case BYTE: return 43;
				case CHAR: return 263;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 903;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case ID: return 181;
				case INT: return 458;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case SHORT: return 226;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 726:
			switch(symbol) {
				case RPAREN: return 521;
			}
			break;
		case 727:
			switch(symbol) {
				case RBRACKET: return 1119;
			}
			break;
		case 731:
			switch(symbol) {
				case ARGUMENTS: return 880;
				case ARGUMENTS_OPT: return 469;
				case LPAREN: return 194;
			}
			break;
		case 732:
			switch(symbol) {
				case ID: return 900;
			}
			break;
		case 733:
			switch(symbol) {
				case RBRACE: return 490;
			}
			break;
		case 734:
			switch(symbol) {
				case BOOLEAN_LIT: return 87;
				case CHAR_LIT: return 334;
				case EXPRESSION2: return 1269;
				case EXPRESSION3: return 607;
				case ID: return 660;
				case INT_LIT: return 299;
				case LITERAL: return 46;
				case LONG_IDENTIFIER: return 261;
				case LPAREN: return 305;
				case MINUS: return 139;
				case NEW: return 1;
				case NOT: return 137;
				case NULL_LIT: return 496;
				case PRIMARY: return 446;
				case SELECTABLE_PRIMARY: return 399;
				case STRING_LIT: return 349;
				case THIS: return 402;
			}
			break;
		case 735:
			switch(symbol) {
				case ARGUMENTS: return 24;
				case ARGUMENTS_OPT: return 919;
				case LPAREN: return 324;
			}
			break;
		case 736:
			switch(symbol) {
				case BOOLEAN_LIT: return 232;
				case CHAR_LIT: return 561;
				case EXPRESSION2: return 58;
				case EXPRESSION3: return 57;
				case ID: return 585;
				case INT_LIT: return 254;
				case LITERAL: return 239;
				case LONG_IDENTIFIER: return 340;
				case LPAREN: return 228;
				case MINUS: return 237;
				case NEW: return 642;
				case NOT: return 630;
				case NULL_LIT: return 312;
				case PRIMARY: return 526;
				case SELECTABLE_PRIMARY: return 113;
				case STRING_LIT: return 522;
				case THIS: return 781;
			}
			break;
		case 737:
			switch(symbol) {
				case ARRAY: return 934;
			}
			break;
		case 739:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 828;
			}
			break;
		case 741:
			switch(symbol) {
				case BOOLEAN_LIT: return 67;
				case CHAR_LIT: return 505;
				case EXPRESSION2: return 629;
				case EXPRESSION3: return 598;
				case ID: return 9;
				case INT_LIT: return 636;
				case LITERAL: return 158;
				case LONG_IDENTIFIER: return 618;
				case LPAREN: return 719;
				case MINUS: return 741;
				case NEW: return 173;
				case NOT: return 208;
				case NULL_LIT: return 742;
				case PRIMARY: return 223;
				case SELECTABLE_PRIMARY: return 680;
				case STRING_LIT: return 99;
				case THIS: return 547;
			}
			break;
		case 744:
			switch(symbol) {
				case BOOLEAN_LIT: return 67;
				case CHAR_LIT: return 505;
				case EXPRESSION1: return 600;
				case EXPRESSION2: return 599;
				case EXPRESSION3: return 598;
				case ID: return 9;
				case INT_LIT: return 636;
				case LITERAL: return 158;
				case LONG_IDENTIFIER: return 618;
				case LPAREN: return 719;
				case MINUS: return 741;
				case NEW: return 173;
				case NOT: return 208;
				case NULL_LIT: return 742;
				case PRIMARY: return 223;
				case SELECTABLE_PRIMARY: return 680;
				case STRING_LIT: return 99;
				case THIS: return 547;
			}
			break;
		case 745:
			switch(symbol) {
				case ABSTRACT: return 284;
				case FINAL: return 12;
				case INTERFACE_BODY_DECLARATION: return 347;
				case INTERFACE_BODY_DECLARATIONS: return 245;
				case MODIFIER: return 647;
				case MODIFIERS: return 398;
				case MODIFIERS_OPT: return 881;
				case NATIVE: return 350;
				case PROTECTED: return 110;
				case PUBLIC: return 356;
				case RBRACE: return 720;
				case SEMICOLON: return 1066;
				case STATIC: return 176;
			}
			break;
		case 746:
			switch(symbol) {
				case BASIC_TYPE: return 904;
				case BOOLEAN: return 576;
				case BYTE: return 1235;
				case CHAR: return 554;
				case ID: return 572;
				case INT: return 352;
				case LONG_IDENTIFIER: return 1000;
				case SHORT: return 610;
				case TYPE: return 603;
			}
			break;
		case 747:
			switch(symbol) {
				case RBRACKET: return 125;
			}
			break;
		case 750:
			switch(symbol) {
				case ID: return 735;
			}
			break;
		case 752:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case EXPRESSION1_REST: return 1206;
				case EXPRESSION_INFIX: return 143;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 286;
				case INSTANCEOF: return 746;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 755:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 403;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 756:
			switch(symbol) {
				case DOT: return 132;
				case LBRACKET: return 280;
				case SELECTOR: return 1099;
			}
			break;
		case 758:
			switch(symbol) {
				case ABSTRACT: return 1202;
				case FINAL: return 979;
				case MODIFIER: return 1297;
				case NATIVE: return 914;
				case PROTECTED: return 1145;
				case PUBLIC: return 256;
				case STATIC: return 369;
			}
			break;
		case 760:
			switch(symbol) {
				case RPAREN: return 965;
			}
			break;
		case 761:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION3: return 1004;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 764:
			switch(symbol) {
				case RPAREN: return 1225;
			}
			break;
		case 765:
			switch(symbol) {
				case RPAREN: return 670;
			}
			break;
		case 766:
			switch(symbol) {
				case RPAREN: return 635;
			}
			break;
		case 770:
			switch(symbol) {
				case ARGUMENTS: return 631;
				case ARGUMENTS_OPT: return 615;
				case LPAREN: return 122;
			}
			break;
		case 774:
			switch(symbol) {
				case RPAREN: return 1209;
			}
			break;
		case 777:
			switch(symbol) {
				case ID: return 1280;
			}
			break;
		case 779:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 734;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 780:
			switch(symbol) {
				case ABSTRACT: return 284;
				case CLASS_BODY_DECLARATION: return 935;
				case FINAL: return 12;
				case MODIFIER: return 647;
				case MODIFIERS: return 398;
				case MODIFIERS_OPT: return 462;
				case NATIVE: return 350;
				case PROTECTED: return 110;
				case PUBLIC: return 356;
				case RBRACE: return 1263;
				case SEMICOLON: return 390;
				case STATIC: return 176;
			}
			break;
		case 784:
			switch(symbol) {
				case RBRACKET: return 654;
			}
			break;
		case 786:
			switch(symbol) {
				case SEMICOLON: return 536;
			}
			break;
		case 787:
			switch(symbol) {
				case RBRACKET: return 582;
			}
			break;
		case 791:
			switch(symbol) {
				case CONSTRUCTOR_DECLARATOR_REST: return 1097;
				case FORMAL_PARAMETERS: return 885;
				case LPAREN: return 932;
			}
			break;
		case 792:
			switch(symbol) {
				case ARRAY: return 967;
			}
			break;
		case 793:
			switch(symbol) {
				case RPAREN: return 895;
			}
			break;
		case 795:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 389;
				case EXPRESSION2: return 1136;
				case EXPRESSION3: return 244;
				case ID: return 188;
				case INT_LIT: return 124;
				case LITERAL: return 18;
				case LONG_IDENTIFIER: return 269;
				case LPAREN: return 97;
				case MINUS: return 138;
				case NEW: return 676;
				case NOT: return 616;
				case NULL_LIT: return 759;
				case PRIMARY: return 533;
				case SELECTABLE_PRIMARY: return 152;
				case STRING_LIT: return 89;
				case THIS: return 455;
			}
			break;
		case 798:
			switch(symbol) {
				case BASIC_TYPE: return 863;
				case BOOLEAN: return 1046;
				case BYTE: return 915;
				case CHAR: return 1246;
				case ID: return 1295;
				case INT: return 127;
				case LONG_IDENTIFIER: return 854;
				case SHORT: return 1154;
				case TYPE: return 1272;
			}
			break;
		case 799:
			switch(symbol) {
				case BASIC_TYPE: return 201;
				case BOOLEAN: return 103;
				case BYTE: return 1130;
				case CHAR: return 584;
				case ID: return 564;
				case INT: return 645;
				case LONG_IDENTIFIER: return 404;
				case SHORT: return 550;
				case TYPE: return 559;
				case TYPE_LIST: return 553;
			}
			break;
		case 801:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case EXPRESSION1_REST: return 1068;
				case EXPRESSION_INFIX: return 1275;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 395;
				case INSTANCEOF: return 159;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 807:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 1027;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 808:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 566;
			}
			break;
		case 810:
			switch(symbol) {
				case RBRACKET: return 648;
			}
			break;
		case 811:
			switch(symbol) {
				case RBRACE: return 978;
			}
			break;
		case 812:
			switch(symbol) {
				case ID: return 921;
			}
			break;
		case 814:
			switch(symbol) {
				case RBRACKET: return 1073;
			}
			break;
		case 815:
			switch(symbol) {
				case RBRACKET: return 439;
			}
			break;
		case 818:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 1056;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 1253;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 820:
			switch(symbol) {
				case ARRAY: return 754;
			}
			break;
		case 821:
			switch(symbol) {
				case COMMA: return 850;
				case INTERFACE_BODY: return 514;
				case LBRACE: return 745;
			}
			break;
		case 829:
			switch(symbol) {
				case BOOLEAN_LIT: return 311;
				case CHAR_LIT: return 326;
				case EXPRESSION2: return 1205;
				case EXPRESSION3: return 749;
				case ID: return 524;
				case INT_LIT: return 465;
				case LITERAL: return 372;
				case LONG_IDENTIFIER: return 68;
				case LPAREN: return 76;
				case MINUS: return 116;
				case NEW: return 16;
				case NOT: return 387;
				case NULL_LIT: return 49;
				case PRIMARY: return 639;
				case SELECTABLE_PRIMARY: return 172;
				case STRING_LIT: return 540;
				case THIS: return 260;
			}
			break;
		case 830:
			switch(symbol) {
				case ID: return 203;
			}
			break;
		case 834:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 39;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 835:
			switch(symbol) {
				case ARRAY: return 823;
				case DOT: return 652;
			}
			break;
		case 836:
			switch(symbol) {
				case RBRACKET: return 920;
			}
			break;
		case 837:
			switch(symbol) {
				case ID: return 969;
			}
			break;
		case 839:
			switch(symbol) {
				case RPAREN: return 918;
			}
			break;
		case 843:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 357;
			}
			break;
		case 846:
			switch(symbol) {
				case BOOLEAN_LIT: return 311;
				case CHAR_LIT: return 326;
				case EXPRESSION3: return 588;
				case ID: return 524;
				case INT_LIT: return 465;
				case LITERAL: return 372;
				case LONG_IDENTIFIER: return 68;
				case LPAREN: return 76;
				case NEW: return 16;
				case NOT: return 387;
				case NULL_LIT: return 49;
				case PRIMARY: return 639;
				case SELECTABLE_PRIMARY: return 172;
				case STRING_LIT: return 540;
				case THIS: return 260;
			}
			break;
		case 847:
			switch(symbol) {
				case ID: return 851;
			}
			break;
		case 849:
			switch(symbol) {
				case BASIC_TYPE: return 201;
				case BOOLEAN: return 103;
				case BYTE: return 1130;
				case CHAR: return 584;
				case ID: return 564;
				case INT: return 645;
				case LONG_IDENTIFIER: return 404;
				case SHORT: return 550;
				case TYPE: return 559;
				case TYPE_LIST: return 558;
			}
			break;
		case 850:
			switch(symbol) {
				case BASIC_TYPE: return 201;
				case BOOLEAN: return 103;
				case BYTE: return 1130;
				case CHAR: return 584;
				case ID: return 564;
				case INT: return 645;
				case LONG_IDENTIFIER: return 404;
				case SHORT: return 550;
				case TYPE: return 262;
			}
			break;
		case 854:
			switch(symbol) {
				case ARRAY: return 1089;
				case DOT: return 405;
			}
			break;
		case 855:
			switch(symbol) {
				case ID: return 980;
			}
			break;
		case 858:
			switch(symbol) {
				case SEMICOLON: return 1123;
			}
			break;
		case 860:
			switch(symbol) {
				case ID: return 331;
			}
			break;
		case 861:
			switch(symbol) {
				case SEMICOLON: return 319;
			}
			break;
		case 863:
			switch(symbol) {
				case ARRAY: return 802;
			}
			break;
		case 866:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 713;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 867:
			switch(symbol) {
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case EXPRESSION2: return 894;
				case EXPRESSION3: return 55;
				case ID: return 15;
				case INT_LIT: return 96;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case PRIMARY: return 242;
				case SELECTABLE_PRIMARY: return 278;
				case STRING_LIT: return 155;
				case THIS: return 25;
			}
			break;
		case 868:
			switch(symbol) {
				case ID: return 731;
			}
			break;
		case 870:
			switch(symbol) {
				case RPAREN: return 1082;
			}
			break;
		case 871:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 1063;
				case CLASS_CREATOR_REST: return 1018;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 876:
			switch(symbol) {
				case RPAREN: return 1201;
			}
			break;
		case 878:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case EXPRESSION1_REST: return 1133;
				case EXPRESSION_INFIX: return 1307;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 960;
				case INSTANCEOF: return 1138;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 879:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 774;
				case CLASS_CREATOR_REST: return 1215;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 881:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BOOLEAN: return 383;
				case BYTE: return 409;
				case CHAR: return 515;
				case ID: return 586;
				case INT: return 416;
				case INTERFACE_MEMBER_DECLARATION: return 106;
				case INTERFACE_METHOD_OR_FIELD_DECLARATION: return 789;
				case LONG_IDENTIFIER: return 663;
				case SHORT: return 527;
				case TYPE: return 860;
				case VOID: return 149;
			}
			break;
		case 882:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 810;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 885:
			switch(symbol) {
				case BLOCK: return 562;
				case LBRACE: return 397;
				case METHOD_BODY: return 591;
			}
			break;
		case 889:
			switch(symbol) {
				case ID: return 65;
			}
			break;
		case 890:
			switch(symbol) {
				case BOOLEAN_LIT: return 136;
				case CHAR_LIT: return 48;
				case EXPRESSION: return 782;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case EXPRESSION3: return 118;
				case FOR_UPDATE: return 430;
				case FOR_UPDATE_OPT: return 393;
				case ID: return 181;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case MINUS: return 6;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case STATEMENT_EXPRESSION: return 386;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 891:
			switch(symbol) {
				case RPAREN: return 883;
			}
			break;
		case 892:
			switch(symbol) {
				case ID: return 267;
			}
			break;
		case 895:
			switch(symbol) {
				case BOOLEAN_LIT: return 215;
				case CHAR_LIT: return 456;
				case EXPRESSION2: return 833;
				case EXPRESSION3: return 686;
				case ID: return 621;
				case INT_LIT: return 148;
				case LITERAL: return 217;
				case LONG_IDENTIFIER: return 175;
				case LPAREN: return 461;
				case MINUS: return 413;
				case NEW: return 392;
				case NOT: return 231;
				case NULL_LIT: return 345;
				case PRIMARY: return 371;
				case SELECTABLE_PRIMARY: return 358;
				case STRING_LIT: return 626;
				case THIS: return 370;
			}
			break;
		case 896:
			switch(symbol) {
				case ID: return 1298;
			}
			break;
		case 899:
			switch(symbol) {
				case RBRACKET: return 824;
			}
			break;
		case 901:
			switch(symbol) {
				case ABSTRACT: return 1202;
				case CLASS_OR_INTERFACE_DECLARATION: return 677;
				case FINAL: return 979;
				case MODIFIER: return 1008;
				case MODIFIERS: return 758;
				case MODIFIERS_OPT: return 973;
				case NATIVE: return 914;
				case PROTECTED: return 1145;
				case PUBLIC: return 256;
				case SEMICOLON: return 1257;
				case STATIC: return 369;
				case TYPE_DECLARATION: return 1294;
				case TYPE_DECLARATIONS_OPT: return 1105;
			}
			break;
		case 902:
			switch(symbol) {
				case BOOLEAN_LIT: return 87;
				case CHAR_LIT: return 334;
				case EXPRESSION2: return 606;
				case EXPRESSION3: return 607;
				case ID: return 660;
				case INT_LIT: return 299;
				case LITERAL: return 46;
				case LONG_IDENTIFIER: return 261;
				case LPAREN: return 305;
				case MINUS: return 139;
				case NEW: return 1;
				case NOT: return 137;
				case NULL_LIT: return 496;
				case PRIMARY: return 446;
				case SELECTABLE_PRIMARY: return 399;
				case STRING_LIT: return 349;
				case THIS: return 402;
			}
			break;
		case 903:
			switch(symbol) {
				case RPAREN: return 1259;
			}
			break;
		case 904:
			switch(symbol) {
				case ARRAY: return 968;
			}
			break;
		case 905:
			switch(symbol) {
				case ARGUMENTS: return 832;
				case ARGUMENTS_OPT: return 519;
				case LPAREN: return 335;
			}
			break;
		case 906:
			switch(symbol) {
				case BOOLEAN_LIT: return 322;
				case CHAR_LIT: return 287;
				case EXPRESSION2: return 1200;
				case EXPRESSION3: return 338;
				case ID: return 34;
				case INT_LIT: return 448;
				case LITERAL: return 117;
				case LONG_IDENTIFIER: return 482;
				case LPAREN: return 452;
				case MINUS: return 488;
				case NEW: return 463;
				case NOT: return 470;
				case NULL_LIT: return 583;
				case PRIMARY: return 406;
				case SELECTABLE_PRIMARY: return 266;
				case STRING_LIT: return 161;
				case THIS: return 178;
			}
			break;
		case 907:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 687;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 910:
			switch(symbol) {
				case ARGUMENTS: return 1256;
				case ARGUMENTS_OPT: return 601;
				case LPAREN: return 427;
			}
			break;
		case 911:
			switch(symbol) {
				case FORMAL_PARAMETERS: return 423;
				case INTERFACE_METHOD_DECLARATOR_REST: return 229;
				case LPAREN: return 560;
			}
			break;
		case 912:
			switch(symbol) {
				case SEMICOLON: return 432;
			}
			break;
		case 913:
			switch(symbol) {
				case LPAREN: return 614;
			}
			break;
		case 916:
			switch(symbol) {
				case RPAREN: return 449;
			}
			break;
		case 921:
			switch(symbol) {
				case ARGUMENTS: return 778;
				case ARGUMENTS_OPT: return 1126;
				case LPAREN: return 282;
			}
			break;
		case 923:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BOOLEAN: return 383;
				case BOOLEAN_LIT: return 85;
				case BYTE: return 409;
				case CHAR: return 515;
				case CHAR_LIT: return 92;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR_INIT: return 213;
				case FOR_INIT_OPT: return 1283;
				case ID: return 428;
				case INT: return 416;
				case INT_LIT: return 96;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 590;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case PRIMARY: return 242;
				case SELECTABLE_PRIMARY: return 278;
				case SHORT: return 527;
				case STATEMENT_EXPRESSION: return 327;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case TYPE: return 1157;
			}
			break;
		case 924:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION2: return 1043;
				case EXPRESSION3: return 220;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 925:
			switch(symbol) {
				case RPAREN: return 1305;
			}
			break;
		case 926:
			switch(symbol) {
				case ID: return 893;
			}
			break;
		case 928:
			switch(symbol) {
				case RPAREN: return 361;
			}
			break;
		case 930:
			switch(symbol) {
				case RPAREN: return 363;
			}
			break;
		case 932:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BOOLEAN: return 383;
				case BYTE: return 409;
				case CHAR: return 515;
				case FORMAL_PARAMETER: return 1197;
				case FORMAL_PARAMETERS_OPT: return 1149;
				case FORMAL_PARAMETER_LIST: return 101;
				case ID: return 586;
				case INT: return 416;
				case LONG_IDENTIFIER: return 663;
				case SHORT: return 527;
				case TYPE: return 695;
			}
			break;
		case 933:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 916;
				case CLASS_CREATOR_REST: return 643;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 940:
			switch(symbol) {
				case ID: return 905;
			}
			break;
		case 946:
			switch(symbol) {
				case BOOLEAN_LIT: return 481;
				case CHAR_LIT: return 163;
				case EXPRESSION1: return 877;
				case EXPRESSION2: return 878;
				case EXPRESSION3: return 341;
				case ID: return 111;
				case INT_LIT: return 123;
				case LITERAL: return 504;
				case LONG_IDENTIFIER: return 290;
				case LPAREN: return 697;
				case MINUS: return 708;
				case NEW: return 384;
				case NOT: return 410;
				case NULL_LIT: return 141;
				case PRIMARY: return 298;
				case SELECTABLE_PRIMARY: return 375;
				case STRING_LIT: return 743;
				case THIS: return 169;
			}
			break;
		case 947:
			switch(symbol) {
				case END_TERMINAL: return 611;
			}
			break;
		case 953:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 544;
			}
			break;
		case 956:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 1238;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 960:
			switch(symbol) {
				case BOOLEAN_LIT: return 311;
				case CHAR_LIT: return 326;
				case EXPRESSION2: return 1071;
				case EXPRESSION3: return 749;
				case ID: return 524;
				case INT_LIT: return 465;
				case LITERAL: return 372;
				case LONG_IDENTIFIER: return 68;
				case LPAREN: return 76;
				case MINUS: return 116;
				case NEW: return 16;
				case NOT: return 387;
				case NULL_LIT: return 49;
				case PRIMARY: return 639;
				case SELECTABLE_PRIMARY: return 172;
				case STRING_LIT: return 540;
				case THIS: return 260;
			}
			break;
		case 963:
			switch(symbol) {
				case LPAREN: return 37;
			}
			break;
		case 966:
			switch(symbol) {
				case RPAREN: return 1196;
			}
			break;
		case 969:
			switch(symbol) {
				case ASSIGN: return 71;
				case FORMAL_PARAMETERS: return 93;
				case LPAREN: return 74;
				case METHOD_DECLARATOR_REST: return 724;
				case METHOD_OR_FIELD_REST: return 241;
				case VARIABLE_DECLARATOR_REST: return 912;
			}
			break;
		case 973:
			switch(symbol) {
				case CLASS: return 690;
				case CLASS_DECLARATION: return 886;
				case INTERFACE: return 497;
				case INTERFACE_DECLARATION: return 503;
			}
			break;
		case 974:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 1186;
			}
			break;
		case 976:
			switch(symbol) {
				case RBRACKET: return 954;
			}
			break;
		case 977:
			switch(symbol) {
				case BLOCK: return 297;
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 1081;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 47;
				case ID: return 15;
				case IF: return 147;
				case INT_LIT: return 96;
				case LBRACE: return 467;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 174;
				case PRIMARY: return 242;
				case RETURN: return 377;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 525;
				case STATEMENT: return 509;
				case STATEMENT_EXPRESSION: return 199;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case WHILE: return 494;
			}
			break;
		case 980:
			switch(symbol) {
				case ARGUMENTS: return 7;
				case ARGUMENTS_OPT: return 922;
				case LPAREN: return 333;
			}
			break;
		case 983:
			switch(symbol) {
				case ELSE: return 549;
			}
			break;
		case 988:
			switch(symbol) {
				case ID: return 571;
				case LONG_IDENTIFIER: return 1208;
				case QUALIFIED_IDENTIFIER: return 360;
			}
			break;
		case 992:
			switch(symbol) {
				case BOOLEAN_LIT: return 136;
				case CHAR_LIT: return 48;
				case EXPRESSION3: return 897;
				case ID: return 181;
				case INT_LIT: return 162;
				case LITERAL: return 301;
				case LONG_IDENTIFIER: return 190;
				case LPAREN: return 64;
				case NEW: return 135;
				case NOT: return 36;
				case NULL_LIT: return 192;
				case PRIMARY: return 51;
				case SELECTABLE_PRIMARY: return 351;
				case STRING_LIT: return 11;
				case THIS: return 216;
			}
			break;
		case 994:
			switch(symbol) {
				case BOOLEAN_LIT: return 232;
				case CHAR_LIT: return 561;
				case EXPRESSION3: return 1127;
				case ID: return 585;
				case INT_LIT: return 254;
				case LITERAL: return 239;
				case LONG_IDENTIFIER: return 340;
				case LPAREN: return 228;
				case NEW: return 642;
				case NOT: return 630;
				case NULL_LIT: return 312;
				case PRIMARY: return 526;
				case SELECTABLE_PRIMARY: return 113;
				case STRING_LIT: return 522;
				case THIS: return 781;
			}
			break;
		case 996:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 1273;
				case CLASS_CREATOR_REST: return 760;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 997:
			switch(symbol) {
				case ARRAY: return 1176;
			}
			break;
		case 999:
			switch(symbol) {
				case RPAREN: return 1134;
			}
			break;
		case 1000:
			switch(symbol) {
				case ARRAY: return 1077;
				case DOT: return 926;
			}
			break;
		case 1002:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 808;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 859;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 1005:
			switch(symbol) {
				case BOOLEAN_LIT: return 215;
				case CHAR_LIT: return 456;
				case EXPRESSION2: return 1011;
				case EXPRESSION3: return 686;
				case ID: return 621;
				case INT_LIT: return 148;
				case LITERAL: return 217;
				case LONG_IDENTIFIER: return 175;
				case LPAREN: return 461;
				case MINUS: return 413;
				case NEW: return 392;
				case NOT: return 231;
				case NULL_LIT: return 345;
				case PRIMARY: return 371;
				case SELECTABLE_PRIMARY: return 358;
				case STRING_LIT: return 626;
				case THIS: return 370;
			}
			break;
		case 1009:
			switch(symbol) {
				case DOT: return 59;
				case LBRACKET: return 240;
				case SELECTOR: return 776;
			}
			break;
		case 1017:
			switch(symbol) {
				case ID: return 884;
			}
			break;
		case 1018:
			switch(symbol) {
				case RPAREN: return 838;
			}
			break;
		case 1019:
			switch(symbol) {
				case ID: return 1308;
			}
			break;
		case 1024:
			switch(symbol) {
				case BOOLEAN_LIT: return 538;
				case CHAR_LIT: return 183;
				case EXPRESSION2: return 52;
				case EXPRESSION3: return 53;
				case ID: return 454;
				case INT_LIT: return 574;
				case LITERAL: return 40;
				case LONG_IDENTIFIER: return 511;
				case LPAREN: return 186;
				case MINUS: return 131;
				case NEW: return 426;
				case NOT: return 477;
				case NULL_LIT: return 380;
				case PRIMARY: return 265;
				case SELECTABLE_PRIMARY: return 457;
				case STRING_LIT: return 66;
				case THIS: return 75;
			}
			break;
		case 1025:
			switch(symbol) {
				case BLOCK: return 297;
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 304;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 47;
				case ID: return 15;
				case IF: return 147;
				case INT_LIT: return 96;
				case LBRACE: return 467;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 205;
				case PRIMARY: return 242;
				case RETURN: return 377;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 525;
				case STATEMENT_EXPRESSION: return 199;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case WHILE: return 494;
			}
			break;
		case 1026:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 993;
			}
			break;
		case 1027:
			switch(symbol) {
				case RBRACKET: return 1222;
			}
			break;
		case 1028:
			switch(symbol) {
				case BOOLEAN_LIT: return 35;
				case CHAR_LIT: return 10;
				case EXPRESSION: return 146;
				case EXPRESSION1: return 221;
				case EXPRESSION2: return 219;
				case EXPRESSION3: return 220;
				case EXPRESSION_LIST: return 1260;
				case ID: return 109;
				case INT_LIT: return 184;
				case LITERAL: return 42;
				case LONG_IDENTIFIER: return 195;
				case LPAREN: return 44;
				case MINUS: return 38;
				case NEW: return 198;
				case NOT: return 126;
				case NULL_LIT: return 185;
				case PRIMARY: return 251;
				case RPAREN: return 1102;
				case SELECTABLE_PRIMARY: return 79;
				case STRING_LIT: return 41;
				case THIS: return 179;
			}
			break;
		case 1030:
			switch(symbol) {
				case RPAREN: return 1010;
			}
			break;
		case 1031:
			switch(symbol) {
				case BOOLEAN_LIT: return 238;
				case CHAR_LIT: return 376;
				case EXPRESSION2: return 344;
				case EXPRESSION3: return 343;
				case ID: return 233;
				case INT_LIT: return 19;
				case LITERAL: return 171;
				case LONG_IDENTIFIER: return 362;
				case LPAREN: return 359;
				case MINUS: return 314;
				case NEW: return 707;
				case NOT: return 712;
				case NULL_LIT: return 762;
				case PRIMARY: return 289;
				case SELECTABLE_PRIMARY: return 717;
				case STRING_LIT: return 129;
				case THIS: return 443;
			}
			break;
		case 1033:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 1057;
			}
			break;
		case 1035:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 765;
				case CLASS_CREATOR_REST: return 1221;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 1036:
			switch(symbol) {
				case LPAREN: return 563;
			}
			break;
		case 1037:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 1050;
				case CLASS_CREATOR_REST: return 1030;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 1038:
			switch(symbol) {
				case LPAREN: return 90;
			}
			break;
		case 1039:
			switch(symbol) {
				case DOT: return 211;
				case LBRACKET: return 365;
				case SELECTOR: return 938;
			}
			break;
		case 1044:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 727;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 1050:
			switch(symbol) {
				case RPAREN: return 790;
			}
			break;
		case 1052:
			switch(symbol) {
				case ABSTRACT: return 284;
				case CLASS_BODY_DECLARATION: return 478;
				case CLASS_BODY_DECLARATIONS: return 214;
				case FINAL: return 12;
				case MODIFIER: return 647;
				case MODIFIERS: return 398;
				case MODIFIERS_OPT: return 462;
				case NATIVE: return 350;
				case PROTECTED: return 110;
				case PUBLIC: return 356;
				case RBRACE: return 1204;
				case SEMICOLON: return 390;
				case STATIC: return 176;
			}
			break;
		case 1053:
			switch(symbol) {
				case RPAREN: return 872;
			}
			break;
		case 1054:
			switch(symbol) {
				case ARRAY: return 989;
				case DOT: return 703;
			}
			break;
		case 1055:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 624;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 1056:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 944;
			}
			break;
		case 1059:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 575;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 1063:
			switch(symbol) {
				case RPAREN: return 985;
			}
			break;
		case 1067:
			switch(symbol) {
				case ID: return 666;
			}
			break;
		case 1074:
			switch(symbol) {
				case SEMICOLON: return 1230;
			}
			break;
		case 1075:
			switch(symbol) {
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case EXPRESSION3: return 682;
				case ID: return 15;
				case INT_LIT: return 96;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case PRIMARY: return 242;
				case SELECTABLE_PRIMARY: return 278;
				case STRING_LIT: return 155;
				case THIS: return 25;
			}
			break;
		case 1078:
			switch(symbol) {
				case RPAREN: return 659;
			}
			break;
		case 1079:
			switch(symbol) {
				case ARRAY: return 942;
			}
			break;
		case 1080:
			switch(symbol) {
				case RPAREN: return 736;
			}
			break;
		case 1081:
			switch(symbol) {
				case ELSE: return 1025;
			}
			break;
		case 1082:
			switch(symbol) {
				case BLOCK: return 88;
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 632;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 209;
				case ID: return 15;
				case IF: return 14;
				case INT_LIT: return 96;
				case LBRACE: return 442;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 948;
				case PRIMARY: return 242;
				case RETURN: return 474;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 313;
				case STATEMENT_EXPRESSION: return 165;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case WHILE: return 300;
			}
			break;
		case 1085:
			switch(symbol) {
				case RBRACKET: return 1140;
			}
			break;
		case 1087:
			switch(symbol) {
				case IMPORT: return 274;
				case IMPORT_DECLARATION: return 721;
			}
			break;
		case 1088:
			switch(symbol) {
				case ARRAY: return 1048;
				case DOT: return 638;
			}
			break;
		case 1090:
			switch(symbol) {
				case ARGUMENTS: return 1142;
				case ARGUMENTS_OPT: return 773;
				case LPAREN: return 435;
			}
			break;
		case 1092:
			switch(symbol) {
				case ID: return 869;
			}
			break;
		case 1093:
			switch(symbol) {
				case LPAREN: return 1037;
			}
			break;
		case 1095:
			switch(symbol) {
				case LPAREN: return 1155;
			}
			break;
		case 1100:
			switch(symbol) {
				case BOOLEAN_LIT: return 320;
				case CHAR_LIT: return 20;
				case EXPRESSION2: return 1163;
				case EXPRESSION3: return 476;
				case ID: return 275;
				case INT_LIT: return 594;
				case LITERAL: return 250;
				case LONG_IDENTIFIER: return 277;
				case LPAREN: return 230;
				case MINUS: return 189;
				case NEW: return 420;
				case NOT: return 429;
				case NULL_LIT: return 247;
				case PRIMARY: return 168;
				case SELECTABLE_PRIMARY: return 182;
				case STRING_LIT: return 270;
				case THIS: return 592;
			}
			break;
		case 1101:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 268;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 1103:
			switch(symbol) {
				case BASIC_TYPE: return 792;
				case BOOLEAN: return 952;
				case BYTE: return 845;
				case CHAR: return 738;
				case ID: return 715;
				case INT: return 82;
				case LONG_IDENTIFIER: return 1088;
				case SHORT: return 729;
				case TYPE: return 706;
			}
			break;
		case 1104:
			switch(symbol) {
				case RBRACKET: return 1252;
			}
			break;
		case 1108:
			switch(symbol) {
				case ID: return 537;
			}
			break;
		case 1109:
			switch(symbol) {
				case ID: return 770;
			}
			break;
		case 1110:
			switch(symbol) {
				case ID: return 1106;
			}
			break;
		case 1111:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 836;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 1113:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 1167;
			}
			break;
		case 1115:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION2: return 987;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 1116:
			switch(symbol) {
				case RPAREN: return 1125;
			}
			break;
		case 1117:
			switch(symbol) {
				case RPAREN: return 596;
			}
			break;
		case 1121:
			switch(symbol) {
				case RPAREN: return 1075;
			}
			break;
		case 1125:
			switch(symbol) {
				case BOOLEAN_LIT: return 114;
				case CHAR_LIT: return 696;
				case EXPRESSION3: return 955;
				case ID: return 140;
				case INT_LIT: return 709;
				case LITERAL: return 328;
				case LONG_IDENTIFIER: return 272;
				case LPAREN: return 105;
				case NEW: return 444;
				case NOT: return 425;
				case NULL_LIT: return 557;
				case PRIMARY: return 291;
				case SELECTABLE_PRIMARY: return 422;
				case STRING_LIT: return 197;
				case THIS: return 653;
			}
			break;
		case 1129:
			switch(symbol) {
				case DOT: return 750;
				case LBRACKET: return 834;
				case SELECTOR: return 1300;
			}
			break;
		case 1132:
			switch(symbol) {
				case RPAREN: return 906;
			}
			break;
		case 1135:
			switch(symbol) {
				case DOT: return 438;
				case LBRACKET: return 441;
				case SELECTOR: return 658;
			}
			break;
		case 1137:
			switch(symbol) {
				case BLOCK: return 297;
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 723;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 47;
				case ID: return 15;
				case IF: return 147;
				case INT_LIT: return 96;
				case LBRACE: return 467;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 948;
				case PRIMARY: return 242;
				case RETURN: return 377;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 525;
				case STATEMENT_EXPRESSION: return 199;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case WHILE: return 494;
			}
			break;
		case 1138:
			switch(symbol) {
				case BASIC_TYPE: return 150;
				case BOOLEAN: return 740;
				case BYTE: return 157;
				case CHAR: return 1022;
				case ID: return 998;
				case INT: return 848;
				case LONG_IDENTIFIER: return 78;
				case SHORT: return 1070;
				case TYPE: return 1181;
			}
			break;
		case 1139:
			switch(symbol) {
				case DOT: return 1019;
				case LBRACKET: return 1059;
				case SELECTOR: return 825;
			}
			break;
		case 1144:
			switch(symbol) {
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case EXPRESSION: return 842;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case EXPRESSION_OPT: return 1207;
				case ID: return 15;
				case INT_LIT: return 96;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case PRIMARY: return 242;
				case SELECTABLE_PRIMARY: return 278;
				case STRING_LIT: return 155;
				case THIS: return 25;
			}
			break;
		case 1148:
			switch(symbol) {
				case BOOLEAN_LIT: return 481;
				case CHAR_LIT: return 163;
				case EXPRESSION3: return 252;
				case ID: return 111;
				case INT_LIT: return 123;
				case LITERAL: return 504;
				case LONG_IDENTIFIER: return 290;
				case LPAREN: return 697;
				case NEW: return 384;
				case NOT: return 410;
				case NULL_LIT: return 141;
				case PRIMARY: return 298;
				case SELECTABLE_PRIMARY: return 375;
				case STRING_LIT: return 743;
				case THIS: return 169;
			}
			break;
		case 1149:
			switch(symbol) {
				case RPAREN: return 1040;
			}
			break;
		case 1150:
			switch(symbol) {
				case BASIC_TYPE: return 471;
				case BOOLEAN: return 383;
				case BYTE: return 409;
				case CHAR: return 515;
				case FORMAL_PARAMETER: return 1086;
				case ID: return 586;
				case INT: return 416;
				case LONG_IDENTIFIER: return 663;
				case SHORT: return 527;
				case TYPE: return 695;
			}
			break;
		case 1155:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 966;
				case CLASS_CREATOR_REST: return 999;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 1157:
			switch(symbol) {
				case ID: return 134;
				case VARIABLE_DECLARATOR: return 317;
			}
			break;
		case 1159:
			switch(symbol) {
				case RPAREN: return 641;
			}
			break;
		case 1166:
			switch(symbol) {
				case RPAREN: return 1152;
			}
			break;
		case 1169:
			switch(symbol) {
				case RPAREN: return 994;
			}
			break;
		case 1170:
			switch(symbol) {
				case ID: return 495;
			}
			break;
		case 1173:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 1098;
			}
			break;
		case 1174:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 875;
			}
			break;
		case 1175:
			switch(symbol) {
				case RBRACKET: return 385;
			}
			break;
		case 1177:
			switch(symbol) {
				case RPAREN: return 846;
			}
			break;
		case 1178:
			switch(symbol) {
				case RPAREN: return 1296;
			}
			break;
		case 1180:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 1216;
			}
			break;
		case 1182:
			switch(symbol) {
				case RPAREN: return 396;
			}
			break;
		case 1185:
			switch(symbol) {
				case BLOCK: return 297;
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 523;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 47;
				case ID: return 15;
				case IF: return 147;
				case INT_LIT: return 96;
				case LBRACE: return 467;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 716;
				case PRIMARY: return 242;
				case RETURN: return 377;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 525;
				case STATEMENT_EXPRESSION: return 199;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case WHILE: return 494;
			}
			break;
		case 1192:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 1262;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 1194:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 389;
				case EXPRESSION1: return 751;
				case EXPRESSION2: return 752;
				case EXPRESSION3: return 244;
				case ID: return 188;
				case INT_LIT: return 124;
				case LITERAL: return 18;
				case LONG_IDENTIFIER: return 269;
				case LPAREN: return 97;
				case MINUS: return 138;
				case NEW: return 676;
				case NOT: return 616;
				case NULL_LIT: return 759;
				case PRIMARY: return 533;
				case SELECTABLE_PRIMARY: return 152;
				case STRING_LIT: return 89;
				case THIS: return 455;
			}
			break;
		case 1198:
			switch(symbol) {
				case BASIC_TYPE: return 737;
				case BOOLEAN: return 909;
				case BYTE: return 1303;
				case CHAR: return 354;
				case ID: return 306;
				case INT: return 783;
				case LONG_IDENTIFIER: return 1054;
				case SHORT: return 753;
				case TYPE: return 411;
			}
			break;
		case 1199:
			switch(symbol) {
				case BOOLEAN_LIT: return 538;
				case CHAR_LIT: return 183;
				case EXPRESSION2: return 975;
				case EXPRESSION3: return 53;
				case ID: return 454;
				case INT_LIT: return 574;
				case LITERAL: return 40;
				case LONG_IDENTIFIER: return 511;
				case LPAREN: return 186;
				case MINUS: return 131;
				case NEW: return 426;
				case NOT: return 477;
				case NULL_LIT: return 380;
				case PRIMARY: return 265;
				case SELECTABLE_PRIMARY: return 457;
				case STRING_LIT: return 66;
				case THIS: return 75;
			}
			break;
		case 1201:
			switch(symbol) {
				case BOOLEAN_LIT: return 311;
				case CHAR_LIT: return 326;
				case EXPRESSION2: return 1141;
				case EXPRESSION3: return 749;
				case ID: return 524;
				case INT_LIT: return 465;
				case LITERAL: return 372;
				case LONG_IDENTIFIER: return 68;
				case LPAREN: return 76;
				case MINUS: return 116;
				case NEW: return 16;
				case NOT: return 387;
				case NULL_LIT: return 49;
				case PRIMARY: return 639;
				case SELECTABLE_PRIMARY: return 172;
				case STRING_LIT: return 540;
				case THIS: return 260;
			}
			break;
		case 1203:
			switch(symbol) {
				case RPAREN: return 761;
			}
			break;
		case 1207:
			switch(symbol) {
				case SEMICOLON: return 890;
			}
			break;
		case 1208:
			switch(symbol) {
				case DOT: return 292;
			}
			break;
		case 1210:
			switch(symbol) {
				case ID: return 248;
			}
			break;
		case 1212:
			switch(symbol) {
				case FORMAL_PARAMETERS: return 93;
				case LPAREN: return 74;
				case METHOD_DECLARATOR_REST: return 917;
			}
			break;
		case 1213:
			switch(symbol) {
				case ID: return 1090;
			}
			break;
		case 1215:
			switch(symbol) {
				case RPAREN: return 970;
			}
			break;
		case 1217:
			switch(symbol) {
				case ID: return 1012;
			}
			break;
		case 1218:
			switch(symbol) {
				case RPAREN: return 492;
			}
			break;
		case 1219:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 433;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 1220:
			switch(symbol) {
				case RBRACKET: return 714;
			}
			break;
		case 1221:
			switch(symbol) {
				case RPAREN: return 822;
			}
			break;
		case 1225:
			switch(symbol) {
				case BOOLEAN_LIT: return 67;
				case CHAR_LIT: return 505;
				case EXPRESSION2: return 856;
				case EXPRESSION3: return 598;
				case ID: return 9;
				case INT_LIT: return 636;
				case LITERAL: return 158;
				case LONG_IDENTIFIER: return 618;
				case LPAREN: return 719;
				case MINUS: return 741;
				case NEW: return 173;
				case NOT: return 208;
				case NULL_LIT: return 742;
				case PRIMARY: return 223;
				case SELECTABLE_PRIMARY: return 680;
				case STRING_LIT: return 99;
				case THIS: return 547;
			}
			break;
		case 1231:
			switch(symbol) {
				case RBRACKET: return 1274;
			}
			break;
		case 1234:
			switch(symbol) {
				case BOOLEAN_LIT: return 320;
				case CHAR_LIT: return 20;
				case EXPRESSION2: return 475;
				case EXPRESSION3: return 476;
				case ID: return 275;
				case INT_LIT: return 594;
				case LITERAL: return 250;
				case LONG_IDENTIFIER: return 277;
				case LPAREN: return 230;
				case MINUS: return 189;
				case NEW: return 420;
				case NOT: return 429;
				case NULL_LIT: return 247;
				case PRIMARY: return 168;
				case SELECTABLE_PRIMARY: return 182;
				case STRING_LIT: return 270;
				case THIS: return 592;
			}
			break;
		case 1238:
			switch(symbol) {
				case RBRACKET: return 1029;
			}
			break;
		case 1240:
			switch(symbol) {
				case BOOLEAN_LIT: return 538;
				case CHAR_LIT: return 183;
				case EXPRESSION2: return 1041;
				case EXPRESSION3: return 53;
				case ID: return 454;
				case INT_LIT: return 574;
				case LITERAL: return 40;
				case LONG_IDENTIFIER: return 511;
				case LPAREN: return 186;
				case MINUS: return 131;
				case NEW: return 426;
				case NOT: return 477;
				case NULL_LIT: return 380;
				case PRIMARY: return 265;
				case SELECTABLE_PRIMARY: return 457;
				case STRING_LIT: return 66;
				case THIS: return 75;
			}
			break;
		case 1242:
			switch(symbol) {
				case RPAREN: return 795;
			}
			break;
		case 1244:
			switch(symbol) {
				case DOT: return 812;
				case LBRACKET: return 755;
				case SELECTOR: return 570;
			}
			break;
		case 1245:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 898;
			}
			break;
		case 1247:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 1053;
				case CLASS_CREATOR_REST: return 468;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 1254:
			switch(symbol) {
				case LPAREN: return 437;
			}
			break;
		case 1259:
			switch(symbol) {
				case BOOLEAN_LIT: return 67;
				case CHAR_LIT: return 505;
				case EXPRESSION3: return 1227;
				case ID: return 9;
				case INT_LIT: return 636;
				case LITERAL: return 158;
				case LONG_IDENTIFIER: return 618;
				case LPAREN: return 719;
				case NEW: return 173;
				case NOT: return 208;
				case NULL_LIT: return 742;
				case PRIMARY: return 223;
				case SELECTABLE_PRIMARY: return 680;
				case STRING_LIT: return 99;
				case THIS: return 547;
			}
			break;
		case 1260:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 1061;
			}
			break;
		case 1261:
			switch(symbol) {
				case ARRAY: return 1013;
				case DOT: return 1110;
			}
			break;
		case 1262:
			switch(symbol) {
				case RBRACKET: return 309;
			}
			break;
		case 1264:
			switch(symbol) {
				case RPAREN: return 924;
			}
			break;
		case 1265:
			switch(symbol) {
				case COMMA: return 100;
				case RPAREN: return 929;
			}
			break;
		case 1266:
			switch(symbol) {
				case ARGUMENTS: return 816;
				case ARGUMENTS_OPT: return 518;
				case LPAREN: return 1028;
			}
			break;
		case 1270:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 1178;
				case CLASS_CREATOR_REST: return 891;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 1271:
			switch(symbol) {
				case BOOLEAN_LIT: return 232;
				case CHAR_LIT: return 561;
				case EXPRESSION2: return 617;
				case EXPRESSION3: return 57;
				case ID: return 585;
				case INT_LIT: return 254;
				case LITERAL: return 239;
				case LONG_IDENTIFIER: return 340;
				case LPAREN: return 228;
				case MINUS: return 237;
				case NEW: return 642;
				case NOT: return 630;
				case NULL_LIT: return 312;
				case PRIMARY: return 526;
				case SELECTABLE_PRIMARY: return 113;
				case STRING_LIT: return 522;
				case THIS: return 781;
			}
			break;
		case 1273:
			switch(symbol) {
				case RPAREN: return 374;
			}
			break;
		case 1275:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 1271;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 1276:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 200;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 1278:
			switch(symbol) {
				case ID: return 1212;
			}
			break;
		case 1281:
			switch(symbol) {
				case BOOLEAN_LIT: return 98;
				case CHAR_LIT: return 4;
				case EXPRESSION: return 814;
				case EXPRESSION1: return 70;
				case EXPRESSION2: return 72;
				case EXPRESSION3: return 69;
				case ID: return 31;
				case INT_LIT: return 166;
				case LITERAL: return 61;
				case LONG_IDENTIFIER: return 8;
				case LPAREN: return 246;
				case MINUS: return 62;
				case NEW: return 28;
				case NOT: return 193;
				case NULL_LIT: return 81;
				case PRIMARY: return 95;
				case SELECTABLE_PRIMARY: return 133;
				case STRING_LIT: return 60;
				case THIS: return 145;
			}
			break;
		case 1282:
			switch(symbol) {
				case ID: return 1158;
			}
			break;
		case 1283:
			switch(symbol) {
				case SEMICOLON: return 1144;
			}
			break;
		case 1284:
			switch(symbol) {
				case BASIC_TYPE: return 379;
				case BOOLEAN: return 1184;
				case BYTE: return 634;
				case CHAR: return 484;
				case ID: return 464;
				case INT: return 1160;
				case LONG_IDENTIFIER: return 1290;
				case SHORT: return 531;
				case TYPE: return 417;
			}
			break;
		case 1285:
			switch(symbol) {
				case RPAREN: return 1065;
			}
			break;
		case 1287:
			switch(symbol) {
				case RPAREN: return 1024;
			}
			break;
		case 1288:
			switch(symbol) {
				case ID: return 1003;
			}
			break;
		case 1289:
			switch(symbol) {
				case BOOLEAN_LIT: return 87;
				case CHAR_LIT: return 334;
				case EXPRESSION3: return 408;
				case ID: return 660;
				case INT_LIT: return 299;
				case LITERAL: return 46;
				case LONG_IDENTIFIER: return 261;
				case LPAREN: return 305;
				case NEW: return 1;
				case NOT: return 137;
				case NULL_LIT: return 496;
				case PRIMARY: return 446;
				case SELECTABLE_PRIMARY: return 399;
				case STRING_LIT: return 349;
				case THIS: return 402;
			}
			break;
		case 1290:
			switch(symbol) {
				case ARRAY: return 325;
				case DOT: return 1092;
			}
			break;
		case 1291:
			switch(symbol) {
				case RPAREN: return 867;
			}
			break;
		case 1292:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 1005;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 1298:
			switch(symbol) {
				case ARGUMENTS: return 1237;
				case ARGUMENTS_OPT: return 651;
				case LPAREN: return 678;
			}
			break;
		case 1305:
			switch(symbol) {
				case BOOLEAN_LIT: return 114;
				case CHAR_LIT: return 696;
				case EXPRESSION2: return 1096;
				case EXPRESSION3: return 803;
				case ID: return 140;
				case INT_LIT: return 709;
				case LITERAL: return 328;
				case LONG_IDENTIFIER: return 272;
				case LPAREN: return 105;
				case MINUS: return 204;
				case NEW: return 444;
				case NOT: return 425;
				case NULL_LIT: return 557;
				case PRIMARY: return 291;
				case SELECTABLE_PRIMARY: return 422;
				case STRING_LIT: return 197;
				case THIS: return 653;
			}
			break;
		case 1306:
			switch(symbol) {
				case BOOLEAN_LIT: return 322;
				case CHAR_LIT: return 287;
				case EXPRESSION2: return 865;
				case EXPRESSION3: return 338;
				case ID: return 34;
				case INT_LIT: return 448;
				case LITERAL: return 117;
				case LONG_IDENTIFIER: return 482;
				case LPAREN: return 452;
				case MINUS: return 488;
				case NEW: return 463;
				case NOT: return 470;
				case NULL_LIT: return 583;
				case PRIMARY: return 406;
				case SELECTABLE_PRIMARY: return 266;
				case STRING_LIT: return 161;
				case THIS: return 178;
			}
			break;
		case 1307:
			switch(symbol) {
				case AND: return 180;
				case DIV: return 144;
				case EAGER_AND: return 207;
				case EAGER_OR: return 170;
				case EQ: return 84;
				case GEQ: return 108;
				case GT: return 3;
				case INFIX_OP: return 829;
				case LEQ: return 445;
				case LT: return 30;
				case MINUS: return 107;
				case MULT: return 156;
				case NEQ: return 206;
				case OR: return 32;
				case PLUS: return 77;
				case REMAINDER: return 26;
				case XOR: return 151;
			}
			break;
		case 1308:
			switch(symbol) {
				case ARGUMENTS: return 1165;
				case ARGUMENTS_OPT: return 1146;
				case LPAREN: return 613;
			}
			break;
		case 1309:
			switch(symbol) {
				case ARGUMENTS: return 167;
				case ARRAY_CREATOR_REST: return 1117;
				case CLASS_CREATOR_REST: return 355;
				case LBRACKET: return 142;
				case LPAREN: return 160;
			}
			break;
		case 1311:
			switch(symbol) {
				case BLOCK: return 88;
				case BOOLEAN_LIT: return 85;
				case CHAR_LIT: return 92;
				case CLOSED_STATEMENT: return 516;
				case EXPRESSION: return 83;
				case EXPRESSION1: return 54;
				case EXPRESSION2: return 56;
				case EXPRESSION3: return 55;
				case FOR: return 209;
				case ID: return 15;
				case IF: return 14;
				case INT_LIT: return 96;
				case LBRACE: return 442;
				case LITERAL: return 296;
				case LONG_IDENTIFIER: return 21;
				case LPAREN: return 191;
				case MINUS: return 33;
				case NEW: return 164;
				case NOT: return 104;
				case NULL_LIT: return 45;
				case OPEN_STATEMENT: return 716;
				case PRIMARY: return 242;
				case RETURN: return 474;
				case SELECTABLE_PRIMARY: return 278;
				case SEMICOLON: return 313;
				case STATEMENT_EXPRESSION: return 165;
				case STRING_LIT: return 155;
				case THIS: return 25;
				case WHILE: return 300;
			}
			break;
		case 1313:
			switch(symbol) {
				case ARGUMENTS: return 873;
				case ARGUMENTS_OPT: return 279;
				case LPAREN: return 1002;
			}
			break;
	}
	return -1;
}

int stateReduce(int currState, int symbol)
{
	switch(currState) {
		case 3:
			switch(symbol) {
				case BOOLEAN_LIT: return 23;
				case CHAR_LIT: return 23;
				case ID: return 23;
				case INT_LIT: return 23;
				case LPAREN: return 23;
				case MINUS: return 23;
				case NEW: return 23;
				case NOT: return 23;
				case NULL_LIT: return 23;
				case STRING_LIT: return 23;
				case THIS: return 23;
			}
			break;
		case 4:
			switch(symbol) {
				case AND: return 5;
				case ASSIGN: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case INSTANCEOF: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case RBRACKET: return 5;
				case REMAINDER: return 5;
				case XOR: return 5;
			}
			break;
		case 5:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case RBRACKET: return 56;
				case REMAINDER: return 56;
				case XOR: return 56;
			}
			break;
		case 7:
			switch(symbol) {
				case AND: return 68;
				case ASSIGN: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case SEMICOLON: return 68;
				case XOR: return 68;
			}
			break;
		case 8:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case INSTANCEOF: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case RBRACKET: return 51;
				case REMAINDER: return 51;
				case XOR: return 51;
			}
			break;
		case 9:
			switch(symbol) {
				case AND: return 1;
				case COMMA: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case INSTANCEOF: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case RPAREN: return 1;
				case XOR: return 1;
			}
			break;
		case 10:
			switch(symbol) {
				case AND: return 5;
				case ASSIGN: return 5;
				case COMMA: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case INSTANCEOF: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case RPAREN: return 5;
				case XOR: return 5;
			}
			break;
		case 11:
			switch(symbol) {
				case AND: return 6;
				case ASSIGN: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case INSTANCEOF: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case RPAREN: return 6;
				case XOR: return 6;
			}
			break;
		case 12:
			switch(symbol) {
				case ABSTRACT: return 117;
				case BOOLEAN: return 117;
				case BYTE: return 117;
				case CHAR: return 117;
				case FINAL: return 117;
				case ID: return 117;
				case INT: return 117;
				case NATIVE: return 117;
				case PROTECTED: return 117;
				case PUBLIC: return 117;
				case SHORT: return 117;
				case STATIC: return 117;
				case VOID: return 117;
			}
			break;
		case 15:
			switch(symbol) {
				case AND: return 1;
				case ASSIGN: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case INSTANCEOF: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case SEMICOLON: return 1;
				case XOR: return 1;
			}
			break;
		case 18:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case RPAREN: return 54;
				case XOR: return 54;
			}
			break;
		case 19:
			switch(symbol) {
				case AND: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case INSTANCEOF: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case RBRACKET: return 4;
				case REMAINDER: return 4;
				case XOR: return 4;
			}
			break;
		case 20:
			switch(symbol) {
				case AND: return 5;
				case ASSIGN: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case SEMICOLON: return 5;
				case XOR: return 5;
			}
			break;
		case 21:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case INSTANCEOF: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case SEMICOLON: return 51;
				case XOR: return 51;
			}
			break;
		case 22:
			switch(symbol) {
				case AND: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case INSTANCEOF: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case RPAREN: return 7;
				case XOR: return 7;
			}
			break;
		case 24:
			switch(symbol) {
				case AND: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case RPAREN: return 68;
				case XOR: return 68;
			}
			break;
		case 25:
			switch(symbol) {
				case AND: return 53;
				case ASSIGN: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case INSTANCEOF: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case SEMICOLON: return 53;
				case XOR: return 53;
			}
			break;
		case 26:
			switch(symbol) {
				case BOOLEAN_LIT: return 29;
				case CHAR_LIT: return 29;
				case ID: return 29;
				case INT_LIT: return 29;
				case LPAREN: return 29;
				case MINUS: return 29;
				case NEW: return 29;
				case NOT: return 29;
				case NULL_LIT: return 29;
				case STRING_LIT: return 29;
				case THIS: return 29;
			}
			break;
		case 27:
			switch(symbol) {
				case AND: return 61;
				case ASSIGN: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case INSTANCEOF: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case RBRACKET: return 61;
				case REMAINDER: return 61;
				case XOR: return 61;
			}
			break;
		case 30:
			switch(symbol) {
				case BOOLEAN_LIT: return 24;
				case CHAR_LIT: return 24;
				case ID: return 24;
				case INT_LIT: return 24;
				case LPAREN: return 24;
				case MINUS: return 24;
				case NEW: return 24;
				case NOT: return 24;
				case NULL_LIT: return 24;
				case STRING_LIT: return 24;
				case THIS: return 24;
			}
			break;
		case 31:
			switch(symbol) {
				case AND: return 1;
				case ASSIGN: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case INSTANCEOF: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case RBRACKET: return 1;
				case REMAINDER: return 1;
				case XOR: return 1;
			}
			break;
		case 32:
			switch(symbol) {
				case BOOLEAN_LIT: return 16;
				case CHAR_LIT: return 16;
				case ID: return 16;
				case INT_LIT: return 16;
				case LPAREN: return 16;
				case MINUS: return 16;
				case NEW: return 16;
				case NOT: return 16;
				case NULL_LIT: return 16;
				case STRING_LIT: return 16;
				case THIS: return 16;
			}
			break;
		case 34:
			switch(symbol) {
				case AND: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case RPAREN: return 1;
				case XOR: return 1;
			}
			break;
		case 35:
			switch(symbol) {
				case AND: return 7;
				case ASSIGN: return 7;
				case COMMA: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case INSTANCEOF: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case RPAREN: return 7;
				case XOR: return 7;
			}
			break;
		case 40:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case RPAREN: return 54;
				case XOR: return 54;
			}
			break;
		case 41:
			switch(symbol) {
				case AND: return 6;
				case ASSIGN: return 6;
				case COMMA: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case INSTANCEOF: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case RPAREN: return 6;
				case XOR: return 6;
			}
			break;
		case 42:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case COMMA: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case RPAREN: return 54;
				case XOR: return 54;
			}
			break;
		case 43:
			switch(symbol) {
				case RPAREN: return 63;
			}
			break;
		case 45:
			switch(symbol) {
				case AND: return 8;
				case ASSIGN: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case INSTANCEOF: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case SEMICOLON: return 8;
				case XOR: return 8;
			}
			break;
		case 46:
			switch(symbol) {
				case AND: return 54;
				case COMMA: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case RPAREN: return 54;
				case XOR: return 54;
			}
			break;
		case 48:
			switch(symbol) {
				case AND: return 5;
				case ASSIGN: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case INSTANCEOF: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case RPAREN: return 5;
				case XOR: return 5;
			}
			break;
		case 49:
			switch(symbol) {
				case AND: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case SEMICOLON: return 8;
				case XOR: return 8;
			}
			break;
		case 50:
			switch(symbol) {
				case AND: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case RPAREN: return 60;
				case XOR: return 60;
			}
			break;
		case 51:
			switch(symbol) {
				case AND: return 44;
				case ASSIGN: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case INSTANCEOF: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case RPAREN: return 44;
				case XOR: return 44;
			}
			break;
		case 52:
			switch(symbol) {
				case AND: return 43;
				case ASSIGN: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case RPAREN: return 43;
				case XOR: return 43;
			}
			break;
		case 53:
			switch(symbol) {
				case AND: return 40;
				case ASSIGN: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case RPAREN: return 40;
				case XOR: return 40;
			}
			break;
		case 54:
			switch(symbol) {
				case SEMICOLON: return 30;
			}
			break;
		case 55:
			switch(symbol) {
				case AND: return 40;
				case ASSIGN: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case INSTANCEOF: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case SEMICOLON: return 40;
				case XOR: return 40;
			}
			break;
		case 56:
			switch(symbol) {
				case ASSIGN: return 33;
				case SEMICOLON: return 33;
			}
			break;
		case 57:
			switch(symbol) {
				case AND: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case RBRACKET: return 40;
				case REMAINDER: return 40;
				case XOR: return 40;
			}
			break;
		case 58:
			switch(symbol) {
				case AND: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case RBRACKET: return 43;
				case REMAINDER: return 43;
				case XOR: return 43;
			}
			break;
		case 60:
			switch(symbol) {
				case AND: return 6;
				case ASSIGN: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case INSTANCEOF: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case RBRACKET: return 6;
				case REMAINDER: return 6;
				case XOR: return 6;
			}
			break;
		case 61:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case RBRACKET: return 54;
				case REMAINDER: return 54;
				case XOR: return 54;
			}
			break;
		case 63:
			switch(symbol) {
				case DOT: return 2;
				case SEMICOLON: return 2;
			}
			break;
		case 65:
			switch(symbol) {
				case AND: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case SEMICOLON: return 2;
				case XOR: return 2;
			}
			break;
		case 66:
			switch(symbol) {
				case AND: return 6;
				case ASSIGN: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case RPAREN: return 6;
				case XOR: return 6;
			}
			break;
		case 67:
			switch(symbol) {
				case AND: return 7;
				case COMMA: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case INSTANCEOF: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case RPAREN: return 7;
				case XOR: return 7;
			}
			break;
		case 68:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case SEMICOLON: return 51;
				case XOR: return 51;
			}
			break;
		case 69:
			switch(symbol) {
				case AND: return 40;
				case ASSIGN: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case INSTANCEOF: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case RBRACKET: return 40;
				case REMAINDER: return 40;
				case XOR: return 40;
			}
			break;
		case 70:
			switch(symbol) {
				case RBRACKET: return 30;
			}
			break;
		case 72:
			switch(symbol) {
				case ASSIGN: return 33;
				case RBRACKET: return 33;
			}
			break;
		case 73:
			switch(symbol) {
				case AND: return 62;
				case COMMA: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case RPAREN: return 62;
				case XOR: return 62;
			}
			break;
		case 74:
			switch(symbol) {
				case RPAREN: return 174;
			}
			break;
		case 75:
			switch(symbol) {
				case AND: return 53;
				case ASSIGN: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case RPAREN: return 53;
				case XOR: return 53;
			}
			break;
		case 77:
			switch(symbol) {
				case BOOLEAN_LIT: return 25;
				case CHAR_LIT: return 25;
				case ID: return 25;
				case INT_LIT: return 25;
				case LPAREN: return 25;
				case MINUS: return 25;
				case NEW: return 25;
				case NOT: return 25;
				case NULL_LIT: return 25;
				case STRING_LIT: return 25;
				case THIS: return 25;
			}
			break;
		case 78:
			switch(symbol) {
				case SEMICOLON: return 9;
			}
			break;
		case 79:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case COMMA: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case INSTANCEOF: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case RPAREN: return 50;
				case XOR: return 50;
			}
			break;
		case 80:
			switch(symbol) {
				case END_TERMINAL: return 149;
			}
			break;
		case 81:
			switch(symbol) {
				case AND: return 8;
				case ASSIGN: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case INSTANCEOF: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case RBRACKET: return 8;
				case REMAINDER: return 8;
				case XOR: return 8;
			}
			break;
		case 82:
			switch(symbol) {
				case ARRAY: return 66;
				case ASSIGN: return 66;
				case RBRACKET: return 66;
			}
			break;
		case 83:
			switch(symbol) {
				case SEMICOLON: return 32;
			}
			break;
		case 84:
			switch(symbol) {
				case BOOLEAN_LIT: return 19;
				case CHAR_LIT: return 19;
				case ID: return 19;
				case INT_LIT: return 19;
				case LPAREN: return 19;
				case MINUS: return 19;
				case NEW: return 19;
				case NOT: return 19;
				case NULL_LIT: return 19;
				case STRING_LIT: return 19;
				case THIS: return 19;
			}
			break;
		case 85:
			switch(symbol) {
				case AND: return 7;
				case ASSIGN: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case INSTANCEOF: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case SEMICOLON: return 7;
				case XOR: return 7;
			}
			break;
		case 87:
			switch(symbol) {
				case AND: return 7;
				case COMMA: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case RPAREN: return 7;
				case XOR: return 7;
			}
			break;
		case 88:
			switch(symbol) {
				case BOOLEAN: return 94;
				case BOOLEAN_LIT: return 94;
				case BYTE: return 94;
				case CHAR: return 94;
				case CHAR_LIT: return 94;
				case FOR: return 94;
				case ID: return 94;
				case IF: return 94;
				case INT: return 94;
				case INT_LIT: return 94;
				case LBRACE: return 94;
				case LPAREN: return 94;
				case MINUS: return 94;
				case NEW: return 94;
				case NOT: return 94;
				case NULL_LIT: return 94;
				case RBRACE: return 94;
				case RETURN: return 94;
				case SEMICOLON: return 94;
				case SHORT: return 94;
				case STRING_LIT: return 94;
				case THIS: return 94;
				case WHILE: return 94;
			}
			break;
		case 89:
			switch(symbol) {
				case AND: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case INSTANCEOF: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case RPAREN: return 6;
				case XOR: return 6;
			}
			break;
		case 91:
			switch(symbol) {
				case AND: return 70;
				case COMMA: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case INSTANCEOF: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case RPAREN: return 70;
				case XOR: return 70;
			}
			break;
		case 92:
			switch(symbol) {
				case AND: return 5;
				case ASSIGN: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case INSTANCEOF: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case SEMICOLON: return 5;
				case XOR: return 5;
			}
			break;
		case 94:
			switch(symbol) {
				case AND: return 45;
				case ASSIGN: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case RBRACKET: return 45;
				case REMAINDER: return 45;
				case XOR: return 45;
			}
			break;
		case 95:
			switch(symbol) {
				case AND: return 44;
				case ASSIGN: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case INSTANCEOF: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case RBRACKET: return 44;
				case REMAINDER: return 44;
				case XOR: return 44;
			}
			break;
		case 96:
			switch(symbol) {
				case AND: return 4;
				case ASSIGN: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case INSTANCEOF: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case SEMICOLON: return 4;
				case XOR: return 4;
			}
			break;
		case 98:
			switch(symbol) {
				case AND: return 7;
				case ASSIGN: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case INSTANCEOF: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case RBRACKET: return 7;
				case REMAINDER: return 7;
				case XOR: return 7;
			}
			break;
		case 99:
			switch(symbol) {
				case AND: return 6;
				case COMMA: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case INSTANCEOF: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case RPAREN: return 6;
				case XOR: return 6;
			}
			break;
		case 101:
			switch(symbol) {
				case RPAREN: return 173;
			}
			break;
		case 102:
			switch(symbol) {
				case AND: return 57;
				case ASSIGN: return 57;
				case COMMA: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case RPAREN: return 57;
				case XOR: return 57;
			}
			break;
		case 103:
			switch(symbol) {
				case ARRAY: return 67;
				case COMMA: return 67;
				case LBRACE: return 67;
			}
			break;
		case 106:
			switch(symbol) {
				case ABSTRACT: return 163;
				case BOOLEAN: return 163;
				case BYTE: return 163;
				case CHAR: return 163;
				case FINAL: return 163;
				case ID: return 163;
				case INT: return 163;
				case NATIVE: return 163;
				case PROTECTED: return 163;
				case PUBLIC: return 163;
				case RBRACE: return 163;
				case SEMICOLON: return 163;
				case SHORT: return 163;
				case STATIC: return 163;
				case VOID: return 163;
			}
			break;
		case 107:
			switch(symbol) {
				case BOOLEAN_LIT: return 26;
				case CHAR_LIT: return 26;
				case ID: return 26;
				case INT_LIT: return 26;
				case LPAREN: return 26;
				case MINUS: return 26;
				case NEW: return 26;
				case NOT: return 26;
				case NULL_LIT: return 26;
				case STRING_LIT: return 26;
				case THIS: return 26;
			}
			break;
		case 108:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 22;
				case ID: return 22;
				case INT_LIT: return 22;
				case LPAREN: return 22;
				case MINUS: return 22;
				case NEW: return 22;
				case NOT: return 22;
				case NULL_LIT: return 22;
				case STRING_LIT: return 22;
				case THIS: return 22;
			}
			break;
		case 109:
			switch(symbol) {
				case AND: return 1;
				case ASSIGN: return 1;
				case COMMA: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case INSTANCEOF: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case RPAREN: return 1;
				case XOR: return 1;
			}
			break;
		case 110:
			switch(symbol) {
				case ABSTRACT: return 114;
				case BOOLEAN: return 114;
				case BYTE: return 114;
				case CHAR: return 114;
				case FINAL: return 114;
				case ID: return 114;
				case INT: return 114;
				case NATIVE: return 114;
				case PROTECTED: return 114;
				case PUBLIC: return 114;
				case SHORT: return 114;
				case STATIC: return 114;
				case VOID: return 114;
			}
			break;
		case 111:
			switch(symbol) {
				case AND: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case INSTANCEOF: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case SEMICOLON: return 1;
				case XOR: return 1;
			}
			break;
		case 112:
			switch(symbol) {
				case BOOLEAN: return 110;
				case BYTE: return 110;
				case CHAR: return 110;
				case ID: return 110;
				case INT: return 110;
				case SHORT: return 110;
				case VOID: return 110;
			}
			break;
		case 113:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case RBRACKET: return 50;
				case REMAINDER: return 50;
				case XOR: return 50;
			}
			break;
		case 114:
			switch(symbol) {
				case AND: return 7;
				case ASSIGN: return 7;
				case COMMA: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case RPAREN: return 7;
				case XOR: return 7;
			}
			break;
		case 115:
			switch(symbol) {
				case ABSTRACT: return 167;
				case BOOLEAN: return 167;
				case BYTE: return 167;
				case CHAR: return 167;
				case FINAL: return 167;
				case ID: return 167;
				case INT: return 167;
				case NATIVE: return 167;
				case PROTECTED: return 167;
				case PUBLIC: return 167;
				case RBRACE: return 167;
				case SEMICOLON: return 167;
				case SHORT: return 167;
				case STATIC: return 167;
				case VOID: return 167;
			}
			break;
		case 117:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case RPAREN: return 54;
				case XOR: return 54;
			}
			break;
		case 118:
			switch(symbol) {
				case AND: return 40;
				case ASSIGN: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case INSTANCEOF: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case RPAREN: return 40;
				case XOR: return 40;
			}
			break;
		case 119:
			switch(symbol) {
				case ASSIGN: return 33;
				case RPAREN: return 33;
			}
			break;
		case 120:
			switch(symbol) {
				case RPAREN: return 30;
			}
			break;
		case 121:
			switch(symbol) {
				case AND: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case INSTANCEOF: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case SEMICOLON: return 68;
				case XOR: return 68;
			}
			break;
		case 123:
			switch(symbol) {
				case AND: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case INSTANCEOF: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case SEMICOLON: return 4;
				case XOR: return 4;
			}
			break;
		case 124:
			switch(symbol) {
				case AND: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case INSTANCEOF: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case RPAREN: return 4;
				case XOR: return 4;
			}
			break;
		case 125:
			switch(symbol) {
				case AND: return 60;
				case ASSIGN: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case INSTANCEOF: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case RPAREN: return 60;
				case XOR: return 60;
			}
			break;
		case 127:
			switch(symbol) {
				case ARRAY: return 66;
				case ASSIGN: return 66;
				case COMMA: return 66;
				case RPAREN: return 66;
			}
			break;
		case 129:
			switch(symbol) {
				case AND: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case INSTANCEOF: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case RBRACKET: return 6;
				case REMAINDER: return 6;
				case XOR: return 6;
			}
			break;
		case 133:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case INSTANCEOF: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case RBRACKET: return 50;
				case REMAINDER: return 50;
				case XOR: return 50;
			}
			break;
		case 134:
			switch(symbol) {
				case SEMICOLON: return 120;
			}
			break;
		case 136:
			switch(symbol) {
				case AND: return 7;
				case ASSIGN: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case INSTANCEOF: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case RPAREN: return 7;
				case XOR: return 7;
			}
			break;
		case 140:
			switch(symbol) {
				case AND: return 1;
				case ASSIGN: return 1;
				case COMMA: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case RPAREN: return 1;
				case XOR: return 1;
			}
			break;
		case 141:
			switch(symbol) {
				case AND: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case INSTANCEOF: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case SEMICOLON: return 8;
				case XOR: return 8;
			}
			break;
		case 143:
			switch(symbol) {
				case RPAREN: return 35;
			}
			break;
		case 144:
			switch(symbol) {
				case BOOLEAN_LIT: return 28;
				case CHAR_LIT: return 28;
				case ID: return 28;
				case INT_LIT: return 28;
				case LPAREN: return 28;
				case MINUS: return 28;
				case NEW: return 28;
				case NOT: return 28;
				case NULL_LIT: return 28;
				case STRING_LIT: return 28;
				case THIS: return 28;
			}
			break;
		case 145:
			switch(symbol) {
				case AND: return 53;
				case ASSIGN: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case INSTANCEOF: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case RBRACKET: return 53;
				case REMAINDER: return 53;
				case XOR: return 53;
			}
			break;
		case 146:
			switch(symbol) {
				case COMMA: return 46;
				case RPAREN: return 46;
			}
			break;
		case 148:
			switch(symbol) {
				case AND: return 4;
				case ASSIGN: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case RBRACKET: return 4;
				case REMAINDER: return 4;
				case XOR: return 4;
			}
			break;
		case 150:
			switch(symbol) {
				case SEMICOLON: return 11;
			}
			break;
		case 151:
			switch(symbol) {
				case BOOLEAN_LIT: return 18;
				case CHAR_LIT: return 18;
				case ID: return 18;
				case INT_LIT: return 18;
				case LPAREN: return 18;
				case MINUS: return 18;
				case NEW: return 18;
				case NOT: return 18;
				case NULL_LIT: return 18;
				case STRING_LIT: return 18;
				case THIS: return 18;
			}
			break;
		case 152:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case INSTANCEOF: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case RPAREN: return 50;
				case XOR: return 50;
			}
			break;
		case 153:
			switch(symbol) {
				case ABSTRACT: return 127;
				case CLASS: return 127;
				case END_TERMINAL: return 127;
				case FINAL: return 127;
				case INTERFACE: return 127;
				case NATIVE: return 127;
				case PROTECTED: return 127;
				case PUBLIC: return 127;
				case SEMICOLON: return 127;
				case STATIC: return 127;
			}
			break;
		case 155:
			switch(symbol) {
				case AND: return 6;
				case ASSIGN: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case INSTANCEOF: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case SEMICOLON: return 6;
				case XOR: return 6;
			}
			break;
		case 156:
			switch(symbol) {
				case BOOLEAN_LIT: return 27;
				case CHAR_LIT: return 27;
				case ID: return 27;
				case INT_LIT: return 27;
				case LPAREN: return 27;
				case MINUS: return 27;
				case NEW: return 27;
				case NOT: return 27;
				case NULL_LIT: return 27;
				case STRING_LIT: return 27;
				case THIS: return 27;
			}
			break;
		case 157:
			switch(symbol) {
				case ARRAY: return 63;
				case SEMICOLON: return 63;
			}
			break;
		case 158:
			switch(symbol) {
				case AND: return 54;
				case COMMA: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case RPAREN: return 54;
				case XOR: return 54;
			}
			break;
		case 161:
			switch(symbol) {
				case AND: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case RPAREN: return 6;
				case XOR: return 6;
			}
			break;
		case 162:
			switch(symbol) {
				case AND: return 4;
				case ASSIGN: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case INSTANCEOF: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case RPAREN: return 4;
				case XOR: return 4;
			}
			break;
		case 163:
			switch(symbol) {
				case AND: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case INSTANCEOF: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case SEMICOLON: return 5;
				case XOR: return 5;
			}
			break;
		case 166:
			switch(symbol) {
				case AND: return 4;
				case ASSIGN: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case INSTANCEOF: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case RBRACKET: return 4;
				case REMAINDER: return 4;
				case XOR: return 4;
			}
			break;
		case 167:
			switch(symbol) {
				case RPAREN: return 76;
			}
			break;
		case 168:
			switch(symbol) {
				case AND: return 44;
				case ASSIGN: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case SEMICOLON: return 44;
				case XOR: return 44;
			}
			break;
		case 169:
			switch(symbol) {
				case AND: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case INSTANCEOF: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case SEMICOLON: return 53;
				case XOR: return 53;
			}
			break;
		case 170:
			switch(symbol) {
				case BOOLEAN_LIT: return 14;
				case CHAR_LIT: return 14;
				case ID: return 14;
				case INT_LIT: return 14;
				case LPAREN: return 14;
				case MINUS: return 14;
				case NEW: return 14;
				case NOT: return 14;
				case NULL_LIT: return 14;
				case STRING_LIT: return 14;
				case THIS: return 14;
			}
			break;
		case 171:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case RBRACKET: return 54;
				case REMAINDER: return 54;
				case XOR: return 54;
			}
			break;
		case 172:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case SEMICOLON: return 50;
				case XOR: return 50;
			}
			break;
		case 174:
			switch(symbol) {
				case BOOLEAN: return 88;
				case BOOLEAN_LIT: return 88;
				case BYTE: return 88;
				case CHAR: return 88;
				case CHAR_LIT: return 88;
				case FOR: return 88;
				case ID: return 88;
				case IF: return 88;
				case INT: return 88;
				case INT_LIT: return 88;
				case LBRACE: return 88;
				case LPAREN: return 88;
				case MINUS: return 88;
				case NEW: return 88;
				case NOT: return 88;
				case NULL_LIT: return 88;
				case RBRACE: return 88;
				case RETURN: return 88;
				case SEMICOLON: return 88;
				case SHORT: return 88;
				case STRING_LIT: return 88;
				case THIS: return 88;
				case WHILE: return 88;
			}
			break;
		case 175:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case RBRACKET: return 51;
				case REMAINDER: return 51;
				case XOR: return 51;
			}
			break;
		case 176:
			switch(symbol) {
				case ABSTRACT: return 115;
				case BOOLEAN: return 115;
				case BYTE: return 115;
				case CHAR: return 115;
				case FINAL: return 115;
				case ID: return 115;
				case INT: return 115;
				case NATIVE: return 115;
				case PROTECTED: return 115;
				case PUBLIC: return 115;
				case SHORT: return 115;
				case STATIC: return 115;
				case VOID: return 115;
			}
			break;
		case 178:
			switch(symbol) {
				case AND: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case RPAREN: return 53;
				case XOR: return 53;
			}
			break;
		case 179:
			switch(symbol) {
				case AND: return 53;
				case ASSIGN: return 53;
				case COMMA: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case INSTANCEOF: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case RPAREN: return 53;
				case XOR: return 53;
			}
			break;
		case 180:
			switch(symbol) {
				case BOOLEAN_LIT: return 17;
				case CHAR_LIT: return 17;
				case ID: return 17;
				case INT_LIT: return 17;
				case LPAREN: return 17;
				case MINUS: return 17;
				case NEW: return 17;
				case NOT: return 17;
				case NULL_LIT: return 17;
				case STRING_LIT: return 17;
				case THIS: return 17;
			}
			break;
		case 181:
			switch(symbol) {
				case AND: return 1;
				case ASSIGN: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case INSTANCEOF: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case RPAREN: return 1;
				case XOR: return 1;
			}
			break;
		case 182:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case SEMICOLON: return 50;
				case XOR: return 50;
			}
			break;
		case 183:
			switch(symbol) {
				case AND: return 5;
				case ASSIGN: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case RPAREN: return 5;
				case XOR: return 5;
			}
			break;
		case 184:
			switch(symbol) {
				case AND: return 4;
				case ASSIGN: return 4;
				case COMMA: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case INSTANCEOF: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case RPAREN: return 4;
				case XOR: return 4;
			}
			break;
		case 185:
			switch(symbol) {
				case AND: return 8;
				case ASSIGN: return 8;
				case COMMA: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case INSTANCEOF: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case RPAREN: return 8;
				case XOR: return 8;
			}
			break;
		case 187:
			switch(symbol) {
				case AND: return 42;
				case ASSIGN: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case INSTANCEOF: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case RBRACKET: return 42;
				case REMAINDER: return 42;
				case XOR: return 42;
			}
			break;
		case 188:
			switch(symbol) {
				case AND: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case INSTANCEOF: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case RPAREN: return 1;
				case XOR: return 1;
			}
			break;
		case 190:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case INSTANCEOF: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case RPAREN: return 51;
				case XOR: return 51;
			}
			break;
		case 192:
			switch(symbol) {
				case AND: return 8;
				case ASSIGN: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case INSTANCEOF: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case RPAREN: return 8;
				case XOR: return 8;
			}
			break;
		case 195:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case COMMA: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case INSTANCEOF: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case RPAREN: return 51;
				case XOR: return 51;
			}
			break;
		case 196:
			switch(symbol) {
				case DOT: return 1;
				case LPAREN: return 1;
			}
			break;
		case 197:
			switch(symbol) {
				case AND: return 6;
				case ASSIGN: return 6;
				case COMMA: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case RPAREN: return 6;
				case XOR: return 6;
			}
			break;
		case 201:
			switch(symbol) {
				case COMMA: return 11;
				case LBRACE: return 11;
			}
			break;
		case 202:
			switch(symbol) {
				case AND: return 39;
				case ASSIGN: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case INSTANCEOF: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case SEMICOLON: return 39;
				case XOR: return 39;
			}
			break;
		case 203:
			switch(symbol) {
				case AND: return 69;
				case ASSIGN: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case RBRACKET: return 69;
				case REMAINDER: return 69;
				case XOR: return 69;
			}
			break;
		case 205:
			switch(symbol) {
				case BOOLEAN: return 91;
				case BOOLEAN_LIT: return 91;
				case BYTE: return 91;
				case CHAR: return 91;
				case CHAR_LIT: return 91;
				case FOR: return 91;
				case ID: return 91;
				case IF: return 91;
				case INT: return 91;
				case INT_LIT: return 91;
				case LBRACE: return 91;
				case LPAREN: return 91;
				case MINUS: return 91;
				case NEW: return 91;
				case NOT: return 91;
				case NULL_LIT: return 91;
				case RBRACE: return 91;
				case RETURN: return 91;
				case SEMICOLON: return 91;
				case SHORT: return 91;
				case STRING_LIT: return 91;
				case THIS: return 91;
				case WHILE: return 91;
			}
			break;
		case 206:
			switch(symbol) {
				case BOOLEAN_LIT: return 20;
				case CHAR_LIT: return 20;
				case ID: return 20;
				case INT_LIT: return 20;
				case LPAREN: return 20;
				case MINUS: return 20;
				case NEW: return 20;
				case NOT: return 20;
				case NULL_LIT: return 20;
				case STRING_LIT: return 20;
				case THIS: return 20;
			}
			break;
		case 207:
			switch(symbol) {
				case BOOLEAN_LIT: return 15;
				case CHAR_LIT: return 15;
				case ID: return 15;
				case INT_LIT: return 15;
				case LPAREN: return 15;
				case MINUS: return 15;
				case NEW: return 15;
				case NOT: return 15;
				case NULL_LIT: return 15;
				case STRING_LIT: return 15;
				case THIS: return 15;
			}
			break;
		case 210:
			switch(symbol) {
				case AND: return 57;
				case ASSIGN: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case INSTANCEOF: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case RPAREN: return 57;
				case XOR: return 57;
			}
			break;
		case 213:
			switch(symbol) {
				case SEMICOLON: return 102;
			}
			break;
		case 214:
			switch(symbol) {
				case BOOLEAN: return 110;
				case BYTE: return 110;
				case CHAR: return 110;
				case ID: return 110;
				case INT: return 110;
				case SHORT: return 110;
				case VOID: return 110;
			}
			break;
		case 215:
			switch(symbol) {
				case AND: return 7;
				case ASSIGN: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case RBRACKET: return 7;
				case REMAINDER: return 7;
				case XOR: return 7;
			}
			break;
		case 216:
			switch(symbol) {
				case AND: return 53;
				case ASSIGN: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case INSTANCEOF: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case RPAREN: return 53;
				case XOR: return 53;
			}
			break;
		case 217:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case RBRACKET: return 54;
				case REMAINDER: return 54;
				case XOR: return 54;
			}
			break;
		case 219:
			switch(symbol) {
				case ASSIGN: return 33;
				case COMMA: return 33;
				case RPAREN: return 33;
			}
			break;
		case 220:
			switch(symbol) {
				case AND: return 40;
				case ASSIGN: return 40;
				case COMMA: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case INSTANCEOF: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case RPAREN: return 40;
				case XOR: return 40;
			}
			break;
		case 221:
			switch(symbol) {
				case COMMA: return 30;
				case RPAREN: return 30;
			}
			break;
		case 223:
			switch(symbol) {
				case AND: return 44;
				case COMMA: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case INSTANCEOF: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case RPAREN: return 44;
				case XOR: return 44;
			}
			break;
		case 224:
			switch(symbol) {
				case AND: return 55;
				case COMMA: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case RPAREN: return 55;
				case XOR: return 55;
			}
			break;
		case 226:
			switch(symbol) {
				case RPAREN: return 64;
			}
			break;
		case 227:
			switch(symbol) {
				case AND: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case RBRACKET: return 45;
				case REMAINDER: return 45;
				case XOR: return 45;
			}
			break;
		case 229:
			switch(symbol) {
				case ABSTRACT: return 165;
				case BOOLEAN: return 165;
				case BYTE: return 165;
				case CHAR: return 165;
				case FINAL: return 165;
				case ID: return 165;
				case INT: return 165;
				case NATIVE: return 165;
				case PROTECTED: return 165;
				case PUBLIC: return 165;
				case RBRACE: return 165;
				case SEMICOLON: return 165;
				case SHORT: return 165;
				case STATIC: return 165;
				case VOID: return 165;
			}
			break;
		case 232:
			switch(symbol) {
				case AND: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case RBRACKET: return 7;
				case REMAINDER: return 7;
				case XOR: return 7;
			}
			break;
		case 233:
			switch(symbol) {
				case AND: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case INSTANCEOF: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case RBRACKET: return 1;
				case REMAINDER: return 1;
				case XOR: return 1;
			}
			break;
		case 235:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case SEMICOLON: return 55;
				case XOR: return 55;
			}
			break;
		case 238:
			switch(symbol) {
				case AND: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case INSTANCEOF: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case RBRACKET: return 7;
				case REMAINDER: return 7;
				case XOR: return 7;
			}
			break;
		case 239:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case RBRACKET: return 54;
				case REMAINDER: return 54;
				case XOR: return 54;
			}
			break;
		case 241:
			switch(symbol) {
				case ABSTRACT: return 157;
				case BOOLEAN: return 157;
				case BYTE: return 157;
				case CHAR: return 157;
				case FINAL: return 157;
				case ID: return 157;
				case INT: return 157;
				case NATIVE: return 157;
				case PROTECTED: return 157;
				case PUBLIC: return 157;
				case RBRACE: return 157;
				case SEMICOLON: return 157;
				case SHORT: return 157;
				case STATIC: return 157;
				case VOID: return 157;
			}
			break;
		case 242:
			switch(symbol) {
				case AND: return 44;
				case ASSIGN: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case INSTANCEOF: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case SEMICOLON: return 44;
				case XOR: return 44;
			}
			break;
		case 243:
			switch(symbol) {
				case AND: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case INSTANCEOF: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case RPAREN: return 39;
				case XOR: return 39;
			}
			break;
		case 244:
			switch(symbol) {
				case AND: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case INSTANCEOF: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case RPAREN: return 40;
				case XOR: return 40;
			}
			break;
		case 245:
			switch(symbol) {
				case BOOLEAN: return 110;
				case BYTE: return 110;
				case CHAR: return 110;
				case ID: return 110;
				case INT: return 110;
				case SHORT: return 110;
				case VOID: return 110;
			}
			break;
		case 247:
			switch(symbol) {
				case AND: return 8;
				case ASSIGN: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case SEMICOLON: return 8;
				case XOR: return 8;
			}
			break;
		case 248:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case DOT: return 2;
				case SEMICOLON: return 2;
			}
			break;
		case 249:
			switch(symbol) {
				case BOOLEAN: return 99;
				case BOOLEAN_LIT: return 99;
				case BYTE: return 99;
				case CHAR: return 99;
				case CHAR_LIT: return 99;
				case ELSE: return 99;
				case FOR: return 99;
				case ID: return 99;
				case IF: return 99;
				case INT: return 99;
				case INT_LIT: return 99;
				case LBRACE: return 99;
				case LPAREN: return 99;
				case MINUS: return 99;
				case NEW: return 99;
				case NOT: return 99;
				case NULL_LIT: return 99;
				case RBRACE: return 99;
				case RETURN: return 99;
				case SEMICOLON: return 99;
				case SHORT: return 99;
				case STRING_LIT: return 99;
				case THIS: return 99;
				case WHILE: return 99;
			}
			break;
		case 250:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case SEMICOLON: return 54;
				case XOR: return 54;
			}
			break;
		case 251:
			switch(symbol) {
				case AND: return 44;
				case ASSIGN: return 44;
				case COMMA: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case INSTANCEOF: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case RPAREN: return 44;
				case XOR: return 44;
			}
			break;
		case 252:
			switch(symbol) {
				case AND: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case INSTANCEOF: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case SEMICOLON: return 42;
				case XOR: return 42;
			}
			break;
		case 254:
			switch(symbol) {
				case AND: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case RBRACKET: return 4;
				case REMAINDER: return 4;
				case XOR: return 4;
			}
			break;
		case 255:
			switch(symbol) {
				case AND: return 70;
				case ASSIGN: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case RPAREN: return 70;
				case XOR: return 70;
			}
			break;
		case 256:
			switch(symbol) {
				case ABSTRACT: return 113;
				case CLASS: return 113;
				case FINAL: return 113;
				case INTERFACE: return 113;
				case NATIVE: return 113;
				case PROTECTED: return 113;
				case PUBLIC: return 113;
				case STATIC: return 113;
			}
			break;
		case 257:
			switch(symbol) {
				case RPAREN: return 67;
			}
			break;
		case 258:
			switch(symbol) {
				case AND: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case INSTANCEOF: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case RBRACKET: return 52;
				case REMAINDER: return 52;
				case XOR: return 52;
			}
			break;
		case 260:
			switch(symbol) {
				case AND: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case SEMICOLON: return 53;
				case XOR: return 53;
			}
			break;
		case 261:
			switch(symbol) {
				case AND: return 51;
				case COMMA: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case RPAREN: return 51;
				case XOR: return 51;
			}
			break;
		case 262:
			switch(symbol) {
				case COMMA: return 145;
				case LBRACE: return 145;
			}
			break;
		case 263:
			switch(symbol) {
				case RPAREN: return 65;
			}
			break;
		case 264:
			switch(symbol) {
				case AND: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case INSTANCEOF: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case RBRACKET: return 70;
				case REMAINDER: return 70;
				case XOR: return 70;
			}
			break;
		case 265:
			switch(symbol) {
				case AND: return 44;
				case ASSIGN: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case RPAREN: return 44;
				case XOR: return 44;
			}
			break;
		case 266:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case RPAREN: return 50;
				case XOR: return 50;
			}
			break;
		case 267:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case SEMICOLON: return 2;
			}
			break;
		case 269:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case INSTANCEOF: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case RPAREN: return 51;
				case XOR: return 51;
			}
			break;
		case 270:
			switch(symbol) {
				case AND: return 6;
				case ASSIGN: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case SEMICOLON: return 6;
				case XOR: return 6;
			}
			break;
		case 271:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case SEMICOLON: return 56;
				case XOR: return 56;
			}
			break;
		case 272:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case COMMA: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case RPAREN: return 51;
				case XOR: return 51;
			}
			break;
		case 273:
			switch(symbol) {
				case ID: return 10;
			}
			break;
		case 275:
			switch(symbol) {
				case AND: return 1;
				case ASSIGN: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case SEMICOLON: return 1;
				case XOR: return 1;
			}
			break;
		case 276:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case RBRACKET: return 56;
				case REMAINDER: return 56;
				case XOR: return 56;
			}
			break;
		case 277:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case SEMICOLON: return 51;
				case XOR: return 51;
			}
			break;
		case 278:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case INSTANCEOF: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case SEMICOLON: return 50;
				case XOR: return 50;
			}
			break;
		case 279:
			switch(symbol) {
				case AND: return 59;
				case ASSIGN: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case INSTANCEOF: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case RPAREN: return 59;
				case XOR: return 59;
			}
			break;
		case 281:
			switch(symbol) {
				case AND: return 45;
				case ASSIGN: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case INSTANCEOF: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case RBRACKET: return 45;
				case REMAINDER: return 45;
				case XOR: return 45;
			}
			break;
		case 284:
			switch(symbol) {
				case ABSTRACT: return 116;
				case BOOLEAN: return 116;
				case BYTE: return 116;
				case CHAR: return 116;
				case FINAL: return 116;
				case ID: return 116;
				case INT: return 116;
				case NATIVE: return 116;
				case PROTECTED: return 116;
				case PUBLIC: return 116;
				case SHORT: return 116;
				case STATIC: return 116;
				case VOID: return 116;
			}
			break;
		case 287:
			switch(symbol) {
				case AND: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case RPAREN: return 5;
				case XOR: return 5;
			}
			break;
		case 289:
			switch(symbol) {
				case AND: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case INSTANCEOF: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case RBRACKET: return 44;
				case REMAINDER: return 44;
				case XOR: return 44;
			}
			break;
		case 290:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case INSTANCEOF: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case SEMICOLON: return 51;
				case XOR: return 51;
			}
			break;
		case 291:
			switch(symbol) {
				case AND: return 44;
				case ASSIGN: return 44;
				case COMMA: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case RPAREN: return 44;
				case XOR: return 44;
			}
			break;
		case 294:
			switch(symbol) {
				case ARRAY: return 67;
				case ASSIGN: return 67;
				case SEMICOLON: return 67;
			}
			break;
		case 296:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case SEMICOLON: return 54;
				case XOR: return 54;
			}
			break;
		case 297:
			switch(symbol) {
				case BOOLEAN: return 94;
				case BOOLEAN_LIT: return 94;
				case BYTE: return 94;
				case CHAR: return 94;
				case CHAR_LIT: return 94;
				case ELSE: return 94;
				case FOR: return 94;
				case ID: return 94;
				case IF: return 94;
				case INT: return 94;
				case INT_LIT: return 94;
				case LBRACE: return 94;
				case LPAREN: return 94;
				case MINUS: return 94;
				case NEW: return 94;
				case NOT: return 94;
				case NULL_LIT: return 94;
				case RBRACE: return 94;
				case RETURN: return 94;
				case SEMICOLON: return 94;
				case SHORT: return 94;
				case STRING_LIT: return 94;
				case THIS: return 94;
				case WHILE: return 94;
			}
			break;
		case 298:
			switch(symbol) {
				case AND: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case INSTANCEOF: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case SEMICOLON: return 44;
				case XOR: return 44;
			}
			break;
		case 299:
			switch(symbol) {
				case AND: return 4;
				case COMMA: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case RPAREN: return 4;
				case XOR: return 4;
			}
			break;
		case 301:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case RPAREN: return 54;
				case XOR: return 54;
			}
			break;
		case 302:
			switch(symbol) {
				case AND: return 57;
				case ASSIGN: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case INSTANCEOF: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case SEMICOLON: return 57;
				case XOR: return 57;
			}
			break;
		case 304:
			switch(symbol) {
				case BOOLEAN: return 95;
				case BOOLEAN_LIT: return 95;
				case BYTE: return 95;
				case CHAR: return 95;
				case CHAR_LIT: return 95;
				case ELSE: return 95;
				case FOR: return 95;
				case ID: return 95;
				case IF: return 95;
				case INT: return 95;
				case INT_LIT: return 95;
				case LBRACE: return 95;
				case LPAREN: return 95;
				case MINUS: return 95;
				case NEW: return 95;
				case NOT: return 95;
				case NULL_LIT: return 95;
				case RBRACE: return 95;
				case RETURN: return 95;
				case SEMICOLON: return 95;
				case SHORT: return 95;
				case STRING_LIT: return 95;
				case THIS: return 95;
				case WHILE: return 95;
			}
			break;
		case 306:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 308:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case SEMICOLON: return 56;
				case XOR: return 56;
			}
			break;
		case 309:
			switch(symbol) {
				case AND: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case INSTANCEOF: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case RBRACKET: return 61;
				case REMAINDER: return 61;
				case XOR: return 61;
			}
			break;
		case 311:
			switch(symbol) {
				case AND: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case SEMICOLON: return 7;
				case XOR: return 7;
			}
			break;
		case 312:
			switch(symbol) {
				case AND: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case RBRACKET: return 8;
				case REMAINDER: return 8;
				case XOR: return 8;
			}
			break;
		case 313:
			switch(symbol) {
				case BOOLEAN: return 100;
				case BOOLEAN_LIT: return 100;
				case BYTE: return 100;
				case CHAR: return 100;
				case CHAR_LIT: return 100;
				case FOR: return 100;
				case ID: return 100;
				case IF: return 100;
				case INT: return 100;
				case INT_LIT: return 100;
				case LBRACE: return 100;
				case LPAREN: return 100;
				case MINUS: return 100;
				case NEW: return 100;
				case NOT: return 100;
				case NULL_LIT: return 100;
				case RBRACE: return 100;
				case RETURN: return 100;
				case SEMICOLON: return 100;
				case SHORT: return 100;
				case STRING_LIT: return 100;
				case THIS: return 100;
				case WHILE: return 100;
			}
			break;
		case 315:
			switch(symbol) {
				case AND: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case INSTANCEOF: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case RPAREN: return 58;
				case XOR: return 58;
			}
			break;
		case 316:
			switch(symbol) {
				case BOOLEAN: return 89;
				case BOOLEAN_LIT: return 89;
				case BYTE: return 89;
				case CHAR: return 89;
				case CHAR_LIT: return 89;
				case FOR: return 89;
				case ID: return 89;
				case IF: return 89;
				case INT: return 89;
				case INT_LIT: return 89;
				case LBRACE: return 89;
				case LPAREN: return 89;
				case MINUS: return 89;
				case NEW: return 89;
				case NOT: return 89;
				case NULL_LIT: return 89;
				case RBRACE: return 89;
				case RETURN: return 89;
				case SEMICOLON: return 89;
				case SHORT: return 89;
				case STRING_LIT: return 89;
				case THIS: return 89;
				case WHILE: return 89;
			}
			break;
		case 317:
			switch(symbol) {
				case SEMICOLON: return 105;
			}
			break;
		case 318:
			switch(symbol) {
				case ARRAY: return 67;
				case RBRACKET: return 67;
			}
			break;
		case 319:
			switch(symbol) {
				case SEMICOLON: return 49;
			}
			break;
		case 320:
			switch(symbol) {
				case AND: return 7;
				case ASSIGN: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case SEMICOLON: return 7;
				case XOR: return 7;
			}
			break;
		case 321:
			switch(symbol) {
				case AND: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case RBRACKET: return 57;
				case REMAINDER: return 57;
				case XOR: return 57;
			}
			break;
		case 322:
			switch(symbol) {
				case AND: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case RPAREN: return 7;
				case XOR: return 7;
			}
			break;
		case 325:
			switch(symbol) {
				case IMPLEMENTS: return 10;
				case LBRACE: return 10;
			}
			break;
		case 326:
			switch(symbol) {
				case AND: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case SEMICOLON: return 5;
				case XOR: return 5;
			}
			break;
		case 327:
			switch(symbol) {
				case SEMICOLON: return 104;
			}
			break;
		case 328:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case COMMA: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case RPAREN: return 54;
				case XOR: return 54;
			}
			break;
		case 329:
			switch(symbol) {
				case AND: return 62;
				case ASSIGN: return 62;
				case COMMA: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case RPAREN: return 62;
				case XOR: return 62;
			}
			break;
		case 330:
			switch(symbol) {
				case BOOLEAN: return 101;
				case BOOLEAN_LIT: return 101;
				case BYTE: return 101;
				case CHAR: return 101;
				case CHAR_LIT: return 101;
				case ELSE: return 101;
				case FOR: return 101;
				case ID: return 101;
				case IF: return 101;
				case INT: return 101;
				case INT_LIT: return 101;
				case LBRACE: return 101;
				case LPAREN: return 101;
				case MINUS: return 101;
				case NEW: return 101;
				case NOT: return 101;
				case NULL_LIT: return 101;
				case RBRACE: return 101;
				case RETURN: return 101;
				case SEMICOLON: return 101;
				case SHORT: return 101;
				case STRING_LIT: return 101;
				case THIS: return 101;
				case WHILE: return 101;
			}
			break;
		case 334:
			switch(symbol) {
				case AND: return 5;
				case COMMA: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case RPAREN: return 5;
				case XOR: return 5;
			}
			break;
		case 336:
			switch(symbol) {
				case ASSIGN: return 10;
				case SEMICOLON: return 10;
			}
			break;
		case 337:
			switch(symbol) {
				case AND: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case INSTANCEOF: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case SEMICOLON: return 43;
				case XOR: return 43;
			}
			break;
		case 338:
			switch(symbol) {
				case AND: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case RPAREN: return 40;
				case XOR: return 40;
			}
			break;
		case 339:
			switch(symbol) {
				case AND: return 36;
				case DIV: return 36;
				case EAGER_AND: return 36;
				case EAGER_OR: return 36;
				case EQ: return 36;
				case GEQ: return 36;
				case GT: return 36;
				case LEQ: return 36;
				case LT: return 36;
				case MINUS: return 36;
				case MULT: return 36;
				case NEQ: return 36;
				case OR: return 36;
				case PLUS: return 36;
				case REMAINDER: return 36;
				case RPAREN: return 36;
				case XOR: return 36;
			}
			break;
		case 340:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case RBRACKET: return 51;
				case REMAINDER: return 51;
				case XOR: return 51;
			}
			break;
		case 341:
			switch(symbol) {
				case AND: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case INSTANCEOF: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case SEMICOLON: return 40;
				case XOR: return 40;
			}
			break;
		case 343:
			switch(symbol) {
				case AND: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case INSTANCEOF: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case RBRACKET: return 40;
				case REMAINDER: return 40;
				case XOR: return 40;
			}
			break;
		case 344:
			switch(symbol) {
				case AND: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case INSTANCEOF: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case RBRACKET: return 43;
				case REMAINDER: return 43;
				case XOR: return 43;
			}
			break;
		case 345:
			switch(symbol) {
				case AND: return 8;
				case ASSIGN: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case RBRACKET: return 8;
				case REMAINDER: return 8;
				case XOR: return 8;
			}
			break;
		case 346:
			switch(symbol) {
				case AND: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case RPAREN: return 42;
				case XOR: return 42;
			}
			break;
		case 347:
			switch(symbol) {
				case ABSTRACT: return 160;
				case BOOLEAN: return 160;
				case BYTE: return 160;
				case CHAR: return 160;
				case FINAL: return 160;
				case ID: return 160;
				case INT: return 160;
				case NATIVE: return 160;
				case PROTECTED: return 160;
				case PUBLIC: return 160;
				case RBRACE: return 160;
				case SEMICOLON: return 160;
				case SHORT: return 160;
				case STATIC: return 160;
				case VOID: return 160;
			}
			break;
		case 348:
			switch(symbol) {
				case AND: return 69;
				case COMMA: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case INSTANCEOF: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case RPAREN: return 69;
				case XOR: return 69;
			}
			break;
		case 349:
			switch(symbol) {
				case AND: return 6;
				case COMMA: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case RPAREN: return 6;
				case XOR: return 6;
			}
			break;
		case 350:
			switch(symbol) {
				case ABSTRACT: return 118;
				case BOOLEAN: return 118;
				case BYTE: return 118;
				case CHAR: return 118;
				case FINAL: return 118;
				case ID: return 118;
				case INT: return 118;
				case NATIVE: return 118;
				case PROTECTED: return 118;
				case PUBLIC: return 118;
				case SHORT: return 118;
				case STATIC: return 118;
				case VOID: return 118;
			}
			break;
		case 351:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case INSTANCEOF: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case RPAREN: return 50;
				case XOR: return 50;
			}
			break;
		case 352:
			switch(symbol) {
				case ARRAY: return 66;
				case RPAREN: return 66;
			}
			break;
		case 353:
			switch(symbol) {
				case AND: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case INSTANCEOF: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case RBRACKET: return 62;
				case REMAINDER: return 62;
				case XOR: return 62;
			}
			break;
		case 354:
			switch(symbol) {
				case ARRAY: return 65;
				case ASSIGN: return 65;
				case RPAREN: return 65;
			}
			break;
		case 356:
			switch(symbol) {
				case ABSTRACT: return 113;
				case BOOLEAN: return 113;
				case BYTE: return 113;
				case CHAR: return 113;
				case FINAL: return 113;
				case ID: return 113;
				case INT: return 113;
				case NATIVE: return 113;
				case PROTECTED: return 113;
				case PUBLIC: return 113;
				case SHORT: return 113;
				case STATIC: return 113;
				case VOID: return 113;
			}
			break;
		case 357:
			switch(symbol) {
				case AND: return 71;
				case ASSIGN: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case SEMICOLON: return 71;
				case XOR: return 71;
			}
			break;
		case 358:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case RBRACKET: return 50;
				case REMAINDER: return 50;
				case XOR: return 50;
			}
			break;
		case 361:
			switch(symbol) {
				case AND: return 73;
				case ASSIGN: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case RPAREN: return 73;
				case XOR: return 73;
			}
			break;
		case 362:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case INSTANCEOF: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case RBRACKET: return 51;
				case REMAINDER: return 51;
				case XOR: return 51;
			}
			break;
		case 363:
			switch(symbol) {
				case AND: return 52;
				case ASSIGN: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case SEMICOLON: return 52;
				case XOR: return 52;
			}
			break;
		case 364:
			switch(symbol) {
				case AND: return 41;
				case ASSIGN: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case INSTANCEOF: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case RBRACKET: return 41;
				case REMAINDER: return 41;
				case XOR: return 41;
			}
			break;
		case 369:
			switch(symbol) {
				case ABSTRACT: return 115;
				case CLASS: return 115;
				case FINAL: return 115;
				case INTERFACE: return 115;
				case NATIVE: return 115;
				case PROTECTED: return 115;
				case PUBLIC: return 115;
				case STATIC: return 115;
			}
			break;
		case 370:
			switch(symbol) {
				case AND: return 53;
				case ASSIGN: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case RBRACKET: return 53;
				case REMAINDER: return 53;
				case XOR: return 53;
			}
			break;
		case 371:
			switch(symbol) {
				case AND: return 44;
				case ASSIGN: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case RBRACKET: return 44;
				case REMAINDER: return 44;
				case XOR: return 44;
			}
			break;
		case 372:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case SEMICOLON: return 54;
				case XOR: return 54;
			}
			break;
		case 373:
			switch(symbol) {
				case SEMICOLON: return 103;
			}
			break;
		case 374:
			switch(symbol) {
				case AND: return 72;
				case COMMA: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case RPAREN: return 72;
				case XOR: return 72;
			}
			break;
		case 375:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case INSTANCEOF: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case SEMICOLON: return 50;
				case XOR: return 50;
			}
			break;
		case 376:
			switch(symbol) {
				case AND: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case INSTANCEOF: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case RBRACKET: return 5;
				case REMAINDER: return 5;
				case XOR: return 5;
			}
			break;
		case 378:
			switch(symbol) {
				case RPAREN: return 75;
			}
			break;
		case 379:
			switch(symbol) {
				case IMPLEMENTS: return 11;
				case LBRACE: return 11;
			}
			break;
		case 380:
			switch(symbol) {
				case AND: return 8;
				case ASSIGN: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case RPAREN: return 8;
				case XOR: return 8;
			}
			break;
		case 381:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case ID: return 2;
			}
			break;
		case 382:
			switch(symbol) {
				case ARRAY: return 66;
				case COMMA: return 66;
				case RPAREN: return 66;
			}
			break;
		case 383:
			switch(symbol) {
				case ARRAY: return 67;
				case ID: return 67;
			}
			break;
		case 385:
			switch(symbol) {
				case AND: return 60;
				case ASSIGN: return 60;
				case COMMA: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case RPAREN: return 60;
				case XOR: return 60;
			}
			break;
		case 386:
			switch(symbol) {
				case RPAREN: return 108;
			}
			break;
		case 388:
			switch(symbol) {
				case RBRACE: return 81;
			}
			break;
		case 389:
			switch(symbol) {
				case AND: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case INSTANCEOF: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case RPAREN: return 5;
				case XOR: return 5;
			}
			break;
		case 390:
			switch(symbol) {
				case ABSTRACT: return 152;
				case BOOLEAN: return 152;
				case BYTE: return 152;
				case CHAR: return 152;
				case FINAL: return 152;
				case ID: return 152;
				case INT: return 152;
				case NATIVE: return 152;
				case PROTECTED: return 152;
				case PUBLIC: return 152;
				case RBRACE: return 152;
				case SEMICOLON: return 152;
				case SHORT: return 152;
				case STATIC: return 152;
				case VOID: return 152;
			}
			break;
		case 391:
			switch(symbol) {
				case LPAREN: return 3;
			}
			break;
		case 394:
			switch(symbol) {
				case AND: return 60;
				case ASSIGN: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case SEMICOLON: return 60;
				case XOR: return 60;
			}
			break;
		case 396:
			switch(symbol) {
				case AND: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case INSTANCEOF: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case RPAREN: return 52;
				case XOR: return 52;
			}
			break;
		case 397:
			switch(symbol) {
				case RBRACE: return 82;
			}
			break;
		case 398:
			switch(symbol) {
				case BOOLEAN: return 109;
				case BYTE: return 109;
				case CHAR: return 109;
				case ID: return 109;
				case INT: return 109;
				case SHORT: return 109;
				case VOID: return 109;
			}
			break;
		case 399:
			switch(symbol) {
				case AND: return 50;
				case COMMA: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case RPAREN: return 50;
				case XOR: return 50;
			}
			break;
		case 401:
			switch(symbol) {
				case RPAREN: return 77;
			}
			break;
		case 402:
			switch(symbol) {
				case AND: return 53;
				case COMMA: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case RPAREN: return 53;
				case XOR: return 53;
			}
			break;
		case 404:
			switch(symbol) {
				case COMMA: return 9;
				case LBRACE: return 9;
			}
			break;
		case 406:
			switch(symbol) {
				case AND: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case RPAREN: return 44;
				case XOR: return 44;
			}
			break;
		case 407:
			switch(symbol) {
				case AND: return 45;
				case ASSIGN: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case INSTANCEOF: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case SEMICOLON: return 45;
				case XOR: return 45;
			}
			break;
		case 408:
			switch(symbol) {
				case AND: return 42;
				case COMMA: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case RPAREN: return 42;
				case XOR: return 42;
			}
			break;
		case 409:
			switch(symbol) {
				case ARRAY: return 63;
				case ID: return 63;
			}
			break;
		case 411:
			switch(symbol) {
				case ASSIGN: return 38;
				case RPAREN: return 38;
			}
			break;
		case 412:
			switch(symbol) {
				case AND: return 73;
				case ASSIGN: return 73;
				case COMMA: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case INSTANCEOF: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case RPAREN: return 73;
				case XOR: return 73;
			}
			break;
		case 416:
			switch(symbol) {
				case ARRAY: return 66;
				case ID: return 66;
			}
			break;
		case 419:
			switch(symbol) {
				case AND: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case RPAREN: return 39;
				case XOR: return 39;
			}
			break;
		case 421:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case SEMICOLON: return 56;
				case XOR: return 56;
			}
			break;
		case 422:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case COMMA: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case RPAREN: return 50;
				case XOR: return 50;
			}
			break;
		case 428:
			switch(symbol) {
				case AND: return 1;
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case ID: return 1;
				case INSTANCEOF: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case SEMICOLON: return 1;
				case XOR: return 1;
			}
			break;
		case 430:
			switch(symbol) {
				case RPAREN: return 106;
			}
			break;
		case 432:
			switch(symbol) {
				case ABSTRACT: return 158;
				case BOOLEAN: return 158;
				case BYTE: return 158;
				case CHAR: return 158;
				case FINAL: return 158;
				case ID: return 158;
				case INT: return 158;
				case NATIVE: return 158;
				case PROTECTED: return 158;
				case PUBLIC: return 158;
				case RBRACE: return 158;
				case SEMICOLON: return 158;
				case SHORT: return 158;
				case STATIC: return 158;
				case VOID: return 158;
			}
			break;
		case 436:
			switch(symbol) {
				case AND: return 45;
				case ASSIGN: return 45;
				case COMMA: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case RPAREN: return 45;
				case XOR: return 45;
			}
			break;
		case 439:
			switch(symbol) {
				case AND: return 61;
				case ASSIGN: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case SEMICOLON: return 61;
				case XOR: return 61;
			}
			break;
		case 442:
			switch(symbol) {
				case RBRACE: return 82;
			}
			break;
		case 443:
			switch(symbol) {
				case AND: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case INSTANCEOF: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case RBRACKET: return 53;
				case REMAINDER: return 53;
				case XOR: return 53;
			}
			break;
		case 445:
			switch(symbol) {
				case BOOLEAN_LIT: return 21;
				case CHAR_LIT: return 21;
				case ID: return 21;
				case INT_LIT: return 21;
				case LPAREN: return 21;
				case MINUS: return 21;
				case NEW: return 21;
				case NOT: return 21;
				case NULL_LIT: return 21;
				case STRING_LIT: return 21;
				case THIS: return 21;
			}
			break;
		case 446:
			switch(symbol) {
				case AND: return 44;
				case COMMA: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case RPAREN: return 44;
				case XOR: return 44;
			}
			break;
		case 447:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case RPAREN: return 55;
				case XOR: return 55;
			}
			break;
		case 448:
			switch(symbol) {
				case AND: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case RPAREN: return 4;
				case XOR: return 4;
			}
			break;
		case 449:
			switch(symbol) {
				case AND: return 72;
				case ASSIGN: return 72;
				case COMMA: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case INSTANCEOF: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case RPAREN: return 72;
				case XOR: return 72;
			}
			break;
		case 451:
			switch(symbol) {
				case AND: return 58;
				case ASSIGN: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case RPAREN: return 58;
				case XOR: return 58;
			}
			break;
		case 453:
			switch(symbol) {
				case AND: return 70;
				case ASSIGN: return 70;
				case COMMA: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case INSTANCEOF: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case RPAREN: return 70;
				case XOR: return 70;
			}
			break;
		case 454:
			switch(symbol) {
				case AND: return 1;
				case ASSIGN: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case RPAREN: return 1;
				case XOR: return 1;
			}
			break;
		case 455:
			switch(symbol) {
				case AND: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case INSTANCEOF: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case RPAREN: return 53;
				case XOR: return 53;
			}
			break;
		case 456:
			switch(symbol) {
				case AND: return 5;
				case ASSIGN: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case RBRACKET: return 5;
				case REMAINDER: return 5;
				case XOR: return 5;
			}
			break;
		case 457:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case RPAREN: return 50;
				case XOR: return 50;
			}
			break;
		case 458:
			switch(symbol) {
				case RPAREN: return 66;
			}
			break;
		case 464:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case IMPLEMENTS: return 1;
				case LBRACE: return 1;
			}
			break;
		case 465:
			switch(symbol) {
				case AND: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case SEMICOLON: return 4;
				case XOR: return 4;
			}
			break;
		case 467:
			switch(symbol) {
				case RBRACE: return 82;
			}
			break;
		case 469:
			switch(symbol) {
				case AND: return 59;
				case ASSIGN: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case RPAREN: return 59;
				case XOR: return 59;
			}
			break;
		case 471:
			switch(symbol) {
				case ID: return 11;
			}
			break;
		case 472:
			switch(symbol) {
				case AND: return 62;
				case ASSIGN: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case RPAREN: return 62;
				case XOR: return 62;
			}
			break;
		case 475:
			switch(symbol) {
				case AND: return 43;
				case ASSIGN: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case SEMICOLON: return 43;
				case XOR: return 43;
			}
			break;
		case 476:
			switch(symbol) {
				case AND: return 40;
				case ASSIGN: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case SEMICOLON: return 40;
				case XOR: return 40;
			}
			break;
		case 478:
			switch(symbol) {
				case ABSTRACT: return 150;
				case BOOLEAN: return 150;
				case BYTE: return 150;
				case CHAR: return 150;
				case FINAL: return 150;
				case ID: return 150;
				case INT: return 150;
				case NATIVE: return 150;
				case PROTECTED: return 150;
				case PUBLIC: return 150;
				case RBRACE: return 150;
				case SEMICOLON: return 150;
				case SHORT: return 150;
				case STATIC: return 150;
				case VOID: return 150;
			}
			break;
		case 479:
			switch(symbol) {
				case AND: return 45;
				case ASSIGN: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case RPAREN: return 45;
				case XOR: return 45;
			}
			break;
		case 480:
			switch(symbol) {
				case AND: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case RBRACKET: return 39;
				case REMAINDER: return 39;
				case XOR: return 39;
			}
			break;
		case 481:
			switch(symbol) {
				case AND: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case INSTANCEOF: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case SEMICOLON: return 7;
				case XOR: return 7;
			}
			break;
		case 482:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case RPAREN: return 51;
				case XOR: return 51;
			}
			break;
		case 483:
			switch(symbol) {
				case ASSIGN: return 9;
				case SEMICOLON: return 9;
			}
			break;
		case 484:
			switch(symbol) {
				case ARRAY: return 65;
				case IMPLEMENTS: return 65;
				case LBRACE: return 65;
			}
			break;
		case 485:
			switch(symbol) {
				case BOOLEAN: return 85;
				case BOOLEAN_LIT: return 85;
				case BYTE: return 85;
				case CHAR: return 85;
				case CHAR_LIT: return 85;
				case FOR: return 85;
				case ID: return 85;
				case IF: return 85;
				case INT: return 85;
				case INT_LIT: return 85;
				case LBRACE: return 85;
				case LPAREN: return 85;
				case MINUS: return 85;
				case NEW: return 85;
				case NOT: return 85;
				case NULL_LIT: return 85;
				case RBRACE: return 85;
				case RETURN: return 85;
				case SEMICOLON: return 85;
				case SHORT: return 85;
				case STRING_LIT: return 85;
				case THIS: return 85;
				case WHILE: return 85;
			}
			break;
		case 486:
			switch(symbol) {
				case AND: return 70;
				case ASSIGN: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case INSTANCEOF: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case SEMICOLON: return 70;
				case XOR: return 70;
			}
			break;
		case 487:
			switch(symbol) {
				case AND: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case INSTANCEOF: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case RPAREN: return 45;
				case XOR: return 45;
			}
			break;
		case 489:
			switch(symbol) {
				case AND: return 52;
				case ASSIGN: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case RBRACKET: return 52;
				case REMAINDER: return 52;
				case XOR: return 52;
			}
			break;
		case 490:
			switch(symbol) {
				case BOOLEAN: return 80;
				case BOOLEAN_LIT: return 80;
				case BYTE: return 80;
				case CHAR: return 80;
				case CHAR_LIT: return 80;
				case ELSE: return 80;
				case FOR: return 80;
				case ID: return 80;
				case IF: return 80;
				case INT: return 80;
				case INT_LIT: return 80;
				case LBRACE: return 80;
				case LPAREN: return 80;
				case MINUS: return 80;
				case NEW: return 80;
				case NOT: return 80;
				case NULL_LIT: return 80;
				case RBRACE: return 80;
				case RETURN: return 80;
				case SEMICOLON: return 80;
				case SHORT: return 80;
				case STRING_LIT: return 80;
				case THIS: return 80;
				case WHILE: return 80;
			}
			break;
		case 491:
			switch(symbol) {
				case AND: return 61;
				case ASSIGN: return 61;
				case COMMA: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case INSTANCEOF: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case RPAREN: return 61;
				case XOR: return 61;
			}
			break;
		case 492:
			switch(symbol) {
				case AND: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case RPAREN: return 52;
				case XOR: return 52;
			}
			break;
		case 495:
			switch(symbol) {
				case AND: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case INSTANCEOF: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case SEMICOLON: return 2;
				case XOR: return 2;
			}
			break;
		case 496:
			switch(symbol) {
				case AND: return 8;
				case COMMA: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case RPAREN: return 8;
				case XOR: return 8;
			}
			break;
		case 498:
			switch(symbol) {
				case AND: return 60;
				case ASSIGN: return 60;
				case COMMA: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case INSTANCEOF: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case RPAREN: return 60;
				case XOR: return 60;
			}
			break;
		case 500:
			switch(symbol) {
				case AND: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case INSTANCEOF: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case SEMICOLON: return 41;
				case XOR: return 41;
			}
			break;
		case 501:
			switch(symbol) {
				case ABSTRACT: return 168;
				case BOOLEAN: return 168;
				case BYTE: return 168;
				case CHAR: return 168;
				case FINAL: return 168;
				case ID: return 168;
				case INT: return 168;
				case NATIVE: return 168;
				case PROTECTED: return 168;
				case PUBLIC: return 168;
				case RBRACE: return 168;
				case SEMICOLON: return 168;
				case SHORT: return 168;
				case STATIC: return 168;
				case VOID: return 168;
			}
			break;
		case 502:
			switch(symbol) {
				case ARRAY: return 63;
				case RBRACKET: return 63;
			}
			break;
		case 503:
			switch(symbol) {
				case END_TERMINAL: return 137;
			}
			break;
		case 504:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case REMAINDER: return 54;
				case SEMICOLON: return 54;
				case XOR: return 54;
			}
			break;
		case 505:
			switch(symbol) {
				case AND: return 5;
				case COMMA: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case INSTANCEOF: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case RPAREN: return 5;
				case XOR: return 5;
			}
			break;
		case 506:
			switch(symbol) {
				case BOOLEAN: return 83;
				case BOOLEAN_LIT: return 83;
				case BYTE: return 83;
				case CHAR: return 83;
				case CHAR_LIT: return 83;
				case FOR: return 83;
				case ID: return 83;
				case IF: return 83;
				case INT: return 83;
				case INT_LIT: return 83;
				case LBRACE: return 83;
				case LPAREN: return 83;
				case MINUS: return 83;
				case NEW: return 83;
				case NOT: return 83;
				case NULL_LIT: return 83;
				case RBRACE: return 83;
				case RETURN: return 83;
				case SEMICOLON: return 83;
				case SHORT: return 83;
				case STRING_LIT: return 83;
				case THIS: return 83;
				case WHILE: return 83;
			}
			break;
		case 507:
			switch(symbol) {
				case AND: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case SEMICOLON: return 62;
				case XOR: return 62;
			}
			break;
		case 508:
			switch(symbol) {
				case AND: return 59;
				case ASSIGN: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case INSTANCEOF: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case RBRACKET: return 59;
				case REMAINDER: return 59;
				case XOR: return 59;
			}
			break;
		case 509:
			switch(symbol) {
				case BOOLEAN: return 90;
				case BOOLEAN_LIT: return 90;
				case BYTE: return 90;
				case CHAR: return 90;
				case CHAR_LIT: return 90;
				case FOR: return 90;
				case ID: return 90;
				case IF: return 90;
				case INT: return 90;
				case INT_LIT: return 90;
				case LBRACE: return 90;
				case LPAREN: return 90;
				case MINUS: return 90;
				case NEW: return 90;
				case NOT: return 90;
				case NULL_LIT: return 90;
				case RBRACE: return 90;
				case RETURN: return 90;
				case SEMICOLON: return 90;
				case SHORT: return 90;
				case STRING_LIT: return 90;
				case THIS: return 90;
				case WHILE: return 90;
			}
			break;
		case 510:
			switch(symbol) {
				case AND: return 52;
				case ASSIGN: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case RPAREN: return 52;
				case XOR: return 52;
			}
			break;
		case 511:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case RPAREN: return 51;
				case XOR: return 51;
			}
			break;
		case 512:
			switch(symbol) {
				case ASSIGN: return 35;
				case RPAREN: return 35;
			}
			break;
		case 514:
			switch(symbol) {
				case END_TERMINAL: return 143;
			}
			break;
		case 515:
			switch(symbol) {
				case ARRAY: return 65;
				case ID: return 65;
			}
			break;
		case 516:
			switch(symbol) {
				case BOOLEAN: return 97;
				case BOOLEAN_LIT: return 97;
				case BYTE: return 97;
				case CHAR: return 97;
				case CHAR_LIT: return 97;
				case FOR: return 97;
				case ID: return 97;
				case IF: return 97;
				case INT: return 97;
				case INT_LIT: return 97;
				case LBRACE: return 97;
				case LPAREN: return 97;
				case MINUS: return 97;
				case NEW: return 97;
				case NOT: return 97;
				case NULL_LIT: return 97;
				case RBRACE: return 97;
				case RETURN: return 97;
				case SEMICOLON: return 97;
				case SHORT: return 97;
				case STRING_LIT: return 97;
				case THIS: return 97;
				case WHILE: return 97;
			}
			break;
		case 517:
			switch(symbol) {
				case AND: return 58;
				case ASSIGN: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case INSTANCEOF: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case RBRACKET: return 58;
				case REMAINDER: return 58;
				case XOR: return 58;
			}
			break;
		case 518:
			switch(symbol) {
				case AND: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case SEMICOLON: return 59;
				case XOR: return 59;
			}
			break;
		case 519:
			switch(symbol) {
				case AND: return 59;
				case ASSIGN: return 59;
				case COMMA: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case RPAREN: return 59;
				case XOR: return 59;
			}
			break;
		case 520:
			switch(symbol) {
				case AND: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case INSTANCEOF: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case SEMICOLON: return 39;
				case XOR: return 39;
			}
			break;
		case 521:
			switch(symbol) {
				case AND: return 52;
				case ASSIGN: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case INSTANCEOF: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case RBRACKET: return 52;
				case REMAINDER: return 52;
				case XOR: return 52;
			}
			break;
		case 522:
			switch(symbol) {
				case AND: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case RBRACKET: return 6;
				case REMAINDER: return 6;
				case XOR: return 6;
			}
			break;
		case 523:
			switch(symbol) {
				case BOOLEAN: return 97;
				case BOOLEAN_LIT: return 97;
				case BYTE: return 97;
				case CHAR: return 97;
				case CHAR_LIT: return 97;
				case ELSE: return 97;
				case FOR: return 97;
				case ID: return 97;
				case IF: return 97;
				case INT: return 97;
				case INT_LIT: return 97;
				case LBRACE: return 97;
				case LPAREN: return 97;
				case MINUS: return 97;
				case NEW: return 97;
				case NOT: return 97;
				case NULL_LIT: return 97;
				case RBRACE: return 97;
				case RETURN: return 97;
				case SEMICOLON: return 97;
				case SHORT: return 97;
				case STRING_LIT: return 97;
				case THIS: return 97;
				case WHILE: return 97;
			}
			break;
		case 524:
			switch(symbol) {
				case AND: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case SEMICOLON: return 1;
				case XOR: return 1;
			}
			break;
		case 525:
			switch(symbol) {
				case BOOLEAN: return 100;
				case BOOLEAN_LIT: return 100;
				case BYTE: return 100;
				case CHAR: return 100;
				case CHAR_LIT: return 100;
				case ELSE: return 100;
				case FOR: return 100;
				case ID: return 100;
				case IF: return 100;
				case INT: return 100;
				case INT_LIT: return 100;
				case LBRACE: return 100;
				case LPAREN: return 100;
				case MINUS: return 100;
				case NEW: return 100;
				case NOT: return 100;
				case NULL_LIT: return 100;
				case RBRACE: return 100;
				case RETURN: return 100;
				case SEMICOLON: return 100;
				case SHORT: return 100;
				case STRING_LIT: return 100;
				case THIS: return 100;
				case WHILE: return 100;
			}
			break;
		case 526:
			switch(symbol) {
				case AND: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case RBRACKET: return 44;
				case REMAINDER: return 44;
				case XOR: return 44;
			}
			break;
		case 527:
			switch(symbol) {
				case ARRAY: return 64;
				case ID: return 64;
			}
			break;
		case 528:
			switch(symbol) {
				case AND: return 45;
				case COMMA: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case RPAREN: return 45;
				case XOR: return 45;
			}
			break;
		case 529:
			switch(symbol) {
				case BOOLEAN: return 80;
				case BOOLEAN_LIT: return 80;
				case BYTE: return 80;
				case CHAR: return 80;
				case CHAR_LIT: return 80;
				case FOR: return 80;
				case ID: return 80;
				case IF: return 80;
				case INT: return 80;
				case INT_LIT: return 80;
				case LBRACE: return 80;
				case LPAREN: return 80;
				case MINUS: return 80;
				case NEW: return 80;
				case NOT: return 80;
				case NULL_LIT: return 80;
				case RBRACE: return 80;
				case RETURN: return 80;
				case SEMICOLON: return 80;
				case SHORT: return 80;
				case STRING_LIT: return 80;
				case THIS: return 80;
				case WHILE: return 80;
			}
			break;
		case 531:
			switch(symbol) {
				case ARRAY: return 64;
				case IMPLEMENTS: return 64;
				case LBRACE: return 64;
			}
			break;
		case 533:
			switch(symbol) {
				case AND: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case INSTANCEOF: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case RPAREN: return 44;
				case XOR: return 44;
			}
			break;
		case 534:
			switch(symbol) {
				case SEMICOLON: return 172;
			}
			break;
		case 536:
			switch(symbol) {
				case RPAREN: return 107;
			}
			break;
		case 537:
			switch(symbol) {
				case AND: return 2;
				case ASSIGN: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case RPAREN: return 2;
				case XOR: return 2;
			}
			break;
		case 538:
			switch(symbol) {
				case AND: return 7;
				case ASSIGN: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
				case LBRACKET: return 7;
				case LEQ: return 7;
				case LT: return 7;
				case MINUS: return 7;
				case MULT: return 7;
				case NEQ: return 7;
				case OR: return 7;
				case PLUS: return 7;
				case REMAINDER: return 7;
				case RPAREN: return 7;
				case XOR: return 7;
			}
			break;
		case 540:
			switch(symbol) {
				case AND: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case SEMICOLON: return 6;
				case XOR: return 6;
			}
			break;
		case 541:
			switch(symbol) {
				case AND: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case INSTANCEOF: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case RPAREN: return 57;
				case XOR: return 57;
			}
			break;
		case 543:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case DOT: return 2;
				case RBRACKET: return 2;
			}
			break;
		case 544:
			switch(symbol) {
				case AND: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case RPAREN: return 71;
				case XOR: return 71;
			}
			break;
		case 546:
			switch(symbol) {
				case AND: return 57;
				case COMMA: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case RPAREN: return 57;
				case XOR: return 57;
			}
			break;
		case 547:
			switch(symbol) {
				case AND: return 53;
				case COMMA: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case INSTANCEOF: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case RPAREN: return 53;
				case XOR: return 53;
			}
			break;
		case 548:
			switch(symbol) {
				case AND: return 62;
				case ASSIGN: return 62;
				case COMMA: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case INSTANCEOF: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case RPAREN: return 62;
				case XOR: return 62;
			}
			break;
		case 550:
			switch(symbol) {
				case ARRAY: return 64;
				case COMMA: return 64;
				case LBRACE: return 64;
			}
			break;
		case 552:
			switch(symbol) {
				case AND: return 59;
				case COMMA: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case INSTANCEOF: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case RPAREN: return 59;
				case XOR: return 59;
			}
			break;
		case 554:
			switch(symbol) {
				case ARRAY: return 65;
				case RPAREN: return 65;
			}
			break;
		case 556:
			switch(symbol) {
				case AND: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case RPAREN: return 2;
				case XOR: return 2;
			}
			break;
		case 557:
			switch(symbol) {
				case AND: return 8;
				case ASSIGN: return 8;
				case COMMA: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case RPAREN: return 8;
				case XOR: return 8;
			}
			break;
		case 559:
			switch(symbol) {
				case COMMA: return 144;
				case LBRACE: return 144;
			}
			break;
		case 560:
			switch(symbol) {
				case RPAREN: return 174;
			}
			break;
		case 561:
			switch(symbol) {
				case AND: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case RBRACKET: return 5;
				case REMAINDER: return 5;
				case XOR: return 5;
			}
			break;
		case 562:
			switch(symbol) {
				case ABSTRACT: return 178;
				case BOOLEAN: return 178;
				case BYTE: return 178;
				case CHAR: return 178;
				case FINAL: return 178;
				case ID: return 178;
				case INT: return 178;
				case NATIVE: return 178;
				case PROTECTED: return 178;
				case PUBLIC: return 178;
				case RBRACE: return 178;
				case SEMICOLON: return 178;
				case SHORT: return 178;
				case STATIC: return 178;
				case VOID: return 178;
			}
			break;
		case 564:
			switch(symbol) {
				case ARRAY: return 1;
				case COMMA: return 1;
				case DOT: return 1;
				case LBRACE: return 1;
			}
			break;
		case 566:
			switch(symbol) {
				case AND: return 71;
				case ASSIGN: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case INSTANCEOF: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case RPAREN: return 71;
				case XOR: return 71;
			}
			break;
		case 567:
			switch(symbol) {
				case BOOLEAN: return 84;
				case BOOLEAN_LIT: return 84;
				case BYTE: return 84;
				case CHAR: return 84;
				case CHAR_LIT: return 84;
				case FOR: return 84;
				case ID: return 84;
				case IF: return 84;
				case INT: return 84;
				case INT_LIT: return 84;
				case LBRACE: return 84;
				case LPAREN: return 84;
				case MINUS: return 84;
				case NEW: return 84;
				case NOT: return 84;
				case NULL_LIT: return 84;
				case RBRACE: return 84;
				case RETURN: return 84;
				case SEMICOLON: return 84;
				case SHORT: return 84;
				case STRING_LIT: return 84;
				case THIS: return 84;
				case WHILE: return 84;
			}
			break;
		case 570:
			switch(symbol) {
				case AND: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case INSTANCEOF: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case RBRACKET: return 58;
				case REMAINDER: return 58;
				case XOR: return 58;
			}
			break;
		case 571:
			switch(symbol) {
				case DOT: return 1;
				case SEMICOLON: return 1;
			}
			break;
		case 572:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 574:
			switch(symbol) {
				case AND: return 4;
				case ASSIGN: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case RPAREN: return 4;
				case XOR: return 4;
			}
			break;
		case 576:
			switch(symbol) {
				case ARRAY: return 67;
				case RPAREN: return 67;
			}
			break;
		case 578:
			switch(symbol) {
				case ARRAY: return 65;
				case COMMA: return 65;
				case RPAREN: return 65;
			}
			break;
		case 582:
			switch(symbol) {
				case AND: return 61;
				case ASSIGN: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case INSTANCEOF: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case SEMICOLON: return 61;
				case XOR: return 61;
			}
			break;
		case 583:
			switch(symbol) {
				case AND: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case RPAREN: return 8;
				case XOR: return 8;
			}
			break;
		case 584:
			switch(symbol) {
				case ARRAY: return 65;
				case COMMA: return 65;
				case LBRACE: return 65;
			}
			break;
		case 585:
			switch(symbol) {
				case AND: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case RBRACKET: return 1;
				case REMAINDER: return 1;
				case XOR: return 1;
			}
			break;
		case 586:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case ID: return 1;
			}
			break;
		case 587:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case RPAREN: return 56;
				case XOR: return 56;
			}
			break;
		case 588:
			switch(symbol) {
				case AND: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case SEMICOLON: return 42;
				case XOR: return 42;
			}
			break;
		case 589:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case RPAREN: return 55;
				case XOR: return 55;
			}
			break;
		case 590:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case ID: return 9;
				case INSTANCEOF: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case SEMICOLON: return 51;
				case XOR: return 51;
			}
			break;
		case 591:
			switch(symbol) {
				case ABSTRACT: return 171;
				case BOOLEAN: return 171;
				case BYTE: return 171;
				case CHAR: return 171;
				case FINAL: return 171;
				case ID: return 171;
				case INT: return 171;
				case NATIVE: return 171;
				case PROTECTED: return 171;
				case PUBLIC: return 171;
				case RBRACE: return 171;
				case SEMICOLON: return 171;
				case SHORT: return 171;
				case STATIC: return 171;
				case VOID: return 171;
			}
			break;
		case 592:
			switch(symbol) {
				case AND: return 53;
				case ASSIGN: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case SEMICOLON: return 53;
				case XOR: return 53;
			}
			break;
		case 593:
			switch(symbol) {
				case ARRAY: return 66;
				case RBRACKET: return 66;
			}
			break;
		case 594:
			switch(symbol) {
				case AND: return 4;
				case ASSIGN: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case SEMICOLON: return 4;
				case XOR: return 4;
			}
			break;
		case 595:
			switch(symbol) {
				case AND: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case INSTANCEOF: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case SEMICOLON: return 69;
				case XOR: return 69;
			}
			break;
		case 596:
			switch(symbol) {
				case AND: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case RBRACKET: return 72;
				case REMAINDER: return 72;
				case XOR: return 72;
			}
			break;
		case 597:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case SEMICOLON: return 55;
				case XOR: return 55;
			}
			break;
		case 598:
			switch(symbol) {
				case AND: return 40;
				case COMMA: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case INSTANCEOF: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case RPAREN: return 40;
				case XOR: return 40;
			}
			break;
		case 599:
			switch(symbol) {
				case COMMA: return 33;
				case RPAREN: return 33;
			}
			break;
		case 600:
			switch(symbol) {
				case COMMA: return 31;
				case RPAREN: return 31;
			}
			break;
		case 601:
			switch(symbol) {
				case AND: return 59;
				case COMMA: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case RPAREN: return 59;
				case XOR: return 59;
			}
			break;
		case 602:
			switch(symbol) {
				case AND: return 73;
				case COMMA: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case INSTANCEOF: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case RPAREN: return 73;
				case XOR: return 73;
			}
			break;
		case 603:
			switch(symbol) {
				case RPAREN: return 38;
			}
			break;
		case 605:
			switch(symbol) {
				case AND: return 36;
				case DIV: return 36;
				case EAGER_AND: return 36;
				case EAGER_OR: return 36;
				case EQ: return 36;
				case GEQ: return 36;
				case GT: return 36;
				case LEQ: return 36;
				case LT: return 36;
				case MINUS: return 36;
				case MULT: return 36;
				case NEQ: return 36;
				case OR: return 36;
				case PLUS: return 36;
				case RBRACKET: return 36;
				case REMAINDER: return 36;
				case XOR: return 36;
			}
			break;
		case 606:
			switch(symbol) {
				case AND: return 36;
				case COMMA: return 36;
				case DIV: return 36;
				case EAGER_AND: return 36;
				case EAGER_OR: return 36;
				case EQ: return 36;
				case GEQ: return 36;
				case GT: return 36;
				case LEQ: return 36;
				case LT: return 36;
				case MINUS: return 36;
				case MULT: return 36;
				case NEQ: return 36;
				case OR: return 36;
				case PLUS: return 36;
				case REMAINDER: return 36;
				case RPAREN: return 36;
				case XOR: return 36;
			}
			break;
		case 607:
			switch(symbol) {
				case AND: return 40;
				case COMMA: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case RPAREN: return 40;
				case XOR: return 40;
			}
			break;
		case 608:
			switch(symbol) {
				case AND: return 57;
				case COMMA: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case INSTANCEOF: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case RPAREN: return 57;
				case XOR: return 57;
			}
			break;
		case 610:
			switch(symbol) {
				case ARRAY: return 64;
				case RPAREN: return 64;
			}
			break;
		case 611:
			switch(symbol) {
				case LPAREN: return 0;
			}
			break;
		case 612:
			switch(symbol) {
				case ARRAY: return 1;
				case COMMA: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 615:
			switch(symbol) {
				case AND: return 59;
				case ASSIGN: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case INSTANCEOF: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case SEMICOLON: return 59;
				case XOR: return 59;
			}
			break;
		case 617:
			switch(symbol) {
				case AND: return 37;
				case DIV: return 37;
				case EAGER_AND: return 37;
				case EAGER_OR: return 37;
				case EQ: return 37;
				case GEQ: return 37;
				case GT: return 37;
				case LEQ: return 37;
				case LT: return 37;
				case MINUS: return 37;
				case MULT: return 37;
				case NEQ: return 37;
				case OR: return 37;
				case PLUS: return 37;
				case RBRACKET: return 37;
				case REMAINDER: return 37;
				case XOR: return 37;
			}
			break;
		case 618:
			switch(symbol) {
				case AND: return 51;
				case COMMA: return 51;
				case DIV: return 51;
				case EAGER_AND: return 51;
				case EAGER_OR: return 51;
				case EQ: return 51;
				case GEQ: return 51;
				case GT: return 51;
				case INSTANCEOF: return 51;
				case LEQ: return 51;
				case LT: return 51;
				case MINUS: return 51;
				case MULT: return 51;
				case NEQ: return 51;
				case OR: return 51;
				case PLUS: return 51;
				case REMAINDER: return 51;
				case RPAREN: return 51;
				case XOR: return 51;
			}
			break;
		case 619:
			switch(symbol) {
				case AND: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case RBRACKET: return 70;
				case REMAINDER: return 70;
				case XOR: return 70;
			}
			break;
		case 621:
			switch(symbol) {
				case AND: return 1;
				case ASSIGN: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case RBRACKET: return 1;
				case REMAINDER: return 1;
				case XOR: return 1;
			}
			break;
		case 622:
			switch(symbol) {
				case AND: return 39;
				case COMMA: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case RPAREN: return 39;
				case XOR: return 39;
			}
			break;
		case 626:
			switch(symbol) {
				case AND: return 6;
				case ASSIGN: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case RBRACKET: return 6;
				case REMAINDER: return 6;
				case XOR: return 6;
			}
			break;
		case 627:
			switch(symbol) {
				case ID: return 12;
			}
			break;
		case 628:
			switch(symbol) {
				case AND: return 72;
				case ASSIGN: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case RBRACKET: return 72;
				case REMAINDER: return 72;
				case XOR: return 72;
			}
			break;
		case 629:
			switch(symbol) {
				case AND: return 39;
				case COMMA: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case INSTANCEOF: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case RPAREN: return 39;
				case XOR: return 39;
			}
			break;
		case 631:
			switch(symbol) {
				case AND: return 68;
				case ASSIGN: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case INSTANCEOF: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case SEMICOLON: return 68;
				case XOR: return 68;
			}
			break;
		case 632:
			switch(symbol) {
				case BOOLEAN: return 96;
				case BOOLEAN_LIT: return 96;
				case BYTE: return 96;
				case CHAR: return 96;
				case CHAR_LIT: return 96;
				case FOR: return 96;
				case ID: return 96;
				case IF: return 96;
				case INT: return 96;
				case INT_LIT: return 96;
				case LBRACE: return 96;
				case LPAREN: return 96;
				case MINUS: return 96;
				case NEW: return 96;
				case NOT: return 96;
				case NULL_LIT: return 96;
				case RBRACE: return 96;
				case RETURN: return 96;
				case SEMICOLON: return 96;
				case SHORT: return 96;
				case STRING_LIT: return 96;
				case THIS: return 96;
				case WHILE: return 96;
			}
			break;
		case 633:
			switch(symbol) {
				case COMMA: return 122;
				case RPAREN: return 122;
			}
			break;
		case 634:
			switch(symbol) {
				case ARRAY: return 63;
				case IMPLEMENTS: return 63;
				case LBRACE: return 63;
			}
			break;
		case 636:
			switch(symbol) {
				case AND: return 4;
				case COMMA: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case INSTANCEOF: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case RPAREN: return 4;
				case XOR: return 4;
			}
			break;
		case 637:
			switch(symbol) {
				case COMMA: return 38;
				case RPAREN: return 38;
			}
			break;
		case 639:
			switch(symbol) {
				case AND: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case REMAINDER: return 44;
				case SEMICOLON: return 44;
				case XOR: return 44;
			}
			break;
		case 640:
			switch(symbol) {
				case AND: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case INSTANCEOF: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case SEMICOLON: return 57;
				case XOR: return 57;
			}
			break;
		case 641:
			switch(symbol) {
				case AND: return 72;
				case ASSIGN: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case RPAREN: return 72;
				case XOR: return 72;
			}
			break;
		case 644:
			switch(symbol) {
				case AND: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case SEMICOLON: return 57;
				case XOR: return 57;
			}
			break;
		case 645:
			switch(symbol) {
				case ARRAY: return 66;
				case COMMA: return 66;
				case LBRACE: return 66;
			}
			break;
		case 647:
			switch(symbol) {
				case ABSTRACT: return 111;
				case BOOLEAN: return 111;
				case BYTE: return 111;
				case CHAR: return 111;
				case FINAL: return 111;
				case ID: return 111;
				case INT: return 111;
				case NATIVE: return 111;
				case PROTECTED: return 111;
				case PUBLIC: return 111;
				case SHORT: return 111;
				case STATIC: return 111;
				case VOID: return 111;
			}
			break;
		case 648:
			switch(symbol) {
				case AND: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case RBRACKET: return 61;
				case REMAINDER: return 61;
				case XOR: return 61;
			}
			break;
		case 649:
			switch(symbol) {
				case AND: return 55;
				case COMMA: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case RPAREN: return 55;
				case XOR: return 55;
			}
			break;
		case 650:
			switch(symbol) {
				case AND: return 60;
				case ASSIGN: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case RBRACKET: return 60;
				case REMAINDER: return 60;
				case XOR: return 60;
			}
			break;
		case 651:
			switch(symbol) {
				case AND: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case INSTANCEOF: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case RPAREN: return 59;
				case XOR: return 59;
			}
			break;
		case 653:
			switch(symbol) {
				case AND: return 53;
				case ASSIGN: return 53;
				case COMMA: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case REMAINDER: return 53;
				case RPAREN: return 53;
				case XOR: return 53;
			}
			break;
		case 654:
			switch(symbol) {
				case AND: return 60;
				case ASSIGN: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case RPAREN: return 60;
				case XOR: return 60;
			}
			break;
		case 655:
			switch(symbol) {
				case AND: return 56;
				case COMMA: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case RPAREN: return 56;
				case XOR: return 56;
			}
			break;
		case 658:
			switch(symbol) {
				case AND: return 58;
				case ASSIGN: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case INSTANCEOF: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case RPAREN: return 58;
				case XOR: return 58;
			}
			break;
		case 659:
			switch(symbol) {
				case AND: return 73;
				case ASSIGN: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case RBRACKET: return 73;
				case REMAINDER: return 73;
				case XOR: return 73;
			}
			break;
		case 660:
			switch(symbol) {
				case AND: return 1;
				case COMMA: return 1;
				case DIV: return 1;
				case DOT: return 1;
				case EAGER_AND: return 1;
				case EAGER_OR: return 1;
				case EQ: return 1;
				case GEQ: return 1;
				case GT: return 1;
				case LBRACKET: return 1;
				case LEQ: return 1;
				case LPAREN: return 1;
				case LT: return 1;
				case MINUS: return 1;
				case MULT: return 1;
				case NEQ: return 1;
				case OR: return 1;
				case PLUS: return 1;
				case REMAINDER: return 1;
				case RPAREN: return 1;
				case XOR: return 1;
			}
			break;
		case 662:
			switch(symbol) {
				case AND: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case SEMICOLON: return 61;
				case XOR: return 61;
			}
			break;
		case 663:
			switch(symbol) {
				case ID: return 9;
			}
			break;
		case 664:
			switch(symbol) {
				case AND: return 57;
				case ASSIGN: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case RPAREN: return 57;
				case XOR: return 57;
			}
			break;
		case 665:
			switch(symbol) {
				case AND: return 57;
				case ASSIGN: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case SEMICOLON: return 57;
				case XOR: return 57;
			}
			break;
		case 666:
			switch(symbol) {
				case AND: return 69;
				case ASSIGN: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case INSTANCEOF: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case RBRACKET: return 69;
				case REMAINDER: return 69;
				case XOR: return 69;
			}
			break;
		case 667:
			switch(symbol) {
				case ABSTRACT: return 125;
				case CLASS: return 125;
				case END_TERMINAL: return 125;
				case FINAL: return 125;
				case IMPORT: return 125;
				case INTERFACE: return 125;
				case NATIVE: return 125;
				case PROTECTED: return 125;
				case PUBLIC: return 125;
				case SEMICOLON: return 125;
				case STATIC: return 125;
			}
			break;
		case 669:
			switch(symbol) {
				case AND: return 41;
				case ASSIGN: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case SEMICOLON: return 41;
				case XOR: return 41;
			}
			break;
		case 670:
			switch(symbol) {
				case AND: return 72;
				case ASSIGN: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case INSTANCEOF: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case SEMICOLON: return 72;
				case XOR: return 72;
			}
			break;
		case 672:
			switch(symbol) {
				case ASSIGN: return 34;
				case RPAREN: return 34;
			}
			break;
		case 673:
			switch(symbol) {
				case ABSTRACT: return 124;
				case CLASS: return 124;
				case END_TERMINAL: return 124;
				case FINAL: return 124;
				case IMPORT: return 124;
				case INTERFACE: return 124;
				case NATIVE: return 124;
				case PROTECTED: return 124;
				case PUBLIC: return 124;
				case SEMICOLON: return 124;
				case STATIC: return 124;
			}
			break;
		case 674:
			switch(symbol) {
				case END_TERMINAL: return 138;
			}
			break;
		case 675:
			switch(symbol) {
				case ABSTRACT: return 161;
				case BOOLEAN: return 161;
				case BYTE: return 161;
				case CHAR: return 161;
				case FINAL: return 161;
				case ID: return 161;
				case INT: return 161;
				case NATIVE: return 161;
				case PROTECTED: return 161;
				case PUBLIC: return 161;
				case RBRACE: return 161;
				case SEMICOLON: return 161;
				case SHORT: return 161;
				case STATIC: return 161;
				case VOID: return 161;
			}
			break;
		case 677:
			switch(symbol) {
				case END_TERMINAL: return 134;
			}
			break;
		case 680:
			switch(symbol) {
				case AND: return 50;
				case COMMA: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case INSTANCEOF: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case REMAINDER: return 50;
				case RPAREN: return 50;
				case XOR: return 50;
			}
			break;
		case 681:
			switch(symbol) {
				case ARRAY: return 64;
				case COMMA: return 64;
				case RPAREN: return 64;
			}
			break;
		case 682:
			switch(symbol) {
				case AND: return 42;
				case ASSIGN: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case INSTANCEOF: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case SEMICOLON: return 42;
				case XOR: return 42;
			}
			break;
		case 684:
			switch(symbol) {
				case AND: return 2;
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case ID: return 2;
				case INSTANCEOF: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case SEMICOLON: return 2;
				case XOR: return 2;
			}
			break;
		case 685:
			switch(symbol) {
				case AND: return 39;
				case ASSIGN: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case RBRACKET: return 39;
				case REMAINDER: return 39;
				case XOR: return 39;
			}
			break;
		case 686:
			switch(symbol) {
				case AND: return 40;
				case ASSIGN: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case RBRACKET: return 40;
				case REMAINDER: return 40;
				case XOR: return 40;
			}
			break;
		case 691:
			switch(symbol) {
				case AND: return 68;
				case ASSIGN: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case RBRACKET: return 68;
				case REMAINDER: return 68;
				case XOR: return 68;
			}
			break;
		case 693:
			switch(symbol) {
				case LBRACE: return 70;
				case RPAREN: return 70;
			}
			break;
		case 696:
			switch(symbol) {
				case AND: return 5;
				case ASSIGN: return 5;
				case COMMA: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
				case LBRACKET: return 5;
				case LEQ: return 5;
				case LT: return 5;
				case MINUS: return 5;
				case MULT: return 5;
				case NEQ: return 5;
				case OR: return 5;
				case PLUS: return 5;
				case REMAINDER: return 5;
				case RPAREN: return 5;
				case XOR: return 5;
			}
			break;
		case 698:
			switch(symbol) {
				case ASSIGN: return 35;
				case COMMA: return 35;
				case RPAREN: return 35;
			}
			break;
		case 699:
			switch(symbol) {
				case COMMA: return 34;
				case RPAREN: return 34;
			}
			break;
		case 702:
			switch(symbol) {
				case BOOLEAN: return 86;
				case BOOLEAN_LIT: return 86;
				case BYTE: return 86;
				case CHAR: return 86;
				case CHAR_LIT: return 86;
				case FOR: return 86;
				case ID: return 86;
				case IF: return 86;
				case INT: return 86;
				case INT_LIT: return 86;
				case LBRACE: return 86;
				case LPAREN: return 86;
				case MINUS: return 86;
				case NEW: return 86;
				case NOT: return 86;
				case NULL_LIT: return 86;
				case RBRACE: return 86;
				case RETURN: return 86;
				case SEMICOLON: return 86;
				case SHORT: return 86;
				case STRING_LIT: return 86;
				case THIS: return 86;
				case WHILE: return 86;
			}
			break;
		case 704:
			switch(symbol) {
				case AND: return 70;
				case ASSIGN: return 70;
				case COMMA: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case RPAREN: return 70;
				case XOR: return 70;
			}
			break;
		case 705:
			switch(symbol) {
				case AND: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case INSTANCEOF: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case RPAREN: return 61;
				case XOR: return 61;
			}
			break;
		case 706:
			switch(symbol) {
				case ASSIGN: return 38;
				case RBRACKET: return 38;
			}
			break;
		case 709:
			switch(symbol) {
				case AND: return 4;
				case ASSIGN: return 4;
				case COMMA: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
				case LBRACKET: return 4;
				case LEQ: return 4;
				case LT: return 4;
				case MINUS: return 4;
				case MULT: return 4;
				case NEQ: return 4;
				case OR: return 4;
				case PLUS: return 4;
				case REMAINDER: return 4;
				case RPAREN: return 4;
				case XOR: return 4;
			}
			break;
		case 710:
			switch(symbol) {
				case ASSIGN: return 35;
				case SEMICOLON: return 35;
			}
			break;
		case 714:
			switch(symbol) {
				case AND: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case INSTANCEOF: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case SEMICOLON: return 60;
				case XOR: return 60;
			}
			break;
		case 715:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case DOT: return 1;
				case RBRACKET: return 1;
			}
			break;
		case 716:
			switch(symbol) {
				case BOOLEAN: return 92;
				case BOOLEAN_LIT: return 92;
				case BYTE: return 92;
				case CHAR: return 92;
				case CHAR_LIT: return 92;
				case FOR: return 92;
				case ID: return 92;
				case IF: return 92;
				case INT: return 92;
				case INT_LIT: return 92;
				case LBRACE: return 92;
				case LPAREN: return 92;
				case MINUS: return 92;
				case NEW: return 92;
				case NOT: return 92;
				case NULL_LIT: return 92;
				case RBRACE: return 92;
				case RETURN: return 92;
				case SEMICOLON: return 92;
				case SHORT: return 92;
				case STRING_LIT: return 92;
				case THIS: return 92;
				case WHILE: return 92;
			}
			break;
		case 717:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case EAGER_AND: return 50;
				case EAGER_OR: return 50;
				case EQ: return 50;
				case GEQ: return 50;
				case GT: return 50;
				case INSTANCEOF: return 50;
				case LEQ: return 50;
				case LT: return 50;
				case MINUS: return 50;
				case MULT: return 50;
				case NEQ: return 50;
				case OR: return 50;
				case PLUS: return 50;
				case RBRACKET: return 50;
				case REMAINDER: return 50;
				case XOR: return 50;
			}
			break;
		case 718:
			switch(symbol) {
				case AND: return 45;
				case ASSIGN: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case SEMICOLON: return 45;
				case XOR: return 45;
			}
			break;
		case 720:
			switch(symbol) {
				case END_TERMINAL: return 148;
			}
			break;
		case 721:
			switch(symbol) {
				case ABSTRACT: return 129;
				case CLASS: return 129;
				case END_TERMINAL: return 129;
				case FINAL: return 129;
				case IMPORT: return 129;
				case INTERFACE: return 129;
				case NATIVE: return 129;
				case PROTECTED: return 129;
				case PUBLIC: return 129;
				case SEMICOLON: return 129;
				case STATIC: return 129;
			}
			break;
		case 722:
			switch(symbol) {
				case AND: return 73;
				case ASSIGN: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case INSTANCEOF: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case RBRACKET: return 73;
				case REMAINDER: return 73;
				case XOR: return 73;
			}
			break;
		case 723:
			switch(symbol) {
				case BOOLEAN: return 96;
				case BOOLEAN_LIT: return 96;
				case BYTE: return 96;
				case CHAR: return 96;
				case CHAR_LIT: return 96;
				case ELSE: return 96;
				case FOR: return 96;
				case ID: return 96;
				case IF: return 96;
				case INT: return 96;
				case INT_LIT: return 96;
				case LBRACE: return 96;
				case LPAREN: return 96;
				case MINUS: return 96;
				case NEW: return 96;
				case NOT: return 96;
				case NULL_LIT: return 96;
				case RBRACE: return 96;
				case RETURN: return 96;
				case SEMICOLON: return 96;
				case SHORT: return 96;
				case STRING_LIT: return 96;
				case THIS: return 96;
				case WHILE: return 96;
			}
			break;
		case 724:
			switch(symbol) {
				case ABSTRACT: return 159;
				case BOOLEAN: return 159;
				case BYTE: return 159;
				case CHAR: return 159;
				case FINAL: return 159;
				case ID: return 159;
				case INT: return 159;
				case NATIVE: return 159;
				case PROTECTED: return 159;
				case PUBLIC: return 159;
				case RBRACE: return 159;
				case SEMICOLON: return 159;
				case SHORT: return 159;
				case STATIC: return 159;
				case VOID: return 159;
			}
			break;
		case 725:
			switch(symbol) {
				case AND: return 72;
				case COMMA: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case INSTANCEOF: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case RPAREN: return 72;
				case XOR: return 72;
			}
			break;
		case 728:
			switch(symbol) {
				case AND: return 70;
				case ASSIGN: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case SEMICOLON: return 70;
				case XOR: return 70;
			}
			break;
		case 729:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case RBRACKET: return 64;
			}
			break;
		case 730:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case RBRACKET: return 55;
				case REMAINDER: return 55;
				case XOR: return 55;
			}
			break;
		case 731:
			switch(symbol) {
				case AND: return 69;
				case ASSIGN: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case RPAREN: return 69;
				case XOR: return 69;
			}
			break;
		case 735:
			switch(symbol) {
				case AND: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case RPAREN: return 69;
				case XOR: return 69;
			}
			break;
		case 737:
			switch(symbol) {
				case ASSIGN: return 11;
				case RPAREN: return 11;
			}
			break;
		case 738:
			switch(symbol) {
				case ARRAY: return 65;
				case ASSIGN: return 65;
				case RBRACKET: return 65;
			}
			break;
		case 740:
			switch(symbol) {
				case ARRAY: return 67;
				case SEMICOLON: return 67;
			}
			break;
		case 742:
			switch(symbol) {
				case AND: return 8;
				case COMMA: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case INSTANCEOF: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case RPAREN: return 8;
				case XOR: return 8;
			}
			break;
		case 743:
			switch(symbol) {
				case AND: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
				case INSTANCEOF: return 6;
				case LBRACKET: return 6;
				case LEQ: return 6;
				case LT: return 6;
				case MINUS: return 6;
				case MULT: return 6;
				case NEQ: return 6;
				case OR: return 6;
				case PLUS: return 6;
				case REMAINDER: return 6;
				case SEMICOLON: return 6;
				case XOR: return 6;
			}
			break;
		case 745:
			switch(symbol) {
				case BOOLEAN: return 110;
				case BYTE: return 110;
				case CHAR: return 110;
				case ID: return 110;
				case INT: return 110;
				case SHORT: return 110;
				case VOID: return 110;
			}
			break;
		case 748:
			switch(symbol) {
				case AND: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case SEMICOLON: return 39;
				case XOR: return 39;
			}
			break;
		case 749:
			switch(symbol) {
				case AND: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case SEMICOLON: return 40;
				case XOR: return 40;
			}
			break;
		case 751:
			switch(symbol) {
				case RPAREN: return 31;
			}
			break;
		case 752:
			switch(symbol) {
				case RPAREN: return 33;
			}
			break;
		case 753:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case RPAREN: return 64;
			}
			break;
		case 754:
			switch(symbol) {
				case ASSIGN: return 12;
				case SEMICOLON: return 12;
			}
			break;
		case 756:
			switch(symbol) {
				case AND: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case INSTANCEOF: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case SEMICOLON: return 45;
				case XOR: return 45;
			}
			break;
		case 757:
			switch(symbol) {
				case AND: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case INSTANCEOF: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case RBRACKET: return 60;
				case REMAINDER: return 60;
				case XOR: return 60;
			}
			break;
		case 758:
			switch(symbol) {
				case CLASS: return 109;
				case INTERFACE: return 109;
			}
			break;
		case 759:
			switch(symbol) {
				case AND: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case INSTANCEOF: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case REMAINDER: return 8;
				case RPAREN: return 8;
				case XOR: return 8;
			}
			break;
		case 761:
			switch(symbol) {
				case AND: return 52;
				case ASSIGN: return 52;
				case COMMA: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case INSTANCEOF: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case RPAREN: return 52;
				case XOR: return 52;
			}
			break;
		case 762:
			switch(symbol) {
				case AND: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
				case INSTANCEOF: return 8;
				case LBRACKET: return 8;
				case LEQ: return 8;
				case LT: return 8;
				case MINUS: return 8;
				case MULT: return 8;
				case NEQ: return 8;
				case OR: return 8;
				case PLUS: return 8;
				case RBRACKET: return 8;
				case REMAINDER: return 8;
				case XOR: return 8;
			}
			break;
		case 763:
			switch(symbol) {
				case ASSIGN: return 34;
				case SEMICOLON: return 34;
			}
			break;
		case 767:
			switch(symbol) {
				case AND: return 72;
				case ASSIGN: return 72;
				case COMMA: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case RPAREN: return 72;
				case XOR: return 72;
			}
			break;
		case 768:
			switch(symbol) {
				case AND: return 42;
				case ASSIGN: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case RBRACKET: return 42;
				case REMAINDER: return 42;
				case XOR: return 42;
			}
			break;
		case 769:
			switch(symbol) {
				case AND: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case INSTANCEOF: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case SEMICOLON: return 59;
				case XOR: return 59;
			}
			break;
		case 770:
			switch(symbol) {
				case AND: return 69;
				case ASSIGN: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case INSTANCEOF: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case SEMICOLON: return 69;
				case XOR: return 69;
			}
			break;
		case 771:
			switch(symbol) {
				case SEMICOLON: return 78;
			}
			break;
		case 772:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case SEMICOLON: return 64;
			}
			break;
		case 773:
			switch(symbol) {
				case AND: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case RBRACKET: return 59;
				case REMAINDER: return 59;
				case XOR: return 59;
			}
			break;
		case 775:
			switch(symbol) {
				case AND: return 2;
				case COMMA: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case INSTANCEOF: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case RPAREN: return 2;
				case XOR: return 2;
			}
			break;
		case 776:
			switch(symbol) {
				case AND: return 58;
				case COMMA: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case INSTANCEOF: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case RPAREN: return 58;
				case XOR: return 58;
			}
			break;
		case 778:
			switch(symbol) {
				case AND: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case INSTANCEOF: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case RBRACKET: return 68;
				case REMAINDER: return 68;
				case XOR: return 68;
			}
			break;
		case 779:
			switch(symbol) {
				case COMMA: return 35;
				case RPAREN: return 35;
			}
			break;
		case 780:
			switch(symbol) {
				case BOOLEAN: return 110;
				case BYTE: return 110;
				case CHAR: return 110;
				case ID: return 110;
				case INT: return 110;
				case SHORT: return 110;
				case VOID: return 110;
			}
			break;
		case 781:
			switch(symbol) {
				case AND: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
				case LBRACKET: return 53;
				case LEQ: return 53;
				case LT: return 53;
				case MINUS: return 53;
				case MULT: return 53;
				case NEQ: return 53;
				case OR: return 53;
				case PLUS: return 53;
				case RBRACKET: return 53;
				case REMAINDER: return 53;
				case XOR: return 53;
			}
			break;
		case 782:
			switch(symbol) {
				case RPAREN: return 32;
			}
			break;
		case 783:
			switch(symbol) {
				case ARRAY: return 66;
				case ASSIGN: return 66;
				case RPAREN: return 66;
			}
			break;
		case 785:
			switch(symbol) {
				case COMMA: return 177;
				case RPAREN: return 177;
			}
			break;
		case 788:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 789:
			switch(symbol) {
				case ABSTRACT: return 164;
				case BOOLEAN: return 164;
				case BYTE: return 164;
				case CHAR: return 164;
				case FINAL: return 164;
				case ID: return 164;
				case INT: return 164;
				case NATIVE: return 164;
				case PROTECTED: return 164;
				case PUBLIC: return 164;
				case RBRACE: return 164;
				case SEMICOLON: return 164;
				case SHORT: return 164;
				case STATIC: return 164;
				case VOID: return 164;
			}
			break;
		case 790:
			switch(symbol) {
				case AND: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case INSTANCEOF: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case SEMICOLON: return 72;
				case XOR: return 72;
			}
			break;
		case 791:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case ID: return 1;
			}
			break;
		case 792:
			switch(symbol) {
				case ASSIGN: return 11;
				case RBRACKET: return 11;
			}
			break;
		case 794:
			switch(symbol) {
				case AND: return 62;
				case ASSIGN: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case INSTANCEOF: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case RBRACKET: return 62;
				case REMAINDER: return 62;
				case XOR: return 62;
			}
			break;
		case 796:
			switch(symbol) {
				case ABSTRACT: return 170;
				case BOOLEAN: return 170;
				case BYTE: return 170;
				case CHAR: return 170;
				case FINAL: return 170;
				case ID: return 170;
				case INT: return 170;
				case NATIVE: return 170;
				case PROTECTED: return 170;
				case PUBLIC: return 170;
				case RBRACE: return 170;
				case SEMICOLON: return 170;
				case SHORT: return 170;
				case STATIC: return 170;
				case VOID: return 170;
			}
			break;
		case 797:
			switch(symbol) {
				case AND: return 58;
				case ASSIGN: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case INSTANCEOF: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case SEMICOLON: return 58;
				case XOR: return 58;
			}
			break;
		case 800:
			switch(symbol) {
				case RBRACKET: return 31;
			}
			break;
		case 801:
			switch(symbol) {
				case RBRACKET: return 33;
			}
			break;
		case 802:
			switch(symbol) {
				case ASSIGN: return 12;
				case COMMA: return 12;
				case RPAREN: return 12;
			}
			break;
		case 803:
			switch(symbol) {
				case AND: return 40;
				case ASSIGN: return 40;
				case COMMA: return 40;
				case DIV: return 40;
				case EAGER_AND: return 40;
				case EAGER_OR: return 40;
				case EQ: return 40;
				case GEQ: return 40;
				case GT: return 40;
				case LEQ: return 40;
				case LT: return 40;
				case MINUS: return 40;
				case MULT: return 40;
				case NEQ: return 40;
				case OR: return 40;
				case PLUS: return 40;
				case REMAINDER: return 40;
				case RPAREN: return 40;
				case XOR: return 40;
			}
			break;
		case 804:
			switch(symbol) {
				case AND: return 37;
				case ASSIGN: return 37;
				case COMMA: return 37;
				case DIV: return 37;
				case EAGER_AND: return 37;
				case EAGER_OR: return 37;
				case EQ: return 37;
				case GEQ: return 37;
				case GT: return 37;
				case LEQ: return 37;
				case LT: return 37;
				case MINUS: return 37;
				case MULT: return 37;
				case NEQ: return 37;
				case OR: return 37;
				case PLUS: return 37;
				case REMAINDER: return 37;
				case RPAREN: return 37;
				case XOR: return 37;
			}
			break;
		case 805:
			switch(symbol) {
				case AND: return 43;
				case COMMA: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case RPAREN: return 43;
				case XOR: return 43;
			}
			break;
		case 806:
			switch(symbol) {
				case END_TERMINAL: return 141;
			}
			break;
		case 809:
			switch(symbol) {
				case AND: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case INSTANCEOF: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case SEMICOLON: return 62;
				case XOR: return 62;
			}
			break;
		case 813:
			switch(symbol) {
				case AND: return 39;
				case ASSIGN: return 39;
				case COMMA: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case RPAREN: return 39;
				case XOR: return 39;
			}
			break;
		case 816:
			switch(symbol) {
				case AND: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case SEMICOLON: return 68;
				case XOR: return 68;
			}
			break;
		case 817:
			switch(symbol) {
				case SEMICOLON: return 12;
			}
			break;
		case 819:
			switch(symbol) {
				case BOOLEAN_LIT: return 79;
				case CHAR_LIT: return 79;
				case FOR: return 79;
				case ID: return 79;
				case IF: return 79;
				case INT_LIT: return 79;
				case LBRACE: return 79;
				case LPAREN: return 79;
				case MINUS: return 79;
				case NEW: return 79;
				case NOT: return 79;
				case NULL_LIT: return 79;
				case RETURN: return 79;
				case SEMICOLON: return 79;
				case STRING_LIT: return 79;
				case THIS: return 79;
				case WHILE: return 79;
			}
			break;
		case 820:
			switch(symbol) {
				case ASSIGN: return 11;
				case SEMICOLON: return 11;
			}
			break;
		case 822:
			switch(symbol) {
				case AND: return 73;
				case ASSIGN: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case INSTANCEOF: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case SEMICOLON: return 73;
				case XOR: return 73;
			}
			break;
		case 823:
			switch(symbol) {
				case RBRACKET: return 10;
			}
			break;
		case 824:
			switch(symbol) {
				case AND: return 61;
				case COMMA: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case INSTANCEOF: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case RPAREN: return 61;
				case XOR: return 61;
			}
			break;
		case 825:
			switch(symbol) {
				case AND: return 58;
				case ASSIGN: return 58;
				case COMMA: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case INSTANCEOF: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case RPAREN: return 58;
				case XOR: return 58;
			}
			break;
		case 826:
			switch(symbol) {
				case ARRAY: return 66;
				case ASSIGN: return 66;
				case SEMICOLON: return 66;
			}
			break;
		case 827:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case RBRACKET: return 55;
				case REMAINDER: return 55;
				case XOR: return 55;
			}
			break;
		case 828:
			switch(symbol) {
				case AND: return 71;
				case COMMA: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case INSTANCEOF: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case RPAREN: return 71;
				case XOR: return 71;
			}
			break;
		case 831:
			switch(symbol) {
				case BOOLEAN_LIT: return 13;
				case CHAR_LIT: return 13;
				case ID: return 13;
				case INT_LIT: return 13;
				case LPAREN: return 13;
				case MINUS: return 13;
				case NEW: return 13;
				case NOT: return 13;
				case NULL_LIT: return 13;
				case STRING_LIT: return 13;
				case THIS: return 13;
			}
			break;
		case 832:
			switch(symbol) {
				case AND: return 68;
				case ASSIGN: return 68;
				case COMMA: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case RPAREN: return 68;
				case XOR: return 68;
			}
			break;
		case 833:
			switch(symbol) {
				case AND: return 43;
				case ASSIGN: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case RBRACKET: return 43;
				case REMAINDER: return 43;
				case XOR: return 43;
			}
			break;
		case 835:
			switch(symbol) {
				case RBRACKET: return 9;
			}
			break;
		case 838:
			switch(symbol) {
				case AND: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case RPAREN: return 73;
				case XOR: return 73;
			}
			break;
		case 840:
			switch(symbol) {
				case AND: return 42;
				case ASSIGN: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case RPAREN: return 42;
				case XOR: return 42;
			}
			break;
		case 841:
			switch(symbol) {
				case AND: return 2;
				case ASSIGN: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case INSTANCEOF: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case RPAREN: return 2;
				case XOR: return 2;
			}
			break;
		case 842:
			switch(symbol) {
				case SEMICOLON: return 48;
			}
			break;
		case 844:
			switch(symbol) {
				case ABSTRACT: return 169;
				case BOOLEAN: return 169;
				case BYTE: return 169;
				case CHAR: return 169;
				case FINAL: return 169;
				case ID: return 169;
				case INT: return 169;
				case NATIVE: return 169;
				case PROTECTED: return 169;
				case PUBLIC: return 169;
				case RBRACE: return 169;
				case SEMICOLON: return 169;
				case SHORT: return 169;
				case STATIC: return 169;
				case VOID: return 169;
			}
			break;
		case 845:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case RBRACKET: return 63;
			}
			break;
		case 846:
			switch(symbol) {
				case AND: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case SEMICOLON: return 52;
				case XOR: return 52;
			}
			break;
		case 848:
			switch(symbol) {
				case ARRAY: return 66;
				case SEMICOLON: return 66;
			}
			break;
		case 851:
			switch(symbol) {
				case AND: return 2;
				case ASSIGN: return 2;
				case COMMA: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case INSTANCEOF: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case RPAREN: return 2;
				case XOR: return 2;
			}
			break;
		case 852:
			switch(symbol) {
				case AND: return 2;
				case ASSIGN: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case SEMICOLON: return 2;
				case XOR: return 2;
			}
			break;
		case 853:
			switch(symbol) {
				case AND: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case INSTANCEOF: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case SEMICOLON: return 70;
				case XOR: return 70;
			}
			break;
		case 854:
			switch(symbol) {
				case ASSIGN: return 9;
				case COMMA: return 9;
				case RPAREN: return 9;
			}
			break;
		case 856:
			switch(symbol) {
				case AND: return 43;
				case COMMA: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case INSTANCEOF: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case RPAREN: return 43;
				case XOR: return 43;
			}
			break;
		case 857:
			switch(symbol) {
				case AND: return 39;
				case ASSIGN: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case SEMICOLON: return 39;
				case XOR: return 39;
			}
			break;
		case 859:
			switch(symbol) {
				case AND: return 70;
				case ASSIGN: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case INSTANCEOF: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case RPAREN: return 70;
				case XOR: return 70;
			}
			break;
		case 862:
			switch(symbol) {
				case COMMA: return 47;
				case RPAREN: return 47;
			}
			break;
		case 863:
			switch(symbol) {
				case ASSIGN: return 11;
				case COMMA: return 11;
				case RPAREN: return 11;
			}
			break;
		case 864:
			switch(symbol) {
				case AND: return 60;
				case ASSIGN: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case INSTANCEOF: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case RBRACKET: return 60;
				case REMAINDER: return 60;
				case XOR: return 60;
			}
			break;
		case 865:
			switch(symbol) {
				case AND: return 37;
				case DIV: return 37;
				case EAGER_AND: return 37;
				case EAGER_OR: return 37;
				case EQ: return 37;
				case GEQ: return 37;
				case GT: return 37;
				case LEQ: return 37;
				case LT: return 37;
				case MINUS: return 37;
				case MULT: return 37;
				case NEQ: return 37;
				case OR: return 37;
				case PLUS: return 37;
				case REMAINDER: return 37;
				case RPAREN: return 37;
				case XOR: return 37;
			}
			break;
		case 869:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case IMPLEMENTS: return 2;
				case LBRACE: return 2;
			}
			break;
		case 872:
			switch(symbol) {
				case AND: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case INSTANCEOF: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case RPAREN: return 72;
				case XOR: return 72;
			}
			break;
		case 873:
			switch(symbol) {
				case AND: return 68;
				case ASSIGN: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case INSTANCEOF: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case RPAREN: return 68;
				case XOR: return 68;
			}
			break;
		case 874:
			switch(symbol) {
				case AND: return 60;
				case COMMA: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case RPAREN: return 60;
				case XOR: return 60;
			}
			break;
		case 875:
			switch(symbol) {
				case AND: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case INSTANCEOF: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case RPAREN: return 71;
				case XOR: return 71;
			}
			break;
		case 877:
			switch(symbol) {
				case SEMICOLON: return 31;
			}
			break;
		case 878:
			switch(symbol) {
				case SEMICOLON: return 33;
			}
			break;
		case 880:
			switch(symbol) {
				case AND: return 68;
				case ASSIGN: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case RPAREN: return 68;
				case XOR: return 68;
			}
			break;
		case 883:
			switch(symbol) {
				case AND: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case SEMICOLON: return 73;
				case XOR: return 73;
			}
			break;
		case 884:
			switch(symbol) {
				case AND: return 2;
				case ASSIGN: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case INSTANCEOF: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case RBRACKET: return 2;
				case REMAINDER: return 2;
				case XOR: return 2;
			}
			break;
		case 886:
			switch(symbol) {
				case END_TERMINAL: return 136;
			}
			break;
		case 887:
			switch(symbol) {
				case AND: return 62;
				case ASSIGN: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case INSTANCEOF: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case RPAREN: return 62;
				case XOR: return 62;
			}
			break;
		case 888:
			switch(symbol) {
				case AND: return 70;
				case ASSIGN: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case RBRACKET: return 70;
				case REMAINDER: return 70;
				case XOR: return 70;
			}
			break;
		case 890:
			switch(symbol) {
				case RPAREN: return 107;
			}
			break;
		case 893:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 894:
			switch(symbol) {
				case AND: return 43;
				case ASSIGN: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case INSTANCEOF: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case SEMICOLON: return 43;
				case XOR: return 43;
			}
			break;
		case 897:
			switch(symbol) {
				case AND: return 42;
				case ASSIGN: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case INSTANCEOF: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case RPAREN: return 42;
				case XOR: return 42;
			}
			break;
		case 898:
			switch(symbol) {
				case AND: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case INSTANCEOF: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case RBRACKET: return 71;
				case REMAINDER: return 71;
				case XOR: return 71;
			}
			break;
		case 900:
			switch(symbol) {
				case AND: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case RBRACKET: return 2;
				case REMAINDER: return 2;
				case XOR: return 2;
			}
			break;
		case 901:
			switch(symbol) {
				case CLASS: return 110;
				case END_TERMINAL: return 131;
				case INTERFACE: return 110;
			}
			break;
		case 904:
			switch(symbol) {
				case RPAREN: return 11;
			}
			break;
		case 905:
			switch(symbol) {
				case AND: return 69;
				case ASSIGN: return 69;
				case COMMA: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case RPAREN: return 69;
				case XOR: return 69;
			}
			break;
		case 908:
			switch(symbol) {
				case AND: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case RBRACKET: return 73;
				case REMAINDER: return 73;
				case XOR: return 73;
			}
			break;
		case 909:
			switch(symbol) {
				case ARRAY: return 67;
				case ASSIGN: return 67;
				case RPAREN: return 67;
			}
			break;
		case 910:
			switch(symbol) {
				case AND: return 69;
				case COMMA: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case RPAREN: return 69;
				case XOR: return 69;
			}
			break;
		case 914:
			switch(symbol) {
				case ABSTRACT: return 118;
				case CLASS: return 118;
				case FINAL: return 118;
				case INTERFACE: return 118;
				case NATIVE: return 118;
				case PROTECTED: return 118;
				case PUBLIC: return 118;
				case STATIC: return 118;
			}
			break;
		case 915:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case COMMA: return 63;
				case RPAREN: return 63;
			}
			break;
		case 917:
			switch(symbol) {
				case ABSTRACT: return 155;
				case BOOLEAN: return 155;
				case BYTE: return 155;
				case CHAR: return 155;
				case FINAL: return 155;
				case ID: return 155;
				case INT: return 155;
				case NATIVE: return 155;
				case PROTECTED: return 155;
				case PUBLIC: return 155;
				case RBRACE: return 155;
				case SEMICOLON: return 155;
				case SHORT: return 155;
				case STATIC: return 155;
				case VOID: return 155;
			}
			break;
		case 918:
			switch(symbol) {
				case AND: return 72;
				case ASSIGN: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case INSTANCEOF: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case RPAREN: return 72;
				case XOR: return 72;
			}
			break;
		case 919:
			switch(symbol) {
				case AND: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case RPAREN: return 59;
				case XOR: return 59;
			}
			break;
		case 920:
			switch(symbol) {
				case AND: return 61;
				case ASSIGN: return 61;
				case COMMA: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case RPAREN: return 61;
				case XOR: return 61;
			}
			break;
		case 921:
			switch(symbol) {
				case AND: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case INSTANCEOF: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case RBRACKET: return 69;
				case REMAINDER: return 69;
				case XOR: return 69;
			}
			break;
		case 922:
			switch(symbol) {
				case AND: return 59;
				case ASSIGN: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case SEMICOLON: return 59;
				case XOR: return 59;
			}
			break;
		case 923:
			switch(symbol) {
				case SEMICOLON: return 103;
			}
			break;
		case 927:
			switch(symbol) {
				case ARRAY: return 65;
				case ASSIGN: return 65;
				case SEMICOLON: return 65;
			}
			break;
		case 929:
			switch(symbol) {
				case AND: return 71;
				case ASSIGN: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case RPAREN: return 71;
				case XOR: return 71;
			}
			break;
		case 931:
			switch(symbol) {
				case AND: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case INSTANCEOF: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case RPAREN: return 73;
				case XOR: return 73;
			}
			break;
		case 932:
			switch(symbol) {
				case RPAREN: return 174;
			}
			break;
		case 934:
			switch(symbol) {
				case ASSIGN: return 12;
				case RPAREN: return 12;
			}
			break;
		case 935:
			switch(symbol) {
				case ABSTRACT: return 151;
				case BOOLEAN: return 151;
				case BYTE: return 151;
				case CHAR: return 151;
				case FINAL: return 151;
				case ID: return 151;
				case INT: return 151;
				case NATIVE: return 151;
				case PROTECTED: return 151;
				case PUBLIC: return 151;
				case RBRACE: return 151;
				case SEMICOLON: return 151;
				case SHORT: return 151;
				case STATIC: return 151;
				case VOID: return 151;
			}
			break;
		case 936:
			switch(symbol) {
				case AND: return 70;
				case COMMA: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case RPAREN: return 70;
				case XOR: return 70;
			}
			break;
		case 937:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case RBRACKET: return 1;
			}
			break;
		case 938:
			switch(symbol) {
				case AND: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case SEMICOLON: return 58;
				case XOR: return 58;
			}
			break;
		case 939:
			switch(symbol) {
				case AND: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case RPAREN: return 61;
				case XOR: return 61;
			}
			break;
		case 941:
			switch(symbol) {
				case AND: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case INSTANCEOF: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case RPAREN: return 41;
				case XOR: return 41;
			}
			break;
		case 942:
			switch(symbol) {
				case RBRACKET: return 12;
			}
			break;
		case 943:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case SEMICOLON: return 56;
				case XOR: return 56;
			}
			break;
		case 944:
			switch(symbol) {
				case AND: return 71;
				case ASSIGN: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case INSTANCEOF: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case RBRACKET: return 71;
				case REMAINDER: return 71;
				case XOR: return 71;
			}
			break;
		case 945:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case DOT: return 1;
				case SEMICOLON: return 1;
			}
			break;
		case 948:
			switch(symbol) {
				case BOOLEAN: return 93;
				case BOOLEAN_LIT: return 93;
				case BYTE: return 93;
				case CHAR: return 93;
				case CHAR_LIT: return 93;
				case FOR: return 93;
				case ID: return 93;
				case IF: return 93;
				case INT: return 93;
				case INT_LIT: return 93;
				case LBRACE: return 93;
				case LPAREN: return 93;
				case MINUS: return 93;
				case NEW: return 93;
				case NOT: return 93;
				case NULL_LIT: return 93;
				case RBRACE: return 93;
				case RETURN: return 93;
				case SEMICOLON: return 93;
				case SHORT: return 93;
				case STRING_LIT: return 93;
				case THIS: return 93;
				case WHILE: return 93;
			}
			break;
		case 949:
			switch(symbol) {
				case AND: return 41;
				case ASSIGN: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case INSTANCEOF: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case SEMICOLON: return 41;
				case XOR: return 41;
			}
			break;
		case 950:
			switch(symbol) {
				case RBRACKET: return 38;
			}
			break;
		case 951:
			switch(symbol) {
				case END_TERMINAL: return 139;
			}
			break;
		case 952:
			switch(symbol) {
				case ARRAY: return 67;
				case ASSIGN: return 67;
				case RBRACKET: return 67;
			}
			break;
		case 954:
			switch(symbol) {
				case AND: return 61;
				case COMMA: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case RPAREN: return 61;
				case XOR: return 61;
			}
			break;
		case 955:
			switch(symbol) {
				case AND: return 42;
				case ASSIGN: return 42;
				case COMMA: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case RPAREN: return 42;
				case XOR: return 42;
			}
			break;
		case 957:
			switch(symbol) {
				case BOOLEAN: return 98;
				case BOOLEAN_LIT: return 98;
				case BYTE: return 98;
				case CHAR: return 98;
				case CHAR_LIT: return 98;
				case ELSE: return 98;
				case FOR: return 98;
				case ID: return 98;
				case IF: return 98;
				case INT: return 98;
				case INT_LIT: return 98;
				case LBRACE: return 98;
				case LPAREN: return 98;
				case MINUS: return 98;
				case NEW: return 98;
				case NOT: return 98;
				case NULL_LIT: return 98;
				case RBRACE: return 98;
				case RETURN: return 98;
				case SEMICOLON: return 98;
				case SHORT: return 98;
				case STRING_LIT: return 98;
				case THIS: return 98;
				case WHILE: return 98;
			}
			break;
		case 958:
			switch(symbol) {
				case AND: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case INSTANCEOF: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case RPAREN: return 2;
				case XOR: return 2;
			}
			break;
		case 959:
			switch(symbol) {
				case AND: return 41;
				case COMMA: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case INSTANCEOF: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case RPAREN: return 41;
				case XOR: return 41;
			}
			break;
		case 961:
			switch(symbol) {
				case AND: return 56;
				case COMMA: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case RPAREN: return 56;
				case XOR: return 56;
			}
			break;
		case 962:
			switch(symbol) {
				case ASSIGN: return 38;
				case SEMICOLON: return 38;
			}
			break;
		case 964:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case RPAREN: return 56;
				case XOR: return 56;
			}
			break;
		case 965:
			switch(symbol) {
				case AND: return 73;
				case COMMA: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case RPAREN: return 73;
				case XOR: return 73;
			}
			break;
		case 967:
			switch(symbol) {
				case ASSIGN: return 12;
				case RBRACKET: return 12;
			}
			break;
		case 968:
			switch(symbol) {
				case RPAREN: return 12;
			}
			break;
		case 969:
			switch(symbol) {
				case SEMICOLON: return 120;
			}
			break;
		case 970:
			switch(symbol) {
				case AND: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case INSTANCEOF: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case RBRACKET: return 73;
				case REMAINDER: return 73;
				case XOR: return 73;
			}
			break;
		case 971:
			switch(symbol) {
				case COMMA: return 12;
				case LBRACE: return 12;
			}
			break;
		case 972:
			switch(symbol) {
				case AND: return 39;
				case ASSIGN: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case RPAREN: return 39;
				case XOR: return 39;
			}
			break;
		case 975:
			switch(symbol) {
				case AND: return 36;
				case ASSIGN: return 36;
				case DIV: return 36;
				case EAGER_AND: return 36;
				case EAGER_OR: return 36;
				case EQ: return 36;
				case GEQ: return 36;
				case GT: return 36;
				case LEQ: return 36;
				case LT: return 36;
				case MINUS: return 36;
				case MULT: return 36;
				case NEQ: return 36;
				case OR: return 36;
				case PLUS: return 36;
				case REMAINDER: return 36;
				case RPAREN: return 36;
				case XOR: return 36;
			}
			break;
		case 978:
			switch(symbol) {
				case ABSTRACT: return 80;
				case BOOLEAN: return 80;
				case BYTE: return 80;
				case CHAR: return 80;
				case FINAL: return 80;
				case ID: return 80;
				case INT: return 80;
				case NATIVE: return 80;
				case PROTECTED: return 80;
				case PUBLIC: return 80;
				case RBRACE: return 80;
				case SEMICOLON: return 80;
				case SHORT: return 80;
				case STATIC: return 80;
				case VOID: return 80;
			}
			break;
		case 979:
			switch(symbol) {
				case ABSTRACT: return 117;
				case CLASS: return 117;
				case FINAL: return 117;
				case INTERFACE: return 117;
				case NATIVE: return 117;
				case PROTECTED: return 117;
				case PUBLIC: return 117;
				case STATIC: return 117;
			}
			break;
		case 980:
			switch(symbol) {
				case AND: return 69;
				case ASSIGN: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case SEMICOLON: return 69;
				case XOR: return 69;
			}
			break;
		case 981:
			switch(symbol) {
				case AND: return 41;
				case ASSIGN: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case INSTANCEOF: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case RPAREN: return 41;
				case XOR: return 41;
			}
			break;
		case 982:
			switch(symbol) {
				case END_TERMINAL: return 142;
			}
			break;
		case 983:
			switch(symbol) {
				case BOOLEAN: return 89;
				case BOOLEAN_LIT: return 89;
				case BYTE: return 89;
				case CHAR: return 89;
				case CHAR_LIT: return 89;
				case FOR: return 89;
				case ID: return 89;
				case IF: return 89;
				case INT: return 89;
				case INT_LIT: return 89;
				case LBRACE: return 89;
				case LPAREN: return 89;
				case MINUS: return 89;
				case NEW: return 89;
				case NOT: return 89;
				case NULL_LIT: return 89;
				case RBRACE: return 89;
				case RETURN: return 89;
				case SEMICOLON: return 89;
				case SHORT: return 89;
				case STRING_LIT: return 89;
				case THIS: return 89;
				case WHILE: return 89;
			}
			break;
		case 984:
			switch(symbol) {
				case ARRAY: return 65;
				case RBRACKET: return 65;
			}
			break;
		case 985:
			switch(symbol) {
				case AND: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case RPAREN: return 72;
				case XOR: return 72;
			}
			break;
		case 986:
			switch(symbol) {
				case AND: return 41;
				case COMMA: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case RPAREN: return 41;
				case XOR: return 41;
			}
			break;
		case 987:
			switch(symbol) {
				case AND: return 43;
				case ASSIGN: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case INSTANCEOF: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case RBRACKET: return 43;
				case REMAINDER: return 43;
				case XOR: return 43;
			}
			break;
		case 989:
			switch(symbol) {
				case ASSIGN: return 10;
				case RPAREN: return 10;
			}
			break;
		case 990:
			switch(symbol) {
				case AND: return 57;
				case ASSIGN: return 57;
				case COMMA: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case INSTANCEOF: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case RPAREN: return 57;
				case XOR: return 57;
			}
			break;
		case 991:
			switch(symbol) {
				case ARRAY: return 63;
				case COMMA: return 63;
				case RPAREN: return 63;
			}
			break;
		case 992:
			switch(symbol) {
				case AND: return 52;
				case ASSIGN: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case INSTANCEOF: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case RPAREN: return 52;
				case XOR: return 52;
			}
			break;
		case 993:
			switch(symbol) {
				case AND: return 71;
				case COMMA: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case RPAREN: return 71;
				case XOR: return 71;
			}
			break;
		case 994:
			switch(symbol) {
				case AND: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case RBRACKET: return 52;
				case REMAINDER: return 52;
				case XOR: return 52;
			}
			break;
		case 995:
			switch(symbol) {
				case AND: return 62;
				case ASSIGN: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case RBRACKET: return 62;
				case REMAINDER: return 62;
				case XOR: return 62;
			}
			break;
		case 997:
			switch(symbol) {
				case COMMA: return 11;
				case RPAREN: return 11;
			}
			break;
		case 998:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case SEMICOLON: return 1;
			}
			break;
		case 1000:
			switch(symbol) {
				case RPAREN: return 9;
			}
			break;
		case 1001:
			switch(symbol) {
				case AND: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case REMAINDER: return 57;
				case RPAREN: return 57;
				case XOR: return 57;
			}
			break;
		case 1003:
			switch(symbol) {
				case AND: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case INSTANCEOF: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case RBRACKET: return 2;
				case REMAINDER: return 2;
				case XOR: return 2;
			}
			break;
		case 1004:
			switch(symbol) {
				case AND: return 42;
				case ASSIGN: return 42;
				case COMMA: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case INSTANCEOF: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case RPAREN: return 42;
				case XOR: return 42;
			}
			break;
		case 1006:
			switch(symbol) {
				case AND: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case RPAREN: return 41;
				case XOR: return 41;
			}
			break;
		case 1007:
			switch(symbol) {
				case AND: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case INSTANCEOF: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case RPAREN: return 42;
				case XOR: return 42;
			}
			break;
		case 1008:
			switch(symbol) {
				case ABSTRACT: return 111;
				case CLASS: return 111;
				case FINAL: return 111;
				case INTERFACE: return 111;
				case NATIVE: return 111;
				case PROTECTED: return 111;
				case PUBLIC: return 111;
				case STATIC: return 111;
			}
			break;
		case 1009:
			switch(symbol) {
				case AND: return 45;
				case COMMA: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case INSTANCEOF: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case RPAREN: return 45;
				case XOR: return 45;
			}
			break;
		case 1010:
			switch(symbol) {
				case AND: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case INSTANCEOF: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case SEMICOLON: return 73;
				case XOR: return 73;
			}
			break;
		case 1011:
			switch(symbol) {
				case AND: return 37;
				case ASSIGN: return 37;
				case DIV: return 37;
				case EAGER_AND: return 37;
				case EAGER_OR: return 37;
				case EQ: return 37;
				case GEQ: return 37;
				case GT: return 37;
				case LEQ: return 37;
				case LT: return 37;
				case MINUS: return 37;
				case MULT: return 37;
				case NEQ: return 37;
				case OR: return 37;
				case PLUS: return 37;
				case RBRACKET: return 37;
				case REMAINDER: return 37;
				case XOR: return 37;
			}
			break;
		case 1012:
			switch(symbol) {
				case ARRAY: return 2;
				case COMMA: return 2;
				case DOT: return 2;
				case LBRACE: return 2;
			}
			break;
		case 1013:
			switch(symbol) {
				case COMMA: return 10;
				case RPAREN: return 10;
			}
			break;
		case 1014:
			switch(symbol) {
				case AND: return 41;
				case ASSIGN: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case RPAREN: return 41;
				case XOR: return 41;
			}
			break;
		case 1015:
			switch(symbol) {
				case AND: return 2;
				case ASSIGN: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case INSTANCEOF: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case SEMICOLON: return 2;
				case XOR: return 2;
			}
			break;
		case 1016:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case RBRACKET: return 55;
				case REMAINDER: return 55;
				case XOR: return 55;
			}
			break;
		case 1020:
			switch(symbol) {
				case ASSIGN: return 34;
				case COMMA: return 34;
				case RPAREN: return 34;
			}
			break;
		case 1021:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case SEMICOLON: return 55;
				case XOR: return 55;
			}
			break;
		case 1022:
			switch(symbol) {
				case ARRAY: return 65;
				case SEMICOLON: return 65;
			}
			break;
		case 1023:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case RBRACKET: return 56;
				case REMAINDER: return 56;
				case XOR: return 56;
			}
			break;
		case 1029:
			switch(symbol) {
				case AND: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case INSTANCEOF: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case SEMICOLON: return 61;
				case XOR: return 61;
			}
			break;
		case 1032:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case RBRACKET: return 56;
				case REMAINDER: return 56;
				case XOR: return 56;
			}
			break;
		case 1034:
			switch(symbol) {
				case AND: return 39;
				case ASSIGN: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case INSTANCEOF: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case RBRACKET: return 39;
				case REMAINDER: return 39;
				case XOR: return 39;
			}
			break;
		case 1039:
			switch(symbol) {
				case AND: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case SEMICOLON: return 45;
				case XOR: return 45;
			}
			break;
		case 1040:
			switch(symbol) {
				case LBRACE: return 172;
			}
			break;
		case 1041:
			switch(symbol) {
				case AND: return 37;
				case ASSIGN: return 37;
				case DIV: return 37;
				case EAGER_AND: return 37;
				case EAGER_OR: return 37;
				case EQ: return 37;
				case GEQ: return 37;
				case GT: return 37;
				case LEQ: return 37;
				case LT: return 37;
				case MINUS: return 37;
				case MULT: return 37;
				case NEQ: return 37;
				case OR: return 37;
				case PLUS: return 37;
				case REMAINDER: return 37;
				case RPAREN: return 37;
				case XOR: return 37;
			}
			break;
		case 1042:
			switch(symbol) {
				case ARRAY: return 64;
				case RBRACKET: return 64;
			}
			break;
		case 1043:
			switch(symbol) {
				case AND: return 43;
				case ASSIGN: return 43;
				case COMMA: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case INSTANCEOF: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case RPAREN: return 43;
				case XOR: return 43;
			}
			break;
		case 1045:
			switch(symbol) {
				case IMPLEMENTS: return 12;
				case LBRACE: return 12;
			}
			break;
		case 1046:
			switch(symbol) {
				case ARRAY: return 67;
				case ASSIGN: return 67;
				case COMMA: return 67;
				case RPAREN: return 67;
			}
			break;
		case 1047:
			switch(symbol) {
				case AND: return 43;
				case ASSIGN: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case INSTANCEOF: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case RPAREN: return 43;
				case XOR: return 43;
			}
			break;
		case 1048:
			switch(symbol) {
				case ASSIGN: return 10;
				case RBRACKET: return 10;
			}
			break;
		case 1049:
			switch(symbol) {
				case AND: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case RPAREN: return 62;
				case XOR: return 62;
			}
			break;
		case 1051:
			switch(symbol) {
				case BOOLEAN: return 99;
				case BOOLEAN_LIT: return 99;
				case BYTE: return 99;
				case CHAR: return 99;
				case CHAR_LIT: return 99;
				case FOR: return 99;
				case ID: return 99;
				case IF: return 99;
				case INT: return 99;
				case INT_LIT: return 99;
				case LBRACE: return 99;
				case LPAREN: return 99;
				case MINUS: return 99;
				case NEW: return 99;
				case NOT: return 99;
				case NULL_LIT: return 99;
				case RBRACE: return 99;
				case RETURN: return 99;
				case SEMICOLON: return 99;
				case SHORT: return 99;
				case STRING_LIT: return 99;
				case THIS: return 99;
				case WHILE: return 99;
			}
			break;
		case 1052:
			switch(symbol) {
				case BOOLEAN: return 110;
				case BYTE: return 110;
				case CHAR: return 110;
				case ID: return 110;
				case INT: return 110;
				case SHORT: return 110;
				case VOID: return 110;
			}
			break;
		case 1054:
			switch(symbol) {
				case ASSIGN: return 9;
				case RPAREN: return 9;
			}
			break;
		case 1057:
			switch(symbol) {
				case AND: return 71;
				case ASSIGN: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case RBRACKET: return 71;
				case REMAINDER: return 71;
				case XOR: return 71;
			}
			break;
		case 1058:
			switch(symbol) {
				case ABSTRACT: return 132;
				case CLASS: return 132;
				case END_TERMINAL: return 132;
				case FINAL: return 132;
				case IMPORT: return 132;
				case INTERFACE: return 132;
				case NATIVE: return 132;
				case PROTECTED: return 132;
				case PUBLIC: return 132;
				case SEMICOLON: return 132;
				case STATIC: return 132;
			}
			break;
		case 1060:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case SEMICOLON: return 55;
				case XOR: return 55;
			}
			break;
		case 1061:
			switch(symbol) {
				case AND: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case SEMICOLON: return 71;
				case XOR: return 71;
			}
			break;
		case 1062:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case COMMA: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 1064:
			switch(symbol) {
				case AND: return 58;
				case ASSIGN: return 58;
				case COMMA: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case RPAREN: return 58;
				case XOR: return 58;
			}
			break;
		case 1065:
			switch(symbol) {
				case AND: return 73;
				case ASSIGN: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case INSTANCEOF: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case RPAREN: return 73;
				case XOR: return 73;
			}
			break;
		case 1066:
			switch(symbol) {
				case ABSTRACT: return 162;
				case BOOLEAN: return 162;
				case BYTE: return 162;
				case CHAR: return 162;
				case FINAL: return 162;
				case ID: return 162;
				case INT: return 162;
				case NATIVE: return 162;
				case PROTECTED: return 162;
				case PUBLIC: return 162;
				case RBRACE: return 162;
				case SEMICOLON: return 162;
				case SHORT: return 162;
				case STATIC: return 162;
				case VOID: return 162;
			}
			break;
		case 1068:
			switch(symbol) {
				case RBRACKET: return 34;
			}
			break;
		case 1069:
			switch(symbol) {
				case AND: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case RBRACKET: return 41;
				case REMAINDER: return 41;
				case XOR: return 41;
			}
			break;
		case 1070:
			switch(symbol) {
				case ARRAY: return 64;
				case SEMICOLON: return 64;
			}
			break;
		case 1071:
			switch(symbol) {
				case AND: return 36;
				case DIV: return 36;
				case EAGER_AND: return 36;
				case EAGER_OR: return 36;
				case EQ: return 36;
				case GEQ: return 36;
				case GT: return 36;
				case LEQ: return 36;
				case LT: return 36;
				case MINUS: return 36;
				case MULT: return 36;
				case NEQ: return 36;
				case OR: return 36;
				case PLUS: return 36;
				case REMAINDER: return 36;
				case SEMICOLON: return 36;
				case XOR: return 36;
			}
			break;
		case 1072:
			switch(symbol) {
				case AND: return 41;
				case ASSIGN: return 41;
				case COMMA: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case RPAREN: return 41;
				case XOR: return 41;
			}
			break;
		case 1073:
			switch(symbol) {
				case AND: return 61;
				case ASSIGN: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case RPAREN: return 61;
				case XOR: return 61;
			}
			break;
		case 1075:
			switch(symbol) {
				case AND: return 52;
				case ASSIGN: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case INSTANCEOF: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case SEMICOLON: return 52;
				case XOR: return 52;
			}
			break;
		case 1076:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case COMMA: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case RPAREN: return 56;
				case XOR: return 56;
			}
			break;
		case 1077:
			switch(symbol) {
				case RPAREN: return 10;
			}
			break;
		case 1079:
			switch(symbol) {
				case RBRACKET: return 11;
			}
			break;
		case 1081:
			switch(symbol) {
				case BOOLEAN: return 89;
				case BOOLEAN_LIT: return 89;
				case BYTE: return 89;
				case CHAR: return 89;
				case CHAR_LIT: return 89;
				case FOR: return 89;
				case ID: return 89;
				case IF: return 89;
				case INT: return 89;
				case INT_LIT: return 89;
				case LBRACE: return 89;
				case LPAREN: return 89;
				case MINUS: return 89;
				case NEW: return 89;
				case NOT: return 89;
				case NULL_LIT: return 89;
				case RBRACE: return 89;
				case RETURN: return 89;
				case SEMICOLON: return 89;
				case SHORT: return 89;
				case STRING_LIT: return 89;
				case THIS: return 89;
				case WHILE: return 89;
			}
			break;
		case 1083:
			switch(symbol) {
				case AND: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case RBRACKET: return 58;
				case REMAINDER: return 58;
				case XOR: return 58;
			}
			break;
		case 1084:
			switch(symbol) {
				case AND: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case INSTANCEOF: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case RBRACKET: return 42;
				case REMAINDER: return 42;
				case XOR: return 42;
			}
			break;
		case 1086:
			switch(symbol) {
				case COMMA: return 176;
				case RPAREN: return 176;
			}
			break;
		case 1087:
			switch(symbol) {
				case ABSTRACT: return 126;
				case CLASS: return 126;
				case END_TERMINAL: return 126;
				case FINAL: return 126;
				case INTERFACE: return 126;
				case NATIVE: return 126;
				case PROTECTED: return 126;
				case PUBLIC: return 126;
				case SEMICOLON: return 126;
				case STATIC: return 126;
			}
			break;
		case 1088:
			switch(symbol) {
				case ASSIGN: return 9;
				case RBRACKET: return 9;
			}
			break;
		case 1089:
			switch(symbol) {
				case ASSIGN: return 10;
				case COMMA: return 10;
				case RPAREN: return 10;
			}
			break;
		case 1090:
			switch(symbol) {
				case AND: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case RBRACKET: return 69;
				case REMAINDER: return 69;
				case XOR: return 69;
			}
			break;
		case 1091:
			switch(symbol) {
				case RPAREN: return 147;
			}
			break;
		case 1094:
			switch(symbol) {
				case ASSIGN: return 34;
				case RBRACKET: return 34;
			}
			break;
		case 1096:
			switch(symbol) {
				case AND: return 43;
				case ASSIGN: return 43;
				case COMMA: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case RPAREN: return 43;
				case XOR: return 43;
			}
			break;
		case 1097:
			switch(symbol) {
				case ABSTRACT: return 156;
				case BOOLEAN: return 156;
				case BYTE: return 156;
				case CHAR: return 156;
				case FINAL: return 156;
				case ID: return 156;
				case INT: return 156;
				case NATIVE: return 156;
				case PROTECTED: return 156;
				case PUBLIC: return 156;
				case RBRACE: return 156;
				case SEMICOLON: return 156;
				case SHORT: return 156;
				case STATIC: return 156;
				case VOID: return 156;
			}
			break;
		case 1098:
			switch(symbol) {
				case AND: return 71;
				case ASSIGN: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case INSTANCEOF: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case SEMICOLON: return 71;
				case XOR: return 71;
			}
			break;
		case 1099:
			switch(symbol) {
				case AND: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case INSTANCEOF: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case SEMICOLON: return 58;
				case XOR: return 58;
			}
			break;
		case 1102:
			switch(symbol) {
				case AND: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case SEMICOLON: return 70;
				case XOR: return 70;
			}
			break;
		case 1105:
			switch(symbol) {
				case END_TERMINAL: return 123;
			}
			break;
		case 1106:
			switch(symbol) {
				case ARRAY: return 2;
				case COMMA: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 1107:
			switch(symbol) {
				case COMMA: return 10;
				case LBRACE: return 10;
			}
			break;
		case 1112:
			switch(symbol) {
				case AND: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case RPAREN: return 70;
				case XOR: return 70;
			}
			break;
		case 1114:
			switch(symbol) {
				case AND: return 59;
				case ASSIGN: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case RBRACKET: return 59;
				case REMAINDER: return 59;
				case XOR: return 59;
			}
			break;
		case 1118:
			switch(symbol) {
				case AND: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case INSTANCEOF: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case RBRACKET: return 57;
				case REMAINDER: return 57;
				case XOR: return 57;
			}
			break;
		case 1119:
			switch(symbol) {
				case AND: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case RBRACKET: return 60;
				case REMAINDER: return 60;
				case XOR: return 60;
			}
			break;
		case 1120:
			switch(symbol) {
				case AND: return 62;
				case ASSIGN: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case SEMICOLON: return 62;
				case XOR: return 62;
			}
			break;
		case 1122:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case COMMA: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case RPAREN: return 55;
				case XOR: return 55;
			}
			break;
		case 1123:
			switch(symbol) {
				case ABSTRACT: return 133;
				case CLASS: return 133;
				case END_TERMINAL: return 133;
				case FINAL: return 133;
				case IMPORT: return 133;
				case INTERFACE: return 133;
				case NATIVE: return 133;
				case PROTECTED: return 133;
				case PUBLIC: return 133;
				case SEMICOLON: return 133;
				case STATIC: return 133;
			}
			break;
		case 1124:
			switch(symbol) {
				case AND: return 72;
				case ASSIGN: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case INSTANCEOF: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case RBRACKET: return 72;
				case REMAINDER: return 72;
				case XOR: return 72;
			}
			break;
		case 1125:
			switch(symbol) {
				case AND: return 52;
				case ASSIGN: return 52;
				case COMMA: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case RPAREN: return 52;
				case XOR: return 52;
			}
			break;
		case 1126:
			switch(symbol) {
				case AND: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case INSTANCEOF: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case RBRACKET: return 59;
				case REMAINDER: return 59;
				case XOR: return 59;
			}
			break;
		case 1127:
			switch(symbol) {
				case AND: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case RBRACKET: return 42;
				case REMAINDER: return 42;
				case XOR: return 42;
			}
			break;
		case 1128:
			switch(symbol) {
				case ARRAY: return 67;
				case COMMA: return 67;
				case RPAREN: return 67;
			}
			break;
		case 1129:
			switch(symbol) {
				case AND: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case RPAREN: return 45;
				case XOR: return 45;
			}
			break;
		case 1130:
			switch(symbol) {
				case ARRAY: return 63;
				case COMMA: return 63;
				case LBRACE: return 63;
			}
			break;
		case 1131:
			switch(symbol) {
				case AND: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case INSTANCEOF: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case RBRACKET: return 41;
				case REMAINDER: return 41;
				case XOR: return 41;
			}
			break;
		case 1133:
			switch(symbol) {
				case SEMICOLON: return 34;
			}
			break;
		case 1134:
			switch(symbol) {
				case AND: return 73;
				case ASSIGN: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case SEMICOLON: return 73;
				case XOR: return 73;
			}
			break;
		case 1135:
			switch(symbol) {
				case AND: return 45;
				case ASSIGN: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case INSTANCEOF: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case RPAREN: return 45;
				case XOR: return 45;
			}
			break;
		case 1136:
			switch(symbol) {
				case AND: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case INSTANCEOF: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case RPAREN: return 43;
				case XOR: return 43;
			}
			break;
		case 1139:
			switch(symbol) {
				case AND: return 45;
				case ASSIGN: return 45;
				case COMMA: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case INSTANCEOF: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case REMAINDER: return 45;
				case RPAREN: return 45;
				case XOR: return 45;
			}
			break;
		case 1140:
			switch(symbol) {
				case AND: return 60;
				case ASSIGN: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case INSTANCEOF: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case SEMICOLON: return 60;
				case XOR: return 60;
			}
			break;
		case 1141:
			switch(symbol) {
				case AND: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case SEMICOLON: return 43;
				case XOR: return 43;
			}
			break;
		case 1142:
			switch(symbol) {
				case AND: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case RBRACKET: return 68;
				case REMAINDER: return 68;
				case XOR: return 68;
			}
			break;
		case 1143:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case RPAREN: return 55;
				case XOR: return 55;
			}
			break;
		case 1144:
			switch(symbol) {
				case SEMICOLON: return 49;
			}
			break;
		case 1145:
			switch(symbol) {
				case ABSTRACT: return 114;
				case CLASS: return 114;
				case FINAL: return 114;
				case INTERFACE: return 114;
				case NATIVE: return 114;
				case PROTECTED: return 114;
				case PUBLIC: return 114;
				case STATIC: return 114;
			}
			break;
		case 1146:
			switch(symbol) {
				case AND: return 59;
				case ASSIGN: return 59;
				case COMMA: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case INSTANCEOF: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case REMAINDER: return 59;
				case RPAREN: return 59;
				case XOR: return 59;
			}
			break;
		case 1147:
			switch(symbol) {
				case AND: return 39;
				case ASSIGN: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case INSTANCEOF: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case RPAREN: return 39;
				case XOR: return 39;
			}
			break;
		case 1148:
			switch(symbol) {
				case AND: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case INSTANCEOF: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case SEMICOLON: return 52;
				case XOR: return 52;
			}
			break;
		case 1151:
			switch(symbol) {
				case AND: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case RBRACKET: return 62;
				case REMAINDER: return 62;
				case XOR: return 62;
			}
			break;
		case 1152:
			switch(symbol) {
				case LBRACE: return 172;
				case SEMICOLON: return 172;
			}
			break;
		case 1153:
			switch(symbol) {
				case AND: return 39;
				case ASSIGN: return 39;
				case COMMA: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case INSTANCEOF: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case REMAINDER: return 39;
				case RPAREN: return 39;
				case XOR: return 39;
			}
			break;
		case 1154:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case COMMA: return 64;
				case RPAREN: return 64;
			}
			break;
		case 1156:
			switch(symbol) {
				case DOT: return 2;
				case LPAREN: return 2;
			}
			break;
		case 1158:
			switch(symbol) {
				case AND: return 2;
				case ASSIGN: return 2;
				case COMMA: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case RPAREN: return 2;
				case XOR: return 2;
			}
			break;
		case 1160:
			switch(symbol) {
				case ARRAY: return 66;
				case IMPLEMENTS: return 66;
				case LBRACE: return 66;
			}
			break;
		case 1161:
			switch(symbol) {
				case AND: return 57;
				case ASSIGN: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case RBRACKET: return 57;
				case REMAINDER: return 57;
				case XOR: return 57;
			}
			break;
		case 1162:
			switch(symbol) {
				case SEMICOLON: return 10;
			}
			break;
		case 1163:
			switch(symbol) {
				case AND: return 36;
				case ASSIGN: return 36;
				case DIV: return 36;
				case EAGER_AND: return 36;
				case EAGER_OR: return 36;
				case EQ: return 36;
				case GEQ: return 36;
				case GT: return 36;
				case LEQ: return 36;
				case LT: return 36;
				case MINUS: return 36;
				case MULT: return 36;
				case NEQ: return 36;
				case OR: return 36;
				case PLUS: return 36;
				case REMAINDER: return 36;
				case SEMICOLON: return 36;
				case XOR: return 36;
			}
			break;
		case 1164:
			switch(symbol) {
				case AND: return 58;
				case ASSIGN: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case RBRACKET: return 58;
				case REMAINDER: return 58;
				case XOR: return 58;
			}
			break;
		case 1165:
			switch(symbol) {
				case AND: return 68;
				case ASSIGN: return 68;
				case COMMA: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case INSTANCEOF: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case RPAREN: return 68;
				case XOR: return 68;
			}
			break;
		case 1167:
			switch(symbol) {
				case LBRACE: return 71;
				case RPAREN: return 71;
			}
			break;
		case 1168:
			switch(symbol) {
				case AND: return 62;
				case COMMA: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case INSTANCEOF: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case RPAREN: return 62;
				case XOR: return 62;
			}
			break;
		case 1171:
			switch(symbol) {
				case BOOLEAN: return 95;
				case BOOLEAN_LIT: return 95;
				case BYTE: return 95;
				case CHAR: return 95;
				case CHAR_LIT: return 95;
				case FOR: return 95;
				case ID: return 95;
				case IF: return 95;
				case INT: return 95;
				case INT_LIT: return 95;
				case LBRACE: return 95;
				case LPAREN: return 95;
				case MINUS: return 95;
				case NEW: return 95;
				case NOT: return 95;
				case NULL_LIT: return 95;
				case RBRACE: return 95;
				case RETURN: return 95;
				case SEMICOLON: return 95;
				case SHORT: return 95;
				case STRING_LIT: return 95;
				case THIS: return 95;
				case WHILE: return 95;
			}
			break;
		case 1172:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case RBRACKET: return 2;
			}
			break;
		case 1176:
			switch(symbol) {
				case COMMA: return 12;
				case RPAREN: return 12;
			}
			break;
		case 1179:
			switch(symbol) {
				case AND: return 58;
				case COMMA: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case RPAREN: return 58;
				case XOR: return 58;
			}
			break;
		case 1181:
			switch(symbol) {
				case SEMICOLON: return 38;
			}
			break;
		case 1183:
			switch(symbol) {
				case ABSTRACT: return 154;
				case BOOLEAN: return 154;
				case BYTE: return 154;
				case CHAR: return 154;
				case FINAL: return 154;
				case ID: return 154;
				case INT: return 154;
				case NATIVE: return 154;
				case PROTECTED: return 154;
				case PUBLIC: return 154;
				case RBRACE: return 154;
				case SEMICOLON: return 154;
				case SHORT: return 154;
				case STATIC: return 154;
				case VOID: return 154;
			}
			break;
		case 1184:
			switch(symbol) {
				case ARRAY: return 67;
				case IMPLEMENTS: return 67;
				case LBRACE: return 67;
			}
			break;
		case 1186:
			switch(symbol) {
				case AND: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case INSTANCEOF: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case SEMICOLON: return 71;
				case XOR: return 71;
			}
			break;
		case 1187:
			switch(symbol) {
				case AND: return 58;
				case ASSIGN: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case SEMICOLON: return 58;
				case XOR: return 58;
			}
			break;
		case 1188:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case COMMA: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case RPAREN: return 56;
				case XOR: return 56;
			}
			break;
		case 1189:
			switch(symbol) {
				case SEMICOLON: return 119;
			}
			break;
		case 1190:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case RPAREN: return 56;
				case XOR: return 56;
			}
			break;
		case 1191:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case RPAREN: return 55;
				case XOR: return 55;
			}
			break;
		case 1193:
			switch(symbol) {
				case AND: return 71;
				case ASSIGN: return 71;
				case COMMA: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case RPAREN: return 71;
				case XOR: return 71;
			}
			break;
		case 1195:
			switch(symbol) {
				case ABSTRACT: return 153;
				case BOOLEAN: return 153;
				case BYTE: return 153;
				case CHAR: return 153;
				case FINAL: return 153;
				case ID: return 153;
				case INT: return 153;
				case NATIVE: return 153;
				case PROTECTED: return 153;
				case PUBLIC: return 153;
				case RBRACE: return 153;
				case SEMICOLON: return 153;
				case SHORT: return 153;
				case STATIC: return 153;
				case VOID: return 153;
			}
			break;
		case 1196:
			switch(symbol) {
				case AND: return 72;
				case ASSIGN: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case SEMICOLON: return 72;
				case XOR: return 72;
			}
			break;
		case 1197:
			switch(symbol) {
				case COMMA: return 175;
				case RPAREN: return 175;
			}
			break;
		case 1200:
			switch(symbol) {
				case AND: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case REMAINDER: return 43;
				case RPAREN: return 43;
				case XOR: return 43;
			}
			break;
		case 1202:
			switch(symbol) {
				case ABSTRACT: return 116;
				case CLASS: return 116;
				case FINAL: return 116;
				case INTERFACE: return 116;
				case NATIVE: return 116;
				case PROTECTED: return 116;
				case PUBLIC: return 116;
				case STATIC: return 116;
			}
			break;
		case 1204:
			switch(symbol) {
				case RPAREN: return 146;
			}
			break;
		case 1205:
			switch(symbol) {
				case AND: return 37;
				case DIV: return 37;
				case EAGER_AND: return 37;
				case EAGER_OR: return 37;
				case EQ: return 37;
				case GEQ: return 37;
				case GT: return 37;
				case LEQ: return 37;
				case LT: return 37;
				case MINUS: return 37;
				case MULT: return 37;
				case NEQ: return 37;
				case OR: return 37;
				case PLUS: return 37;
				case REMAINDER: return 37;
				case SEMICOLON: return 37;
				case XOR: return 37;
			}
			break;
		case 1206:
			switch(symbol) {
				case RPAREN: return 34;
			}
			break;
		case 1208:
			switch(symbol) {
				case SEMICOLON: return 3;
			}
			break;
		case 1209:
			switch(symbol) {
				case AND: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case INSTANCEOF: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case RBRACKET: return 72;
				case REMAINDER: return 72;
				case XOR: return 72;
			}
			break;
		case 1211:
			switch(symbol) {
				case AND: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case SEMICOLON: return 60;
				case XOR: return 60;
			}
			break;
		case 1214:
			switch(symbol) {
				case AND: return 36;
				case ASSIGN: return 36;
				case COMMA: return 36;
				case DIV: return 36;
				case EAGER_AND: return 36;
				case EAGER_OR: return 36;
				case EQ: return 36;
				case GEQ: return 36;
				case GT: return 36;
				case LEQ: return 36;
				case LT: return 36;
				case MINUS: return 36;
				case MULT: return 36;
				case NEQ: return 36;
				case OR: return 36;
				case PLUS: return 36;
				case REMAINDER: return 36;
				case RPAREN: return 36;
				case XOR: return 36;
			}
			break;
		case 1216:
			switch(symbol) {
				case AND: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case RBRACKET: return 71;
				case REMAINDER: return 71;
				case XOR: return 71;
			}
			break;
		case 1222:
			switch(symbol) {
				case AND: return 61;
				case ASSIGN: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case RBRACKET: return 61;
				case REMAINDER: return 61;
				case XOR: return 61;
			}
			break;
		case 1223:
			switch(symbol) {
				case BOOLEAN: return 101;
				case BOOLEAN_LIT: return 101;
				case BYTE: return 101;
				case CHAR: return 101;
				case CHAR_LIT: return 101;
				case FOR: return 101;
				case ID: return 101;
				case IF: return 101;
				case INT: return 101;
				case INT_LIT: return 101;
				case LBRACE: return 101;
				case LPAREN: return 101;
				case MINUS: return 101;
				case NEW: return 101;
				case NOT: return 101;
				case NULL_LIT: return 101;
				case RBRACE: return 101;
				case RETURN: return 101;
				case SEMICOLON: return 101;
				case SHORT: return 101;
				case STRING_LIT: return 101;
				case THIS: return 101;
				case WHILE: return 101;
			}
			break;
		case 1224:
			switch(symbol) {
				case AND: return 36;
				case ASSIGN: return 36;
				case DIV: return 36;
				case EAGER_AND: return 36;
				case EAGER_OR: return 36;
				case EQ: return 36;
				case GEQ: return 36;
				case GT: return 36;
				case LEQ: return 36;
				case LT: return 36;
				case MINUS: return 36;
				case MULT: return 36;
				case NEQ: return 36;
				case OR: return 36;
				case PLUS: return 36;
				case RBRACKET: return 36;
				case REMAINDER: return 36;
				case XOR: return 36;
			}
			break;
		case 1226:
			switch(symbol) {
				case AND: return 57;
				case ASSIGN: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case INSTANCEOF: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case RBRACKET: return 57;
				case REMAINDER: return 57;
				case XOR: return 57;
			}
			break;
		case 1227:
			switch(symbol) {
				case AND: return 42;
				case COMMA: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case INSTANCEOF: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case RPAREN: return 42;
				case XOR: return 42;
			}
			break;
		case 1228:
			switch(symbol) {
				case ABSTRACT: return 112;
				case BOOLEAN: return 112;
				case BYTE: return 112;
				case CHAR: return 112;
				case FINAL: return 112;
				case ID: return 112;
				case INT: return 112;
				case NATIVE: return 112;
				case PROTECTED: return 112;
				case PUBLIC: return 112;
				case SHORT: return 112;
				case STATIC: return 112;
				case VOID: return 112;
			}
			break;
		case 1229:
			switch(symbol) {
				case AND: return 68;
				case ASSIGN: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case INSTANCEOF: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case RBRACKET: return 68;
				case REMAINDER: return 68;
				case XOR: return 68;
			}
			break;
		case 1230:
			switch(symbol) {
				case BOOLEAN: return 87;
				case BOOLEAN_LIT: return 87;
				case BYTE: return 87;
				case CHAR: return 87;
				case CHAR_LIT: return 87;
				case FOR: return 87;
				case ID: return 87;
				case IF: return 87;
				case INT: return 87;
				case INT_LIT: return 87;
				case LBRACE: return 87;
				case LPAREN: return 87;
				case MINUS: return 87;
				case NEW: return 87;
				case NOT: return 87;
				case NULL_LIT: return 87;
				case RBRACE: return 87;
				case RETURN: return 87;
				case SEMICOLON: return 87;
				case SHORT: return 87;
				case STRING_LIT: return 87;
				case THIS: return 87;
				case WHILE: return 87;
			}
			break;
		case 1232:
			switch(symbol) {
				case AND: return 61;
				case ASSIGN: return 61;
				case DIV: return 61;
				case DOT: return 61;
				case EAGER_AND: return 61;
				case EAGER_OR: return 61;
				case EQ: return 61;
				case GEQ: return 61;
				case GT: return 61;
				case INSTANCEOF: return 61;
				case LBRACKET: return 61;
				case LEQ: return 61;
				case LT: return 61;
				case MINUS: return 61;
				case MULT: return 61;
				case NEQ: return 61;
				case OR: return 61;
				case PLUS: return 61;
				case REMAINDER: return 61;
				case RPAREN: return 61;
				case XOR: return 61;
			}
			break;
		case 1233:
			switch(symbol) {
				case AND: return 41;
				case ASSIGN: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case RBRACKET: return 41;
				case REMAINDER: return 41;
				case XOR: return 41;
			}
			break;
		case 1235:
			switch(symbol) {
				case ARRAY: return 63;
				case RPAREN: return 63;
			}
			break;
		case 1236:
			switch(symbol) {
				case AND: return 62;
				case ASSIGN: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case INSTANCEOF: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case SEMICOLON: return 62;
				case XOR: return 62;
			}
			break;
		case 1237:
			switch(symbol) {
				case AND: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case INSTANCEOF: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case RPAREN: return 68;
				case XOR: return 68;
			}
			break;
		case 1239:
			switch(symbol) {
				case AND: return 71;
				case ASSIGN: return 71;
				case COMMA: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
				case INSTANCEOF: return 71;
				case LBRACKET: return 71;
				case LEQ: return 71;
				case LT: return 71;
				case MINUS: return 71;
				case MULT: return 71;
				case NEQ: return 71;
				case OR: return 71;
				case PLUS: return 71;
				case REMAINDER: return 71;
				case RPAREN: return 71;
				case XOR: return 71;
			}
			break;
		case 1241:
			switch(symbol) {
				case AND: return 37;
				case ASSIGN: return 37;
				case DIV: return 37;
				case EAGER_AND: return 37;
				case EAGER_OR: return 37;
				case EQ: return 37;
				case GEQ: return 37;
				case GT: return 37;
				case LEQ: return 37;
				case LT: return 37;
				case MINUS: return 37;
				case MULT: return 37;
				case NEQ: return 37;
				case OR: return 37;
				case PLUS: return 37;
				case REMAINDER: return 37;
				case SEMICOLON: return 37;
				case XOR: return 37;
			}
			break;
		case 1243:
			switch(symbol) {
				case AND: return 73;
				case ASSIGN: return 73;
				case COMMA: return 73;
				case DIV: return 73;
				case DOT: return 73;
				case EAGER_AND: return 73;
				case EAGER_OR: return 73;
				case EQ: return 73;
				case GEQ: return 73;
				case GT: return 73;
				case LBRACKET: return 73;
				case LEQ: return 73;
				case LT: return 73;
				case MINUS: return 73;
				case MULT: return 73;
				case NEQ: return 73;
				case OR: return 73;
				case PLUS: return 73;
				case REMAINDER: return 73;
				case RPAREN: return 73;
				case XOR: return 73;
			}
			break;
		case 1244:
			switch(symbol) {
				case AND: return 45;
				case DIV: return 45;
				case EAGER_AND: return 45;
				case EAGER_OR: return 45;
				case EQ: return 45;
				case GEQ: return 45;
				case GT: return 45;
				case INSTANCEOF: return 45;
				case LEQ: return 45;
				case LT: return 45;
				case MINUS: return 45;
				case MULT: return 45;
				case NEQ: return 45;
				case OR: return 45;
				case PLUS: return 45;
				case RBRACKET: return 45;
				case REMAINDER: return 45;
				case XOR: return 45;
			}
			break;
		case 1246:
			switch(symbol) {
				case ARRAY: return 65;
				case ASSIGN: return 65;
				case COMMA: return 65;
				case RPAREN: return 65;
			}
			break;
		case 1248:
			switch(symbol) {
				case AND: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case INSTANCEOF: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case REMAINDER: return 70;
				case RPAREN: return 70;
				case XOR: return 70;
			}
			break;
		case 1249:
			switch(symbol) {
				case AND: return 68;
				case COMMA: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case INSTANCEOF: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case RPAREN: return 68;
				case XOR: return 68;
			}
			break;
		case 1250:
			switch(symbol) {
				case ABSTRACT: return 128;
				case CLASS: return 128;
				case END_TERMINAL: return 128;
				case FINAL: return 128;
				case IMPORT: return 128;
				case INTERFACE: return 128;
				case NATIVE: return 128;
				case PROTECTED: return 128;
				case PUBLIC: return 128;
				case SEMICOLON: return 128;
				case STATIC: return 128;
			}
			break;
		case 1251:
			switch(symbol) {
				case END_TERMINAL: return 146;
			}
			break;
		case 1252:
			switch(symbol) {
				case AND: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case INSTANCEOF: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case RPAREN: return 60;
				case XOR: return 60;
			}
			break;
		case 1253:
			switch(symbol) {
				case AND: return 70;
				case ASSIGN: return 70;
				case DIV: return 70;
				case DOT: return 70;
				case EAGER_AND: return 70;
				case EAGER_OR: return 70;
				case EQ: return 70;
				case GEQ: return 70;
				case GT: return 70;
				case INSTANCEOF: return 70;
				case LBRACKET: return 70;
				case LEQ: return 70;
				case LT: return 70;
				case MINUS: return 70;
				case MULT: return 70;
				case NEQ: return 70;
				case OR: return 70;
				case PLUS: return 70;
				case RBRACKET: return 70;
				case REMAINDER: return 70;
				case XOR: return 70;
			}
			break;
		case 1255:
			switch(symbol) {
				case END_TERMINAL: return 140;
			}
			break;
		case 1256:
			switch(symbol) {
				case AND: return 68;
				case COMMA: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case REMAINDER: return 68;
				case RPAREN: return 68;
				case XOR: return 68;
			}
			break;
		case 1257:
			switch(symbol) {
				case END_TERMINAL: return 135;
			}
			break;
		case 1258:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case REMAINDER: return 56;
				case RPAREN: return 56;
				case XOR: return 56;
			}
			break;
		case 1259:
			switch(symbol) {
				case AND: return 52;
				case COMMA: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case INSTANCEOF: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case RPAREN: return 52;
				case XOR: return 52;
			}
			break;
		case 1261:
			switch(symbol) {
				case COMMA: return 9;
				case RPAREN: return 9;
			}
			break;
		case 1263:
			switch(symbol) {
				case END_TERMINAL: return 147;
			}
			break;
		case 1266:
			switch(symbol) {
				case AND: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case SEMICOLON: return 69;
				case XOR: return 69;
			}
			break;
		case 1267:
			switch(symbol) {
				case BOOLEAN: return 98;
				case BOOLEAN_LIT: return 98;
				case BYTE: return 98;
				case CHAR: return 98;
				case CHAR_LIT: return 98;
				case FOR: return 98;
				case ID: return 98;
				case IF: return 98;
				case INT: return 98;
				case INT_LIT: return 98;
				case LBRACE: return 98;
				case LPAREN: return 98;
				case MINUS: return 98;
				case NEW: return 98;
				case NOT: return 98;
				case NULL_LIT: return 98;
				case RBRACE: return 98;
				case RETURN: return 98;
				case SEMICOLON: return 98;
				case SHORT: return 98;
				case STRING_LIT: return 98;
				case THIS: return 98;
				case WHILE: return 98;
			}
			break;
		case 1268:
			switch(symbol) {
				case ABSTRACT: return 166;
				case BOOLEAN: return 166;
				case BYTE: return 166;
				case CHAR: return 166;
				case FINAL: return 166;
				case ID: return 166;
				case INT: return 166;
				case NATIVE: return 166;
				case PROTECTED: return 166;
				case PUBLIC: return 166;
				case RBRACE: return 166;
				case SEMICOLON: return 166;
				case SHORT: return 166;
				case STATIC: return 166;
				case VOID: return 166;
			}
			break;
		case 1269:
			switch(symbol) {
				case AND: return 37;
				case COMMA: return 37;
				case DIV: return 37;
				case EAGER_AND: return 37;
				case EAGER_OR: return 37;
				case EQ: return 37;
				case GEQ: return 37;
				case GT: return 37;
				case LEQ: return 37;
				case LT: return 37;
				case MINUS: return 37;
				case MULT: return 37;
				case NEQ: return 37;
				case OR: return 37;
				case PLUS: return 37;
				case REMAINDER: return 37;
				case RPAREN: return 37;
				case XOR: return 37;
			}
			break;
		case 1272:
			switch(symbol) {
				case ASSIGN: return 38;
				case COMMA: return 38;
				case RPAREN: return 38;
			}
			break;
		case 1274:
			switch(symbol) {
				case AND: return 60;
				case COMMA: return 60;
				case DIV: return 60;
				case DOT: return 60;
				case EAGER_AND: return 60;
				case EAGER_OR: return 60;
				case EQ: return 60;
				case GEQ: return 60;
				case GT: return 60;
				case INSTANCEOF: return 60;
				case LBRACKET: return 60;
				case LEQ: return 60;
				case LT: return 60;
				case MINUS: return 60;
				case MULT: return 60;
				case NEQ: return 60;
				case OR: return 60;
				case PLUS: return 60;
				case REMAINDER: return 60;
				case RPAREN: return 60;
				case XOR: return 60;
			}
			break;
		case 1275:
			switch(symbol) {
				case RBRACKET: return 35;
			}
			break;
		case 1277:
			switch(symbol) {
				case AND: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case SEMICOLON: return 41;
				case XOR: return 41;
			}
			break;
		case 1279:
			switch(symbol) {
				case AND: return 41;
				case ASSIGN: return 41;
				case COMMA: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case INSTANCEOF: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case REMAINDER: return 41;
				case RPAREN: return 41;
				case XOR: return 41;
			}
			break;
		case 1280:
			switch(symbol) {
				case AND: return 2;
				case COMMA: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case REMAINDER: return 2;
				case RPAREN: return 2;
				case XOR: return 2;
			}
			break;
		case 1286:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case RBRACKET: return 55;
				case REMAINDER: return 55;
				case XOR: return 55;
			}
			break;
		case 1289:
			switch(symbol) {
				case AND: return 52;
				case COMMA: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
				case LBRACKET: return 52;
				case LEQ: return 52;
				case LT: return 52;
				case MINUS: return 52;
				case MULT: return 52;
				case NEQ: return 52;
				case OR: return 52;
				case PLUS: return 52;
				case REMAINDER: return 52;
				case RPAREN: return 52;
				case XOR: return 52;
			}
			break;
		case 1290:
			switch(symbol) {
				case IMPLEMENTS: return 9;
				case LBRACE: return 9;
			}
			break;
		case 1292:
			switch(symbol) {
				case ASSIGN: return 35;
				case RBRACKET: return 35;
			}
			break;
		case 1293:
			switch(symbol) {
				case AND: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case INSTANCEOF: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case RBRACKET: return 39;
				case REMAINDER: return 39;
				case XOR: return 39;
			}
			break;
		case 1294:
			switch(symbol) {
				case END_TERMINAL: return 130;
			}
			break;
		case 1295:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case COMMA: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 1296:
			switch(symbol) {
				case AND: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
				case LBRACKET: return 72;
				case LEQ: return 72;
				case LT: return 72;
				case MINUS: return 72;
				case MULT: return 72;
				case NEQ: return 72;
				case OR: return 72;
				case PLUS: return 72;
				case REMAINDER: return 72;
				case SEMICOLON: return 72;
				case XOR: return 72;
			}
			break;
		case 1297:
			switch(symbol) {
				case ABSTRACT: return 112;
				case CLASS: return 112;
				case FINAL: return 112;
				case INTERFACE: return 112;
				case NATIVE: return 112;
				case PROTECTED: return 112;
				case PUBLIC: return 112;
				case STATIC: return 112;
			}
			break;
		case 1298:
			switch(symbol) {
				case AND: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case INSTANCEOF: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case RPAREN: return 69;
				case XOR: return 69;
			}
			break;
		case 1299:
			switch(symbol) {
				case SEMICOLON: return 121;
			}
			break;
		case 1300:
			switch(symbol) {
				case AND: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case REMAINDER: return 58;
				case RPAREN: return 58;
				case XOR: return 58;
			}
			break;
		case 1301:
			switch(symbol) {
				case AND: return 62;
				case DIV: return 62;
				case DOT: return 62;
				case EAGER_AND: return 62;
				case EAGER_OR: return 62;
				case EQ: return 62;
				case GEQ: return 62;
				case GT: return 62;
				case INSTANCEOF: return 62;
				case LBRACKET: return 62;
				case LEQ: return 62;
				case LT: return 62;
				case MINUS: return 62;
				case MULT: return 62;
				case NEQ: return 62;
				case OR: return 62;
				case PLUS: return 62;
				case REMAINDER: return 62;
				case RPAREN: return 62;
				case XOR: return 62;
			}
			break;
		case 1302:
			switch(symbol) {
				case AND: return 2;
				case ASSIGN: return 2;
				case DIV: return 2;
				case DOT: return 2;
				case EAGER_AND: return 2;
				case EAGER_OR: return 2;
				case EQ: return 2;
				case GEQ: return 2;
				case GT: return 2;
				case LBRACKET: return 2;
				case LEQ: return 2;
				case LPAREN: return 2;
				case LT: return 2;
				case MINUS: return 2;
				case MULT: return 2;
				case NEQ: return 2;
				case OR: return 2;
				case PLUS: return 2;
				case RBRACKET: return 2;
				case REMAINDER: return 2;
				case XOR: return 2;
			}
			break;
		case 1303:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case RPAREN: return 63;
			}
			break;
		case 1304:
			switch(symbol) {
				case AND: return 42;
				case ASSIGN: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case REMAINDER: return 42;
				case SEMICOLON: return 42;
				case XOR: return 42;
			}
			break;
		case 1307:
			switch(symbol) {
				case SEMICOLON: return 35;
			}
			break;
		case 1308:
			switch(symbol) {
				case AND: return 69;
				case ASSIGN: return 69;
				case COMMA: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case INSTANCEOF: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case RPAREN: return 69;
				case XOR: return 69;
			}
			break;
		case 1310:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case COMMA: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case REMAINDER: return 55;
				case RPAREN: return 55;
				case XOR: return 55;
			}
			break;
		case 1312:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case SEMICOLON: return 63;
			}
			break;
		case 1313:
			switch(symbol) {
				case AND: return 69;
				case ASSIGN: return 69;
				case DIV: return 69;
				case DOT: return 69;
				case EAGER_AND: return 69;
				case EAGER_OR: return 69;
				case EQ: return 69;
				case GEQ: return 69;
				case GT: return 69;
				case INSTANCEOF: return 69;
				case LBRACKET: return 69;
				case LEQ: return 69;
				case LT: return 69;
				case MINUS: return 69;
				case MULT: return 69;
				case NEQ: return 69;
				case OR: return 69;
				case PLUS: return 69;
				case REMAINDER: return 69;
				case RPAREN: return 69;
				case XOR: return 69;
			}
			break;
	}
	return -1;
}