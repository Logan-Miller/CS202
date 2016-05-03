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
    
    Deck aDeck;
    aDeck.display_deck();
    
    aDeck.shuffle();
    cout << endl;
    aDeck.display_deck();

    return 0;
}
