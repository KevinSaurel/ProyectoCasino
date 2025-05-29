#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../Persistencia/bd.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#define PORT 5000
#define MAX_BUFFER 1024

int main()
{
    sqlite3 *db;
    inicializarBBDD(&db);
    crearTablaPersonas(db);
    crearTablaCarreras(db);
    WSADATA wsaData;
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER] = {0};
    const char *response = "Mensaje recibido";

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("Fallo en WSAStartup\n");
        return -1;
    }

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        printf("Fallo en socket: %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR)
    {
        printf("Fallo en bind: %d\n", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return -1;
    }

    if (listen(server_fd, 3) == SOCKET_ERROR)
    {
        printf("Fallo en listen: %d\n", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return -1;
    }

    printf("Esperando conexiones en el puerto %d...\n", PORT);

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) == INVALID_SOCKET)
    {
        printf("Fallo en accept: %d\n", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return -1;
    }

    printf("Cliente conectado. Esperando mensajes...\n");

    // Loop to receive multiple messages
    while (1)
    {
        int bytesRead = recv(new_socket, buffer, MAX_BUFFER - 1, 0);
        if (bytesRead > 0)
        {
            buffer[bytesRead] = '\0';
            printf("Mensaje del cliente: %s\n", buffer);

            // Optionally, check for an exit command
            if (strcmp(buffer, "exit") == 0)
            {
                printf("Cliente solicitó terminar la conexión.\n");
                break;
            }
            char *token = strtok(buffer, ";");//aqui separa cada parte
            int cont=0;
            char nom[25];
            char apellido[25];
            int dinero;
            while (token != NULL)//recorre el buffer
            {
                cont= cont+1;
                if (cont==1)strcpy(nom, token);
                if (cont==2)strcpy(apellido, token);
                if (cont==3)dinero = atof(token);
                
                //printf("%s\n", token);
                token = strtok(NULL, ";");
            }
            //int dinero = atof(buffer);
            float dineroBase=conseguirDineroPersona(db, nom,apellido);
            float mensaje=dineroBase-dinero;
            char mensajeStr[32];
            snprintf(mensajeStr, sizeof(mensajeStr), "%.2f", mensaje);
            // Send response
            send(new_socket, mensajeStr, strlen(mensajeStr), 0);
            printf("Mensaje enviado al cliente\n");
        }
        else if (bytesRead == 0)
        {
            printf("El cliente cerró la conexión.\n");
            break;
        }
        else
        {
            printf("Error en recv.\n");
            break;
        }
        memset(buffer, 0, MAX_BUFFER);
    }

    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();

    return 0;
}