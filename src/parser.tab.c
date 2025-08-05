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
<<<<<<< HEAD
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
  YYSYMBOL_ENTAO = 15,                     /* ENTAO  */
  YYSYMBOL_EU = 16,                        /* EU  */
  YYSYMBOL_SE = 17,                        /* SE  */
  YYSYMBOL_SAEM = 18,                      /* SAEM  */
  YYSYMBOL_ENTRAM = 19,                    /* ENTRAM  */
  YYSYMBOL_TODOS = 20,                     /* TODOS  */
  YYSYMBOL_SOMAR = 21,                     /* SOMAR  */
  YYSYMBOL_SUBTRAIR = 22,                  /* SUBTRAIR  */
  YYSYMBOL_DIVIDIR = 23,                   /* DIVIDIR  */
  YYSYMBOL_MULTIPLICAR = 24,               /* MULTIPLICAR  */
  YYSYMBOL_INICIO = 25,                    /* INICIO  */
  YYSYMBOL_FIM = 26,                       /* FIM  */
  YYSYMBOL_SIM = 27,                       /* SIM  */
  YYSYMBOL_INTERROGACAO = 28,              /* INTERROGACAO  */
  YYSYMBOL_ABRE_COLCHETES = 29,            /* ABRE_COLCHETES  */
  YYSYMBOL_FECHA_COLCHETES = 30,           /* FECHA_COLCHETES  */
  YYSYMBOL_VOLTAR_CENARIO = 31,            /* VOLTAR_CENARIO  */
  YYSYMBOL_VOCE = 32,                      /* VOCE  */
  YYSYMBOL_ABRE_PARENTESES = 33,           /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 34,          /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 35,                   /* VIRGULA  */
  YYSYMBOL_SERA = 36,                      /* SERA  */
  YYSYMBOL_TOKEN = 37,                     /* TOKEN  */
  YYSYMBOL_ADJETIVO_POSITIVO = 38,         /* ADJETIVO_POSITIVO  */
  YYSYMBOL_ADJETIVO_NEGATIVO = 39,         /* ADJETIVO_NEGATIVO  */
  YYSYMBOL_TU = 40,                        /* TU  */
  YYSYMBOL_EH = 41,                        /* EH  */
  YYSYMBOL_E = 42,                         /* E  */
  YYSYMBOL_ENTRE = 43,                     /* ENTRE  */
  YYSYMBOL_ARTIGO = 44,                    /* ARTIGO  */
  YYSYMBOL_MESMO = 45,                     /* MESMO  */
  YYSYMBOL_NUMERO = 46,                    /* NUMERO  */
  YYSYMBOL_ADICIONAR_CENARIO = 47,         /* ADICIONAR_CENARIO  */
  YYSYMBOL_SUBSTITUIR_CENARIO = 48,        /* SUBSTITUIR_CENARIO  */
  YYSYMBOL_POR = 49,                       /* POR  */
  YYSYMBOL_NO_CENARIO = 50,                /* NO_CENARIO  */
  YYSYMBOL_MOSTRAR_CENARIO = 51,           /* MOSTRAR_CENARIO  */
  YYSYMBOL_MOSTRA_VALOR = 52,              /* MOSTRA_VALOR  */
  YYSYMBOL_LE_VALOR = 53,                  /* LE_VALOR  */
  YYSYMBOL_GUARDE = 54,                    /* GUARDE  */
  YYSYMBOL_INTERIOR = 55,                  /* INTERIOR  */
  YYSYMBOL_LEMBRE = 56,                    /* LEMBRE  */
  YYSYMBOL_IF_MOSTRA_VALOR = 57,           /* IF_MOSTRA_VALOR  */
  YYSYMBOL_IF_LE_VALOR = 58,               /* IF_LE_VALOR  */
=======
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
  YYSYMBOL_O_TAMANHO_DE = 58,              /* O_TAMANHO_DE  */
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
  YYSYMBOL_ATO = 59,                       /* ATO  */
  YYSYMBOL_CENA = 60,                      /* CENA  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_programa = 62,                  /* programa  */
  YYSYMBOL_bloco = 63,                     /* bloco  */
  YYSYMBOL_instrucao = 64,                 /* instrucao  */
<<<<<<< HEAD
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
  YYSYMBOL_cena = 93                       /* cena  */
=======
  YYSYMBOL_declaracaoCenario = 65,         /* declaracaoCenario  */
  YYSYMBOL_concatenarCenario = 66,         /* concatenarCenario  */
  YYSYMBOL_substituiCenario = 67,          /* substituiCenario  */
  YYSYMBOL_trocarCenario = 68,             /* trocarCenario  */
  YYSYMBOL_declaracaoQuestionamento = 69,  /* declaracaoQuestionamento  */
  YYSYMBOL_texto = 70,                     /* texto  */
  YYSYMBOL_palavra = 71,                   /* palavra  */
  YYSYMBOL_adjetivos = 72,                 /* adjetivos  */
  YYSYMBOL_declaracao = 73,                /* declaracao  */
  YYSYMBOL_declaracaoInicio = 74,          /* declaracaoInicio  */
  YYSYMBOL_personagensEntrando = 75,       /* personagensEntrando  */
  YYSYMBOL_personagensSaindo = 76,         /* personagensSaindo  */
  YYSYMBOL_alteracaoElenco = 77,           /* alteracaoElenco  */
  YYSYMBOL_personagem = 78,                /* personagem  */
  YYSYMBOL_valor = 79,                     /* valor  */
  YYSYMBOL_expressao = 80,                 /* expressao  */
  YYSYMBOL_if_sentenca = 81,               /* if_sentenca  */
  YYSYMBOL_if_bloco = 82,                  /* if_bloco  */
  YYSYMBOL_83_1 = 83,                      /* $@1  */
  YYSYMBOL_while = 84,                     /* while  */
  YYSYMBOL_85_2 = 85,                      /* $@2  */
  YYSYMBOL_86_3 = 86,                      /* $@3  */
  YYSYMBOL_87_4 = 87,                      /* $@4  */
  YYSYMBOL_condicao = 88,                  /* condicao  */
  YYSYMBOL_dialogo = 89,                   /* dialogo  */
  YYSYMBOL_inicioDialogo = 90,             /* inicioDialogo  */
  YYSYMBOL_ato = 91,                       /* ato  */
  YYSYMBOL_cena = 92                       /* cena  */
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#define YYLAST   289
=======
#define YYLAST   305
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
<<<<<<< HEAD
#define YYNRULES  93
=======
#define YYNRULES  92
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

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
       0,    71,    71,    72,    76,    77,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
<<<<<<< HEAD
      95,    99,   107,   122,   142,   161,   180,   193,   206,   222,
     225,   231,   241,   245,   248,   251,   254,   260,   266,   269,
     274,   281,   292,   304,   316,   329,   340,   351,   364,   377,
     390,   399,   402,   405,   410,   416,   434,   451,   468,   483,
     486,   490,   494,   498,   507,   545,   576,   603,   602,   642,
     661,   641,   686,   685,   725,   728,   731,   734,   737,   740,
     743,   746,   752,   759,   765,   780,   803,   843,   863,   879,
     894,   909,   942,   956
