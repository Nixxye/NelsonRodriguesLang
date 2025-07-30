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
    // TODO: FAZER OS YYABORTS ENCERRAREM O PROGRAMA E NÃO APENAS O PARSER


#line 99 "src/parser.tab.c"

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
  YYSYMBOL_VOLTAR_CENARIO = 28,            /* VOLTAR_CENARIO  */
  YYSYMBOL_ABRE_PARENTESES = 29,           /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 30,          /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 31,                   /* VIRGULA  */
  YYSYMBOL_TOKEN = 32,                     /* TOKEN  */
  YYSYMBOL_ADJETIVO_POSITIVO = 33,         /* ADJETIVO_POSITIVO  */
  YYSYMBOL_ADJETIVO_NEGATIVO = 34,         /* ADJETIVO_NEGATIVO  */
  YYSYMBOL_TU = 35,                        /* TU  */
  YYSYMBOL_EH = 36,                        /* EH  */
  YYSYMBOL_E = 37,                         /* E  */
  YYSYMBOL_ENTRE = 38,                     /* ENTRE  */
  YYSYMBOL_ARTIGO = 39,                    /* ARTIGO  */
  YYSYMBOL_MESMO = 40,                     /* MESMO  */
  YYSYMBOL_NUMERO = 41,                    /* NUMERO  */
  YYSYMBOL_ADICIONAR_CENARIO = 42,         /* ADICIONAR_CENARIO  */
  YYSYMBOL_SUBSTITUIR_CENARIO = 43,        /* SUBSTITUIR_CENARIO  */
  YYSYMBOL_POR = 44,                       /* POR  */
  YYSYMBOL_NO_CENARIO = 45,                /* NO_CENARIO  */
  YYSYMBOL_MOSTRAR_CENARIO = 46,           /* MOSTRAR_CENARIO  */
  YYSYMBOL_MOSTRA_VALOR = 47,              /* MOSTRA_VALOR  */
  YYSYMBOL_LE_VALOR = 48,                  /* LE_VALOR  */
  YYSYMBOL_ATO = 49,                       /* ATO  */
  YYSYMBOL_CENA = 50,                      /* CENA  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_programa = 52,                  /* programa  */
  YYSYMBOL_bloco = 53,                     /* bloco  */
  YYSYMBOL_instrucao = 54,                 /* instrucao  */
  YYSYMBOL_declaracaoCenario = 55,         /* declaracaoCenario  */
  YYSYMBOL_concatenarCenario = 56,         /* concatenarCenario  */
  YYSYMBOL_substituiCenario = 57,          /* substituiCenario  */
  YYSYMBOL_trocarCenario = 58,             /* trocarCenario  */
  YYSYMBOL_declaracaoQuestionamento = 59,  /* declaracaoQuestionamento  */
  YYSYMBOL_texto = 60,                     /* texto  */
  YYSYMBOL_palavra = 61,                   /* palavra  */
  YYSYMBOL_adjetivos = 62,                 /* adjetivos  */
  YYSYMBOL_declaracao = 63,                /* declaracao  */
  YYSYMBOL_declaracaoInicio = 64,          /* declaracaoInicio  */
  YYSYMBOL_personagensEntrando = 65,       /* personagensEntrando  */
  YYSYMBOL_personagensSaindo = 66,         /* personagensSaindo  */
  YYSYMBOL_alteracaoElenco = 67,           /* alteracaoElenco  */
  YYSYMBOL_valor = 68,                     /* valor  */
  YYSYMBOL_expressao = 69,                 /* expressao  */
  YYSYMBOL_if_sentenca = 70,               /* if_sentenca  */
  YYSYMBOL_if_bloco = 71,                  /* if_bloco  */
  YYSYMBOL_while_aux = 72,                 /* while_aux  */
  YYSYMBOL_while = 73,                     /* while  */
  YYSYMBOL_74_1 = 74,                      /* $@1  */
  YYSYMBOL_75_2 = 75,                      /* $@2  */
  YYSYMBOL_condicao = 76,                  /* condicao  */
  YYSYMBOL_dialogo = 77,                   /* dialogo  */
  YYSYMBOL_inicioDialogo = 78,             /* inicioDialogo  */
  YYSYMBOL_ato = 79,                       /* ato  */
  YYSYMBOL_cena = 80                       /* cena  */
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
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    65,    69,    70,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      94,   109,   129,   148,   167,   180,   193,   209,   212,   218,
     228,   232,   235,   238,   241,   247,   253,   256,   261,   268,
     279,   290,   301,   313,   324,   335,   348,   361,   374,   383,
     389,   406,   423,   438,   441,   445,   449,   453,   462,   471,
     478,   496,   495,   509,   508,   537,   540,   543,   546,   549,
     552,   558,   564,   569,   583,   615,   649,   669,   688,   721,
     735
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
  "INTERROGACAO", "ABRE_COLCHETES", "FECHA_COLCHETES", "VOLTAR_CENARIO",
  "ABRE_PARENTESES", "FECHA_PARENTESES", "VIRGULA", "TOKEN",
  "ADJETIVO_POSITIVO", "ADJETIVO_NEGATIVO", "TU", "EH", "E", "ENTRE",
  "ARTIGO", "MESMO", "NUMERO", "ADICIONAR_CENARIO", "SUBSTITUIR_CENARIO",
  "POR", "NO_CENARIO", "MOSTRAR_CENARIO", "MOSTRA_VALOR", "LE_VALOR",
  "ATO", "CENA", "$accept", "programa", "bloco", "instrucao",
  "declaracaoCenario", "concatenarCenario", "substituiCenario",
  "trocarCenario", "declaracaoQuestionamento", "texto", "palavra",
  "adjetivos", "declaracao", "declaracaoInicio", "personagensEntrando",
  "personagensSaindo", "alteracaoElenco", "valor", "expressao",
  "if_sentenca", "if_bloco", "while_aux", "while", "$@1", "$@2",
  "condicao", "dialogo", "inicioDialogo", "ato", "cena", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-34)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -110,   120,  -110,    22,  -110,    83,    97,   -19,  -110,    43,
     -19,  -110,  -110,     2,  -110,  -110,  -110,  -110,  -110,  -110,
     227,  -110,  -110,   -19,   105,  -110,  -110,  -110,  -110,  -110,
     -11,  -110,  -110,   -19,    83,  -110,    40,   252,  -110,   -22,
    -110,    99,    41,   -19,   -19,    77,   160,   -19,   -14,  -110,
    -110,     1,  -110,  -110,  -110,    -8,   -19,   -19,    83,    98,
    -110,    53,   117,   -18,   112,  -110,   107,   109,   118,   135,
     168,   191,   -19,   -22,   124,   -22,   147,   162,   -19,   136,
     -19,   173,   179,  -110,   -22,   -22,   185,   -19,  -110,    84,
    -110,  -110,   -19,    65,    65,    65,    65,   236,    83,    83,
      83,   195,  -110,   -19,   -19,  -110,  -110,    17,  -110,   103,
    -110,  -110,   -19,   144,   178,   200,   201,     2,    32,   181,
     198,   203,   204,    83,    83,    83,  -110,  -110,  -110,     2,
     207,    35,  -110,   -22,   -22,  -110,   214,   215,  -110,    28,
    -110,  -110,   183,  -110,    65,    65,    65,    65,  -110,  -110,
    -110,   161,  -110,   231,  -110,  -110,   228,   230,    83,     2,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,   224,     2,   -19,    76,   190,   234,  -110,  -110
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    60,     0,     0,     0,    30,     0,
       0,    79,    80,     3,     4,    10,    12,    13,    14,    11,
      40,    27,     9,     0,    19,    15,    16,    17,    18,     8,
       0,     6,     7,     0,     0,    51,     0,     0,    49,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     5,
      78,    26,    39,    28,    29,     0,     0,     0,     0,     0,
      71,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,    43,     0,    40,     0,     0,     0,     0,
       0,     0,     0,    38,    41,    42,     0,     0,    73,     0,
      72,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,    46,    48,     0,    21,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,     0,
      49,    27,    58,    44,    45,    20,     0,     0,    23,     0,
      76,    77,     0,    61,     0,     0,     0,     0,    69,    68,
      70,     0,    22,    30,    31,    32,     0,     0,     0,     0,
      54,    55,    57,    56,    59,    75,    36,    34,    35,    37,
      74,     0,     0,     0,    40,     0,     0,    64,    62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -109,   -12,  -110,  -110,  -110,  -110,  -110,    -1,
      20,  -110,  -110,  -110,   194,  -110,  -110,   -57,    82,   233,
    -110,  -110,  -110,  -110,  -110,   -32,  -110,  -110,  -110,  -110
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    13,    14,    15,    16,    17,    18,    19,    39,
      21,   156,    22,    23,    24,    74,    25,    40,    41,    26,
      27,    34,    28,   159,   117,    42,    29,    30,    31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    49,    64,    58,    91,     3,    46,     4,   142,    48,
       8,    81,    20,     8,     8,    83,     5,    59,     8,    53,
     151,     8,    55,    53,     8,    82,    86,    53,     6,    61,
      80,     7,    63,    53,     8,    60,   119,   120,   121,   122,
      54,    35,    73,    75,     9,    10,    79,   135,   -29,     8,
     172,    11,    12,    33,   143,    84,    85,   -29,    53,    54,
     153,   154,   155,    36,     8,    47,    54,    37,    54,    38,
     -29,   101,    72,    53,   -29,    54,    88,   107,    35,   109,
      65,    54,   176,    54,    89,     8,   113,   160,   161,   162,
     163,   118,    77,    54,    53,    54,    35,     8,    50,    54,
      36,    51,   133,   134,    54,    54,    38,    52,     8,    70,
      71,   137,    43,    44,    45,     8,    20,    53,    36,   114,
       2,   131,    37,     3,    38,     4,   171,    54,    20,    54,
      49,   115,   116,    54,     5,     8,    56,    87,    54,    49,
      90,    20,    57,    92,    53,    93,     6,    94,   136,     7,
      20,   102,     8,    54,    54,   103,    95,   131,    20,   108,
      49,   104,     9,    10,     3,   164,     4,   138,     8,    11,
      12,   174,   175,    96,   105,     5,     8,    53,    56,    97,
     126,   127,   128,   132,    57,    53,     3,     6,   158,   106,
       7,    78,     8,     8,    54,    54,   110,     5,    98,    99,
     100,    53,   111,     9,    10,   148,   149,   150,    35,     6,
      11,    12,     7,   177,   139,     8,   112,   129,   144,   132,
     -28,   157,     8,   140,   141,     9,    10,     8,    35,   -28,
      36,    53,    11,    12,    37,   145,   130,   152,    76,   -28,
     146,   147,   -28,   123,   124,   125,   -28,     8,   -28,    50,
      36,   165,    51,   170,    37,   173,   130,   178,    52,     8,
     166,   167,   168,    62,   -33,   -33,   169,     0,    53,   -33,
      66,    67,    68,    69
};

