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
    SHOW = 261,
    EXIT = 262,
    SWITCH = 263,
    ARRAY = 264,
    PYRAMID = 265,
    DOME = 266,
    GRID = 267,
    HEIGHT = 268,
    FITS = 269,
    PLACE = 270,
    DELETE = 271,
    ALL = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    MOVE = 276,
    AND = 277,
    OR = 278,
    EQ = 279,
    AT = 280,
    VAR = 281,
    GVAR = 282
  };
#endif
/* Tokens.  */
#define NUM 258
#define DIR 259
#define TYPE 260
#define SHOW 261
#define EXIT 262
#define SWITCH 263
#define ARRAY 264
#define PYRAMID 265
#define DOME 266
#define GRID 267
#define HEIGHT 268
#define FITS 269
#define PLACE 270
#define DELETE 271
#define ALL 272
#define IF 273
#define THEN 274
#define ELSE 275
#define MOVE 276
#define AND 277
#define OR 278
#define EQ 279
#define AT 280
#define VAR 281
#define GVAR 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "lego.y" /* yacc.c:1909  */

       char* lexeme;			//identifier
       double value;			//value of an identifier of type NUM
       

#line 114 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
