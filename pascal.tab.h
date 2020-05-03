
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
     EXP = 258,
     STR = 259,
     ID = 260,
     PROCEDURE = 261,
     FUNCTION = 262,
     ARRAY = 263,
     INTEGER = 264,
     DOUBLE = 265,
     STRING = 266,
     NUM = 267,
     PROGRAM = 268,
     MC_BEGIN = 269,
     END = 270,
     VAR = 271,
     OF = 272,
     DOTS = 273,
     IF = 274,
     THEN = 275,
     ELSE = 276,
     WHILE = 277,
     DO = 278,
     NOT = 279,
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
     COMMENT = 291,
     Number = 292,
     o_plus = 293,
     o_minus = 294,
     o_lor = 295,
     o_mul = 296,
     o_div = 297,
     o_mod = 298,
     o_land = 299,
     cmp_l = 300,
     cmp_leq = 301,
     cmp_eq = 302,
     cmp_neq = 303,
     cmp_g = 304,
     cmp_geq = 305,
     OPPAFFECT = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 18 "pascal.y"

        int number;
        char *string;
        double fnumber;
        struct Queue * queue ;
        struct listeDescripteursTypes * listType ;



/* Line 1676 of yacc.c  */
#line 113 "pascal.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


