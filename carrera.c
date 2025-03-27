#include <stdio.h>
#include "menus.h"
#include "personas.h"
#include "carrera.h"
#include <stdlib.h>// para el rands
#include <time.h> // para el time
#include <conio.h>   // For kbhit() //waits for a key to be pressed
#include <windows.h> // For Sleep() //sleep


//#define MAX_DISTANCE 50  // Distancia de la carrera
//#define MAX_CABALLOS 5 //numero de caballos en la carrera, modificar esto para que se pueda elegir la cantidad de caballos
void carrera(Cliente c, ListaCarreras lc) {
    int flag = 0;

    system("cls");

    printf("\n====================================================================================\n");
    printf("                              BIENVENIDO A LA CARRERA DE CABALLOS                              \n");//Por ahora de caballos, sujeto a cambio
    printf("====================================================================================\n");
    int posicion=seleccionarCarrera(lc);

    printf("                     Compitiendo en %c                                          \n",lc.aCarreras[posicion].nombre);
    printf("                         - %d corredores        -Distancia de la carrera %d             \n",lc.aCarreras[posicion].numCaballos,lc.aCarreras[posicion].distancia);//podemos poner distintos tipos de apuestas, solo preguntamelo si lo quieres
    printf("                         -Saldo:%.2f            -Recompensa: %d                         \n", c.dinero,lc.aCarreras[posicion].premio);
    printf("====================================================================================\n\n");

    printf("                                 [1] Apostar 20 euros a un caballo                                           \n");
    printf("                                 [0] Salir                                           \n\n");
    printf("                              Seleccione una opcion: ");
    int opcion;
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
        if (c.dinero < 20) {
            printf("\nSaldo insuficiente para apostar.\n");
            break;
        }
        c.dinero -= 20;
            printf("\n                             EMPEZANDO JUEGO                            \n");
            printf("====================================================================================\n");
            startCarrera(&c, lc.aCarreras[posicion]);
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
void startCarrera(Cliente *cliente, Carrera ca){
    int maxDistance = ca.distancia;
    int maxCaballos = ca.numCaballos;
    printf("\nSeleccione el número del caballo (1-%d): ", maxCaballos);
    int caballoElegido;
    scanf("%d", &caballoElegido);
    if (caballoElegido < 1 || caballoElegido > maxCaballos) {
        printf("Selección inválida.\n");
        return;
    }
    //modificar esto para que se pueda elegir la cantidad de caballos
    //primero lo probare con una apuesta fija
    printf("\n                           CARRERA EN MARCHA...                               \n");
    printf("                      Presiona cualquier tecla para detener                       \n\n");
    Caballo *listaCaballos = (Caballo *)malloc(maxCaballos * sizeof(Caballo));
    if (listaCaballos == NULL) {
        printf("Error al asignar memoria para los caballos.\n");
        return;
    }
    for (int i = 0; i < maxCaballos; i++)//inicializamos los caballos
    {
        listaCaballos[i].numero = i+1;
        listaCaballos[i].posicion = 0;
        listaCaballos[i].seleccionado = (i + 1 == caballoElegido) ? 1 : 0;    
    }//de esta forma es facilmente escalable a mayor cantidad de caballos solo cambiando el numero maximo de caballos

    srand(time(NULL)); // Inicializar la semilla de números aleatorios
    int keyPressed = 0;

//encontrar una forma de poder modificar la cantidad de caballos y que funcione el while a sido sorprendentemente dificil
    while (carreraEnCurso(listaCaballos, ca) && !keyPressed){
        for (int i = 0; i < maxCaballos; i++)
        {
            listaCaballos[i].posicion += rand() % 3 ;
            if (listaCaballos[i].posicion > maxDistance) {
                listaCaballos[i].posicion = maxDistance;
            }
        }

        // Limpiar pantalla (Windows usa system("cls"))
        system("cls");

        // Imprimir la pista de la carrera

        for (int i = 0; i < maxCaballos; i++)
        {
            imprimirPistaCarrera(listaCaballos[i], ca);
        }
        printf("---------------------------------------------------------------------\n---------------------------------------------------------------------\n");
        fflush(stdout);

        // Esperar medio segundo (500 ms) en Windows
        if (kbhit()) {
            keyPressed = 1;
            getch(); // Limpiar el buffer del teclado
        }
        Sleep(500);
    }
    if (keyPressed) {
        printf("\nCarrera detenida por el usuario.\n");
    } else {
        printf("\n¡Carrera terminada!\n");
    }

    // Mostrar el resultado de la carrera
    int ganador = -1;
    int maxPos = -1;
    for (int i = 0; i < maxCaballos; i++) {
        if (listaCaballos[i].posicion >= ca.distancia && listaCaballos[i].posicion > maxPos) {
            maxPos = listaCaballos[i].posicion;
            ganador = listaCaballos[i].numero;
        }
    }

    if (ganador != -1) {
        printf("¡Caballo %d gana!\n", ganador);
        if (listaCaballos[ganador - 1].seleccionado) {
            cliente->dinero += ca.premio;
            printf("¡Ganaste %.2f euros! Saldo actual: %.2f\n", ca.premio, cliente->dinero);
        } else {
            printf("Perdiste la apuesta.\n");
        }
    } else {
        printf("No hubo ganador. Se devuelven 20 euros.\n");
        cliente->dinero += 20;
    }
    free(listaCaballos); // Liberar la memoria asignada
}

void imprimirPistaCarrera(Caballo caballo, Carrera c) {
    printf("Caballo %2d: |", caballo.numero);
    for (int i = 0; i <= c.distancia; i++) {
        if (i == caballo.posicion) {
            printf("🐎");
        } else {
            printf(" ");
        }
    }
    printf("| 🏁\n​"); // Meta al final
}
/*void caballoGanador(Caballo caballo,Carrera c, Cliente cliente){
    if (caballo.posicion >= c.distancia){
        printf("¡Caballo %d gana!\n", caballo.numero);
    	fflush(stdout);
        if (caballo.seleccionado==1)
        {
            printf("¡Ganaste!\n");
            cliente.dinero=cliente.dinero + c.premio;
        }else{
            printf("Perdiste!\n");
            cliente.dinero=cliente.dinero - 20;
        }
        
    }
}*/
int carreraEnCurso(Caballo listaCaballos[], Carrera c) {//esta es la unica solucion que he encontrado al problema del while
    for (int i = 0; i < c.numCaballos; i++) {
        if (listaCaballos[i].posicion >= c.distancia) {
            return 0;
        }
    }
    return 1;
}

void visualizarTitulos() {
	printf("%20s%20s%20s%15s\n", "NUM CABALLOS","DISTANCIA", "NOMBRE", "PREMIO");
}

void visualizarCarrera(Carrera c) {
    printf("%20d%20d%20s%15d\n", c.numCaballos,c.distancia, c.nombre, c.premio);
}

void visualizarCarreras(ListaCarreras lc) {
    int i;
    visualizarTitulos();
    for(i=0;i< lc.numCarreras;i++){
        visualizarCarrera(lc.aCarreras[i]);
    }
}

int seleccionarCarrera(ListaCarreras lc) {
    int seleccion;
    do {
        visualizarCarreras(lc);
        printf("Seleccione la carrera (1-%d): ", lc.numCarreras);
        scanf("%d", &seleccion);
    } while (seleccion < 1 || seleccion > lc.numCarreras);
    return seleccion - 1;
}