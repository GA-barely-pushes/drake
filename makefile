CC = gcc
CF = *.c

all: $(CF)
	$(CC) -O3 $(CF) && ./a.out
