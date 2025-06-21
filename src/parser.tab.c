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
#line 8 "src/parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int yylex(void);
    int yyerror(const char *s);

    enum ESTADOS {
        E_TITULO = 0,
        E_DECLARACOES = 1,
        E_ATO = 2,
        E_CENA = 3,
        E_DIALOGO = 4,
    };
    int estado = 0;

    char *cenarioAtual = NULL;

    int DEBUG_BISON = 0;
    // Funções auxiliares
    char* personagemDialogo = NULL; // Guarda o valor do personagem em uma fala
    char* personagemQueFala = NULL; // Guarda o valor do personagem que tá falando
    int result = 0; // guarda o resultado do if

#line 97 "src/parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAIOR = 3,                      /* MAIOR  */
  YYSYMBOL_MENOR = 4,                      /* MENOR  */
  YYSYMBOL_IGUAL = 5,                      /* IGUAL  */
  YYSYMBOL_NAO = 6,                        /* NAO  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_ENTAO = 8,                      /* ENTAO  */
  YYSYMBOL_EU = 9,                         /* EU  */
  YYSYMBOL_SE = 10,                        /* SE  */
  YYSYMBOL_SAEM = 11,                      /* SAEM  */
  YYSYMBOL_ENTRAM = 12,                    /* ENTRAM  */
  YYSYMBOL_TODOS = 13,                     /* TODOS  */
  YYSYMBOL_SOMAR = 14,                     /* SOMAR  */
  YYSYMBOL_SUBTRAIR = 15,                  /* SUBTRAIR  */
  YYSYMBOL_DIVIDIR = 16,                   /* DIVIDIR  */
  YYSYMBOL_MULTIPLICAR = 17,               /* MULTIPLICAR  */
  YYSYMBOL_INICIO = 18,                    /* INICIO  */
  YYSYMBOL_FIM = 19,                       /* FIM  */
  YYSYMBOL_SIM = 20,                       /* SIM  */
  YYSYMBOL_INTERROGACAO = 21,              /* INTERROGACAO  */
  YYSYMBOL_ABRE_COLCHETES = 22,            /* ABRE_COLCHETES  */
  YYSYMBOL_FECHA_COLCHETES = 23,           /* FECHA_COLCHETES  */
  YYSYMBOL_ABRE_PARENTESES = 24,           /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 25,          /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 26,                   /* VIRGULA  */
  YYSYMBOL_TOKEN = 27,                     /* TOKEN  */
  YYSYMBOL_ADJETIVO_POSITIVO = 28,         /* ADJETIVO_POSITIVO  */
  YYSYMBOL_ADJETIVO_NEGATIVO = 29,         /* ADJETIVO_NEGATIVO  */
  YYSYMBOL_TU = 30,                        /* TU  */
  YYSYMBOL_EH = 31,                        /* EH  */
  YYSYMBOL_E = 32,                         /* E  */
  YYSYMBOL_ENTRE = 33,                     /* ENTRE  */
  YYSYMBOL_ARTIGO = 34,                    /* ARTIGO  */
  YYSYMBOL_MESMO = 35,                     /* MESMO  */
  YYSYMBOL_NUMERO = 36,                    /* NUMERO  */
  YYSYMBOL_ADICIONAR_CENARIO = 37,         /* ADICIONAR_CENARIO  */
  YYSYMBOL_SUBSTITUIR_CENARIO = 38,        /* SUBSTITUIR_CENARIO  */
  YYSYMBOL_POR = 39,                       /* POR  */
  YYSYMBOL_NO_CENARIO = 40,                /* NO_CENARIO  */
  YYSYMBOL_MOSTRAR_CENARIO = 41,           /* MOSTRAR_CENARIO  */
  YYSYMBOL_MOSTRA_VALOR = 42,              /* MOSTRA_VALOR  */
  YYSYMBOL_LE_VALOR = 43,                  /* LE_VALOR  */
  YYSYMBOL_ATO = 44,                       /* ATO  */
  YYSYMBOL_CENA = 45,                      /* CENA  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_programa = 47,                  /* programa  */
  YYSYMBOL_bloco = 48,                     /* bloco  */
  YYSYMBOL_declaracaoCenario = 49,         /* declaracaoCenario  */
  YYSYMBOL_concatenarCenario = 50,         /* concatenarCenario  */
  YYSYMBOL_substituiCenario = 51,          /* substituiCenario  */
  YYSYMBOL_declaracaoQuestionamento = 52,  /* declaracaoQuestionamento  */
  YYSYMBOL_texto = 53,                     /* texto  */
  YYSYMBOL_palavra = 54,                   /* palavra  */
  YYSYMBOL_adjetivos = 55,                 /* adjetivos  */
  YYSYMBOL_declaracao = 56,                /* declaracao  */
  YYSYMBOL_declaracaoInicio = 57,          /* declaracaoInicio  */
  YYSYMBOL_alteracaoElenco = 58,           /* alteracaoElenco  */
  YYSYMBOL_valor = 59,                     /* valor  */
  YYSYMBOL_expressao = 60,                 /* expressao  */
  YYSYMBOL_if_sentenca = 61,               /* if_sentenca  */
  YYSYMBOL_condicao = 62,                  /* condicao  */
  YYSYMBOL_dialogo = 63,                   /* dialogo  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_inicioDialogo = 65,             /* inicioDialogo  */
  YYSYMBOL_ato = 66,                       /* ato  */
  YYSYMBOL_cena = 67                       /* cena  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   529

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    54,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    74,    88,   108,   127,   140,   153,
     169,   172,   178,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   207,
     210,   213,   216,   222,   228,   231,   236,   243,   254,   269,
     275,   286,   297,   305,   306,   312,   318,   324,   337,   350,
     353,   356,   359,   362,   365,   370,   376,   379,   406,   442,
     442,   455,   465,   474,   499,   513
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
  "\"end of file\"", "error", "\"invalid token\"", "MAIOR", "MENOR",
  "IGUAL", "NAO", "FOR", "ENTAO", "EU", "SE", "SAEM", "ENTRAM", "TODOS",
  "SOMAR", "SUBTRAIR", "DIVIDIR", "MULTIPLICAR", "INICIO", "FIM", "SIM",
  "INTERROGACAO", "ABRE_COLCHETES", "FECHA_COLCHETES", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "TOKEN", "ADJETIVO_POSITIVO",
  "ADJETIVO_NEGATIVO", "TU", "EH", "E", "ENTRE", "ARTIGO", "MESMO",
  "NUMERO", "ADICIONAR_CENARIO", "SUBSTITUIR_CENARIO", "POR", "NO_CENARIO",
  "MOSTRAR_CENARIO", "MOSTRA_VALOR", "LE_VALOR", "ATO", "CENA", "$accept",
  "programa", "bloco", "declaracaoCenario", "concatenarCenario",
  "substituiCenario", "declaracaoQuestionamento", "texto", "palavra",
  "adjetivos", "declaracao", "declaracaoInicio", "alteracaoElenco",
  "valor", "expressao", "if_sentenca", "condicao", "dialogo", "$@1",
  "inicioDialogo", "ato", "cena", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -78,    71,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   255,
     -78,   -78,   -78,   -78,   495,   495,   -78,   -78,   -78,   -78,
     -78,   -78,   -12,   495,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   221,   -78,   -78,   495,   -78,   -78,   -78,   114,   -78,
     -78,   -78,   -28,    49,   -78,   483,   -78,    -3,   -14,   313,
     347,   495,   184,   -78,    -5,   -78,   -78,   -78,   381,   -78,
     267,     0,   -78,    -6,     8,     9,    16,    21,    31,    24,
     -78,   495,   415,   495,    32,    33,   -78,   -78,   -25,   -78,
     301,   301,   301,   301,    42,   255,   255,   255,   255,   449,
     -78,   146,   -78,   -78,    36,    50,    54,    29,    48,    58,
      59,   255,   255,   255,   -78,   -78,   -78,   -78,   -78,    73,
      30,   -78,   -78,   301,   301,   301,   301,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,    11,   255,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,    75,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    36,    37,    38,    34,    35,    33,     0,
      30,    29,    31,    28,     0,     0,    23,    24,    25,    32,
      27,    26,     0,     0,    74,    75,     3,     8,    10,    11,
       9,     0,    20,     7,     0,    12,    13,     6,     0,     4,
       5,    51,     0,    26,    49,    52,    53,     0,     0,     0,
       0,     0,     0,    73,    19,    47,    21,    22,     0,    65,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,     0,     0,    46,    67,     0,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    58,    14,     0,
      69,    71,    72,     0,     0,     0,     0,    63,    62,    64,
      16,    41,    39,    40,     0,     0,    54,    55,    57,    56,
      68,    44,    42,    43,    45,     0,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   -78,   -78,   -78,   -78,    -1,   -29,   -78,
     -78,   -78,   -78,   -27,   -77,    63,   -78,   -78,   -78,   -78,
     -78,   -78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    26,    27,    28,    29,    30,    45,    32,   124,
      33,    34,    35,    46,    47,    36,    48,    37,   125,    38,
      39,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    74,    57,    67,    68,    94,    51,    62,   104,   105,
     106,   107,    69,    49,    50,    75,    57,    95,    96,    79,
      57,    57,    52,    57,   117,   118,   119,    80,    84,    57,
     130,    57,    88,    58,    85,    86,    87,    60,   131,   132,
     133,    81,    82,    57,   134,   101,   102,   103,   135,    83,
      72,    92,    93,    97,    98,    99,   100,   121,   122,   123,
      57,   113,    57,    63,    64,    65,    66,   110,     0,   111,
      89,     2,    91,   112,     3,     4,     5,     6,     7,     8,
     114,     9,    10,    11,    12,    13,   126,   127,   128,   129,
     115,   116,   120,    14,   136,    15,     0,     0,    16,    17,
      18,    61,     0,    19,    20,    21,     0,     0,    22,    23,
       0,     0,     0,     0,     0,    24,    25,     3,     4,     5,
       6,     7,     8,     0,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    18,     0,     0,    19,    20,    21,     3,
       4,     5,     6,     7,     8,    59,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18,     0,     0,    19,    20,
      21,     0,    56,     0,     0,     0,   109,     3,     4,     5,
       6,     7,     8,     0,     0,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    18,     0,     0,    19,    20,    21,     0,
      56,     0,     0,    73,     3,     4,     5,     6,     7,     8,
       0,     0,    10,    11,    12,    13,     0,     0,     0,    53,
       0,     0,    54,     0,     0,     0,     0,    55,    16,    17,
      18,     0,     0,    19,    20,    21,     0,    56,     3,     4,
       5,     6,     7,     8,    41,     0,    10,    11,    12,    13,
       3,     4,     5,     6,     7,     8,     0,     0,    10,    11,
      12,    13,    16,    17,    18,    42,    77,    19,    20,    43,
       0,    44,     0,    78,    16,    17,    18,     0,     0,    19,
      20,    21,     0,    56,     3,     4,     5,     6,     7,     8,
      41,     0,    10,    11,    12,    13,     3,     4,     5,     6,
       7,     8,     0,     0,    10,    11,    12,    13,    16,    17,
      18,    42,     0,    19,    20,    21,    70,    44,     0,     0,
      16,    17,    18,     0,     0,    19,    20,    21,     0,    56,
       3,     4,     5,     6,     7,     8,     0,     0,    10,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    16,    17,    18,     0,     0,    19,
      20,    21,     0,    56,     3,     4,     5,     6,     7,     8,
       0,     0,    10,    11,    12,    13,     0,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,    16,    17,
      18,     0,     0,    19,    20,    21,     0,    56,     3,     4,
       5,     6,     7,     8,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,    16,    17,    18,     0,     0,    19,    20,    21,
       0,    56,     3,     4,     5,     6,     7,     8,     0,     0,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,    16,    17,    18,     0,
       0,    19,    20,    21,     0,    56,     3,     4,     5,     6,
       7,     8,     0,     0,    10,    11,    12,    13,     3,     4,
       5,     6,     7,     8,     0,     0,    10,    11,    12,    13,
      16,    17,    18,     0,     0,    19,    20,    21,     0,    56,
       0,     0,    16,    17,    18,     0,     0,    19,    20,    21
};

static const yytype_int8 yycheck[] =
{
       1,     6,    31,     6,     7,    30,    18,    35,    85,    86,
      87,    88,    26,    14,    15,    20,    45,    42,    43,    19,
      49,    50,    23,    52,   101,   102,   103,    33,     7,    58,
      19,    60,     8,    34,     3,     4,     5,    38,    27,    28,
      29,    33,    33,    72,    33,     3,     4,     5,   125,    33,
      51,    19,    19,    80,    81,    82,    83,    27,    28,    29,
      89,    32,    91,    14,    15,    16,    17,    31,    -1,    19,
      71,     0,    73,    19,     3,     4,     5,     6,     7,     8,
      32,    10,    11,    12,    13,    14,   113,   114,   115,   116,
      32,    32,    19,    22,    19,    24,    -1,    -1,    27,    28,
      29,    38,    -1,    32,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    32,    33,    34,     3,
       4,     5,     6,     7,     8,    41,    -1,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,    33,
      34,    -1,    36,    -1,    -1,    -1,    40,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    32,    33,    34,    -1,
      36,    -1,    -1,    39,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    -1,    -1,    -1,    18,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    -1,    36,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    14,    27,    28,    29,    30,    19,    32,    33,    34,
      -1,    36,    -1,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    -1,    36,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    14,    27,    28,
      29,    30,    -1,    32,    33,    34,    23,    36,    -1,    -1,
      27,    28,    29,    -1,    -1,    32,    33,    34,    -1,    36,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    -1,    36,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    32,    33,    34,    -1,    36,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    32,    33,    34,
      -1,    36,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    -1,
      -1,    32,    33,    34,    -1,    36,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    14,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      27,    28,    29,    -1,    -1,    32,    33,    34,    -1,    36,
      -1,    -1,    27,    28,    29,    -1,    -1,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,     0,     3,     4,     5,     6,     7,     8,    10,
      11,    12,    13,    14,    22,    24,    27,    28,    29,    32,
      33,    34,    37,    38,    44,    45,    48,    49,    50,    51,
      52,    53,    54,    56,    57,    58,    61,    63,    65,    66,
      67,     9,    30,    34,    36,    53,    59,    60,    62,    53,
      53,    18,    53,    18,    21,    26,    36,    54,    53,    41,
      53,    61,    35,    14,    15,    16,    17,     6,     7,    26,
      23,    26,    53,    39,     6,    20,    19,    19,    26,    19,
      33,    33,    33,    33,     7,     3,     4,     5,     8,    53,
      19,    53,    19,    19,    30,    42,    43,    59,    59,    59,
      59,     3,     4,     5,    60,    60,    60,    60,    25,    40,
      31,    19,    19,    32,    32,    32,    32,    60,    60,    60,
      19,    27,    28,    29,    55,    64,    59,    59,    59,    59,
      19,    27,    28,    29,    33,    60,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    50,    51,    52,    52,    52,
      53,    53,    53,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    56,    57,    58,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    61,    62,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    64,
      63,    63,    63,    65,    66,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     6,     4,     4,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     2,     3,     1,
       2,     1,     1,     1,     6,     6,     6,     6,     5,     4,
       4,     4,     5,     5,     5,     2,     3,     3,     7,     0,
       8,     5,     5,     2,     1,     1
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
  case 14: /* declaracaoCenario: ABRE_PARENTESES texto VIRGULA texto FECHA_PARENTESES  */
