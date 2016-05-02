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
    Card(char * s, char * v);
    ~Card();
    void set_suit(char * source);
    void set_value(char * source);
    void set_hidden(bool source);
    void display_card();

protected:
    char * suit;
    char * value;
    bool hidden;
};

/*
    @desc:
*/
class Deck : public Card
{
public:

protected:

}
