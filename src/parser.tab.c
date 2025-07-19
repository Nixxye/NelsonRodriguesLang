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


#line 98 "src/parser.tab.c"

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
  YYSYMBOL_SIM = 24,                       /* SIM  */
  YYSYMBOL_INTERROGACAO = 25,              /* INTERROGACAO  */
  YYSYMBOL_ABRE_COLCHETES = 26,            /* ABRE_COLCHETES  */
  YYSYMBOL_FECHA_COLCHETES = 27,           /* FECHA_COLCHETES  */
  YYSYMBOL_ABRE_PARENTESES = 28,           /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 29,          /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 30,                   /* VIRGULA  */
  YYSYMBOL_TOKEN = 31,                     /* TOKEN  */
  YYSYMBOL_ADJETIVO_POSITIVO = 32,         /* ADJETIVO_POSITIVO  */
  YYSYMBOL_ADJETIVO_NEGATIVO = 33,         /* ADJETIVO_NEGATIVO  */
  YYSYMBOL_TU = 34,                        /* TU  */
  YYSYMBOL_EH = 35,                        /* EH  */
  YYSYMBOL_E = 36,                         /* E  */
  YYSYMBOL_ENTRE = 37,                     /* ENTRE  */
  YYSYMBOL_ARTIGO = 38,                    /* ARTIGO  */
  YYSYMBOL_MESMO = 39,                     /* MESMO  */
  YYSYMBOL_NUMERO = 40,                    /* NUMERO  */
  YYSYMBOL_ADICIONAR_CENARIO = 41,         /* ADICIONAR_CENARIO  */
  YYSYMBOL_SUBSTITUIR_CENARIO = 42,        /* SUBSTITUIR_CENARIO  */
  YYSYMBOL_POR = 43,                       /* POR  */
  YYSYMBOL_NO_CENARIO = 44,                /* NO_CENARIO  */
  YYSYMBOL_MOSTRAR_CENARIO = 45,           /* MOSTRAR_CENARIO  */
  YYSYMBOL_MOSTRA_VALOR = 46,              /* MOSTRA_VALOR  */
  YYSYMBOL_LE_VALOR = 47,                  /* LE_VALOR  */
  YYSYMBOL_ATO = 48,                       /* ATO  */
  YYSYMBOL_CENA = 49,                      /* CENA  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_programa = 51,                  /* programa  */
  YYSYMBOL_bloco = 52,                     /* bloco  */
  YYSYMBOL_instrucao = 53,                 /* instrucao  */
  YYSYMBOL_declaracaoCenario = 54,         /* declaracaoCenario  */
  YYSYMBOL_concatenarCenario = 55,         /* concatenarCenario  */
  YYSYMBOL_substituiCenario = 56,          /* substituiCenario  */
  YYSYMBOL_declaracaoQuestionamento = 57,  /* declaracaoQuestionamento  */
  YYSYMBOL_texto = 58,                     /* texto  */
  YYSYMBOL_palavra = 59,                   /* palavra  */
  YYSYMBOL_adjetivos = 60,                 /* adjetivos  */
  YYSYMBOL_declaracao = 61,                /* declaracao  */
  YYSYMBOL_declaracaoInicio = 62,          /* declaracaoInicio  */
  YYSYMBOL_personagensEntrando = 63,       /* personagensEntrando  */
  YYSYMBOL_personagensSaindo = 64,         /* personagensSaindo  */
  YYSYMBOL_alteracaoElenco = 65,           /* alteracaoElenco  */
  YYSYMBOL_valor = 66,                     /* valor  */
  YYSYMBOL_expressao = 67,                 /* expressao  */
  YYSYMBOL_if_sentenca = 68,               /* if_sentenca  */
  YYSYMBOL_if_bloco = 69,                  /* if_bloco  */
  YYSYMBOL_while_aux = 70,                 /* while_aux  */
  YYSYMBOL_while = 71,                     /* while  */
  YYSYMBOL_72_1 = 72,                      /* $@1  */
  YYSYMBOL_73_2 = 73,                      /* $@2  */
  YYSYMBOL_condicao = 74,                  /* condicao  */
  YYSYMBOL_dialogo = 75,                   /* dialogo  */
  YYSYMBOL_inicioDialogo = 76,             /* inicioDialogo  */
  YYSYMBOL_ato = 77,                       /* ato  */
  YYSYMBOL_cena = 78                       /* cena  */
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
#define YYLAST   266

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    64,    68,    69,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    92,
     106,   126,   145,   158,   171,   187,   190,   196,   206,   210,
     213,   216,   219,   225,   231,   234,   239,   246,   257,   268,
     279,   291,   302,   313,   326,   339,   352,   361,   367,   384,
     401,   416,   419,   423,   427,   431,   440,   449,   456,   474,
     473,   487,   486,   515,   518,   521,   524,   527,   530,   536,
     542,   547,   561,   593,   627,   647,   666,   699,   713
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
  "SUBTRAIR", "DIVIDIR", "MULTIPLICAR", "INICIO", "FIM", "SIM",
  "INTERROGACAO", "ABRE_COLCHETES", "FECHA_COLCHETES", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "TOKEN", "ADJETIVO_POSITIVO",
  "ADJETIVO_NEGATIVO", "TU", "EH", "E", "ENTRE", "ARTIGO", "MESMO",
  "NUMERO", "ADICIONAR_CENARIO", "SUBSTITUIR_CENARIO", "POR", "NO_CENARIO",
  "MOSTRAR_CENARIO", "MOSTRA_VALOR", "LE_VALOR", "ATO", "CENA", "$accept",
  "programa", "bloco", "instrucao", "declaracaoCenario",
  "concatenarCenario", "substituiCenario", "declaracaoQuestionamento",
  "texto", "palavra", "adjetivos", "declaracao", "declaracaoInicio",
  "personagensEntrando", "personagensSaindo", "alteracaoElenco", "valor",
  "expressao", "if_sentenca", "if_bloco", "while_aux", "while", "$@1",
  "$@2", "condicao", "dialogo", "inicioDialogo", "ato", "cena", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -111,   143,  -111,   -13,  -111,    67,   244,    15,  -111,    -2,
      15,  -111,  -111,   176,  -111,  -111,  -111,  -111,  -111,   209,
    -111,  -111,    15,    56,  -111,  -111,  -111,  -111,  -111,     8,
    -111,  -111,    15,    67,  -111,    24,   237,  -111,   116,  -111,
      46,    44,    15,    15,    61,    -7,    15,   137,  -111,  -111,
      -6,  -111,  -111,  -111,   -21,    15,    15,    67,  -111,   163,
      55,   -15,    66,  -111,    69,    96,   117,   123,    93,   203,
      15,   116,   205,   116,   218,   114,    15,    28,    15,   149,
     153,  -111,   116,   116,   140,  -111,    63,  -111,  -111,    15,
      39,    39,    39,    39,   255,    67,    67,    67,    27,  -111,
      15,    15,  -111,  -111,    97,  -111,    50,  -111,  -111,    15,
     162,   178,   183,   176,    99,   172,   180,   184,   186,    67,
      67,    67,  -111,  -111,  -111,   176,    89,    -8,  -111,   116,
     116,  -111,   210,   104,    51,  -111,  -111,   195,  -111,    39,
      39,    39,    39,  -111,  -111,  -111,   147,  -111,   150,  -111,
    -111,   182,   215,    67,   176,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,   169,   176,    15,     7,
     109,   219,  -111,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    58,     0,     0,     0,    28,     0,
       0,    77,    78,     3,     4,    10,    12,    13,    11,    38,
      25,     9,     0,    18,    14,    15,    16,    17,     8,     0,
       6,     7,     0,     0,    49,     0,     0,    47,    50,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     5,    76,
      24,    37,    26,    27,     0,     0,     0,     0,    69,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,    41,     0,    38,     0,     0,     0,     0,     0,     0,
       0,    36,    39,    40,     0,    71,     0,    70,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,    44,    46,     0,    20,     0,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,     0,    47,    25,    56,    42,
      43,    19,     0,     0,     0,    74,    75,     0,    59,     0,
       0,     0,     0,    67,    66,    68,     0,    21,    28,    29,
      30,     0,     0,     0,     0,    52,    53,    55,    54,    57,
      73,    34,    32,    33,    35,    72,     0,     0,     0,    38,
       0,     0,    62,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -110,   -12,  -111,  -111,  -111,  -111,    -1,   -11,
    -111,  -111,  -111,   204,  -111,  -111,    23,   132,   217,  -111,
    -111,  -111,  -111,  -111,   -22,  -111,  -111,  -111,  -111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    13,    14,    15,    16,    17,    18,    38,    20,
     151,    21,    22,    23,    72,    24,    39,    40,    25,    26,
      33,    27,   154,   113,    41,    28,    29,    30,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    48,    81,   137,    79,   -27,    45,    88,    53,    47,
       8,    62,    19,   171,   -27,   146,     8,    32,    80,    52,
      46,    54,    57,    76,     8,    52,   -27,    53,    59,    49,
     -27,    61,    50,    52,    53,    84,    53,    51,     8,     8,
      34,    71,    73,    53,   167,    77,     8,    52,    53,   125,
      53,   105,    34,    58,    82,    83,    68,    69,     8,     8,
      53,    35,    53,    63,    34,    36,    53,   126,    52,    98,
       8,    53,    53,    35,    70,   104,    75,   106,    87,    37,
      34,     8,   148,   149,   150,    35,    55,   127,   114,    36,
      52,    37,    56,    53,   132,    53,    89,   110,     8,   129,
     130,    35,   -26,    53,    94,    36,    90,    37,   133,   111,
     112,   -26,    19,   115,   116,   117,   118,    34,    53,    53,
     -26,   138,   127,   -26,    19,    48,   131,   -26,     8,   -26,
       8,   166,   172,    91,    48,     8,    19,    52,    35,    52,
       8,   103,    36,     2,   126,    19,     3,     8,     4,    52,
       3,   159,     4,    19,    92,    48,    52,     5,    53,    53,
      93,     5,   155,   156,   157,   158,   169,   170,     8,     6,
     109,     7,   107,     6,     8,     7,   108,    52,     8,     3,
      78,     4,   -31,   -31,     9,    10,    85,   -31,     9,    10,
       5,    11,    12,    86,     8,    11,    12,   134,     3,   168,
     153,   135,     6,    52,     7,   160,   136,     8,   139,     5,
      95,    96,    97,   161,   162,   163,   140,     9,    10,   164,
     141,     6,   142,     7,    11,    12,     8,   122,   123,   124,
     128,    49,    99,   147,    50,   100,     9,    10,   165,    51,
       8,   101,   173,    11,    12,   102,    60,    74,    55,    52,
       0,   143,   144,   145,    56,    64,    65,    66,    67,    42,
      43,    44,   119,   120,   121,   128,   152
};

