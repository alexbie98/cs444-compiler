CXX = $(shell if [ -x "$$(command -v g++-9)" ]; then echo "g++-9"; else echo "g++"; fi)
CXXFLAGS = -std=c++17 -Wall -MMD -g

BUILDDIR = build
SRCDIR = src

OBJECTS = ${addprefix ${BUILDDIR}/,  module/Module.o DFA.o Tokenize.o}
DEPENDS = ${OBJECTS:.o=.d}

LEX_OBJECTS = ${addprefix ${BUILDDIR}/, lex/Module.o lex/RegexProcessor.o}
LEX_DEPENDS = ${OBJECTS:.o=.d}

TEST_OBJECTS = ${addprefix ${BUILDDIR}/, test/Test.o test/MunchTest.o}
TEST_DEPENDS = ${TEST_OBJECTS:.o=.d}

all: lex joosc

lex: ${BUILDDIR}/lex/Main.o ${LEX_OBJECTS}
	${CXX} ${CXXFLAGS}  ${BUILDDIR}/lex/Main.o ${LEX_OBJECTS} -o lex

joosc: ${BUILDDIR}/Main.o ${OBJECTS}
	${CXX} ${CXXFLAGS} ${BUILDDIR}/Main.o ${OBJECTS} -o joosc

${BUILDDIR}/%.o: ${SRCDIR}/%.cc
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} -c -o $@ $<

${SRCDIR}/DFA.cc: scanner.lex
	./lex scanner.lex ${SRCDIR}/DFA.cc

test: all ${BUILDDIR}/test/Main.o ${TEST_OBJECTS}
	${CXX} ${CXXFLAGS} ${BUILDDIR}/test/Main.o ${TEST_OBJECTS} -o test

-include ${DEPENDS}

.PHONY: clean 

clean:
	rm -r ${BUILDDIR} joosc lex test



