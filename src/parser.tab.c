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
  YYSYMBOL_ENQUANTO_COMECO = 3,            /* ENQUANTO_COMECO  */
  YYSYMBOL_ENQUANTO_FIM = 4,               /* ENQUANTO_FIM  */
  YYSYMBOL_MAIOR = 5,                      /* MAIOR  */
  YYSYMBOL_MENOR = 6,                      /* MENOR  */
  YYSYMBOL_IGUAL = 7,                      /* IGUAL  */
  YYSYMBOL_NAO = 8,                        /* NAO  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_ENTAO = 10,                     /* ENTAO  */
  YYSYMBOL_EU = 11,                        /* EU  */
  YYSYMBOL_SE = 12,                        /* SE  */
  YYSYMBOL_SAEM = 13,                      /* SAEM  */
  YYSYMBOL_ENTRAM = 14,                    /* ENTRAM  */
  YYSYMBOL_TODOS = 15,                     /* TODOS  */
  YYSYMBOL_SOMAR = 16,                     /* SOMAR  */
  YYSYMBOL_SUBTRAIR = 17,                  /* SUBTRAIR  */
  YYSYMBOL_DIVIDIR = 18,                   /* DIVIDIR  */
  YYSYMBOL_MULTIPLICAR = 19,               /* MULTIPLICAR  */
  YYSYMBOL_INICIO = 20,                    /* INICIO  */
  YYSYMBOL_FIM = 21,                       /* FIM  */
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
  YYSYMBOL_ATO = 42,                       /* ATO  */
  YYSYMBOL_CENA = 43,                      /* CENA  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_programa = 45,                  /* programa  */
  YYSYMBOL_bloco = 46,                     /* bloco  */
  YYSYMBOL_declaracaoCenario = 47,         /* declaracaoCenario  */
  YYSYMBOL_concatenarCenario = 48,         /* concatenarCenario  */
  YYSYMBOL_substituiCenario = 49,          /* substituiCenario  */
  YYSYMBOL_texto = 50,                     /* texto  */
  YYSYMBOL_palavra = 51,                   /* palavra  */
  YYSYMBOL_adjetivos = 52,                 /* adjetivos  */
  YYSYMBOL_declaracao = 53,                /* declaracao  */
  YYSYMBOL_declaracaoInicio = 54,          /* declaracaoInicio  */
  YYSYMBOL_alteracaoElenco = 55,           /* alteracaoElenco  */
  YYSYMBOL_valor = 56,                     /* valor  */
  YYSYMBOL_expressao = 57,                 /* expressao  */
  YYSYMBOL_if_sentenca = 58,               /* if_sentenca  */
  YYSYMBOL_while = 59,                     /* while  */
  YYSYMBOL_condicao = 60,                  /* condicao  */
  YYSYMBOL_dialogo = 61,                   /* dialogo  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_inicioDialogo = 63,             /* inicioDialogo  */
  YYSYMBOL_ato = 64,                       /* ato  */
  YYSYMBOL_cena = 65                       /* cena  */
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
#define YYLAST   503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    54,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    74,    88,   108,   124,   127,   133,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   157,   160,   163,   166,   172,   178,   181,   186,   191,
     203,   214,   220,   231,   242,   250,   251,   257,   263,   269,
     282,   295,   300,   303,   306,   309,   312,   315,   320,   326,
     329,   353,   387,   387,   403,   420,   430
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
  "\"end of file\"", "error", "\"invalid token\"", "ENQUANTO_COMECO",
  "ENQUANTO_FIM", "MAIOR", "MENOR", "IGUAL", "NAO", "FOR", "ENTAO", "EU",
  "SE", "SAEM", "ENTRAM", "TODOS", "SOMAR", "SUBTRAIR", "DIVIDIR",
  "MULTIPLICAR", "INICIO", "FIM", "ABRE_COLCHETES", "FECHA_COLCHETES",
  "ABRE_PARENTESES", "FECHA_PARENTESES", "VIRGULA", "TOKEN",
  "ADJETIVO_POSITIVO", "ADJETIVO_NEGATIVO", "TU", "EH", "E", "ENTRE",
  "ARTIGO", "MESMO", "NUMERO", "ADICIONAR_CENARIO", "SUBSTITUIR_CENARIO",
  "POR", "NO_CENARIO", "MOSTRAR_CENARIO", "ATO", "CENA", "$accept",
  "programa", "bloco", "declaracaoCenario", "concatenarCenario",
  "substituiCenario", "texto", "palavra", "adjetivos", "declaracao",
  "declaracaoInicio", "alteracaoElenco", "valor", "expressao",
  "if_sentenca", "while", "condicao", "dialogo", "$@1", "inicioDialogo",
  "ato", "cena", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -65,    79,   -65,   222,   -65,   222,   -65,   -65,   -65,   -65,
     469,   469,   -65,   -65,   -65,   -65,   -65,   -65,    -5,   469,
     -65,   -65,   -65,   -65,   -65,   -65,   247,   -65,   -65,   469,
     -65,   -65,   -65,   -65,   156,   -65,   -65,   -65,   -18,   -14,
     -65,   459,   -65,    11,    -3,     4,   324,   349,   469,   195,
     -65,   -65,   -65,   -65,   374,   -65,   272,    13,   -65,     5,
      26,    28,    30,    23,     1,   469,    36,   -65,   469,   384,
     469,   -65,   -65,    35,   -65,   299,   299,   299,   299,    20,
     222,   222,   222,   409,   222,   434,   -65,   185,    37,    34,
      38,    39,    41,   222,   222,   222,   -65,   -65,   -65,   115,
     -65,   -65,    53,    27,   299,   299,   299,   299,   -65,   -65,
     -65,   469,   -65,   -65,   -65,   -65,    24,   222,   -65,   -65,
     -65,   -65,   146,   -65,   -65,   -65,   -65,   -65,    54,    55,
     -65,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    30,     0,    27,    26,    28,    25,
       0,     0,    20,    21,    22,    29,    24,    23,     0,     0,
      65,    66,     3,     8,     9,    10,     0,    17,     7,     0,
      11,    12,    13,     6,     0,     4,     5,    43,     0,    23,
      41,    44,    45,     0,     0,     0,     0,     0,     0,     0,
      64,    39,    18,    19,     0,    58,     0,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,    38,    60,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,     0,
      50,    14,     0,    62,     0,     0,     0,     0,    56,    55,
      57,     0,    16,    33,    31,    32,     0,     0,    46,    47,
      49,    48,     0,    61,    36,    34,    35,    37,     0,     0,
      63,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -22,   -65,   -65,   -65,    -1,   -25,   -65,   -65,
     -65,   -65,   -64,   -45,    44,   -65,    75,   -65,   -65,   -65,
     -65,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    22,    23,    24,    25,    41,    27,   116,    28,
      29,    30,    42,    43,    31,    32,    44,    33,   117,    34,
      35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    53,    59,    60,    61,    62,    80,    81,    82,    46,
      47,    89,    90,    91,    92,    48,    53,    58,    49,    63,
      64,    53,    53,    65,    53,    93,    94,    95,    54,    53,
      66,    53,    79,    56,    74,    96,    97,    98,    75,   100,
     118,   119,   120,   121,    53,   123,    84,    69,   108,   109,
     110,   124,   125,   126,   113,   114,   115,   127,    53,    76,
      53,    77,    53,    78,    83,    88,   104,    85,   103,    87,
     105,   106,   128,   107,   112,   130,   131,   111,    57,     2,
      45,     0,     3,     0,     0,     0,     0,     0,     0,     4,
       0,     5,     6,     7,     8,     9,     0,    53,    26,     0,
       0,    10,     0,    11,     0,     0,    12,    13,    14,     0,
     122,    15,    16,    17,     0,     0,    18,    19,     3,     0,
       0,    20,    21,     0,     0,     4,     0,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,    10,     0,    11,
       0,     0,    12,    13,    14,     0,     0,    15,    16,    17,
     129,     0,    18,    19,     0,     0,     4,    20,    21,     6,
       7,     8,     9,     0,     0,     0,     4,     0,     5,     6,
       7,     8,     9,    12,    13,    14,     0,     0,    15,    16,
      17,     0,    52,    12,    13,    14,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     4,     0,    55,     6,     7,
       8,     9,     0,     0,     0,     4,     0,     0,     6,     7,
       8,     9,    12,    13,    14,     0,     0,    15,    16,    17,
       0,    52,    12,    13,    14,   102,     0,    15,    16,    17,
       0,    52,     4,    37,    70,     6,     7,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      13,    14,    38,     0,    15,    16,    39,     4,    40,     0,
       6,     7,     8,     9,     0,     0,     0,    50,     0,     0,
       0,     0,     0,    51,    12,    13,    14,     0,     0,    15,
      16,    17,     4,    52,     0,     6,     7,     8,     9,     0,
       0,     0,     0,    72,     0,     0,     0,     0,    73,    12,
      13,    14,     0,     0,    15,    16,    17,     0,    52,     4,
      37,     0,     6,     7,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,    14,    38,
       0,    15,    16,    17,     4,    40,     0,     6,     7,     8,
       9,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,    12,    13,    14,     0,     0,    15,    16,    17,     4,
      52,     0,     6,     7,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    12,    13,    14,     0,
       0,    15,    16,    17,     4,    52,     0,     6,     7,     8,
       9,     0,     0,     0,     4,    71,     0,     6,     7,     8,
       9,    12,    13,    14,     0,    86,    15,    16,    17,     0,
      52,    12,    13,    14,     0,     0,    15,    16,    17,     4,
      52,     0,     6,     7,     8,     9,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,    12,    13,    14,     0,
       0,    15,    16,    17,     4,    52,     0,     6,     7,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,   101,
       0,    12,    13,    14,     0,     0,    15,    16,    17,     4,
      52,     0,     6,     7,     8,     9,     0,     0,     0,     4,
       0,     0,     6,     7,     8,     9,    12,    13,    14,     0,
       0,    15,    16,    17,     0,    52,    12,    13,    14,     0,
       0,    15,    16,    17
};