#line 74 "src/parser.y"
                                                         {
        if (estado == E_DECLARACOES) {
            add_symbol((yyvsp[-3].texto), STRING_VAR);
            set_string_value((yyvsp[-3].texto), (yyvsp[-1].texto));
            if (DEBUG_BISON) {
                printf("Cenário adicionado: %s = %s\n", (yyvsp[-3].texto), (yyvsp[-1].texto));
            }
            cenarioAtual = strdup((yyvsp[-3].texto));
        } else {
            yyerror("Declaração de cenário fora de contexto");
        }
    }
#line 1332 "src/parser.tab.c"
    break;

  case 15: /* concatenarCenario: ADICIONAR_CENARIO INICIO texto FIM  */
#line 88 "src/parser.y"
                                       {
        if (estado != E_DECLARACOES) {
            char * valorCenario = get_string_value(cenarioAtual);

            if (valorCenario == NULL) {
                yyerror("Nenhum cenário atual definido");
            } else {
                char* novoCenario = concatena(valorCenario, (yyvsp[-1].texto));
                set_string_value(cenarioAtual, novoCenario);
                // free(novoCenario);
                if (DEBUG_BISON) {
                    printf("Cenário atualizado: %s\n", cenarioAtual);
                }
            }
        } else {
            yyerror("Adição de cenário fora de contexto");
        }
    }
