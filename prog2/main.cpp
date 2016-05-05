#include "deck.h"

int main()
{
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
    Solitaire game;
    game.display_garbage_wrapper();
    
    
    //**********************************************************
    
    
    
    
    //**********************************************************
    //**********************************************************
    //**********************************************************
    //**********************************************************
    //**********************************************************
    //**********************************************************
    return 0;
}
