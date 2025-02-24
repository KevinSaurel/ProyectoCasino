#include <stdio.h>
#include "juegos.h"
int main(int argc, char const *argv[]){
    char opcion;

    do {
        opcion = menuPrincipal();
		switch (opcion) {
            case '1':
                do{
                    opcion2 = TragaPerras();
                    switch(opcion2){
                        case '1':
                            printf("Jugando\n");
                            fflush(stdout);
                            StartTragaPerras();
                            break;
                        case '0':
                            printf("Salir del juego\n");
                            fflush(stdout);
                            flag = 1;
                            break;
                        default:
                            printf("Opcion no valida\n");
                            fflush(stdout);
                            break;
                    }
                }while(opcion2!='0');
                break;
                
            case '2':
                do{
                    opcion2 = menu2();
                    switch(opcion2){
                        
                    }
                }while(opcion2!='0');
                break;

            case '3':
                do{
                    opcion2 = menu2();
                    switch(opcion2){
                        
                    }
                }while(opcion2!='0');
                break;
                
            case '4':
                do{
                    opcion2 = menu2();
                    switch(opcion2){
                        
                    }
                }while(opcion2!='0');
                break;

            case '0':
                printf("Gracias por su visita, esperamos que le quede dinero\n");
                fflush(stdout);
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
    } while (opcion != '0');
        printf("Opcion no valida\n");
        fflush(stdout);
        break;
    
    return 0;
}
