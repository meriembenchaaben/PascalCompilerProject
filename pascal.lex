%x comment foo
%{
#include "semantic.h"
#include "pascal.tab.h"
<<<<<<< HEAD

=======
>>>>>>> master
int yylex();
void yyerror(const char *s);
int line_num = 1;
int comment_caller;
#include <string.h>

%}


delim     [\t]
bl        {delim}+
standardType "integer" 
chiffre   [0-9]
literal_entier {chiffre}+
open_croch "["
close_croch "]"
ouvrante  (\()
fermante  (\))
lettre    [a-zA-Z]
id        {lettre}({lettre}|{chiffre})*
nb        ("-")?{chiffre}+("."{chiffre}+)?(("E"|"e")"-"?{chiffre}+)?
iderrone  {chiffre}({lettre}|{chiffre})*
listeId   ({id}[,])*{id}
Comment_Block "/*"([^*]|\*+[^*/])*\*+"/"
COMMENT_LINE       "//".*[\n]


%%
"/*"		{
    comment_caller = INITIAL;
    BEGIN(comment);}
<foo>"/*"	{
			comment_caller = foo;
			BEGIN(comment);
			}
	   <comment>[^*\n]*	   /* eat anything that's not a '*' */
	   <comment>"*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
	   <comment>\n		   ++line_num;
	   <comment>"*"+"/"	   BEGIN(comment_caller);
{bl}                                                                                 /* pas d'actions */
"\n" 			     {line_num++;}
[0-9]+         {  yylval.number=atoi(yytext);return NUM; }
[0-9]+\.[0-9]* { yylval.fnumber=atof(yytext);return EXP; }
\"[^"\n]*["\n] { yylval.string=strdup(yytext) ;  return STR; }
"program"   		{return PROGRAM;}
"begin"    		{return MC_BEGIN;}
"end"       		{return END;}
"var"     		{return VAR;}
"array"    		    {return ARRAY;}
".."        		{return DOTS;}
"of"       		{return OF;}
"integer"   			{yylval.string=strdup(yytext) ;return INTEGER;}
"double"    		{yylval.string=strdup(yytext) ;return DOUBLE;}
"string"    		{yylval.string=strdup(yytext) ;return STRING;}
"function"  		{yylval.string=strdup(yytext) ;return FUNCTION;}
"procedure"		    {yylval.string=strdup(yytext) ;return PROCEDURE;}
"if"       		{return IF;}
"then"      		{return THEN;}
"else"     		    {return ELSE;}
"while"     		{return WHILE;}
"do"        		{return DO;}
"not"       		{return NOT;}
"True|False"                   {if (!strcmp(yytext,"True")) {yylval.bool=true ;}
                                else { yylval.bool= false ;}
                                return Bool ; }

","         {return SEPARATOR_LIST;}
";"         {return SEPARATOR_LINE;}
"."         {return SEPARATOR_DEAD;}
":"         {return TYPIFIER;}
"("         {return BRACKET_O;}
")"         {return BRACKET_C;}
"["         {return SBRACKET_O;}
"]"         {return SBRACKET_C;}
"+"					return o_plus;
"-"					return o_minus;
"or"				return o_lor;
"*"  				return o_mul;
"/"|"div"  			return o_div;
"%"|"mod"  			return o_mod;
"and"				return o_land;
"<" 				return cmp_l;
"<=" 				return cmp_leq;
"="					return cmp_eq;
"<>"				return cmp_neq;
">" 				return cmp_g;
">=" 				return cmp_geq;
"read"   		   {return _BUILTIN_READ;}
"write"    		   {return _BUILTIN_WRITE;}
":="                                                                            return ASSIGN;
{COMMENT_LINE}         								     							 ++line_num ;
{id}                {yylval.string=strdup(yytext) ;return ID ;}



%%

