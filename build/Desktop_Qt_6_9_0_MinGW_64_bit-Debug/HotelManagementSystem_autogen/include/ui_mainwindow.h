/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *pbShowGuessList;
    QPushButton *pbCheckIn;
    QPushButton *pbCheckOut;
    QPushButton *pbAddExtras;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(758, 565);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 0, 231, 511));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        pbShowGuessList = new QPushButton(frame);
        pbShowGuessList->setObjectName("pbShowGuessList");
        pbShowGuessList->setGeometry(QRect(10, 460, 211, 41));
        QFont font;
        font.setBold(true);
        pbShowGuessList->setFont(font);
        pbCheckIn = new QPushButton(frame);
        pbCheckIn->setObjectName("pbCheckIn");
        pbCheckIn->setGeometry(QRect(10, 8, 211, 171));
        pbCheckIn->setFont(font);
        pbCheckOut = new QPushButton(frame);
        pbCheckOut->setObjectName("pbCheckOut");
        pbCheckOut->setGeometry(QRect(10, 188, 211, 141));
        pbCheckOut->setFont(font);
        pbAddExtras = new QPushButton(frame);
        pbAddExtras->setObjectName("pbAddExtras");
        pbAddExtras->setGeometry(QRect(10, 338, 211, 111));
        pbAddExtras->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 10, 501, 511));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/hotellogo.png")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 758, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pbShowGuessList->setText(QCoreApplication::translate("MainWindow", "Show Guess List", nullptr));
        pbCheckIn->setText(QCoreApplication::translate("MainWindow", "Check-In", nullptr));
        pbCheckOut->setText(QCoreApplication::translate("MainWindow", "Check-Out", nullptr));
        pbAddExtras->setText(QCoreApplication::translate("MainWindow", "Add Extras", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
