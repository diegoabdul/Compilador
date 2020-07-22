#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "diccionario.h"

/**********************************************************************************/
/**********************************************************************************/

/**
 * Devuelve un puntero al un espacio del tamaño del parametro 'bytes'
 * reservado en memoria.
 */
void* smalloc (size_t bytes) {
  /** 'malloc' devuelve un puntero al byte mas bajo en el bloque de memoria asignado/reservado que está alineado adecuadamente 
   * para cualquier tupo de objeto con alineación fundamental.
  */
  void* ptr = malloc(bytes);
  
  if(ptr == NULL) {
    fprintf(stderr,"Problema al reservar memoria\n");
    exit(0);
    }
  else {
    return ptr;
    }
  }


/**********************************************************************************/
/**********************************************************************************/

void insertar_diccionario (DICCIONARIO *diccionario, char *nombre, int tipo, char *valor) {
  printf("\tinsertar_diccionario(): Nombre variable: %s.\n", nombre);
  printf("\tinsertar_diccionario(): Tipo variable: %d.\n", tipo);
  printf("\tinsertar_diccionario(): Valor variable: %s.\n", valor);

  ENTRADA *nueva;
  ENTRADA *primera = diccionario->primera;
  int i;
  
  // Asignamos el puntero donde se va a guardar la entrad, pasándole el tamaño del tipo ENTRADA.
  nueva = smalloc(sizeof(ENTRADA));
  // 
  nueva->siguiente = diccionario->primera;
  // Es necesario asignar el espacio suficiente al puntero destino en el que se va a almacenar *nombre, por eso mismo se le suma 1 al tamaño de nombre.
  nueva->nombre = smalloc(sizeof(nombre)+1);
  nueva->valor = smalloc(sizeof(valor)+1);

  strcpy(nueva->nombre, nombre);
  strcpy(nueva->valor, valor);

  nueva->tipo = tipo;

  printf("\t[TIPO]: %d\n", nueva->tipo);
  printf("\t[VALOR]: %s\n", nueva->valor);
  printf("\n");
  
  diccionario->primera = nueva;
  diccionario->num_entradas++;
  }


/**********************************************************************************/
/**********************************************************************************/

void inicializar_diccionario (DICCIONARIO *diccionario) {
  diccionario = smalloc(sizeof(DICCIONARIO));

  diccionario->primera = NULL;
  diccionario->num_entradas = 0;
}


char* generate()
{
   char* alphabet[52] = {"a", "b", "c", "d", "e", "f", "g",
      "h", "i", "j", "k", "l", "m", "n",
      "o", "p", "q", "r", "s", "t", "u",
      "v", "w", "x", "y", "z","a1","b2","c3","d4","e5",
	  "f6","g7","h8","i9","j10","k11","l12","m13","n14","o15",
	  "p16","q17","r18","s19","u20","w21","x22","y23","z24"}; 
  
    char* res = ""; 
    res = alphabet[rand() % 52];
    return res;
}

/**********************************************************************************/
/**********************************************************************************/

void liberar_diccionario (DICCIONARIO *diccionario) {
  ENTRADA *proxima = diccionario->primera;
  ENTRADA *borrada;
  diccionario->num_entradas = 0;
  
  while (proxima != NULL) {
    borrada = proxima;
    proxima = proxima->siguiente;
    free(borrada);
    }
  }


/**********************************************************************************/
/**********************************************************************************/

ENTRADA* buscar_diccionario (DICCIONARIO *diccionario, char *nombre) {
  printf("(buscar_diccionario()) %s\n", nombre);
  ENTRADA *entrada = diccionario->primera;
  int i;
  
  for (i=0; i<diccionario->num_entradas; i++) {
    // The strcmp() function compares two strings and returns 0 if both strings are identical.
    if (!strcmp(entrada->nombre, nombre)) {
			printf("(buscar_diccionario()) ENCONTRADO! Valor entrada: %s\n", entrada->valor);
      return entrada; 
    }
    entrada = entrada->siguiente;
    }
  
  return NULL;
  }

  // https://www.programiz.com/c-programming/library-function/string.h/strcmp
  void comprobar_tipo(int *esValido, int tipo_regla, int tipo_expected) {
    if(tipo_regla == tipo_expected) {
      *esValido = 1;
    } else {
      *esValido = 0;
    }
  }