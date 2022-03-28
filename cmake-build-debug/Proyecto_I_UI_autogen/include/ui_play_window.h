/********************************************************************************
** Form generated from reading UI file 'play_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAY_WINDOW_H
#define UI_PLAY_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QFrame *frame;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1383, 756);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(87, 193, 144, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(149, 255, 206, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(118, 224, 175, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(43, 96, 72, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(58, 129, 96, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(0, 110, 98, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        QBrush brush8(QColor(252, 252, 252, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush8);
        QBrush brush9(QColor(29, 153, 243, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush9);
        QBrush brush10(QColor(155, 89, 182, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush10);
        QBrush brush11(QColor(171, 224, 199, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush11);
        QBrush brush12(QColor(0, 0, 0, 255));
        brush12.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush12);
        QBrush brush13(QColor(255, 255, 220, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush13);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush14(QColor(0, 0, 0, 128));
        brush14.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush14);
#endif
        QBrush brush15(QColor(194, 194, 194, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush15);
        QBrush brush16(QColor(51, 57, 63, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush16);
        QBrush brush17(QColor(25, 28, 31, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush17);
        QBrush brush18(QColor(38, 43, 47, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush18);
        QBrush brush19(QColor(102, 114, 126, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush19);
        QBrush brush20(QColor(68, 76, 84, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush20);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush15);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush15);
        QBrush brush21(QColor(24, 25, 29, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush21);
        QBrush brush22(QColor(40, 46, 51, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush22);
        QBrush brush23(QColor(118, 118, 118, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush23);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush10);
        QBrush brush24(QColor(35, 38, 41, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush24);
        QBrush brush25(QColor(0, 0, 0, 255));
        brush25.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush25);
        QBrush brush26(QColor(15, 15, 15, 255));
        brush26.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush26);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush14);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush27(QColor(177, 177, 177, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush27);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush20);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush18);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush24);
        QBrush brush28(QColor(0, 0, 0, 255));
        brush28.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush28);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush26);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush14);
#endif
        Form->setPalette(palette);
        Form->setAutoFillBackground(true);
        frame = new QFrame(Form);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-90, 650, 1481, 111));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush29(QColor(0, 68, 193, 255));
        brush29.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush29);
        QBrush brush30(QColor(34, 112, 255, 255));
        brush30.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush30);
        QBrush brush31(QColor(17, 90, 224, 255));
        brush31.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush31);
        QBrush brush32(QColor(0, 34, 96, 255));
        brush32.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush32);
        QBrush brush33(QColor(0, 45, 129, 255));
        brush33.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush33);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush29);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush34(QColor(127, 161, 224, 255));
        brush34.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush34);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush13);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush15);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush16);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush17);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush18);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush19);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush20);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush15);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush15);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush21);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush22);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush23);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush24);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush26);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush32);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush29);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush30);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush31);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush32);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush33);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush32);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush32);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush29);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush29);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush27);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush24);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush26);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush15);
        frame->setPalette(palette1);
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAY_WINDOW_H
