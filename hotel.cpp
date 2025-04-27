
#include "hotel.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include"room.h"

Hotel::Hotel(const QString& customerName, int roomNo)
    : m_customerName(customerName), m_roomNo(roomNo)
{
}

// veritabanına hotel tablosunu oluşturur
void Hotel::createHotelTable()
{
    QSqlQuery query(DatabaseManager::instance()->getDatabase());
    QString createTableSql = R"(IF NOT EXISTS(SELECT * FROM sysobjects WHERE name='hotel' and xtype='U')
    BEGIN
        CREATE TABLE hotel(
            reservationId INT IDENTITY(1,1) PRIMARY KEY,
            customerName NVARCHAR(255) NOT NULL,
            roomNo INT NOT NULL,
            extraExpenses FLOAT NOT NULL,
            totalFee FLOAT NOT NULL
        )
    END
)";

    if(!query.exec(createTableSql))
    {
        qDebug() << "Hotel table is not created: " << query.lastError().text();
    }
    else
    {
        qDebug() << "Hotel table is successfully created.";
    }
}

bool Hotel::checkIn()
{
    // Odayı occupied olarak işaretle
    Room room = Room::findRoomByRoomNo(m_roomNo);  // Odayı bul
    if (!room.changeRoomStatus()) {
        qDebug() << "Failed to change room status during check-in!";
        return false;
    }

    // Rezervasyonu ekleyelim
    QSqlQuery query;
    query.prepare("INSERT INTO hotel (customerName, roomNo, extraExpenses, totalFee) "
                  "VALUES (?, ?, ?, ?)");
    query.addBindValue(m_customerName);
    query.addBindValue(m_roomNo);
    query.addBindValue(m_extraExpenses);
    query.addBindValue(m_totalFee);

    if (!query.exec()) {
        qDebug() << "Failed to insert reservation:" << query.lastError().text();
        return false;
    }

    // ReservationId'yi alalım
    m_reservationId = query.lastInsertId().toInt();
    qDebug() << "Check-in successful for Reservation ID:" << m_reservationId;
    return true;
}


bool Hotel::checkOut(double extraExpenses, double totalFee)
{
    // Odayı boş olarak işaretle
    Room room = Room::findRoomByRoomNo(m_roomNo);  // Odayı bul
    if (!room.changeRoomStatus()) {  // false parametresi ile oda boş yapılıyor
        qDebug() << "Failed to change room status during check-out!";
        return false;
    }

    // Oda için ekstra ücret ve toplam ücreti güncelleme işlemleri
    QSqlQuery query;
    query.prepare("UPDATE hotel SET extraExpenses = ?, totalFee = ? WHERE reservationId = ?");
    query.addBindValue(extraExpenses);  // Parametreleri kullanıyoruz
    query.addBindValue(totalFee);
    query.addBindValue(m_reservationId);

    if (!query.exec()) {
        qDebug() << "Failed to update reservation:" << query.lastError().text();
        return false;
    }

    qDebug() << "Check-out completed successfully for Reservation ID:" << m_reservationId;
    return true;
}



int Hotel::reservationId() const
{
    return m_reservationId;
}

QString Hotel::customerName() const
{
    return m_customerName;
}

int Hotel::roomNo() const
{
    return m_roomNo;
}

double Hotel::extraExpenses(int reservationId) const
{
    QSqlDatabase db = DatabaseManager::instance()->getDatabase();
    QSqlQuery query(db);
    query.prepare("SELECT extraExpenses FROM hotel WHERE reservationId = ?");
    query.addBindValue(reservationId);

    // Sorguyu çalıştırıyoruz
    if (!query.exec()) {
        qDebug() << "Query failed to execute:" << query.lastError().text();
        return 0;  // Eğer sorgu başarısızsa 0 döndürüyoruz
    }

    // Eğer sorgu başarılıysa ve sonuç varsa
    if (query.next()) {
        // extraExpense değerini alıyoruz
        double extraExpense = query.value(0).toDouble();
        return extraExpense;  // extraExpense değerini döndürüyoruz
    } else {
        // Eğer sonuç bulunamadıysa
        qDebug() << "No extra expenses found for reservationId:" << reservationId;
        return 0;  // Bulunamadıysa 0 döndürüyoruz
    }

}

double Hotel::totalFee() const
{
    return m_totalFee;
}

void Hotel::setReservationId(int newReservationId)
{
    m_reservationId = newReservationId;
}

void Hotel::setCustomerName(const QString &newCustomerName)
{
    m_customerName = newCustomerName;
}

void Hotel::setRoomNo(int newRoomNo)
{
    m_roomNo = newRoomNo;
}

void Hotel::setExtraExpenses(double newExtraExpenses)
{
    m_extraExpenses = newExtraExpenses;
}

void Hotel::setTotalFee(double newTotalFee)
{
    m_totalFee = newTotalFee;
}



