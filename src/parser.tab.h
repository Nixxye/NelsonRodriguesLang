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

#line 54 "src/parser.tab.h"

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
    MAIOR_IGUAL = 263,             /* MAIOR_IGUAL  */
    MENOR = 264,                   /* MENOR  */
    MENOR_IGUAL = 265,             /* MENOR_IGUAL  */
    IGUAL = 266,                   /* IGUAL  */
    NAO = 267,                     /* NAO  */
    FOR = 268,                     /* FOR  */
    ENTAO = 269,                   /* ENTAO  */
    EU = 270,                      /* EU  */
    SE = 271,                      /* SE  */
    SAEM = 272,                    /* SAEM  */
    ENTRAM = 273,                  /* ENTRAM  */
    TODOS = 274,                   /* TODOS  */
    SOMAR = 275,                   /* SOMAR  */
    SUBTRAIR = 276,                /* SUBTRAIR  */
    DIVIDIR = 277,                 /* DIVIDIR  */
    MULTIPLICAR = 278,             /* MULTIPLICAR  */
    INICIO = 279,                  /* INICIO  */
    FIM = 280,                     /* FIM  */
    SIM = 281,                     /* SIM  */
    INTERROGACAO = 282,            /* INTERROGACAO  */
    ABRE_COLCHETES = 283,          /* ABRE_COLCHETES  */
    FECHA_COLCHETES = 284,         /* FECHA_COLCHETES  */
    VOLTAR_CENARIO = 285,          /* VOLTAR_CENARIO  */
    VOCE = 286,                    /* VOCE  */
    ABRE_PARENTESES = 287,         /* ABRE_PARENTESES  */
    FECHA_PARENTESES = 288,        /* FECHA_PARENTESES  */
    VIRGULA = 289,                 /* VIRGULA  */
    SERA = 290,                    /* SERA  */
    TOKEN = 291,                   /* TOKEN  */
    ADJETIVO_POSITIVO = 292,       /* ADJETIVO_POSITIVO  */
    ADJETIVO_NEGATIVO = 293,       /* ADJETIVO_NEGATIVO  */
    TU = 294,                      /* TU  */
    EH = 295,                      /* EH  */
    E = 296,                       /* E  */
    ENTRE = 297,                   /* ENTRE  */
    ARTIGO = 298,                  /* ARTIGO  */
    MESMO = 299,                   /* MESMO  */
    NUMERO = 300,                  /* NUMERO  */
    ADICIONAR_CENARIO = 301,       /* ADICIONAR_CENARIO  */
    SUBSTITUIR_CENARIO = 302,      /* SUBSTITUIR_CENARIO  */
    POR = 303,                     /* POR  */
    NO_CENARIO = 304,              /* NO_CENARIO  */
    MOSTRAR_CENARIO = 305,         /* MOSTRAR_CENARIO  */
    MOSTRA_VALOR = 306,            /* MOSTRA_VALOR  */
    LE_VALOR = 307,                /* LE_VALOR  */
    GUARDE = 308,                  /* GUARDE  */
    INTERIOR = 309,                /* INTERIOR  */
    LEMBRE = 310,                  /* LEMBRE  */
    IF_MOSTRA_VALOR = 311,         /* IF_MOSTRA_VALOR  */
    IF_LE_VALOR = 312,             /* IF_LE_VALOR  */
    ATO = 313,                     /* ATO  */
    CENA = 314                     /* CENA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "src/parser.y"

    char* texto;
    int inteiro;
    LLVMValueRef llmValueRef; // Referência para valores LLM

#line 136 "src/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_PARSER_TAB_H_INCLUDED  */
