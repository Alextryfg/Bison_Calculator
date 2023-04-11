/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintactico.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include <math.h>
    #include "abb.h"
    #include "definiciones.h"
    #include "tabladesimbolos.h"
    #include "lex.yy.h"

    tipoelem simbol = {};
    int fail = 0;
    void yyerror(char *s);  /* prototipo de la función de error  */
    extern int yylex(void); /* Esto se utilizará desde otros archivos por eso lleva el extern */
    int yywrap();       /* Esto se utilizará desde otros archivos por eso lleva el extern */
    void prompt();      /* Prototipo de la función prompt */
    void value(double val);       /* Prototipo de la función value para imprimir resultados*/
    double potencia(double base, double exponente);    /* Prototipo de la función potencia */
    int print = 1;      /* Variable que indica si se debe imprimir el resultado de la operación */
    int isnan(double x);    /* Prototipo de la función isnan */
    int loadPrint = 0;       /* Variable que indica si se debe cargar un archivo */


#line 96 "sintactico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sintactico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_NUM = 3,                  /* TOKEN_NUM  */
  YYSYMBOL_TOKEN_VARIABLE = 4,             /* TOKEN_VARIABLE  */
  YYSYMBOL_TOKEN_CONSTANTE = 5,            /* TOKEN_CONSTANTE  */
  YYSYMBOL_TOKEN_FILE = 6,                 /* TOKEN_FILE  */
  YYSYMBOL_TOKEN_MAS_IGUAL = 7,            /* TOKEN_MAS_IGUAL  */
  YYSYMBOL_TOKEN_MENOS_IGUAL = 8,          /* TOKEN_MENOS_IGUAL  */
  YYSYMBOL_TOKEN_MULT_IGUAL = 9,           /* TOKEN_MULT_IGUAL  */
  YYSYMBOL_TOKEN_DIV_IGUAL = 10,           /* TOKEN_DIV_IGUAL  */
  YYSYMBOL_TOKEN_IGUAL_IGUAL = 11,         /* TOKEN_IGUAL_IGUAL  */
  YYSYMBOL_TOKEN_MAYOR_IGUAL = 12,         /* TOKEN_MAYOR_IGUAL  */
  YYSYMBOL_TOKEN_MENOR_IGUAL = 13,         /* TOKEN_MENOR_IGUAL  */
  YYSYMBOL_TOKEN_DIFERENTE_IGUAL = 14,     /* TOKEN_DIFERENTE_IGUAL  */
  YYSYMBOL_TOKEN_MAS_MAS = 15,             /* TOKEN_MAS_MAS  */
  YYSYMBOL_TOKEN_MENOS_MENOS = 16,         /* TOKEN_MENOS_MENOS  */
  YYSYMBOL_TOKEN_FUNC = 17,                /* TOKEN_FUNC  */
  YYSYMBOL_TOKEN_COMMAND1 = 18,            /* TOKEN_COMMAND1  */
  YYSYMBOL_TOKEN_COMMAND2 = 19,            /* TOKEN_COMMAND2  */
  YYSYMBOL_TOKEN_ERROR = 20,               /* TOKEN_ERROR  */
  YYSYMBOL_TOKEN_EOF = 21,                 /* TOKEN_EOF  */
  YYSYMBOL_22_ = 22,                       /* '-'  */
  YYSYMBOL_23_ = 23,                       /* '+'  */
  YYSYMBOL_24_ = 24,                       /* '*'  */
  YYSYMBOL_25_ = 25,                       /* '/'  */
  YYSYMBOL_26_ = 26,                       /* '>'  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_NEG = 28,                       /* NEG  */
  YYSYMBOL_29_ = 29,                       /* '^'  */
  YYSYMBOL_30_n_ = 30,                     /* '\n'  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_start = 36,                     /* start  */
  YYSYMBOL_INICIO = 37,                    /* INICIO  */
  YYSYMBOL_exp = 38,                       /* exp  */
  YYSYMBOL_command = 39,                   /* command  */
  YYSYMBOL_assign = 40                     /* assign  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  69

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    24,    23,     2,    22,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      27,    34,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    29,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    95,    95,    99,   104,   108,   113,   117,   126,   132,
     138,   150,   151,   165,   172,   179,   186,   199,   203,   211,
     215,   229,   244,   258,   272,   286,   300,   316,   332,   348,
     366,   382,   398,   417,   445,   466,   474,   485,   522
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_NUM",
  "TOKEN_VARIABLE", "TOKEN_CONSTANTE", "TOKEN_FILE", "TOKEN_MAS_IGUAL",
  "TOKEN_MENOS_IGUAL", "TOKEN_MULT_IGUAL", "TOKEN_DIV_IGUAL",
  "TOKEN_IGUAL_IGUAL", "TOKEN_MAYOR_IGUAL", "TOKEN_MENOR_IGUAL",
  "TOKEN_DIFERENTE_IGUAL", "TOKEN_MAS_MAS", "TOKEN_MENOS_MENOS",
  "TOKEN_FUNC", "TOKEN_COMMAND1", "TOKEN_COMMAND2", "TOKEN_ERROR",
  "TOKEN_EOF", "'-'", "'+'", "'*'", "'/'", "'>'", "'<'", "NEG", "'^'",
  "'\\n'", "';'", "'('", "')'", "'='", "$accept", "start", "INICIO", "exp",
  "command", "assign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,     0,   -31,   -31,   -31,    58,   -30,   -31,   -24,   -31,
      59,   -31,    59,   -31,   117,   -23,   -25,    59,    59,    59,
      59,   -31,   -31,    39,    59,     7,   167,   -15,    71,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
     -31,   -14,   -31,   -31,   -10,   144,   144,    -2,    -2,   138,
     -31,    94,   -18,   -31,   -15,   -15,   -15,   -15,   144,   144,
      -2,    -2,   -15,   -15,   -15,   -31,   -31,   -31,   -31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    10,    11,    12,     0,    33,    35,    36,
       0,     4,     0,     3,     0,     0,     0,     0,     0,     0,
       0,    26,    27,     0,     0,     0,    12,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     6,     7,     0,    30,    31,    29,    28,    37,
      38,     0,     0,    19,    22,    23,    24,    25,    14,    13,
      15,    16,    21,    20,    18,     8,     9,    32,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,    16,     6,   -31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    13,    14,    15,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       2,     3,    24,     4,     5,    43,    44,    42,    25,    29,
      30,    31,    32,    52,    39,    68,    65,     6,     7,     8,
      66,     9,    10,     0,    37,    38,    27,    39,    28,    50,
      11,     0,    12,    45,    46,    47,    48,     0,     0,    49,
      51,     0,     4,    26,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     6,     7,     8,     0,
       9,    10,     4,    26,     0,    17,    18,    19,    20,     0,
       0,    12,     0,    21,    22,     0,     6,     0,     0,     0,
       0,    10,    29,    30,    31,    32,     0,     0,     0,     0,
       0,    12,    23,    33,    34,    35,    36,    37,    38,     0,
      39,     0,     0,     0,    53,    29,    30,    31,    32,     0,
       0,     0,     0,     0,     0,     0,    33,    34,    35,    36,
      37,    38,     0,    39,     0,     0,     0,    67,    29,    30,
      31,    32,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    38,     0,    39,    40,    41,    29,
      30,    31,    32,     0,     0,    29,    30,    31,    32,     0,
      33,    34,    35,    36,    37,    38,     0,    39,    35,    36,
      37,    38,     0,    39,    17,    18,    19,    20,     0,     0,
       0,     0,    21,    22
};

static const yytype_int8 yycheck[] =
{
       0,     1,    32,     3,     4,    30,    31,    30,    32,    11,
      12,    13,    14,     6,    29,    33,    30,    17,    18,    19,
      30,    21,    22,    -1,    26,    27,    10,    29,    12,    23,
      30,    -1,    32,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,     3,     4,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    17,    18,    19,    -1,
      21,    22,     3,     4,    -1,     7,     8,     9,    10,    -1,
      -1,    32,    -1,    15,    16,    -1,    17,    -1,    -1,    -1,
      -1,    22,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    32,    34,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    -1,    -1,    33,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    11,
      12,    13,    14,    -1,    -1,    11,    12,    13,    14,    -1,
      22,    23,    24,    25,    26,    27,    -1,    29,    24,    25,
      26,    27,    -1,    29,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    15,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,     0,     1,     3,     4,    17,    18,    19,    21,
      22,    30,    32,    37,    38,    39,    40,     7,     8,     9,
      10,    15,    16,    34,    32,    32,     4,    38,    38,    11,
      12,    13,    14,    22,    23,    24,    25,    26,    27,    29,
      30,    31,    30,    30,    31,    38,    38,    38,    38,    38,
      39,    38,     6,    33,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    30,    30,    33,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    37,    37,
      37,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    39,    39,    39,    39,    40,    40
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     3,     3,
       1,     1,     1,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     3,
       3,     3,     4,     1,     4,     1,     1,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* start: %empty  */
