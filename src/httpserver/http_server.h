#ifndef INCLUDED_HTTP_SERVER
#define INCLUDED_HTTP_SERVER
#include <iostream>
#include <unistd.h>
#include "../socket/listen_socket.h"
namespace http
{
    class TcpServer
    {
    public:
        TcpServer(int domain, int service, int protocal, int port, u_long interface, int bl);
        ~TcpServer();
        void start();
        ListenSocket *get_listener();

    private:
        ListenSocket *listener;
    };
} // namespace http
#endif