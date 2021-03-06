/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "lego.y" /* yacc.c:339  */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "header_files/block.h"
#include "header_files/grid.h"

#line 75 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    DIR = 259,
    TYPE = 260,
    SHOW = 261,
    EXIT = 262,
    SWITCH = 263,
    ARRAY = 264,
    PYRAMID = 265,
    DOME = 266,
    GRID = 267,
    HEIGHT = 268,
    FITS = 269,
    PLACE = 270,
    DELETE = 271,
    ALL = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    MOVE = 276,
    AND = 277,
    OR = 278,
    EQ = 279,
    AT = 280,
    VAR = 281,
    GVAR = 282
  };
#endif
/* Tokens.  */
#define NUM 258
#define DIR 259
#define TYPE 260
#define SHOW 261
#define EXIT 262
#define SWITCH 263
#define ARRAY 264
#define PYRAMID 265
#define DOME 266
#define GRID 267
#define HEIGHT 268
#define FITS 269
#define PLACE 270
#define DELETE 271
#define ALL 272
#define IF 273
#define THEN 274
#define ELSE 275
#define MOVE 276
#define AND 277
#define OR 278
#define EQ 279
#define AT 280
#define VAR 281
#define GVAR 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "lego.y" /* yacc.c:355  */

       char* lexeme;			//identifier
       double value;			//value of an identifier of type NUM
       

#line 175 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 192 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   71

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  20
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  68

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    34,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,    28,    29,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    52,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    67,    68,    71,    72,    75,    76,
      77
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "DIR", "TYPE", "SHOW", "EXIT",
  "SWITCH", "ARRAY", "PYRAMID", "DOME", "GRID", "HEIGHT", "FITS", "PLACE",
  "DELETE", "ALL", "IF", "THEN", "ELSE", "MOVE", "AND", "OR", "EQ", "AT",
  "VAR", "GVAR", "'='", "'>'", "'<'", "'\\n'", "'('", "','", "')'",
  "$accept", "line", "stmt", "mopt", "hopt", "dopt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    61,    62,
      60,    10,    40,    44,    41
};
# endif

#define YYPACT_NINF -25

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-25)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      16,   -24,   -25,    -8,   -20,   -15,   -13,     2,   -10,   -11,
      -1,    18,    -6,   -25,     6,   -25,    31,   -25,     3,    11,
      12,   -25,   -25,   -25,     1,   -25,    33,    28,   -25,   -25,
     -25,   -25,     8,    41,    13,   -25,    43,    15,    17,    19,
      45,    20,    47,   -25,    49,    51,    52,    22,    54,    25,
      26,    27,    29,   -25,    30,    58,    60,    62,    63,   -25,
      34,    35,    36,    37,   -25,   -25,   -25,   -25
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    17,     0,    11,     0,     0,
       0,    19,    18,    12,     0,    10,     0,     0,     1,     2,
       3,     5,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     8,    15,     7,     6
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,    55,   -25,   -25,   -25,   -25
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    25,    17,    23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       1,     2,     3,    13,    14,    36,    15,     4,     5,     6,
       7,    18,    16,    19,    20,     8,    24,    26,    28,    21,
       9,    10,     1,     2,     3,    29,    37,    27,    22,     4,
       5,     6,     7,    31,    32,    33,    34,     8,    38,    35,
      39,    40,     9,    10,    41,    42,    43,    44,    47,    45,
      49,    46,    50,    48,    51,    52,    53,    54,    55,    56,
      57,    60,    58,    61,    59,    62,    63,    30,    64,    65,
      66,    67
};

