#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "main2.cpp"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();
    void on_pushButton7_clicked();
    void on_pushButton8_clicked();
    void on_pushButton9_clicked();
    void on_pushButton10_clicked();
    void on_pushButton11_clicked();
    void on_pushButton12_clicked();
    void timer_logic();

private:
    Game_logic g1;
    int seconds = 0;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
