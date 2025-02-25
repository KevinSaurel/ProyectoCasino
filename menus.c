#include "menus.h"
#include "personas.h"
#include <stdio.h>
char menuJuegos(){
	char opcion;
	
    printf("Selecciona una modalidad de juego \n");
	printf("1. Maquina Tragaperras\n");
	printf("2. Carrera de Caballos\n");
	printf("3. Blackjack\n");
	printf("0. Salir\n");
	printf("Elige una opci�n: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}
char menuPrincipal(){
	char opcion;
	
	printf("1. Juegos disponibles\n");
	printf("2. Mirar cuenta de banco\n");
	printf("3. Pedir prestamo al banco\n");
	printf("4. Pagar deudas\n");

	//printf("3. Estadisticas\n");//Dependiendo de como llevemos la carga de trabajo podemos crear hasta una leaderboard
	printf("0. Salir\n");
	printf("Elige una opcion: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}
char menuSesion(){//es el primero que se muestra
	char opcion;
	
	printf("1. Nuevo Jugador\n");
	printf("2. Cargar Jugador\n");//no hace nada todavia
	//printf("3. Borrar Jugador\n");//no hace nada todavia, no se si implementarlo
	printf("0. Salir\n");
	printf("Elige una opcion: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}
char menuTragaperras(){
	char opcion;
	
	printf("1. Jugar\n");
	//printf("2. Guardar partida\n"); //se guardara cada vez que le demos a salir
	//se implemnetara con los ficheros
	printf("0. Salir de la tragaperras\n");
	printf("Elige una opcion: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}