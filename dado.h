#ifndef DADO_H_
#define DADO_H_
#include "personas.h"
void inicializar_dado(int recipientesCantidad, int selecionado);
void lanzar_dado(int recipientesCantidad,int ganador);
void ganar(int victoria,int cantidadRecipiente);
void menuDados(Cliente *c);
void seleccion();



#endif /* DADO_H_ */