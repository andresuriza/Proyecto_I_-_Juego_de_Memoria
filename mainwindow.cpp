#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1078,618);
    this->setWindowTitle("Player");
}

void MainWindow::on_pushButton_clicked()
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




