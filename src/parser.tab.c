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
    char* personagemVoce = NULL; // guarda o valor do ultimo personagem que falou
    int result = 0; // guarda o resultado do if
    // TODO: FAZER OS YYABORTS ENCERRAREM O PROGRAMA E NÃO APENAS O PARSER

    void atualiza_personagemVoce(){
        if (personagemVoce != personagemQueFala) {
            if (DEBUG_BISON) {
                printf("Atualizando personagemVoce: %s\n", personagemQueFala);
            }
            personagemVoce = personagemQueFala;
        }
    }

#line 108 "src/parser.tab.c"

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
<<<<<<< HEAD
  YYSYMBOL_VOCE = 35,                      /* VOCE  */
  YYSYMBOL_TU = 36,                        /* TU  */
  YYSYMBOL_EH = 37,                        /* EH  */
  YYSYMBOL_E = 38,                         /* E  */
  YYSYMBOL_ENTRE = 39,                     /* ENTRE  */
  YYSYMBOL_ARTIGO = 40,                    /* ARTIGO  */
  YYSYMBOL_MESMO = 41,                     /* MESMO  */
  YYSYMBOL_NUMERO = 42,                    /* NUMERO  */
  YYSYMBOL_ADICIONAR_CENARIO = 43,         /* ADICIONAR_CENARIO  */
  YYSYMBOL_SUBSTITUIR_CENARIO = 44,        /* SUBSTITUIR_CENARIO  */
  YYSYMBOL_POR = 45,                       /* POR  */
  YYSYMBOL_NO_CENARIO = 46,                /* NO_CENARIO  */
  YYSYMBOL_MOSTRAR_CENARIO = 47,           /* MOSTRAR_CENARIO  */
  YYSYMBOL_MOSTRA_VALOR = 48,              /* MOSTRA_VALOR  */
  YYSYMBOL_LE_VALOR = 49,                  /* LE_VALOR  */
  YYSYMBOL_ATO = 50,                       /* ATO  */
  YYSYMBOL_CENA = 51,                      /* CENA  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_programa = 53,                  /* programa  */
  YYSYMBOL_bloco = 54,                     /* bloco  */
  YYSYMBOL_instrucao = 55,                 /* instrucao  */
  YYSYMBOL_declaracaoCenario = 56,         /* declaracaoCenario  */
  YYSYMBOL_concatenarCenario = 57,         /* concatenarCenario  */
  YYSYMBOL_substituiCenario = 58,          /* substituiCenario  */
  YYSYMBOL_trocarCenario = 59,             /* trocarCenario  */
  YYSYMBOL_declaracaoQuestionamento = 60,  /* declaracaoQuestionamento  */
  YYSYMBOL_texto = 61,                     /* texto  */
  YYSYMBOL_palavra = 62,                   /* palavra  */
  YYSYMBOL_adjetivos = 63,                 /* adjetivos  */
  YYSYMBOL_declaracao = 64,                /* declaracao  */
  YYSYMBOL_declaracaoInicio = 65,          /* declaracaoInicio  */
  YYSYMBOL_personagensEntrando = 66,       /* personagensEntrando  */
  YYSYMBOL_personagensSaindo = 67,         /* personagensSaindo  */
  YYSYMBOL_alteracaoElenco = 68,           /* alteracaoElenco  */
  YYSYMBOL_valor = 69,                     /* valor  */
  YYSYMBOL_expressao = 70,                 /* expressao  */
  YYSYMBOL_if_sentenca = 71,               /* if_sentenca  */
  YYSYMBOL_if_bloco = 72,                  /* if_bloco  */
  YYSYMBOL_while_aux = 73,                 /* while_aux  */
  YYSYMBOL_while = 74,                     /* while  */
  YYSYMBOL_75_1 = 75,                      /* $@1  */
  YYSYMBOL_76_2 = 76,                      /* $@2  */
  YYSYMBOL_condicao = 77,                  /* condicao  */
  YYSYMBOL_dialogo = 78,                   /* dialogo  */
  YYSYMBOL_inicioDialogo = 79,             /* inicioDialogo  */
  YYSYMBOL_ato = 80,                       /* ato  */
  YYSYMBOL_cena = 81                       /* cena  */
=======
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
  YYSYMBOL_GUARDE = 49,                    /* GUARDE  */
  YYSYMBOL_INTERIOR = 50,                  /* INTERIOR  */
  YYSYMBOL_LEMBRE = 51,                    /* LEMBRE  */
  YYSYMBOL_ATO = 52,                       /* ATO  */
  YYSYMBOL_CENA = 53,                      /* CENA  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_programa = 55,                  /* programa  */
  YYSYMBOL_bloco = 56,                     /* bloco  */
  YYSYMBOL_instrucao = 57,                 /* instrucao  */
  YYSYMBOL_declaracaoCenario = 58,         /* declaracaoCenario  */
  YYSYMBOL_concatenarCenario = 59,         /* concatenarCenario  */
  YYSYMBOL_substituiCenario = 60,          /* substituiCenario  */
  YYSYMBOL_trocarCenario = 61,             /* trocarCenario  */
  YYSYMBOL_declaracaoQuestionamento = 62,  /* declaracaoQuestionamento  */
  YYSYMBOL_texto = 63,                     /* texto  */
  YYSYMBOL_palavra = 64,                   /* palavra  */
  YYSYMBOL_adjetivos = 65,                 /* adjetivos  */
  YYSYMBOL_declaracao = 66,                /* declaracao  */
  YYSYMBOL_declaracaoInicio = 67,          /* declaracaoInicio  */
  YYSYMBOL_personagensEntrando = 68,       /* personagensEntrando  */
  YYSYMBOL_personagensSaindo = 69,         /* personagensSaindo  */
  YYSYMBOL_alteracaoElenco = 70,           /* alteracaoElenco  */
  YYSYMBOL_valor = 71,                     /* valor  */
  YYSYMBOL_expressao = 72,                 /* expressao  */
  YYSYMBOL_if_sentenca = 73,               /* if_sentenca  */
  YYSYMBOL_if_bloco = 74,                  /* if_bloco  */
  YYSYMBOL_while_aux = 75,                 /* while_aux  */
  YYSYMBOL_while = 76,                     /* while  */
  YYSYMBOL_77_1 = 77,                      /* $@1  */
  YYSYMBOL_78_2 = 78,                      /* $@2  */
  YYSYMBOL_condicao = 79,                  /* condicao  */
  YYSYMBOL_dialogo = 80,                   /* dialogo  */
  YYSYMBOL_inicioDialogo = 81,             /* inicioDialogo  */
  YYSYMBOL_ato = 82,                       /* ato  */
  YYSYMBOL_cena = 83                       /* cena  */
