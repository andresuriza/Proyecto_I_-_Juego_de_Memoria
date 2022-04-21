#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QPixmap>
#include <boost/asio.hpp>
#include <QElapsedTimer>
#include <QTimeEdit>
#include <QTimer>
#include <QDebug>

using boost::asio::ip::tcp;
using namespace std;

void Client_socket::send(const string msg)
{   // Sends a message to server and reads incoming one after condition is met
    boost::asio::io_context io_context;
    tcp::socket socket(io_context);

    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"),
                                 1234));
    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(msg + ","), error);

    if (!error) {
        cout << "Client sent a message!" << endl;
        n_sent++;
    } else {
        cout << "send failed: " << error.message() << endl;
    }

    if (n_sent == 2) {
        boost::asio::streambuf receive_buffer;
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
        if (error && error != boost::asio::error::eof) {
            cout << "receive failed: " << error.message() << endl;
        } else {
            const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
            string data_str = data;
            cout << data << endl;
            n_sent = 0;
        }
    }
}

void Client_socket::set_matrix(int values[2][2]) // Copies matrix values to the positions one to remember cards chosen
{
    for (int i = 0; i < 2; i++) {
        positions[i][0] = values[i][0];
    }
    for (int j = 0; j < 2; j++) {
        positions[0][j] = values[0][j];
    }
}

int Client_socket::get_n_sent() // Returns number of cards sent in current turn
{
    return n_sent;
}

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{  // Constructor method of Dialog
    ui->setupUi(this);
    this->setFixedSize(1181,906);

    g1.CardArrayMaker();

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
    ui->timeVal->setNum(seconds);
}

void Dialog::SendCardToServer(int column, int row) // If a card isnt chosen, it chooses it and sends info to server
{
    if (g1.matrix_selector(column, row).get_taken() == false) {
        g1.matrix_changer(column, row);

        if (c1.get_n_sent() == 0) {
            selected_array[0][0] = column;
            selected_array[0][1] = row;
            c1.send(g1.matrix_selector(column, row).get_type());
        } else {
            selected_array[1][0] = column;
            selected_array[1][1] = row;
            c1.set_matrix(selected_array);
            c1.send(g1.matrix_selector(column, row).get_type());
            g1.matrix_selector(column, row).change_status();
            points++;

            if (points == 6) {
                cout << "you won, it took you: " + to_string(seconds) + " seconds" << endl;
            }
            ui->pointsVal->setNum(points);
        }
    }
}

void Dialog::on_pushButton_clicked()  // Manages what pressing button 1 does
{
    SendCardToServer(0,0);
}

void Dialog::on_pushButton_2_clicked() // Manages what pressing button 2 does
{
    SendCardToServer(0,1);
}

void Dialog::on_pushButton_3_clicked()  // Manages what pressing button 3 does
{
    SendCardToServer(0,2);
}

void Dialog::on_pushButton_4_clicked()  // Manages what pressing button 4 does
{
    SendCardToServer(0,3);
}

void Dialog::on_pushButton_5_clicked()  // Manages what pressing button 5 does
{
    SendCardToServer(1,0);
}

void Dialog::on_pushButton_6_clicked()  // Manages what pressing button 6 does
{
    SendCardToServer(1,1);
}

void Dialog::on_pushButton_7_clicked()  // Manages what pressing button 7 does
{
    SendCardToServer(1,2);
}

void Dialog::on_pushButton_8_clicked()  // Manages what pressing button 8 does
{
    SendCardToServer(1,3);
}

void Dialog::on_pushButton_9_clicked()  // Manages what pressing button 9 does
{   // Manages what pressing button 1 does
    SendCardToServer(2,0);
}

void Dialog::on_pushButton_10_clicked()  // Manages what pressing button 10 does
{
    SendCardToServer(2,1);
}

void Dialog::on_pushButton_11_clicked()  // Manages what pressing button 11 does
{
    SendCardToServer(2,2);
}

void Dialog::on_pushButton_12_clicked()  // Manages what pressing button 12 does
{
    SendCardToServer(2,3);
}

Dialog::~Dialog()
{
    delete ui;
}