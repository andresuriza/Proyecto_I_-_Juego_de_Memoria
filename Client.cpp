#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "Game_logic.cpp"

using namespace std;

using boost::asio::ip::tcp;

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
