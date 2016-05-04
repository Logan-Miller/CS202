#include "deck.h"

//*********************DECK CLASS FUNCTIONS*************************************
//Card *** the_deck
//Card *** the_board

/*
    @desc:
*/
Deck::Deck()
{
    the_deck = new Card * [52];
    int index = 0;

    for(int i = 0; i < 13; ++i)
    {
        index = i + 1;
        the_deck[i] = new Card(1, index);
    } 
    
    for(int i = 13; i < 26; ++i)
    {   
        index = i + 1;
        index = index % 13;
        
        if(index == 0)
        {
            the_deck[i] = new Card(2, 13);
        }

        else
        {
            the_deck[i] = new Card(2, index);
        }
    } 
    
    for(int i = 26; i < 39; ++i)
    {
        index = i + 1;
        index = index % 13;
        
        if(index == 0)
        {
            the_deck[i] = new Card(3, 13);
        }

        else
        {
            the_deck[i] = new Card(3, index);
        }
    } 
    
    for(int i = 39; i < 52; ++i)
    {
        index = i + 1;
        index = index % 13;
        
        if(index == 0)
        {
            the_deck[i] = new Card(4, 13);
        }

        else
        {
            the_deck[i] = new Card(4, index);
        }
    } 
}    
/*
    @desc:
*/

Deck::~Deck()
{

}       
/*
    @desc:
*/

void Deck::shuffle()
{
    srand(time(NULL));
    
    int index_to_swap = 0;
    
    for(int j = 0; j < 3; ++j)
    {
        for(int i = 0; i < 52; ++i)
        {
            index_to_swap = rand() % 52;
            Card * temp = the_deck[i];
            the_deck[i] = the_deck[index_to_swap];
            the_deck[index_to_swap] = temp;
        }
    }

    return;
}   
/*
    @desc:
*/
    
void Deck::display_deck()
{
    for(int i = 0; i < 52; ++i)
    {
        //TODO
        the_deck[i]->set_hidden(false);
        cout << i << "_";
        //TODO
        the_deck[i]->display_card();
    }

    return;
}    
/*
    @desc:
*/
    
void Deck::display_board()
{

}


//******************************************************************************

//**********************S_node Functions****************************************
//S_node * next
//S_node * prev
//Card * card

S_node::S_node()
{
    next = NULL;
    prev = NULL;
    card = NULL;
}

S_node::S_node(const Card &aCard)
{
    next = NULL;
    prev = NULL;
    card = NULL;
    card = new Card(aCard);
}

S_node::~S_node()
{

}

S_node * S_node::get_next()
{

}

S_node * S_node::get_prev()
{

}

S_node *& S_node::go_next()
{

}

S_node *& S_node::go_prev()
{

}

bool S_node::if_next() const
{

}

bool S_node::if_prev() const
{

}

void S_node::set_next(S_node * source)
{

}

void S_node::set_prev(S_node * source)
{

}

void S_node::display_node()
{
    card->display_card();
    return;
}


void S_node::set_status(bool status)
{
    card->set_hidden(status);
    return;
}


//******************************************************************************


//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
