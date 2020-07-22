/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

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
#line 1 "archivo_bison.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "ast.c"
#include "comprobacion_tipos.c"
#include "diccionario.h"

extern FILE *output;
extern int lineno;
extern int errores;
void yyerror(char *s);
int yylex();   
DICCIONARIO diccionario;

FILE *mipsOutput;
int declarations_counter = 0;



/* Line 189 of yacc.c  */
#line 95 "archivo_bison.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
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
     V_INTEGER = 258,
     V_FLOAT = 259,
     V_CHAR = 260,
     INT = 261,
     CHAR = 262,
     NATURAL = 263,
     FLOAT = 264,
     POSITIVE = 265,
     STRING = 266,
     BOOLEAN = 267,
     ADD = 268,
     RELATION_EXP = 269,
     EQUALITY_EXP = 270,
     PROCEDURE = 271,
     DESCONOCIDO = 272,
     NOMBRE = 273,
     PCOMA = 274,
     PUTLINE = 275,
     RETURN = 276,
     IF = 277,
     DELIMITADORES = 278,
     COMILLA = 279,
     COMA = 280,
     PIGUAL = 281,
     INCR = 282,
     MULT = 283,
     DIVISION = 284,
     FOR = 285,
     LOOP = 286,
     IN = 287,
     END = 288,
     MAIN = 289,
     IS = 290,
     DOSPUNTOS = 291,
     ELSE = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 22 "archivo_bison.y"

	int ival;
	float fval;
	char type[10];
	char name[20];
	char *sval;
	char cval;

	struct Nodo_AST * nodo;
	union Tipo_Valor * value_type;
	int data_type;



