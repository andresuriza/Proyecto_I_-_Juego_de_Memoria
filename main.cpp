#include <iostream>
#include "server.cpp"

using namespace std;


int main(int argc, char *argv[])
{
    try
    {
        boost::asio::io_context io_context;
        tcp_server server(io_context);
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
    //s1.send(socket, "Hello from Server!");
    //cout << "Server sent Hello Message to Client!" << endl;
}