static const yytype_int16 yycheck[] =
{
       1,    13,    34,    14,    22,     3,     7,     5,   117,    10,
      32,    10,    13,    32,    32,    23,    14,    28,    32,    41,
     129,    32,    23,    41,    32,    24,    58,    41,    26,    30,
      44,    29,    33,    41,    32,    46,    93,    94,    95,    96,
      20,    13,    43,    44,    42,    43,    47,    30,    13,    32,
     159,    49,    50,    31,    22,    56,    57,    22,    41,    39,
      32,    33,    34,    35,    32,    22,    46,    39,    48,    41,
      35,    72,    31,    41,    39,    55,    23,    78,    13,    80,
      40,    61,     6,    63,    31,    32,    87,   144,   145,   146,
     147,    92,    15,    73,    41,    75,    13,    32,    22,    79,
      35,    25,   103,   104,    84,    85,    41,    31,    32,    10,
      11,   112,    15,    16,    17,    32,   117,    41,    35,    35,
       0,   101,    39,     3,    41,     5,   158,   107,   129,   109,
     142,    47,    48,   113,    14,    32,    31,    39,   118,   151,
      23,   142,    37,    31,    41,    38,    26,    38,    45,    29,
     151,    27,    32,   133,   134,    31,    38,   137,   159,    23,
     172,    37,    42,    43,     3,     4,     5,    23,    32,    49,
      50,   172,   173,    38,    27,    14,    32,    41,    31,    11,
      98,    99,   100,   101,    37,    41,     3,    26,     5,    27,
      29,    31,    32,    32,   174,   175,    23,    14,     7,     8,
       9,    41,    23,    42,    43,   123,   124,   125,    13,    26,
      49,    50,    29,    23,    36,    32,    31,    22,    37,   137,
      13,   139,    32,    23,    23,    42,    43,    32,    13,    22,
      35,    41,    49,    50,    39,    37,    41,    23,    44,    32,
      37,    37,    35,     7,     8,     9,    39,    32,    41,    22,
      35,    23,    25,    23,    39,    31,    41,    23,    31,    32,
      32,    33,    34,    30,    33,    34,    38,    -1,    41,    38,
      18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    52,     0,     3,     5,    14,    26,    29,    32,    42,
      43,    49,    50,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    63,    64,    65,    67,    70,    71,    73,    77,
      78,    79,    80,    31,    72,    13,    35,    39,    41,    60,
      68,    69,    76,    15,    16,    17,    60,    22,    60,    54,
      22,    25,    31,    41,    61,    60,    31,    37,    14,    28,
      46,    60,    70,    60,    76,    40,    18,    19,    20,    21,
      10,    11,    31,    60,    66,    60,    65,    15,    31,    60,
      44,    10,    24,    23,    60,    60,    76,    39,    23,    31,
      23,    22,    31,    38,    38,    38,    38,    11,     7,     8,
       9,    60,    27,    31,    37,    27,    27,    60,    23,    60,
      23,    23,    31,    60,    35,    47,    48,    75,    60,    68,
      68,    68,    68,     7,     8,     9,    69,    69,    69,    22,
      41,    61,    69,    60,    60,    30,    45,    60,    23,    36,
      23,    23,    53,    22,    37,    37,    37,    37,    69,    69,
      69,    53,    23,    32,    33,    34,    62,    69,     5,    74,
      68,    68,    68,    68,     4,    23,    32,    33,    34,    38,
      23,    76,    53,    31,    60,    60,     6,    23,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      55,    56,    57,    58,    59,    59,    59,    60,    60,    60,
      61,    62,    62,    62,    62,    62,    62,    62,    63,    64,
      65,    65,    65,    66,    66,    66,    67,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    69,    69,    70,    71,
      72,    74,    73,    75,    73,    76,    76,    76,    76,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    78,    79,
      80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     6,     5,     4,     4,     2,     1,     2,     2,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     2,
       1,     3,     3,     1,     3,     3,     4,     4,     4,     1,
       2,     1,     1,     1,     6,     6,     6,     6,     5,     7,
       0,     0,    11,     0,    11,     4,     4,     4,     5,     5,
       5,     2,     3,     3,     7,     7,     5,     5,     2,     1,
       1
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
#line 69 "src/parser.y"
                                {  }
#line 1304 "src/parser.tab.c"
    break;

  case 5: /* bloco: bloco instrucao  */
#line 70 "src/parser.y"
                               {  }
#line 1310 "src/parser.tab.c"
    break;

  case 20: /* declaracaoCenario: ABRE_PARENTESES texto VIRGULA texto FECHA_PARENTESES  */
#line 94 "src/parser.y"
                                                         {
        if (estado == E_DECLARACOES) {
            add_symbol((yyvsp[-3].texto), STRING_VAR);
            set_string_value((yyvsp[-3].texto), (yyvsp[-1].texto));
            if (DEBUG_BISON) {
                printf("Cenário adicionado: %s = %s\n", (yyvsp[-3].texto), (yyvsp[-1].texto));
            }
            cenarioAtual = strdup((yyvsp[-3].texto));
            ativar_cenario(cenarioAtual);
        } else {
            yyerror("Declaração de cenário fora de contexto");
        }
    }
#line 1328 "src/parser.tab.c"
    break;

  case 21: /* concatenarCenario: ADICIONAR_CENARIO INICIO texto FIM  */
#line 109 "src/parser.y"
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
#line 1351 "src/parser.tab.c"
    break;

  case 22: /* substituiCenario: SUBSTITUIR_CENARIO texto POR texto NO_CENARIO FIM  */
#line 129 "src/parser.y"
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
#line 1372 "src/parser.tab.c"
    break;

  case 23: /* trocarCenario: inicioDialogo VOLTAR_CENARIO ARTIGO texto FIM  */
#line 148 "src/parser.y"
                                                  {
        if (estado == E_DECLARACOES) {
            yyerror("Troca de cenário fora de contexto");
            YYABORT;
        } else {
            if (DEBUG_BISON) {
                printf("Trocando cenário para: %s\n", (yyvsp[-1].texto));
            }
            char *novoCenario = get_string_value((yyvsp[-1].texto));
            if (novoCenario == NULL) {
                yyerror("Cenário não declarado");
                YYABORT;
            } else {
                cenarioAtual = strdup((yyvsp[-1].texto));
                ativar_cenario(cenarioAtual);
            }
        }
    }
#line 1395 "src/parser.tab.c"
    break;

  case 24: /* declaracaoQuestionamento: texto INTERROGACAO NAO FIM  */
#line 167 "src/parser.y"
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
#line 1413 "src/parser.tab.c"
    break;

  case 25: /* declaracaoQuestionamento: texto INTERROGACAO SIM FIM  */
#line 180 "src/parser.y"
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
#line 1431 "src/parser.tab.c"
    break;

  case 26: /* declaracaoQuestionamento: texto INTERROGACAO  */
#line 193 "src/parser.y"
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
#line 1449 "src/parser.tab.c"
    break;

  case 27: /* texto: palavra  */
#line 209 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1457 "src/parser.tab.c"
    break;

  case 28: /* texto: texto NUMERO  */
#line 212 "src/parser.y"
                   {
        //  if (DEBUG_BISON) {
        //      printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1468 "src/parser.tab.c"
    break;

  case 29: /* texto: texto palavra  */
#line 218 "src/parser.y"
                    {
        // if (DEBUG_BISON) {
        //     printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1479 "src/parser.tab.c"
    break;

  case 30: /* palavra: TOKEN  */
#line 228 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1485 "src/parser.tab.c"
    break;

  case 31: /* adjetivos: ADJETIVO_POSITIVO  */
#line 232 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1493 "src/parser.tab.c"
    break;

  case 32: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 235 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
#line 1501 "src/parser.tab.c"
    break;

  case 33: /* adjetivos: TOKEN  */
#line 238 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
#line 1509 "src/parser.tab.c"
    break;

  case 34: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 241 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) + 1;
    }
#line 1520 "src/parser.tab.c"
    break;

  case 35: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 247 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) - 1;
    }
