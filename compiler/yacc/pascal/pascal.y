%{
/*
	mini-c yacc
*/
#include <stdio.h>
%}

%token  T_BRACKET_BEGIN, T_BRACKET_END
%token  TSTRUCT
%token  TCASE, TDEFAULT
%token  TWHILE, TDO, TFOR
%token	TIDENT, TNUMBER, TSEMI, TCOLON, TCOMA, TERROR
%token	TLPAREN, TRPAREN, TLBRACKET, TRBRACKET
%token 	TIF, TELSE, TSWITCH
%token  TBREAK, TRETURN, TCONTINUE
%token  TVOID, TINT, TCHAR, TFLOAT, TDOUBLE, TEQUAL

%left TPLUS, TMINUS
%left TMUL, TDIV, TMOD
%left TEQAUL, TNEQUAL, TLESS, TLESSE, TGREAT, TGREATE
%right TASSIGN, TASPLUS, TASMINUS, TASMUL, TASDIV, TASREMAIN


%%
start_symbol:
        func { puts("0.1 function"); } |
        struct start_symbol { puts("0.2 struct"); } |
        func start_symbol { puts("0.3 functions"); }
        ;

func:
        type TIDENT argument external_stmt { puts("-1.1 bracket"); }
        ;

argument:
        TLPAREN TRPAREN { puts("-1.2 no argument"); } |
        TLPAREN params TRPAREN { puts("-1.3 argument"); }
        ;

params:
        param { puts("-1.4 one parameter"); } |
        params TCOMA param { puts("-1.5 parameters"); }
        ;

param:
        TVOID { puts("-1.6 parameter void "); }  |
        type TIDENT { puts("-1.7 parameter detail"); }
        ;

external_stmt:
        T_BRACKET_BEGIN statements T_BRACKET_END	{ puts("--2.1 bracket"); }
		;

statements:
        statement { puts("---3.1. statement"); } |
        statements TSEMI statement { puts("---3.2. statements"); }
		;

statement:
        /* empty statement */	{ puts("----4.1. empty statement"); } |
        assign_stmt	{ puts("----4.2. assign statement"); } |
        label_stmt { puts("----4.3. label statement"); } |
        iter_stmt { puts("----4.4. iter statement"); } |
        jump_stmt { puts("----4.5. jump statement"); } |
        selection_stmt { puts("----4.6 selection statement"); } |
        bracket_stmt { puts("----4.7 bracket statement"); } |
        init_stmt { puts("----4.8 init statement"); }
        ;

bracket_stmt:
        T_BRACKET_BEGIN statements T_BRACKET_END statements	{ puts("-----5.1 bracket"); }
        ;

label_stmt:
        TDEFAULT TCOLON statements { puts("-----5.2. default"); } | // 추가 default
        TCASE constant TCOLON statements { puts("-----5.3. case"); } // 추가 case
        ;

iter_stmt:
        TWHILE TLPAREN expression TRPAREN statements { puts("-----5.4. while"); } |
        TDO statements TWHILE TLPAREN expression TRPAREN TSEMI statements { puts("-----5.5. do while"); } | // 잘안됨.
        TFOR TLPAREN expression TSEMI expression TSEMI expression TRPAREN statements { puts("-----5.6. for");}
        ;

jump_stmt:
        TCONTINUE { puts("-----5.7. continue"); } |
        TBREAK { puts("-----5.8. break"); } |
        TRETURN expression { puts("-----5.9. return"); }
        ;

selection_stmt:
        TIF TLPAREN expression TRPAREN statements { puts("-----5.10 if"); } |
        TIF TLPAREN expression TRPAREN statements TELSE statements { puts("-----5.11 if else"); } |
        TSWITCH TLPAREN expression TRPAREN statements { puts("-----5.12 if else"); }
        ;

assign_stmt:
        left_hand_side TASSIGN expression	{ puts("-----5.13 TASSIGN"); } |
        left_hand_side TASPLUS expression	{ puts("-----5.14 TASPLUS"); } |
        left_hand_side TASMINUS expression	{ puts("-----5.15 TASMINUS"); } |
        left_hand_side TASMUL expression	{ puts("-----5.16 TASMUL"); } |
        left_hand_side TASDIV expression	{ puts("-----5.17 TASDIV"); } |
        left_hand_side TASREMAIN expression	{ puts("-----5.18 TASREMAIN"); } |
        left_hand_side { puts("-----5.19. a;"); } // 추가 'a;'
		;

init_stmt:
        type id { puts("-----5.20. initial"); }
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
        term TMUL relation_expression	{ puts("--------8.1. mul"); } |
        term TDIV relation_expression	{ puts("--------8.2. div"); } |
        term TMOD relation_expression	{ puts("--------8.3. mod"); } |
        relation_expression	{ puts("--------8.4. relation_expression"); }
		;

relation_expression:
        relation_expression TEQUAL factor { puts("--------8.5. TEQUAL"); } |
        relation_expression TNEQUAL factor { puts("--------8.6. TNEQUAL"); }|
        relation_expression TLESS factor { puts("--------8.7. TLESS"); }|
        relation_expression TLESSE factor { puts("--------8.8. TLESSE"); }|
        relation_expression TGREAT factor { puts("--------8.9. TGREAT"); }|
        relation_expression TGREATE factor { puts("--------8.10. TGREATE"); } |
        factor { puts("--------8.11. factor"); }
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

id:
        init_id { puts("----------10.3. id"); } |
        init_id TCOMA id { puts("----------10.4. id list"); }
        ;

init_id:
        TIDENT { puts("-----------10.5. init_id"); } |
        TIDENT TASSIGN TNUMBER { puts("-----------10.6. initializer"); } |
        TIDENT TASSIGN TIDENT { puts("-----------10.7. init assign"); }
        ;

type:
        TVOID { puts("-----------11.1. void"); } |
        TINT { puts("-----------11.2. int"); } |
        TCHAR { puts("-----------11.3. char"); } |
        TFLOAT { puts("-----------11.4. float"); } |
        TDOUBLE { puts("-----------11.5. double"); }
        ;

struct:
        TSTRUCT TIDENT T_BRACKET_BEGIN struct_declare_list T_BRACKET_END { puts("------------12.1"); } TSEMI
        ;

struct_declare_list:
        struct_declare_list struct_declare { puts("------------12.2"); }|
        struct_declare { puts("------------12.3"); }
        ;

struct_declare:
        type TIDENT TSEMI { puts("------------12.4"); }
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
