CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
OBJS = dlist.o main.o
FILE_MAIN = ./testing/main.c


all: main.c dlist.o
	$(CC) $(CFLAGS) -o ./testing/main.o ./testing/main.c ./obj/dlist.o

dlist.o: ./include/dlist.h ./src/dlist.c
	$(CC) $(CFLAGS) -c ./src/dlist.c -o ./obj/dlist.o

clean:
	rm -rf ./obj/*.o