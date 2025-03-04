
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "pascal.y"


//#define YYDEBUG 1

#include "semantic.h"

#include <stdio.h>
#include "semantic.c"
#include "pascal.tab.h"

int yyerror(char const *msg);
int yylex(void);
extern int line_num;
extern FILE *yyin;
extern int number_errors ;
int currFunctionIndex ;
#include "pascal.tab.h"



/* Line 189 of yacc.c  */
#line 94 "pascal.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     EXP = 258,
     STR = 259,
     ID = 260,
     PROCEDURE = 261,
     FUNCTION = 262,
     ARRAY = 263,
     INTEGER = 264,
     DOUBLE = 265,
     STRING = 266,
     Boolean = 267,
     NUM = 268,
     Bool = 269,
     PROGRAM = 270,
     MC_BEGIN = 271,
     END = 272,
     VAR = 273,
     OF = 274,
     DOTS = 275,
     IF = 276,
     THEN = 277,
     ELSE = 278,
     WHILE = 279,
     DO = 280,
     NOT = 281,
     SEPARATOR_LINE = 282,
     SEPARATOR_LIST = 283,
     SEPARATOR_DEAD = 284,
     TYPIFIER = 285,
     BRACKET_O = 286,
     BRACKET_C = 287,
     SBRACKET_O = 288,
     SBRACKET_C = 289,
     _BUILTIN_READ = 290,
     _BUILTIN_WRITE = 291,
     ASSIGN = 292,
     COMMENT = 293,
     Number = 294,
     o_plus = 295,
     o_minus = 296,
     o_lor = 297,
     o_mul = 298,
     o_div = 299,
     o_mod = 300,
     o_land = 301,
     cmp_l = 302,
     cmp_leq = 303,
     cmp_eq = 304,
     cmp_neq = 305,
     cmp_g = 306,
     cmp_geq = 307,
     OPPAFFECT = 308
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 25 "pascal.y"

        int number;
        char *string;
        double fnumber;
        boolean_  bool ;
        struct Queue * queue ;
        //struct QueueType * queueType ;
        struct listeDescripteursTypes * listType ;
        typePossible  type_;



/* Line 214 of yacc.c  */
<<<<<<< HEAD
#line 196 "pascal.tab.c"
=======
#line 195 "pascal.tab.c"
>>>>>>> master
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
<<<<<<< HEAD
#line 208 "pascal.tab.c"
=======
#line 207 "pascal.tab.c"
>>>>>>> master

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,    15,    17,    21,    22,    27,
      29,    33,    34,    36,    40,    51,    52,    53,    57,    62,
      69,    78,    83,    84,    86,    88,    90,    92,    96,    97,
      99,   101,   105,   109,   111,   116,   123,   128,   133,   138,
     140,   142,   144,   148,   150,   154,   156,   160,   164,   168,
     172,   176,   178,   182,   186,   190,   192,   196,   200,   204,
     208,   210,   212,   214,   216,   220
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    56,    -1,    -1,    15,     5,    57,    27,
      59,    63,    70,    29,    -1,     5,    -1,     5,    28,    58,
      -1,    -1,    18,    62,    27,    59,    -1,    62,    -1,    62,
      27,    60,    -1,    -1,    60,    -1,    58,    30,    69,    -1,
      58,    30,     8,    33,    13,    20,    13,    34,    19,    69,
      -1,    -1,    -1,    64,    65,    63,    -1,    66,    59,    70,
      27,    -1,     6,     5,    31,    61,    32,    27,    -1,     7,
       5,    31,    61,    32,    30,    69,    27,    -1,     5,    31,
      68,    32,    -1,    -1,    75,    -1,     9,    -1,    10,    -1,
      12,    -1,    16,    71,    17,    -1,    -1,    72,    -1,    73,
      -1,    72,    27,    73,    -1,    74,    37,    76,    -1,    70,
      -1,    21,    76,    22,    73,    -1,    21,    76,    22,    73,
      23,    73,    -1,    24,    76,    25,    73,    -1,    35,    31,
      58,    32,    -1,    36,    31,    75,    32,    -1,    67,    -1,
       5,    -1,    76,    -1,    76,    28,    75,    -1,    77,    -1,
      77,    48,    77,    -1,    67,    -1,    77,    52,    77,    -1,
      77,    49,    77,    -1,    77,    50,    77,    -1,    77,    47,
      77,    -1,    77,    51,    77,    -1,    78,    -1,    77,    40,
      78,    -1,    77,    41,    78,    -1,    77,    42,    78,    -1,
      79,    -1,    78,    43,    79,    -1,    78,    46,    79,    -1,
      78,    44,    79,    -1,    78,    45,    79,    -1,    13,    -1,
       3,    -1,     4,    -1,     5,    -1,    31,    76,    32,    -1,
      14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    67,    67,    83,    90,    99,   103,   108,
     113,   121,   125,   130,   155,   182,   185,   185,   191,   202,
