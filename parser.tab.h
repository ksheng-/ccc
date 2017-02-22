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
    PLUSEQ = 258,
    MINUSEQ = 259,
    TIMESEQ = 260,
    DIVEQ = 261,
    MODEQ = 262,
    SHLEQ = 263,
    SHREQ = 264,
    ANDEQ = 265,
    XOREQ = 266,
    OREQ = 267,
    LOGOR = 268,
    LOGAND = 269,
    EQEQ = 270,
    NOTEQ = 271,
    LTEQ = 272,
    GTEQ = 273,
    SHL = 274,
    SHR = 275,
    PLUSPLUS = 276,
    MINUSMINUS = 277,
    INDSEL = 278,
    IDENT = 279,
    TOKEOF = 280,
    ELLIPSIS = 281,
    AUTO = 282,
    BREAK = 283,
    CASE = 284,
    CHAR = 285,
    CONST = 286,
    CONTINUE = 287,
    DEFAULT = 288,
    DO = 289,
    DOUBLE = 290,
    ELSE = 291,
    ENUM = 292,
    EXTERN = 293,
    FLOAT = 294,
    FOR = 295,
    GOTO = 296,
    IF = 297,
    INLINE = 298,
    INT = 299,
    LONG = 300,
    REGISTER = 301,
    RESTRICT = 302,
    RETURN = 303,
    SHORT = 304,
    SIGNED = 305,
    SIZEOF = 306,
    STATIC = 307,
    STRUCT = 308,
    SWITCH = 309,
    TYPEDEF = 310,
    UNION = 311,
    UNSIGNED = 312,
    VOID = 313,
    VOLATILE = 314,
    WHILE = 315,
    _BOOL = 316,
    _COMPLEX = 317,
    _IMAGINARY = 318,
    STRING = 319,
    CHARLIT = 320,
    NUMBER = 321
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "parser.y" /* yacc.c:1909  */

	char *string;
	char character;
	num number;
	// symrec *tptr;

#line 128 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