#line 1355 "src/parser.tab.c"
    break;

  case 16: /* substituiCenario: SUBSTITUIR_CENARIO texto POR texto NO_CENARIO FIM  */
#line 108 "src/parser.y"
                                                     {
        if (estado != E_DECLARACOES) {
            char * valorCenario = get_string_value(cenarioAtual);
            if (valorCenario == NULL) {
                yyerror("Nenhum cenário atual definido");
            } else {
                char* novoValorCenario = substituir_ocorrencias(valorCenario, (yyvsp[-4].texto), (yyvsp[-2].texto));
                set_string_value(cenarioAtual, novoValorCenario);
                if (DEBUG_BISON) {
                    printf("Novo cenário: %s\n", get_string_value(cenarioAtual));
                }
            }
        } else {
            yyerror("Substituição de cenário fora de contexto");
        }
    }
#line 1376 "src/parser.tab.c"
    break;

  case 17: /* declaracaoQuestionamento: texto INTERROGACAO NAO FIM  */
#line 127 "src/parser.y"
                               {
        if (DEBUG_BISON) {
            printf("Declaração de questionamento negativo: %s\n", (yyvsp[-3].texto));
        }
        Symbol *sym = get_symbol((yyvsp[-3].texto));
        if (!sym) {
            add_symbol((yyvsp[-3].texto), BOOL_VAR);
        } else if (sym->type != BOOL_VAR) {
            yyerror("Tipo incorreto para questionamento (esperado BOOL_VAR)");
            YYABORT;
        }
        set_bool_value((yyvsp[-3].texto), 0); // Inicializa como falso
    }
