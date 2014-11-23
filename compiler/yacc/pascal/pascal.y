%{
/*
	mini-c yacc
*/
#include <stdio.h>
%}

%token  T_BRACKET_BEGIN, T_BRACKET_END
%token  TCASE, TDEFAULT
%token  TWHILE, TDO, TFOR
%token	TIDENT, TNUMBER, TASSIGN, TSEMI, TCOLON, TCOMA, TERROR
%token	TPLUS, TMINUS, TMUL, TDIV, TMOD, TLPAREN, TRPAREN, TLBRACKET, TRBRACKET
%token 	TIF, TELSE
%token  TBREAK, TRETURN, TCONTINUE
%token  TVOID, TINT, TCHAR, TFLOAT, TDOUBLE

%left TPLUS, TMINUS
%left TMUL, TDIV
%right TASSIGN

%%
start_symbol:
        type TIDENT argument bracket_stmt { puts("-1.1 bracket"); }
        ;

argument:
        TLPAREN params TRPAREN { puts("-1.2 argument"); }
        ;

params:
        param { puts("-1.3 parameter"); } |
        params TCOMA param { puts("-1.4 parameters"); }
        ;

param:
        type TIDENT { puts("-1.5 parameter"); }
        ;

bracket_stmt:
        T_BRACKET_BEGIN statements T_BRACKET_END	{ puts("--2.4 bracket"); }
		;

statements:
        statement { puts("---3.1. statement"); } |
        statements TSEMI statement { puts("---3.2. statements"); } |
        label_stmt { puts("---3.3. label statement"); } |
        iter_stmt { puts("---3.4. iter statement"); } |
        jump_stmt { puts("---3.5. jump statement"); }
		;

statement:
        /* empty statement */	{ puts("----4.1. empty statement"); } |
        assign_stmt	{ puts("----4.2. assign statement"); }
        ;

label_stmt:
        TDEFAULT TCOLON statement { puts("----4.3. default"); } | // 추가 default
        TCASE constant TCOLON statement { puts("----4.4. case"); } // 추가 case
        ;

iter_stmt:
        TWHILE TLPAREN expression TRPAREN statement { puts("----4.5. while"); } |
        TDO statement TWHILE TLPAREN expression TRPAREN TSEMI { puts("----4.6. do while"); } | // TSEMI 가 들어가면 문제 발생
        TFOR TLPAREN expression TSEMI expression TSEMI expression TRPAREN statement { puts("----4.7. for");} // TSEMI 가 들어가면 문제 발생
        ;

jump_stmt: // 이 부분도 제대로 안되네
        TCONTINUE { puts("----4.8. continue"); } |
        TBREAK { puts("----4.9. break"); } |
        TRETURN expression { puts("----4.10. return"); }
        ;

assign_stmt:
        left_hand_side TASSIGN expression	{ puts("-----5.1 exprssion"); } |
        left_hand_side { puts("-----5.2. a;"); } // 추가 'a;'
		;


left_hand_side:
        variable	{ puts("------6. variable"); }
		;

expression:
        expression TPLUS term { puts("-------7.1. plus"); } |
        expression TMINUS term { puts("-------7.2. minus"); } |
        term { puts("-------7.3. term"); }
		;

term:
        term TMUL factor	{ puts("--------8.1. mul"); } |
        term TDIV factor	{ puts("--------8.2. div"); } |
        term TMOD factor	{ puts("--------8.3. mod"); } |
        factor	{ puts("--------8.4. factor"); }
		;

factor:
        TMINUS factor	{ puts("---------9.1. minus factor"); } |
        variable	{ puts("---------9.2. variable"); } |
        TNUMBER	{ puts("---------9.3. number"); } |
        TLPAREN expression TRPAREN	{ puts("---------9.4. ( )"); }
		;

variable:
        TIDENT	{ puts("----------10.1. identifier"); }
		;

constant:
        TNUMBER { puts("----------10.2. constant"); }
        ;

type:
        TVOID { puts("-----------11.1. void"); } |
        TINT { puts("-----------11.2. int"); } |
        TCHAR { puts("-----------11.3. char"); } |
        TFLOAT { puts("-----------11.4. float"); } |
        TDOUBLE { puts("-----------11.5. double"); }
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
