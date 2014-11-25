%{
/*
	Mini C LEX input file
*/

#include "y.tab.h"
%}

letter	[a-zA-Z_]
digit	[0-9]

%%
\=	return(TASSIGN);
"+"	return(TPLUS);
"-"	return(TMINUS);
"*"	return(TMUL);
"/"	return(TDIV);
";"	return(TSEMI);
\(	return(TLPAREN);
\)	return(TRPAREN);
\.	return(TDOT);

"{"	return(TBEGIN);
"}"	return(TEND);
for	return(TFOR);
if	return(TIF);
else	return(TELSE);

{digit}+	return(TNUMBER);
{letter}({letter}|{digit})*	return(TIDENT);

[ \t\n\r]	;
.	return(TERROR);
%%
int yywrap() { return 1; }

/* empty */