#line 1394 "src/parser.tab.c"
    break;

  case 18: /* declaracaoQuestionamento: texto INTERROGACAO SIM FIM  */
#line 140 "src/parser.y"
                                 {
        if (DEBUG_BISON) {
            printf("Declaração de questionamento afirmativo: %s\n", (yyvsp[-3].texto));
        }
        Symbol *sym = get_symbol((yyvsp[-3].texto));
        if (!sym) {
            add_symbol((yyvsp[-3].texto), BOOL_VAR);
        } else if (sym->type != BOOL_VAR) {
            yyerror("Tipo incorreto para questionamento (esperado BOOL_VAR)");
            YYABORT;
        }
        set_bool_value((yyvsp[-3].texto), 1); // Inicializa como verdadeiro
    }
#line 1412 "src/parser.tab.c"
    break;

  case 19: /* declaracaoQuestionamento: texto INTERROGACAO  */
#line 153 "src/parser.y"
                         {
        if (DEBUG_BISON) {
            printf("Declaração de questionamento: %s\n", (yyvsp[-1].texto));
        }
        Symbol *sym = get_symbol((yyvsp[-1].texto));
        if (!sym) {
            add_symbol((yyvsp[-1].texto), BOOL_VAR);
        } else if (sym->type != BOOL_VAR) {
            yyerror("Tipo incorreto para questionamento (esperado BOOL_VAR)");
            YYABORT;
        }
        set_bool_value((yyvsp[-1].texto), 0); // Inicializa como falso
    }
