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
	std::make_pair(EXPRESSION3, std::vector<unsigned int>{PRIMARY, SELECTORS_OPT}),
	std::make_pair(EXPRESSION_LIST, std::vector<unsigned int>{EXPRESSION}),
	std::make_pair(EXPRESSION_LIST, std::vector<unsigned int>{EXPRESSION_LIST, COMMA, EXPRESSION}),
	std::make_pair(EXPRESSION_OPT, std::vector<unsigned int>{EXPRESSION}),
	std::make_pair(EXPRESSION_OPT, std::vector<unsigned int>{}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{LPAREN, EXPRESSION, RPAREN}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{THIS}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{LITERAL}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{NEW, CREATOR}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{ID}),
	std::make_pair(SELECTORS_OPT, std::vector<unsigned int>{DOT, LONG_IDENTIFIER, SELECTORS}),
	std::make_pair(SELECTORS_OPT, std::vector<unsigned int>{DOT, LONG_IDENTIFIER}),
	std::make_pair(SELECTORS_OPT, std::vector<unsigned int>{}),
	std::make_pair(SELECTORS, std::vector<unsigned int>{SELECTOR}),
	std::make_pair(SELECTORS, std::vector<unsigned int>{SELECTORS, SELECTOR}),
	std::make_pair(SELECTORS, std::vector<unsigned int>{SELECTORS, DOT, ID}),
	std::make_pair(SELECTOR, std::vector<unsigned int>{ARGUMENTS}),
	std::make_pair(SELECTOR, std::vector<unsigned int>{LBRACKET, EXPRESSION, RBRACKET}),
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
	std::make_pair(LOCAL_VARIABLE_DECLARATION_STATEMENT, std::vector<unsigned int>{TYPE, VARIABLE_DECLARATOR, SEMICOLON}),
	std::make_pair(STATEMENT, std::vector<unsigned int>{BLOCK}),
	std::make_pair(STATEMENT, std::vector<unsigned int>{IF, PAR_EXPRESSION, STATEMENT}),
	std::make_pair(STATEMENT, std::vector<unsigned int>{IF, PAR_EXPRESSION, STATEMENT, ELSE, STATEMENT}),
	std::make_pair(STATEMENT, std::vector<unsigned int>{FOR, LPAREN, FOR_INIT_OPT, SEMICOLON, EXPRESSION_OPT, SEMICOLON, FOR_UPDATE_OPT, RPAREN, STATEMENT}),
	std::make_pair(STATEMENT, std::vector<unsigned int>{WHILE, PAR_EXPRESSION, STATEMENT}),
	std::make_pair(STATEMENT, std::vector<unsigned int>{RETURN, SEMICOLON}),
	std::make_pair(STATEMENT, std::vector<unsigned int>{RETURN, EXPRESSION, SEMICOLON}),
	std::make_pair(STATEMENT, std::vector<unsigned int>{SEMICOLON}),
	std::make_pair(STATEMENT, std::vector<unsigned int>{STATEMENT_EXPRESSION, SEMICOLON}),
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
	std::make_pair(FORMAL_PARAMETERS, std::vector<unsigned int>{LPAREN, FORMAL_PARAMETER_LIST, RPAREN}),
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
				case START_TERMINAL: return 1128;
			}
			break;
		case 3:
			switch(symbol) {
				case BOOLEAN_LIT: return 68;
				case CHAR_LIT: return 435;
				case EXPRESSION2: return 1103;
				case EXPRESSION3: return 575;
				case ID: return 350;
				case INT_LIT: return 415;
				case LITERAL: return 98;
				case LPAREN: return 261;
				case MINUS: return 290;
				case NEW: return 102;
				case NOT: return 3;
				case NULL_LIT: return 5;
				case PRIMARY: return 234;
				case STRING_LIT: return 311;
				case THIS: return 371;
			}
			break;
		case 4:
			switch(symbol) {
				case ARRAY: return 741;
				case DOT: return 498;
			}
			break;
		case 6:
			switch(symbol) {
				case BASIC_TYPE: return 1096;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 975;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 10:
			switch(symbol) {
				case CREATOR: return 772;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 434;
			}
			break;
		case 11:
			switch(symbol) {
				case BOOLEAN_LIT: return 219;
				case CHAR_LIT: return 73;
				case EXPRESSION2: return 338;
				case EXPRESSION3: return 35;
				case ID: return 483;
				case INT_LIT: return 386;
				case LITERAL: return 280;
				case LPAREN: return 87;
				case MINUS: return 11;
				case NEW: return 292;
				case NOT: return 281;
				case NULL_LIT: return 29;
				case PRIMARY: return 192;
				case STRING_LIT: return 287;
				case THIS: return 83;
			}
			break;
		case 12:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 1043;
				case CLASS_CREATOR_REST: return 319;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 13:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 1016;
				case CLASS_CREATOR_REST: return 457;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 14:
			switch(symbol) {
				case BOOLEAN_LIT: return 237;
				case CHAR_LIT: return 157;
				case EXPRESSION2: return 971;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 17:
			switch(symbol) {
				case BOOLEAN_LIT: return 602;
				case CHAR_LIT: return 314;
				case EXPRESSION2: return 634;
				case EXPRESSION3: return 163;
				case ID: return 806;
				case INT_LIT: return 209;
				case LITERAL: return 268;
				case LPAREN: return 78;
				case MINUS: return 117;
				case NEW: return 375;
				case NOT: return 398;
				case NULL_LIT: return 503;
				case PRIMARY: return 357;
				case STRING_LIT: return 394;
				case THIS: return 239;
			}
			break;
		case 20:
			switch(symbol) {
				case CREATOR: return 151;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 526;
			}
			break;
		case 21:
			switch(symbol) {
				case CREATOR: return 763;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 442;
			}
			break;
		case 30:
			switch(symbol) {
				case ABSTRACT: return 144;
				case FINAL: return 1;
				case MODIFIER: return 911;
				case NATIVE: return 181;
				case PROTECTED: return 492;
				case PUBLIC: return 470;
				case STATIC: return 91;
			}
			break;
		case 32:
			switch(symbol) {
				case RBRACKET: return 713;
			}
			break;
		case 33:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION2: return 1015;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 34:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION2: return 1041;
				case EXPRESSION3: return 64;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 38:
			switch(symbol) {
				case BOOLEAN_LIT: return 237;
				case CHAR_LIT: return 157;
				case EXPRESSION2: return 659;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 40:
			switch(symbol) {
				case CREATOR: return 1118;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 1003;
			}
			break;
		case 41:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 1135;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 1048;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 42:
			switch(symbol) {
				case ID: return 236;
				case LONG_IDENTIFIER: return 1017;
			}
			break;
		case 44:
			switch(symbol) {
				case DOT: return 608;
				case SELECTORS_OPT: return 850;
			}
			break;
		case 47:
			switch(symbol) {
				case BOOLEAN_LIT: return 54;
				case CHAR_LIT: return 170;
				case EXPRESSION2: return 1131;
				case EXPRESSION3: return 300;
				case ID: return 267;
				case INT_LIT: return 745;
				case LITERAL: return 318;
				case LPAREN: return 514;
				case MINUS: return 845;
				case NEW: return 10;
				case NOT: return 47;
				case NULL_LIT: return 359;
				case PRIMARY: return 356;
				case STRING_LIT: return 159;
				case THIS: return 53;
			}
			break;
		case 48:
			switch(symbol) {
				case RPAREN: return 215;
			}
			break;
		case 52:
			switch(symbol) {
				case ARRAY: return 842;
			}
			break;
		case 57:
			switch(symbol) {
				case ID: return 1133;
				case LONG_IDENTIFIER: return 774;
			}
			break;
		case 58:
			switch(symbol) {
				case BASIC_TYPE: return 211;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 330;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 59:
			switch(symbol) {
				case BASIC_TYPE: return 737;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 351;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 60:
			switch(symbol) {
				case DOT: return 231;
			}
			break;
		case 62:
			switch(symbol) {
				case ASSIGN: return 791;
				case ASSIGN_OP: return 305;
			}
			break;
		case 63:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case EXPRESSION1_REST: return 464;
				case EXPRESSION_INFIX: return 677;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 980;
				case INSTANCEOF: return 715;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 66:
			switch(symbol) {
				case IMPORT: return 189;
				case IMPORT_DECLARATION: return 869;
				case IMPORT_DECLARATIONS: return 653;
				case IMPORT_DECLARATIONS_OPT: return 125;
			}
			break;
		case 71:
			switch(symbol) {
				case DOT: return 42;
				case SELECTORS_OPT: return 376;
			}
			break;
		case 74:
			switch(symbol) {
				case ARGUMENTS: return 79;
				case DOT: return 831;
				case LBRACKET: return 781;
				case LPAREN: return 368;
				case SELECTOR: return 864;
			}
			break;
		case 75:
			switch(symbol) {
				case CREATOR: return 500;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 819;
			}
			break;
		case 76:
			switch(symbol) {
				case RPAREN: return 128;
			}
			break;
		case 78:
			switch(symbol) {
				case BASIC_TYPE: return 860;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 776;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 80:
			switch(symbol) {
				case ASSIGN: return 791;
				case ASSIGN_OP: return 664;
			}
			break;
		case 81:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case EXPRESSION1_REST: return 1125;
				case EXPRESSION_INFIX: return 990;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 670;
				case INSTANCEOF: return 910;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 87:
			switch(symbol) {
				case BASIC_TYPE: return 585;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 103;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 88:
			switch(symbol) {
				case BOOLEAN_LIT: return 54;
				case CHAR_LIT: return 170;
				case EXPRESSION3: return 466;
				case ID: return 267;
				case INT_LIT: return 745;
				case LITERAL: return 318;
				case LPAREN: return 514;
				case NEW: return 10;
				case NOT: return 47;
				case NULL_LIT: return 359;
				case PRIMARY: return 356;
				case STRING_LIT: return 159;
				case THIS: return 53;
			}
			break;
		case 90:
			switch(symbol) {
				case BASIC_TYPE: return 857;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 556;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 92:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case EXPRESSION1_REST: return 341;
				case EXPRESSION_INFIX: return 736;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 778;
				case INSTANCEOF: return 632;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 94:
			switch(symbol) {
				case ASSIGN: return 791;
				case ASSIGN_OP: return 548;
			}
			break;
		case 97:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 272;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 101:
			switch(symbol) {
				case ID: return 202;
				case LONG_IDENTIFIER: return 1097;
			}
			break;
		case 102:
			switch(symbol) {
				case CREATOR: return 743;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 364;
			}
			break;
		case 103:
			switch(symbol) {
				case RPAREN: return 883;
			}
			break;
		case 107:
			switch(symbol) {
				case CLASS_BODY: return 241;
				case LBRACE: return 496;
			}
			break;
		case 108:
			switch(symbol) {
				case ARGUMENTS: return 866;
				case DOT: return 605;
				case LBRACKET: return 732;
				case LPAREN: return 471;
				case SELECTOR: return 1156;
				case SELECTORS: return 1149;
			}
			break;
		case 113:
			switch(symbol) {
				case ID: return 847;
			}
			break;
		case 115:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION2: return 920;
				case EXPRESSION3: return 64;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 117:
			switch(symbol) {
				case BOOLEAN_LIT: return 602;
				case CHAR_LIT: return 314;
				case EXPRESSION2: return 482;
				case EXPRESSION3: return 163;
				case ID: return 806;
				case INT_LIT: return 209;
				case LITERAL: return 268;
				case LPAREN: return 78;
				case MINUS: return 117;
				case NEW: return 375;
				case NOT: return 398;
				case NULL_LIT: return 503;
				case PRIMARY: return 357;
				case STRING_LIT: return 394;
				case THIS: return 239;
			}
			break;
		case 121:
			switch(symbol) {
				case ARGUMENTS: return 220;
				case DOT: return 936;
				case LBRACKET: return 800;
				case LPAREN: return 402;
				case SELECTOR: return 577;
			}
			break;
		case 122:
			switch(symbol) {
				case BOOLEAN_LIT: return 381;
				case CHAR_LIT: return 507;
				case EXPRESSION3: return 358;
				case ID: return 502;
				case INT_LIT: return 61;
				case LITERAL: return 462;
				case LPAREN: return 6;
				case NEW: return 196;
				case NOT: return 169;
				case NULL_LIT: return 84;
				case PRIMARY: return 504;
				case STRING_LIT: return 635;
				case THIS: return 668;
			}
			break;
		case 123:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 1166;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 1066;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 124:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 827;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 125:
			switch(symbol) {
				case ABSTRACT: return 716;
				case CLASS_OR_INTERFACE_DECLARATION: return 491;
				case FINAL: return 702;
				case MODIFIER: return 578;
				case MODIFIERS: return 889;
				case MODIFIERS_OPT: return 393;
				case NATIVE: return 638;
				case PROTECTED: return 255;
				case PUBLIC: return 380;
				case SEMICOLON: return 568;
				case STATIC: return 126;
				case TYPE_DECLARATION: return 538;
				case TYPE_DECLARATIONS_OPT: return 8;
			}
			break;
		case 131:
			switch(symbol) {
				case BOOLEAN_LIT: return 366;
				case CHAR_LIT: return 345;
				case EXPRESSION2: return 469;
				case EXPRESSION3: return 186;
				case ID: return 282;
				case INT_LIT: return 161;
				case LITERAL: return 166;
				case LPAREN: return 90;
				case MINUS: return 131;
				case NEW: return 333;
				case NOT: return 312;
				case NULL_LIT: return 177;
				case PRIMARY: return 194;
				case STRING_LIT: return 547;
				case THIS: return 396;
			}
			break;
		case 134:
			switch(symbol) {
				case DOT: return 839;
				case SELECTORS_OPT: return 1094;
			}
			break;
		case 138:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION2: return 554;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 141:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 389;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 719;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 148:
			switch(symbol) {
				case BOOLEAN_LIT: return 508;
				case CHAR_LIT: return 184;
				case EXPRESSION3: return 885;
				case ID: return 288;
				case INT_LIT: return 256;
				case LITERAL: return 515;
				case LPAREN: return 690;
				case NEW: return 227;
				case NOT: return 235;
				case NULL_LIT: return 408;
				case PRIMARY: return 569;
				case STRING_LIT: return 535;
				case THIS: return 70;
			}
			break;
		case 155:
			switch(symbol) {
				case BASIC_TYPE: return 48;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 1105;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 156:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 460;
				case CLASS_CREATOR_REST: return 433;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 158:
			switch(symbol) {
				case ID: return 919;
			}
			break;
		case 160:
			switch(symbol) {
				case RBRACKET: return 590;
			}
			break;
		case 167:
			switch(symbol) {
				case ID: return 1088;
			}
			break;
		case 169:
			switch(symbol) {
				case BOOLEAN_LIT: return 381;
				case CHAR_LIT: return 507;
				case EXPRESSION2: return 445;
				case EXPRESSION3: return 446;
				case ID: return 502;
				case INT_LIT: return 61;
				case LITERAL: return 462;
				case LPAREN: return 6;
				case MINUS: return 313;
				case NEW: return 196;
				case NOT: return 169;
				case NULL_LIT: return 84;
				case PRIMARY: return 504;
				case STRING_LIT: return 635;
				case THIS: return 668;
			}
			break;
		case 178:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION2: return 955;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 179:
			switch(symbol) {
				case RPAREN: return 539;
			}
			break;
		case 180:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 1065;
			}
			break;
		case 182:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 509;
				case CLASS_CREATOR_REST: return 760;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 183:
			switch(symbol) {
				case ID: return 626;
				case LONG_IDENTIFIER: return 1008;
			}
			break;
		case 187:
			switch(symbol) {
				case DOT: return 915;
				case SELECTORS_OPT: return 725;
			}
			break;
		case 188:
			switch(symbol) {
				case BASIC_TYPE: return 897;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 1034;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 189:
			switch(symbol) {
				case ID: return 746;
				case LONG_IDENTIFIER: return 822;
			}
			break;
		case 192:
			switch(symbol) {
				case DOT: return 938;
				case SELECTORS_OPT: return 705;
			}
			break;
		case 193:
			switch(symbol) {
				case RPAREN: return 813;
			}
			break;
		case 194:
			switch(symbol) {
				case DOT: return 994;
				case SELECTORS_OPT: return 1153;
			}
			break;
		case 195:
			switch(symbol) {
				case ID: return 1124;
			}
			break;
		case 196:
			switch(symbol) {
				case CREATOR: return 721;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 465;
			}
			break;
		case 198:
			switch(symbol) {
				case CONSTRUCTOR_DECLARATOR_REST: return 1058;
				case FORMAL_PARAMETERS: return 796;
				case LPAREN: return 924;
			}
			break;
		case 199:
			switch(symbol) {
				case ID: return 259;
			}
			break;
		case 200:
			switch(symbol) {
				case LPAREN: return 182;
			}
			break;
		case 201:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 119;
				case EXPRESSION2: return 960;
				case EXPRESSION3: return 424;
				case ID: return 455;
				case INT_LIT: return 336;
				case LITERAL: return 7;
				case LPAREN: return 155;
				case MINUS: return 201;
				case NEW: return 21;
				case NOT: return 208;
				case NULL_LIT: return 229;
				case PRIMARY: return 431;
				case STRING_LIT: return 315;
				case THIS: return 132;
			}
			break;
		case 207:
			switch(symbol) {
				case BASIC_TYPE: return 525;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 271;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 208:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 119;
				case EXPRESSION2: return 553;
				case EXPRESSION3: return 424;
				case ID: return 455;
				case INT_LIT: return 336;
				case LITERAL: return 7;
				case LPAREN: return 155;
				case MINUS: return 201;
				case NEW: return 21;
				case NOT: return 208;
				case NULL_LIT: return 229;
				case PRIMARY: return 431;
				case STRING_LIT: return 315;
				case THIS: return 132;
			}
			break;
		case 211:
			switch(symbol) {
				case RPAREN: return 1045;
			}
			break;
		case 212:
			switch(symbol) {
				case DOT: return 101;
				case SELECTORS_OPT: return 641;
			}
			break;
		case 214:
			switch(symbol) {
				case RPAREN: return 671;
			}
			break;
		case 215:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 119;
				case EXPRESSION2: return 685;
				case EXPRESSION3: return 424;
				case ID: return 455;
				case INT_LIT: return 336;
				case LITERAL: return 7;
				case LPAREN: return 155;
				case MINUS: return 201;
				case NEW: return 21;
				case NOT: return 208;
				case NULL_LIT: return 229;
				case PRIMARY: return 431;
				case STRING_LIT: return 315;
				case THIS: return 132;
			}
			break;
		case 216:
			switch(symbol) {
				case BOOLEAN_LIT: return 461;
				case CHAR_LIT: return 96;
				case EXPRESSION2: return 898;
				case EXPRESSION3: return 246;
				case ID: return 298;
				case INT_LIT: return 360;
				case LITERAL: return 205;
				case LPAREN: return 698;
				case MINUS: return 747;
				case NEW: return 247;
				case NOT: return 216;
				case NULL_LIT: return 522;
				case PRIMARY: return 678;
				case STRING_LIT: return 523;
				case THIS: return 146;
			}
			break;
		case 217:
			switch(symbol) {
				case BASIC_TYPE: return 749;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 413;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 226:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 414;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 227:
			switch(symbol) {
				case CREATOR: return 1136;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 867;
			}
			break;
		case 231:
			switch(symbol) {
				case ID: return 966;
			}
			break;
		case 234:
			switch(symbol) {
				case DOT: return 901;
				case SELECTORS_OPT: return 1119;
			}
			break;
		case 235:
			switch(symbol) {
				case BOOLEAN_LIT: return 508;
				case CHAR_LIT: return 184;
				case EXPRESSION2: return 419;
				case EXPRESSION3: return 111;
				case ID: return 288;
				case INT_LIT: return 256;
				case LITERAL: return 515;
				case LPAREN: return 690;
				case MINUS: return 672;
				case NEW: return 227;
				case NOT: return 235;
				case NULL_LIT: return 408;
				case PRIMARY: return 569;
				case STRING_LIT: return 535;
				case THIS: return 70;
			}
			break;
		case 243:
			switch(symbol) {
				case RPAREN: return 689;
			}
			break;
		case 244:
			switch(symbol) {
				case ASSIGN: return 791;
				case ASSIGN_OP: return 369;
			}
			break;
		case 245:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case EXPRESSION1_REST: return 1162;
				case EXPRESSION_INFIX: return 989;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 711;
				case INSTANCEOF: return 871;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 247:
			switch(symbol) {
				case CREATOR: return 1007;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 200;
			}
			break;
		case 248:
			switch(symbol) {
				case RPAREN: return 494;
			}
			break;
		case 249:
			switch(symbol) {
				case ARGUMENTS: return 963;
				case DOT: return 270;
				case LBRACKET: return 739;
				case LPAREN: return 429;
				case SELECTOR: return 1138;
			}
			break;
		case 251:
			switch(symbol) {
				case BOOLEAN_LIT: return 197;
				case CHAR_LIT: return 228;
				case EXPRESSION2: return 799;
				case EXPRESSION3: return 340;
				case ID: return 56;
				case INT_LIT: return 162;
				case LITERAL: return 463;
				case LPAREN: return 217;
				case MINUS: return 299;
				case NEW: return 274;
				case NOT: return 260;
				case NULL_LIT: return 31;
				case PRIMARY: return 334;
				case STRING_LIT: return 221;
				case THIS: return 254;
			}
			break;
		case 258:
			switch(symbol) {
				case BOOLEAN_LIT: return 86;
				case CHAR_LIT: return 758;
				case EXPRESSION2: return 1037;
				case EXPRESSION3: return 516;
				case ID: return 417;
				case INT_LIT: return 335;
				case LITERAL: return 225;
				case LPAREN: return 58;
				case MINUS: return 258;
				case NEW: return 712;
				case NOT: return 663;
				case NULL_LIT: return 560;
				case PRIMARY: return 44;
				case STRING_LIT: return 171;
				case THIS: return 453;
			}
			break;
		case 260:
			switch(symbol) {
				case BOOLEAN_LIT: return 197;
				case CHAR_LIT: return 228;
				case EXPRESSION2: return 378;
				case EXPRESSION3: return 340;
				case ID: return 56;
				case INT_LIT: return 162;
				case LITERAL: return 463;
				case LPAREN: return 217;
				case MINUS: return 299;
				case NEW: return 274;
				case NOT: return 260;
				case NULL_LIT: return 31;
				case PRIMARY: return 334;
				case STRING_LIT: return 221;
				case THIS: return 254;
			}
			break;
		case 261:
			switch(symbol) {
				case BASIC_TYPE: return 479;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 179;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 262:
			switch(symbol) {
				case DOT: return 183;
				case SELECTORS_OPT: return 409;
			}
			break;
		case 264:
			switch(symbol) {
				case CLASS_BODY: return 152;
				case COMMA: return 405;
				case LBRACE: return 561;
			}
			break;
		case 266:
			switch(symbol) {
				case SEMICOLON: return 777;
			}
			break;
		case 269:
			switch(symbol) {
				case RBRACKET: return 780;
			}
			break;
		case 270:
			switch(symbol) {
				case ID: return 1159;
			}
			break;
		case 271:
			switch(symbol) {
				case RPAREN: return 661;
			}
			break;
		case 272:
			switch(symbol) {
				case RBRACKET: return 820;
			}
			break;
		case 273:
			switch(symbol) {
				case RPAREN: return 88;
			}
			break;
		case 274:
			switch(symbol) {
				case CREATOR: return 684;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 931;
			}
			break;
		case 277:
			switch(symbol) {
				case BASIC_TYPE: return 52;
				case BLOCK_STATEMENT: return 230;
				case BOOLEAN: return 223;
				case BYTE: return 210;
				case CHAR: return 65;
				case ID: return 564;
				case INT: return 331;
				case LOCAL_VARIABLE_DECLARATION_STATEMENT: return 618;
				case LONG_IDENTIFIER: return 4;
				case SHORT: return 304;
				case TYPE: return 811;
			}
			break;
		case 281:
			switch(symbol) {
				case BOOLEAN_LIT: return 219;
				case CHAR_LIT: return 73;
				case EXPRESSION2: return 36;
				case EXPRESSION3: return 35;
				case ID: return 483;
				case INT_LIT: return 386;
				case LITERAL: return 280;
				case LPAREN: return 87;
				case MINUS: return 11;
				case NEW: return 292;
				case NOT: return 281;
				case NULL_LIT: return 29;
				case PRIMARY: return 192;
				case STRING_LIT: return 287;
				case THIS: return 83;
			}
			break;
		case 290:
			switch(symbol) {
				case BOOLEAN_LIT: return 68;
				case CHAR_LIT: return 435;
				case EXPRESSION2: return 1009;
				case EXPRESSION3: return 575;
				case ID: return 350;
				case INT_LIT: return 415;
				case LITERAL: return 98;
				case LPAREN: return 261;
				case MINUS: return 290;
				case NEW: return 102;
				case NOT: return 3;
				case NULL_LIT: return 5;
				case PRIMARY: return 234;
				case STRING_LIT: return 311;
				case THIS: return 371;
			}
			break;
		case 292:
			switch(symbol) {
				case CREATOR: return 1092;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 436;
			}
			break;
		case 293:
			switch(symbol) {
				case ID: return 1091;
			}
			break;
		case 294:
			switch(symbol) {
				case RBRACKET: return 329;
			}
			break;
		case 296:
			switch(symbol) {
				case BOOLEAN_LIT: return 602;
				case CHAR_LIT: return 314;
				case EXPRESSION3: return 543;
				case ID: return 806;
				case INT_LIT: return 209;
				case LITERAL: return 268;
				case LPAREN: return 78;
				case NEW: return 375;
				case NOT: return 398;
				case NULL_LIT: return 503;
				case PRIMARY: return 357;
				case STRING_LIT: return 394;
				case THIS: return 239;
			}
			break;
		case 299:
			switch(symbol) {
				case BOOLEAN_LIT: return 197;
				case CHAR_LIT: return 228;
				case EXPRESSION2: return 1129;
				case EXPRESSION3: return 340;
				case ID: return 56;
				case INT_LIT: return 162;
				case LITERAL: return 463;
				case LPAREN: return 217;
				case MINUS: return 299;
				case NEW: return 274;
				case NOT: return 260;
				case NULL_LIT: return 31;
				case PRIMARY: return 334;
				case STRING_LIT: return 221;
				case THIS: return 254;
			}
			break;
		case 302:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case EXPRESSION1_REST: return 1079;
				case EXPRESSION_INFIX: return 1054;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 730;
				case INSTANCEOF: return 349;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 305:
			switch(symbol) {
				case BOOLEAN_LIT: return 68;
				case CHAR_LIT: return 435;
				case EXPRESSION1: return 576;
				case EXPRESSION2: return 574;
				case EXPRESSION3: return 575;
				case ID: return 350;
				case INT_LIT: return 415;
				case LITERAL: return 98;
				case LPAREN: return 261;
				case MINUS: return 290;
				case NEW: return 102;
				case NOT: return 3;
				case NULL_LIT: return 5;
				case PRIMARY: return 234;
				case STRING_LIT: return 311;
				case THIS: return 371;
			}
			break;
		case 307:
			switch(symbol) {
				case ARGUMENTS: return 220;
				case DOT: return 1140;
				case LBRACKET: return 800;
				case LPAREN: return 402;
				case SELECTOR: return 589;
				case SELECTORS: return 121;
			}
			break;
		case 308:
			switch(symbol) {
				case ID: return 136;
			}
			break;
		case 312:
			switch(symbol) {
				case BOOLEAN_LIT: return 366;
				case CHAR_LIT: return 345;
				case EXPRESSION2: return 982;
				case EXPRESSION3: return 186;
				case ID: return 282;
				case INT_LIT: return 161;
				case LITERAL: return 166;
				case LPAREN: return 90;
				case MINUS: return 131;
				case NEW: return 333;
				case NOT: return 312;
				case NULL_LIT: return 177;
				case PRIMARY: return 194;
				case STRING_LIT: return 547;
				case THIS: return 396;
			}
			break;
		case 313:
			switch(symbol) {
				case BOOLEAN_LIT: return 381;
				case CHAR_LIT: return 507;
				case EXPRESSION2: return 573;
				case EXPRESSION3: return 446;
				case ID: return 502;
				case INT_LIT: return 61;
				case LITERAL: return 462;
				case LPAREN: return 6;
				case MINUS: return 313;
				case NEW: return 196;
				case NOT: return 169;
				case NULL_LIT: return 84;
				case PRIMARY: return 504;
				case STRING_LIT: return 635;
				case THIS: return 668;
			}
			break;
		case 317:
			switch(symbol) {
				case RPAREN: return 640;
			}
			break;
		case 319:
			switch(symbol) {
				case RPAREN: return 562;
			}
			break;
		case 324:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case EXPRESSION1_REST: return 987;
				case EXPRESSION_INFIX: return 929;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 688;
				case INSTANCEOF: return 537;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 330:
			switch(symbol) {
				case RPAREN: return 1056;
			}
			break;
		case 332:
			switch(symbol) {
				case RBRACKET: return 505;
			}
			break;
		case 333:
			switch(symbol) {
				case CREATOR: return 443;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 754;
			}
			break;
		case 334:
			switch(symbol) {
				case DOT: return 591;
				case SELECTORS_OPT: return 652;
			}
			break;
		case 337:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 1112;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 346:
			switch(symbol) {
				case ARRAY: return 598;
				case DOT: return 631;
			}
			break;
		case 347:
			switch(symbol) {
				case BASIC_TYPE: return 667;
				case BOOLEAN: return 276;
				case BYTE: return 1098;
				case CHAR: return 795;
				case ID: return 779;
				case INT: return 694;
				case LONG_IDENTIFIER: return 346;
				case SHORT: return 707;
				case TYPE: return 817;
			}
			break;
		case 348:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 1077;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 349:
			switch(symbol) {
				case BASIC_TYPE: return 834;
				case BOOLEAN: return 1150;
				case BYTE: return 600;
				case CHAR: return 997;
				case ID: return 949;
				case INT: return 1093;
				case LONG_IDENTIFIER: return 1076;
				case SHORT: return 1018;
				case TYPE: return 969;
			}
			break;
		case 351:
			switch(symbol) {
				case RPAREN: return 930;
			}
			break;
		case 356:
			switch(symbol) {
				case DOT: return 604;
				case SELECTORS_OPT: return 658;
			}
			break;
		case 357:
			switch(symbol) {
				case DOT: return 1057;
				case SELECTORS_OPT: return 1070;
			}
			break;
		case 364:
			switch(symbol) {
				case LPAREN: return 12;
			}
			break;
		case 365:
			switch(symbol) {
				case BOOLEAN_LIT: return 461;
				case CHAR_LIT: return 96;
				case EXPRESSION3: return 918;
				case ID: return 298;
				case INT_LIT: return 360;
				case LITERAL: return 205;
				case LPAREN: return 698;
				case NEW: return 247;
				case NOT: return 216;
				case NULL_LIT: return 522;
				case PRIMARY: return 678;
				case STRING_LIT: return 523;
				case THIS: return 146;
			}
			break;
		case 368:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 1099;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 986;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 369:
			switch(symbol) {
				case BOOLEAN_LIT: return 328;
				case CHAR_LIT: return 93;
				case EXPRESSION1: return 1032;
				case EXPRESSION2: return 1031;
				case EXPRESSION3: return 326;
				case ID: return 118;
				case INT_LIT: return 629;
				case LITERAL: return 607;
				case LPAREN: return 428;
				case MINUS: return 444;
				case NEW: return 458;
				case NOT: return 476;
				case NULL_LIT: return 441;
				case PRIMARY: return 134;
				case STRING_LIT: return 263;
				case THIS: return 168;
			}
			break;
		case 375:
			switch(symbol) {
				case CREATOR: return 928;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 1169;
			}
			break;
		case 382:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 596;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 387:
			switch(symbol) {
				case ARGUMENTS: return 410;
				case DOT: return 759;
				case LBRACKET: return 382;
				case LPAREN: return 123;
				case SELECTOR: return 1144;
			}
			break;
		case 389:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 363;
			}
			break;
		case 390:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 724;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 353;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 393:
			switch(symbol) {
				case CLASS: return 717;
				case CLASS_DECLARATION: return 532;
				case INTERFACE: return 616;
				case INTERFACE_DECLARATION: return 533;
			}
			break;
		case 395:
			switch(symbol) {
				case ARRAY: return 706;
			}
			break;
		case 398:
			switch(symbol) {
				case BOOLEAN_LIT: return 602;
				case CHAR_LIT: return 314;
				case EXPRESSION2: return 165;
				case EXPRESSION3: return 163;
				case ID: return 806;
				case INT_LIT: return 209;
				case LITERAL: return 268;
				case LPAREN: return 78;
				case MINUS: return 117;
				case NEW: return 375;
				case NOT: return 398;
				case NULL_LIT: return 503;
				case PRIMARY: return 357;
				case STRING_LIT: return 394;
				case THIS: return 239;
			}
			break;
		case 401:
			switch(symbol) {
				case RPAREN: return 478;
			}
			break;
		case 402:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 804;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 903;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 403:
			switch(symbol) {
				case BOOLEAN_LIT: return 508;
				case CHAR_LIT: return 184;
				case EXPRESSION2: return 594;
				case EXPRESSION3: return 111;
				case ID: return 288;
				case INT_LIT: return 256;
				case LITERAL: return 515;
				case LPAREN: return 690;
				case MINUS: return 672;
				case NEW: return 227;
				case NOT: return 235;
				case NULL_LIT: return 408;
				case PRIMARY: return 569;
				case STRING_LIT: return 535;
				case THIS: return 70;
			}
			break;
		case 405:
			switch(symbol) {
				case BASIC_TYPE: return 395;
				case BOOLEAN: return 932;
				case BYTE: return 399;
				case CHAR: return 224;
				case ID: return 172;
				case INT: return 39;
				case LONG_IDENTIFIER: return 650;
				case SHORT: return 279;
				case TYPE: return 383;
			}
			break;
		case 406:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 1061;
				case CLASS_CREATOR_REST: return 248;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 407:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 995;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 413:
			switch(symbol) {
				case RPAREN: return 814;
			}
			break;
		case 416:
			switch(symbol) {
				case BASIC_TYPE: return 1013;
				case BOOLEAN: return 257;
				case BYTE: return 404;
				case CHAR: return 916;
				case ID: return 793;
				case INT: return 1027;
				case LONG_IDENTIFIER: return 1143;
				case SHORT: return 950;
				case TYPE: return 785;
			}
			break;
		case 418:
			switch(symbol) {
				case ID: return 109;
			}
			break;
		case 420:
			switch(symbol) {
				case ARGUMENTS: return 649;
				case DOT: return 480;
				case LBRACKET: return 348;
				case LPAREN: return 879;
				case SELECTOR: return 1069;
				case SELECTORS: return 810;
			}
			break;
		case 421:
			switch(symbol) {
				case BASIC_TYPE: return 52;
				case BOOLEAN: return 223;
				case BYTE: return 210;
				case CHAR: return 65;
				case FORMAL_PARAMETER: return 142;
				case FORMAL_PARAMETER_LIST: return 925;
				case ID: return 564;
				case INT: return 331;
				case LONG_IDENTIFIER: return 4;
				case SHORT: return 304;
				case TYPE: return 495;
			}
			break;
		case 426:
			switch(symbol) {
				case BASIC_TYPE: return 401;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 317;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 427:
			switch(symbol) {
				case ID: return 289;
			}
			break;
		case 428:
			switch(symbol) {
				case BASIC_TYPE: return 1168;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 193;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 429:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 902;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 802;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 431:
			switch(symbol) {
				case DOT: return 697;
				case SELECTORS_OPT: return 952;
			}
			break;
		case 432:
			switch(symbol) {
				case BOOLEAN_LIT: return 367;
				case CHAR_LIT: return 112;
				case EXPRESSION2: return 611;
				case EXPRESSION3: return 309;
				case ID: return 89;
				case INT_LIT: return 18;
				case LITERAL: return 377;
				case LPAREN: return 426;
				case MINUS: return 432;
				case NEW: return 485;
				case NOT: return 474;
				case NULL_LIT: return 173;
				case PRIMARY: return 187;
				case STRING_LIT: return 322;
				case THIS: return 164;
			}
			break;
		case 433:
			switch(symbol) {
				case RPAREN: return 278;
			}
			break;
		case 434:
			switch(symbol) {
				case LPAREN: return 156;
			}
			break;
		case 436:
			switch(symbol) {
				case LPAREN: return 669;
			}
			break;
		case 438:
			switch(symbol) {
				case ARGUMENTS: return 79;
				case DOT: return 906;
				case LBRACKET: return 781;
				case LPAREN: return 368;
				case SELECTOR: return 666;
				case SELECTORS: return 74;
			}
			break;
		case 439:
			switch(symbol) {
				case ARGUMENTS: return 355;
				case DOT: return 981;
				case LBRACKET: return 964;
				case LPAREN: return 41;
				case SELECTOR: return 297;
			}
			break;
		case 442:
			switch(symbol) {
				case LPAREN: return 540;
			}
			break;
		case 444:
			switch(symbol) {
				case BOOLEAN_LIT: return 328;
				case CHAR_LIT: return 93;
				case EXPRESSION2: return 1126;
				case EXPRESSION3: return 326;
				case ID: return 118;
				case INT_LIT: return 629;
				case LITERAL: return 607;
				case LPAREN: return 428;
				case MINUS: return 444;
				case NEW: return 458;
				case NOT: return 476;
				case NULL_LIT: return 441;
				case PRIMARY: return 134;
				case STRING_LIT: return 263;
				case THIS: return 168;
			}
			break;
		case 448:
			switch(symbol) {
				case ABSTRACT: return 144;
				case FINAL: return 1;
				case INTERFACE_BODY_DECLARATION: return 1104;
				case INTERFACE_BODY_DECLARATIONS: return 619;
				case MODIFIER: return 489;
				case MODIFIERS: return 30;
				case MODIFIERS_OPT: return 767;
				case NATIVE: return 181;
				case PROTECTED: return 492;
				case PUBLIC: return 470;
				case RBRACE: return 551;
				case SEMICOLON: return 701;
				case STATIC: return 91;
			}
			break;
		case 450:
			switch(symbol) {
				case RPAREN: return 437;
			}
			break;
		case 456:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 733;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 855;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 457:
			switch(symbol) {
				case RPAREN: return 85;
			}
			break;
		case 458:
			switch(symbol) {
				case CREATOR: return 175;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 1022;
			}
			break;
		case 459:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 680;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 565;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 460:
			switch(symbol) {
				case RPAREN: return 1030;
			}
			break;
		case 465:
			switch(symbol) {
				case LPAREN: return 531;
			}
			break;
		case 467:
			switch(symbol) {
				case RPAREN: return 295;
			}
			break;
		case 468:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 1137;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 471:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 1108;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 775;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 473:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 450;
				case CLASS_CREATOR_REST: return 214;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 474:
			switch(symbol) {
				case BOOLEAN_LIT: return 367;
				case CHAR_LIT: return 112;
				case EXPRESSION2: return 792;
				case EXPRESSION3: return 309;
				case ID: return 89;
				case INT_LIT: return 18;
				case LITERAL: return 377;
				case LPAREN: return 426;
				case MINUS: return 432;
				case NEW: return 485;
				case NOT: return 474;
				case NULL_LIT: return 173;
				case PRIMARY: return 187;
				case STRING_LIT: return 322;
				case THIS: return 164;
			}
			break;
		case 476:
			switch(symbol) {
				case BOOLEAN_LIT: return 328;
				case CHAR_LIT: return 93;
				case EXPRESSION2: return 327;
				case EXPRESSION3: return 326;
				case ID: return 118;
				case INT_LIT: return 629;
				case LITERAL: return 607;
				case LPAREN: return 428;
				case MINUS: return 444;
				case NEW: return 458;
				case NOT: return 476;
				case NULL_LIT: return 441;
				case PRIMARY: return 134;
				case STRING_LIT: return 263;
				case THIS: return 168;
			}
			break;
		case 477:
			switch(symbol) {
				case BASIC_TYPE: return 52;
				case BOOLEAN: return 223;
				case BYTE: return 210;
				case CHAR: return 65;
				case FORMAL_PARAMETER: return 49;
				case ID: return 564;
				case INT: return 331;
				case LONG_IDENTIFIER: return 4;
				case SHORT: return 304;
				case TYPE: return 495;
			}
			break;
		case 478:
			switch(symbol) {
				case BOOLEAN_LIT: return 367;
				case CHAR_LIT: return 112;
				case EXPRESSION2: return 310;
				case EXPRESSION3: return 309;
				case ID: return 89;
				case INT_LIT: return 18;
				case LITERAL: return 377;
				case LPAREN: return 426;
				case MINUS: return 432;
				case NEW: return 485;
				case NOT: return 474;
				case NULL_LIT: return 173;
				case PRIMARY: return 187;
				case STRING_LIT: return 322;
				case THIS: return 164;
			}
			break;
		case 479:
			switch(symbol) {
				case RPAREN: return 1063;
			}
			break;
		case 480:
			switch(symbol) {
				case ID: return 836;
			}
			break;
		case 484:
			switch(symbol) {
				case LPAREN: return 657;
			}
			break;
		case 485:
			switch(symbol) {
				case CREATOR: return 1154;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 484;
			}
			break;
		case 488:
			switch(symbol) {
				case RPAREN: return 1123;
			}
			break;
		case 490:
			switch(symbol) {
				case RPAREN: return 848;
			}
			break;
		case 495:
			switch(symbol) {
				case ID: return 646;
				case VARIABLE_DECLARATOR_ID: return 454;
			}
			break;
		case 496:
			switch(symbol) {
				case ABSTRACT: return 144;
				case CLASS_BODY_DECLARATION: return 748;
				case CLASS_BODY_DECLARATIONS: return 786;
				case FINAL: return 1;
				case MODIFIER: return 489;
				case MODIFIERS: return 30;
				case MODIFIERS_OPT: return 750;
				case NATIVE: return 181;
				case PROTECTED: return 492;
				case PUBLIC: return 470;
				case RBRACE: return 972;
				case SEMICOLON: return 673;
				case STATIC: return 91;
			}
			break;
		case 497:
			switch(symbol) {
				case ARGUMENTS: return 959;
				case DOT: return 293;
				case LBRACKET: return 97;
				case LPAREN: return 456;
				case SELECTOR: return 643;
				case SELECTORS: return 738;
			}
			break;
		case 498:
			switch(symbol) {
				case ID: return 549;
			}
			break;
		case 499:
			switch(symbol) {
				case ARGUMENTS: return 944;
				case DOT: return 984;
				case LBRACKET: return 1082;
				case LPAREN: return 939;
				case SELECTOR: return 708;
				case SELECTORS: return 636;
			}
			break;
		case 504:
			switch(symbol) {
				case DOT: return 927;
				case SELECTORS_OPT: return 784;
			}
			break;
		case 509:
			switch(symbol) {
				case RPAREN: return 765;
			}
			break;
		case 513:
			switch(symbol) {
				case RPAREN: return 674;
			}
			break;
		case 514:
			switch(symbol) {
				case BASIC_TYPE: return 243;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 273;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 517:
			switch(symbol) {
				case ARGUMENTS: return 475;
				case DOT: return 597;
				case LBRACKET: return 468;
				case LPAREN: return 459;
				case SELECTOR: return 1122;
				case SELECTORS: return 1161;
			}
			break;
		case 525:
			switch(symbol) {
				case RPAREN: return 762;
			}
			break;
		case 526:
			switch(symbol) {
				case LPAREN: return 655;
			}
			break;
		case 528:
			switch(symbol) {
				case RPAREN: return 615;
			}
			break;
		case 531:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 937;
				case CLASS_CREATOR_REST: return 1004;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 537:
			switch(symbol) {
				case BASIC_TYPE: return 953;
				case BOOLEAN: return 620;
				case BYTE: return 877;
				case CHAR: return 1010;
				case ID: return 992;
				case INT: return 388;
				case LONG_IDENTIFIER: return 696;
				case SHORT: return 988;
				case TYPE: return 978;
			}
			break;
		case 539:
			switch(symbol) {
				case BOOLEAN_LIT: return 68;
				case CHAR_LIT: return 435;
				case EXPRESSION3: return 343;
				case ID: return 350;
				case INT_LIT: return 415;
				case LITERAL: return 98;
				case LPAREN: return 261;
				case NEW: return 102;
				case NOT: return 3;
				case NULL_LIT: return 5;
				case PRIMARY: return 234;
				case STRING_LIT: return 311;
				case THIS: return 371;
			}
			break;
		case 540:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 833;
				case CLASS_CREATOR_REST: return 983;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 542:
			switch(symbol) {
				case EXTENDS: return 1151;
				case INTERFACE_BODY: return 942;
				case LBRACE: return 448;
			}
			break;
		case 546:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 807;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 681;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 548:
			switch(symbol) {
				case BOOLEAN_LIT: return 367;
				case CHAR_LIT: return 112;
				case EXPRESSION1: return 325;
				case EXPRESSION2: return 324;
				case EXPRESSION3: return 309;
				case ID: return 89;
				case INT_LIT: return 18;
				case LITERAL: return 377;
				case LPAREN: return 426;
				case MINUS: return 432;
				case NEW: return 485;
				case NOT: return 474;
				case NULL_LIT: return 173;
				case PRIMARY: return 187;
				case STRING_LIT: return 322;
				case THIS: return 164;
			}
			break;
		case 552:
			switch(symbol) {
				case BASIC_TYPE: return 720;
				case BOOLEAN: return 756;
				case BYTE: return 1086;
				case CHAR: return 25;
				case ID: return 105;
				case INT: return 744;
				case LONG_IDENTIFIER: return 899;
				case SHORT: return 104;
				case TYPE: return 137;
			}
			break;
		case 555:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 788;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 556:
			switch(symbol) {
				case RPAREN: return 1049;
			}
			break;
		case 558:
			switch(symbol) {
				case RPAREN: return 423;
			}
			break;
		case 561:
			switch(symbol) {
				case ABSTRACT: return 144;
				case CLASS_BODY_DECLARATION: return 748;
				case CLASS_BODY_DECLARATIONS: return 881;
				case FINAL: return 1;
				case MODIFIER: return 489;
				case MODIFIERS: return 30;
				case MODIFIERS_OPT: return 750;
				case NATIVE: return 181;
				case PROTECTED: return 492;
				case PUBLIC: return 470;
				case RBRACE: return 559;
				case SEMICOLON: return 673;
				case STATIC: return 91;
			}
			break;
		case 567:
			switch(symbol) {
				case BASIC_TYPE: return 395;
				case BOOLEAN: return 932;
				case BYTE: return 399;
				case CHAR: return 224;
				case ID: return 172;
				case INT: return 39;
				case LONG_IDENTIFIER: return 650;
				case SHORT: return 279;
				case TYPE: return 133;
				case TYPE_LIST: return 264;
			}
			break;
		case 569:
			switch(symbol) {
				case DOT: return 622;
				case SELECTORS_OPT: return 753;
			}
			break;
		case 571:
			switch(symbol) {
				case ID: return 610;
			}
			break;
		case 574:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case EXPRESSION1_REST: return 633;
				case EXPRESSION_INFIX: return 581;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 1002;
				case INSTANCEOF: return 416;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 579:
			switch(symbol) {
				case BOOLEAN_LIT: return 366;
				case CHAR_LIT: return 345;
				case EXPRESSION2: return 894;
				case EXPRESSION3: return 186;
				case ID: return 282;
				case INT_LIT: return 161;
				case LITERAL: return 166;
				case LPAREN: return 90;
				case MINUS: return 131;
				case NEW: return 333;
				case NOT: return 312;
				case NULL_LIT: return 177;
				case PRIMARY: return 194;
				case STRING_LIT: return 547;
				case THIS: return 396;
			}
			break;
		case 580:
			switch(symbol) {
				case BASIC_TYPE: return 52;
				case BOOLEAN: return 223;
				case BYTE: return 210;
				case CHAR: return 65;
				case FORMAL_PARAMETER: return 142;
				case FORMAL_PARAMETER_LIST: return 710;
				case ID: return 564;
				case INT: return 331;
				case LONG_IDENTIFIER: return 4;
				case SHORT: return 304;
				case TYPE: return 495;
			}
			break;
		case 581:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 17;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 585:
			switch(symbol) {
				case RPAREN: return 1089;
			}
			break;
		case 587:
			switch(symbol) {
				case DOT: return 614;
			}
			break;
		case 591:
			switch(symbol) {
				case ID: return 824;
				case LONG_IDENTIFIER: return 1145;
			}
			break;
		case 592:
			switch(symbol) {
				case SEMICOLON: return 726;
			}
			break;
		case 595:
			switch(symbol) {
				case ID: return 430;
			}
			break;
		case 596:
			switch(symbol) {
				case RBRACKET: return 100;
			}
			break;
		case 597:
			switch(symbol) {
				case ID: return 1073;
			}
			break;
		case 603:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 816;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 888;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 604:
			switch(symbol) {
				case ID: return 1111;
				case LONG_IDENTIFIER: return 108;
			}
			break;
		case 605:
			switch(symbol) {
				case ID: return 1132;
			}
			break;
		case 606:
			switch(symbol) {
				case RBRACKET: return 557;
			}
			break;
		case 608:
			switch(symbol) {
				case ID: return 1115;
				case LONG_IDENTIFIER: return 420;
			}
			break;
		case 609:
			switch(symbol) {
				case FORMAL_PARAMETERS: return 728;
				case INTERFACE_METHOD_DECLARATOR_REST: return 1164;
				case INTERFACE_METHOD_OR_FIELD_REST: return 1001;
				case LPAREN: return 580;
			}
			break;
		case 614:
			switch(symbol) {
				case ID: return 150;
			}
			break;
		case 616:
			switch(symbol) {
				case ID: return 542;
			}
			break;
		case 619:
			switch(symbol) {
				case ABSTRACT: return 144;
				case FINAL: return 1;
				case INTERFACE_BODY_DECLARATION: return 521;
				case MODIFIER: return 489;
				case MODIFIERS: return 30;
				case MODIFIERS_OPT: return 767;
				case NATIVE: return 181;
				case PROTECTED: return 492;
				case PUBLIC: return 470;
				case RBRACE: return 232;
				case SEMICOLON: return 701;
				case STATIC: return 91;
			}
			break;
		case 622:
			switch(symbol) {
				case ID: return 1067;
				case LONG_IDENTIFIER: return 734;
			}
			break;
		case 624:
			switch(symbol) {
				case ARGUMENTS: return 862;
				case DOT: return 595;
				case LBRACKET: return 555;
				case LPAREN: return 782;
				case SELECTOR: return 933;
				case SELECTORS: return 945;
			}
			break;
		case 628:
			switch(symbol) {
				case FORMAL_PARAMETERS: return 935;
				case LPAREN: return 421;
				case METHOD_DECLARATOR_REST: return 768;
			}
			break;
		case 630:
			switch(symbol) {
				case ARRAY: return 645;
				case DOT: return 199;
			}
			break;
		case 631:
			switch(symbol) {
				case ID: return 826;
			}
			break;
		case 632:
			switch(symbol) {
				case BASIC_TYPE: return 695;
				case BOOLEAN: return 789;
				case BYTE: return 1095;
				case CHAR: return 99;
				case ID: return 129;
				case INT: return 647;
				case LONG_IDENTIFIER: return 870;
				case SHORT: return 321;
				case TYPE: return 190;
			}
			break;
		case 636:
			switch(symbol) {
				case ARGUMENTS: return 944;
				case DOT: return 1114;
				case LBRACKET: return 1082;
				case LPAREN: return 939;
				case SELECTOR: return 798;
			}
			break;
		case 640:
			switch(symbol) {
				case BOOLEAN_LIT: return 367;
				case CHAR_LIT: return 112;
				case EXPRESSION3: return 809;
				case ID: return 89;
				case INT_LIT: return 18;
				case LITERAL: return 377;
				case LPAREN: return 426;
				case NEW: return 485;
				case NOT: return 474;
				case NULL_LIT: return 173;
				case PRIMARY: return 187;
				case STRING_LIT: return 322;
				case THIS: return 164;
			}
			break;
		case 642:
			switch(symbol) {
				case RPAREN: return 941;
			}
			break;
		case 650:
			switch(symbol) {
				case ARRAY: return 934;
				case DOT: return 914;
			}
			break;
		case 653:
			switch(symbol) {
				case IMPORT: return 189;
				case IMPORT_DECLARATION: return 373;
			}
			break;
		case 655:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 1024;
				case CLASS_CREATOR_REST: return 771;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 657:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 1050;
				case CLASS_CREATOR_REST: return 803;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 660:
			switch(symbol) {
				case ARRAY: return 977;
				case DOT: return 1165;
			}
			break;
		case 661:
			switch(symbol) {
				case BOOLEAN_LIT: return 237;
				case CHAR_LIT: return 157;
				case EXPRESSION3: return 679;
				case ID: return 242;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 663:
			switch(symbol) {
				case BOOLEAN_LIT: return 86;
				case CHAR_LIT: return 758;
				case EXPRESSION2: return 691;
				case EXPRESSION3: return 516;
				case ID: return 417;
				case INT_LIT: return 335;
				case LITERAL: return 225;
				case LPAREN: return 58;
				case MINUS: return 258;
				case NEW: return 712;
				case NOT: return 663;
				case NULL_LIT: return 560;
				case PRIMARY: return 44;
				case STRING_LIT: return 171;
				case THIS: return 453;
			}
			break;
		case 664:
			switch(symbol) {
				case BOOLEAN_LIT: return 54;
				case CHAR_LIT: return 170;
				case EXPRESSION1: return 301;
				case EXPRESSION2: return 302;
				case EXPRESSION3: return 300;
				case ID: return 267;
				case INT_LIT: return 745;
				case LITERAL: return 318;
				case LPAREN: return 514;
				case MINUS: return 845;
				case NEW: return 10;
				case NOT: return 47;
				case NULL_LIT: return 359;
				case PRIMARY: return 356;
				case STRING_LIT: return 159;
				case THIS: return 53;
			}
			break;
		case 665:
			switch(symbol) {
				case ID: return 609;
			}
			break;
		case 667:
			switch(symbol) {
				case ARRAY: return 886;
			}
			break;
		case 669:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 558;
				case CLASS_CREATOR_REST: return 787;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 670:
			switch(symbol) {
				case BOOLEAN_LIT: return 366;
				case CHAR_LIT: return 345;
				case EXPRESSION2: return 191;
				case EXPRESSION3: return 186;
				case ID: return 282;
				case INT_LIT: return 161;
				case LITERAL: return 166;
				case LPAREN: return 90;
				case MINUS: return 131;
				case NEW: return 333;
				case NOT: return 312;
				case NULL_LIT: return 177;
				case PRIMARY: return 194;
				case STRING_LIT: return 547;
				case THIS: return 396;
			}
			break;
		case 672:
			switch(symbol) {
				case BOOLEAN_LIT: return 508;
				case CHAR_LIT: return 184;
				case EXPRESSION2: return 1060;
				case EXPRESSION3: return 111;
				case ID: return 288;
				case INT_LIT: return 256;
				case LITERAL: return 515;
				case LPAREN: return 690;
				case MINUS: return 672;
				case NEW: return 227;
				case NOT: return 235;
				case NULL_LIT: return 408;
				case PRIMARY: return 569;
				case STRING_LIT: return 535;
				case THIS: return 70;
			}
			break;
		case 677:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 764;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 678:
			switch(symbol) {
				case DOT: return 57;
				case SELECTORS_OPT: return 1090;
			}
			break;
		case 680:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 1081;
			}
			break;
		case 682:
			switch(symbol) {
				case RPAREN: return 365;
			}
			break;
		case 683:
			switch(symbol) {
				case RBRACKET: return 926;
			}
			break;
		case 687:
			switch(symbol) {
				case BASIC_TYPE: return 52;
				case BLOCK_BODY: return 985;
				case BLOCK_STATEMENT: return 135;
				case BLOCK_STATEMENTS: return 277;
				case BOOLEAN: return 223;
				case BYTE: return 210;
				case CHAR: return 65;
				case ID: return 564;
				case INT: return 331;
				case LOCAL_VARIABLE_DECLARATION_STATEMENT: return 618;
				case LONG_IDENTIFIER: return 4;
				case SHORT: return 304;
				case TYPE: return 811;
			}
			break;
		case 688:
			switch(symbol) {
				case BOOLEAN_LIT: return 219;
				case CHAR_LIT: return 73;
				case EXPRESSION2: return 510;
				case EXPRESSION3: return 35;
				case ID: return 483;
				case INT_LIT: return 386;
				case LITERAL: return 280;
				case LPAREN: return 87;
				case MINUS: return 11;
				case NEW: return 292;
				case NOT: return 281;
				case NULL_LIT: return 29;
				case PRIMARY: return 192;
				case STRING_LIT: return 287;
				case THIS: return 83;
			}
			break;
		case 689:
			switch(symbol) {
				case BOOLEAN_LIT: return 54;
				case CHAR_LIT: return 170;
				case EXPRESSION2: return 880;
				case EXPRESSION3: return 300;
				case ID: return 267;
				case INT_LIT: return 745;
				case LITERAL: return 318;
				case LPAREN: return 514;
				case MINUS: return 845;
				case NEW: return 10;
				case NOT: return 47;
				case NULL_LIT: return 359;
				case PRIMARY: return 356;
				case STRING_LIT: return 159;
				case THIS: return 53;
			}
			break;
		case 690:
			switch(symbol) {
				case BASIC_TYPE: return 805;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 1000;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 695:
			switch(symbol) {
				case ARRAY: return 770;
			}
			break;
		case 696:
			switch(symbol) {
				case ARRAY: return 1040;
				case DOT: return 427;
			}
			break;
		case 697:
			switch(symbol) {
				case ID: return 487;
				case LONG_IDENTIFIER: return 497;
			}
			break;
		case 698:
			switch(symbol) {
				case BASIC_TYPE: return 488;
				case BOOLEAN: return 72;
				case BOOLEAN_LIT: return 237;
				case BYTE: return 23;
				case CHAR: return 306;
				case CHAR_LIT: return 157;
				case EXPRESSION: return 682;
				case EXPRESSION1: return 94;
				case EXPRESSION2: return 92;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT: return 391;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case SHORT: return 253;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 699:
			switch(symbol) {
				case BOOLEAN_LIT: return 86;
				case CHAR_LIT: return 758;
				case EXPRESSION2: return 876;
				case EXPRESSION3: return 516;
				case ID: return 417;
				case INT_LIT: return 335;
				case LITERAL: return 225;
				case LPAREN: return 58;
				case MINUS: return 258;
				case NEW: return 712;
				case NOT: return 663;
				case NULL_LIT: return 560;
				case PRIMARY: return 44;
				case STRING_LIT: return 171;
				case THIS: return 453;
			}
			break;
		case 700:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 1014;
			}
			break;
		case 703:
			switch(symbol) {
				case BOOLEAN_LIT: return 197;
				case CHAR_LIT: return 228;
				case EXPRESSION2: return 912;
				case EXPRESSION3: return 340;
				case ID: return 56;
				case INT_LIT: return 162;
				case LITERAL: return 463;
				case LPAREN: return 217;
				case MINUS: return 299;
				case NEW: return 274;
				case NOT: return 260;
				case NULL_LIT: return 31;
				case PRIMARY: return 334;
				case STRING_LIT: return 221;
				case THIS: return 254;
			}
			break;
		case 709:
			switch(symbol) {
				case BOOLEAN_LIT: return 381;
				case CHAR_LIT: return 507;
				case EXPRESSION2: return 1068;
				case EXPRESSION3: return 446;
				case ID: return 502;
				case INT_LIT: return 61;
				case LITERAL: return 462;
				case LPAREN: return 6;
				case MINUS: return 313;
				case NEW: return 196;
				case NOT: return 169;
				case NULL_LIT: return 84;
				case PRIMARY: return 504;
				case STRING_LIT: return 635;
				case THIS: return 668;
			}
			break;
		case 710:
			switch(symbol) {
				case COMMA: return 477;
				case RPAREN: return 613;
			}
			break;
		case 711:
			switch(symbol) {
				case BOOLEAN_LIT: return 86;
				case CHAR_LIT: return 758;
				case EXPRESSION2: return 519;
				case EXPRESSION3: return 516;
				case ID: return 417;
				case INT_LIT: return 335;
				case LITERAL: return 225;
				case LPAREN: return 58;
				case MINUS: return 258;
				case NEW: return 712;
				case NOT: return 663;
				case NULL_LIT: return 560;
				case PRIMARY: return 44;
				case STRING_LIT: return 171;
				case THIS: return 453;
			}
			break;
		case 712:
			switch(symbol) {
				case CREATOR: return 693;
				case ID: return 43;
				case LONG_IDENTIFIER: return 60;
				case QUALIFIED_IDENTIFIER: return 900;
			}
			break;
		case 715:
			switch(symbol) {
				case BASIC_TYPE: return 908;
				case BOOLEAN: return 940;
				case BYTE: return 905;
				case CHAR: return 145;
				case ID: return 204;
				case INT: return 392;
				case LONG_IDENTIFIER: return 630;
				case SHORT: return 320;
				case TYPE: return 1130;
			}
			break;
		case 717:
			switch(symbol) {
				case ID: return 909;
			}
			break;
		case 718:
			switch(symbol) {
				case ID: return 582;
			}
			break;
		case 720:
			switch(symbol) {
				case ARRAY: return 342;
			}
			break;
		case 724:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 1087;
			}
			break;
		case 728:
			switch(symbol) {
				case SEMICOLON: return 837;
			}
			break;
		case 729:
			switch(symbol) {
				case ID: return 572;
			}
			break;
		case 730:
			switch(symbol) {
				case BOOLEAN_LIT: return 508;
				case CHAR_LIT: return 184;
				case EXPRESSION2: return 110;
				case EXPRESSION3: return 111;
				case ID: return 288;
				case INT_LIT: return 256;
				case LITERAL: return 515;
				case LPAREN: return 690;
				case MINUS: return 672;
				case NEW: return 227;
				case NOT: return 235;
				case NULL_LIT: return 408;
				case PRIMARY: return 569;
				case STRING_LIT: return 535;
				case THIS: return 70;
			}
			break;
		case 731:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 520;
			}
			break;
		case 732:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 606;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 733:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 656;
			}
			break;
		case 734:
			switch(symbol) {
				case ARGUMENTS: return 355;
				case DOT: return 823;
				case LBRACKET: return 964;
				case LPAREN: return 41;
				case SELECTOR: return 451;
				case SELECTORS: return 439;
			}
			break;
		case 735:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 891;
			}
			break;
		case 736:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 812;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 737:
			switch(symbol) {
				case RPAREN: return 840;
			}
			break;
		case 738:
			switch(symbol) {
				case ARGUMENTS: return 959;
				case DOT: return 571;
				case LBRACKET: return 97;
				case LPAREN: return 456;
				case SELECTOR: return 50;
			}
			break;
		case 739:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 332;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 747:
			switch(symbol) {
				case BOOLEAN_LIT: return 461;
				case CHAR_LIT: return 96;
				case EXPRESSION2: return 892;
				case EXPRESSION3: return 246;
				case ID: return 298;
				case INT_LIT: return 360;
				case LITERAL: return 205;
				case LPAREN: return 698;
				case MINUS: return 747;
				case NEW: return 247;
				case NOT: return 216;
				case NULL_LIT: return 522;
				case PRIMARY: return 678;
				case STRING_LIT: return 523;
				case THIS: return 146;
			}
			break;
		case 749:
			switch(symbol) {
				case RPAREN: return 251;
			}
			break;
		case 750:
			switch(symbol) {
				case BASIC_TYPE: return 52;
				case BOOLEAN: return 223;
				case BYTE: return 210;
				case CHAR: return 65;
				case ID: return 198;
				case INT: return 331;
				case LONG_IDENTIFIER: return 4;
				case MEMBER_DECLARATION: return 797;
				case METHOD_OR_FIELD_DECLARATION: return 859;
				case SHORT: return 304;
				case TYPE: return 158;
				case VOID: return 801;
			}
			break;
		case 751:
			switch(symbol) {
				case BOOLEAN_LIT: return 219;
				case CHAR_LIT: return 73;
				case EXPRESSION2: return 676;
				case EXPRESSION3: return 35;
				case ID: return 483;
				case INT_LIT: return 386;
				case LITERAL: return 280;
				case LPAREN: return 87;
				case MINUS: return 11;
				case NEW: return 292;
				case NOT: return 281;
				case NULL_LIT: return 29;
				case PRIMARY: return 192;
				case STRING_LIT: return 287;
				case THIS: return 83;
			}
			break;
		case 752:
			switch(symbol) {
				case END_TERMINAL: return 1055;
			}
			break;
		case 754:
			switch(symbol) {
				case LPAREN: return 954;
			}
			break;
		case 759:
			switch(symbol) {
				case ID: return 662;
			}
			break;
		case 760:
			switch(symbol) {
				case RPAREN: return 240;
			}
			break;
		case 761:
			switch(symbol) {
				case RBRACKET: return 621;
			}
			break;
		case 762:
			switch(symbol) {
				case BOOLEAN_LIT: return 237;
				case CHAR_LIT: return 157;
				case EXPRESSION2: return 692;
				case EXPRESSION3: return 95;
				case ID: return 242;
				case INT_LIT: return 16;
				case LITERAL: return 143;
				case LPAREN: return 207;
				case MINUS: return 38;
				case NEW: return 40;
				case NOT: return 14;
				case NULL_LIT: return 28;
				case PRIMARY: return 71;
				case STRING_LIT: return 69;
				case THIS: return 77;
			}
			break;
		case 764:
			switch(symbol) {
				case BOOLEAN_LIT: return 381;
				case CHAR_LIT: return 507;
				case EXPRESSION2: return 974;
				case EXPRESSION3: return 446;
				case ID: return 502;
				case INT_LIT: return 61;
				case LITERAL: return 462;
				case LPAREN: return 6;
				case MINUS: return 313;
				case NEW: return 196;
				case NOT: return 169;
				case NULL_LIT: return 84;
				case PRIMARY: return 504;
				case STRING_LIT: return 635;
				case THIS: return 668;
			}
			break;
		case 767:
			switch(symbol) {
				case BASIC_TYPE: return 52;
				case BOOLEAN: return 223;
				case BYTE: return 210;
				case CHAR: return 65;
				case ID: return 564;
				case INT: return 331;
				case INTERFACE_MEMBER_DECLARATION: return 654;
				case INTERFACE_METHOD_OR_FIELD_DECLARATION: return 541;
				case LONG_IDENTIFIER: return 4;
				case SHORT: return 304;
				case TYPE: return 665;
				case VOID: return 1080;
			}
			break;
		case 769:
			switch(symbol) {
				case ID: return 1148;
			}
			break;
		case 771:
			switch(symbol) {
				case RPAREN: return 362;
			}
			break;
		case 773:
			switch(symbol) {
				case SEMICOLON: return 501;
			}
			break;
		case 774:
			switch(symbol) {
				case ARGUMENTS: return 511;
				case DOT: return 967;
				case LBRACKET: return 821;
				case LPAREN: return 1074;
				case SELECTOR: return 858;
				case SELECTORS: return 1064;
			}
			break;
		case 776:
			switch(symbol) {
				case RPAREN: return 296;
			}
			break;
		case 778:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 119;
				case EXPRESSION2: return 991;
				case EXPRESSION3: return 424;
				case ID: return 455;
				case INT_LIT: return 336;
				case LITERAL: return 7;
				case LPAREN: return 155;
				case MINUS: return 201;
				case NEW: return 21;
				case NOT: return 208;
				case NULL_LIT: return 229;
				case PRIMARY: return 431;
				case STRING_LIT: return 315;
				case THIS: return 132;
			}
			break;
		case 781:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 1078;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 782:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 700;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 907;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 783:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 180;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 627;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 786:
			switch(symbol) {
				case ABSTRACT: return 144;
				case CLASS_BODY_DECLARATION: return 534;
				case FINAL: return 1;
				case MODIFIER: return 489;
				case MODIFIERS: return 30;
				case MODIFIERS_OPT: return 750;
				case NATIVE: return 181;
				case PROTECTED: return 492;
				case PUBLIC: return 470;
				case RBRACE: return 222;
				case SEMICOLON: return 673;
				case STATIC: return 91;
			}
			break;
		case 787:
			switch(symbol) {
				case RPAREN: return 447;
			}
			break;
		case 788:
			switch(symbol) {
				case RBRACKET: return 566;
			}
			break;
		case 790:
			switch(symbol) {
				case SEMICOLON: return 593;
			}
			break;
		case 794:
			switch(symbol) {
				case RPAREN: return 1110;
			}
			break;
		case 796:
			switch(symbol) {
				case BLOCK: return 832;
				case LBRACE: return 687;
				case METHOD_BODY: return 1102;
			}
			break;
		case 800:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 761;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 801:
			switch(symbol) {
				case ID: return 628;
			}
			break;
		case 803:
			switch(symbol) {
				case RPAREN: return 1142;
			}
			break;
		case 804:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 120;
			}
			break;
		case 805:
			switch(symbol) {
				case RPAREN: return 403;
			}
			break;
		case 807:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 1075;
			}
			break;
		case 810:
			switch(symbol) {
				case ARGUMENTS: return 649;
				case DOT: return 418;
				case LBRACKET: return 348;
				case LPAREN: return 879;
				case SELECTOR: return 1120;
			}
			break;
		case 811:
			switch(symbol) {
				case ID: return 962;
				case VARIABLE_DECLARATOR: return 592;
			}
			break;
		case 812:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 119;
				case EXPRESSION2: return 425;
				case EXPRESSION3: return 424;
				case ID: return 455;
				case INT_LIT: return 336;
				case LITERAL: return 7;
				case LPAREN: return 155;
				case MINUS: return 201;
				case NEW: return 21;
				case NOT: return 208;
				case NULL_LIT: return 229;
				case PRIMARY: return 431;
				case STRING_LIT: return 315;
				case THIS: return 132;
			}
			break;
		case 813:
			switch(symbol) {
				case BOOLEAN_LIT: return 328;
				case CHAR_LIT: return 93;
				case EXPRESSION3: return 841;
				case ID: return 118;
				case INT_LIT: return 629;
				case LITERAL: return 607;
				case LPAREN: return 428;
				case NEW: return 458;
				case NOT: return 476;
				case NULL_LIT: return 441;
				case PRIMARY: return 134;
				case STRING_LIT: return 263;
				case THIS: return 168;
			}
			break;
		case 814:
			switch(symbol) {
				case BOOLEAN_LIT: return 197;
				case CHAR_LIT: return 228;
				case EXPRESSION3: return 1127;
				case ID: return 56;
				case INT_LIT: return 162;
				case LITERAL: return 463;
				case LPAREN: return 217;
				case NEW: return 274;
				case NOT: return 260;
				case NULL_LIT: return 31;
				case PRIMARY: return 334;
				case STRING_LIT: return 221;
				case THIS: return 254;
			}
			break;
		case 816:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 675;
			}
			break;
		case 817:
			switch(symbol) {
				case CLASS_BODY: return 385;
				case IMPLEMENTS: return 1083;
				case LBRACE: return 561;
			}
			break;
		case 819:
			switch(symbol) {
				case LPAREN: return 1141;
			}
			break;
		case 821:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 294;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 822:
			switch(symbol) {
				case DOT: return 863;
				case SEMICOLON: return 625;
			}
			break;
		case 823:
			switch(symbol) {
				case ID: return 370;
			}
			break;
		case 825:
			switch(symbol) {
				case BOOLEAN_LIT: return 366;
				case CHAR_LIT: return 345;
				case EXPRESSION2: return 185;
				case EXPRESSION3: return 186;
				case ID: return 282;
				case INT_LIT: return 161;
				case LITERAL: return 166;
				case LPAREN: return 90;
				case MINUS: return 131;
				case NEW: return 333;
				case NOT: return 312;
				case NULL_LIT: return 177;
				case PRIMARY: return 194;
				case STRING_LIT: return 547;
				case THIS: return 396;
			}
			break;
		case 827:
			switch(symbol) {
				case RBRACKET: return 639;
			}
			break;
		case 828:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 683;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 830:
			switch(symbol) {
				case ARRAY: return 1051;
			}
			break;
		case 831:
			switch(symbol) {
				case ID: return 1084;
			}
			break;
		case 833:
			switch(symbol) {
				case RPAREN: return 917;
			}
			break;
		case 834:
			switch(symbol) {
				case ARRAY: return 913;
			}
			break;
		case 835:
			switch(symbol) {
				case RPAREN: return 422;
			}
			break;
		case 838:
			switch(symbol) {
				case ARGUMENTS: return 344;
				case DOT: return 1023;
				case LBRACKET: return 1011;
				case LPAREN: return 141;
				case SELECTOR: return 206;
			}
			break;
		case 839:
			switch(symbol) {
				case ID: return 1155;
				case LONG_IDENTIFIER: return 499;
			}
			break;
		case 840:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION2: return 1019;
				case EXPRESSION3: return 64;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 843:
			switch(symbol) {
				case ARGUMENTS: return 344;
				case DOT: return 1147;
				case LBRACKET: return 1011;
				case LPAREN: return 141;
				case SELECTOR: return 637;
				case SELECTORS: return 838;
			}
			break;
		case 845:
			switch(symbol) {
				case BOOLEAN_LIT: return 54;
				case CHAR_LIT: return 170;
				case EXPRESSION2: return 1100;
				case EXPRESSION3: return 300;
				case ID: return 267;
				case INT_LIT: return 745;
				case LITERAL: return 318;
				case LPAREN: return 514;
				case MINUS: return 845;
				case NEW: return 10;
				case NOT: return 47;
				case NULL_LIT: return 359;
				case PRIMARY: return 356;
				case STRING_LIT: return 159;
				case THIS: return 53;
			}
			break;
		case 851:
			switch(symbol) {
				case BOOLEAN_LIT: return 602;
				case CHAR_LIT: return 314;
				case EXPRESSION2: return 1071;
				case EXPRESSION3: return 163;
				case ID: return 806;
				case INT_LIT: return 209;
				case LITERAL: return 268;
				case LPAREN: return 78;
				case MINUS: return 117;
				case NEW: return 375;
				case NOT: return 398;
				case NULL_LIT: return 503;
				case PRIMARY: return 357;
				case STRING_LIT: return 394;
				case THIS: return 239;
			}
			break;
		case 852:
			switch(symbol) {
				case ARRAY: return 961;
				case DOT: return 893;
			}
			break;
		case 857:
			switch(symbol) {
				case RPAREN: return 579;
			}
			break;
		case 860:
			switch(symbol) {
				case RPAREN: return 851;
			}
			break;
		case 861:
			switch(symbol) {
				case ARGUMENTS: return 727;
				case DOT: return 729;
				case LBRACKET: return 828;
				case LPAREN: return 603;
				case SELECTOR: return 1033;
			}
			break;
		case 863:
			switch(symbol) {
				case ID: return 150;
				case MULT: return 790;
			}
			break;
		case 865:
			switch(symbol) {
				case RPAREN: return 570;
			}
			break;
		case 867:
			switch(symbol) {
				case LPAREN: return 473;
			}
			break;
		case 868:
			switch(symbol) {
				case COMMA: return 477;
				case RPAREN: return 518;
			}
			break;
		case 870:
			switch(symbol) {
				case ARRAY: return 233;
				case DOT: return 1020;
			}
			break;
		case 871:
			switch(symbol) {
				case BASIC_TYPE: return 882;
				case BOOLEAN: return 704;
				case BYTE: return 1053;
				case CHAR: return 922;
				case ID: return 946;
				case INT: return 612;
				case LONG_IDENTIFIER: return 660;
				case SHORT: return 943;
				case TYPE: return 895;
			}
			break;
		case 872:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 467;
				case CLASS_CREATOR_REST: return 865;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 873:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 160;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 874:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 642;
				case CLASS_CREATOR_REST: return 1106;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 878:
			switch(symbol) {
				case ID: return 452;
			}
			break;
		case 879:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 1134;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 1046;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 881:
			switch(symbol) {
				case ABSTRACT: return 144;
				case CLASS_BODY_DECLARATION: return 534;
				case FINAL: return 1;
				case MODIFIER: return 489;
				case MODIFIERS: return 30;
				case MODIFIERS_OPT: return 750;
				case NATIVE: return 181;
				case PROTECTED: return 492;
				case PUBLIC: return 470;
				case RBRACE: return 384;
				case SEMICOLON: return 673;
				case STATIC: return 91;
			}
			break;
		case 882:
			switch(symbol) {
				case ARRAY: return 524;
			}
			break;
		case 883:
			switch(symbol) {
				case BOOLEAN_LIT: return 219;
				case CHAR_LIT: return 73;
				case EXPRESSION3: return 1101;
				case ID: return 483;
				case INT_LIT: return 386;
				case LITERAL: return 280;
				case LPAREN: return 87;
				case NEW: return 292;
				case NOT: return 281;
				case NULL_LIT: return 29;
				case PRIMARY: return 192;
				case STRING_LIT: return 287;
				case THIS: return 83;
			}
			break;
		case 887:
			switch(symbol) {
				case BOOLEAN_LIT: return 461;
				case CHAR_LIT: return 96;
				case EXPRESSION: return 714;
				case EXPRESSION1: return 244;
				case EXPRESSION2: return 245;
				case EXPRESSION3: return 246;
				case ID: return 298;
				case INT_LIT: return 360;
				case LITERAL: return 205;
				case LPAREN: return 698;
				case MINUS: return 747;
				case NEW: return 247;
				case NOT: return 216;
				case NULL_LIT: return 522;
				case PRIMARY: return 678;
				case STRING_LIT: return 523;
				case THIS: return 146;
				case VARIABLE_INITIALIZER: return 1160;
			}
			break;
		case 889:
			switch(symbol) {
				case ABSTRACT: return 716;
				case FINAL: return 702;
				case MODIFIER: return 844;
				case NATIVE: return 638;
				case PROTECTED: return 255;
				case PUBLIC: return 380;
				case STATIC: return 126;
			}
			break;
		case 890:
			switch(symbol) {
				case ARGUMENTS: return 291;
				case DOT: return 958;
				case LBRACKET: return 873;
				case LPAREN: return 783;
				case SELECTOR: return 979;
			}
			break;
		case 893:
			switch(symbol) {
				case ID: return 1005;
			}
			break;
		case 896:
			switch(symbol) {
				case ARGUMENTS: return 853;
				case DOT: return 718;
				case LBRACKET: return 407;
				case LPAREN: return 546;
				case SELECTOR: return 829;
			}
			break;
		case 897:
			switch(symbol) {
				case RPAREN: return 178;
			}
			break;
		case 899:
			switch(symbol) {
				case ARRAY: return 1039;
				case DOT: return 951;
			}
			break;
		case 900:
			switch(symbol) {
				case LPAREN: return 406;
			}
			break;
		case 901:
			switch(symbol) {
				case ID: return 884;
				case LONG_IDENTIFIER: return 1006;
			}
			break;
		case 902:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 213;
			}
			break;
		case 906:
			switch(symbol) {
				case ID: return 849;
			}
			break;
		case 908:
			switch(symbol) {
				case ARRAY: return 583;
			}
			break;
		case 909:
			switch(symbol) {
				case CLASS_BODY: return 51;
				case EXTENDS: return 347;
				case IMPLEMENTS: return 567;
				case LBRACE: return 561;
			}
			break;
		case 910:
			switch(symbol) {
				case BASIC_TYPE: return 830;
				case BOOLEAN: return 722;
				case BYTE: return 1062;
				case CHAR: return 512;
				case ID: return 947;
				case INT: return 651;
				case LONG_IDENTIFIER: return 852;
				case SHORT: return 536;
				case TYPE: return 957;
			}
			break;
		case 914:
			switch(symbol) {
				case ID: return 648;
			}
			break;
		case 915:
			switch(symbol) {
				case ID: return 601;
				case LONG_IDENTIFIER: return 438;
			}
			break;
		case 919:
			switch(symbol) {
				case ASSIGN: return 887;
				case FORMAL_PARAMETERS: return 935;
				case LPAREN: return 421;
				case METHOD_DECLARATOR_REST: return 1035;
				case METHOD_OR_FIELD_REST: return 472;
				case VARIABLE_DECLARATOR_REST: return 773;
			}
			break;
		case 921:
			switch(symbol) {
				case ID: return 563;
			}
			break;
		case 924:
			switch(symbol) {
				case BASIC_TYPE: return 52;
				case BOOLEAN: return 223;
				case BYTE: return 210;
				case CHAR: return 65;
				case FORMAL_PARAMETER: return 142;
				case FORMAL_PARAMETER_LIST: return 868;
				case ID: return 564;
				case INT: return 331;
				case LONG_IDENTIFIER: return 4;
				case SHORT: return 304;
				case TYPE: return 495;
			}
			break;
		case 925:
			switch(symbol) {
				case COMMA: return 477;
				case RPAREN: return 1146;
			}
			break;
		case 927:
			switch(symbol) {
				case ID: return 1158;
				case LONG_IDENTIFIER: return 307;
			}
			break;
		case 929:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 751;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 930:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION3: return 544;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 931:
			switch(symbol) {
				case LPAREN: return 1052;
			}
			break;
		case 935:
			switch(symbol) {
				case BLOCK: return 832;
				case LBRACE: return 687;
				case METHOD_BODY: return 412;
				case SEMICOLON: return 948;
			}
			break;
		case 936:
			switch(symbol) {
				case ID: return 1038;
			}
			break;
		case 937:
			switch(symbol) {
				case RPAREN: return 149;
			}
			break;
		case 938:
			switch(symbol) {
				case ID: return 486;
				case LONG_IDENTIFIER: return 624;
			}
			break;
		case 939:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 735;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 588;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 945:
			switch(symbol) {
				case ARGUMENTS: return 862;
				case DOT: return 998;
				case LBRACKET: return 555;
				case LPAREN: return 782;
				case SELECTOR: return 755;
			}
			break;
		case 951:
			switch(symbol) {
				case ID: return 449;
			}
			break;
		case 953:
			switch(symbol) {
				case ARRAY: return 904;
			}
			break;
		case 954:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 76;
				case CLASS_CREATOR_REST: return 490;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 958:
			switch(symbol) {
				case ID: return 481;
			}
			break;
		case 962:
			switch(symbol) {
				case ASSIGN: return 887;
				case VARIABLE_DECLARATOR_REST: return 265;
			}
			break;
		case 964:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 32;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 967:
			switch(symbol) {
				case ID: return 1021;
			}
			break;
		case 968:
			switch(symbol) {
				case BOOLEAN_LIT: return 328;
				case CHAR_LIT: return 93;
				case EXPRESSION2: return 617;
				case EXPRESSION3: return 326;
				case ID: return 118;
				case INT_LIT: return 629;
				case LITERAL: return 607;
				case LPAREN: return 428;
				case MINUS: return 444;
				case NEW: return 458;
				case NOT: return 476;
				case NULL_LIT: return 441;
				case PRIMARY: return 134;
				case STRING_LIT: return 263;
				case THIS: return 168;
			}
			break;
		case 973:
			switch(symbol) {
				case ID: return 1025;
			}
			break;
		case 975:
			switch(symbol) {
				case RPAREN: return 122;
			}
			break;
		case 980:
			switch(symbol) {
				case BOOLEAN_LIT: return 381;
				case CHAR_LIT: return 507;
				case EXPRESSION2: return 545;
				case EXPRESSION3: return 446;
				case ID: return 502;
				case INT_LIT: return 61;
				case LITERAL: return 462;
				case LPAREN: return 6;
				case MINUS: return 313;
				case NEW: return 196;
				case NOT: return 169;
				case NULL_LIT: return 84;
				case PRIMARY: return 504;
				case STRING_LIT: return 635;
				case THIS: return 668;
			}
			break;
		case 981:
			switch(symbol) {
				case ID: return 818;
			}
			break;
		case 983:
			switch(symbol) {
				case RPAREN: return 1059;
			}
			break;
		case 984:
			switch(symbol) {
				case ID: return 815;
			}
			break;
		case 985:
			switch(symbol) {
				case RBRACE: return 316;
			}
			break;
		case 989:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 699;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 990:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 825;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 994:
			switch(symbol) {
				case ID: return 238;
				case LONG_IDENTIFIER: return 517;
			}
			break;
		case 995:
			switch(symbol) {
				case RBRACKET: return 846;
			}
			break;
		case 998:
			switch(symbol) {
				case ID: return 1036;
			}
			break;
		case 999:
			switch(symbol) {
				case ID: return 203;
			}
			break;
		case 1000:
			switch(symbol) {
				case RPAREN: return 148;
			}
			break;
		case 1002:
			switch(symbol) {
				case BOOLEAN_LIT: return 602;
				case CHAR_LIT: return 314;
				case EXPRESSION2: return 740;
				case EXPRESSION3: return 163;
				case ID: return 806;
				case INT_LIT: return 209;
				case LITERAL: return 268;
				case LPAREN: return 78;
				case MINUS: return 117;
				case NEW: return 375;
				case NOT: return 398;
				case NULL_LIT: return 503;
				case PRIMARY: return 357;
				case STRING_LIT: return 394;
				case THIS: return 239;
			}
			break;
		case 1003:
			switch(symbol) {
				case LPAREN: return 872;
			}
			break;
		case 1004:
			switch(symbol) {
				case RPAREN: return 506;
			}
			break;
		case 1006:
			switch(symbol) {
				case ARGUMENTS: return 853;
				case DOT: return 113;
				case LBRACKET: return 407;
				case LPAREN: return 546;
				case SELECTOR: return 996;
				case SELECTORS: return 896;
			}
			break;
		case 1008:
			switch(symbol) {
				case ARGUMENTS: return 727;
				case DOT: return 973;
				case LBRACKET: return 828;
				case LPAREN: return 603;
				case SELECTOR: return 965;
				case SELECTORS: return 861;
			}
			break;
		case 1011:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 269;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 1012:
			switch(symbol) {
				case BOOLEAN_LIT: return 508;
				case CHAR_LIT: return 184;
				case EXPRESSION2: return 723;
				case EXPRESSION3: return 111;
				case ID: return 288;
				case INT_LIT: return 256;
				case LITERAL: return 515;
				case LPAREN: return 690;
				case MINUS: return 672;
				case NEW: return 227;
				case NOT: return 235;
				case NULL_LIT: return 408;
				case PRIMARY: return 569;
				case STRING_LIT: return 535;
				case THIS: return 70;
			}
			break;
		case 1013:
			switch(symbol) {
				case ARRAY: return 1113;
			}
			break;
		case 1016:
			switch(symbol) {
				case RPAREN: return 586;
			}
			break;
		case 1017:
			switch(symbol) {
				case ARGUMENTS: return 410;
				case DOT: return 1047;
				case LBRACKET: return 382;
				case LPAREN: return 123;
				case SELECTOR: return 116;
				case SELECTORS: return 387;
			}
			break;
		case 1020:
			switch(symbol) {
				case ID: return 1109;
			}
			break;
		case 1022:
			switch(symbol) {
				case LPAREN: return 874;
			}
			break;
		case 1023:
			switch(symbol) {
				case ID: return 1029;
			}
			break;
		case 1024:
			switch(symbol) {
				case RPAREN: return 493;
			}
			break;
		case 1026:
			switch(symbol) {
				case FORMAL_PARAMETERS: return 728;
				case INTERFACE_METHOD_DECLARATOR_REST: return 686;
				case LPAREN: return 580;
			}
			break;
		case 1028:
			switch(symbol) {
				case CLASS_BODY: return 153;
				case COMMA: return 405;
				case LBRACE: return 561;
			}
			break;
		case 1031:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case EXPRESSION1_REST: return 1152;
				case EXPRESSION_INFIX: return 337;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 703;
				case INSTANCEOF: return 552;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 1034:
			switch(symbol) {
				case RPAREN: return 1167;
			}
			break;
		case 1043:
			switch(symbol) {
				case RPAREN: return 374;
			}
			break;
		case 1045:
			switch(symbol) {
				case BOOLEAN_LIT: return 86;
				case CHAR_LIT: return 758;
				case EXPRESSION2: return 808;
				case EXPRESSION3: return 516;
				case ID: return 417;
				case INT_LIT: return 335;
				case LITERAL: return 225;
				case LPAREN: return 58;
				case MINUS: return 258;
				case NEW: return 712;
				case NOT: return 663;
				case NULL_LIT: return 560;
				case PRIMARY: return 44;
				case STRING_LIT: return 171;
				case THIS: return 453;
			}
			break;
		case 1047:
			switch(symbol) {
				case ID: return 1085;
			}
			break;
		case 1049:
			switch(symbol) {
				case BOOLEAN_LIT: return 366;
				case CHAR_LIT: return 345;
				case EXPRESSION3: return 623;
				case ID: return 282;
				case INT_LIT: return 161;
				case LITERAL: return 166;
				case LPAREN: return 90;
				case NEW: return 333;
				case NOT: return 312;
				case NULL_LIT: return 177;
				case PRIMARY: return 194;
				case STRING_LIT: return 547;
				case THIS: return 396;
			}
			break;
		case 1050:
			switch(symbol) {
				case RPAREN: return 923;
			}
			break;
		case 1052:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 528;
				case CLASS_CREATOR_REST: return 794;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 1054:
			switch(symbol) {
				case AND: return 46;
				case DIV: return 285;
				case EAGER_AND: return 27;
				case EAGER_OR: return 127;
				case EQ: return 283;
				case GEQ: return 15;
				case GT: return 286;
				case INFIX_OP: return 1012;
				case LEQ: return 24;
				case LT: return 275;
				case MINUS: return 361;
				case MULT: return 114;
				case NEQ: return 352;
				case OR: return 252;
				case PLUS: return 9;
				case REMAINDER: return 106;
				case XOR: return 154;
			}
			break;
		case 1056:
			switch(symbol) {
				case BOOLEAN_LIT: return 86;
				case CHAR_LIT: return 758;
				case EXPRESSION3: return 1044;
				case ID: return 417;
				case INT_LIT: return 335;
				case LITERAL: return 225;
				case LPAREN: return 58;
				case NEW: return 712;
				case NOT: return 663;
				case NULL_LIT: return 560;
				case PRIMARY: return 44;
				case STRING_LIT: return 171;
				case THIS: return 453;
			}
			break;
		case 1057:
			switch(symbol) {
				case ID: return 1139;
				case LONG_IDENTIFIER: return 843;
			}
			break;
		case 1061:
			switch(symbol) {
				case RPAREN: return 529;
			}
			break;
		case 1063:
			switch(symbol) {
				case BOOLEAN_LIT: return 68;
				case CHAR_LIT: return 435;
				case EXPRESSION2: return 1116;
				case EXPRESSION3: return 575;
				case ID: return 350;
				case INT_LIT: return 415;
				case LITERAL: return 98;
				case LPAREN: return 261;
				case MINUS: return 290;
				case NEW: return 102;
				case NOT: return 3;
				case NULL_LIT: return 5;
				case PRIMARY: return 234;
				case STRING_LIT: return 311;
				case THIS: return 371;
			}
			break;
		case 1064:
			switch(symbol) {
				case ARGUMENTS: return 511;
				case DOT: return 878;
				case LBRACKET: return 821;
				case LPAREN: return 1074;
				case SELECTOR: return 440;
			}
			break;
		case 1074:
			switch(symbol) {
				case BOOLEAN_LIT: return 284;
				case CHAR_LIT: return 250;
				case EXPRESSION: return 139;
				case EXPRESSION1: return 62;
				case EXPRESSION2: return 63;
				case EXPRESSION3: return 64;
				case EXPRESSION_LIST: return 731;
				case ID: return 19;
				case INT_LIT: return 218;
				case LITERAL: return 397;
				case LPAREN: return 59;
				case MINUS: return 115;
				case NEW: return 20;
				case NOT: return 34;
				case NULL_LIT: return 130;
				case PRIMARY: return 212;
				case RPAREN: return 766;
				case STRING_LIT: return 303;
				case THIS: return 26;
			}
			break;
		case 1076:
			switch(symbol) {
				case ARRAY: return 856;
				case DOT: return 769;
			}
			break;
		case 1077:
			switch(symbol) {
				case RBRACKET: return 1157;
			}
			break;
		case 1078:
			switch(symbol) {
				case RBRACKET: return 956;
			}
			break;
		case 1080:
			switch(symbol) {
				case ID: return 1026;
			}
			break;
		case 1082:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION: return 1121;
				case EXPRESSION1: return 80;
				case EXPRESSION2: return 81;
				case EXPRESSION3: return 82;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case MINUS: return 138;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 1083:
			switch(symbol) {
				case BASIC_TYPE: return 395;
				case BOOLEAN: return 932;
				case BYTE: return 399;
				case CHAR: return 224;
				case ID: return 172;
				case INT: return 39;
				case LONG_IDENTIFIER: return 650;
				case SHORT: return 279;
				case TYPE: return 133;
				case TYPE_LIST: return 1028;
			}
			break;
		case 1089:
			switch(symbol) {
				case BOOLEAN_LIT: return 219;
				case CHAR_LIT: return 73;
				case EXPRESSION2: return 970;
				case EXPRESSION3: return 35;
				case ID: return 483;
				case INT_LIT: return 386;
				case LITERAL: return 280;
				case LPAREN: return 87;
				case MINUS: return 11;
				case NEW: return 292;
				case NOT: return 281;
				case NULL_LIT: return 29;
				case PRIMARY: return 192;
				case STRING_LIT: return 287;
				case THIS: return 83;
			}
			break;
		case 1096:
			switch(symbol) {
				case RPAREN: return 709;
			}
			break;
		case 1097:
			switch(symbol) {
				case ARGUMENTS: return 963;
				case DOT: return 921;
				case LBRACKET: return 739;
				case LPAREN: return 429;
				case SELECTOR: return 530;
				case SELECTORS: return 249;
			}
			break;
		case 1099:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 875;
			}
			break;
		case 1105:
			switch(symbol) {
				case RPAREN: return 1163;
			}
			break;
		case 1106:
			switch(symbol) {
				case RPAREN: return 400;
			}
			break;
		case 1107:
			switch(symbol) {
				case ID: return 746;
				case LONG_IDENTIFIER: return 587;
				case QUALIFIED_IDENTIFIER: return 266;
			}
			break;
		case 1108:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 37;
			}
			break;
		case 1112:
			switch(symbol) {
				case BOOLEAN_LIT: return 197;
				case CHAR_LIT: return 228;
				case EXPRESSION2: return 339;
				case EXPRESSION3: return 340;
				case ID: return 56;
				case INT_LIT: return 162;
				case LITERAL: return 463;
				case LPAREN: return 217;
				case MINUS: return 299;
				case NEW: return 274;
				case NOT: return 260;
				case NULL_LIT: return 31;
				case PRIMARY: return 334;
				case STRING_LIT: return 221;
				case THIS: return 254;
			}
			break;
		case 1114:
			switch(symbol) {
				case ID: return 354;
			}
			break;
		case 1117:
			switch(symbol) {
				case COMMA: return 405;
				case INTERFACE_BODY: return 174;
				case LBRACE: return 448;
			}
			break;
		case 1121:
			switch(symbol) {
				case RBRACKET: return 599;
			}
			break;
		case 1123:
			switch(symbol) {
				case BOOLEAN_LIT: return 461;
				case CHAR_LIT: return 96;
				case EXPRESSION2: return 993;
				case EXPRESSION3: return 246;
				case ID: return 298;
				case INT_LIT: return 360;
				case LITERAL: return 205;
				case LPAREN: return 698;
				case MINUS: return 747;
				case NEW: return 247;
				case NOT: return 216;
				case NULL_LIT: return 522;
				case PRIMARY: return 678;
				case STRING_LIT: return 523;
				case THIS: return 146;
			}
			break;
		case 1128:
			switch(symbol) {
				case COMPILER_UNIT: return 752;
				case PACKAGE: return 1107;
				case PACKAGE_DECLARATION: return 66;
			}
			break;
		case 1134:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 411;
			}
			break;
		case 1135:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 976;
			}
			break;
		case 1137:
			switch(symbol) {
				case RBRACKET: return 1042;
			}
			break;
		case 1140:
			switch(symbol) {
				case ID: return 1072;
			}
			break;
		case 1141:
			switch(symbol) {
				case ARGUMENTS: return 107;
				case ARRAY_CREATOR_REST: return 835;
				case CLASS_CREATOR_REST: return 513;
				case LBRACKET: return 124;
				case LPAREN: return 390;
			}
			break;
		case 1143:
			switch(symbol) {
				case ARRAY: return 644;
				case DOT: return 195;
			}
			break;
		case 1145:
			switch(symbol) {
				case ARGUMENTS: return 291;
				case DOT: return 999;
				case LBRACKET: return 873;
				case LPAREN: return 783;
				case SELECTOR: return 757;
				case SELECTORS: return 890;
			}
			break;
		case 1147:
			switch(symbol) {
				case ID: return 527;
			}
			break;
		case 1149:
			switch(symbol) {
				case ARGUMENTS: return 866;
				case DOT: return 308;
				case LBRACKET: return 732;
				case LPAREN: return 471;
				case SELECTOR: return 742;
			}
			break;
		case 1151:
			switch(symbol) {
				case BASIC_TYPE: return 395;
				case BOOLEAN: return 932;
				case BYTE: return 399;
				case CHAR: return 224;
				case ID: return 172;
				case INT: return 39;
				case LONG_IDENTIFIER: return 650;
				case SHORT: return 279;
				case TYPE: return 133;
				case TYPE_LIST: return 1117;
			}
			break;
		case 1161:
			switch(symbol) {
				case ARGUMENTS: return 475;
				case DOT: return 167;
				case LBRACKET: return 468;
				case LPAREN: return 459;
				case SELECTOR: return 550;
			}
			break;
		case 1163:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 119;
				case EXPRESSION3: return 854;
				case ID: return 455;
				case INT_LIT: return 336;
				case LITERAL: return 7;
				case LPAREN: return 155;
				case NEW: return 21;
				case NOT: return 208;
				case NULL_LIT: return 229;
				case PRIMARY: return 431;
				case STRING_LIT: return 315;
				case THIS: return 132;
			}
			break;
		case 1165:
			switch(symbol) {
				case ID: return 584;
			}
			break;
		case 1166:
			switch(symbol) {
				case COMMA: return 226;
				case RPAREN: return 372;
			}
			break;
		case 1167:
			switch(symbol) {
				case BOOLEAN_LIT: return 323;
				case CHAR_LIT: return 55;
				case EXPRESSION3: return 379;
				case ID: return 67;
				case INT_LIT: return 2;
				case LITERAL: return 140;
				case LPAREN: return 188;
				case NEW: return 75;
				case NOT: return 33;
				case NULL_LIT: return 147;
				case PRIMARY: return 262;
				case STRING_LIT: return 176;
				case THIS: return 45;
			}
			break;
		case 1168:
			switch(symbol) {
				case RPAREN: return 968;
			}
			break;
		case 1169:
			switch(symbol) {
				case LPAREN: return 13;
			}
			break;
	}
	return -1;
}

