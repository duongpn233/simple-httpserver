#ifndef INCLUDED_LISTEN_SOCKET
#define INCLUDED_LISTEN_SOCKET

#include "bind_socket.h"
namespace http
{
    class ListenSocket : public BindSocket
    {
    public:
        ListenSocket(int domain, int service, int protocal, int port, u_long interface, int bl);
        ~ListenSocket();
        void listening();

    private:
        int backlog;
        int listener;
    };
} // namespace http
#endif