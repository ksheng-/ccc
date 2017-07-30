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
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ptypes.h"
#include "sym.h"
#include "ast.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);

int current_line = 0;
char current_file[FILENAME_MAX];
int debug = 0;

scope_stack scopes;

astnode *ast_head;
astnode *ast_tail;


#line 91 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 258,
    CHARLIT = 259,
    STRING = 260,
    NUMBER = 261,
    TOKEOF = 262,
    ELLIPSIS = 263,
    AUTO = 264,
    BREAK = 265,
    CASE = 266,
    CHAR = 267,
    CONST = 268,
    CONTINUE = 269,
    DEFAULT = 270,
    DO = 271,
    DOUBLE = 272,
    ENUM = 273,
    EXTERN = 274,
    FLOAT = 275,
    FOR = 276,
    GOTO = 277,
    INLINE = 278,
    INT = 279,
    LONG = 280,
    REGISTER = 281,
    RESTRICT = 282,
    RETURN = 283,
    SHORT = 284,
    SIGNED = 285,
    SIZEOF = 286,
    STATIC = 287,
    STRUCT = 288,
    SWITCH = 289,
    TYPEDEF = 290,
    UNION = 291,
    UNSIGNED = 292,
    VOID = 293,
    VOLATILE = 294,
    WHILE = 295,
    _BOOL = 296,
    _COMPLEX = 297,
    _IMAGINARY = 298,
    PLUSEQ = 299,
    MINUSEQ = 300,
    TIMESEQ = 301,
    DIVEQ = 302,
    MODEQ = 303,
    SHLEQ = 304,
    SHREQ = 305,
    ANDEQ = 306,
    XOREQ = 307,
    OREQ = 308,
    LOGOR = 309,
    LOGAND = 310,
    EQEQ = 311,
    NOTEQ = 312,
    LTEQ = 313,
    GTEQ = 314,
    SHL = 315,
    SHR = 316,
    INDSEL = 317,
    PLUSPLUS = 318,
    MINUSMINUS = 319,
    UNARY = 320,
    IF = 321,
    ELSE = 322
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "parser.y" /* yacc.c:355  */

    char *string;
    char character;
    num number;
    astnode *node;

#line 206 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 223 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  362

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,     2,     2,     2,    75,    62,     2,
      81,    82,    73,    71,    44,    72,    88,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    89,
      65,    45,    67,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    86,     2,    87,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,    60,    91,    79,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    58,
      59,    63,    64,    66,    68,    69,    70,    76,    77,    78,
      83,    84,    85
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   104,   109,   114,   119,   125,   126,   136,
     141,   142,   143,   144,   150,   158,   159,   162,   163,   169,
     175,   179,   180,   183,   188,   193,   198,   203,   208,   215,
     216,   219,   220,   227,   234,   243,   244,   251,   260,   261,
     268,   277,   278,   285,   292,   299,   308,   309,   316,   325,
     326,   335,   336,   345,   346,   355,   356,   365,   366,   375,
     376,   379,   380,   389,   390,   396,   402,   408,   414,   420,
     426,   432,   438,   444,   453,   457,   460,   464,   469,   477,
     478,   479,   483,   490,   491,   494,   518,   544,   545,   548,
     549,   550,   551,   552,   555,   560,   565,   570,   576,   581,
     586,   591,   596,   601,   602,   605,   606,   607,   610,   611,
     614,   615,   618,   621,   622,   623,   624,   627,   628,   631,
     632,   633,   636,   637,   638,   641,   642,   645,   646,   649,
     654,   661,   662,   668,   677,   678,   684,   698,   699,   700,
     701,   702,   710,   711,   712,   718,   726,   727,   733,   734,
     737,   738,   741,   742,   743,   746,   747,   750,   751,   754,
     755,   756,   759,   760,   761,   762,   763,   764,   765,   766,
     767,   768,   769,   775,   776,   777,   780,   781,   785,   786,
     787,   788,   789,   790,   793,   798,   799,   802,   803,   803,
     810,   811,   814,   815,   817,   818,   821,   828,   835,   838,
     844,   850,   851,   852,   855,   856,   857,   858,   859,   863,
     864,   867,   868,   871,   878,   879,   880,   883,   884
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "CHARLIT", "STRING", "NUMBER",
  "TOKEOF", "ELLIPSIS", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ENUM", "EXTERN", "FLOAT", "FOR",
  "GOTO", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT", "RETURN",
  "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF",
  "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "_BOOL", "_COMPLEX",
  "_IMAGINARY", "','", "'='", "PLUSEQ", "MINUSEQ", "TIMESEQ", "DIVEQ",
  "MODEQ", "SHLEQ", "SHREQ", "ANDEQ", "XOREQ", "OREQ", "'?'", "':'",
  "LOGOR", "LOGAND", "'|'", "'^'", "'&'", "EQEQ", "NOTEQ", "'<'", "LTEQ",
  "'>'", "GTEQ", "SHL", "SHR", "'+'", "'-'", "'*'", "'/'", "'%'", "INDSEL",
  "PLUSPLUS", "MINUSMINUS", "'~'", "'!'", "'('", "')'", "UNARY", "IF",
  "ELSE", "'['", "']'", "'.'", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "$@1", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    44,    61,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    63,    58,   309,   310,
     124,    94,    38,   311,   312,    60,   313,    62,   314,   315,
     316,    43,    45,    42,    47,    37,   317,   318,   319,   126,
      33,    40,    41,   320,   321,   322,    91,    93,    46,    59,
     123,   125
};
# endif

