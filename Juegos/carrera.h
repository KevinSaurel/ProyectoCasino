#ifndef CARERRA_H_
#define CARERRA_H_
#include <stdio.h>
#include "../Model/personas.h"


typedef struct {
    int numero;
    int posicion;
    int seleccionado;//si es 1 es el caballo por el cual hemos apostado, si no sera un 0
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

void carrera(Cliente *c, ListaCarreras lc);
void startCarrera(Cliente *c, Carrera ca);
void imprimirPistaCarrera(Caballo caballo, Carrera c);
void caballoGanador(Caballo caballo, Carrera c,Cliente *cliente);
int carreraEnCurso(Caballo listaCaballos[], Carrera c);
void visualizarCarrera(Carrera c);
void visualizarCarreras(ListaCarreras lc);
void visualizarTitulos();
int seleccionarCarrera(ListaCarreras lc);


#endif // 