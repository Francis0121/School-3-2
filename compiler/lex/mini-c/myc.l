/*******************************
*	20093267 김성근
*	myc.l Lex input file
********************************/
%{
#include <stdio.h>
#include <stdlib.h>

enum my_number {
	MY_EOF, MY_IDENTIFIER, MY_NUMBER, MY_ERROR,
	TYPE_VOID, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_CHAR, 
	ST_BEGIN, ST_END, ST_DO, ST_WHILE, ST_IF, ST_ELSE, ST_SWITCH, ST_CASE, ST_FOR,
	ST_COMA, ST_COLON, ST_SEMICOLON, ST_DOT, ST_DEFAULT,
	JP_BREAK, JP_CONTINUE, JP_RETURN,
	OP_PLUS, OP_MINUS, OP_MUL, OP_DIV, OP_REMAIN, OP_PLUSS, OP_MINUSS,
	OP_EQUAL, OP_NEQUAL, OP_LESS, OP_LESSE, OP_GREAT, OP_GREATE,
	AS_DEFAULT, AS_PLUS, AS_MINUS, AS_MUL, AS_DIV, AS_REMAIN,
	ARRAY_BEGIN, ARRAY_END,
	ARGU_BEGIN, ARGU_END, 
};

int LineNumber = 0;

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
";"		return(ST_COLON);
":"		return(ST_SEMICOLON);
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
\n 		LineNumber++;
.		return(MY_ERROR);
%%

main()
{
	enum my_number my;
	
	printf("Lex 시작\n");
	while ((my = yylex()) != MY_EOF){
		switch(my){
		case MY_IDENTIFIER:
		case MY_NUMBER:
			printf("\t(%2i, %s)\n", my, yytext);
			break;
		case MY_ERROR:
			printf("에러 --line %d : [%c]\n", LineNumber, yytext[0]);
			break;
		default:
			printf("\t(%2i, %s)\n", my, yytext);
		}	
	}
}

yywrap(){
	printf("Lex 끝\n");
	return 1;
}
