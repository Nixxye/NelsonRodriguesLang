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

#line 110 "src/parser.tab.c"

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
  YYSYMBOL_MAIOR_IGUAL = 8,                /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR = 9,                      /* MENOR  */
  YYSYMBOL_MENOR_IGUAL = 10,               /* MENOR_IGUAL  */
  YYSYMBOL_IGUAL = 11,                     /* IGUAL  */
  YYSYMBOL_NAO = 12,                       /* NAO  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_ENTAO = 14,                     /* ENTAO  */
  YYSYMBOL_EU = 15,                        /* EU  */
  YYSYMBOL_SE = 16,                        /* SE  */
  YYSYMBOL_SAEM = 17,                      /* SAEM  */
  YYSYMBOL_ENTRAM = 18,                    /* ENTRAM  */
  YYSYMBOL_TODOS = 19,                     /* TODOS  */
  YYSYMBOL_SOMAR = 20,                     /* SOMAR  */
  YYSYMBOL_SUBTRAIR = 21,                  /* SUBTRAIR  */
  YYSYMBOL_DIVIDIR = 22,                   /* DIVIDIR  */
  YYSYMBOL_MULTIPLICAR = 23,               /* MULTIPLICAR  */
  YYSYMBOL_INICIO = 24,                    /* INICIO  */
  YYSYMBOL_FIM = 25,                       /* FIM  */
  YYSYMBOL_SIM = 26,                       /* SIM  */
  YYSYMBOL_INTERROGACAO = 27,              /* INTERROGACAO  */
  YYSYMBOL_ABRE_COLCHETES = 28,            /* ABRE_COLCHETES  */
  YYSYMBOL_FECHA_COLCHETES = 29,           /* FECHA_COLCHETES  */
  YYSYMBOL_VOLTAR_CENARIO = 30,            /* VOLTAR_CENARIO  */
  YYSYMBOL_VOCE = 31,                      /* VOCE  */
  YYSYMBOL_ABRE_PARENTESES = 32,           /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 33,          /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 34,                   /* VIRGULA  */
  YYSYMBOL_SERA = 35,                      /* SERA  */
  YYSYMBOL_TOKEN = 36,                     /* TOKEN  */
  YYSYMBOL_ADJETIVO_POSITIVO = 37,         /* ADJETIVO_POSITIVO  */
  YYSYMBOL_ADJETIVO_NEGATIVO = 38,         /* ADJETIVO_NEGATIVO  */
  YYSYMBOL_TU = 39,                        /* TU  */
  YYSYMBOL_EH = 40,                        /* EH  */
  YYSYMBOL_E = 41,                         /* E  */
  YYSYMBOL_ENTRE = 42,                     /* ENTRE  */
  YYSYMBOL_ARTIGO = 43,                    /* ARTIGO  */
  YYSYMBOL_MESMO = 44,                     /* MESMO  */
  YYSYMBOL_NUMERO = 45,                    /* NUMERO  */
  YYSYMBOL_ADICIONAR_CENARIO = 46,         /* ADICIONAR_CENARIO  */
  YYSYMBOL_SUBSTITUIR_CENARIO = 47,        /* SUBSTITUIR_CENARIO  */
  YYSYMBOL_POR = 48,                       /* POR  */
  YYSYMBOL_NO_CENARIO = 49,                /* NO_CENARIO  */
  YYSYMBOL_MOSTRAR_CENARIO = 50,           /* MOSTRAR_CENARIO  */
  YYSYMBOL_MOSTRA_VALOR = 51,              /* MOSTRA_VALOR  */
  YYSYMBOL_LE_VALOR = 52,                  /* LE_VALOR  */
  YYSYMBOL_GUARDE = 53,                    /* GUARDE  */
  YYSYMBOL_INTERIOR = 54,                  /* INTERIOR  */
  YYSYMBOL_LEMBRE = 55,                    /* LEMBRE  */
  YYSYMBOL_IF_MOSTRA_VALOR = 56,           /* IF_MOSTRA_VALOR  */
  YYSYMBOL_IF_LE_VALOR = 57,               /* IF_LE_VALOR  */
  YYSYMBOL_ATO = 58,                       /* ATO  */
  YYSYMBOL_CENA = 59,                      /* CENA  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_programa = 61,                  /* programa  */
  YYSYMBOL_bloco = 62,                     /* bloco  */
  YYSYMBOL_instrucao = 63,                 /* instrucao  */
  YYSYMBOL_declaracaoCenario = 64,         /* declaracaoCenario  */
  YYSYMBOL_concatenarCenario = 65,         /* concatenarCenario  */
  YYSYMBOL_substituiCenario = 66,          /* substituiCenario  */
  YYSYMBOL_trocarCenario = 67,             /* trocarCenario  */
  YYSYMBOL_declaracaoQuestionamento = 68,  /* declaracaoQuestionamento  */
  YYSYMBOL_texto = 69,                     /* texto  */
  YYSYMBOL_palavra = 70,                   /* palavra  */
  YYSYMBOL_adjetivos = 71,                 /* adjetivos  */
  YYSYMBOL_declaracao = 72,                /* declaracao  */
  YYSYMBOL_declaracaoInicio = 73,          /* declaracaoInicio  */
  YYSYMBOL_personagensEntrando = 74,       /* personagensEntrando  */
  YYSYMBOL_personagensSaindo = 75,         /* personagensSaindo  */
  YYSYMBOL_alteracaoElenco = 76,           /* alteracaoElenco  */
  YYSYMBOL_personagem = 77,                /* personagem  */
  YYSYMBOL_valor = 78,                     /* valor  */
  YYSYMBOL_expressao = 79,                 /* expressao  */
  YYSYMBOL_if_sentenca = 80,               /* if_sentenca  */
  YYSYMBOL_if_bloco = 81,                  /* if_bloco  */
  YYSYMBOL_82_1 = 82,                      /* $@1  */
  YYSYMBOL_while = 83,                     /* while  */
  YYSYMBOL_84_2 = 84,                      /* $@2  */
  YYSYMBOL_85_3 = 85,                      /* $@3  */
  YYSYMBOL_86_4 = 86,                      /* $@4  */
  YYSYMBOL_condicao = 87,                  /* condicao  */
  YYSYMBOL_dialogo = 88,                   /* dialogo  */
  YYSYMBOL_inicioDialogo = 89,             /* inicioDialogo  */
  YYSYMBOL_ato = 90,                       /* ato  */
  YYSYMBOL_cena = 91                       /* cena  */
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
#define YYLAST   299

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    72,    76,    77,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
     101,   116,   136,   155,   174,   187,   200,   216,   219,   225,
     235,   239,   242,   245,   248,   254,   260,   263,   268,   275,
     286,   298,   310,   323,   334,   345,   358,   371,   384,   393,
     396,   399,   404,   410,   428,   445,   462,   477,   480,   484,
     488,   492,   501,   539,   570,   597,   596,   636,   655,   635,
     680,   679,   719,   722,   725,   728,   731,   734,   737,   740,
     746,   753,   759,   774,   797,   837,   857,   873,   888,   903,
     936,   950
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
  "ENQUANTO_COMECO", "ENQUANTO_FIM", "MAIOR", "MAIOR_IGUAL", "MENOR",
  "MENOR_IGUAL", "IGUAL", "NAO", "FOR", "ENTAO", "EU", "SE", "SAEM",
  "ENTRAM", "TODOS", "SOMAR", "SUBTRAIR", "DIVIDIR", "MULTIPLICAR",
  "INICIO", "FIM", "SIM", "INTERROGACAO", "ABRE_COLCHETES",
  "FECHA_COLCHETES", "VOLTAR_CENARIO", "VOCE", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "SERA", "TOKEN", "ADJETIVO_POSITIVO",
  "ADJETIVO_NEGATIVO", "TU", "EH", "E", "ENTRE", "ARTIGO", "MESMO",
  "NUMERO", "ADICIONAR_CENARIO", "SUBSTITUIR_CENARIO", "POR", "NO_CENARIO",
  "MOSTRAR_CENARIO", "MOSTRA_VALOR", "LE_VALOR", "GUARDE", "INTERIOR",
  "LEMBRE", "IF_MOSTRA_VALOR", "IF_LE_VALOR", "ATO", "CENA", "$accept",
  "programa", "bloco", "instrucao", "declaracaoCenario",
  "concatenarCenario", "substituiCenario", "trocarCenario",
  "declaracaoQuestionamento", "texto", "palavra", "adjetivos",
  "declaracao", "declaracaoInicio", "personagensEntrando",
  "personagensSaindo", "alteracaoElenco", "personagem", "valor",
  "expressao", "if_sentenca", "if_bloco", "$@1", "while", "$@2", "$@3",
  "$@4", "condicao", "dialogo", "inicioDialogo", "ato", "cena", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-34)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -116,    18,  -116,   -29,  -116,    43,   228,   -23,  -116,   -10,
     -23,  -116,  -116,   180,  -116,  -116,  -116,  -116,  -116,  -116,
     230,  -116,  -116,   -23,   106,  -116,  -116,  -116,  -116,  -116,
       1,  -116,  -116,   -23,    43,  -116,  -116,   -11,   257,  -116,
      17,  -116,    23,    34,   -23,   -23,    21,    61,   -23,   124,
    -116,  -116,     4,  -116,  -116,  -116,    93,   -23,   -23,    43,
       9,  -116,   109,    56,   -21,    49,  -116,    52,    69,    78,
      90,    83,   277,    74,    17,    26,    17,    92,   132,   -23,
      94,   -23,   138,   140,  -116,    17,    17,   137,   -23,  -116,
     221,  -116,  -116,   -23,    54,    54,    54,    54,   105,    43,
      43,    43,    43,    43,  -116,  -116,   -17,   -31,  -116,   -23,
     -23,  -116,  -116,   -25,  -116,   165,  -116,  -116,    74,   110,
     134,   159,   161,   -23,   -23,   180,    25,   151,   166,   170,
     178,    43,    43,    43,  -116,  -116,  -116,  -116,  -116,  -116,
      43,  -116,  -116,    17,    17,  -116,   175,    17,  -116,   113,
    -116,  -116,   152,   123,   212,  -116,    54,    54,    54,    54,
    -116,  -116,  -116,   180,  -116,  -116,   192,  -116,  -116,   195,
     193,   196,  -116,    43,   180,  -116,  -116,  -116,  -116,   177,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,   141,   180,  -116,
     -23,    39,   154,   197,  -116,  -116
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    67,     0,     0,     0,    30,     0,
       0,    90,    91,     3,     4,    10,    12,    13,    14,    11,
      40,    27,     9,     0,    19,    15,    16,    17,    18,     8,
       0,     6,     7,     0,     0,    54,    55,     0,     0,    52,
      56,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       5,    89,    26,    39,    28,    29,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,     0,     0,    43,     0,    40,     0,     0,     0,
       0,     0,     0,     0,    38,    41,    42,     0,     0,    82,
       0,    81,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    50,    51,     0,    47,     0,
       0,    46,    48,     0,    21,     0,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,    65,
       0,    63,    64,    44,    45,    20,     0,    51,    23,     0,
      85,    86,     0,     0,     0,    68,     0,     0,     0,     0,
      78,    77,    79,     0,    62,    22,    30,    31,    32,     0,
       0,     0,    88,     0,     0,    58,    59,    61,    60,     0,
      84,    36,    34,    35,    37,    83,    87,     0,     0,    66,
       0,    40,     0,     0,    71,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -115,   -12,  -116,  -116,  -116,  -116,  -116,    -1,
      51,  -116,  -116,  -116,   146,  -116,  -116,  -116,   -55,   150,
     172,  -116,  -116,  -116,  -116,  -116,  -116,   -32,  -116,  -116,
    -116,  -116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    13,    14,    15,    16,    17,    18,    19,    40,
      21,   169,    22,    23,    24,    75,    25,   107,    41,    42,
      26,    27,   163,    28,    34,   174,   125,    43,    29,    30,
      31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    50,    65,    92,   140,    33,    47,   139,   145,    49,
     154,     8,    20,     8,    48,     8,    82,    59,     2,     8,
      54,     3,    56,     4,    54,   141,   142,    87,    54,    62,
      83,    60,    64,    66,     5,    71,    72,     8,    78,   127,
     128,   129,   130,    74,    76,   193,     6,    80,   179,   155,
       7,    61,    88,     8,     8,   108,    85,    86,    35,   188,
     109,     8,    54,    51,     9,    10,    52,   110,    73,    35,
      54,    55,   106,    53,    36,     8,    11,    12,   113,     8,
     115,    91,    37,    93,    54,    36,    38,   119,    39,   104,
       8,    55,   126,    37,    94,    79,    98,     8,    55,    39,
      55,   175,   176,   177,   178,   105,    54,    55,   143,   144,
       8,    95,   131,    55,   132,    55,   133,   147,    84,   114,
      96,   111,   152,   153,    20,    55,    57,    55,    35,     8,
       8,    55,    97,    58,    89,   148,    55,    55,    54,    54,
      57,   187,    50,    90,    36,     8,     8,    58,   172,   166,
     167,   168,    37,    20,    54,    54,    38,    55,    39,     8,
       8,   112,    20,   116,    55,   117,    55,    50,    54,    54,
      55,   118,    81,    20,   149,   190,    50,    55,    20,   194,
       3,   189,     4,     3,   150,     4,   151,   191,     8,   192,
       8,    77,   156,     5,    55,    55,     5,    54,    55,    54,
     165,     8,    63,    55,    55,     6,   171,   157,     6,     7,
      54,   158,     7,     8,   146,     3,     8,   173,   185,   159,
     180,   186,   195,     9,    10,     0,     9,    10,     5,   -33,
     -33,   181,   182,   183,   -33,    11,    12,   184,    11,    12,
       6,     0,    55,    55,     7,    44,    45,    46,     8,   134,
     135,   136,   137,   138,    51,     0,     0,    52,     9,    10,
     120,     0,     0,     0,    53,     0,     8,     0,     0,     0,
      11,    12,   121,   122,   123,    54,   124,    67,    68,    69,
      70,   160,   161,   162,    99,   100,   101,   102,   103,     0,
     164,     0,     0,     0,     0,     0,     0,     0,     0,   170
};

