/*******************************
*	20093267 김성근
*	myc.l Lex input file
********************************/
%{
#include "y.tab.h"

#undef yywrap
%}
letter	[a-zA-Z_]
digit	[0-9]
%%

"+"		return(OP_PLUS);
"-"		return(OP_MINUS);
"*"		return(OP_MUL);
"/"		return(OP_DIV);
"%"		return(OP_REMAIN);
"=="		return(OP_EQUAL);
"!="		return(OP_NEQUAL);
"<"		return(OP_LESS);
"<="		return(OP_LESSE);
">"		return(OP_GREAT);
">="		return(OP_GREATE);
"++"		return(OP_PLUSS);
"--"		return(OP_MINUSS);

"="		return(AS_DEFAULT);
"+="		return(AS_PLUS);
"-="		return(AS_MINUS);
"*="		return(AS_MUL);
"/="		return(AS_DIV);
"%="		return(AS_REMAIN);

"["		return(ARRAY_BEGIN);
"]"		return(ARRAY_END);
"("		return(ARGU_BEGIN);
")"		return(ARGU_END);

","		return(ST_COMA);
":"		return(ST_COLON);
";"		return(ST_SEMICOLON);
\.		return(ST_DOT);

"{"		return(ST_BEGIN);
"}"		return(ST_END);
do		return(ST_DO);
while		return(ST_WHILE);
if		return(ST_IF);
else		return(ST_ELSE);
switch		return(ST_SWITCH);
case		return(ST_CASE);
for		return(ST_FOR);
default		return(ST_DEFAULT);

break		return(JP_BREAK);
continue	return(JP_CONTINUE);
return		return(JP_RETURN);

void 		return(TYPE_VOID);
int		return(TYPE_INT);
float		return(TYPE_FLOAT);
double		return(TYPE_DOUBLE);
char		return(TYPE_CHAR);

{letter}({letter}|{digit})*	return(MY_IDENTIFIER);
{digit}+	return(MY_NUMBER);

[ \t\r]		;
.		return(MY_ERROR);
%%

yywrap(){
	printf("Lex 끝\n");
	return 1;
}
