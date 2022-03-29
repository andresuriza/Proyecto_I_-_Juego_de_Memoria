#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this ->setWindowTitle("aa");
}

void MainWindow::on_pushButton_pressed()
{
    //this->close();
    Dialog d;
    //d.setModal(false);
    d.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}




