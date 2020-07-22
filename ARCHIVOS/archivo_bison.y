%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "ast.c"
#include "comprobacion_tipos.c"
#include "diccionario.h"

extern FILE *output;
extern int lineno;
extern int errores;
void yyerror(char *s);
int yylex();   
DICCIONARIO diccionario;

FILE *mipsOutput;
int declarations_counter = 0;

%}
%union {
	int ival;
	float fval;
	char type[10];
	char name[20];
	char *sval;
	char cval;

	struct Nodo_AST * nodo;
	union Tipo_Valor * value_type;
	int data_type;
}

%token<ival> V_INTEGER
%token<fval> V_FLOAT
%token<name> V_CHAR INT CHAR NATURAL FLOAT POSITIVE STRING BOOLEAN
%token<sval> ADD RELATION_EXP EQUALITY_EXP
%token PROCEDURE DESCONOCIDO NOMBRE PCOMA PUTLINE RETURN 
%token IF DELIMITADORES COMILLA COMA PIGUAL
%token INCR MULT DIVISION FOR
%token LOOP IN END MAIN IS DOSPUNTOS ELSE
%type<ival> operaciones
%type<ival> declaraciones 
%type<ival> operaciones_bool
%type<ival> principal
%type<ival> imprimir
%type<name> condicional
%type<ival> v_type
%type<ival> operaciones_cond
%type<name> operaciones_cond_text
// %type<sval> numerosFor1
// %type<sval> numerosFor2
%type<data_type> tipo;
// %type<value_type> ops;
// %type<value_type> ops2;

%start S

%%

S: principal { 
		fprintf(output, "Terminada la compilación!!"); 
			// prueba_impresion_declaracion(mipsOutput);
		};

principal: PROCEDURE V_CHAR is input END V_CHAR pcoma
		{
			char * first_name = $2;
			char * last_name = $6;
			if(strcmp(first_name, last_name) != 0) {
				printf("ERROR: El nombre del procedimiento debe ser el mismo al inicio y al final \n");
			}
			char n = '"';
			fprintf(mipsOutput,"\nend :\n.data\n\tspace : .asciiz %c\\n%c",n,n);
		}
		;

input: /* vacio */
	| input line;

line: '\n'
    | for
	| for '\n'  
	| declaraciones 
	| declaraciones '\n'
	| operaciones
	| operaciones '\n'
	| imprimir
	| imprimir '\n'
	| retornar
	| retornar '\n'	
	| condicional
	;

numerosFor1: V_INTEGER
	{	
		printf("hola\n");
		fprintf(mipsOutput,"\ninitialize:\n\tadd $s1, $zero, %d",$1)
	}
	| V_CHAR 
	{
		printf("El nombre de la variable es: %s\n", $1);
		ENTRADA * entrada = buscar_diccionario(&diccionario,$1);
		if (entrada != NULL) {
			char * valor = entrada->valor;
			fprintf(mipsOutput,"\ninitialize:\n\tadd $s1, $zero, %s", valor);
		} else {
			printf("ERROR: variable %s no definida\n", $1);
		}
	}
	;

numerosFor2: V_INTEGER
			{
				fprintf(mipsOutput,"\n\taddi $s2, $zero,%d\npredicate:\n\tslt $t0, $s1, $s2 \n\tbeq $t0, $zero, endfor \nconsequent:\n\taddi $s1, $s1, 0 \n",$1)
			} 
			| V_CHAR
			{
			 	ENTRADA * entrada = buscar_diccionario(&diccionario,$1);
                if (entrada != NULL) {
					char * valor = entrada->valor;
					fprintf(mipsOutput,"\n\taddi $s2, $zero,%s\npredicate:\n\tslt $t0, $s1, $s2\n\tbeq $t0, $zero, endfor\nconsequent:\n\taddi $s1, $s1, 0\n", valor);
				} else {
					printf("ERROR: variable %s no definida\n", $1);
				}
			}
		;