/* Line 214 of yacc.c  */
#line 183 "archivo_bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 195 "archivo_bison.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYLAST   120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  128

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    13,    14,    17,    19,    21,    24,
      26,    29,    31,    34,    36,    39,    41,    44,    46,    48,
      50,    52,    54,    56,    66,    74,    82,    92,   100,   105,
     107,   109,   111,   112,   114,   116,   118,   125,   134,   143,
     147,   151,   159,   167,   175,   183,   191,   199,   207,   213,
     215,   217,   219,   221,   223,   225,   227,   229,   231,   233,
     237,   239,   241,   243,   245,   247,   249
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    41,    -1,    16,     5,    59,    42,    33,
       5,    58,    -1,    -1,    42,    43,    -1,    38,    -1,    47,
      -1,    47,    38,    -1,    48,    -1,    48,    38,    -1,    53,
      -1,    53,    38,    -1,    54,    -1,    54,    38,    -1,    57,
      -1,    57,    38,    -1,    51,    -1,     3,    -1,     5,    -1,
       3,    -1,     5,    -1,    33,    -1,    30,    44,    60,    45,
      61,    43,    46,    61,    58,    -1,     5,    62,    56,    62,
      64,     3,    58,    -1,     5,    62,    56,    62,    64,     4,
      58,    -1,     5,    62,    56,    62,    64,    24,     5,    24,
      58,    -1,     5,    62,    56,    62,    64,     5,    58,    -1,
       5,    62,    56,    58,    -1,    53,    -1,    52,    -1,    54,
      -1,    -1,    48,    -1,    51,    -1,    47,    -1,    22,    23,
      52,    23,    49,    33,    -1,    22,    23,    52,    23,    49,
      37,    49,    33,    -1,    22,    23,    52,    23,    49,    37,
      50,    33,    -1,    55,    14,    55,    -1,    55,    15,    55,
      -1,     5,    62,    64,     3,    13,     3,    58,    -1,     5,
      62,    64,     3,    13,     5,    58,    -1,     5,    62,    64,
       5,    13,     3,    58,    -1,     5,    62,    64,     5,    13,
       5,    58,    -1,     5,    62,    64,     3,    28,     3,    58,
      -1,     5,    62,    64,     3,    29,     3,    58,    -1,    20,
      23,    24,     5,    24,    23,    58,    -1,    20,    23,     5,
      23,    58,    -1,     3,    -1,     5,    -1,     4,    -1,     6,
      -1,     7,    -1,     8,    -1,     9,    -1,    10,    -1,    11,
      -1,    12,    -1,    63,     5,    58,    -1,    19,    -1,    35,
      -1,    32,    -1,    31,    -1,    36,    -1,    21,    -1,    26,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    67,    79,    80,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    96,   101,
     114,   118,   130,   136,   138,   160,   179,   199,   212,   214,
     218,   219,   221,   222,   223,   224,   226,   227,   228,   231,
     246,   258,   286,   326,   366,   411,   420,   431,   436,   456,
     457,   458,   461,   462,   463,   464,   465,   466,   467,   470,
     473,   474,   477,   478,   479,   480,   481
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "V_INTEGER", "V_FLOAT", "V_CHAR", "INT",
  "CHAR", "NATURAL", "FLOAT", "POSITIVE", "STRING", "BOOLEAN", "ADD",
  "RELATION_EXP", "EQUALITY_EXP", "PROCEDURE", "DESCONOCIDO", "NOMBRE",
  "PCOMA", "PUTLINE", "RETURN", "IF", "DELIMITADORES", "COMILLA", "COMA",
  "PIGUAL", "INCR", "MULT", "DIVISION", "FOR", "LOOP", "IN", "END", "MAIN",
  "IS", "DOSPUNTOS", "ELSE", "'\\n'", "$accept", "S", "principal", "input",
  "line", "numerosFor1", "numerosFor2", "endOPfor", "for", "declaraciones",
  "operaciones_cond", "operaciones_cond_text", "condicional",
  "operaciones_bool", "operaciones", "imprimir", "v_type", "tipo",
  "retornar", "pcoma", "is", "in", "loop", "dospuntos", "return", "pigual", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    42,    42,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    44,    44,
      45,    45,    46,    47,    48,    48,    48,    48,    48,    49,
      49,    49,    50,    50,    50,    50,    51,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    57,
      58,    59,    60,    61,    62,    63,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     7,     0,     2,     1,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     9,     7,     7,     9,     7,     4,     1,
       1,     1,     0,     1,     1,     1,     6,     8,     8,     3,
       3,     7,     7,     7,     7,     7,     7,     7,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,    61,     4,     0,     0,
       0,    65,     0,     0,     0,     6,     5,     7,     9,    17,
      11,    13,    15,     0,    64,     0,     0,     0,    18,    19,
       0,     0,     8,    10,    12,    14,    16,     0,    52,    53,
      54,    55,    56,    57,    58,    66,     0,     0,     0,     0,
      49,    51,    50,     0,     0,    62,     0,    60,     3,    59,
      28,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,    48,     0,    50,
       0,    30,    29,    31,    39,    40,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    32,     0,    24,    25,    27,     0,    41,    42,    45,
      46,    43,    44,    47,    50,    35,    33,     0,     0,    34,
      22,     0,     0,    37,    38,     0,    26,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     8,    16,    30,    71,   121,    17,    18,
      80,   118,    19,    81,    20,    21,    54,    46,    22,    58,
       7,    56,    87,    25,    23,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -66
