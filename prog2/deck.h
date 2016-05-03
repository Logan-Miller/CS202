#include "card.h"

/*
    @desc:
*/
class Deck
{
public:
    Deck();
    ~Deck();
    void shuffle();
    void display_deck();
    void display_board();

protected:
    Card *** the_deck;
    Card *** the_board;
};
