#include "logger.h"
#include <string.h>
//A�ade en el fichero log el mensaje recibido por par�metro
void writeLog(char *mensaje){
	FILE *pf;
	time_t fechaActual;
	char *sfecha;

	pf=fopen(FICHERO_LOG,"a"); //Modo a�adir al final
	if(pf!=(FILE*)NULL){
		//Si el fichero se ha abierto bien, vamos a escribir el
		//mensaje recibido por par�metro indica la fecha/hora del sistema
		fechaActual = time(NULL); //Devuelve la fecha/hora del sistema
		sfecha = ctime(&fechaActual); //Convierte la fecha actual a cadena de caracteres, pero no a�ade el car�cter de fin de cadena \0
		//sfecha[strlen(sfecha)] = '\0';
		fprintf(pf, "%s - %s\n",sfecha,mensaje);
		fclose(pf);
	}
}