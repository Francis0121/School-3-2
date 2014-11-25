%{
/*
	Ultra-mini PASCAL parser
*/
#include <stdio.h>
%}

%token	TIDENT TNUMBER TASSIGN TSEMI TDOT TBEGIN TEND TIF TELSE TFOR TERROR
%token	TLPAREN TRPAREN TLBRACKET TRBRACKET

%left	TPLUS TMINUS
%left	TMUL TDIV TMOD

%%
func_stmt:	TIDENT TLPAREN TRPAREN compound_stmt	{ puts("1"); }
		;
compound_stmt:	TBEGIN statement2 TEND	{ puts("2"); }
		;
statement2: statement	{ puts("3-1"); }
		| statement2 TSEMI statement	{ puts("3-2"); }
		;
statement:	/* empty statement */	{ puts("4-1"); }
		| assign_stmt	{ puts("4-2"); }
		| if_stmt	{ puts("4-3"); }
		| for_stmt	{ puts("4-4"); }
		;
if_stmt: TIF TLPAREN exp TRPAREN statement2	{ puts("11-1"); }
	| TIF TLPAREN exp TRPAREN statement2 TELSE statement	{ puts("11-2"); }
	;
for_stmt:	TFOR TLPAREN exp TSEMI exp TSEMI exp TRPAREN statement2
	;
assign_stmt: lhs TASSIGN exp	{ puts("5"); }
		;
lhs:	variable	{ puts("6"); }
		;
exp:	exp TPLUS term	{ puts("7-1"); }
		| exp TMINUS term	{ puts("7-2"); }
		| term	{ puts("7-3"); }
		;
term:	term TMUL factor	{ puts("8-1"); }
		| term TDIV factor	{ puts("8-2"); }
		| term TMOD factor	{ puts("8-3"); }
		| factor	{ puts("8-4"); }
		;
factor:	TMINUS factor	{ puts("9-1"); }
		| variable	{ puts("9-2"); }
		| TNUMBER	{ puts("9-3"); }
		| TLPAREN exp TRPAREN	{ puts("9-4"); }
		;
variable:	TIDENT	{ puts("10-1"); }
		| TIDENT TLBRACKET exp TRBRACKET	{ puts("10-2"); }
		;
%%

main()
{
	yyparse();
}

yyerror(s)
char *s;
{
	fprintf(stderr, "%s\n", s);
}
