/*
 *Erdem Ege Eroðlu
 *21601636
 *CS 201_2
 */
#include "Flight.h"
#include <iostream>
#include <string>
using namespace std;

Flight::Flight(){
    flightNo = 0;
    rowNo = 0;
    seatNo = 0;
    busyNumber = 0;
    resNo=0;
}
Flight::Flight(int flightNo, int rowNo, int seatNo){
    setFlightNo(flightNo);
    setRowtNo(rowNo);
    setSeatNo(seatNo);
}
Flight::~Flight(){

}
void Flight::setFlightNo(int fNo){
    flightNo = fNo;
}
void Flight::setRowtNo(int rNo){
    rowNo = rNo;
}
void Flight::setSeatNo(int sNo){
    seatNo = sNo;
}
void Flight::setResRowList(int* resRow){
    resRowList = resRow;
}
void Flight::setResColList(char* resCol){
    resColList = resCol;
}
void Flight::setBusyNumber(int bNumber){
    busyNumber = bNumber;
}
int Flight::getFlightNo(){
    return flightNo;
}
int Flight::getRowNo(){
    return rowNo;
}
int Flight::getColNo(){
    return seatNo;
}
int Flight::getBusyNumber(){
    return busyNumber;
}
int*& Flight::getResRowList(){
    return resRowList;
}
char*& Flight::getResColList(){
    return resColList;
}
void Flight::setResCode(int* rCode){
    resCode = rCode;
}
int*& Flight::getResCode(){
    return resCode;
}
int Flight::getResNo(){
    return resNo;
}
void Flight::setResNo(int reserN){
    resNo = reserN;
}

