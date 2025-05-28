#ifndef SERVER_H
#define SERVER_H

#ifdef __cplusplus
#include "socket.h"
#include <stdexcept>
#include <string>

class Server : public Socket {
public:
    Server(int port);
    SOCKET acceptConnection();
};
#endif // __cplusplus

// Interfaz C compatible
#ifdef __cplusplus
extern "C" {
#endif

typedef void* ServerHandle;
typedef intptr_t SocketHandle;  // Tipo compatible para sockets

ServerHandle crearServidor(int port);
void destruirServidor(ServerHandle handle);
SocketHandle aceptarConexion(ServerHandle handle);

#ifdef __cplusplus
}
#endif

#endif // SERVER_H