>>>>>>> pilha_correta
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
#define YYLAST   291

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306
=======
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308
>>>>>>> pilha_correta


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
<<<<<<< HEAD
      45,    46,    47,    48,    49,    50,    51
=======
      45,    46,    47,    48,    49,    50,    51,    52,    53
>>>>>>> pilha_correta
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
<<<<<<< HEAD
       0,    73,    73,    74,    78,    79,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     103,   118,   138,   157,   176,   189,   202,   218,   221,   227,
     237,   241,   244,   247,   250,   256,   262,   265,   270,   277,
     288,   299,   310,   322,   333,   344,   357,   370,   383,   392,
     398,   415,   432,   449,   464,   467,   471,   475,   479,   488,
     497,   504,   522,   521,   535,   534,   563,   566,   569,   572,
     575,   578,   584,   591,   597,   612,   645,   681,   701,   721,
     754,   768
=======
       0,    64,    64,    65,    69,    70,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      94,   109,   129,   148,   167,   180,   193,   209,   212,   218,
     228,   232,   235,   238,   241,   247,   253,   256,   261,   268,
     279,   290,   301,   313,   324,   335,   348,   361,   374,   383,
     389,   406,   423,   438,   441,   445,   449,   453,   462,   471,
     478,   496,   495,   509,   508,   537,   540,   543,   546,   549,
     552,   558,   564,   569,   583,   614,   646,   666,   681,   696,
     711,   744,   758
>>>>>>> pilha_correta
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
<<<<<<< HEAD
  "ADJETIVO_POSITIVO", "ADJETIVO_NEGATIVO", "VOCE", "TU", "EH", "E",
  "ENTRE", "ARTIGO", "MESMO", "NUMERO", "ADICIONAR_CENARIO",
  "SUBSTITUIR_CENARIO", "POR", "NO_CENARIO", "MOSTRAR_CENARIO",
  "MOSTRA_VALOR", "LE_VALOR", "ATO", "CENA", "$accept", "programa",
=======
  "ADJETIVO_POSITIVO", "ADJETIVO_NEGATIVO", "TU", "EH", "E", "ENTRE",
  "ARTIGO", "MESMO", "NUMERO", "ADICIONAR_CENARIO", "SUBSTITUIR_CENARIO",
  "POR", "NO_CENARIO", "MOSTRAR_CENARIO", "MOSTRA_VALOR", "LE_VALOR",
  "GUARDE", "INTERIOR", "LEMBRE", "ATO", "CENA", "$accept", "programa",
>>>>>>> pilha_correta
  "bloco", "instrucao", "declaracaoCenario", "concatenarCenario",
  "substituiCenario", "trocarCenario", "declaracaoQuestionamento", "texto",
  "palavra", "adjetivos", "declaracao", "declaracaoInicio",
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

<<<<<<< HEAD
#define YYPACT_NINF (-111)
=======
#define YYPACT_NINF (-117)
>>>>>>> pilha_correta

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-34)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
    -111,   157,  -111,    -5,  -111,    53,   205,    -2,  -111,    29,
      -2,  -111,  -111,     2,  -111,  -111,  -111,  -111,  -111,  -111,
      -7,  -111,  -111,    -2,    11,  -111,  -111,  -111,  -111,  -111,
      27,  -111,  -111,    -2,    53,  -111,  -111,    13,   223,  -111,
      77,  -111,    60,    34,    -2,    -2,    71,   -21,    -2,   -28,
    -111,  -111,     9,  -111,  -111,  -111,    41,    -2,    -2,    53,
      50,  -111,    79,    78,   -19,    76,  -111,    86,    93,    96,
     102,   107,   279,    -2,    77,   125,    77,   244,   106,    -2,
     152,    -2,   127,   147,  -111,    77,    77,   146,    -2,  -111,
     100,  -111,  -111,    -2,   111,   111,   111,   111,   282,    53,
      53,    53,   213,  -111,    -2,    -2,  -111,  -111,    49,  -111,
     215,  -111,  -111,    -2,   156,   143,   159,   162,     2,    26,
     165,   166,   172,   175,    53,    53,    53,  -111,  -111,  -111,
       2,   224,   245,  -111,    77,    77,  -111,   191,   237,  -111,
     198,  -111,  -111,   173,  -111,   111,   111,   111,   111,  -111,
    -111,  -111,    94,  -111,   135,  -111,  -111,   158,   204,    53,
       2,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,   197,     2,    -2,   187,   183,   216,  -111,  -111
=======
    -117,   163,  -117,   -23,  -117,    80,   169,    -9,  -117,    18,
      -9,  -117,  -117,   185,  -117,  -117,  -117,  -117,  -117,  -117,
     130,  -117,  -117,    -9,    -3,  -117,  -117,  -117,  -117,  -117,
      -7,  -117,  -117,    -9,    80,  -117,     5,   267,  -117,   -28,
    -117,     0,    20,    -9,    -9,    37,    16,    -9,   240,  -117,
    -117,     6,  -117,  -117,  -117,   116,    -9,    -9,    80,    26,
    -117,   210,    44,    60,    78,  -117,    30,    72,    85,    88,
     117,   282,    -9,   -28,    69,   -28,   109,   111,    -9,   150,
      -9,   133,   142,  -117,   -28,   -28,   138,    -9,  -117,   215,
    -117,  -117,    -9,    48,    48,    48,    48,   285,    80,    80,
      80,    -8,  -117,    -9,    -9,  -117,  -117,    58,  -117,     9,
    -117,  -117,    -9,   180,   106,   147,   149,    -9,    -9,   185,
      63,   139,   143,   160,   164,    80,    80,    80,  -117,  -117,
    -117,   185,    92,    31,  -117,   -28,   -28,  -117,   175,   161,
    -117,   191,  -117,  -117,   203,   213,   217,  -117,    48,    48,
      48,    48,  -117,  -117,  -117,    55,  -117,   244,  -117,  -117,
     242,   184,   206,  -117,    80,   185,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,   177,   185,
      -9,   119,   216,   211,  -117,  -117