static const yytype_int16 yycheck[] =
{
       1,    13,    34,    24,    35,    34,     7,    24,    33,    10,
     125,    36,    13,    36,    24,    36,    12,    16,     0,    36,
      45,     3,    23,     5,    45,    56,    57,    59,    45,    30,
      26,    30,    33,    44,    16,    12,    13,    36,    17,    94,
      95,    96,    97,    44,    45,     6,    28,    48,   163,    24,
      32,    50,    43,    36,    36,    29,    57,    58,    15,   174,
      34,    36,    45,    24,    46,    47,    27,    41,    34,    15,
      45,    20,    73,    34,    31,    36,    58,    59,    79,    36,
      81,    25,    39,    34,    45,    31,    43,    88,    45,    15,
      36,    40,    93,    39,    42,    34,    13,    36,    47,    45,
      49,   156,   157,   158,   159,    31,    45,    56,   109,   110,
      36,    42,     7,    62,     9,    64,    11,   118,    25,    25,
      42,    29,   123,   124,   125,    74,    34,    76,    15,    36,
      36,    80,    42,    41,    25,    25,    85,    86,    45,    45,
      34,   173,   154,    34,    31,    36,    36,    41,    25,    36,
      37,    38,    39,   154,    45,    45,    43,   106,    45,    36,
      36,    29,   163,    25,   113,    25,   115,   179,    45,    45,
     119,    34,    48,   174,    40,    34,   188,   126,   179,    25,
       3,     4,     5,     3,    25,     5,    25,   188,    36,   190,
      36,    45,    41,    16,   143,   144,    16,    45,   147,    45,
      25,    36,    30,   152,   153,    28,    54,    41,    28,    32,
      45,    41,    32,    36,    49,     3,    36,     5,    25,    41,
      25,    25,    25,    46,    47,    -1,    46,    47,    16,    37,
      38,    36,    37,    38,    42,    58,    59,    42,    58,    59,
      28,    -1,   191,   192,    32,    17,    18,    19,    36,    99,
     100,   101,   102,   103,    24,    -1,    -1,    27,    46,    47,
      39,    -1,    -1,    -1,    34,    -1,    36,    -1,    -1,    -1,
      58,    59,    51,    52,    53,    45,    55,    20,    21,    22,
      23,   131,   132,   133,     7,     8,     9,    10,    11,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    61,     0,     3,     5,    16,    28,    32,    36,    46,
      47,    58,    59,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    72,    73,    74,    76,    80,    81,    83,    88,
      89,    90,    91,    34,    84,    15,    31,    39,    43,    45,
      69,    78,    79,    87,    17,    18,    19,    69,    24,    69,
      63,    24,    27,    34,    45,    70,    69,    34,    41,    16,
      30,    50,    69,    80,    69,    87,    44,    20,    21,    22,
      23,    12,    13,    34,    69,    75,    69,    74,    17,    34,
      69,    48,    12,    26,    25,    69,    69,    87,    43,    25,
      34,    25,    24,    34,    42,    42,    42,    42,    13,     7,
       8,     9,    10,    11,    15,    31,    69,    77,    29,    34,
      41,    29,    29,    69,    25,    69,    25,    25,    34,    69,
      39,    51,    52,    53,    55,    86,    69,    78,    78,    78,
      78,     7,     9,    11,    79,    79,    79,    79,    79,    24,
      35,    56,    57,    69,    69,    33,    49,    69,    25,    40,
      25,    25,    69,    69,    62,    24,    41,    41,    41,    41,
      79,    79,    79,    82,    79,    25,    36,    37,    38,    71,
      79,    54,    25,     5,    85,    78,    78,    78,    78,    62,
      25,    36,    37,    38,    42,    25,    25,    87,    62,     4,
      34,    69,    69,     6,    25,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    65,    66,    67,    68,    68,    68,    69,    69,    69,
      70,    71,    71,    71,    71,    71,    71,    71,    72,    73,
      74,    74,    74,    75,    75,    75,    76,    76,    76,    77,
      77,    77,    78,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    80,    80,    80,    82,    81,    84,    85,    83,
      86,    83,    87,    87,    87,    87,    87,    87,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      90,    91
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
       6,     6,     6,     5,     5,     0,     8,     0,     0,    11,
       0,    11,     4,     4,     4,     4,     4,     5,     5,     5,
       2,     3,     3,     7,     7,     5,     5,     7,     6,     2,
       1,     1
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
#line 76 "src/parser.y"
                                {  }
#line 1344 "src/parser.tab.c"
    break;

  case 5: /* bloco: bloco instrucao  */
#line 77 "src/parser.y"
                               {  }
#line 1350 "src/parser.tab.c"
    break;

  case 20: /* declaracaoCenario: ABRE_PARENTESES texto VIRGULA texto FECHA_PARENTESES  */
#line 101 "src/parser.y"
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
#line 1368 "src/parser.tab.c"
    break;

  case 21: /* concatenarCenario: ADICIONAR_CENARIO INICIO texto FIM  */
#line 116 "src/parser.y"
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
#line 1391 "src/parser.tab.c"
    break;

  case 22: /* substituiCenario: SUBSTITUIR_CENARIO texto POR texto NO_CENARIO FIM  */
#line 136 "src/parser.y"
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
#line 1412 "src/parser.tab.c"
    break;

  case 23: /* trocarCenario: inicioDialogo VOLTAR_CENARIO ARTIGO texto FIM  */
#line 155 "src/parser.y"
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
#line 1435 "src/parser.tab.c"
    break;

  case 24: /* declaracaoQuestionamento: texto INTERROGACAO NAO FIM  */
#line 174 "src/parser.y"
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
#line 1453 "src/parser.tab.c"
    break;

  case 25: /* declaracaoQuestionamento: texto INTERROGACAO SIM FIM  */
#line 187 "src/parser.y"
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
#line 1471 "src/parser.tab.c"
    break;

  case 26: /* declaracaoQuestionamento: texto INTERROGACAO  */
#line 200 "src/parser.y"
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
#line 1489 "src/parser.tab.c"
    break;

  case 27: /* texto: palavra  */
#line 216 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1497 "src/parser.tab.c"
    break;

  case 28: /* texto: texto NUMERO  */
#line 219 "src/parser.y"
                   {
        //  if (DEBUG_BISON) {
        //      printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1508 "src/parser.tab.c"
    break;

  case 29: /* texto: texto palavra  */
#line 225 "src/parser.y"
                    {
        // if (DEBUG_BISON) {
        //     printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1519 "src/parser.tab.c"
    break;

  case 30: /* palavra: TOKEN  */
#line 235 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1525 "src/parser.tab.c"
    break;

  case 31: /* adjetivos: ADJETIVO_POSITIVO  */
#line 239 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1533 "src/parser.tab.c"
    break;

  case 32: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 242 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
#line 1541 "src/parser.tab.c"
    break;

  case 33: /* adjetivos: TOKEN  */
#line 245 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
#line 1549 "src/parser.tab.c"
    break;

  case 34: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 248 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) + 1;
    }
#line 1560 "src/parser.tab.c"
    break;

  case 35: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 254 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) - 1;
    }
