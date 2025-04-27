#include "checkindialog.h"
#include "ui_checkindialog.h"
#include<QMessageBox>
#include"hotel.h"
#include<QSqlQuery>
#include"roomsdialog.h"

CheckInDialog::CheckInDialog(int roomNo, RoomsDialog* roomsDialog, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CheckInDialog)
    , m_roomNo(roomNo)
    , m_roomsDialog(roomsDialog)
{
    ui->setupUi(this);
    ui->labelRoomNo->setText(QString("Room No: %1").arg(roomNo));
}

CheckInDialog::~CheckInDialog()
{
    delete ui;
}

void CheckInDialog::on_cancelButton_clicked()
{
    reject();
}


void CheckInDialog::on_okButton_clicked()
{
    QString customerName = ui->lineEditCustomerName->text().trimmed();

    if (customerName.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Customer name can not be empty!");
        return;
    }

    // Hotel objesini oluştur
    Hotel hotel(customerName, m_roomNo);

    // Hotel::checkIn() metodunu çağırıyoruz
    if (hotel.checkIn())
    {
        QMessageBox::information(this, "Check-In Successful", "Reservation ID:  " + QString::number(hotel.reservationId()));

        // Check-in başarılıysa RoomsDialog'daki butonları güncelle
        if (m_roomsDialog) {
            m_roomsDialog->updateRoomButtons();
        }

        accept(); // Dialog'u kapat
    }
    else
    {
        QMessageBox::warning(this, "Error", "Failed to insert new reservation!");
    }
}



