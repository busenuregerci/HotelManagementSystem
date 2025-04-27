/********************************************************************************
** Form generated from reading UI file 'extradialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTRADIALOG_H
#define UI_EXTRADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ExtraDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditReservationNo;
    QLabel *labelCustomerInfo;
    QLabel *label2;
    QLineEdit *lineEditExtra;
    QLabel *label_3;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonFetch;

    void setupUi(QDialog *ExtraDialog)
    {
        if (ExtraDialog->objectName().isEmpty())
            ExtraDialog->setObjectName("ExtraDialog");
        ExtraDialog->resize(400, 300);
        label = new QLabel(ExtraDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 381, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(ExtraDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 80, 121, 20));
        lineEditReservationNo = new QLineEdit(ExtraDialog);
        lineEditReservationNo->setObjectName("lineEditReservationNo");
        lineEditReservationNo->setGeometry(QRect(150, 80, 141, 28));
        labelCustomerInfo = new QLabel(ExtraDialog);
        labelCustomerInfo->setObjectName("labelCustomerInfo");
        labelCustomerInfo->setGeometry(QRect(60, 120, 311, 20));
        label2 = new QLabel(ExtraDialog);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(90, 170, 51, 20));
        lineEditExtra = new QLineEdit(ExtraDialog);
        lineEditExtra->setObjectName("lineEditExtra");
        lineEditExtra->setGeometry(QRect(150, 180, 211, 28));
        label_3 = new QLabel(ExtraDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 180, 111, 20));
        pushButtonCancel = new QPushButton(ExtraDialog);
        pushButtonCancel->setObjectName("pushButtonCancel");
        pushButtonCancel->setGeometry(QRect(160, 240, 83, 29));
        pushButtonOk = new QPushButton(ExtraDialog);
        pushButtonOk->setObjectName("pushButtonOk");
        pushButtonOk->setGeometry(QRect(260, 240, 111, 29));
        pushButtonFetch = new QPushButton(ExtraDialog);
        pushButtonFetch->setObjectName("pushButtonFetch");
        pushButtonFetch->setGeometry(QRect(300, 80, 83, 29));

        retranslateUi(ExtraDialog);

        QMetaObject::connectSlotsByName(ExtraDialog);
    } // setupUi

    void retranslateUi(QDialog *ExtraDialog)
    {
        ExtraDialog->setWindowTitle(QCoreApplication::translate("ExtraDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ExtraDialog", "Add Extras", nullptr));
        label_2->setText(QCoreApplication::translate("ExtraDialog", "Reservation No :", nullptr));
        labelCustomerInfo->setText(QString());
        label2->setText(QString());
        label_3->setText(QCoreApplication::translate("ExtraDialog", "Extra Expense :", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("ExtraDialog", "Cancel", nullptr));
        pushButtonOk->setText(QCoreApplication::translate("ExtraDialog", "OK", nullptr));
        pushButtonFetch->setText(QCoreApplication::translate("ExtraDialog", "Fetch", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExtraDialog: public Ui_ExtraDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRADIALOG_H