#line 1531 "src/parser.tab.c"
    break;

  case 36: /* adjetivos: adjetivos TOKEN  */
#line 253 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1539 "src/parser.tab.c"
    break;

  case 37: /* adjetivos: adjetivos ENTRE  */
#line 256 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1547 "src/parser.tab.c"
    break;

  case 38: /* declaracao: declaracaoInicio texto FIM  */
#line 261 "src/parser.y"
                               {
        if (DEBUG_BISON) {
            printf("Declaração: %s\n", (yyvsp[-1].texto));
        }
    }
#line 1557 "src/parser.tab.c"
    break;

  case 39: /* declaracaoInicio: texto VIRGULA  */
#line 268 "src/parser.y"
                  {
        if (estado == E_DECLARACOES) {
            if (DEBUG_BISON) {
                printf("Criando variável: %s\n", (yyvsp[-1].texto));
            }
            add_symbol((yyvsp[-1].texto), INT_VAR);
        }
        (yyval.texto) = (yyvsp[-1].texto);
    }
#line 1571 "src/parser.tab.c"
    break;

  case 40: /* personagensEntrando: texto  */
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
#line 1587 "src/parser.tab.c"
    break;

  case 41: /* personagensEntrando: personagensEntrando VIRGULA texto  */
#line 290 "src/parser.y"
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
#line 1603 "src/parser.tab.c"
    break;

  case 42: /* personagensEntrando: personagensEntrando E texto  */
