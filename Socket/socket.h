#ifndef SOCKET_H
#define SOCKET_H

#ifdef __cplusplus
// Solo incluye headers de C++ si se compila como C++
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdexcept>

class Socket {
protected:
    SOCKET sockfd;
    sockaddr_in address;

public:
    Socket(int domain, int type, int protocol);
    virtual ~Socket();
    SOCKET getSocket() const;
};
// Interfaz mínima para compatibilidad con C
extern "C" {
    #endif
    
    // Tipo opaco para representar sockets (compatible con C)
    typedef intptr_t SocketHandle;
    
    // Nuevas funciones de operación básica
    int enviarDatos(SocketHandle socket, const char* mensaje);
    int recibirDatos(SocketHandle socket, char* buffer, int buffer_length);
    void cerrarSocket(SocketHandle socket);
    #ifdef __cplusplus
    }
    #endif
    
    #endif // SOCKET_H