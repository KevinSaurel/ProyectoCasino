#include <stdio.h>
#include "menus.h"
#include "music.h"
#include "personas.h"
#include "tragaperras.h"
#include <stdlib.h>// para el rands
#include <time.h> // para el time
#include <conio.h>   // For kbhit() //waits for a key to be pressed
#include <windows.h> // For Sleep() //sleep
// A TRAGGAAAAARRRRRRRRRRRRRR 

void TragaPerras(Cliente *c){//el menu se crea en el main, y las partes de arriba en la clase menu
     int flag = 0;
     


     printf("\n====================================================================================\n");
     printf("                              BIENVENIDO AL TRAGAPERRAS                              \n");
     printf("====================================================================================\n");
     printf("                                  REGLAS                 COSTE                         \n");
     printf("                         - Tres numeros son x10        -Cada tirada son 10€             \n");//podemos poner distintos tipos de apuestas, solo preguntamelo si lo quieres
     printf("                         - Dos numeros son x5          -Saldo:%.2f                           \n",c->dinero);
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
void StartTragaPerras(Cliente *c){
    int  flag=0;
    ListaPosiciones p;
    int apuesta = 10;//habria que escribir un scan para pedir la apuesta, pero habria que poner comprobaciones de que no apueste en negativo
    //primero lo probare con una apuesta fija
    printf("\n                           TRAGAPERRAS EN MARCHA...                               \n");
          printf("                      Presiona cualquier tecla para detener                       \n\n");
          
    srand(time(NULL));
     const char *fruits[] = {"🍒", "🍋", "🍊", "🍉", "🍇", "🍓",/*"💀","❤️","👽","🏆"*/};//le he metido mas emojis, pero son de diferentes tamaños qeuda feo
     int cantidadDeFrutas = sizeof(fruits)/sizeof(fruits[0]);
     while (flag==0){
          Sleep(500);
          //estas tres cosas son las que printean por pantalla de aqui se puede expandir mas
          InicializarPosiciones( &p,cantidadDeFrutas);
          system("cls");
          ImprimirTragaPerras(p);
          




          //he intentado hacerlo creando una structura que guarde la posicion y el random, pero casi me vuelvo loco al ver que tenia que cambiar todo el codigo

          //este codigo es una chapuza, ya mañana me pongo a meterle horas, es mas complicado de lo que pensaba
          //printf("                           || %s || %s || %s ||\n                           || %s || %s || %s ||\n                           || %s || %s || %s ||\n",fruits[num4], fruits[num5], fruits[num6],fruits[num1], fruits[num2], fruits[num3],fruits[num7], fruits[num8], fruits[num9]);
          //scanf("%i", &flag);
          /*Sleep(500);
          system("cls");
          printf("                           || %s || %s || %s ||\n|| %s || %s || %s ||\n|| %s || %s || %s ||\n",fruits[num4], fruits[num5], fruits[num6],fruits[num1], fruits[num2], fruits[num3],fruits[num7], fruits[num8], fruits[num9]);
*/
          if (_kbhit()) {  
               int endTimer =500;
               //printf("\n                           TRAGAPERRAS DETENIDO!                               \n");
               while(endTimer<1400){
                    /*num1 = rand()%6;
                    num2 = rand()%6;
                    num3 = rand()%6;
                    Sleep(endTimer);
                    printf("                           || %s || %s || %s ||\n",fruits[num1], fruits[num2], fruits[num3]);*/
                    Sleep(endTimer);
                    InicializarPosiciones( &p,cantidadDeFrutas);
                    system("cls");
                    ImprimirTragaPerras(p);
                    endTimer = endTimer + 200;
               }
               
               int stp = getch(); 
               /*if(stp == 'e'){//easterEgg
                    num2 = num1;
                    num3 = num1;
                    printf("                           || %s || %s || %s ||\n",fruits[num1], fruits[num2], fruits[num3]);

               }*/

               printf("\n\n                          JUEGO DETENIDO!      \n");
               if(/*num1==num2&& num2==num3*/p.p[3].random==p.p[4].random&& p.p[4].random==p.p[5].random){//win grande 
                    
                    c->dinero = c->dinero + apuesta*10;//hay que modificar esto cuando ponga mas formas de apostar
                    printf("\n====================================================================================\n");
                    printf("                          GANASTE EL PREMIO GRANDE !!!                          \n");
                    printf("                             Apuestax10!                                        \n");
                    printf("                                                       Saldo:%.2f              \n", c->dinero);
                    printf("====================================================================================\n");
                    playSong("canciones/tragaperrasWin.wav");
               } 
               else if (/*num1==num2 || num1==num3 || num2==num3*/p.p[3].random==p.p[4].random || p.p[3].random==p.p[5].random||p.p[4].random==p.p[5].random){//partial win  solo hay dos que coinciden 
                    c->dinero = c->dinero + apuesta*5;
                    printf("\n====================================================================================\n");
                   printf("                         GANASTE PREMIO MEDIO!                                     \n");
                   //printf("                     Números obtenidos:  %s || %s || %s                                 \n", fruits[num1], fruits[num2], fruits[num3]);
                   printf("                                                       Saldo:%.2f              \n", c->dinero);
                   printf("====================================================================================\n");
                   playSong("canciones/tragaperrasWin.wav");
              }else{
               c->dinero = c->dinero - apuesta;
               printf("\n====================================================================================\n");
               printf("                              PERDISTE!                                            \n");
               //printf("                     Numeros obtenidos:  %s || %s || %s                                       \n", fruits[num1], fruits[num2], fruits[num3]);
               printf("                                                       Saldo:%.2f              \n", c->dinero);
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
               printf("\n                           TRAGAPERRAS EN MARCHA...                              \n");
               printf("                      Presiona cualquier tecla para detener                       \n\n");
          }
     }
     free(p.p);
}
}
void InicializarPosiciones(ListaPosiciones *lp, int cantidadDeFrutas){

          if (lp->p != NULL) {
               free(lp->p);
           }
           lp->numeroDePosiciones = 9;
           lp->p = (Posicion *)malloc(lp->numeroDePosiciones * sizeof(Posicion));
           
           for (int i = 0; i < lp->numeroDePosiciones; i++) {
               lp->p[i].random = rand() % cantidadDeFrutas;
               lp->p[i].posicion = i + 1;
               }
     
     //odio los punteros
}
void ImprimirTragaPerras(ListaPosiciones lp){
     const char *fruits[] = {"🍒", "🍋", "🍊", "🍉", "🍇", "🍓",/*"💀","❤️","👽","🏆"*/};
     
          int idx = 0;
          printf("                           ..:------:..            \n");
          printf("                      :#################=.      *  \n");
          printf("                    =======================   =##= \n");
          printf("                   =|++++++*++++++++*++++++|= .[]. \n");
          printf("                   =|  %s  |   %s   |  %s  |* .[]. \n", fruits[lp.p[idx].random], fruits[lp.p[idx+1].random], fruits[lp.p[idx+2].random]);
          printf("                  -=|------|--------|------|* .[]. \n");
          printf("                  -=|  %s  |   %s   |  %s  |* .[]. \n", fruits[lp.p[idx+3].random], fruits[lp.p[idx+4].random], fruits[lp.p[idx+5].random]);
          printf("                  -=|------|--------|------|*----. \n");
          printf("                   =|  %s  |   %s   |  %s  |*----. \n", fruits[lp.p[idx+6].random], fruits[lp.p[idx+7].random], fruits[lp.p[idx+8].random]);
          printf("                   =#======#========#======#*       \n");
          printf("                    :-===================-:        \n");
          printf("                     :-------------------:         \n");
          printf("                      ===================          \n");

     
}
// A TRAGGAAAAARRRRRRRRRRRRRR
     
     