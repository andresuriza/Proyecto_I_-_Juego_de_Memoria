#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent, QString name): QMainWindow(parent), ui(new Ui::MainWindow)
{ // Constructor method
    ui->setupUi(this);
    this->setFixedSize(1078,618);
    this->setWindowTitle(name);
}

void MainWindow::on_pushButton_clicked() // Handles start button action
{
    this->close();
    Dialog d;
    d.setModal(false);
    d.show();
    d.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}




