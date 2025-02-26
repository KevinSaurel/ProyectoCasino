#include <stdio.h>
#include "tragaperras.h"
#include "personas.h"
#include "menus.h"
int main(int argc, char const *argv[]){
    Cliente c;//inicializamos el cliente
    //cuando tengamos ficheros se cargaran la informacion al selecionar la opcion 2 en el menu sesion
    



    char opcion,opcion2,opcion3;

    //este NO es un do while, solo queremos que se runee una vez.
        printf("Bienvenido al Casino\n");
        fflush(stdout);
        //despues de cargar los datos del cliente se mostrara el menu principal

        //opcion = menuPrincipal();//este menu seleciona el juego que se quiere jugar
        //primero se seleciona el jugador
        opcion=menuSesion();

		switch (opcion) {
            case '1':
                pedirDatosCliente(&c);
                if(comprobarEdad(c)==0){
                    printf("El acceso a menores de edad no esta permitido\n");
                    fflush(stdout);
                    borrarDatosCliente(&c);
                    break;
                }else{
                    printf("Bienvenido %s\n",c.nombre);
                    fflush(stdout);
                }
                
                break;
                /*do{


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
                break;*/
            case '2':
                cargarDatosCliente(&c);

                break;

            case '0':
                printf("Gracias por su visita, esperamos que le quede dinero\n");
                fflush(stdout);
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
    
    do{
        opcion2 = menuPrincipal();
        switch(opcion2){
            case '1':
                do{
                    opcion3 = menuJuegos();
                    switch(opcion3){
                        case '1'://este es el tragaperras
                        //aqui se pone el menu de tragaperras


                            TragaPerras();
                            break;
                        case '2'://este es la carrera de caballos
                            
                            break;
                        case '3'://este es el blackjack
                            
                            break;
                        case '0':
                            printf("Volver al menu principal\n");
                            fflush(stdout);
                            break;
                        default:
                            printf("Opcion no valida\n");
                            fflush(stdout);
                            break;
                    }
                }while(opcion3!='0');
                break;
            case '2':
                mostrarBalanceBanco(c);
                break;
            case '3':
                pedirPrestamo(&c);
                break;
            case '4':
                devolverDeuda(&c);
                break;
            case '0':
                printf("Hasta la proxima\n");
                fflush(stdout);
                //guardar los cambios en el fichero

                borrarDatosCliente(&c);//borramos los datos del cliente que sale
                break;
            default:
                printf("Opcion no valida\n");
                fflush(stdout);
                
        }
    }while(opcion2!='0');
    
    
    return 0;
}
