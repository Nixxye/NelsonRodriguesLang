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
  YYSYMBOL_alteracaoElenco = 63,           /* alteracaoElenco  */
  YYSYMBOL_valor = 64,                     /* valor  */
  YYSYMBOL_expressao = 65,                 /* expressao  */
  YYSYMBOL_if_sentenca = 66,               /* if_sentenca  */
  YYSYMBOL_if_bloco = 67,                  /* if_bloco  */
  YYSYMBOL_while_aux = 68,                 /* while_aux  */
  YYSYMBOL_while = 69,                     /* while  */
  YYSYMBOL_70_1 = 70,                      /* $@1  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_condicao = 72,                  /* condicao  */
  YYSYMBOL_dialogo = 73,                   /* dialogo  */
  YYSYMBOL_inicioDialogo = 74,             /* inicioDialogo  */
  YYSYMBOL_ato = 75,                       /* ato  */
  YYSYMBOL_cena = 76                       /* cena  */
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
#define YYLAST   249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

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
      77,    78,    79,    80,    81,    82,    83,    84,    91,   105,
     125,   144,   157,   170,   186,   189,   195,   205,   209,   212,
     215,   218,   224,   230,   233,   238,   245,   256,   271,   277,
     294,   311,   326,   329,   333,   337,   341,   350,   359,   366,
     384,   383,   397,   396,   425,   428,   431,   434,   437,   440,
     446,   452,   457,   471,   499,   529,   542,   553,   578,   592
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
  "alteracaoElenco", "valor", "expressao", "if_sentenca", "if_bloco",
  "while_aux", "while", "$@1", "$@2", "condicao", "dialogo",
  "inicioDialogo", "ato", "cena", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-31)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -94,    53,   -94,   -27,   -94,   176,   -23,   -23,   -94,    -9,
     -23,   -94,   -94,   112,   -94,   -94,   -94,   -94,   -94,   198,
     -94,   -94,   -23,   -94,   -94,   -94,   -94,   -94,    -7,   -94,
     -94,   -23,   176,   -94,   -24,   228,   -94,    14,   -94,   233,
      -2,   177,    89,   -23,   202,   -94,   -94,     1,   -94,   -94,
     -94,   162,   176,   -94,    10,     0,    49,    17,   -94,    -6,
      15,    18,    28,    59,    67,   -23,   -94,   -23,   199,   -23,
      77,    98,   -94,    42,   -94,    44,   -94,   -94,   -23,    99,
      99,    99,    99,   183,   176,   176,   176,   165,   127,   -94,
     111,   -94,   -94,   -23,    71,   100,   105,   112,    82,   108,
     116,   138,   140,   176,   176,   176,   -94,   -94,   -94,   112,
     175,    35,   -94,   -94,   118,   187,   137,   -94,   -94,   131,
     -94,    99,    99,    99,    99,   -94,   -94,   -94,    83,   -94,
      66,   -94,   -94,   203,   158,   176,   112,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   156,   112,
     -23,     4,   201,   178,   -94,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    49,     0,     0,     0,    27,     0,
       0,    68,    69,     3,     4,    10,    12,    13,    11,     0,
      24,     9,     0,    14,    15,    16,    17,     8,     0,     6,
       7,     0,     0,    40,     0,     0,    38,    41,    42,     0,
       0,     0,     0,     0,     0,     5,    67,    23,    36,    25,
      26,     0,     0,    60,     0,     0,     0,     0,    39,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,    35,     0,    62,     0,    61,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,     0,
      38,    24,    47,    18,     0,     0,     0,    65,    66,     0,
      50,     0,     0,     0,     0,    58,    57,    59,     0,    20,
      27,    28,    29,     0,     0,     0,     0,    43,    44,    46,
      45,    48,    64,    33,    31,    32,    34,    63,     0,     0,
       0,     0,     0,     0,    53,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   -93,   -12,   -94,   -94,   -94,   -94,    -1,    -5,
     -94,   -94,   -94,   -94,   -62,    79,   170,   -94,   -94,   -94,
     -94,   -94,   -30,   -94,   -94,   -94,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    13,    14,    15,    16,    17,    18,    37,    20,
     133,    21,    22,    23,    38,    39,    24,    25,    32,    26,
     136,    97,    40,    27,    28,    29,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    45,    57,    31,   119,    41,    42,    52,     8,    44,
     153,    70,    19,    43,    50,    58,   128,    99,   100,   101,
     102,    51,    73,    76,     8,    71,    46,    54,    65,    47,
      56,    79,    50,    74,    48,     8,    50,    50,    53,    50,
      75,     8,    68,   149,    49,     8,    50,    78,   -26,    50,
      49,    50,    80,     2,    49,    81,     3,   -26,     4,   137,
     138,   139,   140,    50,    87,    82,    88,     5,    90,   -26,
      83,    77,    93,   -26,    84,    85,    86,    98,    94,     6,
       8,     7,   111,    50,     8,    50,     3,   141,     4,    49,
      95,    96,   115,    50,     9,    10,    19,     5,   -30,   -30,
      91,    11,    12,   -30,   120,   148,   116,    45,    19,     6,
     111,     7,    33,     8,     8,     3,    45,     4,    19,    67,
       8,    92,    49,   117,     9,    10,     5,    19,   118,    49,
       8,    11,    12,    34,     3,    19,   135,    45,     6,    36,
       7,   129,     8,     8,   121,     5,    50,    50,   151,   152,
      33,    49,   122,     9,    10,   114,   113,     6,     8,     7,
      11,    12,     8,   106,   107,   108,   112,    49,   130,   131,
     132,    34,     9,    10,   123,    35,   124,    36,    33,    11,
      12,   147,   125,   126,   127,    72,   150,   109,   -25,    33,
     103,   104,   105,     8,   112,   134,     8,   -25,    55,    34,
      33,   155,    49,    35,    66,   110,   -25,     8,     8,   -25,
      34,     0,     0,   -25,    35,   -25,    36,    49,     8,     0,
      46,    34,    89,    47,   154,    35,   142,   110,    48,     8,
       8,     0,     8,     8,   143,   144,   145,     0,    49,    49,
     146,    49,    49,    63,    64,    69,    59,    60,    61,    62
};