int stateReduce(int currState, int symbol)
{
	switch(currState) {
		case 1:
			switch(symbol) {
				case ABSTRACT: return 110;
				case BOOLEAN: return 110;
				case BYTE: return 110;
				case CHAR: return 110;
				case FINAL: return 110;
				case ID: return 110;
				case INT: return 110;
				case NATIVE: return 110;
				case PROTECTED: return 110;
				case PUBLIC: return 110;
				case SHORT: return 110;
				case STATIC: return 110;
				case VOID: return 110;
			}
			break;
		case 2:
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
		case 4:
			switch(symbol) {
				case ID: return 9;
			}
			break;
		case 5:
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
		case 7:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 8:
			switch(symbol) {
				case END_TERMINAL: return 116;
			}
			break;
		case 9:
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
		case 15:
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
		case 16:
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
		case 18:
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
		case 19:
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
		case 22:
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
		case 23:
			switch(symbol) {
				case RPAREN: return 62;
			}
			break;
		case 24:
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
		case 25:
			switch(symbol) {
				case ARRAY: return 64;
				case SEMICOLON: return 64;
			}
			break;
		case 26:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case COMMA: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 27:
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
		case 28:
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
		case 29:
			switch(symbol) {
				case AND: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
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
		case 30:
			switch(symbol) {
				case BOOLEAN: return 102;
				case BYTE: return 102;
				case CHAR: return 102;
				case ID: return 102;
				case INT: return 102;
				case SHORT: return 102;
				case VOID: return 102;
			}
			break;
		case 31:
			switch(symbol) {
				case AND: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
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
		case 35:
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
		case 36:
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
		case 37:
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
				case LPAREN: return 70;
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
		case 39:
			switch(symbol) {
				case ARRAY: return 65;
				case COMMA: return 65;
				case LBRACE: return 65;
			}
			break;
		case 43:
			switch(symbol) {
				case DOT: return 1;
				case LPAREN: return 1;
			}
			break;
		case 44:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
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
		case 45:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 46:
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
		case 49:
			switch(symbol) {
				case COMMA: return 167;
				case RPAREN: return 167;
			}
			break;
		case 50:
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
				case LPAREN: return 58;
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
		case 51:
			switch(symbol) {
				case END_TERMINAL: return 131;
			}
			break;
		case 52:
			switch(symbol) {
				case ID: return 11;
			}
			break;
		case 53:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 54:
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
		case 55:
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
		case 56:
			switch(symbol) {
				case AND: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
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
		case 60:
			switch(symbol) {
				case LPAREN: return 3;
			}
			break;
		case 61:
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
		case 62:
			switch(symbol) {
				case COMMA: return 30;
				case RPAREN: return 30;
			}
			break;
		case 63:
			switch(symbol) {
				case ASSIGN: return 33;
				case COMMA: return 33;
				case RPAREN: return 33;
			}
			break;
		case 64:
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
		case 65:
			switch(symbol) {
				case ARRAY: return 64;
				case ID: return 64;
			}
			break;
		case 66:
			switch(symbol) {
				case ABSTRACT: return 120;
				case CLASS: return 120;
				case END_TERMINAL: return 120;
				case FINAL: return 120;
				case INTERFACE: return 120;
				case NATIVE: return 120;
				case PROTECTED: return 120;
				case PUBLIC: return 120;
				case SEMICOLON: return 120;
				case STATIC: return 120;
			}
			break;
		case 67:
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
		case 68:
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
		case 69:
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
		case 70:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 71:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
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
		case 72:
			switch(symbol) {
				case RPAREN: return 66;
			}
			break;
		case 73:
			switch(symbol) {
				case AND: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
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
		case 74:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
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
		case 77:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 79:
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
				case LPAREN: return 60;
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
		case 80:
			switch(symbol) {
				case RBRACKET: return 30;
			}
			break;
		case 81:
			switch(symbol) {
				case ASSIGN: return 33;
				case RBRACKET: return 33;
			}
			break;
		case 82:
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
		case 83:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 84:
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
		case 85:
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
		case 86:
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
		case 88:
			switch(symbol) {
				case AND: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case INSTANCEOF: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case RBRACKET: return 49;
				case REMAINDER: return 49;
				case XOR: return 49;
			}
			break;
		case 89:
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
		case 91:
			switch(symbol) {
				case ABSTRACT: return 108;
				case BOOLEAN: return 108;
				case BYTE: return 108;
				case CHAR: return 108;
				case FINAL: return 108;
				case ID: return 108;
				case INT: return 108;
				case NATIVE: return 108;
				case PROTECTED: return 108;
				case PUBLIC: return 108;
				case SHORT: return 108;
				case STATIC: return 108;
				case VOID: return 108;
			}
			break;
		case 92:
			switch(symbol) {
				case ASSIGN: return 33;
				case RPAREN: return 33;
			}
			break;
		case 93:
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
				case RPAREN: return 30;
			}
			break;
		case 95:
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
		case 96:
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
		case 98:
			switch(symbol) {
				case AND: return 51;
				case COMMA: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 99:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case RPAREN: return 64;
			}
			break;
		case 100:
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
				case LPAREN: return 61;
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
		case 104:
			switch(symbol) {
				case ARRAY: return 63;
				case SEMICOLON: return 63;
			}
			break;
		case 105:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case SEMICOLON: return 1;
			}
			break;
		case 106:
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
		case 107:
			switch(symbol) {
				case RPAREN: return 75;
			}
			break;
		case 108:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
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
		case 109:
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
				case LPAREN: return 59;
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
		case 110:
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
		case 111:
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
		case 112:
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
		case 114:
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
		case 116:
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
				case LPAREN: return 57;
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
		case 118:
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
		case 119:
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
		case 120:
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
				case LPAREN: return 70;
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
		case 121:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case COMMA: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
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
		case 122:
			switch(symbol) {
				case AND: return 49;
				case ASSIGN: return 49;
				case COMMA: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case RPAREN: return 49;
				case XOR: return 49;
			}
			break;
		case 125:
			switch(symbol) {
				case CLASS: return 103;
				case END_TERMINAL: return 124;
				case INTERFACE: return 103;
			}
			break;
		case 126:
			switch(symbol) {
				case ABSTRACT: return 108;
				case CLASS: return 108;
				case FINAL: return 108;
				case INTERFACE: return 108;
				case NATIVE: return 108;
				case PROTECTED: return 108;
				case PUBLIC: return 108;
				case STATIC: return 108;
			}
			break;
		case 127:
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
		case 128:
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
		case 129:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 130:
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
		case 132:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 133:
			switch(symbol) {
				case COMMA: return 137;
				case LBRACE: return 137;
			}
			break;
		case 134:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
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
		case 135:
			switch(symbol) {
				case BOOLEAN: return 82;
				case BYTE: return 82;
				case CHAR: return 82;
				case ID: return 82;
				case INT: return 82;
				case RBRACE: return 82;
				case SHORT: return 82;
			}
			break;
		case 136:
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
				case LPAREN: return 59;
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
		case 137:
			switch(symbol) {
				case SEMICOLON: return 38;
			}
			break;
		case 139:
			switch(symbol) {
				case COMMA: return 45;
				case RPAREN: return 45;
			}
			break;
		case 140:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 142:
			switch(symbol) {
				case COMMA: return 166;
				case RPAREN: return 166;
			}
			break;
		case 143:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 144:
			switch(symbol) {
				case ABSTRACT: return 109;
				case BOOLEAN: return 109;
				case BYTE: return 109;
				case CHAR: return 109;
				case FINAL: return 109;
				case ID: return 109;
				case INT: return 109;
				case NATIVE: return 109;
				case PROTECTED: return 109;
				case PUBLIC: return 109;
				case SHORT: return 109;
				case STATIC: return 109;
				case VOID: return 109;
			}
			break;
		case 145:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case COMMA: return 64;
				case RPAREN: return 64;
			}
			break;
		case 146:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 147:
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
		case 148:
			switch(symbol) {
				case AND: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case RBRACKET: return 49;
				case REMAINDER: return 49;
				case XOR: return 49;
			}
			break;
		case 149:
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
		case 150:
			switch(symbol) {
				case DOT: return 2;
				case SEMICOLON: return 2;
			}
			break;
		case 151:
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
		case 152:
			switch(symbol) {
				case END_TERMINAL: return 133;
			}
			break;
		case 153:
			switch(symbol) {
				case END_TERMINAL: return 134;
			}
			break;
		case 154:
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
		case 157:
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
		case 159:
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
		case 161:
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
		case 162:
			switch(symbol) {
				case AND: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
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
		case 163:
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
		case 164:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 165:
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
		case 166:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 168:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 170:
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
		case 171:
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
		case 172:
			switch(symbol) {
				case ARRAY: return 1;
				case COMMA: return 1;
				case DOT: return 1;
				case LBRACE: return 1;
			}
			break;
		case 173:
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
		case 174:
			switch(symbol) {
				case END_TERMINAL: return 136;
			}
			break;
		case 175:
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
		case 176:
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
		case 177:
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
		case 181:
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
		case 184:
			switch(symbol) {
				case AND: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
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
		case 185:
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
		case 186:
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
		case 187:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
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
		case 190:
			switch(symbol) {
				case ASSIGN: return 38;
				case RPAREN: return 38;
			}
			break;
		case 191:
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
		case 192:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
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
		case 194:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
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
		case 197:
			switch(symbol) {
				case AND: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
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
		case 198:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case ID: return 1;
			}
			break;
		case 202:
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
		case 203:
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
		case 204:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case COMMA: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 205:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 206:
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
				case LPAREN: return 58;
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
		case 209:
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
		case 210:
			switch(symbol) {
				case ARRAY: return 62;
				case ID: return 62;
			}
			break;
		case 212:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case COMMA: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
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
		case 213:
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
				case LPAREN: return 70;
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
		case 218:
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
		case 219:
			switch(symbol) {
				case AND: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
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
		case 220:
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
				case LPAREN: return 60;
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
		case 221:
			switch(symbol) {
				case AND: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
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
		case 222:
			switch(symbol) {
				case RPAREN: return 140;
			}
			break;
		case 223:
			switch(symbol) {
				case ARRAY: return 66;
				case ID: return 66;
			}
			break;
		case 224:
			switch(symbol) {
				case ARRAY: return 64;
				case COMMA: return 64;
				case LBRACE: return 64;
			}
			break;
		case 225:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 228:
			switch(symbol) {
				case AND: return 5;
				case DIV: return 5;
				case DOT: return 5;
				case EAGER_AND: return 5;
				case EAGER_OR: return 5;
				case EQ: return 5;
				case GEQ: return 5;
				case GT: return 5;
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
		case 229:
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
		case 230:
			switch(symbol) {
				case BOOLEAN: return 83;
				case BYTE: return 83;
				case CHAR: return 83;
				case ID: return 83;
				case INT: return 83;
				case RBRACE: return 83;
				case SHORT: return 83;
			}
			break;
		case 232:
			switch(symbol) {
				case END_TERMINAL: return 142;
			}
			break;
		case 233:
			switch(symbol) {
				case ASSIGN: return 10;
				case RPAREN: return 10;
			}
			break;
		case 234:
			switch(symbol) {
				case AND: return 56;
				case COMMA: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
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
		case 236:
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
		case 237:
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
		case 238:
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
		case 239:
			switch(symbol) {
				case AND: return 50;
				case COMMA: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 240:
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
		case 241:
			switch(symbol) {
				case RPAREN: return 76;
			}
			break;
		case 242:
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
		case 244:
			switch(symbol) {
				case SEMICOLON: return 30;
			}
			break;
		case 245:
			switch(symbol) {
				case ASSIGN: return 33;
				case SEMICOLON: return 33;
			}
			break;
		case 246:
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
		case 249:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case COMMA: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
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
		case 250:
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
		case 252:
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
		case 253:
			switch(symbol) {
				case RPAREN: return 63;
			}
			break;
		case 254:
			switch(symbol) {
				case AND: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 255:
			switch(symbol) {
				case ABSTRACT: return 107;
				case CLASS: return 107;
				case FINAL: return 107;
				case INTERFACE: return 107;
				case NATIVE: return 107;
				case PROTECTED: return 107;
				case PUBLIC: return 107;
				case STATIC: return 107;
			}
			break;
		case 256:
			switch(symbol) {
				case AND: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
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
		case 257:
			switch(symbol) {
				case ARRAY: return 66;
				case COMMA: return 66;
				case RPAREN: return 66;
			}
			break;
		case 259:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case COMMA: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 262:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
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
		case 263:
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
		case 265:
			switch(symbol) {
				case SEMICOLON: return 112;
			}
			break;
		case 267:
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
		case 268:
			switch(symbol) {
				case AND: return 51;
				case COMMA: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 275:
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
		case 276:
			switch(symbol) {
				case ARRAY: return 66;
				case IMPLEMENTS: return 66;
				case LBRACE: return 66;
			}
			break;
		case 277:
			switch(symbol) {
				case RBRACE: return 80;
			}
			break;
		case 278:
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
		case 279:
			switch(symbol) {
				case ARRAY: return 63;
				case COMMA: return 63;
				case LBRACE: return 63;
			}
			break;
		case 280:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 282:
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
		case 283:
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
		case 284:
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
		case 285:
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
		case 286:
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
		case 287:
			switch(symbol) {
				case AND: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
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
		case 288:
			switch(symbol) {
				case AND: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
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
		case 289:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 291:
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
				case LPAREN: return 60;
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
		case 295:
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
		case 296:
			switch(symbol) {
				case AND: return 49;
				case COMMA: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case RPAREN: return 49;
				case XOR: return 49;
			}
			break;
		case 297:
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
				case LPAREN: return 58;
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
		case 298:
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
		case 300:
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
		case 301:
			switch(symbol) {
				case RBRACKET: return 31;
			}
			break;
		case 302:
			switch(symbol) {
				case RBRACKET: return 33;
			}
			break;
		case 303:
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
		case 304:
			switch(symbol) {
				case ARRAY: return 63;
				case ID: return 63;
			}
			break;
		case 306:
			switch(symbol) {
				case RPAREN: return 64;
			}
			break;
		case 307:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case COMMA: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
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
		case 309:
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
		case 310:
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
		case 311:
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
		case 314:
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
		case 315:
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
		case 316:
			switch(symbol) {
				case ABSTRACT: return 79;
				case BOOLEAN: return 79;
				case BYTE: return 79;
				case CHAR: return 79;
				case FINAL: return 79;
				case ID: return 79;
				case INT: return 79;
				case NATIVE: return 79;
				case PROTECTED: return 79;
				case PUBLIC: return 79;
				case RBRACE: return 79;
				case SEMICOLON: return 79;
				case SHORT: return 79;
				case STATIC: return 79;
				case VOID: return 79;
			}
			break;
		case 318:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 320:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case COMMA: return 63;
				case RPAREN: return 63;
			}
			break;
		case 321:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case RPAREN: return 63;
			}
			break;
		case 322:
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
		case 323:
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
		case 324:
			switch(symbol) {
				case RPAREN: return 33;
			}
			break;
		case 325:
			switch(symbol) {
				case RPAREN: return 31;
			}
			break;
		case 326:
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
		case 327:
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
		case 328:
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
		case 329:
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
				case LPAREN: return 61;
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
		case 331:
			switch(symbol) {
				case ARRAY: return 65;
				case ID: return 65;
			}
			break;
		case 334:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
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
		case 335:
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
		case 336:
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
		case 337:
			switch(symbol) {
				case SEMICOLON: return 35;
			}
			break;
		case 338:
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
		case 339:
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
		case 340:
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
		case 341:
			switch(symbol) {
				case ASSIGN: return 34;
				case RPAREN: return 34;
			}
			break;
		case 342:
			switch(symbol) {
				case SEMICOLON: return 12;
			}
			break;
		case 343:
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
		case 344:
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
				case LPAREN: return 60;
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
		case 345:
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
		case 346:
			switch(symbol) {
				case IMPLEMENTS: return 9;
				case LBRACE: return 9;
			}
			break;
		case 350:
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
		case 352:
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
		case 353:
			switch(symbol) {
				case LBRACE: return 69;
				case RPAREN: return 69;
			}
			break;
		case 354:
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
				case LPAREN: return 59;
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
		case 355:
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
				case LPAREN: return 60;
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
		case 356:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
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
		case 357:
			switch(symbol) {
				case AND: return 56;
				case COMMA: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
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
		case 358:
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
		case 359:
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
		case 360:
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
		case 361:
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
		case 362:
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
		case 363:
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
				case LPAREN: return 70;
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
		case 365:
			switch(symbol) {
				case AND: return 49;
				case ASSIGN: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case INSTANCEOF: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case SEMICOLON: return 49;
				case XOR: return 49;
			}
			break;
		case 366:
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
		case 367:
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
		case 370:
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
		case 371:
			switch(symbol) {
				case AND: return 50;
				case COMMA: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 372:
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
				case LPAREN: return 70;
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
		case 373:
			switch(symbol) {
				case ABSTRACT: return 122;
				case CLASS: return 122;
				case END_TERMINAL: return 122;
				case FINAL: return 122;
				case IMPORT: return 122;
				case INTERFACE: return 122;
				case NATIVE: return 122;
				case PROTECTED: return 122;
				case PUBLIC: return 122;
				case SEMICOLON: return 122;
				case STATIC: return 122;
			}
			break;
		case 374:
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
		case 376:
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
		case 377:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 378:
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
		case 379:
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
		case 380:
			switch(symbol) {
				case ABSTRACT: return 106;
				case CLASS: return 106;
				case FINAL: return 106;
				case INTERFACE: return 106;
				case NATIVE: return 106;
				case PROTECTED: return 106;
				case PUBLIC: return 106;
				case STATIC: return 106;
			}
			break;
		case 381:
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
		case 383:
			switch(symbol) {
				case COMMA: return 138;
				case LBRACE: return 138;
			}
			break;
		case 384:
			switch(symbol) {
				case END_TERMINAL: return 140;
			}
			break;
		case 385:
			switch(symbol) {
				case END_TERMINAL: return 132;
			}
			break;
		case 386:
			switch(symbol) {
				case AND: return 4;
				case DIV: return 4;
				case DOT: return 4;
				case EAGER_AND: return 4;
				case EAGER_OR: return 4;
				case EQ: return 4;
				case GEQ: return 4;
				case GT: return 4;
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
		case 387:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
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
		case 388:
			switch(symbol) {
				case ARRAY: return 65;
				case RPAREN: return 65;
			}
			break;
		case 391:
			switch(symbol) {
				case RPAREN: return 65;
			}
			break;
		case 392:
			switch(symbol) {
				case ARRAY: return 65;
				case ASSIGN: return 65;
				case COMMA: return 65;
				case RPAREN: return 65;
			}
			break;
		case 394:
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
		case 395:
			switch(symbol) {
				case COMMA: return 11;
				case LBRACE: return 11;
			}
			break;
		case 396:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 397:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case COMMA: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 399:
			switch(symbol) {
				case ARRAY: return 62;
				case COMMA: return 62;
				case LBRACE: return 62;
			}
			break;
		case 400:
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
		case 404:
			switch(symbol) {
				case ARRAY: return 62;
				case COMMA: return 62;
				case RPAREN: return 62;
			}
			break;
		case 408:
			switch(symbol) {
				case AND: return 8;
				case DIV: return 8;
				case DOT: return 8;
				case EAGER_AND: return 8;
				case EAGER_OR: return 8;
				case EQ: return 8;
				case GEQ: return 8;
				case GT: return 8;
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
		case 409:
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
		case 410:
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
				case LPAREN: return 60;
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
		case 411:
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
				case LPAREN: return 70;
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
		case 412:
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
		case 414:
			switch(symbol) {
				case COMMA: return 46;
				case RPAREN: return 46;
			}
			break;
		case 415:
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
		case 417:
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
		case 419:
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
		case 420:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
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
		case 422:
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
		case 423:
			switch(symbol) {
				case AND: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
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
		case 424:
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
		case 425:
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
		case 430:
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
		case 431:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
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
		case 435:
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
		case 437:
			switch(symbol) {
				case AND: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
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
		case 438:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
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
		case 439:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
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
		case 440:
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
				case LPAREN: return 58;
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
		case 441:
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
		case 443:
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
		case 445:
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
		case 446:
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
		case 447:
			switch(symbol) {
				case AND: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
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
		case 448:
			switch(symbol) {
				case BOOLEAN: return 103;
				case BYTE: return 103;
				case CHAR: return 103;
				case ID: return 103;
				case INT: return 103;
				case SHORT: return 103;
				case VOID: return 103;
			}
			break;
		case 449:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case SEMICOLON: return 2;
			}
			break;
		case 451:
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
				case LPAREN: return 57;
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
		case 452:
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
				case LPAREN: return 59;
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
		case 453:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 454:
			switch(symbol) {
				case COMMA: return 168;
				case RPAREN: return 168;
			}
			break;
		case 455:
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
		case 461:
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
		case 462:
			switch(symbol) {
				case AND: return 51;
				case ASSIGN: return 51;
				case COMMA: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 463:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 464:
			switch(symbol) {
				case ASSIGN: return 34;
				case COMMA: return 34;
				case RPAREN: return 34;
			}
			break;
		case 466:
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
		case 469:
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
		case 470:
			switch(symbol) {
				case ABSTRACT: return 106;
				case BOOLEAN: return 106;
				case BYTE: return 106;
				case CHAR: return 106;
				case FINAL: return 106;
				case ID: return 106;
				case INT: return 106;
				case NATIVE: return 106;
				case PROTECTED: return 106;
				case PUBLIC: return 106;
				case SHORT: return 106;
				case STATIC: return 106;
				case VOID: return 106;
			}
			break;
		case 472:
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
		case 475:
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
				case LPAREN: return 60;
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
		case 481:
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
				case LPAREN: return 59;
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
		case 482:
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
		case 483:
			switch(symbol) {
				case AND: return 53;
				case DIV: return 53;
				case DOT: return 53;
				case EAGER_AND: return 53;
				case EAGER_OR: return 53;
				case EQ: return 53;
				case GEQ: return 53;
				case GT: return 53;
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
		case 486:
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
		case 487:
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
		case 489:
			switch(symbol) {
				case ABSTRACT: return 104;
				case BOOLEAN: return 104;
				case BYTE: return 104;
				case CHAR: return 104;
				case FINAL: return 104;
				case ID: return 104;
				case INT: return 104;
				case NATIVE: return 104;
				case PROTECTED: return 104;
				case PUBLIC: return 104;
				case SHORT: return 104;
				case STATIC: return 104;
				case VOID: return 104;
			}
			break;
		case 491:
			switch(symbol) {
				case END_TERMINAL: return 127;
			}
			break;
		case 492:
			switch(symbol) {
				case ABSTRACT: return 107;
				case BOOLEAN: return 107;
				case BYTE: return 107;
				case CHAR: return 107;
				case FINAL: return 107;
				case ID: return 107;
				case INT: return 107;
				case NATIVE: return 107;
				case PROTECTED: return 107;
				case PUBLIC: return 107;
				case SHORT: return 107;
				case STATIC: return 107;
				case VOID: return 107;
			}
			break;
		case 493:
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
		case 494:
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
		case 496:
			switch(symbol) {
				case BOOLEAN: return 103;
				case BYTE: return 103;
				case CHAR: return 103;
				case ID: return 103;
				case INT: return 103;
				case SHORT: return 103;
				case VOID: return 103;
			}
			break;
		case 497:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
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
		case 499:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
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
		case 500:
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
		case 501:
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
		case 502:
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
		case 503:
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
		case 504:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case COMMA: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
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
		case 505:
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
				case LPAREN: return 61;
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
		case 506:
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
		case 507:
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
		case 508:
			switch(symbol) {
				case AND: return 7;
				case DIV: return 7;
				case DOT: return 7;
				case EAGER_AND: return 7;
				case EAGER_OR: return 7;
				case EQ: return 7;
				case GEQ: return 7;
				case GT: return 7;
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
		case 510:
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
		case 511:
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
				case LPAREN: return 60;
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
		case 512:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case RBRACKET: return 64;
			}
			break;
		case 515:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 516:
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
		case 517:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
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
		case 518:
			switch(symbol) {
				case LBRACE: return 165;
			}
			break;
		case 519:
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
		case 520:
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
				case LPAREN: return 70;
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
		case 521:
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
		case 522:
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
		case 523:
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
		case 524:
			switch(symbol) {
				case ASSIGN: return 12;
				case SEMICOLON: return 12;
			}
			break;
		case 527:
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
		case 529:
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
		case 530:
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
				case LPAREN: return 57;
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
		case 532:
			switch(symbol) {
				case END_TERMINAL: return 129;
			}
			break;
		case 533:
			switch(symbol) {
				case END_TERMINAL: return 130;
			}
			break;
		case 534:
			switch(symbol) {
				case ABSTRACT: return 144;
				case BOOLEAN: return 144;
				case BYTE: return 144;
				case CHAR: return 144;
				case FINAL: return 144;
				case ID: return 144;
				case INT: return 144;
				case NATIVE: return 144;
				case PROTECTED: return 144;
				case PUBLIC: return 144;
				case RBRACE: return 144;
				case SEMICOLON: return 144;
				case SHORT: return 144;
				case STATIC: return 144;
				case VOID: return 144;
			}
			break;
		case 535:
			switch(symbol) {
				case AND: return 6;
				case DIV: return 6;
				case DOT: return 6;
				case EAGER_AND: return 6;
				case EAGER_OR: return 6;
				case EQ: return 6;
				case GEQ: return 6;
				case GT: return 6;
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
		case 536:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case RBRACKET: return 63;
			}
			break;
		case 538:
			switch(symbol) {
				case END_TERMINAL: return 123;
			}
			break;
		case 539:
			switch(symbol) {
				case AND: return 49;
				case COMMA: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case INSTANCEOF: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case RPAREN: return 49;
				case XOR: return 49;
			}
			break;
		case 541:
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
		case 543:
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
		case 544:
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
		case 545:
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
		case 547:
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
		case 549:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case ID: return 2;
			}
			break;
		case 550:
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
				case LPAREN: return 58;
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
		case 551:
			switch(symbol) {
				case END_TERMINAL: return 141;
			}
			break;
		case 553:
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
		case 554:
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
		case 557:
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
				case LPAREN: return 61;
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
		case 559:
			switch(symbol) {
				case END_TERMINAL: return 139;
			}
			break;
		case 560:
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
		case 561:
			switch(symbol) {
				case BOOLEAN: return 103;
				case BYTE: return 103;
				case CHAR: return 103;
				case ID: return 103;
				case INT: return 103;
				case SHORT: return 103;
				case VOID: return 103;
			}
			break;
		case 562:
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
		case 563:
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
		case 564:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case ID: return 1;
			}
			break;
		case 565:
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
				case LPAREN: return 69;
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
		case 566:
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
				case LPAREN: return 61;
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
		case 568:
			switch(symbol) {
				case END_TERMINAL: return 128;
			}
			break;
		case 569:
			switch(symbol) {
				case AND: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
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
		case 570:
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
		case 572:
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
				case LPAREN: return 59;
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
		case 573:
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
		case 574:
			switch(symbol) {
				case COMMA: return 33;
				case RPAREN: return 33;
			}
			break;
		case 575:
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
		case 576:
			switch(symbol) {
				case COMMA: return 31;
				case RPAREN: return 31;
			}
			break;
		case 577:
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
				case LPAREN: return 58;
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
		case 578:
			switch(symbol) {
				case ABSTRACT: return 104;
				case CLASS: return 104;
				case FINAL: return 104;
				case INTERFACE: return 104;
				case NATIVE: return 104;
				case PROTECTED: return 104;
				case PUBLIC: return 104;
				case STATIC: return 104;
			}
			break;
		case 581:
			switch(symbol) {
				case COMMA: return 35;
				case RPAREN: return 35;
			}
			break;
		case 582:
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
				case LPAREN: return 59;
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
		case 583:
			switch(symbol) {
				case ASSIGN: return 12;
				case COMMA: return 12;
				case RPAREN: return 12;
			}
			break;
		case 584:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case DOT: return 2;
				case SEMICOLON: return 2;
			}
			break;
		case 586:
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
		case 587:
			switch(symbol) {
				case SEMICOLON: return 3;
			}
			break;
		case 588:
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
				case LPAREN: return 69;
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
		case 589:
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
				case LPAREN: return 57;
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
		case 590:
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
				case LPAREN: return 61;
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
		case 593:
			switch(symbol) {
				case ABSTRACT: return 126;
				case CLASS: return 126;
				case END_TERMINAL: return 126;
				case FINAL: return 126;
				case IMPORT: return 126;
				case INTERFACE: return 126;
				case NATIVE: return 126;
				case PROTECTED: return 126;
				case PUBLIC: return 126;
				case SEMICOLON: return 126;
				case STATIC: return 126;
			}
			break;
		case 594:
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
		case 598:
			switch(symbol) {
				case IMPLEMENTS: return 10;
				case LBRACE: return 10;
			}
			break;
		case 599:
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
				case LPAREN: return 61;
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
		case 600:
			switch(symbol) {
				case ARRAY: return 62;
				case RBRACKET: return 62;
			}
			break;
		case 601:
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
		case 602:
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
		case 607:
			switch(symbol) {
				case AND: return 51;
				case DIV: return 51;
				case DOT: return 51;
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
		case 610:
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
				case LPAREN: return 59;
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
		case 611:
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
		case 612:
			switch(symbol) {
				case ARRAY: return 65;
				case ASSIGN: return 65;
				case SEMICOLON: return 65;
			}
			break;
		case 613:
			switch(symbol) {
				case SEMICOLON: return 165;
			}
			break;
		case 615:
			switch(symbol) {
				case AND: return 71;
				case DIV: return 71;
				case DOT: return 71;
				case EAGER_AND: return 71;
				case EAGER_OR: return 71;
				case EQ: return 71;
				case GEQ: return 71;
				case GT: return 71;
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
		case 617:
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
		case 618:
			switch(symbol) {
				case BOOLEAN: return 84;
				case BYTE: return 84;
				case CHAR: return 84;
				case ID: return 84;
				case INT: return 84;
				case RBRACE: return 84;
				case SHORT: return 84;
			}
			break;
		case 619:
			switch(symbol) {
				case BOOLEAN: return 103;
				case BYTE: return 103;
				case CHAR: return 103;
				case ID: return 103;
				case INT: return 103;
				case SHORT: return 103;
				case VOID: return 103;
			}
			break;
		case 620:
			switch(symbol) {
				case ARRAY: return 66;
				case RPAREN: return 66;
			}
			break;
		case 621:
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
				case LPAREN: return 61;
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
		case 623:
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
		case 624:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
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
		case 625:
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
		case 626:
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
		case 627:
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
				case LPAREN: return 69;
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
		case 629:
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
		case 630:
			switch(symbol) {
				case ASSIGN: return 9;
				case COMMA: return 9;
				case RPAREN: return 9;
			}
			break;
		case 633:
			switch(symbol) {
				case COMMA: return 34;
				case RPAREN: return 34;
			}
			break;
		case 634:
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
		case 635:
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
		case 636:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
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
		case 637:
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
				case LPAREN: return 57;
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
		case 638:
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
		case 639:
			switch(symbol) {
				case RPAREN: return 74;
			}
			break;
		case 640:
			switch(symbol) {
				case AND: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case INSTANCEOF: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case RPAREN: return 49;
				case XOR: return 49;
			}
			break;
		case 641:
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
		case 643:
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
				case LPAREN: return 57;
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
		case 644:
			switch(symbol) {
				case COMMA: return 10;
				case RPAREN: return 10;
			}
			break;
		case 645:
			switch(symbol) {
				case ASSIGN: return 10;
				case COMMA: return 10;
				case RPAREN: return 10;
			}
			break;
		case 646:
			switch(symbol) {
				case COMMA: return 115;
				case RPAREN: return 115;
			}
			break;
		case 647:
			switch(symbol) {
				case ARRAY: return 65;
				case ASSIGN: return 65;
				case RPAREN: return 65;
			}
			break;
		case 648:
			switch(symbol) {
				case ARRAY: return 2;
				case COMMA: return 2;
				case DOT: return 2;
				case LBRACE: return 2;
			}
			break;
		case 649:
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
				case LPAREN: return 60;
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
		case 650:
			switch(symbol) {
				case COMMA: return 9;
				case LBRACE: return 9;
			}
			break;
		case 651:
			switch(symbol) {
				case ARRAY: return 65;
				case ASSIGN: return 65;
				case RBRACKET: return 65;
			}
			break;
		case 652:
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
		case 653:
			switch(symbol) {
				case ABSTRACT: return 119;
				case CLASS: return 119;
				case END_TERMINAL: return 119;
				case FINAL: return 119;
				case INTERFACE: return 119;
				case NATIVE: return 119;
				case PROTECTED: return 119;
				case PUBLIC: return 119;
				case SEMICOLON: return 119;
				case STATIC: return 119;
			}
			break;
		case 654:
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
		case 656:
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
				case LPAREN: return 70;
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
		case 658:
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
		case 659:
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
		case 660:
			switch(symbol) {
				case ASSIGN: return 9;
				case SEMICOLON: return 9;
			}
			break;
		case 661:
			switch(symbol) {
				case AND: return 49;
				case ASSIGN: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case INSTANCEOF: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case RPAREN: return 49;
				case XOR: return 49;
			}
			break;
		case 662:
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
				case LPAREN: return 59;
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
		case 666:
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
				case LPAREN: return 57;
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
		case 667:
			switch(symbol) {
				case IMPLEMENTS: return 11;
				case LBRACE: return 11;
			}
			break;
		case 668:
			switch(symbol) {
				case AND: return 50;
				case ASSIGN: return 50;
				case COMMA: return 50;
				case DIV: return 50;
				case DOT: return 50;
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
		case 671:
			switch(symbol) {
				case AND: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
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
		case 673:
			switch(symbol) {
				case ABSTRACT: return 145;
				case BOOLEAN: return 145;
				case BYTE: return 145;
				case CHAR: return 145;
				case FINAL: return 145;
				case ID: return 145;
				case INT: return 145;
				case NATIVE: return 145;
				case PROTECTED: return 145;
				case PUBLIC: return 145;
				case RBRACE: return 145;
				case SEMICOLON: return 145;
				case SHORT: return 145;
				case STATIC: return 145;
				case VOID: return 145;
			}
			break;
		case 674:
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
		case 675:
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
				case LPAREN: return 70;
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
		case 676:
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
		case 677:
			switch(symbol) {
				case ASSIGN: return 35;
				case COMMA: return 35;
				case RPAREN: return 35;
			}
			break;
		case 678:
			switch(symbol) {
				case AND: return 56;
				case ASSIGN: return 56;
				case DIV: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case INSTANCEOF: return 56;
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
		case 679:
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
		case 681:
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
				case LPAREN: return 69;
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
		case 684:
			switch(symbol) {
				case AND: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
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
		case 685:
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
		case 686:
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
		case 687:
			switch(symbol) {
				case RBRACE: return 81;
			}
			break;
		case 691:
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
		case 692:
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
		case 693:
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
		case 694:
			switch(symbol) {
				case ARRAY: return 65;
				case IMPLEMENTS: return 65;
				case LBRACE: return 65;
			}
			break;
		case 695:
			switch(symbol) {
				case ASSIGN: return 11;
				case RPAREN: return 11;
			}
			break;
		case 696:
			switch(symbol) {
				case RPAREN: return 9;
			}
			break;
		case 701:
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
		case 702:
			switch(symbol) {
				case ABSTRACT: return 110;
				case CLASS: return 110;
				case FINAL: return 110;
				case INTERFACE: return 110;
				case NATIVE: return 110;
				case PROTECTED: return 110;
				case PUBLIC: return 110;
				case STATIC: return 110;
			}
			break;
		case 704:
			switch(symbol) {
				case ARRAY: return 66;
				case ASSIGN: return 66;
				case SEMICOLON: return 66;
			}
			break;
		case 705:
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
		case 706:
			switch(symbol) {
				case COMMA: return 12;
				case LBRACE: return 12;
			}
			break;
		case 707:
			switch(symbol) {
				case ARRAY: return 63;
				case IMPLEMENTS: return 63;
				case LBRACE: return 63;
			}
			break;
		case 708:
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
				case LPAREN: return 57;
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
		case 713:
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
				case LPAREN: return 61;
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
		case 714:
			switch(symbol) {
				case SEMICOLON: return 77;
			}
			break;
		case 716:
			switch(symbol) {
				case ABSTRACT: return 109;
				case CLASS: return 109;
				case FINAL: return 109;
				case INTERFACE: return 109;
				case NATIVE: return 109;
				case PROTECTED: return 109;
				case PUBLIC: return 109;
				case STATIC: return 109;
			}
			break;
		case 719:
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
				case LPAREN: return 69;
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
		case 720:
			switch(symbol) {
				case SEMICOLON: return 11;
			}
			break;
		case 721:
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
		case 722:
			switch(symbol) {
				case ARRAY: return 66;
				case ASSIGN: return 66;
				case RBRACKET: return 66;
			}
			break;
		case 723:
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
		case 725:
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
		case 726:
			switch(symbol) {
				case BOOLEAN: return 85;
				case BYTE: return 85;
				case CHAR: return 85;
				case ID: return 85;
				case INT: return 85;
				case RBRACE: return 85;
				case SHORT: return 85;
			}
			break;
		case 727:
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
				case LPAREN: return 60;
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
		case 734:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
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
		case 736:
			switch(symbol) {
				case ASSIGN: return 35;
				case RPAREN: return 35;
			}
			break;
		case 738:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
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
		case 740:
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
		case 741:
			switch(symbol) {
				case ID: return 10;
			}
			break;
		case 742:
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
				case LPAREN: return 58;
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
		case 743:
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
		case 744:
			switch(symbol) {
				case ARRAY: return 65;
				case SEMICOLON: return 65;
			}
			break;
		case 745:
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
		case 746:
			switch(symbol) {
				case DOT: return 1;
				case SEMICOLON: return 1;
			}
			break;
		case 748:
			switch(symbol) {
				case ABSTRACT: return 143;
				case BOOLEAN: return 143;
				case BYTE: return 143;
				case CHAR: return 143;
				case FINAL: return 143;
				case ID: return 143;
				case INT: return 143;
				case NATIVE: return 143;
				case PROTECTED: return 143;
				case PUBLIC: return 143;
				case RBRACE: return 143;
				case SEMICOLON: return 143;
				case SHORT: return 143;
				case STATIC: return 143;
				case VOID: return 143;
			}
			break;
		case 753:
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
		case 755:
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
				case LPAREN: return 58;
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
		case 756:
			switch(symbol) {
				case ARRAY: return 66;
				case SEMICOLON: return 66;
			}
			break;
		case 757:
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
				case LPAREN: return 57;
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
		case 758:
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
		case 763:
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
		case 765:
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
		case 766:
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
				case LPAREN: return 69;
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
		case 768:
			switch(symbol) {
				case ABSTRACT: return 148;
				case BOOLEAN: return 148;
				case BYTE: return 148;
				case CHAR: return 148;
				case FINAL: return 148;
				case ID: return 148;
				case INT: return 148;
				case NATIVE: return 148;
				case PROTECTED: return 148;
				case PUBLIC: return 148;
				case RBRACE: return 148;
				case SEMICOLON: return 148;
				case SHORT: return 148;
				case STATIC: return 148;
				case VOID: return 148;
			}
			break;
		case 770:
			switch(symbol) {
				case ASSIGN: return 12;
				case RPAREN: return 12;
			}
			break;
		case 772:
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
		case 774:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
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
		case 775:
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
				case LPAREN: return 69;
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
		case 777:
			switch(symbol) {
				case ABSTRACT: return 117;
				case CLASS: return 117;
				case END_TERMINAL: return 117;
				case FINAL: return 117;
				case IMPORT: return 117;
				case INTERFACE: return 117;
				case NATIVE: return 117;
				case PROTECTED: return 117;
				case PUBLIC: return 117;
				case SEMICOLON: return 117;
				case STATIC: return 117;
			}
			break;
		case 779:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case IMPLEMENTS: return 1;
				case LBRACE: return 1;
			}
			break;
		case 780:
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
				case LPAREN: return 61;
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
		case 784:
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
		case 785:
			switch(symbol) {
				case COMMA: return 38;
				case RPAREN: return 38;
			}
			break;
		case 786:
			switch(symbol) {
				case BOOLEAN: return 103;
				case BYTE: return 103;
				case CHAR: return 103;
				case ID: return 103;
				case INT: return 103;
				case SHORT: return 103;
				case VOID: return 103;
			}
			break;
		case 789:
			switch(symbol) {
				case ARRAY: return 66;
				case ASSIGN: return 66;
				case RPAREN: return 66;
			}
			break;
		case 791:
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
		case 792:
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
		case 793:
			switch(symbol) {
				case ARRAY: return 1;
				case COMMA: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 795:
			switch(symbol) {
				case ARRAY: return 64;
				case IMPLEMENTS: return 64;
				case LBRACE: return 64;
			}
			break;
		case 797:
			switch(symbol) {
				case ABSTRACT: return 146;
				case BOOLEAN: return 146;
				case BYTE: return 146;
				case CHAR: return 146;
				case FINAL: return 146;
				case ID: return 146;
				case INT: return 146;
				case NATIVE: return 146;
				case PROTECTED: return 146;
				case PUBLIC: return 146;
				case RBRACE: return 146;
				case SEMICOLON: return 146;
				case SHORT: return 146;
				case STATIC: return 146;
				case VOID: return 146;
			}
			break;
		case 798:
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
				case LPAREN: return 58;
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
		case 799:
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
		case 802:
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
				case LPAREN: return 69;
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
		case 806:
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
		case 808:
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
		case 809:
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
		case 810:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
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
		case 813:
			switch(symbol) {
				case AND: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case INSTANCEOF: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case SEMICOLON: return 49;
				case XOR: return 49;
			}
			break;
		case 814:
			switch(symbol) {
				case AND: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case SEMICOLON: return 49;
				case XOR: return 49;
			}
			break;
		case 815:
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
		case 818:
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
				case LPAREN: return 59;
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
		case 820:
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
				case LPAREN: return 61;
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
		case 824:
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
		case 826:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case IMPLEMENTS: return 2;
				case LBRACE: return 2;
			}
			break;
		case 829:
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
				case LPAREN: return 58;
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
		case 830:
			switch(symbol) {
				case ASSIGN: return 11;
				case RBRACKET: return 11;
			}
			break;
		case 832:
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
		case 834:
			switch(symbol) {
				case RBRACKET: return 11;
			}
			break;
		case 836:
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
		case 837:
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
		case 838:
			switch(symbol) {
				case AND: return 54;
				case COMMA: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
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
		case 841:
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
		case 842:
			switch(symbol) {
				case ID: return 12;
			}
			break;
		case 843:
			switch(symbol) {
				case AND: return 55;
				case COMMA: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
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
		case 844:
			switch(symbol) {
				case ABSTRACT: return 105;
				case CLASS: return 105;
				case FINAL: return 105;
				case INTERFACE: return 105;
				case NATIVE: return 105;
				case PROTECTED: return 105;
				case PUBLIC: return 105;
				case STATIC: return 105;
			}
			break;
		case 846:
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
				case LPAREN: return 61;
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
		case 847:
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
		case 848:
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
		case 849:
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
		case 850:
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
		case 852:
			switch(symbol) {
				case ASSIGN: return 9;
				case RBRACKET: return 9;
			}
			break;
		case 853:
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
				case LPAREN: return 60;
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
		case 854:
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
		case 855:
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
				case LPAREN: return 69;
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
		case 856:
			switch(symbol) {
				case RBRACKET: return 10;
			}
			break;
		case 858:
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
				case LPAREN: return 57;
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
		case 859:
			switch(symbol) {
				case ABSTRACT: return 147;
				case BOOLEAN: return 147;
				case BYTE: return 147;
				case CHAR: return 147;
				case FINAL: return 147;
				case ID: return 147;
				case INT: return 147;
				case NATIVE: return 147;
				case PROTECTED: return 147;
				case PUBLIC: return 147;
				case RBRACE: return 147;
				case SEMICOLON: return 147;
				case SHORT: return 147;
				case STATIC: return 147;
				case VOID: return 147;
			}
			break;
		case 861:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
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
		case 862:
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
				case LPAREN: return 60;
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
		case 864:
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
				case LPAREN: return 58;
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
		case 866:
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
				case LPAREN: return 60;
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
		case 869:
			switch(symbol) {
				case ABSTRACT: return 121;
				case CLASS: return 121;
				case END_TERMINAL: return 121;
				case FINAL: return 121;
				case IMPORT: return 121;
				case INTERFACE: return 121;
				case NATIVE: return 121;
				case PROTECTED: return 121;
				case PUBLIC: return 121;
				case SEMICOLON: return 121;
				case STATIC: return 121;
			}
			break;
		case 870:
			switch(symbol) {
				case ASSIGN: return 9;
				case RPAREN: return 9;
			}
			break;
		case 875:
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
				case LPAREN: return 70;
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
		case 876:
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
		case 877:
			switch(symbol) {
				case ARRAY: return 62;
				case RPAREN: return 62;
			}
			break;
		case 880:
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
		case 881:
			switch(symbol) {
				case BOOLEAN: return 103;
				case BYTE: return 103;
				case CHAR: return 103;
				case ID: return 103;
				case INT: return 103;
				case SHORT: return 103;
				case VOID: return 103;
			}
			break;
		case 882:
			switch(symbol) {
				case ASSIGN: return 11;
				case SEMICOLON: return 11;
			}
			break;
		case 883:
			switch(symbol) {
				case AND: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case RPAREN: return 49;
				case XOR: return 49;
			}
			break;
		case 884:
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
		case 885:
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
		case 886:
			switch(symbol) {
				case IMPLEMENTS: return 12;
				case LBRACE: return 12;
			}
			break;
		case 888:
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
				case LPAREN: return 69;
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
		case 889:
			switch(symbol) {
				case CLASS: return 102;
				case INTERFACE: return 102;
			}
			break;
		case 890:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
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
		case 891:
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
				case LPAREN: return 70;
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
		case 892:
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
		case 895:
			switch(symbol) {
				case ASSIGN: return 38;
				case SEMICOLON: return 38;
			}
			break;
		case 896:
			switch(symbol) {
				case AND: return 54;
				case COMMA: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
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
		case 898:
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
		case 899:
			switch(symbol) {
				case SEMICOLON: return 9;
			}
			break;
		case 903:
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
				case LPAREN: return 69;
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
		case 904:
			switch(symbol) {
				case RPAREN: return 12;
			}
			break;
		case 905:
			switch(symbol) {
				case ARRAY: return 62;
				case ASSIGN: return 62;
				case COMMA: return 62;
				case RPAREN: return 62;
			}
			break;
		case 907:
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
				case LPAREN: return 69;
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
				case ASSIGN: return 11;
				case COMMA: return 11;
				case RPAREN: return 11;
			}
			break;
		case 911:
			switch(symbol) {
				case ABSTRACT: return 105;
				case BOOLEAN: return 105;
				case BYTE: return 105;
				case CHAR: return 105;
				case FINAL: return 105;
				case ID: return 105;
				case INT: return 105;
				case NATIVE: return 105;
				case PROTECTED: return 105;
				case PUBLIC: return 105;
				case SHORT: return 105;
				case STATIC: return 105;
				case VOID: return 105;
			}
			break;
		case 912:
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
		case 913:
			switch(symbol) {
				case RBRACKET: return 12;
			}
			break;
		case 916:
			switch(symbol) {
				case ARRAY: return 64;
				case COMMA: return 64;
				case RPAREN: return 64;
			}
			break;
		case 917:
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
		case 918:
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
		case 919:
			switch(symbol) {
				case SEMICOLON: return 113;
			}
			break;
		case 920:
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
		case 922:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case SEMICOLON: return 64;
			}
			break;
		case 923:
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
		case 926:
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
				case LPAREN: return 61;
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
		case 928:
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
		case 929:
			switch(symbol) {
				case RPAREN: return 35;
			}
			break;
		case 930:
			switch(symbol) {
				case AND: return 49;
				case ASSIGN: return 49;
				case COMMA: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case INSTANCEOF: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case RPAREN: return 49;
				case XOR: return 49;
			}
			break;
		case 932:
			switch(symbol) {
				case ARRAY: return 66;
				case COMMA: return 66;
				case LBRACE: return 66;
			}
			break;
		case 933:
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
				case LPAREN: return 57;
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
		case 934:
			switch(symbol) {
				case COMMA: return 10;
				case LBRACE: return 10;
			}
			break;
		case 940:
			switch(symbol) {
				case ARRAY: return 66;
				case ASSIGN: return 66;
				case COMMA: return 66;
				case RPAREN: return 66;
			}
			break;
		case 941:
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
		case 942:
			switch(symbol) {
				case END_TERMINAL: return 135;
			}
			break;
		case 943:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case SEMICOLON: return 63;
			}
			break;
		case 944:
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
				case LPAREN: return 60;
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
		case 945:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
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
		case 946:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case DOT: return 1;
				case SEMICOLON: return 1;
			}
			break;
		case 947:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case DOT: return 1;
				case RBRACKET: return 1;
			}
			break;
		case 948:
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
		case 949:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case RBRACKET: return 1;
			}
			break;
		case 950:
			switch(symbol) {
				case ARRAY: return 63;
				case COMMA: return 63;
				case RPAREN: return 63;
			}
			break;
		case 952:
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
		case 953:
			switch(symbol) {
				case RPAREN: return 11;
			}
			break;
		case 955:
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
		case 956:
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
				case LPAREN: return 61;
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
		case 957:
			switch(symbol) {
				case ASSIGN: return 38;
				case RBRACKET: return 38;
			}
			break;
		case 959:
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
				case LPAREN: return 60;
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
		case 960:
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
		case 961:
			switch(symbol) {
				case ASSIGN: return 10;
				case RBRACKET: return 10;
			}
			break;
		case 962:
			switch(symbol) {
				case SEMICOLON: return 113;
			}
			break;
		case 963:
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
				case LPAREN: return 60;
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
		case 965:
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
				case LPAREN: return 57;
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
		case 966:
			switch(symbol) {
				case DOT: return 2;
				case LPAREN: return 2;
			}
			break;
		case 969:
			switch(symbol) {
				case RBRACKET: return 38;
			}
			break;
		case 970:
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
		case 971:
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
		case 972:
			switch(symbol) {
				case RPAREN: return 139;
			}
			break;
		case 974:
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
		case 976:
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
				case LPAREN: return 70;
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
		case 977:
			switch(symbol) {
				case ASSIGN: return 10;
				case SEMICOLON: return 10;
			}
			break;
		case 978:
			switch(symbol) {
				case RPAREN: return 38;
			}
			break;
		case 979:
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
				case LPAREN: return 58;
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
		case 982:
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
		case 986:
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
				case LPAREN: return 69;
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
		case 987:
			switch(symbol) {
				case RPAREN: return 34;
			}
			break;
		case 988:
			switch(symbol) {
				case ARRAY: return 63;
				case RPAREN: return 63;
			}
			break;
		case 989:
			switch(symbol) {
				case ASSIGN: return 35;
				case SEMICOLON: return 35;
			}
			break;
		case 990:
			switch(symbol) {
				case ASSIGN: return 35;
				case RBRACKET: return 35;
			}
			break;
		case 991:
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
		case 992:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 993:
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
		case 996:
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
				case LPAREN: return 57;
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
		case 997:
			switch(symbol) {
				case ARRAY: return 64;
				case RBRACKET: return 64;
			}
			break;
		case 1001:
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
		case 1005:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case DOT: return 2;
				case RBRACKET: return 2;
			}
			break;
		case 1006:
			switch(symbol) {
				case AND: return 55;
				case COMMA: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
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
		case 1007:
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
		case 1008:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
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
		case 1009:
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
		case 1010:
			switch(symbol) {
				case ARRAY: return 64;
				case RPAREN: return 64;
			}
			break;
		case 1013:
			switch(symbol) {
				case COMMA: return 11;
				case RPAREN: return 11;
			}
			break;
		case 1014:
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
				case LPAREN: return 70;
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
		case 1015:
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
		case 1017:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
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
		case 1018:
			switch(symbol) {
				case ARRAY: return 63;
				case RBRACKET: return 63;
			}
			break;
		case 1019:
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
		case 1021:
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
		case 1025:
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
		case 1027:
			switch(symbol) {
				case ARRAY: return 65;
				case COMMA: return 65;
				case RPAREN: return 65;
			}
			break;
		case 1029:
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
				case LPAREN: return 59;
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
		case 1030:
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
		case 1031:
			switch(symbol) {
				case SEMICOLON: return 33;
			}
			break;
		case 1032:
			switch(symbol) {
				case SEMICOLON: return 31;
			}
			break;
		case 1033:
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
				case LPAREN: return 58;
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
		case 1035:
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
		case 1036:
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
				case LPAREN: return 59;
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
		case 1037:
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
		case 1038:
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
				case LPAREN: return 59;
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
		case 1039:
			switch(symbol) {
				case SEMICOLON: return 10;
			}
			break;
		case 1040:
			switch(symbol) {
				case RPAREN: return 10;
			}
			break;
		case 1041:
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
		case 1042:
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
				case LPAREN: return 61;
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
		case 1044:
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
		case 1046:
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
				case LPAREN: return 69;
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
		case 1048:
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
				case LPAREN: return 69;
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
		case 1049:
			switch(symbol) {
				case AND: return 49;
				case ASSIGN: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case RBRACKET: return 49;
				case REMAINDER: return 49;
				case XOR: return 49;
			}
			break;
		case 1051:
			switch(symbol) {
				case ASSIGN: return 12;
				case RBRACKET: return 12;
			}
			break;
		case 1053:
			switch(symbol) {
				case ARRAY: return 62;
				case ASSIGN: return 62;
				case SEMICOLON: return 62;
			}
			break;
		case 1054:
			switch(symbol) {
				case RBRACKET: return 35;
			}
			break;
		case 1055:
			switch(symbol) {
				case LPAREN: return 0;
			}
			break;
		case 1056:
			switch(symbol) {
				case AND: return 49;
				case ASSIGN: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case SEMICOLON: return 49;
				case XOR: return 49;
			}
			break;
		case 1058:
			switch(symbol) {
				case ABSTRACT: return 149;
				case BOOLEAN: return 149;
				case BYTE: return 149;
				case CHAR: return 149;
				case FINAL: return 149;
				case ID: return 149;
				case INT: return 149;
				case NATIVE: return 149;
				case PROTECTED: return 149;
				case PUBLIC: return 149;
				case RBRACE: return 149;
				case SEMICOLON: return 149;
				case SHORT: return 149;
				case STATIC: return 149;
				case VOID: return 149;
			}
			break;
		case 1059:
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
		case 1060:
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
		case 1062:
			switch(symbol) {
				case ARRAY: return 62;
				case ASSIGN: return 62;
				case RBRACKET: return 62;
			}
			break;
		case 1064:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
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
		case 1065:
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
				case LPAREN: return 70;
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
		case 1066:
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
				case LPAREN: return 69;
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
		case 1067:
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
		case 1068:
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
		case 1069:
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
				case LPAREN: return 57;
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
		case 1070:
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
		case 1071:
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
		case 1072:
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
		case 1073:
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
		case 1075:
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
				case LPAREN: return 70;
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
		case 1076:
			switch(symbol) {
				case RBRACKET: return 9;
			}
			break;
		case 1079:
			switch(symbol) {
				case RBRACKET: return 34;
			}
			break;
		case 1081:
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
				case LPAREN: return 70;
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
		case 1084:
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
				case LPAREN: return 59;
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
		case 1085:
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
		case 1086:
			switch(symbol) {
				case ARRAY: return 62;
				case SEMICOLON: return 62;
			}
			break;
		case 1087:
			switch(symbol) {
				case LBRACE: return 70;
				case RPAREN: return 70;
			}
			break;
		case 1088:
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
				case LPAREN: return 59;
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
		case 1090:
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
		case 1091:
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
		case 1092:
			switch(symbol) {
				case AND: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
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
		case 1093:
			switch(symbol) {
				case ARRAY: return 65;
				case RBRACKET: return 65;
			}
			break;
		case 1094:
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
		case 1095:
			switch(symbol) {
				case ARRAY: return 62;
				case ASSIGN: return 62;
				case RPAREN: return 62;
			}
			break;
		case 1097:
			switch(symbol) {
				case AND: return 55;
				case ASSIGN: return 55;
				case COMMA: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case INSTANCEOF: return 55;
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
		case 1098:
			switch(symbol) {
				case ARRAY: return 62;
				case IMPLEMENTS: return 62;
				case LBRACE: return 62;
			}
			break;
		case 1100:
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
		case 1101:
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
		case 1102:
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
		case 1103:
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
		case 1104:
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
		case 1109:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 1110:
			switch(symbol) {
				case AND: return 72;
				case DIV: return 72;
				case DOT: return 72;
				case EAGER_AND: return 72;
				case EAGER_OR: return 72;
				case EQ: return 72;
				case GEQ: return 72;
				case GT: return 72;
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
		case 1111:
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
		case 1113:
			switch(symbol) {
				case COMMA: return 12;
				case RPAREN: return 12;
			}
			break;
		case 1115:
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
		case 1116:
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
		case 1118:
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
		case 1119:
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
		case 1120:
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
				case LPAREN: return 58;
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
		case 1122:
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
				case LPAREN: return 57;
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
		case 1124:
			switch(symbol) {
				case ARRAY: return 2;
				case COMMA: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 1125:
			switch(symbol) {
				case ASSIGN: return 34;
				case RBRACKET: return 34;
			}
			break;
		case 1126:
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
				case REMAINDER: return 42;
				case SEMICOLON: return 42;
				case XOR: return 42;
			}
			break;
		case 1128:
			switch(symbol) {
				case ABSTRACT: return 118;
				case CLASS: return 118;
				case END_TERMINAL: return 118;
				case FINAL: return 118;
				case IMPORT: return 118;
				case INTERFACE: return 118;
				case NATIVE: return 118;
				case PROTECTED: return 118;
				case PUBLIC: return 118;
				case SEMICOLON: return 118;
				case STATIC: return 118;
			}
			break;
		case 1129:
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
		case 1130:
			switch(symbol) {
				case ASSIGN: return 38;
				case COMMA: return 38;
				case RPAREN: return 38;
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
		case 1132:
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
		case 1133:
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
		case 1136:
			switch(symbol) {
				case AND: return 52;
				case DIV: return 52;
				case DOT: return 52;
				case EAGER_AND: return 52;
				case EAGER_OR: return 52;
				case EQ: return 52;
				case GEQ: return 52;
				case GT: return 52;
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
		case 1138:
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
				case LPAREN: return 58;
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
		case 1139:
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
		case 1142:
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
		case 1143:
			switch(symbol) {
				case COMMA: return 9;
				case RPAREN: return 9;
			}
			break;
		case 1144:
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
				case LPAREN: return 58;
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
		case 1145:
			switch(symbol) {
				case AND: return 55;
				case DIV: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case GEQ: return 55;
				case GT: return 55;
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
		case 1146:
			switch(symbol) {
				case LBRACE: return 165;
				case SEMICOLON: return 165;
			}
			break;
		case 1148:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case RBRACKET: return 2;
			}
			break;
		case 1149:
			switch(symbol) {
				case AND: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case INSTANCEOF: return 54;
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
		case 1150:
			switch(symbol) {
				case ARRAY: return 66;
				case RBRACKET: return 66;
			}
			break;
		case 1152:
			switch(symbol) {
				case SEMICOLON: return 34;
			}
			break;
		case 1153:
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
		case 1154:
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
		case 1155:
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
		case 1156:
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
				case LPAREN: return 57;
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
		case 1157:
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
				case LPAREN: return 61;
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
		case 1158:
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
		case 1159:
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
				case LPAREN: return 59;
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
		case 1160:
			switch(symbol) {
				case SEMICOLON: return 114;
			}
			break;
		case 1161:
			switch(symbol) {
				case AND: return 54;
				case ASSIGN: return 54;
				case DIV: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case GEQ: return 54;
				case GT: return 54;
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
		case 1162:
			switch(symbol) {
				case ASSIGN: return 34;
				case SEMICOLON: return 34;
			}
			break;
		case 1163:
			switch(symbol) {
				case AND: return 49;
				case ASSIGN: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case REMAINDER: return 49;
				case RPAREN: return 49;
				case XOR: return 49;
			}
			break;
		case 1164:
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
		case 1167:
			switch(symbol) {
				case AND: return 49;
				case ASSIGN: return 49;
				case DIV: return 49;
				case DOT: return 49;
				case EAGER_AND: return 49;
				case EAGER_OR: return 49;
				case EQ: return 49;
				case GEQ: return 49;
				case GT: return 49;
				case INSTANCEOF: return 49;
				case LEQ: return 49;
				case LT: return 49;
				case MINUS: return 49;
				case MULT: return 49;
				case NEQ: return 49;
				case OR: return 49;
				case PLUS: return 49;
				case RBRACKET: return 49;
				case REMAINDER: return 49;
				case XOR: return 49;
			}
			break;
	}
	return -1;
}
