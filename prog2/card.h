#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

/*
    @desc:
*/
class Card
{
public:
    Card();
    Card(int s, int v);
    Card(const Card &card);
    ~Card();
    void set_suit(int source);
    void set_value(int source);
    void set_hidden(bool source);
    void display_card();
    bool compare_cards(Card source);
    bool is_smaller_match_suit(Card source);
    bool are_the_same(Card source);
    bool matched(int s, int v);
    int which_is_bigger(Card source);
protected:
    int suit;
    int value;
    bool hidden;
};

