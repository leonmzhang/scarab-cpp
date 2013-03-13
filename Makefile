# makefile

test : test.o
	g++ -o test test.o

test.o : test.cpp include/sc_utils.h
	g++ -o test.o -c -g test.cpp

clean :
	rm *.o test
