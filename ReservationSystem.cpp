/*
 *Erdem Ege Eroðlu
 *21601636
 *CS 201_2
 */
#include "ReservationSystem.h"

#include <string>
#include <iostream>
using namespace std;

ReservationSystem::ReservationSystem()
{
    reservationNumber = 0;
    numberOfFlights = 0;
    flightList = NULL;
}
ReservationSystem::~ReservationSystem()
{
    if(numberOfFlights!=0)
    {
        int start = 0;
        for(int i =0; i < numberOfFlights; i++)
        {
            cancelFlightWOMessage(flightList[start].getFlightNo());
        }
        if(flightList != NULL)
        {
            delete [] flightList;
            flightList = NULL;
        }
    }

}
void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo )
{
    for(int i =0; i < numberOfFlights; i++)
    {
        if(flightNo==flightList[i].getFlightNo())
        {
            cout<<"Flight "<<flightNo<<" already exists"<<endl;
            cout<<endl;
            return;
        }
    }
    if( rowNo <= 0 && seatNo <= 0 )
    {
        cout<<"Row and Seat number should be positive integers"<<endl;
        return;
    }
    Flight* temp = new Flight[numberOfFlights+1];
    for(int i = 0; i<numberOfFlights; i++)
    {
        temp[i] = flightList[i];
    }
    delete [] flightList;
    temp[numberOfFlights].setFlightNo(flightNo);
    temp[numberOfFlights].setRowtNo(rowNo);
    temp[numberOfFlights].setSeatNo(seatNo);
    temp[numberOfFlights].setResNo(0);

    flightList = temp;
    cout<<"Flight "<<flightNo<<" has been added"<<endl;

    numberOfFlights++;
}
void ReservationSystem::cancelFlight( const int flightNo )
{
    int location = -1;
    bool exist = false;
    for(int i = 0; i < numberOfFlights; i++)
    {
        if(flightNo==flightList[i].getFlightNo())
        {
            exist = true;
            location = i;
        }
    }
    if(!exist)
    {
        cout<<"Flight "<< flightNo<<" does not exist"<<endl;
        return;
    }
    numberOfFlights--;
    Flight* newList = new Flight[numberOfFlights];
    for(int i = 0; i<location; i++)
    {
        newList[i] = flightList[i];
    }
    for(int i= location; i < numberOfFlights; i++)
    {
        newList[i] = flightList[i+1];
    }


    for(int i =0; i<newList[location].getBusyNumber(); i++)
    {
        cancelRezWOMessage(flightList[location].getResCode()[i]);
    }
    if(flightList != NULL)
    {
        delete [] flightList;
    }

    if(flightList[location].getBusyNumber() > 0)
    {
        int *resCodeNew = flightList[location].getResCode();
        delete [] resCodeNew;
        resCodeNew = NULL;
    }

    if(flightList[location].getBusyNumber() > 0)
    {
        char *resColNew = flightList[location].getResColList();
        delete [] resColNew;
        resColNew = NULL;

    }
    if(flightList[location].getBusyNumber() > 0)
    {
        int *resRowNew = flightList[location].getResRowList();
        delete [] resRowNew;
        resRowNew = NULL;
    }
    flightList[location].setBusyNumber(0);

    flightList = new Flight[numberOfFlights];
    for(int i = 0; i<numberOfFlights; i++)
    {
        flightList[i] = newList[i];
    }

    delete [] newList;
    newList = NULL;
    cout<<"Flight "<< flightNo<<" and all of its reservations are canceled"<<endl;
    cout<<endl;
}
void ReservationSystem::showAllFlights()
{
    if(numberOfFlights < 1)
    {
        cout<<"No flight exist"<<endl;
    }
    else
    {
        cout<<"Flights currently operated: "<<endl;
        for(int i = 0; i<numberOfFlights; i++)
        {
            cout<<"Flight "<<flightList[i].getFlightNo()<<" ("<<(flightList[i].getRowNo())*(flightList[i].getColNo())-(flightList[i].getBusyNumber())<<" available seats)"<<endl;
        }
    }
    cout<<endl;
}