#line 1571 "src/parser.tab.c"
    break;

  case 36: /* adjetivos: adjetivos TOKEN  */
#line 260 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1579 "src/parser.tab.c"
    break;

  case 37: /* adjetivos: adjetivos ENTRE  */
#line 263 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1587 "src/parser.tab.c"
    break;

  case 38: /* declaracao: declaracaoInicio texto FIM  */
#line 268 "src/parser.y"
                               {
        if (DEBUG_BISON) {
            printf("Declaração: %s\n", (yyvsp[-1].texto));
        }
    }
#line 1597 "src/parser.tab.c"
    break;

  case 39: /* declaracaoInicio: texto VIRGULA  */
#line 275 "src/parser.y"
                  {
        if (estado == E_DECLARACOES) {
            if (DEBUG_BISON) {
                printf("Criando variável: %s\n", (yyvsp[-1].texto));
            }
            add_symbol((yyvsp[-1].texto), INT_VAR);
        }
        (yyval.texto) = (yyvsp[-1].texto);
    }
#line 1611 "src/parser.tab.c"
    break;

  case 40: /* personagensEntrando: texto  */
#line 286 "src/parser.y"
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
#line 1628 "src/parser.tab.c"
    break;

  case 41: /* personagensEntrando: personagensEntrando VIRGULA texto  */
