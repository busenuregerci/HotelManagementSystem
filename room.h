#ifndef ROOM_H
#define ROOM_H

class Room
{
public:
    Room(int roomNumber, double dailyRate);
    Room();
    static void createRoomTable(); // Rooms tablosunu oluşturmak için
    bool addRoom(); // bu nesnenin odasını veri tabanına ekler

    bool isOccupied() const;
    void setIsOccupied(bool newIsOccupied);

    int roomNumber() const;
    static Room findRoomByRoomNo(int roomNo);
    bool changeRoomStatus();

    void setRoomNumber(int newRoomNumber);

    void setDailyRate(double newDailyRate);

    double dailyRate() const;

private:
    int m_roomNumber; // oda numarası primary key
    bool m_isOccupied; // oda dolu mu boş mu
    double m_dailyRate; // günlük ücret
};

#endif // ROOM_H
