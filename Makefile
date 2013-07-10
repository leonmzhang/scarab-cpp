# makefile

test : test.o
	g++ -o test -std=c++11 test.o

test.o : test.cpp include/sc_utils.h include/hardware.h
	g++ -o test.o -c -g -std=c++11 test.cpp

clean :
	rm *.o test