#line 298 "src/parser.y"
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
#line 1645 "src/parser.tab.c"
    break;

  case 42: /* personagensEntrando: personagensEntrando E texto  */
#line 310 "src/parser.y"
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
#line 1662 "src/parser.tab.c"
    break;

  case 43: /* personagensSaindo: texto  */
#line 323 "src/parser.y"
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
#line 1678 "src/parser.tab.c"
    break;

  case 44: /* personagensSaindo: personagensSaindo VIRGULA texto  */
#line 334 "src/parser.y"
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
#line 1694 "src/parser.tab.c"
    break;

  case 45: /* personagensSaindo: personagensSaindo E texto  */
#line 345 "src/parser.y"
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
#line 1710 "src/parser.tab.c"
    break;

  case 46: /* alteracaoElenco: ABRE_COLCHETES ENTRAM personagensEntrando FECHA_COLCHETES  */
#line 358 "src/parser.y"
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
#line 1728 "src/parser.tab.c"
    break;

  case 47: /* alteracaoElenco: ABRE_COLCHETES SAEM personagensSaindo FECHA_COLCHETES  */
#line 371 "src/parser.y"
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
#line 1746 "src/parser.tab.c"
    break;

  case 48: /* alteracaoElenco: ABRE_COLCHETES TODOS SAEM FECHA_COLCHETES  */
