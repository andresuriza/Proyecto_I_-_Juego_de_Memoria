#include "mainwindow.h"
#include "form.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow menu1;
    MainWindow menu2;
    menu1.show();
    //menu2.show();
    return a.exec();
}
