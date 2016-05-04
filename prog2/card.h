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

protected:
    int suit;
    int value;
    bool hidden;
};

