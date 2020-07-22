// Se crea un enum para almacenar los diferentes tipos de nodos que se pueden crear
typedef enum Tipo_Nodo {
	BASIC_NODE,  // no tiene ningún uso especial (solo para la raiz).
	// declaraciones
	DECL_NODE,   // declaración
	// statements
	IF_NODE,     // if statement
	ELSIF_NODE,  // else if branch
	FOR_NODE,    // for statement
	ASSIGN_NODE, // assigment
	SIMPLE_NODE, // continue, break and "main" return statements
	INCR_NODE,   // increment statement (non-expression one)
	FUNC_CALL,   // function call
	// expressions
	ARITHM_NODE, // arithmetic expression
	BOOL_NODE,   // boolean expression
	REL_NODE,    // relational expression
	EQU_NODE,    // equality expression
	// functions
	FUNC_DECL,   // function declaration
	RETURN_NODE, // return statement of functions
}Tipo_Nodo;

// enum para los operadores aritméticos (suma, resta, multiplicación y división)
typedef enum Arithm_op{
	ADD_OP,  // + operator
	SUB_OP,  // - operator
	MUL_OP,  // * operator
	DIV_OP , // / operator
	INC_OP, // ++ operator
	DEC_OP, // -- operator
}Arithm_op;

// enum para los operadores booleanos
typedef enum Bool_op{
	OR_OP,  // || operator
	AND_OP, // && operator
	NOT_OP  // ! operator
}Bool_op;

// enu para los operadores relacionales
typedef enum Rel_op{
	GREATER_OP,        // > operator
	LESS_OP,           // < operator
	GREATER_EQUAL_OP,  // >= operator
	LESS_EQUAL_OP     // <= operator
}Rel_op;

// enum para los operadores de igualdad
typedef enum Equ_op{
	EQUAL_OP,    // == operator
	NOT_EQUAL_OP // != operator
}Equ_op;

/**
 * La diferencia entre un union y un structure es que todos los componentes de un union se encuentran el a misma dirección de memoria.
 */
// posibles valores de las variables almacenadas
typedef union Tipo_Valor{
	int ival;
	double fval;
	char cval;
	char *sval;
}Tipo_Valor;

// estructura básica de un Nodo de un AST (Abstract Syntax Tree)
typedef struct Nodo_AST{
	enum Tipo_Nodo type;
	struct Nodo_AST *left;
	struct Nodo_AST *right;
}Nodo_AST;

typedef struct Declaracion_Nodo_AST{
	enum Tipo_Nodo type;
	// Nombre de la variable
	int data_type;
	char* name;
	char* data;
}Declaracion_Nodo_AST;

typedef struct If_Nodo_AST{
	enum Tipo_Nodo type; // node type

	// condition
	struct Nodo_AST *condition;

	// if branch
	struct Nodo_AST *if_branch;

	// else if branches
	struct Nodo_AST **elsif_branches;
	int elseif_count;

	// else branch
	struct Nodo_AST *else_branch;
}AST_Node_If;
/* Declaraciones */

Nodo_AST *new_declaracion_Node_AST(int data_type, char *name, char *data, int * declarations_counter, FILE *output);
void imprimir_Nodo(Nodo_AST *nodo);
void ast_traversal(Nodo_AST *nodo);
void prueba_impresion_declaracion(FILE * output);