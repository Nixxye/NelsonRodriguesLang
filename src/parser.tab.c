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
    char* ultimoPersonagemQueFala = NULL; // Guarda o valor do último personagem que falou
    char* personagemVoce = NULL; // guarda o valor do ultimo personagem que falou e diferente do atual
    int result = 0; // guarda o resultado do if
    // TODO: FAZER OS YYABORTS ENCERRAREM O PROGRAMA E NÃO APENAS O PARSER

    void atualiza_personagemVoce(){
        if (!personagemVoce || strcmp(ultimoPersonagemQueFala, personagemQueFala) != 0) {
            if (DEBUG_BISON) {
                printf("Atualizando personagemVoce: %s\n", ultimoPersonagemQueFala);
            }
            personagemVoce = ultimoPersonagemQueFala;
        }
        ultimoPersonagemQueFala = personagemQueFala;
    }
    // Variável global para a nossa pilha.
    PilhaControleFluxo pilhaControleFluxo;

#line 112 "src/parser.tab.c"

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
  YYSYMBOL_VOCE = 29,                      /* VOCE  */
  YYSYMBOL_ABRE_PARENTESES = 30,           /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 31,          /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 32,                   /* VIRGULA  */
  YYSYMBOL_SERA = 33,                      /* SERA  */
  YYSYMBOL_TOKEN = 34,                     /* TOKEN  */
  YYSYMBOL_ADJETIVO_POSITIVO = 35,         /* ADJETIVO_POSITIVO  */
  YYSYMBOL_ADJETIVO_NEGATIVO = 36,         /* ADJETIVO_NEGATIVO  */
  YYSYMBOL_TU = 37,                        /* TU  */
  YYSYMBOL_EH = 38,                        /* EH  */
  YYSYMBOL_E = 39,                         /* E  */
  YYSYMBOL_ENTRE = 40,                     /* ENTRE  */
  YYSYMBOL_ARTIGO = 41,                    /* ARTIGO  */
  YYSYMBOL_MESMO = 42,                     /* MESMO  */
  YYSYMBOL_NUMERO = 43,                    /* NUMERO  */
  YYSYMBOL_ADICIONAR_CENARIO = 44,         /* ADICIONAR_CENARIO  */
  YYSYMBOL_SUBSTITUIR_CENARIO = 45,        /* SUBSTITUIR_CENARIO  */
  YYSYMBOL_POR = 46,                       /* POR  */
  YYSYMBOL_NO_CENARIO = 47,                /* NO_CENARIO  */
  YYSYMBOL_MOSTRAR_CENARIO = 48,           /* MOSTRAR_CENARIO  */
  YYSYMBOL_MOSTRA_VALOR = 49,              /* MOSTRA_VALOR  */
  YYSYMBOL_LE_VALOR = 50,                  /* LE_VALOR  */
  YYSYMBOL_GUARDE = 51,                    /* GUARDE  */
  YYSYMBOL_INTERIOR = 52,                  /* INTERIOR  */
  YYSYMBOL_LEMBRE = 53,                    /* LEMBRE  */
  YYSYMBOL_IF_MOSTRA_VALOR = 54,           /* IF_MOSTRA_VALOR  */
  YYSYMBOL_IF_LE_VALOR = 55,               /* IF_LE_VALOR  */
  YYSYMBOL_ATO = 56,                       /* ATO  */
  YYSYMBOL_CENA = 57,                      /* CENA  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_programa = 59,                  /* programa  */
  YYSYMBOL_bloco = 60,                     /* bloco  */
  YYSYMBOL_instrucao = 61,                 /* instrucao  */
  YYSYMBOL_declaracaoCenario = 62,         /* declaracaoCenario  */
  YYSYMBOL_concatenarCenario = 63,         /* concatenarCenario  */
  YYSYMBOL_substituiCenario = 64,          /* substituiCenario  */
  YYSYMBOL_trocarCenario = 65,             /* trocarCenario  */
  YYSYMBOL_declaracaoQuestionamento = 66,  /* declaracaoQuestionamento  */
  YYSYMBOL_texto = 67,                     /* texto  */
  YYSYMBOL_palavra = 68,                   /* palavra  */
  YYSYMBOL_adjetivos = 69,                 /* adjetivos  */
  YYSYMBOL_declaracao = 70,                /* declaracao  */
  YYSYMBOL_declaracaoInicio = 71,          /* declaracaoInicio  */
  YYSYMBOL_personagensEntrando = 72,       /* personagensEntrando  */
  YYSYMBOL_personagensSaindo = 73,         /* personagensSaindo  */
  YYSYMBOL_alteracaoElenco = 74,           /* alteracaoElenco  */
  YYSYMBOL_personagem = 75,                /* personagem  */
  YYSYMBOL_valor = 76,                     /* valor  */
  YYSYMBOL_expressao = 77,                 /* expressao  */
  YYSYMBOL_if_sentenca = 78,               /* if_sentenca  */
  YYSYMBOL_if_bloco = 79,                  /* if_bloco  */
  YYSYMBOL_80_1 = 80,                      /* $@1  */
  YYSYMBOL_while = 81,                     /* while  */
  YYSYMBOL_82_2 = 82,                      /* $@2  */
  YYSYMBOL_83_3 = 83,                      /* $@3  */
  YYSYMBOL_condicao = 84,                  /* condicao  */
  YYSYMBOL_dialogo = 85,                   /* dialogo  */
  YYSYMBOL_inicioDialogo = 86,             /* inicioDialogo  */
  YYSYMBOL_ato = 87,                       /* ato  */
  YYSYMBOL_cena = 88                       /* cena  */
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
#define YYLAST   282

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    74,    78,    79,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     103,   118,   138,   157,   176,   189,   202,   218,   221,   227,
     237,   241,   244,   247,   250,   256,   262,   265,   270,   277,
     288,   300,   312,   325,   336,   347,   360,   373,   386,   395,
     398,   401,   406,   412,   429,   446,   463,   478,   481,   485,
     489,   493,   502,   540,   571,   598,   597,   637,   636,   645,
     644,   656,   659,   662,   665,   668,   671,   677,   684,   690,
     705,   728,   768,   788,   804,   819,   834,   867,   881
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
  "VOCE", "ABRE_PARENTESES", "FECHA_PARENTESES", "VIRGULA", "SERA",
  "TOKEN", "ADJETIVO_POSITIVO", "ADJETIVO_NEGATIVO", "TU", "EH", "E",
  "ENTRE", "ARTIGO", "MESMO", "NUMERO", "ADICIONAR_CENARIO",
  "SUBSTITUIR_CENARIO", "POR", "NO_CENARIO", "MOSTRAR_CENARIO",
  "MOSTRA_VALOR", "LE_VALOR", "GUARDE", "INTERIOR", "LEMBRE",
  "IF_MOSTRA_VALOR", "IF_LE_VALOR", "ATO", "CENA", "$accept", "programa",
  "bloco", "instrucao", "declaracaoCenario", "concatenarCenario",
  "substituiCenario", "trocarCenario", "declaracaoQuestionamento", "texto",
  "palavra", "adjetivos", "declaracao", "declaracaoInicio",
  "personagensEntrando", "personagensSaindo", "alteracaoElenco",
  "personagem", "valor", "expressao", "if_sentenca", "if_bloco", "$@1",
  "while", "$@2", "$@3", "condicao", "dialogo", "inicioDialogo", "ato",
  "cena", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-34)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -121,   126,  -121,   -22,   201,   201,   254,    15,  -121,    13,
      15,  -121,  -121,   175,  -121,  -121,  -121,  -121,  -121,  -121,
     165,  -121,  -121,    15,    -2,  -121,  -121,  -121,  -121,  -121,
      65,  -121,  -121,    15,  -121,  -121,    19,   255,  -121,    57,
    -121,     3,    30,    78,    15,    15,    79,   160,    15,   107,
    -121,  -121,     1,  -121,  -121,  -121,    69,    15,    15,   201,
      84,  -121,    85,    95,   -15,  -121,   106,   119,   121,   122,
     136,   270,    15,    -8,    57,    77,    57,   116,   124,    15,
     111,    15,   143,   144,  -121,    57,    57,   137,    15,  -121,
     206,  -121,  -121,   211,   211,   211,   211,   273,   201,   201,
     201,    62,  -121,  -121,    68,   -13,  -121,    15,    15,  -121,
    -121,   157,  -121,    20,  -121,  -121,    -8,   161,   141,   158,
     170,    15,    15,   175,   174,   176,   183,   186,   201,   201,
     201,  -121,  -121,  -121,  -121,  -121,   201,  -121,  -121,    57,
      57,  -121,   173,    57,  -121,   101,  -121,  -121,    16,   184,
     207,   211,   211,   211,   211,  -121,  -121,  -121,   175,   175,
    -121,  -121,   232,  -121,  -121,   226,   188,   200,  -121,   201,
    -121,  -121,  -121,  -121,   175,   172,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,   194,     2,  -121,    15,   213,    43,  -121,
    -121
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,    30,     0,
       0,    87,    88,     3,     4,    10,    12,    13,    14,    11,
      40,    27,     9,     0,    19,    15,    16,    17,    18,     8,
       0,     6,     7,     0,    54,    55,     0,     0,    52,    56,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,    86,    26,    39,    28,    29,     0,     0,     0,     0,
       0,    77,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,    43,     0,    40,     0,     0,     0,
       0,     0,     0,     0,    38,    41,    42,     0,     0,    79,
       0,    78,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,    50,    51,     0,    47,     0,     0,    46,
      48,     0,    21,     0,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,    72,    73,    67,    65,     0,    63,    64,    44,
      45,    20,     0,    51,    23,     0,    82,    83,     0,     0,
       0,     0,     0,     0,     0,    75,    74,    76,     0,     0,
      62,    22,    30,    31,    32,     0,     0,     0,    85,     0,
      58,    59,    61,    60,     0,     0,    81,    36,    34,    35,
      37,    80,    84,     0,    40,    66,     0,     0,     0,    68,
      70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -120,   -11,  -121,  -121,  -121,  -121,  -121,    -1,
     -16,  -121,  -121,  -121,   189,  -121,  -121,  -121,   -78,   -47,
     209,  -121,  -121,  -121,  -121,  -121,    -4,  -121,  -121,  -121,
    -121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    13,    14,    15,    16,    17,    18,    19,    39,
      21,   165,    22,    23,    24,    75,    25,   105,    40,    41,
      26,    27,   159,    28,   158,   123,    42,    29,    30,    31,
      32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    43,    50,   150,    55,   102,    47,    92,   187,    49,
      33,    82,    20,    70,    71,   124,   125,   126,   127,     8,
     136,   103,    56,    55,    51,    83,     8,    52,    54,    62,
      57,    55,    64,    55,    53,    48,     8,    58,   174,   175,
      55,   137,   138,    74,    76,    54,    55,    80,    55,     8,
       8,   131,   132,   133,     8,    87,    85,    86,    55,    54,
      55,    65,    72,    54,    55,   134,   190,   142,   167,    55,
      55,   101,   104,   170,   171,   172,   173,     8,   111,    59,
     113,   155,   156,   157,   134,    55,    54,   117,    55,   160,
     135,     8,    84,    60,    78,    55,     8,    55,   166,     8,
      54,    55,     8,     8,   106,    54,   139,   140,    89,   107,
      73,    54,    54,    61,    34,   143,   108,    90,    91,     8,
     148,   149,    20,    55,    55,    88,     2,    55,    54,     3,
      35,     4,    55,    55,   112,   162,   163,   164,    36,    50,
       5,     8,    37,   109,    38,     8,    93,    97,    57,    20,
      54,   110,     6,    81,    54,    58,     7,    20,    20,    94,
       8,    95,    96,    50,    50,   183,   114,   115,    55,   116,
       9,    10,    55,   184,    20,     3,   185,     4,     3,   145,
       4,   146,    11,    12,   144,   188,     5,    51,   141,     5,
      52,     8,    79,   147,     8,     8,   161,    53,     6,     8,
      54,     6,     7,    54,    54,     7,     8,   168,    54,     8,
       3,   181,   169,   151,    34,   152,     9,    10,     8,     9,
      10,     5,   153,   182,    34,   154,   186,    54,    11,    12,
      35,    11,    12,     6,    77,     8,   189,     7,    36,    63,
      35,     8,    37,   118,    38,     8,     0,     0,    36,   176,
       0,     9,    10,     0,    38,   119,   120,   121,     0,   122,
     177,   178,   179,    11,    12,     0,   180,   -33,   -33,    44,
      45,    46,   -33,    66,    67,    68,    69,    98,    99,   100,
     128,   129,   130
};

