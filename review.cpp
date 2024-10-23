#include "review.h"

// Default constructor 
GameReview::GameReview()
{
    userName = "";
    userText = nullptr; 
}

// Parametrized constructor
GameReview::GameReview(string n, string t)
{
    userName = n;
    userText = new string(t); 
}

// Destructor
GameReview::~GameReview()
{
    delete userText;
}

// Display review information
void GameReview::display()
{
    cout << "\nReviewer: " << userName;
    if (userText && !userText->empty())
    {
        cout << "\nReview: " << *userText;
    }
    else
    {
        cout << "\nThere is no review for the game";
    }
    cout << endl;
}

// Save review information to a file
void GameReview::save(ofstream &out)
{
    if (userText && !userText->empty())
    {
        out << userName << endl;
        out << *userText << endl;
    }
    else
    {
        out << "There is no review for the game";
    }
}

// Set the review text
void GameReview::setReview(string t)
{
    if (userText)
    {
        delete userText;
    }
    userText = new string(t); 
}