#line 1430 "src/parser.tab.c"
    break;

  case 20: /* texto: palavra  */
#line 169 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1438 "src/parser.tab.c"
    break;

  case 21: /* texto: texto NUMERO  */
#line 172 "src/parser.y"
                   {
         if (DEBUG_BISON) {
             printf("Concatenando: %s + %s\n", (yyvsp[-1].texto), (yyvsp[0].texto));
        }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1449 "src/parser.tab.c"
    break;

  case 22: /* texto: texto palavra  */
#line 178 "src/parser.y"
                    {
        if (DEBUG_BISON) {
            printf("Concatenando: %s + %s\n", (yyvsp[-1].texto), (yyvsp[0].texto));
        }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1460 "src/parser.tab.c"
    break;

  case 23: /* palavra: TOKEN  */
#line 188 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1466 "src/parser.tab.c"
    break;

  case 24: /* palavra: ADJETIVO_POSITIVO  */
#line 189 "src/parser.y"
                        { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1472 "src/parser.tab.c"
    break;

  case 25: /* palavra: ADJETIVO_NEGATIVO  */
#line 190 "src/parser.y"
                        { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1478 "src/parser.tab.c"
    break;

  case 26: /* palavra: ARTIGO  */
#line 191 "src/parser.y"
             { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1484 "src/parser.tab.c"
    break;

  case 27: /* palavra: ENTRE  */
#line 192 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1490 "src/parser.tab.c"
    break;

  case 28: /* palavra: SOMAR  */
#line 193 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1496 "src/parser.tab.c"
    break;

  case 29: /* palavra: ENTRAM  */
#line 194 "src/parser.y"
             { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1502 "src/parser.tab.c"
    break;

  case 30: /* palavra: SAEM  */
#line 195 "src/parser.y"
           { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1508 "src/parser.tab.c"
    break;

  case 31: /* palavra: TODOS  */
#line 196 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1514 "src/parser.tab.c"
    break;

  case 32: /* palavra: E  */
#line 197 "src/parser.y"
        { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1520 "src/parser.tab.c"
    break;

  case 33: /* palavra: ENTAO  */
#line 198 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1526 "src/parser.tab.c"
    break;

  case 34: /* palavra: NAO  */
#line 199 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1532 "src/parser.tab.c"
    break;

  case 35: /* palavra: FOR  */
#line 200 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1538 "src/parser.tab.c"
    break;

  case 36: /* palavra: MAIOR  */
#line 201 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1544 "src/parser.tab.c"
    break;

  case 37: /* palavra: MENOR  */
#line 202 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1550 "src/parser.tab.c"
    break;

  case 38: /* palavra: IGUAL  */
#line 203 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1556 "src/parser.tab.c"
    break;

  case 39: /* adjetivos: ADJETIVO_POSITIVO  */
#line 207 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1564 "src/parser.tab.c"
    break;

  case 40: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 210 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
#line 1572 "src/parser.tab.c"
    break;

  case 41: /* adjetivos: TOKEN  */
#line 213 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
#line 1580 "src/parser.tab.c"
    break;

  case 42: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 216 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) + 1;
    }
#line 1591 "src/parser.tab.c"
    break;

  case 43: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 222 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) - 1;
    }
#line 1602 "src/parser.tab.c"
    break;

  case 44: /* adjetivos: adjetivos TOKEN  */
#line 228 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1610 "src/parser.tab.c"
    break;

  case 45: /* adjetivos: adjetivos ENTRE  */
#line 231 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1618 "src/parser.tab.c"
    break;

  case 46: /* declaracao: declaracaoInicio texto FIM  */
#line 236 "src/parser.y"
                               {
        if (DEBUG_BISON) {
            printf("Declaração: %s\n", (yyvsp[-1].texto));
        }
    }
#line 1628 "src/parser.tab.c"
    break;

  case 47: /* declaracaoInicio: texto VIRGULA  */
#line 243 "src/parser.y"
                  {
        if (estado == E_DECLARACOES) {
            if (DEBUG_BISON) {
                printf("Criando variável: %s\n", (yyvsp[-1].texto));
            }
            add_symbol((yyvsp[-1].texto), INT_VAR);
        }
        (yyval.texto) = (yyvsp[-1].texto);
    }
#line 1642 "src/parser.tab.c"
    break;

  case 48: /* alteracaoElenco: ABRE_COLCHETES texto FECHA_COLCHETES  */
#line 254 "src/parser.y"
                                         {
        if (estado == E_CENA) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", (yyvsp[-1].texto));
            }
        } if (estado == E_DIALOGO) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", (yyvsp[-1].texto));
            }
        } else {
            printf("Alteração de elenco fora de contexto, estado atual: %d\n", estado);
        }
    }
