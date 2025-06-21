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

    int DEBUG_BISON = 1;
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
  YYSYMBOL_FACA = 3,                       /* FACA  */
  YYSYMBOL_ENDIF = 4,                      /* ENDIF  */
  YYSYMBOL_ENQUANTO_COMECO = 5,            /* ENQUANTO_COMECO  */
  YYSYMBOL_ENQUANTO_FIM = 6,               /* ENQUANTO_FIM  */
  YYSYMBOL_MAIOR = 7,                      /* MAIOR  */
  YYSYMBOL_MENOR = 8,                      /* MENOR  */
  YYSYMBOL_IGUAL = 9,                      /* IGUAL  */
  YYSYMBOL_NAO = 10,                       /* NAO  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_ENTAO = 12,                     /* ENTAO  */
  YYSYMBOL_EU = 13,                        /* EU  */
  YYSYMBOL_SE = 14,                        /* SE  */
  YYSYMBOL_SAEM = 15,                      /* SAEM  */
  YYSYMBOL_ENTRAM = 16,                    /* ENTRAM  */
  YYSYMBOL_TODOS = 17,                     /* TODOS  */
  YYSYMBOL_SOMAR = 18,                     /* SOMAR  */
  YYSYMBOL_SUBTRAIR = 19,                  /* SUBTRAIR  */
  YYSYMBOL_DIVIDIR = 20,                   /* DIVIDIR  */
  YYSYMBOL_MULTIPLICAR = 21,               /* MULTIPLICAR  */
  YYSYMBOL_INICIO = 22,                    /* INICIO  */
  YYSYMBOL_FIM = 23,                       /* FIM  */
  YYSYMBOL_ABRE_COLCHETES = 24,            /* ABRE_COLCHETES  */
  YYSYMBOL_FECHA_COLCHETES = 25,           /* FECHA_COLCHETES  */
  YYSYMBOL_ABRE_PARENTESES = 26,           /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 27,          /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 28,                   /* VIRGULA  */
  YYSYMBOL_TOKEN = 29,                     /* TOKEN  */
  YYSYMBOL_ADJETIVO_POSITIVO = 30,         /* ADJETIVO_POSITIVO  */
  YYSYMBOL_ADJETIVO_NEGATIVO = 31,         /* ADJETIVO_NEGATIVO  */
  YYSYMBOL_TU = 32,                        /* TU  */
  YYSYMBOL_EH = 33,                        /* EH  */
  YYSYMBOL_E = 34,                         /* E  */
  YYSYMBOL_ENTRE = 35,                     /* ENTRE  */
  YYSYMBOL_ARTIGO = 36,                    /* ARTIGO  */
  YYSYMBOL_MESMO = 37,                     /* MESMO  */
  YYSYMBOL_NUMERO = 38,                    /* NUMERO  */
  YYSYMBOL_ADICIONAR_CENARIO = 39,         /* ADICIONAR_CENARIO  */
  YYSYMBOL_SUBSTITUIR_CENARIO = 40,        /* SUBSTITUIR_CENARIO  */
  YYSYMBOL_POR = 41,                       /* POR  */
  YYSYMBOL_NO_CENARIO = 42,                /* NO_CENARIO  */
  YYSYMBOL_MOSTRAR_CENARIO = 43,           /* MOSTRAR_CENARIO  */
  YYSYMBOL_ATO = 44,                       /* ATO  */
  YYSYMBOL_CENA = 45,                      /* CENA  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_programa = 47,                  /* programa  */
  YYSYMBOL_bloco = 48,                     /* bloco  */
  YYSYMBOL_declaracaoCenario = 49,         /* declaracaoCenario  */
  YYSYMBOL_concatenarCenario = 50,         /* concatenarCenario  */
  YYSYMBOL_substituiCenario = 51,          /* substituiCenario  */
  YYSYMBOL_texto = 52,                     /* texto  */
  YYSYMBOL_palavra = 53,                   /* palavra  */
  YYSYMBOL_adjetivos = 54,                 /* adjetivos  */
  YYSYMBOL_declaracao = 55,                /* declaracao  */
  YYSYMBOL_declaracaoInicio = 56,          /* declaracaoInicio  */
  YYSYMBOL_alteracaoElenco = 57,           /* alteracaoElenco  */
  YYSYMBOL_valor = 58,                     /* valor  */
  YYSYMBOL_expressao = 59,                 /* expressao  */
  YYSYMBOL_if_sentenca = 60,               /* if_sentenca  */
  YYSYMBOL_if_bloco = 61,                  /* if_bloco  */
  YYSYMBOL_while = 62,                     /* while  */
  YYSYMBOL_condicao = 63,                  /* condicao  */
  YYSYMBOL_dialogo = 64,                   /* dialogo  */
  YYSYMBOL_65_1 = 65,                      /* $@1  */
  YYSYMBOL_inicioDialogo = 66,             /* inicioDialogo  */
  YYSYMBOL_ato = 67,                       /* ato  */
  YYSYMBOL_cena = 68                       /* cena  */
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
#define YYLAST   608

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

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
      64,    65,    66,    67,    68,    75,    89,   109,   125,   128,
     134,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   158,   161,   164,   167,   173,   179,   182,   187,
     192,   204,   215,   221,   232,   243,   251,   252,   258,   264,
     270,   283,   292,   299,   304,   311,   314,   317,   320,   323,
     326,   331,   337,   342,   366,   400,   400,   416,   433,   443
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
  "\"end of file\"", "error", "\"invalid token\"", "FACA", "ENDIF",
  "ENQUANTO_COMECO", "ENQUANTO_FIM", "MAIOR", "MENOR", "IGUAL", "NAO",
  "FOR", "ENTAO", "EU", "SE", "SAEM", "ENTRAM", "TODOS", "SOMAR",
  "SUBTRAIR", "DIVIDIR", "MULTIPLICAR", "INICIO", "FIM", "ABRE_COLCHETES",
  "FECHA_COLCHETES", "ABRE_PARENTESES", "FECHA_PARENTESES", "VIRGULA",
  "TOKEN", "ADJETIVO_POSITIVO", "ADJETIVO_NEGATIVO", "TU", "EH", "E",
  "ENTRE", "ARTIGO", "MESMO", "NUMERO", "ADICIONAR_CENARIO",
  "SUBSTITUIR_CENARIO", "POR", "NO_CENARIO", "MOSTRAR_CENARIO", "ATO",
  "CENA", "$accept", "programa", "bloco", "declaracaoCenario",
  "concatenarCenario", "substituiCenario", "texto", "palavra", "adjetivos",
  "declaracao", "declaracaoInicio", "alteracaoElenco", "valor",
  "expressao", "if_sentenca", "if_bloco", "while", "condicao", "dialogo",
  "$@1", "inicioDialogo", "ato", "cena", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -77,   117,   -77,   -24,   303,   -77,   303,   -77,   -77,   -77,
     -77,    75,    75,   -77,   -77,   -77,   -77,   -77,   -77,   -16,
      75,   -77,   -77,   -77,   -77,   -77,   -77,   328,   -77,   -77,
      75,   -77,   -77,   -77,   -77,   -77,   211,   -77,   -77,    75,
     -77,   -30,    25,   -77,   570,   -77,    17,   -19,   -11,   415,
     440,    75,   249,   -77,   -77,   -77,   -77,   465,   303,   -77,
     353,    -2,   475,   -77,   -22,    -5,     4,    14,    36,    48,
      75,    75,   -77,    75,   500,    75,   -77,    -3,   -77,    20,
     -77,   155,   380,   380,   380,   380,    76,   303,   303,   303,
     510,   276,   535,   -77,   221,    75,    26,    53,    19,    28,
      33,    39,   303,   303,   303,   -77,   -77,   -77,   155,   155,
      37,   -10,   -77,   -77,    52,   390,    66,   303,   380,   380,
     380,   380,   -77,   -77,   -77,    75,    67,   -77,   -77,   -77,
     -77,   -15,   303,    50,   -77,   -77,   -77,   -77,   186,   -77,
     -77,   -77,   -77,   -77,   -77,    56,    75,    63,   -77,   560,
     -77,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,    31,     0,    28,    27,    29,
      26,     0,     0,    21,    22,    23,    30,    25,    24,     0,
       0,    68,    69,     3,     8,     9,    10,     0,    18,     7,
       0,    11,    12,    13,    14,     6,     0,     4,     5,     0,
      44,     0,    24,    42,    45,    46,     0,     0,     0,     0,
       0,     0,     0,    67,    40,    19,    20,     0,     0,    61,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    39,     0,    63,     0,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,    57,     0,     0,
      19,    18,    51,    15,     0,     0,    65,     0,     0,     0,
       0,     0,    59,    58,    60,     0,     0,    17,    34,    32,
      33,     0,     0,     0,    47,    48,    50,    49,     0,    52,
      64,    37,    35,    36,    38,     0,     0,     0,    66,     0,
      53,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -76,   -77,   -77,   -77,    -1,   -26,   -77,   -77,
     -77,   -77,    92,    12,    62,   -77,   -77,    -4,   -77,   -77,
     -77,   -77,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    23,    24,    25,    26,    44,    28,   131,    29,
      30,    31,    45,    46,    32,    33,    34,    47,    35,   132,
      36,    37,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    56,    48,   -20,    39,    97,    51,    63,   140,    70,
      49,    50,   -20,    82,   141,   142,   143,    71,    56,    52,
     144,    80,   -20,    56,    56,    95,    56,    68,    69,    57,
      83,    56,   125,   126,    56,    60,    56,   -42,    62,    84,
     -42,   -42,   -42,    64,    65,    66,    67,    86,    56,    85,
      74,   -42,    96,   118,    77,    87,    88,    89,   117,   116,
     -42,   -42,   119,   -42,    56,   111,    56,   120,    56,    90,
      91,   139,    92,   121,    94,   127,   -42,   -42,   146,   148,
      27,   -42,   -42,   102,   103,   104,   150,     5,     0,   111,
       7,     8,     9,    10,   115,   128,   129,   130,    61,   105,
     106,   107,     0,   112,    13,    14,    15,    27,    27,    16,
      17,    18,    56,   133,   122,   123,   124,     2,     0,     0,
       3,     0,     4,    56,   138,     0,     0,   112,     0,     5,
       0,     6,     7,     8,     9,    10,     0,     0,     0,     0,
       0,    11,     0,    12,   145,   149,    13,    14,    15,     0,
       0,    16,    17,    18,     0,     0,    19,    20,     3,     0,
       4,    21,    22,     0,     0,     0,     0,     5,     0,     6,
       7,     8,     9,    10,    98,    99,   100,   101,     0,    11,
       0,    12,     0,     0,    13,    14,    15,     0,     0,    16,
      17,    18,   147,     0,    19,    20,     0,     0,     5,    21,
      22,     7,     8,     9,    10,     0,     0,     0,     0,     0,
     134,   135,   136,   137,     0,    13,    14,    15,     0,     0,
      16,    17,    18,     5,    55,    58,     7,     8,     9,    10,
       0,     0,     0,     5,     0,     0,     7,     8,     9,    10,
      13,    14,    15,     0,     0,    16,    17,    18,     0,     0,
      13,    14,    15,     0,    59,    16,    17,    18,     0,    55,
       0,     5,     0,   114,     7,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
      15,     0,     0,    16,    17,    18,     0,    55,     5,    40,
      75,     7,     8,     9,    10,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    41,     0,
      16,    17,    42,     0,   110,     5,    40,     0,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    14,    15,    41,     0,    16,    17,    42,
       5,    43,     0,     7,     8,     9,    10,     0,     0,     0,
      53,     0,     0,     0,     0,     0,    54,    13,    14,    15,
       0,     0,    16,    17,    18,     5,    55,     0,     7,     8,
       9,    10,     0,     0,     0,     0,    78,     0,     0,     0,
       0,    79,    13,    14,    15,     0,     0,    16,    17,    18,
       0,    55,     5,    40,     0,     7,     8,     9,    10,     0,
       0,     0,     5,    40,     0,     7,     8,     9,    10,    13,
      14,    15,    41,     0,    16,    17,    18,     0,    43,    13,
      14,    15,    41,     0,    16,    17,    42,     5,   110,     0,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
      72,     0,     0,     0,    13,    14,    15,     0,     0,    16,
      17,    18,     5,    55,     0,     7,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    13,
      14,    15,     0,     0,    16,    17,    18,     5,    55,     0,
       7,     8,     9,    10,     0,     0,     0,     5,    76,     0,
       7,     8,     9,    10,    13,    14,    15,    81,     0,    16,
      17,    18,     0,    55,    13,    14,    15,     0,     0,    16,
      17,    18,     5,    55,     0,     7,     8,     9,    10,     0,
       0,     0,     5,    93,     0,     7,     8,     9,    10,    13,
      14,    15,   108,     0,    16,    17,    18,     0,    55,    13,
      14,    15,     0,     0,    16,    17,    18,     5,    55,     0,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,    13,    14,    15,     0,     0,    16,
      17,    18,     5,    55,     0,     7,     8,     9,    10,     0,
       0,     0,     5,   151,     0,     7,     8,     9,    10,    13,
      14,    15,     0,     0,    16,    17,    18,     0,    55,    13,
      14,    15,     0,     0,    16,    17,    18,     0,    55
};