#define YYPACT_NINF -187

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-187)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1104,  -187,  -187,  -187,  -187,  -187,     7,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,    23,    58,  -187,    26,  1280,  1280,  -187,    20,  -187,
    1280,   848,   -22,    47,   783,  -187,  -187,   -47,    49,  -187,
    -187,    23,    19,  -187,   -17,  -187,   814,  -187,  -187,    27,
    1308,  -187,    55,  -187,    26,  -187,   848,   888,   184,   -22,
    -187,  -187,    49,    98,   -25,  -187,  -187,  -187,  -187,    58,
    -187,   483,  -187,   848,  1308,  1308,   916,  -187,    48,  1308,
    -187,   391,   137,  -187,  -187,  -187,  -187,     8,   120,   145,
    -187,   -12,   128,   141,  -187,   168,   -24,  1152,    49,  -187,
    -187,  -187,  -187,  -187,  -187,  1164,  -187,  -187,  -187,  -187,
    1176,  1176,  -187,  -187,  1073,   483,  -187,   157,   271,  1152,
    -187,   125,   107,   170,    69,   191,   175,   169,   172,   183,
      30,  -187,  -187,  -187,  -187,   944,  -187,  -187,  -187,  1152,
      -9,  -187,   189,  -187,   194,   171,  1152,   173,   212,   445,
     197,   290,   599,   216,   234,   246,  -187,  -187,    -6,  -187,
    -187,  -187,  -187,   270,  -187,  -187,  -187,  -187,  -187,   724,
     642,  -187,    41,  -187,    52,  -187,  1180,   325,  -187,  -187,
    -187,   243,  -187,  -187,  -187,  -187,  -187,  1073,  -187,  1152,
    -187,  -187,    10,   115,   249,  -187,   -20,   330,  -187,  -187,
     981,  1152,   331,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  1152,  -187,  1152,  1152,  1152,  1152,
    1152,  1152,  1152,  1152,  1152,  1152,  1152,  1152,  1152,  1152,
    1152,  1152,  1152,  1152,  1152,  -187,  -187,    48,  -187,  1152,
     445,  -187,   278,  -187,   445,   296,   562,   248,  -187,    -4,
    1152,  1152,  1152,  1152,  -187,  -187,  -187,  -187,   256,   258,
     257,  -187,   259,    52,  1001,   693,  -187,  -187,  -187,  -187,
     263,  -187,  1249,   127,  -187,  1152,   308,  -187,  -187,  -187,
      21,  -187,   -13,  -187,  -187,  -187,  -187,  -187,   125,   125,
     107,   107,   170,   170,   170,   170,    69,    69,   191,   175,
     169,   172,   -29,   183,  -187,  -187,  -187,   445,  -187,   272,
     613,   613,  -187,  -187,   103,   104,   143,  -187,  -187,  -187,
    -187,  -187,  -187,   273,   265,  -187,   269,  -187,  -187,  -187,
    -187,  1152,  -187,  -187,  1152,  -187,  1152,   993,   275,   445,
     445,   445,  -187,  -187,  -187,  -187,  -187,   147,   445,   149,
     445,  -187,  -187,   277,   274,  -187,   445,  -187,   445,  -187,
    -187,  -187
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,    92,    95,   129,   100,     0,    90,    99,    97,
      98,    93,    96,   101,    91,   108,    89,   109,   102,    94,
     130,   142,     0,   212,     0,    79,    81,   103,     0,   104,
      83,     0,   131,     0,     0,   209,   211,   124,     0,   146,
     144,   143,     0,    77,     0,    85,    87,    80,    82,   107,
       0,    84,   188,   217,     0,   216,     0,     0,     0,   132,
       1,   210,     0,   127,     0,   125,   147,   145,   134,     0,
      78,     0,   213,     0,     0,   113,     0,   110,     0,   115,
     187,     0,    87,   218,   215,   155,   141,   154,     0,   148,
     150,     0,     0,     0,   135,     0,     0,     0,     0,   122,
      86,     2,     4,     5,     3,     0,    23,    25,    26,    24,
       0,     0,    27,    28,     0,     0,     7,    17,    29,     0,
      31,    35,    38,    41,    46,    49,    51,    53,    55,    57,
      59,    61,   173,    88,   214,     0,   114,   105,   111,     0,
       0,   117,   119,   116,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   194,    74,     0,   192,
     193,   178,   179,     0,   190,   180,   181,   182,   183,     0,
       0,   152,   159,   153,   160,   139,     0,     0,   140,   136,
     137,     0,   123,    29,    76,   128,   126,     0,    21,     0,
      18,    19,     0,   157,     0,   176,     0,     0,    13,    14,
       0,     0,     0,    63,    67,    68,    64,    65,    66,    69,
      70,    71,    72,    73,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   120,     0,   112,     0,
       0,   206,     0,   205,     0,     0,     0,     0,   207,     0,
       0,     0,     0,     0,   195,   189,   191,   169,     0,     0,
      24,   163,     0,   161,     0,     0,   149,   151,   156,   138,
       0,     6,     0,   159,   158,     0,     0,   174,    12,     9,
       0,    15,     0,    11,    62,    32,    33,    34,    36,    37,
      39,    40,    42,    44,    43,    45,    47,    48,    50,    52,
      54,    56,     0,    58,   118,   121,   184,     0,   186,     0,
       0,     0,   204,   208,     0,     0,     0,    75,   170,   162,
     167,   164,   171,     0,    24,   165,     0,    22,    30,   175,
     177,     0,    10,     8,     0,   185,     0,     0,     0,     0,
       0,     0,   172,   168,   166,    16,    60,     0,     0,     0,
       0,   198,   199,   196,     0,   202,     0,   201,     0,   200,
     203,   197
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,  -187,   -64,  -187,   -98,    39,    44,    24,
      40,   129,   134,   135,   133,   138,  -187,   -90,   -70,  -187,
    -110,  -130,    17,     0,  -187,   298,  -187,   142,  -187,  -187,
     294,   -59,   -61,  -187,   132,  -187,   309,   276,    37,    15,
     -27,   -19,   315,   -54,  -187,   199,  -187,   190,   -79,  -167,
    -103,  -187,  -136,  -187,   163,  -187,  -187,   213,  -186,  -187,
    -187,  -187,  -187,   344,  -187,   336
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   116,   117,   280,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   157,   214,
     158,   185,    23,    54,    44,    45,    25,    26,    27,    28,
      76,    77,    78,   140,   141,    29,    64,    65,    30,    31,
      32,    33,    41,   258,    89,    90,    91,   194,   259,   174,
     133,   196,   160,   161,   162,    81,   163,   164,   165,   166,
     167,   168,    34,    35,    36,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      24,   132,    40,    88,   192,   263,    59,   184,   173,   236,
      37,     1,   195,   245,   136,   253,   242,   138,   143,    98,
      98,   215,    67,    49,   276,    47,    48,    69,   334,     1,
      51,   253,   177,   183,    24,   237,     4,    42,   253,    46,
     253,   188,   249,    62,     1,   132,   190,   191,    53,   184,
       1,     1,    63,   193,   253,   183,   184,    87,    39,    57,
     311,     1,    20,    53,    58,   331,    99,   182,   172,    82,
     178,   277,    70,    83,   333,   183,   138,   192,    66,   192,
     238,    21,   183,   254,    82,   313,   233,    79,   234,   169,
      83,   282,   271,   142,   170,    39,    21,    38,   159,    21,
     262,    68,   171,   332,   306,   139,   263,    22,   308,   305,
      50,    79,    79,    79,   274,    43,    79,    74,   285,   286,
     287,    21,   169,   302,   337,   338,   193,   170,    22,    22,
     281,    21,    66,   264,   223,   224,   225,   226,   265,    22,
     314,   315,   316,    97,   284,    59,    80,   253,   253,   184,
     172,    79,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,    87,
     183,   335,    79,   330,   273,   183,    87,   328,   219,   220,
     159,     4,    71,   317,    42,   339,   340,   253,    21,   176,
      92,   253,    75,   253,    55,   326,   272,     4,   216,   217,
     218,   170,   175,   351,   352,   353,   132,    20,   272,    72,
     323,   183,   355,   170,   357,   179,    75,    75,    75,    84,
     360,    75,   361,    20,    79,   341,   347,   349,   180,   354,
     230,   356,   231,   197,   198,   199,   134,   229,   200,   221,
     222,   181,   232,   201,   346,   202,   239,   292,   293,   294,
     295,   240,   142,   273,   227,   228,    75,    93,   288,   289,
     241,   345,   243,   310,    87,   290,   291,   296,   297,   244,
     183,    94,    87,   144,   102,   103,   104,    75,   246,     2,
     145,   146,     3,     4,   147,   148,   149,     5,     6,     7,
       8,   150,   151,   247,     9,    10,    11,   250,   152,    12,
      13,   105,    14,    15,   153,    16,    17,    18,    19,    20,
     154,   101,   102,   103,   104,   251,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   252,   268,    75,
     269,   275,   106,   278,   283,   307,   309,   312,   318,   105,
     319,   107,   108,   109,   320,   327,   321,   110,   111,   112,
     113,   114,   343,   336,   155,   342,   344,   350,   298,   156,
      52,   255,   358,   359,   299,   301,   300,   100,   135,   304,
     106,    96,   303,    95,   186,   267,   256,   270,    61,   107,
     108,   109,    73,     0,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   144,   102,   103,   104,   115,   329,
       2,   145,   146,     3,     4,   147,   148,   149,     5,     6,
       7,     8,   150,   151,     0,     9,    10,    11,     0,   152,
      12,    13,   105,    14,    15,   153,    16,    17,    18,    19,
      20,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   102,
     103,   104,     0,   106,     0,   145,   146,     0,     0,   147,
     148,   149,   107,   108,   109,     0,   150,   151,   110,   111,
     112,   113,   114,   152,     0,   155,   105,     0,     0,   153,
     156,    52,     0,     0,     0,   154,   101,   102,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,     0,
       0,     0,     0,     0,   105,     0,   107,   108,   109,     0,
       0,     0,   110,   111,   112,   113,   114,     0,     0,   155,
       0,     0,     0,     0,   156,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   101,   102,   103,   104,     0,
       0,     2,     0,   115,     3,     4,     0,     0,     0,     5,
       6,     7,     8,     0,     0,     0,     9,    10,    11,     0,
       0,    12,    13,   105,    14,    15,     0,    16,    17,    18,
      19,    20,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
     105,     0,     0,   107,   108,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   105,   101,   102,   103,   104,     0,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
     107,   108,   109,   105,     0,   106,   110,   111,   112,   113,
     114,     0,     0,     0,   107,   108,   109,     0,   248,     0,
     110,   111,   112,   113,   114,     0,   101,   102,   103,   104,
       0,     0,   156,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,   107,   108,   260,     0,     0,     0,   110,
     111,   112,   113,   114,   105,     0,     0,     1,     0,   261,
       0,     0,     0,     2,     0,     0,     3,     4,     0,     0,
       0,     5,     6,     7,     8,     0,     0,     0,     9,    10,
      11,     0,     0,    12,    13,   106,    14,    15,     0,    16,
      17,    18,    19,    20,   107,   108,   324,     0,     0,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,     0,
     325,     0,     0,    60,     0,     0,     1,     0,     0,     0,
       0,     0,     2,     0,     0,     3,     4,    21,     0,     0,
       5,     6,     7,     8,     0,   169,   257,     9,    10,    11,
     170,     0,    12,    13,     0,    14,    15,     0,    16,    17,
      18,    19,    20,     2,     0,     0,     3,     4,     0,     0,
       0,     5,     6,     7,     8,     0,     0,     0,     9,    10,
      11,     0,     0,    12,    13,     0,    14,    15,     0,    16,
      17,    18,    19,    20,     0,     0,    21,     2,     0,    71,
       3,     4,     0,     0,    22,     5,     6,     7,     8,     0,
       0,     0,     9,    10,    11,     0,     0,    12,    13,     0,
      14,    15,     0,    16,    17,    18,    19,    20,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     2,     0,     0,
       3,     4,     0,     0,    52,     5,     6,     7,     8,     0,
       0,     0,     9,    10,    11,     0,     0,    12,    13,     0,
      14,    15,     0,    16,    17,    18,    19,    20,     3,     4,
       0,     0,     0,     5,     6,     0,     8,     0,    52,     0,
       9,    10,     0,     0,     0,    12,    13,     0,     0,    15,
       0,     0,    17,    18,    19,    20,     3,     4,     0,     0,
       0,     5,     6,     0,     8,     0,     0,     0,     9,    10,
      86,     0,     0,    12,    13,     0,     0,    15,     0,     0,
      17,    18,    19,    20,   101,   102,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
       2,     0,   105,     3,     4,     0,     0,     0,     5,     6,
       7,     8,     0,     0,   105,     9,    10,    11,     0,     0,
      12,    13,     0,    14,    15,   235,    16,    17,    18,    19,
      20,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   108,   109,   106,     0,     0,   110,   111,
     112,   113,   114,   279,   107,   108,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   348,   101,   102,   103,   104,
       0,     0,     0,   322,     0,     3,     4,     0,     0,     0,
       5,     6,     0,     8,     0,     0,     0,     9,    10,     0,
       0,     0,    12,    13,   105,     0,    15,     1,     0,    17,
      18,    19,    20,     2,     0,     0,     3,     4,     0,     0,
       0,     5,     6,     7,     8,     0,     0,     0,     9,    10,
      11,     0,     0,    12,    13,   106,    14,    15,     0,    16,
      17,    18,    19,    20,   107,   108,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,    21,     0,   101,
     102,   103,   104,   105,     0,    22,     0,     0,   266,     2,
       0,     0,     3,     4,     0,   105,     0,     5,     6,     7,
       8,     0,     0,     0,     9,    10,    11,   105,     0,    12,
      13,     0,    14,    15,   106,    16,    17,    18,    19,    20,
       0,     0,     0,   107,   108,   109,   106,     0,     0,   110,
     111,   112,   113,   114,     0,   107,   108,   109,   106,     0,
       0,   110,   111,   112,   113,   187,     0,   107,   108,   109,
       0,     0,     0,   110,   111,   112,   113,   189,     2,     0,
       0,     3,     4,     0,     0,     0,     5,     6,     7,     8,
       0,     0,     0,     9,    10,    11,     0,     0,    12,    13,
       0,    14,    15,     0,    16,    17,    18,    19,    20,     2,
       0,     0,     3,     4,     0,     0,     0,     5,     6,     7,
       8,     0,     0,     0,     9,    10,    11,     0,     0,    12,
      13,     0,    14,    15,     0,    16,    17,    18,    19,    20,
       3,     4,    21,     0,     0,     5,     6,     0,     8,     0,
     272,   257,     9,    10,     0,   170,     0,    12,    13,     0,
       0,    15,     0,     0,    17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    71,    21,    57,   114,   172,    33,    97,    87,   139,
       3,     3,   115,   149,    75,    44,   146,    76,    79,    44,
      44,   119,    41,     3,    44,    25,    26,    44,    57,     3,
      30,    44,    44,    97,    34,    44,    13,    22,    44,    24,
      44,   105,   152,    90,     3,   115,   110,   111,    31,   139,
       3,     3,     3,   114,    44,   119,   146,    57,    21,    81,
     246,     3,    39,    46,    86,    44,    91,    91,    87,    54,
      82,    91,    89,    56,    87,   139,   135,   187,    41,   189,
      89,    73,   146,    89,    69,    89,    56,    50,    58,    81,
      73,   201,    82,    78,    86,    58,    73,    90,    81,    73,
     170,    82,    87,    82,   240,    57,   273,    81,   244,   239,
      90,    74,    75,    76,   193,    89,    79,    90,   216,   217,
     218,    73,    81,   233,   310,   311,   187,    86,    81,    81,
     200,    73,    95,    81,    65,    66,    67,    68,    86,    81,
     250,   251,   252,    45,   214,   172,    91,    44,    44,   239,
     169,   114,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   169,
     234,   307,   135,   276,   193,   239,   176,   275,    71,    72,
     163,    13,    45,   253,   169,    82,    82,    44,    73,    44,
       6,    44,    50,    44,    31,   265,    81,    13,    73,    74,
      75,    86,    82,   339,   340,   341,   276,    39,    81,    46,
     264,   275,   348,    86,   350,    87,    74,    75,    76,    56,
     356,    79,   358,    39,   187,    82,   336,   337,    87,    82,
      61,    82,    60,    76,    77,    78,    73,    62,    81,    69,
      70,    73,    59,    86,   334,    88,    57,   223,   224,   225,
     226,    57,   237,   272,    63,    64,   114,    73,   219,   220,
      89,   331,    89,   246,   264,   221,   222,   227,   228,    57,
     334,    87,   272,     3,     4,     5,     6,   135,    81,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     3,    24,    25,    26,    81,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     3,     4,     5,     6,    81,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    81,     3,   187,
      87,    82,    62,     3,     3,    57,    40,    89,    82,    31,
      82,    71,    72,    73,    87,    82,    87,    77,    78,    79,
      80,    81,    87,    81,    84,    82,    87,    82,   229,    89,
      90,    91,    85,    89,   230,   232,   231,    69,    74,   237,
      62,    62,   234,    58,    98,   176,   163,   187,    34,    71,
      72,    73,    46,    -1,    -1,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    90,    91,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    62,    -1,    10,    11,    -1,    -1,    14,
      15,    16,    71,    72,    73,    -1,    21,    22,    77,    78,
      79,    80,    81,    28,    -1,    84,    31,    -1,    -1,    34,
      89,    90,    -1,    -1,    -1,    40,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    71,    72,    73,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    80,    81,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    90,    12,    13,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    71,    72,    73,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    31,     3,     4,     5,     6,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    31,    -1,    62,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    71,    72,    73,    -1,    89,    -1,
      77,    78,    79,    80,    81,    -1,     3,     4,     5,     6,
      -1,    -1,    89,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    31,    -1,    -1,     3,    -1,    87,
      -1,    -1,    -1,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    -1,    -1,    29,    30,    62,    32,    33,    -1,    35,
      36,    37,    38,    39,    71,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,     0,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    12,    13,    73,    -1,    -1,
      17,    18,    19,    20,    -1,    81,    82,    24,    25,    26,
      86,    -1,    29,    30,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    -1,    -1,    29,    30,    -1,    32,    33,    -1,    35,
      36,    37,    38,    39,    -1,    -1,    73,     9,    -1,    45,
      12,    13,    -1,    -1,    81,    17,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    -1,    -1,    29,    30,    -1,
      32,    33,    -1,    35,    36,    37,    38,    39,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      12,    13,    -1,    -1,    90,    17,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    -1,    -1,    29,    30,    -1,
      32,    33,    -1,    35,    36,    37,    38,    39,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    90,    -1,
      24,    25,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      -1,    -1,    36,    37,    38,    39,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    24,    25,
      82,    -1,    -1,    29,    30,    -1,    -1,    33,    -1,    -1,
      36,    37,    38,    39,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
       9,    -1,    31,    12,    13,    -1,    -1,    -1,    17,    18,
      19,    20,    -1,    -1,    31,    24,    25,    26,    -1,    -1,
      29,    30,    -1,    32,    33,    91,    35,    36,    37,    38,
      39,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    62,    -1,    -1,    77,    78,
      79,    80,    81,    82,    71,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,     3,     4,     5,     6,
      -1,    -1,    -1,    82,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    -1,    33,     3,    -1,    36,
      37,    38,    39,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    -1,    -1,    29,    30,    62,    32,    33,    -1,    35,
      36,    37,    38,    39,    71,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    80,    81,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,     3,
       4,     5,     6,    31,    -1,    81,    -1,    -1,     8,     9,
      -1,    -1,    12,    13,    -1,    31,    -1,    17,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    31,    -1,    29,
      30,    -1,    32,    33,    62,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    71,    72,    73,    62,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    71,    72,    73,    62,    -1,
      -1,    77,    78,    79,    80,    81,    -1,    71,    72,    73,
      -1,    -1,    -1,    77,    78,    79,    80,    81,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    -1,    -1,    29,    30,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    -1,    -1,    29,
      30,    -1,    32,    33,    -1,    35,    36,    37,    38,    39,
      12,    13,    73,    -1,    -1,    17,    18,    -1,    20,    -1,
      81,    82,    24,    25,    -1,    86,    -1,    29,    30,    -1,
      -1,    33,    -1,    -1,    36,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    12,    13,    17,    18,    19,    20,    24,
      25,    26,    29,    30,    32,    33,    35,    36,    37,    38,
      39,    73,    81,   114,   115,   118,   119,   120,   121,   127,
     130,   131,   132,   133,   154,   155,   156,     3,    90,   130,
     133,   134,   131,    89,   116,   117,   131,   115,   115,     3,
      90,   115,    90,   114,   115,   146,   157,    81,    86,   132,
       0,   155,    90,     3,   128,   129,   130,   133,    82,    44,
      89,    45,   146,   157,    90,   119,   122,   123,   124,   130,
      91,   147,   131,   114,   146,     3,    82,   115,   135,   136,
     137,   138,     6,    73,    87,   134,   128,    45,    44,    91,
     117,     3,     4,     5,     6,    31,    62,    71,    72,    73,
      77,    78,    79,    80,    81,    90,    93,    94,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   142,   146,   122,   124,    91,   123,    57,
     125,   126,   131,   124,     3,    10,    11,    14,    15,    16,
      21,    22,    28,    34,    40,    84,    89,   110,   112,   114,
     144,   145,   146,   148,   149,   150,   151,   152,   153,    81,
      86,   131,   133,   140,   141,    82,    44,    44,    82,    87,
      87,    73,    91,    96,   109,   113,   129,    81,    96,    81,
      96,    96,   112,   124,   139,   142,   143,    76,    77,    78,
      81,    86,    88,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,   111,    98,    73,    74,    75,    71,
      72,    69,    70,    65,    66,    67,    68,    63,    64,    62,
      61,    60,    59,    56,    58,    91,   113,    44,    89,    57,
      57,    89,   113,    89,    57,   144,    81,     3,    89,   112,
      81,    81,    81,    44,    89,    91,   149,    82,   135,   140,
      73,    87,   110,   141,    81,    86,     8,   137,     3,    87,
     139,    82,    81,   133,   140,    82,    44,    91,     3,    82,
      95,   110,   112,     3,   110,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   101,   102,   102,   103,   104,
     105,   106,   112,   107,   126,   113,   144,    57,   144,    40,
     114,   150,    89,    89,   112,   112,   112,   110,    82,    82,
      87,    87,    82,   135,    73,    87,   110,    82,    98,    91,
     142,    44,    82,    87,    57,   144,    81,   150,   150,    82,
      82,    82,    82,    87,    87,   110,   109,   112,    82,   112,
      82,   144,   144,   144,    82,   144,    82,   144,    85,    89,
     144,   144
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    97,    97,    97,    98,
      98,    99,    99,    99,    99,   100,   100,   100,   101,   101,
     101,   102,   102,   102,   102,   102,   103,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   116,   116,   117,   117,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   120,   120,   120,   121,   121,
     122,   122,   123,   124,   124,   124,   124,   125,   125,   126,
     126,   126,   127,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   133,   133,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   137,   138,   138,   139,   139,   140,
     140,   140,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   142,   142,   142,   143,   143,   144,   144,
     144,   144,   144,   144,   145,   145,   145,   146,   147,   146,
     148,   148,   149,   149,   150,   150,   151,   151,   151,   152,
     152,   152,   152,   152,   153,   153,   153,   153,   153,   154,
     154,   155,   155,   156,   156,   156,   156,   157,   157
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     2,     1,     1,
       1,     2,     3,     1,     2,     1,     2,     1,     3,     1,
       2,     3,     4,     5,     2,     1,     3,     1,     3,     1,
       1,     1,     2,     1,     3,     3,     4,     4,     5,     4,
       4,     3,     1,     2,     2,     3,     1,     2,     1,     3,
       1,     3,     2,     2,     1,     1,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     3,     4,     2,
       3,     3,     4,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     0,     4,
       1,     2,     1,     1,     1,     2,     5,     7,     5,     5,
       7,     6,     6,     7,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     3,     4,     3,     2,     1,     2
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
#line 101 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = find_sym(&scopes, NS_DEFAULT, (yyvsp[0].string));
                      }
