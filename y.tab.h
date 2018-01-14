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
    EXIT = 261,
    MATRIX = 262,
    ARRAY = 263,
    PYRAMID = 264,
    DOME = 265,
    GRID = 266,
    HEIGHT = 267,
    FITS = 268,
    PLACE = 269,
    DELETE = 270,
    ALL = 271,
    IF = 272,
    THEN = 273,
    ELSE = 274,
    MOVE = 275,
    AND = 276,
    OR = 277,
    EQ = 278,
    AT = 279,
    VAR = 280
  };
#endif
/* Tokens.  */
#define NUM 258
#define DIR 259
#define SHOW 260
#define EXIT 261
#define MATRIX 262
#define ARRAY 263
#define PYRAMID 264
#define DOME 265
#define GRID 266
#define HEIGHT 267
#define FITS 268
#define PLACE 269
#define DELETE 270
#define ALL 271
#define IF 272
#define THEN 273
#define ELSE 274
#define MOVE 275
#define AND 276
#define OR 277
#define EQ 278
#define AT 279
#define VAR 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "lego.y" /* yacc.c:1909  */

       char* lexeme;			//identifier
       double value;			//value of an identifier of type NUM
       

#line 110 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
