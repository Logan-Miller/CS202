#include <stdlib.h>
#include <time.h>
#include "card.h"

/*
    @desc: A deck has an array of 52 cards. The constructor creates 52 unique
           cards, ensuring 4 different suits each with 13 different values are 
           created, and assigns each a position within the array.
*/
class Deck
{
public:
    Deck();
    virtual ~Deck();
    void shuffle();
    void display_deck();
    void display_board();

protected:
    Card ** the_deck;
//    Card *** the_board;
};

/*
    @desc: S_nodes are used for creating doubly linked list type data 
           structures of nodes containing a pointer to a card. 
*/
class S_node
{
public:
    S_node();   
    S_node(const Card &aCard);
    ~S_node();
    S_node *& go_next();
    S_node *& go_prev();
    bool if_next() const;
    bool if_prev() const;
    void set_next(S_node * source);
    void set_prev(S_node * source);
    void set_status(bool status);
    void display_node();

protected:
    S_node * next;
    S_node * prev;
    Card * card;
};

/*
    @desc:
*/
class Solitaire : public Deck
{
public:
    Solitaire();
    virtual ~Solitaire();

protected:
   S_node ** tableau;
   S_node ** foundation;
   S_node * stock;
   S_node * talon;
};

/*
    @desc:
*/
class W_node
{
public:

protected:

};

/*
    @desc:
*/
class War
{
public:

protected:

};