static const yytype_int16 yycheck[] =
{
       1,    13,    23,   113,    10,    13,     7,    22,    19,    10,
      31,    33,    13,     6,    22,   125,    31,    30,    24,    40,
      22,    22,    14,    30,    31,    40,    34,    38,    29,    22,
      38,    32,    25,    40,    45,    57,    47,    30,    31,    31,
      13,    42,    43,    54,   154,    46,    31,    40,    59,    22,
      61,    23,    13,    45,    55,    56,    10,    11,    31,    31,
      71,    34,    73,    39,    13,    38,    77,    40,    40,    70,
      31,    82,    83,    34,    30,    76,    15,    78,    23,    40,
      13,    31,    31,    32,    33,    34,    30,    98,    89,    38,
      40,    40,    36,   104,    44,   106,    30,    34,    31,   100,
     101,    34,    13,   114,    11,    38,    37,    40,   109,    46,
      47,    22,   113,    90,    91,    92,    93,    13,   129,   130,
      31,    22,   133,    34,   125,   137,    29,    38,    31,    40,
      31,   153,    23,    37,   146,    31,   137,    40,    34,    40,
      31,    27,    38,     0,    40,   146,     3,    31,     5,    40,
       3,     4,     5,   154,    37,   167,    40,    14,   169,   170,
      37,    14,   139,   140,   141,   142,   167,   168,    31,    26,
      30,    28,    23,    26,    31,    28,    23,    40,    31,     3,
      43,     5,    32,    33,    41,    42,    23,    37,    41,    42,
      14,    48,    49,    30,    31,    48,    49,    35,     3,    30,
       5,    23,    26,    40,    28,    23,    23,    31,    36,    14,
       7,     8,     9,    31,    32,    33,    36,    41,    42,    37,
      36,    26,    36,    28,    48,    49,    31,    95,    96,    97,
      98,    22,    27,    23,    25,    30,    41,    42,    23,    30,
      31,    36,    23,    48,    49,    27,    29,    43,    30,    40,
      -1,   119,   120,   121,    36,    18,    19,    20,    21,    15,
      16,    17,     7,     8,     9,   133,   134
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,     0,     3,     5,    14,    26,    28,    31,    41,
      42,    48,    49,    52,    53,    54,    55,    56,    57,    58,
      59,    61,    62,    63,    65,    68,    69,    71,    75,    76,
      77,    78,    30,    70,    13,    34,    38,    40,    58,    66,
      67,    74,    15,    16,    17,    58,    22,    58,    53,    22,
      25,    30,    40,    59,    58,    30,    36,    14,    45,    58,
      68,    58,    74,    39,    18,    19,    20,    21,    10,    11,
      30,    58,    64,    58,    63,    15,    30,    58,    43,    10,
      24,    23,    58,    58,    74,    23,    30,    23,    22,    30,
      37,    37,    37,    37,    11,     7,     8,     9,    58,    27,
      30,    36,    27,    27,    58,    23,    58,    23,    23,    30,
      34,    46,    47,    73,    58,    66,    66,    66,    66,     7,
       8,     9,    67,    67,    67,    22,    40,    59,    67,    58,
      58,    29,    44,    58,    35,    23,    23,    52,    22,    36,
      36,    36,    36,    67,    67,    67,    52,    23,    31,    32,
      33,    60,    67,     5,    72,    66,    66,    66,    66,     4,
      23,    31,    32,    33,    37,    23,    74,    52,    30,    58,
      58,     6,    23,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      55,    56,    57,    57,    57,    58,    58,    58,    59,    60,
      60,    60,    60,    60,    60,    60,    61,    62,    63,    63,
      63,    64,    64,    64,    65,    65,    65,    66,    66,    66,
      66,    67,    67,    67,    67,    67,    68,    69,    70,    72,
      71,    73,    71,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    76,    77,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     6,     4,     4,     2,     1,     2,     2,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     2,     1,     3,
       3,     1,     3,     3,     4,     4,     4,     1,     2,     1,
       1,     1,     6,     6,     6,     6,     5,     7,     0,     0,
      11,     0,    11,     4,     4,     4,     5,     5,     5,     2,
       3,     3,     7,     7,     5,     5,     2,     1,     1
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
  case 4: /* bloco: instrucao  */
#line 68 "src/parser.y"
                                {  }
#line 1295 "src/parser.tab.c"
    break;

  case 5: /* bloco: bloco instrucao  */
#line 69 "src/parser.y"
                               {  }
#line 1301 "src/parser.tab.c"
    break;

  case 19: /* declaracaoCenario: ABRE_PARENTESES texto VIRGULA texto FECHA_PARENTESES  */
#line 92 "src/parser.y"
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
#line 1318 "src/parser.tab.c"
    break;

  case 20: /* concatenarCenario: ADICIONAR_CENARIO INICIO texto FIM  */
#line 106 "src/parser.y"
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
#line 1341 "src/parser.tab.c"
    break;

  case 21: /* substituiCenario: SUBSTITUIR_CENARIO texto POR texto NO_CENARIO FIM  */
#line 126 "src/parser.y"
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
#line 1362 "src/parser.tab.c"
    break;

  case 22: /* declaracaoQuestionamento: texto INTERROGACAO NAO FIM  */
#line 145 "src/parser.y"
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
#line 1380 "src/parser.tab.c"
    break;

  case 23: /* declaracaoQuestionamento: texto INTERROGACAO SIM FIM  */
#line 158 "src/parser.y"
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
#line 1398 "src/parser.tab.c"
    break;

  case 24: /* declaracaoQuestionamento: texto INTERROGACAO  */
#line 171 "src/parser.y"
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
#line 1416 "src/parser.tab.c"
    break;

  case 25: /* texto: palavra  */
#line 187 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1424 "src/parser.tab.c"
    break;

  case 26: /* texto: texto NUMERO  */
#line 190 "src/parser.y"
                   {
        //  if (DEBUG_BISON) {
        //      printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1435 "src/parser.tab.c"
    break;

  case 27: /* texto: texto palavra  */
#line 196 "src/parser.y"
                    {
        // if (DEBUG_BISON) {
        //     printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1446 "src/parser.tab.c"
    break;

  case 28: /* palavra: TOKEN  */
#line 206 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1452 "src/parser.tab.c"
    break;

  case 29: /* adjetivos: ADJETIVO_POSITIVO  */
#line 210 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1460 "src/parser.tab.c"
    break;

  case 30: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 213 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
#line 1468 "src/parser.tab.c"
    break;

  case 31: /* adjetivos: TOKEN  */
#line 216 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
#line 1476 "src/parser.tab.c"
    break;

  case 32: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 219 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) + 1;
    }
#line 1487 "src/parser.tab.c"
    break;

  case 33: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 225 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) - 1;
    }
