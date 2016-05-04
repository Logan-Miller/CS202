#include "card.h"


//*********************CLASS CARD FUNCTIONS*************************************
//char * suite
//char * value

/*
    @desc:
*/
Card::Card()
{
    suit = 0;
    value = 0;
    hidden = true;
}

/*
    @desc:
*/
Card::Card(int s, int v)
{
    suit = s;
    value = v;
    hidden = true;
}

/*
    @desc:
*/
Card::Card(const Card &card)
{
    suit = card.suit;
    value = card.value;
    hidden = card.hidden;
}

/*
    @desc:
*/
Card::~Card()
{
    suit = 0;
    value = 0;
    hidden = true;
}

/*
    @desc:
*/
void Card::set_suit(int source)
{
    suit = source;
    return;
}
/*
    @desc:
*/
void Card::set_value(int source)
{
    value = source;
    return;
}
/*
    @desc:
*/
void Card::set_hidden(bool source)
{
    hidden = source;
    return;
}


/*
    @desc:
*/
void Card::display_card()
{
    if(hidden)
    {
        cout << "****" << endl;
        return;
    }
    
    switch(suit)
    {
    case 1:
        cout << "H";
        break;
    case 2:
        cout << "D";
        break;
    case 3:
        cout << "C";
        break;
    case 4:
        cout << "S";
        break;
    default:
        cout << "X";
        break;
    }

    switch(value)
    {
    case 1:
        cout << "_" << "A" << endl;
        break;
    case 10: 
        cout << value << endl;
        break;
    case 11:
        cout << "_" << "J" << endl;
        break;
    case 12:
        cout << "_" << "Q" << endl;
        break;
    case 13:
        cout << "_" << "K" << endl;
        break;
    }

    if(value > 1 && value < 10)
    {
        cout << "_" << value << endl;
    }

    else if(value < 1 || value > 13)
    {
        cout << "XX" << endl;
    }
    
    return;
}
//******************************************************************************