#line 384 "src/parser.y"
                                                {
        if (DEBUG_BISON) {
            printf("Todos os personagens estão inativos\n");
        }
        // Ativa todos os personagens
        desativar_todos_personagens();
    }
#line 1758 "src/parser.tab.c"
    break;

  case 49: /* personagem: EU  */
#line 393 "src/parser.y"
       {
        (yyval.texto) = personagemQueFala;
    }
#line 1766 "src/parser.tab.c"
    break;

  case 50: /* personagem: VOCE  */
#line 396 "src/parser.y"
           {
        (yyval.texto) = personagemVoce;
    }
#line 1774 "src/parser.tab.c"
    break;

  case 51: /* personagem: texto  */
#line 399 "src/parser.y"
            {
        (yyval.texto) = (yyvsp[0].texto);
    }
#line 1782 "src/parser.tab.c"
    break;

  case 52: /* valor: NUMERO  */
#line 404 "src/parser.y"
           {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi((yyvsp[0].texto)));
        }
        (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), atoi((yyvsp[0].texto)), 0);
    }
#line 1793 "src/parser.tab.c"
    break;

  case 53: /* valor: TU MESMO  */
#line 410 "src/parser.y"
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
                printf("Valor de 'tu mesmo': %s\n", sym->name);
                // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
                LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_tu");
                // 2. Gera a chamada ao runtime para obter o valor do topo
                (yyval.llmValueRef) = gerar_peek_pilha(pilha_ptr);
            }
        }
    }