>>>>>>> pilha_correta
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
<<<<<<< HEAD
       2,     0,     1,     0,    61,     0,     0,     0,    30,     0,
       0,    80,    81,     3,     4,    10,    12,    13,    14,    11,
      40,    27,     9,     0,    19,    15,    16,    17,    18,     8,
       0,     6,     7,     0,     0,    51,    52,     0,     0,    49,
      53,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       5,    79,    26,    39,    28,    29,     0,     0,     0,     0,
       0,    72,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,    43,     0,    40,     0,     0,     0,
       0,     0,     0,     0,    38,    41,    42,     0,     0,    74,
       0,    73,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,    46,    48,     0,    21,
       0,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
       0,    49,    27,    59,    44,    45,    20,     0,     0,    23,
       0,    77,    78,     0,    62,     0,     0,     0,     0,    70,
      69,    71,     0,    22,    30,    31,    32,     0,     0,     0,
       0,    55,    56,    58,    57,    60,    76,    36,    34,    35,
      37,    75,     0,     0,     0,    40,     0,     0,    65,    63
=======
       2,     0,     1,     0,    60,     0,     0,     0,    30,     0,
       0,    81,    82,     3,     4,    10,    12,    13,    14,    11,
      40,    27,     9,     0,    19,    15,    16,    17,    18,     8,
       0,     6,     7,     0,     0,    51,     0,     0,    49,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     5,
      80,    26,    39,    28,    29,     0,     0,     0,     0,     0,
      71,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,    43,     0,    40,     0,     0,     0,     0,
       0,     0,     0,    38,    41,    42,     0,     0,    73,     0,
      72,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,    46,    48,     0,    21,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,     0,    49,    27,    58,    44,    45,    20,     0,     0,
      23,     0,    76,    77,     0,     0,     0,    61,     0,     0,
       0,     0,    69,    68,    70,     0,    22,    30,    31,    32,
       0,     0,     0,    79,     0,     0,    54,    55,    57,    56,
      59,    75,    36,    34,    35,    37,    74,    78,     0,     0,
       0,    40,     0,     0,    64,    62
>>>>>>> pilha_correta
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
<<<<<<< HEAD
    -111,  -111,  -110,   -12,  -111,  -111,  -111,  -111,  -111,    -1,
      20,  -111,  -111,  -111,   206,  -111,  -111,    19,   -63,   222,
    -111,  -111,  -111,  -111,  -111,   -32,  -111,  -111,  -111,  -111
=======
    -117,  -117,  -116,   -12,  -117,  -117,  -117,  -117,  -117,    -1,
      74,  -117,  -117,  -117,   196,  -117,  -117,   -76,   -63,   222,
    -117,  -117,  -117,  -117,  -117,   -32,  -117,  -117,  -117,  -117
>>>>>>> pilha_correta
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
<<<<<<< HEAD
       0,     1,    13,    14,    15,    16,    17,    18,    19,    40,
      21,   157,    22,    23,    24,    75,    25,    41,    42,    26,
      27,    34,    28,   160,   118,    43,    29,    30,    31,    32
=======
       0,     1,    13,    14,    15,    16,    17,    18,    19,    39,
      21,   160,    22,    23,    24,    74,    25,    40,    41,    26,
      27,    34,    28,   165,   119,    42,    29,    30,    31,    32
>>>>>>> pilha_correta
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
<<<<<<< HEAD
      20,    50,    65,    92,     8,     3,    47,     4,   143,    49,
      79,     8,    20,     8,    54,    51,     5,    81,    52,    82,
     152,    54,    56,    54,    53,     8,    33,    87,     6,    62,
       8,     7,    64,    83,     8,    54,   127,   128,   129,   133,
      55,    59,    57,    74,    76,     9,    10,    80,   144,    58,
     173,    48,    11,    12,    66,    60,    85,    86,     8,     8,
      55,   149,   150,   151,    84,    73,    35,    55,    54,    55,
      71,    72,   102,     8,    61,   133,    55,   158,   108,   136,
     110,     8,    55,    54,    55,     8,    78,   114,    36,    37,
      88,    54,   119,    38,    55,    39,    55,     3,   165,     4,
      55,    91,    89,   134,   135,    55,    55,    93,     5,     8,
      90,     8,   138,   120,   121,   122,   123,    20,    98,    54,
       6,    54,   132,     7,    35,    94,     8,   172,    55,    20,
      55,    50,    95,   107,    55,    96,   115,     9,    10,    55,
      50,    97,    20,     8,    11,    12,    36,    37,   116,   117,
     111,    20,   103,    39,    55,    55,   104,     2,   132,    20,
       3,    50,     4,   105,   161,   162,   163,   164,   -33,   -33,
     112,     5,   175,   176,   -33,   109,     3,   113,   159,   139,
     140,   166,   141,     6,     8,   142,     7,     5,     8,     8,
     167,   168,   169,   177,    54,    55,    55,   170,    54,     6,
       9,    10,     7,   145,   146,     8,   178,    11,    12,    51,
     147,    35,    52,   148,   153,     8,     9,    10,    53,     8,
      44,    45,    46,    11,    12,    54,    35,   171,   174,    54,
     154,   155,   156,    36,    37,   130,     0,   -28,    38,   179,
      39,    67,    68,    69,    70,     8,   -28,     8,    36,    37,
      35,    77,    63,    38,     0,   131,   -28,    54,   -29,   -28,
     -28,   137,     0,     0,   -28,     0,   -28,   -29,     0,     8,
       0,   106,    36,    37,     0,    57,     0,    38,     0,   131,
     -29,   -29,    58,     0,     0,   -29,    99,   100,   101,   124,
     125,   126
