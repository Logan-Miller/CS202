#include "card.h"


//*********************CLASS CARD FUNCTIONS*************************************

/*
    @desc: a card is an object that has a suit, value and a hidden status
*/
Card::Card()
{
    suit = 0;
    value = 0;
    hidden = true;
}

/*
    @desc: given two integers, initializes the card with a suit and value
           of the given values. 
*/
Card::Card(int s, int v)
{
    suit = s;
    value = v;
    hidden = false;
}

/*
    @desc: copy constructor for cards
*/
Card::Card(const Card &card)
{
    suit = card.suit;
    value = card.value;
    hidden = card.hidden;
}

/*
    @desc: destructor just sets the values to null equivalent
*/
Card::~Card()
{
    suit = 0;
    value = 0;
    hidden = true;
}

/*
    @desc: sets the suit to a given value
*/
void Card::set_suit(int source)
{
    suit = source;
    return;
}

/*
    @desc: sets the value to a given value
*/
void Card::set_value(int source)
{
    value = source;
    return;
}

/*
    @desc: sets the hidden status
*/
void Card::set_hidden(bool source)
{
    hidden = source;
    return;
}

/*
    @desc: displays a card, checks the values and displays given characters
           dependent on what the suit and value is. If the card's status is set
           to hidden, it just displays ***
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
        cout << "_" << value;
    }

    else if(value < 1 || value > 13)
    {
        cout << "XX" << endl;
    }
    
    return;
}

/*
    @desc: checks if the given card is less than the current card
*/
bool Card::compare_cards(Card source)
{
    //if the current card's value is 1 greater than the source's value then
    //return true.   
    if(value == (source.value + 1)) return true;
    return false;
}

/*
    @desc: checks if a given card has a smaller value than the current card
*/
bool Card::is_smaller_match_suit(Card source)
{
    if(value == (source.value - 1) && suit == source.suit) return true;
    return false;
}

/*
    @desc: checks ifboth cards are the same
*/
bool Card::are_the_same(Card source)
{
    if(suit == source.suit && value == source.value) return true;
    return false;
}

/*
    @desc: checks if a given suit and value are the same as the current carde
*/
bool Card::matched(int s, int v)
{
    if(suit == s && value == v) return true;
    return false;
}

/*
    @desc: checks which card, the current or the source, has a greater value
*/
int Card::which_is_bigger(Card source)
{
    //return 1 if both cards are the same
    if(value == source.value) return 1;
    //return 2 if this card is bigger than source
    else if(value > source.value) return 2;
    //else this card is less than source return 3
    else return 3;
}
//******************************************************************************




