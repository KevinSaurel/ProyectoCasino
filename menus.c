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