#line 1660 "src/parser.tab.c"
    break;

  case 49: /* valor: NUMERO  */
#line 269 "src/parser.y"
            {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi((yyvsp[0].texto)));
        }
        (yyval.inteiro) = atoi((yyvsp[0].texto));
    }
#line 1671 "src/parser.tab.c"
    break;

  case 50: /* valor: TU MESMO  */
#line 275 "src/parser.y"
               { 
        if (DEBUG_BISON) {
            printf("Valor de 'tu mesmo': %d\n", get_int_value(personagemDialogo));
        }
        if (personagemDialogo == NULL) {
            yyerror("Variável 'tu mesmo' não definida");
            (yyval.inteiro) = 0; // Valor padrão
        } else {
            (yyval.inteiro) = get_int_value(personagemDialogo);
        }
    }
#line 1687 "src/parser.tab.c"
    break;

  case 51: /* valor: EU  */
#line 286 "src/parser.y"
         {
        if (DEBUG_BISON) {
            printf("Valor de 'eu': %d\n", get_int_value(personagemQueFala));
        }
        if (personagemDialogo == NULL) {
            yyerror("Variável 'eu' não definida");
            (yyval.inteiro) = 0; // Valor padrão
        } else {
            (yyval.inteiro) = get_int_value(personagemDialogo);
        }
    }
#line 1703 "src/parser.tab.c"
    break;

  case 52: /* valor: texto  */
#line 297 "src/parser.y"
            {
        if (DEBUG_BISON) {
            printf("Valor de texto: %d\n", get_int_value((yyvsp[0].texto)));
        }
        (yyval.inteiro) = get_int_value((yyvsp[0].texto)); //O texto todo é uma variável
    }
#line 1714 "src/parser.tab.c"
    break;

  case 54: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 306 "src/parser.y"
                                       {
        if (DEBUG_BISON) {
            printf("Expressão de soma: %s\n", (yyvsp[-4].texto));
        }
        (yyval.inteiro) = (yyvsp[-2].inteiro) + (yyvsp[0].inteiro); // Exemplo de operação
    }
#line 1725 "src/parser.tab.c"
    break;

  case 55: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 312 "src/parser.y"
                                          {
        if (DEBUG_BISON) {
            printf("Expressão de subtração: %s\n", (yyvsp[-4].texto));
        }
        (yyval.inteiro) = (yyvsp[-2].inteiro) - (yyvsp[0].inteiro);
    }
#line 1736 "src/parser.tab.c"
    break;

  case 56: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 318 "src/parser.y"
                                             {
        if (DEBUG_BISON) {
            printf("Expressão de multiplicação: %s\n", (yyvsp[-4].texto));
        }
        (yyval.inteiro) = (yyvsp[-2].inteiro) * (yyvsp[0].inteiro);
    }