static const yytype_int16 yycheck[] =
{
       1,     5,    13,   123,    20,    13,     7,    22,     6,    10,
      32,    10,    13,    10,    11,    93,    94,    95,    96,    34,
      33,    29,    23,    39,    22,    24,    34,    25,    43,    30,
      32,    47,    33,    49,    32,    22,    34,    39,   158,   159,
      56,    54,    55,    44,    45,    43,    62,    48,    64,    34,
      34,    98,    99,   100,    34,    59,    57,    58,    74,    43,
      76,    42,    32,    43,    80,    22,    23,    47,    52,    85,
      86,    72,    73,   151,   152,   153,   154,    34,    79,    14,
      81,   128,   129,   130,    22,   101,    43,    88,   104,   136,
      22,    34,    23,    28,    15,   111,    34,   113,   145,    34,
      43,   117,    34,    34,    27,    43,   107,   108,    23,    32,
      32,    43,    43,    48,    13,   116,    39,    32,    23,    34,
     121,   122,   123,   139,   140,    41,     0,   143,    43,     3,
      29,     5,   148,   149,    23,    34,    35,    36,    37,   150,
      14,    34,    41,    27,    43,    34,    40,    11,    32,   150,
      43,    27,    26,    46,    43,    39,    30,   158,   159,    40,
      34,    40,    40,   174,   175,   169,    23,    23,   184,    32,
      44,    45,   188,   174,   175,     3,     4,     5,     3,    38,
       5,    23,    56,    57,    23,   186,    14,    22,    31,    14,
      25,    34,    32,    23,    34,    34,    23,    32,    26,    34,
      43,    26,    30,    43,    43,    30,    34,    23,    43,    34,
       3,    23,     5,    39,    13,    39,    44,    45,    34,    44,
      45,    14,    39,    23,    13,    39,    32,    43,    56,    57,
      29,    56,    57,    26,    45,    34,    23,    30,    37,    30,
      29,    34,    41,    37,    43,    34,    -1,    -1,    37,    23,
      -1,    44,    45,    -1,    43,    49,    50,    51,    -1,    53,
      34,    35,    36,    56,    57,    -1,    40,    35,    36,    15,
      16,    17,    40,    18,    19,    20,    21,     7,     8,     9,
       7,     8,     9
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,     0,     3,     5,    14,    26,    30,    34,    44,
      45,    56,    57,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    70,    71,    72,    74,    78,    79,    81,    85,
      86,    87,    88,    32,    13,    29,    37,    41,    43,    67,
      76,    77,    84,    84,    15,    16,    17,    67,    22,    67,
      61,    22,    25,    32,    43,    68,    67,    32,    39,    14,
      28,    48,    67,    78,    67,    42,    18,    19,    20,    21,
      10,    11,    32,    32,    67,    73,    67,    72,    15,    32,
      67,    46,    10,    24,    23,    67,    67,    84,    41,    23,
      32,    23,    22,    40,    40,    40,    40,    11,     7,     8,
       9,    67,    13,    29,    67,    75,    27,    32,    39,    27,
      27,    67,    23,    67,    23,    23,    32,    67,    37,    49,
      50,    51,    53,    83,    76,    76,    76,    76,     7,     8,
       9,    77,    77,    77,    22,    22,    33,    54,    55,    67,
      67,    31,    47,    67,    23,    38,    23,    23,    67,    67,
      60,    39,    39,    39,    39,    77,    77,    77,    82,    80,
      77,    23,    34,    35,    36,    69,    77,    52,    23,     5,
      76,    76,    76,    76,    60,    60,    23,    34,    35,    36,
      40,    23,    23,    84,    67,     4,    32,     6,    67,    23,
      23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    63,    64,    65,    66,    66,    66,    67,    67,    67,
      68,    69,    69,    69,    69,    69,    69,    69,    70,    71,
      72,    72,    72,    73,    73,    73,    74,    74,    74,    75,
      75,    75,    76,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    78,    78,    78,    80,    79,    82,    81,    83,
      81,    84,    84,    84,    84,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    86,    87,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     6,     5,     4,     4,     2,     1,     2,     2,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     2,
       1,     3,     3,     1,     3,     3,     4,     4,     4,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     6,     6,
       6,     6,     6,     5,     5,     0,     8,     0,    10,     0,
      11,     4,     4,     4,     5,     5,     5,     2,     3,     3,
       7,     7,     5,     5,     7,     6,     2,     1,     1
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
#line 78 "src/parser.y"
                                {  }
#line 1338 "src/parser.tab.c"
    break;

  case 5: /* bloco: bloco instrucao  */
#line 79 "src/parser.y"
                               {  }
#line 1344 "src/parser.tab.c"
    break;

  case 20: /* declaracaoCenario: ABRE_PARENTESES texto VIRGULA texto FECHA_PARENTESES  */
#line 103 "src/parser.y"
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
#line 1362 "src/parser.tab.c"
    break;

  case 21: /* concatenarCenario: ADICIONAR_CENARIO INICIO texto FIM  */
#line 118 "src/parser.y"
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
#line 1385 "src/parser.tab.c"
    break;

  case 22: /* substituiCenario: SUBSTITUIR_CENARIO texto POR texto NO_CENARIO FIM  */
#line 138 "src/parser.y"
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
#line 1406 "src/parser.tab.c"
    break;

  case 23: /* trocarCenario: inicioDialogo VOLTAR_CENARIO ARTIGO texto FIM  */
#line 157 "src/parser.y"
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
#line 1429 "src/parser.tab.c"
    break;

  case 24: /* declaracaoQuestionamento: texto INTERROGACAO NAO FIM  */
#line 176 "src/parser.y"
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
#line 1447 "src/parser.tab.c"
    break;

  case 25: /* declaracaoQuestionamento: texto INTERROGACAO SIM FIM  */
#line 189 "src/parser.y"
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
#line 1465 "src/parser.tab.c"
    break;

  case 26: /* declaracaoQuestionamento: texto INTERROGACAO  */
#line 202 "src/parser.y"
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
#line 1483 "src/parser.tab.c"
    break;

  case 27: /* texto: palavra  */
#line 218 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1491 "src/parser.tab.c"
    break;

  case 28: /* texto: texto NUMERO  */
#line 221 "src/parser.y"
                   {
        //  if (DEBUG_BISON) {
        //      printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1502 "src/parser.tab.c"
    break;

  case 29: /* texto: texto palavra  */
#line 227 "src/parser.y"
                    {
        // if (DEBUG_BISON) {
        //     printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1513 "src/parser.tab.c"
    break;

  case 30: /* palavra: TOKEN  */
#line 237 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1519 "src/parser.tab.c"
    break;

  case 31: /* adjetivos: ADJETIVO_POSITIVO  */
#line 241 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1527 "src/parser.tab.c"
    break;

  case 32: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 244 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
#line 1535 "src/parser.tab.c"
    break;

  case 33: /* adjetivos: TOKEN  */
#line 247 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
#line 1543 "src/parser.tab.c"
    break;

  case 34: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 250 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) + 1;
    }
#line 1554 "src/parser.tab.c"
    break;

  case 35: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 256 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) - 1;
    }