#line 1498 "src/parser.tab.c"
    break;

  case 34: /* adjetivos: adjetivos TOKEN  */
#line 231 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1506 "src/parser.tab.c"
    break;

  case 35: /* adjetivos: adjetivos ENTRE  */
#line 234 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1514 "src/parser.tab.c"
    break;

  case 36: /* declaracao: declaracaoInicio texto FIM  */
#line 239 "src/parser.y"
                               {
        if (DEBUG_BISON) {
            printf("Declaração: %s\n", (yyvsp[-1].texto));
        }
    }
#line 1524 "src/parser.tab.c"
    break;

  case 37: /* declaracaoInicio: texto VIRGULA  */
#line 246 "src/parser.y"
                  {
        if (estado == E_DECLARACOES) {
            if (DEBUG_BISON) {
                printf("Criando variável: %s\n", (yyvsp[-1].texto));
            }
            add_symbol((yyvsp[-1].texto), INT_VAR);
        }
        (yyval.texto) = (yyvsp[-1].texto);
    }
#line 1538 "src/parser.tab.c"
    break;

  case 38: /* personagensEntrando: texto  */
#line 257 "src/parser.y"
          {
        Symbol *sym = get_symbol((yyvsp[0].texto));
        if (!sym) {
            printf("Personagem não declarado: %s", (yyvsp[0].texto));
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 1;
    }
#line 1554 "src/parser.tab.c"
    break;

  case 39: /* personagensEntrando: personagensEntrando VIRGULA texto  */
#line 268 "src/parser.y"
                                        {
        Symbol *sym = get_symbol((yyvsp[0].texto));
        if (!sym) {
            printf("Personagem não declarado: %s", (yyvsp[0].texto));
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 1;
    }
#line 1570 "src/parser.tab.c"
    break;

  case 40: /* personagensEntrando: personagensEntrando E texto  */
#line 279 "src/parser.y"
                                  {
        Symbol *sym = get_symbol((yyvsp[0].texto));
        if (!sym) {
            printf("Personagem não declarado: %s", (yyvsp[0].texto));
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 1;
    }
#line 1586 "src/parser.tab.c"
    break;

  case 41: /* personagensSaindo: texto  */
#line 291 "src/parser.y"
          {
        Symbol *sym = get_symbol((yyvsp[0].texto));
        if (!sym) {
            printf("Personagem não declarado: %s", (yyvsp[0].texto));
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 0;
    }
#line 1602 "src/parser.tab.c"
    break;

  case 42: /* personagensSaindo: personagensSaindo VIRGULA texto  */
#line 302 "src/parser.y"
                                      {
        Symbol *sym = get_symbol((yyvsp[0].texto));
        if (!sym) {
            printf("Personagem não declarado: %s", (yyvsp[0].texto));
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 0;
    }
#line 1618 "src/parser.tab.c"
    break;

  case 43: /* personagensSaindo: personagensSaindo E texto  */
#line 313 "src/parser.y"
                                {
        Symbol *sym = get_symbol((yyvsp[0].texto));
        if (!sym) {
            printf("Personagem não declarado: %s", (yyvsp[0].texto));
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 0;
    }
#line 1634 "src/parser.tab.c"
    break;

  case 44: /* alteracaoElenco: ABRE_COLCHETES ENTRAM personagensEntrando FECHA_COLCHETES  */
#line 326 "src/parser.y"
                                                              {
        if (estado == E_CENA) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", (yyvsp[-2].texto));
            }
        } else if (estado == E_DIALOGO) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", (yyvsp[-2].texto));
            }
        } else {
            printf("Alteração de elenco fora de contexto, estado atual: %d\n", estado);
        }
    }
#line 1652 "src/parser.tab.c"
    break;

  case 45: /* alteracaoElenco: ABRE_COLCHETES SAEM personagensSaindo FECHA_COLCHETES  */
#line 339 "src/parser.y"
                                                            {
        if (estado == E_CENA) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", (yyvsp[-2].texto));
            }
        } else if (estado == E_DIALOGO) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", (yyvsp[-2].texto));
            }
        } else {
            printf("Alteração de elenco fora de contexto, estado atual: %d\n", estado);
        }
    }
