#include <iostream>
#include "server.cpp"

int main(int argc, char *argv[])
{
    Server_socket s1;
    boost::asio::io_service ios;
    tcp::acceptor acceptor(ios, tcp::endpoint(tcp::v4(), 1234));
    tcp::socket socket(ios);
    acceptor.accept(socket);
    string message = s1.read(socket);
    cout << message << endl;
    //s1.send(socket, "Hello from Server!");
    //cout << "Server sent Hello Message to Client!" << endl;
    return 0;
}