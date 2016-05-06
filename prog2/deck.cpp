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
    for(int i = 0; i < 53; ++i)
    {
        delete the_deck[i];
    }

    delete [] the_deck;
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
    next = NULL;
    prev = NULL;
    if(card) delete card;
    card = NULL;
}

S_node *& S_node::go_next()
{
    return next;
}

S_node *& S_node::go_prev()
{
    return prev;
}

bool S_node::if_next() const
{
    if(next) return true;
    return false;
}

bool S_node::if_prev() const
{
    if(prev) return true;
    return false;
}

void S_node::set_next(S_node * source)
{
    if(source) next = source;
    else next = NULL;
    return;
}

void S_node::set_prev(S_node * source)
{
    if(source) prev = source;
    else prev = NULL;
    return;
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

bool S_node::compare_nodes(S_node * source)
{
    return card->compare_cards(*source->card);
}

bool S_node::smaller_compare(S_node * source)
{
    return card->is_smaller_match_suit(*source->card);
}

bool S_node::card_is_the_same(Card source)
{
    return card->are_the_same(source);
}
//******************************************************************************


//*************************Solitaire class functions****************************
//S_node ** board
//S_node *** display_board
Solitaire::Solitaire()
{
    //Two different boards are used, one for the data structure keeping track
    //of the cards in a specified order, and another for displaying. First we
    //initialize the board data structure
    board = new S_node * [13];
    for(int i = 0; i < 13; ++i)
    {
        board[i] = NULL;
    }
    deal_cards();
    
    //Then we initialize the display board and null out all pointers.
    display_board = new S_node ** [13];
    
    for(int i = 0; i < 13; ++i)
    {
        display_board[i] = new S_node * [20];
    }
    
    clear_display_board();
}

Solitaire::~Solitaire()
{

}

void Solitaire::initialize_board()
{
    
}

void Solitaire::insert_card(int i, S_node * &source)
{
    if(!board[i]) 
    {   
        board[i] = source; 
        return;
    }

    source->set_next(board[i]);
    board[i]->set_prev(source);
    board[i] = source;
    return;
}

void Solitaire::deal_cards()
{
    int index = 0;
    
    for(int i = 0; i < 7; ++i)
    {
        for(int j = 0; j < i + 1; ++j)
        {
            S_node * temp = new S_node(*the_deck[index]);
            insert_card(i, temp);
            ++index;
        }
    }

    for(index; index < 52; ++index)
    {
        S_node * temp = new S_node(*the_deck[index]);
        insert_card(11, temp);
    }

    return;
}
//TODO purely for testing

void Solitaire::display_garbage_wrapper()
{
    for(int i = 0; i < 7; ++i)
    {
        display_garbage(board[i]);
        cout << endl << endl;
    }

    display_garbage(board[11]);

    return;
}
//TODO purely for testing
void Solitaire::display_garbage(S_node * head)
{
    if(!head) return;
    head->display_node();
    display_garbage(head->go_next());
    return;
}

void Solitaire::clear_display_board()
{
    for(int i = 0; i < 13; ++i)
    {
        for(int j = 0; j < 20; ++j)
        {
            display_board[i][j] = NULL;
        }
    }

    return;
}

void Solitaire::send_to_d_board_wrapper()
{
    for(int i = 0; i < 7; ++i)
    {
        send_to_d_board(i, 0, board[i]); 
    }
    
    for(int i = 7; i < 13; ++i)
    {
        if(board[i])
        {
            display_board[i][0] = board[i];
        }
    }

    return;
}

void Solitaire::send_to_d_board(int i, int j, S_node * head)
{
    if(!head)
    {
        return;
    }

    display_board[i][j] = head;
    //TODO possible erro
    ++j;
    send_to_d_board(i, j, head->go_next());
    return;
}

void Solitaire::d_board()
{
    int index = 0;
    cout << "******************************************************************"
         << "**********************************************" << endl;
    cout << "***********************************SOLITAIRE BOARD****************"
         << "**********************************************" << endl;
    cout << "******************************************************************"
         << "**********************************************" << endl;
    cout << endl;
    cout << "-Index--" << "-Index--" << "-Index--" << "-Index--" << "-Index--" 
         << "-Index--" << "-Index--" << "-Index--" << "-Index--" << "-Index--"
         << "-Index--" << "-Index--" << "-Index--" << endl;
    cout << "**0*****" << "**1*****" << "**2*****" << "**3*****" << "**4*****" 
         << "**5*****" << "**6*****" << "**7*****" << "**8*****" << "**9*****"
         << "**10****" << "**11****" << "**12****" << endl;
    cout << "T: 1    " << "T: 2    " << "T: 3    " << "T: 4    " << "T: 5    " 
         << "T: 6    " << "T: 7    " << "H aces  " << "D Aces  " << "C Aces  "
         << "S Aces  " << "Hand    " << "Talon   " << endl;
    
    for(int j = 0; j < 20; ++j)
    {
        for(int i = 0; i < 13; ++i)
        {
            if(!display_board[i][j])
            {
                cout << "        ";
            }
            if(display_board[i][j])
            {
                display_board[i][j]->display_node();
                
                cout << "     ";
            }

        }
        cout << endl;
    }
    
    return;
}

void::Solitaire::play_game()
{
    bool running = true;
    char response = '\0';
    cout << endl << endl;
    cout << "Welcome screen." << endl;
    cout << "Rules: for suits 1 is hearts, 2 is diamonds, 3 is clubs, 4 is"
         << " spades. Aces are 1, 2 through 10 and simply 2 through 10,"
         << endl << "Jacks are 11, queens are 12, Kings are 13.";
    cout << endl << endl;
    
    send_to_d_board_wrapper();
    d_board();
    
    while(running)
    {
        cout << "1: Move a card" << endl << "2: Display the next hand card"
             << endl << "3: Shuffle the talon pile" << endl << "Enter"
             << " 1, 2, or 3 now: ";
        cin >> response;
        cin.ignore(100, '\n');

        if(response == '1')
        {
            make_move();
            clear_display_board();
            send_to_d_board_wrapper();
            d_board();
        }
        
        else if(response == '2')
        {
            move_down_hand();
            clear_display_board();
            send_to_d_board_wrapper();
            d_board();
        }
        
        else if(response == '3')
        {
            shift_talon_to_hand();
            clear_display_board();
            send_to_d_board_wrapper();
            d_board();
        }

        else
        {
            cout << "Invalid option" << endl;
        }
        
        if(win_condition())
        {
            cout << "Congratualations on the sick win!" << endl;
            running = false;
        }

    }

    cout << "The game's now over!" << endl;
    return;
}

S_node * Solitaire::find_node_wrapper(int index, int s, int v)
{
    Card aCard(s, v);
    return find_node(board[index], aCard);
}

S_node * Solitaire::find_node(S_node * &head, Card source)
{
    if(!head) return NULL;
    
    if(head->card_is_the_same(source))
    {
        return head;
    }

    return find_node(head->go_next(), source);
}

S_node * Solitaire::get_tail(S_node * &head)
{
    if(!head) return NULL;
    if(!head->if_next()) return head;
    return get_tail(head->go_next());
}

void Solitaire::move_a_node(S_node * dest, S_node * source)
{
    dest->set_next(source);
    source->set_prev(dest);
    return;
}

bool Solitaire::win_condition()
{
    if(!board[7] || !board[8] || board[9] || board[10])
    {
        return false;
    }
    
    bool hearts = false;
    bool diamonds = false;
    bool clubs = false;
    bool spades = false;

    Card heart(1, 13);
    Card diamond(2, 13);
    Card club(3, 13);
    Card spade(4, 13);

    if(board[7]->card_is_the_same(heart)) hearts = true;
    if(board[8]->card_is_the_same(diamond)) diamonds = true;
    if(board[9]->card_is_the_same(club)) clubs = true;
    if(board[10]->card_is_the_same(spade)) spades = true;

    return hearts && diamonds && clubs && spades;
}

void Solitaire::move_down_hand()
{
    if(!board[11])
    {
        cout << "No cards in the hand pile." << endl;
        return;
    }

    S_node * source = board[11];
    
    //If there's other cards in the hand, break the link.
    if(source->if_next())
    {
        board[11] = source->go_next();
        board[11]->set_prev(NULL);
    }

    else
    {
        board[11] = NULL;
    }
    
    //now link up with the talon.
    if(!board[12])
    {
        board[12] = source;
        source->set_next(NULL);
        source->set_prev(NULL);
    }

    else
    {
        source->set_next(board[12]);
        source->set_prev(NULL);
        board[12]->set_prev(source);    
        board[12] = source;
    }

    return;
}

void Solitaire::shift_talon_to_hand()
{
    if(board[11])
    {
        cout << "The hand isn't empty, you can't reshuffle yet." << endl;
        return;
    }
    
    board[11] = board[12];
    board[12] = NULL;
    return;
}

void Solitaire::make_move()
{   
    //data for what is to be moved
    int index = 0;
    int s = 0;
    int v = 0;
    //the array index the data is attempting to move to
    int dest_index = 0;
    cout << "to make a move input the table index, the suite, and the card's"
         << " value.";
    cout << "make move: " << endl;
    
    //Get the data to be moved
    cout << "Enter index: ";
    cin >> index;
    cin.ignore(100, '\n');
    
    cout << "Enter suit: ";
    cin >> s;
    cin.ignore(100, '\n');
    
    cout << "Enter value: ";
    cin >> v;
    cin.ignore(100, '\n');
    
    cout << "move to: ";
    cin >> dest_index;
    cin.ignore(100, '\n');

    cout << endl << endl;
    
    //There are four different moves in solitaire that can be made. Moving 
    //card from the tableau to a different place in the tableau, with a sub
    //case of moving a to an open slot, moving a tableau card to an ace pile
    //moving a talon card to a

    //Case 1, tab to tab
    if(index < 7 && dest_index < 7)
    {
        //Case 1.1 moving a king to an open slot
        if(v == 13)
        {
            //try to append to NULL spot
            move_king_open(index, dest_index, s, v);
        }
        else
        {
            move_tab_to_tab(index, dest_index, s, v);
        }
    }

    //case 2, moving from the tableua to the ace pile
    else if(index < 7 && dest_index > 6)
    {
        move_tab_to_aces(index, dest_index, s, v);
    }
    
    //case 3 moving from the hand to the tableau
    else if(index == 11 && dest_index < 7)
    {
        move_hand_to_tab(index, dest_index, s, v);
    }

    else if(index == 11 && dest_index > 6 && dest_index < 11)
    {
        move_hand_to_tab(index, dest_index, s, v);
    }

    else
    {
        cout << "Indices not recognized." << endl;
    }

    return;
}

void Solitaire::move_king_open(int index, int dest_index, int s, int v)
{
    //if the space isn't open, a move can't be made.
    if(board[dest_index])
    {
        cout << "That space isn't open." << endl;
        return;
    }
    
    //otherwise, find the node;
    S_node * moving = find_node_wrapper(index, s, v);
    
    //if the searched for card wasn't found, quit.
    if(!moving)
    {
        cout << "Card not found." << endl;
        return;
    }
    
    //else let's make the move
    else
    {
        if(!moving->if_prev())
        {
            board[index] = NULL;
        }
        
        //break the old bounds, set the new one
        else
        {
            moving->go_prev()->set_next(NULL);
            moving->set_prev(NULL);
            board[dest_index] = moving;
        }
    }
    return;
}

void Solitaire::move_tab_to_tab(int index, int dest_index, int s, int v)
{
    //If where the user is wanting to move is not NULL and what the user wants
    //to move is not NULL, then check if the move is legal. If it is swap.
    S_node * moving = find_node_wrapper(index, s, v);
    S_node * dest = NULL;
    if(moving)
    {
        //if there is a node to move and a place to move it to, see if the move
        //can be made
        if(moving && board[dest_index])
        {
            //get last node in that list.
            dest = get_tail(board[dest_index]);
            
            
            //check if the destination is bigger 
            if(dest->compare_nodes(moving))
            {
                if(!moving->if_prev())
                {
                    board[index] = NULL;
                }
                
                //make the move
                else
                {
                    moving->go_prev()->set_next(NULL);
                    dest->set_next(moving);
                    moving->set_prev(dest);
                }
            }

            else
            {
                cout << "Invalid move." << endl;
            }
        }

        else
        {
            cout << "No such move found." << endl;
        }
    }
}

void Solitaire::move_tab_to_aces(int index, int dest_index, int s, int v)
{
    //If where the user is wanting to move is not NULL and what the user wants
    //to move is not NULL, then check if the move is legal. If it is swap.
    S_node * moving = find_node_wrapper(index, s, v);
    S_node * dest = NULL;
    
    //If a node was found based on the search terms, try to move it to the
    //desired place.
    if(moving->if_next())
    {
        cout << "Can't add a card to an ace pile that is not at the bottom of"
             << " the tableau." << endl;
        return;
    }

    if(moving)
    {
        //If there isn't anything at the destination, the only thing that can
        //be added is an ace with a matching suit.
        if(!board[dest_index])
        {      
            //check if are trying to add an ace with matching suit
            if(v == 1 && s == (dest_index - 6))
            {
                //if so, the destination is going to point to the node
                board[dest_index] = moving;
                
                //have to make sure nothing is still connected to the ace
                if(moving->if_prev())
                {
                    moving->go_prev()->set_next(NULL);
                    moving->set_prev(NULL);;
                    moving->set_next(NULL);
                }
                
                //If it was connected to something, break that connection and
                //NULL out that space
                else
                {
                    moving->set_prev(NULL);
                    moving->set_next(NULL);
                    board[index] = NULL;
                }
            }
        }
        
        //if there is aleady a node at the index, we have to go to the end. 
        else
        {
            dest = get_tail(board[dest_index]);
            //check if the card is the same suit and bigger
            if(dest->smaller_compare(moving))
            {
                //if it is, before we connect it to its new home we need to 
                //break any old connections it may have had.
                if(moving->if_prev())
                {
                    moving->go_prev()->set_next(NULL);
                    
                    moving->set_prev(dest);
                    dest->set_next(moving);
                    moving->set_next(NULL);
                    board[dest_index] = moving;
                }
                
                //if there wasn't anything before, set that previous space to 
                //NULL
                else
                {
                    moving->set_prev(dest);
                    dest->set_next(moving);
                    moving->set_next(NULL);
                    board[dest_index] = moving;
                    board[index] = NULL;
                }
            }

            //else it wasn't so don't add
            else
            {
                cout << "Couldn't add a that card there." << endl;
            }
        }
    }

    //else tell them the card wasn't found.
    else
    {
        cout << "Card not found." << endl;
    }

    return;
}

void Solitaire::move_hand_to_tab(int index, int dest_index, int s, int v)
{
    //If where the user is wanting to move is not NULL and what the user wants
    //to move is not NULL, then check if the move is legal. If it is swap.
    Card aCard(s, v);
    S_node * moving = board[index];
    S_node * dest = NULL;
    
    //If the user didn't enter in the top card of the hand then leave, return
    //because only the top card can be moved.
    if(!moving->card_is_the_same(aCard))
    {
        cout << "That was not matching the top card of the Hand." << endl;
        return;
    }

    if(moving)
    {
        //Case for moving a king from the hand to an open tableau   
        if(v == 13 && !board[dest_index])
        {
            
            if(!moving->if_next())
            {
                board[index] = NULL;
            }
        
            //break the old bounds, set the new one
            else
            {
                board[index] = moving->go_next();
                moving->go_next()->set_prev(NULL);
                moving->set_next(NULL);
                board[dest_index] = moving;
            }
        }
        
        
        //if there is a node to move and a place to move it to, see if the move
        //can be made
        else if(moving && board[dest_index])
        {
            //get last node in that list.
            dest = get_tail(board[dest_index]);
            
            //check if the destination is bigger 
            if(dest->compare_nodes(moving))
            {
                if(!moving->if_next())
                {
                    board[index] = NULL;
                }
                
                //make the move
                else
                {
                    cout << endl << endl << endl << "HERRRRRRRRRRRRRRRR" << endl;
                    board[index] = moving->go_next();
                    moving->go_next()->set_prev(NULL);
                    dest->set_next(moving);
                    moving->set_prev(dest);
                    moving->set_next(NULL);
                }
            }

            else
            {
                cout << "Invalid move." << endl;
            }
        }

        else
        {
            cout << "No such move found." << endl;
        }
    }

    else
    {
        cout << "card not found." << endl;
    }
}

void Solitaire::move_hand_aces(int index, int dest_index, int s, int v)
{
    //If where the user is wanting to move is not NULL and what the user wants
    //to move is not NULL, then check if the move is legal. If it is swap.
    S_node * moving = board[11];
    S_node * dest = NULL;
    Card aCard(s, v);
    
    if(!moving->card_is_the_same(aCard))
    {
        cout << "That was not matching the top card of the hand." << endl;
        return;
    }

    if(moving)
    {
        //If there isn't anything at the destination, the only thing that can
        //be added is an ace with a matching suit.
        if(!board[dest_index])
        {      
            //check if are trying to add an ace with matching suit
            if(v == 1 && s == (dest_index - 6))
            {
                //if so, the destination is going to point to the node
                board[dest_index] = moving;
                
                //have to make sure nothing is still connected to the ace
                if(moving->if_next())
                {
                    board[index] = moving->go_next();
                    moving->go_next()->set_prev(NULL);
                    moving->set_prev(NULL);;
                    moving->set_next(NULL);
                }
                
                //If it was connected to something, break that connection and
                //NULL out that space
                else
                {
                    moving->set_prev(NULL);
                    moving->set_next(NULL);
                    board[index] = NULL;
                }
            }
        }
        
        //if there is aleady a node at the index, we have to go to the end. 
        else
        {
            dest = get_tail(board[dest_index]);
            //check if the card is the same suit and bigger
            if(dest->smaller_compare(moving))
            {
                //if it is, before we connect it to its new home we need to 
                //break any old connections it may have had.
                if(moving->if_next())
                {
                    board[index] = moving->go_next();
                    moving->go_next()->set_next(NULL);
                    moving->set_prev(dest);
                    dest->set_next(moving);
                    moving->set_next(NULL);
                    board[dest_index] = moving;
                }
                
                //if there wasn't anything before, set that previous space to 
                //NULL
                else
                {
                    moving->set_prev(dest);
                    dest->set_next(moving);
                    moving->set_next(NULL);
                    board[dest_index] = moving;
                    board[index] = NULL;
                }
            }

            //else it wasn't so don't add
            else
            {
                cout << "Couldn't add that card there." << endl;
            }
        }
    }

    //else tell them the card wasn't found.
    else
    {
        cout << "Card not found." << endl;
    }

    return;
}

//******************************************************************************

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
