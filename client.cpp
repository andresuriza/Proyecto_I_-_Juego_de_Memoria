#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using namespace std;

using boost::asio::ip::tcp;

class Client_socket {
public:
    void start() {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context);

        socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 1234 ));

        const string msg = "Hello from Client!\n";
        boost::system::error_code error;
        boost::asio::write( socket, boost::asio::buffer(msg), error );
        if(!error) {
            cout << "Client sent hello message!" << endl;
        }
        else {
            cout << "send failed: " << error.message() << endl;
        }

        boost::asio::streambuf receive_buffer;
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
        if( error && error != boost::asio::error::eof ) {
            cout << "receive failed: " << error.message() << endl;
        }
        else {
            const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
            cout << data << endl;
        }
    }
};

int main (int argc, char *argv[]) {
    Client_socket c1;
    c1.start();
    //QApplication app(argc, argv);
    //MainWindow menu1;
    //MainWindow menu2;
    //menu1.show();
    //menu2.show();
    //return app.exec();
    return 0;
}

    /*
    QApplication app(argc, argv);
    MainWindow menu1;
    MainWindow menu2;
    menu1.show();
    menu2.show();
    return app.exec();
    */
