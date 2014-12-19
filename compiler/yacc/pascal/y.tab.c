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
#define NUMBER 265
#define FLOAT 266
#define DOUBLE 267
#define HEXA 268
#define TIDENT 269
#define TSEMI 270
#define TCOLON 271
#define TCOMA 272
#define TERROR 273
#define TLPAREN 274
#define TRPAREN 275
#define TLBRACKET 276
#define TRBRACKET 277
#define TIF 278
#define TELSE 279
#define TSWITCH 280
#define TBREAK 281
#define TRETURN 282
#define TCONTINUE 283
#define TVOID 284
#define TINT 285
#define TCHAR 286
#define TFLOAT 287
#define TDOUBLE 288
#define TEQUAL 289
#define TPLUS 290
#define TMINUS 291
#define TMUL 292
#define TDIV 293
#define TMOD 294
#define TEQAUL 295
#define TNEQUAL 296
#define TLESS 297
#define TLESSE 298
#define TGREAT 299
#define TGREATE 300
#define TASSIGN 301
#define TASPLUS 302
#define TASMINUS 303
#define TASMUL 304
#define TASDIV 305
#define TASREMAIN 306
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    1,    4,    4,    6,    6,    7,    7,
    5,    8,    8,    9,    9,    9,    9,    9,    9,    9,
    9,   15,   11,   11,   12,   12,   12,   13,   13,   13,
   14,   14,   14,   10,   10,   10,   10,   10,   10,   10,
   16,   19,   18,   18,   18,   22,   22,   22,   22,   23,
   23,   23,   23,   23,   23,   23,   24,   24,   24,   24,
   24,   24,   24,   21,   17,   20,   20,   25,   25,   25,
   25,   25,   25,    3,    3,    3,    3,    3,   27,    2,
   26,   26,   28,
};
static const short yylen[] = {                            2,
    1,    2,    2,    4,    2,    3,    1,    3,    1,    2,
    3,    1,    3,    0,    1,    1,    1,    1,    1,    1,
    1,    4,    3,    4,    5,    8,    9,    1,    1,    2,
    5,    7,    5,    3,    3,    3,    3,    3,    3,    1,
    2,    1,    3,    3,    1,    3,    3,    3,    1,    3,
    3,    3,    3,    3,    3,    1,    2,    1,    1,    1,
    1,    1,    3,    1,    1,    1,    3,    1,    3,    3,
    3,    3,    3,    1,    1,    1,    1,    1,    0,    7,
    2,    1,    3,
};
static const short yydefred[] = {                         0,
    0,   74,   75,   76,   77,   78,    0,    0,    0,    0,
    0,    3,    2,    0,    0,    0,    0,    0,    0,   82,
    5,    0,    0,    0,    7,    0,    4,    0,   79,   81,
   10,    0,    6,    0,    0,    0,    0,    0,    0,   64,
    0,    0,   29,    0,   28,    0,    0,   12,   15,   16,
   17,   18,   19,   20,   21,    0,   42,   83,    0,    8,
    0,   65,    0,    0,    0,    0,    0,    0,    0,   59,
   60,   61,   62,    0,    0,    0,   58,    0,    0,   56,
    0,   41,    0,   11,    0,    0,    0,    0,    0,    0,
    0,   80,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   57,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   63,
    0,    0,    0,    0,    0,   50,   51,   52,   53,   54,
   55,   69,   70,   71,   72,   73,   67,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const short yydgoto[] = {                          7,
    8,    9,   46,   17,   27,   24,   25,   47,   48,   49,
   50,   51,   52,   53,   54,   55,   63,   76,   56,   82,
   77,   78,   79,   80,   83,   19,   59,   20,
};
static const short yysindex[] = {                      -175,
 -259,    0,    0,    0,    0,    0,    0, -175, -175, -221,
 -188,    0,    0, -198,    9,   23, -164, -145, -234,    0,
    0,    0, -127, -118,    0,  -57,    0, -155,    0,    0,
    0,   41,    0,  -57, -183, -119, -110,  -57,  -94,    0,
  -85,  -78,    0,  -32,    0, -113, -249,    0,    0,    0,
    0,    0,    0,    0,    0,   18,    0,    0,  -76,    0,
 -241,    0,  -63,  -57,  -32, -187,  -32,  -32,  -32,    0,
    0,    0,    0,  -32,  -32, -171,    0, -133,   17,    0,
  -79,    0,  -34,    0,  -57,  -32,  -32,  -32,  -32,  -32,
  -32,    0,  -57,  -57,  -29, -272,  -20, -268, -158, -147,
  -43,    0,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
  -32,  -32,  -32,   65, -113,    0, -171, -171, -171, -171,
 -171, -171,  -29,  -29,  -57,  -32,  -32,  -57,  -57,    0,
 -133, -133,   17,   17,   17,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -29,   -3, -263,
 -214,  -29,  -15,  -32,  -57,  -57,   14,  -29,  -29,  -57,
  -29,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,  256,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -181,    0,    0,    0, -212,    0,    0,    0,    0,
    0,    0,    0, -212,    0,    0,    0,   -8,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -173,    0,    0,    0,    0,
    0,    0,    0, -254,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -172,    0, -107, -213,    0,
  -19,    0,  -91,    0, -254,    0,    0,    0,    0,    0,
    0,    0, -254, -254, -232,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -61,  -18,  -13,  -12,
    6,    7,  -93,  -92, -254,    0,    0, -254, -254,    0,
  -80,  -77, -154, -144, -117,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   12,    0,    0,
 -157,   13,    0,    0, -254, -254,    0,   20,   21, -254,
   22,
};
static const short yygindex[] = {                       183,
    0,    0,   55,    0,    0,    0,  231,  -33,  188,    0,
    0,    0,    0,    0,    0,    0,    0,  -54,    0,  166,
  -26,  116,  110,  -69,    0,    0,    0,  271,
};
#define YYTABLESIZE 334
static const short yytable[] = {                         57,
   61,  127,  125,   14,   66,  102,  154,   57,   84,   11,
   96,   57,   98,   99,  100,   14,   93,  103,  104,  101,
   85,  103,  104,   29,   14,   23,  103,  104,   85,   23,
   95,  117,  118,  119,  120,  121,  122,   57,  136,  137,
  138,  139,  140,  141,   49,   14,   23,   14,   49,    2,
    3,    4,    5,    6,   10,   85,   49,   14,   57,  123,
  124,   49,   10,   10,  155,   49,   57,   57,   15,   18,
   23,  149,  150,   18,   97,   16,   49,   49,   49,   49,
   49,   62,   85,    1,   40,   30,   23,   74,   40,   30,
    9,  148,   26,    9,  151,  152,   40,   30,   57,  157,
   31,   57,   57,   46,   31,   40,   30,   46,    2,    3,
    4,    5,    6,   47,   58,   46,  128,   47,  103,  104,
   46,  158,  159,   28,   46,   47,  161,  129,   57,   57,
   47,  103,  104,   57,   47,   46,   46,   46,   46,   46,
   48,   31,  103,  104,   48,   47,   47,   47,   47,   47,
   45,   64,   48,   32,   45,   81,   33,   48,  105,  106,
  107,   48,   45,   65,   22,   24,   66,   45,   22,   24,
   66,   45,   48,   48,   48,   48,   48,   43,   66,   67,
   44,   43,   45,   45,   44,   22,   24,   66,   68,   43,
   12,   13,   44,   92,   43,   69,   34,   44,   43,   34,
   34,   44,   35,   36,   37,   38,   39,   94,   34,   43,
   43,   40,   44,   44,  133,  134,  135,   34,  131,  132,
   41,  114,   42,   43,   44,   45,    2,    3,    4,    5,
    6,  130,   70,   71,   72,   73,   40,  115,   68,   35,
   85,   74,   68,   35,   36,   37,  103,  104,   36,   37,
   68,   35,   68,  126,  156,    1,   36,   37,   75,   68,
   35,   14,   60,   38,   39,   36,   37,   38,   39,   25,
   33,  153,  116,   25,   33,   38,   39,   32,   26,   27,
  147,   32,   26,   27,   38,   39,  103,  104,  160,   30,
   25,   33,    2,    3,    4,    5,    6,   21,   32,   26,
   27,    0,    0,  103,  104,  108,   22,    3,    4,    5,
    6,    0,  109,  110,  111,  112,  113,    0,   86,   87,
   88,   89,   90,   91,   22,    3,    4,    5,    6,  142,
  143,  144,  145,  146,
};
static const short yycheck[] = {                         26,
   34,  270,  275,  258,   38,   75,  270,   34,  258,  269,
   65,   38,   67,   68,   69,  270,  258,  290,  291,   74,
  270,  290,  291,  258,  279,  258,  290,  291,  270,  262,
   64,   86,   87,   88,   89,   90,   91,   64,  108,  109,
  110,  111,  112,  113,  258,  258,  279,  269,  262,  284,
  285,  286,  287,  288,    0,  270,  270,  270,   85,   93,
   94,  275,    8,    9,  279,  279,   93,   94,  257,   15,
   16,  126,  127,   19,  262,  274,  290,  291,  292,  293,
  294,  265,  270,  259,  258,  258,   32,  269,  262,  262,
  272,  125,  257,  275,  128,  129,  270,  270,  125,  154,
  258,  128,  129,  258,  262,  279,  279,  262,  284,  285,
  286,  287,  288,  258,  270,  270,  275,  262,  290,  291,
  275,  155,  156,  269,  279,  270,  160,  275,  155,  156,
  275,  290,  291,  160,  279,  290,  291,  292,  293,  294,
  258,  269,  290,  291,  262,  290,  291,  292,  293,  294,
  258,  271,  270,  272,  262,  269,  275,  275,  292,  293,
  294,  279,  270,  274,  258,  258,  258,  275,  262,  262,
  262,  279,  290,  291,  292,  293,  294,  258,  270,  274,
  258,  262,  290,  291,  262,  279,  279,  279,  274,  270,
    8,    9,  270,  270,  275,  274,  258,  275,  279,  257,
  262,  279,  260,  261,  262,  263,  264,  271,  270,  290,
  291,  269,  290,  291,  105,  106,  107,  279,  103,  104,
  278,  301,  280,  281,  282,  283,  284,  285,  286,  287,
  288,  275,  265,  266,  267,  268,  269,  272,  258,  258,
  270,  274,  262,  262,  258,  258,  290,  291,  262,  262,
  270,  270,  272,  274,  270,    0,  270,  270,  291,  279,
  279,  270,   32,  258,  258,  279,  279,  262,  262,  258,
  258,  275,   85,  262,  262,  270,  270,  258,  258,  258,
  115,  262,  262,  262,  279,  279,  290,  291,  275,   19,
  279,  279,  284,  285,  286,  287,  288,  275,  279,  279,
  279,   -1,   -1,  290,  291,  289,  284,  285,  286,  287,
  288,   -1,  296,  297,  298,  299,  300,   -1,  301,  302,
  303,  304,  305,  306,  284,  285,  286,  287,  288,  265,
  266,  267,  268,  269,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_BRACKET_BEGIN","T_BRACKET_END",
"TSTRUCT","TCASE","TDEFAULT","TWHILE","TDO","TFOR","NUMBER","FLOAT","DOUBLE",
"HEXA","TIDENT","TSEMI","TCOLON","TCOMA","TERROR","TLPAREN","TRPAREN",
"TLBRACKET","TRBRACKET","TIF","TELSE","TSWITCH","TBREAK","TRETURN","TCONTINUE",
"TVOID","TINT","TCHAR","TFLOAT","TDOUBLE","TEQUAL","TPLUS","TMINUS","TMUL",
"TDIV","TMOD","TEQAUL","TNEQUAL","TLESS","TLESSE","TGREAT","TGREATE","TASSIGN",
"TASPLUS","TASMINUS","TASMUL","TASDIV","TASREMAIN",
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
"factor : NUMBER",
"factor : FLOAT",
"factor : DOUBLE",
"factor : HEXA",
"factor : TLPAREN expression TRPAREN",
"variable : TIDENT",
"constant : NUMBER",
"id : init_id",
"id : init_id TCOMA id",
"init_id : TIDENT",
"init_id : TIDENT TASSIGN NUMBER",
"init_id : TIDENT TASSIGN FLOAT",
"init_id : TIDENT TASSIGN DOUBLE",
"init_id : TIDENT TASSIGN HEXA",
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
#line 192 "pascal.y"


main()
{
	yyparse();
}

yyerror(s)
char *s;
{
	fprintf(stderr, "%s\n", s);
}
#line 428 "y.tab.c"

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
#line 27 "pascal.y"
	{ puts("0.1 function"); }
break;
case 2:
#line 28 "pascal.y"
	{ puts("0.2 struct"); }
break;
case 3:
#line 29 "pascal.y"
	{ puts("0.3 functions"); }
break;
case 4:
#line 33 "pascal.y"
	{ puts("-1.1 bracket"); }
break;
case 5:
#line 37 "pascal.y"
	{ puts("-1.2 no argument"); }
break;
case 6:
#line 38 "pascal.y"
	{ puts("-1.3 argument"); }
break;
case 7:
#line 42 "pascal.y"
	{ puts("-1.4 one parameter"); }
break;
case 8:
#line 43 "pascal.y"
	{ puts("-1.5 parameters"); }
break;
case 9:
#line 47 "pascal.y"
	{ puts("-1.6 parameter void "); }
break;
case 10:
#line 48 "pascal.y"
	{ puts("-1.7 parameter detail"); }
break;
case 11:
#line 52 "pascal.y"
	{ puts("--2.1 bracket"); }
break;
case 12:
#line 56 "pascal.y"
	{ puts("---3.1. statement"); }
break;
case 13:
#line 57 "pascal.y"
	{ puts("---3.2. statements"); }
break;
case 14:
#line 61 "pascal.y"
	{ puts("----4.1. empty statement"); }
break;
case 15:
#line 62 "pascal.y"
	{ puts("----4.2. assign statement"); }
break;
case 16:
#line 63 "pascal.y"
	{ puts("----4.3. label statement"); }
break;
case 17:
#line 64 "pascal.y"
	{ puts("----4.4. iter statement"); }
break;
case 18:
#line 65 "pascal.y"
	{ puts("----4.5. jump statement"); }
break;
case 19:
#line 66 "pascal.y"
	{ puts("----4.6 selection statement"); }
break;
case 20:
#line 67 "pascal.y"
	{ puts("----4.7 bracket statement"); }
break;
case 21:
#line 68 "pascal.y"
	{ puts("----4.8 init statement"); }
break;
case 22:
#line 72 "pascal.y"
	{ puts("-----5.1 bracket"); }
break;
case 23:
#line 76 "pascal.y"
	{ puts("-----5.2. default"); }
break;
case 24:
#line 77 "pascal.y"
	{ puts("-----5.3. case"); }
break;
case 25:
#line 81 "pascal.y"
	{ puts("-----5.4. while"); }
break;
case 26:
#line 82 "pascal.y"
	{ puts("-----5.5. do while"); }
break;
case 27:
#line 83 "pascal.y"
	{ puts("-----5.6. for");}
break;
case 28:
#line 87 "pascal.y"
	{ puts("-----5.7. continue"); }
break;
case 29:
#line 88 "pascal.y"
	{ puts("-----5.8. break"); }
break;
case 30:
#line 89 "pascal.y"
	{ puts("-----5.9. return"); }
break;
case 31:
#line 93 "pascal.y"
	{ puts("-----5.10 if"); }
break;
case 32:
#line 94 "pascal.y"
	{ puts("-----5.11 if else"); }
break;
case 33:
#line 95 "pascal.y"
	{ puts("-----5.12 if else"); }
break;
case 34:
#line 99 "pascal.y"
	{ puts("-----5.13 TASSIGN"); }
break;
case 35:
#line 100 "pascal.y"
	{ puts("-----5.14 TASPLUS"); }
break;
case 36:
#line 101 "pascal.y"
	{ puts("-----5.15 TASMINUS"); }
break;
case 37:
#line 102 "pascal.y"
	{ puts("-----5.16 TASMUL"); }
break;
case 38:
#line 103 "pascal.y"
	{ puts("-----5.17 TASDIV"); }
break;
case 39:
#line 104 "pascal.y"
	{ puts("-----5.18 TASREMAIN"); }
break;
case 40:
#line 105 "pascal.y"
	{ puts("-----5.19. a;"); }
break;
case 41:
#line 109 "pascal.y"
	{ puts("-----5.20. initial"); }
break;
case 42:
#line 113 "pascal.y"
	{ puts("------6. variable"); }
break;
case 43:
#line 117 "pascal.y"
	{ puts("-------7.1. plus"); }
break;
case 44:
#line 118 "pascal.y"
	{ puts("-------7.2. minus"); }
break;
case 45:
#line 119 "pascal.y"
	{ puts("-------7.3. term"); }
break;
case 46:
#line 123 "pascal.y"
	{ puts("--------8.1. mul"); }
break;
case 47:
#line 124 "pascal.y"
	{ puts("--------8.2. div"); }
break;
case 48:
#line 125 "pascal.y"
	{ puts("--------8.3. mod"); }
break;
case 49:
#line 126 "pascal.y"
	{ puts("--------8.4. relation_expression"); }
break;
case 50:
#line 130 "pascal.y"
	{ puts("--------8.5. TEQUAL"); }
break;
case 51:
#line 131 "pascal.y"
	{ puts("--------8.6. TNEQUAL"); }
break;
case 52:
#line 132 "pascal.y"
	{ puts("--------8.7. TLESS"); }
break;
case 53:
#line 133 "pascal.y"
	{ puts("--------8.8. TLESSE"); }
break;
case 54:
#line 134 "pascal.y"
	{ puts("--------8.9. TGREAT"); }
break;
case 55:
#line 135 "pascal.y"
	{ puts("--------8.10. TGREATE"); }
break;
case 56:
#line 136 "pascal.y"
	{ puts("--------8.11. factor"); }
break;
case 57:
#line 140 "pascal.y"
	{ puts("---------9.1. minus factor"); }
break;
case 58:
#line 141 "pascal.y"
	{ puts("---------9.2. variable"); }
break;
case 59:
#line 142 "pascal.y"
	{ puts("---------9.3. number"); }
break;
case 60:
#line 143 "pascal.y"
	{ puts("---------9.4. float");  }
break;
case 61:
#line 144 "pascal.y"
	{ puts("---------9.5. double");  }
break;
case 62:
#line 145 "pascal.y"
	{ puts("---------9.6. hexa");  }
break;
case 63:
#line 146 "pascal.y"
	{ puts("---------9.7. ( )"); }
break;
case 64:
#line 150 "pascal.y"
	{ puts("----------10.1. identifier"); }
break;
case 65:
#line 154 "pascal.y"
	{ puts("----------10.2. constant"); }
break;
case 66:
#line 158 "pascal.y"
	{ puts("----------10.3. id"); }
break;
case 67:
#line 159 "pascal.y"
	{ puts("----------10.4. id list"); }
break;
case 68:
#line 163 "pascal.y"
	{ puts("-----------10.5. init_id"); }
break;
case 69:
#line 164 "pascal.y"
	{ puts("-----------10.6. initializer"); }
break;
case 70:
#line 165 "pascal.y"
	{ puts("-----------10.7. initializer float"); }
break;
case 71:
#line 166 "pascal.y"
	{ puts("-----------10.8. initializer double"); }
break;
case 72:
#line 167 "pascal.y"
	{ puts("-----------10.9. initializer hexa"); }
break;
case 73:
#line 168 "pascal.y"
	{ puts("-----------10.10. init assign"); }
break;
case 74:
#line 172 "pascal.y"
	{ puts("-----------11.1. void"); }
break;
case 75:
#line 173 "pascal.y"
	{ puts("-----------11.2. int"); }
break;
case 76:
#line 174 "pascal.y"
	{ puts("-----------11.3. char"); }
break;
case 77:
#line 175 "pascal.y"
	{ puts("-----------11.4. float"); }
break;
case 78:
#line 176 "pascal.y"
	{ puts("-----------11.5. double"); }
break;
case 79:
#line 180 "pascal.y"
	{ puts("------------12.1"); }
break;
case 81:
#line 184 "pascal.y"
	{ puts("------------12.2"); }
break;
case 82:
#line 185 "pascal.y"
	{ puts("------------12.3"); }
break;
case 83:
#line 189 "pascal.y"
	{ puts("------------12.4"); }
break;
#line 962 "y.tab.c"
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