=======
      20,    49,    64,   146,     8,    35,    46,    58,    33,    48,
      70,    71,    20,    53,   131,   155,    81,   121,   122,   123,
     124,    59,    55,     8,     8,     8,    86,    36,    56,    61,
      82,    37,    63,   132,    57,   128,   129,   130,   134,    60,
      47,     8,    73,    75,   -29,    65,    79,    78,     8,   179,
      53,    72,    77,   -29,   138,    84,    85,    53,     3,   170,
       4,    35,   152,   153,   154,    87,   -29,    90,    93,     5,
     -29,   101,   166,   167,   168,   169,   134,   107,   161,   109,
       8,     6,    91,    36,     7,   147,   113,     8,   137,    38,
       8,   120,     8,    35,    54,     8,   102,     9,    10,    53,
     103,    53,   135,   136,    53,   -28,   104,    11,    12,    92,
      94,   139,     8,    54,   -28,    36,   144,   145,    20,    37,
      54,    38,    54,    95,   -28,   183,    96,   -28,    97,    54,
      20,   -28,   178,   -28,    49,    54,   105,    54,   106,    83,
      56,    50,   141,    49,    51,    20,    57,    54,     8,    54,
      52,     8,    50,    54,    20,    51,   110,    53,    54,    54,
      53,    52,     8,     2,    20,   111,     3,    49,     4,   112,
     142,    53,   143,   108,    35,   133,   148,     5,   181,   182,
     149,    54,     8,    54,    43,    44,    45,    54,     3,     6,
       4,    53,     7,     8,    54,     8,    36,   150,   156,     5,
      37,   151,   132,   140,    35,     9,    10,   176,   180,    54,
      54,     6,     8,   133,     7,    11,    12,     8,    54,    54,
       3,    53,   164,   157,   158,   159,    36,     9,    10,   177,
      37,     5,    38,    88,   185,     8,   163,    11,    12,   184,
      76,    89,     8,     6,    53,     8,     7,     0,     8,     8,
     114,    53,    62,   162,    53,    54,    54,    53,     0,     9,
      10,     0,   115,   116,   117,   171,   118,     0,     0,    11,
      12,     0,     8,     0,   172,   173,   174,   -33,   -33,     0,
     175,    53,   -33,     0,    80,    66,    67,    68,    69,    98,
      99,   100,   125,   126,   127
>>>>>>> pilha_correta
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
       1,    13,    34,    22,    32,     3,     7,     5,   118,    10,
      31,    32,    13,    32,    42,    22,    14,    45,    25,    10,
     130,    42,    23,    42,    31,    32,    31,    59,    26,    30,
      32,    29,    33,    24,    32,    42,    99,   100,   101,   102,
      20,    14,    31,    44,    45,    43,    44,    48,    22,    38,
     160,    22,    50,    51,    41,    28,    57,    58,    32,    32,
      40,   124,   125,   126,    23,    31,    13,    47,    42,    49,
      10,    11,    73,    32,    47,   138,    56,   140,    79,    30,
      81,    32,    62,    42,    64,    32,    15,    88,    35,    36,
      40,    42,    93,    40,    74,    42,    76,     3,     4,     5,
      80,    23,    23,   104,   105,    85,    86,    31,    14,    32,
      31,    32,   113,    94,    95,    96,    97,   118,    11,    42,
      26,    42,   102,    29,    13,    39,    32,   159,   108,   130,
     110,   143,    39,    27,   114,    39,    36,    43,    44,   119,
     152,    39,   143,    32,    50,    51,    35,    36,    48,    49,
      23,   152,    27,    42,   134,   135,    31,     0,   138,   160,
       3,   173,     5,    38,   145,   146,   147,   148,    33,    34,
      23,    14,   173,   174,    39,    23,     3,    31,     5,    23,
      37,    23,    23,    26,    32,    23,    29,    14,    32,    32,
      32,    33,    34,     6,    42,   175,   176,    39,    42,    26,
      43,    44,    29,    38,    38,    32,    23,    50,    51,    22,
      38,    13,    25,    38,    23,    32,    43,    44,    31,    32,
      15,    16,    17,    50,    51,    42,    13,    23,    31,    42,
      32,    33,    34,    35,    36,    22,    -1,    13,    40,    23,
      42,    18,    19,    20,    21,    32,    22,    32,    35,    36,
      13,    45,    30,    40,    -1,    42,    32,    42,    13,    35,
      36,    46,    -1,    -1,    40,    -1,    42,    22,    -1,    32,
      -1,    27,    35,    36,    -1,    31,    -1,    40,    -1,    42,
      35,    36,    38,    -1,    -1,    40,     7,     8,     9,     7,
       8,     9
=======
       1,    13,    34,   119,    32,    13,     7,    14,    31,    10,
      10,    11,    13,    41,    22,   131,    10,    93,    94,    95,
      96,    28,    23,    32,    32,    32,    58,    35,    31,    30,
      24,    39,    33,    41,    37,    98,    99,   100,   101,    46,
      22,    32,    43,    44,    13,    40,    47,    31,    32,   165,
      41,    31,    15,    22,    45,    56,    57,    41,     3,     4,
       5,    13,   125,   126,   127,    39,    35,    23,    38,    14,
      39,    72,   148,   149,   150,   151,   139,    78,   141,    80,
      32,    26,    22,    35,    29,    22,    87,    32,    30,    41,
      32,    92,    32,    13,    20,    32,    27,    42,    43,    41,
      31,    41,   103,   104,    41,    13,    37,    52,    53,    31,
      38,   112,    32,    39,    22,    35,   117,   118,   119,    39,
      46,    41,    48,    38,    32,     6,    38,    35,    11,    55,
     131,    39,   164,    41,   146,    61,    27,    63,    27,    23,
      31,    22,    36,   155,    25,   146,    37,    73,    32,    75,
      31,    32,    22,    79,   155,    25,    23,    41,    84,    85,
      41,    31,    32,     0,   165,    23,     3,   179,     5,    31,
      23,    41,    23,    23,    13,   101,    37,    14,   179,   180,
      37,   107,    32,   109,    15,    16,    17,   113,     3,    26,
       5,    41,    29,    32,   120,    32,    35,    37,    23,    14,
      39,    37,    41,    23,    13,    42,    43,    23,    31,   135,
     136,    26,    32,   139,    29,    52,    53,    32,   144,   145,
       3,    41,     5,    32,    33,    34,    35,    42,    43,    23,
      39,    14,    41,    23,    23,    32,    23,    52,    53,    23,
      44,    31,    32,    26,    41,    32,    29,    -1,    32,    32,
      35,    41,    30,    50,    41,   181,   182,    41,    -1,    42,
      43,    -1,    47,    48,    49,    23,    51,    -1,    -1,    52,
      53,    -1,    32,    -1,    32,    33,    34,    33,    34,    -1,
      38,    41,    38,    -1,    44,    18,    19,    20,    21,     7,
       8,     9,     7,     8,     9
