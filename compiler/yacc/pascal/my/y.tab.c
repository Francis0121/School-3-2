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

#line 2 "mc.y"
/*
	Ultra-mini PASCAL parser
*/
#include <stdio.h>
#line 24 "y.tab.c"

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

#define TIDENT 257
#define TNUMBER 258
#define TASSIGN 259
#define TSEMI 260
#define TDOT 261
#define TBEGIN 262
#define TEND 263
#define TIF 264
#define TELSE 265
#define TFOR 266
#define TERROR 267
#define TLPAREN 268
#define TRPAREN 269
#define TLBRACKET 270
#define TRBRACKET 271
#define TPLUS 272
#define TMINUS 273
#define TMUL 274
#define TDIV 275
#define TMOD 276
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    2,    2,    3,    3,    3,    3,    5,    5,
    6,    4,    8,    7,    7,    7,   10,   10,   10,   10,
   11,   11,   11,   11,    9,    9,
};
static const short yylen[] = {                            2,
    4,    3,    1,    3,    0,    1,    1,    1,    5,    7,
    9,    3,    1,    3,    3,    1,    3,    3,    3,    1,
    2,    1,    1,    3,    1,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,
    3,    6,    7,    8,    0,   13,    0,    0,    0,    0,
    2,    0,   23,    0,    0,    0,   22,    0,   20,    0,
    0,    4,    0,    0,   21,   26,    0,    0,    0,    0,
    0,    0,    0,   24,    0,    0,   17,   18,   19,    0,
    0,    0,    0,   10,    0,    0,    0,
};
static const short yydgoto[] = {                          2,
    6,   10,   11,   12,   13,   14,   26,   15,   27,   28,
   29,
};
static const short yysindex[] = {                      -254,
 -258,    0, -239, -214, -253,    0, -193, -212, -203, -232,
    0,    0,    0,    0, -186,    0, -241, -241, -241, -253,
    0, -241,    0, -241, -241, -169,    0, -168,    0, -179,
 -211,    0, -202, -174,    0,    0, -241, -241, -241, -241,
 -241, -253, -241,    0, -168, -168,    0,    0,    0, -220,
 -197, -253, -241,    0, -172, -253, -181,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -221,    0, -251,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -177,
    0,    0,    0,    0,    0,    0,    0, -219,    0,    0,
    0,    0, -176,    0,    0,    0,    0,    0,    0,    0,
    0, -177,    0,    0, -205, -191,    0,    0,    0, -178,
    0, -177,    0,    0,    0, -177, -206,
};
static const short yygindex[] = {                         0,
    0,  -13,  -14,    0,    0,    0,  -17,    0,   -5,   54,
   -6,
};
#define YYTABLESIZE 108
static const short yytable[] = {                         16,
   30,   31,    1,    7,   33,   32,   34,   25,   25,    3,
    8,   25,    9,   25,   16,    7,   23,   25,   35,   25,
   25,   25,   25,   25,   25,   51,   24,   20,   50,    4,
   21,   25,   47,   48,   49,   55,   16,   54,    5,   20,
   16,    5,   57,   16,   52,   16,   16,    5,   43,   16,
   16,   16,   16,   16,   14,   18,   11,   14,   11,   14,
   37,   38,   53,   14,   19,   14,   14,   14,   15,   37,
   38,   15,   22,   15,   37,   38,   17,   15,   20,   15,
   15,   15,    5,   12,    9,    5,   12,    5,   12,   42,
   45,   46,   37,   38,   44,    0,   56,   37,   38,   37,
   38,   36,   37,   38,    0,   39,   40,   41,
};
static const short yycheck[] = {                          5,
   18,   19,  257,  257,   22,   20,   24,  259,  260,  268,
  264,  263,  266,  265,   20,  257,  258,  269,   25,  271,
  272,  273,  274,  275,  276,   43,  268,  260,   42,  269,
  263,  273,   39,   40,   41,   53,   42,   52,  260,  260,
  260,  263,   56,  263,  265,  265,   52,  262,  260,  269,
   56,  271,  272,  273,  260,  268,  263,  263,  265,  265,
  272,  273,  260,  269,  268,  271,  272,  273,  260,  272,
  273,  263,  259,  265,  272,  273,  270,  269,  260,  271,
  272,  273,  260,  260,  263,  263,  263,  265,  265,  269,
   37,   38,  272,  273,  269,   -1,  269,  272,  273,  272,
  273,  271,  272,  273,   -1,  274,  275,  276,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TIDENT","TNUMBER","TASSIGN",
"TSEMI","TDOT","TBEGIN","TEND","TIF","TELSE","TFOR","TERROR","TLPAREN",
"TRPAREN","TLBRACKET","TRBRACKET","TPLUS","TMINUS","TMUL","TDIV","TMOD",
};
static const char *yyrule[] = {
"$accept : func_stmt",
"func_stmt : TIDENT TLPAREN TRPAREN compound_stmt",
"compound_stmt : TBEGIN statement2 TEND",
"statement2 : statement",
"statement2 : statement2 TSEMI statement",
"statement :",
"statement : assign_stmt",
"statement : if_stmt",
"statement : for_stmt",
"if_stmt : TIF TLPAREN exp TRPAREN statement2",
"if_stmt : TIF TLPAREN exp TRPAREN statement2 TELSE statement",
"for_stmt : TFOR TLPAREN exp TSEMI exp TSEMI exp TRPAREN statement2",
"assign_stmt : lhs TASSIGN exp",
"lhs : variable",
"exp : exp TPLUS term",
"exp : exp TMINUS term",
"exp : term",
"term : term TMUL factor",
"term : term TDIV factor",
"term : term TMOD factor",
"term : factor",
"factor : TMINUS factor",
"factor : variable",
"factor : TNUMBER",
"factor : TLPAREN exp TRPAREN",
"variable : TIDENT",
"variable : TIDENT TLBRACKET exp TRBRACKET",

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
#line 54 "mc.y"

main()
{
	yyparse();
}

yyerror(s)
char *s;
{
	fprintf(stderr, "%s\n", s);
}
#line 242 "y.tab.c"

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
#line 15 "mc.y"
	{ puts("1"); }
break;
case 2:
#line 17 "mc.y"
	{ puts("2"); }
break;
case 3:
#line 19 "mc.y"
	{ puts("3-1"); }
break;
case 4:
#line 20 "mc.y"
	{ puts("3-2"); }
break;
case 5:
#line 22 "mc.y"
	{ puts("4-1"); }
break;
case 6:
#line 23 "mc.y"
	{ puts("4-2"); }
break;
case 7:
#line 24 "mc.y"
	{ puts("4-3"); }
break;
case 8:
#line 25 "mc.y"
	{ puts("4-4"); }
break;
case 9:
#line 27 "mc.y"
	{ puts("11-1"); }
break;
case 10:
#line 28 "mc.y"
	{ puts("11-2"); }
break;
case 12:
#line 32 "mc.y"
	{ puts("5"); }
break;
case 13:
#line 34 "mc.y"
	{ puts("6"); }
break;
case 14:
#line 36 "mc.y"
	{ puts("7-1"); }
break;
case 15:
#line 37 "mc.y"
	{ puts("7-2"); }
break;
case 16:
#line 38 "mc.y"
	{ puts("7-3"); }
break;
case 17:
#line 40 "mc.y"
	{ puts("8-1"); }
break;
case 18:
#line 41 "mc.y"
	{ puts("8-2"); }
break;
case 19:
#line 42 "mc.y"
	{ puts("8-3"); }
break;
case 20:
#line 43 "mc.y"
	{ puts("8-4"); }
break;
case 21:
#line 45 "mc.y"
	{ puts("9-1"); }
break;
case 22:
#line 46 "mc.y"
	{ puts("9-2"); }
break;
case 23:
#line 47 "mc.y"
	{ puts("9-3"); }
break;
case 24:
#line 48 "mc.y"
	{ puts("9-4"); }
break;
case 25:
#line 50 "mc.y"
	{ puts("10-1"); }
break;
case 26:
#line 51 "mc.y"
	{ puts("10-2"); }
break;
#line 548 "y.tab.c"
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
