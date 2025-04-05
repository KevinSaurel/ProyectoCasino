#ifndef BD_H_
#define BD_H_
#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h> 
#include "personas.h"
#define NOMBRE_BBDD "bd/bd.db"

int inicializarBBDD(sqlite3 **db);
void crearTablas(sqlite3 *db);
void volcarFicheroV2ALaBBDD(char *nomfich, sqlite3 *db);
void actualizarPersonaBD(char *nomfich, sqlite3 *db);
#endif /* BBDD_H_ */