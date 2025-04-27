#include "extradialog.h"
#include "ui_extradialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include "hotel.h"
#include "hotelmanager.h"

ExtraDialog::ExtraDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExtraDialog)
{
    ui->setupUi(this);
}

ExtraDialog::~ExtraDialog()
{
    delete ui;
}


void ExtraDialog::on_pushButtonOk_clicked()
{
    if (m_reservationId == 0) {
        QMessageBox::warning(this, "Warning", "Please fetch a valid reservation first.");
        return;
    }

    QString extraText = ui->lineEditExtra->text().trimmed();
    if (extraText.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter an extra amount.");
        return;
    }

    bool ok;
    double extraAmount = extraText.toDouble(&ok);
    if (!ok || extraAmount < 0) {
        QMessageBox::warning(this, "Warning", "Invalid extra amount.");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE hotel SET ExtraExpenses = ExtraExpenses + ? WHERE ReservationId = ?");
    query.addBindValue(extraAmount);
    query.addBindValue(m_reservationId);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Extra expenses updated successfully!");
        accept();
    } else {
        QMessageBox::warning(this, "Error", "Failed to update extra expenses.");
        qDebug() << "SQL Error:" << query.lastError().text();
    }
}

void ExtraDialog::on_pushButtonCancel_clicked()
{
    reject();
}

void ExtraDialog::on_pushButtonFetch_clicked()
{
    QString idText = ui->lineEditReservationNo->text().trimmed();
    qDebug() << "Reservation ID Text: " << idText;  // idText'in doğru şekilde alındığını kontrol et
    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a Reservation ID.");
        return;
    }

    bool ok;
    int reservationId = idText.toInt(&ok);
    qDebug() << "Parsed Reservation ID: " << reservationId;  // reservationId'nin doğru şekilde parse edilip edilmediğini kontrol et
    if (!ok) {
        QMessageBox::warning(this, "Warning", "Invalid Reservation ID format.");
        return;
    }

    // HotelManager'dan rezervasyonu bul
    Hotel guest = HotelManager::findGuestByReservationId(reservationId);
    if (guest.customerName().isEmpty()) {
        QMessageBox::warning(this, "Error", "Reservation not found.");
        ui->labelCustomerInfo->clear(); // Buraya müşteri bilgisi yazıyorsun ya, label'ı boşalt
        m_reservationId = 0;
    } else {
        QString info = QString("Customer: %1 | Room No: %2").arg(guest.customerName()).arg(guest.roomNo());
        ui->labelCustomerInfo->setText(info); // Müşteri bilgilerini label'a yaz
        m_reservationId = reservationId;
    }
}

