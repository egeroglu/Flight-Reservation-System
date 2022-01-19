/*
 *Erdem Ege Eroðlu
 *21601636
 *CS 201_2
 */
#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>

using namespace std;

class Reservation{
public:
    Reservation();
    Reservation(int resCode);
    ~Reservation();
    void setReservationCode(int resCode);
    int getReservationCode();
private:
    int reservationCode;
};

#endif // RESERVATION_H
