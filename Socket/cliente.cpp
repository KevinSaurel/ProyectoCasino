#ifdef __cplusplus
#define _WIN32_WINNT 0x0600  // Habilita funciones de Windows Vista y superiores
#include "cliente.h"
#include <winsock2.h>      // Funciones de sockets en Windows
#include <ws2tcpip.h>      // inet_pton
#include <iostream>

//#include <arpa/inet.h>



Cliente::Cliente(std::string serverIp, int port) 
    : Socket(AF_INET, SOCK_STREAM, 0) {  // Llama al constructor de Socket

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(serverIp.c_str());

    
    // Convierte la dirección IP a formato binario pero nose por que da error
    if (address.sin_addr.s_addr == INADDR_NONE) {
        throw std::runtime_error("Dirección IP inválida");
    }

    // Intenta conectar al servidor
    if (connect(getSocket(),(sockaddr*)&address,sizeof(address)) == SOCKET_ERROR) {
        throw std::runtime_error("Error en connect");
    }
}

// Envía un mensaje al servidor
void Cliente::sendMessage(const std::string& message) {
    send(getSocket(),message.c_str(),message.size(),0);
}
// Implementación de la interfaz C
extern "C" {
ClienteHandle crearCliente(const char* serverIp, int port) {
    try {
        return new Cliente(serverIp, port);
    } catch (const std::exception& e) {
        std::cerr << "Error creando cliente: " << e.what() << std::endl;
        return nullptr;
    }
}

void destruirCliente(ClienteHandle handle) {
    delete static_cast<Cliente*>(handle);
}

void enviarMensaje(ClienteHandle handle, const char* message) {
    try {
        Cliente* cliente = static_cast<Cliente*>(handle);
        cliente->sendMessage(message);
    } catch (const std::exception& e) {
        std::cerr << "Error enviando mensaje: " << e.what() << std::endl;
    }
}
SocketHandle obtenerSocketCliente(ClienteHandle handle) {
    try {
        Cliente* cliente = static_cast<Cliente*>(handle);
        return static_cast<SocketHandle>(cliente->getSocket());
    } catch (...) {
        return (SocketHandle)INVALID_SOCKET;
    }
}
}
#endif