#line 1670 "src/parser.tab.c"
    break;

  case 46: /* alteracaoElenco: ABRE_COLCHETES TODOS SAEM FECHA_COLCHETES  */
#line 352 "src/parser.y"
                                                {
        if (DEBUG_BISON) {
            printf("Todos os personagens estão inativos\n");
        }
        // Ativa todos os personagens
        desativar_todos_personagens();
    }
#line 1682 "src/parser.tab.c"
    break;

  case 47: /* valor: NUMERO  */
#line 361 "src/parser.y"
           {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi((yyvsp[0].texto)));
        }
        (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), atoi((yyvsp[0].texto)), 0);
    }
#line 1693 "src/parser.tab.c"
    break;

  case 48: /* valor: TU MESMO  */
#line 367 "src/parser.y"
             {
        if (personagemDialogo == NULL) {
            yyerror("Variável 'tu mesmo' não definida");
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            if (DEBUG_BISON) {
                // printf("Valor de 'tu mesmo': %d\n", get_int_value(personagemDialogo));
            }
            Symbol *sym = get_symbol(personagemDialogo);
            if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
                yyerror("Variável 'tu mesmo' inválida ou não declarada");
                (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
            } else {
                (yyval.llmValueRef) = LLVMBuildLoad2(builder, LLVMInt32Type(), sym->llvm_ref, "load_tu");
            }
        }
    }
