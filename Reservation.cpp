/*
 *Erdem Ege Eroðlu
 *21601636
 *CS 201_2
 */

#include "Reservation.h"
#include <iostream>
#include <string>
using namespace std;

Reservation::Reservation(){
    reservationCode = 0;
}
Reservation::~Reservation(){

}
Reservation::Reservation(int resCode){
    setReservationCode(resCode);
}
void Reservation::setReservationCode(int resCode){
    reservationCode = resCode;
}
int Reservation::getReservationCode(){
    return reservationCode;
}
