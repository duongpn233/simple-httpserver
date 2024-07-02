#include "listen_socket.h"
#include <unistd.h>
namespace http
{
    ListenSocket::ListenSocket(int domain, int service, int protocal, int port, u_long interface, int bl) : BindSocket(domain, service, protocal, port, interface), backlog(bl)
    {
    }

    ListenSocket::~ListenSocket() {};
    void ListenSocket::listening()
    {
        listener = listen(get_socket(), backlog);
        if (listener < 0)
        {
            perror("Listen failed");
            exit(EXIT_FAILURE);
        }
    }
}
