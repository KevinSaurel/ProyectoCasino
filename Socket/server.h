#ifndef SERVER_H
#define SERVER_H

#include "socket.h" 
#include <stdexcept>
#include <string>

class Server : public Socket {
public:
    Server(int port);
    SOCKET acceptConnection();
};

#endif // SERVER_H