endOPfor: END 
	{
		fprintf(mipsOutput,"\taddi $s1, $s1, 1 \n\tj predicate \nendfor: \n")
	}
	;

for: FOR numerosFor1 in numerosFor2 loop line endOPfor loop pcoma;

declaraciones:	V_CHAR dospuntos tipo dospuntos pigual V_INTEGER pcoma 
		   		{
					// a:Integer:=8;
					// &diccionario: es la dirección de memoria en la que se encuentra guardado.
					ENTRADA *entrada = buscar_diccionario(&diccionario,$1);
					int esValido;
					comprobar_tipo(&esValido, $3, 2);
					if(entrada == NULL && esValido == 1) {
						char integer[64];
						sprintf(integer, "%d", $6);
						printf("%s\n", integer);
						insertar_diccionario(&diccionario, $1, $3, integer);
						fprintf(output, "Valor de la V_CHAR %i\n",$6, lineno-1);
						// Nodo_AST *nodo = new_declaracion_Node_AST(2, $1, integer, &declarations_counter, mipsOutput);
					} else if(entrada == NULL && esValido == 0){
						printf("ERROR: %s no coincide el valor con el tipo de la V_CHAR %s. El valor tiene que ser: %s.\n", $3, $1, "Integer"); 
					} else {
						printf("ERROR: V_CHAR %s ya existe.\n", $1); 
						
					}
				}
			|
				V_CHAR dospuntos tipo dospuntos pigual V_FLOAT pcoma 
				{
					// a:Float:=8.6;
					ENTRADA *entrada = buscar_diccionario(&diccionario,$1);
					int esValido;
					comprobar_tipo(&esValido, $3, 4);
					if(entrada == NULL && esValido == 1) {
						char v_float[64];
						sprintf(v_float, "%f", $6);
						insertar_diccionario(&diccionario, $1, $3, v_float);
						fprintf(output, "Valor de la V_CHAR %i\n",$6, lineno-1);
						Nodo_AST *nodo = new_declaracion_Node_AST(4, $1, v_float, &declarations_counter, mipsOutput);
					} else if(entrada == NULL && esValido == 0){
						printf("ERROR: %s no coincide el valor con el tipo de la V_CHAR %s. El valor tiene que ser: %s.\n", $3, $1, "Float"); 
					} else {
						printf("ERROR: V_CHAR %s ya existe.\n", $1); 
					}
				}
		   	|
			   V_CHAR dospuntos tipo dospuntos pigual COMILLA V_CHAR COMILLA pcoma 
				{
					// a:String:="Hola";
					ENTRADA *entrada = buscar_diccionario(&diccionario,$1);
					int esValido;
					comprobar_tipo(&esValido, $3, 6);
					if(entrada == NULL && esValido == 1) {
						insertar_diccionario(&diccionario, $1,$3, $7);
						fprintf(output, "Valor de la V_CHAR %i\n",$7, lineno-1);
						Nodo_AST *nodo = new_declaracion_Node_AST(6, $1, $7,&declarations_counter, mipsOutput);
					} else if(entrada == NULL && esValido == 0){
						printf("ERROR: %s no coincide el valor con el tipo de la V_CHAR %s. El valor tiene que ser: %s.\n", $3, $1, "String"); 
					} else {
						printf("ERROR: V_CHAR %s ya existe.\n", $1); 
					}
				}

		   	|
			   	

				V_CHAR dospuntos tipo dospuntos pigual V_CHAR pcoma 
		   		{
					// a:Integer:=b;
					ENTRADA *entrada = buscar_diccionario(&diccionario,$6);
					if (entrada != NULL) {
						char* valor = entrada->valor;
						insertar_diccionario(&diccionario, $1, $3, valor);
						fprintf(output, "Valor de la V_CHAR %i\n",$$, lineno-1);
					} else { 
						$$ = 0;
						printf("ERROR: V_CHAR %s no definida\n", $6); 
					} 
				}
		   	|	V_CHAR dospuntos tipo pcoma
		   ;	
