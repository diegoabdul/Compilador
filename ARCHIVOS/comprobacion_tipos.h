  
/* Opciones Tipos */
#define UNDEF 0
#define TYPE_CHAR 1
#define TYPE_INT 2
#define TYPE_NAT 3
#define TYPE_FLOAT 4
#define TYPE_POSITIVE 5
#define TYPE_STRING 6
#define TYPE_BOOLEAN 7

/* Opciones expresiones */
#define NONE 0
#define RELATIONAL_TOKEN 1  // <= | >= | < | >
#define EQUALITY_TOKEN 2    // == | !=
#define ARITHMETIC_TOKEN 3  // + | - | / | *
#define INCR_TOKEN 4        // ++ | --


int resultado_comprobacion_tipos (int tipo_derecha, int tipo_izquierda, int tipo_op);

void imprimir_error(int tipo_derecha, int tipo_izquierda, int tipo_op);

