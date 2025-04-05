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

void volcarFicheroV2ALaBBDD(char *nomfich, sqlite3 *db) {
    FILE *fichero = fopen(nomfich, "r");
    if (fichero == NULL) {
        printf("Error al abrir el fichero\n");
        fflush(stdout);
        return;
    }

    char sql[200];
    sqlite3_stmt *stmt;
    char nombre[50], apellido[50];
    int edad;
    float dinero, deuda;

    while (fscanf(fichero, "%[^,],%[^,],%d,%f,%f\n", nombre, apellido, &edad, &dinero, &deuda) == 5) {
        sprintf(sql, "INSERT INTO Persona(nombre, apellido, edad, dinero, deuda) VALUES ('%s', '%s', %d, %f, %f)", nombre, apellido, edad, dinero, deuda);
        sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
        sqlite3_step(stmt); //Ejecutar la sentencia
        sqlite3_finalize(stmt); //Cerrar la sentencia
    }

    fclose(fichero); 
}

void actualizarPersonaBD(char *nomfich, sqlite3 *db) {
    FILE *fichero = fopen(nomfich, "r");
    if (fichero == NULL) {
        printf("Error al abrir el fichero: %s\n", nomfich);
        fflush(stdout);
        return;
    }

    char sql[200];
    sqlite3_stmt *stmt;
    char nombre[50], apellido[50];
    int edad;
    float dinero, deuda;

    // Leer cada línea del fichero y actualizar la base de datos
    while (fscanf(fichero, "%[^,],%[^,],%d,%f,%f\n", nombre, apellido, &edad, &dinero, &deuda) == 5) {
        // Crear la consulta SQL para actualizar la tabla Persona
        sprintf(sql, "UPDATE Persona SET dinero = %f, deuda = %f WHERE nombre = '%s' AND apellido = '%s'", dinero, deuda, nombre, apellido);

        // Preparar la consulta
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
            printf("Error al preparar la consulta: %s\n", sqlite3_errmsg(db));
            continue; // Pasar al siguiente registro en caso de error
        }

        // Ejecutar la consulta
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            printf("Error al ejecutar la consulta: %s\n", sqlite3_errmsg(db));
        }

        // Finalizar la consulta
        sqlite3_finalize(stmt);
    }

    // Cerrar el fichero
    fclose(fichero);

}