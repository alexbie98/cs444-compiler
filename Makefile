CXX = $(shell if [ -x "$$(command -v g++-9)" ]; then echo "g++-9"; else echo "g++"; fi)
CXXFLAGS = -std=c++17 -Wall -MMD -g

BUILDDIR = build
SRCDIR = src

OBJECTS = ${addprefix ${BUILDDIR}/,  module/Module.o DFA.o Tokenize.o}
DEPENDS = ${OBJECTS:.o=.d}

LEX_OBJECTS = ${addprefix ${BUILDDIR}/, lex/Module.o lex/RegexProcessor.o lex/FA.o}
LEX_DEPENDS = ${OBJECTS:.o=.d}

LEX_TEST_OBJECTS = ${addprefix ${BUILDDIR}/, lex/test/Test.o TestDFA.o}
LEX_DEPENDS = ${OBJECTS:.o=.d}

TEST_OBJECTS = ${addprefix ${BUILDDIR}/, test/Test.o test/MunchTest.o}
TEST_DEPENDS = ${TEST_OBJECTS:.o=.d}

all: lex joosc

lex: ${BUILDDIR}/lex/Main.o ${LEX_OBJECTS}
	${CXX} ${CXXFLAGS}  ${BUILDDIR}/lex/Main.o ${LEX_OBJECTS} -o lex

joosc: ${BUILDDIR}/Main.o ${OBJECTS}
	${CXX} ${CXXFLAGS} ${BUILDDIR}/Main.o ${OBJECTS} -o joosc

${BUILDDIR}/DFA.o: ${BUILDDIR}/DFA.cc
	${CXX} ${CXXFLAGS} -c -o $@ $<

${BUILDDIR}/%.o: ${SRCDIR}/%.cc
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} -c -o $@ $<

${BUILDDIR}/DFA.cc: scanner.lex lex
	./lex scanner.lex ${BUILDDIR}/DFA.cc

${BUILDDIR}/TestDFA.cc: src/lex/test/test.lex lex
	./lex src/lex/test/test.lex ${BUILDDIR}/TestDFA.cc

test: all ${BUILDDIR}/test/Main.o ${TEST_OBJECTS}
	${CXX} ${CXXFLAGS} ${BUILDDIR}/test/Main.o ${TEST_OBJECTS} -o test

lex_test: lex ${LEX_TEST_OBJECTS}
	${CXX} ${CXXFLAGS} ${LEX_TEST_OBJECTS} -o lex_test

-include ${DEPENDS}

.PHONY: clean 

clean:
	rm -r ${BUILDDIR} joosc lex test



