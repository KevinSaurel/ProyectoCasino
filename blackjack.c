#include "blackjack.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "personas.h"  

#define MAX_CARTAS 52 
#define APUESTA_INICIAL 500

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
void jugar_blackjack(Cliente *c) {     
    srand(time(NULL)); // Inicializar semilla aleatoria     
    int total_jugador = 0, total_banca = 0;     
    char opcion;     
    int saldo = APUESTA_INICIAL, apuesta;      
    
    printf("\n\033[1;33m╔════════════════════════════════════╗\033[0m\n");
    printf("\033[1;33m║      BIENVENIDO AL BLACKJACK        ║\033[0m\n");
    printf("\033[1;33m╚════════════════════════════════════╝\033[0m\n\n");
    
    printf("\033[1;36m► ApuestaMaxima: $%d\033[0m\n\n", saldo);      
    
    printf("\033[1;37m► Ingresa tu apuesta: \033[0m");     
    scanf("%d", &apuesta);     
    c->dinero=c->dinero-apuesta;     
    
    if (apuesta > saldo || apuesta <= 0) {         
        printf("\033[1;31m✖ Apuesta inválida.\033[0m\n");                 
        return;     
    }      
    
    // Jugador recibe dos cartas     
    Carta carta1 = obtener_carta();     
    Carta carta2 = obtener_carta();     
    total_jugador = carta1.valor + carta2.valor;     
    printf("\n\033[1;32m♠ Tus cartas: \033[1;37m%s\033[0m y \033[1;37m%s\033[0m (Total: \033[1;37m%d\033[0m)\033[0m\n", 
           carta1.nombre, carta2.nombre, total_jugador);          
    
    // Banca recibe una carta visible     
    Carta banca_carta1 = obtener_carta();     
    total_banca = banca_carta1.valor;     
    printf("\033[1;31m♣ Carta visible de la banca: \033[1;37m%s\033[0m\n", banca_carta1.nombre);      
    
    // Turno del jugador     
    while (total_jugador < 21) {         
        printf("\n\033[1;35m► ¿Deseas Pedir \033[1;37m(p)\033[1;35m o Quedarte \033[1;37m(q)\033[1;35m? \033[0m");         
        scanf(" %c", &opcion);                  
        
        if (opcion == 'p') {             
            Carta nueva_carta = obtener_carta();             
            total_jugador += nueva_carta.valor;             
            printf("\033[1;32m♦ Has recibido: \033[1;37m%s\033[0m (Total: \033[1;37m%d\033[0m)\033[0m\n", 
                   nueva_carta.nombre, total_jugador);         
        } else {             
            break;         
        }     
    }          
    
    // Verificar si el jugador perdió     
    if (total_jugador > 21) {         
        printf("\n\033[1;31m✖ Te has pasado de 21. ¡Pierdes!\033[0m\n");         
        saldo -= apuesta;         
        printf("\033[1;36m► Saldo actual: $%d\033[0m\n", saldo);                  
        return;     
    }          
    
    // Turno de la banca     
    while (total_banca < 17) {         
        Carta nueva_carta = obtener_carta();         
        total_banca += nueva_carta.valor;     
    }          
    
    printf("\n\033[1;31m♣ Total de la banca: \033[1;37m%d\033[0m\n", total_banca);          
    
    // Determinar ganador     
    if (total_banca > 21 || total_jugador > total_banca) {                  
        saldo += apuesta;         
        float wn=(apuesta*2);         
        c->dinero = c->dinero+wn;         
        printf("\n\033[1;32m✓ ¡Ganaste $%.2f!\033[0m\n", wn);      
    } else if (total_jugador == total_banca) {         
        printf("\n\033[1;33m♦ Empate.\033[0m\n");         
        c->dinero=c->dinero+apuesta;//recuperas apuesta empate      
    } else {         
        printf("\n\033[1;31m✖ La banca gana.\033[0m\n");         
        saldo -= apuesta;     
    }     
    printf("\033[1;36m► Saldo actual: $%d\033[0m\n", saldo); 
}