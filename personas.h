#ifndef PERSONAS_H_
#define PERSONAS_H_


typedef struct 
{   
    char nombre[50];
    char apellido[50];
    int edad;//no permitir jugar si es menor a 18
    int dinero;//se inicializa a 500, no permitir jugar si es menor que zero
    int deuda;//se inicializa a 0
    //int estadisticas; //contador de partidas jugadas, se pueden crear mas de este tipo
    //por ejemplo dinero ganado apostando, y con los ficheros se podemos crear hasta una leaderBoard

}Cliente;
int comprobarEdad(Cliente c);//devuelve 1 si es mayor a 18, 0 si es menor
void pedirDatosCliente(Cliente *c);
void cargarDatosCliente(Cliente *c);
void mostrarBalanceBanco(Cliente c);//simplemente mostrar los valores de dinero y deuda
//tambien podemos poner que aparezca el dinero siempre mientras se juega
void pedirPrestamo(Cliente *c);
void devolverPrestamo(Cliente *c);
void borrarDatosCliente(Cliente *c);



#endif // PERSONAS_H_ //