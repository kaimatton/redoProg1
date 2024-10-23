#include "game.h"

// Default constructor (when user doesnt pass info it auto to this init)
Game::Game()
{
    gameName = "";
    category = "";
    rating = 0.0;
    gameReview = nullptr; 
}

// Parametrized constructor (used when user passes info)
Game::Game(string gn, string c,float r)
{
    gameName = gn;
    category = c;
    gameReview = nullptr; 
}

// Destructor to free dynamically allocated Review
Game::~Game()
{
    delete gameReview;
}

// Display game and review information
void Game::display()
{
    cout << "--------------------------------";
    cout << "\nGame Name: " << gameName;
    cout << "\nCategory: " << category;
    cout << "\nGame Rating: " << rating << endl;
    if (gameReview)
    {
        gameReview->display(); // this will call the funtion in the class review
    }
}

// Save game and review information to a file
void Game::save(ofstream &out)
{
    out << gameName << "\n";
    out << category << "\n";
    out << rating << "\n";

    if (gameReview)
    {
        gameReview->save(out); // Save the review if it exists
    }
}

// Function to add or update a review for the game
void Game::addReview(string reviewerName, string reviewText)
{
    if (gameReview)
    {
        delete gameReview; // Delete the old review if it exists
    }
    gameReview = new GameReview(reviewerName, reviewText); // Create a new review
}