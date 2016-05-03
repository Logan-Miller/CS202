#include "deck.h"

int main()
{
    //TESTING CARD CLASS FUNCTIONS
    char * s = new char[1];
    char * v = new char[2];
    
    strcpy(s, "C");
    strcpy(v, "10");
    
    Card aCard(s, v);
    cout << endl;
    aCard.display_card();

    //*********************************************************
    return 0;
}
