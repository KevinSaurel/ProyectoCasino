#include "socket.cpp"

class Server : public Socket {
    //herencia por parte de socket para repetir la menor cantidad de codigo
    public:
        Server(int port) : Socket(AF_INET, SOCK_STREAM, 0) {
            address.sin_family = AF_INET;
            address.sin_addr.s_addr = INADDR_ANY;
            address.sin_port = htons(port);
    
            if (bind(sockfd, (sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
                throw std::runtime_error("Error en bind()");
            }
    
            if (listen(sockfd, SOMAXCONN) == SOCKET_ERROR) {
                throw std::runtime_error("Error en listen()");
            }
    
            std::cout << "Servidor escuchando en el puerto " << port << "...\n";
        }
    
        SOCKET acceptConnection() {
            SOCKET clientSocket = accept(sockfd, nullptr, nullptr);
            if (clientSocket == INVALID_SOCKET) {
                throw std::runtime_error("Error en accept()");
            }
            return clientSocket;
        }
    };
    