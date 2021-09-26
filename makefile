CC=gcc
CFLAGS=-o dc -g
LIBS=-lSDL2 -lGL -lGLEW
SRC=*.c

game: $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LIBS)

run:
	./dc