>>>>>>> pilha_correta
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
<<<<<<< HEAD
       0,    53,     0,     3,     5,    14,    26,    29,    32,    43,
      44,    50,    51,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    64,    65,    66,    68,    71,    72,    74,    78,
      79,    80,    81,    31,    73,    13,    35,    36,    40,    42,
      61,    69,    70,    77,    15,    16,    17,    61,    22,    61,
      55,    22,    25,    31,    42,    62,    61,    31,    38,    14,
      28,    47,    61,    71,    61,    77,    41,    18,    19,    20,
      21,    10,    11,    31,    61,    67,    61,    66,    15,    31,
      61,    45,    10,    24,    23,    61,    61,    77,    40,    23,
      31,    23,    22,    31,    39,    39,    39,    39,    11,     7,
       8,     9,    61,    27,    31,    38,    27,    27,    61,    23,
      61,    23,    23,    31,    61,    36,    48,    49,    76,    61,
      69,    69,    69,    69,     7,     8,     9,    70,    70,    70,
      22,    42,    62,    70,    61,    61,    30,    46,    61,    23,
      37,    23,    23,    54,    22,    38,    38,    38,    38,    70,
      70,    70,    54,    23,    32,    33,    34,    63,    70,     5,
      75,    69,    69,    69,    69,     4,    23,    32,    33,    34,
      39,    23,    77,    54,    31,    61,    61,     6,    23,    23
=======
       0,    55,     0,     3,     5,    14,    26,    29,    32,    42,
      43,    52,    53,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    66,    67,    68,    70,    73,    74,    76,    80,
      81,    82,    83,    31,    75,    13,    35,    39,    41,    63,
      71,    72,    79,    15,    16,    17,    63,    22,    63,    57,
      22,    25,    31,    41,    64,    63,    31,    37,    14,    28,
      46,    63,    73,    63,    79,    40,    18,    19,    20,    21,
      10,    11,    31,    63,    69,    63,    68,    15,    31,    63,
      44,    10,    24,    23,    63,    63,    79,    39,    23,    31,
      23,    22,    31,    38,    38,    38,    38,    11,     7,     8,
       9,    63,    27,    31,    37,    27,    27,    63,    23,    63,
      23,    23,    31,    63,    35,    47,    48,    49,    51,    78,
      63,    71,    71,    71,    71,     7,     8,     9,    72,    72,
      72,    22,    41,    64,    72,    63,    63,    30,    45,    63,
      23,    36,    23,    23,    63,    63,    56,    22,    37,    37,
      37,    37,    72,    72,    72,    56,    23,    32,    33,    34,
      65,    72,    50,    23,     5,    77,    71,    71,    71,    71,
       4,    23,    32,    33,    34,    38,    23,    23,    79,    56,
      31,    63,    63,     6,    23,    23
>>>>>>> pilha_correta
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
<<<<<<< HEAD
       0,    52,    53,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    57,    58,    59,    60,    60,    60,    61,    61,    61,
      62,    63,    63,    63,    63,    63,    63,    63,    64,    65,
      66,    66,    66,    67,    67,    67,    68,    68,    68,    69,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    71,
      72,    73,    75,    74,    76,    74,    77,    77,    77,    77,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    79,
      80,    81
=======
       0,    54,    55,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    59,    60,    61,    62,    62,    62,    63,    63,    63,
      64,    65,    65,    65,    65,    65,    65,    65,    66,    67,
      68,    68,    68,    69,    69,    69,    70,    70,    70,    71,
      71,    71,    71,    72,    72,    72,    72,    72,    73,    74,
      75,    77,    76,    78,    76,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      81,    82,    83
>>>>>>> pilha_correta
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     6,     5,     4,     4,     2,     1,     2,     2,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     2,
       1,     3,     3,     1,     3,     3,     4,     4,     4,     1,
<<<<<<< HEAD
       2,     1,     1,     1,     1,     6,     6,     6,     6,     5,
       7,     0,     0,    11,     0,    11,     4,     4,     4,     5,
       5,     5,     2,     3,     3,     7,     7,     5,     5,     2,
       1,     1
=======
       2,     1,     1,     1,     6,     6,     6,     6,     5,     7,
       0,     0,    11,     0,    11,     4,     4,     4,     5,     5,
       5,     2,     3,     3,     7,     7,     5,     5,     7,     6,
       2,     1,     1
>>>>>>> pilha_correta
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
<<<<<<< HEAD
#line 1318 "src/parser.tab.c"
=======
#line 1314 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 5: /* bloco: bloco instrucao  */
#line 79 "src/parser.y"
                               {  }