static const yytype_int8 yypact[] =
{
      19,    23,    40,   -66,    47,   -66,   -66,   -66,     0,    44,
      61,   -66,    63,    68,    84,   -66,   -66,    52,    53,   -66,
      54,    55,    56,    90,   -66,    57,    -1,    45,   -66,   -66,
      64,    78,   -66,   -66,   -66,   -66,   -66,    78,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,    51,    69,    75,    94,
     -66,   -66,   -66,    77,    -7,   -66,    72,   -66,   -66,   -66,
     -66,    79,   -10,    88,    78,    80,    21,    45,    45,   -66,
     -66,    71,     7,    73,   100,   103,    76,   -66,    85,    44,
      10,   -66,   -66,   -66,   -66,   -66,   -66,    24,    78,    78,
      78,   102,    78,    78,    78,    78,    78,    78,    78,    79,
     -66,    12,    81,   -66,   -66,   -66,    86,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,    44,   -66,   -66,    82,    83,   -66,
     -66,    71,    78,   -66,   -66,    78,   -66,   -66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,   -66,   -66,    22,   -66,   -66,   -66,    11,    16,
      17,   -66,    18,    93,   -65,   -64,   -54,   -66,   -66,   -37,
     -66,   -66,    -8,   -40,   -66,    50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      59,    82,    83,    73,    48,     9,    61,    67,    68,    60,
      88,    89,    90,    84,    85,    50,    51,   114,    74,    75,
      10,    11,    12,    49,    50,    51,    79,    77,     4,     9,
      13,    91,    10,    14,    12,     1,    82,    83,    15,    99,
       5,    10,    13,   100,    10,    11,    12,   101,    50,    51,
      52,   103,   104,   105,    13,   107,   108,   109,   110,   111,
     112,   113,    15,    38,    39,    40,    41,    42,    43,    44,
      57,    28,    62,    29,    63,    69,    92,    70,    93,    96,
      24,    97,     6,    45,    26,   126,    27,    24,   127,    31,
      32,    33,    34,    35,    36,    37,    55,    57,    64,    65,
      66,    76,    86,    94,    78,    45,    95,   106,    98,   102,
     122,    72,   115,   125,   120,   123,   124,   116,   117,   119,
      53
};

