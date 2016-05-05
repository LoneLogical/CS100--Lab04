
CC=g++


CFLAGS=-c -Wall

all: lab04

lab04: main.o class.o sort.o container.o
	$(CC) main.o class.o sort.o container.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

class.o: class.cpp
	$(CC) $(CFLAGS) class.cpp

sort.o: sort.cpp
	$(CC) $(CFLAGS) sort.cpp

container.o: container.cpp
	$(CC) $(CFLAGS) container.cpp