static const yytype_int16 yycheck[] =
{
       1,    13,    32,    30,    97,     6,     7,    14,    31,    10,
       6,    10,    13,    22,    19,    39,   109,    79,    80,    81,
      82,    22,    52,    23,    31,    24,    22,    28,    30,    25,
      31,    37,    37,    23,    30,    31,    41,    42,    45,    44,
      30,    31,    43,   136,    40,    31,    51,    30,    13,    54,
      40,    56,    37,     0,    40,    37,     3,    22,     5,   121,
     122,   123,   124,    68,    65,    37,    67,    14,    69,    34,
      11,    22,    30,    38,     7,     8,     9,    78,    34,    26,
      31,    28,    87,    88,    31,    90,     3,     4,     5,    40,
      46,    47,    93,    98,    41,    42,    97,    14,    32,    33,
      23,    48,    49,    37,    22,   135,    35,   119,   109,    26,
     115,    28,    13,    31,    31,     3,   128,     5,   119,    30,
      31,    23,    40,    23,    41,    42,    14,   128,    23,    40,
      31,    48,    49,    34,     3,   136,     5,   149,    26,    40,
      28,    23,    31,    31,    36,    14,   151,   152,   149,   150,
      13,    40,    36,    41,    42,    44,    29,    26,    31,    28,
      48,    49,    31,    84,    85,    86,    87,    40,    31,    32,
      33,    34,    41,    42,    36,    38,    36,    40,    13,    48,
      49,    23,   103,   104,   105,    23,    30,    22,    13,    13,
       7,     8,     9,    31,   115,   116,    31,    22,    28,    34,
      13,    23,    40,    38,    27,    40,    31,    31,    31,    34,
      34,    -1,    -1,    38,    38,    40,    40,    40,    31,    -1,
      22,    34,    23,    25,    23,    38,    23,    40,    30,    31,
      31,    -1,    31,    31,    31,    32,    33,    -1,    40,    40,
      37,    40,    40,    10,    11,    43,    18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,     0,     3,     5,    14,    26,    28,    31,    41,
      42,    48,    49,    52,    53,    54,    55,    56,    57,    58,
      59,    61,    62,    63,    66,    67,    69,    73,    74,    75,
      76,    30,    68,    13,    34,    38,    40,    58,    64,    65,
      72,    58,    58,    22,    58,    53,    22,    25,    30,    40,
      59,    58,    14,    45,    58,    66,    58,    72,    39,    18,
      19,    20,    21,    10,    11,    30,    27,    30,    58,    43,
      10,    24,    23,    72,    23,    30,    23,    22,    30,    37,
      37,    37,    37,    11,     7,     8,     9,    58,    58,    23,
      58,    23,    23,    30,    34,    46,    47,    71,    58,    64,
      64,    64,    64,     7,     8,     9,    65,    65,    65,    22,
      40,    59,    65,    29,    44,    58,    35,    23,    23,    52,
      22,    36,    36,    36,    36,    65,    65,    65,    52,    23,
      31,    32,    33,    60,    65,     5,    70,    64,    64,    64,
      64,     4,    23,    31,    32,    33,    37,    23,    72,    52,
      30,    58,    58,     6,    23,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    55,
      56,    57,    57,    57,    58,    58,    58,    59,    60,    60,
      60,    60,    60,    60,    60,    61,    62,    63,    64,    64,
      64,    64,    65,    65,    65,    65,    65,    66,    67,    68,
      70,    69,    71,    69,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    74,    75,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       6,     4,     4,     2,     1,     2,     2,     1,     1,     1,
       1,     2,     2,     2,     2,     3,     2,     3,     1,     2,
       1,     1,     1,     6,     6,     6,     6,     5,     7,     0,
       0,    11,     0,    11,     4,     4,     4,     5,     5,     5,
       2,     3,     3,     7,     7,     5,     5,     2,     1,     1
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
#line 1280 "src/parser.tab.c"
    break;

  case 5: /* bloco: bloco instrucao  */
#line 69 "src/parser.y"
                               {  }
#line 1286 "src/parser.tab.c"
    break;

  case 18: /* declaracaoCenario: ABRE_PARENTESES texto VIRGULA texto FECHA_PARENTESES  */
#line 91 "src/parser.y"
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
#line 1303 "src/parser.tab.c"
    break;

  case 19: /* concatenarCenario: ADICIONAR_CENARIO INICIO texto FIM  */
#line 105 "src/parser.y"
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
#line 1326 "src/parser.tab.c"
    break;

  case 20: /* substituiCenario: SUBSTITUIR_CENARIO texto POR texto NO_CENARIO FIM  */
#line 125 "src/parser.y"
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
#line 1347 "src/parser.tab.c"
    break;

  case 21: /* declaracaoQuestionamento: texto INTERROGACAO NAO FIM  */
#line 144 "src/parser.y"
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
#line 1365 "src/parser.tab.c"
    break;

  case 22: /* declaracaoQuestionamento: texto INTERROGACAO SIM FIM  */
#line 157 "src/parser.y"
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
#line 1383 "src/parser.tab.c"
    break;

  case 23: /* declaracaoQuestionamento: texto INTERROGACAO  */
#line 170 "src/parser.y"
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
#line 1401 "src/parser.tab.c"
    break;

  case 24: /* texto: palavra  */
#line 186 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1409 "src/parser.tab.c"
    break;

  case 25: /* texto: texto NUMERO  */
#line 189 "src/parser.y"
                   {
        //  if (DEBUG_BISON) {
        //      printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1420 "src/parser.tab.c"
    break;

  case 26: /* texto: texto palavra  */
#line 195 "src/parser.y"
                    {
        // if (DEBUG_BISON) {
        //     printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
#line 1431 "src/parser.tab.c"
    break;

  case 27: /* palavra: TOKEN  */
#line 205 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
#line 1437 "src/parser.tab.c"
    break;

  case 28: /* adjetivos: ADJETIVO_POSITIVO  */
#line 209 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1445 "src/parser.tab.c"
    break;

  case 29: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 212 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
#line 1453 "src/parser.tab.c"
    break;

  case 30: /* adjetivos: TOKEN  */
#line 215 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
#line 1461 "src/parser.tab.c"
    break;

  case 31: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 218 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) + 1;
    }
#line 1472 "src/parser.tab.c"
    break;

  case 32: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 224 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) - 1;
    }
