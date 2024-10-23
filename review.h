#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// class definition
class GameReview
{
    string userName;
    string *userText;

public:
    // default contrustor 
    GameReview();
    // peramter contructor 
    GameReview(string userName, string userText);

    // function 
    void display();
    void save(ofstream &out);
    void setReview(string userText);
    // destructor 
    ~GameReview();

};

#endif