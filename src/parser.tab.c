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
  YYSYMBOL_FINALIZACAO = 3,                /* FINALIZACAO  */
  YYSYMBOL_FACA = 4,                       /* FACA  */
  YYSYMBOL_ENDIF = 5,                      /* ENDIF  */
  YYSYMBOL_ENQUANTO_COMECO = 6,            /* ENQUANTO_COMECO  */
  YYSYMBOL_ENQUANTO_FIM = 7,               /* ENQUANTO_FIM  */
  YYSYMBOL_MAIOR = 8,                      /* MAIOR  */
  YYSYMBOL_MAIOR_IGUAL = 9,                /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR = 10,                     /* MENOR  */
  YYSYMBOL_MENOR_IGUAL = 11,               /* MENOR_IGUAL  */
  YYSYMBOL_IGUAL = 12,                     /* IGUAL  */
  YYSYMBOL_NAO = 13,                       /* NAO  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
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
  YYSYMBOL_O_TAMANHO_DE = 58,              /* O_TAMANHO_DE  */
  YYSYMBOL_ATO = 59,                       /* ATO  */
  YYSYMBOL_CENA = 60,                      /* CENA  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_programa = 62,                  /* programa  */
  YYSYMBOL_bloco = 63,                     /* bloco  */
  YYSYMBOL_instrucao = 64,                 /* instrucao  */
  YYSYMBOL_saida = 65,                     /* saida  */
  YYSYMBOL_declaracaoCenario = 66,         /* declaracaoCenario  */
  YYSYMBOL_concatenarCenario = 67,         /* concatenarCenario  */
  YYSYMBOL_substituiCenario = 68,          /* substituiCenario  */
  YYSYMBOL_trocarCenario = 69,             /* trocarCenario  */
  YYSYMBOL_declaracaoQuestionamento = 70,  /* declaracaoQuestionamento  */
  YYSYMBOL_texto = 71,                     /* texto  */
  YYSYMBOL_palavra = 72,                   /* palavra  */
  YYSYMBOL_adjetivos = 73,                 /* adjetivos  */
  YYSYMBOL_declaracao = 74,                /* declaracao  */
  YYSYMBOL_declaracaoInicio = 75,          /* declaracaoInicio  */
  YYSYMBOL_personagensEntrando = 76,       /* personagensEntrando  */
  YYSYMBOL_personagensSaindo = 77,         /* personagensSaindo  */
  YYSYMBOL_alteracaoElenco = 78,           /* alteracaoElenco  */
  YYSYMBOL_personagem = 79,                /* personagem  */
  YYSYMBOL_valor = 80,                     /* valor  */
  YYSYMBOL_expressao = 81,                 /* expressao  */
  YYSYMBOL_if_sentenca = 82,               /* if_sentenca  */
  YYSYMBOL_if_bloco = 83,                  /* if_bloco  */
  YYSYMBOL_84_1 = 84,                      /* $@1  */
  YYSYMBOL_while = 85,                     /* while  */
  YYSYMBOL_86_2 = 86,                      /* $@2  */
  YYSYMBOL_87_3 = 87,                      /* $@3  */
  YYSYMBOL_88_4 = 88,                      /* $@4  */
  YYSYMBOL_condicao = 89,                  /* condicao  */
  YYSYMBOL_dialogo = 90,                   /* dialogo  */
  YYSYMBOL_inicioDialogo = 91,             /* inicioDialogo  */
  YYSYMBOL_ato = 92,                       /* ato  */
  YYSYMBOL_cena = 93,                      /* cena  */
  YYSYMBOL_nome_variavel_int = 94,         /* nome_variavel_int  */
  YYSYMBOL_nome_cenario = 95,              /* nome_cenario  */
  YYSYMBOL_nome_questionamento = 96,       /* nome_questionamento  */
  YYSYMBOL_nome_personagem = 97,           /* nome_personagem  */
  YYSYMBOL_valor_string = 98               /* valor_string  */
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
<<<<<<< HEAD
#define YYLAST   307
=======
#define YYLAST   315
>>>>>>> main

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
<<<<<<< HEAD
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200
=======
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206
>>>>>>> main

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
<<<<<<< HEAD
       0,    71,    71,    72,    76,    77,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
     101,   120,   144,   169,   191,   208,   225,   245,   248,   254,
     264,   268,   271,   274,   277,   283,   289,   292,   297,   304,
     315,   327,   339,   353,   364,   375,   388,   401,   414,   423,
     426,   429,   434,   440,   458,   475,   492,   510,   526,   529,
     533,   537,   541,   550,   588,   619,   646,   645,   685,   704,
     684,   729,   728,   768,   771,   774,   777,   780,   783,   786,
     789,   792,   805,   811,   817,   832,   847,   887,   910,   930,
     946,   961,   976,  1009,  1023
=======
       0,    83,    83,    84,    88,    89,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   111,   119,   134,   154,   173,   192,   205,   218,   234,
     237,   243,   253,   257,   260,   263,   266,   272,   278,   281,
     286,   293,   304,   316,   328,   342,   353,   364,   377,   390,
     403,   412,   415,   418,   423,   429,   447,   464,   481,   498,
     513,   516,   520,   524,   528,   537,   575,   606,   633,   632,
     672,   691,   671,   716,   715,   755,   758,   761,   764,   767,
     770,   773,   776,   782,   789,   795,   810,   833,   873,   893,
     909,   924,   939,   972,   986,  1000,  1004,  1008,  1012,  1016
>>>>>>> main
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
  "\"end of file\"", "error", "\"invalid token\"", "FINALIZACAO", "FACA",
  "ENDIF", "ENQUANTO_COMECO", "ENQUANTO_FIM", "MAIOR", "MAIOR_IGUAL",
  "MENOR", "MENOR_IGUAL", "IGUAL", "NAO", "FOR", "EU", "SE", "SAEM",
  "ENTRAM", "TODOS", "SOMAR", "SUBTRAIR", "DIVIDIR", "MULTIPLICAR",
  "INICIO", "FIM", "SIM", "INTERROGACAO", "ABRE_COLCHETES",
  "FECHA_COLCHETES", "VOLTAR_CENARIO", "VOCE", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "SERA", "TOKEN", "ADJETIVO_POSITIVO",
  "ADJETIVO_NEGATIVO", "TU", "EH", "E", "ENTRE", "ARTIGO", "MESMO",
  "NUMERO", "ADICIONAR_CENARIO", "SUBSTITUIR_CENARIO", "POR", "NO_CENARIO",
  "MOSTRAR_CENARIO", "MOSTRA_VALOR", "LE_VALOR", "GUARDE", "INTERIOR",
  "LEMBRE", "IF_MOSTRA_VALOR", "IF_LE_VALOR", "O_TAMANHO_DE", "ATO",
  "CENA", "$accept", "programa", "bloco", "instrucao", "saida",
  "declaracaoCenario", "concatenarCenario", "substituiCenario",
  "trocarCenario", "declaracaoQuestionamento", "texto", "palavra",
  "adjetivos", "declaracao", "declaracaoInicio", "personagensEntrando",
  "personagensSaindo", "alteracaoElenco", "personagem", "valor",
  "expressao", "if_sentenca", "if_bloco", "$@1", "while", "$@2", "$@3",
  "$@4", "condicao", "dialogo", "inicioDialogo", "ato", "cena",
  "nome_variavel_int", "nome_cenario", "nome_questionamento",
  "nome_personagem", "valor_string", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

<<<<<<< HEAD
#define YYPACT_NINF (-127)
=======
#define YYPACT_NINF (-126)
>>>>>>> main

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

