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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NUM = 258,
    DIR = 259,
    TYPE = 260,
    VAR = 261,
    GVAR = 262,
    SHOW = 263,
    EXIT = 264,
    SWITCH = 265,
    ROTATE = 266,
    POSSIBLE = 267,
    WHILE = 268,
    GRID = 269,
    HEIGHT = 270,
    FITS = 271,
    PLACE = 272,
    DELETE = 273,
    ALL = 274,
    IF = 275,
    THEN = 276,
    MOVE = 277,
    AT = 278
  };
#endif
/* Tokens.  */
#define NUM 258
#define DIR 259
#define TYPE 260
#define VAR 261
#define GVAR 262
#define SHOW 263
#define EXIT 264
#define SWITCH 265
#define ROTATE 266
#define POSSIBLE 267
#define WHILE 268
#define GRID 269
#define HEIGHT 270
#define FITS 271
#define PLACE 272
#define DELETE 273
#define ALL 274
#define IF 275
#define THEN 276
#define MOVE 277
#define AT 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "lego.y" /* yacc.c:1909  */

	char* lexeme;
	int value;
		

#line 106 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