#line 1565 "src/parser.tab.c"
    break;

  case 36: /* adjetivos: adjetivos TOKEN  */
#line 262 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1573 "src/parser.tab.c"
    break;

  case 37: /* adjetivos: adjetivos ENTRE  */
#line 265 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1581 "src/parser.tab.c"
    break;

  case 38: /* declaracao: declaracaoInicio texto FIM  */
#line 270 "src/parser.y"
                               {
        if (DEBUG_BISON) {
            printf("Declaração: %s\n", (yyvsp[-1].texto));
        }
    }
#line 1591 "src/parser.tab.c"
    break;

  case 39: /* declaracaoInicio: texto VIRGULA  */
#line 277 "src/parser.y"
                  {
        if (estado == E_DECLARACOES) {
            if (DEBUG_BISON) {
                printf("Criando variável: %s\n", (yyvsp[-1].texto));
            }
            add_symbol((yyvsp[-1].texto), INT_VAR);
        }
        (yyval.texto) = (yyvsp[-1].texto);
    }
#line 1605 "src/parser.tab.c"
    break;

  case 40: /* personagensEntrando: texto  */
#line 288 "src/parser.y"
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
        personagemVoce = (yyvsp[0].texto); // Atualiza personagemVoce com o personagem que está entrando
    }
