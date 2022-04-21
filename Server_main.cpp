#include <iostream>
#include <QApplication>
#include "serverwindow.h"
using namespace std;

int main(int argc, char *argv[]) {
    try {
        QApplication serverUI(argc, argv);
        serverWindow server_window(nullptr);
        server_window.show();
        serverUI.exec();

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}