#line 96 "sintactico.y"
{
    prompt();
}
#line 1183 "sintactico.tab.c"
    break;

  case 4: /* INICIO: '\n'  */
#line 105 "sintactico.y"
{
    prompt();
}
#line 1191 "sintactico.tab.c"
    break;

  case 5: /* INICIO: exp '\n'  */
#line 109 "sintactico.y"
{
    value((yyvsp[-1].val));
    prompt();
}
#line 1200 "sintactico.tab.c"
    break;

  case 6: /* INICIO: command '\n'  */
#line 114 "sintactico.y"
{
    prompt();
}
#line 1208 "sintactico.tab.c"
    break;

  case 7: /* INICIO: assign '\n'  */
#line 118 "sintactico.y"
{
    if(isnan((yyvsp[-1].val)) || isnan(-(yyvsp[-1].val))){
        print=0;
        printf("Error: El resultado es NaN\n");
    }
    value((yyvsp[-1].val));
    prompt();
}
#line 1221 "sintactico.tab.c"
    break;

  case 8: /* INICIO: exp ';' '\n'  */
#line 127 "sintactico.y"
{   
    print = 0;
    value((yyvsp[-2].val));
    prompt();
}
#line 1231 "sintactico.tab.c"
    break;

  case 9: /* INICIO: assign ';' '\n'  */
