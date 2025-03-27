#ifndef PERSONAS_H_
#define PERSONAS_H_


typedef struct 
{   
    char nombre[50];
    char apellido[50];
    int edad;//no permitir jugar si es menor a 18
    float dinero;//se inicializa a 500, no permitir jugar si es menor que zero
    float deuda;//se inicializa a 0
    //int estadisticas; //contador de partidas jugadas, se pueden crear mas de este tipo
    //por ejemplo dinero ganado apostando, y con los ficheros se podemos crear hasta una leaderBoard
    /*podemos usar un Array de ints, que almacene las veces que ha ganado una partida el jugador
    ejemplo:int[3]= en la posicion [0] guardamos la cantidad de veces que ha ganado en la tragaperras y asi*/
}Cliente;

typedef struct //para la hora de querer mostrar los datos de mas de un cliente necesitaremos guardarlos en una lista dinamica
{//con esto ya tendriamos el minimo de listas dinamicas en el proyecto
    Cliente *clientes;
    int numClientes;
}ListaClientes;//por ahora no haremos uso de esta estructura, sera util cuando toque la segunda parte de servers

int comprobarEdad(Cliente c);//devuelve 1 si es mayor a 18, 0 si es menor
void pedirDatosCliente(Cliente *c);
void cargarDatosCliente(Cliente *c);
void mostrarBalanceBanco(Cliente c);//simplemente mostrar los valores de dinero y deuda
//tambien podemos poner que aparezca el dinero siempre mientras se juega
void pedirPrestamo(Cliente *c);
void devolverDeuda(Cliente *c);
void borrarDatosCliente(Cliente *c);
int bancaRota(Cliente *c);//impide que el jugador juegue teniendo dinero negativo(0 no tiene dinero suficiente, 1 tiene dinero), y transforma el dinero negativo en deuda

void compararDatosConfig(Cliente *c);//compara los datos de la configuracion con los datos de los clientes, si no coinciden, se cambian los datos de los clientes

#endif // PERSONAS_H_ //