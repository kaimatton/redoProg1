CC = g++
CFLAGS = -Wall -g
 
 
driver: driver.o game.o gameLibrary.o review.o
    $(CC) $(CFLAGS) -o driver driver.o game.o gameLibrary.o review.o
 
 
driver.o: Driver.cpp game.h gameLibrary.h review.h
    $(CC) $(CFLAGS) -c Driver.cpp
 
game.o: game.h
 
gameLibrary.o: gameLibrary.h game.h

review.o: review.h gameLibrary.h game.h
