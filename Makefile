CXX = g++
CXXFLAGS = -std=c++17 -Wall -MMD -g
BUILDDIR = build
SRCDIR = src
EXEC = joosc lex
OBJECTS = ${addprefix ${BUILDDIR}/, lex/Module.o module/Module.o DFA.o Tokenize.o}
DEPENDS = ${OBJECTS:.o=.d}

all: lex joosc

lex: ${BUILDDIR}/lex/Main.o ${OBJECTS}
	${CXX}  ${BUILDDIR}/lex/Main.o ${OBJECTS} -o lex

joosc: ${BUILDDIR}/Main.o ${OBJECTS}
	${CXX} ${BUILDDIR}/Main.o ${OBJECTS} -o joosc

${BUILDDIR}/%.o: ${SRCDIR}/%.cc
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} -c -o $@ $<

-include ${DEPENDS}

.PHONY: clean

clean:
	rm -r ${BUILDDIR} joosc lex
