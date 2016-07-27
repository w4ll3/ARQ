/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_INTER_TAB_H_INCLUDED
# define YY_YY_INTER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARCH = 258,
    A_SUM = 259,
    A_MUL = 260,
    A_DIV = 261,
    A_BIN = 262,
    A_BCH = 263,
    A_BES = 264,
    VALUE = 265,
    RE_SUM = 266,
    RE_SUB = 267,
    RE_DIV = 268,
    RE_MUL = 269,
    TEXTO = 270,
    DDATA = 271,
    DTEXT = 272,
    CICLOS = 273,
    REG_I = 274,
    REG2 = 275,
    REG2_L = 276,
    REG2_I = 277,
    REG3 = 278,
    LAB = 279,
    CIFRAO = 280,
    REG = 281,
    LABEL = 282,
    COMMA = 283,
    COLLON = 284,
    EQUAL = 285,
    EOL = 286,
    TYPE = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 7 "inter.y" /* yacc.c:1909  */

	char *opp, *reg, *label;
	int value;

#line 92 "inter.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTER_TAB_H_INCLUDED  */
