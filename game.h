#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <fstream>
#include "review.h"

using namespace std;

// class definition
class Game
{
    string gameName;
    string category;
    float rating;
    GameReview *gameReview;

public:
    // default constructor 
    Game();
    Game(string, string,float);

    void display();
    void save(ofstream&);
    void addReview(string reviewerName, string reviewText);   

    ~Game(); 

};

#endif