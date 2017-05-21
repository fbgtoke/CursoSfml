CC= g++
CFLAGS= -O0 -Wall -std=c++11
LIBS= -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

SRC= src
BIN= bin

all: ejemplo-1 ejemplo-2 ejemplo-3 ejemplo-4 ejercicio-1 ejercicio-2

ejemplo-1: $(SRC)/ejemplo-1.cpp
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BIN)/$@

ejemplo-2: $(SRC)/ejemplo-2.cpp
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BIN)/$@

ejemplo-3: $(SRC)/ejemplo-3.cpp
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BIN)/$@

ejemplo-4: $(SRC)/ejemplo-4.cpp
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BIN)/$@

ejercicio-1: $(SRC)/ejercicio-1.cpp
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BIN)/$@

ejercicio-2: $(SRC)/ejercicio-2.cpp
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BIN)/$@

clean:
	rm -rf $(BIN)/*
