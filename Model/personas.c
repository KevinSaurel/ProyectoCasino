#include "personas.h"  
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "../Persistencia/fichero.h"
#include "../Persistencia/config.h"
#include "../Logger/logger.h"

void pedirPrestamo(Cliente *c){
    float prestamo;
    printf("Ingrese el monto del prestamo: ");
    scanf("%f", &prestamo);
    if (prestamo < 0 )
    {
        printf("No se puede pedir un prestamo negativo\n");
        return;
    }
    c->dinero += prestamo; 
    c->deuda += prestamo; 
}
void devolverDeuda(Cliente *c){//problema, si pides un prestamo muy generoso, no puedes devolverlo
    printf("El monto a devolver es: %.2f\n", c->deuda * 1.05);//interes del 5%
    if(c->dinero >= c->deuda * 1.05){
        c->dinero -= c->deuda * 1.05;
        c->deuda = 0;
        printf("Deuda pagada, tenga un buen dia\n");

    }else{
        printf("No tiene suficiente dinero para devolver la deuda\n");
        bancaRota(c);
    }
}
int bancaRota(Cliente *c){
    if(c->dinero < 0&&c->deuda >= c->dinero ){
        c->deuda -= c->dinero;//el dinero esta en negativo, por lo que le restamos(negativo-negativo = positivo) creo
        c->dinero = 0;
        printf("Debe mas dinero del que pose, el casino procedera a cobrar su deuda\n");
        //para que no se pueda seguir jugando aun estando en negativo ofreceremos 50 euros de prestamo
        printf("Se le ofrecera otra oportunidad de empezar de 0\n");//esta parte se borrara cuando se implemente el fichero
        c->dinero = 50;
        return 0;
    }
    return 1;
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
    *c =  getPersona(nombre, "ficheros/personas.txt") ;

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


void compararDatosConfig(Cliente *c) {
    Config config;
	char user[TAM],con[TAM];

	config = leerConfiguracion("ficheros/configuracion.config");
	writeLog("Configuración leída");

    pedirDatosCliente(c);
    if (strcmp(c->nombre, config.nombreAdmin) == 0 && strcmp(c->apellido, config.apellidoAdmin) == 0) {
        writeLog("Inicio de sesión exitoso");
    } else {
        writeLog("Inicio de sesión fallido");
    }
}