#line 133 "sintactico.y"
{   
    print = 0;
    value((yyvsp[-2].val));
    prompt();
}
#line 1241 "sintactico.tab.c"
    break;

  case 10: /* INICIO: error  */
#line 139 "sintactico.y"
{   
    /* No detectamos ningun token valido, por lo tanto llegamos al token terminal error */
    /* Se debe limpiar el buffer de entrada */
    yyclearin;
    fail = 1;
}
#line 1252 "sintactico.tab.c"
    break;

  case 12: /* exp: TOKEN_VARIABLE  */
#line 152 "sintactico.y"
{   
    simbol = getSimbol((yyvsp[0].str));

    if(simbol.lexema != NULL){
        (yyval.val) = simbol.data.val;
    }else{
        printf("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free((yyvsp[0].str));

}
#line 1270 "sintactico.tab.c"
    break;

  case 13: /* exp: exp '+' exp  */
#line 166 "sintactico.y"
{ 
    (yyval.val) = (yyvsp[-2].val) + (yyvsp[0].val);
    if(isnan((yyval.val))){
        print = 0;
    }
}
#line 1281 "sintactico.tab.c"
    break;

  case 14: /* exp: exp '-' exp  */
#line 173 "sintactico.y"
{ 
    (yyval.val) = (yyvsp[-2].val) - (yyvsp[0].val);
    if(isnan((yyval.val))){
        print = 0;
    }
}
#line 1292 "sintactico.tab.c"
    break;

  case 15: /* exp: exp '*' exp  */
#line 180 "sintactico.y"
{ 
    (yyval.val) = (yyvsp[-2].val) * (yyvsp[0].val);
    if(isnan((yyval.val))){
        print = 0;
    }
}
#line 1303 "sintactico.tab.c"
    break;

  case 16: /* exp: exp '/' exp  */
#line 187 "sintactico.y"
{ 
    
    (yyval.val) = (yyvsp[-2].val) / (yyvsp[0].val);
    //Caso de nan y -nan
    if(isnan((yyval.val))){
        print = 0;
    }
    if((yyvsp[0].val) == 0){
        printf("Error: Division entre 0\n");
        print = 0;
    }
}
#line 1320 "sintactico.tab.c"
    break;

  case 17: /* exp: '-' exp  */
#line 200 "sintactico.y"
{ 
    (yyval.val) = -(yyvsp[0].val);
}
#line 1328 "sintactico.tab.c"
    break;

  case 18: /* exp: exp '^' exp  */
#line 204 "sintactico.y"
{ 
    (yyval.val) = potencia((yyvsp[-2].val), (yyvsp[0].val));
    if(isnan((yyval.val))){
        printf("Error: El resultado es un NaN\n");
        print = 0;
    }
}
#line 1340 "sintactico.tab.c"
    break;

  case 19: /* exp: '(' exp ')'  */
#line 212 "sintactico.y"
{ 
    (yyval.val) = (yyvsp[-1].val);
}
#line 1348 "sintactico.tab.c"
    break;

  case 20: /* exp: exp '<' exp  */
#line 216 "sintactico.y"
{ 
    (yyval.val) = (yyvsp[-2].val) < (yyvsp[0].val);
    if(!fail){
        if((yyval.val) == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;
}
#line 1366 "sintactico.tab.c"
    break;

  case 21: /* exp: exp '>' exp  */
#line 230 "sintactico.y"
{ 
    (yyval.val) = (yyvsp[-2].val) > (yyvsp[0].val);
    if(!fail){
        if((yyval.val) == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;

}
#line 1385 "sintactico.tab.c"
    break;

  case 22: /* exp: exp TOKEN_IGUAL_IGUAL exp  */
#line 245 "sintactico.y"
{ 
    (yyval.val) = (yyvsp[-2].val) == (yyvsp[0].val);
    if(!fail){
        if((yyval.val) == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;
}
#line 1403 "sintactico.tab.c"
    break;

  case 23: /* exp: exp TOKEN_MAYOR_IGUAL exp  */
#line 259 "sintactico.y"
{ 
    (yyval.val) = (yyvsp[-2].val) >= (yyvsp[0].val);
    if(!fail){
        if((yyval.val) == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;
}
#line 1421 "sintactico.tab.c"
    break;

  case 24: /* exp: exp TOKEN_MENOR_IGUAL exp  */
#line 273 "sintactico.y"
{ 
    (yyval.val) = (yyvsp[-2].val) <= (yyvsp[0].val);
    if(!fail){
        if((yyval.val) == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;
}
#line 1439 "sintactico.tab.c"
    break;

  case 25: /* exp: exp TOKEN_DIFERENTE_IGUAL exp  */
#line 287 "sintactico.y"
{ 
    (yyval.val) = (yyvsp[-2].val) != (yyvsp[0].val);
    if(!fail){
        if((yyval.val) == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;
}
#line 1457 "sintactico.tab.c"
    break;

  case 26: /* exp: TOKEN_VARIABLE TOKEN_MAS_MAS  */
#line 301 "sintactico.y"
{
    simbol = getSimbol((yyvsp[-1].str));

    if(simbol.lexema != NULL){
        (yyval.val) = simbol.data.val;
        (yyval.val)++;
        actualizarSimbolo((yyvsp[-1].str), (yyval.val));
    }else{
        printf("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free((yyvsp[-1].str));

}
#line 1477 "sintactico.tab.c"
    break;

  case 27: /* exp: TOKEN_VARIABLE TOKEN_MENOS_MENOS  */
#line 317 "sintactico.y"
{
    simbol = getSimbol((yyvsp[-1].str));

    if(simbol.lexema != NULL){
        (yyval.val) = simbol.data.val;
        (yyval.val)--;
        actualizarSimbolo((yyvsp[-1].str), (yyval.val));
    }else{
        printf("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free((yyvsp[-1].str));

}
#line 1497 "sintactico.tab.c"
    break;

  case 28: /* exp: TOKEN_VARIABLE TOKEN_DIV_IGUAL exp  */
#line 333 "sintactico.y"
{
    simbol = getSimbol((yyvsp[-2].str));

    if(simbol.lexema != NULL){
        (yyval.val) = simbol.data.val;
        (yyval.val) /= (yyvsp[0].val);
        actualizarSimbolo((yyvsp[-2].str), (yyval.val));
    }else{
        printf("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free((yyvsp[-2].str));

}
#line 1517 "sintactico.tab.c"
    break;

  case 29: /* exp: TOKEN_VARIABLE TOKEN_MULT_IGUAL exp  */
#line 349 "sintactico.y"
{
    simbol = getSimbol((yyvsp[-2].str));

    if(simbol.lexema != NULL){
        (yyval.val) = simbol.data.val;
        (yyval.val) *= (yyvsp[0].val);
        actualizarSimbolo((yyvsp[-2].str), (yyval.val));
    }else{
        printf("Error: La variable no ha sido declarada\n");
        print = 0;
    }


    free((yyvsp[-2].str));


}
#line 1539 "sintactico.tab.c"
    break;

  case 30: /* exp: TOKEN_VARIABLE TOKEN_MAS_IGUAL exp  */
#line 367 "sintactico.y"
{
    simbol = getSimbol((yyvsp[-2].str));

    if(simbol.lexema != NULL){
        (yyval.val) = simbol.data.val;
        (yyval.val) += (yyvsp[0].val);
        actualizarSimbolo((yyvsp[-2].str), (yyval.val));
    }else{
        printf("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free((yyvsp[-2].str));

}
#line 1559 "sintactico.tab.c"
    break;

  case 31: /* exp: TOKEN_VARIABLE TOKEN_MENOS_IGUAL exp  */
#line 383 "sintactico.y"
{
    simbol = getSimbol((yyvsp[-2].str));

    if(simbol.lexema != NULL){
        (yyval.val) = simbol.data.val;
        (yyval.val) -= (yyvsp[0].val);
        actualizarSimbolo((yyvsp[-2].str), (yyval.val));
    }else{
        printf("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free((yyvsp[-2].str));

}
#line 1579 "sintactico.tab.c"
    break;

  case 32: /* exp: TOKEN_FUNC '(' exp ')'  */
#line 399 "sintactico.y"
{   
    simbol = getSimbol((yyvsp[-3].str));

        double (*ptrFunc)(double) = simbol.data.func;
        if (ptrFunc != NULL) {
            (yyval.val) = (*(ptrFunc))((yyvsp[-1].val));
        } else {
            printf("Error: El puntero a función es nulo.\n");
            print=0;
        }

    free((yyvsp[-3].str));
}
#line 1597 "sintactico.tab.c"
    break;

  case 33: /* command: TOKEN_COMMAND1  */
#line 418 "sintactico.y"
{

    if(!fail){

        
        simbol = getSimbol((yyvsp[0].str));

        double (*ptrFunc)() = simbol.data.func;
        if (ptrFunc != NULL) {
            (*(ptrFunc))();
        } else {
            printf("Error: El puntero a función es nulo.\n");
        }

        if(strcmp((yyvsp[0].str), "exit") == 0){
            printf("Saliendo del programa...\n");
            return 1;
        }

    }
    
    fail = 0;
    free((yyvsp[0].str));

    

}
#line 1629 "sintactico.tab.c"
    break;

  case 34: /* command: TOKEN_COMMAND2 '(' TOKEN_FILE ')'  */
#line 446 "sintactico.y"
{
    if(!fail){
        
        simbol = getSimbol("load");

        double (*ptrFunc)(char *) = simbol.data.func;
        if (ptrFunc != NULL) {
            loadPrint = 1;
            (*(ptrFunc))((yyvsp[-1].str));
        } else {
            printf("Error: El puntero a función es nulo.\n");
        }

    }

    free((yyvsp[-3].str));
    free((yyvsp[-1].str));
    fail = 0;

}
#line 1654 "sintactico.tab.c"
    break;

  case 35: /* command: TOKEN_COMMAND2  */
#line 467 "sintactico.y"
{
    if(!fail){
        printf("Error: No se ha especificado el nombre del archivo a importar\n");
        print = 0;
    }

}
#line 1666 "sintactico.tab.c"
    break;

  case 36: /* command: TOKEN_EOF  */
#line 475 "sintactico.y"
{
    if(!fail){
        loadPrint = 0;
        printf("Archivo cargado con exito");
    }
}
#line 1677 "sintactico.tab.c"
    break;

  case 37: /* assign: TOKEN_VARIABLE '=' exp  */
#line 486 "sintactico.y"
{   

    //printf("entro a assign");
    simbol = getSimbol((yyvsp[-2].str));

    if(!fail){

        if(simbol.lexema != NULL){ 
            if(simbol.type == ID_CONST){
                printf("Error: No se puede asignar un valor a una constante\n");
                print = 0;
                fail = 1;
            }

        }
        
    
        if(!fail){

            if(!existeSimbolo((yyvsp[-2].str))){
                insertarSimbolo((yyvsp[-2].str), (yyvsp[0].val));
            }else{
                actualizarSimbolo((yyvsp[-2].str), (yyvsp[0].val));
            }

        }
        
        

    }
    
    free((yyvsp[-2].str));
    fail = 0;
    (yyval.val) = (yyvsp[0].val);

}
#line 1718 "sintactico.tab.c"
    break;

  case 38: /* assign: TOKEN_VARIABLE '=' command  */
#line 523 "sintactico.y"
{
    if(!fail){
        printf("Error: No se puede asignar una funcion a una variable o constante\n");
        print = 0;
    }

    free((yyvsp[-2].str));
}
#line 1731 "sintactico.tab.c"
    break;


#line 1735 "sintactico.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 542 "sintactico.y"


/* Función de error */
void yyerror(char *s){
    printf("%s\n", s);
}

int yywrap(){
    return 1;
}

void prompt(){
    if(!loadPrint)
        printf("\033[32m$>\033[0m");
}

void value(double val){
    if(print){
        printf("%lf\n", val);
    }else{
        print = 1;
    }
}

double potencia(double base, double exponente){
        double resultado = 1;
    int i;

    // Si el exponente es positivo, multiplica la base el número de veces del exponente
    if (exponente > 0) {
        for (i = 1; i <= exponente; i++) {
            resultado *= base;
        }
    }
    // Si el exponente es negativo, divide la base el número de veces del exponente absoluto
    else {
        int exponenteAbsoluto = -exponente;
        for (i = 1; i <= exponenteAbsoluto; i++) {
            resultado /= base;
        }
    }

    return resultado;
}

int isnan(double x){
    return x != x;
}