<<<<<<< HEAD
#define YYTABLE_NINF (-82)
=======
#define YYTABLE_NINF (-98)
>>>>>>> main

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
    -127,    37,  -127,   -26,  -127,   244,   132,    -6,  -127,    44,
      -6,  -127,  -127,   158,  -127,  -127,  -127,  -127,  -127,  -127,
     -17,  -127,  -127,    -6,    30,  -127,  -127,  -127,  -127,  -127,
      20,  -127,  -127,    -6,   244,  -127,  -127,    49,   245,  -127,
      -6,   122,  -127,    78,    65,    -6,    -6,    84,   176,    -6,
     -25,  -127,  -127,     9,  -127,  -127,  -127,    18,    -6,    -6,
     244,    73,  -127,   162,    96,     2,    88,  -127,    89,    90,
     117,   123,   -18,   127,   296,    77,   -18,   196,   -18,   202,
     141,    -6,    94,    -6,   153,   163,  -127,   -18,   -18,   149,
      -6,  -127,  -127,   243,  -127,  -127,    -6,    36,    36,    36,
      36,   267,   244,   244,   244,   244,   244,  -127,  -127,    10,
     -32,  -127,    -6,    -6,  -127,  -127,   166,  -127,   119,  -127,
    -127,    77,    98,    67,   175,   184,    -6,    -6,   158,    64,
     -18,   181,   188,   191,   194,   244,   244,   244,  -127,  -127,
    -127,  -127,  -127,  -127,   244,  -127,  -127,   -18,   -18,  -127,
     208,   -18,  -127,   219,  -127,  -127,    79,   156,   192,  -127,
      36,    36,    36,    36,  -127,  -127,  -127,   158,  -127,  -127,
    -127,  -127,   -18,    24,   215,   216,  -127,   244,   158,  -127,
    -127,  -127,  -127,    82,  -127,  -127,  -127,  -127,   -18,  -127,
    -127,   182,   158,  -127,    -6,   236,   178,   221,  -127,  -127
=======
    -126,   101,  -126,  -126,   -30,  -126,   228,   187,   -13,  -126,
     -18,   -13,  -126,  -126,    40,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,    82,  -126,  -126,   -13,    51,  -126,  -126,  -126,
    -126,  -126,    78,  -126,  -126,     5,    15,  -126,   -13,   228,
    -126,  -126,    30,   240,  -126,   -13,    16,  -126,     7,    19,
    -126,   -13,   -13,    41,    16,    57,   -13,    16,    63,  -126,
    -126,  -126,  -126,    87,   -13,   -13,   228,    80,  -126,    16,
      96,    64,  -126,     9,   -21,   104,  -126,    98,   116,   123,
     124,  -126,   129,   220,    -3,    81,  -126,   133,   115,   -13,
     121,   -13,  -126,  -126,  -126,   122,   -13,  -126,  -126,   102,
     143,   144,  -126,   -13,   257,   257,   257,   257,   182,   228,
     228,   228,   228,   228,  -126,  -126,    89,    14,  -126,  -126,
     -13,   -13,  -126,  -126,   142,  -126,   127,    -3,   157,   145,
     162,   168,   -13,   -13,  -126,  -126,    40,   106,   160,   161,
     167,   173,   228,   228,   228,  -126,  -126,  -126,  -126,  -126,
    -126,   228,  -126,  -126,  -126,  -126,  -126,   198,  -126,   239,
    -126,  -126,    21,    48,   209,  -126,   257,   257,   257,   257,
    -126,  -126,  -126,    40,  -126,  -126,   158,  -126,  -126,   202,
     199,   201,  -126,   228,    40,  -126,  -126,  -126,  -126,   175,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,   208,    40,  -126,
     -13,     2,   114,   211,  -126,  -126
>>>>>>> main
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
<<<<<<< HEAD
       2,     0,     1,     0,    68,     0,     0,     0,    30,     0,
       0,    93,    94,     3,     4,    10,    12,    13,    14,    11,
      40,    27,     9,     0,    19,    15,    16,    17,    18,     8,
       0,     6,     7,     0,     0,    54,    55,     0,     0,    52,
       0,    57,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     5,    92,    26,    39,    28,    29,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,    43,     0,    40,     0,
       0,     0,     0,     0,     0,     0,    38,    41,    42,     0,
       0,    84,    85,     0,    83,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,    50,    51,
       0,    47,     0,     0,    46,    48,     0,    21,     0,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,    73,    74,
      75,    76,    77,    66,     0,    64,    65,    44,    45,    20,
       0,    51,    23,     0,    88,    89,     0,     0,     0,    69,
       0,     0,     0,     0,    79,    78,    80,     0,    63,    22,
      31,    32,    33,     0,     0,     0,    91,     0,     0,    59,
      60,    62,    61,     0,    86,    34,    35,    37,    36,    87,
      90,     0,     0,    67,     0,    40,     0,     0,    72,    70
=======
       2,     0,     1,    21,     0,    70,     0,     0,     0,    32,
       0,     0,    93,    94,     3,     4,    20,    10,    12,    13,
      14,    11,    98,    29,     9,     0,    19,    15,    16,    17,
      18,     8,     0,     6,     7,     0,     0,    42,     0,     0,
      56,    57,     0,     0,    54,     0,    95,    60,     0,     0,
      59,     0,     0,     0,    96,     0,     0,    99,     0,     5,
      92,    30,    31,     0,     0,     0,     0,     0,    83,    98,
       0,     0,    41,    28,     0,     0,    55,     0,     0,     0,
       0,    58,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,    40,    43,    44,     0,     0,    84,    85,     0,
       0,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,    52,    98,     0,    53,    49,
       0,     0,    48,    50,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,    77,    78,    79,
      68,     0,    66,    67,    46,    47,    22,     0,    25,     0,
      88,    89,     0,     0,     0,    71,     0,     0,     0,     0,
      81,    80,    82,     0,    65,    24,    32,    33,    34,     0,
       0,     0,    91,     0,     0,    61,    62,    64,    63,     0,
      87,    38,    36,    37,    39,    86,    90,     0,     0,    69,
       0,    98,     0,     0,    74,    72
>>>>>>> main
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
<<<<<<< HEAD
    -127,  -127,  -126,   -12,  -127,  -127,  -127,  -127,  -127,    -1,
      97,  -127,  -127,  -127,   201,  -127,  -127,  -127,   -84,     0,
     231,  -127,  -127,  -127,  -127,  -127,  -127,   -29,  -127,  -127,
    -127,  -127
=======
    -126,  -126,  -125,   -12,  -126,  -126,  -126,  -126,  -126,  -126,
      -1,     8,  -126,  -126,  -126,   181,  -126,  -126,  -126,   -88,
     107,   214,  -126,  -126,  -126,  -126,  -126,  -126,   -34,  -126,
    -126,  -126,  -126,     0,   151,  -126,   -24,   -22
>>>>>>> main
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
<<<<<<< HEAD
       0,     1,    13,    14,    15,    16,    17,    18,    19,   130,
      21,   173,    22,    23,    24,    77,    25,   110,    42,    43,
      26,    27,   167,    28,    34,   178,   128,    44,    29,    30,
      31,    32
=======
       0,     1,    14,    15,    16,    17,    18,    19,    20,    21,
      46,    23,   179,    24,    25,    26,    85,    27,   117,    47,
      48,    28,    29,   173,    30,    39,   184,   136,    49,    31,
      32,    33,    34,    50,    55,    36,    37,    58
>>>>>>> main
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
<<<<<<< HEAD
      20,    51,   158,   144,    41,    66,    48,    52,    33,    50,
      53,     8,    20,   131,   132,   133,   134,    54,     8,     8,
      55,    84,    57,    83,   145,   146,    95,    55,    55,    63,
       8,    89,    65,    41,   143,    85,    60,     2,     8,    72,
       3,   183,     4,    86,    76,    78,     8,    55,    82,   184,
      61,    35,   192,     5,     8,    55,     8,    87,    88,    41,
       8,   185,   186,    55,    58,     6,   187,    36,    49,     7,
      62,    59,     8,     8,   109,    37,   179,   180,   181,   182,
     116,    39,   118,     9,    10,     3,   193,     4,   159,   122,
      73,    74,   107,    67,    40,   129,    11,    12,     5,    75,
       8,    80,   138,   139,   140,   141,   142,   153,   108,    55,
       6,   147,   148,     8,     7,     8,    90,    56,     8,   117,
     151,    94,    96,   152,    55,   156,   157,    20,     9,    10,
       8,    97,    98,   175,     8,   164,   165,   166,    56,    55,
     101,    11,    12,    55,   168,    56,    51,    56,   191,    45,
      46,    47,   172,   174,    56,     8,   -81,    20,     8,    99,
      56,     3,    56,     4,    55,   100,    20,    55,   150,    56,
     115,    51,   188,    56,     5,    56,    41,    20,   119,    56,
      51,   176,    20,   121,    56,    56,     6,    91,   120,    92,
       7,   195,     8,   196,     8,     3,    93,   177,     8,   149,
     154,    55,     8,   198,     9,    10,    56,    55,     5,   155,
      81,    55,     8,    56,     8,    56,   194,    11,    12,    56,
       6,    55,   160,    55,     7,   111,    56,    56,     8,   161,
     112,   114,   162,   169,    35,   163,    58,   113,     9,    10,
     189,   190,   197,    59,    56,    56,   199,    79,    56,     0,
      36,    11,    12,    56,    56,     8,   170,   171,    37,    35,
      52,    64,    38,    53,    39,    68,    69,    70,    71,    56,
      54,     0,     8,     0,   135,    36,   136,    40,   137,     0,
       8,    55,   123,    37,     0,    56,     0,    38,     0,    39,
       0,     0,    56,    56,   124,   125,   126,     0,   127,     0,
       0,     0,    40,   102,   103,   104,   105,   106