#line 301 "src/parser.y"
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
#line 1619 "src/parser.tab.c"
    break;

  case 43: /* personagensSaindo: texto  */
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
#line 1635 "src/parser.tab.c"
    break;

  case 44: /* personagensSaindo: personagensSaindo VIRGULA texto  */
#line 324 "src/parser.y"
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
#line 1651 "src/parser.tab.c"
    break;

  case 45: /* personagensSaindo: personagensSaindo E texto  */
#line 335 "src/parser.y"
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
#line 1667 "src/parser.tab.c"
    break;

  case 46: /* alteracaoElenco: ABRE_COLCHETES ENTRAM personagensEntrando FECHA_COLCHETES  */
#line 348 "src/parser.y"
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
#line 1685 "src/parser.tab.c"
    break;

  case 47: /* alteracaoElenco: ABRE_COLCHETES SAEM personagensSaindo FECHA_COLCHETES  */
#line 361 "src/parser.y"
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
#line 1703 "src/parser.tab.c"
    break;

  case 48: /* alteracaoElenco: ABRE_COLCHETES TODOS SAEM FECHA_COLCHETES  */
#line 374 "src/parser.y"
                                                {
        if (DEBUG_BISON) {
            printf("Todos os personagens estão inativos\n");
        }
        // Ativa todos os personagens
        desativar_todos_personagens();
    }