<<<<<<< HEAD
#line 1324 "src/parser.tab.c"
=======
#line 1320 "src/parser.tab.c"
>>>>>>> pilha_correta
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
<<<<<<< HEAD
#line 1342 "src/parser.tab.c"
=======
#line 1338 "src/parser.tab.c"
>>>>>>> pilha_correta
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
<<<<<<< HEAD
#line 1365 "src/parser.tab.c"
=======
#line 1361 "src/parser.tab.c"
>>>>>>> pilha_correta
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
<<<<<<< HEAD
#line 1386 "src/parser.tab.c"
=======
#line 1382 "src/parser.tab.c"
>>>>>>> pilha_correta
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
<<<<<<< HEAD
#line 1409 "src/parser.tab.c"
=======
#line 1405 "src/parser.tab.c"
>>>>>>> pilha_correta
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
<<<<<<< HEAD
#line 1427 "src/parser.tab.c"
=======
#line 1423 "src/parser.tab.c"
>>>>>>> pilha_correta
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
<<<<<<< HEAD
#line 1445 "src/parser.tab.c"
=======
#line 1441 "src/parser.tab.c"
>>>>>>> pilha_correta
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
<<<<<<< HEAD
#line 1463 "src/parser.tab.c"
=======
#line 1459 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 27: /* texto: palavra  */
#line 218 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
<<<<<<< HEAD
#line 1471 "src/parser.tab.c"
=======
#line 1467 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 28: /* texto: texto NUMERO  */
#line 221 "src/parser.y"
                   {
        //  if (DEBUG_BISON) {
        //      printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
<<<<<<< HEAD
#line 1482 "src/parser.tab.c"
=======
#line 1478 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 29: /* texto: texto palavra  */
#line 227 "src/parser.y"
                    {
        // if (DEBUG_BISON) {
        //     printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
<<<<<<< HEAD
#line 1493 "src/parser.tab.c"
=======
#line 1489 "src/parser.tab.c"
    break;

  case 30: /* palavra: TOKEN  */
#line 228 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1495 "src/parser.tab.c"
    break;

  case 31: /* adjetivos: ADJETIVO_POSITIVO  */
#line 232 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1503 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 30: /* palavra: TOKEN  */
#line 237 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1499 "src/parser.tab.c"
    break;

  case 31: /* adjetivos: ADJETIVO_POSITIVO  */
#line 241 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1507 "src/parser.tab.c"
    break;

  case 32: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 244 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
<<<<<<< HEAD
#line 1515 "src/parser.tab.c"
=======
#line 1511 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 33: /* adjetivos: TOKEN  */
#line 247 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
<<<<<<< HEAD
#line 1523 "src/parser.tab.c"
=======
#line 1519 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 34: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 250 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) + 1;
    }
<<<<<<< HEAD
#line 1534 "src/parser.tab.c"
=======
#line 1530 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 35: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 256 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) - 1;
    }
<<<<<<< HEAD
#line 1545 "src/parser.tab.c"
=======
#line 1541 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 36: /* adjetivos: adjetivos TOKEN  */
#line 262 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
<<<<<<< HEAD
#line 1553 "src/parser.tab.c"
=======
#line 1549 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 37: /* adjetivos: adjetivos ENTRE  */
#line 265 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
<<<<<<< HEAD
#line 1561 "src/parser.tab.c"
=======
#line 1557 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 38: /* declaracao: declaracaoInicio texto FIM  */
#line 270 "src/parser.y"
                               {
        if (DEBUG_BISON) {
            printf("Declaração: %s\n", (yyvsp[-1].texto));
        }
    }
<<<<<<< HEAD
#line 1571 "src/parser.tab.c"
=======
#line 1567 "src/parser.tab.c"
>>>>>>> pilha_correta
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
<<<<<<< HEAD
#line 1585 "src/parser.tab.c"
=======
#line 1581 "src/parser.tab.c"
>>>>>>> pilha_correta
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
    }
<<<<<<< HEAD
#line 1601 "src/parser.tab.c"
=======
#line 1597 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 41: /* personagensEntrando: personagensEntrando VIRGULA texto  */
#line 299 "src/parser.y"
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
<<<<<<< HEAD
#line 1617 "src/parser.tab.c"
=======
#line 1613 "src/parser.tab.c"
>>>>>>> pilha_correta
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
    }
<<<<<<< HEAD
#line 1633 "src/parser.tab.c"
=======
#line 1629 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 43: /* personagensSaindo: texto  */
#line 322 "src/parser.y"
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
<<<<<<< HEAD
#line 1649 "src/parser.tab.c"
=======
#line 1645 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 44: /* personagensSaindo: personagensSaindo VIRGULA texto  */
#line 333 "src/parser.y"
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
<<<<<<< HEAD
#line 1665 "src/parser.tab.c"
=======
#line 1661 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 45: /* personagensSaindo: personagensSaindo E texto  */
#line 344 "src/parser.y"
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
<<<<<<< HEAD
#line 1681 "src/parser.tab.c"
=======
#line 1677 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 46: /* alteracaoElenco: ABRE_COLCHETES ENTRAM personagensEntrando FECHA_COLCHETES  */
#line 357 "src/parser.y"
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
#line 1699 "src/parser.tab.c"
=======
#line 1695 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 47: /* alteracaoElenco: ABRE_COLCHETES SAEM personagensSaindo FECHA_COLCHETES  */
#line 370 "src/parser.y"
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
#line 1717 "src/parser.tab.c"
=======
#line 1713 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 48: /* alteracaoElenco: ABRE_COLCHETES TODOS SAEM FECHA_COLCHETES  */
#line 383 "src/parser.y"
                                                {
        if (DEBUG_BISON) {
            printf("Todos os personagens estão inativos\n");
        }
        // Ativa todos os personagens
        desativar_todos_personagens();
    }
<<<<<<< HEAD
#line 1729 "src/parser.tab.c"
=======
#line 1725 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 49: /* valor: NUMERO  */
#line 392 "src/parser.y"
           {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi((yyvsp[0].texto)));
        }
        (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), atoi((yyvsp[0].texto)), 0);
    }
