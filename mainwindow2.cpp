#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "Game_logic.cpp"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    Game_logic game;

    srand(time(nullptr));
    game.shuffler();
    game.matrix_maker();
    cout << "server running" << endl;

    ui->setupUi(this);
    QByteArray b1 = game.matrix_selector(0,0).get_image();
    QString b1_qstr = QString(b1);
    //string b1_str = b1_qstr.toStdString();

    QPixmap pix1;
    QByteArray imag = b1_qstr.toUtf8();
    pix1.loadFromData(b1, "PNG");
    ui->labelImage->setPixmap(pix1);
    //ui->pushButton->setFlat(true);

}

MainWindow2::~MainWindow2()
{
    delete ui;
}