#line 1715 "src/parser.tab.c"
    break;

  case 49: /* valor: NUMERO  */
#line 383 "src/parser.y"
           {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi((yyvsp[0].texto)));
        }
        (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), atoi((yyvsp[0].texto)), 0);
    }
#line 1726 "src/parser.tab.c"
    break;

  case 50: /* valor: TU MESMO  */
#line 389 "src/parser.y"
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
#line 1748 "src/parser.tab.c"
    break;

  case 51: /* valor: EU  */
#line 406 "src/parser.y"
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
#line 1770 "src/parser.tab.c"
    break;

  case 52: /* valor: texto  */
#line 423 "src/parser.y"
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
#line 1787 "src/parser.tab.c"
    break;

  case 53: /* expressao: valor  */
#line 438 "src/parser.y"
          {
        (yyval.llmValueRef) = (yyvsp[0].llmValueRef); // valor já retorna LLVMValueRef
    }
#line 1795 "src/parser.tab.c"
    break;

  case 54: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 441 "src/parser.y"
                                     {
        if (DEBUG_BISON) printf("Expressão de soma\n");
        (yyval.llmValueRef) = LLVMBuildAdd(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "addtmp");
    }
#line 1804 "src/parser.tab.c"
    break;

  case 55: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 445 "src/parser.y"
                                        {
        if (DEBUG_BISON) printf("Expressão de subtração\n");
        (yyval.llmValueRef) = LLVMBuildSub(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "subtmp");
    }
