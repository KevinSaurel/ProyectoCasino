#include <stdio.h>
#include "tragaperras.h"
#include "personas.h"
#include "menus.h"
#include "music.h"
#include <windows.h>
#include "carrera.h"
#include <stdlib.h> // for rand and system
#include "dado.h"
#include "fichero.h"

int main(int argc, char const *argv[]){
    Cliente c;//inicializamos el cliente
    //cuando tengamos ficheros se cargaran la informacion al selecionar la opcion 2 en el menu sesion
    //lo siguiente son datos de prueba, esta informacion la cargaremos de una base de datos, pero hasta que implementemos eso creare unos datos de prueba
    // Crear una lista de carreras
    ListaCarreras listaCarreras;
    listaCarreras.numCarreras = 0;

    // Crear la primera carrera
    Carrera carrera1;
    carrera1.numCaballos = 8;
    carrera1.distancia = 60;
    strcpy(carrera1.nombre, "Gran Premio Basauri");
    carrera1.premio = 50;

    // Añadir la primera carrera a la lista
    listaCarreras.aCarreras[listaCarreras.numCarreras++] = carrera1;

    // Crear la segunda carrera
    Carrera carrera2;
    carrera2.numCaballos = 10;
    carrera2.distancia = 50;
    strcpy(carrera2.nombre, "Clásico Euskadi");
    carrera2.premio = 70;

    // Añadir la segunda carrera a la lista
    listaCarreras.aCarreras[listaCarreras.numCarreras++] = carrera2;


//estos datos se pueden poner con una funcion que sea añadir carrera, y guardarlo a la base de datos, pero con esto deberia funcionar por ahora






    music();

    int numeroAlt = 0;



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
                guardarNuevaPersona( c, "ficheros/personas.txt" );

                if(comprobarEdad(c)==0){
                    printf("El acceso a menores de edad no esta permitido\n");
                    fflush(stdout);
                    borrarDatosCliente(&c);
                    break;//salimos del switch
                }else{
                    printf("Bienvenido %s\n",c.nombre);
                    Sleep(2);
                    fflush(stdout);
                }
                break;
            case '2':
                cargarDatosCliente(&c);

                break;

            case '0':
                printf("Gracias por su visita, esperamos que le quede dinero\n");
                fflush(stdout);
                break;
            default:
                printf("Opción no válida\n");
                opcion='0';
                fflush(stdout);
                break;
        }
    if(comprobarEdad(c)==1&&opcion!='0'){
    do{
        opcion2 = menuPrincipal();
        switch(opcion2){
            case '1':
                do{
                    int numeroAlt = rand() % 50;
                    if(numeroAlt == 50){
                        playSong("canciones/letsgogambling.wav",2);
                    }
                    opcion3 = menuJuegos();
                    if (bancaRota(&c)==1)
                    {//condicion que comprueba que el jugador tiene dinero
                    switch(opcion3){
                        case '1'://este es el tragaperras
                        //aqui se pone el menu de tragaperras


                            TragaPerras(&c);
                            break;
                        case '2'://este es la carrera de caballos
                            carrera(c, listaCarreras);
                            break;
                        case '3'://este es el blackjack
                            
                            break;
                        case '4'://este es el dado
                            menuDados(&c);//pondre un menu para que escojas los valores que aparecen aqui
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
                    }
                    //printf("No tienes dinero suficiente para jugar\n");
                    fflush(stdout);
                    break;
                }while(opcion3!='0');
                break;
            case '2':
                mostrarBalanceBanco(c);
                break;
            case '3':
                pedirPrestamo(&c);
                mostrarBalanceBanco(c);
                break;
            case '4':
                devolverDeuda(&c);
                break;
            case '0':
                printf("Hasta la proxima\n");
                actualizarPersona(c,"ficheros/personas.txt");

                fflush(stdout);
                //guardar los cambios en el fichero

                borrarDatosCliente(&c);//borramos los datos del cliente que sale
                break;
            default:
                printf("Opcion no valida\n");
                fflush(stdout);
                
        }
        Sleep(3000);
    }while(opcion2!='0'&&bancaRota(&c)==1);
}
    
    
    return 0;
}
