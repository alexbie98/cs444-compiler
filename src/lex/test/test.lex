#include "../src/lex/test/TestDFA.h"

%%
g	A

	This is a comment
(ab[cde])	B
x(yz)+	C
[^hi]j	D

	This is another comment
.l.	E
m(no)*[^q]*	F
/\*([^*]*(\*)+[^*/])*[^*]*(\*)*\*/	ML_COMMENT
tab\ttab	G
\n\r\t\v\f\0	ESCAPES
