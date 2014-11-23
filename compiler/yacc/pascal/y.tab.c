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

#line 1 "pascal.y"

/*
	mini-c yacc
*/
#include <stdio.h>
#line 25 "y.tab.c"

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

#define T_BRACKET_BEGIN 257
#define T_BRACKET_END 258
#define TCASE 259
#define TDEFAULT 260
#define TWHILE 261
#define TDO 262
#define TFOR 263
#define TIDENT 264
#define TNUMBER 265
#define TASSIGN 266
#define TSEMI 267
#define TCOLON 268
#define TCOMA 269
#define TERROR 270
#define TPLUS 271
#define TMINUS 272
#define TMUL 273
#define TDIV 274
#define TMOD 275
#define TLPAREN 276
#define TRPAREN 277
#define TLBRACKET 278
#define TRBRACKET 279
#define TIF 280
#define TELSE 281
#define TBREAK 282
#define TRETURN 283
#define TCONTINUE 284
#define TVOID 285
#define TINT 286
#define TCHAR 287
#define TFLOAT 288
#define TDOUBLE 289
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    2,    4,    4,    5,    3,    6,    6,    6,    6,
    6,    7,    7,    8,    8,    9,    9,    9,   10,   10,
   10,   11,   11,   14,   13,   13,   13,   16,   16,   16,
   16,   17,   17,   17,   17,   15,   12,    1,    1,    1,
    1,    1,
};
static const short yylen[] = {                            2,
    4,    3,    1,    3,    2,    3,    1,    3,    1,    1,
    1,    0,    1,    3,    4,    5,    7,    9,    1,    1,
    2,    3,    1,    1,    3,    3,    1,    3,    3,    3,
    1,    2,    1,    1,    3,    1,    1,    1,    1,    1,
    1,    1,
};
static const short yydefred[] = {                         0,
   38,   39,   40,   41,   42,    0,    0,    0,    0,    0,
    0,    0,    3,    0,    1,    5,    0,    2,    0,    0,
    0,    0,    0,   36,   20,    0,   19,    0,    7,    9,
   10,   11,   13,    0,   24,    4,   37,    0,    0,    0,
    0,    0,   34,    0,    0,    0,   33,    0,   31,    6,
    0,    0,    0,   14,    0,    0,    0,   32,    0,    0,
    0,    0,    0,    0,    8,    0,   15,    0,    0,    0,
   35,    0,    0,   28,   29,   30,   16,    0,    0,    0,
    0,   17,    0,    0,   18,
};
static const short yydgoto[] = {                          6,
   11,   10,   15,   12,   13,   28,   29,   30,   31,   32,
   33,   38,   46,   34,   47,   48,   49,
};
static const short yysindex[] = {                      -180,
    0,    0,    0,    0,    0,    0, -257, -261, -180, -229,
 -226, -264,    0, -240,    0,    0, -180,    0, -219, -215,
 -220, -204, -212,    0,    0, -262,    0, -231,    0,    0,
    0,    0,    0, -197,    0,    0,    0, -193, -204, -262,
 -179, -262,    0, -262, -262, -158,    0, -163,    0,    0,
 -204, -262, -204,    0, -260, -192, -170,    0, -191, -262,
 -262, -262, -262, -262,    0, -158,    0, -204, -262, -262,
    0, -163, -163,    0,    0,    0,    0, -181, -168, -178,
 -262,    0, -177, -204,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -210,    0,    0,    0,    0,    0,    0,
    0, -169,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -232,    0,    0,    0,    0, -210,    0,
    0,    0,    0,    0,    0, -200,    0, -206,    0,    0,
 -210,    0, -210,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -182,    0, -210,    0,    0,
    0, -199, -184,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -210,    0,
};
static const short yygindex[] = {                         0,
   98,    0,    0,    0,   99,    0,  -21,    0,    0,    0,
    0,    0,  -36,    0,  -14,  -20,  -13,
};
#define YYTABLESIZE 116
static const short yytable[] = {                         35,
   41,   24,   43,   55,   17,   57,    8,   35,   59,   44,
   60,   61,   18,   45,    9,   66,   68,   54,   19,   20,
   21,   22,   23,   24,   35,   23,   50,   14,   23,   65,
   58,   67,   78,   79,   23,   51,   35,   16,   35,   72,
   73,   25,   26,   27,   83,   37,   77,   12,   74,   75,
   76,   27,   39,   35,   27,   40,   12,   21,   25,   24,
   27,   25,   85,   42,   27,   27,   21,   25,   52,   35,
   27,   25,   25,   26,   53,   22,   26,   25,   22,   60,
   61,   56,   26,   69,   22,   71,   26,   26,   82,   60,
   61,   12,   26,   60,   61,   80,   70,    7,   81,   84,
   60,   61,   60,   61,    1,    2,    3,    4,    5,   62,
   63,   64,   60,   61,    0,   36,
};
static const short yycheck[] = {                         14,
   22,  264,  265,   40,  269,   42,  264,   22,   45,  272,
  271,  272,  277,  276,  276,   52,  277,   39,  259,  260,
  261,  262,  263,  264,   39,  258,  258,  257,  261,   51,
   44,   53,   69,   70,  267,  267,   51,  264,   53,   60,
   61,  282,  283,  284,   81,  265,   68,  258,   62,   63,
   64,  258,  268,   68,  261,  276,  267,  258,  258,  264,
  267,  261,   84,  276,  271,  272,  267,  267,  266,   84,
  277,  271,  272,  258,  268,  258,  261,  277,  261,  271,
  272,  261,  267,  276,  267,  277,  271,  272,  267,  271,
  272,  261,  277,  271,  272,  277,  267,    0,  267,  277,
  271,  272,  271,  272,  285,  286,  287,  288,  289,  273,
  274,  275,  271,  272,   -1,   17,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 289
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_BRACKET_BEGIN","T_BRACKET_END",
"TCASE","TDEFAULT","TWHILE","TDO","TFOR","TIDENT","TNUMBER","TASSIGN","TSEMI",
"TCOLON","TCOMA","TERROR","TPLUS","TMINUS","TMUL","TDIV","TMOD","TLPAREN",
"TRPAREN","TLBRACKET","TRBRACKET","TIF","TELSE","TBREAK","TRETURN","TCONTINUE",
"TVOID","TINT","TCHAR","TFLOAT","TDOUBLE",
};
static const char *yyrule[] = {
"$accept : start_symbol",
"start_symbol : type TIDENT argument bracket_stmt",
"argument : TLPAREN params TRPAREN",
"params : param",
"params : params TCOMA param",
"param : type TIDENT",
"bracket_stmt : T_BRACKET_BEGIN statements T_BRACKET_END",
"statements : statement",
"statements : statements TSEMI statement",
"statements : label_stmt",
"statements : iter_stmt",
"statements : jump_stmt",
"statement :",
"statement : assign_stmt",
"label_stmt : TDEFAULT TCOLON statement",
"label_stmt : TCASE constant TCOLON statement",
"iter_stmt : TWHILE TLPAREN expression TRPAREN statement",
"iter_stmt : TDO statement TWHILE TLPAREN expression TRPAREN TSEMI",
"iter_stmt : TFOR TLPAREN expression TSEMI expression TSEMI expression TRPAREN statement",
"jump_stmt : TCONTINUE",
"jump_stmt : TBREAK",
"jump_stmt : TRETURN expression",
"assign_stmt : left_hand_side TASSIGN expression",
"assign_stmt : left_hand_side",
"left_hand_side : variable",
"expression : expression TPLUS term",
"expression : expression TMINUS term",
"expression : term",
"term : term TMUL factor",
"term : term TDIV factor",
"term : term TMOD factor",
"term : factor",
"factor : TMINUS factor",
"factor : variable",
"factor : TNUMBER",
"factor : TLPAREN expression TRPAREN",
"variable : TIDENT",
"constant : TNUMBER",
"type : TVOID",
"type : TINT",
"type : TCHAR",
"type : TFLOAT",
"type : TDOUBLE",

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
#line 120 "pascal.y"


main()
{
	yyparse();
}

yyerror(s)
char *s;
{
	fprintf(stderr, "%s\n", s);
}
#line 290 "y.tab.c"

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
#line 23 "pascal.y"
	{ puts("-1.1 bracket"); }
break;
case 2:
#line 27 "pascal.y"
	{ puts("-1.2 argument"); }
break;
case 3:
#line 31 "pascal.y"
	{ puts("-1.3 parameter"); }
break;
case 4:
#line 32 "pascal.y"
	{ puts("-1.4 parameters"); }
break;
case 5:
#line 36 "pascal.y"
	{ puts("-1.5 parameter"); }
break;
case 6:
#line 40 "pascal.y"
	{ puts("--2.4 bracket"); }
break;
case 7:
#line 44 "pascal.y"
	{ puts("---3.1. statement"); }
break;
case 8:
#line 45 "pascal.y"
	{ puts("---3.2. statements"); }
break;
case 9:
#line 46 "pascal.y"
	{ puts("---3.3. label statement"); }
break;
case 10:
#line 47 "pascal.y"
	{ puts("---3.4. iter statement"); }
break;
case 11:
#line 48 "pascal.y"
	{ puts("---3.5. jump statement"); }
break;
case 12:
#line 52 "pascal.y"
	{ puts("----4.1. empty statement"); }
break;
case 13:
#line 53 "pascal.y"
	{ puts("----4.2. assign statement"); }
break;
case 14:
#line 57 "pascal.y"
	{ puts("----4.3. default"); }
break;
case 15:
#line 58 "pascal.y"
	{ puts("----4.4. case"); }
break;
case 16:
#line 62 "pascal.y"
	{ puts("----4.5. while"); }
break;
case 17:
#line 63 "pascal.y"
	{ puts("----4.6. do while"); }
break;
case 18:
#line 64 "pascal.y"
	{ puts("----4.7. for");}
break;
case 19:
#line 68 "pascal.y"
	{ puts("----4.8. continue"); }
break;
case 20:
#line 69 "pascal.y"
	{ puts("----4.9. break"); }
break;
case 21:
#line 70 "pascal.y"
	{ puts("----4.10. return"); }
break;
case 22:
#line 74 "pascal.y"
	{ puts("-----5.1 exprssion"); }
break;
case 23:
#line 75 "pascal.y"
	{ puts("-----5.2. a;"); }
break;
case 24:
#line 80 "pascal.y"
	{ puts("------6. variable"); }
break;
case 25:
#line 84 "pascal.y"
	{ puts("-------7.1. plus"); }
break;
case 26:
#line 85 "pascal.y"
	{ puts("-------7.2. minus"); }
break;
case 27:
#line 86 "pascal.y"
	{ puts("-------7.3. term"); }
break;
case 28:
#line 90 "pascal.y"
	{ puts("--------8.1. mul"); }
break;
case 29:
#line 91 "pascal.y"
	{ puts("--------8.2. div"); }
break;
case 30:
#line 92 "pascal.y"
	{ puts("--------8.3. mod"); }
break;
case 31:
#line 93 "pascal.y"
	{ puts("--------8.4. factor"); }
break;
case 32:
#line 97 "pascal.y"
	{ puts("---------9.1. minus factor"); }
break;
case 33:
#line 98 "pascal.y"
	{ puts("---------9.2. variable"); }
break;
case 34:
#line 99 "pascal.y"
	{ puts("---------9.3. number"); }
break;
case 35:
#line 100 "pascal.y"
	{ puts("---------9.4. ( )"); }
break;
case 36:
#line 104 "pascal.y"
	{ puts("----------10.1. identifier"); }
break;
case 37:
#line 108 "pascal.y"
	{ puts("----------10.2. constant"); }
break;
case 38:
#line 112 "pascal.y"
	{ puts("-----------11.1. void"); }
break;
case 39:
#line 113 "pascal.y"
	{ puts("-----------11.2. int"); }
break;
case 40:
#line 114 "pascal.y"
	{ puts("-----------11.3. char"); }
break;
case 41:
#line 115 "pascal.y"
	{ puts("-----------11.4. float"); }
break;
case 42:
#line 116 "pascal.y"
	{ puts("-----------11.5. double"); }
break;
#line 664 "y.tab.c"
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
