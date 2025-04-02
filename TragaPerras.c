#include <stdio.h>
#include "menus.h"
#include "music.h"
#include "personas.h"
#include "tragaperras.h"
#include <stdlib.h> // for rand and system
#include <time.h> // for time
#include <conio.h> // for kbhit() and getch()
#include <windows.h> // for Sleep()

void TragaPerras(Cliente *c) {
    int flag = 0;
    system("cls");

    printf("\n====================================================================================\n");
    printf("                              BIENVENIDO AL TRAGAPERRAS                              \n");
    printf("====================================================================================\n");
    printf("                                  REGLAS                 COSTE                         \n");
    printf("                         - Tres numeros son x10        -Cada tirada son 10€             \n");
    printf("                         - Dos numeros son x5          -Saldo:%.2f                           \n", c->dinero);
    printf("====================================================================================\n\n");

    printf("                                 [1] Jugar                                           \n");
    printf("                                 [0] Salir                                           \n\n");
    printf("                              Seleccione una opcion: ");
    int opcion;
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            printf("\n                             EMPEZANDO JUEGO                            \n");
            printf("====================================================================================\n");
            StartTragaPerras(c);
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

void StartTragaPerras(Cliente *c) {
    int flag = 0;
    ListaPosiciones p;
    p.p = NULL; // Initialize p.p to NULL
    int apuesta = 10; // fixed bet for now
    printf("\n                           TRAGAPERRAS EN MARCHA...                               \n");
    printf("                      Presiona cualquier tecla para detener                       \n\n");

    srand(time(NULL));
    const char *fruits[] = {"🍒", "🍋", "🍊", "🍉", "🍇", "🍓"};
    int cantidadDeFrutas = sizeof(fruits) / sizeof(fruits[0]);
    while (flag == 0) {
        Sleep(500);
        InicializarPosiciones(&p, cantidadDeFrutas);
        system("cls");


        ImprimirTragaPerras(p);

        if (_kbhit()) {
            int endTimer = 500;
            while (endTimer < 1400) {
                Sleep(endTimer);
                InicializarPosiciones(&p, cantidadDeFrutas);
                system("cls");
                ImprimirTragaPerras(p);
                endTimer += 200;
            }

            getch(); // wait for key press

            printf("\n\n                          JUEGO DETENIDO!      \n");
            if (p.p[3].random == p.p[4].random && p.p[4].random == p.p[5].random) { // big win
                c->dinero += apuesta * 10;
                printf("\n====================================================================================\n");
                printf("                          GANASTE EL PREMIO GRANDE !!!                          \n");
                printf("                             Apuestax10!                                        \n");
                printf("                                                       Saldo:%.2f              \n", c->dinero);
                printf("====================================================================================\n");
                playSong("canciones/tragaperrasWin.wav",3);
            } else if (p.p[3].random == p.p[4].random || p.p[3].random == p.p[5].random || p.p[4].random == p.p[5].random) { // partial win
                c->dinero += apuesta * 5;
                printf("\n====================================================================================\n");
                printf("                         GANASTE PREMIO MEDIO!                                     \n");
                printf("                                                       Saldo:%.2f              \n", c->dinero);
                printf("====================================================================================\n");
                playSong("canciones/tragaperrasWin.wav",3);
            } else {
                c->dinero -= apuesta;
                printf("\n====================================================================================\n");
                printf("                              PERDISTE!                                            \n");
                printf("                                                       Saldo:%.2f              \n", c->dinero);
                printf("====================================================================================\n");
            }
            printf("\n                         DESEAS SEGUIR JUGANDO?                                 \n");
            printf("                                [1] Si                                             \n");
            printf("                                [0] No                                             \n\n");
            printf("                             Seleccione una opcion: ");

            int opcion;
            scanf("%d", &opcion);

            if (opcion == 0) {
                flag = 1;
                printf("\n                              HASTA PRONTO!                                   \n");
                printf("====================================================================================\n");
            } else {
                printf("\n                           TRAGAPERRAS EN MARCHA...                              \n");
                printf("                      Presiona cualquier tecla para detener                       \n\n");
            }
        }
    }
    free(p.p);
}

void InicializarPosiciones(ListaPosiciones *lp, int cantidadDeFrutas) {
    if (lp->p != NULL) {
        free(lp->p);
    }
    lp->numeroDePosiciones = 9;
    lp->p = (Posicion *)malloc(lp->numeroDePosiciones * sizeof(Posicion));
    if (lp->p == NULL) {
        printf("Memory allocation failed\n"); // Debug print
        return;
    }

    for (int i = 0; i < lp->numeroDePosiciones; i++) {
        lp->p[i].random = rand() % cantidadDeFrutas;
        lp->p[i].posicion = i + 1;
    }
}

void ImprimirTragaPerras(ListaPosiciones lp) {
    const char *fruits[] = {"®", "µ", "¥", "Ω", "§", "¶"};


    int idx = 0;
    printf("                           ..:------:..            \n");
    printf("                      :#################=.      *  \n");
    printf("                    =======================   =##= \n");
    printf("                   =|++++++*++++++++*++++++|= .[]. \n");
    printf("                   =|  %s  |   %s   |  %s  |* .[]. \n", fruits[lp.p[idx+3].random], fruits[lp.p[idx+4].random], fruits[lp.p[idx+5].random]);
    printf("                  -=|------|--------|------|* .[]. \n");
    printf("                  -=|  %s  |   %s   |  %s  |* .[]. \n", fruits[lp.p[idx+3].random], fruits[lp.p[idx+4].random], fruits[lp.p[idx+5].random]);
    printf("                  -=|------|--------|------|*----. \n");
    printf("                   =|  %s  |   %s   |  %s  |*----. \n", fruits[lp.p[idx+6].random], fruits[lp.p[idx+7].random], fruits[lp.p[idx+8].random]);
    printf("                   =#======#========#======#*       \n");
    printf("                    :-===================-:        \n");
    printf("                     :-------------------:         \n");
    printf("                      ===================          \n");
}