#ifdef __cplusplus
#include "Socket.h"
#include <iostream>
#include <cstring>

// Inicialización única de Winsock (evita múltiples llamadas a WSAStartup)
namespace {
    struct WinsockInitializer {
        WinsockInitializer() {
            WSADATA wsaData;
            if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
                throw std::runtime_error("Error al iniciar Winsock");
            }
        }

        ~WinsockInitializer() {
            WSACleanup();
        }
    };

    static WinsockInitializer winsock; // Se inicializa una sola vez
}

// Constructor
Socket::Socket(int domain, int type, int protocol) {
    sockfd = socket(domain, type, protocol);
    if (sockfd == INVALID_SOCKET) {
        throw std::runtime_error("Error al crear el socket");
    }
}

Socket::~Socket() {
    //no es necesario el winsock aqui, se destruye automaticamente
    closesocket(sockfd);
}

SOCKET Socket::getSocket() const {
    return sockfd;
}
// Implementación de funciones C
extern "C" {
    int enviarDatos(SocketHandle socket, const char* mensaje) {
        SOCKET s = static_cast<SOCKET>(socket);
        int len = static_cast<int>(strlen(mensaje));
        int bytes_enviados = send(s, mensaje, len, 0);
        if (bytes_enviados == SOCKET_ERROR) {
            return -1;
        }
        return bytes_enviados;
    }

    int recibirDatos(SocketHandle socket, char* buffer, int buffer_length) {
        SOCKET s = static_cast<SOCKET>(socket);
        int bytes_recibidos = recv(s, buffer, buffer_length - 1, 0);
        if (bytes_recibidos == SOCKET_ERROR) {
            return -1;
        }
        if (bytes_recibidos >= 0 && bytes_recibidos < buffer_length) {
            buffer[bytes_recibidos] = '\0';
        }
        return bytes_recibidos;
    }

    void cerrarSocket(SocketHandle socket) {
        SOCKET s = static_cast<SOCKET>(socket);
        closesocket(s);
    }
}
#endif // __cplusplus