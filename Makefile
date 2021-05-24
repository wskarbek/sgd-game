IDIR = include
LDIR = lib
ODIR = bin
SDIR = src

LIBS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image

CC=g++
CFLAGS=-I$(IDIR) -I$(SDIR) -L$(LDIR) -w -std=c++14

_OBJ = game.o spritesheet.o world.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

bin/game.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)