#line 1622 "src/parser.tab.c"
    break;

  case 41: /* personagensEntrando: personagensEntrando VIRGULA texto  */
#line 300 "src/parser.y"
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
        personagemVoce = (yyvsp[0].texto); // Atualiza personagemVoce com o personagem que está entrando
    }
#line 1639 "src/parser.tab.c"
    break;

  case 42: /* personagensEntrando: personagensEntrando E texto  */
#line 312 "src/parser.y"
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
        personagemVoce = (yyvsp[0].texto); // Atualiza personagemVoce com o personagem que está entrando
    }
#line 1656 "src/parser.tab.c"
    break;

  case 43: /* personagensSaindo: texto  */
#line 325 "src/parser.y"
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
#line 1672 "src/parser.tab.c"
    break;

  case 44: /* personagensSaindo: personagensSaindo VIRGULA texto  */
#line 336 "src/parser.y"
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
#line 1688 "src/parser.tab.c"
    break;

  case 45: /* personagensSaindo: personagensSaindo E texto  */
#line 347 "src/parser.y"
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
#line 1704 "src/parser.tab.c"
    break;

  case 46: /* alteracaoElenco: ABRE_COLCHETES ENTRAM personagensEntrando FECHA_COLCHETES  */
#line 360 "src/parser.y"
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
#line 1722 "src/parser.tab.c"
    break;

  case 47: /* alteracaoElenco: ABRE_COLCHETES SAEM personagensSaindo FECHA_COLCHETES  */
