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

#ifndef YY_YY_SINTACTICO_TAB_H_INCLUDED
# define YY_YY_SINTACTICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    ID = 259,                      /* ID  */
    ID_MAS_IGUAL = 260,            /* ID_MAS_IGUAL  */
    ID_MENOS_IGUAL = 261,          /* ID_MENOS_IGUAL  */
    ID_MULT_IGUAL = 262,           /* ID_MULT_IGUAL  */
    ID_DIV_IGUAL = 263,            /* ID_DIV_IGUAL  */
    ID_IGUAL_IGUAL = 264,          /* ID_IGUAL_IGUAL  */
    ID_MAYOR_IGUAL = 265,          /* ID_MAYOR_IGUAL  */
    ID_MENOR_IGUAL = 266,          /* ID_MENOR_IGUAL  */
    ID_DIFERENTE_IGUAL = 267,      /* ID_DIFERENTE_IGUAL  */
    ID_MAS_MAS = 268,              /* ID_MAS_MAS  */
    ID_MENOS_MENOS = 269,          /* ID_MENOS_MENOS  */
    ID_ASIGNACION = 270,           /* ID_ASIGNACION  */
    EXIT = 271,                    /* EXIT  */
    WORKSPACE = 272,               /* WORKSPACE  */
    HELP = 273,                    /* HELP  */
    CLEAR_WORKSPACE = 274,         /* CLEAR_WORKSPACE  */
    SIMBOLOS = 275,                /* SIMBOLOS  */
    LOAD = 276,                    /* LOAD  */
    IMPORT = 277,                  /* IMPORT  */
    NEG = 278                      /* NEG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "sintactico.y"

    double val;
    char *str;

#line 92 "sintactico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTACTICO_TAB_H_INCLUDED  */
