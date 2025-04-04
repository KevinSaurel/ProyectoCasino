#include "blackjack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARTAS 52
#define APUESTA_INICIAL 100

// Estructura para representar una carta
typedef struct {
    char *nombre;
    int valor;
} Carta;

// Baraja de cartas estándar
Carta baraja[MAX_CARTAS] = {
    {"As", 11}, {"Dos", 2}, {"Tres", 3}, {"Cuatro", 4}, {"Cinco", 5},
    {"Seis", 6}, {"Siete", 7}, {"Ocho", 8}, {"Nueve", 9}, {"Diez", 10},
    {"Jota", 10}, {"Reina", 10}, {"Rey", 10}
};

// Función para obtener una carta aleatoria
Carta obtener_carta() {
    int indice = rand() % 13;  // 13 tipos de cartas
    return baraja[indice];
}

// Función para jugar una ronda de Blackjack
void jugar_blackjack() {
    srand(time(NULL)); // Inicializar semilla aleatoria
    int total_jugador = 0, total_banca = 0;
    char opcion;
    int saldo = APUESTA_INICIAL, apuesta;

    printf("Bienvenido al Blackjack!\n");
    printf("Saldo inicial: %d\n", saldo);

    printf("Ingresa tu apuesta: ");
    scanf("%d", &apuesta);
    if (apuesta > saldo || apuesta <= 0) {
        printf("Apuesta inválida.\n");
        return;
    }

    // Jugador recibe dos cartas
    Carta carta1 = obtener_carta();
    Carta carta2 = obtener_carta();
    total_jugador = carta1.valor + carta2.valor;
    printf("Tus cartas: %s y %s (Total: %d)\n", carta1.nombre, carta2.nombre, total_jugador);
    
    // Banca recibe una carta visible
    Carta banca_carta1 = obtener_carta();
    total_banca = banca_carta1.valor;
    printf("Carta visible de la banca: %s\n", banca_carta1.nombre);

    // Turno del jugador
    while (total_jugador < 21) {
        printf("\n¿Deseas Pedir (p) o Quedarte (q)? ");
        scanf(" %c", &opcion);
        
        if (opcion == 'p') {
            Carta nueva_carta = obtener_carta();
            total_jugador += nueva_carta.valor;
            printf("Has recibido: %s (Total: %d)\n", nueva_carta.nombre, total_jugador);
        } else {
            break;
        }
    }
    
    // Verificar si el jugador perdió
    if (total_jugador > 21) {
        printf("Te has pasado de 21. ¡Pierdes!\n");
        saldo -= apuesta;
        printf("Saldo actual: %d\n", saldo);
        return;
    }
    
    // Turno de la banca
    while (total_banca < 17) {
        Carta nueva_carta = obtener_carta();
        total_banca += nueva_carta.valor;
    }
    
    printf("Total de la banca: %d\n", total_banca);
    
    // Determinar ganador
    if (total_banca > 21 || total_jugador > total_banca) {
        printf("¡Ganaste!\n");
        saldo += apuesta;
    } else if (total_jugador == total_banca) {
        printf("Empate.\n");
    } else {
        printf("La banca gana.\n");
        saldo -= apuesta;
    }
    printf("Saldo actual: %d\n", saldo);
}

int main() {
    jugar_blackjack();
    return 0;
}
