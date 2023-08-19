CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
OBJS = dlist.o main.o
FILE_MAIN = main.o


all:
	$(CC) $(CFLAGS) -o ./obj/main.o ./testing/main.c ./obj/dlist.o
dlist.o: ./include/dlist.h ./src/dlist.c
	$(CC) $(CFLAGS) -c ./src/dlist.c -o ./obj/dlist.o
clean:
	rm -rf ./obj/*.o
run:
	./obj/main.o
