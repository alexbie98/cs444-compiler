#include "ParseTable.h"
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
	std::make_pair(PREFIX_OP, std::vector<unsigned int>{NOT}),
	std::make_pair(PREFIX_OP, std::vector<unsigned int>{MINUS}),
	std::make_pair(EXPRESSION, std::vector<unsigned int>{EXPRESSION1}),
	std::make_pair(EXPRESSION, std::vector<unsigned int>{EXPRESSION1, ASSIGN_OP, EXPRESSION1}),
	std::make_pair(STATEMENT_EXPRESSION, std::vector<unsigned int>{EXPRESSION}),
	std::make_pair(EXPRESSION1, std::vector<unsigned int>{EXPRESSION2}),
	std::make_pair(EXPRESSION1, std::vector<unsigned int>{EXPRESSION2, EXPRESSION1_REST}),
	std::make_pair(EXPRESSION1_REST, std::vector<unsigned int>{EXPRESSION_INFIX}),
	std::make_pair(EXPRESSION_INFIX, std::vector<unsigned int>{INFIX_OP, EXPRESSION2}),
	std::make_pair(EXPRESSION_INFIX, std::vector<unsigned int>{EXPRESSION_INFIX, INFIX_OP, EXPRESSION2}),
	std::make_pair(EXPRESSION1_REST, std::vector<unsigned int>{INSTANCEOF, TYPE}),
	std::make_pair(EXPRESSION2, std::vector<unsigned int>{PREFIX_OP, EXPRESSION2}),
	std::make_pair(EXPRESSION2, std::vector<unsigned int>{LPAREN, EXPRESSION, RPAREN, EXPRESSION2}),
	std::make_pair(EXPRESSION2, std::vector<unsigned int>{LPAREN, TYPE, RPAREN, EXPRESSION2}),
	std::make_pair(EXPRESSION2, std::vector<unsigned int>{PRIMARY, SELECTORS}),
	std::make_pair(EXPRESSION_LIST, std::vector<unsigned int>{EXPRESSION}),
	std::make_pair(EXPRESSION_LIST, std::vector<unsigned int>{EXPRESSION_LIST, COMMA, EXPRESSION}),
	std::make_pair(EXPRESSION_OPT, std::vector<unsigned int>{EXPRESSION}),
	std::make_pair(EXPRESSION_OPT, std::vector<unsigned int>{}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{LPAREN, EXPRESSION, RPAREN}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{THIS}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{LITERAL}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{NEW, CREATOR}),
	std::make_pair(PRIMARY, std::vector<unsigned int>{IDENTIFIER}),
	std::make_pair(SELECTORS, std::vector<unsigned int>{SELECTOR}),
	std::make_pair(SELECTORS, std::vector<unsigned int>{SELECTORS, SELECTOR}),
	std::make_pair(SELECTOR, std::vector<unsigned int>{DOT, IDENTIFIER}),
	std::make_pair(SELECTOR, std::vector<unsigned int>{DOT, IDENTIFIER, ARGUMENTS}),
	std::make_pair(SELECTOR, std::vector<unsigned int>{DOT, THIS}),
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
	std::make_pair(INNER_CREATOR, std::vector<unsigned int>{IDENTIFIER, CLASS_CREATOR_REST}),
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
	std::make_pair(STATEMENT, std::vector<unsigned int>{STATEMENT_EXPRESSION}),
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
	std::make_pair(VARIABLE_DECLARATOR, std::vector<unsigned int>{IDENTIFIER, VARIABLE_DECLARATOR_REST}),
	std::make_pair(VARIABLE_DECLARATOR_REST, std::vector<unsigned int>{}),
	std::make_pair(VARIABLE_DECLARATOR_REST, std::vector<unsigned int>{ASSIGN, VARIABLE_INITIALIZER}),
	std::make_pair(VARIABLE_DECLARATOR_ID, std::vector<unsigned int>{IDENTIFIER}),
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
	std::make_pair(CLASS_DECLARATION, std::vector<unsigned int>{CLASS, IDENTIFIER, CLASS_BODY}),
	std::make_pair(CLASS_DECLARATION, std::vector<unsigned int>{CLASS, IDENTIFIER, EXTENDS, TYPE, CLASS_BODY}),
	std::make_pair(CLASS_DECLARATION, std::vector<unsigned int>{CLASS, IDENTIFIER, IMPLEMENTS, TYPE_LIST, CLASS_BODY}),
	std::make_pair(CLASS_DECLARATION, std::vector<unsigned int>{CLASS, IDENTIFIER, EXTENDS, TYPE, IMPLEMENTS, TYPE_LIST, CLASS_BODY}),
	std::make_pair(INTERFACE_DECLARATION, std::vector<unsigned int>{INTERFACE, IDENTIFIER, INTERFACE_BODY}),
	std::make_pair(INTERFACE_DECLARATION, std::vector<unsigned int>{INTERFACE, IDENTIFIER, EXTENDS, TYPE_LIST, INTERFACE_BODY}),
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
	std::make_pair(MEMBER_DECLARATION, std::vector<unsigned int>{VOID, IDENTIFIER, METHOD_DECLARATOR_REST}),
	std::make_pair(MEMBER_DECLARATION, std::vector<unsigned int>{IDENTIFIER, CONSTRUCTOR_DECLARATOR_REST}),
	std::make_pair(METHOD_OR_FIELD_DECLARATION, std::vector<unsigned int>{TYPE, IDENTIFIER, METHOD_OR_FIELD_REST}),
	std::make_pair(METHOD_OR_FIELD_REST, std::vector<unsigned int>{VARIABLE_DECLARATOR_REST}),
	std::make_pair(METHOD_OR_FIELD_REST, std::vector<unsigned int>{METHOD_DECLARATOR_REST}),
	std::make_pair(INTERFACE_BODY_DECLARATIONS, std::vector<unsigned int>{INTERFACE_BODY_DECLARATION}),
	std::make_pair(INTERFACE_BODY_DECLARATIONS, std::vector<unsigned int>{INTERFACE_BODY_DECLARATIONS, INTERFACE_BODY_DECLARATION}),
	std::make_pair(INTERFACE_BODY_DECLARATION, std::vector<unsigned int>{SEMICOLON}),
	std::make_pair(INTERFACE_BODY_DECLARATION, std::vector<unsigned int>{MODIFIERS_OPT, INTERFACE_MEMBER_DECLARATION}),
	std::make_pair(INTERFACE_MEMBER_DECLARATION, std::vector<unsigned int>{INTERFACE_METHOD_OR_FIELD_DECLARATION}),
	std::make_pair(INTERFACE_MEMBER_DECLARATION, std::vector<unsigned int>{VOID, IDENTIFIER, INTERFACE_METHOD_DECLARATOR_REST}),
	std::make_pair(INTERFACE_METHOD_OR_FIELD_DECLARATION, std::vector<unsigned int>{TYPE, IDENTIFIER, INTERFACE_METHOD_OR_FIELD_REST}),
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
				case START_TERMINAL: return 679;
			}
			break;
		case 2:
			switch(symbol) {
				case CREATOR: return 497;
				case ID: return 762;
				case LONG_IDENTIFIER: return 420;
				case QUALIFIED_IDENTIFIER: return 873;
			}
			break;
		case 6:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 652;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 566;
			}
			break;
		case 7:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 360;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 8:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 443;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 11:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 138;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 14:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 775;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 16:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case EXPRESSION1_REST: return 882;
				case EXPRESSION_INFIX: return 559;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 826;
				case INSTANCEOF: return 406;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 17:
			switch(symbol) {
				case ASSIGN: return 10;
				case ASSIGN_OP: return 378;
			}
			break;
		case 20:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 464;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 21:
			switch(symbol) {
				case ARGUMENTS: return 130;
				case ARRAY_CREATOR_REST: return 536;
				case CLASS_CREATOR_REST: return 153;
				case LBRACKET: return 816;
				case LPAREN: return 384;
			}
			break;
		case 22:
			switch(symbol) {
				case ASSIGN: return 597;
				case FORMAL_PARAMETERS: return 529;
				case LPAREN: return 460;
				case METHOD_DECLARATOR_REST: return 455;
				case METHOD_OR_FIELD_REST: return 572;
				case VARIABLE_DECLARATOR_REST: return 471;
			}
			break;
		case 23:
			switch(symbol) {
				case IDENTIFIER: return 757;
				case THIS: return 642;
			}
			break;
		case 24:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 65;
			}
			break;
		case 25:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 746;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 132;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 207;
				case PRIMARY: return 441;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 27:
			switch(symbol) {
				case DOT: return 194;
				case LBRACKET: return 62;
				case SELECTOR: return 758;
				case SELECTORS: return 822;
			}
			break;
		case 28:
			switch(symbol) {
				case DOT: return 344;
				case LBRACKET: return 695;
				case SELECTOR: return 633;
			}
			break;
		case 31:
			switch(symbol) {
				case RBRACKET: return 280;
			}
			break;
		case 33:
			switch(symbol) {
				case ARRAY: return 520;
			}
			break;
		case 35:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 79;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 557;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 35;
				case PRIMARY: return 256;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 37:
			switch(symbol) {
				case ARRAY: return 814;
				case DOT: return 554;
			}
			break;
		case 39:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 425;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 58;
			}
			break;
		case 42:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 653;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 541;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 42;
				case PRIMARY: return 202;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 47:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 309;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 871;
			}
			break;
		case 49:
			switch(symbol) {
				case DOT: return 224;
				case LBRACKET: return 66;
				case SELECTOR: return 709;
				case SELECTORS: return 310;
			}
			break;
		case 51:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 72;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 295;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 51;
				case PRIMARY: return 302;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 52:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 582;
			}
			break;
		case 53:
			switch(symbol) {
				case ARGUMENTS: return 50;
				case LPAREN: return 355;
			}
			break;
		case 54:
			switch(symbol) {
				case ARRAY: return 716;
			}
			break;
		case 58:
			switch(symbol) {
				case RPAREN: return 872;
			}
			break;
		case 59:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 818;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 62:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 599;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 66:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 674;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 68:
			switch(symbol) {
				case DOT: return 538;
				case LBRACKET: return 585;
				case SELECTOR: return 847;
				case SELECTORS: return 730;
			}
			break;
		case 70:
			switch(symbol) {
				case DOT: return 476;
				case LBRACKET: return 605;
				case SELECTOR: return 263;
				case SELECTORS: return 238;
			}
			break;
		case 73:
			switch(symbol) {
				case ASSIGN: return 10;
				case ASSIGN_OP: return 272;
			}
			break;
		case 75:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case EXPRESSION1_REST: return 216;
				case EXPRESSION_INFIX: return 701;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 607;
				case INSTANCEOF: return 146;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 81:
			switch(symbol) {
				case DOT: return 344;
				case LBRACKET: return 695;
				case SELECTOR: return 666;
				case SELECTORS: return 28;
			}
			break;
		case 82:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 329;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 354;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 348;
				case PRIMARY: return 250;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 84:
			switch(symbol) {
				case COMMA: return 241;
				case RPAREN: return 55;
			}
			break;
		case 86:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 791;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 87:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 253;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 386;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 172;
				case PRIMARY: return 124;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 90:
			switch(symbol) {
				case RPAREN: return 842;
			}
			break;
		case 94:
			switch(symbol) {
				case ABSTRACT: return 158;
				case CLASS_BODY_DECLARATION: return 89;
				case FINAL: return 404;
				case MODIFIER: return 64;
				case MODIFIERS: return 108;
				case MODIFIERS_OPT: return 227;
				case NATIVE: return 114;
				case PROTECTED: return 105;
				case PUBLIC: return 125;
				case RBRACE: return 749;
				case SEMICOLON: return 503;
				case STATIC: return 234;
			}
			break;
		case 97:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 831;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 102;
			}
			break;
		case 98:
			switch(symbol) {
				case RPAREN: return 294;
			}
			break;
		case 99:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 269;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 132;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 207;
				case PRIMARY: return 441;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 101:
			switch(symbol) {
				case IDENTIFIER: return 513;
				case THIS: return 191;
			}
			break;
		case 102:
			switch(symbol) {
				case RPAREN: return 481;
			}
			break;
		case 106:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 608;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 229;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 106;
				case PRIMARY: return 290;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 107:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 192;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 140;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 107;
				case PRIMARY: return 117;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 108:
			switch(symbol) {
				case ABSTRACT: return 158;
				case FINAL: return 404;
				case MODIFIER: return 778;
				case NATIVE: return 114;
				case PROTECTED: return 105;
				case PUBLIC: return 125;
				case STATIC: return 234;
			}
			break;
		case 110:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 898;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 112:
			switch(symbol) {
				case IDENTIFIER: return 809;
				case THIS: return 602;
			}
			break;
		case 117:
			switch(symbol) {
				case DOT: return 388;
				case LBRACKET: return 486;
				case SELECTOR: return 332;
				case SELECTORS: return 450;
			}
			break;
		case 119:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case EXPRESSION1_REST: return 706;
				case EXPRESSION_INFIX: return 160;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 82;
				case INSTANCEOF: return 766;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 120:
			switch(symbol) {
				case ASSIGN: return 10;
				case ASSIGN_OP: return 719;
			}
			break;
		case 121:
			switch(symbol) {
				case IDENTIFIER: return 680;
				case THIS: return 515;
			}
			break;
		case 122:
			switch(symbol) {
				case RPAREN: return 852;
			}
			break;
		case 124:
			switch(symbol) {
				case DOT: return 23;
				case LBRACKET: return 212;
				case SELECTOR: return 702;
				case SELECTORS: return 307;
			}
			break;
		case 126:
			switch(symbol) {
				case RPAREN: return 707;
			}
			break;
		case 128:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 31;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 130:
			switch(symbol) {
				case CLASS_BODY: return 231;
				case LBRACE: return 739;
			}
			break;
		case 131:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 304;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 478;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 132:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 527;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 656;
			}
			break;
		case 134:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 422;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 136:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 907;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 277;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 136;
				case PRIMARY: return 587;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 137:
			switch(symbol) {
				case DOT: return 413;
				case LBRACKET: return 458;
				case SELECTOR: return 174;
			}
			break;
		case 140:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 495;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 626;
			}
			break;
		case 143:
			switch(symbol) {
				case DOT: return 255;
				case LBRACKET: return 110;
				case SELECTOR: return 218;
				case SELECTORS: return 271;
			}
			break;
		case 146:
			switch(symbol) {
				case BASIC_TYPE: return 568;
				case BOOLEAN: return 431;
				case BYTE: return 669;
				case CHAR: return 844;
				case ID: return 862;
				case INT: return 647;
				case LONG_IDENTIFIER: return 581;
				case SHORT: return 865;
				case TYPE: return 145;
			}
			break;
		case 147:
			switch(symbol) {
				case IDENTIFIER: return 920;
				case THIS: return 249;
			}
			break;
		case 151:
			switch(symbol) {
				case FORMAL_PARAMETERS: return 273;
				case INTERFACE_METHOD_DECLARATOR_REST: return 411;
				case INTERFACE_METHOD_OR_FIELD_REST: return 643;
				case LPAREN: return 233;
			}
			break;
		case 152:
			switch(symbol) {
				case RPAREN: return 288;
			}
			break;
		case 153:
			switch(symbol) {
				case RPAREN: return 232;
			}
			break;
		case 154:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 743;
			}
			break;
		case 155:
			switch(symbol) {
				case CLASS_BODY: return 149;
				case COMMA: return 735;
				case LBRACE: return 200;
			}
			break;
		case 159:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 927;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 352;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 159;
				case PRIMARY: return 265;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 160:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 171;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 162:
			switch(symbol) {
				case IDENTIFIER: return 151;
			}
			break;
		case 164:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case EXPRESSION1_REST: return 446;
				case EXPRESSION_INFIX: return 906;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 416;
				case INSTANCEOF: return 592;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 166:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 403;
			}
			break;
		case 169:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 475;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 140;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 107;
				case PRIMARY: return 117;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 171:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 764;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 354;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 348;
				case PRIMARY: return 250;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 172:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 358;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 386;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 172;
				case PRIMARY: return 124;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 173:
			switch(symbol) {
				case ID: return 303;
			}
			break;
		case 178:
			switch(symbol) {
				case ID: return 846;
			}
			break;
		case 179:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 361;
			}
			break;
		case 181:
			switch(symbol) {
				case CLASS_BODY: return 262;
				case EXTENDS: return 463;
				case IMPLEMENTS: return 854;
				case LBRACE: return 200;
			}
			break;
		case 182:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 109;
			}
			break;
		case 185:
			switch(symbol) {
				case ARGUMENTS: return 296;
				case LPAREN: return 725;
			}
			break;
		case 187:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 127;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 222;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 187;
				case PRIMARY: return 143;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 189:
			switch(symbol) {
				case ARGUMENTS: return 60;
				case LPAREN: return 258;
			}
			break;
		case 190:
			switch(symbol) {
				case RPAREN: return 512;
			}
			break;
		case 194:
			switch(symbol) {
				case IDENTIFIER: return 748;
				case THIS: return 186;
			}
			break;
		case 195:
			switch(symbol) {
				case IDENTIFIER: return 468;
				case THIS: return 689;
			}
			break;
		case 196:
			switch(symbol) {
				case ARRAY: return 785;
			}
			break;
		case 198:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 402;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 454;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 198;
				case PRIMARY: return 516;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 199:
			switch(symbol) {
				case COMMA: return 241;
				case RPAREN: return 340;
			}
			break;
		case 200:
			switch(symbol) {
				case ABSTRACT: return 158;
				case CLASS_BODY_DECLARATION: return 502;
				case CLASS_BODY_DECLARATIONS: return 94;
				case FINAL: return 404;
				case MODIFIER: return 64;
				case MODIFIERS: return 108;
				case MODIFIERS_OPT: return 227;
				case NATIVE: return 114;
				case PROTECTED: return 105;
				case PUBLIC: return 125;
				case RBRACE: return 649;
				case SEMICOLON: return 503;
				case STATIC: return 234;
			}
			break;
		case 202:
			switch(symbol) {
				case DOT: return 112;
				case LBRACKET: return 270;
				case SELECTOR: return 703;
				case SELECTORS: return 299;
			}
			break;
		case 203:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case EXPRESSION1_REST: return 180;
				case EXPRESSION_INFIX: return 830;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 365;
				case INSTANCEOF: return 251;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 204:
			switch(symbol) {
				case ASSIGN: return 10;
				case ASSIGN_OP: return 579;
			}
			break;
		case 205:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 896;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 132;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 207;
				case PRIMARY: return 441;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 206:
			switch(symbol) {
				case ARRAY: return 671;
			}
			break;
		case 207:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 95;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 132;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 207;
				case PRIMARY: return 441;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 208:
			switch(symbol) {
				case RBRACKET: return 655;
			}
			break;
		case 210:
			switch(symbol) {
				case BLOCK_BODY: return 392;
				case BLOCK_STATEMENT: return 96;
				case BLOCK_STATEMENTS: return 864;
				case LOCAL_VARIABLE_DECLARATION_STATEMENT: return 614;
				case TYPE: return 396;
			}
			break;
		case 212:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 690;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 213:
			switch(symbol) {
				case ID: return 264;
			}
			break;
		case 214:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 724;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 454;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 198;
				case PRIMARY: return 516;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 215:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 24;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 394;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 221:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 99;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 222:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 915;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 590;
			}
			break;
		case 224:
			switch(symbol) {
				case IDENTIFIER: return 185;
				case THIS: return 415;
			}
			break;
		case 225:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 534;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 226:
			switch(symbol) {
				case ARRAY: return 834;
				case DOT: return 213;
			}
			break;
		case 227:
			switch(symbol) {
				case IDENTIFIER: return 549;
				case MEMBER_DECLARATION: return 483;
				case METHOD_OR_FIELD_DECLARATION: return 609;
				case TYPE: return 244;
				case VOID: return 289;
			}
			break;
		case 228:
			switch(symbol) {
				case ARRAY: return 342;
				case DOT: return 178;
			}
			break;
		case 229:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 722;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 787;
			}
			break;
		case 233:
			switch(symbol) {
				case FORMAL_PARAMETER: return 239;
				case FORMAL_PARAMETER_LIST: return 740;
				case TYPE: return 613;
			}
			break;
		case 236:
			switch(symbol) {
				case ARGUMENTS: return 129;
				case LPAREN: return 799;
			}
			break;
		case 237:
			switch(symbol) {
				case ID: return 135;
			}
			break;
		case 238:
			switch(symbol) {
				case DOT: return 476;
				case LBRACKET: return 605;
				case SELECTOR: return 866;
			}
			break;
		case 240:
			switch(symbol) {
				case ARRAY: return 419;
				case DOT: return 237;
			}
			break;
		case 241:
			switch(symbol) {
				case FORMAL_PARAMETER: return 754;
				case TYPE: return 613;
			}
			break;
		case 244:
			switch(symbol) {
				case IDENTIFIER: return 22;
			}
			break;
		case 247:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 817;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 421;
			}
			break;
		case 248:
			switch(symbol) {
				case ARGUMENTS: return 32;
				case LPAREN: return 351;
			}
			break;
		case 250:
			switch(symbol) {
				case DOT: return 195;
				case LBRACKET: return 8;
				case SELECTOR: return 397;
				case SELECTORS: return 627;
			}
			break;
		case 251:
			switch(symbol) {
				case BASIC_TYPE: return 693;
				case BOOLEAN: return 845;
				case BYTE: return 700;
				case CHAR: return 427;
				case ID: return 493;
				case INT: return 630;
				case LONG_IDENTIFIER: return 665;
				case SHORT: return 116;
				case TYPE: return 467;
			}
			break;
		case 252:
			switch(symbol) {
				case RPAREN: return 424;
			}
			break;
		case 254:
			switch(symbol) {
				case ARRAY: return 859;
			}
			break;
		case 255:
			switch(symbol) {
				case IDENTIFIER: return 53;
				case THIS: return 393;
			}
			break;
		case 256:
			switch(symbol) {
				case DOT: return 121;
				case LBRACKET: return 372;
				case SELECTOR: return 600;
				case SELECTORS: return 418;
			}
			break;
		case 257:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 459;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 126;
			}
			break;
		case 258:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 718;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 881;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 259:
			switch(symbol) {
				case EXTENDS: return 856;
				case INTERFACE_BODY: return 85;
				case LBRACE: return 583;
			}
			break;
		case 260:
			switch(symbol) {
				case DOT: return 312;
				case LBRACKET: return 134;
				case SELECTOR: return 279;
				case SELECTORS: return 685;
			}
			break;
		case 265:
			switch(symbol) {
				case DOT: return 417;
				case LBRACKET: return 327;
				case SELECTOR: return 111;
				case SELECTORS: return 439;
			}
			break;
		case 268:
			switch(symbol) {
				case RPAREN: return 637;
			}
			break;
		case 270:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 594;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 271:
			switch(symbol) {
				case DOT: return 255;
				case LBRACKET: return 110;
				case SELECTOR: return 499;
			}
			break;
		case 272:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION1: return 165;
				case EXPRESSION2: return 164;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 541;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 42;
				case PRIMARY: return 202;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 273:
			switch(symbol) {
				case SEMICOLON: return 163;
			}
			break;
		case 274:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 868;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 391;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 274;
				case PRIMARY: return 260;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 277:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 152;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 268;
			}
			break;
		case 281:
			switch(symbol) {
				case ARRAY: return 286;
			}
			break;
		case 282:
			switch(symbol) {
				case ABSTRACT: return 623;
				case CLASS_OR_INTERFACE_DECLARATION: return 465;
				case FINAL: return 510;
				case MODIFIER: return 636;
				case MODIFIERS: return 297;
				case MODIFIERS_OPT: return 482;
				case NATIVE: return 498;
				case PROTECTED: return 293;
				case PUBLIC: return 328;
				case SEMICOLON: return 629;
				case STATIC: return 320;
				case TYPE_DECLARATION: return 861;
				case TYPE_DECLARATIONS_OPT: return 44;
			}
			break;
		case 287:
			switch(symbol) {
				case BASIC_TYPE: return 254;
				case BOOLEAN: return 466;
				case BYTE: return 245;
				case CHAR: return 837;
				case ID: return 925;
				case INT: return 209;
				case LONG_IDENTIFIER: return 226;
				case SHORT: return 810;
				case TYPE: return 899;
			}
			break;
		case 288:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 892;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 277;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 136;
				case PRIMARY: return 587;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 289:
			switch(symbol) {
				case IDENTIFIER: return 634;
			}
			break;
		case 290:
			switch(symbol) {
				case DOT: return 413;
				case LBRACKET: return 458;
				case SELECTOR: return 611;
				case SELECTORS: return 137;
			}
			break;
		case 294:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 261;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 295;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 51;
				case PRIMARY: return 302;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 295:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 98;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 449;
			}
			break;
		case 297:
			switch(symbol) {
				case ABSTRACT: return 623;
				case FINAL: return 510;
				case MODIFIER: return 40;
				case NATIVE: return 498;
				case PROTECTED: return 293;
				case PUBLIC: return 328;
				case STATIC: return 320;
			}
			break;
		case 298:
			switch(symbol) {
				case CLASS_BODY: return 546;
				case COMMA: return 735;
				case LBRACE: return 200;
			}
			break;
		case 299:
			switch(symbol) {
				case DOT: return 112;
				case LBRACKET: return 270;
				case SELECTOR: return 612;
			}
			break;
		case 302:
			switch(symbol) {
				case DOT: return 147;
				case LBRACKET: return 225;
				case SELECTOR: return 832;
				case SELECTORS: return 803;
			}
			break;
		case 304:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 794;
			}
			break;
		case 305:
			switch(symbol) {
				case RBRACKET: return 201;
			}
			break;
		case 307:
			switch(symbol) {
				case DOT: return 23;
				case LBRACKET: return 212;
				case SELECTOR: return 291;
			}
			break;
		case 308:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 751;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 317;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 357;
				case PRIMARY: return 81;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 309:
			switch(symbol) {
				case RPAREN: return 524;
			}
			break;
		case 310:
			switch(symbol) {
				case DOT: return 224;
				case LBRACKET: return 66;
				case SELECTOR: return 885;
			}
			break;
		case 311:
			switch(symbol) {
				case ABSTRACT: return 158;
				case CLASS_BODY_DECLARATION: return 89;
				case FINAL: return 404;
				case MODIFIER: return 64;
				case MODIFIERS: return 108;
				case MODIFIERS_OPT: return 227;
				case NATIVE: return 114;
				case PROTECTED: return 105;
				case PUBLIC: return 125;
				case RBRACE: return 625;
				case SEMICOLON: return 503;
				case STATIC: return 234;
			}
			break;
		case 312:
			switch(symbol) {
				case IDENTIFIER: return 808;
				case THIS: return 793;
			}
			break;
		case 313:
			switch(symbol) {
				case COMMA: return 735;
				case INTERFACE_BODY: return 177;
				case LBRACE: return 583;
			}
			break;
		case 314:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 752;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 531;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 315:
			switch(symbol) {
				case ARRAY: return 610;
			}
			break;
		case 316:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 798;
			}
			break;
		case 317:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 523;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 911;
			}
			break;
		case 318:
			switch(symbol) {
				case DOT: return 596;
				case LBRACKET: return 901;
				case SELECTOR: return 790;
				case SELECTORS: return 860;
			}
			break;
		case 319:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 567;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 317;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 357;
				case PRIMARY: return 81;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 324:
			switch(symbol) {
				case ARRAY: return 811;
				case DOT: return 672;
			}
			break;
		case 325:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case EXPRESSION1_REST: return 80;
				case EXPRESSION_INFIX: return 858;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 699;
				case INSTANCEOF: return 287;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 327:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 591;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 331:
			switch(symbol) {
				case ARGUMENTS: return 429;
				case LPAREN: return 452;
			}
			break;
		case 335:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 5;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 229;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 106;
				case PRIMARY: return 290;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 344:
			switch(symbol) {
				case IDENTIFIER: return 519;
				case THIS: return 678;
			}
			break;
		case 345:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION1: return 770;
				case EXPRESSION2: return 769;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 386;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 172;
				case PRIMARY: return 124;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 347:
			switch(symbol) {
				case ARGUMENTS: return 849;
				case LPAREN: return 829;
			}
			break;
		case 348:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 518;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 354;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 348;
				case PRIMARY: return 250;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 351:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 760;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 150;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 352:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 747;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 704;
			}
			break;
		case 353:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 619;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 257;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 353;
				case PRIMARY: return 70;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 354:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 511;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 542;
			}
			break;
		case 355:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 781;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 563;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 356:
			switch(symbol) {
				case RBRACKET: return 330;
			}
			break;
		case 357:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 412;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 317;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 357;
				case PRIMARY: return 81;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 364:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 154;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 768;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 365:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 477;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 229;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 106;
				case PRIMARY: return 290;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 367:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 104;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 454;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 198;
				case PRIMARY: return 516;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 368:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 759;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 352;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 159;
				case PRIMARY: return 265;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 369:
			switch(symbol) {
				case DOT: return 101;
				case LBRACKET: return 128;
				case SELECTOR: return 673;
			}
			break;
		case 370:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 606;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 277;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 136;
				case PRIMARY: return 587;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 372:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 548;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 375:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 514;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 247;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 375;
				case PRIMARY: return 438;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 376:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 537;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 378:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION1: return 326;
				case EXPRESSION2: return 325;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 557;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 35;
				case PRIMARY: return 256;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 382:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 389;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 384:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 484;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 243;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 385:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 788;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 454;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 198;
				case PRIMARY: return 516;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 386:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 461;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 560;
			}
			break;
		case 388:
			switch(symbol) {
				case IDENTIFIER: return 737;
				case THIS: return 220;
			}
			break;
		case 389:
			switch(symbol) {
				case RBRACKET: return 432;
			}
			break;
		case 391:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 797;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 252;
			}
			break;
		case 392:
			switch(symbol) {
				case RBRACE: return 891;
			}
			break;
		case 396:
			switch(symbol) {
				case IDENTIFIER: return 913;
				case VARIABLE_DECLARATOR: return 774;
			}
			break;
		case 398:
			switch(symbol) {
				case IDENTIFIER: return 248;
				case THIS: return 489;
			}
			break;
		case 405:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 923;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 352;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 159;
				case PRIMARY: return 265;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 406:
			switch(symbol) {
				case BASIC_TYPE: return 196;
				case BOOLEAN: return 533;
				case BYTE: return 731;
				case CHAR: return 589;
				case ID: return 526;
				case INT: return 782;
				case LONG_IDENTIFIER: return 228;
				case SHORT: return 712;
				case TYPE: return 556;
			}
			break;
		case 407:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 658;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 222;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 187;
				case PRIMARY: return 143;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 413:
			switch(symbol) {
				case IDENTIFIER: return 331;
				case THIS: return 167;
			}
			break;
		case 414:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 922;
			}
			break;
		case 416:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 571;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 222;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 187;
				case PRIMARY: return 143;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 417:
			switch(symbol) {
				case IDENTIFIER: return 189;
				case THIS: return 909;
			}
			break;
		case 418:
			switch(symbol) {
				case DOT: return 121;
				case LBRACKET: return 372;
				case SELECTOR: return 184;
			}
			break;
		case 420:
			switch(symbol) {
				case DOT: return 908;
			}
			break;
		case 421:
			switch(symbol) {
				case RPAREN: return 547;
			}
			break;
		case 422:
			switch(symbol) {
				case RBRACKET: return 230;
			}
			break;
		case 424:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 779;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 391;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 274;
				case PRIMARY: return 260;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 425:
			switch(symbol) {
				case RPAREN: return 807;
			}
			break;
		case 426:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 338;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 222;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 187;
				case PRIMARY: return 143;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 433:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 540;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 97;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 433;
				case PRIMARY: return 318;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 435:
			switch(symbol) {
				case ARRAY: return 631;
				case DOT: return 928;
			}
			break;
		case 437:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case EXPRESSION1_REST: return 857;
				case EXPRESSION_INFIX: return 59;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 916;
				case INSTANCEOF: return 508;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 438:
			switch(symbol) {
				case DOT: return 657;
				case LBRACKET: return 618;
				case SELECTOR: return 855;
				case SELECTORS: return 895;
			}
			break;
		case 439:
			switch(symbol) {
				case DOT: return 417;
				case LBRACKET: return 327;
				case SELECTOR: return 374;
			}
			break;
		case 441:
			switch(symbol) {
				case DOT: return 398;
				case LBRACKET: return 20;
				case SELECTOR: return 688;
				case SELECTORS: return 667;
			}
			break;
		case 442:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 840;
			}
			break;
		case 443:
			switch(symbol) {
				case RBRACKET: return 383;
			}
			break;
		case 445:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 379;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 229;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 106;
				case PRIMARY: return 290;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 449:
			switch(symbol) {
				case RPAREN: return 663;
			}
			break;
		case 450:
			switch(symbol) {
				case DOT: return 388;
				case LBRACKET: return 486;
				case SELECTOR: return 175;
			}
			break;
		case 451:
			switch(symbol) {
				case IMPORT: return 485;
				case IMPORT_DECLARATION: return 616;
				case IMPORT_DECLARATIONS: return 894;
				case IMPORT_DECLARATIONS_OPT: return 282;
			}
			break;
		case 452:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 525;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 346;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 453:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 684;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 454;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 198;
				case PRIMARY: return 516;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 454:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 784;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 496;
			}
			break;
		case 456:
			switch(symbol) {
				case END_TERMINAL: return 157;
			}
			break;
		case 458:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 208;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 459:
			switch(symbol) {
				case RPAREN: return 570;
			}
			break;
		case 460:
			switch(symbol) {
				case FORMAL_PARAMETER: return 239;
				case FORMAL_PARAMETER_LIST: return 199;
				case TYPE: return 613;
			}
			break;
		case 461:
			switch(symbol) {
				case RPAREN: return 87;
			}
			break;
		case 463:
			switch(symbol) {
				case BASIC_TYPE: return 281;
				case BOOLEAN: return 444;
				case BYTE: return 727;
				case CHAR: return 876;
				case ID: return 929;
				case INT: return 682;
				case LONG_IDENTIFIER: return 324;
				case SHORT: return 622;
				case TYPE: return 839;
			}
			break;
		case 464:
			switch(symbol) {
				case RBRACKET: return 359;
			}
			break;
		case 468:
			switch(symbol) {
				case ARGUMENTS: return 469;
				case LPAREN: return 490;
			}
			break;
		case 470:
			switch(symbol) {
				case INTERFACE_MEMBER_DECLARATION: return 176;
				case INTERFACE_METHOD_OR_FIELD_DECLARATION: return 661;
				case TYPE: return 162;
				case VOID: return 819;
			}
			break;
		case 472:
			switch(symbol) {
				case IDENTIFIER: return 867;
				case THIS: return 267;
			}
			break;
		case 476:
			switch(symbol) {
				case IDENTIFIER: return 347;
				case THIS: return 462;
			}
			break;
		case 480:
			switch(symbol) {
				case RBRACKET: return 336;
			}
			break;
		case 481:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 897;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 97;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 433;
				case PRIMARY: return 318;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 482:
			switch(symbol) {
				case CLASS: return 521;
				case CLASS_DECLARATION: return 744;
				case INTERFACE: return 670;
				case INTERFACE_DECLARATION: return 278;
			}
			break;
		case 484:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 662;
			}
			break;
		case 485:
			switch(symbol) {
				case ID: return 123;
				case LONG_IDENTIFIER: return 835;
			}
			break;
		case 486:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 578;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 488:
			switch(symbol) {
				case FORMAL_PARAMETERS: return 273;
				case INTERFACE_METHOD_DECLARATOR_REST: return 710;
				case LPAREN: return 233;
			}
			break;
		case 490:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 442;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 697;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 491:
			switch(symbol) {
				case BASIC_TYPE: return 615;
				case BOOLEAN: return 381;
				case BYTE: return 603;
				case CHAR: return 777;
				case ID: return 802;
				case INT: return 569;
				case LONG_IDENTIFIER: return 545;
				case SHORT: return 914;
				case TYPE: return 197;
			}
			break;
		case 495:
			switch(symbol) {
				case RPAREN: return 169;
			}
			break;
		case 496:
			switch(symbol) {
				case RPAREN: return 385;
			}
			break;
		case 500:
			switch(symbol) {
				case DOT: return 694;
			}
			break;
		case 501:
			switch(symbol) {
				case RPAREN: return 888;
			}
			break;
		case 505:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 74;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 140;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 107;
				case PRIMARY: return 117;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 508:
			switch(symbol) {
				case BASIC_TYPE: return 206;
				case BOOLEAN: return 558;
				case BYTE: return 292;
				case CHAR: return 474;
				case ID: return 504;
				case INT: return 246;
				case LONG_IDENTIFIER: return 240;
				case SHORT: return 532;
				case TYPE: return 535;
			}
			break;
		case 511:
			switch(symbol) {
				case RPAREN: return 732;
			}
			break;
		case 512:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 88;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 541;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 42;
				case PRIMARY: return 202;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 513:
			switch(symbol) {
				case ARGUMENTS: return 646;
				case LPAREN: return 638;
			}
			break;
		case 516:
			switch(symbol) {
				case DOT: return 101;
				case LBRACKET: return 128;
				case SELECTOR: return 440;
				case SELECTORS: return 369;
			}
			break;
		case 517:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 410;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 317;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 357;
				case PRIMARY: return 81;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 519:
			switch(symbol) {
				case ARGUMENTS: return 522;
				case LPAREN: return 806;
			}
			break;
		case 521:
			switch(symbol) {
				case IDENTIFIER: return 181;
			}
			break;
		case 523:
			switch(symbol) {
				case RPAREN: return 319;
			}
			break;
		case 524:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 161;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 525:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 659;
			}
			break;
		case 527:
			switch(symbol) {
				case RPAREN: return 205;
			}
			break;
		case 528:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 275;
			}
			break;
		case 529:
			switch(symbol) {
				case BLOCK: return 815;
				case LBRACE: return 210;
				case METHOD_BODY: return 827;
				case SEMICOLON: return 714;
			}
			break;
		case 534:
			switch(symbol) {
				case RBRACKET: return 838;
			}
			break;
		case 536:
			switch(symbol) {
				case RPAREN: return 726;
			}
			break;
		case 538:
			switch(symbol) {
				case IDENTIFIER: return 771;
				case THIS: return 796;
			}
			break;
		case 539:
			switch(symbol) {
				case ID: return 836;
			}
			break;
		case 541:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 190;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 501;
			}
			break;
		case 542:
			switch(symbol) {
				case RPAREN: return 641;
			}
			break;
		case 543:
			switch(symbol) {
				case FORMAL_PARAMETER: return 239;
				case FORMAL_PARAMETER_LIST: return 84;
				case TYPE: return 613;
			}
			break;
		case 545:
			switch(symbol) {
				case ARRAY: return 624;
				case DOT: return 173;
			}
			break;
		case 547:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 692;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 247;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 375;
				case PRIMARY: return 438;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 548:
			switch(symbol) {
				case RBRACKET: return 36;
			}
			break;
		case 549:
			switch(symbol) {
				case CONSTRUCTOR_DECLARATOR_REST: return 863;
				case FORMAL_PARAMETERS: return 574;
				case LPAREN: return 543;
			}
			break;
		case 552:
			switch(symbol) {
				case RBRACKET: return 148;
			}
			break;
		case 553:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 367;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 554:
			switch(symbol) {
				case ID: return 479;
			}
			break;
		case 555:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 408;
			}
			break;
		case 557:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BOOLEAN_LIT: return 34;
				case BYTE: return 142;
				case CHAR: return 18;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 90;
				case EXPRESSION1: return 73;
				case EXPRESSION2: return 75;
				case ID: return 100;
				case IDENTIFIER: return 9;
				case INT: return 26;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LONG_IDENTIFIER: return 37;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case SHORT: return 67;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case TYPE: return 122;
			}
			break;
		case 559:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 370;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 560:
			switch(symbol) {
				case RPAREN: return 795;
			}
			break;
		case 561:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 883;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 391;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 274;
				case PRIMARY: return 260;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 566:
			switch(symbol) {
				case RPAREN: return 376;
			}
			break;
		case 568:
			switch(symbol) {
				case ARRAY: return 648;
			}
			break;
		case 570:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 848;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 257;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 353;
				case PRIMARY: return 70;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 574:
			switch(symbol) {
				case BLOCK: return 815;
				case LBRACE: return 210;
				case METHOD_BODY: return 879;
			}
			break;
		case 575:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 736;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 247;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 375;
				case PRIMARY: return 438;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 577:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case EXPRESSION1_REST: return 869;
				case EXPRESSION_INFIX: return 221;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 919;
				case INSTANCEOF: return 491;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 578:
			switch(symbol) {
				case RBRACKET: return 492;
			}
			break;
		case 579:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION1: return 436;
				case EXPRESSION2: return 437;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 352;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 159;
				case PRIMARY: return 265;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 580:
			switch(symbol) {
				case BASIC_TYPE: return 874;
				case BOOLEAN: return 772;
				case BYTE: return 890;
				case CHAR: return 696;
				case ID: return 675;
				case INT: return 917;
				case LONG_IDENTIFIER: return 435;
				case SHORT: return 753;
				case TYPE: return 343;
			}
			break;
		case 581:
			switch(symbol) {
				case ARRAY: return 850;
				case DOT: return 776;
			}
			break;
		case 583:
			switch(symbol) {
				case ABSTRACT: return 158;
				case FINAL: return 404;
				case INTERFACE_BODY_DECLARATION: return 584;
				case INTERFACE_BODY_DECLARATIONS: return 893;
				case MODIFIER: return 64;
				case MODIFIERS: return 108;
				case MODIFIERS_OPT: return 470;
				case NATIVE: return 114;
				case PROTECTED: return 105;
				case PUBLIC: return 125;
				case RBRACE: return 133;
				case SEMICOLON: return 43;
				case STATIC: return 234;
			}
			break;
		case 585:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 480;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 587:
			switch(symbol) {
				case DOT: return 472;
				case LBRACKET: return 382;
				case SELECTOR: return 283;
				case SELECTORS: return 683;
			}
			break;
		case 590:
			switch(symbol) {
				case RPAREN: return 407;
			}
			break;
		case 591:
			switch(symbol) {
				case RBRACKET: return 878;
			}
			break;
		case 592:
			switch(symbol) {
				case BASIC_TYPE: return 54;
				case BOOLEAN: return 118;
				case BYTE: return 142;
				case CHAR: return 18;
				case ID: return 100;
				case INT: return 26;
				case LONG_IDENTIFIER: return 37;
				case SHORT: return 67;
				case TYPE: return 409;
			}
			break;
		case 594:
			switch(symbol) {
				case RBRACKET: return 183;
			}
			break;
		case 595:
			switch(symbol) {
				case SEMICOLON: return 141;
			}
			break;
		case 596:
			switch(symbol) {
				case IDENTIFIER: return 780;
				case THIS: return 400;
			}
			break;
		case 597:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 487;
				case EXPRESSION1: return 204;
				case EXPRESSION2: return 203;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 391;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 274;
				case PRIMARY: return 260;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case VARIABLE_INITIALIZER: return 366;
			}
			break;
		case 599:
			switch(symbol) {
				case RBRACKET: return 705;
			}
			break;
		case 604:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 921;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 317;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 357;
				case PRIMARY: return 81;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 605:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 621;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 607:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 434;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 295;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 51;
				case PRIMARY: return 302;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 613:
			switch(symbol) {
				case IDENTIFIER: return 639;
				case VARIABLE_DECLARATOR_ID: return 877;
			}
			break;
		case 615:
			switch(symbol) {
				case ARRAY: return 902;
			}
			break;
		case 617:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 812;
				case EXPRESSION1: return 800;
				case EXPRESSION2: return 801;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 257;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 353;
				case PRIMARY: return 70;
				case STRING_LIT: return 46;
				case THIS: return 13;
				case VARIABLE_INITIALIZER: return 841;
			}
			break;
		case 618:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 686;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 620:
			switch(symbol) {
				case ARRAY: return 910;
				case DOT: return 765;
			}
			break;
		case 621:
			switch(symbol) {
				case RBRACKET: return 301;
			}
			break;
		case 626:
			switch(symbol) {
				case RPAREN: return 505;
			}
			break;
		case 627:
			switch(symbol) {
				case DOT: return 195;
				case LBRACKET: return 8;
				case SELECTOR: return 447;
			}
			break;
		case 628:
			switch(symbol) {
				case ARRAY: return 851;
				case DOT: return 792;
			}
			break;
		case 634:
			switch(symbol) {
				case FORMAL_PARAMETERS: return 529;
				case LPAREN: return 460;
				case METHOD_DECLARATOR_REST: return 880;
			}
			break;
		case 637:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 211;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 277;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 136;
				case PRIMARY: return 587;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 638:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 166;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 783;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 641:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 448;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 354;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 348;
				case PRIMARY: return 250;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 645:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 517;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 651:
			switch(symbol) {
				case ARRAY: return 833;
			}
			break;
		case 652:
			switch(symbol) {
				case RPAREN: return 823;
			}
			break;
		case 654:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 473;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 656:
			switch(symbol) {
				case RPAREN: return 25;
			}
			break;
		case 657:
			switch(symbol) {
				case IDENTIFIER: return 236;
				case THIS: return 323;
			}
			break;
		case 663:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 285;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 295;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 51;
				case PRIMARY: return 302;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 665:
			switch(symbol) {
				case ARRAY: return 875;
				case DOT: return 738;
			}
			break;
		case 667:
			switch(symbol) {
				case DOT: return 398;
				case LBRACKET: return 20;
				case SELECTOR: return 741;
			}
			break;
		case 670:
			switch(symbol) {
				case IDENTIFIER: return 259;
			}
			break;
		case 672:
			switch(symbol) {
				case ID: return 824;
			}
			break;
		case 674:
			switch(symbol) {
				case RBRACKET: return 586;
			}
			break;
		case 679:
			switch(symbol) {
				case COMPILER_UNIT: return 456;
				case PACKAGE: return 924;
				case PACKAGE_DECLARATION: return 451;
			}
			break;
		case 680:
			switch(symbol) {
				case ARGUMENTS: return 69;
				case LPAREN: return 314;
			}
			break;
		case 681:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 528;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 494;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 683:
			switch(symbol) {
				case DOT: return 472;
				case LBRACKET: return 382;
				case SELECTOR: return 91;
			}
			break;
		case 685:
			switch(symbol) {
				case DOT: return 312;
				case LBRACKET: return 134;
				case SELECTOR: return 284;
			}
			break;
		case 686:
			switch(symbol) {
				case RBRACKET: return 550;
			}
			break;
		case 687:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 179;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 395;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 690:
			switch(symbol) {
				case RBRACKET: return 399;
			}
			break;
		case 693:
			switch(symbol) {
				case ARRAY: return 362;
			}
			break;
		case 694:
			switch(symbol) {
				case ID: return 593;
			}
			break;
		case 695:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 552;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 698:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 321;
			}
			break;
		case 699:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 723;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 97;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 433;
				case PRIMARY: return 318;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 701:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 767;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 704:
			switch(symbol) {
				case RPAREN: return 405;
			}
			break;
		case 707:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 506;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 257;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 353;
				case PRIMARY: return 70;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 717:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 691;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 97;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 433;
				case PRIMARY: return 318;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 718:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 926;
			}
			break;
		case 719:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION1: return 576;
				case EXPRESSION2: return 577;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 247;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 375;
				case PRIMARY: return 438;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 721:
			switch(symbol) {
				case BASIC_TYPE: return 315;
				case BOOLEAN: return 113;
				case BYTE: return 349;
				case CHAR: return 77;
				case ID: return 92;
				case INT: return 333;
				case LONG_IDENTIFIER: return 628;
				case SHORT: return 93;
				case TYPE: return 45;
				case TYPE_LIST: return 155;
			}
			break;
		case 722:
			switch(symbol) {
				case RPAREN: return 335;
			}
			break;
		case 725:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 555;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 334;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 730:
			switch(symbol) {
				case DOT: return 538;
				case LBRACKET: return 585;
				case SELECTOR: return 734;
			}
			break;
		case 732:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 350;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 354;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 348;
				case PRIMARY: return 250;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 735:
			switch(symbol) {
				case BASIC_TYPE: return 315;
				case BOOLEAN: return 113;
				case BYTE: return 349;
				case CHAR: return 77;
				case ID: return 92;
				case INT: return 333;
				case LONG_IDENTIFIER: return 628;
				case SHORT: return 93;
				case TYPE: return 300;
			}
			break;
		case 737:
			switch(symbol) {
				case ARGUMENTS: return 905;
				case LPAREN: return 884;
			}
			break;
		case 738:
			switch(symbol) {
				case ID: return 322;
			}
			break;
		case 739:
			switch(symbol) {
				case ABSTRACT: return 158;
				case CLASS_BODY_DECLARATION: return 502;
				case CLASS_BODY_DECLARATIONS: return 311;
				case FINAL: return 404;
				case MODIFIER: return 64;
				case MODIFIERS: return 108;
				case MODIFIERS_OPT: return 227;
				case NATIVE: return 114;
				case PROTECTED: return 105;
				case PUBLIC: return 125;
				case RBRACE: return 401;
				case SEMICOLON: return 503;
				case STATIC: return 234;
			}
			break;
		case 740:
			switch(symbol) {
				case COMMA: return 241;
				case RPAREN: return 38;
			}
			break;
		case 747:
			switch(symbol) {
				case RPAREN: return 368;
			}
			break;
		case 748:
			switch(symbol) {
				case ARGUMENTS: return 825;
				case LPAREN: return 887;
			}
			break;
		case 752:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 341;
			}
			break;
		case 755:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 457;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 222;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 187;
				case PRIMARY: return 143;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 757:
			switch(symbol) {
				case ARGUMENTS: return 745;
				case LPAREN: return 904;
			}
			break;
		case 760:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 276;
			}
			break;
		case 761:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 708;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 97;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 433;
				case PRIMARY: return 318;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 765:
			switch(symbol) {
				case ID: return 632;
			}
			break;
		case 766:
			switch(symbol) {
				case BASIC_TYPE: return 651;
				case BOOLEAN: return 306;
				case BYTE: return 530;
				case CHAR: return 756;
				case ID: return 729;
				case INT: return 564;
				case LONG_IDENTIFIER: return 620;
				case SHORT: return 750;
				case TYPE: return 804;
			}
			break;
		case 767:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 742;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 295;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 51;
				case PRIMARY: return 302;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 769:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case EXPRESSION1_REST: return 676;
				case EXPRESSION_INFIX: return 645;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 308;
				case INSTANCEOF: return 580;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 771:
			switch(symbol) {
				case ARGUMENTS: return 551;
				case LPAREN: return 773;
			}
			break;
		case 773:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 52;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 763;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 774:
			switch(symbol) {
				case SEMICOLON: return 711;
			}
			break;
		case 776:
			switch(symbol) {
				case ID: return 668;
			}
			break;
		case 780:
			switch(symbol) {
				case ARGUMENTS: return 78;
				case LPAREN: return 364;
			}
			break;
		case 781:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 820;
			}
			break;
		case 784:
			switch(symbol) {
				case RPAREN: return 214;
			}
			break;
		case 786:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 339;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 229;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 106;
				case PRIMARY: return 290;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 787:
			switch(symbol) {
				case RPAREN: return 445;
			}
			break;
		case 792:
			switch(symbol) {
				case ID: return 601;
			}
			break;
		case 795:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 168;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 386;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 172;
				case PRIMARY: return 124;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 797:
			switch(symbol) {
				case RPAREN: return 561;
			}
			break;
		case 799:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 182;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 390;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 800:
			switch(symbol) {
				case ASSIGN: return 10;
				case ASSIGN_OP: return 345;
			}
			break;
		case 801:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case EXPRESSION1_REST: return 507;
				case EXPRESSION_INFIX: return 553;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 453;
				case INSTANCEOF: return 853;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 803:
			switch(symbol) {
				case DOT: return 147;
				case LBRACKET: return 225;
				case SELECTOR: return 677;
			}
			break;
		case 806:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 813;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 139;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 807:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 373;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 808:
			switch(symbol) {
				case ARGUMENTS: return 565;
				case LPAREN: return 681;
			}
			break;
		case 809:
			switch(symbol) {
				case ARGUMENTS: return 650;
				case LPAREN: return 215;
			}
			break;
		case 813:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 588;
			}
			break;
		case 816:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 356;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 817:
			switch(symbol) {
				case RPAREN: return 575;
			}
			break;
		case 818:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 843;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 140;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 107;
				case PRIMARY: return 117;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 819:
			switch(symbol) {
				case IDENTIFIER: return 488;
			}
			break;
		case 822:
			switch(symbol) {
				case DOT: return 194;
				case LBRACKET: return 62;
				case SELECTOR: return 41;
			}
			break;
		case 823:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 115;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 6;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 7;
				case PRIMARY: return 27;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 826:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 598;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 277;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 136;
				case PRIMARY: return 587;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 829:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 698;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 423;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 830:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 786;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 831:
			switch(symbol) {
				case RPAREN: return 717;
			}
			break;
		case 835:
			switch(symbol) {
				case DOT: return 918;
				case SEMICOLON: return 156;
			}
			break;
		case 839:
			switch(symbol) {
				case CLASS_BODY: return 889;
				case IMPLEMENTS: return 721;
				case LBRACE: return 200;
			}
			break;
		case 842:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 509;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 557;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 35;
				case PRIMARY: return 256;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 852:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 900;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 557;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 35;
				case PRIMARY: return 256;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 853:
			switch(symbol) {
				case BASIC_TYPE: return 33;
				case BOOLEAN: return 715;
				case BYTE: return 428;
				case CHAR: return 380;
				case ID: return 660;
				case INT: return 144;
				case LONG_IDENTIFIER: return 903;
				case SHORT: return 430;
				case TYPE: return 640;
			}
			break;
		case 854:
			switch(symbol) {
				case BASIC_TYPE: return 315;
				case BOOLEAN: return 113;
				case BYTE: return 349;
				case CHAR: return 77;
				case ID: return 92;
				case INT: return 333;
				case LONG_IDENTIFIER: return 628;
				case SHORT: return 93;
				case TYPE: return 45;
				case TYPE_LIST: return 298;
			}
			break;
		case 856:
			switch(symbol) {
				case BASIC_TYPE: return 315;
				case BOOLEAN: return 113;
				case BYTE: return 349;
				case CHAR: return 77;
				case ID: return 92;
				case INT: return 333;
				case LONG_IDENTIFIER: return 628;
				case SHORT: return 93;
				case TYPE: return 45;
				case TYPE_LIST: return 313;
			}
			break;
		case 858:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 761;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 860:
			switch(symbol) {
				case DOT: return 596;
				case LBRACKET: return 901;
				case SELECTOR: return 805;
			}
			break;
		case 864:
			switch(symbol) {
				case BLOCK_STATEMENT: return 371;
				case LOCAL_VARIABLE_DECLARATION_STATEMENT: return 614;
				case TYPE: return 396;
			}
			break;
		case 867:
			switch(symbol) {
				case ARGUMENTS: return 562;
				case LPAREN: return 687;
			}
			break;
		case 870:
			switch(symbol) {
				case COMMA: return 14;
				case RPAREN: return 170;
			}
			break;
		case 871:
			switch(symbol) {
				case RPAREN: return 654;
			}
			break;
		case 872:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 387;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 873:
			switch(symbol) {
				case LPAREN: return 21;
			}
			break;
		case 874:
			switch(symbol) {
				case ARRAY: return 363;
			}
			break;
		case 884:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 870;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 266;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 887:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 316;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 544;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 888:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 83;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 541;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 42;
				case PRIMARY: return 202;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 893:
			switch(symbol) {
				case ABSTRACT: return 158;
				case FINAL: return 404;
				case INTERFACE_BODY_DECLARATION: return 821;
				case MODIFIER: return 64;
				case MODIFIERS: return 108;
				case MODIFIERS_OPT: return 470;
				case NATIVE: return 114;
				case PROTECTED: return 105;
				case PUBLIC: return 125;
				case RBRACE: return 728;
				case SEMICOLON: return 43;
				case STATIC: return 234;
			}
			break;
		case 894:
			switch(symbol) {
				case IMPORT: return 485;
				case IMPORT_DECLARATION: return 886;
			}
			break;
		case 895:
			switch(symbol) {
				case DOT: return 657;
				case LBRACKET: return 618;
				case SELECTOR: return 664;
			}
			break;
		case 898:
			switch(symbol) {
				case RBRACKET: return 720;
			}
			break;
		case 901:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 305;
				case EXPRESSION1: return 120;
				case EXPRESSION2: return 119;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 39;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 11;
				case PRIMARY: return 68;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 903:
			switch(symbol) {
				case ARRAY: return 337;
				case DOT: return 539;
			}
			break;
		case 904:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION: return 71;
				case EXPRESSION1: return 17;
				case EXPRESSION2: return 16;
				case EXPRESSION_LIST: return 414;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 47;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 86;
				case PRIMARY: return 49;
				case RPAREN: return 644;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 906:
			switch(symbol) {
				case AND: return 63;
				case DIV: return 188;
				case EAGER_AND: return 76;
				case EAGER_OR: return 29;
				case EQ: return 193;
				case GEQ: return 56;
				case GT: return 242;
				case INFIX_OP: return 426;
				case LEQ: return 103;
				case LT: return 223;
				case MINUS: return 48;
				case MULT: return 235;
				case NEQ: return 57;
				case OR: return 217;
				case PLUS: return 219;
				case REMAINDER: return 15;
				case XOR: return 19;
			}
			break;
		case 908:
			switch(symbol) {
				case ID: return 789;
			}
			break;
		case 911:
			switch(symbol) {
				case RPAREN: return 604;
			}
			break;
		case 912:
			switch(symbol) {
				case SEMICOLON: return 828;
			}
			break;
		case 913:
			switch(symbol) {
				case ASSIGN: return 617;
				case VARIABLE_DECLARATOR_REST: return 713;
			}
			break;
		case 915:
			switch(symbol) {
				case RPAREN: return 755;
			}
			break;
		case 916:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 377;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 140;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 107;
				case PRIMARY: return 117;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 918:
			switch(symbol) {
				case ID: return 593;
				case MULT: return 595;
			}
			break;
		case 919:
			switch(symbol) {
				case BOOLEAN_LIT: return 34;
				case CHAR_LIT: return 12;
				case EXPRESSION2: return 573;
				case IDENTIFIER: return 9;
				case INT_LIT: return 4;
				case LITERAL: return 30;
				case LPAREN: return 132;
				case MINUS: return 1;
				case NEW: return 2;
				case NOT: return 3;
				case NULL_LIT: return 61;
				case PREFIX_OP: return 207;
				case PRIMARY: return 441;
				case STRING_LIT: return 46;
				case THIS: return 13;
			}
			break;
		case 920:
			switch(symbol) {
				case ARGUMENTS: return 733;
				case LPAREN: return 131;
			}
			break;
		case 924:
			switch(symbol) {
				case ID: return 123;
				case LONG_IDENTIFIER: return 500;
				case QUALIFIED_IDENTIFIER: return 912;
			}
			break;
		case 928:
			switch(symbol) {
				case ID: return 635;
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
				case BOOLEAN_LIT: return 31;
				case CHAR_LIT: return 31;
				case INT_LIT: return 31;
				case LPAREN: return 31;
				case MINUS: return 31;
				case NEW: return 31;
				case NOT: return 31;
				case NULL_LIT: return 31;
				case STRING_LIT: return 31;
				case THIS: return 31;
			}
			break;
		case 3:
			switch(symbol) {
				case BOOLEAN_LIT: return 30;
				case CHAR_LIT: return 30;
				case INT_LIT: return 30;
				case LPAREN: return 30;
				case MINUS: return 30;
				case NEW: return 30;
				case NOT: return 30;
				case NULL_LIT: return 30;
				case STRING_LIT: return 30;
				case THIS: return 30;
			}
			break;
		case 4:
			switch(symbol) {
				case DOT: return 4;
				case LBRACKET: return 4;
			}
			break;
		case 5:
			switch(symbol) {
				case ABSTRACT: return 42;
				case AND: return 42;
				case ASSIGN: return 42;
				case BOOLEAN: return 42;
				case BYTE: return 42;
				case CHAR: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case FINAL: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case ID: return 42;
				case INT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NATIVE: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case PROTECTED: return 42;
				case PUBLIC: return 42;
				case RBRACE: return 42;
				case REMAINDER: return 42;
				case SEMICOLON: return 42;
				case SHORT: return 42;
				case STATIC: return 42;
				case VOID: return 42;
				case XOR: return 42;
			}
			break;
		case 9:
			switch(symbol) {
				case DOT: return 53;
				case LBRACKET: return 53;
			}
			break;
		case 10:
			switch(symbol) {
				case BOOLEAN_LIT: return 13;
				case CHAR_LIT: return 13;
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
		case 12:
			switch(symbol) {
				case DOT: return 5;
				case LBRACKET: return 5;
			}
			break;
		case 13:
			switch(symbol) {
				case DOT: return 50;
				case LBRACKET: return 50;
			}
			break;
		case 15:
			switch(symbol) {
				case BOOLEAN_LIT: return 29;
				case CHAR_LIT: return 29;
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
		case 16:
			switch(symbol) {
				case ASSIGN: return 35;
				case COMMA: return 35;
				case RPAREN: return 35;
			}
			break;
		case 17:
			switch(symbol) {
				case COMMA: return 32;
				case RPAREN: return 32;
			}
			break;
		case 18:
			switch(symbol) {
				case ARRAY: return 62;
				case RPAREN: return 62;
			}
			break;
		case 19:
			switch(symbol) {
				case BOOLEAN_LIT: return 18;
				case CHAR_LIT: return 18;
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
		case 22:
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
				case RBRACE: return 111;
				case SEMICOLON: return 111;
				case SHORT: return 111;
				case STATIC: return 111;
				case VOID: return 111;
			}
			break;
		case 26:
			switch(symbol) {
				case ARRAY: return 63;
				case RPAREN: return 63;
			}
			break;
		case 28:
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
		case 29:
			switch(symbol) {
				case BOOLEAN_LIT: return 14;
				case CHAR_LIT: return 14;
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
		case 30:
			switch(symbol) {
				case DOT: return 51;
				case LBRACKET: return 51;
			}
			break;
		case 32:
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
		case 33:
			switch(symbol) {
				case ASSIGN: return 11;
				case SEMICOLON: return 11;
			}
			break;
		case 34:
			switch(symbol) {
				case DOT: return 7;
				case LBRACKET: return 7;
			}
			break;
		case 36:
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
		case 37:
			switch(symbol) {
				case RPAREN: return 9;
			}
			break;
		case 38:
			switch(symbol) {
				case SEMICOLON: return 163;
			}
			break;
		case 40:
			switch(symbol) {
				case ABSTRACT: return 103;
				case CLASS: return 103;
				case FINAL: return 103;
				case INTERFACE: return 103;
				case NATIVE: return 103;
				case PROTECTED: return 103;
				case PUBLIC: return 103;
				case STATIC: return 103;
			}
			break;
		case 41:
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
		case 43:
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
		case 44:
			switch(symbol) {
				case END_TERMINAL: return 114;
			}
			break;
		case 45:
			switch(symbol) {
				case COMMA: return 135;
				case LBRACE: return 135;
			}
			break;
		case 46:
			switch(symbol) {
				case DOT: return 6;
				case LBRACKET: return 6;
			}
			break;
		case 48:
			switch(symbol) {
				case BOOLEAN_LIT: return 26;
				case CHAR_LIT: return 26;
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
		case 50:
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
		case 53:
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
		case 54:
			switch(symbol) {
				case RPAREN: return 11;
			}
			break;
		case 55:
			switch(symbol) {
				case LBRACE: return 163;
			}
			break;
		case 56:
			switch(symbol) {
				case BOOLEAN_LIT: return 22;
				case CHAR_LIT: return 22;
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
		case 57:
			switch(symbol) {
				case BOOLEAN_LIT: return 20;
				case CHAR_LIT: return 20;
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
		case 59:
			switch(symbol) {
				case ABSTRACT: return 37;
				case BOOLEAN: return 37;
				case BYTE: return 37;
				case CHAR: return 37;
				case FINAL: return 37;
				case ID: return 37;
				case INT: return 37;
				case NATIVE: return 37;
				case PROTECTED: return 37;
				case PUBLIC: return 37;
				case RBRACE: return 37;
				case SEMICOLON: return 37;
				case SHORT: return 37;
				case STATIC: return 37;
				case VOID: return 37;
			}
			break;
		case 60:
			switch(symbol) {
				case ABSTRACT: return 57;
				case AND: return 57;
				case BOOLEAN: return 57;
				case BYTE: return 57;
				case CHAR: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case FINAL: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case ID: return 57;
				case INSTANCEOF: return 57;
				case INT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NATIVE: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case PROTECTED: return 57;
				case PUBLIC: return 57;
				case RBRACE: return 57;
				case REMAINDER: return 57;
				case SEMICOLON: return 57;
				case SHORT: return 57;
				case STATIC: return 57;
				case VOID: return 57;
				case XOR: return 57;
			}
			break;
		case 61:
			switch(symbol) {
				case DOT: return 8;
				case LBRACKET: return 8;
			}
			break;
		case 63:
			switch(symbol) {
				case BOOLEAN_LIT: return 17;
				case CHAR_LIT: return 17;
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
		case 64:
			switch(symbol) {
				case ABSTRACT: return 102;
				case BOOLEAN: return 102;
				case BYTE: return 102;
				case CHAR: return 102;
				case FINAL: return 102;
				case ID: return 102;
				case INT: return 102;
				case NATIVE: return 102;
				case PROTECTED: return 102;
				case PUBLIC: return 102;
				case SHORT: return 102;
				case STATIC: return 102;
				case VOID: return 102;
			}
			break;
		case 65:
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
		case 67:
			switch(symbol) {
				case ARRAY: return 61;
				case RPAREN: return 61;
			}
			break;
		case 69:
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
		case 71:
			switch(symbol) {
				case COMMA: return 45;
				case RPAREN: return 45;
			}
			break;
		case 72:
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
		case 73:
			switch(symbol) {
				case RPAREN: return 32;
			}
			break;
		case 74:
			switch(symbol) {
				case ABSTRACT: return 43;
				case AND: return 43;
				case BOOLEAN: return 43;
				case BYTE: return 43;
				case CHAR: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case FINAL: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case ID: return 43;
				case INT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NATIVE: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case PROTECTED: return 43;
				case PUBLIC: return 43;
				case RBRACE: return 43;
				case REMAINDER: return 43;
				case SEMICOLON: return 43;
				case SHORT: return 43;
				case STATIC: return 43;
				case VOID: return 43;
				case XOR: return 43;
			}
			break;
		case 75:
			switch(symbol) {
				case ASSIGN: return 35;
				case RPAREN: return 35;
			}
			break;
		case 76:
			switch(symbol) {
				case BOOLEAN_LIT: return 15;
				case CHAR_LIT: return 15;
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
		case 77:
			switch(symbol) {
				case ARRAY: return 62;
				case COMMA: return 62;
				case LBRACE: return 62;
			}
			break;
		case 78:
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
		case 79:
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
		case 80:
			switch(symbol) {
				case COMMA: return 36;
				case RPAREN: return 36;
			}
			break;
		case 83:
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
		case 85:
			switch(symbol) {
				case END_TERMINAL: return 133;
			}
			break;
		case 87:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 88:
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
		case 89:
			switch(symbol) {
				case ABSTRACT: return 142;
				case BOOLEAN: return 142;
				case BYTE: return 142;
				case CHAR: return 142;
				case FINAL: return 142;
				case ID: return 142;
				case INT: return 142;
				case NATIVE: return 142;
				case PROTECTED: return 142;
				case PUBLIC: return 142;
				case RBRACE: return 142;
				case SEMICOLON: return 142;
				case SHORT: return 142;
				case STATIC: return 142;
				case VOID: return 142;
			}
			break;
		case 91:
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
		case 92:
			switch(symbol) {
				case ARRAY: return 1;
				case COMMA: return 1;
				case DOT: return 1;
				case LBRACE: return 1;
			}
			break;
		case 93:
			switch(symbol) {
				case ARRAY: return 61;
				case COMMA: return 61;
				case LBRACE: return 61;
			}
			break;
		case 94:
			switch(symbol) {
				case BOOLEAN: return 101;
				case BYTE: return 101;
				case CHAR: return 101;
				case ID: return 101;
				case INT: return 101;
				case SHORT: return 101;
				case VOID: return 101;
			}
			break;
		case 95:
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
		case 96:
			switch(symbol) {
				case BOOLEAN: return 80;
				case BYTE: return 80;
				case CHAR: return 80;
				case ID: return 80;
				case INT: return 80;
				case RBRACE: return 80;
				case SHORT: return 80;
			}
			break;
		case 100:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 103:
			switch(symbol) {
				case BOOLEAN_LIT: return 21;
				case CHAR_LIT: return 21;
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
		case 104:
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
		case 105:
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
		case 108:
			switch(symbol) {
				case BOOLEAN: return 100;
				case BYTE: return 100;
				case CHAR: return 100;
				case ID: return 100;
				case INT: return 100;
				case SHORT: return 100;
				case VOID: return 100;
			}
			break;
		case 109:
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
		case 111:
			switch(symbol) {
				case ABSTRACT: return 54;
				case AND: return 54;
				case BOOLEAN: return 54;
				case BYTE: return 54;
				case CHAR: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case FINAL: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case ID: return 54;
				case INSTANCEOF: return 54;
				case INT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NATIVE: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case PROTECTED: return 54;
				case PUBLIC: return 54;
				case RBRACE: return 54;
				case REMAINDER: return 54;
				case SEMICOLON: return 54;
				case SHORT: return 54;
				case STATIC: return 54;
				case VOID: return 54;
				case XOR: return 54;
			}
			break;
		case 113:
			switch(symbol) {
				case ARRAY: return 64;
				case COMMA: return 64;
				case LBRACE: return 64;
			}
			break;
		case 114:
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
		case 115:
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
		case 116:
			switch(symbol) {
				case ABSTRACT: return 61;
				case ARRAY: return 61;
				case ASSIGN: return 61;
				case BOOLEAN: return 61;
				case BYTE: return 61;
				case CHAR: return 61;
				case FINAL: return 61;
				case ID: return 61;
				case INT: return 61;
				case NATIVE: return 61;
				case PROTECTED: return 61;
				case PUBLIC: return 61;
				case RBRACE: return 61;
				case SEMICOLON: return 61;
				case SHORT: return 61;
				case STATIC: return 61;
				case VOID: return 61;
			}
			break;
		case 118:
			switch(symbol) {
				case ARRAY: return 64;
				case RPAREN: return 64;
			}
			break;
		case 119:
			switch(symbol) {
				case ASSIGN: return 35;
				case RBRACKET: return 35;
			}
			break;
		case 120:
			switch(symbol) {
				case RBRACKET: return 32;
			}
			break;
		case 123:
			switch(symbol) {
				case DOT: return 1;
				case SEMICOLON: return 1;
			}
			break;
		case 125:
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
		case 127:
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
		case 129:
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
		case 130:
			switch(symbol) {
				case RPAREN: return 73;
			}
			break;
		case 133:
			switch(symbol) {
				case END_TERMINAL: return 139;
			}
			break;
		case 135:
			switch(symbol) {
				case ABSTRACT: return 2;
				case ARRAY: return 2;
				case BOOLEAN: return 2;
				case BYTE: return 2;
				case CHAR: return 2;
				case DOT: return 2;
				case FINAL: return 2;
				case ID: return 2;
				case INT: return 2;
				case NATIVE: return 2;
				case PROTECTED: return 2;
				case PUBLIC: return 2;
				case RBRACE: return 2;
				case SEMICOLON: return 2;
				case SHORT: return 2;
				case STATIC: return 2;
				case VOID: return 2;
			}
			break;
		case 137:
			switch(symbol) {
				case ABSTRACT: return 44;
				case AND: return 44;
				case ASSIGN: return 44;
				case BOOLEAN: return 44;
				case BYTE: return 44;
				case CHAR: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case FINAL: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case ID: return 44;
				case INT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NATIVE: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case PROTECTED: return 44;
				case PUBLIC: return 44;
				case RBRACE: return 44;
				case REMAINDER: return 44;
				case SEMICOLON: return 44;
				case SHORT: return 44;
				case STATIC: return 44;
				case VOID: return 44;
				case XOR: return 44;
			}
			break;
		case 138:
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
		case 139:
			switch(symbol) {
				case AND: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case SEMICOLON: return 67;
				case XOR: return 67;
			}
			break;
		case 141:
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
		case 142:
			switch(symbol) {
				case ARRAY: return 60;
				case RPAREN: return 60;
			}
			break;
		case 144:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case SEMICOLON: return 63;
			}
			break;
		case 145:
			switch(symbol) {
				case ASSIGN: return 40;
				case RPAREN: return 40;
			}
			break;
		case 148:
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
		case 149:
			switch(symbol) {
				case END_TERMINAL: return 132;
			}
			break;
		case 150:
			switch(symbol) {
				case AND: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case RBRACKET: return 67;
				case REMAINDER: return 67;
				case XOR: return 67;
			}
			break;
		case 156:
			switch(symbol) {
				case ABSTRACT: return 123;
				case CLASS: return 123;
				case END_TERMINAL: return 123;
				case FINAL: return 123;
				case IMPORT: return 123;
				case INTERFACE: return 123;
				case NATIVE: return 123;
				case PROTECTED: return 123;
				case PUBLIC: return 123;
				case SEMICOLON: return 123;
				case STATIC: return 123;
			}
			break;
		case 157:
			switch(symbol) {
				case LPAREN: return 0;
			}
			break;
		case 158:
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
		case 160:
			switch(symbol) {
				case ASSIGN: return 37;
				case RBRACKET: return 37;
			}
			break;
		case 161:
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
		case 163:
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
		case 164:
			switch(symbol) {
				case RPAREN: return 35;
			}
			break;
		case 165:
			switch(symbol) {
				case RPAREN: return 33;
			}
			break;
		case 167:
			switch(symbol) {
				case ABSTRACT: return 58;
				case AND: return 58;
				case ASSIGN: return 58;
				case BOOLEAN: return 58;
				case BYTE: return 58;
				case CHAR: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case FINAL: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case ID: return 58;
				case INT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NATIVE: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case PROTECTED: return 58;
				case PUBLIC: return 58;
				case RBRACE: return 58;
				case REMAINDER: return 58;
				case SEMICOLON: return 58;
				case SHORT: return 58;
				case STATIC: return 58;
				case VOID: return 58;
				case XOR: return 58;
			}
			break;
		case 168:
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
		case 169:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 170:
			switch(symbol) {
				case ABSTRACT: return 68;
				case AND: return 68;
				case BOOLEAN: return 68;
				case BYTE: return 68;
				case CHAR: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case FINAL: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case ID: return 68;
				case INT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NATIVE: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case PROTECTED: return 68;
				case PUBLIC: return 68;
				case RBRACE: return 68;
				case REMAINDER: return 68;
				case SEMICOLON: return 68;
				case SHORT: return 68;
				case STATIC: return 68;
				case VOID: return 68;
				case XOR: return 68;
			}
			break;
		case 174:
			switch(symbol) {
				case ABSTRACT: return 55;
				case AND: return 55;
				case ASSIGN: return 55;
				case BOOLEAN: return 55;
				case BYTE: return 55;
				case CHAR: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case FINAL: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case ID: return 55;
				case INT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NATIVE: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case PROTECTED: return 55;
				case PUBLIC: return 55;
				case RBRACE: return 55;
				case REMAINDER: return 55;
				case SEMICOLON: return 55;
				case SHORT: return 55;
				case STATIC: return 55;
				case VOID: return 55;
				case XOR: return 55;
			}
			break;
		case 175:
			switch(symbol) {
				case ABSTRACT: return 55;
				case AND: return 55;
				case BOOLEAN: return 55;
				case BYTE: return 55;
				case CHAR: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case FINAL: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case ID: return 55;
				case INT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NATIVE: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case PROTECTED: return 55;
				case PUBLIC: return 55;
				case RBRACE: return 55;
				case REMAINDER: return 55;
				case SEMICOLON: return 55;
				case SHORT: return 55;
				case STATIC: return 55;
				case VOID: return 55;
				case XOR: return 55;
			}
			break;
		case 176:
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
		case 177:
			switch(symbol) {
				case END_TERMINAL: return 134;
			}
			break;
		case 180:
			switch(symbol) {
				case ABSTRACT: return 36;
				case ASSIGN: return 36;
				case BOOLEAN: return 36;
				case BYTE: return 36;
				case CHAR: return 36;
				case FINAL: return 36;
				case ID: return 36;
				case INT: return 36;
				case NATIVE: return 36;
				case PROTECTED: return 36;
				case PUBLIC: return 36;
				case RBRACE: return 36;
				case SEMICOLON: return 36;
				case SHORT: return 36;
				case STATIC: return 36;
				case VOID: return 36;
			}
			break;
		case 183:
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
		case 184:
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
		case 185:
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
		case 186:
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
		case 188:
			switch(symbol) {
				case BOOLEAN_LIT: return 28;
				case CHAR_LIT: return 28;
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
		case 189:
			switch(symbol) {
				case ABSTRACT: return 56;
				case AND: return 56;
				case BOOLEAN: return 56;
				case BYTE: return 56;
				case CHAR: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case FINAL: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case ID: return 56;
				case INSTANCEOF: return 56;
				case INT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NATIVE: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case PROTECTED: return 56;
				case PUBLIC: return 56;
				case RBRACE: return 56;
				case REMAINDER: return 56;
				case SEMICOLON: return 56;
				case SHORT: return 56;
				case STATIC: return 56;
				case VOID: return 56;
				case XOR: return 56;
			}
			break;
		case 191:
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
		case 192:
			switch(symbol) {
				case ABSTRACT: return 41;
				case AND: return 41;
				case BOOLEAN: return 41;
				case BYTE: return 41;
				case CHAR: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case FINAL: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case ID: return 41;
				case INT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NATIVE: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case PROTECTED: return 41;
				case PUBLIC: return 41;
				case RBRACE: return 41;
				case REMAINDER: return 41;
				case SEMICOLON: return 41;
				case SHORT: return 41;
				case STATIC: return 41;
				case VOID: return 41;
				case XOR: return 41;
			}
			break;
		case 193:
			switch(symbol) {
				case BOOLEAN_LIT: return 19;
				case CHAR_LIT: return 19;
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
		case 196:
			switch(symbol) {
				case ASSIGN: return 11;
				case COMMA: return 11;
				case RPAREN: return 11;
			}
			break;
		case 197:
			switch(symbol) {
				case RBRACKET: return 40;
			}
			break;
		case 200:
			switch(symbol) {
				case BOOLEAN: return 101;
				case BYTE: return 101;
				case CHAR: return 101;
				case ID: return 101;
				case INT: return 101;
				case SHORT: return 101;
				case VOID: return 101;
			}
			break;
		case 201:
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
		case 203:
			switch(symbol) {
				case ABSTRACT: return 35;
				case ASSIGN: return 35;
				case BOOLEAN: return 35;
				case BYTE: return 35;
				case CHAR: return 35;
				case FINAL: return 35;
				case ID: return 35;
				case INT: return 35;
				case NATIVE: return 35;
				case PROTECTED: return 35;
				case PUBLIC: return 35;
				case RBRACE: return 35;
				case SEMICOLON: return 35;
				case SHORT: return 35;
				case STATIC: return 35;
				case VOID: return 35;
			}
			break;
		case 204:
			switch(symbol) {
				case ABSTRACT: return 32;
				case BOOLEAN: return 32;
				case BYTE: return 32;
				case CHAR: return 32;
				case FINAL: return 32;
				case ID: return 32;
				case INT: return 32;
				case NATIVE: return 32;
				case PROTECTED: return 32;
				case PUBLIC: return 32;
				case RBRACE: return 32;
				case SEMICOLON: return 32;
				case SHORT: return 32;
				case STATIC: return 32;
				case VOID: return 32;
			}
			break;
		case 205:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 206:
			switch(symbol) {
				case ABSTRACT: return 11;
				case BOOLEAN: return 11;
				case BYTE: return 11;
				case CHAR: return 11;
				case FINAL: return 11;
				case ID: return 11;
				case INT: return 11;
				case NATIVE: return 11;
				case PROTECTED: return 11;
				case PUBLIC: return 11;
				case RBRACE: return 11;
				case SEMICOLON: return 11;
				case SHORT: return 11;
				case STATIC: return 11;
				case VOID: return 11;
			}
			break;
		case 209:
			switch(symbol) {
				case ARRAY: return 63;
				case COMMA: return 63;
				case RPAREN: return 63;
			}
			break;
		case 210:
			switch(symbol) {
				case RBRACE: return 79;
			}
			break;
		case 211:
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
		case 214:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 216:
			switch(symbol) {
				case ASSIGN: return 36;
				case RPAREN: return 36;
			}
			break;
		case 217:
			switch(symbol) {
				case BOOLEAN_LIT: return 16;
				case CHAR_LIT: return 16;
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
		case 218:
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
		case 219:
			switch(symbol) {
				case BOOLEAN_LIT: return 25;
				case CHAR_LIT: return 25;
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
		case 220:
			switch(symbol) {
				case ABSTRACT: return 58;
				case AND: return 58;
				case BOOLEAN: return 58;
				case BYTE: return 58;
				case CHAR: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case FINAL: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case ID: return 58;
				case INT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NATIVE: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case PROTECTED: return 58;
				case PUBLIC: return 58;
				case RBRACE: return 58;
				case REMAINDER: return 58;
				case SEMICOLON: return 58;
				case SHORT: return 58;
				case STATIC: return 58;
				case VOID: return 58;
				case XOR: return 58;
			}
			break;
		case 221:
			switch(symbol) {
				case RBRACKET: return 37;
			}
			break;
		case 223:
			switch(symbol) {
				case BOOLEAN_LIT: return 24;
				case CHAR_LIT: return 24;
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
		case 226:
			switch(symbol) {
				case COMMA: return 9;
				case RPAREN: return 9;
			}
			break;
		case 228:
			switch(symbol) {
				case ASSIGN: return 9;
				case COMMA: return 9;
				case RPAREN: return 9;
			}
			break;
		case 230:
			switch(symbol) {
				case ABSTRACT: return 59;
				case AND: return 59;
				case ASSIGN: return 59;
				case BOOLEAN: return 59;
				case BYTE: return 59;
				case CHAR: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case FINAL: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case ID: return 59;
				case INSTANCEOF: return 59;
				case INT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NATIVE: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case PROTECTED: return 59;
				case PUBLIC: return 59;
				case RBRACE: return 59;
				case REMAINDER: return 59;
				case SEMICOLON: return 59;
				case SHORT: return 59;
				case STATIC: return 59;
				case VOID: return 59;
				case XOR: return 59;
			}
			break;
		case 231:
			switch(symbol) {
				case RPAREN: return 74;
			}
			break;
		case 232:
			switch(symbol) {
				case DOT: return 70;
				case LBRACKET: return 70;
			}
			break;
		case 234:
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
		case 235:
			switch(symbol) {
				case BOOLEAN_LIT: return 27;
				case CHAR_LIT: return 27;
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
		case 236:
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
		case 238:
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
		case 239:
			switch(symbol) {
				case COMMA: return 164;
				case RPAREN: return 164;
			}
			break;
		case 240:
			switch(symbol) {
				case ABSTRACT: return 9;
				case BOOLEAN: return 9;
				case BYTE: return 9;
				case CHAR: return 9;
				case FINAL: return 9;
				case ID: return 9;
				case INT: return 9;
				case NATIVE: return 9;
				case PROTECTED: return 9;
				case PUBLIC: return 9;
				case RBRACE: return 9;
				case SEMICOLON: return 9;
				case SHORT: return 9;
				case STATIC: return 9;
				case VOID: return 9;
			}
			break;
		case 242:
			switch(symbol) {
				case BOOLEAN_LIT: return 23;
				case CHAR_LIT: return 23;
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
		case 243:
			switch(symbol) {
				case LBRACE: return 67;
				case RPAREN: return 67;
			}
			break;
		case 245:
			switch(symbol) {
				case ARRAY: return 60;
				case COMMA: return 60;
				case RPAREN: return 60;
			}
			break;
		case 246:
			switch(symbol) {
				case ABSTRACT: return 63;
				case ARRAY: return 63;
				case BOOLEAN: return 63;
				case BYTE: return 63;
				case CHAR: return 63;
				case FINAL: return 63;
				case ID: return 63;
				case INT: return 63;
				case NATIVE: return 63;
				case PROTECTED: return 63;
				case PUBLIC: return 63;
				case RBRACE: return 63;
				case SEMICOLON: return 63;
				case SHORT: return 63;
				case STATIC: return 63;
				case VOID: return 63;
			}
			break;
		case 248:
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
		case 249:
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
		case 253:
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
				case COMMA: return 11;
				case RPAREN: return 11;
			}
			break;
		case 261:
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
		case 262:
			switch(symbol) {
				case END_TERMINAL: return 129;
			}
			break;
		case 263:
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
		case 264:
			switch(symbol) {
				case ARRAY: return 2;
				case COMMA: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 266:
			switch(symbol) {
				case ABSTRACT: return 67;
				case AND: return 67;
				case BOOLEAN: return 67;
				case BYTE: return 67;
				case CHAR: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case FINAL: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case ID: return 67;
				case INT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NATIVE: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case PROTECTED: return 67;
				case PUBLIC: return 67;
				case RBRACE: return 67;
				case REMAINDER: return 67;
				case SEMICOLON: return 67;
				case SHORT: return 67;
				case STATIC: return 67;
				case VOID: return 67;
				case XOR: return 67;
			}
			break;
		case 267:
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
		case 269:
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
		case 271:
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
		case 275:
			switch(symbol) {
				case ABSTRACT: return 68;
				case AND: return 68;
				case ASSIGN: return 68;
				case BOOLEAN: return 68;
				case BYTE: return 68;
				case CHAR: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case FINAL: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case ID: return 68;
				case INSTANCEOF: return 68;
				case INT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NATIVE: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case PROTECTED: return 68;
				case PUBLIC: return 68;
				case RBRACE: return 68;
				case REMAINDER: return 68;
				case SEMICOLON: return 68;
				case SHORT: return 68;
				case STATIC: return 68;
				case VOID: return 68;
				case XOR: return 68;
			}
			break;
		case 276:
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
		case 278:
			switch(symbol) {
				case END_TERMINAL: return 128;
			}
			break;
		case 279:
			switch(symbol) {
				case ABSTRACT: return 54;
				case AND: return 54;
				case ASSIGN: return 54;
				case BOOLEAN: return 54;
				case BYTE: return 54;
				case CHAR: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case FINAL: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case ID: return 54;
				case INSTANCEOF: return 54;
				case INT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NATIVE: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case PROTECTED: return 54;
				case PUBLIC: return 54;
				case RBRACE: return 54;
				case REMAINDER: return 54;
				case SEMICOLON: return 54;
				case SHORT: return 54;
				case STATIC: return 54;
				case VOID: return 54;
				case XOR: return 54;
			}
			break;
		case 280:
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
		case 281:
			switch(symbol) {
				case IMPLEMENTS: return 11;
				case LBRACE: return 11;
			}
			break;
		case 282:
			switch(symbol) {
				case CLASS: return 101;
				case END_TERMINAL: return 122;
				case INTERFACE: return 101;
			}
			break;
		case 283:
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
		case 284:
			switch(symbol) {
				case ABSTRACT: return 55;
				case AND: return 55;
				case ASSIGN: return 55;
				case BOOLEAN: return 55;
				case BYTE: return 55;
				case CHAR: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case FINAL: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case ID: return 55;
				case INSTANCEOF: return 55;
				case INT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NATIVE: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case PROTECTED: return 55;
				case PUBLIC: return 55;
				case RBRACE: return 55;
				case REMAINDER: return 55;
				case SEMICOLON: return 55;
				case SHORT: return 55;
				case STATIC: return 55;
				case VOID: return 55;
				case XOR: return 55;
			}
			break;
		case 285:
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
		case 286:
			switch(symbol) {
				case IMPLEMENTS: return 12;
				case LBRACE: return 12;
			}
			break;
		case 288:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 291:
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
		case 292:
			switch(symbol) {
				case ABSTRACT: return 60;
				case ARRAY: return 60;
				case BOOLEAN: return 60;
				case BYTE: return 60;
				case CHAR: return 60;
				case FINAL: return 60;
				case ID: return 60;
				case INT: return 60;
				case NATIVE: return 60;
				case PROTECTED: return 60;
				case PUBLIC: return 60;
				case RBRACE: return 60;
				case SEMICOLON: return 60;
				case SHORT: return 60;
				case STATIC: return 60;
				case VOID: return 60;
			}
			break;
		case 293:
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
		case 294:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 296:
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
		case 297:
			switch(symbol) {
				case CLASS: return 100;
				case INTERFACE: return 100;
			}
			break;
		case 299:
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
		case 300:
			switch(symbol) {
				case COMMA: return 136;
				case LBRACE: return 136;
			}
			break;
		case 301:
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
		case 303:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case RBRACKET: return 2;
			}
			break;
		case 306:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case RBRACKET: return 64;
			}
			break;
		case 307:
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
		case 310:
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
		case 311:
			switch(symbol) {
				case BOOLEAN: return 101;
				case BYTE: return 101;
				case CHAR: return 101;
				case ID: return 101;
				case INT: return 101;
				case SHORT: return 101;
				case VOID: return 101;
			}
			break;
		case 315:
			switch(symbol) {
				case COMMA: return 11;
				case LBRACE: return 11;
			}
			break;
		case 319:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 320:
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
		case 321:
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
		case 322:
			switch(symbol) {
				case ABSTRACT: return 2;
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case BOOLEAN: return 2;
				case BYTE: return 2;
				case CHAR: return 2;
				case DOT: return 2;
				case FINAL: return 2;
				case ID: return 2;
				case INT: return 2;
				case NATIVE: return 2;
				case PROTECTED: return 2;
				case PUBLIC: return 2;
				case RBRACE: return 2;
				case SEMICOLON: return 2;
				case SHORT: return 2;
				case STATIC: return 2;
				case VOID: return 2;
			}
			break;
		case 323:
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
		case 324:
			switch(symbol) {
				case IMPLEMENTS: return 9;
				case LBRACE: return 9;
			}
			break;
		case 325:
			switch(symbol) {
				case COMMA: return 35;
				case RPAREN: return 35;
			}
			break;
		case 326:
			switch(symbol) {
				case COMMA: return 33;
				case RPAREN: return 33;
			}
			break;
		case 328:
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
		case 329:
			switch(symbol) {
				case AND: return 38;
				case ASSIGN: return 38;
				case DIV: return 38;
				case EAGER_AND: return 38;
				case EAGER_OR: return 38;
				case EQ: return 38;
				case GEQ: return 38;
				case GT: return 38;
				case LEQ: return 38;
				case LT: return 38;
				case MINUS: return 38;
				case MULT: return 38;
				case NEQ: return 38;
				case OR: return 38;
				case PLUS: return 38;
				case RBRACKET: return 38;
				case REMAINDER: return 38;
				case XOR: return 38;
			}
			break;
		case 330:
			switch(symbol) {
				case RPAREN: return 72;
			}
			break;
		case 331:
			switch(symbol) {
				case ABSTRACT: return 56;
				case AND: return 56;
				case ASSIGN: return 56;
				case BOOLEAN: return 56;
				case BYTE: return 56;
				case CHAR: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case FINAL: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case ID: return 56;
				case INT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NATIVE: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case PROTECTED: return 56;
				case PUBLIC: return 56;
				case RBRACE: return 56;
				case REMAINDER: return 56;
				case SEMICOLON: return 56;
				case SHORT: return 56;
				case STATIC: return 56;
				case VOID: return 56;
				case XOR: return 56;
			}
			break;
		case 332:
			switch(symbol) {
				case ABSTRACT: return 54;
				case AND: return 54;
				case BOOLEAN: return 54;
				case BYTE: return 54;
				case CHAR: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case FINAL: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case ID: return 54;
				case INT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NATIVE: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case PROTECTED: return 54;
				case PUBLIC: return 54;
				case RBRACE: return 54;
				case REMAINDER: return 54;
				case SEMICOLON: return 54;
				case SHORT: return 54;
				case STATIC: return 54;
				case VOID: return 54;
				case XOR: return 54;
			}
			break;
		case 333:
			switch(symbol) {
				case ARRAY: return 63;
				case COMMA: return 63;
				case LBRACE: return 63;
			}
			break;
		case 334:
			switch(symbol) {
				case AND: return 67;
				case ASSIGN: return 67;
				case COMMA: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case INSTANCEOF: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case RPAREN: return 67;
				case XOR: return 67;
			}
			break;
		case 335:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 336:
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
		case 337:
			switch(symbol) {
				case ASSIGN: return 10;
				case SEMICOLON: return 10;
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
				case ABSTRACT: return 39;
				case AND: return 39;
				case ASSIGN: return 39;
				case BOOLEAN: return 39;
				case BYTE: return 39;
				case CHAR: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case FINAL: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case ID: return 39;
				case INT: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NATIVE: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case PROTECTED: return 39;
				case PUBLIC: return 39;
				case RBRACE: return 39;
				case REMAINDER: return 39;
				case SEMICOLON: return 39;
				case SHORT: return 39;
				case STATIC: return 39;
				case VOID: return 39;
				case XOR: return 39;
			}
			break;
		case 340:
			switch(symbol) {
				case LBRACE: return 163;
				case SEMICOLON: return 163;
			}
			break;
		case 341:
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
		case 342:
			switch(symbol) {
				case ASSIGN: return 10;
				case COMMA: return 10;
				case RPAREN: return 10;
			}
			break;
		case 343:
			switch(symbol) {
				case SEMICOLON: return 40;
			}
			break;
		case 346:
			switch(symbol) {
				case ABSTRACT: return 67;
				case AND: return 67;
				case ASSIGN: return 67;
				case BOOLEAN: return 67;
				case BYTE: return 67;
				case CHAR: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case FINAL: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case ID: return 67;
				case INT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NATIVE: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case PROTECTED: return 67;
				case PUBLIC: return 67;
				case RBRACE: return 67;
				case REMAINDER: return 67;
				case SEMICOLON: return 67;
				case SHORT: return 67;
				case STATIC: return 67;
				case VOID: return 67;
				case XOR: return 67;
			}
			break;
		case 347:
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
		case 349:
			switch(symbol) {
				case ARRAY: return 60;
				case COMMA: return 60;
				case LBRACE: return 60;
			}
			break;
		case 350:
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
		case 358:
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
		case 359:
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
		case 360:
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
		case 361:
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
		case 362:
			switch(symbol) {
				case ABSTRACT: return 12;
				case ASSIGN: return 12;
				case BOOLEAN: return 12;
				case BYTE: return 12;
				case CHAR: return 12;
				case FINAL: return 12;
				case ID: return 12;
				case INT: return 12;
				case NATIVE: return 12;
				case PROTECTED: return 12;
				case PUBLIC: return 12;
				case RBRACE: return 12;
				case SEMICOLON: return 12;
				case SHORT: return 12;
				case STATIC: return 12;
				case VOID: return 12;
			}
			break;
		case 363:
			switch(symbol) {
				case SEMICOLON: return 12;
			}
			break;
		case 366:
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
				case RBRACE: return 112;
				case SEMICOLON: return 112;
				case SHORT: return 112;
				case STATIC: return 112;
				case VOID: return 112;
			}
			break;
		case 368:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 369:
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
		case 371:
			switch(symbol) {
				case BOOLEAN: return 81;
				case BYTE: return 81;
				case CHAR: return 81;
				case ID: return 81;
				case INT: return 81;
				case RBRACE: return 81;
				case SHORT: return 81;
			}
			break;
		case 373:
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
		case 374:
			switch(symbol) {
				case ABSTRACT: return 55;
				case AND: return 55;
				case BOOLEAN: return 55;
				case BYTE: return 55;
				case CHAR: return 55;
				case DIV: return 55;
				case DOT: return 55;
				case EAGER_AND: return 55;
				case EAGER_OR: return 55;
				case EQ: return 55;
				case FINAL: return 55;
				case GEQ: return 55;
				case GT: return 55;
				case ID: return 55;
				case INSTANCEOF: return 55;
				case INT: return 55;
				case LBRACKET: return 55;
				case LEQ: return 55;
				case LT: return 55;
				case MINUS: return 55;
				case MULT: return 55;
				case NATIVE: return 55;
				case NEQ: return 55;
				case OR: return 55;
				case PLUS: return 55;
				case PROTECTED: return 55;
				case PUBLIC: return 55;
				case RBRACE: return 55;
				case REMAINDER: return 55;
				case SEMICOLON: return 55;
				case SHORT: return 55;
				case STATIC: return 55;
				case VOID: return 55;
				case XOR: return 55;
			}
			break;
		case 377:
			switch(symbol) {
				case ABSTRACT: return 38;
				case AND: return 38;
				case BOOLEAN: return 38;
				case BYTE: return 38;
				case CHAR: return 38;
				case DIV: return 38;
				case EAGER_AND: return 38;
				case EAGER_OR: return 38;
				case EQ: return 38;
				case FINAL: return 38;
				case GEQ: return 38;
				case GT: return 38;
				case ID: return 38;
				case INT: return 38;
				case LEQ: return 38;
				case LT: return 38;
				case MINUS: return 38;
				case MULT: return 38;
				case NATIVE: return 38;
				case NEQ: return 38;
				case OR: return 38;
				case PLUS: return 38;
				case PROTECTED: return 38;
				case PUBLIC: return 38;
				case RBRACE: return 38;
				case REMAINDER: return 38;
				case SEMICOLON: return 38;
				case SHORT: return 38;
				case STATIC: return 38;
				case VOID: return 38;
				case XOR: return 38;
			}
			break;
		case 379:
			switch(symbol) {
				case ABSTRACT: return 43;
				case AND: return 43;
				case ASSIGN: return 43;
				case BOOLEAN: return 43;
				case BYTE: return 43;
				case CHAR: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case FINAL: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case ID: return 43;
				case INT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NATIVE: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case PROTECTED: return 43;
				case PUBLIC: return 43;
				case RBRACE: return 43;
				case REMAINDER: return 43;
				case SEMICOLON: return 43;
				case SHORT: return 43;
				case STATIC: return 43;
				case VOID: return 43;
				case XOR: return 43;
			}
			break;
		case 380:
			switch(symbol) {
				case ARRAY: return 62;
				case ASSIGN: return 62;
				case SEMICOLON: return 62;
			}
			break;
		case 381:
			switch(symbol) {
				case ARRAY: return 64;
				case RBRACKET: return 64;
			}
			break;
		case 383:
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
		case 387:
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
		case 390:
			switch(symbol) {
				case AND: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case INSTANCEOF: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case RBRACKET: return 67;
				case REMAINDER: return 67;
				case XOR: return 67;
			}
			break;
		case 393:
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
		case 394:
			switch(symbol) {
				case AND: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case INSTANCEOF: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case RPAREN: return 67;
				case XOR: return 67;
			}
			break;
		case 395:
			switch(symbol) {
				case AND: return 67;
				case ASSIGN: return 67;
				case COMMA: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case RPAREN: return 67;
				case XOR: return 67;
			}
			break;
		case 397:
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
		case 399:
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
		case 400:
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
		case 401:
			switch(symbol) {
				case RPAREN: return 137;
			}
			break;
		case 402:
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
		case 403:
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
		case 404:
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
		case 408:
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
		case 409:
			switch(symbol) {
				case RPAREN: return 40;
			}
			break;
		case 410:
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
		case 411:
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
		case 412:
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
		case 415:
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
		case 418:
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
		case 419:
			switch(symbol) {
				case ABSTRACT: return 10;
				case BOOLEAN: return 10;
				case BYTE: return 10;
				case CHAR: return 10;
				case FINAL: return 10;
				case ID: return 10;
				case INT: return 10;
				case NATIVE: return 10;
				case PROTECTED: return 10;
				case PUBLIC: return 10;
				case RBRACE: return 10;
				case SEMICOLON: return 10;
				case SHORT: return 10;
				case STATIC: return 10;
				case VOID: return 10;
			}
			break;
		case 420:
			switch(symbol) {
				case LPAREN: return 3;
			}
			break;
		case 423:
			switch(symbol) {
				case AND: return 67;
				case ASSIGN: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case INSTANCEOF: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case SEMICOLON: return 67;
				case XOR: return 67;
			}
			break;
		case 427:
			switch(symbol) {
				case ABSTRACT: return 62;
				case ARRAY: return 62;
				case ASSIGN: return 62;
				case BOOLEAN: return 62;
				case BYTE: return 62;
				case CHAR: return 62;
				case FINAL: return 62;
				case ID: return 62;
				case INT: return 62;
				case NATIVE: return 62;
				case PROTECTED: return 62;
				case PUBLIC: return 62;
				case RBRACE: return 62;
				case SEMICOLON: return 62;
				case SHORT: return 62;
				case STATIC: return 62;
				case VOID: return 62;
			}
			break;
		case 428:
			switch(symbol) {
				case ARRAY: return 60;
				case ASSIGN: return 60;
				case SEMICOLON: return 60;
			}
			break;
		case 429:
			switch(symbol) {
				case ABSTRACT: return 57;
				case AND: return 57;
				case ASSIGN: return 57;
				case BOOLEAN: return 57;
				case BYTE: return 57;
				case CHAR: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case FINAL: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case ID: return 57;
				case INT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NATIVE: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case PROTECTED: return 57;
				case PUBLIC: return 57;
				case RBRACE: return 57;
				case REMAINDER: return 57;
				case SEMICOLON: return 57;
				case SHORT: return 57;
				case STATIC: return 57;
				case VOID: return 57;
				case XOR: return 57;
			}
			break;
		case 430:
			switch(symbol) {
				case ARRAY: return 61;
				case ASSIGN: return 61;
				case SEMICOLON: return 61;
			}
			break;
		case 431:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case RPAREN: return 64;
			}
			break;
		case 432:
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
		case 434:
			switch(symbol) {
				case AND: return 38;
				case ASSIGN: return 38;
				case DIV: return 38;
				case EAGER_AND: return 38;
				case EAGER_OR: return 38;
				case EQ: return 38;
				case GEQ: return 38;
				case GT: return 38;
				case LEQ: return 38;
				case LT: return 38;
				case MINUS: return 38;
				case MULT: return 38;
				case NEQ: return 38;
				case OR: return 38;
				case PLUS: return 38;
				case REMAINDER: return 38;
				case RPAREN: return 38;
				case XOR: return 38;
			}
			break;
		case 435:
			switch(symbol) {
				case SEMICOLON: return 9;
			}
			break;
		case 436:
			switch(symbol) {
				case ABSTRACT: return 33;
				case BOOLEAN: return 33;
				case BYTE: return 33;
				case CHAR: return 33;
				case FINAL: return 33;
				case ID: return 33;
				case INT: return 33;
				case NATIVE: return 33;
				case PROTECTED: return 33;
				case PUBLIC: return 33;
				case RBRACE: return 33;
				case SEMICOLON: return 33;
				case SHORT: return 33;
				case STATIC: return 33;
				case VOID: return 33;
			}
			break;
		case 437:
			switch(symbol) {
				case ABSTRACT: return 35;
				case BOOLEAN: return 35;
				case BYTE: return 35;
				case CHAR: return 35;
				case FINAL: return 35;
				case ID: return 35;
				case INT: return 35;
				case NATIVE: return 35;
				case PROTECTED: return 35;
				case PUBLIC: return 35;
				case RBRACE: return 35;
				case SEMICOLON: return 35;
				case SHORT: return 35;
				case STATIC: return 35;
				case VOID: return 35;
			}
			break;
		case 439:
			switch(symbol) {
				case ABSTRACT: return 44;
				case AND: return 44;
				case BOOLEAN: return 44;
				case BYTE: return 44;
				case CHAR: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case FINAL: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case ID: return 44;
				case INSTANCEOF: return 44;
				case INT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NATIVE: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case PROTECTED: return 44;
				case PUBLIC: return 44;
				case RBRACE: return 44;
				case REMAINDER: return 44;
				case SEMICOLON: return 44;
				case SHORT: return 44;
				case STATIC: return 44;
				case VOID: return 44;
				case XOR: return 44;
			}
			break;
		case 440:
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
		case 444:
			switch(symbol) {
				case ARRAY: return 64;
				case IMPLEMENTS: return 64;
				case LBRACE: return 64;
			}
			break;
		case 446:
			switch(symbol) {
				case RPAREN: return 36;
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
				case RBRACKET: return 55;
				case REMAINDER: return 55;
				case XOR: return 55;
			}
			break;
		case 448:
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
		case 450:
			switch(symbol) {
				case ABSTRACT: return 44;
				case AND: return 44;
				case BOOLEAN: return 44;
				case BYTE: return 44;
				case CHAR: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case FINAL: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case ID: return 44;
				case INT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NATIVE: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case PROTECTED: return 44;
				case PUBLIC: return 44;
				case RBRACE: return 44;
				case REMAINDER: return 44;
				case SEMICOLON: return 44;
				case SHORT: return 44;
				case STATIC: return 44;
				case VOID: return 44;
				case XOR: return 44;
			}
			break;
		case 451:
			switch(symbol) {
				case ABSTRACT: return 118;
				case CLASS: return 118;
				case END_TERMINAL: return 118;
				case FINAL: return 118;
				case INTERFACE: return 118;
				case NATIVE: return 118;
				case PROTECTED: return 118;
				case PUBLIC: return 118;
				case SEMICOLON: return 118;
				case STATIC: return 118;
			}
			break;
		case 455:
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
		case 457:
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
		case 462:
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
		case 465:
			switch(symbol) {
				case END_TERMINAL: return 125;
			}
			break;
		case 466:
			switch(symbol) {
				case ARRAY: return 64;
				case COMMA: return 64;
				case RPAREN: return 64;
			}
			break;
		case 467:
			switch(symbol) {
				case ABSTRACT: return 40;
				case ASSIGN: return 40;
				case BOOLEAN: return 40;
				case BYTE: return 40;
				case CHAR: return 40;
				case FINAL: return 40;
				case ID: return 40;
				case INT: return 40;
				case NATIVE: return 40;
				case PROTECTED: return 40;
				case PUBLIC: return 40;
				case RBRACE: return 40;
				case SEMICOLON: return 40;
				case SHORT: return 40;
				case STATIC: return 40;
				case VOID: return 40;
			}
			break;
		case 468:
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
		case 469:
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
		case 471:
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
		case 473:
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
		case 474:
			switch(symbol) {
				case ABSTRACT: return 62;
				case ARRAY: return 62;
				case BOOLEAN: return 62;
				case BYTE: return 62;
				case CHAR: return 62;
				case FINAL: return 62;
				case ID: return 62;
				case INT: return 62;
				case NATIVE: return 62;
				case PROTECTED: return 62;
				case PUBLIC: return 62;
				case RBRACE: return 62;
				case SEMICOLON: return 62;
				case SHORT: return 62;
				case STATIC: return 62;
				case VOID: return 62;
			}
			break;
		case 475:
			switch(symbol) {
				case ABSTRACT: return 42;
				case AND: return 42;
				case BOOLEAN: return 42;
				case BYTE: return 42;
				case CHAR: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case FINAL: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case ID: return 42;
				case INT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NATIVE: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case PROTECTED: return 42;
				case PUBLIC: return 42;
				case RBRACE: return 42;
				case REMAINDER: return 42;
				case SEMICOLON: return 42;
				case SHORT: return 42;
				case STATIC: return 42;
				case VOID: return 42;
				case XOR: return 42;
			}
			break;
		case 477:
			switch(symbol) {
				case ABSTRACT: return 38;
				case AND: return 38;
				case ASSIGN: return 38;
				case BOOLEAN: return 38;
				case BYTE: return 38;
				case CHAR: return 38;
				case DIV: return 38;
				case EAGER_AND: return 38;
				case EAGER_OR: return 38;
				case EQ: return 38;
				case FINAL: return 38;
				case GEQ: return 38;
				case GT: return 38;
				case ID: return 38;
				case INT: return 38;
				case LEQ: return 38;
				case LT: return 38;
				case MINUS: return 38;
				case MULT: return 38;
				case NATIVE: return 38;
				case NEQ: return 38;
				case OR: return 38;
				case PLUS: return 38;
				case PROTECTED: return 38;
				case PUBLIC: return 38;
				case RBRACE: return 38;
				case REMAINDER: return 38;
				case SEMICOLON: return 38;
				case SHORT: return 38;
				case STATIC: return 38;
				case VOID: return 38;
				case XOR: return 38;
			}
			break;
		case 478:
			switch(symbol) {
				case AND: return 67;
				case ASSIGN: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case RPAREN: return 67;
				case XOR: return 67;
			}
			break;
		case 479:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 483:
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
		case 487:
			switch(symbol) {
				case ABSTRACT: return 75;
				case BOOLEAN: return 75;
				case BYTE: return 75;
				case CHAR: return 75;
				case FINAL: return 75;
				case ID: return 75;
				case INT: return 75;
				case NATIVE: return 75;
				case PROTECTED: return 75;
				case PUBLIC: return 75;
				case RBRACE: return 75;
				case SEMICOLON: return 75;
				case SHORT: return 75;
				case STATIC: return 75;
				case VOID: return 75;
			}
			break;
		case 489:
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
		case 492:
			switch(symbol) {
				case ABSTRACT: return 59;
				case AND: return 59;
				case BOOLEAN: return 59;
				case BYTE: return 59;
				case CHAR: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case FINAL: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case ID: return 59;
				case INT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NATIVE: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case PROTECTED: return 59;
				case PUBLIC: return 59;
				case RBRACE: return 59;
				case REMAINDER: return 59;
				case SEMICOLON: return 59;
				case SHORT: return 59;
				case STATIC: return 59;
				case VOID: return 59;
				case XOR: return 59;
			}
			break;
		case 493:
			switch(symbol) {
				case ABSTRACT: return 1;
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case BOOLEAN: return 1;
				case BYTE: return 1;
				case CHAR: return 1;
				case DOT: return 1;
				case FINAL: return 1;
				case ID: return 1;
				case INT: return 1;
				case NATIVE: return 1;
				case PROTECTED: return 1;
				case PUBLIC: return 1;
				case RBRACE: return 1;
				case SEMICOLON: return 1;
				case SHORT: return 1;
				case STATIC: return 1;
				case VOID: return 1;
			}
			break;
		case 494:
			switch(symbol) {
				case ABSTRACT: return 67;
				case AND: return 67;
				case ASSIGN: return 67;
				case BOOLEAN: return 67;
				case BYTE: return 67;
				case CHAR: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case FINAL: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case ID: return 67;
				case INSTANCEOF: return 67;
				case INT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NATIVE: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case PROTECTED: return 67;
				case PUBLIC: return 67;
				case RBRACE: return 67;
				case REMAINDER: return 67;
				case SEMICOLON: return 67;
				case SHORT: return 67;
				case STATIC: return 67;
				case VOID: return 67;
				case XOR: return 67;
			}
			break;
		case 497:
			switch(symbol) {
				case DOT: return 52;
				case LBRACKET: return 52;
			}
			break;
		case 498:
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
		case 499:
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
		case 500:
			switch(symbol) {
				case SEMICOLON: return 3;
			}
			break;
		case 502:
			switch(symbol) {
				case ABSTRACT: return 141;
				case BOOLEAN: return 141;
				case BYTE: return 141;
				case CHAR: return 141;
				case FINAL: return 141;
				case ID: return 141;
				case INT: return 141;
				case NATIVE: return 141;
				case PROTECTED: return 141;
				case PUBLIC: return 141;
				case RBRACE: return 141;
				case SEMICOLON: return 141;
				case SHORT: return 141;
				case STATIC: return 141;
				case VOID: return 141;
			}
			break;
		case 503:
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
		case 504:
			switch(symbol) {
				case ABSTRACT: return 1;
				case ARRAY: return 1;
				case BOOLEAN: return 1;
				case BYTE: return 1;
				case CHAR: return 1;
				case DOT: return 1;
				case FINAL: return 1;
				case ID: return 1;
				case INT: return 1;
				case NATIVE: return 1;
				case PROTECTED: return 1;
				case PUBLIC: return 1;
				case RBRACE: return 1;
				case SEMICOLON: return 1;
				case SHORT: return 1;
				case STATIC: return 1;
				case VOID: return 1;
			}
			break;
		case 506:
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
		case 507:
			switch(symbol) {
				case ASSIGN: return 36;
				case SEMICOLON: return 36;
			}
			break;
		case 509:
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
		case 510:
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
		case 512:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 513:
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
		case 514:
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
		case 515:
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
		case 518:
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
		case 519:
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
		case 520:
			switch(symbol) {
				case ASSIGN: return 12;
				case SEMICOLON: return 12;
			}
			break;
		case 522:
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
		case 524:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 526:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case COMMA: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 530:
			switch(symbol) {
				case ARRAY: return 60;
				case ASSIGN: return 60;
				case RBRACKET: return 60;
			}
			break;
		case 531:
			switch(symbol) {
				case AND: return 67;
				case COMMA: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case INSTANCEOF: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case RPAREN: return 67;
				case XOR: return 67;
			}
			break;
		case 532:
			switch(symbol) {
				case ABSTRACT: return 61;
				case ARRAY: return 61;
				case BOOLEAN: return 61;
				case BYTE: return 61;
				case CHAR: return 61;
				case FINAL: return 61;
				case ID: return 61;
				case INT: return 61;
				case NATIVE: return 61;
				case PROTECTED: return 61;
				case PUBLIC: return 61;
				case RBRACE: return 61;
				case SEMICOLON: return 61;
				case SHORT: return 61;
				case STATIC: return 61;
				case VOID: return 61;
			}
			break;
		case 533:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case COMMA: return 64;
				case RPAREN: return 64;
			}
			break;
		case 535:
			switch(symbol) {
				case ABSTRACT: return 40;
				case BOOLEAN: return 40;
				case BYTE: return 40;
				case CHAR: return 40;
				case FINAL: return 40;
				case ID: return 40;
				case INT: return 40;
				case NATIVE: return 40;
				case PROTECTED: return 40;
				case PUBLIC: return 40;
				case RBRACE: return 40;
				case SEMICOLON: return 40;
				case SHORT: return 40;
				case STATIC: return 40;
				case VOID: return 40;
			}
			break;
		case 537:
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
		case 540:
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
		case 544:
			switch(symbol) {
				case AND: return 67;
				case ASSIGN: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case INSTANCEOF: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case RPAREN: return 67;
				case XOR: return 67;
			}
			break;
		case 545:
			switch(symbol) {
				case RBRACKET: return 9;
			}
			break;
		case 546:
			switch(symbol) {
				case END_TERMINAL: return 131;
			}
			break;
		case 550:
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
		case 551:
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
		case 553:
			switch(symbol) {
				case ASSIGN: return 37;
				case SEMICOLON: return 37;
			}
			break;
		case 556:
			switch(symbol) {
				case ASSIGN: return 40;
				case COMMA: return 40;
				case RPAREN: return 40;
			}
			break;
		case 558:
			switch(symbol) {
				case ABSTRACT: return 64;
				case ARRAY: return 64;
				case BOOLEAN: return 64;
				case BYTE: return 64;
				case CHAR: return 64;
				case FINAL: return 64;
				case ID: return 64;
				case INT: return 64;
				case NATIVE: return 64;
				case PROTECTED: return 64;
				case PUBLIC: return 64;
				case RBRACE: return 64;
				case SEMICOLON: return 64;
				case SHORT: return 64;
				case STATIC: return 64;
				case VOID: return 64;
			}
			break;
		case 559:
			switch(symbol) {
				case ASSIGN: return 37;
				case COMMA: return 37;
				case RPAREN: return 37;
			}
			break;
		case 561:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 562:
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
		case 563:
			switch(symbol) {
				case AND: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case RPAREN: return 67;
				case XOR: return 67;
			}
			break;
		case 564:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case RBRACKET: return 63;
			}
			break;
		case 565:
			switch(symbol) {
				case ABSTRACT: return 57;
				case AND: return 57;
				case ASSIGN: return 57;
				case BOOLEAN: return 57;
				case BYTE: return 57;
				case CHAR: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case FINAL: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case ID: return 57;
				case INSTANCEOF: return 57;
				case INT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NATIVE: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case PROTECTED: return 57;
				case PUBLIC: return 57;
				case RBRACE: return 57;
				case REMAINDER: return 57;
				case SEMICOLON: return 57;
				case SHORT: return 57;
				case STATIC: return 57;
				case VOID: return 57;
				case XOR: return 57;
			}
			break;
		case 567:
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
		case 568:
			switch(symbol) {
				case ASSIGN: return 11;
				case RPAREN: return 11;
			}
			break;
		case 569:
			switch(symbol) {
				case ARRAY: return 63;
				case RBRACKET: return 63;
			}
			break;
		case 570:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 571:
			switch(symbol) {
				case AND: return 38;
				case DIV: return 38;
				case EAGER_AND: return 38;
				case EAGER_OR: return 38;
				case EQ: return 38;
				case GEQ: return 38;
				case GT: return 38;
				case LEQ: return 38;
				case LT: return 38;
				case MINUS: return 38;
				case MULT: return 38;
				case NEQ: return 38;
				case OR: return 38;
				case PLUS: return 38;
				case REMAINDER: return 38;
				case RPAREN: return 38;
				case XOR: return 38;
			}
			break;
		case 572:
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
		case 573:
			switch(symbol) {
				case AND: return 38;
				case DIV: return 38;
				case EAGER_AND: return 38;
				case EAGER_OR: return 38;
				case EQ: return 38;
				case GEQ: return 38;
				case GT: return 38;
				case LEQ: return 38;
				case LT: return 38;
				case MINUS: return 38;
				case MULT: return 38;
				case NEQ: return 38;
				case OR: return 38;
				case PLUS: return 38;
				case RBRACKET: return 38;
				case REMAINDER: return 38;
				case XOR: return 38;
			}
			break;
		case 575:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 576:
			switch(symbol) {
				case RBRACKET: return 33;
			}
			break;
		case 577:
			switch(symbol) {
				case RBRACKET: return 35;
			}
			break;
		case 581:
			switch(symbol) {
				case ASSIGN: return 9;
				case RPAREN: return 9;
			}
			break;
		case 582:
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
		case 583:
			switch(symbol) {
				case BOOLEAN: return 101;
				case BYTE: return 101;
				case CHAR: return 101;
				case ID: return 101;
				case INT: return 101;
				case SHORT: return 101;
				case VOID: return 101;
			}
			break;
		case 584:
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
		case 586:
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
		case 588:
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
		case 589:
			switch(symbol) {
				case ARRAY: return 62;
				case ASSIGN: return 62;
				case COMMA: return 62;
				case RPAREN: return 62;
			}
			break;
		case 593:
			switch(symbol) {
				case DOT: return 2;
				case SEMICOLON: return 2;
			}
			break;
		case 598:
			switch(symbol) {
				case AND: return 38;
				case ASSIGN: return 38;
				case COMMA: return 38;
				case DIV: return 38;
				case EAGER_AND: return 38;
				case EAGER_OR: return 38;
				case EQ: return 38;
				case GEQ: return 38;
				case GT: return 38;
				case LEQ: return 38;
				case LT: return 38;
				case MINUS: return 38;
				case MULT: return 38;
				case NEQ: return 38;
				case OR: return 38;
				case PLUS: return 38;
				case REMAINDER: return 38;
				case RPAREN: return 38;
				case XOR: return 38;
			}
			break;
		case 600:
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
		case 601:
			switch(symbol) {
				case ARRAY: return 2;
				case COMMA: return 2;
				case DOT: return 2;
				case LBRACE: return 2;
			}
			break;
		case 602:
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
		case 603:
			switch(symbol) {
				case ARRAY: return 60;
				case RBRACKET: return 60;
			}
			break;
		case 606:
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
		case 608:
			switch(symbol) {
				case ABSTRACT: return 41;
				case AND: return 41;
				case ASSIGN: return 41;
				case BOOLEAN: return 41;
				case BYTE: return 41;
				case CHAR: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case FINAL: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case ID: return 41;
				case INT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NATIVE: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case PROTECTED: return 41;
				case PUBLIC: return 41;
				case RBRACE: return 41;
				case REMAINDER: return 41;
				case SEMICOLON: return 41;
				case SHORT: return 41;
				case STATIC: return 41;
				case VOID: return 41;
				case XOR: return 41;
			}
			break;
		case 609:
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
		case 610:
			switch(symbol) {
				case COMMA: return 12;
				case LBRACE: return 12;
			}
			break;
		case 611:
			switch(symbol) {
				case ABSTRACT: return 54;
				case AND: return 54;
				case ASSIGN: return 54;
				case BOOLEAN: return 54;
				case BYTE: return 54;
				case CHAR: return 54;
				case DIV: return 54;
				case DOT: return 54;
				case EAGER_AND: return 54;
				case EAGER_OR: return 54;
				case EQ: return 54;
				case FINAL: return 54;
				case GEQ: return 54;
				case GT: return 54;
				case ID: return 54;
				case INT: return 54;
				case LBRACKET: return 54;
				case LEQ: return 54;
				case LT: return 54;
				case MINUS: return 54;
				case MULT: return 54;
				case NATIVE: return 54;
				case NEQ: return 54;
				case OR: return 54;
				case PLUS: return 54;
				case PROTECTED: return 54;
				case PUBLIC: return 54;
				case RBRACE: return 54;
				case REMAINDER: return 54;
				case SEMICOLON: return 54;
				case SHORT: return 54;
				case STATIC: return 54;
				case VOID: return 54;
				case XOR: return 54;
			}
			break;
		case 612:
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
		case 614:
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
		case 615:
			switch(symbol) {
				case RBRACKET: return 11;
			}
			break;
		case 616:
			switch(symbol) {
				case ABSTRACT: return 119;
				case CLASS: return 119;
				case END_TERMINAL: return 119;
				case FINAL: return 119;
				case IMPORT: return 119;
				case INTERFACE: return 119;
				case NATIVE: return 119;
				case PROTECTED: return 119;
				case PUBLIC: return 119;
				case SEMICOLON: return 119;
				case STATIC: return 119;
			}
			break;
		case 619:
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
		case 620:
			switch(symbol) {
				case ASSIGN: return 9;
				case RBRACKET: return 9;
			}
			break;
		case 622:
			switch(symbol) {
				case ARRAY: return 61;
				case IMPLEMENTS: return 61;
				case LBRACE: return 61;
			}
			break;
		case 623:
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
		case 624:
			switch(symbol) {
				case RBRACKET: return 10;
			}
			break;
		case 625:
			switch(symbol) {
				case RPAREN: return 138;
			}
			break;
		case 627:
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
		case 628:
			switch(symbol) {
				case COMMA: return 9;
				case LBRACE: return 9;
			}
			break;
		case 629:
			switch(symbol) {
				case END_TERMINAL: return 126;
			}
			break;
		case 630:
			switch(symbol) {
				case ABSTRACT: return 63;
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case BOOLEAN: return 63;
				case BYTE: return 63;
				case CHAR: return 63;
				case FINAL: return 63;
				case ID: return 63;
				case INT: return 63;
				case NATIVE: return 63;
				case PROTECTED: return 63;
				case PUBLIC: return 63;
				case RBRACE: return 63;
				case SEMICOLON: return 63;
				case SHORT: return 63;
				case STATIC: return 63;
				case VOID: return 63;
			}
			break;
		case 631:
			switch(symbol) {
				case SEMICOLON: return 10;
			}
			break;
		case 632:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case DOT: return 2;
				case RBRACKET: return 2;
			}
			break;
		case 633:
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
		case 635:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case SEMICOLON: return 2;
			}
			break;
		case 636:
			switch(symbol) {
				case ABSTRACT: return 102;
				case CLASS: return 102;
				case FINAL: return 102;
				case INTERFACE: return 102;
				case NATIVE: return 102;
				case PROTECTED: return 102;
				case PUBLIC: return 102;
				case STATIC: return 102;
			}
			break;
		case 639:
			switch(symbol) {
				case COMMA: return 113;
				case RPAREN: return 113;
			}
			break;
		case 640:
			switch(symbol) {
				case ASSIGN: return 40;
				case SEMICOLON: return 40;
			}
			break;
		case 642:
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
		case 643:
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
		case 644:
			switch(symbol) {
				case AND: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case INSTANCEOF: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case SEMICOLON: return 67;
				case XOR: return 67;
			}
			break;
		case 645:
			switch(symbol) {
				case SEMICOLON: return 37;
			}
			break;
		case 646:
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
		case 647:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case RPAREN: return 63;
			}
			break;
		case 648:
			switch(symbol) {
				case ASSIGN: return 12;
				case RPAREN: return 12;
			}
			break;
		case 649:
			switch(symbol) {
				case END_TERMINAL: return 137;
			}
			break;
		case 650:
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
		case 651:
			switch(symbol) {
				case ASSIGN: return 11;
				case RBRACKET: return 11;
			}
			break;
		case 653:
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
		case 655:
			switch(symbol) {
				case ABSTRACT: return 59;
				case AND: return 59;
				case ASSIGN: return 59;
				case BOOLEAN: return 59;
				case BYTE: return 59;
				case CHAR: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case FINAL: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case ID: return 59;
				case INT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NATIVE: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case PROTECTED: return 59;
				case PUBLIC: return 59;
				case RBRACE: return 59;
				case REMAINDER: return 59;
				case SEMICOLON: return 59;
				case SHORT: return 59;
				case STATIC: return 59;
				case VOID: return 59;
				case XOR: return 59;
			}
			break;
		case 658:
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
		case 659:
			switch(symbol) {
				case ABSTRACT: return 68;
				case AND: return 68;
				case ASSIGN: return 68;
				case BOOLEAN: return 68;
				case BYTE: return 68;
				case CHAR: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case FINAL: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case ID: return 68;
				case INT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NATIVE: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case PROTECTED: return 68;
				case PUBLIC: return 68;
				case RBRACE: return 68;
				case REMAINDER: return 68;
				case SEMICOLON: return 68;
				case SHORT: return 68;
				case STATIC: return 68;
				case VOID: return 68;
				case XOR: return 68;
			}
			break;
		case 660:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case DOT: return 1;
				case SEMICOLON: return 1;
			}
			break;
		case 661:
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
		case 662:
			switch(symbol) {
				case LBRACE: return 68;
				case RPAREN: return 68;
			}
			break;
		case 664:
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
		case 665:
			switch(symbol) {
				case ABSTRACT: return 9;
				case ASSIGN: return 9;
				case BOOLEAN: return 9;
				case BYTE: return 9;
				case CHAR: return 9;
				case FINAL: return 9;
				case ID: return 9;
				case INT: return 9;
				case NATIVE: return 9;
				case PROTECTED: return 9;
				case PUBLIC: return 9;
				case RBRACE: return 9;
				case SEMICOLON: return 9;
				case SHORT: return 9;
				case STATIC: return 9;
				case VOID: return 9;
			}
			break;
		case 666:
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
		case 667:
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
		case 668:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 669:
			switch(symbol) {
				case ARRAY: return 60;
				case ASSIGN: return 60;
				case RPAREN: return 60;
			}
			break;
		case 671:
			switch(symbol) {
				case ABSTRACT: return 12;
				case BOOLEAN: return 12;
				case BYTE: return 12;
				case CHAR: return 12;
				case FINAL: return 12;
				case ID: return 12;
				case INT: return 12;
				case NATIVE: return 12;
				case PROTECTED: return 12;
				case PUBLIC: return 12;
				case RBRACE: return 12;
				case SEMICOLON: return 12;
				case SHORT: return 12;
				case STATIC: return 12;
				case VOID: return 12;
			}
			break;
		case 673:
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
		case 675:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case SEMICOLON: return 1;
			}
			break;
		case 676:
			switch(symbol) {
				case SEMICOLON: return 36;
			}
			break;
		case 677:
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
		case 678:
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
		case 679:
			switch(symbol) {
				case ABSTRACT: return 116;
				case CLASS: return 116;
				case END_TERMINAL: return 116;
				case FINAL: return 116;
				case IMPORT: return 116;
				case INTERFACE: return 116;
				case NATIVE: return 116;
				case PROTECTED: return 116;
				case PUBLIC: return 116;
				case SEMICOLON: return 116;
				case STATIC: return 116;
			}
			break;
		case 680:
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
		case 682:
			switch(symbol) {
				case ARRAY: return 63;
				case IMPLEMENTS: return 63;
				case LBRACE: return 63;
			}
			break;
		case 683:
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
		case 684:
			switch(symbol) {
				case AND: return 38;
				case ASSIGN: return 38;
				case DIV: return 38;
				case EAGER_AND: return 38;
				case EAGER_OR: return 38;
				case EQ: return 38;
				case GEQ: return 38;
				case GT: return 38;
				case LEQ: return 38;
				case LT: return 38;
				case MINUS: return 38;
				case MULT: return 38;
				case NEQ: return 38;
				case OR: return 38;
				case PLUS: return 38;
				case REMAINDER: return 38;
				case SEMICOLON: return 38;
				case XOR: return 38;
			}
			break;
		case 685:
			switch(symbol) {
				case ABSTRACT: return 44;
				case AND: return 44;
				case ASSIGN: return 44;
				case BOOLEAN: return 44;
				case BYTE: return 44;
				case CHAR: return 44;
				case DIV: return 44;
				case EAGER_AND: return 44;
				case EAGER_OR: return 44;
				case EQ: return 44;
				case FINAL: return 44;
				case GEQ: return 44;
				case GT: return 44;
				case ID: return 44;
				case INSTANCEOF: return 44;
				case INT: return 44;
				case LEQ: return 44;
				case LT: return 44;
				case MINUS: return 44;
				case MULT: return 44;
				case NATIVE: return 44;
				case NEQ: return 44;
				case OR: return 44;
				case PLUS: return 44;
				case PROTECTED: return 44;
				case PUBLIC: return 44;
				case RBRACE: return 44;
				case REMAINDER: return 44;
				case SEMICOLON: return 44;
				case SHORT: return 44;
				case STATIC: return 44;
				case VOID: return 44;
				case XOR: return 44;
			}
			break;
		case 688:
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
		case 689:
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
		case 691:
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
		case 692:
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
		case 693:
			switch(symbol) {
				case ABSTRACT: return 11;
				case ASSIGN: return 11;
				case BOOLEAN: return 11;
				case BYTE: return 11;
				case CHAR: return 11;
				case FINAL: return 11;
				case ID: return 11;
				case INT: return 11;
				case NATIVE: return 11;
				case PROTECTED: return 11;
				case PUBLIC: return 11;
				case RBRACE: return 11;
				case SEMICOLON: return 11;
				case SHORT: return 11;
				case STATIC: return 11;
				case VOID: return 11;
			}
			break;
		case 696:
			switch(symbol) {
				case ARRAY: return 62;
				case SEMICOLON: return 62;
			}
			break;
		case 697:
			switch(symbol) {
				case AND: return 67;
				case ASSIGN: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case RBRACKET: return 67;
				case REMAINDER: return 67;
				case XOR: return 67;
			}
			break;
		case 700:
			switch(symbol) {
				case ABSTRACT: return 60;
				case ARRAY: return 60;
				case ASSIGN: return 60;
				case BOOLEAN: return 60;
				case BYTE: return 60;
				case CHAR: return 60;
				case FINAL: return 60;
				case ID: return 60;
				case INT: return 60;
				case NATIVE: return 60;
				case PROTECTED: return 60;
				case PUBLIC: return 60;
				case RBRACE: return 60;
				case SEMICOLON: return 60;
				case SHORT: return 60;
				case STATIC: return 60;
				case VOID: return 60;
			}
			break;
		case 701:
			switch(symbol) {
				case ASSIGN: return 37;
				case RPAREN: return 37;
			}
			break;
		case 702:
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
		case 703:
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
		case 705:
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
		case 706:
			switch(symbol) {
				case ASSIGN: return 36;
				case RBRACKET: return 36;
			}
			break;
		case 708:
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
		case 709:
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
		case 710:
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
		case 711:
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
		case 712:
			switch(symbol) {
				case ARRAY: return 61;
				case ASSIGN: return 61;
				case COMMA: return 61;
				case RPAREN: return 61;
			}
			break;
		case 713:
			switch(symbol) {
				case SEMICOLON: return 110;
			}
			break;
		case 714:
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
		case 715:
			switch(symbol) {
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case SEMICOLON: return 64;
			}
			break;
		case 716:
			switch(symbol) {
				case RPAREN: return 12;
			}
			break;
		case 717:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 720:
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
		case 723:
			switch(symbol) {
				case AND: return 38;
				case COMMA: return 38;
				case DIV: return 38;
				case EAGER_AND: return 38;
				case EAGER_OR: return 38;
				case EQ: return 38;
				case GEQ: return 38;
				case GT: return 38;
				case LEQ: return 38;
				case LT: return 38;
				case MINUS: return 38;
				case MULT: return 38;
				case NEQ: return 38;
				case OR: return 38;
				case PLUS: return 38;
				case REMAINDER: return 38;
				case RPAREN: return 38;
				case XOR: return 38;
			}
			break;
		case 724:
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
		case 726:
			switch(symbol) {
				case DOT: return 69;
				case LBRACKET: return 69;
			}
			break;
		case 727:
			switch(symbol) {
				case ARRAY: return 60;
				case IMPLEMENTS: return 60;
				case LBRACE: return 60;
			}
			break;
		case 728:
			switch(symbol) {
				case END_TERMINAL: return 140;
			}
			break;
		case 729:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case DOT: return 1;
				case RBRACKET: return 1;
			}
			break;
		case 730:
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
		case 731:
			switch(symbol) {
				case ARRAY: return 60;
				case ASSIGN: return 60;
				case COMMA: return 60;
				case RPAREN: return 60;
			}
			break;
		case 732:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 733:
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
		case 734:
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
		case 736:
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
		case 737:
			switch(symbol) {
				case ABSTRACT: return 56;
				case AND: return 56;
				case BOOLEAN: return 56;
				case BYTE: return 56;
				case CHAR: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case FINAL: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case ID: return 56;
				case INT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NATIVE: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case PROTECTED: return 56;
				case PUBLIC: return 56;
				case RBRACE: return 56;
				case REMAINDER: return 56;
				case SEMICOLON: return 56;
				case SHORT: return 56;
				case STATIC: return 56;
				case VOID: return 56;
				case XOR: return 56;
			}
			break;
		case 739:
			switch(symbol) {
				case BOOLEAN: return 101;
				case BYTE: return 101;
				case CHAR: return 101;
				case ID: return 101;
				case INT: return 101;
				case SHORT: return 101;
				case VOID: return 101;
			}
			break;
		case 741:
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
		case 742:
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
		case 743:
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
		case 744:
			switch(symbol) {
				case END_TERMINAL: return 127;
			}
			break;
		case 745:
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
		case 746:
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
		case 748:
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
		case 749:
			switch(symbol) {
				case END_TERMINAL: return 138;
			}
			break;
		case 750:
			switch(symbol) {
				case ARRAY: return 61;
				case ASSIGN: return 61;
				case RBRACKET: return 61;
			}
			break;
		case 751:
			switch(symbol) {
				case AND: return 38;
				case DIV: return 38;
				case EAGER_AND: return 38;
				case EAGER_OR: return 38;
				case EQ: return 38;
				case GEQ: return 38;
				case GT: return 38;
				case LEQ: return 38;
				case LT: return 38;
				case MINUS: return 38;
				case MULT: return 38;
				case NEQ: return 38;
				case OR: return 38;
				case PLUS: return 38;
				case REMAINDER: return 38;
				case SEMICOLON: return 38;
				case XOR: return 38;
			}
			break;
		case 753:
			switch(symbol) {
				case ARRAY: return 61;
				case SEMICOLON: return 61;
			}
			break;
		case 754:
			switch(symbol) {
				case COMMA: return 165;
				case RPAREN: return 165;
			}
			break;
		case 755:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 756:
			switch(symbol) {
				case ARRAY: return 62;
				case ASSIGN: return 62;
				case RBRACKET: return 62;
			}
			break;
		case 757:
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
		case 758:
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
		case 759:
			switch(symbol) {
				case ABSTRACT: return 42;
				case AND: return 42;
				case BOOLEAN: return 42;
				case BYTE: return 42;
				case CHAR: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case FINAL: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case ID: return 42;
				case INSTANCEOF: return 42;
				case INT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NATIVE: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case PROTECTED: return 42;
				case PUBLIC: return 42;
				case RBRACE: return 42;
				case REMAINDER: return 42;
				case SEMICOLON: return 42;
				case SHORT: return 42;
				case STATIC: return 42;
				case VOID: return 42;
				case XOR: return 42;
			}
			break;
		case 762:
			switch(symbol) {
				case DOT: return 1;
				case LPAREN: return 1;
			}
			break;
		case 763:
			switch(symbol) {
				case AND: return 67;
				case ASSIGN: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case INSTANCEOF: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case RBRACKET: return 67;
				case REMAINDER: return 67;
				case XOR: return 67;
			}
			break;
		case 764:
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
		case 768:
			switch(symbol) {
				case AND: return 67;
				case COMMA: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case RPAREN: return 67;
				case XOR: return 67;
			}
			break;
		case 769:
			switch(symbol) {
				case SEMICOLON: return 35;
			}
			break;
		case 770:
			switch(symbol) {
				case SEMICOLON: return 33;
			}
			break;
		case 771:
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
		case 772:
			switch(symbol) {
				case ARRAY: return 64;
				case SEMICOLON: return 64;
			}
			break;
		case 775:
			switch(symbol) {
				case COMMA: return 46;
				case RPAREN: return 46;
			}
			break;
		case 777:
			switch(symbol) {
				case ARRAY: return 62;
				case RBRACKET: return 62;
			}
			break;
		case 778:
			switch(symbol) {
				case ABSTRACT: return 103;
				case BOOLEAN: return 103;
				case BYTE: return 103;
				case CHAR: return 103;
				case FINAL: return 103;
				case ID: return 103;
				case INT: return 103;
				case NATIVE: return 103;
				case PROTECTED: return 103;
				case PUBLIC: return 103;
				case SHORT: return 103;
				case STATIC: return 103;
				case VOID: return 103;
			}
			break;
		case 779:
			switch(symbol) {
				case ABSTRACT: return 43;
				case AND: return 43;
				case ASSIGN: return 43;
				case BOOLEAN: return 43;
				case BYTE: return 43;
				case CHAR: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case FINAL: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case ID: return 43;
				case INSTANCEOF: return 43;
				case INT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NATIVE: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case PROTECTED: return 43;
				case PUBLIC: return 43;
				case RBRACE: return 43;
				case REMAINDER: return 43;
				case SEMICOLON: return 43;
				case SHORT: return 43;
				case STATIC: return 43;
				case VOID: return 43;
				case XOR: return 43;
			}
			break;
		case 780:
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
		case 782:
			switch(symbol) {
				case ARRAY: return 63;
				case ASSIGN: return 63;
				case COMMA: return 63;
				case RPAREN: return 63;
			}
			break;
		case 783:
			switch(symbol) {
				case AND: return 67;
				case ASSIGN: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case REMAINDER: return 67;
				case SEMICOLON: return 67;
				case XOR: return 67;
			}
			break;
		case 785:
			switch(symbol) {
				case ASSIGN: return 12;
				case COMMA: return 12;
				case RPAREN: return 12;
			}
			break;
		case 788:
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
		case 789:
			switch(symbol) {
				case DOT: return 2;
				case LPAREN: return 2;
			}
			break;
		case 790:
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
		case 791:
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
		case 793:
			switch(symbol) {
				case ABSTRACT: return 58;
				case AND: return 58;
				case ASSIGN: return 58;
				case BOOLEAN: return 58;
				case BYTE: return 58;
				case CHAR: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case FINAL: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case ID: return 58;
				case INSTANCEOF: return 58;
				case INT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NATIVE: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case PROTECTED: return 58;
				case PUBLIC: return 58;
				case RBRACE: return 58;
				case REMAINDER: return 58;
				case SEMICOLON: return 58;
				case SHORT: return 58;
				case STATIC: return 58;
				case VOID: return 58;
				case XOR: return 58;
			}
			break;
		case 794:
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
		case 796:
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
		case 798:
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
		case 800:
			switch(symbol) {
				case SEMICOLON: return 32;
			}
			break;
		case 801:
			switch(symbol) {
				case ASSIGN: return 35;
				case SEMICOLON: return 35;
			}
			break;
		case 802:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case RBRACKET: return 1;
			}
			break;
		case 803:
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
		case 804:
			switch(symbol) {
				case ASSIGN: return 40;
				case RBRACKET: return 40;
			}
			break;
		case 805:
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
		case 807:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 808:
			switch(symbol) {
				case ABSTRACT: return 56;
				case AND: return 56;
				case ASSIGN: return 56;
				case BOOLEAN: return 56;
				case BYTE: return 56;
				case CHAR: return 56;
				case DIV: return 56;
				case DOT: return 56;
				case EAGER_AND: return 56;
				case EAGER_OR: return 56;
				case EQ: return 56;
				case FINAL: return 56;
				case GEQ: return 56;
				case GT: return 56;
				case ID: return 56;
				case INSTANCEOF: return 56;
				case INT: return 56;
				case LBRACKET: return 56;
				case LEQ: return 56;
				case LT: return 56;
				case MINUS: return 56;
				case MULT: return 56;
				case NATIVE: return 56;
				case NEQ: return 56;
				case OR: return 56;
				case PLUS: return 56;
				case PROTECTED: return 56;
				case PUBLIC: return 56;
				case RBRACE: return 56;
				case REMAINDER: return 56;
				case SEMICOLON: return 56;
				case SHORT: return 56;
				case STATIC: return 56;
				case VOID: return 56;
				case XOR: return 56;
			}
			break;
		case 809:
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
		case 810:
			switch(symbol) {
				case ARRAY: return 61;
				case COMMA: return 61;
				case RPAREN: return 61;
			}
			break;
		case 811:
			switch(symbol) {
				case IMPLEMENTS: return 10;
				case LBRACE: return 10;
			}
			break;
		case 812:
			switch(symbol) {
				case SEMICOLON: return 75;
			}
			break;
		case 814:
			switch(symbol) {
				case RPAREN: return 10;
			}
			break;
		case 815:
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
		case 820:
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
		case 821:
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
		case 822:
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
		case 823:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 824:
			switch(symbol) {
				case ARRAY: return 2;
				case DOT: return 2;
				case IMPLEMENTS: return 2;
				case LBRACE: return 2;
			}
			break;
		case 825:
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
		case 827:
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
		case 828:
			switch(symbol) {
				case ABSTRACT: return 115;
				case CLASS: return 115;
				case END_TERMINAL: return 115;
				case FINAL: return 115;
				case IMPORT: return 115;
				case INTERFACE: return 115;
				case NATIVE: return 115;
				case PROTECTED: return 115;
				case PUBLIC: return 115;
				case SEMICOLON: return 115;
				case STATIC: return 115;
			}
			break;
		case 830:
			switch(symbol) {
				case ABSTRACT: return 37;
				case ASSIGN: return 37;
				case BOOLEAN: return 37;
				case BYTE: return 37;
				case CHAR: return 37;
				case FINAL: return 37;
				case ID: return 37;
				case INT: return 37;
				case NATIVE: return 37;
				case PROTECTED: return 37;
				case PUBLIC: return 37;
				case RBRACE: return 37;
				case SEMICOLON: return 37;
				case SHORT: return 37;
				case STATIC: return 37;
				case VOID: return 37;
			}
			break;
		case 832:
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
		case 833:
			switch(symbol) {
				case ASSIGN: return 12;
				case RBRACKET: return 12;
			}
			break;
		case 834:
			switch(symbol) {
				case COMMA: return 10;
				case RPAREN: return 10;
			}
			break;
		case 836:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case DOT: return 2;
				case SEMICOLON: return 2;
			}
			break;
		case 837:
			switch(symbol) {
				case ARRAY: return 62;
				case COMMA: return 62;
				case RPAREN: return 62;
			}
			break;
		case 838:
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
		case 840:
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
		case 841:
			switch(symbol) {
				case SEMICOLON: return 112;
			}
			break;
		case 842:
			switch(symbol) {
				case DOT: return 49;
				case LBRACKET: return 49;
			}
			break;
		case 843:
			switch(symbol) {
				case ABSTRACT: return 39;
				case AND: return 39;
				case BOOLEAN: return 39;
				case BYTE: return 39;
				case CHAR: return 39;
				case DIV: return 39;
				case EAGER_AND: return 39;
				case EAGER_OR: return 39;
				case EQ: return 39;
				case FINAL: return 39;
				case GEQ: return 39;
				case GT: return 39;
				case ID: return 39;
				case INT: return 39;
				case LEQ: return 39;
				case LT: return 39;
				case MINUS: return 39;
				case MULT: return 39;
				case NATIVE: return 39;
				case NEQ: return 39;
				case OR: return 39;
				case PLUS: return 39;
				case PROTECTED: return 39;
				case PUBLIC: return 39;
				case RBRACE: return 39;
				case REMAINDER: return 39;
				case SEMICOLON: return 39;
				case SHORT: return 39;
				case STATIC: return 39;
				case VOID: return 39;
				case XOR: return 39;
			}
			break;
		case 844:
			switch(symbol) {
				case ARRAY: return 62;
				case ASSIGN: return 62;
				case RPAREN: return 62;
			}
			break;
		case 845:
			switch(symbol) {
				case ABSTRACT: return 64;
				case ARRAY: return 64;
				case ASSIGN: return 64;
				case BOOLEAN: return 64;
				case BYTE: return 64;
				case CHAR: return 64;
				case FINAL: return 64;
				case ID: return 64;
				case INT: return 64;
				case NATIVE: return 64;
				case PROTECTED: return 64;
				case PUBLIC: return 64;
				case RBRACE: return 64;
				case SEMICOLON: return 64;
				case SHORT: return 64;
				case STATIC: return 64;
				case VOID: return 64;
			}
			break;
		case 846:
			switch(symbol) {
				case ARRAY: return 2;
				case ASSIGN: return 2;
				case COMMA: return 2;
				case DOT: return 2;
				case RPAREN: return 2;
			}
			break;
		case 847:
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
		case 848:
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
		case 849:
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
		case 850:
			switch(symbol) {
				case ASSIGN: return 10;
				case RPAREN: return 10;
			}
			break;
		case 851:
			switch(symbol) {
				case COMMA: return 10;
				case LBRACE: return 10;
			}
			break;
		case 855:
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
		case 857:
			switch(symbol) {
				case ABSTRACT: return 36;
				case BOOLEAN: return 36;
				case BYTE: return 36;
				case CHAR: return 36;
				case FINAL: return 36;
				case ID: return 36;
				case INT: return 36;
				case NATIVE: return 36;
				case PROTECTED: return 36;
				case PUBLIC: return 36;
				case RBRACE: return 36;
				case SEMICOLON: return 36;
				case SHORT: return 36;
				case STATIC: return 36;
				case VOID: return 36;
			}
			break;
		case 858:
			switch(symbol) {
				case COMMA: return 37;
				case RPAREN: return 37;
			}
			break;
		case 859:
			switch(symbol) {
				case COMMA: return 12;
				case RPAREN: return 12;
			}
			break;
		case 860:
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
		case 861:
			switch(symbol) {
				case END_TERMINAL: return 121;
			}
			break;
		case 862:
			switch(symbol) {
				case ARRAY: return 1;
				case ASSIGN: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 863:
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
		case 864:
			switch(symbol) {
				case RBRACE: return 78;
			}
			break;
		case 865:
			switch(symbol) {
				case ARRAY: return 61;
				case ASSIGN: return 61;
				case RPAREN: return 61;
			}
			break;
		case 866:
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
		case 867:
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
		case 868:
			switch(symbol) {
				case ABSTRACT: return 41;
				case AND: return 41;
				case ASSIGN: return 41;
				case BOOLEAN: return 41;
				case BYTE: return 41;
				case CHAR: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case FINAL: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case ID: return 41;
				case INSTANCEOF: return 41;
				case INT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NATIVE: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case PROTECTED: return 41;
				case PUBLIC: return 41;
				case RBRACE: return 41;
				case REMAINDER: return 41;
				case SEMICOLON: return 41;
				case SHORT: return 41;
				case STATIC: return 41;
				case VOID: return 41;
				case XOR: return 41;
			}
			break;
		case 869:
			switch(symbol) {
				case RBRACKET: return 36;
			}
			break;
		case 874:
			switch(symbol) {
				case SEMICOLON: return 11;
			}
			break;
		case 875:
			switch(symbol) {
				case ABSTRACT: return 10;
				case ASSIGN: return 10;
				case BOOLEAN: return 10;
				case BYTE: return 10;
				case CHAR: return 10;
				case FINAL: return 10;
				case ID: return 10;
				case INT: return 10;
				case NATIVE: return 10;
				case PROTECTED: return 10;
				case PUBLIC: return 10;
				case RBRACE: return 10;
				case SEMICOLON: return 10;
				case SHORT: return 10;
				case STATIC: return 10;
				case VOID: return 10;
			}
			break;
		case 876:
			switch(symbol) {
				case ARRAY: return 62;
				case IMPLEMENTS: return 62;
				case LBRACE: return 62;
			}
			break;
		case 877:
			switch(symbol) {
				case COMMA: return 166;
				case RPAREN: return 166;
			}
			break;
		case 878:
			switch(symbol) {
				case ABSTRACT: return 59;
				case AND: return 59;
				case BOOLEAN: return 59;
				case BYTE: return 59;
				case CHAR: return 59;
				case DIV: return 59;
				case DOT: return 59;
				case EAGER_AND: return 59;
				case EAGER_OR: return 59;
				case EQ: return 59;
				case FINAL: return 59;
				case GEQ: return 59;
				case GT: return 59;
				case ID: return 59;
				case INSTANCEOF: return 59;
				case INT: return 59;
				case LBRACKET: return 59;
				case LEQ: return 59;
				case LT: return 59;
				case MINUS: return 59;
				case MULT: return 59;
				case NATIVE: return 59;
				case NEQ: return 59;
				case OR: return 59;
				case PLUS: return 59;
				case PROTECTED: return 59;
				case PUBLIC: return 59;
				case RBRACE: return 59;
				case REMAINDER: return 59;
				case SEMICOLON: return 59;
				case SHORT: return 59;
				case STATIC: return 59;
				case VOID: return 59;
				case XOR: return 59;
			}
			break;
		case 879:
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
		case 880:
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
		case 881:
			switch(symbol) {
				case ABSTRACT: return 67;
				case AND: return 67;
				case BOOLEAN: return 67;
				case BYTE: return 67;
				case CHAR: return 67;
				case DIV: return 67;
				case DOT: return 67;
				case EAGER_AND: return 67;
				case EAGER_OR: return 67;
				case EQ: return 67;
				case FINAL: return 67;
				case GEQ: return 67;
				case GT: return 67;
				case ID: return 67;
				case INSTANCEOF: return 67;
				case INT: return 67;
				case LBRACKET: return 67;
				case LEQ: return 67;
				case LT: return 67;
				case MINUS: return 67;
				case MULT: return 67;
				case NATIVE: return 67;
				case NEQ: return 67;
				case OR: return 67;
				case PLUS: return 67;
				case PROTECTED: return 67;
				case PUBLIC: return 67;
				case RBRACE: return 67;
				case REMAINDER: return 67;
				case SEMICOLON: return 67;
				case SHORT: return 67;
				case STATIC: return 67;
				case VOID: return 67;
				case XOR: return 67;
			}
			break;
		case 882:
			switch(symbol) {
				case ASSIGN: return 36;
				case COMMA: return 36;
				case RPAREN: return 36;
			}
			break;
		case 883:
			switch(symbol) {
				case ABSTRACT: return 42;
				case AND: return 42;
				case ASSIGN: return 42;
				case BOOLEAN: return 42;
				case BYTE: return 42;
				case CHAR: return 42;
				case DIV: return 42;
				case EAGER_AND: return 42;
				case EAGER_OR: return 42;
				case EQ: return 42;
				case FINAL: return 42;
				case GEQ: return 42;
				case GT: return 42;
				case ID: return 42;
				case INSTANCEOF: return 42;
				case INT: return 42;
				case LEQ: return 42;
				case LT: return 42;
				case MINUS: return 42;
				case MULT: return 42;
				case NATIVE: return 42;
				case NEQ: return 42;
				case OR: return 42;
				case PLUS: return 42;
				case PROTECTED: return 42;
				case PUBLIC: return 42;
				case RBRACE: return 42;
				case REMAINDER: return 42;
				case SEMICOLON: return 42;
				case SHORT: return 42;
				case STATIC: return 42;
				case VOID: return 42;
				case XOR: return 42;
			}
			break;
		case 885:
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
		case 886:
			switch(symbol) {
				case ABSTRACT: return 120;
				case CLASS: return 120;
				case END_TERMINAL: return 120;
				case FINAL: return 120;
				case IMPORT: return 120;
				case INTERFACE: return 120;
				case NATIVE: return 120;
				case PROTECTED: return 120;
				case PUBLIC: return 120;
				case SEMICOLON: return 120;
				case STATIC: return 120;
			}
			break;
		case 889:
			switch(symbol) {
				case END_TERMINAL: return 130;
			}
			break;
		case 890:
			switch(symbol) {
				case ARRAY: return 60;
				case SEMICOLON: return 60;
			}
			break;
		case 891:
			switch(symbol) {
				case ABSTRACT: return 77;
				case BOOLEAN: return 77;
				case BYTE: return 77;
				case CHAR: return 77;
				case FINAL: return 77;
				case ID: return 77;
				case INT: return 77;
				case NATIVE: return 77;
				case PROTECTED: return 77;
				case PUBLIC: return 77;
				case RBRACE: return 77;
				case SEMICOLON: return 77;
				case SHORT: return 77;
				case STATIC: return 77;
				case VOID: return 77;
			}
			break;
		case 892:
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
		case 893:
			switch(symbol) {
				case BOOLEAN: return 101;
				case BYTE: return 101;
				case CHAR: return 101;
				case ID: return 101;
				case INT: return 101;
				case SHORT: return 101;
				case VOID: return 101;
			}
			break;
		case 894:
			switch(symbol) {
				case ABSTRACT: return 117;
				case CLASS: return 117;
				case END_TERMINAL: return 117;
				case FINAL: return 117;
				case INTERFACE: return 117;
				case NATIVE: return 117;
				case PROTECTED: return 117;
				case PUBLIC: return 117;
				case SEMICOLON: return 117;
				case STATIC: return 117;
			}
			break;
		case 895:
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
		case 896:
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
		case 897:
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
		case 899:
			switch(symbol) {
				case COMMA: return 40;
				case RPAREN: return 40;
			}
			break;
		case 900:
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
		case 902:
			switch(symbol) {
				case RBRACKET: return 12;
			}
			break;
		case 903:
			switch(symbol) {
				case ASSIGN: return 9;
				case SEMICOLON: return 9;
			}
			break;
		case 905:
			switch(symbol) {
				case ABSTRACT: return 57;
				case AND: return 57;
				case BOOLEAN: return 57;
				case BYTE: return 57;
				case CHAR: return 57;
				case DIV: return 57;
				case DOT: return 57;
				case EAGER_AND: return 57;
				case EAGER_OR: return 57;
				case EQ: return 57;
				case FINAL: return 57;
				case GEQ: return 57;
				case GT: return 57;
				case ID: return 57;
				case INT: return 57;
				case LBRACKET: return 57;
				case LEQ: return 57;
				case LT: return 57;
				case MINUS: return 57;
				case MULT: return 57;
				case NATIVE: return 57;
				case NEQ: return 57;
				case OR: return 57;
				case PLUS: return 57;
				case PROTECTED: return 57;
				case PUBLIC: return 57;
				case RBRACE: return 57;
				case REMAINDER: return 57;
				case SEMICOLON: return 57;
				case SHORT: return 57;
				case STATIC: return 57;
				case VOID: return 57;
				case XOR: return 57;
			}
			break;
		case 906:
			switch(symbol) {
				case RPAREN: return 37;
			}
			break;
		case 907:
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
		case 909:
			switch(symbol) {
				case ABSTRACT: return 58;
				case AND: return 58;
				case BOOLEAN: return 58;
				case BYTE: return 58;
				case CHAR: return 58;
				case DIV: return 58;
				case DOT: return 58;
				case EAGER_AND: return 58;
				case EAGER_OR: return 58;
				case EQ: return 58;
				case FINAL: return 58;
				case GEQ: return 58;
				case GT: return 58;
				case ID: return 58;
				case INSTANCEOF: return 58;
				case INT: return 58;
				case LBRACKET: return 58;
				case LEQ: return 58;
				case LT: return 58;
				case MINUS: return 58;
				case MULT: return 58;
				case NATIVE: return 58;
				case NEQ: return 58;
				case OR: return 58;
				case PLUS: return 58;
				case PROTECTED: return 58;
				case PUBLIC: return 58;
				case RBRACE: return 58;
				case REMAINDER: return 58;
				case SEMICOLON: return 58;
				case SHORT: return 58;
				case STATIC: return 58;
				case VOID: return 58;
				case XOR: return 58;
			}
			break;
		case 910:
			switch(symbol) {
				case ASSIGN: return 10;
				case RBRACKET: return 10;
			}
			break;
		case 913:
			switch(symbol) {
				case SEMICOLON: return 111;
			}
			break;
		case 914:
			switch(symbol) {
				case ARRAY: return 61;
				case RBRACKET: return 61;
			}
			break;
		case 917:
			switch(symbol) {
				case ARRAY: return 63;
				case SEMICOLON: return 63;
			}
			break;
		case 920:
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
		case 921:
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
		case 922:
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
		case 923:
			switch(symbol) {
				case ABSTRACT: return 43;
				case AND: return 43;
				case BOOLEAN: return 43;
				case BYTE: return 43;
				case CHAR: return 43;
				case DIV: return 43;
				case EAGER_AND: return 43;
				case EAGER_OR: return 43;
				case EQ: return 43;
				case FINAL: return 43;
				case GEQ: return 43;
				case GT: return 43;
				case ID: return 43;
				case INSTANCEOF: return 43;
				case INT: return 43;
				case LEQ: return 43;
				case LT: return 43;
				case MINUS: return 43;
				case MULT: return 43;
				case NATIVE: return 43;
				case NEQ: return 43;
				case OR: return 43;
				case PLUS: return 43;
				case PROTECTED: return 43;
				case PUBLIC: return 43;
				case RBRACE: return 43;
				case REMAINDER: return 43;
				case SEMICOLON: return 43;
				case SHORT: return 43;
				case STATIC: return 43;
				case VOID: return 43;
				case XOR: return 43;
			}
			break;
		case 925:
			switch(symbol) {
				case ARRAY: return 1;
				case COMMA: return 1;
				case DOT: return 1;
				case RPAREN: return 1;
			}
			break;
		case 926:
			switch(symbol) {
				case ABSTRACT: return 68;
				case AND: return 68;
				case BOOLEAN: return 68;
				case BYTE: return 68;
				case CHAR: return 68;
				case DIV: return 68;
				case DOT: return 68;
				case EAGER_AND: return 68;
				case EAGER_OR: return 68;
				case EQ: return 68;
				case FINAL: return 68;
				case GEQ: return 68;
				case GT: return 68;
				case ID: return 68;
				case INSTANCEOF: return 68;
				case INT: return 68;
				case LBRACKET: return 68;
				case LEQ: return 68;
				case LT: return 68;
				case MINUS: return 68;
				case MULT: return 68;
				case NATIVE: return 68;
				case NEQ: return 68;
				case OR: return 68;
				case PLUS: return 68;
				case PROTECTED: return 68;
				case PUBLIC: return 68;
				case RBRACE: return 68;
				case REMAINDER: return 68;
				case SEMICOLON: return 68;
				case SHORT: return 68;
				case STATIC: return 68;
				case VOID: return 68;
				case XOR: return 68;
			}
			break;
		case 927:
			switch(symbol) {
				case ABSTRACT: return 41;
				case AND: return 41;
				case BOOLEAN: return 41;
				case BYTE: return 41;
				case CHAR: return 41;
				case DIV: return 41;
				case EAGER_AND: return 41;
				case EAGER_OR: return 41;
				case EQ: return 41;
				case FINAL: return 41;
				case GEQ: return 41;
				case GT: return 41;
				case ID: return 41;
				case INSTANCEOF: return 41;
				case INT: return 41;
				case LEQ: return 41;
				case LT: return 41;
				case MINUS: return 41;
				case MULT: return 41;
				case NATIVE: return 41;
				case NEQ: return 41;
				case OR: return 41;
				case PLUS: return 41;
				case PROTECTED: return 41;
				case PUBLIC: return 41;
				case RBRACE: return 41;
				case REMAINDER: return 41;
				case SEMICOLON: return 41;
				case SHORT: return 41;
				case STATIC: return 41;
				case VOID: return 41;
				case XOR: return 41;
			}
			break;
		case 929:
			switch(symbol) {
				case ARRAY: return 1;
				case DOT: return 1;
				case IMPLEMENTS: return 1;
				case LBRACE: return 1;
			}
			break;
	}
	return -1;
}
