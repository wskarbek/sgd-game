IDIR = include
LDIR = lib
ODIR = build
SDIR = src

LIBS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image

CC=g++
CFLAGS=-I$(IDIR) -I$(SDIR) -L$(LDIR) -w -std=c++14

_DEPS = game.hpp spritesheet.hpp world.hpp
DEPS = $(patsubst %,$(SDIR)/%,$(_DEPS))

_OBJ = game.o spritesheet.o world.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build/game.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)