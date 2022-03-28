#include <iostream>
#include "form.h"
#include "ui_form.h"
#include <QPixmap>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setFixedSize(1181,906);

    QPixmap pix("/home/andres/Pictures/c++.jpg");

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

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_pressed()
{
    std::cout << "i work" << std::endl;
}


void Form::on_pushButton_2_pressed()
{

}



void Form::on_pushButton_3_pressed()
{

}

void Form::on_pushButton_4_pressed()
{

}


void Form::on_pushButton_5_pressed()
{

}


void Form::on_pushButton_6_pressed()
{

}


void Form::on_pushButton_7_pressed()
{

}


void Form::on_pushButton_8_pressed()
{

}


void Form::on_pushButton_9_pressed()
{

}

void Form::on_pushButton_10_pressed()
{

}

void Form::on_pushButton_11_pressed()
{

}

void Form::on_pushButton_12_pressed()
{

}
