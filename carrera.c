#include <stdio.h>
#include "menus.h"
#include "personas.h"
#include "carrera.h"
#include <stdlib.h>// para el rands
#include <time.h> // para el time
#include <conio.h>   // For kbhit() //waits for a key to be pressed
#include <windows.h> // For Sleep() //sleep
#include <stdlib.h>0

#define MAX_DISTANCE 50  // Distancia de la carrera
void carrera(Cliente c){//el menu se crea en el main, y las partes de arriba en la clase menu
     int flag = 0;
     


     printf("\n====================================================================================\n");
     printf("                              BIENVENIDO A LA CARRERA DE CABALLOS                              \n");//Por ahora de caballos, sujeto a cambio
     printf("====================================================================================\n");
     printf("                                  REGLAS                 COSTE                         \n");
     printf("                         - Ganador x10        -Cada tirada son 10€             \n");//podemos poner distintos tipos de apuestas, solo preguntamelo si lo quieres
     printf("                         - Dos numeros son x5          -Saldo:%.2f                           \n",c.dinero);
     printf("====================================================================================\n\n");

     printf("                                 [1] Jugar                                           \n");
     printf("                                 [0] Salir                                           \n\n");
     printf("                              Seleccione una opcion: ");
               int opcion;
               scanf("%d", &opcion);
               switch(opcion){
                    case 1:
                    printf("\n                             EMPEZANDO JUEGO                            \n");
                    printf("====================================================================================\n");
                    startCarrera(&c);
                    break;
                    case 0:
                    flag = 1;
                    printf("\n                              HASTA LUEGO                                  \n");
                    printf("====================================================================================\n");
                    break;
                    default:
                    printf("\n                            OPCION NO VALIDA                                 \n");
                    printf("====================================================================================\n");
                    break;
               }
           

     

}
void startCarrera(Cliente *c){
    int  flag=0;
    int apuesta = 10;//habria que escribir un scan para pedir la apuesta, pero habria que poner comprobaciones de que no apueste en negativo
    //primero lo probare con una apuesta fija
    printf("\n                           CARRERA EN MARCHA...                               \n");
    printf("                      Presiona cualquier tecla para detener                       \n\n");
    
    

    int c1 = 0, c2 = 0, c3 = 0;

    srand(time(NULL)); // Inicializar la semilla de números aleatorios

    while (c1 < MAX_DISTANCE && c2 < MAX_DISTANCE && c3 < MAX_DISTANCE) {
        c1 += rand() % 3;  // Movimiento aleatorio entre 0 y 3
        c2 += rand() % 3;
        c3 += rand() % 3;

        // Limpiar pantalla (Windows usa system("cls"))
        system("cls");

        // Imprimir la pista de la carrera
        printf("Caballo 1: ");
        fflush(stdout);
        for (int i = 0; i < MAX_DISTANCE; i++) {
            if (i == c1){
                printf("🐎​​");
                fflush(stdout);
            }else{
                printf(" ");
                fflush(stdout);
            }
        }
        printf("\n");
        fflush(stdout);

        printf("Caballo 2: ");
        fflush(stdout);
        for (int i = 0; i < MAX_DISTANCE; i++) {
            if (i == c2){
                printf("🐎​​");
                fflush(stdout);

            }else{
                printf(" ");
                fflush(stdout);
            }
        }
        printf("\n");
        fflush(stdout);

        printf("Caballo 3: ");
        fflush(stdout);
        for (int i = 0; i < MAX_DISTANCE; i++) {
            if (i == c3){
                printf("🐎​​");
                fflush(stdout);
            }else{
                printf(" ");
                fflush(stdout);

            }
        }
        printf("\n");
        printf("---------------------------------------------------------------------\n---------------------------------------------------------------------\n");
        fflush(stdout);

        // Esperar medio segundo (500 ms) en Windows
        Sleep(500);
    }

    // Mostrar el resultado de la carrera
    printf("\n¡Carrera terminada! Gracias por participar!\n");
    fflush(stdout);

    if (c1 >= MAX_DISTANCE){
        printf("¡Caballo 1 gana!\n");
    	fflush(stdout);
    }

    if (c2 >= MAX_DISTANCE){
        printf("¡Caballo 2 gana!\n");
    	fflush(stdout);
    }

    if (c3 >= MAX_DISTANCE){
        printf("¡Caballo 3 gana!\n");
    	fflush(stdout);
    }

}
