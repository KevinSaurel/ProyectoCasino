#include <stdio.h>
#include "menus.h"
#include "personas.h"
#include "tragaperras.h"
#include <stdlib.h>// para el rands
#include <time.h> // para el time
#include <conio.h>   // For kbhit() //waits for a key to be pressed
#include <windows.h> // For Sleep() //sleep
// A TRAGGAAAAARRRRRRRRRRRRRR 
void TragaPerras(){//el menu se crea en el main, y las partes de arriba en la clase menu
     int flag = 0;



     printf("\n====================================================================================\n");
     printf("                              BIENVENIDO AL TRAGAPERRAS                              \n");
     printf("====================================================================================\n");
     printf("                                       REGLAS                                        \n");
     printf("                              - Tres numeros son x10                                 \n");
     printf("                              - Dos numeros son x5                                   \n");
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
                    StartTragaPerras();
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
void StartTragaPerras(){
    int  flag=0;
    printf("\n                           TRAGAPERRAS EN MARCHA...                               \n");
          printf("                      Presiona cualquier tecla para detener                       \n\n");
          
    srand(time(NULL));
     while (flag==0){
          
          Sleep(500);
          int num1 = rand()%10;
          int num2 = rand()%10;
          int num3 = rand()%10;
          printf("                           || %i || %i || %i ||\n",num1,num2,num3);
          //scanf("%i", &flag);
          if (_kbhit()) {  
               printf("\n\n                          JUEGO DETENIDO!      ");
               int stp = getch(); 
               if(num1==num2==num3){//win grande 
                    printf("\n====================================================================================\n");
                    printf("                          GANASTE EL PREMIO GRANDE !!!                          \n");
                    printf("                            TU APUESTA x10!                                        \n");
                    printf("====================================================================================\n");
               } 
               else if (num1==num2 || num1==num3 || num2==num3){//partial win  solo hay dos que coinciden 
                    printf("\n====================================================================================\n");
                   printf("                         GANASTE PREMIO MEDIO!                                     \n");
                   printf("                     Números obtenidos: %i, %i, %i                                  \n", num1, num2, num3);
                   printf("====================================================================================\n");
              }else{
               printf("\n====================================================================================\n");
               printf("                              PERDISTE!                                            \n");
               printf("                     Numeros obtenidos: %i, %i, %i                                  \n", num1, num2, num3);
               printf("====================================================================================\n");
          }
          printf("\n                         DESEAS SEGUIR JUGANDO?                                 \n");
          printf("                                [1] Si                                             \n");
          printf("                                [0] No                                             \n\n");
          printf("                             Seleccione una opcion: ");
          
          int opcion;
          scanf("%d", &opcion);
          if(opcion == 0) {
               flag = 1;
               printf("\n                              HASTA PRONTO!                                   \n");
               printf("====================================================================================\n");
          } else {
               flag = 0;
               printf("\n                           TRAGAPERRAS EN MARCHA...                              \n");
               printf("                      Presiona cualquier tecla para detener                       \n\n");
          }
     }
}
}
// A TRAGGAAAAARRRRRRRRRRRRRR
     
     