#line 1816 "src/parser.tab.c"
    break;

  case 54: /* valor: EU  */
#line 428 "src/parser.y"
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
#line 1838 "src/parser.tab.c"
    break;

  case 55: /* valor: VOCE  */
#line 445 "src/parser.y"
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
#line 1860 "src/parser.tab.c"
    break;

  case 56: /* valor: texto  */
#line 462 "src/parser.y"
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
#line 1877 "src/parser.tab.c"
    break;

  case 57: /* expressao: valor  */
#line 477 "src/parser.y"
          {
        (yyval.llmValueRef) = (yyvsp[0].llmValueRef); // valor já retorna LLVMValueRef
    }
#line 1885 "src/parser.tab.c"
    break;

  case 58: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 480 "src/parser.y"
                                     {
        if (DEBUG_BISON) printf("Expressão de soma\n");
        (yyval.llmValueRef) = LLVMBuildAdd(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "addtmp");
    }
#line 1894 "src/parser.tab.c"
    break;

  case 59: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 484 "src/parser.y"
                                        {
        if (DEBUG_BISON) printf("Expressão de subtração\n");
        (yyval.llmValueRef) = LLVMBuildSub(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "subtmp");
    }
#line 1903 "src/parser.tab.c"
    break;

  case 60: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 488 "src/parser.y"
                                           {
        if (DEBUG_BISON) printf("Expressão de multiplicação\n");
        (yyval.llmValueRef) = LLVMBuildMul(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "multmp");
    }
