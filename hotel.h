
#ifndef HOTEL_H
#define HOTEL_H
#include<QString>

// Bu sınıf rezervasyon bilgilerini tutar ve yönetir
class Hotel
{
public:
    Hotel(const QString& customerName, int roomNo);

    static void createHotelTable(); // hotel yani reservation tablosunu oluşturu
    bool checkIn(); // Check-in işlemi: rezervasyon ekle + oda durumunu güncelle
    bool checkOut(double extraExpenses, double totalFee); // check-out işlemi: faturayı hesapla ve odayı boşalt
    int reservationId() const;
    QString customerName() const;
    int roomNo() const;
    double extraExpenses(int reservationId) const;
    double totalFee() const;

    void setReservationId(int newReservationId);
    void setCustomerName(const QString &newCustomerName);
    void setRoomNo(int newRoomNo);
    void setExtraExpenses(double newExtraExpenses);
    void setTotalFee(double newTotalFee);

private:
    int m_reservationId;
    QString m_customerName;
    int m_roomNo;
    double m_extraExpenses = 0.0;
    double m_totalFee = 0.0;
};

#endif // HOTEL_H

