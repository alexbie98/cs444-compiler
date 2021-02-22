#include "../src/DFA.h"

%%

	whitespace -----------------------------
\f| |\t|\n	WS

	comment -------------------------------
(//[^\n]*\n)|(/\*([^*]*(\*)+[^*/])*[^*]*(\*)*\*/)	COMMENT

	separator ---------------------
\(	LPAREN
\)	RPAREN
{	LBRACE
}	RBRACE
\[	LBRACKET
\]	RBRACKET
;	SEMICOLON
,	COMMA
\.	DOT

	keyword -------------------------------
if	IF
else	ELSE
while	WHILE
for	FOR

class	CLASS
extends	EXTENDS
implements	IMPLEMENTS
interface	INTERFACE
this	THIS
instanceof	INSTANCEOF

static	STATIC
public	PUBLIC
private	PRIVATE
protected	PROTECTED
abstract	ABSTRACT
final	FINAL
native	NATIVE

package	PACKAGE
import	IMPORT

return	RETURN
void	VOID

int	INT
boolean	BOOLEAN
char	CHAR
byte	BYTE
short	SHORT
\[\]	ARRAY

	unsupported keyword ---------------------
const	CONST
strictfp	STRICTFP
synchronized	SYNCHRONIZED
transient	TRANSIENT
volatile	VOLATILE
	
double	DOUBLE
float	FLOAT
long	LONG
catch	CATCH
finally	FINALLY
throw	THROW
throws	THROWS
try	TRY
	
new	NEW
super	SUPER
	
break	BREAK
case	CASE
continue	CONTINUE
default	DEFAULT
do	DO
goto	GOTO
switch	SWITCH

	literal ----------------------------
(true)|(false)	BOOLEAN_LIT
null	NULL_LIT

'[^\n']|(\\b|(t|(n|(f|(r|("|('|(\\|([0-7]|(([0-7][0-7])|([0-3][0-7][0-7])))))))))))'	CHAR_LIT

	string lit regex ERROR constructing DFA ---------------
"([^\n"]|(\\b|(t|(n|(f|(r|("|('|(\\|([0-7]|(([0-7][0-7])|([0-3][0-7][0-7]))))))))))))*"	STRING_LIT



((0[0-7]+)|(0|([1-9][0-9]*)))|(0(X|x)(([0-9]|[a-f])|[A-F])+)	INT_LIT

	identifier ------------------
([a-z]|([A-Z]|($|_)))([a-z]|([A-Z]|($|(_|[0-9]))))*	ID

		operator ----------
=	ASSIGN
>	GT
<	LT
!	NOT
~	BITWISE_NOT
\?	TERNARY_IF
:	TERNARY_ELSE
==	EQ
<=	LEQ
>=	GEQ
!=	NEQ
&&	AND
\|\|	OR
\+\+	INCR
\-\-	DECR
\+	PLUS
\-	MINUS
\*	MULT
/	DIV
&	EAGER_AND
\|	EAGER_OR
\^	XOR
%	REMAINDER
<<	LSHIFT
>>	RSHIFT
>>>	UNSIGNED_RSHIFT
\+=	PLUS_ASSIGN
\-=	MINUS_ASSIGN
\*=	MULT_ASSIGN
/=	DIV_ASSIGN
&=	BITWISE_AND_ASSIGN
\|=	BITWISE_OR_ASSIGN
\^=	BITWISE_XOR_ASSIGN
%=	REMAINDER_ASSIGN
<<=	LSHIFT_ASSIGN
>>=	RSHIFT_ASSIGN
>>>=	UNSIGNED_RSHIFT_ASSIGN

