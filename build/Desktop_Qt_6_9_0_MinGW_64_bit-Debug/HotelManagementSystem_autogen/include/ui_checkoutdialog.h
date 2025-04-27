/********************************************************************************
** Form generated from reading UI file 'checkoutdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTDIALOG_H
#define UI_CHECKOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CheckOutDialog
{
public:
    QLabel *labelRoomNo;
    QLabel *label;
    QLineEdit *lineEditReservationId;
    QLabel *label_3;
    QLabel *labelCustomerName;
    QLineEdit *lineEditTotalDays;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *labelTotalFee;
    QPushButton *pushButton;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonFetch;

    void setupUi(QDialog *CheckOutDialog)
    {
        if (CheckOutDialog->objectName().isEmpty())
            CheckOutDialog->setObjectName("CheckOutDialog");
        CheckOutDialog->resize(426, 300);
        labelRoomNo = new QLabel(CheckOutDialog);
        labelRoomNo->setObjectName("labelRoomNo");
        labelRoomNo->setGeometry(QRect(40, 20, 321, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setPointSize(18);
        labelRoomNo->setFont(font);
        labelRoomNo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(CheckOutDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 70, 151, 20));
        lineEditReservationId = new QLineEdit(CheckOutDialog);
        lineEditReservationId->setObjectName("lineEditReservationId");
        lineEditReservationId->setGeometry(QRect(180, 70, 141, 28));
        label_3 = new QLabel(CheckOutDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 110, 121, 20));
        labelCustomerName = new QLabel(CheckOutDialog);
        labelCustomerName->setObjectName("labelCustomerName");
        labelCustomerName->setGeometry(QRect(160, 110, 241, 21));
        lineEditTotalDays = new QLineEdit(CheckOutDialog);
        lineEditTotalDays->setObjectName("lineEditTotalDays");
        lineEditTotalDays->setGeometry(QRect(170, 150, 201, 28));
        label_5 = new QLabel(CheckOutDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(80, 150, 91, 20));
        label_4 = new QLabel(CheckOutDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(230, 190, 71, 20));
        labelTotalFee = new QLabel(CheckOutDialog);
        labelTotalFee->setObjectName("labelTotalFee");
        labelTotalFee->setGeometry(QRect(310, 190, 71, 20));
        pushButton = new QPushButton(CheckOutDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 190, 121, 29));
        pushButtonOk = new QPushButton(CheckOutDialog);
        pushButtonOk->setObjectName("pushButtonOk");
        pushButtonOk->setGeometry(QRect(290, 240, 121, 41));
        pushButtonCancel = new QPushButton(CheckOutDialog);
        pushButtonCancel->setObjectName("pushButtonCancel");
        pushButtonCancel->setGeometry(QRect(190, 240, 91, 41));
        pushButtonFetch = new QPushButton(CheckOutDialog);
        pushButtonFetch->setObjectName("pushButtonFetch");
        pushButtonFetch->setGeometry(QRect(330, 70, 83, 29));

        retranslateUi(CheckOutDialog);

        QMetaObject::connectSlotsByName(CheckOutDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckOutDialog)
    {
        CheckOutDialog->setWindowTitle(QCoreApplication::translate("CheckOutDialog", "Dialog", nullptr));
        labelRoomNo->setText(QCoreApplication::translate("CheckOutDialog", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("CheckOutDialog", "Reservation Number :", nullptr));
        label_3->setText(QCoreApplication::translate("CheckOutDialog", "Customer Name :", nullptr));
        labelCustomerName->setText(QString());
        label_5->setText(QCoreApplication::translate("CheckOutDialog", "Total Days :", nullptr));
        label_4->setText(QCoreApplication::translate("CheckOutDialog", "Total Fee :", nullptr));
        labelTotalFee->setText(QString());
        pushButton->setText(QCoreApplication::translate("CheckOutDialog", "Calculate Fee", nullptr));
        pushButtonOk->setText(QCoreApplication::translate("CheckOutDialog", "OK", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("CheckOutDialog", "Cancel", nullptr));
        pushButtonFetch->setText(QCoreApplication::translate("CheckOutDialog", "Fetch", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckOutDialog: public Ui_CheckOutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTDIALOG_H