void ReservationSystem::showFlight( const int flightNo )
{
    int location = -1;
    for(int i =0; i<numberOfFlights; i++)
        if(flightNo==flightList[i].getFlightNo())
            location = i;
    if(location<0)
    {
        cout<<"Flight "<<flightNo<<" does not exist"<<endl;
        return;
    }
    cout<<"Flight "<<flightNo<<" has "<<(flightList[location].getRowNo())*(flightList[location].getColNo())-(flightList[location].getBusyNumber())<<" available seats"<<endl;

    int* fakeCol = new int[flightList[location].getBusyNumber()];
    int* fakeRow = new int[flightList[location].getBusyNumber()];

    for(int i =0; i<flightList[location].getBusyNumber(); i++)
    {
        fakeRow[i] =flightList[location].getResRowList()[i];
        fakeCol[i] = (int) flightList[location].getResColList()[i]-65;
    }
    char c;
    cout<<"  ";
    for(int i =65; i<(65+flightList[location].getColNo()); i++)
    {
        c = i;
        cout<<c<<" ";
    }
    cout<<endl;
    char** temp = new char*[flightList[location].getRowNo()];
    for(int i =0; i<flightList[location].getRowNo(); i++)
    {
        temp[i] = new char[flightList[location].getColNo()];
    }

    for(int i =0; i<flightList[location].getRowNo(); i++)
    {
        for(int j =0; j<flightList[location].getColNo(); j++)
        {
            temp[i][j] ='o';
        }
    }
    for(int i =0; i<flightList[location].getBusyNumber(); i++)
    {
        for(int j =1; j<=flightList[location].getRowNo(); j++)
        {
            for(int k = 0; k<flightList[location].getColNo(); k++)
            {
                if(fakeRow[i]==j&&fakeCol[i]==k)
                {
                    temp[j-1][k] ='x';
                }
            }
        }
    }
    for(int i =0; i<flightList[location].getRowNo(); i++)
    {
        cout<<i+1<<" ";
        for(int j =0; j<flightList[location].getColNo(); j++)
        {
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < flightList[location].getRowNo(); i++)
    {
        delete[] temp[i];
        temp[i] = NULL;
    }
    delete[] temp;
    delete [] fakeCol;
    delete [] fakeRow;
    temp = NULL;
    fakeCol = NULL;
    fakeRow = NULL;
}

int ReservationSystem::makeReservation(const int flightNo, const int numPassengers,const int *seatRow, const char *seatCol )
{
    int quit = -1;
    int location = -1; // location of flight
    bool available = true;
    for(int i = 0; i < numberOfFlights; i++ )
    {
        if(flightNo == flightList[i].getFlightNo())
        {
            location = i;
        }
    }
    if(location<0)
    {
        cout<<"Flight "<<flightNo<<" does not exist"<<endl;
        return quit;
    }

    int oldResCount = 0;
    oldResCount = flightList[location].getBusyNumber();
    for(int i =0; i<oldResCount; i++)
    {
        for(int j =0; j<numPassengers; j++)
        {
            if(flightList[location].getResRowList()[i]==seatRow[j] && flightList[location].getResColList()[i]==seatCol[j])
            {
                cout<<flightList[location].getResRowList()[i]<<flightList[location].getResColList()[i]<<" ";
                available=false;
            }
        }
    }
    if(!available)
    {
        cout<<" not available"<<endl;
        return quit;
    }
    int updatedResCount = oldResCount + numPassengers;
    flightList[location].setBusyNumber(updatedResCount);

    reservationNumber++;

    int* tempRow = flightList[location].getResRowList();
    char* tempCol = flightList[location].getResColList();
    int* tempCode = flightList[location].getResCode();

    flightList[location].setResRowList(new int[updatedResCount]);
    flightList[location].setResColList(new char[updatedResCount]);
    flightList[location].setResCode(new int[updatedResCount]);

    for(int i =0; i <oldResCount; i++)
    {
        flightList[location].getResRowList()[i] = tempRow[i];
        flightList[location].getResColList()[i] = tempCol[i];
        flightList[location].getResCode()[i] = tempCode[i];
    }
    for(int i = oldResCount; i<updatedResCount; i++)
    {
        flightList[location].getResRowList()[i] = seatRow[i-oldResCount];
        flightList[location].getResColList()[i] = seatCol[i-oldResCount];
        flightList[location].getResCode()[i] = reservationNumber;
    }

    delete [] tempRow;
    delete [] tempCol;
    delete [] tempCode;
    tempCode = NULL;
    tempRow = NULL;
    tempCol = NULL;
    cout<<endl;
    return reservationNumber;
}

void ReservationSystem::cancelReservation( const int resCode )
{
    bool checkResCode = false; //existence of the reservation code
    int location = -1;
    int resIndex = -1;
    int friends = 0;
    for(int i=0; i<numberOfFlights; i++)
    {
        for(int j=0; j<flightList[i].getBusyNumber(); j++)
        {
            if(resCode==flightList[i].getResCode()[j])
            {
                location=i;
                checkResCode= true;
            }
        }
    }
    if(!checkResCode)
    {
        cout<<"No reservation are found under code "<<resCode<<endl;
        return;
    }
    for(int i=0; i<flightList[location].getBusyNumber(); i++)
    {
        if(flightList[location].getResCode()[i]==resCode)
        {
            friends++;
        }
    }

    for(int j=0; j<flightList[location].getBusyNumber(); j++)
    {
        if(resCode==flightList[location].getResCode()[j])
        {
            resIndex = j-friends+1;
        }
    }

    cout<<"Reservation for seats ";

    for(int j =0; j<flightList[location].getBusyNumber(); j++)
    {
        if(resCode==(flightList[location].getResCode()[j]))
        {
            cout<<flightList[location].getResRowList()[j]<<flightList[location].getResColList()[j]<<" ";
        }
    }

    cout<<" canceled in flight "<<flightList[location].getFlightNo()<<endl;

    int* tempRow = flightList[location].getResRowList();
    char* tempCol = flightList[location].getResColList();
    int* tempResCode = flightList[location].getResCode();

    int newPopulation = flightList[location].getBusyNumber()-friends;

    int *flightListRowList = new int[newPopulation];
    char *flightListColList = new char[newPopulation];
    int *flightListResCode = new int[newPopulation];

    for(int i=0; i<resIndex; i++)
    {
        flightListRowList[i] = tempRow[i];
        flightListColList[i]= tempCol[i];
        flightListResCode[i] = tempResCode[i];
    }

    for(int i =resIndex; i<newPopulation; i++)
    {
        flightListRowList[i] = tempRow[i+friends];
        flightListColList[i]= tempCol[i+friends];
        flightListResCode[i] = tempResCode[i+friends];
    }
    flightList[location].setBusyNumber(newPopulation);

    flightList[location].setResRowList(flightListRowList);
    flightList[location].setResColList(flightListColList);
    flightList[location].setResCode(flightListResCode);

    delete [] tempRow;
    delete [] tempCol;
    delete [] tempResCode;
    tempRow = NULL;
    tempCol = NULL;
    tempResCode = NULL;
    cout<<endl;
}

void ReservationSystem::showReservation( const int resCode)
{
    int location = -1;
    for(int i =0; i<numberOfFlights; i++)
    {
        for(int j=0; j<flightList[i].getBusyNumber(); j++)
        {
            if(resCode==flightList[i].getResCode()[j])
            {
                location=i;
            }
        }
    }
    if(location>=0)
    {
        cout<<"Reservation under "<<resCode<<" in Flight "<<flightList[location].getFlightNo()<<": ";
        for(int i = 0; i <numberOfFlights; i++)
        {
            int sizeOfRez = flightList[i].getBusyNumber();
            for(int j =0; j<sizeOfRez; j++)
            {
                if(resCode==(flightList[i].getResCode()[j]))
                {
                    cout<<flightList[i].getResRowList()[j]<<flightList[i].getResColList()[j]<<" ";
                }
            }
        }
        cout<<endl;
    }
    else
    {
        cout<<"No reservation under code "<<resCode<<endl;
        return;
    }
}
void ReservationSystem::cancelRezWOMessage(const int resCode)
{
    bool checkResCode = false; //existence of the reservation code
    int location = -1;
    int resIndex = -1;
    int friends = 0;
    for(int i=0; i<numberOfFlights; i++)
    {
        for(int j=0; j<flightList[i].getBusyNumber(); j++)
        {
            if(resCode==flightList[i].getResCode()[j])
            {
                location=i;
                checkResCode= true;
            }
        }
    }
    if(!checkResCode)
    {
        return;
    }
    for(int i=0; i<flightList[location].getBusyNumber(); i++)
    {
        if(flightList[location].getResCode()[i]==resCode)
        {
            friends++;
        }
    }

    for(int j=0; j<flightList[location].getBusyNumber(); j++)
    {
        if(resCode==flightList[location].getResCode()[j])
        {
            resIndex = j-friends+1;
        }
    }

    int* tempRow = flightList[location].getResRowList();
    char* tempCol = flightList[location].getResColList();
    int* tempResCode = flightList[location].getResCode();

    int newPopulation = flightList[location].getBusyNumber()-friends;

    int *flightListRowList = new int[newPopulation];
    char *flightListColList = new char[newPopulation];
    int *flightListResCode = new int[newPopulation];

    for(int i=0; i<resIndex; i++)
    {
        flightListRowList[i] = tempRow[i];
        flightListColList[i]= tempCol[i];
        flightListResCode[i] = tempResCode[i];
    }

    for(int i =resIndex; i<newPopulation; i++)
    {
        flightListRowList[i] = tempRow[i+friends];
        flightListColList[i]= tempCol[i+friends];
        flightListResCode[i] = tempResCode[i+friends];
    }
    flightList[location].setBusyNumber(newPopulation);

    flightList[location].setResRowList(flightListRowList);
    flightList[location].setResColList(flightListColList);
    flightList[location].setResCode(flightListResCode);

    delete [] tempRow;
    delete [] tempCol;
    delete [] tempResCode;
    tempRow = NULL;
    tempCol = NULL;
    tempResCode = NULL;
}

void ReservationSystem::cancelFlightWOMessage( const int flightNo )
{
    bool exist = false;
    int location = -1;
    for(int i = 0; i < numberOfFlights; i++)
    {
        if(flightNo==flightList[i].getFlightNo())
        {
            exist = true;
            location = i;
        }
    }
    if(!exist)
    {
        return;
    }
    numberOfFlights--;
    Flight* newList = new Flight[numberOfFlights];
    for(int i = 0; i<location; i++)
    {
        newList[i] = flightList[i];
    }
    for(int i= location; i < numberOfFlights; i++)
    {
        newList[i] = flightList[i+1];
    }

    if(flightList[location].getResCode() != NULL)
    {
        delete[] flightList[location].getResCode();
        flightList[location].getResCode() = NULL;
    }

    if(flightList[location].getResColList() != NULL)
    {
        delete [] flightList[location].getResColList();
        flightList[location].getResColList() = NULL;
    }
    if(flightList[location].getResRowList() != NULL)
    {
        delete [] flightList[location].getResRowList();
        flightList[location].getResRowList() = NULL;
    }

    if(flightList != NULL)
    {
        delete [] flightList;
        flightList = NULL;
    }


    flightList = newList;
}
