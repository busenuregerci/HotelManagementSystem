#include "hotelmanager.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include"hotel.h"

QList<Hotel> HotelManager::m_guests;

QList<Hotel> HotelManager::getGuessList()
{
    QList<Hotel> guessList;
    QSqlDatabase db = DatabaseManager::instance()->getDatabase();
    QSqlQuery query(db);

    // TotalFee = 0 olanları sorgula yani hala hotelde olan konuklar
    query.prepare("SELECT reservationId, customerName, roomNo FROM hotel WHERE totalFee = 0");
    if (!query.exec()) {
        qDebug() << "Unable to retrieve guess list:" << query.lastError().text();
        return guessList; // Eğer hata varsa boş liste döneriz
    }

    while (query.next()) {
        int reservationId = query.value(0).toInt();   // bunu kullanacağız
        QString customerName = query.value(1).toString();
        int roomNo = query.value(2).toInt();

        // Yeni nesne oluştur (Artık sadece customerName ve roomNo kullanıyoruz)
        Hotel guest(customerName,roomNo);
        guest.setReservationId(reservationId); // set metodu ile atıyoruz

        guessList.append(guest);
    }

    return guessList;
}

Hotel HotelManager::findGuestByReservationId(int reservationId)
{
    QSqlQuery query;
    query.prepare("SELECT CustomerName, RoomNo, ReservationId FROM hotel WHERE ReservationId = :reservationId");
    query.bindValue(":reservationId", reservationId);

    if (query.exec()) {
        if (query.next()) {
            // Veritabanından müşteri bilgilerini alıyoruz
            QString customerName = query.value("CustomerName").toString();
            int roomNo = query.value("RoomNo").toInt();
            int foundReservationId = query.value("ReservationId").toInt(); // reservationId'yi buradan alıyoruz

            // ReservationId'yi dışarıda tutarak, sadece customerName ve roomNo ile Hotel nesnesi döndürüyoruz
            Hotel guest(customerName, roomNo);
            guest.setReservationId(foundReservationId); // reservationId'yi burada ayarlıyoruz
            return guest;
        } else {
            qDebug() << "HotelManager::findGuestByReservationId - No guest found for ReservationId:" << reservationId;
        }
    } else {
        qDebug() << "HotelManager::findGuestByReservationId - Error executing query:" << query.lastError().text();
    }

    return Hotel("", 0); // Eğer misafir bulunmazsa, boş bir Hotel döndürüyoruz
}

HotelManager HotelManager::hotelManager()
{
    return m_hotelManager;
}
