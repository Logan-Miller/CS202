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
    //TODO change to true before
    hidden = false;
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
        cout << "***";
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
        cout << "_" << "A";
        break;
    case 10: 
        cout << value;
        break;
    case 11:
        cout << "_" << "J";
        break;
    case 12:
        cout << "_" << "Q";
        break;
    case 13:
        cout << "_" << "K";
        break;
    }

    if(value > 1 && value < 10)
    {
    //TODO took away new line
        cout << "_" << value;
    }

    else if(value < 1 || value > 13)
    {
        cout << "XX" << endl;
    }
    
    return;
}

bool Card::compare_cards(Card source)
{
    //if the current card's value is 1 greater than the source's value then
    //return true.   
    if(value == (source.value + 1)) return true;
    return false;
}

bool Card::are_the_same(Card source)
{
    if(suit == source.suit && value == source.value) return true;
    return false;
}

bool Card:: matched(int s, int v)
{
    if(suit == s && value == v) return true;
    return false;
}
//******************************************************************************




