#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "Game_logic.cpp"

using namespace std;

namespace Ui {
class Dialog;
}

/**
 * Creates a client socket that communicates with the server
 *
 */
class Client_socket
{
public:
    void send(const string msg);
    int get_n_sent();
    void set_matrix(int values[2][2]);

private:
    int n_sent = 0;
    int positions[2][2];
    Game_logic gl;
};

/**
 * Creates a dialog UI that displays the game cards and other information so the user can play
 *
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void timer_logic();
    void SendCardToServer(int column, int row);
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


private:
    int seconds = 0;
    Ui::Dialog *ui;
    Client_socket c1;
    int selected_array[2][2];
    Game_logic g1;
    int points = 0;
};

#endif // DIALOG_H
