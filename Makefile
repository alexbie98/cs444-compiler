CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
BUILDDIR = build
SRCDIR = src
EXEC = joosc lex
OBJECTS = ${addprefix ${BUILDDIR}/, Module.o module/Module.o lex/Module.o}
DEPENDS = ${OBJECTS:.o=.d}

all: lex joosc

lex: ${BUILDDIR}/lex/Main.o ${OBJECTS}
	${CXX} ${BUILDDIR}/lex/Main.o ${OBJECTS} -o lex

joosc: ${BUILDDIR}/Main.o ${OBJECTS}
	${CXX} ${BUILDDIR}/Main.o ${OBJECTS} -o joosc

${BUILDDIR}/%.o: ${SRCDIR}/%.cc
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} -c -o $@ $<

-include ${DEPENDS}

.PHONY: clean

clean:
	rm -r ${BUILDDIR} joosc lex
