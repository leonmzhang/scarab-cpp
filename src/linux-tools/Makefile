OUTPUT=sc_ls


$(OUTPUT) : sc_ls.o
	g++ -o $(OUTPUT) sc_ls.o

sc_ls.o : sc_ls.cpp
	g++ -o sc_ls.o -c -g sc_ls.cpp

clean :
	rm -rf *.o $(OUTPUT)
