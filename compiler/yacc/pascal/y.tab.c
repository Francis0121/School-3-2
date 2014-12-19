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
#define TSTRUCT 259
#define TCASE 260
#define TDEFAULT 261
#define TWHILE 262
#define TDO 263
#define TFOR 264
#define TIDENT 265
#define TNUMBER 266
#define TSEMI 267
#define TCOLON 268
#define TCOMA 269
#define TERROR 270
#define TLPAREN 271
#define TRPAREN 272
#define TLBRACKET 273
#define TRBRACKET 274
#define TIF 275
#define TELSE 276
#define TSWITCH 277
#define TBREAK 278
#define TRETURN 279
#define TCONTINUE 280
#define TVOID 281
#define TINT 282
#define TCHAR 283
#define TFLOAT 284
#define TDOUBLE 285
#define TEQUAL 286
#define TPLUS 287
#define TMINUS 288
#define TMUL 289
#define TDIV 290
#define TMOD 291
#define TEQAUL 292
#define TNEQUAL 293
#define TLESS 294
#define TLESSE 295
#define TGREAT 296
#define TGREATE 297
#define TASSIGN 298
#define TASPLUS 299
#define TASMINUS 300
#define TASMUL 301
#define TASDIV 302
#define TASREMAIN 303
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    1,    4,    4,    6,    6,    7,    7,
    5,    8,    8,    9,    9,    9,    9,    9,    9,    9,
    9,   15,   11,   11,   12,   12,   12,   13,   13,   13,
   14,   14,   14,   10,   10,   10,   10,   10,   10,   10,
   16,   19,   18,   18,   18,   22,   22,   22,   22,   23,
   23,   23,   23,   23,   23,   23,   24,   24,   24,   24,
   21,   17,   20,   20,   25,   25,   25,    3,    3,    3,
    3,    3,   27,    2,   26,   26,   28,
};
static const short yylen[] = {                            2,
    1,    2,    2,    4,    2,    3,    1,    3,    1,    2,
    3,    1,    3,    0,    1,    1,    1,    1,    1,    1,
    1,    4,    3,    4,    5,    8,    9,    1,    1,    2,
    5,    7,    5,    3,    3,    3,    3,    3,    3,    1,
    2,    1,    3,    3,    1,    3,    3,    3,    1,    3,
    3,    3,    3,    3,    3,    1,    2,    1,    1,    3,
    1,    1,    1,    3,    1,    3,    3,    1,    1,    1,
    1,    1,    0,    7,    2,    1,    3,
};
static const short yydefred[] = {                         0,
    0,   68,   69,   70,   71,   72,    0,    0,    0,    0,
    0,    3,    2,    0,    0,    0,    0,    0,    0,   76,
    5,    0,    0,    0,    7,    0,    4,    0,   73,   75,
   10,    0,    6,    0,    0,    0,    0,    0,    0,   61,
    0,    0,   29,    0,   28,    0,    0,   12,   15,   16,
   17,   18,   19,   20,   21,    0,   42,   77,    0,    8,
    0,   62,    0,    0,    0,    0,    0,    0,    0,   59,
    0,    0,    0,   58,    0,    0,   56,    0,   41,    0,
   11,    0,    0,    0,    0,    0,    0,    0,   74,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   57,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   13,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   60,    0,    0,    0,
    0,    0,   50,   51,   52,   53,   54,   55,   67,   66,
   64,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yydgoto[] = {                          7,
    8,    9,   46,   17,   27,   24,   25,   47,   48,   49,
   50,   51,   52,   53,   54,   55,   63,   73,   56,   79,
   74,   75,   76,   77,   80,   19,   59,   20,
};
static const short yysindex[] = {                       -61,
 -250,    0,    0,    0,    0,    0,    0,  -61,  -61, -244,
 -174,    0,    0, -262,   13,   20, -170, -184, -256,    0,
    0,    0, -139, -132,    0,  -46,    0, -198,    0,    0,
    0,   45,    0,  -46, -181, -108, -102,  -46,  -69,    0,
  -68,  -63,    0, -218,    0, -111, -248,    0,    0,    0,
    0,    0,    0,    0,    0,   22,    0,    0, -119,    0,
 -212,    0, -105,  -46, -218, -153, -218, -218, -218,    0,
 -218, -218, -180,    0,  -35,   21,    0, -110,    0,  -79,
    0,  -46, -218, -218, -218, -218, -218, -218,    0,  -46,
  -46,  -58, -126,  -44, -264,  -62,   -2,    1,    0, -218,
 -218, -218, -218, -218, -218, -218, -218, -218, -218, -218,
 -114, -111,    0, -180, -180, -180, -180, -180, -180,  -58,
  -58,  -46, -218, -218,  -46,  -46,    0,  -35,  -35,   21,
   21,   21,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -58,    3, -237, -188,  -58,  -39, -218,  -46,  -46,
   12,  -58,  -58,  -46,  -58,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,  230,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   41,    0,    0,    0, -176,    0,    0,    0,    0,
    0,    0,    0, -176,    0,    0,    0,  -19,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -172,    0,    0,    0,    0,
    0,    0,    0, -254,    0,    0,    0,    0,    0,    0,
    0,    0, -164,    0,  -83, -213,    0, -156,    0, -140,
    0, -254,    0,    0,    0,    0,    0,    0,    0, -254,
 -254, -196,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -120,  -82,  -18,  -17,  -16,  -15, -133,
  -80, -254,    0,    0, -254, -254,    0,  -81,  -75, -157,
 -123, -117,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   -5,    0,    0, -251,    4,    0,    0, -254, -254,
    0,    5,    6, -254,    7,
};
static const short yygindex[] = {                       149,
    0,    0,   52,    0,    0,    0,  240,  -33,  192,    0,
    0,    0,    0,    0,    0,    0,    0,  -51,    0,  167,
  -26,   99,  174,  -66,    0,    0,    0,  268,
};
#define YYTABLESIZE 330
static const short yytable[] = {                         57,
   61,   29,  124,   14,   66,   99,   31,   57,   16,   81,
   31,   57,   14,   93,   11,   95,   96,   97,   82,   98,
   14,   14,  100,  101,    2,    3,    4,    5,    6,  148,
   92,  114,  115,  116,  117,  118,  119,   57,  133,  134,
  135,  136,  137,  138,   49,   90,   40,   70,   49,  100,
  101,   10,   71,   49,   82,   57,  120,  121,   49,   10,
   10,   23,   49,   57,   57,   23,   18,   23,   58,   72,
   18,  143,  144,   49,   49,   49,   49,   49,   82,   23,
   28,   14,   15,   23,   62,   40,   26,  149,  142,   40,
   14,  145,  146,   30,   40,   57,  151,   30,   57,   57,
   46,   65,   30,   40,   46,   65,  100,  101,   94,   46,
   65,   30,   65,   82,   46,  152,  153,   63,   46,   65,
  155,   63,   57,   57,   22,   31,   63,   57,   22,   46,
   46,   46,   46,   46,   47,   63,   32,   34,   47,   33,
   48,   34,   22,   47,   48,  122,   34,   89,   47,   48,
  139,  140,   47,   78,   48,   34,   12,   13,   48,   64,
  100,  101,   91,   47,   47,   47,   47,   47,   65,   48,
   48,   48,   48,   48,   45,   35,   43,   24,   45,   35,
   43,   24,   44,   45,   35,   43,   44,  111,   45,  112,
   43,   44,   45,   35,   43,   24,   44,    1,  128,  129,
   44,   67,   68,   45,   45,   43,   43,   69,   82,  125,
   34,   44,   44,   35,   36,   37,   38,   39,   40,    2,
    3,    4,    5,    6,  100,  101,  123,  150,   41,    1,
   42,   43,   44,   45,    2,    3,    4,    5,    6,   36,
   37,   38,   39,   36,   37,   38,   39,   14,   36,   37,
   38,   39,   25,  102,  103,  104,   25,   36,   37,   38,
   39,   33,   32,   26,   27,   33,   32,   26,   27,  126,
   25,   60,  127,  113,  147,  130,  131,  132,  141,   33,
   32,   26,   27,  154,  100,  101,   30,  100,  101,  100,
  101,   21,    0,    2,    3,    4,    5,    6,  100,  101,
   22,    3,    4,    5,    6,   68,  105,    0,    0,    9,
    0,    0,    9,  106,  107,  108,  109,  110,    0,   83,
   84,   85,   86,   87,   88,   22,    3,    4,    5,    6,
};
static const short yycheck[] = {                         26,
   34,  258,  267,  258,   38,   72,  258,   34,  271,  258,
  262,   38,  267,   65,  265,   67,   68,   69,  267,   71,
  265,  276,  287,  288,  281,  282,  283,  284,  285,  267,
   64,   83,   84,   85,   86,   87,   88,   64,  105,  106,
  107,  108,  109,  110,  258,  258,  265,  266,  262,  287,
  288,    0,  271,  267,  267,   82,   90,   91,  272,    8,
    9,  258,  276,   90,   91,  262,   15,   16,  267,  288,
   19,  123,  124,  287,  288,  289,  290,  291,  267,  276,
  265,  258,  257,   32,  266,  258,  257,  276,  122,  262,
  267,  125,  126,  258,  267,  122,  148,  262,  125,  126,
  258,  258,  267,  276,  262,  262,  287,  288,  262,  267,
  267,  276,  269,  267,  272,  149,  150,  258,  276,  276,
  154,  262,  149,  150,  258,  265,  267,  154,  262,  287,
  288,  289,  290,  291,  258,  276,  269,  258,  262,  272,
  258,  262,  276,  267,  262,  272,  267,  267,  272,  267,
  265,  266,  276,  265,  272,  276,    8,    9,  276,  268,
  287,  288,  268,  287,  288,  289,  290,  291,  271,  287,
  288,  289,  290,  291,  258,  258,  258,  258,  262,  262,
  262,  262,  258,  267,  267,  267,  262,  298,  272,  269,
  272,  267,  276,  276,  276,  276,  272,  259,  100,  101,
  276,  271,  271,  287,  288,  287,  288,  271,  267,  272,
  257,  287,  288,  260,  261,  262,  263,  264,  265,  281,
  282,  283,  284,  285,  287,  288,  271,  267,  275,    0,
  277,  278,  279,  280,  281,  282,  283,  284,  285,  258,
  258,  258,  258,  262,  262,  262,  262,  267,  267,  267,
  267,  267,  258,  289,  290,  291,  262,  276,  276,  276,
  276,  258,  258,  258,  258,  262,  262,  262,  262,  272,
  276,   32,  272,   82,  272,  102,  103,  104,  112,  276,
  276,  276,  276,  272,  287,  288,   19,  287,  288,  287,
  288,  272,   -1,  281,  282,  283,  284,  285,  287,  288,
  281,  282,  283,  284,  285,  265,  286,   -1,   -1,  269,
   -1,   -1,  272,  293,  294,  295,  296,  297,   -1,  298,
  299,  300,  301,  302,  303,  281,  282,  283,  284,  285,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 303
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_BRACKET_BEGIN","T_BRACKET_END",
"TSTRUCT","TCASE","TDEFAULT","TWHILE","TDO","TFOR","TIDENT","TNUMBER","TSEMI",
"TCOLON","TCOMA","TERROR","TLPAREN","TRPAREN","TLBRACKET","TRBRACKET","TIF",
"TELSE","TSWITCH","TBREAK","TRETURN","TCONTINUE","TVOID","TINT","TCHAR",
"TFLOAT","TDOUBLE","TEQUAL","TPLUS","TMINUS","TMUL","TDIV","TMOD","TEQAUL",
"TNEQUAL","TLESS","TLESSE","TGREAT","TGREATE","TASSIGN","TASPLUS","TASMINUS",
"TASMUL","TASDIV","TASREMAIN",
};
static const char *yyrule[] = {
"$accept : start_symbol",
"start_symbol : func",
"start_symbol : struct start_symbol",
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
"$$1 :",
"struct : TSTRUCT TIDENT T_BRACKET_BEGIN struct_declare_list T_BRACKET_END $$1 TSEMI",
"struct_declare_list : struct_declare_list struct_declare",
"struct_declare_list : struct_declare",
"struct_declare : type TIDENT TSEMI",

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
#line 185 "pascal.y"


main()
{
	yyparse();
}

yyerror(s)
char *s;
{
	fprintf(stderr, "%s\n", s);
}
#line 412 "y.tab.c"

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
	{ puts("0.1 function"); }
break;
case 2:
#line 27 "pascal.y"
	{ puts("0.2 struct"); }
break;
case 3:
#line 28 "pascal.y"
	{ puts("0.3 functions"); }
break;
case 4:
#line 32 "pascal.y"
	{ puts("-1.1 bracket"); }
break;
case 5:
#line 36 "pascal.y"
	{ puts("-1.2 no argument"); }
break;
case 6:
#line 37 "pascal.y"
	{ puts("-1.3 argument"); }
break;
case 7:
#line 41 "pascal.y"
	{ puts("-1.4 one parameter"); }
break;
case 8:
#line 42 "pascal.y"
	{ puts("-1.5 parameters"); }
break;
case 9:
#line 46 "pascal.y"
	{ puts("-1.6 parameter void "); }
break;
case 10:
#line 47 "pascal.y"
	{ puts("-1.7 parameter detail"); }
break;
case 11:
#line 51 "pascal.y"
	{ puts("--2.1 bracket"); }
break;
case 12:
#line 55 "pascal.y"
	{ puts("---3.1. statement"); }
break;
case 13:
#line 56 "pascal.y"
	{ puts("---3.2. statements"); }
break;
case 14:
#line 60 "pascal.y"
	{ puts("----4.1. empty statement"); }
break;
case 15:
#line 61 "pascal.y"
	{ puts("----4.2. assign statement"); }
break;
case 16:
#line 62 "pascal.y"
	{ puts("----4.3. label statement"); }
break;
case 17:
#line 63 "pascal.y"
	{ puts("----4.4. iter statement"); }
break;
case 18:
#line 64 "pascal.y"
	{ puts("----4.5. jump statement"); }
break;
case 19:
#line 65 "pascal.y"
	{ puts("----4.6 selection statement"); }
break;
case 20:
#line 66 "pascal.y"
	{ puts("----4.7 bracket statement"); }
break;
case 21:
#line 67 "pascal.y"
	{ puts("----4.8 init statement"); }
break;
case 22:
#line 71 "pascal.y"
	{ puts("-----5.1 bracket"); }
break;
case 23:
#line 75 "pascal.y"
	{ puts("-----5.2. default"); }
break;
case 24:
#line 76 "pascal.y"
	{ puts("-----5.3. case"); }
break;
case 25:
#line 80 "pascal.y"
	{ puts("-----5.4. while"); }
break;
case 26:
#line 81 "pascal.y"
	{ puts("-----5.5. do while"); }
break;
case 27:
#line 82 "pascal.y"
	{ puts("-----5.6. for");}
break;
case 28:
#line 86 "pascal.y"
	{ puts("-----5.7. continue"); }
break;
case 29:
#line 87 "pascal.y"
	{ puts("-----5.8. break"); }
break;
case 30:
#line 88 "pascal.y"
	{ puts("-----5.9. return"); }
break;
case 31:
#line 92 "pascal.y"
	{ puts("-----5.10 if"); }
break;
case 32:
#line 93 "pascal.y"
	{ puts("-----5.11 if else"); }
break;
case 33:
#line 94 "pascal.y"
	{ puts("-----5.12 if else"); }
break;
case 34:
#line 98 "pascal.y"
	{ puts("-----5.13 TASSIGN"); }
break;
case 35:
#line 99 "pascal.y"
	{ puts("-----5.14 TASPLUS"); }
break;
case 36:
#line 100 "pascal.y"
	{ puts("-----5.15 TASMINUS"); }
break;
case 37:
#line 101 "pascal.y"
	{ puts("-----5.16 TASMUL"); }
break;
case 38:
#line 102 "pascal.y"
	{ puts("-----5.17 TASDIV"); }
break;
case 39:
#line 103 "pascal.y"
	{ puts("-----5.18 TASREMAIN"); }
break;
case 40:
#line 104 "pascal.y"
	{ puts("-----5.19. a;"); }
break;
case 41:
#line 108 "pascal.y"
	{ puts("-----5.20. initial"); }
break;
case 42:
#line 112 "pascal.y"
	{ puts("------6. variable"); }
break;
case 43:
#line 116 "pascal.y"
	{ puts("-------7.1. plus"); }
break;
case 44:
#line 117 "pascal.y"
	{ puts("-------7.2. minus"); }
break;
case 45:
#line 118 "pascal.y"
	{ puts("-------7.3. term"); }
break;
case 46:
#line 122 "pascal.y"
	{ puts("--------8.1. mul"); }
break;
case 47:
#line 123 "pascal.y"
	{ puts("--------8.2. div"); }
break;
case 48:
#line 124 "pascal.y"
	{ puts("--------8.3. mod"); }
break;
case 49:
#line 125 "pascal.y"
	{ puts("--------8.4. relation_expression"); }
break;
case 50:
#line 129 "pascal.y"
	{ puts("--------8.5. TEQUAL"); }
break;
case 51:
#line 130 "pascal.y"
	{ puts("--------8.6. TNEQUAL"); }
break;
case 52:
#line 131 "pascal.y"
	{ puts("--------8.7. TLESS"); }
break;
case 53:
#line 132 "pascal.y"
	{ puts("--------8.8. TLESSE"); }
break;
case 54:
#line 133 "pascal.y"
	{ puts("--------8.9. TGREAT"); }
break;
case 55:
#line 134 "pascal.y"
	{ puts("--------8.10. TGREATE"); }
break;
case 56:
#line 135 "pascal.y"
	{ puts("--------8.11. factor"); }
break;
case 57:
#line 139 "pascal.y"
	{ puts("---------9.1. minus factor"); }
break;
case 58:
#line 140 "pascal.y"
	{ puts("---------9.2. variable"); }
break;
case 59:
#line 141 "pascal.y"
	{ puts("---------9.3. number"); }
break;
case 60:
#line 142 "pascal.y"
	{ puts("---------9.4. ( )"); }
break;
case 61:
#line 146 "pascal.y"
	{ puts("----------10.1. identifier"); }
break;
case 62:
#line 150 "pascal.y"
	{ puts("----------10.2. constant"); }
break;
case 63:
#line 154 "pascal.y"
	{ puts("----------10.3. id"); }
break;
case 64:
#line 155 "pascal.y"
	{ puts("----------10.4. id list"); }
break;
case 65:
#line 159 "pascal.y"
	{ puts("-----------10.5. init_id"); }
break;
case 66:
#line 160 "pascal.y"
	{ puts("-----------10.6. initializer"); }
break;
case 67:
#line 161 "pascal.y"
	{ puts("-----------10.7. init assign"); }
break;
case 68:
#line 165 "pascal.y"
	{ puts("-----------11.1. void"); }
break;
case 69:
#line 166 "pascal.y"
	{ puts("-----------11.2. int"); }
break;
case 70:
#line 167 "pascal.y"
	{ puts("-----------11.3. char"); }
break;
case 71:
#line 168 "pascal.y"
	{ puts("-----------11.4. float"); }
break;
case 72:
#line 169 "pascal.y"
	{ puts("-----------11.5. double"); }
break;
case 73:
#line 173 "pascal.y"
	{ puts("------------12.1"); }
break;
case 75:
#line 177 "pascal.y"
	{ puts("------------12.2"); }
break;
case 76:
#line 178 "pascal.y"
	{ puts("------------12.3"); }
break;
case 77:
#line 182 "pascal.y"
	{ puts("------------12.4"); }
break;
#line 922 "y.tab.c"
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
