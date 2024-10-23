CC = g++
CFLAGS = -Wall -g
 
 
main: main.o game.o gameLibrary.o review.o
    $(CC) $(CFLAGS) -o main main.o game.o gameLibrary.o review.o
 
 
main.o: main.cpp game.h gameLibrary.h review.o
    $(CC) $(CFLAGS) -c main.cpp
 
game.o: game.h
 
gameLibrary.o: gameLibrary.h game.h

review.o: review.h gameLibrary.h game.h