#include <stdio.h>
#include "menus.h"
#include "personas.h"
#include "juegos.h"
#include <stdlib.h>// para el rands
#include <time.h> // para el time
#include <conio.h>   // For kbhit() //waits for a key to be pressed
// A TRAGGAAAAARRRRRRRRRRRRRR 
void TragaPerras(){
     int flag = 0;
     
           printf("Tragaperras\n");
               printf("1. Jugar\n");
               printf("0. Salir\n");
               int opcion;
               scanf("%d", &opcion);
               switch(opcion){
                    case '1':
                         printf("Jugando\n");
                         StartTragaPerras();
                         break;
                    case '0':
                         flag = 1;
                         break;
                    default:
                         printf("Opcion no valida\n");
                         break;
                         
               }
           

     

}
void StartTragaPerras(){
    int  flag=0;
    srand(time(NULL));
     while (flag==0)
     {
          Sleep(1000);
          printf("|| %i || %i || %i ||\n",rand()%10,rand()%10,rand()%10);
          //scanf("%i", &flag);
          if (_kbhit()) {  
               printf("Press 1 to stop: ");
               scanf("%i", &flag);
           }

          
     }
}
     