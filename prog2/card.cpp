#include "card.h"


//*********************CLASS CARD FUNCTIONS*************************************
//char * suite
//char * value

/*
    @desc:
*/
Card::Card()
{
    suit = NULL;
    value = NULL;
    hidden = true;
}

/*
    @desc:
*/
Card::Card(char * s, char * v)
{
    suit = NULL;
    value = NULL;
    hidden = true;

    suit = new char[strlen(s) + 1];
    value = new char[strlen(v) + 1];
    
    strcpy(suit, s);
    strcpy(value, v);
}

/*
    @desc:
*/
Card::~Card()
{
    if(suit)
    {
        delete [] suit;
    }

    if(value)
    {
        delete [] value;
    }

    suit = NULL;
    value = NULL;
}

/*
    @desc:
*/
void Card::set_suit(char * source)
{
    if(!suit)
    {
        suit = new char[strlen(source) + 1];
        strcpy(suit, source);
        return;
    }

    delete [] suit;
    suit = new char[strlen(source) + 1];
    strcpy(suit, source);
    return;
}
/*
    @desc:
*/
void Card::set_value(char * source)
{
    if(!value)
    {
        value = new char[strlen(source) + 1];
        strcpy(value, source);
        return;
    }

    delete [] value;
    value = new char[strlen(source) + 1];
    strcpy(value, source);
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
        cout << "******" << endl;
        return;
    }

    if(suit && value)
    {
        cout << suit << " " << value << endl;
    }

    return;
}
//******************************************************************************

