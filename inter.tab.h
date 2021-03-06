/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
    MEM_SIZE = 270,
    TEXTO = 271,
    DDATA = 272,
    DTEXT = 273,
    CICLOS = 274,
    REG_I = 275,
    REG2 = 276,
    REG2_L = 277,
    REG2_I = 278,
    REG3 = 279,
    LAB = 280,
    CIFRAO = 281,
    REG = 282,
    LABEL = 283,
    COMMA = 284,
    COLLON = 285,
    EQUAL = 286,
    EOL = 287,
    TYPE = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 26 "inter.y" /* yacc.c:1909  */

	char *opp, *reg, *label;
	int value;

#line 93 "inter.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTER_TAB_H_INCLUDED  */
