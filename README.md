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
- `./test` to test the latest assignment
- `./test a2` to test a2
- `./test constexpr` to test all the cases in `custom_testcases/constexpr`
- `./test a4 r` to test a4, running regression on a1...a3, plus all custom test cases and unit tests
- `./test constexpr r` to test all custom test cases and unit tests

### Notes
- If you add a new `.cc` file, add it to line 7 `OBJECTS = ...` of the `Makefile` (line 10 `TEST_OBJECTS = ...` for test files)