#line 1747 "src/parser.tab.c"
    break;

  case 57: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 324 "src/parser.y"
                                         {
        if (DEBUG_BISON) {
            printf("Expressão de divisão: %s\n", (yyvsp[-4].texto));
        }
        if ((yyvsp[0].inteiro) == 0) {
            yyerror("Divisão por zero");
            (yyval.inteiro) = 0; // Valor padrão em caso de erro
        } else {
            (yyval.inteiro) = (yyvsp[-2].inteiro) / (yyvsp[0].inteiro);
        }
    }
#line 1763 "src/parser.tab.c"
    break;

  case 58: /* if_sentenca: SE condicao VIRGULA ENTAO expressao  */
#line 337 "src/parser.y"
                                       {
        if (DEBUG_BISON) {
            printf("Condicao do IF: %d\n", (yyvsp[-3].inteiro));
            printf("resultado do IF: %d\n", (yyvsp[0].inteiro));
        }
        if ((yyvsp[-3].inteiro)) {
            (yyval.inteiro) = (yyvsp[0].inteiro);
        } else {
            (yyval.inteiro) = 0; // valor padrão 
        }
    }
#line 1779 "src/parser.tab.c"
    break;

  case 59: /* condicao: expressao FOR MAIOR expressao  */
#line 350 "src/parser.y"
                                  {
        (yyval.inteiro) = (yyvsp[-3].inteiro) > (yyvsp[0].inteiro);
    }
#line 1787 "src/parser.tab.c"
    break;

  case 60: /* condicao: expressao FOR MENOR expressao  */
#line 353 "src/parser.y"
                                   {
        (yyval.inteiro) = (yyvsp[-3].inteiro) < (yyvsp[0].inteiro);
    }
#line 1795 "src/parser.tab.c"
    break;

  case 61: /* condicao: expressao FOR IGUAL expressao  */
#line 356 "src/parser.y"
                                   {
        (yyval.inteiro) = (yyvsp[-3].inteiro) = (yyvsp[0].inteiro);
    }
#line 1803 "src/parser.tab.c"
    break;

  case 62: /* condicao: expressao NAO FOR MENOR expressao  */
#line 359 "src/parser.y"
                                       {
        (yyval.inteiro) = !((yyvsp[-4].inteiro) < (yyvsp[0].inteiro));
    }
#line 1811 "src/parser.tab.c"
    break;

  case 63: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 362 "src/parser.y"
                                       {
        (yyval.inteiro) = !((yyvsp[-4].inteiro) > (yyvsp[0].inteiro));
    }
#line 1819 "src/parser.tab.c"
    break;

  case 64: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 365 "src/parser.y"
                                       {
        (yyval.inteiro) = !((yyvsp[-4].inteiro) = (yyvsp[0].inteiro));
    }
#line 1827 "src/parser.tab.c"
    break;

  case 65: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 370 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
    }
#line 1838 "src/parser.tab.c"
    break;

  case 66: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 376 "src/parser.y"
                                   {

    }
#line 1846 "src/parser.tab.c"
    break;

  case 67: /* dialogo: inicioDialogo texto FIM  */
#line 379 "src/parser.y"
                              {
        if (DEBUG_BISON) {
            printf("Diálogo: %s\n", (yyvsp[-1].texto));
            switch (estado) {
                case E_TITULO:
                    printf("Título\n");
                    break;
                case E_DECLARACOES:
                    printf("Declarações\n");
                    break;
                case E_DIALOGO:
                    printf("Diálogo\n");
                    break;
                case E_CENA:
                    printf("Cena\n");
                    break;
                case E_ATO:
                    printf("Ato\n");
                    break;
                default:
                    yyerror("Estado desconhecido no diálogo\n");
                    break;
            }
        }

    }
#line 1877 "src/parser.tab.c"
    break;

  case 68: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 406 "src/parser.y"
                                                      {
        switch (estado) {
            case E_TITULO:
                if (DEBUG_BISON) {
                    printf("Título com vírgula: %s\n", (yyvsp[-4].texto));
                }
                break;
            case E_DECLARACOES:
                if (DEBUG_BISON) {
                    printf("Declarações com vírgula: %s\n", (yyvsp[-4].texto));
                }
                break;
            case E_DIALOGO:
                if (DEBUG_BISON) {
                    printf("Diálogo com vírgula: %s\n", (yyvsp[-5].texto));
                    printf("Alterando variável: %s\n", (yyvsp[-5].texto));
                    printf("    Valor atual: %d\n", get_int_value((yyvsp[-5].texto)));
                }
                // pegar valor do texto !!!
                set_int_value((yyvsp[-5].texto), get_int_value((yyvsp[-5].texto)) + (yyvsp[-1].inteiro));
                if (DEBUG_BISON) {
                    printf("    Novo valor: %d\n", get_int_value((yyvsp[-5].texto)));
                }
                break;
            case E_CENA:
                printf("Cena com vírgula: %s\n", (yyvsp[-4].texto));
                break;
            case E_ATO:
                printf("Ato com vírgula: %s\n", (yyvsp[-4].texto));
                break;
            default:
                yyerror("Estado desconhecido no diálogo com vírgula\n");
                break;
        }
        (yyval.texto) = (yyvsp[-6].texto);
    }
