#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 *  PROCESO DE CREACIÓN DE UN NODO:
 *      1. Se tiene que crear primero el la estructura de nodo que se quiera, AST_Nodo_Decl, ...
 * 		2. Despues, creamos la función que reciba los parámetros correspondientes a la estructura, menos el type que se mete directamente dentro de la función.
 * 		3. Finalmente se devuelve el nodo creado casteado a la estructura del nodo genérico.
 */

/**
 * .data
	texto: .asciiz "Hola mundo" //Texto
	char: .byte 'a' //Char
	numero1: .word 5 //Integer
	numero2: .float 5.33 //Float
	numero3: .double 7.323 //Double
 */ 
Nodo_AST *new_declaracion_Node_AST(int data_type, char *name, char *data, int *declarations_counter, FILE *output){
	printf("%d\n", *declarations_counter);
	printf("new_declaracion_Node_AST(): Creamos el nodo de DECLARACION\n");
	// Establecemos un espacio en memoria para guardar el nodo.
	Declaracion_Nodo_AST *nuevoNodo = malloc (sizeof (Declaracion_Nodo_AST));
	// Establecemos las entradas del nodo.
	nuevoNodo->type = DECL_NODE;
	nuevoNodo->data_type = data_type;
	nuevoNodo->name = name;
	nuevoNodo->data = data;
	// devolvemos el nodo
	printf("TAMANO data: %d\n", sizeof(data));
	printf("data-type: %d\n", data_type);
	if(*declarations_counter == 0) {
		fprintf(output, ".data\n");
	}
	if(data_type == 1) {
		fprintf(output, "\t%s: .byte '%s'\n", name, data);
		*declarations_counter = *declarations_counter+1;
	} else if (data_type == 2) {
		fprintf(output, "\t%s: .word %s\n", name, data);
		*declarations_counter = *declarations_counter+1;
	} else if (data_type == 4) {
		fprintf(output, "\t%s: .float %s\n", name, data);
		*declarations_counter = *declarations_counter+1;
	} else if (data_type == 6) {
		fprintf(output, "\t%s: .asciiz %s\n", name, data);
		*declarations_counter = *declarations_counter+1;
	}

	return (struct Nodo_AST *) nuevoNodo;
}

void imprimir_Nodo(Nodo_AST *nodo){
	/* temp nodes */
	Declaracion_Nodo_AST *temp_decl;

	switch(nodo->type){
		case BASIC_NODE:
			printf("Basic Node\n");
			break;
		case DECL_NODE:
			temp_decl = (struct Declaracion_Nodo_AST *) nodo;
			printf("Nodo de DECLARACION con data-type %d y nombre %s.\n",
				temp_decl->data_type, temp_decl->name);
			break;
		default:
			fprintf(stderr, "Error en la seleccion!\n");
			exit(1);
	}
}

void ast_traversal(Nodo_AST *nodo){
	int i;

	if(nodo == NULL){
		return;
	}

	// else if(node->type == IF_NODE){
	// 	AST_Node_If *temp_if = (struct AST_Node_If *) node;
	// 	ast_traversal(temp_if->condition);
	// 	ast_traversal(temp_if->if_branch);
	// 	for(i = 0; i < temp_if->elseif_count; i++){
	// 		ast_traversal(temp_if->elsif_branches[i]);
	// 	}
	// 	ast_traversal(temp_if->else_branch);
	// 	ast_print_node(node);
	// }
	/* the else if case */ 
	// else if(node->type == ELSIF_NODE){
	// 	AST_Node_Elsif *temp_elsif = (struct AST_Node_Elsif *) node;
	// 	ast_traversal(temp_elsif->condition);
	// 	ast_traversal(temp_elsif->elsif_branch);
	// 	ast_print_node(node);
	// }
	/* for case */
	// else if(node->type == FOR_NODE){
	// 	AST_Node_For *temp_for = (struct AST_Node_For *) node;
	// 	ast_traversal(temp_for->condition);
	// 	ast_traversal(temp_for->for_branch);
	// 	ast_print_node(node);
	// }
	/* return case */
	// else if(node->type == RETURN_NODE){
	// 	AST_Node_Return *temp_return = (struct AST_Node_Return *) node;
	// 	ast_traversal(temp_return->ret_val);
	// 	ast_print_node(node);
	// }
	/* others */
	else{
		imprimir_Nodo(nodo);
	}
}

void prueba_impresion_declaracion(FILE * output) {
	Tipo_Valor nombre_variable, data_variable;
	Tipo_Valor nombre_char, data_char;
	Tipo_Valor nombre_integer, data_integer;
	Tipo_Valor nombre_float, data_float;

	nombre_variable.sval = "nombre";
	data_variable.sval = "Adrian";

	nombre_char.sval = "Categoria";
	data_char.sval = "a";

	nombre_integer.sval = "Años";
	data_integer.sval = "21";

	nombre_float.sval = "Km recorridos";
	data_float.sval = "35.2";
	
	// Nodo_AST *nodo_prueba1 = new_declaracion_Node_AST(6, nombre_variable.sval, data_variable.sval, output);
	// Nodo_AST *nodo_prueba2 = new_declaracion_Node_AST(1, nombre_char.sval, data_char.sval, output);
	// Nodo_AST *nodo_prueba3 = new_declaracion_Node_AST(2, nombre_integer.sval, data_integer.sval, output);
	// Nodo_AST *nodo_prueba4 = new_declaracion_Node_AST(4, nombre_float.sval, data_float.sval, output);

	// ast_traversal(nodo_prueba1);
}