=======
     101,   116,   136,   155,   174,   187,   200,   216,   219,   225,
     235,   239,   242,   245,   248,   254,   260,   263,   268,   275,
     286,   298,   310,   324,   335,   346,   359,   372,   385,   394,
     397,   400,   405,   411,   429,   446,   463,   480,   495,   498,
     502,   506,   510,   519,   557,   588,   615,   614,   654,   673,
     653,   698,   697,   737,   740,   743,   746,   749,   752,   755,
     758,   764,   771,   777,   792,   815,   855,   875,   891,   906,
     921,   954,   968
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
  "MENOR", "MENOR_IGUAL", "IGUAL", "NAO", "FOR", "ENTAO", "EU", "SE",
  "SAEM", "ENTRAM", "TODOS", "SOMAR", "SUBTRAIR", "DIVIDIR", "MULTIPLICAR",
  "INICIO", "FIM", "SIM", "INTERROGACAO", "ABRE_COLCHETES",
  "FECHA_COLCHETES", "VOLTAR_CENARIO", "VOCE", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "SERA", "TOKEN", "ADJETIVO_POSITIVO",
  "ADJETIVO_NEGATIVO", "TU", "EH", "E", "ENTRE", "ARTIGO", "MESMO",
  "NUMERO", "ADICIONAR_CENARIO", "SUBSTITUIR_CENARIO", "POR", "NO_CENARIO",
  "MOSTRAR_CENARIO", "MOSTRA_VALOR", "LE_VALOR", "GUARDE", "INTERIOR",
<<<<<<< HEAD
  "LEMBRE", "IF_MOSTRA_VALOR", "IF_LE_VALOR", "ATO", "CENA", "$accept",
  "programa", "bloco", "instrucao", "saida", "declaracaoCenario",
=======
  "LEMBRE", "IF_MOSTRA_VALOR", "IF_LE_VALOR", "O_TAMANHO_DE", "ATO",
  "CENA", "$accept", "programa", "bloco", "instrucao", "declaracaoCenario",
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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

<<<<<<< HEAD
#define YYPACT_NINF (-102)
=======
#define YYPACT_NINF (-124)
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
    -102,    44,  -102,  -102,   -19,  -102,    -7,   269,    -9,  -102,
      15,    -9,  -102,  -102,   134,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,    70,  -102,  -102,    -9,   -27,  -102,  -102,  -102,
    -102,  -102,    25,  -102,  -102,    -9,    -7,  -102,  -102,    -4,
     262,  -102,   163,  -102,    -2,    20,    -9,    -9,    39,   231,
      -9,   199,  -102,  -102,     5,  -102,  -102,  -102,    17,    -9,
      -9,    -7,    26,  -102,   179,    52,    -8,    51,  -102,    47,
      58,    69,    71,    86,   270,    81,   163,    92,   163,   204,
      87,    -9,    83,    -9,   128,   132,  -102,   163,   163,   115,
      -9,  -102,    31,  -102,  -102,    -9,    56,    56,    56,    56,
     120,    -7,    -7,    -7,    -7,    -7,  -102,  -102,   111,   -22,
    -102,    -9,    -9,  -102,  -102,   228,  -102,   110,  -102,  -102,
      81,   116,   105,   140,   143,    -9,    -9,   134,   158,   131,
     137,   142,   144,    -7,    -7,    -7,  -102,  -102,  -102,  -102,
    -102,  -102,    -7,  -102,  -102,   163,   163,  -102,   150,   163,
    -102,   217,  -102,  -102,   183,   181,   184,  -102,    56,    56,
      56,    56,  -102,  -102,  -102,   134,  -102,  -102,   232,  -102,
    -102,   221,   166,   189,  -102,    -7,   134,  -102,  -102,  -102,
    -102,   193,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   188,
     134,  -102,    -9,   124,   182,   198,  -102,  -102
=======
    -124,     5,  -124,    -8,  -124,    48,   266,    -6,  -124,    12,
      -6,  -124,  -124,   182,  -124,  -124,  -124,  -124,  -124,  -124,
     118,  -124,  -124,    -6,    49,  -124,  -124,  -124,  -124,  -124,
      19,  -124,  -124,    -6,    48,  -124,  -124,     6,   259,  -124,
      -6,    77,  -124,    85,    22,    -6,    -6,    50,   188,    -6,
     129,  -124,  -124,    -9,  -124,  -124,  -124,   -18,    -6,    -6,
      48,    27,  -124,   126,    47,    -5,    39,  -124,    53,    58,
      61,    75,    77,   102,   260,    71,    77,   106,    77,   175,
      92,    -6,    -2,    -6,   105,   109,  -124,    77,    77,   103,
      -6,  -124,   196,  -124,  -124,    -6,    73,    73,    73,    73,
     265,    48,    48,    48,    48,    48,  -124,  -124,    96,   -10,
    -124,    -6,    -6,  -124,  -124,   157,  -124,   -25,  -124,  -124,
      71,    60,   113,   148,   151,    -6,    -6,   182,   112,   145,
     147,   167,   172,    48,    48,    48,  -124,  -124,  -124,  -124,
    -124,  -124,    48,  -124,  -124,    77,    77,  -124,   174,    77,
    -124,    23,  -124,  -124,   158,   125,   218,  -124,    73,    73,
      73,    73,  -124,  -124,  -124,   182,  -124,  -124,   224,  -124,
    -124,   194,   192,   195,  -124,    48,   182,  -124,  -124,  -124,
    -124,   179,  -124,  -124,  -124,  -124,  -124,  -124,  -124,   193,
     182,  -124,    -6,   122,   156,   212,  -124,  -124
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
<<<<<<< HEAD
       2,     0,     1,    21,     0,    69,     0,     0,     0,    32,
       0,     0,    92,    93,     3,     4,    20,    10,    12,    13,
      14,    11,    42,    29,     9,     0,    19,    15,    16,    17,
      18,     8,     0,     6,     7,     0,     0,    56,    57,     0,
       0,    54,    58,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     5,    91,    28,    41,    30,    31,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,    45,     0,    42,     0,
       0,     0,     0,     0,     0,     0,    40,    43,    44,     0,
       0,    84,     0,    83,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,     0,
      49,     0,     0,    48,    50,     0,    23,     0,    26,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    67,     0,    65,    66,    46,    47,    22,     0,    53,
      25,     0,    87,    88,     0,     0,     0,    70,     0,     0,
       0,     0,    80,    79,    81,     0,    64,    24,    32,    33,
      34,     0,     0,     0,    90,     0,     0,    60,    61,    63,
      62,     0,    86,    38,    36,    37,    39,    85,    89,     0,
       0,    68,     0,    42,     0,     0,    73,    71
