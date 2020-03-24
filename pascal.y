%error-verbose
%{
#define YYDEBUG 1
#include "pascal.tab.h"
#include <stdio.h>

int yyerror(char const *msg);
int yylex(void);
extern int yylineno;


extern FILE *yyin;


%}

%token  EXP
%token  STR
%token  NUM
%token  ID
%token  _R_INTEGER _R_DOUBLE _R_STRING
%token _R_PROGRAM _R_BEGIN _R_END _R_VAR _R_ARRAY _R_OF _R_DOTS _R_FUNCTION _R_PROCEDURE _R_IF _R_THEN _R_ELSE _R_WHILE _R_DO _R_NOT SEPARATOR_LINE SEPARATOR_LIST SEPARATOR_DEAD TYPIFIER BRACKET_O BRACKET_C SBRACKET_O SBRACKET_C _BUILTIN_READ _BUILTIN_WRITE ASSIGN
%token error COMMENT Number o_plus o_minus o_lor o_mul o_div o_mod o_land cmp_l cmp_leq cmp_eq cmp_neq cmp_g cmp_geq type OPPAFFECT

 

%start file

%%

file:
	/*empty*/
		{fprintf(stderr, "#   warning: empty file\n");
		return(0);}
	|
	program {fprintf(stderr, "#   program accepted by interpreter\n");};
program:
	_R_PROGRAM ID SEPARATOR_LINE declarationz_list compound_statement SEPARATOR_DEAD ;
identifier_list:
	ID
	|
	ID SEPARATOR_LIST identifier_list ;
declarationz_list:
	/* empty */
	|
	declarationz_list _R_VAR declaration ;
declaration:
	identifier_list TYPIFIER _R_INTEGER SEPARATOR_LINE
	|
	identifier_list TYPIFIER _R_DOUBLE SEPARATOR_LINE;
compound_statement:
	_R_BEGIN optional_statement _R_END ;
optional_statement:
	/*empty*/
	|
	statement_list  ;
statement_list:
	statement
	|
	statement_list SEPARATOR_LINE statement ;
statement:
	variable ASSIGN expr
	|
	compound_statement
	|
	_R_WHILE expr _R_DO statement
	|
	_R_IF expr _R_THEN statement _R_ELSE statement
	|
	_BUILTIN_READ BRACKET_O identifier_list BRACKET_C
	|
	_BUILTIN_WRITE BRACKET_O expr_list BRACKET_C ;
variable:
	ID ;
expr_list:
	expr
	|
	expr_list SEPARATOR_LIST expr ;
expr:
	simple_expr
	|
	simple_expr cmp_leq simple_expr
	|
	simple_expr cmp_geq simple_expr
	|
	simple_expr cmp_eq  simple_expr
	|
	simple_expr cmp_neq simple_expr
	|
	simple_expr cmp_l   simple_expr
	|
	simple_expr cmp_g   simple_expr ;
simple_expr:
	term
	|
	simple_expr o_plus  term
	|
	simple_expr o_minus term
	|
	simple_expr o_lor   term ;
term:
	factor
	|
	term o_mul  factor
	|
	term o_land factor
	|
	term o_div  factor
	|
	term o_mod  factor ;
factor:
	NUM
	|
	EXP
	|
	STR
	|
	ID
	|
	BRACKET_O expr BRACKET_C ;
%%

#include <stdlib.h>
int yyerror(char const *msg) {
	fprintf(stderr, "%s %d\n", msg,yylineno);
	return 0;
}
int main(int argc,char** argv)
{
	char str[60];
	yyin = fopen(argv[1],"r");

	yyparse() ;

	return 0 ;
}

int yywrap()
{
 return(1);
}
                   
