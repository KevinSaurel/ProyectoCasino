#ifndef CARERRA_H_
#define CARERRA_H_
#include <stdio.h>
#include "personas.h"


typedef struct {
    int numero;
    int posicion;
} Caballo;

typedef struct{
    int numCaballos;
    int distancia;
    char nombre[50];
    int premio;
}Carrera;

typedef struct{
    Carrera aCarreras[5];
    int numCarreras;
}ListaCarreras;

void carrera(Cliente c);
void startCarrera(Cliente *c, Carrera ca);
void imprimirPistaCarrera(Caballo caballo, Carrera c);
void caballoGanador(Caballo caballo, Carrera c);
int carreraEnCurso(Caballo listaCaballos[], Carrera c);
void visualizarCarrera(Carrera c);
void visualizarCarreras(ListaCarreras lc);
void visualizarTitulos();
int seleccionarCarrera(ListaCarreras lc);

#endif // 