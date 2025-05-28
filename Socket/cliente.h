#ifndef CLIENT_H
#define CLIENT_H

#ifdef __cplusplus

#include "socket.h"       
#include <string>         
#include <stdexcept>      

class Cliente : public Socket {
public:
    Cliente(std::string serverIp, int port);
    void sendMessage(const std::string& message);
};
#endif // __cplusplus
// Interfaz C compatible
#ifdef __cplusplus
extern "C" {
#endif

typedef void* ClienteHandle;

ClienteHandle crearCliente(const char* serverIp, int port);
void destruirCliente(ClienteHandle handle);
SocketHandle obtenerSocketCliente(ClienteHandle handle);
#ifdef __cplusplus
}
#endif
#endif // CLIENT_H