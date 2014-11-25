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
#define TSWITCH 282
#define TBREAK 283
#define TRETURN 284
#define TCONTINUE 285
#define TVOID 286
#define TINT 287
#define TCHAR 288
#define TFLOAT 289
#define TDOUBLE 290
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    3,    3,    5,    5,    6,    6,    4,
    7,    7,    8,    8,    8,    8,    8,    8,    8,    8,
   14,   10,   10,   11,   11,   11,   12,   12,   12,   13,
   13,   13,    9,    9,   15,   18,   17,   17,   17,   21,
   21,   21,   21,   22,   22,   22,   22,   20,   16,   19,
   19,   23,   23,   23,    2,    2,    2,    2,    2,
};
static const short yylen[] = {                            2,
    1,    2,    4,    2,    3,    1,    3,    1,    2,    3,
    1,    3,    0,    1,    1,    1,    1,    1,    1,    1,
    4,    3,    4,    5,    8,    9,    1,    1,    2,    5,
    7,    5,    3,    1,    2,    1,    3,    3,    1,    3,
    3,    3,    1,    2,    1,    1,    3,    1,    1,    1,
    3,    1,    3,    3,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
   55,   56,   57,   58,   59,    0,    0,    0,    2,    0,
    0,    0,    4,    0,    0,    0,    6,    0,    3,    9,
    0,    5,    0,    0,    0,    0,    0,    0,   48,    0,
    0,   28,    0,   27,    0,    0,   11,   14,   15,   16,
   17,   18,   19,   20,    0,   36,    7,    0,   49,    0,
    0,    0,    0,    0,    0,    0,   46,    0,    0,    0,
   45,    0,   43,    0,   35,    0,   10,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   44,    0,    0,
    0,    0,    0,    0,    0,    0,   12,    0,    0,    0,
    0,    0,    0,    0,    0,   47,    0,    0,   40,   41,
   42,   54,   53,   51,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yydgoto[] = {                          6,
    7,   35,   12,   19,   16,   17,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   50,   60,   45,   65,   61,
   62,   63,   66,
};
static const short yysindex[] = {                       -85,
    0,    0,    0,    0,    0,    0,  -85, -263,    0, -237,
 -103, -199,    0,    0, -196, -265,    0, -176,    0,    0,
  -80,    0, -176, -202, -198, -194, -176, -171,    0, -139,
 -116,    0, -262,    0, -131, -193,    0,    0,    0,    0,
    0,    0,    0,    0,  -98,    0,    0, -169,    0, -118,
 -176, -262, -201, -262, -262, -262,    0, -262, -262,  -96,
    0, -183,    0,  -86,    0, -107,    0, -176, -262, -176,
 -176,  -89, -150,  -94,  -74, -129, -108,    0, -106, -262,
 -262, -262, -262, -262,  -53, -131,    0,  -96,  -89,  -89,
 -176, -262, -262, -176, -176,    0, -183, -183,    0,    0,
    0,    0,    0,    0,  -89,  -83,  -72, -225,  -89,  -75,
 -262, -176, -176,  -81,  -89,  -89, -176,  -89,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,  215,    0,    0,    0,
    0,    0,    0, -205,    0,    0,    0, -165,    0,    0,
    0,    0, -165,    0,    0,    0,  -51,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -245,    0,    0,    0,    0,    0,
 -240,    0,    0,    0,    0,    0,    0,    0,    0, -241,
    0, -143,    0, -224,    0, -142,    0, -240,    0, -240,
 -240, -214,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -114, -212, -210,
 -240,    0,    0, -240, -240,    0, -141, -126,    0,    0,
    0,    0,    0,    0, -158,    0,    0,  -88, -109,    0,
    0, -240, -240,    0, -104, -102, -240, -100,
};
static const short yygindex[] = {                       210,
    0,    8,    0,    0,    0,  197,  -16,  151,    0,    0,
    0,    0,    0,    0,    0,    0,  -31,    0,  134,  -18,
  133,  -52,    0,
};
#define YYTABLESIZE 220
static const short yytable[] = {                         46,
   10,   29,   57,   21,   46,   78,   48,    8,   46,   58,
   53,   22,   34,   59,    8,   34,   29,   13,   15,   29,
   73,   34,   75,   76,   77,   29,   13,   79,   15,   99,
  100,  101,   46,   52,   72,   34,   52,   88,   11,   29,
   13,   68,   52,   22,   52,   21,   22,   23,   21,   46,
   23,   46,   46,   89,   90,  112,   52,   18,   55,   74,
  106,  107,   49,    8,   67,   68,   22,   20,   21,   51,
   23,    8,   46,   68,  105,   46,   46,  108,  109,  114,
   23,   52,   24,   25,   26,   27,   28,   29,   70,   82,
   83,   84,   13,   46,   46,  115,  116,   68,   46,   24,
  118,   13,   24,   30,   54,   31,   32,   33,   34,    1,
    2,    3,    4,    5,   39,   50,   37,   39,   50,   37,
   80,   81,   24,   39,   50,   37,   91,   39,   39,   37,
   37,   38,   64,   39,   38,   37,   55,   39,   50,   37,
   38,   80,   81,   33,   38,   38,   33,   94,   32,   71,
   38,   32,   33,   31,   38,   25,   31,   26,   25,   56,
   26,   86,   80,   81,   80,   81,   33,   69,   95,   30,
   96,   32,   30,   13,   80,   81,   31,   68,   25,   85,
   26,   92,   14,    2,    3,    4,    5,   80,   81,   80,
   81,  113,   93,  110,  111,  117,   80,   81,   80,   81,
    1,    2,    3,    4,    5,   14,    2,    3,    4,    5,
  102,  103,   97,   98,    1,   13,    9,   47,   87,  104,
};
static const short yycheck[] = {                         18,
  264,  264,  265,  269,   23,   58,   23,    0,   27,  272,
   27,  277,  258,  276,    7,  261,  258,  258,   11,  261,
   52,  267,   54,   55,   56,  267,  267,   59,   21,   82,
   83,   84,   51,  258,   51,  281,  261,   69,  276,  281,
  281,  267,  267,  258,  269,  258,  261,  258,  261,   68,
  261,   70,   71,   70,   71,  281,  281,  257,  264,  261,
   92,   93,  265,  269,  258,  267,  281,  264,  281,  268,
  281,  277,   91,  267,   91,   94,   95,   94,   95,  111,
  257,  276,  259,  260,  261,  262,  263,  264,  258,  273,
  274,  275,  258,  112,  113,  112,  113,  267,  117,  258,
  117,  267,  261,  280,  276,  282,  283,  284,  285,  286,
  287,  288,  289,  290,  258,  258,  258,  261,  261,  261,
  271,  272,  281,  267,  267,  267,  277,  271,  272,  271,
  272,  258,  264,  277,  261,  277,  276,  281,  281,  281,
  267,  271,  272,  258,  271,  272,  261,  277,  258,  268,
  277,  261,  267,  258,  281,  258,  261,  258,  261,  276,
  261,  269,  271,  272,  271,  272,  281,  266,  277,  258,
  277,  281,  261,  277,  271,  272,  281,  267,  281,  266,
  281,  276,  286,  287,  288,  289,  290,  271,  272,  271,
  272,  267,  267,  277,  267,  277,  271,  272,  271,  272,
  286,  287,  288,  289,  290,  286,  287,  288,  289,  290,
  264,  265,   80,   81,    0,  267,    7,   21,   68,   86,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
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
"TRPAREN","TLBRACKET","TRBRACKET","TIF","TELSE","TSWITCH","TBREAK","TRETURN",
"TCONTINUE","TVOID","TINT","TCHAR","TFLOAT","TDOUBLE",
};
static const char *yyrule[] = {
"$accept : start_symbol",
"start_symbol : func",
"start_symbol : func start_symbol",
"func : type TIDENT argument external_stmt",
"argument : TLPAREN TRPAREN",
"argument : TLPAREN params TRPAREN",
"params : param",
"params : params TCOMA param",
"param : TVOID",
"param : type TIDENT",
"external_stmt : T_BRACKET_BEGIN statements T_BRACKET_END",
"statements : statement",
"statements : statements TSEMI statement",
"statement :",
"statement : assign_stmt",
"statement : label_stmt",
"statement : iter_stmt",
"statement : jump_stmt",
"statement : selection_stmt",
"statement : bracket_stmt",
"statement : init_stmt",
"bracket_stmt : T_BRACKET_BEGIN statements T_BRACKET_END statements",
"label_stmt : TDEFAULT TCOLON statements",
"label_stmt : TCASE constant TCOLON statements",
"iter_stmt : TWHILE TLPAREN expression TRPAREN statements",
"iter_stmt : TDO statements TWHILE TLPAREN expression TRPAREN TSEMI statements",
"iter_stmt : TFOR TLPAREN expression TSEMI expression TSEMI expression TRPAREN statements",
"jump_stmt : TCONTINUE",
"jump_stmt : TBREAK",
"jump_stmt : TRETURN expression",
"selection_stmt : TIF TLPAREN expression TRPAREN statements",
"selection_stmt : TIF TLPAREN expression TRPAREN statements TELSE statements",
"selection_stmt : TSWITCH TLPAREN expression TRPAREN statements",
"assign_stmt : left_hand_side TASSIGN expression",
"assign_stmt : left_hand_side",
"init_stmt : type id",
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
"id : init_id",
"id : init_id TCOMA id",
"init_id : TIDENT",
"init_id : TIDENT TASSIGN TNUMBER",
"init_id : TIDENT TASSIGN TIDENT",
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
#line 153 "pascal.y"


main()
{
	yyparse();
}

yyerror(s)
char *s;
{
	fprintf(stderr, "%s\n", s);
}
#line 341 "y.tab.c"

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
	{ puts("0.1. function"); }
break;
case 2:
#line 24 "pascal.y"
	{ puts("0.2 functions"); }
break;
case 3:
#line 28 "pascal.y"
	{ puts("-1.1 bracket"); }
break;
case 4:
#line 32 "pascal.y"
	{ puts("-1.2 no argument"); }
break;
case 5:
#line 33 "pascal.y"
	{ puts("-1.3 argument"); }
break;
case 6:
#line 37 "pascal.y"
	{ puts("-1.4 one parameter"); }
break;
case 7:
#line 38 "pascal.y"
	{ puts("-1.5 parameters"); }
break;
case 8:
#line 42 "pascal.y"
	{ puts("-1.6 parameter void "); }
break;
case 9:
#line 43 "pascal.y"
	{ puts("-1.7 parameter detail"); }
break;
case 10:
#line 47 "pascal.y"
	{ puts("--2.1 bracket"); }
break;
case 11:
#line 51 "pascal.y"
	{ puts("---3.1. statement"); }
break;
case 12:
#line 52 "pascal.y"
	{ puts("---3.2. statements"); }
break;
case 13:
#line 56 "pascal.y"
	{ puts("----4.1. empty statement"); }
break;
case 14:
#line 57 "pascal.y"
	{ puts("----4.2. assign statement"); }
break;
case 15:
#line 58 "pascal.y"
	{ puts("----4.3. label statement"); }
break;
case 16:
#line 59 "pascal.y"
	{ puts("----4.4. iter statement"); }
break;
case 17:
#line 60 "pascal.y"
	{ puts("----4.5. jump statement"); }
break;
case 18:
#line 61 "pascal.y"
	{ puts("----4.6 selection statement"); }
break;
case 19:
#line 62 "pascal.y"
	{ puts("----4.7 bracket statement"); }
break;
case 20:
#line 63 "pascal.y"
	{ puts("----4.8 init statement"); }
break;
case 21:
#line 67 "pascal.y"
	{ puts("-----5.1 bracket"); }
break;
case 22:
#line 71 "pascal.y"
	{ puts("-----5.2. default"); }
break;
case 23:
#line 72 "pascal.y"
	{ puts("-----5.3. case"); }
break;
case 24:
#line 76 "pascal.y"
	{ puts("-----5.4. while"); }
break;
case 25:
#line 77 "pascal.y"
	{ puts("-----5.5. do while"); }
break;
case 26:
#line 78 "pascal.y"
	{ puts("-----5.6. for");}
break;
case 27:
#line 82 "pascal.y"
	{ puts("-----5.7. continue"); }
break;
case 28:
#line 83 "pascal.y"
	{ puts("-----5.8. break"); }
break;
case 29:
#line 84 "pascal.y"
	{ puts("-----5.9. return"); }
break;
case 30:
#line 88 "pascal.y"
	{ puts("-----5.10 if"); }
break;
case 31:
#line 89 "pascal.y"
	{ puts("-----5.11 if else"); }
break;
case 32:
#line 90 "pascal.y"
	{ puts("-----5.12 if else"); }
break;
case 33:
#line 94 "pascal.y"
	{ puts("-----5.13 exprssion"); }
break;
case 34:
#line 95 "pascal.y"
	{ puts("-----5.14. a;"); }
break;
case 35:
#line 99 "pascal.y"
	{ puts("-----5.14. initial"); }
break;
case 36:
#line 103 "pascal.y"
	{ puts("------6. variable"); }
break;
case 37:
#line 107 "pascal.y"
	{ puts("-------7.1. plus"); }
break;
case 38:
#line 108 "pascal.y"
	{ puts("-------7.2. minus"); }
break;
case 39:
#line 109 "pascal.y"
	{ puts("-------7.3. term"); }
break;
case 40:
#line 113 "pascal.y"
	{ puts("--------8.1. mul"); }
break;
case 41:
#line 114 "pascal.y"
	{ puts("--------8.2. div"); }
break;
case 42:
#line 115 "pascal.y"
	{ puts("--------8.3. mod"); }
break;
case 43:
#line 116 "pascal.y"
	{ puts("--------8.4. factor"); }
break;
case 44:
#line 120 "pascal.y"
	{ puts("---------9.1. minus factor"); }
break;
case 45:
#line 121 "pascal.y"
	{ puts("---------9.2. variable"); }
break;
case 46:
#line 122 "pascal.y"
	{ puts("---------9.3. number"); }
break;
case 47:
#line 123 "pascal.y"
	{ puts("---------9.4. ( )"); }
break;
case 48:
#line 127 "pascal.y"
	{ puts("----------10.1. identifier"); }
break;
case 49:
#line 131 "pascal.y"
	{ puts("----------10.2. constant"); }
break;
case 50:
#line 135 "pascal.y"
	{ puts("----------10.3. id"); }
break;
case 51:
#line 136 "pascal.y"
	{ puts("----------10.4. id list"); }
break;
case 52:
#line 140 "pascal.y"
	{ puts("-----------10.5. init_id"); }
break;
case 53:
#line 141 "pascal.y"
	{ puts("-----------10.6. initializer"); }
break;
case 54:
#line 142 "pascal.y"
	{ puts("-----------10.7. init assign"); }
break;
case 55:
#line 146 "pascal.y"
	{ puts("-----------11.1. void"); }
break;
case 56:
#line 147 "pascal.y"
	{ puts("-----------11.2. int"); }
break;
case 57:
#line 148 "pascal.y"
	{ puts("-----------11.3. char"); }
break;
case 58:
#line 149 "pascal.y"
	{ puts("-----------11.4. float"); }
break;
case 59:
#line 150 "pascal.y"
	{ puts("-----------11.5. double"); }
break;
#line 783 "y.tab.c"
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
