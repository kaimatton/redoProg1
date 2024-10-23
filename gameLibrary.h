#ifndef GAMELIBRARY_H
#define GAMELIBRARY_H

#include "game.h"
#include <fstream>

// class definition
class GameLibrary
{
    Game **games;
    int numGames;

public:
// default constructor 
    GameLibrary();

    // function 
    void importLibrary();
    void displayGame();
    void addGame();
    void saveLibrary();    
    
    //deestructor 
    ~GameLibrary();
};

#endif