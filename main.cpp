#include "mainwindow.h"
#include <QApplication>
#include <QBuffer>
#include "main2.cpp"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow menu1;
    //MainWindow menu2;
    menu1.show();
    //menu2.show();
    return app.exec();

}
