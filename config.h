#ifndef CONFIG_H_
#define CONFIG_H_

#define TAM 20
typedef struct{
	char nombreBD[TAM];
	char nombreAdmin[TAM];
	char apellidoAdmin[TAM];
}Config;

Config leerConfiguracion(char *nomfich);

#endif /* CONFIG_H_ */