<<<<<<< HEAD
#line 1740 "src/parser.tab.c"
=======
#line 1736 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 50: /* valor: TU MESMO  */
#line 398 "src/parser.y"
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
<<<<<<< HEAD
#line 1762 "src/parser.tab.c"
=======
#line 1758 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 51: /* valor: EU  */
#line 415 "src/parser.y"
       {
        if (personagemQueFala == NULL) {
            yyerror("Variável 'eu' não definida");
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            if (DEBUG_BISON) {
                printf("Valor de 'eu': %d\n", get_int_value(personagemQueFala));
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
<<<<<<< HEAD
#line 1784 "src/parser.tab.c"
=======
#line 1780 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 52: /* valor: VOCE  */
#line 432 "src/parser.y"
         {
        if (personagemVoce == NULL) {
            yyerror("Variável 'voce' não definida");
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            if (DEBUG_BISON) {
                printf("Valor de 'voce': %d\n", get_int_value(personagemVoce));
            }
            Symbol *sym = get_symbol(personagemVoce);
            if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
                yyerror("Variável 'voce' inválida ou não declarada");
                (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0);
            } else {
                (yyval.llmValueRef) = LLVMBuildLoad2(builder, LLVMInt32Type(), sym->llvm_ref, "load_voce");
            }
        }
    }
#line 1806 "src/parser.tab.c"
    break;

  case 53: /* valor: texto  */
#line 449 "src/parser.y"
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
<<<<<<< HEAD
#line 1823 "src/parser.tab.c"
=======
#line 1797 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 54: /* expressao: valor  */
#line 464 "src/parser.y"
          {
        (yyval.llmValueRef) = (yyvsp[0].llmValueRef); // valor já retorna LLVMValueRef
    }
<<<<<<< HEAD
#line 1831 "src/parser.tab.c"
=======
#line 1805 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 55: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 467 "src/parser.y"
                                     {
        if (DEBUG_BISON) printf("Expressão de soma\n");
        (yyval.llmValueRef) = LLVMBuildAdd(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "addtmp");
    }
<<<<<<< HEAD
#line 1840 "src/parser.tab.c"
=======
#line 1814 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 56: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 471 "src/parser.y"
                                        {
        if (DEBUG_BISON) printf("Expressão de subtração\n");
        (yyval.llmValueRef) = LLVMBuildSub(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "subtmp");
    }
<<<<<<< HEAD
#line 1849 "src/parser.tab.c"
=======
#line 1823 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 57: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 475 "src/parser.y"
                                           {
        if (DEBUG_BISON) printf("Expressão de multiplicação\n");
        (yyval.llmValueRef) = LLVMBuildMul(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "multmp");
    }
<<<<<<< HEAD
#line 1858 "src/parser.tab.c"
=======
#line 1832 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 58: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 479 "src/parser.y"
                                       {
        if (DEBUG_BISON) printf("Expressão de divisão\n");

        // Divisão por zero em tempo de compilação não pode ser detectada aqui
        (yyval.llmValueRef) = LLVMBuildSDiv(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "divtmp");
    }
<<<<<<< HEAD
#line 1869 "src/parser.tab.c"
=======
#line 1843 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 59: /* if_sentenca: SE condicao VIRGULA texto expressao  */
#line 488 "src/parser.y"
                                       {
        if (DEBUG_BISON) {
            printf("IF BLOCO DETECTADO\n");
            printf("Condicao do IF: %d\n", (yyvsp[-3].llmValueRef));
            printf("resultado do IF: %d\n", (yyvsp[0].llmValueRef));
        }
    }
<<<<<<< HEAD
#line 1881 "src/parser.tab.c"
=======
#line 1855 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 60: /* if_bloco: SE condicao VIRGULA texto INICIO bloco ENDIF  */
#line 497 "src/parser.y"
                                                {
        if (DEBUG_BISON) { 
            printf("IF BLOCO DETECTADO\n");
        }
    }
<<<<<<< HEAD
#line 1891 "src/parser.tab.c"
=======
#line 1865 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 61: /* while_aux: %empty  */
#line 504 "src/parser.y"
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
<<<<<<< HEAD
#line 1908 "src/parser.tab.c"
=======
#line 1882 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 62: /* $@1: %empty  */
#line 522 "src/parser.y"
    {
        if (DEBUG_BISON) printf("WHILE DETECTADO\n");

        LLVMBuildCondBr(builder, (yyvsp[-3].llmValueRef), (yyvsp[-4].WhileBlocks).body_bb, (yyvsp[-4].WhileBlocks).after_bb);

        LLVMPositionBuilderAtEnd(builder, (yyvsp[-4].WhileBlocks).body_bb);
    }
<<<<<<< HEAD
#line 1920 "src/parser.tab.c"
=======
#line 1894 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 63: /* while: ENQUANTO_COMECO while_aux condicao VIRGULA texto INICIO $@1 bloco texto ENQUANTO_FIM FIM  */
#line 530 "src/parser.y"
    {
        LLVMBuildBr(builder, (yyvsp[-9].WhileBlocks).cond_bb);
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-9].WhileBlocks).after_bb);
    }
<<<<<<< HEAD
#line 1929 "src/parser.tab.c"
=======
#line 1903 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 64: /* $@2: %empty  */
#line 535 "src/parser.y"
    {
        if (DEBUG_BISON) printf("DO-WHILE DETECTADO\n");

        LLVMBasicBlockRef body_bb = LLVMAppendBasicBlock(funcao_main, "do_body");
        LLVMBasicBlockRef cond_bb = LLVMAppendBasicBlock(funcao_main, "do_cond");
        LLVMBasicBlockRef after_bb = LLVMAppendBasicBlock(funcao_main, "do_end");

        push_while_blocks(cond_bb, body_bb, after_bb);

        LLVMBuildBr(builder, body_bb);
        LLVMPositionBuilderAtEnd(builder, body_bb);
    }
<<<<<<< HEAD
#line 1946 "src/parser.tab.c"
=======
#line 1920 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 65: /* while: FACA VIRGULA texto INICIO $@2 bloco ENQUANTO_COMECO condicao VIRGULA texto FIM  */
#line 548 "src/parser.y"
    {
        WhileBlocks blocks = pop_while_blocks();

        LLVMBuildBr(builder, blocks.cond_bb);
        LLVMPositionBuilderAtEnd(builder, blocks.cond_bb);

        LLVMValueRef cond = (yyvsp[-4].texto);
        LLVMBuildCondBr(builder, cond, blocks.body_bb, blocks.after_bb);

        LLVMPositionBuilderAtEnd(builder, blocks.after_bb);
    }
