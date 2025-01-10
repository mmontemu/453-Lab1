CC = gcc
CFLAGS = -c -g -Wall
LD = gcc
LDFLAGS = -g -Wall

all: forkit tryit

forkit: forkit.o
	$(LD) $(LDFLAGS) -o forkit forkit.o

forkit.o: forkit.c
	$(CC) $(CFLAGS) -o forkit.o forkit.c

tryit: tryit.o
	$(LD) $(LDFLAGS) -o tryit tryit.o

tryit.o: tryit.c
	$(CC) $(CFLAGS) -o tryit.o tryit.c
