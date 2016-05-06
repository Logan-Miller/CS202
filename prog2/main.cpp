#include "deck.h"

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

    //TESTING CARD CLASS FUNCTIONS
    /*
    Card aCard(3, 4);
    cout << endl;
    aCard.display_card();
    
    aCard.set_hidden(false);
    cout << endl;
    aCard.display_card();
    
    aCard.set_value(10);
    aCard.display_card();
    
    aCard.set_value(13);
    aCard.display_card();

    aCard.set_suit(1);
    aCard.set_value(8);
    aCard.display_card();
    */
    //*********************************************************
    
    //TESTING DECK FUNCTIONS
    /*
    Deck aDeck;
    aDeck.display_deck();
    
    aDeck.shuffle();
    cout << endl;
    aDeck.display_deck();
    */
    //**********************************************************

    //****TESTING S_NODE FUNCTIONS******************************
    /*
    Card * aCard = new Card(3, 13);
    S_node * node = new S_node(*aCard);
    node->display_node();
    node->set_status(false);
    node->display_node();
    aCard = NULL;
    node->display_node();
    */
    //**********************************************************
    
    
    
    //***********Testing solitaire functions********************
    /* 
    cout << "start" << endl;
    Solitaire game;
    //game.display_garbage_wrapper();
    cout << "its made " << endl;
    game.send_to_d_board_wrapper();
    game.d_board();
    game.play_game();

    cout << "end" << endl; 
    */
    //**********************************************************
    
    
    
    
    //**********************************************************
    //War game;
    //game.play_game();
    
    //**********************************************************
    
    
    //**********************************************************
    //**********************************************************
    //**********************************************************
    //**********************************************************
    return 0;
}
