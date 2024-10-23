#include "gameLibrary.h"

GameLibrary::GameLibrary()
{
    games = nullptr;
    numGames = 0;
};

// Destructor
GameLibrary::~GameLibrary()
{
    for (int i = 0; i < numGames; i++)
    {
        delete games[i];
    }
    delete games;
};

void GameLibrary::importLibrary()
{
    ifstream myFile;
    string line;
    string fileName;

    string gameName;
    string gameCategory;
    float rating;

    // for reviwe class
    string userName, userText;
    int tempCount = 0;
    cin.ignore();

    if (numGames < 1)
    {
        cout << "\nEnter The name of file of your Game Library: ";
        getline(cin, fileName);
        
        // opens file user types (if exist)
        myFile.open(fileName, ios::in);
        if (myFile.is_open())
        {
            // first loop which counts the number of lines
            while (!myFile.eof())
            {
                // gets name cat and rating and stores them into correct definitions 
                getline(myFile, gameName);  
                getline(myFile, gameCategory);       
                myFile >> rating;         
                myFile.ignore();

                // skips the review if it exists
                getline(myFile, line);

                if (line != "")
                {
                    getline(myFile, line);
                    myFile.ignore();
                }

                tempCount++;
            }

            // allocates array to number of games within file 
            // based on count we can create another oobject 
            games = new Game *[tempCount];

            // https://www.geeksforgeeks.org/file-handling-c-classes/
            myFile.clear();
            myFile.seekg(0, ios::beg); 

            tempCount = 0;

            // This will itterate and store each line into the object 
            while (!(myFile.eof()))
            {
                getline(myFile, gameName);  
                getline(myFile, gameCategory);
                myFile >> rating;          
                myFile.ignore();

                //this is where it is storing the data
                games[tempCount] = new Game(gameName, gameCategory,rating);

                getline(myFile, userName);

                // gets the users review 
                if (userName != "")
                {
                    getline(myFile, userText);
                    myFile.ignore();
                    games[tempCount]->addReview(userName, userText);
                }

                // counts the number of objects
                tempCount++;
            }

            myFile.close();

            cout << endl
                << fileName << " The Loaded Library has " << tempCount << " Games Saved.\n";

            numGames = tempCount;
        }
        // if file doesnt exist
        else
        {
            cout << "File failed to open ." << endl;
        }
    }
    // if games loaded on to current library, it will give error 
    else
    {
        cout << endl << "Games are already added or loaded, to load a saved file, empty your current library." << endl;
    }
};

void GameLibrary::displayGame()
{
    if (numGames > 0)
    {
        for (int i = 0; i < numGames; i++)
        {
            games[i]->display();
        }
    }
    else
    {
        cout << endl
            << "There are no Games in the Library. Add or load data " << endl;
    }
}

void GameLibrary::addGame()
{
    string gameName;
    string gameCategory;
    float rating;
    string userName, userText;

    // create new array of pointers to games objects
    Game **newGame = new Game *[numGames + 1];

    for (int i = 0; i < numGames; i++)
    {
        newGame[i] = games[i];
    }

    // get user input 
    cout << "\nGame Name: ";
    cin.ignore();
    getline(cin, gameName);
    cout << "\nGame Category: ";
    getline(cin, gameCategory);
    cout << "\nRating: ";
    cin >> rating;

    // creates the new game 
    newGame[numGames] = new Game(gameName, gameCategory,rating);

    // Get review for a game
    char reviewChoice;
    cout << "\nDo you want to add a review for the game? (y/n): ";
    cin >> reviewChoice;
    if (tolower(reviewChoice) == 'y')
    {

        cout << "\nWhats Your Name: ";
        cin.ignore();
        getline(cin, userName);
        cout << "\nLeave the Review Here: ";
        getline(cin, userText);
        newGame[numGames]->addReview(userName, userText);
    }

    delete[] games;
    games = newGame;
    numGames++;
}

void GameLibrary::saveLibrary()
{
    ofstream outFile;
    string fileName;
    string target = ".txt";

    // checks if there are games in library to save
    if (numGames > 0)
    {
        cin.ignore();

        cout << endl << "Enter a saved file with '.txt' to save or overwrite the data: ";
        getline(cin, fileName);

        // if file user entered exists, it will overwrite
        // if file doesnt exists, it will create new file 
        outFile.open(fileName, ios::out);
        if (outFile.is_open())
        {
            for (int i = 0; i < numGames; i++)
            {
                games[i]->save(outFile);
                if (i < numGames - 1)
                    outFile << endl;
            }
            cout << "File " << fileName << " has been updated with new data" << endl;
        }
    }
    else 
    {
        cout << endl << "You have no game libraries saved, Start and save a game library in menu" << endl;
    }

}