#line 373 "src/parser.y"
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
#line 1740 "src/parser.tab.c"
    break;

  case 48: /* alteracaoElenco: ABRE_COLCHETES TODOS SAEM FECHA_COLCHETES  */
#line 386 "src/parser.y"
                                                {
        if (DEBUG_BISON) {
            printf("Todos os personagens estão inativos\n");
        }
        // Ativa todos os personagens
        desativar_todos_personagens();
    }
#line 1752 "src/parser.tab.c"
    break;

  case 49: /* personagem: EU  */
#line 395 "src/parser.y"
       {
        (yyval.texto) = personagemQueFala;
    }
#line 1760 "src/parser.tab.c"
    break;

  case 50: /* personagem: VOCE  */
#line 398 "src/parser.y"
           {
        (yyval.texto) = personagemVoce;
    }
#line 1768 "src/parser.tab.c"
    break;

  case 51: /* personagem: texto  */
#line 401 "src/parser.y"
            {
        (yyval.texto) = (yyvsp[0].texto);
    }
#line 1776 "src/parser.tab.c"
    break;

  case 52: /* valor: NUMERO  */
#line 406 "src/parser.y"
           {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi((yyvsp[0].texto)));
        }
        (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), atoi((yyvsp[0].texto)), 0);
    }
#line 1787 "src/parser.tab.c"
    break;

  case 53: /* valor: TU MESMO  */
