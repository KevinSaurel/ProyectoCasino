#include "personas.h"  

void pedirPrestamo(Cliente *c){
    printf("Ingrese el monto del prestamo: ");
    scanf("%f", &c->prestamo);
    printf("Ingrese la cantidad de cuotas: ");
    scanf("%d", &c->cuotas);
    printf("Ingrese el interes: ");
    scanf("%f", &c->interes);
}

void devolverPrestamo(Cliente *c){
    printf("El monto a devolver es: %.2f\n", c->prestamo * (1 + c->interes));
}
