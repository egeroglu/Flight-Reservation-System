#ifndef FLIGHT_H
#define FLIGHT_H
/*
 *Erdem Ege Eroðlu
 *21601636
 *CS 201_2
 */

#include "Reservation.h"

#include <iostream>
#include <string>
using namespace std;

class Flight{
public:
    Flight();
    Flight(int flightNo, int rowNo, int seatNo);
    ~Flight();
    void setFlightNo(int fNo);
    void setRowtNo(int rNo);
    void setSeatNo(int sNo);
    void setBusyNumber(int bNumber);
    void setResNo(int reserN);
    void setResRowList(int* resRow);
    void setResColList(char* resCol);
    void setResCode(int* rCode);

    int getFlightNo();
    int getRowNo();
    int getColNo();
    int getBusyNumber();
    int getResNo();
    int*& getResRowList();
    char*& getResColList();
    int*& getResCode();
private:
    int flightNo;
    int rowNo;
    int seatNo;
    int resNo;
    int busyNumber;
    int* resRowList;
    char* resColList;
    int* resCode;
};
#endif // end of FLIGHT_H
