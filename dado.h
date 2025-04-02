#ifndef DADO_H_
#define DADO_H_
#include "personas.h"
int inicializar_dado(int recipientesCantidad, int selecionado);
void lanzar_dado(int recipientesCantidad,int ganador);
int ganar(int victoria,int cantidadRecipiente);
void menuDados(Cliente *c);
void seleccion(Cliente *c);



#endif /* DADO_H_ */