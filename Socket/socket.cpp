#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <stdexcept>

#pragma comment(lib, "Ws2_32.lib")
//se inicializa todo en este, no es necesario un hpp
//este codigo esta escrito con Windows en mente, es posible que de errores en otros sistemas operativos
class Socket {
protected:
    SOCKET sockfd;
    sockaddr_in address;
    //este es el padre donde se gestiona todo lo general de los soskets

public:
    Socket(int domain, int type, int protocol) {
        WSAData wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            throw std::runtime_error("Error al iniciar Winsock");
        }

        sockfd = socket(domain, type, protocol);
        if (sockfd == INVALID_SOCKET) {
            throw std::runtime_error("Error al crear el socket");
        }
    }

    SOCKET getSocket() const { return sockfd; }

    virtual ~Socket() {
        closesocket(sockfd);
        WSACleanup();
    }
};
