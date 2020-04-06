%error-verbose
%{
#define YYDEBUG 1
#include "pascal.tab.h"
#include <stdio.h>

int yyerror(char const *msg);
int yylex(void);
extern int line_num;


extern FILE *yyin;


%}

%token  EXP
%token  STR
%token  NUM
%token  ID
%token  INTEGER DOUBLE STRING
%token PROGRAM MC_BEGIN END VAR ARRAY OF DOTS FUNCTION PROCEDURE IF THEN ELSE WHILE DO NOT SEPARATOR_LINE SEPARATOR_LIST SEPARATOR_DEAD TYPIFIER BRACKET_O BRACKET_C SBRACKET_O SBRACKET_C _BUILTIN_READ _BUILTIN_WRITE ASSIGN
%token error COMMENT Number o_plus o_minus o_lor o_mul o_div o_mod o_land cmp_l cmp_leq cmp_eq cmp_neq cmp_g cmp_geq  OPPAFFECT

 

%start file

%%

file:
	program {fprintf(stderr, "#   program accepted by interpreter\n"); return (0) } ;
program:
	PROGRAM ID SEPARATOR_LINE declarations_list declaration_methods_list compound_statement SEPARATOR_DEAD ;
identifier_list:
	ID
	|
	ID SEPARATOR_LIST identifier_list ;
declarations_list:
	/* empty */
	|
	declarations_list VAR declaration SEPARATOR_LINE ;
parameters_list:
	declaration
	|
	declaration SEPARATOR_LINE parameters_list ;
declaration:
	identifier_list TYPIFIER type
	|
	identifier_list TYPIFIER ARRAY SBRACKET_O NUM DOTS NUM SBRACKET_C OF type ;
declaration_methods_list :
	/* empty */
	|
	declaration_methods_list declaration_method
declaration_method :
	method_header declarations_list compound_statement SEPARATOR_LINE ;
method_header :
	PROCEDURE ID BRACKET_O arguments BRACKET_C SEPARATOR_LINE ;
method_call :
	ID BRACKET_O call_parameters BRACKET_C ;
call_parameters :
	/* empty */
	|
	expr_list ;
arguments :
	/* empty */
	|
	parameters_list
type :
	INTEGER
	|
	DOUBLE ;
compound_statement:
	MC_BEGIN optional_statement END ;
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
	method_call
	|
	IF expr THEN statement
	|
	IF expr THEN statement ELSE statement
	|
	WHILE expr DO statement
	|
	_BUILTIN_READ BRACKET_O identifier_list BRACKET_C
	|
	_BUILTIN_WRITE BRACKET_O expr_list BRACKET_C ;
variable:
	ID ;
expr_list:
	expr
	|
	expr SEPARATOR_LIST expr_list ;
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
	fprintf(stderr, "Sorry for you , %s %d\n", msg,line_num);
	return 0;
}
int main(int argc,char** argv)
{
	char str[60];
	yyin = fopen(argv[1],"r");

	return yyparse() ;


}

int yywrap()
{
 return(1);
}
                   