#line 1715 "src/parser.tab.c"
    break;

  case 49: /* valor: EU  */
#line 384 "src/parser.y"
       {
        if (personagemQueFala == NULL) {
            yyerror("Variável 'eu' não definida");
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            if (DEBUG_BISON) {
                // printf("Valor de 'eu': %d\n", get_int_value(personagemQueFala));
            }
            Symbol *sym = get_symbol(personagemQueFala);
            if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
                yyerror("Variável 'eu' inválida ou não declarada");
                (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
            } else {
                (yyval.llmValueRef) = LLVMBuildLoad2(builder, LLVMInt32Type(), sym->llvm_ref, "load_eu");
            }
        }
    }
#line 1737 "src/parser.tab.c"
    break;

  case 50: /* valor: texto  */
#line 401 "src/parser.y"
          {
        if (DEBUG_BISON) {
            printf("Valor de variável: %s\n", (yyvsp[0].texto));
        }
        Symbol *sym = get_symbol((yyvsp[0].texto));
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            printf("Variável inválida ou não declarada: %s\n", (yyvsp[0].texto));
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            (yyval.llmValueRef) = LLVMBuildLoad2(builder, LLVMInt32Type(), sym->llvm_ref, "load_var");
        }
    }
#line 1754 "src/parser.tab.c"
    break;

  case 51: /* expressao: valor  */