#line 1483 "src/parser.tab.c"
    break;

  case 33: /* adjetivos: adjetivos TOKEN  */
#line 230 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1491 "src/parser.tab.c"
    break;

  case 34: /* adjetivos: adjetivos ENTRE  */
#line 233 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1499 "src/parser.tab.c"
    break;

  case 35: /* declaracao: declaracaoInicio texto FIM  */
#line 238 "src/parser.y"
                               {
        if (DEBUG_BISON) {
            printf("Declaração: %s\n", (yyvsp[-1].texto));
        }
    }
#line 1509 "src/parser.tab.c"
    break;

  case 36: /* declaracaoInicio: texto VIRGULA  */
#line 245 "src/parser.y"
                  {
        if (estado == E_DECLARACOES) {
            if (DEBUG_BISON) {
                printf("Criando variável: %s\n", (yyvsp[-1].texto));
            }
            add_symbol((yyvsp[-1].texto), INT_VAR);
        }
        (yyval.texto) = (yyvsp[-1].texto);
    }
#line 1523 "src/parser.tab.c"
    break;

  case 37: /* alteracaoElenco: ABRE_COLCHETES texto FECHA_COLCHETES  */
#line 256 "src/parser.y"
                                         {
        if (estado == E_CENA) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", (yyvsp[-1].texto));
            }
        } else if (estado == E_DIALOGO) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", (yyvsp[-1].texto));
            }
        } else {
            printf("Alteração de elenco fora de contexto, estado atual: %d\n", estado);
        }
    }
