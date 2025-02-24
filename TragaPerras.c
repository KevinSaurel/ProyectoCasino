#include <stdio.h>
#include "juegos.h"
#include <windows.h> // para el sleep
#include <stdlib.h>// para el rands
// A TRAGGAAAAARRRRRRRRRRRRRR 
void TragaPerras(){
     int flag = 0;
     
           printf("Tragaperras\n");
               printf("1. Jugar\n");
               printf("2. Salir\n");
               int opcion;
               scanf("%d", &opcion);
               switch(opcion){
                    case 1:
                         printf("Jugando\n");
                         StartTragaPerras();
                    case 2:
                         flag = 1;
                         
                    default:
                         printf("Opcion no valida\n");
                         
               }
           

     

}
void StartTragaPerras(){
    int  flag=0;
     while (flag==0)
     {
          Sleep(1000);
          printf("|| %i || %i || %i ||\n",rand()%10,rand()%10,rand()%10);
          scanf("%d", &flag);
          if(flag==1){
               "acabo";
          }
     }
}
     