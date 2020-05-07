%error-verbose

%{

//#define YYDEBUG 1

#include "semantic.h"

#include <stdio.h>
#include "semantic.c"
#include "pascal.tab.h"

int yyerror(char const *msg);
int yylex(void);
extern int line_num;
extern FILE *yyin;
extern int number_errors ;
int currFunctionIndex ;
#include "pascal.tab.h"

%}


%union
{
        int number;
        char *string;
        double fnumber;
        boolean_  bool ;
        struct Queue * queue ;
        //struct QueueType * queueType ;
        struct listeDescripteursTypes * listType ;
        typePossible  type_;
}
%token  <fnumber>EXP
%token  <string>STR ID PROCEDURE FUNCTION ARRAY INTEGER DOUBLE STRING Boolean
%token  <number>NUM
%token <bool>Bool
%token PROGRAM MC_BEGIN END VAR OF DOTS IF THEN ELSE WHILE DO NOT SEPARATOR_LINE SEPARATOR_LIST SEPARATOR_DEAD TYPIFIER BRACKET_O BRACKET_C SBRACKET_O SBRACKET_C _BUILTIN_READ _BUILTIN_WRITE ASSIGN
%token error COMMENT Number o_plus o_minus o_lor o_mul o_div o_mod o_land cmp_l cmp_leq cmp_eq cmp_neq cmp_g cmp_geq  OPPAFFECT
%type <listType> arguments declaration declarations_list parameters_list expr_list call_parameters
%type <queue> identifier_list
%type <string> type variable

%type <type_> term expr factor simple_expr method_call statement

%start file

%%

file:
	program
	{
		//printCurrentDict() ;
		verifUsed();
		if(number_errors)
		{
		printf("\n\nNUMBER OF ERRORS = %d\n",number_errors) ;
		return 1 ;
		}

		printf("#program accepted by interpreter\n");
		return (0) ;

	} ;
program:
	PROGRAM ID{
		ajouterEntree($2,*nouveau(getTypeByName("program")) ,line_num) ;
	} SEPARATOR_LINE declarations_list declaration_methods_list compound_statement SEPARATOR_DEAD
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
		listeDescripteursTypes *head = NULL ;
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

	}
	;
declaration_methods_list :
	/* empty */
	|
	{
	upScope() ;
	}declaration_method declaration_methods_list
declaration_method  :
	// apres method_header faires change scope (dictionaire ybadel el sommet wel base )

	method_header declarations_list compound_statement SEPARATOR_LINE
	{
		//node * variables = concatenateSiblingLists($1->children,$2) ;
		//printCurrentDict();
		downScope() ;
		if(currFunctionIndex >=0)
		{
		ajouterEntree(dico[currFunctionIndex].identif,dico[currFunctionIndex].type,dico[currFunctionIndex].declarationLine) ;
		}
	};
method_header :
	PROCEDURE ID BRACKET_O arguments BRACKET_C SEPARATOR_LINE
	{


		descripteurType * tempType =nouveau(getTypeByName($1)) ;
		tempType->attributs.casProcedure.typesArguments = $4 ;
		currFunctionIndex = ajouterEntree($2,*tempType,line_num) ;
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
		currFunctionIndex = ajouterEntree($2,*tempType,line_num) ;
		//printCurrentDict() ;
		//$$= NULL
	};
method_call :
	ID BRACKET_O call_parameters BRACKET_C
	{
		$$=verifMethodCall($1,$3);
	};
call_parameters :
	/* empty */
	{
	$$=NULL;
	}
	|
	expr_list
	{
	$$=$1;
	}
	;
type :
	INTEGER
	{
		$$ = $1 ;
	}
	|
	DOUBLE
	{
		$$ = $1 ;
	}
	|
	Boolean
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
	{
		ENTREE_DICO * variable  = search_variable($1) ;
		if (variable)
		{
			if(memeType(nouveau($3),&variable->type))
			{
				variable->initialised = 1 ;
				//variable->used = 1 ;
			}
			else if ((variable->type.classe==tDouble) && ($3==tInt))
			{
				variable->initialised = 1 ;
				//variable->used = 1 ;
			}
			else
			{
				number_errors++ ;
				printf("Type variable incompatible \n");
			}

		}



	}
	|
	compound_statement{
	}
	|
	IF expr THEN statement
	{
		if ($2!=tBool)
		{
			number_errors ++ ;
			printf("if condition must be of type boolean\n") ;
		}
	}
	|
	IF expr THEN statement ELSE statement
	{
		if ($2!=tBool)
		{
			number_errors ++ ;
			printf("if condition must be of type boolean\n") ;
		}
	}
	|
	WHILE expr DO statement
	{
		if ($2!=tBool)
		{
			number_errors ++ ;
			printf("while condition must be of type boolean\n") ;
		}
	}
	|
	_BUILTIN_READ BRACKET_O identifier_list BRACKET_C
	{
		Queue * tempQueue = $3 ;
		while (tempQueue->front){
			search_variable(tempQueue->front->key) ;
			deQueue(tempQueue) ;
		}

	}
	|
	_BUILTIN_WRITE BRACKET_O expr_list BRACKET_C
	{

	}
	|
	method_call
	{
	};
