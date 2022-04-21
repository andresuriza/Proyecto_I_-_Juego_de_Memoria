#include "serverwindow.h"
#include "ui_serverwindow.h"
#include "Server.cpp"

serverWindow::serverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serverWindow)
    // Constructor method for serverWindow
{
    ui->setupUi(this);
    this->setWindowTitle("Server");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    boost::asio::io_context io_context;
    tcp_server server(io_context);
    io_context.run();
}

void serverWindow::AddPointsP1() // Adds points to player 1
{
    p1Points++;
    ui->tableWidget->item(0,0)->setText(QString(p1Points));
}

void serverWindow::AddPointsP2() // Adds points to player 2
{
    p2Points++;
    ui->tableWidget->item(1,0)->setText(QString(p2Points));
}

serverWindow::~serverWindow()
{
    delete ui;
}
