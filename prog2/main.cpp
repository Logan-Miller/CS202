#include "deck.h"
/*
    @desc: The purpose of the main function is to give the user a choice 
           between two different games to play. The main function will give
           the user the choice of the game, initialize and run the desired 
           game, and then continue to to run games until they wish for the 
           program to close. 
*/
int main()
{
    char response = '\0';
    bool running = true;
    Deck * game = NULL;
    cout << "Welcome to the game selection. There are two different games you"
         << " are able to play." << endl << "The games available to play are" 
         << " solitaire or war." << endl;
    
    while(running)
    {
        cout << "Enter 1 to play solitaire, 2"
             << " To play war, or q to quit." << endl << "Enter now: ";

        cin >> response;
        cin.ignore(100, '\n');

        if(response == '1')
        {
            game = new Solitaire;
            game->play_game();
            if(game) delete game;
            game = NULL;
        }

        else if(response == '2')
        {
            game = new War;
            game->play_game();
            if(game) delete game;
            game = NULL;
        }

        else if(response == 'q')
        {
            running = false;
        }

        else
        {
            cout << "Response given wasn't recognized. Enter 1, 2, or q."
                 << endl;
        }
    }

    cout << "Thanks for playing, the program will now close." << endl;
    
    return 0;
}