operaciones_cond: operaciones
			{
				fprintf(mipsOutput,"j end \n endif%i: ",lineno-2);
			}
			| operaciones_bool
			| imprimir
			;
operaciones_cond_text: 
			| declaraciones
			| condicional
			| for
			;
condicional: IF DELIMITADORES operaciones_bool DELIMITADORES operaciones_cond END
		| IF DELIMITADORES operaciones_bool DELIMITADORES operaciones_cond ELSE operaciones_cond END
		| IF DELIMITADORES operaciones_bool DELIMITADORES operaciones_cond ELSE operaciones_cond_text END
		;

operaciones_bool:v_type RELATION_EXP v_type
			{ 
				char * signo = $2;
				printf("El operador del condicional es: %s\n", signo);
				if((strcmp(signo, ">") == 0) || (strcmp(signo, ">=") == 0)) {
					printf("Mayor o mayor-igual!\n");
					char* b = generate();
					fprintf(mipsOutput,"\n.text\n\taddi $s1,$zero, %i\n\taddi $s2,$zero, %i\n\tslt $t3, $s1, $s2\n\tbeq $t3, $zero,alternate%s\nj endif%i\n\talternate%s:",$1,$3,b,lineno-1,b);
				} else if((strcmp(signo, "<") == 0) || (strcmp(signo, "<=") == 0)) {
					printf("Menor o menor-igual!\n");
					char* b = generate();
					fprintf(mipsOutput,"\n.text\n\taddi $s1,$zero, %i\n\taddi $s2,$zero, %i\n\tslt $t3, $s2, $s1\n\tbeq $t3, $zero,alternate%s\nj endif%i\n\talternate%s:",$1,$3,b,lineno-1,b);

				}
			}
			| v_type EQUALITY_EXP v_type
			{ 
				char * signo = $2;
				printf("El operador del condicional es: %s\n", signo);
				if((strcmp(signo, "==") == 0)) {
					printf("Igual!\n");
					char* b = generate();
					fprintf(mipsOutput,"\n.text\n\taddi $s1,$zero, %i\n\taddi $s2,$zero, %i\n\tbeq $s1, $s2,alternate%s\nj endif%i\nalternate%s:",$1,$3,b,lineno-1,b);
				}
			}
			;