#line 1789 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 105 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_NUMBER);
                        (yyval.node)->astnode_number.number = (yyvsp[0].number);
                      }
#line 1798 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 110 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_CHARLIT);
                        (yyval.node)->astnode_charlit.ch = (yyvsp[0].character);
                      }
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 115 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_STRING);
                        (yyval.node)->astnode_string.string = (yyvsp[0].string);
                      }
#line 1816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 120 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = (yyvsp[-1].node);
                      }
#line 1824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 127 "parser.y" /* yacc.c:1646  */
    {
                        astnode *index = new_astnode(AST_BINOP);
                        index->astnode_binop.left = (yyvsp[-3].node);
                        index->astnode_binop.right = (yyvsp[-1].node); 
                        index->astnode_binop.op = (int) '+';
                        
                        (yyval.node) = new_astnode(AST_DEREF);
                        insert_astnode(index, (yyval.node)); 
                      }
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 137 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_CALL);
                        (yyval.node)->astnode_call.stab = (yyvsp[-2].node);
                      }
#line 1847 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 145 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node)  = new_astnode(AST_OP);
                        (yyval.node)->astnode_op.op = OP_POSTINC;
                        insert_astnode_op((yyval.node), (yyvsp[-1].node));
                      }
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 151 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_OP);
                        (yyval.node)->astnode_op.op = OP_POSTDEC;
                        insert_astnode_op((yyval.node), (yyvsp[-1].node));
                      }