#line 416 "src/parser.y"
          {
        (yyval.llmValueRef) = (yyvsp[0].llmValueRef); // valor já retorna LLVMValueRef
    }
#line 1762 "src/parser.tab.c"
    break;

  case 52: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 419 "src/parser.y"
                                     {
        if (DEBUG_BISON) printf("Expressão de soma\n");
        (yyval.llmValueRef) = LLVMBuildAdd(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "addtmp");
    }
#line 1771 "src/parser.tab.c"
    break;

  case 53: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 423 "src/parser.y"
                                        {
        if (DEBUG_BISON) printf("Expressão de subtração\n");
        (yyval.llmValueRef) = LLVMBuildSub(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "subtmp");
    }
#line 1780 "src/parser.tab.c"
    break;

  case 54: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 427 "src/parser.y"
                                           {
        if (DEBUG_BISON) printf("Expressão de multiplicação\n");
        (yyval.llmValueRef) = LLVMBuildMul(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "multmp");
    }
#line 1789 "src/parser.tab.c"
    break;

  case 55: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 431 "src/parser.y"
                                       {
        if (DEBUG_BISON) printf("Expressão de divisão\n");

        // Divisão por zero em tempo de compilação não pode ser detectada aqui
        (yyval.llmValueRef) = LLVMBuildSDiv(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "divtmp");
    }
#line 1800 "src/parser.tab.c"
    break;

  case 56: /* if_sentenca: SE condicao VIRGULA texto expressao  */
#line 440 "src/parser.y"
                                       {
        if (DEBUG_BISON) {
            printf("IF BLOCO DETECTADO\n");
            printf("Condicao do IF: %d\n", (yyvsp[-3].llmValueRef));
            printf("resultado do IF: %d\n", (yyvsp[0].llmValueRef));
        }
    }
#line 1812 "src/parser.tab.c"
    break;

  case 57: /* if_bloco: SE condicao VIRGULA texto INICIO bloco ENDIF  */
#line 449 "src/parser.y"
                                                {
        if (DEBUG_BISON) { 
            printf("IF BLOCO DETECTADO\n");
        }
    }
#line 1822 "src/parser.tab.c"
    break;

  case 58: /* while_aux: %empty  */
#line 456 "src/parser.y"
      {
        LLVMBasicBlockRef cond_bb = LLVMAppendBasicBlock(funcao_main, "while_cond");
        LLVMBasicBlockRef body_bb = LLVMAppendBasicBlock(funcao_main, "while_body");
        LLVMBasicBlockRef after_bb = LLVMAppendBasicBlock(funcao_main, "while_end");

        LLVMBuildBr(builder, cond_bb);
        LLVMPositionBuilderAtEnd(builder, cond_bb);

        (yyval.WhileBlocks).cond_bb = cond_bb;
        (yyval.WhileBlocks).body_bb = body_bb;
        (yyval.WhileBlocks).after_bb = after_bb;
    }
