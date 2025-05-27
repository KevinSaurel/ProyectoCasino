#ifdef __cplusplus
#include "Socket.h"
#include <iostream>

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

#endif // __cplusplus