#line 1867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 164 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_OP);
                        (yyval.node)->astnode_op.op = OP_PREINC;
                        insert_astnode_op((yyval.node), (yyvsp[0].node));
                      }
#line 1877 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 170 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_OP);
                        (yyval.node)->astnode_op.op = OP_PREDEC;
                        insert_astnode_op((yyval.node), (yyvsp[0].node));
                      }
#line 1887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 176 "parser.y" /* yacc.c:1646  */
    {
                        insert_astnode_op((yyval.node), (yyvsp[0].node));
                      }
#line 1895 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 184 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_OP);
                        (yyval.node)->astnode_op.op = OP_ADDROF;
                      }
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_OP);
                        (yyval.node)->astnode_op.op = OP_DEREF;
                      }
#line 1913 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 194 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_OP);
                        (yyval.node)->astnode_op.op = OP_POS;
                      }
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 199 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_OP);
                        (yyval.node)->astnode_op.op = OP_NEG;
                      }
#line 1931 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 204 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_OP);
                        (yyval.node)->astnode_op.op = OP_NOT;
                      }
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 209 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_OP);
                        (yyval.node)->astnode_op.op = OP_LOGNOT;
                      }
#line 1949 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 221 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_MULT;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 1960 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 228 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_DIV;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 235 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_MOD;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 245 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_ADD;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 1993 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 252 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_SUB;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2004 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 262 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_SHL;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2015 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 269 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_SHR;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2026 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 279 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_LT;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2037 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 286 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_GT;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2048 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 293 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_LTEQ;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 300 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_GTEQ;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2070 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 310 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_EQEQ;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2081 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 317 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_NOTEQ;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2092 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 327 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_AND;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 337 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_XOR;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2114 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 347 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_OR;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2125 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 357 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_LOGAND;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2136 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 367 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_LOGOR;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2147 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 381 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_EQ;
                        (yyval.node)->astnode_binop.left = (yyvsp[-2].node);
                        (yyval.node)->astnode_binop.right = (yyvsp[0].node);
                      }
