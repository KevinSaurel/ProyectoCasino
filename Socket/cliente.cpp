#define _WIN32_WINNT 0x0600  // Habilita funciones de Windows Vista y superiores
#include "cliente.h"
#include <winsock2.h>      // Funciones de sockets en Windows
#include <ws2tcpip.h>      // inet_pton

// Constructor
Cliente::Cliente(std::string serverIp, int port) 
    : Socket(AF_INET, SOCK_STREAM, 0) {  // Llama al constructor de Socket

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    
    // Convierte la dirección IP a formato binario pero nose por que da error
    if (inet_pton(AF_INET, serverIp.c_str(), &address.sin_addr) <= 0) {//inet_pton daba errores al compilar
        throw std::runtime_error("Dirección IP inválida");
    }

    // Intenta conectar al servidor
    if (connect(getSocket(),(sockaddr*)&address,sizeof(address)) == SOCKET_ERROR) {
        throw std::runtime_error("Error en connect");
    }
}

// Envía un mensaje al servidor
void Cliente::sendMessage(const std::string& message) {
    send(
        getSocket(), 
        message.c_str(), 
        message.size(), 
        0
    );
}