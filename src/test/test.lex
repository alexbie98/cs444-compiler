#include "../../src/test/TestDFA.h"

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
"([^\n']|(\\b|(t|(n|(f|(r|("|('|(\\|([0-7]|(([0-7][0-7])|([0-3][0-7][0-7]))))))))))))*"	STRING_LIT
[A-Z][^B-Y][0-9][^1-8]	H
