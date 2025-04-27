/********************************************************************************
** Form generated from reading UI file 'guesslistdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESSLISTDIALOG_H
#define UI_GUESSLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_GuessListDialog
{
public:
    QPushButton *pushButtonExit;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QDialog *GuessListDialog)
    {
        if (GuessListDialog->objectName().isEmpty())
            GuessListDialog->setObjectName("GuessListDialog");
        GuessListDialog->resize(451, 434);
        pushButtonExit = new QPushButton(GuessListDialog);
        pushButtonExit->setObjectName("pushButtonExit");
        pushButtonExit->setGeometry(QRect(360, 400, 83, 29));
        label = new QLabel(GuessListDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 10, 301, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tableWidget = new QTableWidget(GuessListDialog);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 50, 451, 341));

        retranslateUi(GuessListDialog);

        QMetaObject::connectSlotsByName(GuessListDialog);
    } // setupUi

    void retranslateUi(QDialog *GuessListDialog)
    {
        GuessListDialog->setWindowTitle(QCoreApplication::translate("GuessListDialog", "Dialog", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("GuessListDialog", "Exit", nullptr));
        label->setText(QCoreApplication::translate("GuessListDialog", "Guess List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuessListDialog: public Ui_GuessListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESSLISTDIALOG_H