=======
       2,     0,     1,     0,    68,     0,     0,     0,    30,     0,
       0,    91,    92,     3,     4,    10,    12,    13,    14,    11,
      40,    27,     9,     0,    19,    15,    16,    17,    18,     8,
       0,     6,     7,     0,     0,    54,    55,     0,     0,    52,
       0,    57,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     5,    90,    26,    39,    28,    29,     0,     0,     0,
       0,     0,    81,     0,     0,     0,     0,    53,     0,     0,
       0,     0,    56,     0,     0,     0,    43,     0,    40,     0,
       0,     0,     0,     0,     0,     0,    38,    41,    42,     0,
       0,    83,     0,    82,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    50,    51,     0,
      47,     0,     0,    46,    48,     0,    21,     0,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    74,    75,    76,
      77,    66,     0,    64,    65,    44,    45,    20,     0,    51,
      23,     0,    86,    87,     0,     0,     0,    69,     0,     0,
       0,     0,    79,    78,    80,     0,    63,    22,    30,    31,
      32,     0,     0,     0,    89,     0,     0,    59,    60,    62,
      61,     0,    85,    36,    34,    35,    37,    84,    88,     0,
       0,    67,     0,    40,     0,     0,    72,    70
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
<<<<<<< HEAD
    -102,  -102,  -101,   -13,  -102,  -102,  -102,  -102,  -102,  -102,
      -1,    57,  -102,  -102,  -102,   190,  -102,  -102,  -102,   -93,
     -82,   203,  -102,  -102,  -102,  -102,  -102,  -102,   -34,  -102,
    -102,  -102,  -102
=======
    -124,  -124,  -123,   -12,  -124,  -124,  -124,  -124,  -124,    -1,
      51,  -124,  -124,  -124,   197,  -124,  -124,  -124,   -83,   154,
     210,  -124,  -124,  -124,  -124,  -124,  -124,   -32,  -124,  -124,
    -124,  -124
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
<<<<<<< HEAD
       0,     1,    14,    15,    16,    17,    18,    19,    20,    21,
      42,    23,   171,    24,    25,    26,    77,    27,   109,    43,
      44,    28,    29,   165,    30,    36,   176,   127,    45,    31,
      32,    33,    34
=======
       0,     1,    13,    14,    15,    16,    17,    18,    19,    41,
      21,   171,    22,    23,    24,    77,    25,   109,    42,    43,
      26,    27,   165,    28,    34,   176,   127,    44,    29,    30,
      31,    32
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
<<<<<<< HEAD
      22,    52,    67,   129,   130,   131,   132,    49,    59,    37,
      51,    73,    74,    22,   142,    60,    35,    94,    84,   136,
     137,   138,   139,   140,    58,    38,   156,    89,     9,     9,
       9,    64,    85,    39,    66,   143,   144,    40,    56,    41,
      50,    68,    61,    86,     2,    76,    78,     3,     4,    82,
       5,   162,   163,   164,     9,    75,    62,    80,    87,    88,
     166,     6,     9,    56,   181,   177,   178,   179,   180,   172,
      90,   122,    37,     7,   108,   190,    63,     8,    93,    57,
     115,     9,   117,   123,   124,   125,    95,   126,    38,   121,
      96,    10,    11,     9,   128,    53,    39,   106,    54,    57,
     100,    97,    41,    12,    13,    55,    57,     9,    57,   116,
     145,   146,    98,   107,    99,    57,    56,   114,     9,   149,
       9,    57,   110,    57,   154,   155,    22,   111,   133,    56,
     134,   195,   135,    57,   112,    57,   141,     3,     4,    57,
       5,   189,   150,    52,    57,    57,   151,     9,     9,    53,
     120,     6,    54,     9,   118,    22,    56,    56,   119,    55,
     148,     9,    56,     7,    22,    57,   152,     8,    52,   153,
      56,     9,    57,   158,    57,    22,   167,    52,    57,   159,
      22,    10,    11,   157,   160,    57,   161,     3,     4,   193,
     175,   194,   187,    12,    13,     9,     3,     4,   191,     5,
       9,     6,    57,    57,    56,    91,    57,   174,   196,    56,
       6,    57,    57,     7,    92,   188,     9,     8,     9,     9,
       9,     9,     7,   192,   197,    56,     8,    56,    56,    56,
       9,    10,    11,    37,   113,    65,     9,    79,   173,    59,
      10,    11,     0,    12,    13,    56,    60,   182,    83,    38,
      57,    57,    12,    13,   168,   169,   170,    39,   183,   184,
     185,    40,   147,    41,   186,     9,    81,     0,     9,     0,
     -35,   -35,     0,     0,    56,   -35,     0,    56,   101,   102,
     103,   104,   105,    69,    70,    71,    72,    46,    47,    48