#line 1912 "src/parser.tab.c"
    break;

  case 61: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 492 "src/parser.y"
                                       {
        if (DEBUG_BISON) printf("Expressão de divisão\n");

        // Divisão por zero em tempo de compilação não pode ser detectada aqui
        (yyval.llmValueRef) = LLVMBuildSDiv(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "divtmp");
    }
#line 1923 "src/parser.tab.c"
    break;

  case 62: /* if_sentenca: SE condicao VIRGULA personagem SERA expressao  */
#line 501 "src/parser.y"
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
#line 1966 "src/parser.tab.c"
    break;

  case 63: /* if_sentenca: SE condicao VIRGULA personagem IF_MOSTRA_VALOR  */
#line 539 "src/parser.y"
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
#line 2002 "src/parser.tab.c"
    break;

  case 64: /* if_sentenca: SE condicao VIRGULA personagem IF_LE_VALOR  */
#line 570 "src/parser.y"
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
#line 2031 "src/parser.tab.c"
    break;

  case 65: /* $@1: %empty  */
#line 597 "src/parser.y"
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
#line 2051 "src/parser.tab.c"
    break;

  case 66: /* if_bloco: SE condicao VIRGULA texto INICIO $@1 bloco ENDIF  */
#line 613 "src/parser.y"
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
#line 2075 "src/parser.tab.c"
    break;

  case 67: /* $@2: %empty  */
#line 636 "src/parser.y"
    {
        // WHILE
        // --- Ação 1: Prepara os blocos ---
        ControleFluxo controle;
        controle.else_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "while_cond");
        controle.then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "while_body");
        controle.merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "while_merge");

        // 1. Pula para o bloco da condição para o primeiro teste.
        LLVMBuildBr(builder, controle.else_block);

        // 2. Empilha a estrutura para uso futuro.
        pilha_push(&pilhaControleFluxo, controle);

        // 3. Posiciona o builder no bloco da CONDIÇÃO.
        // É aqui que o código da regra 'condicao' será gerado.
        LLVMPositionBuilderAtEnd(builder, controle.else_block);
    }
#line 2098 "src/parser.tab.c"
    break;

  case 68: /* $@3: %empty  */
#line 655 "src/parser.y"
    {
        // --- Ação 2: Gera o desvio condicional ---
        // 1. Pega a estrutura de controle (sem remover da pilha).
        ControleFluxo controle = pilha_peek(&pilhaControleFluxo);

        // 2. A condição ($3) acabou de ser processada. Agora geramos o desvio.
        // Se for true -> vai para o corpo. Se for false -> sai do laço.
        LLVMBuildCondBr(builder, (yyvsp[-3].llmValueRef), controle.then_block, controle.merge_block);

        // 3. Move o builder para o corpo do laço para gerar o código do 'bloco'.
        LLVMPositionBuilderAtEnd(builder, controle.then_block);
    }
#line 2115 "src/parser.tab.c"
    break;

  case 69: /* while: ENQUANTO_COMECO $@2 condicao VIRGULA texto INICIO $@3 bloco texto ENQUANTO_FIM FIM  */
#line 668 "src/parser.y"
    {
        // --- Ação de Saída do While ---
        // 1. Pega a estrutura de controle e remove da pilha.
        ControleFluxo controle = pilha_pop(&pilhaControleFluxo);

        // 2. No final do corpo do laço, cria um pulo de volta para o teste da condição.
        LLVMBuildBr(builder, controle.else_block);

        // 3. Move o builder para o bloco de continuação.
        LLVMPositionBuilderAtEnd(builder, controle.merge_block);
    }
#line 2131 "src/parser.tab.c"
    break;

  case 70: /* $@4: %empty  */
#line 680 "src/parser.y"
    {
        printf("Iniciando do-while\n");
        // DO WHILE
        ControleFluxo controle;
        controle.then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "do_body");
        controle.else_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "do_cond");
        controle.merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "do_merge");

        // Começamos no corpo
        LLVMBuildBr(builder, controle.then_block);
        LLVMPositionBuilderAtEnd(builder, controle.then_block);

        pilha_push(&pilhaControleFluxo, controle);
    }
#line 2150 "src/parser.tab.c"
    break;

  case 71: /* while: FACA VIRGULA texto INICIO $@4 bloco ENQUANTO_COMECO condicao VIRGULA texto FIM  */
