/*
 *Erdem Ege Eroðlu
 *21601636
 *CS 201_2
 */
#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include "Flight.h"
#include <iostream>
#include <string>
using namespace std;

class ReservationSystem
{
public:
    ReservationSystem();
    ~ReservationSystem();
    void addFlight( const int flightNo, const int rowNo, const int seatNo );
    void cancelFlight( const int flightNo );
    void showAllFlights();
    void showFlight( const int flightNo );
    int makeReservation( const int flightNo, const int numPassengers,
                         const int *seatRow, const char *seatCol );
    void cancelReservation( const int resCode );
    void showReservation( const int resCode );
// ...
// you may define additional member functions and data members, if necessary.
    void cancelRezWOMessage( const int resCode);
    void cancelFlightWOMessage(const int flightNo);
private:
    int numberOfFlights;
    int reservationNumber;
    Flight* flightList;
};
#endif //end of RESERVATIONSYSTEM_H