#line 2158 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 391 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_MULT;
                        (yyval.node)->astnode_binop.left = (yyvsp[-1].node);
                      }
#line 2168 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 397 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_DIV;
                        (yyval.node)->astnode_binop.left = (yyvsp[-1].node);
                      }
#line 2178 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 403 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_MOD;
                        (yyval.node)->astnode_binop.left = (yyvsp[-1].node);
                      }
#line 2188 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 409 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_ADD;
                        (yyval.node)->astnode_binop.left = (yyvsp[-1].node);
                      }
#line 2198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 415 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_SUB;
                        (yyval.node)->astnode_binop.left = (yyvsp[-1].node);
                      }
#line 2208 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 421 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_SHL;
                        (yyval.node)->astnode_binop.left = (yyvsp[-1].node);
                      }
#line 2218 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 427 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_SHR;
                        (yyval.node)->astnode_binop.left = (yyvsp[-1].node);
                      }
#line 2228 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 433 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_AND;
                        (yyval.node)->astnode_binop.left = (yyvsp[-1].node);
                      }
#line 2238 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 439 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_XOR;
                        (yyval.node)->astnode_binop.left = (yyvsp[-1].node);
                      }
#line 2248 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 445 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_BINOP);
                        (yyval.node)->astnode_binop.op = OP_OR;
                        (yyval.node)->astnode_binop.left = (yyvsp[-1].node);
                      }
