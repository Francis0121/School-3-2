/************************************
*	20093267 김성근
*	myyacc.y yacc input file
************************************/
%{
    #include <stdio.h>
%}
%token MY_EOF MY_IDENTIFIER MY_NUMBER MY_ERROR
%token TYPE_VOID TYPE_INT TYPE_FLOAT TYPE_DOUBLE TYPE_CHAR
%token ST_BEGIN ST_END ST_DO ST_WHILE ST_IF ST_ELSE ST_SWITCH ST_CASE ST_FOR
%token ST_COMA ST_COLON ST_SEMICOLON ST_DOT ST_DEFAULT
%token JP_BREAK JP_CONTINUE JP_RETURN
%token OP_PLUS OP_MINUS OP_MUL OP_DIV OP_REMAIN OP_PLUSS OP_MINUSS
%token OP_EQUAL OP_NEQUAL OP_LESS OP_LESSE OP_GREAT OP_GREATE
%token AS_DEFAULT AS_PLUS AS_MINUS AS_MUL AS_DIV AS_REMAIN
%token ARRAY_BEGIN ARRAY_END
%token ARGU_BEGIN ARGU_END
%%

statements:
        bracket_stat { printf("braket_stat"); } |
        express_stat { printf("express_stat"); } |
        label_stat { printf("label"); } |
        iter_stat { printf("iter"); } |
        jump_stat { printf("jump"); }
        ;

label_stat:
        MY_IDENTIFIER ST_COLON statements |
        ST_CASE constant ST_COLON statements |
        ST_DEFAULT ST_COLON statements
        ;

constant:
        MY_NUMBER constant |
        MY_NUMBER
        ;

iter_stat:
        ST_WHILE ARGU_BEGIN expression ARGU_END statements |
        ST_DO statements ST_WHILE ARGU_BEGIN expression ARGU_END ST_SEMICOLON |
        ST_FOR ARGU_BEGIN expression ST_SEMICOLON expression ST_SEMICOLON expression ARGU_END statements
        ;

jump_stat:
        JP_CONTINUE |
        JP_BREAK |
        JP_RETURN expression ST_SEMICOLON
        ;


bracket_stat:
        ST_BEGIN statements ST_END
        ;

express_stat:
        expression ST_COLON
        ;

expression:
        assignment_expression |
        expression ST_COMA assignment_expression
        ;

assignment_expression:
        nexpression assignment_operator assignment_expression
        ;

nexpression:
        MY_IDENTIFIER num_operator MY_IDENTIFIER
        ;

assignment_operator:
        AS_DEFAULT |
        AS_PLUS |
        AS_MINUS |
        AS_MUL |
        AS_DIV |
        AS_REMAIN
        ;

num_operator:
        OP_PLUS |
        OP_MINUS |
        OP_MUL |
        OP_DIV |
        OP_REMAIN |
        OP_EQUAL |
        OP_NEQUAL |
        OP_LESS |
        OP_LESSE |
        OP_GREAT |
        OP_GREATE
        ;

%%

main(){
    yyparse();
}

yyerror(char *s){
    printf("%s\n", s);
}