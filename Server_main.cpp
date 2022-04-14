#include <iostream>
#include "Server.cpp"

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
}