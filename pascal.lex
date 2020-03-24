%{option yylineno
#include "pascal.tab.h"
int yylex();
void yyerror(const char *s);
%}

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
COMMENT_LINE       "//".*[\n]


%%

{bl}                                                                                 /* pas d'actions */
"\n" 			     ++yylineno;
{Comment_Block}		 return COMMENT;
[0-9]+         {  return NUMBER; }
[0-9]+\.[0-9]* { return EXP; }
\"[^"\n]*["\n] {   return STR; }
"program"   		{return _R_PROGRAM;}
"begin"     		{return _R_BEGIN;}
"end"       		{return _R_END;}
"var"       		{return _R_VAR;}
"array"    		    {return _R_ARRAY;}
".."        		{return _R_DOTS;}
"of"        		{return _R_OF;}
"integer"  			{return _R_INTEGER;}
"double"    		{return _R_DOUBLE;}
"string"    		{return _R_STRING;}
"function"  		{return _R_FUNCTION;}
"procedure"		    {return _R_PROCEDURE;}
"if"        		{return _R_IF;}
"then"      		{return _R_THEN;}
"else"     		    {return _R_ELSE;}
"while"     		{return _R_WHILE;}
"do"        		{return _R_DO;}
"not"       		{return _R_NOT;}
{nb}				return Number ;
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
{typeE}					                                                             return type ;
":="                                                                            return OPPAFFECT;
{COMMENT_LINE}         								     							 return COMMENT;
{id}                return Identifier ;



%%

