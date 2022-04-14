#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "Game_logic.cpp"

namespace Ui {
class Dialog;
}

class Client_socket
{
public:
    void send(const string msg);

private:
    int n_sent = 0;
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void timer_logic();

private:
    Game_logic g1;
    int seconds = 0;
    Ui::Dialog *ui;
    Client_socket c1;
};

#endif // DIALOG_H