#line 2258 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 454 "parser.y" /* yacc.c:1646  */
    {
                        print_ast((yyvsp[0].node), 0);
                      }
#line 2266 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 465 "parser.y" /* yacc.c:1646  */
    {
                        insert_astnode((yyvsp[-1].node), ast_tail);
                        print_ast(ast_head, 0);
                      }
#line 2275 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 470 "parser.y" /* yacc.c:1646  */
    {
                        /* attach declspecs to declarator */
                        insert_astnode((yyvsp[-2].node), ast_tail); 
                        print_ast(ast_head, 0);
                      }
#line 2285 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 480 "parser.y" /* yacc.c:1646  */
    {
                        transform_typespecs((yyvsp[0].node));
                      }
#line 2293 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 484 "parser.y" /* yacc.c:1646  */
    {
                        /* accumulate type specifiers */
                        (yyvsp[-1].node)->astnode_typespecs.type_arr |= (yyvsp[0].node)->astnode_typespecs.type_arr;
                        transform_typespecs((yyvsp[-1].node));
                        (yyval.node) = (yyvsp[-1].node);
                      }
#line 2304 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 495 "parser.y" /* yacc.c:1646  */
    {
                        if ((yyvsp[0].node)->astnode_ident.next && *(int *) ((yyvsp[0].node)->astnode_ident.next) == AST_FUNC)
                        {
                            astnode *func_node = (yyvsp[0].node)->astnode_ident.next;
                            strcpy(func_node->astnode_func.name, (yyvsp[0].node)->astnode_ident.name);
                            insert_entry(&scopes, 0, NS_DEFAULT, func_node->astnode_func.name, func_node);
                            insert_astnode((yyvsp[-1].node), ast_tail); 
                            ast_head = func_node;
                            print_ast(ast_head, 0);
                            ast_head = new_astnode(AST_NULL);
                            ast_tail = ast_head;
                        }
                        else /* variable declaration */ 
                        {
                            * (int *) (yyvsp[0].node) = AST_VAR;
                            strcpy((yyvsp[0].node)->astnode_var.name, (yyvsp[0].node)->astnode_ident.name);
                            insert_entry(&scopes, 0, NS_DEFAULT, (yyvsp[0].node)->astnode_var.name, ast_head->astnode_null.next);
                            insert_astnode((yyvsp[-1].node), ast_tail); 
                            print_ast(ast_head, 0);
                            ast_head = new_astnode(AST_NULL);
                            ast_tail = ast_head;
                        }
                      }
