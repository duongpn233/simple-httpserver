#ifndef INCLUDED_SOCKET_TCP
#define INCLUDED_SOCKET_TCP
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
namespace http
{
    class TcpSocket
    {
    public:
        TcpSocket(int domain, int service, int protocal, int port, u_long interface);
        ~TcpSocket();
        virtual int connect(int sock, struct sockaddr_in addr) = 0;
        struct sockaddr_in get_address();
        int get_socket();
        int get_connection();
        void set_connection(int conn);

    private:
        int sock;
        int connection;
        struct sockaddr_in address;
    };
} // namespace http
#endif