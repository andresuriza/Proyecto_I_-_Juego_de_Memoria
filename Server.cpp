#include <iostream>
#include <string>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <cstring>

using boost::asio::ip::tcp;
using namespace std;

/**
 * Creates the necessary functions to handle socket connections and read/write operations
 *
 */
class tcp_connection: public boost::enable_shared_from_this<tcp_connection>
{
private:
    tcp::socket socket_;
    enum {max_length = 1024};
    char data[7]{};
    string type;

public:
    typedef boost::shared_ptr<tcp_connection> pointer;

    explicit tcp_connection(boost::asio::io_context& io_context): socket_(io_context){}

    static pointer create(boost::asio::io_context& io_context) { return pointer(new tcp_connection(io_context)); }

    tcp::socket& socket() { return socket_; }

    string start() // Reads data sent from client socket asynchronously
    {
        socket_.async_read_some(boost::asio::buffer(data, max_length),
                                boost::bind(&tcp_connection::handle_read, shared_from_this(),
                                    boost::asio::placeholders::error,
                                    boost::asio::placeholders::bytes_transferred));

        StringReader();

        return type;
    }

    void StringReader() // Reads string received to another string and ends if it detects ','
    {
        for (int i = 0; i < 8; i++) {
            if (data[i] != ',') {
                type.push_back(data[i]);
            } else {
                break;
            }
        }
    }

    void send(string message) // Sends a string to the client
    {
        socket_.async_write_some(boost::asio::buffer(message, max_length),
                                 boost::bind(&tcp_connection::handle_write, shared_from_this(),
                                             boost::asio::placeholders::error,
                                             boost::asio::placeholders::bytes_transferred));
    }

    void handle_read(const boost::system::error_code& err, size_t bytes_transferred)
    // Executes code after receiving message
    {
        if (!err) {}

        else {
            cerr << "error: " << err.message() << endl;
            socket_.close();
        }
    }

    void handle_write(const boost::system::error_code& err, size_t bytes_transferred)
    // Executes code after sending message
    {
        if (!err) {
            memset(data, 0, 7);
        } else {
            cerr << "error: " << err.message() << endl;
        }
    }
};

/**
 *  A TCP server that allows asynchronous client connections and calls the necessary functions to handle their
 *  connections
 */
class tcp_server
{
private:
    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
    string types_array[2];

    int i = 0;
    int j = 0;

    void start_accept() // Creates sockets for incoming connections
    {
        tcp_connection::pointer new_connection = tcp_connection::create(io_context_);


        acceptor_.async_accept(new_connection->socket(),
                               boost::bind(&tcp_server::handle_accept, this,new_connection,
                                           boost::asio::placeholders::error));

    }

public:
    explicit tcp_server(boost::asio::io_context& io_context): io_context_(io_context),   // Constructor RUNS ONCE
              acceptor_(io_context, tcp::endpoint(tcp::v4(), 1234))
    {
        cout << "server running" << endl;

        start_accept();
    }

    void handle_accept(tcp_connection::pointer new_connection, const boost::system::error_code& err)
    // Runs everytime it receives a message from client, and it handles receiving a pair of cards
    {
        if (!err) {
            cout << "Client connected" << endl;

            if (i < 1) {
                types_array[j] = new_connection->start();
                i++;
                j++;
            } else {
                types_array[j] = new_connection->start();
                cout << types_array[0] << endl;
                cout << types_array[1] << endl;
                bool randBool = types_array[0] == types_array[1];

                if (randBool == 0) {
                    new_connection->send("false");
                } else {
                    new_connection->send("true");
                }

                fill_n(types_array, 2, "");
                cout << randBool << endl;
                i = 0;
                j = 0;
            }
        }
        start_accept();
    }
};