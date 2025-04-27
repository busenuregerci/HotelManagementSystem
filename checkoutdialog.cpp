#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"
#include"hotel.h"
#include"hotelmanager.h"
#include <QMessageBox>
#include "room.h"
//♥

CheckOutDialog::CheckOutDialog(int roomNo, RoomsDialog* roomsDialog, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CheckOutDialog)
    , m_roomNo(roomNo)
    , m_roomsDialog(roomsDialog)
{
    ui->setupUi(this);
    ui->labelRoomNo->setText(QString("Room No: %1").arg(roomNo));
}

CheckOutDialog::~CheckOutDialog()
{
    delete ui;
}


void CheckOutDialog::on_pushButtonFetch_clicked()
{
    QString idText = ui->lineEditReservationId->text().trimmed();
    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a Reservation ID.");
        return;
    }

    bool ok;
    int reservationId = idText.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Warning", "Invalid Reservation ID format.");
        return;
    }

    // Veritabanında sorgu yapıyoruz
    Hotel guest = HotelManager::findGuestByReservationId(reservationId);

    if (guest.customerName().isEmpty()) {
        QMessageBox::warning(this, "Error", "No reservation found for this ID.");
        ui->labelCustomerName->clear();
        return;
    }

    // Odanın numarasını kontrol ediyoruz
    if (guest.roomNo() != m_roomNo) {
        QMessageBox::warning(this, "Error", "This guest is not assigned to the selected room.");
        return;
    }

    // Rezervasyon bulundu ve oda eşleşti
    QString info = QString(" %1 ").arg(guest.customerName()).arg(guest.roomNo());
    ui->labelCustomerName->setText(info);  // Müşteri bilgilerini label'a yazıyoruz
}


void CheckOutDialog::on_pushButton_clicked()
{
    bool ok;
    // Gün sayısını alıyoruz
    int days = ui->lineEditTotalDays->text().toInt(&ok);
    if (!ok || days <= 0) {
        QMessageBox::warning(this, "Error", "Please enter a valid number of days.");
        return;
    }

    // Odanın numarasını alıyoruz
    int roomNumber = m_roomNo; // Odanın numarasını, daha önce seçtiğimiz odadan alıyoruz

    // Room nesnesi ile odanın detaylarını alıyoruz
    Room room = Room::findRoomByRoomNo(roomNumber);

    if (room.roomNumber() == 0) { // Eğer oda bulunamadıysa
        QMessageBox::warning(this, "Error", "Room not found.");
        return;
    }

    // Odanın günlük ücretini alıyoruz
    double dailyRate = room.dailyRate();
    QString idText = ui->lineEditReservationId->text().trimmed();
    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a Reservation ID.");
        return;
    }
    bool ok2;
    int reservationId = idText.toInt(&ok2);
    m_reservationId = reservationId;
    if (!ok) {
        QMessageBox::warning(this, "Warning", "Invalid Reservation ID format.");
        return;
    }

    // Hotel nesnesi ile rezervasyon bilgilerini alıyoruz
    Hotel guest = HotelManager::findGuestByReservationId(m_reservationId); // m_reservationId'yi daha önceki işlemden alıyoruz
    guest.setReservationId(reservationId);
    if (guest.reservationId() == 0) { // Eğer misafir bulunamadıysa
        QMessageBox::warning(this, "Error", "Guest not found.");
        return;
    }

    // Misafirin ekstra ücretini alıyoruz
    double extraExpenses = guest.extraExpenses(reservationId);

    // Toplam ücreti hesaplıyoruz
    double totalFee = (dailyRate * days) + extraExpenses;

    // Toplam ücreti label'da gösteriyoruz
    ui->labelTotalFee->setText(QString::number(totalFee));
}


void CheckOutDialog::on_pushButtonOk_clicked()
{
    QString idText = ui->lineEditReservationId->text().trimmed();
    bool ok;
    int reservationId = idText.toInt(&ok);
    m_reservationId = reservationId;
    if (idText.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Reservation Id can not be empty!");
        return;
    }

    Hotel guest = HotelManager::findGuestByReservationId(m_reservationId); // m_reservationId'yi daha önceki işlemden alıyoruz
    guest.setReservationId(reservationId);
    if (guest.reservationId() == 0) { // Eğer misafir bulunamadıysa
        QMessageBox::warning(this, "Error", "Guest not found.");
        return;
    }
    double extraExpense = guest.extraExpenses(m_reservationId);
    QString totalFeeText = ui->labelTotalFee->text().trimmed();
    bool ok2;
    double totalFee = totalFeeText.toDouble(&ok2);
    if (totalFeeText.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "You can not continue without calculating total fee!");
        return;
    }

    if (guest.checkOut(extraExpense,totalFee))
    {
        QMessageBox::information(this, "Check-Out Successful","See you again!");
        // Check-out başarılıysa RoomsDialog'daki butonları güncelle
        if (m_roomsDialog) {
            m_roomsDialog->updateRoomButtons();
        }
        // Dialog'u kapat
        accept();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Failed to insert checkout!");
    }
}

