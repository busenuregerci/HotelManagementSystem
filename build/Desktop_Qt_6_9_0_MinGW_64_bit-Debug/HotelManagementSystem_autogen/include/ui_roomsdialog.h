/********************************************************************************
** Form generated from reading UI file 'roomsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMSDIALOG_H
#define UI_ROOMSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RoomsDialog
{
public:
    QGroupBox *groupBox;
    QPushButton *pb101;
    QPushButton *pb102;
    QPushButton *pb103;
    QPushButton *pb104;
    QGroupBox *groupBox_2;
    QPushButton *pb201;
    QPushButton *pb202;
    QPushButton *pb203;

    void setupUi(QDialog *RoomsDialog)
    {
        if (RoomsDialog->objectName().isEmpty())
            RoomsDialog->setObjectName("RoomsDialog");
        RoomsDialog->resize(591, 377);
        groupBox = new QGroupBox(RoomsDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 571, 171));
        pb101 = new QPushButton(groupBox);
        pb101->setObjectName("pb101");
        pb101->setGeometry(QRect(10, 30, 131, 131));
        pb102 = new QPushButton(groupBox);
        pb102->setObjectName("pb102");
        pb102->setGeometry(QRect(150, 30, 131, 131));
        pb103 = new QPushButton(groupBox);
        pb103->setObjectName("pb103");
        pb103->setGeometry(QRect(290, 30, 131, 131));
        pb104 = new QPushButton(groupBox);
        pb104->setObjectName("pb104");
        pb104->setGeometry(QRect(430, 30, 131, 131));
        groupBox_2 = new QGroupBox(RoomsDialog);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 170, 561, 191));
        pb201 = new QPushButton(groupBox_2);
        pb201->setObjectName("pb201");
        pb201->setGeometry(QRect(10, 40, 131, 131));
        pb202 = new QPushButton(groupBox_2);
        pb202->setObjectName("pb202");
        pb202->setGeometry(QRect(150, 40, 131, 131));
        pb203 = new QPushButton(groupBox_2);
        pb203->setObjectName("pb203");
        pb203->setGeometry(QRect(290, 40, 261, 131));

        retranslateUi(RoomsDialog);

        QMetaObject::connectSlotsByName(RoomsDialog);
    } // setupUi

    void retranslateUi(QDialog *RoomsDialog)
    {
        RoomsDialog->setWindowTitle(QCoreApplication::translate("RoomsDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RoomsDialog", "Floor 1", nullptr));
        pb101->setText(QCoreApplication::translate("RoomsDialog", "101", nullptr));
        pb102->setText(QCoreApplication::translate("RoomsDialog", "102", nullptr));
        pb103->setText(QCoreApplication::translate("RoomsDialog", "103", nullptr));
        pb104->setText(QCoreApplication::translate("RoomsDialog", "104", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("RoomsDialog", "Floor 2", nullptr));
        pb201->setText(QCoreApplication::translate("RoomsDialog", "201", nullptr));
        pb202->setText(QCoreApplication::translate("RoomsDialog", "202", nullptr));
        pb203->setText(QCoreApplication::translate("RoomsDialog", "203 [\342\231\246SUITE\342\231\246]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomsDialog: public Ui_RoomsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMSDIALOG_H
