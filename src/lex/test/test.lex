#include "../src/lex/test/TestDFA.h"

%%
g	A
(ab[cde])	B
x(yz)+	C
[^hi]j	D
.l.	E
m(no)*[^q]*	F
/\*([^*]*(\*)+[^*/])*[^*]*(\*)*\*/	ML_COMMENT
