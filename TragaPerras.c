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
          int num1 = rand()%10;
          int num2 = rand()%10;
          int num3 = rand()%10;
          printf("|| %i || %i || %i ||\n",num1,num2,num3);
          //scanf("%i", &flag);
          if (_kbhit()) {  
               printf("Presiona una tecla para detener\n");
               scanf("%i", &flag);
               if(num1==num2==num3){//win grande 
                    printf("Ganaste\n");
               }else if (num1==num2 || num1==num3 || num2==num3){//partial win  solo hay dos que coinciden 
                    printf("Ganaste premio medio el numero era %i , %i , %i \n", num1 , num2 , num3);
                    printf("Deseas seguir jugando\n");
                    printf("1. Si\n");
                    printf("0. No\n");
                    int opcion;
                    scanf("%d", &opcion);
                    if(opcion==0){
                         flag=1;
                    }else{
                         flag=0;
                    }

               
               }else{
                    printf("Perdiste tienes  %i , %i , %i \n", num1 , num2 , num3);
               }
              
           }

          
     }
}
     
     