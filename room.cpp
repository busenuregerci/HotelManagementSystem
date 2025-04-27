#include "room.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Room::Room(int roomNumber, double dailyRate) : m_roomNumber(roomNumber), m_isOccupied(false), m_dailyRate(dailyRate) {}
Room::Room() : m_roomNumber(0), m_isOccupied(false), m_dailyRate(0.0) {}

// Rooms tablosunu oluşturur
void Room::createRoomTable()
{
    QSqlQuery query(DatabaseManager::instance()->getDatabase());
    QString createTableSql = R"(
        IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='rooms' AND xtype='U')
        BEGIN
            CREATE TABLE rooms (
                roomNumber INT PRIMARY KEY,
                isOccupied BIT NOT NULL,
                dailyRate FLOAT NOT NULL
            )
        END
    )";

    if(!query.exec(createTableSql))
    {
        qDebug() <<"Rooms table is not created: "<<query.lastError().text();
    }
    else
    {
        qDebug() << "Rooms table is created!";
    }
}

// odayı veri tabanına ekler
bool Room::addRoom()
{
    QSqlQuery query(DatabaseManager::instance()->getDatabase());
    query.prepare("INSERT INTO rooms (roomNumber, isOccupied, dailyRate) VALUES (?, ?, ?)");
    query.addBindValue(m_roomNumber);
    query.addBindValue(m_isOccupied);
    query.addBindValue(m_dailyRate);

    if(!query.exec())
    {
        qDebug() << "Room can not added: "<<query.lastError().text();
        return false;
    }
    else
    {
        qDebug() << "Room can added successfully.";
        return true;
    }
}
Room Room::findRoomByRoomNo(int roomNo)
{
    QSqlDatabase db = DatabaseManager::instance()->getDatabase();
    QSqlQuery query(db);
    query.prepare("SELECT roomNumber, isOccupied, dailyRate FROM rooms WHERE roomNumber = ?");
    query.addBindValue(roomNo);

    if (!query.exec()) {
        qDebug() << "Query failed to execute:" << query.lastError().text();
        return Room();  // Boş bir Room nesnesi döndürüyoruz
    }

    Room room; // Default constructor ile boş bir Room nesnesi oluşturuyoruz

    if (query.exec() && query.next()) {
        room.setRoomNumber(query.value(0).toInt());
        room.setIsOccupied(query.value(1).toBool());
        room.setDailyRate(query.value(2).toDouble());

    } else {
        qDebug() << "Room not found for room number:" << roomNo;
    }

    return room; // Room nesnesini döndürüyoruz
}

bool Room::changeRoomStatus()
{
    // Odayı bulalım
    Room room = Room::findRoomByRoomNo(m_roomNumber);

    // Oda bulunamadıysa
    if (room.roomNumber() == 0) {
        qDebug() << "Room not found!";
        return false;
    }

    // Odanın bilgilerini yazdıralım
    qDebug() << "Room found: RoomNumber=" << room.roomNumber() << ", IsOccupied=" << room.isOccupied();

    // Mevcut odanın isOccupied değerini tersine çeviriyoruz
    bool newStatus = !room.isOccupied();

    // Veritabanında güncelleme yapalım
    QSqlDatabase db = DatabaseManager::instance()->getDatabase();
    QSqlQuery query(db);
    query.prepare("UPDATE rooms SET isOccupied = ? WHERE roomNumber = ?");
    query.addBindValue(newStatus);
    query.addBindValue(room.roomNumber());

    if (query.exec()) {
        // Room nesnesinin isOccupied durumunu güncelle
        room.setIsOccupied(newStatus);
        qDebug() << "Room status updated successfully for room number:" << room.roomNumber();
        return true;
    } else {
        qDebug() << "Failed to update room status:" << query.lastError().text();
        return false;
    }
}

void Room::setRoomNumber(int newRoomNumber)
{
    m_roomNumber = newRoomNumber;
}

void Room::setDailyRate(double newDailyRate)
{
    m_dailyRate = newDailyRate;
}

double Room::dailyRate() const
{
    return m_dailyRate;
}
bool Room::isOccupied() const
{
    return m_isOccupied;
}

void Room::setIsOccupied(bool newIsOccupied)
{
    m_isOccupied = newIsOccupied;
}

int Room::roomNumber() const
{
    return m_roomNumber;
}
