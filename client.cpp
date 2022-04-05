#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using namespace std;

using boost::asio::ip::tcp;



        /*
        boost::asio::streambuf receive_buffer;
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
        if( error && error != boost::asio::error::eof ) {
            cout << "receive failed: " << error.message() << endl;
        }
        else {
            const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
            cout << data << endl;
        }
         */

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow menu1(nullptr, "Player 1");
    MainWindow menu2(nullptr, "Player 2");
    menu1.show();
    menu2.show();
    return app.exec();
}

    /*
    QApplication app(argc, argv);
    MainWindow menu1;
    MainWindow menu2;
    menu1.show();
    menu2.show();
    return app.exec();
    */
