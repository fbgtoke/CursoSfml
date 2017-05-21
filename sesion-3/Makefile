CC= g++
CFLAGS= -O0 -Wall -std=c++11 -Iinc
LIBS= -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

SRC= src
BIN= bin

all: ejemplo-1 ejemplo-2 ejemplo-3

ejemplo-1: $(SRC)/ejemplo-1.cpp
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BIN)/$@

ejemplo-2: $(SRC)/ejemplo-2.cpp $(SRC)/animation.cpp $(SRC)/animatedsprite.cpp
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BIN)/$@

ejemplo-3: $(SRC)/ejemplo-3.cpp $(SRC)/ejemplo-3-game.cpp $(SRC)/quote.cpp $(SRC)/animation.cpp $(SRC)/animatedsprite.cpp
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BIN)/$@

clean:
	rm -rf $(BIN)/*