#line 412 "src/parser.y"
               {
        if (personagemDialogo == NULL) {
            yyerror("Variável 'tu mesmo' não definida");
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            Symbol *sym = get_symbol(personagemDialogo);
            if (!sym || sym->type != INT_VAR) { // INT_VAR é uma pilha
                yyerror("Variável 'tu mesmo' inválida ou não declarada");
                (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
            } else {
                // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
                LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_tu");
                // 2. Gera a chamada ao runtime para obter o valor do topo
                (yyval.llmValueRef) = gerar_peek_pilha(pilha_ptr);
            }
        }
    }
#line 1809 "src/parser.tab.c"
    break;

  case 54: /* valor: EU  */
#line 429 "src/parser.y"
         {
        if (personagemQueFala == NULL) {
            yyerror("Variável 'eu' não definida");
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            Symbol *sym = get_symbol(personagemQueFala);
            if (!sym || sym->type != INT_VAR) {
                yyerror("Variável 'eu' inválida ou não declarada");
                (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
            } else {
                // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
                LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_eu");
                // 2. Gera a chamada ao runtime para obter o valor do topo
                (yyval.llmValueRef) = gerar_peek_pilha(pilha_ptr);
            }
        }
    }
#line 1831 "src/parser.tab.c"
    break;

  case 55: /* valor: VOCE  */
#line 446 "src/parser.y"
           {
        if (personagemVoce == NULL) {
            yyerror("Variável 'voce' não definida");
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            Symbol *sym = get_symbol(personagemVoce);
            if (!sym || sym->type != INT_VAR) {
                yyerror("Variável 'voce' inválida ou não declarada");
                (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
            } else {
                // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
                LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_voce");
                // 2. Gera a chamada ao runtime para obter o valor do topo
                (yyval.llmValueRef) = gerar_peek_pilha(pilha_ptr);
            }
        }
    }
#line 1853 "src/parser.tab.c"
    break;

  case 56: /* valor: texto  */
#line 463 "src/parser.y"
            {
        Symbol *sym = get_symbol((yyvsp[0].texto));
        if (!sym || sym->type != INT_VAR) {
            printf("Variável de pilha inválida ou não declarada: %s\n", (yyvsp[0].texto));
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_var");
            // 2. Gera a chamada ao runtime para obter o valor do topo
            (yyval.llmValueRef) = gerar_peek_pilha(pilha_ptr);
        }
    }
#line 1870 "src/parser.tab.c"
    break;

  case 57: /* expressao: valor  */
#line 478 "src/parser.y"
          {
        (yyval.llmValueRef) = (yyvsp[0].llmValueRef); // valor já retorna LLVMValueRef
    }
#line 1878 "src/parser.tab.c"
    break;

  case 58: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 481 "src/parser.y"
                                     {
        if (DEBUG_BISON) printf("Expressão de soma\n");
        (yyval.llmValueRef) = LLVMBuildAdd(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "addtmp");
    }
#line 1887 "src/parser.tab.c"
    break;

  case 59: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 485 "src/parser.y"
                                        {
        if (DEBUG_BISON) printf("Expressão de subtração\n");
        (yyval.llmValueRef) = LLVMBuildSub(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "subtmp");
    }
#line 1896 "src/parser.tab.c"
    break;

  case 60: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 489 "src/parser.y"
                                           {
        if (DEBUG_BISON) printf("Expressão de multiplicação\n");
        (yyval.llmValueRef) = LLVMBuildMul(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "multmp");
    }
#line 1905 "src/parser.tab.c"
    break;

  case 61: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 493 "src/parser.y"
                                       {
        if (DEBUG_BISON) printf("Expressão de divisão\n");

        // Divisão por zero em tempo de compilação não pode ser detectada aqui
        (yyval.llmValueRef) = LLVMBuildSDiv(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "divtmp");
    }
#line 1916 "src/parser.tab.c"
    break;

  case 62: /* if_sentenca: SE condicao VIRGULA personagem SERA expressao  */
#line 502 "src/parser.y"
                                                  {
        // $2 é a condição (LLVMValueRef do tipo i1)
        // $4 é o nome da variável de pilha (const char*)
        // $6 é o novo valor para o topo (LLVMValueRef do tipo i32)

        // 1. Cria os blocos básicos para os caminhos do if.
        LLVMBasicBlockRef then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_then");
        LLVMBasicBlockRef merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_merge");

        // 2. Gera o desvio condicional.
        // Se a condição ($2) for true, pula para 'then_block', senão, pula para 'merge_block'.
        LLVMBuildCondBr(builder, (yyvsp[-4].llmValueRef), then_block, merge_block);

        // 3. Posiciona o builder para começar a escrever o código do bloco 'then'.
        // Este código só será executado se a condição for verdadeira.
        LLVMPositionBuilderAtEnd(builder, then_block);
        {
            // Lógica para atualizar o topo da pilha
            const char* nome_pilha = (yyvsp[-2].texto);
            LLVMValueRef novo_valor = (yyvsp[0].llmValueRef);
            Symbol* sym = get_symbol(nome_pilha);

            if (sym && sym->type == INT_VAR) {
                // Carrega o ponteiro para a estrutura da pilha
                LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr");
                // Gera a chamada ao runtime para atualizar o topo
                gerar_set_topo_pilha(pilha_ptr, novo_valor);
            } else {
                yyerror("Variável de destino no 'SE' não é uma pilha válida.");
            }
            
            // Ao final do bloco 'then', pula incondicionalmente para o bloco de continuação.
            LLVMBuildBr(builder, merge_block);
        }

        // 4. Move o builder para o bloco 'merge' para as próximas instruções do programa.
        LLVMPositionBuilderAtEnd(builder, merge_block);
    }
#line 1959 "src/parser.tab.c"
    break;

  case 63: /* if_sentenca: SE condicao VIRGULA personagem IF_MOSTRA_VALOR  */
#line 540 "src/parser.y"
                                                     {
        // --- Padrão de 'if' em LLVM ---
        // 1. Cria os blocos para os caminhos 'then' (se verdadeiro) e 'merge' (continuação).
        LLVMBasicBlockRef then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_then");
        LLVMBasicBlockRef merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_merge");

        // 2. Gera o desvio condicional baseado na condição ($2).
        LLVMBuildCondBr(builder, (yyvsp[-3].llmValueRef), then_block, merge_block);

        // 3. Posiciona o builder para preencher o bloco 'then'.
        LLVMPositionBuilderAtEnd(builder, then_block);
        {
            // --- Lógica do MOSTRA_VALOR ---
            const char *nome = (yyvsp[-1].texto);
            Symbol *sym = get_symbol(nome);
            if (!sym || sym->type != INT_VAR) {
                yyerror("Variável inválida ou não declarada no SE.");
            } else if (!sym->active) {
                printf("Variável %s não está ativa no SE.\n", sym->name);
            } else {
                gerar_print_topo_pilha(nome);
                // atualiza_personagemVoce();
            }
            // --- Fim da lógica ---

            // 4. No final do bloco 'then', pula para o bloco 'merge'.
            LLVMBuildBr(builder, merge_block);
        }
        // 5. Move o builder para o bloco 'merge' para continuar o resto do programa.
        LLVMPositionBuilderAtEnd(builder, merge_block);
    }
#line 1995 "src/parser.tab.c"
    break;

  case 64: /* if_sentenca: SE condicao VIRGULA personagem IF_LE_VALOR  */
#line 571 "src/parser.y"
                                                 {
        // --- Padrão de 'if' em LLVM ---
        LLVMBasicBlockRef then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_then");
        LLVMBasicBlockRef merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_merge");
        LLVMBuildCondBr(builder, (yyvsp[-3].llmValueRef), then_block, merge_block);

        LLVMPositionBuilderAtEnd(builder, then_block);
        {
            // --- Lógica do LE_VALOR ---
            const char *nome = (yyvsp[-1].texto);
            Symbol *sym = get_symbol(nome);
            if (!sym || sym->type != INT_VAR) {
                yyerror("Variável inválida ou não declarada no SE.");
            } else if (!sym->active) {
                printf("Variável %s não está ativa no SE.\n", sym->name);
            } else {
                gerar_leitura_inteiro(nome);
                // atualiza_personagemVoce();
            }
            // --- Fim da lógica ---
            LLVMBuildBr(builder, merge_block);
        }
        LLVMPositionBuilderAtEnd(builder, merge_block);
    }
#line 2024 "src/parser.tab.c"
    break;

  case 65: /* $@1: %empty  */
#line 598 "src/parser.y"
    {
        // --- AÇÃO INTERMEDIÁRIA (Mid-rule Action) ---
        ControleFluxo controle;
        controle.then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_then");
        controle.merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_merge");
        controle.else_block = controle.merge_block;

        LLVMBuildCondBr(builder, (yyvsp[-3].llmValueRef), controle.then_block, controle.merge_block);

        // Empilha a estrutura de controlo
        pilha_push(&pilhaControleFluxo, controle);

        // Move o builder para o bloco 'then'
        LLVMPositionBuilderAtEnd(builder, controle.then_block);
    }
#line 2044 "src/parser.tab.c"
    break;

  case 66: /* if_bloco: SE condicao VIRGULA texto INICIO $@1 bloco ENDIF  */
#line 614 "src/parser.y"
    {
        // --- AÇÃO FINAL ---
        // Pega a estrutura de controlo do topo da pilha e remove-a.
        ControleFluxo controle = pilha_pop(&pilhaControleFluxo);

        // Cria um desvio incondicional do final do bloco 'then' para o 'merge',
        // mas apenas se o bloco atual ainda não tiver uma instrução de terminação.
        LLVMBasicBlockRef current_block = LLVMGetInsertBlock(builder);
        LLVMValueRef last_instruction = LLVMGetLastInstruction(current_block);

        // Um bloco não tem terminador se estiver vazio (last_instruction == NULL)
        // ou se a sua última instrução não for um terminador.
        if (last_instruction == NULL || !LLVMIsATerminatorInst(last_instruction)) {
            LLVMBuildBr(builder, controle.merge_block);
        }

        // Move o builder para o bloco 'merge' para continuar a geração de código.
        LLVMPositionBuilderAtEnd(builder, controle.merge_block);
    }
#line 2068 "src/parser.tab.c"
    break;

  case 67: /* $@2: %empty  */
#line 637 "src/parser.y"
    {

    }
#line 2076 "src/parser.tab.c"
    break;

  case 68: /* while: ENQUANTO_COMECO condicao VIRGULA texto INICIO $@2 bloco texto ENQUANTO_FIM FIM  */
#line 641 "src/parser.y"
    {

    }
#line 2084 "src/parser.tab.c"
    break;

  case 69: /* $@3: %empty  */
#line 645 "src/parser.y"
    {

    }
#line 2092 "src/parser.tab.c"
    break;

  case 70: /* while: FACA VIRGULA texto INICIO $@3 bloco ENQUANTO_COMECO condicao VIRGULA texto FIM  */
#line 649 "src/parser.y"
    {

    }
#line 2100 "src/parser.tab.c"
    break;

  case 71: /* condicao: expressao FOR MAIOR expressao  */
#line 656 "src/parser.y"
                                      {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpgt");
        }
#line 2108 "src/parser.tab.c"
    break;

  case 72: /* condicao: expressao FOR MENOR expressao  */
#line 659 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmplt");
        }
#line 2116 "src/parser.tab.c"
    break;

  case 73: /* condicao: expressao FOR IGUAL expressao  */
#line 662 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpeq");
        }
#line 2124 "src/parser.tab.c"
    break;

  case 74: /* condicao: expressao NAO FOR MENOR expressao  */
#line 665 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpnlt");
        }