=======
      20,    51,    66,    84,   156,     2,    48,    86,     3,    50,
       4,     8,    20,   129,   130,   131,   132,    85,     8,    94,
      55,     5,    57,   116,   148,   142,    33,    55,    89,    63,
       8,     8,    65,     6,     8,    60,    49,     7,    35,    72,
      55,     8,   181,    55,    76,    78,   143,   144,    82,    61,
      67,     9,    10,   190,    36,     8,    75,    87,    88,   168,
     169,   170,    37,    35,    11,    12,    38,    80,    39,    62,
      90,    56,    93,    95,   108,   177,   178,   179,   180,    36,
     115,    40,   117,    58,     8,   150,   106,    37,    35,   121,
      59,    38,    56,    39,   128,    96,     8,    73,    74,    56,
      97,    56,   107,    98,    36,    55,    40,     8,    56,     8,
     145,   146,    37,     8,    56,   100,    56,    99,    39,   149,
     141,   114,    55,    56,   154,   155,    20,    56,   195,    56,
     118,    40,     8,    56,   119,   110,   157,   120,    56,    56,
     111,    55,    52,   189,    51,    53,    52,   112,     8,    53,
     174,    91,    54,   151,     8,    20,    54,    55,     8,    56,
      92,     8,     8,    55,    20,     8,    56,    55,    56,    51,
      55,    55,    56,   152,    55,    20,   153,    83,    51,    56,
      20,   196,     3,   191,     4,     3,   158,     4,   159,   193,
     147,   194,     8,     8,     8,     5,    56,    56,     5,   167,
      56,    55,    55,    55,   113,    56,    56,     6,   160,    58,
       6,     7,   173,   161,     7,     8,    59,   187,     8,   182,
     188,     3,    81,   175,     8,     9,    10,   192,     9,    10,
     183,   184,   185,    55,     5,   122,   186,   197,    11,    12,
      64,    11,    12,    79,    56,    56,     6,   123,   124,   125,
       7,   126,     0,     0,     8,   136,   137,   138,   139,   140,
       0,   -33,   -33,     0,     9,    10,   -33,   101,   102,   103,
     104,   105,   133,     0,   134,     0,   135,    11,    12,    68,
      69,    70,    71,    45,    46,    47,     0,   162,   163,   164,
       0,     0,     0,     0,     0,     0,   166,     0,     0,     0,
       0,     0,     0,     0,     0,   172
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
       1,    14,    36,    96,    97,    98,    99,     8,    35,    16,
      11,    13,    14,    14,    36,    42,    35,    25,    13,   101,
     102,   103,   104,   105,    25,    32,   127,    61,    37,    37,
      37,    32,    27,    40,    35,    57,    58,    44,    46,    46,
      25,    45,    17,    26,     0,    46,    47,     3,     4,    50,
       6,   133,   134,   135,    37,    35,    31,    18,    59,    60,
     142,    17,    37,    46,   165,   158,   159,   160,   161,   151,
      44,    40,    16,    29,    75,   176,    51,    33,    26,    22,
      81,    37,    83,    52,    53,    54,    35,    56,    32,    90,
      43,    47,    48,    37,    95,    25,    40,    16,    28,    42,
      14,    43,    46,    59,    60,    35,    49,    37,    51,    26,
     111,   112,    43,    32,    43,    58,    46,    30,    37,   120,
      37,    64,    30,    66,   125,   126,   127,    35,     8,    46,
      10,     7,    12,    76,    42,    78,    25,     3,     4,    82,
       6,   175,    26,   156,    87,    88,    41,    37,    37,    25,
      35,    17,    28,    37,    26,   156,    46,    46,    26,    35,
      50,    37,    46,    29,   165,   108,    26,    33,   181,    26,
      46,    37,   115,    42,   117,   176,    26,   190,   121,    42,
     181,    47,    48,    25,    42,   128,    42,     3,     4,   190,
       6,   192,    26,    59,    60,    37,     3,     4,     5,     6,
      37,    17,   145,   146,    46,    26,   149,    26,    26,    46,
      17,   154,   155,    29,    35,    26,    37,    33,    37,    37,
      37,    37,    29,    35,    26,    46,    33,    46,    46,    46,
      37,    47,    48,    16,    30,    32,    37,    47,    55,    35,
      47,    48,    -1,    59,    60,    46,    42,    26,    49,    32,
     193,   194,    59,    60,    37,    38,    39,    40,    37,    38,
      39,    44,    34,    46,    43,    37,    35,    -1,    37,    -1,
      38,    39,    -1,    -1,    46,    43,    -1,    46,     8,     9,
      10,    11,    12,    21,    22,    23,    24,    18,    19,    20
=======
       1,    13,    34,    12,   127,     0,     7,    25,     3,    10,
       5,    36,    13,    96,    97,    98,    99,    26,    36,    24,
      45,    16,    23,    25,    49,    35,    34,    45,    60,    30,
      36,    36,    33,    28,    36,    16,    24,    32,    15,    40,
      45,    36,   165,    45,    45,    46,    56,    57,    49,    30,
      44,    46,    47,   176,    31,    36,    34,    58,    59,    36,
      37,    38,    39,    15,    59,    60,    43,    17,    45,    50,
      43,    20,    25,    34,    75,   158,   159,   160,   161,    31,
      81,    58,    83,    34,    36,    25,    15,    39,    15,    90,
      41,    43,    41,    45,    95,    42,    36,    12,    13,    48,
      42,    50,    31,    42,    31,    45,    58,    36,    57,    36,
     111,   112,    39,    36,    63,    13,    65,    42,    45,   120,
      24,    29,    45,    72,   125,   126,   127,    76,     6,    78,
      25,    58,    36,    82,    25,    29,    24,    34,    87,    88,
      34,    45,    24,   175,   156,    27,    24,    41,    36,    27,
      25,    25,    34,    40,    36,   156,    34,    45,    36,   108,
      34,    36,    36,    45,   165,    36,   115,    45,   117,   181,
      45,    45,   121,    25,    45,   176,    25,    48,   190,   128,
     181,    25,     3,     4,     5,     3,    41,     5,    41,   190,
      33,   192,    36,    36,    36,    16,   145,   146,    16,    25,
     149,    45,    45,    45,    29,   154,   155,    28,    41,    34,
      28,    32,    54,    41,    32,    36,    41,    25,    36,    25,
      25,     3,    34,     5,    36,    46,    47,    34,    46,    47,
      36,    37,    38,    45,    16,    39,    42,    25,    59,    60,
      30,    59,    60,    46,   193,   194,    28,    51,    52,    53,
      32,    55,    -1,    -1,    36,   101,   102,   103,   104,   105,
      -1,    37,    38,    -1,    46,    47,    42,     7,     8,     9,
      10,    11,     7,    -1,     9,    -1,    11,    59,    60,    20,
      21,    22,    23,    17,    18,    19,    -1,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
<<<<<<< HEAD
       0,    62,     0,     3,     4,     6,    17,    29,    33,    37,
      47,    48,    59,    60,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    74,    75,    76,    78,    82,    83,
      85,    90,    91,    92,    93,    35,    86,    16,    32,    40,
      44,    46,    71,    80,    81,    89,    18,    19,    20,    71,
      25,    71,    64,    25,    28,    35,    46,    72,    71,    35,
      42,    17,    31,    51,    71,    82,    71,    89,    45,    21,
      22,    23,    24,    13,    14,    35,    71,    77,    71,    76,
      18,    35,    71,    49,    13,    27,    26,    71,    71,    89,
      44,    26,    35,    26,    25,    35,    43,    43,    43,    43,
      14,     8,     9,    10,    11,    12,    16,    32,    71,    79,
      30,    35,    42,    30,    30,    71,    26,    71,    26,    26,
      35,    71,    40,    52,    53,    54,    56,    88,    71,    80,
      80,    80,    80,     8,    10,    12,    81,    81,    81,    81,
      81,    25,    36,    57,    58,    71,    71,    34,    50,    71,
      26,    41,    26,    26,    71,    71,    63,    25,    42,    42,
      42,    42,    81,    81,    81,    84,    81,    26,    37,    38,
      39,    73,    81,    55,    26,     6,    87,    80,    80,    80,
      80,    63,    26,    37,    38,    39,    43,    26,    26,    89,
      63,     5,    35,    71,    71,     7,    26,    26
