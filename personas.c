#include "personas.h"  
#include <stdio.h>
#include <string.h>

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
    printf("Ingrese el nombre de Usuario: ");
    scanf("%s", c->nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", c->apellido);
    printf("Ingrese la edad: ");
    scanf("%d", &c->edad);
    c->dinero = 500;
    c->deuda = 0;
}
void cargarDatosCliente(Cliente *c){
    //Aqui se implementaria la carga de datos de un archivo
    char nombre[50];
    printf("Ingrese el nombre de Usuario: ");
    scanf("%s", nombre);
    //cargar desde el fichero usando el nombre
    //if(nombre.existe){
    //    c->dinero = nombre.dinero;
    //    c->deuda = nombre.deuda;
    //    c->edad = nombre.edad;
    //}else{
    //    printf("El usuario no existe\n");
    //    printf("Desea crearlo(S/N): ");
    //    char respuesta;
    //    scanf("%c", &respuesta);
    //    if(respuesta == 'S'){
    //        pedirDatosCliente(c);
    //    }else{
    //        printf("No se ha creado el usuario\n");
    //    }
    //}


}
void mostrarBalanceBanco(Cliente c){
    printf("El dinero de la cuenta es: %.2f\n Deuda pendiente:  %.2f\n", c.dinero,c.deuda);
}
void borrarDatosCliente(Cliente *c){
    strcpy(c->nombre, "");
    strcpy(c->apellido, "");
    c->edad = 0;
    c->dinero = 0;
    c->deuda = 0;
}
