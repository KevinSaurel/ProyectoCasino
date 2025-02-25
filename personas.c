#include "personas.h"  

void pedirPrestamo(Cliente *c){
    float prestamo;
    printf("Ingrese el monto del prestamo: ");
    scanf("%f", &prestamo);
    c->dinero += prestamo; 
    c->deuda += prestamo; 
    //printf("Ingrese la cantidad de cuotas: ");
   // scanf("%d", &c->cuotas);
   // printf("Ingrese el interes: ");
   // scanf("%f", &c->interes);
}

void devolverDeuda(Cliente *c){
    printf("El monto a devolver es: %.2f\n", c->deuda * 1.05);//interes del 5%
    if(c->dinero >= c->deuda * 1.05){
        c->dinero -= c->deuda * 1.05;
        c->deuda = 0;
    }else{
        printf("No tiene suficiente dinero para devolver la deuda\n");
    }
}
int comprobarEdad(Cliente c){
    if(c.edad >= 18){
        return 1;
    }else{
        return 0;
    }
}
void pedirDatosCliente(Cliente *c){

}
void cargarDatosCliente(Cliente *c){

}
void mostrarBalanceBanco(Cliente c){
    printf("El dinero de la cuenta es: %.2f\n Deuda pendiente:  %.2f\n", c.dinero,c.deuda);
}
