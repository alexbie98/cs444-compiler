## CS 444 - Compilers Project
- Compiler for Joos 1W
- Victor Scurtu, Edwin Lin, and Alex Bie (Group 28)

### Setup
(Tested with gcc 9.3.0 and Apple clang 12.0.0)
- `git clone https://github.com/waterloo-cs444/cs444-w21-group28.git cs444`
- `cd cs444`
- `make`
- `./joosc ...` OR `./lex ...`

### Tests
- `scp -r user@linux.student.cs.uwaterloo.ca:/u/cs444/pub/* ./` to download testcases
- `make test`
- `./test`

### Notes
- If you add a new `.cc` file, add it to line 7 `OBJECTS = ...` of the `Makefile` (line 10 `TEST_OBJECTS = ...` for test files)
