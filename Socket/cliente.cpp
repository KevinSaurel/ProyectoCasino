#include "socket.cpp"

class Client : public Socket {
    //herencia por parte de socket para repetir la menor cantidad de codigo
    public:
        Client(std::string serverIp, int port) : Socket(AF_INET, SOCK_STREAM, 0) {
            address.sin_family = AF_INET;
            address.sin_port = htons(port);
            inet_pton(AF_INET, serverIp.c_str(), &address.sin_addr);
    
            if (connect(sockfd, (sockaddr*)&address, sizeof(address)) < 0)
                throw std::runtime_error("Error en connect()");
        }
    
        void sendMessage(const std::string& message) {
            send(sockfd, message.c_str(), message.size(), 0);
        }
    };
    