#line 1541 "src/parser.tab.c"
    break;

  case 38: /* valor: NUMERO  */
#line 271 "src/parser.y"
           {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi((yyvsp[0].texto)));
        }
        (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), atoi((yyvsp[0].texto)), 0);
    }
#line 1552 "src/parser.tab.c"
    break;

  case 39: /* valor: TU MESMO  */
#line 277 "src/parser.y"
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
#line 1574 "src/parser.tab.c"
    break;

  case 40: /* valor: EU  */
#line 294 "src/parser.y"
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
#line 1596 "src/parser.tab.c"
    break;

  case 41: /* valor: texto  */
#line 311 "src/parser.y"
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
#line 1613 "src/parser.tab.c"
    break;

  case 42: /* expressao: valor  */
#line 326 "src/parser.y"
          {
        (yyval.llmValueRef) = (yyvsp[0].llmValueRef); // valor já retorna LLVMValueRef
    }
#line 1621 "src/parser.tab.c"
    break;

  case 43: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 329 "src/parser.y"
                                     {
        if (DEBUG_BISON) printf("Expressão de soma\n");
        (yyval.llmValueRef) = LLVMBuildAdd(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "addtmp");
    }
#line 1630 "src/parser.tab.c"
    break;

  case 44: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 333 "src/parser.y"
                                        {
        if (DEBUG_BISON) printf("Expressão de subtração\n");
        (yyval.llmValueRef) = LLVMBuildSub(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "subtmp");
    }
