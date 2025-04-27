#ifndef HOTELMANAGER_H
#define HOTELMANAGER_H

#include <QList>
#include "hotel.h"

class HotelManager
{
public:
    static QList<Hotel> getGuessList();
   static Hotel findGuestByReservationId(int reservationId);

    static HotelManager hotelManager();

private:
    static QList<Hotel> m_guests;
    static HotelManager m_hotelManager;
};

#endif // HOTELMANAGER_H
