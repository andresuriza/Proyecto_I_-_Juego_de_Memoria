#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setFixedSize(1181,906);

    QPixmap pix("../images/clover.png");

    ui->label_image->setPixmap(pix);
    ui->pushButton->setFlat(true);

    ui->label_image2->setPixmap(pix);
    ui->pushButton_2->setFlat(true);

    ui->label_image3->setPixmap(pix);
    ui->pushButton_3->setFlat(true);

    ui->label_image4->setPixmap(pix);
    ui->pushButton_4->setFlat(true);

    ui->label_image5->setPixmap(pix);
    ui->pushButton_5->setFlat(true);

    ui->label_image6->setPixmap(pix);
    ui->pushButton_6->setFlat(true);

    ui->label_image7->setPixmap(pix);
    ui->pushButton_7->setFlat(true);

    ui->label_image8->setPixmap(pix);
    ui->pushButton_8->setFlat(true);

    ui->label_image9->setPixmap(pix);
    ui->pushButton_9->setFlat(true);

    ui->label_image10->setPixmap(pix);
    ui->pushButton_10->setFlat(true);

    ui->label_image11->setPixmap(pix);
    ui->pushButton_11->setFlat(true);

    ui->label_image12->setPixmap(pix);
    ui->pushButton_12->setFlat(true);
}

Dialog::~Dialog()
{
    delete ui;
}