operaciones: V_CHAR dospuntos pigual V_INTEGER ADD V_INTEGER pcoma
			{
				// char * signo = $5;
				char * c_result;
				int result;
				if (strcmp($5, "+") == 0) {
					printf("OPERACIONES: Suma.\n");
					char* primera = generate();
					char* segunda = generate();
					fprintf(mipsOutput,"\n.data\n\t%s: .word %d\n\t%s: .word %d\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tadd $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, $4, segunda, $6, primera, segunda);
					int valor = $4 + $6;
					char integer[64];
					sprintf(integer, "%d", valor);
					insertar_diccionario(&diccionario, $1, 2, integer);

				} else {
					printf("OPERACIONES: Resta.\n");
					char* primera = generate();
					char* segunda = generate();
					fprintf(mipsOutput,"\n.data\n\t%s: .word %d\n\t%s: .word %d\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tsub $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, $4, segunda, $6, primera, segunda);
					int valor = $4 - $6;
					char integer[64];
					sprintf(integer, "%d", valor);
					insertar_diccionario(&diccionario, $1, 2, integer);

				}
			}

			| V_CHAR dospuntos pigual V_INTEGER ADD V_CHAR pcoma
			{
				// char * signo = $5;
				char * c_result;
				ENTRADA *entrada = buscar_diccionario(&diccionario,$6);
				if(entrada != NULL) {
					char * valor = entrada->valor;
					if (strcmp($5, "+") == 0) {
						printf("OPERACIONES: Suma (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						printf("%s\n", valor);
						fprintf(mipsOutput,"\n.data\n\t%s: .word %d\n\t%s: .word %s\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tadd $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, $4, segunda, valor, primera, segunda);

						int value_int;
						sscanf(valor, "%d", &value_int);
						int suma = $4 + value_int;
						
						char integer[64];
						sprintf(integer, "%d", suma);
						insertar_diccionario(&diccionario, $1, 2, integer);

					} else {
						printf("OPERACIONES: Resta (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						printf("%s\n", valor);
						fprintf(mipsOutput,"\n.data\n\t%s: .word %d\n\t%s: .word %s\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tsub $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, $4, segunda, valor, primera, segunda);
						
						int value_int;
						sscanf(valor, "%d", &value_int);
						int resta = $4 - value_int;
						
						char integer[64];
						sprintf(integer, "%d", resta);
						insertar_diccionario(&diccionario, $1, 2, integer);
					}
					

				}
			} | V_CHAR dospuntos pigual V_CHAR ADD V_INTEGER pcoma
			{
				// char * signo = $5;
				char * c_result;
				ENTRADA *entrada = buscar_diccionario(&diccionario,$4);
				if(entrada != NULL) {
					char * valor = entrada->valor;
					if (strcmp($5, "+") == 0) {
						printf("OPERACIONES: Suma (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						printf("%s\n", valor);
						fprintf(mipsOutput,"\n.data\n\t%s: .word %s\n\t%s: .word %d\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tadd $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, valor, segunda, $6, primera, segunda);

						int value_int;
						sscanf(valor, "%d", &value_int);
						int suma = value_int + $6;
						
						char integer[64];
						sprintf(integer, "%d", suma);
						insertar_diccionario(&diccionario, $1, 2, integer);

					} else {
						printf("OPERACIONES: Resta (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						printf("%s\n", valor);
						fprintf(mipsOutput,"\n.data\n\t%s: .word %s\n\t%s: .word %d\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tsub $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, valor, segunda, $6, primera, segunda);

						int value_int;
						sscanf(valor, "%d", &value_int);
						int resta = value_int - $6;
						
						char integer[64];
						sprintf(integer, "%d", resta);
						insertar_diccionario(&diccionario, $1, 2, integer);

					}

				}
			} | V_CHAR dospuntos pigual V_CHAR ADD V_CHAR pcoma
			{
				// char * signo = $5;
				char * c_result;
				ENTRADA *entrada1 = buscar_diccionario(&diccionario,$4);
				ENTRADA *entrada2 = buscar_diccionario(&diccionario,$6);
				if(entrada1 != NULL && entrada2 != NULL) {
					char * valor1 = entrada1->valor;
					char * valor2 = entrada2->valor;
					if (strcmp($5, "+") == 0) {
						printf("OPERACIONES: Suma (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						fprintf(mipsOutput,"\n.data\n\t%s: .word %s\n\t%s: .word %s\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tadd $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, valor1, segunda, valor2, primera, segunda);

						int value_int1;
						int value_int2;
						sscanf(valor1, "%d", &value_int1);
						sscanf(valor2, "%d", &value_int2);
						int suma = value_int1 + value_int2;
						
						char integer[64];
						sprintf(integer, "%d", suma);
						insertar_diccionario(&diccionario, $1, 2, integer);

					} else {
						printf("OPERACIONES: Resta (2a variable).\n");
						char* primera = generate();
						char* segunda = generate();
						fprintf(mipsOutput,"\n.data\n\t%s: .word %s\n\t%s: .word %s\n.text\n\tlw $t0, %s($zero)\n\tlw $t1, %s($zero)\n\tsub $t2, $t0, $t1\n\tli $v0, 1\n\tmove $a0, $t2\n\tsyscall\n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n", primera, valor1, segunda, valor2, primera, segunda);
						
						int value_int1;
						int value_int2;
						sscanf(valor1, "%d", &value_int1);
						sscanf(valor2, "%d", &value_int2);
						int resta = value_int1 - value_int2;

						char integer[64];
						sprintf(integer, "%d", resta);
						insertar_diccionario(&diccionario, $1, 2, integer);

					}

				}
			}
			| V_CHAR dospuntos pigual V_INTEGER MULT V_INTEGER pcoma 
			{
				printf("OPERACIONES: Multiplicacion.\n");
				char* primera = generate();
				char* segunda = generate();
				int result = $4 * $6; 
				printf("\t%d\n", result);
				fprintf(mipsOutput,"\n.text\n\taddi $t0,$zero, %i\n\taddi $t1,$zero, %i\n\tmul $t2, $t0, $t1\nli $v0, 1\n\tmove $a0, $t2 \nsyscall \n\taddi $v0, $zero, 4\n\tla $a0, space\nsyscall\n",$4,$6,$4,$6);
			}
			| V_CHAR dospuntos pigual V_INTEGER DIVISION V_INTEGER pcoma 
			{
				printf("OPERACIONES: Division.\n");
				char* primera = generate();
				char* segunda = generate();
				double result = $4 / $6;
				printf("\t%d\n", result);
				fprintf(mipsOutput,"\n .text\n addi $t0,$zero, %i\n addi $t1,$zero, %i\n div $t2, $t0, $t1 \nli $v0, 1\n  move $a0, $t2 \n	syscall \n addi $v0, $zero, 4\n la $a0, space \n syscall \n",$4,$6,$4,$6);
			}
			;
				
imprimir: PUTLINE DELIMITADORES COMILLA V_CHAR COMILLA DELIMITADORES pcoma
 			{
				printf("%s de tipo %d:\n", $4, "String");

			}
		| PUTLINE DELIMITADORES V_CHAR DELIMITADORES pcoma
			{	
				ENTRADA *entrada = buscar_diccionario(&diccionario,$3);
                if (entrada != NULL) {
					char * valor = entrada->valor;
					printf("(bison.y) ENCONTRADO! Valor entrada: %s\n", valor);
					int type = entrada->tipo;
					if(type == 2 || type == 4) {
						printf("%s\n", entrada->valor);

					} else {
						printf("%s\n", entrada->valor);
					}
				} else {
					$$ = 0;
					printf("ERROR: V_CHAR %s no definida\n", $3);
				}
			}
		;

v_type: V_INTEGER
		| V_CHAR
		| V_FLOAT
		;

tipo: INT  		{ $$ = TYPE_INT;  printf("Integer.\n")   }
	| CHAR 		{ $$ = TYPE_CHAR;  }
	| NATURAL 	{ $$ = TYPE_NAT;  }
	| FLOAT 	{ $$ = TYPE_FLOAT; printf("Float.\n") }
	| POSITIVE 	{ $$ = TYPE_POSITIVE;  }
	| STRING 	{ $$ = TYPE_STRING;  }
	| BOOLEAN 	{ $$ = TYPE_BOOLEAN;  }

;
retornar: return V_CHAR pcoma
	;

pcoma: PCOMA;
is: IS;
division: DIVISION;
coma: COMA;
in: IN;
loop: LOOP;
dospuntos: DOSPUNTOS;
return: RETURN;
pigual:PIGUAL;

%%

extern FILE *yyin;
int main(int argc,char *argv[])
{	
    char filename[40];
	++argv, --argc; /* se salta el nombre del programa */
	if (argc>0)
		yyin = fopen(argv[0], "r");
	else {
		printf("Introduzca el nombre del fichero de entrada: ");
		scanf("%s", &filename);
		inicializar_diccionario(&diccionario);
		yyin = fopen(filename, "r");
		mipsOutput = fopen( "./mipsOutput.txt", "wt" );
        if ((output = fopen( "./lexOutput.txt", "wt" )) == NULL )
        {
            printf("Error creando el fichero de salida.\n");
        } else {
            fprintf(output,"%-50s%-30s%-15s\n", "TOKEN","LEXEMA","LINEA");
            yyparse();
            printf("\nFichero de salida creado correctamente.\n");
        }
        fclose(yyin);
	}
	liberar_diccionario(&diccionario);
    return 0;
}

void yyerror(char *s) {
    printf("%d: %s\n", lineno, s) ;
}


