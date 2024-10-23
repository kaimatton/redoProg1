#include "game.h"
#include "gameLibrary.h"

int main()
{
    // Creates instance of gamelibrary
    GameLibrary myGame;

    int choice;

    do
    {
        cout << "\n----------------------------------------------";
        cout << "\nWhat Would You Like To Do?";
        cout << "\n\t1 - Import A Game Library";
        cout << "\n\t2 - Add A New Game";
        cout << "\n\t3 - Print Your Game Library";
        cout << "\n\t4 - Save Your Game Library ";
        cout << "\n\t5 - Exit";
        do
        {
            cout << "\n\tCHOOSE: 1-5: ";
            cin >> choice;

            if (choice < 1 || choice > 5) {
                cout << endl << "Please choose valid number (1-5)" << endl;
            }

        } while (choice < 1 || choice > 5);

        switch (choice)
        {
        case 1:
            myGame.importLibrary();
            break;
        case 2:
            myGame.addGame();
            break;
        case 3:
            myGame.displayGame();
            break;
        case 4:
            myGame.saveLibrary();
            break;
        }
    } while (choice != 5);

    cout << endl << "Program Is Ending..." << endl;

    return 0;
}