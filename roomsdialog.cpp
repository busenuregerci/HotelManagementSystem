#include "roomsdialog.h"
#include "ui_roomsdialog.h"
#include"checkindialog.h"
#include"checkoutdialog.h"
#include<QSqlDatabase>
#include"databasemanager.h"
#include<QSqlQuery>
#include<QSqlError>

RoomsDialog::RoomsDialog(OperationMode mode, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoomsDialog)
    , m_mode(mode)
{
    ui->setupUi(this);
    // Bütün butonlara property verelim
    ui->pb101->setProperty("roomNo", 101);
    ui->pb102->setProperty("roomNo", 102);
    ui->pb103->setProperty("roomNo", 103);
    ui->pb104->setProperty("roomNo", 104);
    ui->pb201->setProperty("roomNo", 201);
    ui->pb202->setProperty("roomNo", 202);
    ui->pb203->setProperty("roomNo", 203);

    // Hepsine aynı slotu bağla
    connect(ui->pb101, &QPushButton::clicked, this, &RoomsDialog::handleRoomButtonClicked);
    connect(ui->pb102, &QPushButton::clicked, this, &RoomsDialog::handleRoomButtonClicked);
    connect(ui->pb103, &QPushButton::clicked, this, &RoomsDialog::handleRoomButtonClicked);
    connect(ui->pb104, &QPushButton::clicked, this, &RoomsDialog::handleRoomButtonClicked);
    connect(ui->pb201, &QPushButton::clicked, this, &RoomsDialog::handleRoomButtonClicked);
    connect(ui->pb202, &QPushButton::clicked, this, &RoomsDialog::handleRoomButtonClicked);
    connect(ui->pb203, &QPushButton::clicked, this, &RoomsDialog::handleRoomButtonClicked);

     updateRoomButtons();
}

RoomsDialog::~RoomsDialog()
{
    delete ui;
}

void RoomsDialog::handleRoomButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button)
        return;

    int roomNo = button->property("roomNo").toInt();

    if (m_mode == CheckIn) {
        CheckInDialog *checkInDialog = new CheckInDialog(roomNo, this, this);
        checkInDialog->exec();
    } else if (m_mode == CheckOut) {
        CheckOutDialog *checkOutDialog = new CheckOutDialog(roomNo, this, this);
        checkOutDialog->exec();
    }
}

bool RoomsDialog::isRoomOccupied(int roomNo) {
    // Oda numarasına göre veritabanından doluluk durumunu kontrol et
    QSqlDatabase db = DatabaseManager::instance()->getDatabase();
    QSqlQuery query(db);
    query.prepare("SELECT isOccupied FROM rooms WHERE roomNumber = ?");
    query.addBindValue(roomNo);

    if (!query.exec()) {
        qDebug() << "Query failed to execute:" << query.lastError().text();
        return false;  // Eğer sorgu hatalıysa varsayılan olarak oda boş kabul edilir.
    }

    if (query.next()) {
        return query.value(0).toBool();  // isOccupied sütununu kontrol et
    }

    return false;  // Oda bulunmazsa boş kabul edilir.
}
void RoomsDialog::updateRoomButtons()
{
    // Oda butonlarını duruma göre renklendir
    QPushButton* buttons[] = {ui->pb101, ui->pb102, ui->pb103, ui->pb104, ui->pb201, ui->pb202, ui->pb203};

    for (QPushButton* button : buttons) {
        int roomNo = button->property("roomNo").toInt();

        // Odanın doluluk durumunu kontrol et
        bool isOccupied = isRoomOccupied(roomNo);

        if (m_mode == CheckIn) {
            // Check-in modunda, dolu odalar kırmızı, boş odalar yeşil
            if (isOccupied) {
                button->setStyleSheet("background-color: #FF5733; color: white;");  // Kırmızı
                button->setEnabled(false);  // Dolu odalar tıklanamaz
            } else {
                button->setStyleSheet("background-color: #28a745; color: white;");  // Yeşil
                button->setEnabled(true);  // Boş odalar tıklanabilir
            }
        } else if (m_mode == CheckOut) {
            // Check-out modunda, sadece dolu odalar tıklanabilir
            if (isOccupied) {
                button->setStyleSheet("background-color: #FF5733; color: white;");  // Kırmızı
                button->setEnabled(true);  // Dolu odalar tıklanabilir
            } else {
                button->setStyleSheet("background-color: #d3d3d3; color: gray;");  // Gri
                button->setEnabled(false);  // Boş odalar tıklanamaz
            }
        }
    }

}