=======
       0,    62,     0,     3,     5,    16,    28,    32,    36,    46,
      47,    59,    60,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    73,    74,    75,    77,    81,    82,    84,    89,
      90,    91,    92,    34,    85,    15,    31,    39,    43,    45,
      58,    70,    79,    80,    88,    17,    18,    19,    70,    24,
      70,    64,    24,    27,    34,    45,    71,    70,    34,    41,
      16,    30,    50,    70,    81,    70,    88,    44,    20,    21,
      22,    23,    70,    12,    13,    34,    70,    76,    70,    75,
      17,    34,    70,    48,    12,    26,    25,    70,    70,    88,
      43,    25,    34,    25,    24,    34,    42,    42,    42,    42,
      13,     7,     8,     9,    10,    11,    15,    31,    70,    78,
      29,    34,    41,    29,    29,    70,    25,    70,    25,    25,
      34,    70,    39,    51,    52,    53,    55,    87,    70,    79,
      79,    79,    79,     7,     9,    11,    80,    80,    80,    80,
      80,    24,    35,    56,    57,    70,    70,    33,    49,    70,
      25,    40,    25,    25,    70,    70,    63,    24,    41,    41,
      41,    41,    80,    80,    80,    83,    80,    25,    36,    37,
      38,    72,    80,    54,    25,     5,    86,    79,    79,    79,
      79,    63,    25,    36,    37,    38,    42,    25,    25,    88,
      63,     4,    34,    70,    70,     6,    25,    25
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
<<<<<<< HEAD
      64,    65,    66,    67,    68,    69,    70,    70,    70,    71,
      71,    71,    72,    73,    73,    73,    73,    73,    73,    73,
      74,    75,    76,    76,    76,    77,    77,    77,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    80,    80,    81,
      81,    81,    81,    81,    82,    82,    82,    84,    83,    86,
      87,    85,    88,    85,    89,    89,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    91,    92,    93
=======
      65,    66,    67,    68,    69,    69,    69,    70,    70,    70,
      71,    72,    72,    72,    72,    72,    72,    72,    73,    74,
      75,    75,    75,    76,    76,    76,    77,    77,    77,    78,
      78,    78,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    81,    81,    81,    83,    82,    85,    86,
      84,    87,    84,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    91,    92
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
<<<<<<< HEAD
       1,     1,     5,     4,     6,     5,     4,     4,     2,     1,
       2,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     2,     1,     3,     3,     1,     3,     3,     4,     4,
       4,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       6,     6,     6,     6,     6,     5,     5,     0,     8,     0,
       0,    11,     0,    11,     4,     4,     4,     4,     4,     5,
       5,     5,     2,     3,     3,     7,     7,     5,     5,     7,
       6,     2,     1,     1
=======
       5,     4,     6,     5,     4,     4,     2,     1,     2,     2,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     2,
       1,     3,     3,     1,     3,     3,     4,     4,     4,     1,
       1,     1,     1,     2,     1,     1,     2,     1,     1,     6,
       6,     6,     6,     6,     5,     5,     0,     8,     0,     0,
      11,     0,    11,     4,     4,     4,     4,     4,     5,     5,
       5,     2,     3,     3,     7,     7,     5,     5,     7,     6,
       2,     1,     1
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 1347 "src/parser.tab.c"
    break;

  case 5: /* bloco: bloco instrucao  */
#line 77 "src/parser.y"
                               {  }
#line 1353 "src/parser.tab.c"
    break;

  case 21: /* saida: FINALIZACAO  */
#line 99 "src/parser.y"
                {
        gerar_exit();
    }
#line 1358 "src/parser.tab.c"
    break;

  case 22: /* declaracaoCenario: ABRE_PARENTESES texto VIRGULA texto FECHA_PARENTESES  */
#line 107 "src/parser.y"
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
#line 1376 "src/parser.tab.c"
=======
#line 1371 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 23: /* concatenarCenario: ADICIONAR_CENARIO INICIO texto FIM  */
#line 122 "src/parser.y"
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
#line 1399 "src/parser.tab.c"
=======
#line 1394 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 24: /* substituiCenario: SUBSTITUIR_CENARIO texto POR texto NO_CENARIO FIM  */
#line 142 "src/parser.y"
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
#line 1420 "src/parser.tab.c"
=======
#line 1415 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 25: /* trocarCenario: inicioDialogo VOLTAR_CENARIO ARTIGO texto FIM  */
#line 161 "src/parser.y"
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
#line 1443 "src/parser.tab.c"
=======
#line 1438 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 26: /* declaracaoQuestionamento: texto INTERROGACAO NAO FIM  */
#line 180 "src/parser.y"
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
#line 1461 "src/parser.tab.c"
=======
#line 1456 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 27: /* declaracaoQuestionamento: texto INTERROGACAO SIM FIM  */
#line 193 "src/parser.y"
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
#line 1479 "src/parser.tab.c"
=======
#line 1474 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 28: /* declaracaoQuestionamento: texto INTERROGACAO  */
#line 206 "src/parser.y"
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
#line 1497 "src/parser.tab.c"
=======
#line 1492 "src/parser.tab.c"
    break;

  case 27: /* texto: palavra  */
#line 216 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1500 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 29: /* texto: palavra  */
#line 222 "src/parser.y"
            { 
        (yyval.texto) = strdup((yyvsp[0].texto));
    }
#line 1505 "src/parser.tab.c"
    break;

  case 30: /* texto: texto NUMERO  */
#line 225 "src/parser.y"
                   {
        //  if (DEBUG_BISON) {
        //      printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
<<<<<<< HEAD
#line 1516 "src/parser.tab.c"
=======
#line 1511 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 31: /* texto: texto palavra  */
#line 231 "src/parser.y"
                    {
        // if (DEBUG_BISON) {
        //     printf("Concatenando: %s + %s\n", $1, $2);
        // }
        (yyval.texto) = concatena((yyvsp[-1].texto), (yyvsp[0].texto));
    }
<<<<<<< HEAD
#line 1527 "src/parser.tab.c"
=======
#line 1522 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 32: /* palavra: TOKEN  */
#line 241 "src/parser.y"
          { (yyval.texto) = strdup((yyvsp[0].texto)); }
<<<<<<< HEAD
#line 1533 "src/parser.tab.c"
=======
#line 1528 "src/parser.tab.c"
    break;

  case 31: /* adjetivos: ADJETIVO_POSITIVO  */
#line 239 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1536 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 33: /* adjetivos: ADJETIVO_POSITIVO  */
#line 245 "src/parser.y"
                      { 
        (yyval.inteiro) = 1;
    }
#line 1544 "src/parser.tab.c"
    break;

  case 34: /* adjetivos: ADJETIVO_NEGATIVO  */
#line 248 "src/parser.y"
                        {
        (yyval.inteiro) = -1;
    }
#line 1552 "src/parser.tab.c"
    break;

  case 35: /* adjetivos: TOKEN  */
#line 251 "src/parser.y"
            {
        (yyval.inteiro) = 0;
    }
#line 1557 "src/parser.tab.c"
    break;

  case 36: /* adjetivos: adjetivos ADJETIVO_POSITIVO  */
#line 254 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) + 1;
    }
<<<<<<< HEAD
#line 1568 "src/parser.tab.c"
=======
#line 1563 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 37: /* adjetivos: adjetivos ADJETIVO_NEGATIVO  */
#line 260 "src/parser.y"
                                  {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", (yyvsp[0].texto));
        }
        (yyval.inteiro) = (yyvsp[-1].inteiro) - 1;
    }
