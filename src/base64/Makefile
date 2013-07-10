TARGET=main

OBJECT=main.o sc_base64.o

$(TARGET) : $(OBJECT)
	g++ -o $(TARGET) $(OBJECT)

sc_base64.o : sc_base64.cpp sc_base64.h
	g++ -o sc_base64.o -c -g sc_base64.cpp

main.o : main.cpp
	g++ -o main.o -c -g main.cpp

clean :
	rm -rf *.o $(TARGET)
