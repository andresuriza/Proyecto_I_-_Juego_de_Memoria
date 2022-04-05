#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QPixmap>
#include <boost/asio.hpp>
#include <QElapsedTimer>
#include <QTimeEdit>
#include <QTimer>

using boost::asio::ip::tcp;
using namespace std;

class Client_socket
{
public:
    void start(const string msg) {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context);

        socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"),
                                     1234));

        boost::system::error_code error;
        boost::asio::write(socket, boost::asio::buffer(msg), error);
        if (!error) {
            cout << "Client sent a message!" << endl;
        } else {
            cout << "send failed: " << error.message() << endl;
        }

        const string msg2 = "hello again\n";

        boost::asio::write(socket, boost::asio::buffer(msg2), error);
        if (!error) {
            cout << "Client sent another message!" << endl;
        } else {
            cout << "send failed: " << error.message() << endl;
        }
    }
};

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setFixedSize(1181,906);

    srand(time(nullptr));
    g1.shuffler();
    g1.matrix_maker();

    QPixmap pix1;
    pix1.loadFromData(g1.matrix_selector(0,0).get_image(), "PNG");
    ui->label_image->setPixmap(pix1);
    ui->pushButton->setFlat(true);

    QPixmap pix2;
    pix2.loadFromData(g1.matrix_selector(0,1).get_image(), "PNG");
    ui->label_image2->setPixmap(pix2);
    ui->pushButton_2->setFlat(true);

    QPixmap pix3;
    pix3.loadFromData(g1.matrix_selector(0,2).get_image(),"PNG");
    ui->label_image3->setPixmap(pix3);
    ui->pushButton_3->setFlat(true);

    QPixmap pix4;
    pix4.loadFromData(g1.matrix_selector(0,3).get_image(),"PNG");
    ui->label_image4->setPixmap(pix4);
    ui->pushButton_4->setFlat(true);

    QPixmap pix5;
    pix5.loadFromData(g1.matrix_selector(1,0).get_image(),"PNG");
    ui->label_image5->setPixmap(pix5);
    ui->pushButton_5->setFlat(true);

    QPixmap pix6;
    pix6.loadFromData(g1.matrix_selector(1,1).get_image(),"PNG");
    ui->label_image6->setPixmap(pix6);
    ui->pushButton_6->setFlat(true);

    QPixmap pix7;
    pix7.loadFromData(g1.matrix_selector(1,2).get_image(),"PNG");
    ui->label_image7->setPixmap(pix7);
    ui->pushButton_7->setFlat(true);

    QPixmap pix8;
    pix8.loadFromData(g1.matrix_selector(1,3).get_image(),"PNG");
    ui->label_image8->setPixmap(pix8);
    ui->pushButton_8->setFlat(true);

    QPixmap pix9;
    pix9.loadFromData(g1.matrix_selector(2,0).get_image(),"PNG");
    ui->label_image9->setPixmap(pix9);
    ui->pushButton_9->setFlat(true);

    QPixmap pix10;
    pix10.loadFromData(g1.matrix_selector(2,1).get_image(),"PNG");
    ui->label_image10->setPixmap(pix10);
    ui->pushButton_10->setFlat(true);

    QPixmap pix11;
    pix11.loadFromData(g1.matrix_selector(2,2).get_image(),"PNG");
    ui->label_image11->setPixmap(pix11);
    ui->pushButton_11->setFlat(true);

    QPixmap pix12;
    pix12.loadFromData(g1.matrix_selector(2,3).get_image(),"PNG");
    ui->label_image12->setPixmap(pix12);
    ui->pushButton_12->setFlat(true);

    QTimer* timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_logic()));
    timer->start();
}

void Dialog::timer_logic() // Adds a second and updates the label
{
    seconds++;
    ui->time_val->setNum(seconds);
}

void Dialog::on_pushButton_clicked()
{
    g1.matrix_selector(0,0);
    Client_socket c1;
}

void Dialog::on_pushButton2_clicked()
{
    g1.matrix_selector(0,1);
    Client_socket c1;
}

void Dialog::on_pushButton3_clicked()
{
    g1.matrix_selector(0,2);
    Client_socket c1;
}

void Dialog::on_pushButton4_clicked()
{
    g1.matrix_selector(1,0);
    Client_socket c1;
}

void Dialog::on_pushButton5_clicked()
{
    g1.matrix_selector(1,1);
    Client_socket c1;
}

void Dialog::on_pushButton6_clicked()
{
    g1.matrix_selector(1,2);
    Client_socket c1;
}

void Dialog::on_pushButton7_clicked()
{
    g1.matrix_selector(2,0);
    Client_socket c1;
}

void Dialog::on_pushButton8_clicked()
{
    g1.matrix_selector(2,1);
    Client_socket c1;
}

void Dialog::on_pushButton9_clicked()
{
    g1.matrix_selector(2,2);
    Client_socket c1;
}

void Dialog::on_pushButton10_clicked()
{
    g1.matrix_selector(3,0);
    Client_socket c1;
}

void Dialog::on_pushButton11_clicked()
{
    g1.matrix_selector(3,1);
    Client_socket c1;
}

void Dialog::on_pushButton12_clicked()
{
    g1.matrix_selector(3,2);
    Client_socket c1;
}

Dialog::~Dialog()
{
    delete ui;
}