static const yytype_int8 yycheck[] =
{
       1,    26,    16,    17,    18,    19,     5,     6,     7,    10,
      11,    75,    76,    77,    78,    20,    41,    35,    19,     8,
       9,    46,    47,    26,    49,     5,     6,     7,    29,    54,
      26,    56,     9,    34,    21,    80,    81,    82,    33,    84,
     104,   105,   106,   107,    69,    21,    10,    48,    93,    94,
      95,    27,    28,    29,    27,    28,    29,    33,    83,    33,
      85,    33,    87,    33,    65,    30,    32,    68,    31,    70,
      32,    32,   117,    32,    21,    21,    21,    99,    34,     0,
       5,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    12,    13,    14,    15,    16,    -1,   122,    99,    -1,
      -1,    22,    -1,    24,    -1,    -1,    27,    28,    29,    -1,
     111,    32,    33,    34,    -1,    -1,    37,    38,     3,    -1,
      -1,    42,    43,    -1,    -1,    10,    -1,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,
      -1,    -1,    27,    28,    29,    -1,    -1,    32,    33,    34,
       4,    -1,    37,    38,    -1,    -1,    10,    42,    43,    13,
      14,    15,    16,    -1,    -1,    -1,    10,    -1,    12,    13,
      14,    15,    16,    27,    28,    29,    -1,    -1,    32,    33,
      34,    -1,    36,    27,    28,    29,    -1,    -1,    32,    33,
      34,    -1,    -1,    -1,    -1,    10,    -1,    41,    13,    14,
      15,    16,    -1,    -1,    -1,    10,    -1,    -1,    13,    14,
      15,    16,    27,    28,    29,    -1,    -1,    32,    33,    34,
      -1,    36,    27,    28,    29,    40,    -1,    32,    33,    34,
      -1,    36,    10,    11,    39,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    -1,    32,    33,    34,    10,    36,    -1,
      13,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    10,    36,    -1,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    -1,    36,    10,
      11,    -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      -1,    32,    33,    34,    10,    36,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    32,    33,    34,    10,
      36,    -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    10,    36,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    10,    21,    -1,    13,    14,    15,
      16,    27,    28,    29,    -1,    21,    32,    33,    34,    -1,
      36,    27,    28,    29,    -1,    -1,    32,    33,    34,    10,
      36,    -1,    13,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    32,    33,    34,    10,    36,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,    29,    -1,    -1,    32,    33,    34,    10,
      36,    -1,    13,    14,    15,    16,    -1,    -1,    -1,    10,
      -1,    -1,    13,    14,    15,    16,    27,    28,    29,    -1,
      -1,    32,    33,    34,    -1,    36,    27,    28,    29,    -1,
      -1,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,     0,     3,    10,    12,    13,    14,    15,    16,
      22,    24,    27,    28,    29,    32,    33,    34,    37,    38,
      42,    43,    46,    47,    48,    49,    50,    51,    53,    54,
      55,    58,    59,    61,    63,    64,    65,    11,    30,    34,
      36,    50,    56,    57,    60,    60,    50,    50,    20,    50,
      20,    26,    36,    51,    50,    41,    50,    58,    35,    16,
      17,    18,    19,     8,     9,    26,    26,    23,    26,    50,
      39,    21,    21,    26,    21,    33,    33,    33,    33,     9,
       5,     6,     7,    50,    10,    50,    21,    50,    30,    56,
      56,    56,    56,     5,     6,     7,    57,    57,    57,    20,
      57,    25,    40,    31,    32,    32,    32,    32,    57,    57,
      57,    46,    21,    27,    28,    29,    52,    62,    56,    56,
      56,    56,    50,    21,    27,    28,    29,    33,    57,     4,
      21,    21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    47,    48,    49,    50,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    53,    54,
      55,    56,    56,    56,    56,    57,    57,    57,    57,    57,
      58,    59,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    62,    61,    63,    64,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     6,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     2,
       3,     1,     2,     1,     1,     1,     6,     6,     6,     6,
       5,     9,     4,     4,     4,     5,     5,     5,     2,     3,
       3,     7,     0,     8,     2,     1,     1
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
#line 1322 "src/parser.tab.c"
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
#line 1345 "src/parser.tab.c"
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
                printf("Novo cenário: %s\n", get_string_value(cenarioAtual));
            }
        } else {
            yyerror("Substituição de cenário fora de contexto");
        }
    }
