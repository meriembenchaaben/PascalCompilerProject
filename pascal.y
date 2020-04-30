%error-verbose

%{
#define YYDEBUG 1
#include "pascal.tab.h"
#include <stdio.h>
#include "semantic2.c"
int yyerror(char const *msg);
int yylex(void);
extern int line_num;
extern FILE *yyin;
extern int number_errors ;

%}

%union
{
        int number;
        char *string;
        double fnumber;
        struct Queue * queue ;
        struct listeDescripteursTypes * listType ;
}
%token  <fnumber>EXP
%token  <string>STR ID PROCEDURE FUNCTION ARRAY INTEGER DOUBLE STRING
%token  <number>NUM

%token PROGRAM MC_BEGIN END VAR OF DOTS IF THEN ELSE WHILE DO NOT SEPARATOR_LINE SEPARATOR_LIST SEPARATOR_DEAD TYPIFIER BRACKET_O BRACKET_C SBRACKET_O SBRACKET_C _BUILTIN_READ _BUILTIN_WRITE ASSIGN
%token error COMMENT Number o_plus o_minus o_lor o_mul o_div o_mod o_land cmp_l cmp_leq cmp_eq cmp_neq cmp_g cmp_geq  OPPAFFECT
%type <listType> arguments declaration declarations_list parameters_list
%type <queue> identifier_list
%type <string> type
%start file

%%

file:
	program
	{
		printCurrentDict() ;
		if(number_errors)
		return 1 ;
		fprintf(stderr, "#program accepted by interpreter\n"); return (0)
	} ;
program:
	PROGRAM ID SEPARATOR_LINE declarations_list declaration_methods_list compound_statement SEPARATOR_DEAD
	{
		//create main node
		//node * main = createNode($2,$1,NULL) ;
		//push to main sublist declaration list netsarfou fil nodes
		//parrent = main ;
		//node * global = $4 ;
		//current = null ;
		//char * currentType ;
		//check(global)
		//CHECK(global, haja elli bech ncheckiha ) ;
		//strcpy(currentType,"") ;
	};
identifier_list:
	ID
	{
		Queue * temp = createQueue() ;
		enQueue(temp,$1);
		$$ = temp ;
	}
	|
	ID SEPARATOR_LIST identifier_list
	{
		Queue * temp = createQueue() ;
		enQueue(temp,$1);
		enQueueQueue(temp,$3);
		$$= temp;
	};
declarations_list:
	/*empty*/
	{
		$$ = NULL ;
	}
	|
	VAR declaration SEPARATOR_LINE declarations_list
	{
		$$ = NULL
	};
parameters_list:
	declaration
	{
		$$ = $1 ;
	}
	|
	declaration SEPARATOR_LINE parameters_list
	{
		listeDescripteursTypes * list1 = $1;
		concatenateTypeList(list1,$3) ;
		$$=list1 ;
	};
arguments :
	/* empty */
	{
		$$ = NULL ;
	}
	|
	parameters_list
	{
		$$ = $1 ;
	};
declaration:
	identifier_list TYPIFIER type
	{
		listeDescripteursTypes *head = head=NULL ;
		Queue * tempQueue = $1 ;
		descripteurType * tempType ;
		while (tempQueue->front){

			tempType =nouveau(getTypeByName($3)) ;
			ajouterEntree(tempQueue->front->key,*tempType,line_num) ;


			listeDescripteursTypes *new = malloc(sizeof(listeDescripteursTypes));
			new->info = tempType ;
			new->suivant = head ;
			head = new ;


			deQueue(tempQueue) ;
		}
		//printCurrentDict() ;
		//addTypeToSiblings($1,$3) ;
		//$$ = $1
		$$= head ;
	}
	|
	identifier_list TYPIFIER ARRAY SBRACKET_O NUM DOTS NUM SBRACKET_C OF type
	{
		listeDescripteursTypes *head  = NULL ;
		Queue * tempQueue = $1 ;
		descripteurType * tempType =nouveau(getTypeByName("tTableau")) ;
		tempType->attributs.casTableau.indiceDebut= $5 ;
		tempType->attributs.casTableau.indiceFin= $7 ;
		//fprintf(stderr,"%s ",getTypeName(nouveau(getTypeByName($10))->classe));
		descripteurType * tempElementType=nouveau(getTypeByName($10));
		tempType->attributs.casTableau.typeElement = tempElementType ;

		while (tempQueue->front!= NULL){

			ajouterEntree(tempQueue->front->key,*tempType,line_num) ;

			listeDescripteursTypes *new = malloc(sizeof(listeDescripteursTypes));
			new->info = tempType ;
			new->suivant = head ;
			head = new ;

			deQueue(tempQueue) ;
		}
		//printCurrentDict() ;
		$$= head ;
	// todo array bech ne5dmouga ye men 3ach
	}
	;
declaration_methods_list :
	/* empty */
	|
	declaration_method declaration_methods_list
declaration_method :
	// apres method_header faires change scope (dictionaire ybadel el sommet wel base )
	{
	//badel scope
	}
	method_header declarations_list compound_statement SEPARATOR_LINE
	{
		//node * variables = concatenateSiblingLists($1->children,$2) ;

		// raja3 el scope (sommet wel base ) ;

	};
method_header :
	PROCEDURE ID BRACKET_O arguments BRACKET_C SEPARATOR_LINE
	{


		descripteurType * tempType =nouveau(getTypeByName($1)) ;
		tempType->attributs.casProcedure.typesArguments = $4 ;
		ajouterEntree($2,*tempType,line_num) ;
		//printCurrentDict() ;
		//$$= NULL
	}
	|
	FUNCTION ID BRACKET_O arguments BRACKET_C TYPIFIER type SEPARATOR_LINE
	{
		descripteurType * tempType =nouveau(getTypeByName($1)) ;
		descripteurType * tempReturnType=nouveau(getTypeByName($7));
		tempType->attributs.casFonction.typeResultat = tempReturnType ;
		tempType->attributs.casFonction.typesArguments = $4 ;
		ajouterEntree($2,*tempType,line_num) ;
		//printCurrentDict() ;
		//$$= NULL
	};
method_call :
	ID BRACKET_O call_parameters BRACKET_C
	{
		//checkFunction($1,$3) ;
	};
call_parameters :
	/* empty */
	|
	expr_list ;
type :
	INTEGER
	{
		$$ = $1 ;
	}
	|
	DOUBLE
	{
		$$ = $1 ;
	};
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


	creerDico() ;

	char str[60];
	yyin = fopen(argv[1],"r");

	return yyparse() ;


}

int yywrap()
{
 return(1);
}
                   
