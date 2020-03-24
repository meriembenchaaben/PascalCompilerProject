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
%token  NUMBER
%token  ID
%token  _R_INTEGER _R_DOUBLE _R_STRING

%token _R_PROGRAM _R_BEGIN _R_END _R_VAR _R_ARRAY _R_OF _R_DOTS _R_FUNCTION _R_PROCEDURE _R_IF _R_THEN _R_ELSE _R_WHILE _R_DO _R_NOT SEPARATOR_LINE SEPARATOR_LIST SEPARATOR_DEAD TYPIFIER BRACKET_O BRACKET_C SBRACKET_O SBRACKET_C _BUILTIN_READ _BUILTIN_WRITE ASSIGN

%token error COMMENT Number o_plus o_minus o_lor o_mul o_div o_mod o_land cmp_l cmp_leq cmp_eq cmp_neq cmp_g cmp_geq type OPPAFFECT Identifier

 

%start programmes

%%

programmes		     : _R_PROGRAM Identifier SEPARATOR_LINE {printf("ok");}
                               | COMMENT Identifier SEPARATOR_LINE            {yyerror (" program attendu on line : "); }
                               | _R_PROGRAM COMMENT SEPARATOR_LINE       {yyerror (" nom du programme invalide on line : "); }
                               | _R_PROGRAM Identifier COMMENT                  {yyerror (" point virgule attendu on line : "); } ;


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
                   
