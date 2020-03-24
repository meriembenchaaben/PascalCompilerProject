
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     EXP = 259,
     STR = 260,
     ID = 261,
     _R_INTEGER = 262,
     _R_DOUBLE = 263,
     _R_STRING = 264,
     _R_PROGRAM = 265,
     _R_BEGIN = 266,
     _R_END = 267,
     _R_VAR = 268,
     _R_ARRAY = 269,
     _R_OF = 270,
     _R_DOTS = 271,
     _R_FUNCTION = 272,
     _R_PROCEDURE = 273,
     _R_IF = 274,
     _R_THEN = 275,
     _R_ELSE = 276,
     _R_WHILE = 277,
     _R_DO = 278,
     _R_NOT = 279,
     SEPARATOR_LINE = 280,
     SEPARATOR_LIST = 281,
     SEPARATOR_DEAD = 282,
     TYPIFIER = 283,
     BRACKET_O = 284,
     BRACKET_C = 285,
     SBRACKET_O = 286,
     SBRACKET_C = 287,
     _BUILTIN_READ = 288,
     _BUILTIN_WRITE = 289,
     ASSIGN = 290,
     COMMENT = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