static const yytype_uint8 yycheck[] =
{
       6,     7,     8,    27,    12,     4,    26,    13,    14,    15,
      16,    26,    32,    26,    12,    21,    26,    28,     0,    17,
      26,    27,     6,     7,     8,    31,    25,    28,    26,    13,
      14,    15,    16,    27,     3,    32,    25,    21,     5,    27,
      12,    33,    26,    27,     3,    32,     3,    32,     3,    32,
       3,    32,     3,    33,     3,     3,    34,     3,    33,    33,
      33,     3,    33,     3,    34,     3,     3,    12,    34,    34,
      34,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,    13,    14,    15,    16,    21,    26,
      27,    36,    37,    27,    12,    26,    32,    39,    26,    26,
      12,    17,    26,    40,    26,    38,    28,    28,     0,    31,
      36,    27,     3,    32,    25,    27,     4,    25,     5,    12,
      33,     3,    32,     3,    32,    32,    32,     3,    33,     3,
       3,     3,     3,    34,     3,    33,    33,    33,    33,    34,
       3,     3,     3,     3,    34,    34,    34,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    38,    38,    39,    39,    40,    40,
      40
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     3,     8,     8,     8,     2,
       2,     2,     2,     7,     3,     7,     5,     1,     1,     1,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 51 "lego.y" /* yacc.c:1646  */
    {printf("Result: %f\n");}
#line 1304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "lego.y" /* yacc.c:1646  */
    {}
#line 1310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 55 "lego.y" /* yacc.c:1646  */
    {exit(EXIT_SUCCESS);}
#line 1316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 56 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",switch_grid(grid_list,(yyvsp[0].lexeme)));}
#line 1322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 57 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",add_grid(grid_list,(yyvsp[-7].lexeme),(yyvsp[-3].value),(yyvsp[-1].value)));}
#line 1328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 58 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",add(default_grid,(yyvsp[-7].lexeme),(yyvsp[-3].value),(yyvsp[-1].value),(yyvsp[-5].lexeme),-1,-1));}
#line 1334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 59 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",update(default_grid,0,(yyvsp[-6].lexeme),(yyvsp[-3].value),(yyvsp[-1].value)));}
#line 1340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 60 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",show(grid_list,(yyvsp[0].lexeme)));}
#line 1346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 61 "lego.y" /* yacc.c:1646  */
    {;}
#line 1352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 62 "lego.y" /* yacc.c:1646  */
    {;}
#line 1358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 63 "lego.y" /* yacc.c:1646  */
    {;}
#line 1364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",fits(default_grid,(yyvsp[-5].lexeme),(yyvsp[-3].value),(yyvsp[-1].value)));}
#line 1370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 67 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",update_dir(default_grid,(yyvsp[-2].lexeme),(yyvsp[-1].lexeme),(yyvsp[0].value)));}
#line 1376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 68 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",update(default_grid,1,(yyvsp[-6].lexeme),(yyvsp[-3].value),(yyvsp[-1].value)));}
#line 1382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 71 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",height(default_grid,(yyvsp[-3].value),(yyvsp[-1].value)));}
#line 1388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 72 "lego.y" /* yacc.c:1646  */
    {}
#line 1394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 75 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",rm(default_grid,(yyvsp[0].lexeme)));}
#line 1400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 76 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",rm_all(default_grid));}
#line 1406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 77 "lego.y" /* yacc.c:1646  */
    {printf("%d\n",rm_grid(grid_list,(yyvsp[0].lexeme)));}
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1416 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 80 "lego.y" /* yacc.c:1906  */


#include "lex.yy.c"


l_list* create_list(void) {
    l_list* p;
    p = malloc(sizeof(l_list));
    p->head = NULL;
    return p;
}

g_list* create_grid_list(void) {
    g_list* p;
    p = malloc(sizeof(g_list));
    p->head = NULL;
    return p;
}
grid_t* create_grid_t(void) {
		grid_t* p;
		p = malloc(sizeof(grid_t));
		return p;
}

int free_matrix(char *** matrix, int row, int col){
    for(int i=0; i < row; i++){
        for(int j=0; j < col; j++){
            free(matrix[i][j]);
        }
    }
    free(matrix);
}


int add_grid(g_list * list, char id[], int row, int col) {

	  if (row == 0 || col == 0){
    	printf("You cannot create a grid with size 0. Error in line %d\n", yylineno);
      return 0;
    }
    grid_t * current = list->head;
    grid_t * grid = malloc(sizeof(grid_t));
    grid->id = id;
    grid->row = row;
    grid->col = col;
    grid->blocks = create_list();
    default_grid=create_grid_t();
    grid->matrix = (char * * *) malloc(row * sizeof(char * *));
    for(int i=0; i < row; i++){
        grid->matrix[i] = (char * *) malloc(col * sizeof(char *));
        for(int j=0; j < col; j++){
            grid->matrix[i][j] = "0";
        }
    }

    if (list->head == NULL){
      list->head = grid;
      list->head->next = NULL;
      default_grid = list->head;
      default_grid->id=list->head->id;
      return 1;
    }

    while (current->next != NULL) {
      if(strcmp(current->id, id) == 0){
        printf("This grid is already used. Error in line %d\n", yylineno);
        free(grid->matrix);
        free(grid);
        return 0;
      }
      current = current->next;
    }

    if(strcmp(current->id, id) == 0){
      printf("This grid is already used. Error in line %d\n", yylineno);
      free(grid->matrix);
      free(grid);
      return 0;
    }

    current->next = malloc(sizeof(grid_t));
    current->next = grid;
    current->next->next = NULL;

    default_grid = current->next;


    return 1;
}

int switch_grid(g_list * list, char* id) {

    if (list->head == NULL){
      printf("Grid list is empty: could not switch to any grid. Error in line %d\n", yylineno);
      return 0;
    }

    if(strcmp(id, "-1") == 0){
      id = list->head->id;
    } 


    grid_t* current = list->head;
    
    while(current != NULL){
      if (strcmp(current->id, id)==0 ){
        default_grid = current;
        printf("Switched to grid id=%s\n", id);
        return 1;
      }
      current = current->next;
    }

    printf("Grid %s does not exist: you cannot switch to it. Error in line %d\n", id, yylineno);
    return 0;
}


int rm_grid(g_list * list, char* id) {

    if (list->head == NULL){
      printf("Grid list is empty: could not delete %s. Error in line %d\n", id, yylineno);
      return 0;
    }

    grid_t* current = list->head;
    grid_t* temp = malloc(sizeof(grid_t));
    char* def_id = default_grid->id;

    if (strcmp(current->id, id) == 0){
      rm_all(current->blocks);
      free(current);
      list->head = current->next;
      printf("Deleted grid id=%s\n", id);
      if (strcmp(def_id, id) == 0){
        switch_grid(list, "-1");
      }
      return 1;
    }

    // delete any element
    while(current->next != NULL){
      if (strcmp(current->next->id, id)==0 ){
        rm_all(current->blocks);
        temp = current->next;
        current->next = temp->next;
        free(temp);
        printf("Deleted grid id=%s\n", id);
        if (strcmp(def_id, id) == 0){
          switch_grid(list, list->head->id);
        }
        return 1;
      }
      current = current->next;
    }

    printf("Grid %s does not exist: it cannot be deleted. Error in line %d\n", id, yylineno);
    return 0;
}

int show(g_list * list, char* id){

    grid_t* current = list->head;

    if (list->head == NULL){
      printf("Grid list is empty: could not print %s. Error in line %d\n", id, yylineno);
      return 0;
    }

    while (current != NULL) {
      if(strcmp(current->id, id) == 0){
        int maxRow = current->row;
        int maxCol = current->col;
        for (int row=0; row<maxRow; row++){
          for(int col=0; col<maxCol; col++){
            printf("%s     ", current->matrix[row][col]);
          }
          printf("\n");
        }
        return 1;
      }
      current = current->next;
    }

}

int fits(grid_t * grid, char id[], int x, int y){
    l_list * list = grid->blocks;
		node_t * current = list->head;
		int gridx = grid->row;
		int gridy = grid->col;

    if (list->head == NULL){
      printf("Grid list is empty: could not find %s. Error in line %d\n", yylineno);
      return 0;
    }

    if (x > gridx || y > gridy){
			printf("The coordinates are too big for the grid. Error in line %d\n", yylineno);
		  	return 0;
    }

    while (current != NULL) {
      if(strcmp(current->id, id) == 0){
      	int checkx = (current->x)-gridx+x;
      	int checky = (current->y)-gridy+y;
      	if(checkx > 0 || checky > 0){
      		printf("Cannot insert this variable at this point. There is not enough space. Check the grid size and the coordinates. Error in line %d\n", yylineno);
      		return 0;
      	}

      	char * var = grid->matrix[x][y];
      	if(strstr(var, "o") != NULL || strstr(var,"x") != NULL){
		      printf("Cannot place the variable on the top of a dome or pyramid block. Error in line %d\n", yylineno);
		      return 0;
				}
				char * currVar;

				for(int i = x; i < x+current->x; i++){
		      for(int j = y; j < y+current->y; j++){
            currVar = grid->matrix[i][j];
            if(strcmp(var,currVar) != 0){
                  printf("Cannot place the variable on blocks with different heights. Error in line %d\n", yylineno);
                  return 0;
            }
		      }
				}
      	printf("The block fits in the desidered coordinates %d, %d.\n", x, y);
      	return 1;
      }
      current = current->next;
    }

    printf("This variable does not exist. Error in line %d\n", yylineno);
    return 0;
}

int add(grid_t * grid, char id[], int x, int y, char* type, int coox, int cooy) {
	  if (x == 0 || y == 0){
    	printf("You cannot create a variable with size 0. Error in line %d\n", yylineno);
      return 0;
    }
    l_list * list = grid->blocks;
    node_t * current = list->head;
    node_t * node = malloc(sizeof(node_t));
    node->id = id;
    node->x = x;
    node->y = y;
    node->type = type;
    node->coox = coox;
    node->cooy = cooy;

    if (list->head == NULL){
      list->head = node;
      list->head->next = NULL;
      printf("Added item %s to grid %s\n", list->head->id, grid->id);
      return 1;
    }

    while (current->next != NULL) {
      if(strcmp(current->id, id) == 0){
        printf("This variable is already used. Error in line %d\n", yylineno);
        free(node);
        return 0;
      }
      current = current->next;
    }

    if(strcmp(current->id, id) == 0){
      printf("This variable is already used. Error in line %d\n", yylineno);
      free(node);
      return 0;
    }

    current->next = malloc(sizeof(node_t));
    current->next = node;
    current->next->next = NULL;

    printf("Added item %s to grid %s\n", current->next->id, grid->id);

    return 1;
}

int on_top(grid_t * grid, node_t * node){ // problem is here

    return 0;
		int coox = node->coox;
		int cooy = node->cooy;
		printf("here3\n");
		
		if (node->h == height(grid, coox, cooy)){
			printf("here1\n");
			return 1;
		}

		return 0;
}

int height(grid_t * grid, int x, int y){

		if(x >= grid->row || y >= grid-> row){
			printf("Cannot calculate the height of a cell not in the grid boundary. Error in line %d\n", yylineno);
      return 0;
		}

    char * var = grid->matrix[x][y];
		int h = atoi(var);
		return h;
}

int add_in_matrix(grid_t * grid, node_t * node, int coox, int cooy){
		int x = node->x;
		int y = node->y;
		char * type = node->type;
		int cell_height = height(grid, coox,cooy);
		node->h = cell_height + 1;

		char * t = "";
		if(strcmp(type, "dome") == 0){
			t = "o";
		}else if (strcmp(type, "pyramid") == 0){
			t = "x";
		}

		for(int i = coox; i < x+coox; i++){
	    for(int j = cooy; j < y+cooy; j++){
	    	int curr = atoi(grid->matrix[i][j])+1;
	    	char * res = malloc(sizeof(char)*4);
	    	snprintf(res, sizeof(res), "%d", curr);
	    	strcat(res, t);
	    	grid->matrix[i][j] = res;
	    }
		}

}

int delete_in_matrix(grid_t * grid, node_t * node){

    return 0;
		int x = node->x;
		int y = node->y;
		int coox = node->coox;
		int cooy = node->cooy;
		printf("here1\n");
		if(on_top(grid, node) == 0){
			printf("here2\n");
			return 0;
		}

		for(int i = coox; i < x+coox; i++){
	    for(int j = cooy; j < y+cooy; j++){
	    	int curr = atoi(grid->matrix[i][j])-1;
	    	char * res = malloc(sizeof(char)*4);
	    	snprintf(res, sizeof(res), "%d", curr);
	    	grid->matrix[i][j] = res;
	    }
		}
}

int update(grid_t * grid, int method, char* id, int coox, int cooy) {
    l_list * list = grid->blocks;
    node_t * current = list->head;

    if (list->head == NULL){
      printf("This variable does not exist. Error in line %d\n", yylineno);
      return 0;
    }

    while (current != NULL) {
      if((strcmp(current->id, id) == 0)){
        if(method == 0){
          if(current->coox == -1 && current->cooy == -1){
          	if(fits(grid, current->id, coox, cooy)){
          		current->coox = coox;
            	current->cooy = cooy;
            	add_in_matrix(grid, current, coox, cooy);
            	return 1;
          	}else{
          		return 0;
          	}
          }else{
            printf("This lego was already placed. Please use move to move it. Error in line %d\n", yylineno);
            return 0;
          }
        }else{
          if(current->coox != -1 && current->cooy != -1){
						int past_x = current->coox;
						int past_y = current->cooy;
	          delete_in_matrix(grid, current);
          	if(fits(grid, current->id, coox, cooy)){
	            current->coox = coox;
	            current->cooy = cooy;
	            add_in_matrix(grid, current, coox, cooy);
	            return 1;
          	}else{
          		add_in_matrix(grid, current, past_x, past_y);
          		return 0;
          	}
          }else{
          	printf("Cannot move the lego. It has to be placed before it can be moved. Error in line %d\n", yylineno);
            return 0;
          }
        }
      }
      current = current->next;
    }

    printf("This variable does not exist. Error in line %d\n", yylineno);

    return 0;
}

int update_dir(grid_t * grid, char* id, int coox, int cooy){
    l_list * list = grid->blocks;
    node_t * current = list->head;

    return 0;

    if (list->head == NULL){
      printf("There exist no variables. Error in line %d\n", yylineno);
      return 0;
    }

    while (current != NULL) {
      if((strcmp(current->id, id) == 0)){
        if(current->coox == -1 && current->cooy == -1){
          printf("Cannot move the lego. It has to be placed before it can be moved. Error in line %d\n", yylineno);
          return 0;
        }else{
          current->coox = coox;
          current->cooy = cooy;
          printf("before coox = %d, cooy = %d\n", coox, cooy);
          return 1;
        }
      }
      current = current->next;
    }

    printf("This variable does not exist. Error in line %d\n", yylineno);

    return 0;
}

int rm(grid_t * grid, char* id) {
    l_list * list = grid->blocks;
    node_t* current = list->head;
    node_t* temp = malloc(sizeof(node_t));

    if (list->head == NULL){
      printf("Variable list is empty: could not delete %s. Error in line %d\n", id, yylineno);
      return 0;
    }

    if (strcmp(current->id, id) == 0){
      free(current);
      list->head = current->next;
      delete_in_matrix(grid, current);
      printf("Deleted node id=%s\n", id);
      return 1;
    }

    // delete any element
    while(current->next != NULL){
      if (strcmp(current->next->id, id)==0 ){
        temp = current->next;
        current->next = temp->next;
        free(temp);
        delete_in_matrix(grid, current->next);
        printf("Deleted node id=%s\n", id);
        return 1;
      }
      current = current->next;
    }

    printf("Variable %s does not exist: it cannot be deleted. Error in line %d\n", id, yylineno);
    return 0;
}

int rm_all(grid_t * grid){
    l_list * list = grid->blocks;
    node_t* current = list->head;
    node_t* temp = malloc(sizeof(node_t));

    if (list->head == NULL){
      printf("Variable list is empty: could not delete any element. Error in line %d\n", yylineno);
      return 0;
    }

    // delete any element
    while(current != NULL){
    	//delete_in_matrix(grid, current);
      printf("deleted id=%s\n",current->id );
      temp=current->next;
      free(current);
      current=temp;
      
    }

    //printf("Variable does not exist: it cannot be deleted. Error in line %d\n", yylineno);
    return 1;
}


int main (void) {
  grid_list = create_list();
  return yyparse ( );
}
