#ifndef CARERRA_H_
#define CARERRA_H_
#include <stdio.h>
#include "personas.h"


typedef struct {
    int numero;
    int posicion;
} Caballo;
void carrera(Cliente c);
void startCarrera(Cliente *c);
void imprimirPistaCarrera(Caballo caballo);
void caballoGanador(Caballo caballo);
int carreraEnCurso(Caballo listaCaballos[]);
#endif // 