#line 1813 "src/parser.tab.c"
    break;

  case 56: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 449 "src/parser.y"
                                           {
        if (DEBUG_BISON) printf("Expressão de multiplicação\n");
        (yyval.llmValueRef) = LLVMBuildMul(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "multmp");
    }
#line 1822 "src/parser.tab.c"
    break;

  case 57: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 453 "src/parser.y"
                                       {
        if (DEBUG_BISON) printf("Expressão de divisão\n");

        // Divisão por zero em tempo de compilação não pode ser detectada aqui
        (yyval.llmValueRef) = LLVMBuildSDiv(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "divtmp");
    }
#line 1833 "src/parser.tab.c"
    break;

  case 58: /* if_sentenca: SE condicao VIRGULA texto expressao  */
#line 462 "src/parser.y"
                                       {
        if (DEBUG_BISON) {
            printf("IF BLOCO DETECTADO\n");
            printf("Condicao do IF: %d\n", (yyvsp[-3].llmValueRef));
            printf("resultado do IF: %d\n", (yyvsp[0].llmValueRef));
        }
    }
#line 1845 "src/parser.tab.c"
    break;

  case 59: /* if_bloco: SE condicao VIRGULA texto INICIO bloco ENDIF  */
#line 471 "src/parser.y"
                                                {
        if (DEBUG_BISON) { 
            printf("IF BLOCO DETECTADO\n");
        }
    }
#line 1855 "src/parser.tab.c"
    break;

  case 60: /* while_aux: %empty  */
#line 478 "src/parser.y"
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
#line 1872 "src/parser.tab.c"
    break;

  case 61: /* $@1: %empty  */
#line 496 "src/parser.y"
    {
        if (DEBUG_BISON) printf("WHILE DETECTADO\n");

        LLVMBuildCondBr(builder, (yyvsp[-3].llmValueRef), (yyvsp[-4].WhileBlocks).body_bb, (yyvsp[-4].WhileBlocks).after_bb);

        LLVMPositionBuilderAtEnd(builder, (yyvsp[-4].WhileBlocks).body_bb);
    }
#line 1884 "src/parser.tab.c"
    break;

  case 62: /* while: ENQUANTO_COMECO while_aux condicao VIRGULA texto INICIO $@1 bloco texto ENQUANTO_FIM FIM  */
