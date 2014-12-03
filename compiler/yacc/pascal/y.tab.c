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
#define TSEMI 266
#define TCOLON 267
#define TCOMA 268
#define TERROR 269
#define TPLUS 270
#define TMINUS 271
#define TMUL 272
#define TDIV 273
#define TMOD 274
#define TLPAREN 275
#define TRPAREN 276
#define TLBRACKET 277
#define TRBRACKET 278
#define TIF 279
#define TELSE 280
#define TSWITCH 281
#define TBREAK 282
#define TRETURN 283
#define TCONTINUE 284
#define TVOID 285
#define TINT 286
#define TCHAR 287
#define TFLOAT 288
#define TDOUBLE 289
#define TASSIGN 290
#define TASPLUS 291
#define TASMINUS 292
#define TASMUL 293
#define TASDIV 294
#define TASREMAIN 295
#define TEQUAL 296
#define TNEQUAL 297
#define TLESS 298
#define TLESSE 299
#define TGREAT 300
#define TGREATE 301
#define TEQAUL 302
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    3,    3,    5,    5,    6,    6,    4,
    7,    7,    8,    8,    8,    8,    8,    8,    8,    8,
   14,   10,   10,   11,   11,   11,   12,   12,   12,   13,
   13,   13,    9,    9,    9,    9,    9,    9,    9,   15,
   18,   17,   17,   17,   21,   21,   21,   21,   22,   22,
   22,   22,   22,   22,   22,   23,   23,   23,   23,   20,
   16,   19,   19,   24,   24,   24,    2,    2,    2,    2,
    2,
};
static const short yylen[] = {                            2,
    1,    2,    4,    2,    3,    1,    3,    1,    2,    3,
    1,    3,    0,    1,    1,    1,    1,    1,    1,    1,
    4,    3,    4,    5,    8,    9,    1,    1,    2,    5,
    7,    5,    3,    3,    3,    3,    3,    3,    1,    2,
    1,    3,    3,    1,    3,    3,    3,    1,    3,    3,
    3,    3,    3,    3,    1,    2,    1,    1,    3,    1,
    1,    1,    3,    1,    3,    3,    1,    1,    1,    1,
    1,
};
static const short yydefred[] = {                         0,
   67,   68,   69,   70,   71,    0,    0,    0,    2,    0,
    0,    0,    4,    0,    0,    0,    6,    0,    3,    9,
    0,    5,    0,    0,    0,    0,    0,    0,   60,    0,
    0,   28,    0,   27,    0,    0,   11,   14,   15,   16,
   17,   18,   19,   20,    0,   41,    7,    0,   61,    0,
    0,    0,    0,    0,    0,    0,   58,    0,    0,    0,
   57,    0,    0,   55,    0,   40,    0,   10,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   56,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   12,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   59,    0,    0,    0,    0,    0,   49,   50,
   51,   52,   53,   54,   66,   65,   63,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const short yydgoto[] = {                          6,
    7,   35,   12,   19,   16,   17,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   50,   60,   45,   66,   61,
   62,   63,   64,   67,
};
static const short yysindex[] = {                        25,
    0,    0,    0,    0,    0,    0,   25, -253,    0, -223,
  -23, -181,    0,    0, -177, -264,    0, -182,    0,    0,
   30,    0, -182, -144, -137, -126, -182, -121,    0, -120,
 -109,    0,  -15,    0,  -83, -252,    0,    0,    0,    0,
    0,    0,    0,    0,   -2,    0,    0, -245,    0,  -84,
 -182,  -15, -244,  -15,  -15,  -15,    0,  -15,  -15, -203,
    0, -101,    2,    0, -152,    0,  -78,    0, -182,  -15,
  -15,  -15,  -15,  -15,  -15, -182, -182,  -71, -216,  -75,
 -102,   -3,   -1,    0,    1,  -15,  -15,  -15,  -15,  -15,
  -15,  -15,  -15,  -15,  -15,  -15, -169,  -83,    0, -203,
 -203, -203, -203, -203, -203,  -71,  -71, -182,  -15,  -15,
 -182, -182,    0, -101, -101,    2,    2,    2,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -71,    8,   38,
 -265,  -71,  -70,  -15, -182, -182,   10,  -71,  -71, -182,
  -71,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,  218,    0,    0,    0,
    0,    0,    0, -129,    0,    0,    0, -226,    0,    0,
    0,    0, -226,    0,    0,    0,  -43,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -196,    0,    0,    0,    0,    0,
 -256,    0,    0,    0,    0,    0,    0,    0,    0,  -73,
    0,  -79, -147,    0, -197,    0,  -55,    0, -256,    0,
    0,    0,    0,    0,    0, -256, -256, -233,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -49,
  -45,  -39,  -32,  -28,  -22, -232, -231, -256,    0,    0,
 -256, -256,    0,  -72,  -56, -130, -113,  -96,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -208,    0,    0,
 -149, -195,    0,    0, -256, -256,    0, -172, -148, -256,
 -124,
};
static const short yygindex[] = {                       221,
    0,  240,    0,    0,    0,  211,  -20,  168,    0,    0,
    0,    0,    0,    0,    0,    0,  -36,    0,  144,  -18,
   65,  206,  -50,    0,
};
#define YYTABLESIZE 319
static const short yytable[] = {                         46,
   69,   13,   48,   21,   46,   68,   53,   84,   46,   13,
   10,   22,   76,   69,  135,   79,   80,   81,   82,   83,
   69,   69,   85,   13,   22,   21,   23,   22,   21,   23,
   78,   13,   46,  100,  101,  102,  103,  104,  105,   13,
  119,  120,  121,  122,  123,  124,   22,   21,   23,   24,
   46,   11,   24,   86,   87,  106,  107,   46,   46,  108,
   64,   39,   32,   64,   39,   32,   86,   87,   64,   39,
   64,   24,  129,  130,   23,   18,   24,   25,   26,   27,
   28,   29,   64,   39,   32,   31,   20,  128,   31,   46,
  131,  132,   46,   46,  125,  126,   30,  137,   31,   32,
   33,   34,    1,    2,    3,    4,    5,   31,   30,   25,
   48,   30,   25,   48,  138,  139,   46,   46,   48,  141,
   49,   46,   48,   48,   48,   48,   48,   45,   48,   51,
   45,   25,   48,   26,   67,   45,   26,   97,    8,   45,
   45,   45,   45,   45,   46,   45,    8,   46,   52,   45,
  114,  115,   46,   54,   55,   26,   46,   46,   46,   46,
   46,   47,   46,  110,   47,   56,   46,   86,   87,   47,
   88,   89,   90,   47,   47,   47,   47,   47,   44,   47,
   65,   44,   77,   47,   29,   42,   44,   29,   42,   98,
   44,   44,   29,   42,   69,  136,   44,   42,   42,  109,
   44,   43,   62,   42,   43,   62,   29,   42,   33,   43,
   62,   33,   34,   43,   43,   34,   33,    1,   35,   43,
   34,   35,   13,   43,   62,   36,   35,    9,   36,   37,
   33,   47,   37,   36,   34,   38,   99,   37,   38,    8,
   35,  127,    0,   38,    0,    0,    8,   36,   29,   57,
   15,   37,   13,    0,    0,   58,    0,   38,    0,   59,
   15,   14,    2,    3,    4,    5,   86,   87,   86,   87,
   86,   87,  111,    0,  112,    0,  113,   86,   87,   86,
   87,    0,    0,  133,    0,  140,    0,   70,   71,   72,
   73,   74,   75,  116,  117,  118,    0,   91,   92,   93,
   94,   95,   96,  134,    0,    0,    0,   86,   87,    1,
    2,    3,    4,    5,   14,    2,    3,    4,    5,
};
static const short yycheck[] = {                         18,
  266,  258,   23,  268,   23,  258,   27,   58,   27,  266,
  264,  276,  258,  266,  280,   52,  261,   54,   55,   56,
  266,  266,   59,  280,  258,  258,  258,  261,  261,  261,
   51,  258,   51,   70,   71,   72,   73,   74,   75,  266,
   91,   92,   93,   94,   95,   96,  280,  280,  280,  258,
   69,  275,  261,  270,  271,   76,   77,   76,   77,  276,
  258,  258,  258,  261,  261,  261,  270,  271,  266,  266,
  268,  280,  109,  110,  257,  257,  259,  260,  261,  262,
  263,  264,  280,  280,  280,  258,  264,  108,  261,  108,
  111,  112,  111,  112,  264,  265,  279,  134,  281,  282,
  283,  284,  285,  286,  287,  288,  289,  280,  258,  258,
  258,  261,  261,  261,  135,  136,  135,  136,  266,  140,
  265,  140,  270,  271,  272,  273,  274,  258,  276,  267,
  261,  280,  280,  258,  264,  266,  261,  290,  268,  270,
  271,  272,  273,  274,  258,  276,  276,  261,  275,  280,
   86,   87,  266,  275,  275,  280,  270,  271,  272,  273,
  274,  258,  276,  266,  261,  275,  280,  270,  271,  266,
  272,  273,  274,  270,  271,  272,  273,  274,  258,  276,
  264,  261,  267,  280,  258,  258,  266,  261,  261,  268,
  270,  271,  266,  266,  266,  266,  276,  270,  271,  275,
  280,  258,  258,  276,  261,  261,  280,  280,  258,  266,
  266,  261,  258,  270,  271,  261,  266,    0,  258,  276,
  266,  261,  266,  280,  280,  258,  266,    7,  261,  258,
  280,   21,  261,  266,  280,  258,   69,  266,  261,    0,
  280,   98,   -1,  266,   -1,   -1,    7,  280,  264,  265,
   11,  280,  276,   -1,   -1,  271,   -1,  280,   -1,  275,
   21,  285,  286,  287,  288,  289,  270,  271,  270,  271,
  270,  271,  276,   -1,  276,   -1,  276,  270,  271,  270,
  271,   -1,   -1,  276,   -1,  276,   -1,  290,  291,  292,
  293,  294,  295,   88,   89,   90,   -1,  296,  297,  298,
  299,  300,  301,  266,   -1,   -1,   -1,  270,  271,  285,
  286,  287,  288,  289,  285,  286,  287,  288,  289,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 302
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_BRACKET_BEGIN","T_BRACKET_END",
"TCASE","TDEFAULT","TWHILE","TDO","TFOR","TIDENT","TNUMBER","TSEMI","TCOLON",
"TCOMA","TERROR","TPLUS","TMINUS","TMUL","TDIV","TMOD","TLPAREN","TRPAREN",
"TLBRACKET","TRBRACKET","TIF","TELSE","TSWITCH","TBREAK","TRETURN","TCONTINUE",
"TVOID","TINT","TCHAR","TFLOAT","TDOUBLE","TASSIGN","TASPLUS","TASMINUS",
"TASMUL","TASDIV","TASREMAIN","TEQUAL","TNEQUAL","TLESS","TLESSE","TGREAT",
"TGREATE","TEQAUL",
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
"assign_stmt : left_hand_side TASPLUS expression",
"assign_stmt : left_hand_side TASMINUS expression",
"assign_stmt : left_hand_side TASMUL expression",
"assign_stmt : left_hand_side TASDIV expression",
"assign_stmt : left_hand_side TASREMAIN expression",
"assign_stmt : left_hand_side",
"init_stmt : type id",
"left_hand_side : variable",
"expression : expression TPLUS term",
"expression : expression TMINUS term",
"expression : term",
"term : term TMUL relation_expression",
"term : term TDIV relation_expression",
"term : term TMOD relation_expression",
"term : relation_expression",
"relation_expression : relation_expression TEQUAL factor",
"relation_expression : relation_expression TNEQUAL factor",
"relation_expression : relation_expression TLESS factor",
"relation_expression : relation_expression TLESSE factor",
"relation_expression : relation_expression TGREAT factor",
"relation_expression : relation_expression TGREATE factor",
"relation_expression : factor",
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
#line 171 "pascal.y"


main()
{
	yyparse();
}

yyerror(s)
char *s;
{
	fprintf(stderr, "%s\n", s);
}
#line 400 "y.tab.c"

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
#line 26 "pascal.y"
	{ puts("0.1. function"); }
break;
case 2:
#line 27 "pascal.y"
	{ puts("0.2 functions"); }
break;
case 3:
#line 31 "pascal.y"
	{ puts("-1.1 bracket"); }
break;
case 4:
#line 35 "pascal.y"
	{ puts("-1.2 no argument"); }
break;
case 5:
#line 36 "pascal.y"
	{ puts("-1.3 argument"); }
break;
case 6:
#line 40 "pascal.y"
	{ puts("-1.4 one parameter"); }
break;
case 7:
#line 41 "pascal.y"
	{ puts("-1.5 parameters"); }
break;
case 8:
#line 45 "pascal.y"
	{ puts("-1.6 parameter void "); }
break;
case 9:
#line 46 "pascal.y"
	{ puts("-1.7 parameter detail"); }
break;
case 10:
#line 50 "pascal.y"
	{ puts("--2.1 bracket"); }
break;
case 11:
#line 54 "pascal.y"
	{ puts("---3.1. statement"); }
break;
case 12:
#line 55 "pascal.y"
	{ puts("---3.2. statements"); }
break;
case 13:
#line 59 "pascal.y"
	{ puts("----4.1. empty statement"); }
break;
case 14:
#line 60 "pascal.y"
	{ puts("----4.2. assign statement"); }
break;
case 15:
#line 61 "pascal.y"
	{ puts("----4.3. label statement"); }
break;
case 16:
#line 62 "pascal.y"
	{ puts("----4.4. iter statement"); }
break;
case 17:
#line 63 "pascal.y"
	{ puts("----4.5. jump statement"); }
break;
case 18:
#line 64 "pascal.y"
	{ puts("----4.6 selection statement"); }
break;
case 19:
#line 65 "pascal.y"
	{ puts("----4.7 bracket statement"); }
break;
case 20:
#line 66 "pascal.y"
	{ puts("----4.8 init statement"); }
break;
case 21:
#line 70 "pascal.y"
	{ puts("-----5.1 bracket"); }
break;
case 22:
#line 74 "pascal.y"
	{ puts("-----5.2. default"); }
break;
case 23:
#line 75 "pascal.y"
	{ puts("-----5.3. case"); }
break;
case 24:
#line 79 "pascal.y"
	{ puts("-----5.4. while"); }
break;
case 25:
#line 80 "pascal.y"
	{ puts("-----5.5. do while"); }
break;
case 26:
#line 81 "pascal.y"
	{ puts("-----5.6. for");}
break;
case 27:
#line 85 "pascal.y"
	{ puts("-----5.7. continue"); }
break;
case 28:
#line 86 "pascal.y"
	{ puts("-----5.8. break"); }
break;
case 29:
#line 87 "pascal.y"
	{ puts("-----5.9. return"); }
break;
case 30:
#line 91 "pascal.y"
	{ puts("-----5.10 if"); }
break;
case 31:
#line 92 "pascal.y"
	{ puts("-----5.11 if else"); }
break;
case 32:
#line 93 "pascal.y"
	{ puts("-----5.12 if else"); }
break;
case 33:
#line 97 "pascal.y"
	{ puts("-----5.13 TASSIGN"); }
break;
case 34:
#line 98 "pascal.y"
	{ puts("-----5.14 TASPLUS"); }
break;
case 35:
#line 99 "pascal.y"
	{ puts("-----5.15 TASMINUS"); }
break;
case 36:
#line 100 "pascal.y"
	{ puts("-----5.16 TASMUL"); }
break;
case 37:
#line 101 "pascal.y"
	{ puts("-----5.17 TASDIV"); }
break;
case 38:
#line 102 "pascal.y"
	{ puts("-----5.18 TASREMAIN"); }
break;
case 39:
#line 103 "pascal.y"
	{ puts("-----5.19. a;"); }
break;
case 40:
#line 107 "pascal.y"
	{ puts("-----5.20. initial"); }
break;
case 41:
#line 111 "pascal.y"
	{ puts("------6. variable"); }
break;
case 42:
#line 115 "pascal.y"
	{ puts("-------7.1. plus"); }
break;
case 43:
#line 116 "pascal.y"
	{ puts("-------7.2. minus"); }
break;
case 44:
#line 117 "pascal.y"
	{ puts("-------7.3. term"); }
break;
case 45:
#line 121 "pascal.y"
	{ puts("--------8.1. mul"); }
break;
case 46:
#line 122 "pascal.y"
	{ puts("--------8.2. div"); }
break;
case 47:
#line 123 "pascal.y"
	{ puts("--------8.3. mod"); }
break;
case 48:
#line 124 "pascal.y"
	{ puts("--------8.4. relation_expression"); }
break;
case 49:
#line 128 "pascal.y"
	{ puts("--------8.5. TEQUAL"); }
break;
case 50:
#line 129 "pascal.y"
	{ puts("--------8.6. TNEQUAL"); }
break;
case 51:
#line 130 "pascal.y"
	{ puts("--------8.7. TLESS"); }
break;
case 52:
#line 131 "pascal.y"
	{ puts("--------8.8. TLESSE"); }
break;
case 53:
#line 132 "pascal.y"
	{ puts("--------8.9. TGREAT"); }
break;
case 54:
#line 133 "pascal.y"
	{ puts("--------8.10. TGREATE"); }
break;
case 55:
#line 134 "pascal.y"
	{ puts("--------8.11. factor"); }
break;
case 56:
#line 138 "pascal.y"
	{ puts("---------9.1. minus factor"); }
break;
case 57:
#line 139 "pascal.y"
	{ puts("---------9.2. variable"); }
break;
case 58:
#line 140 "pascal.y"
	{ puts("---------9.3. number"); }
break;
case 59:
#line 141 "pascal.y"
	{ puts("---------9.4. ( )"); }
break;
case 60:
#line 145 "pascal.y"
	{ puts("----------10.1. identifier"); }
break;
case 61:
#line 149 "pascal.y"
	{ puts("----------10.2. constant"); }
break;
case 62:
#line 153 "pascal.y"
	{ puts("----------10.3. id"); }
break;
case 63:
#line 154 "pascal.y"
	{ puts("----------10.4. id list"); }
break;
case 64:
#line 158 "pascal.y"
	{ puts("-----------10.5. init_id"); }
break;
case 65:
#line 159 "pascal.y"
	{ puts("-----------10.6. initializer"); }
break;
case 66:
#line 160 "pascal.y"
	{ puts("-----------10.7. init assign"); }
break;
case 67:
#line 164 "pascal.y"
	{ puts("-----------11.1. void"); }
break;
case 68:
#line 165 "pascal.y"
	{ puts("-----------11.2. int"); }
break;
case 69:
#line 166 "pascal.y"
	{ puts("-----------11.3. char"); }
break;
case 70:
#line 167 "pascal.y"
	{ puts("-----------11.4. float"); }
break;
case 71:
#line 168 "pascal.y"
	{ puts("-----------11.5. double"); }
break;
#line 890 "y.tab.c"
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
