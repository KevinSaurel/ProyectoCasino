#ifndef BD_H_
#define BD_H_
#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h> 
#include "../Model/personas.h"
#define NOMBRE_BBDD "bd/bd.db"

int inicializarBBDD(sqlite3 **db);
void crearTablaPersonas(sqlite3 *db);
void volcarFicheroPersonasALaBBDD(char *nomfich, sqlite3 *db);
void actualizarPersonaBD(char *nomfich, sqlite3 *db);
void crearTablaCarreras(sqlite3 *db);
void volcarFicheroCarrerasALaBBDD(char *nomfich, sqlite3 *db);
void cerrarBBDD(sqlite3 *db);
float conseguirDineroPersona(sqlite3 *db, char *nombre, char *apellido);
#endif /* BBDD_H_ */