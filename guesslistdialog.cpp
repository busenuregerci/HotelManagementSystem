#include "guesslistdialog.h"
#include "ui_guesslistdialog.h"
#include "hotel.h"
#include "hotelmanager.h"
#include <QTableWidget>
#include <QVBoxLayout>

GuessListDialog::GuessListDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GuessListDialog)
{
    ui->setupUi(this);

    // QTableWidget nesnesine sütunları ekliyoruz
    ui->tableWidget->setColumnCount(3); // 3 sütun olacak: Ad Soyad, Oda No, Rezervasyon ID
    ui->tableWidget->setHorizontalHeaderLabels({"Customer Name", "Room No", "Reservation ID"});

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true); // Son sütunu genişlet

    updateGuessList(); // İlk başta misafir listesi güncelle
}

GuessListDialog::~GuessListDialog()
{
    delete ui;
}

void GuessListDialog::updateGuessList()
{
    // Misafir listesini alıyoruz
    QList<Hotel> guessList = HotelManager::getGuessList();

    // Tabloyu temizliyoruz
    ui->tableWidget->setRowCount(0);

    // Her misafiri tablonun bir satırına ekliyoruz
    for (const Hotel &guest : guessList) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Misafirin bilgilerini tablonun hücrelerine yerleştiriyoruz
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(guest.customerName())); // Müşteri adı
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(guest.roomNo()))); // Oda numarası
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(guest.reservationId()))); // Rezervasyon ID'si
    }

    // Sütunları ve satırları içeriklere göre otomatik boyutlandırıyoruz
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}