variable:

	ID {
		$$=$1 ;
	};
expr_list:
	expr{
		listeDescripteursTypes *head = NULL ;
		head = (listeDescripteursTypes*)malloc(sizeof(listeDescripteursTypes));
		head->info= nouveau($1) ;
		head->suivant= NULL ;
		$$=head ;
	}
	|
	expr SEPARATOR_LIST expr_list
	{

		listeDescripteursTypes *head = NULL ;
		head = (listeDescripteursTypes*)malloc(sizeof(listeDescripteursTypes));
		head->info= nouveau($1) ;
		head->suivant= NULL ;
		concatenateTypeList(head,$3) ;
		$$=head ;
	};

expr:
	simple_expr
	{
		$$= $1 ;
	}
	|
	simple_expr cmp_leq simple_expr
	{

		$$=verifCompare($1,$3) ;
	}
	|
	method_call
	{
		$$ = $1 ;
	}
	|
	simple_expr cmp_geq simple_expr
	{
		$$=verifCompare($1,$3) ;
	}
	|
	simple_expr cmp_eq  simple_expr
	{
		$$=verifCompare($1,$3) ;
	}
	|
	simple_expr cmp_neq simple_expr
	{
		$$=verifCompare($1,$3) ;
	}
	|
	simple_expr cmp_l   simple_expr
	{
		$$=verifCompare($1,$3) ;
	}
	|
	simple_expr cmp_g   simple_expr{
		$$=verifCompare($1,$3) ;
	}
	;
simple_expr:
	term
	{
		$$=$1
	}
	|
	simple_expr o_plus  term
	{
		if($1==tInt&&$3==tInt)
			$$ = tInt;
		else if($1==tInt || $3==tInt)
			if($1==tDouble||$3==tDouble)
				$$ = tDouble;
		else if($1==tDouble&&$3==tDouble)
			$$= tDouble ;
		else if($1==tString&&$3==tString)
			$$=tString ;
		else{
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
			$$= tInt ;
		}
	}
	|
	simple_expr o_minus term
	{
		if($1==tInt&&$3==tInt)
			$$ = tInt;
		else if($1==tInt || $3==tInt)
			if($1==tDouble||$3==tDouble)
				$$ = tDouble;
		else if($1==tDouble&&$3==tDouble)
			$$= tDouble ;
		else {
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
			$$= tDouble ;
		}
	}
	|
	simple_expr o_lor  term
	{
		if($1==tBool&&$3==tBool)
			$$ = tBool;
		else {
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
			$$=$1 ;
		}
	};
term:
	factor
	{
		$$=$1 ;
	}
	|
	term o_mul  factor
	{
		if($1==tInt&&$3==tInt)
			$$ = tInt;
		else if($1==tInt || $3==tInt)
			if($1==tDouble||$3==tDouble)
				$$ = tDouble;
		else if($1==tDouble&&$3==tDouble)
			$$= tDouble ;
		else {
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
			$$ = tInt ;
		}
	}
	|
	term o_land factor
	{
		if($1==tBool&&$3==tBool)
			$$ = tBool;
		else {
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
			$$=$1 ;
		}

	}
	|
	term o_div  factor
	{
		$$=tDouble ;
	}
	|
	term o_mod  factor
	{
		if($1!=tInt||$3!=tInt)
		{
			number_errors ++ ;
			printf("operator is not overloaded at line : %d\n",line_num) ;
		}
		$$=tInt
	};
factor:
	NUM
	{
		$$=tInt ;
	}
	|
	EXP
	{
		$$=tDouble ;
	}
	|
	STR
	{
		$$=tString ;
	}
	|
	ID
	{
		ENTREE_DICO * variable  = search_variable($1) ;
		if (variable)
		{
			if(!variable->initialised)
			{
				number_errors ++ ;
				printf("vriable avec l'identificateur %s non initialisé\n",variable->identif) ;
			}
			variable->used = 1 ;
			$$= variable->type.classe ;
		}
		else {
			$$= tVoid ;
		}
		//probablement va causer des probs
	}
	|
	BRACKET_O expr BRACKET_C
	{
		$$=$2 ;
	}
	|
	Bool
	{
		$$=tBool ;
	};
%%

#include <stdlib.h>
int yyerror(char const *msg) {
	printf("%s %d\n", msg,line_num);
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
                   
