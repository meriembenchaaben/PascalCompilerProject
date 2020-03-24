%option yylineno
delim     [ \t]
bl        {delim}+
standardType "integer" 
chiffre   [0-9]
literal_entier {chiffre}+
open_croch "["
close_croch "]"
ouvrante  (\()
fermante  (\))
typeE      ({standardType})|(("aray"){open_croch}{literal_entier}(".."){literal_entier}{close_croch})
lettre    [a-zA-Z]
id        {lettre}({lettre}|{chiffre})*
nb        ("-")?{chiffre}+("."{chiffre}+)?(("E"|"e")"-"?{chiffre}+)?
iderrone  {chiffre}({lettre}|{chiffre})*
listeId   ({id}[,])*{id}
Comment_Block "/*"([^*]|\*+[^*/])*\*+"/"




COMMENT_LINE        "//"


%%

{bl}                                                                                 /* pas d'actions */
"\n" 			                                                                     ++yylineno;
{Comment_Block}																		 printf("COMMENT");
"program"                                                                            printf(" keyword ");
"begin"                                                                              printf(" keyword ");
"end"                                                                                printf(" keyword ");
"var"   																			 printf(" keyword_var");
"procedure"																			 printf("keyword_prcedure");
"if"																				 printf(" keyword_IF ");
"else"																				 printf(" keyword_else ");
"while"																			     printf(" keyword_while ");


{ouvrante}                                                                           printf(" parenthèse_ouvrante ");
{fermante}                                                                           printf(" parenthèse_fermante ");
{id}                                                                                 printf(" Identifier ");
{nb}                                                                                 printf(" Number ");
"="|"<>"|"<"|">"|"<="|">="	                                                         printf(" OPPerateur "); 
{typeE}					                                                             printf(" type ");
":="
": ="	                                                                             printf(" OPPAFFECT ");
":" 																			     printf(" : ");
{COMMENT_LINE}         								     printf(" COMMENT ");

{iderrone}              {fprintf(stderr,"illegal identifier \'%s\' on line :%d\n",yytext,yylineno);}
	

%%

int main(int argc, char *argv[]) 
{
     yyin = fopen(argv[1], "r");
     yylex();
     fclose(yyin);
}

yywrap()
{
	return(1);
}
