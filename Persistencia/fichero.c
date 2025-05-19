#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Model/personas.h"

void guardarNuevaPersona(Cliente cliente, char*fichero ){
    FILE *file;
    file = fopen(fichero , "a");
    
    fprintf(file , "%s,%s,%i,%f,%f\n",cliente.nombre,cliente.apellido,
                                    cliente.edad , cliente.dinero,cliente.deuda);


}

void actualizarPersona(Cliente clienteActualizado, char *fichero) {
    FILE *file = fopen(fichero, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", fichero);
        return;
    }

    // Temporary array to store all clients
    Cliente clientes[100];
    int numClientes = 0;

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Read line: %s", buffer); // Debug: Print the line read
        sscanf(buffer, "%[^,],%[^,],%d,%f,%f",
               clientes[numClientes].nombre,
               clientes[numClientes].apellido,
               &clientes[numClientes].edad,
               &clientes[numClientes].dinero,
               &clientes[numClientes].deuda);
        numClientes++;
    }
    fclose(file);

    // Update the client
    int found = 0;
    for (int i = 0; i < numClientes; i++) {
        printf("Checking client: %s\n", clientes[i].nombre); // Debug: Print the client name
        if (strcmp(clientes[i].nombre, clienteActualizado.nombre) == 0) {
            printf("Updating client: %s\n", clientes[i].nombre); // Debug: Print the name being updated
            clientes[i] = clienteActualizado;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Client with name '%s' not found.\n", clienteActualizado.nombre);
        return;
    }

    // Write all clients back to the file
    file = fopen(fichero, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", fichero);
        return;
    }

    for (int i = 0; i < numClientes; i++) {
        printf("Writing client: %s\n", clientes[i].nombre); // Debug: Print the client name
        fprintf(file, "%s,%s,%d,%f,%f\n",
                clientes[i].nombre,
                clientes[i].apellido,
                clientes[i].edad,
                clientes[i].dinero,
                clientes[i].deuda);
    }
    fclose(file);
}
Cliente getPersona(char *nombreCliente, char *fichero) {
    FILE *file = fopen(fichero, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", fichero);
        Cliente emptyCliente = {"", "", 0, 0.0, 0.0};
        return emptyCliente; // Return an empty client if the file cannot be opened
    }else {
        printf("File %s opened successfully.\n", fichero);
    }

    Cliente cliente;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%[^,],%[^,],%d,%f,%f",
               cliente.nombre,
               cliente.apellido,
               &cliente.edad,
               &cliente.dinero,
               &cliente.deuda);
            printf(cliente.nombre);
            printf("Parsed name: %s\n", cliente.nombre); // Debug: Print the parsed name

        if (strcmp(cliente.nombre, nombreCliente) == 0) {
            fclose(file);
            return cliente; // Return the client if the name matches
        }
    }

    fclose(file);
    printf("Error: Client with name '%s' not found.\n", nombreCliente);
    Cliente emptyCliente = {"", "", 0, 0.0, 0.0};
    return emptyCliente; // Return an empty client if not found
}