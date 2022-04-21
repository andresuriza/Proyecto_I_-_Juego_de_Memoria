/********************************************************************************
** Form generated from reading UI file 'serverwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *serverWindow)
    {
        if (serverWindow->objectName().isEmpty())
            serverWindow->setObjectName(QString::fromUtf8("serverWindow"));
        serverWindow->resize(1062, 549);
        centralwidget = new QWidget(serverWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 7)
            tableWidget->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem14);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 30, 971, 441));
        tableWidget->setMaximumSize(QSize(1101, 461));
        tableWidget->setAutoFillBackground(false);
        tableWidget->setShowGrid(true);
        tableWidget->setWordWrap(true);
        serverWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(serverWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1062, 22));
        serverWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(serverWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        serverWindow->setStatusBar(statusbar);

        retranslateUi(serverWindow);

        QMetaObject::connectSlotsByName(serverWindow);
    } // setupUi

    void retranslateUi(QMainWindow *serverWindow)
    {
        serverWindow->setWindowTitle(QCoreApplication::translate("serverWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("serverWindow", "Value:", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("serverWindow", "Player1 points", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("serverWindow", "Player2 points", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("serverWindow", "Page faults", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("serverWindow", "Page hits", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("serverWindow", "Memory usage", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("serverWindow", "Pages in memory", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("serverWindow", "Pages in disk", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("serverWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(1, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("serverWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(2, 0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("serverWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(3, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("serverWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(4, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("serverWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(5, 0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("serverWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(6, 0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("serverWindow", "0", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class serverWindow: public Ui_serverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
