#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <cstring>

using boost::asio::ip::tcp;
using namespace std;

class tcp_connection : public boost::enable_shared_from_this<tcp_connection>
{
private:
    tcp::socket socket_;
    enum {max_length = 1024};
    char data[7];
    int i = 0;
    string type;
    //bool received = false;

public:
    typedef boost::shared_ptr<tcp_connection> pointer;

    tcp_connection(boost::asio::io_context& io_context): socket_(io_context){}

    static pointer create(boost::asio::io_context& io_context) // Creates a pointer for server
    {
        return pointer(new tcp_connection(io_context));
    }

    tcp::socket& socket() // Returns socket mem direction
    {
        return socket_;
    }

    string start()
    {
        socket_.async_read_some(boost::asio::buffer(data, max_length),
                                boost::bind(&tcp_connection::handle_read, shared_from_this(),
                                    boost::asio::placeholders::error,
                                    boost::asio::placeholders::bytes_transferred));  // Reads data and executes
                                                                                        //code when received from client
        for (int i = 0; i < 8; i++) {
            if (data[i] != ',') {
                type.push_back(data[i]);
            } else {
                //data_array[0] = data
                //cout << type << endl;
                break;
            }
        }

        return type;

            /*
            socket_.async_write_some(boost::asio::buffer(mess, max_length),
                                     boost::bind(&tcp_connection::handle_write, shared_from_this(),
                                                 boost::asio::placeholders::error,
                                                 boost::asio::placeholders::bytes_transferred));
            */

    }

    void send(string message)
    {
        socket_.async_write_some(boost::asio::buffer(message, max_length),
                                 boost::bind(&tcp_connection::handle_write, shared_from_this(),
                                             boost::asio::placeholders::error,
                                             boost::asio::placeholders::bytes_transferred));
    }

    void handle_read(const boost::system::error_code& err, size_t bytes_transferred)
    // Executes code after receiving message
    {
        if (!err) {
            //memset(data, 0, 1024);

         } else {
            cerr << "error: " << err.message() << endl;
            socket_.close();
        }
    }

    void handle_write(const boost::system::error_code& err, size_t bytes_transferred)
    // Executes code after sending message
    {
        if (!err) {
            memset(data, 0, 7);
           // cout << "Server sent Hello Message!" << endl;
        } else {
            cerr << "error: " << err.message() << endl;
        }
    }
};

class tcp_server
{
private:
    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
    int i = 0;
    int j = 0;
    string types_array[2];

    void start_accept() // Creates sockets for incoming connections
    {
        tcp_connection::pointer new_connection = tcp_connection::create(io_context_);

        acceptor_.async_accept(new_connection->socket(),
                               boost::bind(&tcp_server::handle_accept, this, new_connection,
                                           boost::asio::placeholders::error));
    }

public:
    tcp_server(boost::asio::io_context& io_context): io_context_(io_context),   // Constructor
              acceptor_(io_context, tcp::endpoint(tcp::v4(), 1234))
    {
        start_accept();
    }

    void handle_accept(tcp_connection::pointer new_connection, const boost::system::error_code& err)
    // Creates pointer to connected client
    {
        if (!err) {
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