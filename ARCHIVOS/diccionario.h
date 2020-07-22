#include <stdlib.h>
#include <stdio.h>

// Declaramos tipos alternativos de datos para que sea mas sencilla la declaración de ciertos tipos.
typedef struct entrada ENTRADA;

// Estructura predeterminada de entrada.
struct entrada {
  ENTRADA *siguiente;
  char *nombre;
  int tipo;
  char *padre; // Si es de primer nivel, guardar procedure, sino guardar el nombre de la funcion a la que pertenece.
  char *valor;
  };
  
typedef struct diccionario DICCIONARIO;

struct diccionario {
  ENTRADA *primera;
  int num_entradas;
  };
  
void* smalloc (size_t);

void insertar_diccionario (DICCIONARIO*, char*, int, char*);

void inicializar_diccionario (DICCIONARIO*);

void liberar_diccionario (DICCIONARIO *);

ENTRADA* buscar_diccionario (DICCIONARIO*, char*);


char* generate();

void comprobar_tipo(int*, int, int);
