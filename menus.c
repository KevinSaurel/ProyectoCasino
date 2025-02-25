#include "menus.h"
#include <stdio.h>
char menuPrincipal(){
	char opcion;
	
    printf("Selecciona una modalidad de juego \n");
	printf("1. Maquina Tragaperras\n");
	printf("2. Carrera de Caballos\n");
	printf("3. Blackjack\n");
    printf("4. Recursos del casino\n");
	printf("0. Salir\n");
	printf("Elige una opci�n: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}
char menuSesion(){
	char opcion;
	
	printf("1. Nuevo Jugador\n");
	printf("2. Cargar Jugador\n");//no hace nada todavia
	printf("0. Salir\n");
	printf("Elige una opcion: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}
char menuJuegos(){
	char opcion;

	return opcion;
}