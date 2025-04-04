#include "bd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializarBBDD(sqlite3 **db) {
    int result = sqlite3_open("bd/bd.db", db);
	if (result != SQLITE_OK) {
		printf("Error al abrir la BBDD\n");
		fflush(stdout);
		return result;
	}
}


void crearTablas(sqlite3 *db) {
    sqlite3_stmt *stmt;
    char sql[200];
    sprintf(sql,
        "CREATE TABLE IF NOT EXISTS Persona(nombre varchar(50), apellido varchar(50),edad int, dinero float, deuda float)");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
    sqlite3_step(stmt); //Ejecutar la sentencia
    sqlite3_finalize(stmt); //Cerrar la sentencia
}
