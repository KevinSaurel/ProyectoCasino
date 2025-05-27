#include "server.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>


Server::Server(int port) : Socket(AF_INET, SOCK_STREAM, 0) {
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(getSocket(),reinterpret_cast<sockaddr*>(&address),sizeof(address)) == SOCKET_ERROR) {
        throw std::runtime_error("Error en bind()");
    }

    if (listen(getSocket(), SOMAXCONN) == SOCKET_ERROR) {
        throw std::runtime_error("Error en listen()");
    }

    std::cout << "Servidor escuchando en el puerto " << port << "...\n";
}

// Aceptar conexión
SOCKET Server::acceptConnection() {
    SOCKET clientSocket = accept(getSocket(), nullptr, nullptr);
    if (clientSocket == INVALID_SOCKET) {
        throw std::runtime_error("Error en accept()");
    }
    return clientSocket;
}