CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
OBJS = dlist.o main.o
FILE_MAIN = main.o


all:
	$(CC) $(CFLAGS) -o ./obj/main.o ./testing/main.c ./obj/argapi_dlist.o

argapi_dlist.o: ./include/argapi_dlist.h ./src/argapi_dlist.c

	$(CC) $(CFLAGS) -c ./src/argapi_dlist.c -o ./obj/argapi_dlist.o
clean:
	rm -rf ./obj/*.o
run:
	./obj/main.o
