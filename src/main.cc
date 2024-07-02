#include <iostream>
#include "httpserver/http_server.h"

int main()
{
    std::cout << "init server\n";
    http::TcpServer server(AF_INET, SOCK_STREAM, 0, 8088, INADDR_ANY, 10);
    server.start();

    return 0;
}