#line 1639 "src/parser.tab.c"
    break;

  case 45: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 337 "src/parser.y"
                                           {
        if (DEBUG_BISON) printf("Expressão de multiplicação\n");
        (yyval.llmValueRef) = LLVMBuildMul(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "multmp");
    }
#line 1648 "src/parser.tab.c"
    break;

  case 46: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 341 "src/parser.y"
                                       {
        if (DEBUG_BISON) printf("Expressão de divisão\n");

        // Divisão por zero em tempo de compilação não pode ser detectada aqui
        (yyval.llmValueRef) = LLVMBuildSDiv(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "divtmp");
    }
#line 1659 "src/parser.tab.c"
    break;

  case 47: /* if_sentenca: SE condicao VIRGULA texto expressao  */
#line 350 "src/parser.y"
                                       {
        if (DEBUG_BISON) {
            printf("IF BLOCO DETECTADO\n");
            printf("Condicao do IF: %d\n", (yyvsp[-3].llmValueRef));
            printf("resultado do IF: %d\n", (yyvsp[0].llmValueRef));
        }
    }
#line 1671 "src/parser.tab.c"
    break;

  case 48: /* if_bloco: SE condicao VIRGULA texto INICIO bloco ENDIF  */
#line 359 "src/parser.y"
                                                {
        if (DEBUG_BISON) { 
            printf("IF BLOCO DETECTADO\n");
        }
    }
#line 1681 "src/parser.tab.c"
    break;

  case 49: /* while_aux: %empty  */
#line 366 "src/parser.y"
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
#line 1698 "src/parser.tab.c"
    break;

  case 50: /* $@1: %empty  */
#line 384 "src/parser.y"
    {
        if (DEBUG_BISON) printf("WHILE DETECTADO\n");

        LLVMBuildCondBr(builder, (yyvsp[-3].llmValueRef), (yyvsp[-4].WhileBlocks).body_bb, (yyvsp[-4].WhileBlocks).after_bb);

        LLVMPositionBuilderAtEnd(builder, (yyvsp[-4].WhileBlocks).body_bb);
    }
#line 1710 "src/parser.tab.c"
    break;

  case 51: /* while: ENQUANTO_COMECO while_aux condicao VIRGULA texto INICIO $@1 bloco texto ENQUANTO_FIM FIM  */
#line 392 "src/parser.y"
    {
        LLVMBuildBr(builder, (yyvsp[-9].WhileBlocks).cond_bb);
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-9].WhileBlocks).after_bb);
    }
#line 1719 "src/parser.tab.c"
    break;

  case 52: /* $@2: %empty  */
#line 397 "src/parser.y"
    {
        if (DEBUG_BISON) printf("DO-WHILE DETECTADO\n");

        LLVMBasicBlockRef body_bb = LLVMAppendBasicBlock(funcao_main, "do_body");
        LLVMBasicBlockRef cond_bb = LLVMAppendBasicBlock(funcao_main, "do_cond");
        LLVMBasicBlockRef after_bb = LLVMAppendBasicBlock(funcao_main, "do_end");

        push_while_blocks(cond_bb, body_bb, after_bb);

        LLVMBuildBr(builder, body_bb);
        LLVMPositionBuilderAtEnd(builder, body_bb);
    }
#line 1736 "src/parser.tab.c"
    break;

  case 53: /* while: FACA VIRGULA texto INICIO $@2 bloco ENQUANTO_COMECO condicao VIRGULA texto FIM  */
#line 410 "src/parser.y"
    {
        WhileBlocks blocks = pop_while_blocks();

        LLVMBuildBr(builder, blocks.cond_bb);
        LLVMPositionBuilderAtEnd(builder, blocks.cond_bb);

        LLVMValueRef cond = (yyvsp[-4].texto);
        LLVMBuildCondBr(builder, cond, blocks.body_bb, blocks.after_bb);

        LLVMPositionBuilderAtEnd(builder, blocks.after_bb);
    }
