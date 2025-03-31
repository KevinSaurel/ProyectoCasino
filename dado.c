#include "dado.h"
#include "personas.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // Para sleep
void menuDados(Cliente *c) {
    int flag = 0;
    system("cls");

    printf("\n====================================================================================\n");
    printf("                              BIENVENIDO A LOS DADOS                              \n");
    printf("====================================================================================\n");
    printf("                                  REGLAS(TODAVIA FALTA POR CAMBIAR)                 COSTE                         \n");
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
        system("cls");
            printf("====================================================================================\n");
            printf("\n                             EMPEZANDO JUEGO                            \n");
            printf("====================================================================================\n");
            //otro menu donde te pide la cantidad de vasos con los que jugar y cual elijes
            seleccion();
            //incializar
            break;
        case 0:
            flag = 1;
            system("cls");
            printf("====================================================================================\n");
            printf("\n                              HASTA LUEGO                                  \n");
            printf("====================================================================================\n");
            break;
        default:
        system("cls");
            printf("====================================================================================\n");
            printf("\n                            OPCION NO VALIDA                                 \n");
            printf("====================================================================================\n");
            break;
    }
}

void lanzar_dado(int recipientesCantidad,int ganador){//tambien necesito el numero de recipiente ganador
    int numRecipientes = recipientesCantidad;//cuanto mayor recipiente mayor apuesta
    int offset = 0;//es el que controla donde empieza, se puede centrar para que este en medio de la pantalla
    int direccion = 1; // 1 derecha, -1 izquierda
    const int max_offset = 10;//limite de movimiento
    // Obtener el tiempo de inicio
    // Control de movimiento vertical para cada recipiente
    int *vertical_offsets = malloc(numRecipientes * sizeof(int));
    int *vertical_direcciones = malloc(numRecipientes * sizeof(int));

    // Inicializar: primer recipiente se mueve, otros estáticos
    for (int i = 0; i < numRecipientes; i++) {
        vertical_offsets[i] = 0;
        vertical_direcciones[i] = 0;
    }
    // Configurar movimiento para recipientes 0 y 1 (ejemplo)
    //vertical_direcciones[0] = 1; //esto es para mover hacia abajo el recipiente 1
    //vertical_direcciones[1] = -1; //esto es para mover hacia arriba el recipiente 2

    long frame = 0;
    const int max_vertical_offset = 5;

    while (frame<70) { // Bucle infinito para la animación
        // Limpiar la pantalla usando códigos ANSI
        system("cls");

        // Imprimir cada línea con espacios de desplazamiento
        // Actualizar desplazamientos verticales
        for (int i = 0; i < numRecipientes; i++) {
            if (vertical_direcciones[i] != 0) {
                vertical_offsets[i] += vertical_direcciones[i];
                if (abs(vertical_offsets[i]) >= max_vertical_offset) {
                    vertical_direcciones[i] *= -1;  // Invertir dirección
                }
            }
        }

        // Dibujar cada línea de los recipientes
        for (int line = 0; line < 6; line++) {
            for (int i = 0; i < numRecipientes; i++) {
                // Calcular posición vertical ajustada
                int vp = 1 + line + vertical_offsets[i];
                
                // Calcular posición horizontal según línea
                int hp;
                if (line == 0) {
                    hp = offset + 1 + i * 9;  // Línea superior con espacio extra
                } else {
                    hp = offset + i * 9;
                }

                // Determinar el símbolo a dibujar
                const char *simbolo;
                switch(line) {
                    case 0:  // Parte superior
                        simbolo = (i < numRecipientes - 1) ? ".---.    " : ".---.";
                        break;
                    case 1:  // Línea decorada
                        simbolo = (i < numRecipientes - 1) ? "|'-=-'|  " : "|'-=-'|";
                        break;
                    case 5:  // Parte inferior
                        simbolo = (i < numRecipientes - 1) ? "'.___.'  " : "'.___.'";
                        break;
                    default:  // Cuerpo del recipiente
                        simbolo = (i < numRecipientes - 1) ? "|     |  " : "|     |";
                }

                // Posicionar y dibujar usando códigos ANSI
                printf("\033[%d;%dH%s", vp, hp + 1, simbolo);
            }
        }

        // Control horizontal
        offset += direccion;
        if (offset >= max_offset || offset <= 0) {
            direccion *= -1;
        }
        if (frame>65)//para cuando queden solo 20 frames mas
        //iniciamos la animacion hacia arriba del recipiente ganador
        //y detenemos el movimiento horizontal
        {
            direccion = 0;
            vertical_direcciones[ganador] = -1;

        }
        

        Sleep(150);  // Ajustar velocidad 0.15 segundos
        frame++;
    }
}
void inicializar_dado(int recipientesCantidad, int selecionado){//devuelve 1 si gana y 0 si pierde
    int ganador = rand() % recipientesCantidad;
    int victoria=0;

    
    lanzar_dado(recipientesCantidad,ganador);
    if (ganador == selecionado)
    {
        victoria=1;
    }else{
        victoria=0;
    }
    ganar(victoria,recipientesCantidad);
}


void ganar(int victoria,int cantidadRecipiente){
    if (victoria==1)
    {
        Sleep(2);
        system("cls");
        printf("====================================================================================\n");
        printf("                              HAS GANADO                                     \n");
        printf("====================================================================================\n");
        //aumentar el dinero en funcion a la cantidad de recipientes
        //apuesta*cantidadRecipiente
    }else{
        Sleep(2);
        system("cls");
        printf("====================================================================================\n");
        printf("                              HAS PERDIDO                                     \n");
        printf("====================================================================================\n");

    }
}
void seleccion(){
    int recipientesCantidad;
     int selecionado;
 printf("\n====================================================================================\n");
    printf("                              BIENVENIDO A LA MESA                                 \n");
    printf("====================================================================================\n");
    printf("\n");
    system("cls");
    printf("====================================================================================\n");
    printf("                              CON CUANTOS DADOS DESEAS JUGAR                        \n");
    printf("====================================================================================\n");
    printf("                              Seleccione cantidad de dados: ");
    scanf("%d", &recipientesCantidad);
    system("cls");
    printf("====================================================================================\n");
    printf("                              POR QUE DADO APUESTAS                                 \n");
    printf("====================================================================================\n");
    printf("                              Seleccione el dado: ");
    scanf("%d", &selecionado);
    if(recipientesCantidad>9){
        system("cls");
        printf("====================================================================================\n");
        printf("                NUMERO MAXIMO DE DADOS ALCANZADO(9)                \n");
        printf("                                  INTENTELO DE NUEVO                \n");
        printf("====================================================================================\n");
        seleccion();
    }else if (selecionado>recipientesCantidad||selecionado<0)
    {
        system("cls");
        printf("====================================================================================\n");
        printf("                EL DADO SELECCIONADO NO EXISTE                    \n");
        printf("                                  INTENTELO DE NUEVO                \n");
        printf("====================================================================================\n");
        seleccion();
    }
     inicializar_dado(recipientesCantidad,selecionado);
}