static const yytype_uint8 yycheck[] =
{
      37,    66,    66,    13,     5,     5,    46,    14,    15,    46,
       3,     4,     5,    67,    68,     3,     4,     5,    28,    29,
      20,    21,    22,    24,     3,     4,     5,    64,     5,     5,
      30,    24,    20,    33,    22,    16,   101,   101,    38,    79,
       0,    20,    30,    33,    20,    21,    22,    37,     3,     4,
       5,    88,    89,    90,    30,    92,    93,    94,    95,    96,
      97,    98,    38,     6,     7,     8,     9,    10,    11,    12,
      19,     3,     3,     5,     5,     3,     3,     5,     5,     3,
      36,     5,    35,    26,    23,   122,    23,    36,   125,     5,
      38,    38,    38,    38,    38,     5,    32,    19,    23,     5,
      23,    13,    31,     3,    24,    26,     3,     5,    23,    87,
      24,    61,   101,   121,    33,    33,    33,   101,   101,   101,
      27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    40,    41,     5,     0,    35,    59,    42,     5,
      20,    21,    22,    30,    33,    38,    43,    47,    48,    51,
      53,    54,    57,    63,    36,    62,    23,    23,     3,     5,
      44,     5,    38,    38,    38,    38,    38,     5,     6,     7,
       8,     9,    10,    11,    12,    26,    56,    64,     5,    24,
       3,     4,     5,    52,    55,    32,    60,    19,    58,    58,
      58,    62,     3,     5,    23,     5,    23,    14,    15,     3,
       5,    45,    64,    13,    28,    29,    13,    58,    24,     5,
      49,    52,    53,    54,    55,    55,    31,    61,     3,     4,
       5,    24,     3,     5,     3,     3,     3,     5,    23,    62,
      33,    37,    43,    58,    58,    58,     5,    58,    58,    58,
      58,    58,    58,    58,     5,    47,    48,    49,    50,    51,
      33,    46,    24,    33,    33,    61,    58,    58
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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

/* Line 1464 of yacc.c  */
#line 62 "archivo_bison.y"
    { 
		fprintf(output, "Terminada la compilación!!"); 
			// prueba_impresion_declaracion(mipsOutput);
		;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 68 "archivo_bison.y"
    {
			char * first_name = (yyvsp[(2) - (7)].name);
			char * last_name = (yyvsp[(6) - (7)].name);
			if(strcmp(first_name, last_name) != 0) {
				printf("ERROR: El nombre del procedimiento debe ser el mismo al inicio y al final \n");
			}
			char n = '"';
			fprintf(mipsOutput,"\nend :\n.data\n\tspace : .asciiz %c\\n%c",n,n);
		;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 97 "archivo_bison.y"
    {	
		printf("hola\n");
		fprintf(mipsOutput,"\ninitialize:\n\tadd $s1, $zero, %d",(yyvsp[(1) - (1)].ival))
	;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 102 "archivo_bison.y"
    {
		printf("El nombre de la variable es: %s\n", (yyvsp[(1) - (1)].name));
		ENTRADA * entrada = buscar_diccionario(&diccionario,(yyvsp[(1) - (1)].name));
		if (entrada != NULL) {
			char * valor = entrada->valor;
			fprintf(mipsOutput,"\ninitialize:\n\tadd $s1, $zero, %s", valor);
		} else {
			printf("ERROR: variable %s no definida\n", (yyvsp[(1) - (1)].name));
		}
	;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 115 "archivo_bison.y"
    {
				fprintf(mipsOutput,"\n\taddi $s2, $zero,%d\npredicate:\n\tslt $t0, $s1, $s2 \n\tbeq $t0, $zero, endfor \nconsequent:\n\taddi $s1, $s1, 0 \n",(yyvsp[(1) - (1)].ival))
			;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 119 "archivo_bison.y"
    {
			 	ENTRADA * entrada = buscar_diccionario(&diccionario,(yyvsp[(1) - (1)].name));
                if (entrada != NULL) {
					char * valor = entrada->valor;
					fprintf(mipsOutput,"\n\taddi $s2, $zero,%s\npredicate:\n\tslt $t0, $s1, $s2\n\tbeq $t0, $zero, endfor\nconsequent:\n\taddi $s1, $s1, 0\n", valor);
				} else {
					printf("ERROR: variable %s no definida\n", (yyvsp[(1) - (1)].name));
				}
			;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 131 "archivo_bison.y"
    {
		fprintf(mipsOutput,"\taddi $s1, $s1, 1 \n\tj predicate \nendfor: \n")
	;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 139 "archivo_bison.y"
    {
					// a:Integer:=8;
					// &diccionario: es la dirección de memoria en la que se encuentra guardado.
					ENTRADA *entrada = buscar_diccionario(&diccionario,(yyvsp[(1) - (7)].name));
					int esValido;
					comprobar_tipo(&esValido, (yyvsp[(3) - (7)].data_type), 2);
					if(entrada == NULL && esValido == 1) {
						char integer[64];
						sprintf(integer, "%d", (yyvsp[(6) - (7)].ival));
						printf("%s\n", integer);
						insertar_diccionario(&diccionario, (yyvsp[(1) - (7)].name), (yyvsp[(3) - (7)].data_type), integer);
						fprintf(output, "Valor de la V_CHAR %i\n",(yyvsp[(6) - (7)].ival), lineno-1);
						// Nodo_AST *nodo = new_declaracion_Node_AST(2, $1, integer, &declarations_counter, mipsOutput);
					} else if(entrada == NULL && esValido == 0){
						printf("ERROR: %s no coincide el valor con el tipo de la V_CHAR %s. El valor tiene que ser: %s.\n", (yyvsp[(3) - (7)].data_type), (yyvsp[(1) - (7)].name), "Integer"); 
					} else {
						printf("ERROR: V_CHAR %s ya existe.\n", (yyvsp[(1) - (7)].name)); 
						
					}
				;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 161 "archivo_bison.y"
    {
					// a:Float:=8.6;
					ENTRADA *entrada = buscar_diccionario(&diccionario,(yyvsp[(1) - (7)].name));
					int esValido;
					comprobar_tipo(&esValido, (yyvsp[(3) - (7)].data_type), 4);
					if(entrada == NULL && esValido == 1) {
						char v_float[64];
						sprintf(v_float, "%f", (yyvsp[(6) - (7)].fval));
						insertar_diccionario(&diccionario, (yyvsp[(1) - (7)].name), (yyvsp[(3) - (7)].data_type), v_float);
						fprintf(output, "Valor de la V_CHAR %i\n",(yyvsp[(6) - (7)].fval), lineno-1);
						Nodo_AST *nodo = new_declaracion_Node_AST(4, (yyvsp[(1) - (7)].name), v_float, &declarations_counter, mipsOutput);
					} else if(entrada == NULL && esValido == 0){
						printf("ERROR: %s no coincide el valor con el tipo de la V_CHAR %s. El valor tiene que ser: %s.\n", (yyvsp[(3) - (7)].data_type), (yyvsp[(1) - (7)].name), "Float"); 
					} else {
						printf("ERROR: V_CHAR %s ya existe.\n", (yyvsp[(1) - (7)].name)); 
					}
				;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 180 "archivo_bison.y"
    {
					// a:String:="Hola";
					ENTRADA *entrada = buscar_diccionario(&diccionario,(yyvsp[(1) - (9)].name));
					int esValido;
					comprobar_tipo(&esValido, (yyvsp[(3) - (9)].data_type), 6);
					if(entrada == NULL && esValido == 1) {
						insertar_diccionario(&diccionario, (yyvsp[(1) - (9)].name),(yyvsp[(3) - (9)].data_type), (yyvsp[(7) - (9)].name));
						fprintf(output, "Valor de la V_CHAR %i\n",(yyvsp[(7) - (9)].name), lineno-1);
						Nodo_AST *nodo = new_declaracion_Node_AST(6, (yyvsp[(1) - (9)].name), (yyvsp[(7) - (9)].name),&declarations_counter, mipsOutput);
					} else if(entrada == NULL && esValido == 0){
						printf("ERROR: %s no coincide el valor con el tipo de la V_CHAR %s. El valor tiene que ser: %s.\n", (yyvsp[(3) - (9)].data_type), (yyvsp[(1) - (9)].name), "String"); 
					} else {
						printf("ERROR: V_CHAR %s ya existe.\n", (yyvsp[(1) - (9)].name)); 
					}
				;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 200 "archivo_bison.y"
    {
					// a:Integer:=b;
					ENTRADA *entrada = buscar_diccionario(&diccionario,(yyvsp[(6) - (7)].name));
					if (entrada != NULL) {
						char* valor = entrada->valor;
						insertar_diccionario(&diccionario, (yyvsp[(1) - (7)].name), (yyvsp[(3) - (7)].data_type), valor);
						fprintf(output, "Valor de la V_CHAR %i\n",(yyval.ival), lineno-1);
					} else { 
						(yyval.ival) = 0;
						printf("ERROR: V_CHAR %s no definida\n", (yyvsp[(6) - (7)].name)); 
					} 
				;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 215 "archivo_bison.y"
    {
				fprintf(mipsOutput,"j end \n endif%i: ",lineno-2);
			;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 232 "archivo_bison.y"
    { 
				char * signo = (yyvsp[(2) - (3)].sval);
				printf("El operador del condicional es: %s\n", signo);
				if((strcmp(signo, ">") == 0) || (strcmp(signo, ">=") == 0)) {
					printf("Mayor o mayor-igual!\n");
					char* b = generate();
					fprintf(mipsOutput,"\n.text\n\taddi $s1,$zero, %i\n\taddi $s2,$zero, %i\n\tslt $t3, $s1, $s2\n\tbeq $t3, $zero,alternate%s\nj endif%i\n\talternate%s:",(yyvsp[(1) - (3)].ival),(yyvsp[(3) - (3)].ival),b,lineno-1,b);
				} else if((strcmp(signo, "<") == 0) || (strcmp(signo, "<=") == 0)) {
					printf("Menor o menor-igual!\n");
					char* b = generate();
					fprintf(mipsOutput,"\n.text\n\taddi $s1,$zero, %i\n\taddi $s2,$zero, %i\n\tslt $t3, $s2, $s1\n\tbeq $t3, $zero,alternate%s\nj endif%i\n\talternate%s:",(yyvsp[(1) - (3)].ival),(yyvsp[(3) - (3)].ival),b,lineno-1,b);

				}
			;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 247 "archivo_bison.y"
    { 
				char * signo = (yyvsp[(2) - (3)].sval);
				printf("El operador del condicional es: %s\n", signo);
				if((strcmp(signo, "==") == 0)) {
					printf("Igual!\n");
					char* b = generate();
					fprintf(mipsOutput,"\n.text\n\taddi $s1,$zero, %i\n\taddi $s2,$zero, %i\n\tbeq $s1, $s2,alternate%s\nj endif%i\nalternate%s:",(yyvsp[(1) - (3)].ival),(yyvsp[(3) - (3)].ival),b,lineno-1,b);
				}
			;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 259 "archivo_bison.y"
    {
				// char * signo = $5;
				char * c_result;
				int result;
				if (strcmp((yyvsp[(5) - (7)].sval), "+") == 0) {
					printf("OPERACIONES: Suma.\n");
					char* primera = generate();
					char* segunda = generate();
					fprintf(mipsOutput,"\n.data\n\t%s: .word %d\n\t%s: .word %d\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tadd $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, (yyvsp[(4) - (7)].ival), segunda, (yyvsp[(6) - (7)].ival), primera, segunda);
					int valor = (yyvsp[(4) - (7)].ival) + (yyvsp[(6) - (7)].ival);
					char integer[64];
					sprintf(integer, "%d", valor);
					insertar_diccionario(&diccionario, (yyvsp[(1) - (7)].name), 2, integer);

				} else {
					printf("OPERACIONES: Resta.\n");
					char* primera = generate();
					char* segunda = generate();
					fprintf(mipsOutput,"\n.data\n\t%s: .word %d\n\t%s: .word %d\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tsub $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, (yyvsp[(4) - (7)].ival), segunda, (yyvsp[(6) - (7)].ival), primera, segunda);
					int valor = (yyvsp[(4) - (7)].ival) - (yyvsp[(6) - (7)].ival);
					char integer[64];
					sprintf(integer, "%d", valor);
					insertar_diccionario(&diccionario, (yyvsp[(1) - (7)].name), 2, integer);

				}
			;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 287 "archivo_bison.y"
    {
				// char * signo = $5;
				char * c_result;
				ENTRADA *entrada = buscar_diccionario(&diccionario,(yyvsp[(6) - (7)].name));
				if(entrada != NULL) {
					char * valor = entrada->valor;
					if (strcmp((yyvsp[(5) - (7)].sval), "+") == 0) {
						printf("OPERACIONES: Suma (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						printf("%s\n", valor);
						fprintf(mipsOutput,"\n.data\n\t%s: .word %d\n\t%s: .word %s\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tadd $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, (yyvsp[(4) - (7)].ival), segunda, valor, primera, segunda);

						int value_int;
						sscanf(valor, "%d", &value_int);
						int suma = (yyvsp[(4) - (7)].ival) + value_int;
						
						char integer[64];
						sprintf(integer, "%d", suma);
						insertar_diccionario(&diccionario, (yyvsp[(1) - (7)].name), 2, integer);

					} else {
						printf("OPERACIONES: Resta (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						printf("%s\n", valor);
						fprintf(mipsOutput,"\n.data\n\t%s: .word %d\n\t%s: .word %s\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tsub $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, (yyvsp[(4) - (7)].ival), segunda, valor, primera, segunda);
						
						int value_int;
						sscanf(valor, "%d", &value_int);
						int resta = (yyvsp[(4) - (7)].ival) - value_int;
						
						char integer[64];
						sprintf(integer, "%d", resta);
						insertar_diccionario(&diccionario, (yyvsp[(1) - (7)].name), 2, integer);
					}
					

				}
			;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 327 "archivo_bison.y"
    {
				// char * signo = $5;
				char * c_result;
				ENTRADA *entrada = buscar_diccionario(&diccionario,(yyvsp[(4) - (7)].name));
				if(entrada != NULL) {
					char * valor = entrada->valor;
					if (strcmp((yyvsp[(5) - (7)].sval), "+") == 0) {
						printf("OPERACIONES: Suma (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						printf("%s\n", valor);
						fprintf(mipsOutput,"\n.data\n\t%s: .word %s\n\t%s: .word %d\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tadd $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, valor, segunda, (yyvsp[(6) - (7)].ival), primera, segunda);

						int value_int;
						sscanf(valor, "%d", &value_int);
						int suma = value_int + (yyvsp[(6) - (7)].ival);
						
						char integer[64];
						sprintf(integer, "%d", suma);
						insertar_diccionario(&diccionario, (yyvsp[(1) - (7)].name), 2, integer);

					} else {
						printf("OPERACIONES: Resta (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						printf("%s\n", valor);
						fprintf(mipsOutput,"\n.data\n\t%s: .word %s\n\t%s: .word %d\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tsub $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, valor, segunda, (yyvsp[(6) - (7)].ival), primera, segunda);

						int value_int;
						sscanf(valor, "%d", &value_int);
						int resta = value_int - (yyvsp[(6) - (7)].ival);
						
						char integer[64];
						sprintf(integer, "%d", resta);
						insertar_diccionario(&diccionario, (yyvsp[(1) - (7)].name), 2, integer);

					}

				}
			;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 367 "archivo_bison.y"
    {
				// char * signo = $5;
				char * c_result;
				ENTRADA *entrada1 = buscar_diccionario(&diccionario,(yyvsp[(4) - (7)].name));
				ENTRADA *entrada2 = buscar_diccionario(&diccionario,(yyvsp[(6) - (7)].name));
				if(entrada1 != NULL && entrada2 != NULL) {
					char * valor1 = entrada1->valor;
					char * valor2 = entrada2->valor;
					if (strcmp((yyvsp[(5) - (7)].sval), "+") == 0) {
						printf("OPERACIONES: Suma (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						fprintf(mipsOutput,"\n.data\n\t%s: .word %s\n\t%s: .word %s\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tadd $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, valor1, segunda, valor2, primera, segunda);

						int value_int1;
						int value_int2;
						sscanf(valor1, "%d", &value_int1);
						sscanf(valor2, "%d", &value_int2);
						int suma = value_int1 + value_int2;
						
						char integer[64];
						sprintf(integer, "%d", suma);
						insertar_diccionario(&diccionario, (yyvsp[(1) - (7)].name), 2, integer);

					} else {
						printf("OPERACIONES: Resta (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						fprintf(mipsOutput,"\n.data\n\t%s: .word %s\n\t%s: .word %s\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tsub $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, valor1, segunda, valor2, primera, segunda);
						
						int value_int1;
						int value_int2;
						sscanf(valor1, "%d", &value_int1);
						sscanf(valor2, "%d", &value_int2);
						int resta = value_int1 - value_int2;

						char integer[64];
						sprintf(integer, "%d", resta);
						insertar_diccionario(&diccionario, (yyvsp[(1) - (7)].name), 2, integer);

					}

				}
			;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 412 "archivo_bison.y"
    {
				printf("OPERACIONES: Multiplicacion.\n");
				char* primera = generate();
				char* segunda = generate();
				int result = (yyvsp[(4) - (7)].ival) * (yyvsp[(6) - (7)].ival); 
				printf("\t%d\n", result);
				fprintf(mipsOutput,"\n.text\n\taddi $t0,$zero, %i\n\taddi $t1,$zero, %i\n\tmul $t2, $t0, $t1\nli $v0, 1\n\tmove $a0, $t2 \nsyscall \n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n",(yyvsp[(4) - (7)].ival),(yyvsp[(6) - (7)].ival),(yyvsp[(4) - (7)].ival),(yyvsp[(6) - (7)].ival));
			;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 421 "archivo_bison.y"
    {
				printf("OPERACIONES: Division.\n");
				char* primera = generate();
				char* segunda = generate();
				double result = (yyvsp[(4) - (7)].ival) / (yyvsp[(6) - (7)].ival);
				printf("\t%d\n", result);
				fprintf(mipsOutput,"\n .text\n addi $t0,$zero, %i\n addi $t1,$zero, %i\n div $t2, $t0, $t1 \nli $v0, 1\n  move $a0, $t2 \n	syscall \n addi $v0, $zero, 4\n la $a0, space \n syscall \n",(yyvsp[(4) - (7)].ival),(yyvsp[(6) - (7)].ival),(yyvsp[(4) - (7)].ival),(yyvsp[(6) - (7)].ival));
			;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 432 "archivo_bison.y"
    {
				printf("%s de tipo %d:\n", (yyvsp[(4) - (7)].name), "String");

			;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 437 "archivo_bison.y"
    {	
				ENTRADA *entrada = buscar_diccionario(&diccionario,(yyvsp[(3) - (5)].name));
                if (entrada != NULL) {
					char * valor = entrada->valor;
					printf("(bison.y) ENCONTRADO! Valor entrada: %s\n", valor);
					int type = entrada->tipo;
					if(type == 2 || type == 4) {
						printf("%s\n", entrada->valor);

					} else {
						printf("%s\n", entrada->valor);
					}
				} else {
					(yyval.ival) = 0;
					printf("ERROR: V_CHAR %s no definida\n", (yyvsp[(3) - (5)].name));
				}
			;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 461 "archivo_bison.y"
    { (yyval.data_type) = TYPE_INT;  printf("Integer.\n")   ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 462 "archivo_bison.y"
    { (yyval.data_type) = TYPE_CHAR;  ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 463 "archivo_bison.y"
    { (yyval.data_type) = TYPE_NAT;  ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 464 "archivo_bison.y"
    { (yyval.data_type) = TYPE_FLOAT; printf("Float.\n") ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 465 "archivo_bison.y"
    { (yyval.data_type) = TYPE_POSITIVE;  ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 466 "archivo_bison.y"
    { (yyval.data_type) = TYPE_STRING;  ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 467 "archivo_bison.y"
    { (yyval.data_type) = TYPE_BOOLEAN;  ;}
    break;



/* Line 1464 of yacc.c  */
#line 2009 "archivo_bison.tab.c"
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



/* Line 1684 of yacc.c  */
#line 483 "archivo_bison.y"


extern FILE *yyin;
int main(int argc,char *argv[])
{	
    char filename[40];
	++argv, --argc; /* se salta el nombre del programa */
	if (argc>0)
		yyin = fopen(argv[0], "r");
	else {
		printf("Introduzca el nombre del fichero de entrada: ");
		scanf("%s", &filename);
		inicializar_diccionario(&diccionario);
		yyin = fopen(filename, "r");
		mipsOutput = fopen( "./mipsOutput.txt", "wt" );
        if ((output = fopen( "./lexOutput.txt", "wt" )) == NULL )
        {
            printf("Error creando el fichero de salida.\n");
        } else {
            fprintf(output,"%-50s%-30s%-15s\n", "TOKEN","LEXEMA","LINEA");
            yyparse();
            printf("\nFichero de salida creado correctamente.\n");
        }
        fclose(yyin);
	}
	liberar_diccionario(&diccionario);
    return 0;
}

void yyerror(char *s) {
    printf("%d: %s\n", lineno, s) ;
}



