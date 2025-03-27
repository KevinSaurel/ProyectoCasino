#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>
#include <time.h> //Obtener la fecha/hora del sistema
#define FICHERO_LOG "log.txt"

//A�ade en el fichero log el mensaje recibido por par�metro
void writeLog(char *mensaje);

#endif /* LOGGER_H_ */