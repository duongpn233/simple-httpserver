#ifndef INCLUDED_BIND_SOCKET
#define INCLUDED_BIND_SOCKET

#include "socket.h"
namespace http
{
    class BindSocket : public TcpSocket
    {
    public:
        BindSocket(int domain, int service, int protocal, int port, u_long interface);
        ~BindSocket();
        int connect(int sock, struct sockaddr_in addr) override;

    private:
    };
} // namespace http
#endif