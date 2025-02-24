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
                    swtich(opcion2){
                        case 1:
                        printf("Jugando\n");
                        StartTragaPerras();
                        break;
                        case 2:
                            flag = 1;
                            break;
                        default:
                            printf("Opcion no valida\n");
                            break;
                    }
                }while(opcion2!='0');
                break;
                
            case '2':
                do{
                    opcion2 = menu2();
                    swtich(opcion2){
                        
                    }
                }while(opcion2!='0');
                break;

            case '3':
                do{
                    opcion2 = menu2();
                    swtich(opcion2){
                        
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
    //Yahoooooooo viva el casino (Prueba 1 Commit con VSCODE)
    TragaPerras();
    return 0;
}
