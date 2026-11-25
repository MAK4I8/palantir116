CC = gcc
CFLAGS = -Wall -Wextra

all: main

main: main.c
	$(CC) $(CFLAGS) main.c -lm -o main

clean:
	rm -f main *.o