=======
      22,    35,    59,   102,    38,    75,    56,    54,    71,   203,
      57,   164,   114,    22,    35,     9,   138,   139,   140,   141,
      82,    83,   100,     9,    61,    63,    60,    86,   115,   -97,
      62,    69,    95,     9,    90,   101,   -95,    74,     9,    72,
      93,    94,    73,     3,     4,    81,     5,    61,   189,   151,
      69,    69,     9,    84,    62,    57,     6,     9,    88,   198,
     118,    61,    62,    69,    69,    62,    61,   124,     7,   126,
     152,   153,     8,   182,    76,   181,     9,    62,   185,   186,
     187,   188,    62,   116,     9,    64,    10,    11,    57,    98,
      57,    89,    65,    61,    66,    54,   154,   155,    99,    12,
      13,     2,   137,   118,     3,     4,    60,     5,    67,   -97,
     119,    91,    92,   150,     9,   120,   -95,     6,     9,    69,
      69,    97,   121,    96,    62,     9,    69,    61,    68,     7,
     165,   162,   163,     8,    61,    22,    35,     9,   103,   204,
     104,   129,     9,   108,   123,    62,   125,    10,    11,   197,
       9,    61,    59,   130,   131,   132,   127,   133,   105,    61,
      12,    13,   122,    22,    35,   106,   107,    64,   134,   135,
      62,    62,    22,    35,    65,   156,   157,    59,     3,     4,
     199,     5,   158,    22,    35,   159,    59,   160,    22,    35,
     142,     6,   143,   161,   144,   -35,   -35,   201,    35,   202,
     -35,   166,   167,     7,    51,    52,    53,     8,   168,    62,
      62,     9,     3,     4,   169,   183,   145,   146,   147,   148,
     149,    10,    11,   175,   195,     6,   196,   190,   109,   110,
     111,   112,   113,    87,    12,    13,   205,     7,   191,   192,
     193,     8,   200,    40,   194,     9,    70,   128,     0,   170,
     171,   172,     0,     0,    40,    10,    11,     0,   174,    41,
      77,    78,    79,    80,     9,     0,   180,    42,    12,    13,
      41,    43,    40,    44,     0,   176,   177,   178,    42,     0,
       0,     0,    43,     0,    44,     0,    45,     0,    41,     0,
       0,     0,     0,     9,     0,     0,    42,    45,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    45
>>>>>>> main
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
       1,    13,   128,    35,     5,    34,     7,    24,    34,    10,
      27,    36,    13,    97,    98,    99,   100,    34,    36,    36,
      45,    12,    23,    48,    56,    57,    24,    45,    45,    30,
      36,    60,    33,    34,    24,    26,    16,     0,    36,    40,
       3,   167,     5,    25,    45,    46,    36,    45,    49,    25,
      30,    15,   178,    16,    36,    45,    36,    58,    59,    60,
      36,    37,    38,    45,    34,    28,    42,    31,    24,    32,
      50,    41,    36,    36,    75,    39,   160,   161,   162,   163,
      81,    45,    83,    46,    47,     3,     4,     5,    24,    90,
      12,    13,    15,    44,    58,    96,    59,    60,    16,    34,
      36,    17,   102,   103,   104,   105,   106,    40,    31,    45,
      28,   112,   113,    36,    32,    36,    43,    20,    36,    25,
     121,    25,    34,    25,    45,   126,   127,   128,    46,    47,
      36,    42,    42,    54,    36,   135,   136,   137,    41,    45,
      13,    59,    60,    45,   144,    48,   158,    50,   177,    17,
      18,    19,   153,   153,    57,    36,    34,   158,    36,    42,
      63,     3,    65,     5,    45,    42,   167,    45,    49,    72,
      29,   183,   173,    76,    16,    78,   177,   178,    25,    82,
     192,    25,   183,    34,    87,    88,    28,    25,    25,    27,
      32,   192,    36,   194,    36,     3,    34,     5,    36,    33,
      25,    45,    36,    25,    46,    47,   109,    45,    16,    25,
      34,    45,    36,   116,    36,   118,    34,    59,    60,   122,
      28,    45,    41,    45,    32,    29,   129,   130,    36,    41,
      34,    29,    41,    25,    15,    41,    34,    41,    46,    47,
      25,    25,     6,    41,   147,   148,    25,    46,   151,    -1,
      31,    59,    60,   156,   157,    36,    37,    38,    39,    15,
      24,    30,    43,    27,    45,    20,    21,    22,    23,   172,
      34,    -1,    36,    -1,     7,    31,     9,    58,    11,    -1,
      36,    45,    39,    39,    -1,   188,    -1,    43,    -1,    45,
      -1,    -1,   195,   196,    51,    52,    53,    -1,    55,    -1,
      -1,    -1,    58,     7,     8,     9,    10,    11
=======
       1,     1,    14,    24,    34,    39,    24,     8,    32,     7,
      11,   136,    15,    14,    14,    36,   104,   105,   106,   107,
      13,    14,    13,    36,    45,    25,    24,    51,    31,    27,
      22,    32,    66,    36,    56,    26,    34,    38,    36,    34,
      64,    65,    27,     3,     4,    45,     6,    45,   173,    35,
      51,    52,    36,    34,    46,    56,    16,    36,    17,   184,
      84,    45,    54,    64,    65,    57,    45,    89,    28,    91,
      56,    57,    32,    25,    44,    54,    36,    69,   166,   167,
     168,   169,    74,    84,    36,    34,    46,    47,    89,    25,
      91,    34,    41,    45,    16,    96,   120,   121,    34,    59,
      60,     0,   103,   127,     3,     4,    24,     6,    30,    27,
      29,    48,    25,    24,    36,    34,    34,    16,    36,   120,
     121,    25,    41,    43,   116,    36,   127,    45,    50,    28,
      24,   132,   133,    32,    45,   136,   136,    36,    34,    25,
      42,    39,    36,    14,    29,   137,    25,    46,    47,   183,
      36,    45,   164,    51,    52,    53,    34,    55,    42,    45,
      59,    60,    29,   164,   164,    42,    42,    34,    25,    25,
     162,   163,   173,   173,    41,    33,    49,   189,     3,     4,
       5,     6,    25,   184,   184,    40,   198,    25,   189,   189,
       8,    16,    10,    25,    12,    37,    38,   198,   198,   200,
      42,    41,    41,    28,    17,    18,    19,    32,    41,   201,
     202,    36,     3,     4,    41,     6,   109,   110,   111,   112,
     113,    46,    47,    25,    25,    16,    25,    25,     8,     9,
      10,    11,    12,    52,    59,    60,    25,    28,    36,    37,
      38,    32,    34,    15,    42,    36,    32,    96,    -1,   142,
     143,   144,    -1,    -1,    15,    46,    47,    -1,   151,    31,
      20,    21,    22,    23,    36,    -1,   159,    39,    59,    60,
      31,    43,    15,    45,    -1,    36,    37,    38,    39,    -1,
      -1,    -1,    43,    -1,    45,    -1,    58,    -1,    31,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    39,    58,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58
