all: my_program

my_program: my_program.o
	g++ -o my_program my_program.o

my.program.o: my_program.cpp
	g++ -O -c my_program.cpp

clean:
	rm -f my_program *.o
