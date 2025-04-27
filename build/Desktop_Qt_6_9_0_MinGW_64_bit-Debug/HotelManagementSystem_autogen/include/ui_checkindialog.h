/********************************************************************************
** Form generated from reading UI file 'checkindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKINDIALOG_H
#define UI_CHECKINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CheckInDialog
{
public:
    QLabel *labelRoomNo;
    QLineEdit *lineEditCustomerName;
    QLabel *label;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *CheckInDialog)
    {
        if (CheckInDialog->objectName().isEmpty())
            CheckInDialog->setObjectName("CheckInDialog");
        CheckInDialog->resize(400, 233);
        labelRoomNo = new QLabel(CheckInDialog);
        labelRoomNo->setObjectName("labelRoomNo");
        labelRoomNo->setGeometry(QRect(40, 10, 321, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setPointSize(18);
        labelRoomNo->setFont(font);
        labelRoomNo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEditCustomerName = new QLineEdit(CheckInDialog);
        lineEditCustomerName->setObjectName("lineEditCustomerName");
        lineEditCustomerName->setGeometry(QRect(150, 110, 241, 31));
        label = new QLabel(CheckInDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 110, 121, 20));
        cancelButton = new QPushButton(CheckInDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(180, 180, 91, 29));
        okButton = new QPushButton(CheckInDialog);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(282, 180, 111, 29));

        retranslateUi(CheckInDialog);

        QMetaObject::connectSlotsByName(CheckInDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckInDialog)
    {
        CheckInDialog->setWindowTitle(QCoreApplication::translate("CheckInDialog", "Dialog", nullptr));
        labelRoomNo->setText(QCoreApplication::translate("CheckInDialog", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("CheckInDialog", "Customer Name :", nullptr));
        cancelButton->setText(QCoreApplication::translate("CheckInDialog", "Cancel", nullptr));
        okButton->setText(QCoreApplication::translate("CheckInDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckInDialog: public Ui_CheckInDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKINDIALOG_H
