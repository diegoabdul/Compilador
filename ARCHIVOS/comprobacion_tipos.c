  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comprobacion_tipos.h"


int resultado_comprobacion_tipos (int tipo_izquierda, int tipo_derecha, int tipo_op) {
    switch (tipo_op) {
        case NONE:

            break;

        case RELATIONAL_TOKEN:
            /* code */
            break;

        case EQUALITY_TOKEN:
            /* code */
            break;
        case ARITHMETIC_TOKEN:
            if (tipo_izquierda == TYPE_INT)
            {
                if(tipo_derecha == TYPE_INT){
					return TYPE_INT;
				}
				else if(tipo_derecha == TYPE_FLOAT){
					return TYPE_FLOAT;
				}
				else{
					imprimir_error(tipo_izquierda, tipo_derecha, tipo_op);
				}
            } else if (tipo_izquierda == TYPE_FLOAT)
            {
                if(tipo_derecha == TYPE_INT){
					return TYPE_FLOAT;
				}
				else if(tipo_derecha == TYPE_FLOAT){
					return TYPE_FLOAT;
				}
				else{
					imprimir_error(tipo_izquierda, tipo_derecha, tipo_op);
				}
            }
            break;
        case INCR_TOKEN:
            /* code */
            break;
        default:
            break;
    }
}

void imprimir_error(int tipo_derecha, int tipo_izquierda, int tipo_op) {
    printf("ERROR! Los tipos %d y %d no son compatibles usando el operador %d.\n,", tipo_derecha, tipo_izquierda, tipo_op);
}