>>>>>>> main
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
<<<<<<< HEAD
       0,    62,     0,     3,     5,    16,    28,    32,    36,    46,
      47,    59,    60,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    73,    74,    75,    77,    81,    82,    84,    89,
      90,    91,    92,    34,    85,    15,    31,    39,    43,    45,
      58,    70,    79,    80,    88,    17,    18,    19,    70,    24,
      70,    64,    24,    27,    34,    45,    71,    70,    34,    41,
      16,    30,    50,    70,    81,    70,    88,    44,    20,    21,
      22,    23,    70,    12,    13,    34,    70,    76,    70,    75,
      17,    34,    70,    48,    12,    26,    25,    70,    70,    88,
      43,    25,    27,    34,    25,    24,    34,    42,    42,    42,
      42,    13,     7,     8,     9,    10,    11,    15,    31,    70,
      78,    29,    34,    41,    29,    29,    70,    25,    70,    25,
      25,    34,    70,    39,    51,    52,    53,    55,    87,    70,
      70,    79,    79,    79,    79,     7,     9,    11,    80,    80,
      80,    80,    80,    24,    35,    56,    57,    70,    70,    33,
      49,    70,    25,    40,    25,    25,    70,    70,    63,    24,
      41,    41,    41,    41,    80,    80,    80,    83,    80,    25,
      37,    38,    70,    72,    80,    54,    25,     5,    86,    79,
      79,    79,    79,    63,    25,    37,    38,    42,    70,    25,
      25,    88,    63,     4,    34,    70,    70,     6,    25,    25
=======
       0,    62,     0,     3,     4,     6,    16,    28,    32,    36,
      46,    47,    59,    60,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    74,    75,    76,    78,    82,    83,
      85,    90,    91,    92,    93,    94,    96,    97,    34,    86,
      15,    31,    39,    43,    45,    58,    71,    80,    81,    89,
      94,    17,    18,    19,    71,    95,    24,    71,    98,    64,
      24,    45,    72,    94,    34,    41,    16,    30,    50,    71,
      82,    97,    34,    27,    71,    89,    44,    20,    21,    22,
      23,    94,    13,    14,    34,    77,    97,    76,    17,    34,
      98,    48,    25,    97,    97,    89,    43,    25,    25,    34,
      13,    26,    24,    34,    42,    42,    42,    42,    14,     8,
       9,    10,    11,    12,    15,    31,    71,    79,    97,    29,
      34,    41,    29,    29,    98,    25,    98,    34,    95,    39,
      51,    52,    53,    55,    25,    25,    88,    71,    80,    80,
      80,    80,     8,    10,    12,    81,    81,    81,    81,    81,
      24,    35,    56,    57,    97,    97,    33,    49,    25,    40,
      25,    25,    71,    71,    63,    24,    41,    41,    41,    41,
      81,    81,    81,    84,    81,    25,    36,    37,    38,    73,
      81,    54,    25,     6,    87,    80,    80,    80,    80,    63,
      25,    36,    37,    38,    42,    25,    25,    89,    63,     5,
      34,    71,    71,     7,    25,    25
>>>>>>> main
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
<<<<<<< HEAD
      65,    66,    67,    68,    69,    69,    69,    70,    70,    70,
      71,    72,    72,    72,    72,    72,    72,    72,    73,    74,
      75,    75,    75,    76,    76,    76,    77,    77,    77,    78,
      78,    78,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    81,    81,    81,    83,    82,    85,    86,
      84,    87,    84,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    90,    91,    92
=======
      64,    65,    66,    67,    68,    69,    70,    70,    70,    71,
      71,    71,    72,    73,    73,    73,    73,    73,    73,    73,
      74,    75,    76,    76,    76,    77,    77,    77,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      81,    81,    81,    81,    81,    82,    82,    82,    84,    83,
      86,    87,    85,    88,    85,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    92,    93,    94,    95,    96,    97,    98
>>>>>>> main
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
<<<<<<< HEAD
       5,     4,     6,     5,     4,     4,     2,     1,     2,     2,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     2,
       1,     3,     3,     1,     3,     3,     4,     4,     4,     1,
       1,     1,     1,     2,     1,     1,     2,     1,     1,     6,
       6,     6,     6,     6,     5,     5,     0,     8,     0,     0,
      11,     0,    11,     4,     4,     4,     4,     4,     5,     5,
       5,     1,     2,     3,     3,     3,     7,     7,     5,     5,
       7,     6,     2,     1,     1
=======
       1,     1,     5,     4,     6,     5,     4,     4,     2,     1,
       2,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     2,     1,     3,     3,     1,     3,     3,     4,     4,
       4,     1,     1,     1,     1,     2,     1,     1,     2,     1,
       1,     6,     6,     6,     6,     6,     5,     5,     0,     8,
       0,     0,    11,     0,    11,     4,     4,     4,     4,     4,
       5,     5,     5,     2,     3,     3,     7,     7,     5,     5,
       7,     6,     2,     1,     1,     1,     1,     1,     1,     1
>>>>>>> main
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
#line 88 "src/parser.y"
                                {  }
#line 1360 "src/parser.tab.c"
    break;

  case 5: /* bloco: bloco instrucao  */
#line 89 "src/parser.y"
                               {  }
#line 1366 "src/parser.tab.c"
    break;

  case 21: /* saida: FINALIZACAO  */
#line 111 "src/parser.y"
                {
        gerar_exit();
    }
#line 1374 "src/parser.tab.c"
    break;

  case 22: /* declaracaoCenario: ABRE_PARENTESES nome_cenario VIRGULA valor_string FECHA_PARENTESES  */
#line 119 "src/parser.y"
                                                                       {
        if (estado == E_DECLARACOES) {
            if (DEBUG_BISON) {
                printf("Declaração de cenário: %s com valor inicial: %s\n", (yyvsp[-3].texto), (yyvsp[-1].texto));
            }
            add_symbol((yyvsp[-3].texto), STRING_VAR);
            cenarioAtual = strdup((yyvsp[-3].texto));
            ativar_cenario(cenarioAtual);

            Symbol* sym = get_symbol(cenarioAtual);
            LLVMValueRef nova_str_ptr = gerar_criar_string((yyvsp[-1].texto));
            // Armazena o ponteiro na variável
            LLVMBuildStore(builder, nova_str_ptr, sym->llvm_ref);
        } else {
            yyerror("Declaração de cenário fora de contexto");
        }
    }
<<<<<<< HEAD
#line 1375 "src/parser.tab.c"
    break;

  case 21: /* concatenarCenario: ADICIONAR_CENARIO INICIO texto FIM  */
#line 120 "src/parser.y"
                                       {
=======
#line 1392 "src/parser.tab.c"
    break;

  case 23: /* concatenarCenario: ADICIONAR_CENARIO INICIO valor_string FIM  */
#line 134 "src/parser.y"
                                              {
>>>>>>> main
        if (estado != E_DECLARACOES) {
            if (cenarioAtual == NULL) {
                yyerror("Nenhum cenário atual definido");
            } else {
                Symbol* sym = get_symbol(cenarioAtual);
                // 1. LOAD: Carrega o ponteiro atual da string
                LLVMValueRef str_atual_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "load_str");
                
                // 2. CALL: Gera a chamada para a função de concatenação
                LLVMValueRef str_nova_ptr = gerar_concatenar_string(str_atual_ptr, (yyvsp[-1].texto));

                // 3. STORE: Armazena o novo ponteiro de volta na variável (MUITO IMPORTANTE!)
                LLVMBuildStore(builder, str_nova_ptr, sym->llvm_ref);
                if (DEBUG_BISON) {
                    printf("Cenário atualizado: %s\n", cenarioAtual);
                }
            }
        } else {
            yyerror("Adição de cenário fora de contexto");
        }
    }
<<<<<<< HEAD
#line 1402 "src/parser.tab.c"
    break;

  case 22: /* substituiCenario: SUBSTITUIR_CENARIO texto POR texto NO_CENARIO FIM  */
#line 144 "src/parser.y"
                                                     {
=======
#line 1415 "src/parser.tab.c"
    break;

  case 24: /* substituiCenario: SUBSTITUIR_CENARIO valor_string POR valor_string NO_CENARIO FIM  */
#line 154 "src/parser.y"
                                                                   {
>>>>>>> main
        if (estado != E_DECLARACOES) {
            if (cenarioAtual == NULL) {
                yyerror("Nenhum cenário atual definido");
            } else {
                Symbol* sym = get_symbol(cenarioAtual);
                if (sym) {
                    // 1. LOAD: Carrega o ponteiro atual da string
                    LLVMValueRef str_atual_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "load_str");

                    // 2. CALL: Gera a chamada para a função de substituição
                    LLVMValueRef str_nova_ptr = gerar_substituir_string(str_atual_ptr, (yyvsp[-4].texto), (yyvsp[-2].texto));

                    // 3. STORE: Armazena o novo ponteiro de volta na variável (MUITO IMPORTANTE!)
                    LLVMBuildStore(builder, str_nova_ptr, sym->llvm_ref);
                }
                if (DEBUG_BISON) {
                }
            }
        } else {
            yyerror("Substituição de cenário fora de contexto");
        }
    }
