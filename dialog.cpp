#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include "main2.cpp"
#include <iostream>
#include <QByteArray>
#include <QPixmap>
#include <QBuffer>
#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;
using ip::tcp;


class Client_socket
{
public:
    void start()
    {
        boost::asio::io_service ios;
        tcp::socket socket(ios);
        socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"),
                                     1234));

        /*
        const string msg = "Hello from Client!\n";
        boost::system::error_code error;
        boost::asio::write(socket, boost::asio::buffer(msg), error);

        if (!error) {
            cout << "Client sent hello message!" << endl;
        } else {
            cout << "send failed: " << error.message() << endl;
        }

        boost::asio::streambuf receive_buffer;
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
        if (error && error != boost::asio::error::eof) {
            cout << "receive failed: " << error.message() << endl;
        } else {
            const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
            cout << data << endl;
        }
         */
    }

    void send_message(string msg)
    {
        boost::asio::io_service ios;
        tcp::socket socket(ios);
        socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"),
                                     1234));
        boost::system::error_code error;
        boost::asio::write(socket, boost::asio::buffer(msg), error);

        if (!error) {
            cout << "Client sent hello message!" << endl;
        } else {
            cout << "send failed: " << error.message() << endl;
        }
    }
};

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setFixedSize(1181,906);

    srand(time(nullptr));
    Game_logic g1;
    g1.shuffler();
    g1.matrix_maker();

    QPixmap pix1;
    pix1.loadFromData(g1.matrix_selector(0,0), "PNG");
    ui->label_image->setPixmap(pix1);
    ui->pushButton->setFlat(true);

    QPixmap pix2;
    pix2.loadFromData(g1.matrix_selector(0,1), "PNG");
    ui->label_image2->setPixmap(pix2);
    ui->pushButton_2->setFlat(true);

    QPixmap pix3;
    pix3.loadFromData(g1.matrix_selector(0,2),"PNG");
    ui->label_image3->setPixmap(pix3);
    ui->pushButton_3->setFlat(true);

    QPixmap pix4;
    pix4.loadFromData(g1.matrix_selector(0,3),"PNG");
    ui->label_image4->setPixmap(pix4);
    ui->pushButton_4->setFlat(true);

    QPixmap pix5;
    pix5.loadFromData(g1.matrix_selector(1,0),"PNG");
    ui->label_image5->setPixmap(pix5);
    ui->pushButton_5->setFlat(true);

    QPixmap pix6;
    pix6.loadFromData(g1.matrix_selector(1,1),"PNG");
    ui->label_image6->setPixmap(pix6);
    ui->pushButton_6->setFlat(true);

    QPixmap pix7;
    pix7.loadFromData(g1.matrix_selector(1,2),"PNG");
    ui->label_image7->setPixmap(pix7);
    ui->pushButton_7->setFlat(true);

    QPixmap pix8;
    pix8.loadFromData(g1.matrix_selector(1,3),"PNG");
    ui->label_image8->setPixmap(pix8);
    ui->pushButton_8->setFlat(true);

    QPixmap pix9;
    pix9.loadFromData(g1.matrix_selector(2,0),"PNG");
    ui->label_image9->setPixmap(pix9);
    ui->pushButton_9->setFlat(true);

    QPixmap pix10;
    pix10.loadFromData(g1.matrix_selector(2,1),"PNG");
    ui->label_image10->setPixmap(pix10);
    ui->pushButton_10->setFlat(true);

    QPixmap pix11;
    pix11.loadFromData(g1.matrix_selector(2,2),"PNG");
    ui->label_image11->setPixmap(pix11);
    ui->pushButton_11->setFlat(true);

    QPixmap pix12;
    pix12.loadFromData(g1.matrix_selector(2,3),"PNG");
    ui->label_image12->setPixmap(pix12);
    ui->pushButton_12->setFlat(true);
}

void Dialog::on_pushButton_clicked()
{
    Client_socket c1;
    c1.send_message("I work!\n");
}


Dialog::~Dialog()
{
    delete ui;
}