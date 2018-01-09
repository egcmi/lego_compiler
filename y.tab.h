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
    SHOW = 260,
    MATRIX = 261,
    ARRAY = 262,
    PYRAMID = 263,
    DOME = 264,
    GRID = 265,
    HEIGHT = 266,
    FITS = 267,
    PLACE = 268,
    DELETE = 269,
    ALL = 270,
    IF = 271,
    THEN = 272,
    ELSE = 273,
    MOVE = 274,
    AND = 275,
    OR = 276,
    EQ = 277,
    AT = 278,
    VAR = 279
  };
#endif
/* Tokens.  */
#define NUM 258
#define DIR 259
#define SHOW 260
#define MATRIX 261
#define ARRAY 262
#define PYRAMID 263
#define DOME 264
#define GRID 265
#define HEIGHT 266
#define FITS 267
#define PLACE 268
#define DELETE 269
#define ALL 270
#define IF 271
#define THEN 272
#define ELSE 273
#define MOVE 274
#define AND 275
#define OR 276
#define EQ 277
#define AT 278
#define VAR 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "lego.y" /* yacc.c:1909  */

       char* lexeme;			//identifier
       double value;			//value of an identifier of type NUM
       

#line 108 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
