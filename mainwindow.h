#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*
    MainWindow(QString title) {
        titlebar = title;
    }
    */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //QString titlebar;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H