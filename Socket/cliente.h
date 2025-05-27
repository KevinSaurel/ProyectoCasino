#ifndef CLIENT_H
#define CLIENT_H

#include "socket.h"       
#include <string>         
#include <stdexcept>      

class Cliente : public Socket {
public:
    Cliente(std::string serverIp, int port);
    void sendMessage(const std::string& message);
};

#endif // CLIENT_H