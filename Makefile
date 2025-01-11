CC = gcc
CFLAGS = -c -g -Wall
LD = gcc
LDFLAGS = -g -Wall

all: pipeit

pipeit: pipeit.o
	$(LD) $(LDFLAGS) -o pipeit pipeit.o

pipeit.o: pipeit.c
	$(CC) $(CFLAGS) -o pipeit.o pipeit.c