#line 2332 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 519 "parser.y" /* yacc.c:1646  */
    {
                        if ((yyvsp[0].node)->astnode_ident.next && *(int *) ((yyvsp[0].node)->astnode_ident.next) == AST_FUNC)
                        {
                            astnode *func_node = (yyvsp[0].node)->astnode_ident.next;
                            strcpy(func_node->astnode_func.name, (yyvsp[0].node)->astnode_ident.name);
                            insert_entry(&scopes, 0, NS_DEFAULT, func_node->astnode_func.name, func_node);

                            insert_astnode((yyvsp[-3].node), ast_tail);
                            print_ast(ast_head, 0);
                            ast_head = new_astnode(AST_NULL);
                            ast_tail = ast_head;
                        }
                        else /* variable declaration */ 
                        {
                            * (int *) (yyvsp[0].node) = AST_VAR;
                            strcpy((yyvsp[0].node)->astnode_var.name, (yyvsp[0].node)->astnode_ident.name);
                            insert_entry(&scopes, 0, NS_DEFAULT, (yyvsp[0].node)->astnode_var.name, ast_head->astnode_null.next);
                            insert_astnode((yyvsp[-3].node), ast_tail); 
                            print_ast(ast_head, 0);
                            ast_head = new_astnode(AST_NULL);
                            ast_tail = ast_head;
                        }
                      }
#line 2360 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 548 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new_astnode(AST_TYPEDEF_NAME);}
#line 2366 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 549 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new_astnode(AST_VAR); (yyval.node)->astnode_var.stg = EXTERN;}
#line 2372 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 550 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new_astnode(AST_VAR); (yyval.node)->astnode_var.stg = STATIC;}
#line 2378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 551 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new_astnode(AST_VAR); (yyval.node)->astnode_var.stg = AUTO;}
#line 2384 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 552 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new_astnode(AST_VAR); (yyval.node)->astnode_var.stg = REGISTER;}
#line 2390 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 556 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_TYPESPECS);
                        SET_TYPE((yyval.node)->astnode_typespecs.type_arr, TYPE_VOID); 
                      }
#line 2399 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 561 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_TYPESPECS);
                        SET_TYPE((yyval.node)->astnode_typespecs.type_arr, TYPE_CHAR); 
                      }
#line 2408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 566 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_TYPESPECS);
                        SET_TYPE((yyval.node)->astnode_typespecs.type_arr, TYPE_SHORT); 
                      }
#line 2417 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 571 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_TYPESPECS);
                        SET_TYPE((yyval.node)->astnode_typespecs.type_arr, TYPE_INT); 
                        /* insert_astnode(newnode, ast_tail); */
                      }
