



CPP_FLAGS='-std=c++11'
LDLIBS=-lm
output: main.o Flight.o Reservation.o ReservationSystem.o
	g++ ${CPP_FLAGS} main.o Flight.o Reservation.o ReservationSystem.o -o output
main.o: main.cpp
	g++ ${CPP_FLAGS} -c main.cpp
Flight.o: Flight.cpp Flight.h
	g++ ${CPP_FLAGS} -c Flight.cpp
Reservation.o: Reservation.cpp Reservation.h
	g++ ${CPP_FLAGS} -c Reservation.cpp
ReservationSystem.o: ReservationSystem.cpp  ReservationSystem.h
	g++ ${CPP_FLAGS} -c ReservationSystem.cpp
clean:
	rm *.o output