<<<<<<< HEAD
#line 1579 "src/parser.tab.c"
=======
#line 1574 "src/parser.tab.c"
    break;

  case 36: /* adjetivos: adjetivos TOKEN  */
#line 260 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1582 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 38: /* adjetivos: adjetivos TOKEN  */
#line 266 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1590 "src/parser.tab.c"
    break;

  case 39: /* adjetivos: adjetivos ENTRE  */
#line 269 "src/parser.y"
                      {
        (yyval.inteiro) = (yyvsp[-1].inteiro);
    }
#line 1595 "src/parser.tab.c"
    break;

  case 40: /* declaracao: declaracaoInicio texto FIM  */
#line 274 "src/parser.y"
                               {
        if (DEBUG_BISON) {
            printf("Declaração: %s\n", (yyvsp[-1].texto));
        }
    }
<<<<<<< HEAD
#line 1605 "src/parser.tab.c"
=======
#line 1600 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 41: /* declaracaoInicio: texto VIRGULA  */
#line 281 "src/parser.y"
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
#line 1619 "src/parser.tab.c"
=======
#line 1614 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 42: /* personagensEntrando: texto  */
#line 292 "src/parser.y"
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
<<<<<<< HEAD
#line 1636 "src/parser.tab.c"
=======
#line 1631 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 43: /* personagensEntrando: personagensEntrando VIRGULA texto  */
#line 304 "src/parser.y"
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
<<<<<<< HEAD
#line 1653 "src/parser.tab.c"
=======
#line 1648 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    break;

  case 44: /* personagensEntrando: personagensEntrando E texto  */
#line 316 "src/parser.y"
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
<<<<<<< HEAD
#line 1670 "src/parser.tab.c"
    break;

  case 45: /* personagensSaindo: texto  */
#line 329 "src/parser.y"
=======
#line 1665 "src/parser.tab.c"
    break;

  case 43: /* personagensSaindo: texto  */
#line 324 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 1686 "src/parser.tab.c"
    break;

  case 46: /* personagensSaindo: personagensSaindo VIRGULA texto  */
#line 340 "src/parser.y"
=======
#line 1681 "src/parser.tab.c"
    break;

  case 44: /* personagensSaindo: personagensSaindo VIRGULA texto  */
#line 335 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 1702 "src/parser.tab.c"
    break;

  case 47: /* personagensSaindo: personagensSaindo E texto  */
#line 351 "src/parser.y"
=======
#line 1697 "src/parser.tab.c"
    break;

  case 45: /* personagensSaindo: personagensSaindo E texto  */
#line 346 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 1718 "src/parser.tab.c"
    break;

  case 48: /* alteracaoElenco: ABRE_COLCHETES ENTRAM personagensEntrando FECHA_COLCHETES  */
#line 364 "src/parser.y"
=======
#line 1713 "src/parser.tab.c"
    break;

  case 46: /* alteracaoElenco: ABRE_COLCHETES ENTRAM personagensEntrando FECHA_COLCHETES  */
#line 359 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 1736 "src/parser.tab.c"
    break;

  case 49: /* alteracaoElenco: ABRE_COLCHETES SAEM personagensSaindo FECHA_COLCHETES  */
#line 377 "src/parser.y"
=======
#line 1731 "src/parser.tab.c"
    break;

  case 47: /* alteracaoElenco: ABRE_COLCHETES SAEM personagensSaindo FECHA_COLCHETES  */
#line 372 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 1754 "src/parser.tab.c"
    break;

  case 50: /* alteracaoElenco: ABRE_COLCHETES TODOS SAEM FECHA_COLCHETES  */
#line 390 "src/parser.y"
=======
#line 1749 "src/parser.tab.c"
    break;

  case 48: /* alteracaoElenco: ABRE_COLCHETES TODOS SAEM FECHA_COLCHETES  */
#line 385 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
                                                {
        if (DEBUG_BISON) {
            printf("Todos os personagens estão inativos\n");
        }
        // Ativa todos os personagens
        desativar_todos_personagens();
    }
<<<<<<< HEAD
#line 1766 "src/parser.tab.c"
    break;

  case 51: /* personagem: EU  */
#line 399 "src/parser.y"
       {
        (yyval.texto) = personagemQueFala;
=======
#line 1761 "src/parser.tab.c"
    break;

  case 49: /* personagem: EU  */
#line 394 "src/parser.y"
       {
        (yyval.texto) = personagemQueFala;
    }
#line 1769 "src/parser.tab.c"
    break;

  case 50: /* personagem: VOCE  */
#line 397 "src/parser.y"
           {
        (yyval.texto) = personagemVoce;
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    }
#line 1777 "src/parser.tab.c"
    break;

<<<<<<< HEAD
  case 52: /* personagem: VOCE  */
#line 402 "src/parser.y"
           {
        (yyval.texto) = personagemVoce;
=======
  case 51: /* personagem: texto  */
#line 400 "src/parser.y"
            {
        (yyval.texto) = (yyvsp[0].texto);
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
    }
#line 1785 "src/parser.tab.c"
    break;

<<<<<<< HEAD
  case 53: /* personagem: texto  */
#line 405 "src/parser.y"
            {
        (yyval.texto) = (yyvsp[0].texto);
    }
#line 1790 "src/parser.tab.c"
    break;

  case 54: /* valor: NUMERO  */
#line 410 "src/parser.y"
=======
  case 52: /* valor: NUMERO  */
#line 405 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
           {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi((yyvsp[0].texto)));
        }
        (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), atoi((yyvsp[0].texto)), 0);
    }
<<<<<<< HEAD
#line 1801 "src/parser.tab.c"
    break;

  case 55: /* valor: TU MESMO  */
#line 416 "src/parser.y"
=======
#line 1796 "src/parser.tab.c"
    break;

  case 53: /* valor: TU MESMO  */
#line 411 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 1824 "src/parser.tab.c"
    break;

  case 56: /* valor: EU  */
#line 434 "src/parser.y"
=======
#line 1819 "src/parser.tab.c"
    break;

  case 54: /* valor: EU  */
#line 429 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 1846 "src/parser.tab.c"
    break;

  case 57: /* valor: VOCE  */
#line 451 "src/parser.y"
=======
#line 1841 "src/parser.tab.c"
    break;

  case 55: /* valor: VOCE  */
#line 446 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 1868 "src/parser.tab.c"
    break;

  case 58: /* valor: texto  */
#line 468 "src/parser.y"
=======
#line 1863 "src/parser.tab.c"
    break;

  case 56: /* valor: O_TAMANHO_DE texto  */
