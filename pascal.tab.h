
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
     Boolean = 267,
     NUM = 268,
     Bool = 269,
     PROGRAM = 270,
     MC_BEGIN = 271,
     END = 272,
     VAR = 273,
     OF = 274,
     DOTS = 275,
     IF = 276,
     THEN = 277,
     ELSE = 278,
     WHILE = 279,
     DO = 280,
     NOT = 281,
     SEPARATOR_LINE = 282,
     SEPARATOR_LIST = 283,
     SEPARATOR_DEAD = 284,
     TYPIFIER = 285,
     BRACKET_O = 286,
     BRACKET_C = 287,
     SBRACKET_O = 288,
     SBRACKET_C = 289,
     _BUILTIN_READ = 290,
     _BUILTIN_WRITE = 291,
     ASSIGN = 292,
     COMMENT = 293,
     Number = 294,
     o_plus = 295,
     o_minus = 296,
     o_lor = 297,
     o_mul = 298,
     o_div = 299,
     o_mod = 300,
     o_land = 301,
     cmp_l = 302,
     cmp_leq = 303,
     cmp_eq = 304,
     cmp_neq = 305,
     cmp_g = 306,
     cmp_geq = 307,
     OPPAFFECT = 308
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 25 "pascal.y"

        int number;
        char *string;
        double fnumber;
        boolean_  bool ;
        struct Queue * queue ;
        //struct QueueType * queueType ;
        struct listeDescripteursTypes * listType ;
        typePossible  type_;



/* Line 1676 of yacc.c  */
#line 118 "pascal.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


