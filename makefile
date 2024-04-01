CC = gcc
CFLAGS = -O1 -g -Wall -Werror -Idudect -I.


main.o: main.c oop.h oop.c 
	$(CC) -o main main.c oop.c $(CFLAGS)

clean:
	rm main