#line 463 "src/parser.y"
                         {
        // $2 é o nome da pilha (const char*)
        const char* nome_pilha = (yyvsp[0].texto);
        Symbol* sym = get_symbol(nome_pilha);

        // Valida se a variável existe e é uma pilha
        if (!sym || sym->type != INT_VAR) {
            printf("Variável de pilha inválida ou não declarada: %s\n", nome_pilha);
            (yyval.llmValueRef) = LLVMConstInt(LLVMInt32Type(), 0, 0); // Retorna 0 em caso de erro
        } else {
            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_size");

            // 2. Gera a chamada ao runtime para obter o tamanho da pilha
            (yyval.llmValueRef) = gerar_obter_tamanho_pilha(pilha_ptr);
        }
    }
#line 1885 "src/parser.tab.c"
    break;

  case 57: /* valor: texto  */
#line 480 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
<<<<<<< HEAD
#line 1885 "src/parser.tab.c"
    break;

  case 59: /* expressao: valor  */
#line 483 "src/parser.y"
          {
        (yyval.llmValueRef) = (yyvsp[0].llmValueRef); // valor já retorna LLVMValueRef
    }
#line 1893 "src/parser.tab.c"
    break;

  case 60: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 486 "src/parser.y"
=======
#line 1902 "src/parser.tab.c"
    break;

  case 58: /* expressao: valor  */
#line 495 "src/parser.y"
          {
        (yyval.llmValueRef) = (yyvsp[0].llmValueRef); // valor já retorna LLVMValueRef
    }
#line 1910 "src/parser.tab.c"
    break;

  case 59: /* expressao: ARTIGO SOMAR ENTRE valor E valor  */
#line 498 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
                                     {
        if (DEBUG_BISON) printf("Expressão de soma\n");
        (yyval.llmValueRef) = LLVMBuildAdd(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "addtmp");
    }
<<<<<<< HEAD
#line 1902 "src/parser.tab.c"
    break;

  case 61: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 490 "src/parser.y"
=======
#line 1919 "src/parser.tab.c"
    break;

  case 60: /* expressao: ARTIGO SUBTRAIR ENTRE valor E valor  */
#line 502 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
                                        {
        if (DEBUG_BISON) printf("Expressão de subtração\n");
        (yyval.llmValueRef) = LLVMBuildSub(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "subtmp");
    }
<<<<<<< HEAD
#line 1911 "src/parser.tab.c"
    break;

  case 62: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 494 "src/parser.y"
=======
#line 1928 "src/parser.tab.c"
    break;

  case 61: /* expressao: ARTIGO MULTIPLICAR ENTRE valor E valor  */
#line 506 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
                                           {
        if (DEBUG_BISON) printf("Expressão de multiplicação\n");
        (yyval.llmValueRef) = LLVMBuildMul(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "multmp");
    }
<<<<<<< HEAD
#line 1920 "src/parser.tab.c"
    break;

  case 63: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 498 "src/parser.y"
=======
#line 1937 "src/parser.tab.c"
    break;

  case 62: /* expressao: ARTIGO DIVIDIR ENTRE valor E valor  */
#line 510 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
                                       {
        if (DEBUG_BISON) printf("Expressão de divisão\n");

        // Divisão por zero em tempo de compilação não pode ser detectada aqui
        (yyval.llmValueRef) = LLVMBuildSDiv(builder, (yyvsp[-2].llmValueRef), (yyvsp[0].llmValueRef), "divtmp");
    }
<<<<<<< HEAD
#line 1931 "src/parser.tab.c"
    break;

  case 64: /* if_sentenca: SE condicao VIRGULA personagem SERA expressao  */
#line 507 "src/parser.y"
=======
#line 1948 "src/parser.tab.c"
    break;

  case 63: /* if_sentenca: SE condicao VIRGULA personagem SERA expressao  */
#line 519 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 1974 "src/parser.tab.c"
    break;

  case 65: /* if_sentenca: SE condicao VIRGULA personagem IF_MOSTRA_VALOR  */
#line 545 "src/parser.y"
=======
#line 1991 "src/parser.tab.c"
    break;

  case 64: /* if_sentenca: SE condicao VIRGULA personagem IF_MOSTRA_VALOR  */
#line 557 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2010 "src/parser.tab.c"
    break;

  case 66: /* if_sentenca: SE condicao VIRGULA personagem IF_LE_VALOR  */
#line 576 "src/parser.y"
=======
#line 2027 "src/parser.tab.c"
    break;

  case 65: /* if_sentenca: SE condicao VIRGULA personagem IF_LE_VALOR  */
#line 588 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2039 "src/parser.tab.c"
    break;

  case 67: /* $@1: %empty  */
#line 603 "src/parser.y"
=======
#line 2056 "src/parser.tab.c"
    break;

  case 66: /* $@1: %empty  */
#line 615 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2059 "src/parser.tab.c"
    break;

  case 68: /* if_bloco: SE condicao VIRGULA texto INICIO $@1 bloco ENDIF  */
#line 619 "src/parser.y"
=======
#line 2076 "src/parser.tab.c"
    break;

  case 67: /* if_bloco: SE condicao VIRGULA texto INICIO $@1 bloco ENDIF  */
#line 631 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2083 "src/parser.tab.c"
    break;

  case 69: /* $@2: %empty  */
#line 642 "src/parser.y"
=======
#line 2100 "src/parser.tab.c"
    break;

  case 68: /* $@2: %empty  */
#line 654 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2106 "src/parser.tab.c"
    break;

  case 70: /* $@3: %empty  */
#line 661 "src/parser.y"
=======
#line 2123 "src/parser.tab.c"
    break;

  case 69: /* $@3: %empty  */
#line 673 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2123 "src/parser.tab.c"
    break;

  case 71: /* while: ENQUANTO_COMECO $@2 condicao VIRGULA texto INICIO $@3 bloco texto ENQUANTO_FIM FIM  */
#line 674 "src/parser.y"
=======
#line 2140 "src/parser.tab.c"
    break;

  case 70: /* while: ENQUANTO_COMECO $@2 condicao VIRGULA texto INICIO $@3 bloco texto ENQUANTO_FIM FIM  */
#line 686 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2139 "src/parser.tab.c"
    break;

  case 72: /* $@4: %empty  */
#line 686 "src/parser.y"
=======
#line 2156 "src/parser.tab.c"
    break;

  case 71: /* $@4: %empty  */
#line 698 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2158 "src/parser.tab.c"
    break;

  case 73: /* while: FACA VIRGULA texto INICIO $@4 bloco ENQUANTO_COMECO condicao VIRGULA texto FIM  */
#line 701 "src/parser.y"
=======
#line 2175 "src/parser.tab.c"
    break;

  case 72: /* while: FACA VIRGULA texto INICIO $@4 bloco ENQUANTO_COMECO condicao VIRGULA texto FIM  */
#line 713 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2185 "src/parser.tab.c"
    break;

  case 74: /* condicao: expressao FOR MAIOR expressao  */
