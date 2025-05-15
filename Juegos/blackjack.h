#define MAX_CARTAS 52
#define APUESTA_INICIAL 100
#include "Model/personas.h"

// Estructura para representar una carta
typedef struct {
    char *nombre;
    int valor;
} Carta;

// Función para obtener una carta aleatoria
Carta obtener_carta();

// Función para jugar una ronda de Blackjack
void jugar_blackjack(Cliente *c); 