#line 2132 "src/parser.tab.c"
    break;

  case 75: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 668 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpngt");
        }
#line 2140 "src/parser.tab.c"
    break;

  case 76: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 671 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpneq");
        }
#line 2148 "src/parser.tab.c"
    break;

  case 77: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 677 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
        atualiza_personagemVoce();
    }
#line 2160 "src/parser.tab.c"
    break;

  case 78: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 684 "src/parser.y"
                                    {
        if (DEBUG_BISON) {
            printf("if sentença\n");
        }
        atualiza_personagemVoce();
    }
#line 2171 "src/parser.tab.c"
    break;

  case 79: /* dialogo: inicioDialogo texto FIM  */
#line 690 "src/parser.y"
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
        atualiza_personagemVoce();
    }
#line 2191 "src/parser.tab.c"
    break;

  case 80: /* dialogo: inicioDialogo texto VIRGULA TU EH expressao FIM  */
#line 705 "src/parser.y"
                                                      {
        personagemDialogo = strdup((yyvsp[-5].texto));

        Symbol *sym = get_symbol(personagemDialogo);
        if (!sym || sym->type != INT_VAR) { // INT_VAR é uma pilha
            yyerror("Variável de pilha inválida ou não declarada");
            YYABORT;
        } else if (!sym->active) {
            printf("Variável %s não está ativa\n", personagemDialogo);
            YYABORT;
        } else {

            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr");

            // Atualiza o valor no topo da pilha
            gerar_set_topo_pilha(pilha_ptr, (yyvsp[-1].llmValueRef));
        }

        free(personagemDialogo);
        personagemDialogo = NULL;
        atualiza_personagemVoce();
    }
