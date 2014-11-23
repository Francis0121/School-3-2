%{
/*
	mini-c lex
*/

#include "y.tab.h"
%}

letter	[a-zA-Z_]
digit	[0-9]

%%
"="	return(TASSIGN);
"+"	return(TPLUS);
"-" return(TMINUS);
"*" return(TMUL);
"/" return(TDIV);
";"	return(TSEMI);
":" return(TCOLON);
"," return(TCOMA);

\(	return(TLPAREN);
\)	return(TRPAREN);

"{"	return(T_BRACKET_BEGIN);
"}"	return(T_BRACKET_END);

if	return(TIF);
else	return(TELSE);
case		return(TCASE);
default		return(TDEFAULT);
while       return(TWHILE);
do          return(TDO);
for         return(TFOR);

return      return(TRETURN);
continue    return(TCONTINUE);
break       return(TBREAK);

void        return(TVOID);
int         return(TINT);
char        return(TCHAR);
float       return(TFLOAT);
double      return(TDOUBLE);

{digit}+	return(TNUMBER);
{letter}({letter}|{digit})*	return(TIDENT);

[ \t\n\r]	;
.	return(TERROR);
%%
int yywrap() { return 1; }

/* empty */
