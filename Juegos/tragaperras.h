#ifndef TRAGAPERRAS_H_
#define TRAGAPERRAS_H_
#include "../Model/personas.h"
typedef struct{
    int random;
    int posicion;
}Posicion;

typedef struct{
    Posicion *p;
    int numeroDePosiciones;
}ListaPosiciones;

void TragaPerras(Cliente *c);
void StartTragaPerras(Cliente *c);
void InicializarPosiciones(ListaPosiciones *p,int cantidadDeFrutas);
void ImprimirTragaPerras(ListaPosiciones p);

#endif // 