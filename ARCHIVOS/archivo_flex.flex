%option yylineno

%{
#include <stdio.h>
#include "archivo_bison.tab.h" 
#include "ast.h"

int lineno=1;
int errores=0;
FILE *output;
#define YY_DECL int yylex()
void escribir_fichero(FILE *output, char *token);
%}
INTEGER [0-9]+
FLOAT {INTEGER}\.{INTEGER}
VARIABLE [a-zA-Z_][a-zA-Z_0-9-]*
%%
"procedure"             {escribir_fichero(output, "TOKEN_PROCEDURE"); return PROCEDURE;}
"Text_IO.Put_Line"      {escribir_fichero(output, "TOKEN_PUTLINE"); return PUTLINE;}
"else"                  {escribir_fichero(output, "TOKEN_ELSE"); return ELSE;}

"Character"             { escribir_fichero(output, "TYPE_CHAR"); return CHAR;}
"Integer"               { escribir_fichero(output, "TYPE_INT"); return INT;}
"Natural"               { escribir_fichero(output, "TYPE_NAT"); return NATURAL;}
"Float"                 { escribir_fichero(output, "TYPE_FLOAT"); return FLOAT;}
"Positive"              { escribir_fichero(output, "TYPE_POSITIVE"); return POSITIVE;}
"String"                { escribir_fichero(output, "TYPE_STRING"); return STRING;}
"Boolean"               { escribir_fichero(output, "TYPE_BOOLEAN"); return BOOLEAN;}

"if"                    { escribir_fichero(output, "TYPE_IF"); return IF;}
"for"                   { escribir_fichero(output, "TYPE_FOR"); return FOR;}
"else"                  { escribir_fichero(output, "TYPE_ELSE"); return ELSE;}
"loop"                  { escribir_fichero(output, "TOKEN_LOOP"); return LOOP;}
"continue"              { escribir_fichero(output, "TYPE_CONTINUE"); }
"break"	                { escribir_fichero(output, "TYPE_BREAK"); }
"void"                  { escribir_fichero(output, "TYPE_VOID"); }
"return"                { escribir_fichero(output, "TYPE_RETURN"); return RETURN;}

"in"                    { escribir_fichero(output, "TOKEN_IN"); return IN;}
"end"                   { escribir_fichero(output, "TOKEN_END"); return END;}
";"                     { escribir_fichero(output, "TOKEN_PCOMA"); return PCOMA;}
"="                     { escribir_fichero(output, "TOKEN_PIGUAL"); return PIGUAL;}
">="|"<="|"<"|">"	    {escribir_fichero(output, "RELATIONAL_TOKEN"); 
                            yylval.sval = malloc(yyleng * sizeof(char));
                            strcpy(yylval.sval, yytext);
                            return RELATION_EXP;
                        }

"=="|"!="             	{escribir_fichero(output, "EQUALITY_TOKEN");
                            yylval.sval = malloc(yyleng * sizeof(char));
                            strcpy(yylval.sval, yytext);
                            return EQUALITY_EXP;
                        }
":"                     {escribir_fichero(output, "DOSPUNTOS_TOKEN"); return DOSPUNTOS;}
"is"                    {escribir_fichero(output, "IS_TOKEN"); return IS;}
"{"|"}"|"("|")"|"["|"]" {fprintf(output,"%-50s%-30s%-15d\n","Token DELIMITADOR",yytext, yylineno); return DELIMITADORES;}


"+"|"-"                 {escribir_fichero(output, "ADD_TOKEN"); 
                            yylval.sval = malloc(yyleng * sizeof(char));
                            strcpy(yylval.sval, yytext);
                            return ADD;
                            
                        }

"*"                     {fprintf(output,"%-50s%-30s%-15d\n","Token MULTIPLICACION",yytext, yylineno); return MULT;}
"/"                     {fprintf(output,"%-50s%-30s%-15d\n","Token DIVISION",yytext, yylineno); return DIVISION;} 
"++"|"--"               {escribir_fichero(output, "INCR_TOKEN"); return INCR;}
\x22                    {fprintf(output,"%-50s%-30s%-15d\n","Token COMILLA",yytext, yylineno); return COMILLA;}
","                     {escribir_fichero(output, "COMA_TOKEN"); return COMA;}

{INTEGER}		        {escribir_fichero(output, "INTEGER_TOKEN"); yylval.ival = atoi(yytext); return V_INTEGER;}
{FLOAT} 	            {escribir_fichero(output, "FLOAT_TOKEN"); yylval.fval = atof(yytext); return V_FLOAT;}
[ \t] ;                 /* ignore whitespace */
{VARIABLE}              {escribir_fichero(output, "VARIABLE_TOKEN"); sscanf(yytext, "%s", yylval.name);  return V_CHAR;}
\n	lineno++;
. ;
%%

int yywrap() {
    fprintf(output, "\n------------------------\nFin del fichero.\nNº total de líneas: %d\nNº errores: %d", yylineno, errores);
}

void escribir_fichero(FILE *output, char *token) {
    fprintf(output,"%-50s%-30s%-15d\n",token ,yytext, yylineno);
}