#line 1839 "src/parser.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 474 "src/parser.y"
    {
        if (DEBUG_BISON) printf("WHILE DETECTADO\n");

        LLVMBuildCondBr(builder, (yyvsp[-3].llmValueRef), (yyvsp[-4].WhileBlocks).body_bb, (yyvsp[-4].WhileBlocks).after_bb);

        LLVMPositionBuilderAtEnd(builder, (yyvsp[-4].WhileBlocks).body_bb);
    }
#line 1851 "src/parser.tab.c"
    break;

  case 60: /* while: ENQUANTO_COMECO while_aux condicao VIRGULA texto INICIO $@1 bloco texto ENQUANTO_FIM FIM  */
#line 482 "src/parser.y"
    {
        LLVMBuildBr(builder, (yyvsp[-9].WhileBlocks).cond_bb);
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-9].WhileBlocks).after_bb);
    }
#line 1860 "src/parser.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 487 "src/parser.y"
    {
        if (DEBUG_BISON) printf("DO-WHILE DETECTADO\n");

        LLVMBasicBlockRef body_bb = LLVMAppendBasicBlock(funcao_main, "do_body");
        LLVMBasicBlockRef cond_bb = LLVMAppendBasicBlock(funcao_main, "do_cond");
        LLVMBasicBlockRef after_bb = LLVMAppendBasicBlock(funcao_main, "do_end");

        push_while_blocks(cond_bb, body_bb, after_bb);

        LLVMBuildBr(builder, body_bb);
        LLVMPositionBuilderAtEnd(builder, body_bb);
    }
#line 1877 "src/parser.tab.c"
    break;

  case 62: /* while: FACA VIRGULA texto INICIO $@2 bloco ENQUANTO_COMECO condicao VIRGULA texto FIM  */
#line 500 "src/parser.y"
    {
        WhileBlocks blocks = pop_while_blocks();

        LLVMBuildBr(builder, blocks.cond_bb);
        LLVMPositionBuilderAtEnd(builder, blocks.cond_bb);

        LLVMValueRef cond = (yyvsp[-4].texto);
        LLVMBuildCondBr(builder, cond, blocks.body_bb, blocks.after_bb);

        LLVMPositionBuilderAtEnd(builder, blocks.after_bb);
    }
#line 1893 "src/parser.tab.c"
    break;

  case 63: /* condicao: expressao FOR MAIOR expressao  */
#line 515 "src/parser.y"
                                      {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpgt");
        }
#line 1901 "src/parser.tab.c"
    break;

  case 64: /* condicao: expressao FOR MENOR expressao  */
#line 518 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmplt");
        }
#line 1909 "src/parser.tab.c"
    break;

  case 65: /* condicao: expressao FOR IGUAL expressao  */
#line 521 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpeq");
        }
#line 1917 "src/parser.tab.c"
    break;

  case 66: /* condicao: expressao NAO FOR MENOR expressao  */
#line 524 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpnlt");
        }
#line 1925 "src/parser.tab.c"
    break;

  case 67: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 527 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpngt");
        }
#line 1933 "src/parser.tab.c"
    break;

  case 68: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 530 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpneq");
        }
#line 1941 "src/parser.tab.c"
    break;

  case 69: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 536 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
    }
#line 1952 "src/parser.tab.c"
    break;

  case 70: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 542 "src/parser.y"
                                    {
        if (DEBUG_BISON) {
            printf("if sentença\n");
        }
    }
#line 1962 "src/parser.tab.c"
    break;

  case 71: /* dialogo: inicioDialogo texto FIM  */
#line 547 "src/parser.y"
                              {
        if (DEBUG_BISON) {
            printf("Diálogo: %s\n", (yyvsp[-1].texto));
            switch (estado) {
                case E_TITULO:    printf("Título\n"); break;
                case E_DECLARACOES: printf("Declarações\n"); break;
                case E_DIALOGO:   printf("Diálogo\n"); break;
                case E_CENA:      printf("Cena\n"); break;
                case E_ATO:       printf("Ato\n"); break;
                default:
                    yyerror("Estado desconhecido no diálogo\n");
            }
        }
    }
#line 1981 "src/parser.tab.c"
    break;

  case 72: /* dialogo: inicioDialogo texto VIRGULA TU EH expressao FIM  */