<<<<<<< HEAD
#line 1962 "src/parser.tab.c"
=======
#line 1936 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 66: /* condicao: expressao FOR MAIOR expressao  */
#line 563 "src/parser.y"
                                      {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpgt");
        }
<<<<<<< HEAD
#line 1970 "src/parser.tab.c"
=======
#line 1944 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 67: /* condicao: expressao FOR MENOR expressao  */
#line 566 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmplt");
        }
<<<<<<< HEAD
#line 1978 "src/parser.tab.c"
=======
#line 1952 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 68: /* condicao: expressao FOR IGUAL expressao  */
#line 569 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpeq");
        }
<<<<<<< HEAD
#line 1986 "src/parser.tab.c"
=======
#line 1960 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 69: /* condicao: expressao NAO FOR MENOR expressao  */
#line 572 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpnlt");
        }
<<<<<<< HEAD
#line 1994 "src/parser.tab.c"
=======
#line 1968 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 70: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 575 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpngt");
        }
<<<<<<< HEAD
#line 2002 "src/parser.tab.c"
=======
#line 1976 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 71: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 578 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpneq");
        }
<<<<<<< HEAD
#line 2010 "src/parser.tab.c"
=======
#line 1984 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 72: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 584 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
        atualiza_personagemVoce();
    }
<<<<<<< HEAD
#line 2022 "src/parser.tab.c"
=======
#line 1995 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 73: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 591 "src/parser.y"
                                    {
        if (DEBUG_BISON) {
            printf("if sentença\n");
        }
        atualiza_personagemVoce();
    }
<<<<<<< HEAD
#line 2033 "src/parser.tab.c"
=======
#line 2005 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 74: /* dialogo: inicioDialogo texto FIM  */
#line 597 "src/parser.y"
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
<<<<<<< HEAD
#line 2053 "src/parser.tab.c"
=======
#line 2024 "src/parser.tab.c"
>>>>>>> pilha_correta
    break;

  case 75: /* dialogo: inicioDialogo texto VIRGULA TU EH expressao FIM  */
#line 612 "src/parser.y"
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

            // 2. Lê o valor atual do topo da pilha
            LLVMValueRef valorAtual = gerar_peek_pilha(pilha_ptr);

            // 3. Pega o valor da expressão
            LLVMValueRef incremento = (yyvsp[-1].llmValueRef);

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
#line 2091 "src/parser.tab.c"
    break;

  case 76: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 645 "src/parser.y"
                                                      {
        personagemDialogo = strdup((yyvsp[-5].texto));


        if (DEBUG_BISON) {
            // printf("Valor do personagem antes do diálogo: %d\n", get_int_value(personagemDialogo));
        }

        // LLVM: gerar incremento personagem = personagem + $6
=======
#line 2060 "src/parser.tab.c"
    break;

  case 75: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 614 "src/parser.y"
                                                      {
        personagemDialogo = strdup((yyvsp[-5].texto));

>>>>>>> pilha_correta
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
<<<<<<< HEAD
#line 2131 "src/parser.tab.c"
    break;

  case 77: /* dialogo: inicioDialogo texto VIRGULA MOSTRA_VALOR FIM  */
#line 681 "src/parser.y"
=======
#line 2096 "src/parser.tab.c"
    break;

  case 76: /* dialogo: inicioDialogo texto VIRGULA MOSTRA_VALOR FIM  */
#line 646 "src/parser.y"
>>>>>>> pilha_correta
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
<<<<<<< HEAD
        gerar_print_int((yyvsp[-3].texto));
        atualiza_personagemVoce();
    }
#line 2156 "src/parser.tab.c"
    break;

  case 78: /* dialogo: inicioDialogo texto VIRGULA LE_VALOR FIM  */
#line 701 "src/parser.y"
=======
        gerar_print_topo_pilha((yyvsp[-3].texto));

    }
#line 2121 "src/parser.tab.c"
    break;

  case 77: /* dialogo: inicioDialogo texto VIRGULA LE_VALOR FIM  */
#line 666 "src/parser.y"
>>>>>>> pilha_correta
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
<<<<<<< HEAD
#line 2177 "src/parser.tab.c"
    break;

  case 79: /* inicioDialogo: texto INICIO  */
#line 721 "src/parser.y"
=======
#line 2141 "src/parser.tab.c"
    break;

  case 78: /* dialogo: inicioDialogo texto VIRGULA GUARDE texto INTERIOR FIM  */
#line 681 "src/parser.y"
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
#line 2161 "src/parser.tab.c"
    break;

  case 79: /* dialogo: inicioDialogo texto VIRGULA LEMBRE texto FIM  */
#line 696 "src/parser.y"
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
#line 2178 "src/parser.tab.c"
    break;

  case 80: /* inicioDialogo: texto INICIO  */
#line 711 "src/parser.y"
>>>>>>> pilha_correta
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
#line 2213 "src/parser.tab.c"
    break;

  case 80: /* ato: ATO  */
#line 754 "src/parser.y"
=======
#line 2214 "src/parser.tab.c"
    break;

  case 81: /* ato: ATO  */
#line 744 "src/parser.y"
>>>>>>> pilha_correta
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
#line 2230 "src/parser.tab.c"
    break;

  case 81: /* cena: CENA  */
#line 768 "src/parser.y"
=======
#line 2231 "src/parser.tab.c"
    break;

  case 82: /* cena: CENA  */
#line 758 "src/parser.y"
>>>>>>> pilha_correta
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
#line 2247 "src/parser.tab.c"
    break;


#line 2251 "src/parser.tab.c"
=======
#line 2248 "src/parser.tab.c"
    break;


#line 2252 "src/parser.tab.c"
>>>>>>> pilha_correta

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
#line 782 "src/parser.y"
=======
#line 772 "src/parser.y"
>>>>>>> pilha_correta


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
