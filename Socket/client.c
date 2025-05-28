/*#include <stdio.h>
#include <string.h>
#include <unistd.h>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#endif

#define MAX_BUFFER 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    #ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        printf("WSAStartup failed.\n");
        return -1;
    }
    #endif

    if (argc < 2) {
        printf("Error. El programa no tiene argumentos.\n");
        #ifdef _WIN32
        WSACleanup();
        #endif
        return -1;
    }

    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER] = {0};

    // Crear socket de archivo descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nFallo en la creación del socket\n");
        #ifdef _WIN32
        WSACleanup();
        #endif
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convertir la dirección IPv4 de texto a formato binario
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nDirección inválida/ No soportada\n");
        #ifdef _WIN32
        closesocket(sock);
        WSACleanup();
        #else
        close(sock);
        #endif
        return -1;
    }

    // Nos conectamos al servidor
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nFalló la conexión\n");
        #ifdef _WIN32
        closesocket(sock);
        WSACleanup();
        #else
        close(sock);
        #endif
        return -1;
    }

    // Enviamos un mensaje al servidor
    send(sock, argv[1], strlen(argv[1]), 0);
    printf("Mensaje enviado: %s\n", argv[1]);

    // Leemos la respuesta del servidor
    int valread = recv(sock, buffer, MAX_BUFFER - 1, 0);
    if (valread > 0) {
        buffer[valread] = '\0';
        printf("Respuesta del servidor: %s\n", buffer);
    } else {
        printf("No se recibió respuesta del servidor.\n");
    }

    // Cerramos la conexión
    #ifdef _WIN32
    closesocket(sock);
    WSACleanup();
    #else
    close(sock);
    #endif

    return 0;
}*/