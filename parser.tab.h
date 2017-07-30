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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 258,
    CHARLIT = 259,
    STRING = 260,
    NUMBER = 261,
    TOKEOF = 262,
    ELLIPSIS = 263,
    AUTO = 264,
    BREAK = 265,
    CASE = 266,
    CHAR = 267,
    CONST = 268,
    CONTINUE = 269,
    DEFAULT = 270,
    DO = 271,
    DOUBLE = 272,
    ENUM = 273,
    EXTERN = 274,
    FLOAT = 275,
    FOR = 276,
    GOTO = 277,
    INLINE = 278,
    INT = 279,
    LONG = 280,
    REGISTER = 281,
    RESTRICT = 282,
    RETURN = 283,
    SHORT = 284,
    SIGNED = 285,
    SIZEOF = 286,
    STATIC = 287,
    STRUCT = 288,
    SWITCH = 289,
    TYPEDEF = 290,
    UNION = 291,
    UNSIGNED = 292,
    VOID = 293,
    VOLATILE = 294,
    WHILE = 295,
    _BOOL = 296,
    _COMPLEX = 297,
    _IMAGINARY = 298,
    PLUSEQ = 299,
    MINUSEQ = 300,
    TIMESEQ = 301,
    DIVEQ = 302,
    MODEQ = 303,
    SHLEQ = 304,
    SHREQ = 305,
    ANDEQ = 306,
    XOREQ = 307,
    OREQ = 308,
    LOGOR = 309,
    LOGAND = 310,
    EQEQ = 311,
    NOTEQ = 312,
    LTEQ = 313,
    GTEQ = 314,
    SHL = 315,
    SHR = 316,
    INDSEL = 317,
    PLUSPLUS = 318,
    MINUSMINUS = 319,
    UNARY = 320,
    IF = 321,
    ELSE = 322
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "parser.y" /* yacc.c:1909  */

    char *string;
    char character;
    num number;
    astnode *node;

#line 129 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