#line 561 "src/parser.y"
                                                      {
        personagemDialogo = strdup((yyvsp[-5].texto));

        if (DEBUG_BISON) {
            // printf("Valor do personagem antes do diálogo: %d\n", get_int_value(personagemDialogo));
        }

        Symbol *sym = get_symbol(personagemDialogo);
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            yyerror("Variável inteira inválida ou não declarada");
            YYABORT;
        }  else if (!sym->active) {
            printf("Variável %s não está ativa\n", personagemDialogo);
            YYABORT;
        } else {
            LLVMValueRef valorAtual = LLVMBuildLoad2(builder, LLVMInt32Type(), sym->llvm_ref, "tmp_load");
            LLVMValueRef incremento = (yyvsp[-1].llmValueRef);
            LLVMValueRef soma = LLVMBuildAdd(builder, valorAtual, incremento, "tmp_sum");
            LLVMBuildStore(builder, soma, sym->llvm_ref);
        }

        // Atualiza na tabela de valores também (se precisar)
        // int novoValor = get_int_value(personagemDialogo) + $6;
        // set_int_value(personagemDialogo, novoValor);

        if (DEBUG_BISON) {
            // printf("Valor do personagem após diálogo: %d\n", get_int_value(personagemDialogo));
        }

        free(personagemDialogo);
        personagemDialogo = NULL;
    }
#line 2018 "src/parser.tab.c"
    break;

  case 73: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 593 "src/parser.y"
                                                      {
        personagemDialogo = strdup((yyvsp[-5].texto));

        if (DEBUG_BISON) {
            // printf("Valor do personagem antes do diálogo: %d\n", get_int_value(personagemDialogo));
        }

        // LLVM: gerar incremento personagem = personagem + $6
        Symbol *sym = get_symbol(personagemDialogo);
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            yyerror("Variável inteira inválida ou não declarada");
            YYABORT;
        }  else if (!sym->active) {
            printf("Variável %s não está ativa\n", personagemDialogo);
            YYABORT;
        } else {
            LLVMValueRef valorAtual = LLVMBuildLoad2(builder, LLVMInt32Type(), sym->llvm_ref, "tmp_load");
            LLVMValueRef incremento = LLVMConstInt(LLVMInt32Type(), (yyvsp[-1].inteiro), 0);
            LLVMValueRef soma = LLVMBuildAdd(builder, valorAtual, incremento, "tmp_sum");
            LLVMBuildStore(builder, soma, sym->llvm_ref);
        }

        // Atualiza na tabela de valores também
        // int novoValor = get_int_value(personagemDialogo) + $6;
        // set_int_value(personagemDialogo, novoValor);

        if (DEBUG_BISON) {
            // printf("Valor do personagem após diálogo: %d\n", get_int_value(personagemDialogo));
        }

        free(personagemDialogo);
        personagemDialogo = NULL;
    }
#line 2056 "src/parser.tab.c"
    break;

  case 74: /* dialogo: inicioDialogo texto VIRGULA MOSTRA_VALOR FIM  */
#line 627 "src/parser.y"
                                                   {
        if (DEBUG_BISON) {
            // int val = get_int_value($2);
            // if (val == -1) {
            //     yyerror("Variável não definida");
            // } else {
            //     printf("Valor de %s: %d\n", $2, val);
            // }
        }
        Symbol *sym = get_symbol((yyvsp[-3].texto));
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            yyerror("Variável inteira inválida ou não declarada");
            YYABORT;
        }  else if (!sym->active) {
            printf("Variável %s não está ativa\n", sym->name);
            YYABORT;
        }
        gerar_print_int((yyvsp[-3].texto));

    }
#line 2081 "src/parser.tab.c"
    break;

  case 75: /* dialogo: inicioDialogo texto VIRGULA LE_VALOR FIM  */
#line 647 "src/parser.y"
                                               {
        // Scanf
        if (DEBUG_BISON) {
            printf("Lendo valor de %s\n", (yyvsp[-3].texto));
        }
        Symbol *sym = get_symbol((yyvsp[-3].texto));
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            yyerror("Variável inteira inválida ou não declarada");
            YYABORT;
        }  else if (!sym->active) {
            printf("Variável %s não está ativa\n", sym->name);
            YYABORT;
        }
        gerar_leitura_inteiro((yyvsp[-3].texto));
    }
#line 2101 "src/parser.tab.c"
    break;

  case 76: /* inicioDialogo: texto INICIO  */
#line 666 "src/parser.y"
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
                printf("Início do diálogo\n");
            }   
            Symbol *sym = get_symbol((yyvsp[-1].texto));
            if (!sym) {
                yyerror("Personagem não declarado");
                YYABORT;
            } else if (!sym->active) {
                yyerror("Personagem não está ativo");
                YYABORT;
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
#line 2137 "src/parser.tab.c"
    break;

  case 77: /* ato: ATO  */
#line 699 "src/parser.y"
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
#line 2154 "src/parser.tab.c"
    break;

  case 78: /* cena: CENA  */
#line 713 "src/parser.y"
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
#line 2171 "src/parser.tab.c"
    break;


#line 2175 "src/parser.tab.c"

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

#line 727 "src/parser.y"


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
