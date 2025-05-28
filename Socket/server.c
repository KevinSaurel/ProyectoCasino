/*#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define MAX_BUFFER 1024
int main() {
    WSADATA wsaData;
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER] = {0};
    const char* response = "Mensaje recibido";

    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        printf("Fallo en WSAStartup\n");
        return -1;
    }

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Fallo en socket: %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR) {
        printf("Fallo en bind: %d\n", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return -1;
    }

    if (listen(server_fd, 3) == SOCKET_ERROR) {
        printf("Fallo en listen: %d\n", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return -1;
    }

    printf("Esperando conexiones en el puerto %d...\n", PORT);

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) == INVALID_SOCKET) {
        printf("Fallo en accept: %d\n", WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return -1;
    }

    // Leemos el mensaje del socket
    int bytesRead = recv(new_socket, buffer, MAX_BUFFER - 1, 0);
    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';
        printf("Mensaje del cliente: %s\n", buffer);

        // Enviamos respuesta al cliente
        send(new_socket, response, strlen(response), 0);
        printf("Mensaje enviado al cliente\n");
    } else {
        printf("No se recibió mensaje del cliente o error en recv.\n");
    }

    // Limpiamos el buffer
    memset(buffer, 0, MAX_BUFFER);

    // Cerramos la conexión
    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();

    return 0;
}*/