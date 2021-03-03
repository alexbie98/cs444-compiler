CXX = $(shell if [ -x "$$(command -v g++-9)" ]; then echo "g++-9"; else echo "g++"; fi)
CXXFLAGS = -std=c++17 -Wall -MMD -g

BUILDDIR = build
SRCDIR = src

OBJECTS = ${addprefix ${BUILDDIR}/,  module/Module.o Tokenize.o Token.o Parser.o Weeder.o ASTBuilder.o ast/ASTNode.o}
DEPENDS = ${OBJECTS:.o=.d}

LEX_OBJECTS = ${addprefix ${BUILDDIR}/, lex/Module.o lex/RegexProcessor.o lex/FA.o}
LEX_DEPENDS = ${OBJECTS:.o=.d}

LEX_TEST_OBJECTS = ${addprefix ${BUILDDIR}/, lex/test/Test.o TestDFA.o}
LEX_DEPENDS = ${OBJECTS:.o=.d}

TEST_OBJECTS = ${addprefix ${BUILDDIR}/, test/Test.o test/MunchTest.o}
TEST_DEPENDS = ${TEST_OBJECTS:.o=.d}

PARSE_TABLE_OBJECTS = ${addprefix ${BUILDDIR}/, parseTable/LR1ParseTableGenerator.o}
PARSE_TABLE_DEPENDS = ${PARSE_TABLE_OBJECTS:.o=.d}

all: lex joosc parseTable

lex: ${BUILDDIR}/lex/Main.o ${LEX_OBJECTS}
	${CXX} ${CXXFLAGS}  ${BUILDDIR}/lex/Main.o ${LEX_OBJECTS} -o lex

joosc: ${BUILDDIR}/Main.o ${OBJECTS} ${BUILDDIR}/DFA.o ${BUILDDIR}/ParseTable.o
	${CXX} ${CXXFLAGS} ${BUILDDIR}/Main.o ${OBJECTS} ${BUILDDIR}/DFA.o ${BUILDDIR}/ParseTable.o -o joosc

parseTable: ${BUILDDIR}/parseTable/main.o ${PARSE_TABLE_OBJECTS}
	${CXX} ${CXXFLAGS}  ${BUILDDIR}/parseTable/main.o ${PARSE_TABLE_OBJECTS} -o parseTable

${BUILDDIR}/DFA.o: ${BUILDDIR}/DFA.cc
	${CXX} ${CXXFLAGS} -c -o $@ $<

${BUILDDIR}/ParseTable.o: ${BUILDDIR}/ParseTable.cc
	${CXX} ${CXXFLAGS} -c -o $@ $<

${BUILDDIR}/%.o: ${SRCDIR}/%.cc
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} -c -o $@ $<

${BUILDDIR}/DFA.cc: scanner.lex lex
	./lex scanner.lex ${BUILDDIR}/DFA.cc

${BUILDDIR}/ParseTable.cc: src/parseTable/grammar.lr1 parseTable
	./parseTable src/parseTable/grammar.lr1  ${BUILDDIR}/ParseTable.cc

${BUILDDIR}/TestDFA.cc: src/lex/test/test.lex lex
	./lex src/lex/test/test.lex ${BUILDDIR}/TestDFA.cc

test: all ${BUILDDIR}/test/Main.o ${TEST_OBJECTS}
	${CXX} ${CXXFLAGS} ${BUILDDIR}/test/Main.o ${TEST_OBJECTS} -o test

lex_test: lex ${LEX_TEST_OBJECTS}
	${CXX} ${CXXFLAGS} ${LEX_TEST_OBJECTS} -o lex_test

-include ${DEPENDS}

.PHONY: clean zip

clean:
	rm -r ${BUILDDIR} joosc lex test parseTable

zip:
	zip -r ../submit.zip src Makefile scanner.lex

