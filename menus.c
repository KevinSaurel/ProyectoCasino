#include "menus.h"
#include "personas.h"
#include <stdio.h>
#include <stdlib.h> 

char menuJuegos() {
    char opcion;
    system("cls");
    printf("====================================================================================\n");
    printf("                     SELECCIONA UNA MODALIDAD DE JUEGO                             \n");
    printf("====================================================================================\n");
    printf("                     1. Maquina Tragaperras                                        \n");
    printf("                     2. Carrera de Caballos                                        \n");
    printf("                     3. Blackjack                                                  \n");
    printf("                     4. Dados                                                      \n");
    printf("                     0. Salir                                                      \n");
    printf("====================================================================================\n");
    printf("                     Elige una opcion: ");
    
    fflush(stdout);
    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}

char menuPrincipal() {
    char opcion;
    system("cls");
    printf("====================================================================================\n");
    printf("                           MENU PRINCIPAL                                          \n");
    printf("====================================================================================\n");
    printf("                     1. Juegos disponibles                                         \n");
    printf("                     2. Mirar cuenta de banco                                      \n");
    printf("                     3. Pedir prestamo al banco                                    \n");
    printf("                     4. Pagar deudas                                               \n");
    printf("                     0. Salir                                                      \n");
    printf("====================================================================================\n");
    printf("                     Elige una opcion: ");
    
    fflush(stdout);
    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}

char menuSesion() {
    char opcion;
    system("cls");
    printf("====================================================================================\n");
    printf("                           MENU DE SESION                                          \n");
    printf("====================================================================================\n");
    printf("                     1. Nuevo Jugador                                              \n");
    printf("                     2. Cargar Jugador                                             \n");
    printf("                     0. Salir                                                      \n");
    printf("====================================================================================\n");
    printf("                     Elige una opcion: ");
    
    fflush(stdout);
    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}
//los menus de juegos no se utilizan
char menuTragaperras() {
    char opcion;
    system("cls");
    printf("====================================================================================\n");
    printf("                           MENU TRAGAPERRAS                                        \n");
    printf("====================================================================================\n");
    printf("                     1. Jugar                                                      \n");
    printf("                     0. Salir de la tragaperras                                    \n");
    printf("====================================================================================\n");
    printf("                     Elige una opcion: ");
    
    fflush(stdout);
    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}

char menuCarrera() {
    char opcion;
    system("cls");
    printf("====================================================================================\n");
    printf("                           MENU CARRERA DE CABALLOS                                \n");
    printf("====================================================================================\n");
    printf("                     1. Jugar                                                      \n");
    printf("                     0. Salir de la carrera                                        \n");
    printf("====================================================================================\n");
    printf("                     Elige una opcion: ");
    
    fflush(stdout);
    fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}