#line 695 "src/parser.y"
    {
        // --- Ação de Saída Corrigida ---
        ControleFluxo controle = pilha_pop(&pilhaControleFluxo);

        LLVMBasicBlockRef current_block = LLVMGetInsertBlock(builder);
        LLVMValueRef last_instruction = LLVMGetLastInstruction(current_block);
        if (last_instruction == NULL || !LLVMIsATerminatorInst(last_instruction)) {
            // No final do corpo, pula para o bloco de teste da condição.
            LLVMBuildBr(builder, controle.else_block);
        }

        // Posiciona o builder no bloco da condição.
        LLVMPositionBuilderAtEnd(builder, controle.else_block);

        // Se a condição ($8) for true, volta para o corpo; senão, sai do laço.
        LLVMBuildCondBr(builder, (yyvsp[-3].llmValueRef), controle.then_block, controle.merge_block);
        
        // Move o builder para o bloco de continuação.
        LLVMPositionBuilderAtEnd(builder, controle.merge_block);

        // TODO: Entender pq aqui é o 8 que é o correto
    }
#line 2177 "src/parser.tab.c"
    break;

  case 72: /* condicao: expressao FOR MAIOR expressao  */
#line 719 "src/parser.y"
                                      {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpgt");
        }
#line 2185 "src/parser.tab.c"
    break;

  case 73: /* condicao: expressao FOR MAIOR_IGUAL expressao  */
#line 722 "src/parser.y"
                                          {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpge");
        }
#line 2193 "src/parser.tab.c"
    break;

  case 74: /* condicao: expressao FOR MENOR expressao  */
#line 725 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmplt");
        }
#line 2201 "src/parser.tab.c"
    break;

  case 75: /* condicao: expressao FOR MENOR_IGUAL expressao  */
#line 728 "src/parser.y"
                                          {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmple");
        }
#line 2209 "src/parser.tab.c"
    break;

  case 76: /* condicao: expressao FOR IGUAL expressao  */
#line 731 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpeq");
        }
#line 2217 "src/parser.tab.c"
    break;

  case 77: /* condicao: expressao NAO FOR MENOR expressao  */
#line 734 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpnlt");
        }
#line 2225 "src/parser.tab.c"
    break;

  case 78: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 737 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpngt");
        }
#line 2233 "src/parser.tab.c"
    break;

  case 79: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 740 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpneq");
        }
#line 2241 "src/parser.tab.c"
    break;

  case 80: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 746 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
        atualiza_personagemVoce();
    }
#line 2253 "src/parser.tab.c"
    break;

  case 81: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 753 "src/parser.y"
                                    {
        if (DEBUG_BISON) {
            printf("if sentença\n");
        }
        atualiza_personagemVoce();
    }
#line 2264 "src/parser.tab.c"
    break;

  case 82: /* dialogo: inicioDialogo texto FIM  */
#line 759 "src/parser.y"
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
#line 2284 "src/parser.tab.c"
    break;

  case 83: /* dialogo: inicioDialogo texto VIRGULA TU EH expressao FIM  */
#line 774 "src/parser.y"
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
#line 2312 "src/parser.tab.c"
    break;

  case 84: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 797 "src/parser.y"
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
#line 2356 "src/parser.tab.c"
    break;

  case 85: /* dialogo: inicioDialogo texto VIRGULA MOSTRA_VALOR FIM  */
#line 837 "src/parser.y"
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
#line 2381 "src/parser.tab.c"
    break;

  case 86: /* dialogo: inicioDialogo texto VIRGULA LE_VALOR FIM  */
#line 857 "src/parser.y"
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
#line 2402 "src/parser.tab.c"
    break;

  case 87: /* dialogo: inicioDialogo texto VIRGULA GUARDE texto INTERIOR FIM  */
#line 873 "src/parser.y"
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
#line 2422 "src/parser.tab.c"
    break;

  case 88: /* dialogo: inicioDialogo texto VIRGULA LEMBRE texto FIM  */
#line 888 "src/parser.y"
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
#line 2439 "src/parser.tab.c"
    break;

  case 89: /* inicioDialogo: texto INICIO  */
#line 903 "src/parser.y"
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
#line 2475 "src/parser.tab.c"
    break;

  case 90: /* ato: ATO  */
#line 936 "src/parser.y"
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
#line 2492 "src/parser.tab.c"
    break;

  case 91: /* cena: CENA  */
#line 950 "src/parser.y"
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
#line 2509 "src/parser.tab.c"
    break;


#line 2513 "src/parser.tab.c"

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

#line 964 "src/parser.y"


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
