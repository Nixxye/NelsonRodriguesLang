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
    FINALIZACAO = 258,             /* FINALIZACAO  */
    FACA = 259,                    /* FACA  */
    ENDIF = 260,                   /* ENDIF  */
    ENQUANTO_COMECO = 261,         /* ENQUANTO_COMECO  */
    ENQUANTO_FIM = 262,            /* ENQUANTO_FIM  */
    MAIOR = 263,                   /* MAIOR  */
    MAIOR_IGUAL = 264,             /* MAIOR_IGUAL  */
    MENOR = 265,                   /* MENOR  */
    MENOR_IGUAL = 266,             /* MENOR_IGUAL  */
    IGUAL = 267,                   /* IGUAL  */
    NAO = 268,                     /* NAO  */
    FOR = 269,                     /* FOR  */
    ENTAO = 270,                   /* ENTAO  */
    EU = 271,                      /* EU  */
    SE = 272,                      /* SE  */
    SAEM = 273,                    /* SAEM  */
    ENTRAM = 274,                  /* ENTRAM  */
    TODOS = 275,                   /* TODOS  */
    SOMAR = 276,                   /* SOMAR  */
    SUBTRAIR = 277,                /* SUBTRAIR  */
    DIVIDIR = 278,                 /* DIVIDIR  */
    MULTIPLICAR = 279,             /* MULTIPLICAR  */
    INICIO = 280,                  /* INICIO  */
    FIM = 281,                     /* FIM  */
    SIM = 282,                     /* SIM  */
    INTERROGACAO = 283,            /* INTERROGACAO  */
    ABRE_COLCHETES = 284,          /* ABRE_COLCHETES  */
    FECHA_COLCHETES = 285,         /* FECHA_COLCHETES  */
    VOLTAR_CENARIO = 286,          /* VOLTAR_CENARIO  */
    VOCE = 287,                    /* VOCE  */
    ABRE_PARENTESES = 288,         /* ABRE_PARENTESES  */
    FECHA_PARENTESES = 289,        /* FECHA_PARENTESES  */
    VIRGULA = 290,                 /* VIRGULA  */
    SERA = 291,                    /* SERA  */
    TOKEN = 292,                   /* TOKEN  */
    ADJETIVO_POSITIVO = 293,       /* ADJETIVO_POSITIVO  */
    ADJETIVO_NEGATIVO = 294,       /* ADJETIVO_NEGATIVO  */
    TU = 295,                      /* TU  */
    EH = 296,                      /* EH  */
    E = 297,                       /* E  */
    ENTRE = 298,                   /* ENTRE  */
    ARTIGO = 299,                  /* ARTIGO  */
    MESMO = 300,                   /* MESMO  */
    NUMERO = 301,                  /* NUMERO  */
    ADICIONAR_CENARIO = 302,       /* ADICIONAR_CENARIO  */
    SUBSTITUIR_CENARIO = 303,      /* SUBSTITUIR_CENARIO  */
    POR = 304,                     /* POR  */
    NO_CENARIO = 305,              /* NO_CENARIO  */
    MOSTRAR_CENARIO = 306,         /* MOSTRAR_CENARIO  */
    MOSTRA_VALOR = 307,            /* MOSTRA_VALOR  */
    LE_VALOR = 308,                /* LE_VALOR  */
    GUARDE = 309,                  /* GUARDE  */
    INTERIOR = 310,                /* INTERIOR  */
    LEMBRE = 311,                  /* LEMBRE  */
    IF_MOSTRA_VALOR = 312,         /* IF_MOSTRA_VALOR  */
    IF_LE_VALOR = 313,             /* IF_LE_VALOR  */
    ATO = 314,                     /* ATO  */
    CENA = 315                     /* CENA  */
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

#line 137 "src/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_PARSER_TAB_H_INCLUDED  */
