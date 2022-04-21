#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>

namespace Ui {
class serverWindow;
}

/**
 * Creates a UI for the server to display information
 *
 */
class serverWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit serverWindow(QWidget *parent = nullptr);
    void AddPointsP1();
    void AddPointsP2();
    ~serverWindow();

private:
    Ui::serverWindow *ui;
    int p1Points = 0;
    int p2Points = 0;
};

#endif