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
    virtual void play_game() = 0;
protected:
    Card ** the_deck;
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
    bool compare_nodes(S_node * source);
    bool smaller_compare(S_node * source);
    bool card_is_the_same(Card source);
protected:
    S_node * next;
    S_node * prev;
    Card * card;
};

/*
    @desc: derived from a deck, the solitaire class is used for playing games
           of solitaire using the base class's deck
*/
class Solitaire : public Deck
{
public:
    Solitaire();
    virtual ~Solitaire();
    void delete_list(S_node * &head);
    void play_game();
    void deal_cards();
    void insert_card(int i, S_node * &source);
    void display_garbage(S_node * head);
    void display_garbage_wrapper();
    void clear_display_board();
    void send_to_d_board(int i, int j, S_node * head);
    void send_to_d_board_wrapper();
    void d_board();
    S_node * find_node_wrapper(int index, int s, int v);   
    S_node * find_node(S_node * &head, Card source);
    S_node * get_tail(S_node * &head);
    void move_a_node(S_node * dest, S_node * source);
    void make_move();
    void move_tab_to_tab(int index, int dest_index, int s, int v);
    void move_king_open(int index, int dest_index, int s, int v);
    void move_tab_to_aces(int index, int dest_index, int s, int v);
    void move_hand_to_tab(int index, int dest_index, int s, int v);
    void move_hand_aces(int index, int dest_index, int s, int v);
    void move_down_hand();
    void shift_talon_to_hand();
    bool win_condition();
protected:
    S_node ** board;
    S_node *** display_board;
};

/*
    @desc: W_nodes are used for building linear linked lists of arrays.
*/
class W_node
{
public:
    W_node();   
    W_node(const Card &aCard);
    ~W_node();
    W_node *& go_next();
    bool if_next() const;
    void set_next(W_node * source);
    void display_node();
    int compare_for_winner(W_node * source);
protected:
    W_node * next;
    Card ** cards;
};

/*
    @desc: the war class is derived from the deck class. It uses the base 
           classes deck to play games of war with two players. 
*/
class War : public Deck
{
public:
    War();
    virtual ~War();   
    void delete_players(W_node * &head);
    void play_game();
    void play_turn();
    void round_winner();
    int increment_score();
    bool game_over();
    void build_players();
    void insert_w_node(W_node * &head, W_node * &source);
    void prepare_next_round();
protected:
    W_node * player1;
    W_node * player2;
    int p1_score;
    int p2_score;
};