#line 1364 "src/parser.tab.c"
    break;

  case 17: /* texto: palavra  */
#line 124 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1372 "src/parser.tab.c"
    break;

  case 18: /* texto: texto NUMERO  */
#line 127 "src/parser.y"
                   {
         if (DEBUG_BISON) {
             printf("Concatenando: %s + %s\n", (yyvsp[-1].texto), (yyvsp[0].texto));
        }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1383 "src/parser.tab.c"
    break;

  case 19: /* texto: texto palavra  */
#line 133 "src/parser.y"
                    {
        if (DEBUG_BISON) {
            printf("Concatenando: %s + %s\n", (yyvsp[-1].texto), (yyvsp[0].texto));
        }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1394 "src/parser.tab.c"
    break;

  case 20: /* palavra: TOKEN  */
#line 143 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1400 "src/parser.tab.c"
    break;

  case 21: /* palavra: ADJETIVO_POSITIVO  */
#line 144 "src/parser.y"
                        { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1406 "src/parser.tab.c"
    break;

  case 22: /* palavra: ADJETIVO_NEGATIVO  */
#line 145 "src/parser.y"
                        { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1412 "src/parser.tab.c"
    break;

  case 23: /* palavra: ARTIGO  */
#line 146 "src/parser.y"
             { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1418 "src/parser.tab.c"
    break;

  case 24: /* palavra: ENTRE  */
#line 147 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1424 "src/parser.tab.c"
    break;

  case 25: /* palavra: SOMAR  */
#line 148 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1430 "src/parser.tab.c"
    break;

  case 26: /* palavra: ENTRAM  */
#line 149 "src/parser.y"
             { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1436 "src/parser.tab.c"
    break;

  case 27: /* palavra: SAEM  */
#line 150 "src/parser.y"
           { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1442 "src/parser.tab.c"
    break;

  case 28: /* palavra: TODOS  */
#line 151 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1448 "src/parser.tab.c"
    break;

  case 29: /* palavra: E  */
#line 152 "src/parser.y"
        { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1454 "src/parser.tab.c"
    break;

  case 30: /* palavra: ENTAO  */
#line 153 "src/parser.y"
            { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1460 "src/parser.tab.c"
    break;

  case 31: /* adjetivos: ADJETIVO_POSITIVO  */
#line 157 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1468 "src/parser.tab.c"
    break;

  case 32: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 160 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
#line 1476 "src/parser.tab.c"
    break;

  case 33: /* adjetivos: TOKEN  */
#line 163 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
#line 1484 "src/parser.tab.c"
    break;

  case 34: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 166 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) + 1;
    }
#line 1495 "src/parser.tab.c"
    break;

  case 35: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 172 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) - 1;
    }
#line 1506 "src/parser.tab.c"
    break;

  case 36: /* adjetivos: adjetivos TOKEN  */
#line 178 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1514 "src/parser.tab.c"
    break;

  case 37: /* adjetivos: adjetivos ENTRE  */
#line 181 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1522 "src/parser.tab.c"
    break;

  case 38: /* declaracao: declaracaoInicio texto FIM  */
#line 186 "src/parser.y"
                               {
        printf("Declaração: %s\n", (yyvsp[-2].texto));
    }
#line 1530 "src/parser.tab.c"
    break;

  case 39: /* declaracaoInicio: texto VIRGULA  */
#line 191 "src/parser.y"
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
#line 1545 "src/parser.tab.c"
    break;

  case 40: /* alteracaoElenco: ABRE_COLCHETES texto FECHA_COLCHETES  */
#line 203 "src/parser.y"
                                         {
        if (estado == E_CENA) {
            printf("Alteração de elenco: %s\n", (yyvsp[-1].texto));
        } if (estado == E_DIALOGO) {
            printf("Alteração de elenco: %s\n", (yyvsp[-1].texto));
        } else {
            printf("Alteração de elenco fora de contexto, estado atual: %d\n", estado);
        }
    }
#line 1559 "src/parser.tab.c"
    break;

  case 41: /* valor: NUMERO  */
#line 214 "src/parser.y"
            {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi((yyvsp[0].texto)));
        }
        (yyval.inteiro) = atoi((yyvsp[0].texto));
    }
#line 1570 "src/parser.tab.c"
    break;

  case 42: /* valor: TU MESMO  */
#line 220 "src/parser.y"
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
#line 1586 "src/parser.tab.c"
    break;

  case 43: /* valor: EU  */
#line 231 "src/parser.y"
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
#line 1602 "src/parser.tab.c"
    break;

  case 44: /* valor: texto  */
#line 242 "src/parser.y"
            {
        if (DEBUG_BISON) {
            printf("Valor de texto: %d\n", get_int_value((yyvsp[0].texto)));
        }
        (yyval.inteiro) = get_int_value((yyvsp[0].texto)); //O texto todo é uma variável
    }
#line 1613 "src/parser.tab.c"
    break;

  case 46: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 251 "src/parser.y"
                                       {
        if (DEBUG_BISON) {
            printf("Expressão de soma: %s\n", (yyvsp[-4].texto));
        }
        (yyval.inteiro) = (yyvsp[-2].inteiro) + (yyvsp[0].inteiro); // Exemplo de operação
    }
#line 1624 "src/parser.tab.c"
    break;

  case 47: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 257 "src/parser.y"
                                          {
        if (DEBUG_BISON) {
            printf("Expressão de subtração: %s\n", (yyvsp[-4].texto));
        }
        (yyval.inteiro) = (yyvsp[-2].inteiro) - (yyvsp[0].inteiro);
    }
#line 1635 "src/parser.tab.c"
    break;

  case 48: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 263 "src/parser.y"
                                             {
        if (DEBUG_BISON) {
            printf("Expressão de multiplicação: %s\n", (yyvsp[-4].texto));
        }
        (yyval.inteiro) = (yyvsp[-2].inteiro) * (yyvsp[0].inteiro);
    }
#line 1646 "src/parser.tab.c"
    break;

  case 49: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 269 "src/parser.y"
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
#line 1662 "src/parser.tab.c"
    break;

  case 50: /* if_sentenca: SE condicao VIRGULA ENTAO expressao  */
#line 282 "src/parser.y"
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
#line 1678 "src/parser.tab.c"
    break;

  case 51: /* while: ENQUANTO_COMECO condicao VIRGULA texto INICIO bloco texto ENQUANTO_FIM FIM  */
#line 295 "src/parser.y"
                                                                              {
        printf("WHILE DETECTADO\n");
    }
#line 1686 "src/parser.tab.c"
    break;

  case 52: /* condicao: expressao FOR MAIOR expressao  */
#line 300 "src/parser.y"
                                  {
        (yyval.inteiro) = (yyvsp[-3].inteiro) > (yyvsp[0].inteiro);
    }
#line 1694 "src/parser.tab.c"
    break;

  case 53: /* condicao: expressao FOR MENOR expressao  */
#line 303 "src/parser.y"
                                   {
        (yyval.inteiro) = (yyvsp[-3].inteiro) < (yyvsp[0].inteiro);
    }
#line 1702 "src/parser.tab.c"
    break;

  case 54: /* condicao: expressao FOR IGUAL expressao  */
#line 306 "src/parser.y"
                                   {
        (yyval.inteiro) = (yyvsp[-3].inteiro) = (yyvsp[0].inteiro);
    }
#line 1710 "src/parser.tab.c"
    break;

  case 55: /* condicao: expressao NAO FOR MENOR expressao  */
#line 309 "src/parser.y"
                                       {
        (yyval.inteiro) = !((yyvsp[-4].inteiro) < (yyvsp[0].inteiro));
    }
#line 1718 "src/parser.tab.c"
    break;

  case 56: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 312 "src/parser.y"
                                       {
        (yyval.inteiro) = !((yyvsp[-4].inteiro) > (yyvsp[0].inteiro));
    }
#line 1726 "src/parser.tab.c"
    break;

  case 57: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 315 "src/parser.y"
                                       {
        (yyval.inteiro) = !((yyvsp[-4].inteiro) = (yyvsp[0].inteiro));
    }
#line 1734 "src/parser.tab.c"
    break;

  case 58: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 320 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
    }
#line 1745 "src/parser.tab.c"
    break;

  case 59: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 326 "src/parser.y"
                                   {

    }
#line 1753 "src/parser.tab.c"
    break;

  case 60: /* dialogo: inicioDialogo texto FIM  */
#line 329 "src/parser.y"
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
#line 1781 "src/parser.tab.c"
    break;

  case 61: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 353 "src/parser.y"
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
#line 1820 "src/parser.tab.c"
    break;

  case 62: /* $@1: %empty  */
#line 387 "src/parser.y"
                                        {
        personagemDialogo = (yyvsp[-3].texto);
    }
#line 1828 "src/parser.tab.c"
    break;

  case 63: /* dialogo: inicioDialogo texto VIRGULA TU EH $@1 expressao FIM  */
#line 389 "src/parser.y"
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
#line 1844 "src/parser.tab.c"
    break;

  case 64: /* inicioDialogo: texto INICIO  */
#line 403 "src/parser.y"
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
#line 1864 "src/parser.tab.c"
    break;

  case 65: /* ato: ATO  */
#line 420 "src/parser.y"
        {
        if (estado == E_DECLARACOES) {
            printf("Ato: %d\n", (yyvsp[0].inteiro));
            estado = E_ATO;
        } else if (estado != E_ATO) {
            yyerror("Ato fora de contexto");
        }
    }
#line 1877 "src/parser.tab.c"
    break;

  case 66: /* cena: CENA  */
#line 430 "src/parser.y"
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
#line 1892 "src/parser.tab.c"
    break;


#line 1896 "src/parser.tab.c"

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

#line 442 "src/parser.y"


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
