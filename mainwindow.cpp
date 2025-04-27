#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"room.h"
#include"guesslistdialog.h"
#include"roomsdialog.h"
#include"hotel.h"
#include "extradialog.h"
#include "hotelmanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Veritabanı bağlantısı otomatik açılıyor DatabaseManager sayesinde
   Room::createRoomTable(); // Eğer yoksa room tablosu oluşur
    Hotel::createHotelTable(); // eğer yoksa hotel tablosu oluşur

   // Check-in Butonu
   ui->pbCheckIn->setStyleSheet(
        "QPushButton {"
        "    background-color: #007BFF;"  // Modern mavi
        "    border: none;"
        "    color: white;"
        "    font-size: 20px;"
        "    padding: 12px 24px;"
        "    border-radius: 8px;"
        "    cursor: pointer;"
        "    transition: background-color 0.3s, transform 0.2s;"
        "}"
        "QPushButton:hover {"
        "    background-color: #0056b3;"  // Hover'da daha koyu mavi
        "}"
       );

   // Check-out Butonu
   ui->pbCheckOut->setStyleSheet(
       "QPushButton {"
       "    background-color: #28a745;"  // Yeşil
       "    border: none;"
       "    color: white;"
       "    font-size: 20px;"
       "    padding: 12px 24px;"
       "    border-radius: 8px;"
       "    cursor: pointer;"
       "    transition: background-color 0.3s, transform 0.2s;"
       "}"
       "QPushButton:hover {"
       "    background-color: #218838;"
       "}"
       );

   // Add Extra Butonu
   ui->pbAddExtras->setStyleSheet(
       "QPushButton {"
       "    background-color: #FF6F00;"  // Turuncu
       "    border: none;"
       "    color: white;"
       "    font-size: 20px;"
       "    padding: 12px 24px;"
       "    border-radius: 8px;"
       "    cursor: pointer;"
       "    transition: background-color 0.3s, transform 0.2s;"
       "}"
       "QPushButton:hover {"
       "    background-color: #e65c00;"
       "}"
       );

   // Show Guest List Butonu
   ui->pbShowGuessList->setStyleSheet(
       "QPushButton {"
       "    background-color: #9C27B0;"  // Mor
       "    border: none;"
       "    color: white;"
       "    font-size: 20px;"
       "    padding: 12px 24px;"
       "    border-radius: 8px;"
       "    cursor: pointer;"
       "    transition: background-color 0.3s, transform 0.2s;"
       "}"
       "QPushButton:hover {"
       "    background-color: #8E24AA;"
       "}"
       );

/*
    Room oda1(101, 150.0);
    oda1.addRoom();

    Room oda2(102, 180.0);
    oda2.addRoom();

    Room oda3(103, 200.0);
    oda3.addRoom();

    Room oda4(104, 220.0);
    oda4.addRoom();

    Room oda5(201, 230.0);
    oda5.addRoom();

    Room oda6(202, 230.0);
    oda6.addRoom();

    Room oda7(203, 550.0);
    oda7.addRoom();
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbShowGuessList_clicked()
{
    // GuessListDialog'u oluşturuyoruz ve gösteriyoruz
    GuessListDialog *dialog = new GuessListDialog(this);
    dialog->exec();
    dialog->deleteLater();

}


void MainWindow::on_pbCheckIn_clicked()
{
    RoomsDialog *dialog = new RoomsDialog(CheckIn, this);
    dialog->exec();
    dialog->deleteLater();
}


void MainWindow::on_pbCheckOut_clicked()
{
    RoomsDialog *dialog = new RoomsDialog(CheckOut, this);
    dialog->exec();
    dialog->deleteLater();

}


void MainWindow::on_pbAddExtras_clicked()
{
    ExtraDialog *dialog = new ExtraDialog(this);
    dialog->exec();
    dialog->deleteLater();

}

