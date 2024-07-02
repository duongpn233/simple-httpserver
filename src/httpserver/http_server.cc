#include "http_server.h"

namespace http
{
    TcpServer::TcpServer(int domain, int service, int protocol, int port, u_long interface, int bl)
    {
        listener = new ListenSocket(domain, service, protocol, port, interface, bl);
    }
    TcpServer::~TcpServer()
    {
    }
    void TcpServer::start()
    {
        listener->listening();
        std::cout << "listening\n";
        struct sockaddr_in addr = listener->get_address();
        socklen_t addr_len = sizeof(addr);
        int sock = listener->get_socket();

        while (true)
        {
            int new_socket = accept(sock, (struct sockaddr *)&addr, &addr_len);
            if (new_socket < 0)
            {
                perror("In accept request failed");
                exit(EXIT_FAILURE);
            }

            char buffer[30000] = {0};
            read(new_socket, buffer, 30000);
            std::cout << buffer;
            close(new_socket);
        }
    }
    ListenSocket *TcpServer::get_listener()
    {
        return listener;
    }
}