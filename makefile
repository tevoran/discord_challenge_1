CC=gcc
CFLAGS=-o dc
LIBS=-lSDL2
SRC=*.c

game: $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LIBS)

run:
	./dc