#line 504 "src/parser.y"
    {
        LLVMBuildBr(builder, (yyvsp[-9].WhileBlocks).cond_bb);
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-9].WhileBlocks).after_bb);
    }
#line 1893 "src/parser.tab.c"
    break;

  case 63: /* $@2: %empty  */
#line 509 "src/parser.y"
    {
        if (DEBUG_BISON) printf("DO-WHILE DETECTADO\n");

        LLVMBasicBlockRef body_bb = LLVMAppendBasicBlock(funcao_main, "do_body");
        LLVMBasicBlockRef cond_bb = LLVMAppendBasicBlock(funcao_main, "do_cond");
        LLVMBasicBlockRef after_bb = LLVMAppendBasicBlock(funcao_main, "do_end");

        push_while_blocks(cond_bb, body_bb, after_bb);

        LLVMBuildBr(builder, body_bb);
        LLVMPositionBuilderAtEnd(builder, body_bb);
    }
#line 1910 "src/parser.tab.c"
    break;

  case 64: /* while: FACA VIRGULA texto INICIO $@2 bloco ENQUANTO_COMECO condicao VIRGULA texto FIM  */
#line 522 "src/parser.y"
    {
        WhileBlocks blocks = pop_while_blocks();

        LLVMBuildBr(builder, blocks.cond_bb);
        LLVMPositionBuilderAtEnd(builder, blocks.cond_bb);

        LLVMValueRef cond = (yyvsp[-4].texto);
        LLVMBuildCondBr(builder, cond, blocks.body_bb, blocks.after_bb);

        LLVMPositionBuilderAtEnd(builder, blocks.after_bb);
    }
#line 1926 "src/parser.tab.c"
    break;

  case 65: /* condicao: expressao FOR MAIOR expressao  */
#line 537 "src/parser.y"
                                      {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpgt");
        }
#line 1934 "src/parser.tab.c"
    break;

  case 66: /* condicao: expressao FOR MENOR expressao  */
#line 540 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmplt");
        }
#line 1942 "src/parser.tab.c"
    break;

  case 67: /* condicao: expressao FOR IGUAL expressao  */
#line 543 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpeq");
        }
#line 1950 "src/parser.tab.c"
    break;

  case 68: /* condicao: expressao NAO FOR MENOR expressao  */
#line 546 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpnlt");
        }
#line 1958 "src/parser.tab.c"
    break;

  case 69: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 549 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpngt");
        }
#line 1966 "src/parser.tab.c"
    break;

  case 70: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 552 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpneq");
        }
#line 1974 "src/parser.tab.c"
    break;

  case 71: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 558 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
    }
#line 1985 "src/parser.tab.c"
    break;

  case 72: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 564 "src/parser.y"
                                    {
        if (DEBUG_BISON) {
            printf("if sentença\n");
        }
    }
#line 1995 "src/parser.tab.c"
    break;

  case 73: /* dialogo: inicioDialogo texto FIM  */
#line 569 "src/parser.y"
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
#line 2014 "src/parser.tab.c"
    break;

  case 74: /* dialogo: inicioDialogo texto VIRGULA TU EH expressao FIM  */
#line 583 "src/parser.y"
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
#line 2051 "src/parser.tab.c"
    break;

  case 75: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 615 "src/parser.y"
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
#line 2089 "src/parser.tab.c"
    break;

  case 76: /* dialogo: inicioDialogo texto VIRGULA MOSTRA_VALOR FIM  */
#line 649 "src/parser.y"
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
        gerar_print_topo_pilha((yyvsp[-3].texto));

    }
#line 2114 "src/parser.tab.c"
    break;

  case 77: /* dialogo: inicioDialogo texto VIRGULA LE_VALOR FIM  */
#line 669 "src/parser.y"
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
#line 2134 "src/parser.tab.c"
    break;

  case 78: /* inicioDialogo: texto INICIO  */
#line 688 "src/parser.y"
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
#line 2170 "src/parser.tab.c"
    break;

  case 79: /* ato: ATO  */
#line 721 "src/parser.y"
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
#line 2187 "src/parser.tab.c"
    break;

  case 80: /* cena: CENA  */
#line 735 "src/parser.y"
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
#line 2204 "src/parser.tab.c"
    break;


#line 2208 "src/parser.tab.c"

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

#line 749 "src/parser.y"


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