#line 725 "src/parser.y"
                                      {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpgt");
=======
#line 2202 "src/parser.tab.c"
    break;

  case 73: /* condicao: expressao FOR MAIOR expressao  */
#line 737 "src/parser.y"
                                      {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpgt");
        }
#line 2210 "src/parser.tab.c"
    break;

  case 74: /* condicao: expressao FOR MAIOR_IGUAL expressao  */
#line 740 "src/parser.y"
                                          {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpge");
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
        }
#line 2218 "src/parser.tab.c"
    break;

<<<<<<< HEAD
  case 75: /* condicao: expressao FOR MAIOR_IGUAL expressao  */
#line 728 "src/parser.y"
                                          {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpge");
=======
  case 75: /* condicao: expressao FOR MENOR expressao  */
#line 743 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmplt");
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
        }
#line 2226 "src/parser.tab.c"
    break;

<<<<<<< HEAD
  case 76: /* condicao: expressao FOR MENOR expressao  */
#line 731 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLT, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmplt");
=======
  case 76: /* condicao: expressao FOR MENOR_IGUAL expressao  */
#line 746 "src/parser.y"
                                          {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmple");
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
        }
#line 2234 "src/parser.tab.c"
    break;

<<<<<<< HEAD
  case 77: /* condicao: expressao FOR MENOR_IGUAL expressao  */
#line 734 "src/parser.y"
                                          {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmple");
=======
  case 77: /* condicao: expressao FOR IGUAL expressao  */
#line 749 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpeq");
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
        }
#line 2242 "src/parser.tab.c"
    break;

<<<<<<< HEAD
  case 78: /* condicao: expressao FOR IGUAL expressao  */
#line 737 "src/parser.y"
                                    {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-3].llmValueRef), (yyvsp[0].llmValueRef), "cmpeq");
=======
  case 78: /* condicao: expressao NAO FOR MENOR expressao  */
#line 752 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpnlt");
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
        }
#line 2250 "src/parser.tab.c"
    break;

<<<<<<< HEAD
  case 79: /* condicao: expressao NAO FOR MENOR expressao  */
#line 740 "src/parser.y"
=======
  case 79: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 755 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpnlt");
        }
#line 2258 "src/parser.tab.c"
    break;

<<<<<<< HEAD
  case 80: /* condicao: expressao NAO FOR MAIOR expressao  */
#line 743 "src/parser.y"
=======
  case 80: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 758 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpngt");
        }
#line 2266 "src/parser.tab.c"
    break;

<<<<<<< HEAD
  case 81: /* condicao: expressao NAO FOR IGUAL expressao  */
#line 746 "src/parser.y"
                                        {
            (yyval.llmValueRef) = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-4].llmValueRef), (yyvsp[0].llmValueRef), "cmpneq");
        }
#line 2249 "src/parser.tab.c"
    break;

  case 82: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 752 "src/parser.y"
=======
  case 81: /* dialogo: inicioDialogo MOSTRAR_CENARIO  */
#line 764 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
                                  {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
        atualiza_personagemVoce();
    }
<<<<<<< HEAD
#line 2261 "src/parser.tab.c"
    break;

  case 83: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 759 "src/parser.y"
=======
#line 2278 "src/parser.tab.c"
    break;

  case 82: /* dialogo: inicioDialogo if_sentenca FIM  */
#line 771 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
                                    {
        if (DEBUG_BISON) {
            printf("if sentença\n");
        }
        atualiza_personagemVoce();
    }
<<<<<<< HEAD
#line 2272 "src/parser.tab.c"
    break;

  case 84: /* dialogo: inicioDialogo texto FIM  */
#line 765 "src/parser.y"
=======
#line 2289 "src/parser.tab.c"
    break;

  case 83: /* dialogo: inicioDialogo texto FIM  */
#line 777 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2292 "src/parser.tab.c"
    break;

  case 85: /* dialogo: inicioDialogo texto VIRGULA TU EH expressao FIM  */
#line 780 "src/parser.y"
=======
#line 2309 "src/parser.tab.c"
    break;

  case 84: /* dialogo: inicioDialogo texto VIRGULA TU EH expressao FIM  */
#line 792 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
<<<<<<< HEAD
#line 2320 "src/parser.tab.c"
    break;

  case 86: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 803 "src/parser.y"
=======
#line 2337 "src/parser.tab.c"
    break;

  case 85: /* dialogo: inicioDialogo texto VIRGULA TU EH adjetivos FIM  */
#line 815 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
<<<<<<< HEAD
#line 2364 "src/parser.tab.c"
    break;

  case 87: /* dialogo: inicioDialogo texto VIRGULA MOSTRA_VALOR FIM  */
#line 843 "src/parser.y"
=======
#line 2381 "src/parser.tab.c"
    break;

  case 86: /* dialogo: inicioDialogo texto VIRGULA MOSTRA_VALOR FIM  */
#line 855 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
<<<<<<< HEAD
#line 2389 "src/parser.tab.c"
    break;

  case 88: /* dialogo: inicioDialogo texto VIRGULA LE_VALOR FIM  */
#line 863 "src/parser.y"
=======
#line 2406 "src/parser.tab.c"
    break;

  case 87: /* dialogo: inicioDialogo texto VIRGULA LE_VALOR FIM  */
#line 875 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2410 "src/parser.tab.c"
    break;

  case 89: /* dialogo: inicioDialogo texto VIRGULA GUARDE texto INTERIOR FIM  */
#line 879 "src/parser.y"
=======
#line 2427 "src/parser.tab.c"
    break;

  case 88: /* dialogo: inicioDialogo texto VIRGULA GUARDE texto INTERIOR FIM  */
#line 891 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
<<<<<<< HEAD
#line 2430 "src/parser.tab.c"
    break;

  case 90: /* dialogo: inicioDialogo texto VIRGULA LEMBRE texto FIM  */
#line 894 "src/parser.y"
=======
#line 2447 "src/parser.tab.c"
    break;

  case 89: /* dialogo: inicioDialogo texto VIRGULA LEMBRE texto FIM  */
#line 906 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
<<<<<<< HEAD
#line 2447 "src/parser.tab.c"
    break;

  case 91: /* inicioDialogo: texto INICIO  */
#line 909 "src/parser.y"
=======
#line 2464 "src/parser.tab.c"
    break;

  case 90: /* inicioDialogo: texto INICIO  */
#line 921 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2483 "src/parser.tab.c"
    break;

  case 92: /* ato: ATO  */
#line 942 "src/parser.y"
=======
#line 2500 "src/parser.tab.c"
    break;

  case 91: /* ato: ATO  */
#line 954 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2500 "src/parser.tab.c"
    break;

  case 93: /* cena: CENA  */
#line 956 "src/parser.y"
=======
#line 2517 "src/parser.tab.c"
    break;

  case 92: /* cena: CENA  */
#line 968 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
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
#line 2517 "src/parser.tab.c"
    break;


#line 2521 "src/parser.tab.c"
=======
#line 2534 "src/parser.tab.c"
    break;


#line 2538 "src/parser.tab.c"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647

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
#line 970 "src/parser.y"
=======
#line 982 "src/parser.y"
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647


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
