CC= g++
CFLAGS= -O0 -Wall -std=c++11 -Iinc
LIBS= -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

SRC= src
BIN= bin

all: ejemplo-1 ejemplo-2

ejemplo-1: $(SRC)/ejemplo-1.cpp $(SRC)/ejemplo-1-game.cpp
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BIN)/$@

ejemplo-2: $(SRC)/ejemplo-2.cpp $(SRC)/ejemplo-2-game.cpp $(SRC)/scene.cpp $(SRC)/scenes/mainmenu.cpp $(SRC)/scenes/test2.cpp $(SRC)/scenes/test1.cpp
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BIN)/$@

clean:
	rm -rf $(BIN)/*
