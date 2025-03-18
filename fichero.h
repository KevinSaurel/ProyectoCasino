#ifndef FICHERO_H_
#define FICHERO_H_
#include "personas.h"


void guardarNuevaPersona(Cliente cliente, char*fichero );
Cliente getPersona(char *nombreCliente, char *fichero) ;
void actualizarPersona(Cliente clienteActualizado, char *fichero) ;


#endif