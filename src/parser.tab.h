/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_PARSER_TAB_H_INCLUDED
# define YY_YY_SRC_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "src/parser.y"

  #include "../include/nrUtils.h"
  #include "../include/LLVMgen.h"

// Variável global para a nossa pilha.
PilhaControleFluxo pilhaControleFluxo;

#line 57 "src/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FACA = 258,                    /* FACA  */
    ENDIF = 259,                   /* ENDIF  */
    ENQUANTO_COMECO = 260,         /* ENQUANTO_COMECO  */
    ENQUANTO_FIM = 261,            /* ENQUANTO_FIM  */
    MAIOR = 262,                   /* MAIOR  */
    MENOR = 263,                   /* MENOR  */
    IGUAL = 264,                   /* IGUAL  */
    NAO = 265,                     /* NAO  */
    FOR = 266,                     /* FOR  */
    ENTAO = 267,                   /* ENTAO  */
    EU = 268,                      /* EU  */
    SE = 269,                      /* SE  */
    SAEM = 270,                    /* SAEM  */
    ENTRAM = 271,                  /* ENTRAM  */
    TODOS = 272,                   /* TODOS  */
    SOMAR = 273,                   /* SOMAR  */
    SUBTRAIR = 274,                /* SUBTRAIR  */
    DIVIDIR = 275,                 /* DIVIDIR  */
    MULTIPLICAR = 276,             /* MULTIPLICAR  */
    INICIO = 277,                  /* INICIO  */
    FIM = 278,                     /* FIM  */
    SIM = 279,                     /* SIM  */
    INTERROGACAO = 280,            /* INTERROGACAO  */
    ABRE_COLCHETES = 281,          /* ABRE_COLCHETES  */
    FECHA_COLCHETES = 282,         /* FECHA_COLCHETES  */
    VOLTAR_CENARIO = 283,          /* VOLTAR_CENARIO  */
    VOCE = 284,                    /* VOCE  */
    ABRE_PARENTESES = 285,         /* ABRE_PARENTESES  */
    FECHA_PARENTESES = 286,        /* FECHA_PARENTESES  */
    VIRGULA = 287,                 /* VIRGULA  */
    SERA = 288,                    /* SERA  */
    TOKEN = 289,                   /* TOKEN  */
    ADJETIVO_POSITIVO = 290,       /* ADJETIVO_POSITIVO  */
    ADJETIVO_NEGATIVO = 291,       /* ADJETIVO_NEGATIVO  */
    TU = 292,                      /* TU  */
    EH = 293,                      /* EH  */
    E = 294,                       /* E  */
    ENTRE = 295,                   /* ENTRE  */
    ARTIGO = 296,                  /* ARTIGO  */
    MESMO = 297,                   /* MESMO  */
    NUMERO = 298,                  /* NUMERO  */
    ADICIONAR_CENARIO = 299,       /* ADICIONAR_CENARIO  */
    SUBSTITUIR_CENARIO = 300,      /* SUBSTITUIR_CENARIO  */
    POR = 301,                     /* POR  */
    NO_CENARIO = 302,              /* NO_CENARIO  */
    MOSTRAR_CENARIO = 303,         /* MOSTRAR_CENARIO  */
    MOSTRA_VALOR = 304,            /* MOSTRA_VALOR  */
    LE_VALOR = 305,                /* LE_VALOR  */
    GUARDE = 306,                  /* GUARDE  */
    INTERIOR = 307,                /* INTERIOR  */
    LEMBRE = 308,                  /* LEMBRE  */
    ATO = 309,                     /* ATO  */
    CENA = 310                     /* CENA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 51 "src/parser.y"

    char* texto;
    int inteiro;
    LLVMValueRef llmValueRef; // Referência para valores LLM

#line 135 "src/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_PARSER_TAB_H_INCLUDED  */