#line 2219 "src/parser.tab.c"
    break;

  case 81: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 728 "src/parser.y"
                                                      {
        personagemDialogo = strdup((yyvsp[-5].texto));


        if (DEBUG_BISON) {
            // printf("Valor do personagem antes do diálogo: %d\n", get_int_value(personagemDialogo));
        }

        // LLVM: gerar incremento personagem = personagem + $6

        Symbol *sym = get_symbol(personagemDialogo);
        if (!sym || sym->type != INT_VAR) {
            yyerror("Variável de pilha inválida ou não declarada");
            YYABORT;
        } else if (!sym->active) {
            printf("Variável %s não está ativa\n", personagemDialogo);
            YYABORT;
        } else {

            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr");

            // 2. Lê o valor atual do topo da pilha
            LLVMValueRef valorAtual = gerar_peek_pilha(pilha_ptr);

            // 3. Converte o valor do adjetivo (int) para um LLVMValueRef
            LLVMValueRef incremento = LLVMConstInt(LLVMInt32Type(), (yyvsp[-1].inteiro), 0);

            // 4. Calcula o novo valor
            LLVMValueRef soma = LLVMBuildAdd(builder, valorAtual, incremento, "tmp_sum");

            // 5. Atualiza o valor no topo da pilha
            gerar_set_topo_pilha(pilha_ptr, soma);
        }

        free(personagemDialogo);
        personagemDialogo = NULL;
        atualiza_personagemVoce();
    }
#line 2263 "src/parser.tab.c"
    break;

  case 82: /* dialogo: inicioDialogo texto VIRGULA MOSTRA_VALOR FIM  */
#line 768 "src/parser.y"
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
        atualiza_personagemVoce();
    }
#line 2288 "src/parser.tab.c"
    break;

  case 83: /* dialogo: inicioDialogo texto VIRGULA LE_VALOR FIM  */
#line 788 "src/parser.y"
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
        atualiza_personagemVoce();
    }
#line 2309 "src/parser.tab.c"
    break;

  case 84: /* dialogo: inicioDialogo texto VIRGULA GUARDE texto INTERIOR FIM  */
#line 804 "src/parser.y"
                                                            {
        Symbol *sym = get_symbol((yyvsp[-5].texto));
        if (!sym || sym->type != INT_VAR) {
            yyerror("Variável não é uma pilha de inteiros ou não foi declarada.");
        } else {
            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr");

            // 2. Cria uma constante LLVM para o valor 0
            LLVMValueRef zero_const = LLVMConstInt(LLVMInt32Type(), 0, 0);
            
            // 3. Gera a chamada para a função de push do runtime com o valor 0
            gerar_push_pilha(pilha_ptr, zero_const);
        }
    }
#line 2329 "src/parser.tab.c"
    break;

  case 85: /* dialogo: inicioDialogo texto VIRGULA LEMBRE texto FIM  */
#line 819 "src/parser.y"
                                                   {
        Symbol *sym = get_symbol((yyvsp[-4].texto));
        if (!sym || sym->type != INT_VAR) {
            yyerror("Variável não é uma pilha de inteiros ou não foi declarada.");
        } else {
            printf("Lembrete: %s\n", (yyvsp[-2].texto));
            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr");
            
            gerar_pop_pilha(pilha_ptr);
        }
    }
#line 2346 "src/parser.tab.c"
    break;

  case 86: /* inicioDialogo: texto INICIO  */
#line 834 "src/parser.y"
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
#line 2382 "src/parser.tab.c"
    break;

  case 87: /* ato: ATO  */
#line 867 "src/parser.y"
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
#line 2399 "src/parser.tab.c"
    break;

  case 88: /* cena: CENA  */
#line 881 "src/parser.y"
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
#line 2416 "src/parser.tab.c"
    break;


#line 2420 "src/parser.tab.c"

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

#line 895 "src/parser.y"


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
