#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20110908

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 6 "myyacc.y"
    #include <stdio.h>
#line 21 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define MY_EOF 257
#define MY_IDENTIFIER 258
#define MY_NUMBER 259
#define MY_ERROR 260
#define TYPE_VOID 261
#define TYPE_INT 262
#define TYPE_FLOAT 263
#define TYPE_DOUBLE 264
#define TYPE_CHAR 265
#define ST_BEGIN 266
#define ST_END 267
#define ST_DO 268
#define ST_WHILE 269
#define ST_IF 270
#define ST_ELSE 271
#define ST_SWITCH 272
#define ST_CASE 273
#define ST_FOR 274
#define ST_COMA 275
#define ST_COLON 276
#define ST_SEMICOLON 277
#define ST_DOT 278
#define ST_DEFAULT 279
#define JP_BREAK 280
#define JP_CONTINUE 281
#define JP_RETURN 282
#define OP_PLUS 283
#define OP_MINUS 284
#define OP_MUL 285
#define OP_DIV 286
#define OP_REMAIN 287
#define OP_PLUSS 288
#define OP_MINUSS 289
#define OP_EQUAL 290
#define OP_NEQUAL 291
#define OP_LESS 292
#define OP_LESSE 293
#define OP_GREAT 294
#define OP_GREATE 295
#define AS_DEFAULT 296
#define AS_PLUS 297
#define AS_MINUS 298
#define AS_MUL 299
#define AS_DIV 300
#define AS_REMAIN 301
#define ARRAY_BEGIN 302
#define ARRAY_END 303
#define ARGU_BEGIN 304
#define ARGU_END 305
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    3,    3,    3,    6,    6,
    4,    4,    4,    5,    5,    5,    1,    2,    7,    7,
    8,    9,   10,   10,   10,   10,   10,   10,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,
};
static const short yylen[] = {                            2,
    1,    1,    1,    1,    1,    3,    4,    3,    2,    1,
    5,    7,    9,    1,    1,    3,    3,    2,    1,    3,
    3,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,   15,   14,    0,
    0,    1,    2,    3,    4,    5,    0,   19,    0,    0,
   29,   30,   31,   32,   33,   34,   35,   36,   37,   38,
   39,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   18,   23,   24,   25,   26,   27,   28,    0,
    6,   22,   17,    0,    0,    9,    0,    0,    8,   16,
   20,   21,    0,    0,    7,    0,    0,   11,    0,    0,
    0,   12,    0,    0,   13,
};
static const short yydgoto[] = {                         11,
   12,   13,   14,   15,   16,   37,   17,   18,   19,   50,
   32,
};
static const short yysindex[] = {                      -228,
 -216, -228, -228, -288, -238, -279, -250,    0,    0, -231,
    0,    0,    0,    0,    0,    0, -252,    0, -289, -228,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -229, -234, -233, -231, -238, -237, -231, -228, -203,
 -262, -231,    0,    0,    0,    0,    0,    0,    0, -231,
    0,    0,    0, -261, -273,    0, -228, -258,    0,    0,
    0,    0, -231, -228,    0, -231, -271,    0, -255, -235,
 -231,    0, -270, -228,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -232,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                        -2,
    0,    0,    0,    0,    0,   11,   -7,  -36,    0,    0,
    0,
};
#define YYTABLESIZE 92
static const short yytable[] = {                         33,
   34,   42,   41,   42,   42,   61,   44,   45,   46,   47,
   48,   49,   42,   62,   60,   35,   42,   51,   66,   42,
   36,   71,   42,   43,   38,   39,   40,   55,   52,    1,
   58,   64,   53,   70,   74,   54,   59,    2,   57,    3,
    4,   72,   63,   10,    5,    6,   56,    0,    0,    0,
    7,    8,    9,   10,   65,   67,    0,    0,   69,   20,
    0,   68,    0,   73,    0,    0,   21,   22,   23,   24,
   25,   75,    0,   26,   27,   28,   29,   30,   31,   21,
   22,   23,   24,   25,    0,    0,   26,   27,   28,   29,
   30,   31,
};
static const short yycheck[] = {                          2,
    3,  275,   10,  275,  275,   42,  296,  297,  298,  299,
  300,  301,  275,   50,  277,  304,  275,   20,  277,  275,
  259,  277,  275,  276,  304,  276,  258,   35,  258,  258,
   38,  305,  267,  305,  305,  269,   39,  266,  276,  268,
  269,  277,  304,  276,  273,  274,   36,   -1,   -1,   -1,
  279,  280,  281,  282,   57,   63,   -1,   -1,   66,  276,
   -1,   64,   -1,   71,   -1,   -1,  283,  284,  285,  286,
  287,   74,   -1,  290,  291,  292,  293,  294,  295,  283,
  284,  285,  286,  287,   -1,   -1,  290,  291,  292,  293,
  294,  295,
};
#define YYFINAL 11
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 305
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"MY_EOF","MY_IDENTIFIER",
"MY_NUMBER","MY_ERROR","TYPE_VOID","TYPE_INT","TYPE_FLOAT","TYPE_DOUBLE",
"TYPE_CHAR","ST_BEGIN","ST_END","ST_DO","ST_WHILE","ST_IF","ST_ELSE",
"ST_SWITCH","ST_CASE","ST_FOR","ST_COMA","ST_COLON","ST_SEMICOLON","ST_DOT",
"ST_DEFAULT","JP_BREAK","JP_CONTINUE","JP_RETURN","OP_PLUS","OP_MINUS","OP_MUL",
"OP_DIV","OP_REMAIN","OP_PLUSS","OP_MINUSS","OP_EQUAL","OP_NEQUAL","OP_LESS",
"OP_LESSE","OP_GREAT","OP_GREATE","AS_DEFAULT","AS_PLUS","AS_MINUS","AS_MUL",
"AS_DIV","AS_REMAIN","ARRAY_BEGIN","ARRAY_END","ARGU_BEGIN","ARGU_END",
};
static const char *yyrule[] = {
"$accept : statements",
"statements : bracket_stat",
"statements : express_stat",
"statements : label_stat",
"statements : iter_stat",
"statements : jump_stat",
"label_stat : MY_IDENTIFIER ST_COLON statements",
"label_stat : ST_CASE constant ST_COLON statements",
"label_stat : ST_DEFAULT ST_COLON statements",
"constant : MY_NUMBER constant",
"constant : MY_NUMBER",
"iter_stat : ST_WHILE ARGU_BEGIN expression ARGU_END statements",
"iter_stat : ST_DO statements ST_WHILE ARGU_BEGIN expression ARGU_END ST_SEMICOLON",
"iter_stat : ST_FOR ARGU_BEGIN expression ST_SEMICOLON expression ST_SEMICOLON expression ARGU_END statements",
"jump_stat : JP_CONTINUE",
"jump_stat : JP_BREAK",
"jump_stat : JP_RETURN expression ST_SEMICOLON",
"bracket_stat : ST_BEGIN statements ST_END",
"express_stat : expression ST_COLON",
"expression : assignment_expression",
"expression : expression ST_COMA assignment_expression",
"assignment_expression : nexpression assignment_operator assignment_expression",
"nexpression : MY_IDENTIFIER num_operator MY_IDENTIFIER",
"assignment_operator : AS_DEFAULT",
"assignment_operator : AS_PLUS",
"assignment_operator : AS_MINUS",
"assignment_operator : AS_MUL",
"assignment_operator : AS_DIV",
"assignment_operator : AS_REMAIN",
"num_operator : OP_PLUS",
"num_operator : OP_MINUS",
"num_operator : OP_MUL",
"num_operator : OP_DIV",
"num_operator : OP_REMAIN",
"num_operator : OP_EQUAL",
"num_operator : OP_NEQUAL",
"num_operator : OP_LESS",
"num_operator : OP_LESSE",
"num_operator : OP_GREAT",
"num_operator : OP_GREATE",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 97 "myyacc.y"

main(){
    yyparse();
}

yyerror(char *s){
    printf("%s\n", s);
}
#line 289 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 21 "myyacc.y"
	{ printf("braket_stat"); }
break;
case 2:
#line 22 "myyacc.y"
	{ printf("express_stat"); }
break;
case 3:
#line 23 "myyacc.y"
	{ printf("label"); }
break;
case 4:
#line 24 "myyacc.y"
	{ printf("iter"); }
break;
case 5:
#line 25 "myyacc.y"
	{ printf("jump"); }
break;
#line 515 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