#line 1752 "src/parser.tab.c"
    break;

  case 54: /* condicao: expressao FOR MAIOR expressao  */
#line 425 "src/parser.y"
                                      {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpgt");
        }
#line 1760 "src/parser.tab.c"
    break;

  case 55: /* condicao: expressao FOR MENOR expressao  */
#line 428 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmplt");
        }
#line 1768 "src/parser.tab.c"
    break;

  case 56: /* condicao: expressao FOR IGUAL expressao  */
#line 431 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpeq");
        }
#line 1776 "src/parser.tab.c"
    break;

  case 57: /* condicao: expressao NAO FOR MENOR expressao  */
#line 434 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpnlt");
        }
#line 1784 "src/parser.tab.c"
    break;

  case 58: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 437 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpngt");
        }
#line 1792 "src/parser.tab.c"
    break;

  case 59: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 440 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpneq");
        }
#line 1800 "src/parser.tab.c"
    break;

  case 60: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 446 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
    }
#line 1811 "src/parser.tab.c"
    break;

  case 61: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 452 "src/parser.y"
                                    {
        if (DEBUG_BISON) {
            printf("if sentença\n");
        }
    }
#line 1821 "src/parser.tab.c"
    break;

  case 62: /* dialogo: inicioDialogo texto FIM  */
#line 457 "src/parser.y"
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
#line 1840 "src/parser.tab.c"
    break;

  case 63: /* dialogo: inicioDialogo texto VIRGULA TU EH expressao FIM  */
#line 471 "src/parser.y"
                                                      {
        personagemDialogo = strdup((yyvsp[-5].texto));

        if (DEBUG_BISON) {
            // printf("Valor do personagem antes do diálogo: %d\n", get_int_value(personagemDialogo));
        }

        Symbol *sym = get_symbol(personagemDialogo);
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            yyerror("Variável inteira inválida ou não declarada");
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
#line 1873 "src/parser.tab.c"
    break;

  case 64: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 499 "src/parser.y"
                                                      {
        personagemDialogo = strdup((yyvsp[-5].texto));

        if (DEBUG_BISON) {
            // printf("Valor do personagem antes do diálogo: %d\n", get_int_value(personagemDialogo));
        }

        // LLVM: gerar incremento personagem = personagem + $6
        Symbol *sym = get_symbol(personagemDialogo);
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            yyerror("Variável inteira inválida ou não declarada");
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
#line 1907 "src/parser.tab.c"
    break;

  case 65: /* dialogo: inicioDialogo texto VIRGULA MOSTRA_VALOR FIM  */
#line 529 "src/parser.y"
                                                   {
        if (DEBUG_BISON) {
            // int val = get_int_value($2);
            // if (val == -1) {
            //     yyerror("Variável não definida");
            // } else {
            //     printf("Valor de %s: %d\n", $2, val);
            // }
        }

        gerar_print_int((yyvsp[-3].texto));

    }
#line 1925 "src/parser.tab.c"
    break;

  case 66: /* dialogo: inicioDialogo texto VIRGULA LE_VALOR FIM  */
#line 542 "src/parser.y"
                                               {
        // Scanf
        if (DEBUG_BISON) {
            printf("Lendo valor de %s\n", (yyvsp[-3].texto));
        }
        gerar_leitura_inteiro((yyvsp[-3].texto));
    }
#line 1937 "src/parser.tab.c"
    break;

  case 67: /* inicioDialogo: texto INICIO  */
#line 553 "src/parser.y"
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
#line 1965 "src/parser.tab.c"
    break;

  case 68: /* ato: ATO  */
#line 578 "src/parser.y"
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
#line 1982 "src/parser.tab.c"
    break;

  case 69: /* cena: CENA  */
#line 592 "src/parser.y"
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
#line 1999 "src/parser.tab.c"
    break;


#line 2003 "src/parser.tab.c"

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

#line 606 "src/parser.y"


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
