#include "socket.h"
#include <cstring>
#include <unistd.h>
namespace http
{
    TcpSocket::TcpSocket(int domain, int service, int protocal, int port, u_long interafce)
    {
        // define address struct
        // memset(&address, 0, sizeof(address));
        address.sin_family = domain;
        address.sin_port = htons(port);
        address.sin_addr.s_addr = htonl(interafce);

        // establish socket
        sock = socket(domain, service, protocal);
        if (sock == -1)
        {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        // establish network connection
        // connection = connect(sock, address);
    }
    TcpSocket::~TcpSocket()
    {
        close(sock);
    }
    struct sockaddr_in TcpSocket::get_address()
    {
        return address;
    }
    int TcpSocket::get_socket()
    {
        return sock;
    }
    int TcpSocket::get_connection()
    {
        return connection;
    }
    void TcpSocket::set_connection(int conn)
    {
        connection = conn;
    }
}