#line 1918 "src/parser.tab.c"
    break;

  case 69: /* $@1: %empty  */
#line 442 "src/parser.y"
                                        {
        personagemDialogo = (yyvsp[-3].texto);
    }
#line 1926 "src/parser.tab.c"
    break;

  case 70: /* dialogo: inicioDialogo texto VIRGULA TU EH $@1 expressao FIM  */
#line 444 "src/parser.y"
                    {
        if (DEBUG_BISON) {
            printf("Valor do personagem antes do diálogo: %d\n", get_int_value(personagemDialogo));
        }
        set_int_value(personagemDialogo, (yyvsp[-1].inteiro));
        if (DEBUG_BISON) {
            printf("Valor do personagem após diálogo: %d\n", get_int_value(personagemDialogo));
        }
        free(personagemDialogo);
        personagemDialogo = NULL;
    }
#line 1942 "src/parser.tab.c"
    break;

  case 71: /* dialogo: inicioDialogo texto VIRGULA MOSTRA_VALOR FIM  */
#line 455 "src/parser.y"
                                                   {
        if (DEBUG_BISON) {
            if (get_int_value((yyvsp[-3].texto)) == -1) {
                yyerror("Variável não definida");
            } else {
                printf("Valor de %s: %d\n", (yyvsp[-3].texto), get_int_value((yyvsp[-3].texto)));
            }
        }
        gerar_print_int((yyvsp[-3].texto));
    }
#line 1957 "src/parser.tab.c"
    break;

  case 72: /* dialogo: inicioDialogo texto VIRGULA LE_VALOR FIM  */
#line 465 "src/parser.y"
                                               {
        if (DEBUG_BISON) {
            printf("Lendo valor de %s\n", (yyvsp[-3].texto));
        }
        gerar_leitura_inteiro((yyvsp[-3].texto));
    }
#line 1968 "src/parser.tab.c"
    break;

  case 73: /* inicioDialogo: texto INICIO  */
#line 474 "src/parser.y"
                 {
        personagemQueFala = (yyvsp[-1].texto);
        if (estado == E_TITULO) {
            if (DEBUG_BISON) {
                printf("Título: %s\n", (yyvsp[-1].texto));
            }
            estado = E_DECLARACOES;
        } 
        else if (estado == E_DIALOGO) {
            if (DEBUG_BISON) {
                printf("Apenas um texto\n");
            }    
        } else if (estado == E_CENA) {
            if (DEBUG_BISON) {
                printf("Início do diálogo: %s\n", (yyvsp[-1].texto));
            }
            estado = E_DIALOGO;
        } else {     
            if (DEBUG_BISON) {
                yyerror("Diálogo fora de contexto\n");
            }        
        }
    }
#line 1996 "src/parser.tab.c"
    break;

  case 74: /* ato: ATO  */
#line 499 "src/parser.y"
        {
        if (estado == E_DECLARACOES) {
            if (DEBUG_BISON) {
                printf("Ato: %d\n", (yyvsp[0].inteiro));
            }
            estado = E_ATO;
        } else if (estado != E_ATO) {
            if (DEBUG_BISON) {
                yyerror("Ato fora de contexto");
            }
        }
    }
#line 2013 "src/parser.tab.c"
    break;

  case 75: /* cena: CENA  */
#line 513 "src/parser.y"
         {
        if (estado == E_ATO) {
            if (DEBUG_BISON) {
                printf("Cena: %d\n", (yyvsp[0].inteiro));
            }
            estado = E_CENA;
        } else if (estado == E_CENA) {
            // faz algo
        } else {
            printf("Cena fora de contexto, estado atual: %d", estado);
        }
    }
#line 2030 "src/parser.tab.c"
    break;


#line 2034 "src/parser.tab.c"

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

#line 527 "src/parser.y"


int main() {
    iniciar_codegen();
    yyparse();
    finalizar_codegen();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
    return 0;
}