<<<<<<< HEAD
     213,   224,   230,   234,   240,   245,   250,   255,   256,   259,
     261,   263,   265,   292,   295,   304,   313,   322,   332,   337,
     342,   346,   354,   366,   371,   377,   382,   387,   392,   397,
     402,   407,   412,   430,   446,   457,   462,   478,   490,   495,
     505,   510,   515,   520,   539,   544
=======
     213,   224,   230,   234,   240,   245,   250,   251,   254,   256,
     258,   260,   285,   288,   292,   301,   310,   319,   329,   335,
     339,   347,   359,   364,   370,   375,   380,   385,   390,   395,
     400,   405,   423,   439,   450,   455,   471,   483,   488,   498,
     503,   508,   513,   532,   537
>>>>>>> master
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EXP", "STR", "ID", "PROCEDURE",
  "FUNCTION", "ARRAY", "INTEGER", "DOUBLE", "STRING", "Boolean", "NUM",
  "Bool", "PROGRAM", "MC_BEGIN", "END", "VAR", "OF", "DOTS", "IF", "THEN",
  "ELSE", "WHILE", "DO", "NOT", "SEPARATOR_LINE", "SEPARATOR_LIST",
  "SEPARATOR_DEAD", "TYPIFIER", "BRACKET_O", "BRACKET_C", "SBRACKET_O",
  "SBRACKET_C", "_BUILTIN_READ", "_BUILTIN_WRITE", "ASSIGN", "COMMENT",
  "Number", "o_plus", "o_minus", "o_lor", "o_mul", "o_div", "o_mod",
  "o_land", "cmp_l", "cmp_leq", "cmp_eq", "cmp_neq", "cmp_g", "cmp_geq",
  "OPPAFFECT", "$accept", "file", "program", "$@1", "identifier_list",
  "declarations_list", "parameters_list", "arguments", "declaration",
  "declaration_methods_list", "$@2", "declaration_method", "method_header",
  "method_call", "call_parameters", "type", "compound_statement",
  "optional_statement", "statement_list", "statement", "variable",
  "expr_list", "expr", "simple_expr", "term", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    57,    56,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    63,    64,    63,    65,    66,
      66,    67,    68,    68,    69,    69,    69,    70,    71,    71,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    77,    77,    77,    77,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     8,     1,     3,     0,     4,     1,
       3,     0,     1,     3,    10,     0,     0,     3,     4,     6,
       8,     4,     0,     1,     1,     1,     1,     3,     0,     1,
       1,     3,     3,     1,     4,     6,     4,     4,     4,     1,
       1,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     1,     0,     7,     0,    16,
       5,     0,     0,     0,     0,     0,     0,     7,    28,     0,
       0,     0,    16,     7,     6,     0,    24,    25,    26,    13,
       8,    40,     0,     0,     0,     0,    39,    33,     0,    29,
      30,     0,     4,     0,     0,    17,     0,     0,    22,    61,
      62,    63,    60,    65,     0,    45,     0,    43,    51,    55,
       0,     0,     0,    27,     0,     0,    11,    11,     0,     0,
       0,    23,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,    12,     0,     9,     0,    18,     0,    21,
       0,    64,    34,    63,    52,    53,    54,    49,    44,    47,
      48,    50,    46,    56,    58,    59,    57,    36,    37,    38,
       0,     0,     0,     0,    42,     0,    19,    10,     0,     0,
      35,     0,     0,    20,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,    11,     9,    93,    94,    95,    13,
      14,    22,    23,    55,    70,    29,    37,    38,    39,    40,
      41,    71,    72,    57,    58,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -119
