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
    } else {
        std::cout << "Cliente conectado con éxito!" << std::endl;
    }
    return clientSocket;
}
// Implementación de la interfaz C
ServerHandle crearServidor(int port) {
    try {
        return new Server(port);
    } catch (const std::exception& e) {
        std::cerr << "Error creando servidor: " << e.what() << std::endl;
        return nullptr;
    }
}

void destruirServidor(ServerHandle handle) {
    delete static_cast<Server*>(handle);
}

SocketHandle aceptarConexion(ServerHandle handle) {
    try {
        Server* servidor = static_cast<Server*>(handle);
        return static_cast<SocketHandle>(servidor->acceptConnection());
    } catch (const std::exception& e) {
        std::cerr << "Error aceptando conexión: " << e.what() << std::endl;
        return static_cast<SocketHandle>(INVALID_SOCKET);
    }
}