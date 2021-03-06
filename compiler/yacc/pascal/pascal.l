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
"+=" return(TASPLUS);
"-=" return(TASMINUS);
"*=" return(TASMUL);
"/=" return(TASDIV);
"%=" return(TASREMAIN);

"+"	return(TPLUS);
"-" return(TMINUS);
"*" return(TMUL);
"/" return(TDIV);
";"	return(TSEMI);
":" return(TCOLON);
"," return(TCOMA);

"==" return(TEQUAL);
"!=" return(TNEQUAL);
"<"	 return(TLESS);
"<=" return(TLESSE);
">"	 return(TGREAT);
">=" return(TGREATE);

\(	return(TLPAREN);
\)	return(TRPAREN);

"{"	return(T_BRACKET_BEGIN);
"}"	return(T_BRACKET_END);

if	        return(TIF);
else	    return(TELSE);
switch      return(TSWITCH);
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

struct		return(TSTRUCT);

{digit}+	return(NUMBER);
0[xX][0-9a-fA-F]+ return(HEXA);
{digit}+\.{digit}+[f] return(FLOAT);
{digit}+\.{digit}+ return(DOUBLE);
{letter}({letter}|{digit})*	return(TIDENT);

[ \t\n\r]	;
.	return(TERROR);
%%
int yywrap() { return 1; }

/* empty */
