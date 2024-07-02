#include "bind_socket.h"
#include <unistd.h>
namespace http
{
    BindSocket::BindSocket(int domain, int service, int protocal, int port, u_long interface) : TcpSocket(domain, service, protocal, port, interface)
    {
        int conn = connect(get_socket(), get_address());
        if (conn < 0)
        {
            perror("Bind failed");
            close(get_socket());
            exit(EXIT_FAILURE);
        }
        set_connection(conn);
    }
    int BindSocket::connect(int sock, struct sockaddr_in addr)
    {
        return bind(sock, (struct sockaddr *)&addr, sizeof(addr));
    }
    BindSocket::~BindSocket() {};
}