<<<<<<< HEAD
#line 1430 "src/parser.tab.c"
    break;

  case 23: /* trocarCenario: inicioDialogo VOLTAR_CENARIO ARTIGO texto FIM  */
#line 169 "src/parser.y"
                                                  {
=======
#line 1436 "src/parser.tab.c"
    break;

  case 25: /* trocarCenario: inicioDialogo VOLTAR_CENARIO ARTIGO nome_cenario FIM  */
#line 173 "src/parser.y"
                                                         {
>>>>>>> main
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
<<<<<<< HEAD
#line 1453 "src/parser.tab.c"
    break;

  case 24: /* declaracaoQuestionamento: texto INTERROGACAO NAO FIM  */
#line 191 "src/parser.y"
                               {
=======
#line 1459 "src/parser.tab.c"
    break;

  case 26: /* declaracaoQuestionamento: nome_questionamento INTERROGACAO NAO FIM  */
#line 192 "src/parser.y"
                                             {
>>>>>>> main
        if (DEBUG_BISON) {
            printf("Declaração de questionamento negativo: %s\n", (yyvsp[-3].texto));
        }
        Symbol *sym = get_symbol((yyvsp[-3].texto));
        if (!sym) {
            add_symbol((yyvsp[-3].texto), BOOL_VAR);
            Symbol *sym = get_symbol((yyvsp[-3].texto)); // Colocar isso no add_symbol?
            sym->llvm_ref = gerar_criar_booleano((yyvsp[-3].texto), 0);
        } else if (sym->type != BOOL_VAR) {
            yyerror("Tipo incorreto para questionamento (esperado BOOL_VAR)");
            YYABORT;
        } else {
            LLVMValueRef valor_false = LLVMConstInt(LLVMInt1Type(), 0, 0);
            gerar_set_booleano(sym->llvm_ref, valor_false);
        }
    }
<<<<<<< HEAD
#line 1475 "src/parser.tab.c"
    break;

  case 25: /* declaracaoQuestionamento: texto INTERROGACAO SIM FIM  */
#line 208 "src/parser.y"
                                 {
=======
#line 1477 "src/parser.tab.c"
    break;

  case 27: /* declaracaoQuestionamento: nome_questionamento INTERROGACAO SIM FIM  */
#line 205 "src/parser.y"
                                               {
>>>>>>> main
        if (DEBUG_BISON) {
            printf("Declaração de questionamento afirmativo: %s\n", (yyvsp[-3].texto));
        }
        Symbol *sym = get_symbol((yyvsp[-3].texto));
        if (!sym) {
            add_symbol((yyvsp[-3].texto), BOOL_VAR);
            Symbol *sym = get_symbol((yyvsp[-3].texto)); // Colocar isso no add_symbol?
            sym->llvm_ref = gerar_criar_booleano((yyvsp[-3].texto), 1);
        } else if (sym->type != BOOL_VAR) {
            yyerror("Tipo incorreto para questionamento (esperado BOOL_VAR)");
            YYABORT;
        } else {
            LLVMValueRef valor_true = LLVMConstInt(LLVMInt1Type(), 1, 0);
            gerar_set_booleano(sym->llvm_ref, valor_true);// Inicializa como verdadeiro
        }
    }
<<<<<<< HEAD
#line 1497 "src/parser.tab.c"
    break;

  case 26: /* declaracaoQuestionamento: texto INTERROGACAO  */
#line 225 "src/parser.y"
                         {
=======
#line 1495 "src/parser.tab.c"
    break;

  case 28: /* declaracaoQuestionamento: nome_questionamento INTERROGACAO  */
#line 218 "src/parser.y"
                                       {
>>>>>>> main
        if (DEBUG_BISON) {
            printf("Declaração de questionamento: %s\n", (yyvsp[-1].texto));
        }
        Symbol *sym = get_symbol((yyvsp[-1].texto));
        if (!sym) {
            add_symbol((yyvsp[-1].texto), BOOL_VAR);
            Symbol *sym = get_symbol((yyvsp[-1].texto)); // Colocar isso no add_symbol?
            sym->llvm_ref = gerar_criar_booleano((yyvsp[-1].texto), 0);
        } else if (sym->type != BOOL_VAR) {
            yyerror("Tipo incorreto para questionamento (esperado BOOL_VAR)");
            YYABORT;
        } else {
            LLVMValueRef valor_false = LLVMConstInt(LLVMInt1Type(), 0, 0);
            gerar_set_booleano(sym->llvm_ref, valor_false);
        }
    }
<<<<<<< HEAD
#line 1519 "src/parser.tab.c"
    break;

  case 27: /* texto: palavra  */
#line 245 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1527 "src/parser.tab.c"
    break;

  case 28: /* texto: texto NUMERO  */
#line 248 "src/parser.y"
=======
#line 1513 "src/parser.tab.c"
    break;

  case 29: /* texto: palavra  */
#line 234 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1521 "src/parser.tab.c"
    break;

  case 30: /* texto: texto NUMERO  */
#line 237 "src/parser.y"
>>>>>>> main
                   {
        //  if (DEBUG_BISON) {
        //      printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
<<<<<<< HEAD
#line 1538 "src/parser.tab.c"
    break;

  case 29: /* texto: texto palavra  */
#line 254 "src/parser.y"
=======
#line 1532 "src/parser.tab.c"
    break;

  case 31: /* texto: texto palavra  */
#line 243 "src/parser.y"
>>>>>>> main
                    {
        // if (DEBUG_BISON) {
        //     printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
<<<<<<< HEAD
#line 1549 "src/parser.tab.c"
    break;

  case 30: /* palavra: TOKEN  */
#line 264 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1555 "src/parser.tab.c"
    break;

  case 31: /* adjetivos: ADJETIVO_POSITIVO  */
#line 268 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1563 "src/parser.tab.c"
    break;

  case 32: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 271 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
#line 1571 "src/parser.tab.c"
    break;

  case 33: /* adjetivos: texto  */
#line 274 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
#line 1579 "src/parser.tab.c"
    break;

  case 34: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 277 "src/parser.y"
=======
#line 1543 "src/parser.tab.c"
    break;

  case 32: /* palavra: TOKEN  */
#line 253 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1549 "src/parser.tab.c"
    break;

  case 33: /* adjetivos: ADJETIVO_POSITIVO  */
#line 257 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1557 "src/parser.tab.c"
    break;

  case 34: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 260 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
#line 1565 "src/parser.tab.c"
    break;

  case 35: /* adjetivos: TOKEN  */
#line 263 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
#line 1573 "src/parser.tab.c"
    break;

  case 36: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 266 "src/parser.y"
>>>>>>> main
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) + 1;
    }
<<<<<<< HEAD
#line 1590 "src/parser.tab.c"
    break;

  case 35: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 283 "src/parser.y"
=======
#line 1584 "src/parser.tab.c"
    break;

  case 37: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 272 "src/parser.y"
>>>>>>> main
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) - 1;
    }
<<<<<<< HEAD
#line 1601 "src/parser.tab.c"
    break;

  case 36: /* adjetivos: adjetivos texto  */
#line 289 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1609 "src/parser.tab.c"
    break;

  case 37: /* adjetivos: adjetivos ENTRE  */
#line 292 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1617 "src/parser.tab.c"
    break;

  case 38: /* declaracao: declaracaoInicio texto FIM  */
#line 297 "src/parser.y"
                               {
=======
#line 1595 "src/parser.tab.c"
    break;

  case 38: /* adjetivos: adjetivos TOKEN  */
#line 278 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1603 "src/parser.tab.c"
    break;

  case 39: /* adjetivos: adjetivos ENTRE  */
#line 281 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1611 "src/parser.tab.c"
    break;

  case 40: /* declaracao: declaracaoInicio nome_variavel_int FIM  */
#line 286 "src/parser.y"
                                           {
>>>>>>> main
        if (DEBUG_BISON) {
            printf("Declaração: %s\n", (yyvsp[-1].texto));
        }
    }
<<<<<<< HEAD
#line 1627 "src/parser.tab.c"
    break;

  case 39: /* declaracaoInicio: texto VIRGULA  */
#line 304 "src/parser.y"
                  {
=======
#line 1621 "src/parser.tab.c"
    break;

  case 41: /* declaracaoInicio: nome_variavel_int VIRGULA  */
#line 293 "src/parser.y"
                              {
>>>>>>> main
        if (estado == E_DECLARACOES) {
            if (DEBUG_BISON) {
                printf("Criando variável: %s\n", (yyvsp[-1].texto));
            }
            add_symbol((yyvsp[-1].texto), INT_VAR);
        }
        (yyval.texto) = (yyvsp[-1].texto);
    }
<<<<<<< HEAD
#line 1641 "src/parser.tab.c"
    break;

  case 40: /* personagensEntrando: texto  */
#line 315 "src/parser.y"
          {
=======
#line 1635 "src/parser.tab.c"
    break;

  case 42: /* personagensEntrando: nome_personagem  */
#line 304 "src/parser.y"
                    {
>>>>>>> main
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
<<<<<<< HEAD
#line 1658 "src/parser.tab.c"
    break;

  case 41: /* personagensEntrando: personagensEntrando VIRGULA texto  */
#line 327 "src/parser.y"
                                        {
=======
#line 1652 "src/parser.tab.c"
    break;

  case 43: /* personagensEntrando: personagensEntrando VIRGULA nome_personagem  */
#line 316 "src/parser.y"
                                                  {
>>>>>>> main
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
<<<<<<< HEAD
#line 1675 "src/parser.tab.c"
    break;

  case 42: /* personagensEntrando: personagensEntrando E texto  */
#line 339 "src/parser.y"
                                  {
=======
#line 1669 "src/parser.tab.c"
    break;

  case 44: /* personagensEntrando: personagensEntrando E nome_personagem  */
#line 328 "src/parser.y"
                                            {
>>>>>>> main
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
<<<<<<< HEAD
#line 1692 "src/parser.tab.c"
    break;

  case 43: /* personagensSaindo: texto  */
#line 353 "src/parser.y"
          {
=======
#line 1686 "src/parser.tab.c"
    break;

  case 45: /* personagensSaindo: nome_personagem  */
#line 342 "src/parser.y"
                    {
>>>>>>> main
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
<<<<<<< HEAD
#line 1708 "src/parser.tab.c"
    break;

  case 44: /* personagensSaindo: personagensSaindo VIRGULA texto  */
#line 364 "src/parser.y"
                                      {
=======
#line 1702 "src/parser.tab.c"
    break;

  case 46: /* personagensSaindo: personagensSaindo VIRGULA nome_personagem  */
#line 353 "src/parser.y"
                                                {
>>>>>>> main
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
<<<<<<< HEAD
#line 1724 "src/parser.tab.c"
    break;

  case 45: /* personagensSaindo: personagensSaindo E texto  */
#line 375 "src/parser.y"
                                {
=======
#line 1718 "src/parser.tab.c"
    break;

  case 47: /* personagensSaindo: personagensSaindo E nome_personagem  */
#line 364 "src/parser.y"
                                          {
>>>>>>> main
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
<<<<<<< HEAD
#line 1740 "src/parser.tab.c"
    break;

  case 46: /* alteracaoElenco: ABRE_COLCHETES ENTRAM personagensEntrando FECHA_COLCHETES  */
#line 388 "src/parser.y"
=======
#line 1734 "src/parser.tab.c"
    break;

  case 48: /* alteracaoElenco: ABRE_COLCHETES ENTRAM personagensEntrando FECHA_COLCHETES  */
#line 377 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 1758 "src/parser.tab.c"
    break;

  case 47: /* alteracaoElenco: ABRE_COLCHETES SAEM personagensSaindo FECHA_COLCHETES  */
#line 401 "src/parser.y"
=======
#line 1752 "src/parser.tab.c"
    break;

  case 49: /* alteracaoElenco: ABRE_COLCHETES SAEM personagensSaindo FECHA_COLCHETES  */
#line 390 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 1776 "src/parser.tab.c"
    break;

  case 48: /* alteracaoElenco: ABRE_COLCHETES TODOS SAEM FECHA_COLCHETES  */
#line 414 "src/parser.y"
=======
#line 1770 "src/parser.tab.c"
    break;

  case 50: /* alteracaoElenco: ABRE_COLCHETES TODOS SAEM FECHA_COLCHETES  */
#line 403 "src/parser.y"
>>>>>>> main
                                                {
        if (DEBUG_BISON) {
            printf("Todos os personagens estão inativos\n");
        }
        // Ativa todos os personagens
        desativar_todos_personagens();
    }
<<<<<<< HEAD
#line 1788 "src/parser.tab.c"
    break;

  case 49: /* personagem: EU  */
#line 423 "src/parser.y"
       {
        (yyval.texto) = personagemQueFala;
    }
#line 1796 "src/parser.tab.c"
    break;

  case 50: /* personagem: VOCE  */
#line 426 "src/parser.y"
           {
        (yyval.texto) = personagemVoce;
    }
#line 1804 "src/parser.tab.c"
    break;

  case 51: /* personagem: texto  */
#line 429 "src/parser.y"
            {
        (yyval.texto) = (yyvsp[0].texto);
    }
#line 1812 "src/parser.tab.c"
    break;

  case 52: /* valor: NUMERO  */
#line 434 "src/parser.y"
=======
#line 1782 "src/parser.tab.c"
    break;

  case 51: /* personagem: EU  */
#line 412 "src/parser.y"
       {
        (yyval.texto) = personagemQueFala;
    }
#line 1790 "src/parser.tab.c"
    break;

  case 52: /* personagem: VOCE  */
#line 415 "src/parser.y"
           {
        (yyval.texto) = personagemVoce;
    }
#line 1798 "src/parser.tab.c"
    break;

  case 53: /* personagem: nome_personagem  */
#line 418 "src/parser.y"
                      {
        (yyval.texto) = (yyvsp[0].texto);
    }
#line 1806 "src/parser.tab.c"
    break;

  case 54: /* valor: NUMERO  */
#line 423 "src/parser.y"
>>>>>>> main
           {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi((yyvsp[0].texto)));
        }
        (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), atoi((yyvsp[0].texto)), 0);
    }
<<<<<<< HEAD
#line 1823 "src/parser.tab.c"
    break;

  case 53: /* valor: TU MESMO  */
#line 440 "src/parser.y"
=======
#line 1817 "src/parser.tab.c"
    break;

  case 55: /* valor: TU MESMO  */
#line 429 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 1846 "src/parser.tab.c"
    break;

  case 54: /* valor: EU  */
#line 458 "src/parser.y"
=======
#line 1840 "src/parser.tab.c"
    break;

  case 56: /* valor: EU  */
#line 447 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 1868 "src/parser.tab.c"
    break;

  case 55: /* valor: VOCE  */
#line 475 "src/parser.y"
=======
#line 1862 "src/parser.tab.c"
    break;

  case 57: /* valor: VOCE  */
#line 464 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 1890 "src/parser.tab.c"
    break;

  case 56: /* valor: O_TAMANHO_DE texto  */
#line 492 "src/parser.y"
                         {
=======
#line 1884 "src/parser.tab.c"
    break;

  case 58: /* valor: O_TAMANHO_DE nome_variavel_int  */
#line 481 "src/parser.y"
                                     {
>>>>>>> main
        // $2 é o nome da pilha (const char*)
        const char* nome_pilha = (yyvsp[0].texto);
        Symbol* sym = get_symbol(nome_pilha);

        // Valida se a variável existe e é uma pilha
        if (!sym || sym->type != INT_VAR) {
            printf("Variável de pilha inválida ou não declarada: %s\n", nome_pilha);
            printf("Regra valor->tamanho\n");
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0); // Retorna 0 em caso de erro
        } else {
            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_size");

            // 2. Gera a chamada ao runtime para obter o tamanho da pilha
            (yyval.llmValueRef) = gerar_obter_tamanho_pilha(pilha_ptr);
        }
    }
<<<<<<< HEAD
#line 1913 "src/parser.tab.c"
    break;

  case 57: /* valor: texto  */
#line 510 "src/parser.y"
            {
=======
#line 1906 "src/parser.tab.c"
    break;

  case 59: /* valor: nome_variavel_int  */
#line 498 "src/parser.y"
                        {
>>>>>>> main
        Symbol *sym = get_symbol((yyvsp[0].texto));
        if (!sym || sym->type != INT_VAR) {
            printf("Variável de pilha inválida ou não declarada: %s\n", (yyvsp[0].texto));
            printf("Regra valor->texto\n");
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_var");
            // 2. Gera a chamada ao runtime para obter o valor do topo
            (yyval.llmValueRef) = gerar_peek_pilha(pilha_ptr);
        }
    }
<<<<<<< HEAD
#line 1931 "src/parser.tab.c"
    break;

  case 58: /* expressao: valor  */
#line 526 "src/parser.y"
          {
        (yyval.llmValueRef) = (yyvsp[0].llmValueRef); // valor já retorna LLVMValueRef
    }
#line 1939 "src/parser.tab.c"
    break;

  case 59: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 529 "src/parser.y"
=======
#line 1923 "src/parser.tab.c"
    break;

  case 60: /* expressao: valor  */
#line 513 "src/parser.y"
          {
        (yyval.llmValueRef) = (yyvsp[0].llmValueRef); // valor já retorna LLVMValueRef
    }
#line 1931 "src/parser.tab.c"
    break;

  case 61: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 516 "src/parser.y"
>>>>>>> main
                                     {
        if (DEBUG_BISON) printf("Expressão de soma\n");
        (yyval.llmValueRef) = LLVMBuildAdd(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "addtmp");
    }
<<<<<<< HEAD
#line 1948 "src/parser.tab.c"
    break;

  case 60: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 533 "src/parser.y"
=======
#line 1940 "src/parser.tab.c"
    break;

  case 62: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 520 "src/parser.y"
>>>>>>> main
                                        {
        if (DEBUG_BISON) printf("Expressão de subtração\n");
        (yyval.llmValueRef) = LLVMBuildSub(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "subtmp");
    }
<<<<<<< HEAD
#line 1957 "src/parser.tab.c"
    break;

  case 61: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 537 "src/parser.y"
=======
#line 1949 "src/parser.tab.c"
    break;

  case 63: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 524 "src/parser.y"
>>>>>>> main
                                           {
        if (DEBUG_BISON) printf("Expressão de multiplicação\n");
        (yyval.llmValueRef) = LLVMBuildMul(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "multmp");
    }
<<<<<<< HEAD
#line 1966 "src/parser.tab.c"
    break;

  case 62: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 541 "src/parser.y"
=======
#line 1958 "src/parser.tab.c"
    break;

  case 64: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 528 "src/parser.y"
>>>>>>> main
                                       {
        if (DEBUG_BISON) printf("Expressão de divisão\n");

        // Divisão por zero em tempo de compilação não pode ser detectada aqui
        (yyval.llmValueRef) = LLVMBuildSDiv(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "divtmp");
    }
<<<<<<< HEAD
#line 1977 "src/parser.tab.c"
    break;

  case 63: /* if_sentenca: SE condicao VIRGULA personagem SERA expressao  */
#line 550 "src/parser.y"
=======
#line 1969 "src/parser.tab.c"
    break;

  case 65: /* if_sentenca: SE condicao VIRGULA personagem SERA expressao  */
#line 537 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2020 "src/parser.tab.c"
    break;

  case 64: /* if_sentenca: SE condicao VIRGULA personagem IF_MOSTRA_VALOR  */
#line 588 "src/parser.y"
=======
#line 2012 "src/parser.tab.c"
    break;

  case 66: /* if_sentenca: SE condicao VIRGULA personagem IF_MOSTRA_VALOR  */
#line 575 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2056 "src/parser.tab.c"
    break;

  case 65: /* if_sentenca: SE condicao VIRGULA personagem IF_LE_VALOR  */
#line 619 "src/parser.y"
=======
#line 2048 "src/parser.tab.c"
    break;

  case 67: /* if_sentenca: SE condicao VIRGULA personagem IF_LE_VALOR  */
#line 606 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2085 "src/parser.tab.c"
    break;

  case 66: /* $@1: %empty  */
#line 646 "src/parser.y"
=======
#line 2077 "src/parser.tab.c"
    break;

  case 68: /* $@1: %empty  */
#line 633 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2105 "src/parser.tab.c"
    break;

  case 67: /* if_bloco: SE condicao VIRGULA texto INICIO $@1 bloco ENDIF  */
#line 662 "src/parser.y"
=======
#line 2097 "src/parser.tab.c"
    break;

  case 69: /* if_bloco: SE condicao VIRGULA texto INICIO $@1 bloco ENDIF  */
#line 649 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2129 "src/parser.tab.c"
    break;

  case 68: /* $@2: %empty  */
#line 685 "src/parser.y"
=======
#line 2121 "src/parser.tab.c"
    break;

  case 70: /* $@2: %empty  */
#line 672 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2152 "src/parser.tab.c"
    break;

  case 69: /* $@3: %empty  */
#line 704 "src/parser.y"
=======
#line 2144 "src/parser.tab.c"
    break;

  case 71: /* $@3: %empty  */
#line 691 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2169 "src/parser.tab.c"
    break;

  case 70: /* while: ENQUANTO_COMECO $@2 condicao VIRGULA texto INICIO $@3 bloco texto ENQUANTO_FIM FIM  */
#line 717 "src/parser.y"
=======
#line 2161 "src/parser.tab.c"
    break;

  case 72: /* while: ENQUANTO_COMECO $@2 condicao VIRGULA texto INICIO $@3 bloco texto ENQUANTO_FIM FIM  */
#line 704 "src/parser.y"
>>>>>>> main
    {
        // --- Ação de Saída do While ---
        // 1. Pega a estrutura de controle e remove da pilha.
        ControleFluxo controle = pilha_pop(&pilhaControleFluxo);

        // 2. No final do corpo do laço, cria um pulo de volta para o teste da condição.
        LLVMBuildBr(builder, controle.else_block);

        // 3. Move o builder para o bloco de continuação.
        LLVMPositionBuilderAtEnd(builder, controle.merge_block);
    }
<<<<<<< HEAD
#line 2185 "src/parser.tab.c"
    break;

  case 71: /* $@4: %empty  */
#line 729 "src/parser.y"
=======
#line 2177 "src/parser.tab.c"
    break;

  case 73: /* $@4: %empty  */
#line 716 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2204 "src/parser.tab.c"
    break;

  case 72: /* while: FACA VIRGULA texto INICIO $@4 bloco ENQUANTO_COMECO condicao VIRGULA texto FIM  */
#line 744 "src/parser.y"
=======
#line 2196 "src/parser.tab.c"
    break;

  case 74: /* while: FACA VIRGULA texto INICIO $@4 bloco ENQUANTO_COMECO condicao VIRGULA texto FIM  */
#line 731 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2231 "src/parser.tab.c"
    break;

  case 73: /* condicao: expressao FOR MAIOR expressao  */
#line 768 "src/parser.y"
                                  {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpgt");
        }
#line 2239 "src/parser.tab.c"
    break;

  case 74: /* condicao: expressao FOR MAIOR_IGUAL expressao  */
#line 771 "src/parser.y"
                                          {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpge");
        }
#line 2247 "src/parser.tab.c"
    break;

  case 75: /* condicao: expressao FOR MENOR expressao  */
#line 774 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmplt");
        }
#line 2255 "src/parser.tab.c"
    break;

  case 76: /* condicao: expressao FOR MENOR_IGUAL expressao  */
#line 777 "src/parser.y"
                                          {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmple");
        }
#line 2263 "src/parser.tab.c"
    break;

  case 77: /* condicao: expressao FOR IGUAL expressao  */
#line 780 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpeq");
        }
#line 2271 "src/parser.tab.c"
    break;

  case 78: /* condicao: expressao NAO FOR MENOR expressao  */
#line 783 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpnlt");
        }
#line 2279 "src/parser.tab.c"
    break;

  case 79: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 786 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpngt");
        }
#line 2287 "src/parser.tab.c"
    break;

  case 80: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 789 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpneq");
    }
#line 2295 "src/parser.tab.c"
    break;

  case 81: /* condicao: texto  */
#line 792 "src/parser.y"
            {
        Symbol* sym = get_symbol((yyvsp[0].texto));
        if (sym && sym->type == BOOL_VAR) {
            // Chama a função para gerar a instrução 'load'.
            // $$ agora contém o valor i1 (true/false) da variável.
            (yyval.llmValueRef) = gerar_get_booleano(sym->llvm_ref);
        } else {
            yyerror("Variável de condição não é um booleano válido.");
        }
    }
#line 2310 "src/parser.tab.c"
    break;

  case 82: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 805 "src/parser.y"
=======
#line 2223 "src/parser.tab.c"
    break;

  case 75: /* condicao: expressao FOR MAIOR expressao  */
#line 755 "src/parser.y"
                                      {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpgt");
        }
#line 2231 "src/parser.tab.c"
    break;

  case 76: /* condicao: expressao FOR MAIOR_IGUAL expressao  */
#line 758 "src/parser.y"
                                          {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpge");
        }
#line 2239 "src/parser.tab.c"
    break;

  case 77: /* condicao: expressao FOR MENOR expressao  */
#line 761 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmplt");
        }
#line 2247 "src/parser.tab.c"
    break;

  case 78: /* condicao: expressao FOR MENOR_IGUAL expressao  */
#line 764 "src/parser.y"
                                          {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmple");
        }
#line 2255 "src/parser.tab.c"
    break;

  case 79: /* condicao: expressao FOR IGUAL expressao  */
#line 767 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpeq");
        }
#line 2263 "src/parser.tab.c"
    break;

  case 80: /* condicao: expressao NAO FOR MENOR expressao  */
#line 770 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpnlt");
        }
#line 2271 "src/parser.tab.c"
    break;

  case 81: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 773 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpngt");
        }
#line 2279 "src/parser.tab.c"
    break;

  case 82: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 776 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpneq");
        }
#line 2287 "src/parser.tab.c"
    break;

  case 83: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 782 "src/parser.y"
>>>>>>> main
                                  {
        if (DEBUG_BISON) {
        }
        gerar_print_string(cenarioAtual);
        atualiza_personagemVoce();
    }
<<<<<<< HEAD
#line 2321 "src/parser.tab.c"
    break;

  case 83: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 811 "src/parser.y"
=======
#line 2299 "src/parser.tab.c"
    break;

  case 84: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 789 "src/parser.y"
>>>>>>> main
                                    {
        if (DEBUG_BISON) {
            printf("if sentença\n");
        }
        atualiza_personagemVoce();
    }
<<<<<<< HEAD
#line 2332 "src/parser.tab.c"
    break;

  case 84: /* dialogo: inicioDialogo texto FIM  */
#line 817 "src/parser.y"
                              {
=======
#line 2310 "src/parser.tab.c"
    break;

  case 85: /* dialogo: inicioDialogo nome_personagem FIM  */
#line 795 "src/parser.y"
                                        {
>>>>>>> main
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
<<<<<<< HEAD
#line 2352 "src/parser.tab.c"
    break;

  case 85: /* dialogo: inicioDialogo texto INTERROGACAO  */
#line 832 "src/parser.y"
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
=======
#line 2330 "src/parser.tab.c"
    break;

  case 86: /* dialogo: inicioDialogo nome_personagem VIRGULA TU EH expressao FIM  */
#line 810 "src/parser.y"
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
>>>>>>> main
        }
        atualiza_personagemVoce();
    }
<<<<<<< HEAD
#line 2372 "src/parser.tab.c"
    break;

  case 86: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 847 "src/parser.y"
                                                      {
=======
#line 2358 "src/parser.tab.c"
    break;

  case 87: /* dialogo: inicioDialogo nome_personagem VIRGULA TU EH adjetivos FIM  */
#line 833 "src/parser.y"
                                                                {
>>>>>>> main
        personagemDialogo = strdup((yyvsp[-5].texto));


        if (DEBUG_BISON) {
            // printf("Valor do personagem antes do diálogo: %d\n", get_int_value(personagemDialogo));
        }

        // LLVM: gerar incremento personagem = personagem + $6

        Symbol *sym = get_symbol(personagemDialogo);
        if (!sym || sym->type != INT_VAR) {
            yyerror("Variável de pilha inválida ou não declarada");
            printf("Regra dialogos->adjetivos\n");
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
<<<<<<< HEAD
#line 2417 "src/parser.tab.c"
    break;

  case 87: /* dialogo: inicioDialogo texto VIRGULA TU EH expressao FIM  */
#line 887 "src/parser.y"
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
#line 2445 "src/parser.tab.c"
    break;

  case 88: /* dialogo: inicioDialogo texto VIRGULA MOSTRA_VALOR FIM  */
#line 910 "src/parser.y"
                                                   {
=======
#line 2402 "src/parser.tab.c"
    break;

  case 88: /* dialogo: inicioDialogo nome_personagem VIRGULA MOSTRA_VALOR FIM  */
#line 873 "src/parser.y"
                                                             {
>>>>>>> main
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
<<<<<<< HEAD
#line 2470 "src/parser.tab.c"
    break;

  case 89: /* dialogo: inicioDialogo texto VIRGULA LE_VALOR FIM  */
#line 930 "src/parser.y"
                                               {
=======
#line 2427 "src/parser.tab.c"
    break;

  case 89: /* dialogo: inicioDialogo nome_personagem VIRGULA LE_VALOR FIM  */
#line 893 "src/parser.y"
                                                         {
>>>>>>> main
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
<<<<<<< HEAD
#line 2491 "src/parser.tab.c"
    break;

  case 90: /* dialogo: inicioDialogo texto VIRGULA GUARDE texto INTERIOR FIM  */
#line 946 "src/parser.y"
                                                            {
=======
#line 2448 "src/parser.tab.c"
    break;

  case 90: /* dialogo: inicioDialogo nome_personagem VIRGULA GUARDE texto INTERIOR FIM  */
#line 909 "src/parser.y"
                                                                      {
>>>>>>> main
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
<<<<<<< HEAD
#line 2511 "src/parser.tab.c"
    break;

  case 91: /* dialogo: inicioDialogo texto VIRGULA LEMBRE texto FIM  */
#line 961 "src/parser.y"
                                                   {
=======
#line 2468 "src/parser.tab.c"
    break;

  case 91: /* dialogo: inicioDialogo nome_personagem VIRGULA LEMBRE texto FIM  */
#line 924 "src/parser.y"
                                                             {
>>>>>>> main
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
<<<<<<< HEAD
#line 2528 "src/parser.tab.c"
    break;

  case 92: /* inicioDialogo: texto INICIO  */
#line 976 "src/parser.y"
=======
#line 2485 "src/parser.tab.c"
    break;

  case 92: /* inicioDialogo: texto INICIO  */
#line 939 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2564 "src/parser.tab.c"
    break;

  case 93: /* ato: ATO  */
#line 1009 "src/parser.y"
=======
#line 2521 "src/parser.tab.c"
    break;

  case 93: /* ato: ATO  */
#line 972 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2581 "src/parser.tab.c"
    break;

  case 94: /* cena: CENA  */
#line 1023 "src/parser.y"
=======
#line 2538 "src/parser.tab.c"
    break;

  case 94: /* cena: CENA  */
#line 986 "src/parser.y"
>>>>>>> main
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
<<<<<<< HEAD
#line 2598 "src/parser.tab.c"
    break;


#line 2602 "src/parser.tab.c"
=======
#line 2555 "src/parser.tab.c"
    break;

  case 95: /* nome_variavel_int: texto  */
#line 1000 "src/parser.y"
                    { (yyval.texto) = (yyvsp[0].texto); }
#line 2561 "src/parser.tab.c"
    break;

  case 96: /* nome_cenario: texto  */
#line 1004 "src/parser.y"
                    { (yyval.texto) = (yyvsp[0].texto); }
#line 2567 "src/parser.tab.c"
    break;

  case 97: /* nome_questionamento: texto  */
#line 1008 "src/parser.y"
                    { (yyval.texto) = (yyvsp[0].texto); }
#line 2573 "src/parser.tab.c"
    break;

  case 98: /* nome_personagem: texto  */
#line 1012 "src/parser.y"
                    { (yyval.texto) = (yyvsp[0].texto); }
#line 2579 "src/parser.tab.c"
    break;

  case 99: /* valor_string: texto  */
#line 1016 "src/parser.y"
                    { (yyval.texto) = (yyvsp[0].texto); }
#line 2585 "src/parser.tab.c"
    break;


#line 2589 "src/parser.tab.c"
>>>>>>> main

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

<<<<<<< HEAD
#line 1037 "src/parser.y"
=======
#line 1020 "src/parser.y"
>>>>>>> main


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
