#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

class tcp_connection : public boost::enable_shared_from_this<tcp_connection>
{
private:
    tcp::socket socket_;
    std::string message_ = "Hello from Server!";
    enum {max_length = 1024};
    char data[max_length];

public:
    typedef boost::shared_ptr<tcp_connection> pointer;

    tcp_connection(boost::asio::io_context& io_context): socket_(io_context){}

    static pointer create(boost::asio::io_context& io_context)
    {
        return pointer(new tcp_connection(io_context));
    }

    tcp::socket& socket()
    {
        return socket_;
    }

    void start()
    {
        socket_.async_read_some(boost::asio::buffer(data, max_length),
                                boost::bind(&tcp_connection::handle_read, shared_from_this(),
                                            boost::asio::placeholders::error,
                                            boost::asio::placeholders::bytes_transferred));

        /*
        socket_.async_write_some(boost::asio::buffer(data, max_length),
                                 boost::bind(&tcp_connection::handle_write, shared_from_this(),
                                             boost::asio::placeholders::error,
                                             boost::asio::placeholders::bytes_transferred));
                                             */
    }

    void handle_write(const boost::system::error_code& err, size_t bytes_transferred)
    {
        if (!err) {
            cout << "Server sent Hello Message!" << endl;
        } else {
            cerr << "error: " << err.message() << endl;
        }
    }

    void handle_read(const boost::system::error_code& err, size_t bytes_transferred)
    {
        if (!err) {
            cout << data << endl;
        } else {
            cerr << "error: " << err.message() << endl;
            socket_.close();
        }
    }
};

class tcp_server
{
private:
    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;

    void start_accept()
    {
        tcp_connection::pointer new_connection = tcp_connection::create(io_context_);

        acceptor_.async_accept(new_connection->socket(),
                               boost::bind(&tcp_server::handle_accept, this, new_connection,
                                           boost::asio::placeholders::error));
    }

public:
    tcp_server(boost::asio::io_context& io_context): io_context_(io_context),
              acceptor_(io_context, tcp::endpoint(tcp::v4(), 1234))
    {
        start_accept();
    }

    void handle_accept(tcp_connection::pointer new_connection, const boost::system::error_code& err)
    {
        if (!err)
        {
            new_connection->start();
        }
        start_accept();
    }
};