static const yytype_int8 yypact[] =
{
      -2,    10,    27,  -119,  -119,  -119,    -3,    20,    35,    66,
      58,    25,    60,    72,    38,    35,    24,    20,     7,    61,
      84,    86,    66,    20,  -119,    59,  -119,  -119,  -119,  -119,
    -119,    62,     4,     4,    63,    64,  -119,  -119,    79,    70,
    -119,    65,  -119,    67,    68,  -119,    72,    87,     4,  -119,
    -119,    62,  -119,  -119,     4,  -119,    81,    17,    28,  -119,
      76,    35,     4,  -119,     7,     4,    35,    35,    77,    85,
      74,  -119,    80,    78,     7,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,     7,    82,
      83,  -119,  -119,  -119,    88,    89,    90,  -119,    96,  -119,
       4,  -119,    94,  -119,    28,    28,    28,    39,    39,    39,
      39,    39,    39,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
      91,    35,    93,    92,  -119,     7,  -119,  -119,    51,   100,
    -119,    97,    51,  -119,  -119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -119,  -119,  -119,  -119,   -13,    -1,   -10,    45,   105,    99,
    -119,  -119,  -119,   -18,  -119,  -118,    -7,  -119,  -119,   -63,
    -119,   -59,   -28,   -29,     8,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -16
static const yytype_int16 yytable[] =
{
      36,    91,    24,    90,    56,    60,    19,    49,    50,    51,
     131,   102,    31,     1,   134,     4,    30,    52,    53,    49,
      50,   103,    46,    18,     7,   117,    73,     5,    32,    52,
      53,    33,    25,    26,    27,    54,    28,    92,     8,    68,
      10,   124,    34,    35,    20,    21,    36,    54,    89,   107,
     108,   109,   110,   111,   112,    16,    36,    75,    76,    77,
      26,    27,   130,    28,    78,    79,    80,    81,    82,    83,
      36,    84,    85,    86,    87,   113,   114,   115,   116,    75,
      76,    77,   -15,   104,   105,   106,    15,    17,    18,    43,
      42,    44,    47,    48,    61,    62,    63,    64,    66,    67,
      69,    88,    65,    74,    97,    98,    99,    36,   100,   123,
     101,   127,    96,    12,   118,   119,   121,   125,   126,   132,
     120,    45,   122,   128,   133,     0,   129
};

static const yytype_int16 yycheck[] =
{
      18,    64,    15,    62,    32,    33,    13,     3,     4,     5,
     128,    74,     5,    15,   132,     5,    17,    13,    14,     3,
       4,     5,    23,    16,    27,    88,    54,     0,    21,    13,
      14,    24,     8,     9,    10,    31,    12,    65,    18,    46,
       5,   100,    35,    36,     6,     7,    64,    31,    61,    78,
      79,    80,    81,    82,    83,    30,    74,    40,    41,    42,
       9,    10,   125,    12,    47,    48,    49,    50,    51,    52,
      88,    43,    44,    45,    46,    84,    85,    86,    87,    40,
      41,    42,    16,    75,    76,    77,    28,    27,    16,     5,
      29,     5,    33,    31,    31,    31,    17,    27,    31,    31,
      13,    25,    37,    22,    27,    20,    32,   125,    28,    13,
      32,   121,    67,     8,    32,    32,    27,    23,    27,    19,
      32,    22,    32,    30,    27,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    55,    56,     5,     0,    57,    27,    18,    59,
       5,    58,    62,    63,    64,    28,    30,    27,    16,    70,
       6,     7,    65,    66,    58,     8,     9,    10,    12,    69,
      59,     5,    21,    24,    35,    36,    67,    70,    71,    72,
      73,    74,    29,     5,     5,    63,    59,    33,    31,     3,
       4,     5,    13,    14,    31,    67,    76,    77,    78,    79,
      76,    31,    31,    17,    27,    37,    31,    31,    70,    13,
      68,    75,    76,    76,    22,    40,    41,    42,    47,    48,
      49,    50,    51,    52,    43,    44,    45,    46,    25,    58,
      75,    73,    76,    60,    61,    62,    61,    27,    20,    32,
      28,    32,    73,     5,    78,    78,    78,    77,    77,    77,
      77,    77,    77,    79,    79,    79,    79,    73,    32,    32,
      32,    27,    32,    13,    75,    23,    27,    60,    30,    34,
      73,    69,    19,    27,    69
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 53 "pascal.y"
    {
		//printCurrentDict() ;
		verifUsed();
		if(number_errors)
		{
		printf("\n\nNUMBER OF ERRORS = %d\n",number_errors) ;
		return 1 ;
		}

		printf("#program accepted by interpreter\n");
		return (0) ;

	;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 67 "pascal.y"
    {
		ajouterEntree((yyvsp[(2) - (2)].string),*nouveau(getTypeByName("program")) ,line_num) ;
	;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 70 "pascal.y"
    {
		//create main node
		//node * main = createNode($2,$1,NULL) ;
		//push to main sublist declaration list netsarfou fil nodes
		//parrent = main ;
		//node * global = $4 ;
		//current = null ;
		//char * currentType ;
		//check(global)
		//CHECK(global, haja elli bech ncheckiha ) ;
		//strcpy(currentType,"") ;
	;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 84 "pascal.y"
    {
		Queue * temp = createQueue() ;
		enQueue(temp,(yyvsp[(1) - (1)].string));
		(yyval.queue) = temp ;
	;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 91 "pascal.y"
    {
		Queue * temp = createQueue() ;
		enQueue(temp,(yyvsp[(1) - (3)].string));
		enQueueQueue(temp,(yyvsp[(3) - (3)].queue));
		(yyval.queue)= temp;
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 99 "pascal.y"
    {
		(yyval.listType) = NULL ;
	;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 104 "pascal.y"
    {
		(yyval.listType) = NULL
	;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 109 "pascal.y"
    {
		(yyval.listType) = (yyvsp[(1) - (1)].listType) ;
	;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 114 "pascal.y"
    {
		listeDescripteursTypes * list1 = (yyvsp[(1) - (3)].listType);
		concatenateTypeList(list1,(yyvsp[(3) - (3)].listType)) ;
		(yyval.listType)=list1 ;
	;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 121 "pascal.y"
    {
		(yyval.listType) = NULL ;
	;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 126 "pascal.y"
    {
		(yyval.listType) = (yyvsp[(1) - (1)].listType) ;
	;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 131 "pascal.y"
    {
		listeDescripteursTypes *head = NULL ;
		Queue * tempQueue = (yyvsp[(1) - (3)].queue) ;
		descripteurType * tempType ;
		while (tempQueue->front){

			tempType =nouveau(getTypeByName((yyvsp[(3) - (3)].string))) ;
			ajouterEntree(tempQueue->front->key,*tempType,line_num) ;


			listeDescripteursTypes *new = malloc(sizeof(listeDescripteursTypes));
			new->info = tempType ;
			new->suivant = head ;
			head = new ;


			deQueue(tempQueue) ;
		}
		//printCurrentDict() ;
		//addTypeToSiblings($1,$3) ;
		//$$ = $1
		(yyval.listType)= head ;
	;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 156 "pascal.y"
    {
		listeDescripteursTypes *head  = NULL ;
		Queue * tempQueue = (yyvsp[(1) - (10)].queue) ;
		descripteurType * tempType =nouveau(getTypeByName("tTableau")) ;
		tempType->attributs.casTableau.indiceDebut= (yyvsp[(5) - (10)].number) ;
		tempType->attributs.casTableau.indiceFin= (yyvsp[(7) - (10)].number) ;
		//fprintf(stderr,"%s ",getTypeName(nouveau(getTypeByName($10))->classe));
		descripteurType * tempElementType=nouveau(getTypeByName((yyvsp[(10) - (10)].string)));
		tempType->attributs.casTableau.typeElement = tempElementType ;

		while (tempQueue->front!= NULL){

			ajouterEntree(tempQueue->front->key,*tempType,line_num) ;

			listeDescripteursTypes *new = malloc(sizeof(listeDescripteursTypes));
			new->info = tempType ;
			new->suivant = head ;
			head = new ;

			deQueue(tempQueue) ;
		}
		//printCurrentDict() ;
		(yyval.listType)= head ;

	;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 185 "pascal.y"
    {
	upScope() ;
	;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 192 "pascal.y"
    {
		//node * variables = concatenateSiblingLists($1->children,$2) ;
		//printCurrentDict();
		downScope() ;
		if(currFunctionIndex >=0)
		{
		ajouterEntree(dico[currFunctionIndex].identif,dico[currFunctionIndex].type,dico[currFunctionIndex].declarationLine) ;
		}
	;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 203 "pascal.y"
    {


		descripteurType * tempType =nouveau(getTypeByName((yyvsp[(1) - (6)].string))) ;
		tempType->attributs.casProcedure.typesArguments = (yyvsp[(4) - (6)].listType) ;
		currFunctionIndex = ajouterEntree((yyvsp[(2) - (6)].string),*tempType,line_num) ;
		//printCurrentDict() ;
		//$$= NULL
	;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 214 "pascal.y"
    {
		descripteurType * tempType =nouveau(getTypeByName((yyvsp[(1) - (8)].string))) ;
		descripteurType * tempReturnType=nouveau(getTypeByName((yyvsp[(7) - (8)].string)));
		tempType->attributs.casFonction.typeResultat = tempReturnType ;
		tempType->attributs.casFonction.typesArguments = (yyvsp[(4) - (8)].listType) ;
		currFunctionIndex = ajouterEntree((yyvsp[(2) - (8)].string),*tempType,line_num) ;
		//printCurrentDict() ;
		//$$= NULL
	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 225 "pascal.y"
    {
		(yyval.type_)=verifMethodCall((yyvsp[(1) - (4)].string),(yyvsp[(3) - (4)].listType));
	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 230 "pascal.y"
    {
	(yyval.listType)=NULL;
	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 235 "pascal.y"
    {
	(yyval.listType)=(yyvsp[(1) - (1)].listType);
	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 241 "pascal.y"
    {
		(yyval.string) = (yyvsp[(1) - (1)].string) ;
	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 246 "pascal.y"
<<<<<<< HEAD
    {
		(yyval.string) = (yyvsp[(1) - (1)].string) ;
	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 251 "pascal.y"
=======
>>>>>>> master
    {
		(yyval.string) = (yyvsp[(1) - (1)].string) ;
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 266 "pascal.y"
=======
#line 261 "pascal.y"
>>>>>>> master
    {
		ENTREE_DICO * variable  = search_variable((yyvsp[(1) - (3)].string)) ;
		if (variable)
		{
			if(memeType(nouveau((yyvsp[(3) - (3)].type_)),&variable->type))
			{
				variable->initialised = 1 ;
				//variable->used = 1 ;
<<<<<<< HEAD
			}
			else if ((variable->type.classe==tDouble) && ((yyvsp[(3) - (3)].type_)==tInt))
			{
				variable->initialised = 1 ;
				//variable->used = 1 ;
=======
>>>>>>> master
			}
			else
			{
				number_errors++ ;
				printf("Type variable incompatible \n");
			}

		}
<<<<<<< HEAD



=======
		else {
			number_errors ++ ;
			printf("Variable not found \n");
		}


	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 285 "pascal.y"
    {
>>>>>>> master
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 292 "pascal.y"
=======
#line 289 "pascal.y"
>>>>>>> master
    {
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 296 "pascal.y"
=======
#line 293 "pascal.y"
>>>>>>> master
    {
		if ((yyvsp[(2) - (4)].type_)!=tBool)
		{
			number_errors ++ ;
			printf("if condition must be of type boolean\n") ;
		}
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 305 "pascal.y"
=======
#line 302 "pascal.y"
>>>>>>> master
    {
		if ((yyvsp[(2) - (6)].type_)!=tBool)
		{
			number_errors ++ ;
			printf("if condition must be of type boolean\n") ;
		}
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 314 "pascal.y"
=======
#line 311 "pascal.y"
>>>>>>> master
    {
		if ((yyvsp[(2) - (4)].type_)!=tBool)
		{
			number_errors ++ ;
			printf("while condition must be of type boolean\n") ;
		}
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 323 "pascal.y"
=======
#line 320 "pascal.y"
>>>>>>> master
    {
		Queue * tempQueue = (yyvsp[(3) - (4)].queue) ;
		while (tempQueue->front){
			search_variable(tempQueue->front->key) ;
			deQueue(tempQueue) ;
		}

	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 333 "pascal.y"
=======
#line 330 "pascal.y"
>>>>>>> master
    {

	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 338 "pascal.y"
    {
=======
#line 335 "pascal.y"
    {
		(yyval.string)=(yyvsp[(1) - (1)].string) ;
>>>>>>> master
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 342 "pascal.y"
    {
		(yyval.string)=(yyvsp[(1) - (1)].string) ;
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 346 "pascal.y"
=======
#line 339 "pascal.y"
>>>>>>> master
    {
		listeDescripteursTypes *head = NULL ;
		head = (listeDescripteursTypes*)malloc(sizeof(listeDescripteursTypes));
		head->info= nouveau((yyvsp[(1) - (1)].type_)) ;
		head->suivant= NULL ;
		(yyval.listType)=head ;
	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 355 "pascal.y"
=======
#line 348 "pascal.y"
>>>>>>> master
    {

		listeDescripteursTypes *head = NULL ;
		head = (listeDescripteursTypes*)malloc(sizeof(listeDescripteursTypes));
		head->info= nouveau((yyvsp[(1) - (3)].type_)) ;
		head->suivant= NULL ;
		concatenateTypeList(head,(yyvsp[(3) - (3)].listType)) ;
		(yyval.listType)=head ;
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 367 "pascal.y"
=======
#line 360 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)= (yyvsp[(1) - (1)].type_) ;
	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 372 "pascal.y"
=======
#line 365 "pascal.y"
>>>>>>> master
    {

		(yyval.type_)=verifCompare((yyvsp[(1) - (3)].type_),(yyvsp[(3) - (3)].type_)) ;
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 378 "pascal.y"
=======
#line 371 "pascal.y"
>>>>>>> master
    {
		(yyval.type_) = (yyvsp[(1) - (1)].type_) ;
	;}
    break;

<<<<<<< HEAD
  case 46:

/* Line 1455 of yacc.c  */
#line 383 "pascal.y"
=======
  case 45:

/* Line 1455 of yacc.c  */
#line 376 "pascal.y"
    {
		(yyval.type_)=verifCompare((yyvsp[(1) - (3)].type_),(yyvsp[(3) - (3)].type_)) ;
	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 381 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=verifCompare((yyvsp[(1) - (3)].type_),(yyvsp[(3) - (3)].type_)) ;
	;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 388 "pascal.y"
=======
#line 386 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=verifCompare((yyvsp[(1) - (3)].type_),(yyvsp[(3) - (3)].type_)) ;
	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 393 "pascal.y"
=======
#line 391 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=verifCompare((yyvsp[(1) - (3)].type_),(yyvsp[(3) - (3)].type_)) ;
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 398 "pascal.y"
=======
#line 395 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=verifCompare((yyvsp[(1) - (3)].type_),(yyvsp[(3) - (3)].type_)) ;
	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 402 "pascal.y"
=======
#line 401 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=verifCompare((yyvsp[(1) - (3)].type_),(yyvsp[(3) - (3)].type_)) ;
	;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 408 "pascal.y"
    {
		(yyval.type_)=(yyvsp[(1) - (1)].type_)
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 413 "pascal.y"
=======
#line 406 "pascal.y"
>>>>>>> master
    {
		if((yyvsp[(1) - (3)].type_)==tInt&&(yyvsp[(3) - (3)].type_)==tInt)
			(yyval.type_) = tInt;
		else if((yyvsp[(1) - (3)].type_)==tInt || (yyvsp[(3) - (3)].type_)==tInt)
			if((yyvsp[(1) - (3)].type_)==tDouble||(yyvsp[(3) - (3)].type_)==tDouble)
				(yyval.type_) = tDouble;
		else if((yyvsp[(1) - (3)].type_)==tDouble&&(yyvsp[(3) - (3)].type_)==tDouble)
			(yyval.type_)= tDouble ;
		else if((yyvsp[(1) - (3)].type_)==tString&&(yyvsp[(3) - (3)].type_)==tString)
			(yyval.type_)=tString ;
		else{
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
			(yyval.type_)= tInt ;
		}
	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 431 "pascal.y"
=======
#line 424 "pascal.y"
>>>>>>> master
    {
		if((yyvsp[(1) - (3)].type_)==tInt&&(yyvsp[(3) - (3)].type_)==tInt)
			(yyval.type_) = tInt;
		else if((yyvsp[(1) - (3)].type_)==tInt || (yyvsp[(3) - (3)].type_)==tInt)
			if((yyvsp[(1) - (3)].type_)==tDouble||(yyvsp[(3) - (3)].type_)==tDouble)
				(yyval.type_) = tDouble;
		else if((yyvsp[(1) - (3)].type_)==tDouble&&(yyvsp[(3) - (3)].type_)==tDouble)
			(yyval.type_)= tDouble ;
		else {
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
			(yyval.type_)= tDouble ;
		}
	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 447 "pascal.y"
=======
#line 440 "pascal.y"
>>>>>>> master
    {
		if((yyvsp[(1) - (3)].type_)==tBool&&(yyvsp[(3) - (3)].type_)==tBool)
			(yyval.type_) = tBool;
		else {
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
			(yyval.type_)=(yyvsp[(1) - (3)].type_) ;
		}
	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 458 "pascal.y"
=======
#line 451 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=(yyvsp[(1) - (1)].type_) ;
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 463 "pascal.y"
=======
#line 456 "pascal.y"
>>>>>>> master
    {
		if((yyvsp[(1) - (3)].type_)==tInt&&(yyvsp[(3) - (3)].type_)==tInt)
			(yyval.type_) = tInt;
		else if((yyvsp[(1) - (3)].type_)==tInt || (yyvsp[(3) - (3)].type_)==tInt)
			if((yyvsp[(1) - (3)].type_)==tDouble||(yyvsp[(3) - (3)].type_)==tDouble)
				(yyval.type_) = tDouble;
		else if((yyvsp[(1) - (3)].type_)==tDouble&&(yyvsp[(3) - (3)].type_)==tDouble)
			(yyval.type_)= tDouble ;
		else {
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
			(yyval.type_) = tInt ;
		}
	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 479 "pascal.y"
=======
#line 472 "pascal.y"
>>>>>>> master
    {
		if((yyvsp[(1) - (3)].type_)==tBool&&(yyvsp[(3) - (3)].type_)==tBool)
			(yyval.type_) = tBool;
		else {
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
			(yyval.type_)=(yyvsp[(1) - (3)].type_) ;
		}

	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 491 "pascal.y"
=======
#line 484 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=tDouble ;
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 496 "pascal.y"
=======
#line 489 "pascal.y"
>>>>>>> master
    {
		if((yyvsp[(1) - (3)].type_)!=tInt||(yyvsp[(3) - (3)].type_)!=tInt)
		{
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
		}
		(yyval.type_)=tInt
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 506 "pascal.y"
=======
#line 499 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=tInt ;
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 511 "pascal.y"
=======
#line 504 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=tDouble ;
	;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 516 "pascal.y"
=======
#line 509 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=tString ;
	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 521 "pascal.y"
=======
#line 514 "pascal.y"
>>>>>>> master
    {
		ENTREE_DICO * variable  = search_variable((yyvsp[(1) - (1)].string)) ;
		if (variable)
		{
			if(!variable->initialised)
			{
				number_errors ++ ;
				printf("vriable avec l'identificateur %s non initialisé\n",variable->identif) ;
			}
			variable->used = 1 ;
			(yyval.type_)= variable->type.classe ;
		}
		else {
			(yyval.type_)= tVoid ;
		}
		//probablement va causer des probs
	;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 540 "pascal.y"
=======
#line 533 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=(yyvsp[(2) - (3)].type_) ;
	;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 545 "pascal.y"
=======
#line 538 "pascal.y"
>>>>>>> master
    {
		(yyval.type_)=tBool ;
	;}
    break;



/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 2234 "pascal.tab.c"
=======
#line 2221 "pascal.tab.c"
>>>>>>> master
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
<<<<<<< HEAD
#line 548 "pascal.y"
=======
#line 541 "pascal.y"
>>>>>>> master


#include <stdlib.h>
int yyerror(char const *msg) {
	printf("%s %d\n", msg,line_num);
	return 0;
}

int main(int argc,char** argv)
{


	creerDico() ;

	char str[60];
	yyin = fopen(argv[1],"r");

	return yyparse() ;


}

int yywrap()
{
 return(1);
}
                   