#line 2427 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 577 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_TYPESPECS);
                        SET_TYPE((yyval.node)->astnode_typespecs.type_arr, TYPE_LONG); 
                      }
#line 2436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 582 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_TYPESPECS);
                        SET_TYPE((yyval.node)->astnode_typespecs.type_arr, TYPE_FLOAT); 
                      }
#line 2445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 587 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_TYPESPECS);
                        SET_TYPE((yyval.node)->astnode_typespecs.type_arr, TYPE_DOUBLE); 
                      }
#line 2454 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 592 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_TYPESPECS);
                        SET_TYPE((yyval.node)->astnode_typespecs.type_arr, TYPE_SIGNED); 
                      }
#line 2463 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 597 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_TYPESPECS);
                        SET_TYPE((yyval.node)->astnode_typespecs.type_arr, TYPE_UNSIGNED); 
                      }
#line 2472 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 610 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new_astnode(AST_STRUCT_TAG);}
#line 2478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 611 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new_astnode(AST_UNION_TAG);}
#line 2484 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 650 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_TYPESPECS);
                        (yyval.node)->astnode_typespecs.is_const = 1;
                      }
#line 2493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 655 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_TYPESPECS);
                        (yyval.node)->astnode_typespecs.is_volatile = 1;
                      }
#line 2502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 663 "parser.y" /* yacc.c:1646  */
    {
                        insert_astnode((yyvsp[-1].node), ast_tail);      
                      }
#line 2510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 669 "parser.y" /* yacc.c:1646  */
    { 
                        ast_head = new_astnode(AST_IDENT);
                        ast_tail = ast_head;
                        strcpy(ast_head->astnode_ident.name, (yyvsp[0].string));
                        (yyval.node) = ast_head;
                        /* ast_head = newnode; */
                        /* insert_astnode(newnode, ast_tail); */
                      }
#line 2523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 679 "parser.y" /* yacc.c:1646  */
    {
                        astnode *newnode = new_astnode(AST_ARRAY);
                        newnode->astnode_array.size = -1; 
                        insert_astnode(newnode, ast_tail);
                      }
#line 2533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 685 "parser.y" /* yacc.c:1646  */
    {
                        astnode *newnode = new_astnode(AST_ARRAY);
                        newnode->astnode_array.size = (yyvsp[-1].number).value.s_int;
                        insert_astnode(newnode, ast_tail);
                      }
#line 2543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 703 "parser.y" /* yacc.c:1646  */
    {
                        astnode *newnode = new_astnode(AST_FUNC);
                        insert_astnode(newnode, ast_tail);
                        ast_tail = newnode;
                      }
#line 2553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 710 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new_astnode(AST_PTR);}
#line 2559 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 711 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = new_astnode(AST_PTR);}
#line 2565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 713 "parser.y" /* yacc.c:1646  */
    {
                       astnode *newnode = new_astnode(AST_PTR);
                       insert_astnode(newnode, (yyvsp[0].node));
                       (yyval.node) = (yyvsp[0].node);
                      }
#line 2575 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 719 "parser.y" /* yacc.c:1646  */
    {
                       astnode *newnode = new_astnode(AST_PTR);
                       insert_astnode(newnode, (yyvsp[0].node));
                       (yyval.node) = (yyvsp[0].node);
                      }
#line 2585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 728 "parser.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node)->astnode_qualif.next = (yyvsp[0].node);
                      }
#line 2593 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 794 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = (yyvsp[0].node);
                        insert_entry(&scopes, 0, NS_LABEL, (yyvsp[-2].string),  (yyvsp[0].node));
                      }
#line 2602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 803 "parser.y" /* yacc.c:1646  */
    {push_scope(&scopes, SCOPE_BLOCK);}
#line 2608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 804 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = (yyvsp[-1].node);
                        pop_scope(&scopes);
                      }
#line 2617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 822 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_IF);
                        (yyval.node)->astnode_if.test = (yyvsp[-2].node);
                        (yyval.node)->astnode_if.true = (yyvsp[0].node);
                        (yyval.node)->astnode_if.false = 0;
                      }
#line 2628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 829 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_IF);
                        (yyval.node)->astnode_if.test = (yyvsp[-4].node);
                        (yyval.node)->astnode_if.true = (yyvsp[-2].node);
                        (yyval.node)->astnode_if.false = (yyvsp[0].node);
                      }
#line 2639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 839 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_WHILE);
                        (yyval.node)->astnode_while.test = (yyvsp[-2].node);
                        (yyval.node)->astnode_while.body = (yyvsp[0].node);
                      }
#line 2649 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 845 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.node) = new_astnode(AST_DOWHILE);
                        (yyval.node)->astnode_while.test = (yyvsp[-2].node);
                        (yyval.node)->astnode_while.body = (yyvsp[-5].node);
                      }
#line 2659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 872 "parser.y" /* yacc.c:1646  */
    {
                        // insert_astnode($1, ast_tail); 
                        print_ast(ast_head, 0);
                        astnode *node = new_astnode(AST_FUNC);
                        node->astnode_func.rtype = (yyvsp[-2].node);
                      }
#line 2670 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2674 "parser.tab.c" /* yacc.c:1646  */
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
#line 887 "parser.y" /* yacc.c:1906  */


void yyerror(const char *s)
{
    fprintf(stderr, "Parse error at line %d in file '%s': %s.\n", current_line, current_file, s);
}

int main()
{
    push_scope(&scopes, SCOPE_FILE);
    ast_head = new_astnode(AST_NULL);
    ast_tail = ast_head;
    yyin = stdin;
    do {
        yyparse();
        print_all_tables(&scopes);
    } while(!feof(yyin));
    return 0;
}




