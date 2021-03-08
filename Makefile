CXX = $(shell if [ -x "$$(command -v g++-9)" ]; then echo "g++-9"; else echo "g++"; fi)
CXXFLAGS = -std=c++17 -Wall -MMD -g -Wno-unused-label

BUILDDIR = build
SRCDIR = src

OBJECTS = ${addprefix ${BUILDDIR}/, DFA.o ParseTable.o Tokenize.o Token.o Parser.o Weeder.o ASTBuilder.o ast/ASTNode.o NameResolution.o HierarchyCheck.o}
DEPENDS = ${OBJECTS:.o=.d}

LEX_OBJECTS = ${addprefix ${BUILDDIR}/, lex/RegexProcessor.o lex/FA.o}
LEX_DEPENDS = ${OBJECTS:.o=.d}

TEST_OBJECTS = ${addprefix ${BUILDDIR}/, test/Test.o test/LexTest.o test/TestDFA.o}
TEST_DEPENDS = ${TEST_OBJECTS:.o=.d}

PARSE_TABLE_OBJECTS = ${addprefix ${BUILDDIR}/, parseTable/LR1ParseTableGenerator.o}
PARSE_TABLE_DEPENDS = ${PARSE_TABLE_OBJECTS:.o=.d}

joosc: ${BUILDDIR}/Main.o ${OBJECTS}
	${CXX} ${CXXFLAGS} ${BUILDDIR}/Main.o ${OBJECTS} -o joosc

lex: ${BUILDDIR}/lex/Main.o ${LEX_OBJECTS}
	${CXX} ${CXXFLAGS}  ${BUILDDIR}/lex/Main.o ${LEX_OBJECTS} -o lex

parseTable: ${BUILDDIR}/parseTable/main.o ${PARSE_TABLE_OBJECTS}
	${CXX} ${CXXFLAGS}  ${BUILDDIR}/parseTable/main.o ${PARSE_TABLE_OBJECTS} -o parseTable

${BUILDDIR}/DFA.cc: scanner.lex lex
	./lex scanner.lex ${BUILDDIR}/DFA.cc

${BUILDDIR}/ParseTable.cc: ${BUILDDIR}/grammar.lr1 parseTable
	./parseTable ${BUILDDIR}/grammar.lr1  ${BUILDDIR}/ParseTable.cc

${BUILDDIR}/test/TestDFA.cc: ${SRCDIR}/test/test.lex lex
	./lex src/test/test.lex ${BUILDDIR}/test/TestDFA.cc

${BUILDDIR}/%.o: ${SRCDIR}/%.cc
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} -c -o $@ $<

${BUILDDIR}/%.o: ${BUILDDIR}/%.cc
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} -c -o $@ $<

${BUILDDIR}/grammar.lr1: grammar.cfg ${SRCDIR}/jlalr/Jlalr1.java
	java ${SRCDIR}/jlalr/Jlalr1.java < grammar.cfg > ${BUILDDIR}/grammar.lr1

test: lex joosc parseTable ${BUILDDIR}/test/Main.o ${TEST_OBJECTS}
	${CXX} ${CXXFLAGS} ${BUILDDIR}/test/Main.o ${TEST_OBJECTS} -o test

-include ${DEPENDS}

.PHONY: clean zip

clean:
	rm -r ${BUILDDIR} joosc lex test parseTable submit.zip

zip:
	rm -f submit.zip
	zip -r submit.zip src Makefile scanner.lex grammar.cfg

