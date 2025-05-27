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

#endif // __cplusplus
#endif // SOCKET_H