static const yytype_int16 yycheck[] =
{
       1,    27,     6,    13,    28,    81,    22,    37,    23,    28,
      11,    12,    22,    35,    29,    30,    31,    28,    44,    20,
      35,    23,    32,    49,    50,    28,    52,    10,    11,    30,
      35,    57,   108,   109,    60,    36,    62,     0,    39,    35,
       3,     4,     5,    18,    19,    20,    21,    11,    74,    35,
      51,    14,    32,    34,    58,     7,     8,     9,     5,    33,
      23,    24,    34,    26,    90,    91,    92,    34,    94,    70,
      71,     4,    73,    34,    75,    23,    39,    40,    28,    23,
      81,    44,    45,     7,     8,     9,    23,    12,    -1,   115,
      15,    16,    17,    18,    95,    29,    30,    31,    36,    87,
      88,    89,    -1,    91,    29,    30,    31,   108,   109,    34,
      35,    36,   138,   117,   102,   103,   104,     0,    -1,    -1,
       3,    -1,     5,   149,   125,    -1,    -1,   115,    -1,    12,
      -1,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    26,   132,   146,    29,    30,    31,    -1,
      -1,    34,    35,    36,    -1,    -1,    39,    40,     3,    -1,
       5,    44,    45,    -1,    -1,    -1,    -1,    12,    -1,    14,
      15,    16,    17,    18,    82,    83,    84,    85,    -1,    24,
      -1,    26,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      35,    36,     6,    -1,    39,    40,    -1,    -1,    12,    44,
      45,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,    29,    30,    31,    -1,    -1,
      34,    35,    36,    12,    38,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    17,    18,
      29,    30,    31,    -1,    -1,    34,    35,    36,    -1,    -1,
      29,    30,    31,    -1,    43,    34,    35,    36,    -1,    38,
      -1,    12,    -1,    42,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    -1,    34,    35,    36,    -1,    38,    12,    13,
      41,    15,    16,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,
      34,    35,    36,    -1,    38,    12,    13,    -1,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    34,    35,    36,
      12,    38,    -1,    15,    16,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      -1,    -1,    34,    35,    36,    12,    38,    -1,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    -1,    -1,    34,    35,    36,
      -1,    38,    12,    13,    -1,    15,    16,    17,    18,    -1,
      -1,    -1,    12,    13,    -1,    15,    16,    17,    18,    29,
      30,    31,    32,    -1,    34,    35,    36,    -1,    38,    29,
      30,    31,    32,    -1,    34,    35,    36,    12,    38,    -1,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      35,    36,    12,    38,    -1,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    -1,    -1,    34,    35,    36,    12,    38,    -1,
      15,    16,    17,    18,    -1,    -1,    -1,    12,    23,    -1,
      15,    16,    17,    18,    29,    30,    31,    22,    -1,    34,
      35,    36,    -1,    38,    29,    30,    31,    -1,    -1,    34,
      35,    36,    12,    38,    -1,    15,    16,    17,    18,    -1,
      -1,    -1,    12,    23,    -1,    15,    16,    17,    18,    29,
      30,    31,    22,    -1,    34,    35,    36,    -1,    38,    29,
      30,    31,    -1,    -1,    34,    35,    36,    12,    38,    -1,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    29,    30,    31,    -1,    -1,    34,
      35,    36,    12,    38,    -1,    15,    16,    17,    18,    -1,
      -1,    -1,    12,    23,    -1,    15,    16,    17,    18,    29,
      30,    31,    -1,    -1,    34,    35,    36,    -1,    38,    29,
      30,    31,    -1,    -1,    34,    35,    36,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,     0,     3,     5,    12,    14,    15,    16,    17,
      18,    24,    26,    29,    30,    31,    34,    35,    36,    39,
      40,    44,    45,    48,    49,    50,    51,    52,    53,    55,
      56,    57,    60,    61,    62,    64,    66,    67,    68,    28,
      13,    32,    36,    38,    52,    58,    59,    63,    63,    52,
      52,    22,    52,    22,    28,    38,    53,    52,    14,    43,
      52,    60,    52,    37,    18,    19,    20,    21,    10,    11,
      28,    28,    25,    28,    52,    41,    23,    63,    23,    28,
      23,    22,    35,    35,    35,    35,    11,     7,     8,     9,
      52,    52,    52,    23,    52,    28,    32,    48,    58,    58,
      58,    58,     7,     8,     9,    59,    59,    59,    22,    22,
      38,    53,    59,    27,    42,    52,    33,     5,    34,    34,
      34,    34,    59,    59,    59,    48,    48,    23,    29,    30,
      31,    54,    65,    63,    58,    58,    58,    58,    52,     4,
      23,    29,    30,    31,    35,    59,    28,     6,    23,    52,
      23,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    50,    51,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    55,
      56,    57,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    60,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    65,    64,    66,    67,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     6,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     3,
       2,     3,     1,     2,     1,     1,     1,     6,     6,     6,
       6,     5,     7,     9,    10,     4,     4,     4,     5,     5,
       5,     2,     3,     3,     7,     0,     8,     2,     1,     1
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
  case 15: /* declaracaoCenario: ABRE_PARENTESES texto VIRGULA texto FECHA_PARENTESES  */
#line 75 "src/parser.y"
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
#line 1352 "src/parser.tab.c"
    break;

  case 16: /* concatenarCenario: ADICIONAR_CENARIO INICIO texto FIM  */
#line 89 "src/parser.y"
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
#line 1375 "src/parser.tab.c"
    break;

  case 17: /* substituiCenario: SUBSTITUIR_CENARIO texto POR texto NO_CENARIO FIM  */
#line 109 "src/parser.y"
                                                     {
        if (estado != E_DECLARACOES) {
            char * valorCenario = get_string_value(cenarioAtual);
            if (valorCenario == NULL) {
                yyerror("Nenhum cenário atual definido");
            } else {
                char* novoValorCenario = substituir_ocorrencias(valorCenario, (yyvsp[-4].texto), (yyvsp[-2].texto));
                set_string_value(cenarioAtual, novoValorCenario);
                printf("Novo cenário: %s\n", get_string_value(cenarioAtual));
            }
        } else {
            yyerror("Substituição de cenário fora de contexto");
        }
    }
#line 1394 "src/parser.tab.c"
    break;

  case 18: /* texto: palavra  */
#line 125 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1402 "src/parser.tab.c"
    break;

  case 19: /* texto: texto NUMERO  */
#line 128 "src/parser.y"
                   {
         if (DEBUG_BISON) {
             printf("Concatenando: %s + %s\n", (yyvsp[-1].texto), (yyvsp[0].texto));
        }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1413 "src/parser.tab.c"
    break;

  case 20: /* texto: texto palavra  */
#line 134 "src/parser.y"
                    {
        if (DEBUG_BISON) {
            printf("Concatenando: %s + %s\n", (yyvsp[-1].texto), (yyvsp[0].texto));
        }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1424 "src/parser.tab.c"
    break;

  case 21: /* palavra: TOKEN  */
#line 144 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1430 "src/parser.tab.c"
    break;

  case 22: /* palavra: ADJETIVO_POSITIVO  */
#line 145 "src/parser.y"
                        { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1436 "src/parser.tab.c"
    break;

  case 23: /* palavra: ADJETIVO_NEGATIVO  */
#line 146 "src/parser.y"
                        { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1442 "src/parser.tab.c"
    break;

  case 24: /* palavra: ARTIGO  */
#line 147 "src/parser.y"
             { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1448 "src/parser.tab.c"
    break;

  case 25: /* palavra: ENTRE  */
#line 148 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1454 "src/parser.tab.c"
    break;

  case 26: /* palavra: SOMAR  */
#line 149 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1460 "src/parser.tab.c"
    break;

  case 27: /* palavra: ENTRAM  */
#line 150 "src/parser.y"
             { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1466 "src/parser.tab.c"
    break;

  case 28: /* palavra: SAEM  */
#line 151 "src/parser.y"
           { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1472 "src/parser.tab.c"
    break;

  case 29: /* palavra: TODOS  */
#line 152 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1478 "src/parser.tab.c"
    break;

  case 30: /* palavra: E  */
#line 153 "src/parser.y"
        { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1484 "src/parser.tab.c"
    break;

  case 31: /* palavra: ENTAO  */
#line 154 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1490 "src/parser.tab.c"
    break;

  case 32: /* adjetivos: ADJETIVO_POSITIVO  */
#line 158 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1498 "src/parser.tab.c"
    break;

  case 33: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 161 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
#line 1506 "src/parser.tab.c"
    break;

  case 34: /* adjetivos: TOKEN  */
#line 164 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
#line 1514 "src/parser.tab.c"
    break;

  case 35: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 167 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) + 1;
    }
#line 1525 "src/parser.tab.c"
    break;

  case 36: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 173 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) - 1;
    }
#line 1536 "src/parser.tab.c"
    break;

  case 37: /* adjetivos: adjetivos TOKEN  */
#line 179 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1544 "src/parser.tab.c"
    break;

  case 38: /* adjetivos: adjetivos ENTRE  */
#line 182 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1552 "src/parser.tab.c"
    break;

  case 39: /* declaracao: declaracaoInicio texto FIM  */
#line 187 "src/parser.y"
                               {
        printf("Declaração: %s\n", (yyvsp[-2].texto));
    }
#line 1560 "src/parser.tab.c"
    break;

  case 40: /* declaracaoInicio: texto VIRGULA  */
#line 192 "src/parser.y"
                  {
        if (estado == E_DECLARACOES) {
            printf("Início da declaração\n");
            if (DEBUG_BISON) {
                printf("Criando variável: %s\n", (yyvsp[-1].texto));
            }
            add_symbol((yyvsp[-1].texto), INT_VAR);
        }
        (yyval.texto) = (yyvsp[-1].texto);
    }
#line 1575 "src/parser.tab.c"
    break;

  case 41: /* alteracaoElenco: ABRE_COLCHETES texto FECHA_COLCHETES  */
#line 204 "src/parser.y"
                                         {
        if (estado == E_CENA) {
            printf("Alteração de elenco: %s\n", (yyvsp[-1].texto));
        } if (estado == E_DIALOGO) {
            printf("Alteração de elenco: %s\n", (yyvsp[-1].texto));
        } else {
            printf("Alteração de elenco fora de contexto, estado atual: %d\n", estado);
        }
    }
#line 1589 "src/parser.tab.c"
    break;

  case 42: /* valor: NUMERO  */
#line 215 "src/parser.y"
            {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi((yyvsp[0].texto)));
        }
        (yyval.inteiro) = atoi((yyvsp[0].texto));
    }
#line 1600 "src/parser.tab.c"
    break;

  case 43: /* valor: TU MESMO  */
#line 221 "src/parser.y"
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
#line 1616 "src/parser.tab.c"
    break;

  case 44: /* valor: EU  */
#line 232 "src/parser.y"
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
#line 1632 "src/parser.tab.c"
    break;

  case 45: /* valor: texto  */
#line 243 "src/parser.y"
            {
        if (DEBUG_BISON) {
            printf("Valor de texto: %d\n", get_int_value((yyvsp[0].texto)));
        }
        (yyval.inteiro) = get_int_value((yyvsp[0].texto)); //O texto todo é uma variável
    }
#line 1643 "src/parser.tab.c"
    break;

  case 47: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 252 "src/parser.y"
                                       {
        if (DEBUG_BISON) {
            printf("Expressão de soma: %s\n", (yyvsp[-4].texto));
        }
        (yyval.inteiro) = (yyvsp[-2].inteiro) + (yyvsp[0].inteiro); // Exemplo de operação
    }
#line 1654 "src/parser.tab.c"
    break;

  case 48: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 258 "src/parser.y"
                                          {
        if (DEBUG_BISON) {
            printf("Expressão de subtração: %s\n", (yyvsp[-4].texto));
        }
        (yyval.inteiro) = (yyvsp[-2].inteiro) - (yyvsp[0].inteiro);
    }
#line 1665 "src/parser.tab.c"
    break;

  case 49: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 264 "src/parser.y"
                                             {
        if (DEBUG_BISON) {
            printf("Expressão de multiplicação: %s\n", (yyvsp[-4].texto));
        }
        (yyval.inteiro) = (yyvsp[-2].inteiro) * (yyvsp[0].inteiro);
    }
#line 1676 "src/parser.tab.c"
    break;

  case 50: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 270 "src/parser.y"
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
#line 1692 "src/parser.tab.c"
    break;

  case 51: /* if_sentenca: SE condicao VIRGULA texto expressao  */
#line 283 "src/parser.y"
                                       {
        if (DEBUG_BISON) {
            printf("IF BLOCO DETECTADO\n");
            printf("Condicao do IF: %d\n", (yyvsp[-3].inteiro));
            printf("resultado do IF: %d\n", (yyvsp[0].inteiro));
        }
    }
#line 1704 "src/parser.tab.c"
    break;

  case 52: /* if_bloco: SE condicao VIRGULA texto INICIO bloco ENDIF  */
#line 292 "src/parser.y"
                                                {
        if (DEBUG_BISON) { 
            printf("IF BLOCO DETECTADO\n");
        }
    }
#line 1714 "src/parser.tab.c"
    break;

  case 53: /* while: ENQUANTO_COMECO condicao VIRGULA texto INICIO bloco texto ENQUANTO_FIM FIM  */
#line 299 "src/parser.y"
                                                                              {
        if (DEBUG_BISON) { 
            printf("WHILE DETECTADO\n");
        }
    }
#line 1724 "src/parser.tab.c"
    break;

  case 54: /* while: FACA VIRGULA texto INICIO bloco ENQUANTO_COMECO condicao VIRGULA texto FIM  */
#line 304 "src/parser.y"
                                                                                {
        if (DEBUG_BISON) { 
            printf("DO  WHILE DETECTADO\n");
        }
    }
#line 1734 "src/parser.tab.c"
    break;

  case 55: /* condicao: expressao FOR MAIOR expressao  */
#line 311 "src/parser.y"
                                  {
        (yyval.inteiro) = (yyvsp[-3].inteiro) > (yyvsp[0].inteiro);
    }
#line 1742 "src/parser.tab.c"
    break;

  case 56: /* condicao: expressao FOR MENOR expressao  */
#line 314 "src/parser.y"
                                   {
        (yyval.inteiro) = (yyvsp[-3].inteiro) < (yyvsp[0].inteiro);
    }
#line 1750 "src/parser.tab.c"
    break;

  case 57: /* condicao: expressao FOR IGUAL expressao  */
#line 317 "src/parser.y"
                                   {
        (yyval.inteiro) = (yyvsp[-3].inteiro) = (yyvsp[0].inteiro);
    }
#line 1758 "src/parser.tab.c"
    break;

  case 58: /* condicao: expressao NAO FOR MENOR expressao  */
#line 320 "src/parser.y"
                                       {
        (yyval.inteiro) = !((yyvsp[-4].inteiro) < (yyvsp[0].inteiro));
    }
#line 1766 "src/parser.tab.c"
    break;

  case 59: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 323 "src/parser.y"
                                       {
        (yyval.inteiro) = !((yyvsp[-4].inteiro) > (yyvsp[0].inteiro));
    }
#line 1774 "src/parser.tab.c"
    break;

  case 60: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 326 "src/parser.y"
                                       {
        (yyval.inteiro) = !((yyvsp[-4].inteiro) = (yyvsp[0].inteiro));
    }
#line 1782 "src/parser.tab.c"
    break;

  case 61: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 331 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
    }
#line 1793 "src/parser.tab.c"
    break;

  case 62: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 337 "src/parser.y"
                                   {
        if (DEBUG_BISON) {
            printf("if sentenca");
        }
    }
#line 1803 "src/parser.tab.c"
    break;

  case 63: /* dialogo: inicioDialogo texto FIM  */
#line 342 "src/parser.y"
                              {
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
#line 1831 "src/parser.tab.c"
    break;

  case 64: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 366 "src/parser.y"
                                                      {
        switch (estado) {
            case E_TITULO:
                printf("Título com vírgula: %s\n", (yyvsp[-4].texto));
                break;
            case E_DECLARACOES:
                printf("Declarações com vírgula: %s\n", (yyvsp[-4].texto));
                break;
            case E_DIALOGO:
                printf("Diálogo com vírgula: %s\n", (yyvsp[-5].texto));
                if (DEBUG_BISON) {
                    // printf("Tabela de símbolos:\n");
                    // print_symbols();
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
#line 1870 "src/parser.tab.c"
    break;

  case 65: /* $@1: %empty  */
#line 400 "src/parser.y"
                                        {
        personagemDialogo = (yyvsp[-3].texto);
    }
#line 1878 "src/parser.tab.c"
    break;

  case 66: /* dialogo: inicioDialogo texto VIRGULA TU EH $@1 expressao FIM  */
#line 402 "src/parser.y"
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
#line 1894 "src/parser.tab.c"
    break;

  case 67: /* inicioDialogo: texto INICIO  */
#line 416 "src/parser.y"
                 {
        personagemQueFala = (yyvsp[-1].texto);
        if (estado == E_TITULO) {
            printf("Título: %s\n", (yyvsp[-1].texto));
            estado = E_DECLARACOES;
        } 
        else if (estado == E_DIALOGO) {
            printf("Apenas um texto\n");
        } else if (estado == E_CENA) {
            printf("Início do diálogo: %s\n", (yyvsp[-1].texto));
            estado = E_DIALOGO;
        } else {            
            yyerror("Diálogo fora de contexto\n");
        }
    }
#line 1914 "src/parser.tab.c"
    break;

  case 68: /* ato: ATO  */
#line 433 "src/parser.y"
        {
        if (estado == E_DECLARACOES) {
            printf("Ato: %d\n", (yyvsp[0].inteiro));
            estado = E_ATO;
        } else if (estado != E_ATO) {
            yyerror("Ato fora de contexto");
        }
    }
#line 1927 "src/parser.tab.c"
    break;

  case 69: /* cena: CENA  */
#line 443 "src/parser.y"
         {
        if (estado == E_ATO) {
            printf("Cena: %d\n", (yyvsp[0].inteiro));
            estado = E_CENA;
        } else if (estado == E_CENA) {
            // faz algo
        } else {
            printf("Cena fora de contexto, estado atual: %d", estado);
        }
    }
#line 1942 "src/parser.tab.c"
    break;


#line 1946 "src/parser.tab.c"

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

#line 455 "src/parser.y"


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
