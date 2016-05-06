#include "deck.h"

//*********************DECK CLASS FUNCTIONS*************************************

/*
    @desc: initializes a deck, making an array of size 52. Then assigning 
           unique cards to each index. 4 for loops are used to creat 13 cards
           of each suit.
*/
Deck::Deck()
{
    the_deck = new Card * [52];
    int index = 0;

    //initializing all hearts
    for(int i = 0; i < 13; ++i)
    {
        index = i + 1;
        the_deck[i] = new Card(1, index);
    } 
    
    //initializing all diamonds
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
    
    //initializing all clubs
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
    
    //initializing all spades
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
    @desc: deallocates all memory for the deck
*/

Deck::~Deck()
{   
    for(int i = 0; i < 52; ++i)
    {   
        if(the_deck[i]) delete the_deck[i];
    }
    
    if(the_deck) delete [] the_deck;
}       
/*
    @desc: uses a random number generator to generate indices. uses a for loop
           to iterate over the array. At each index, generates another index to
           swap with. This shuffling happens three times.
*/

void Deck::shuffle()
{
    srand(time(NULL));
    
    int index_to_swap = 0;
    
    //shuffle 3 times to get that good distribution
    for(int j = 0; j < 3; ++j)
    {
        //swap each index of the array
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
    @desc: displays the entire deck.
*/
    
void Deck::display_deck()
{
    for(int i = 0; i < 52; ++i)
    {
        the_deck[i]->set_hidden(false);
        cout << i << "_";
        the_deck[i]->display_card();
    }

    return;
}

//******************************************************************************

//**********************S_node Functions****************************************
/*
    @desc: set pointers to null initially
*/
S_node::S_node()
{
    next = NULL;
    prev = NULL;
    card = NULL;
}

/*
    @desc: given a card, set pointers to null, set card to a new card using
           the card copy constructor
*/
S_node::S_node(const Card &aCard)
{
    next = NULL;
    prev = NULL;
    card = NULL;
    card = new Card(aCard);
}

/*
    @desc: deallocate memory.
*/
S_node::~S_node()
{
    next = NULL;
    prev = NULL;
    if(card) delete card;
    card = NULL;
}

/*
    @desc: returns the next pointer
*/
S_node *& S_node::go_next()
{
    return next;
}

/*
    @desc: returns the previous pointer
*/
S_node *& S_node::go_prev()
{
    return prev;
}

/*
    @desc: checks if next
*/
bool S_node::if_next() const
{
    if(next) return true;
    return false;
}

/*
    @desc: checks if previous
*/
bool S_node::if_prev() const
{
    if(prev) return true;
    return false;
}

/*
    @desc: sets the next
*/
void S_node::set_next(S_node * source)
{
    if(source) next = source;
    else next = NULL;
    return;
}

/*
    @desc: sets the previous
*/
void S_node::set_prev(S_node * source)
{
    if(source) prev = source;
    else prev = NULL;
    return;
}

/*
    @desc: displays the card in the node
*/
void S_node::display_node()
{
    card->display_card();
    return;
}

/*
    @desc: sets the cards status
*/
void S_node::set_status(bool status)
{
    card->set_hidden(status);
    return;
}

/*
    @desc: compares the nodes cards
*/
bool S_node::compare_nodes(S_node * source)
{
    return card->compare_cards(*source->card);
}

/*
    @desc: 
*/
bool S_node::smaller_compare(S_node * source)
{
    return card->is_smaller_match_suit(*source->card);
}

/*
    @desc: checks if the node's cards are the same
*/
bool S_node::card_is_the_same(Card source)
{
    return card->are_the_same(source);
}
//******************************************************************************


//*************************Solitaire class functions****************************
/*
    @desc: shuffles the deck, creates the board, and array  doubly linked lists.
           initially sets all indexes to null. calls the deal function to build
           the lists. builds the display_board, a multidimensional array purely
           for displaying the solitaire board. ensures the display_board is
           initially nulled out. 
*/  
Solitaire::Solitaire()
{
    shuffle();
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

/*
    @desc: uses the delete list function to delete each list in the board array
           then deletes the display board 2d array.
*/
Solitaire::~Solitaire()
{
    clear_display_board();

    for(int i = 0; i < 13; ++i)
    {
        if(display_board[i]) delete [] display_board[i];
    }
    
    if(display_board) delete [] display_board;

    for(int i = 0; i < 13; ++i)
    {
        if(board[i]) delete_list(board[i]);
        board[i] = NULL;
    }

    if(board) delete [] board;
}

/*
    @desc: recursive function to delete a list 
*/
void Solitaire::delete_list(S_node * &head)
{
    if(!head) return;
    delete_list(head->go_next());
    delete head; 
    head = NULL;
    return;
}

/*
    @desc: given an index and a node, inserts the node into the board at the
           given index. For insertion we add at the head. 
*/
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

/*
    @desc: deals the cards out to the board in the same way a solitaire board
           would. In this way the first tableau has 1 card, the second has 2, 
           etc, until the 7th index has 7 cards. The hand pile at index 12 is
           then given the rest of the cards. 
*/
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

/*
    @desc: This function is purely for testing, along with the display_garbage
           function, this is used to display the actual cards in the data 
           structure used to keep track of all the cards actual positions.
*/
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

/*
    @desc: recursive function only used by the wrapper above to display all 
           nodes in a given list
*/
void Solitaire::display_garbage(S_node * head)
{
    if(!head) return;
    head->display_node();
    display_garbage(head->go_next());
    return;
}

/*
    @desc: iterates over the entire 2d array, setting each index to null.
*/
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

/*
    @desc: gets all nodes from the actual board and sets pointers to them in
           the display_board.
*/
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

/*
    @desc: given the index in a 2d array, i and j, and a node, sets the pointer
           at the given index to that given node.
*/
void Solitaire::send_to_d_board(int i, int j, S_node * head)
{
    if(!head)
    {
        return;
    }

    display_board[i][j] = head;
    ++j;
    send_to_d_board(i, j, head->go_next());
    return;
}

/*
    @desc: displays the display_board. uses couts for a large menu, and then
           iterates over the 2d array and displays the nodes ensuring the 
           solitaire board is displayed in a way friendly to the user. 
*/
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

/*
    @desc: function for playing a game of solitaire. gives the user a prompt
           and the rules of the game. 
*/
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
    
    //allows the user to keep entering moves until a specified condition is met
    while(running)
    {
        cout << "1: Move a card" << endl << "2: Display the next hand card"
             << endl << "3: Shuffle the talon pile" << endl << "Enter"
             << " 1, 2, or 3 now: ";
        cin >> response;
        cin.ignore(100, '\n');

        //response for moving a card
        if(response == '1')
        {
            make_move();
            clear_display_board();
            send_to_d_board_wrapper();
            d_board();
        }
        
        //response for changing the hand to the next card
        else if(response == '2')
        {
            move_down_hand();
            clear_display_board();
            send_to_d_board_wrapper();
            d_board();
        }
        
        //response for moving the talon (discard pile) back to the hand
        else if(response == '3')
        {
            shift_talon_to_hand();
            clear_display_board();
            send_to_d_board_wrapper();
            d_board();
        }

        //case for incorrect input
        else
        {
            cout << "Invalid option" << endl;
        }
        
        //checks the win condition to see if the game is over, if they won,
        //the game will close. 
        if(win_condition())
        {
            cout << "Congratualations on the sick win!" << endl;
            running = false;
        }

    }

    cout << "The game's now over!" << endl;
    return;
}

/*
    @desc: wrapper function to search for a node
*/
S_node * Solitaire::find_node_wrapper(int index, int s, int v)
{
    Card aCard(s, v);
    return find_node(board[index], aCard);
}

/*
    @desc: searches for a node given a list's head and the card to be searched
           for.
*/
S_node * Solitaire::find_node(S_node * &head, Card source)
{
    if(!head) return NULL;
    
    if(head->card_is_the_same(source))
    {
        return head;
    }

    return find_node(head->go_next(), source);
}

/*
    @desc: given a list, gets the tail of that list
*/
S_node * Solitaire::get_tail(S_node * &head)
{
    if(!head) return NULL;
    if(!head->if_next()) return head;
    return get_tail(head->go_next());
}

/*
    @desc: given a destination node and a source node, moves the source node
           to the destination node's next
*/
void Solitaire::move_a_node(S_node * dest, S_node * source)
{
    dest->set_next(source);
    source->set_prev(dest);
    return;
}

/*
    @desc: checks if the game has been won. To win all the ace piles must be
           filled.
*/
bool Solitaire::win_condition()
{
    //first condition is that there is even a card in each ace pile
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
    
    //The last condition is that the last card in each ace pile is a king of 
    //its respective suit
    if(board[7]->card_is_the_same(heart)) hearts = true;
    if(board[8]->card_is_the_same(diamond)) diamonds = true;
    if(board[9]->card_is_the_same(club)) clubs = true;
    if(board[10]->card_is_the_same(spade)) spades = true;

    return hearts && diamonds && clubs && spades;
}

/*
    @desc: function for moving down the hand, which sets the current hand card
           into the talon pile, and then moves the current hand to the next
           card.
*/
void Solitaire::move_down_hand()
{
    if(!board[11])
    {
        cout << endl << "No cards in the hand pile." << endl;
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

/*
    @desc: Shifts the talon pile to the hand pile
*/
void Solitaire::shift_talon_to_hand()
{
    if(board[11])
    {
        cout << endl << "The hand isn't empty, you can't reshuffle yet." 
             << endl;
        return;
    }
    
    board[11] = board[12];
    board[12] = NULL;
    return;
}

/*
    @desc: when making a move there are 4 things that are needed, the pile the 
           user is trying to move a card from, its index, the suit and the 
           value of the card they are trying to move, and the pile the user
           is trying to move the card to, or the destination index.
*/
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
    
    //case 4 moving a hand card to the tableau
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

/*
    @desc: function for moving a king card to an open slot on the tableau
*/
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

/*
    @desc: function for moving a tableau card to another spot on the tableau
*/
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

/*
    @desc: function for moving a tableau card to an ace pile
*/
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

/*
    @desc: function for moving a card from the hand pile to the tableau
*/
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

/*
    @desc: function for moving a hand card to an ace pile
*/
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

//*******************W_node Class functions*************************************
/*
    @desc: initializes a node
*/
W_node::W_node()
{
    next = NULL;
    cards = new Card * [1];
    cards[0] = NULL;
}

/*
    @desc: initializes a node with a given card, using the card's copy function
*/
W_node::W_node(const Card &aCard)
{
    next = NULL;
    cards = new Card * [1];
    cards[0] = new Card(aCard);
}

/*
    @desc: deallocates memory for a node
*/
W_node::~W_node()
{
    delete cards[0];
    delete [] cards;
}

/*
    @desc: returns the nodes next pointer
*/
W_node *& W_node::go_next()
{
   return next;
}

/*
    @desc: returns whether or not there is a next
*/
bool W_node::if_next() const
{
    if(next) return true;
    return false;
}

/*
    @desc: sets the next pointer to a given node
*/
void W_node::set_next(W_node * source)
{
    next = source;
    return;
}

/*
    @desc: displays the card in the node
*/
void W_node::display_node()
{
    cards[0]->display_card();
    return;
}

/*
    @desc: calls the card's comparefunction to determine which of the two cards
           is of greater value
*/
int W_node::compare_for_winner(W_node * source)
{
    return cards[0]->which_is_bigger(*source->cards[0]);
}

//******************************************************************************


//********************War calss funtions****************************************
/*
    @desc: shuffles the deck, sets the player's data to null equivalents.
           then calls the build function to build both players, both will be
           a linear linked list of arrays with 26 nodes.
*/
War::War()
{
    shuffle();
    player1 = NULL;
    player2 = NULL;
    p1_score = 0;
    p2_score = 0;

    build_players();
}

/*
    @desc: deallocates memory for both player lists using the delete players
           function
*/
War::~War()
{   
    if(player1)
    {
        delete_players(player1);
    }
    
    if(player2)
    {
        delete_players(player2);
    }
    player1 = NULL;
    player2 = NULL;
}

/*
    @desc: given a list's head, deletes all nodes
*/
void War::delete_players(W_node * &head)
{
    if(!head) return;
    delete_players(head->go_next());
    if(head) delete head;
    head = NULL;
    return;
}

/*
    @desc: Playing a game runs each turn until there are no more cards to 
           compare (when one of the lists is empty). it then checks the 
           players scores to see who one, and then displays the winner
*/
void War::play_game()
{
    bool running = true;
    char response = '\0';
    cout << endl << endl;
    cout << "Welcome to war, the game that pits to players agianst eachother"
         << endl << "The deck will be split between both players. Each player"
         << endl << "will then have reveal their top card simultaniously. The"
         << endl << "player with the higher card value will win the round. The"
         << endl << "game will end when both players are out of cards." << endl
         << endl;

    cout << "Type 1 to begin: ";
    cin >> response;
    cin.ignore(100, '\n');
    cout << endl;

    while(running)
    {
        play_turn();
        if(game_over()) running = false;
        cout << "Next turn? (y): ";
        cin >> response;
        cin.ignore(100, '\n');
        cout << endl;
    }

    if(p1_score > p2_score)
    {
        cout << "Player 1 won!" << endl;
    }

    else if(p1_score < p2_score)
    {
        cout << "Player 2 won!" << endl;
    }

    else
    {
        cout << "Game was a draw!" << endl;
    }

    cout << "The game will now quit." << endl;
    return;
}

/*
    @desc: a turn displays both player's cards, then determines the winner of
           the turn using the round_winner function. then prepares for the next
           turn.
*/
void War::play_turn()
{
    cout << "Player 1's card: ";
    player1->display_node();
    cout << endl;
    cout << "Player 2's card: ";
    player2->display_node();
    cout << endl;
    round_winner();
    prepare_next_round();
}

/*
    @desc: round winner compares both cards, displays the outcome to the
           players and increments the winner's score. If it was a draw no 
           points are allocated
*/
void War::round_winner()
{
    if(!player1 || !player2)
    {
        cout << "There are no cards!" << endl;
        return;
    }

    int winner = player1->compare_for_winner(player2);
    if(winner == 1)
    {
        cout << "Its a draw!" << endl;
    }

    else if(winner == 2)
    {
        cout << "Player 1 wins!" << endl;
        ++p1_score;
    }

    else
    {
        cout << "Player 2 wins!" << endl;
        ++p2_score;
    }
    
    return;
}

/*
    @desc: to prepare for the next round, both player's list is moved to the
           next node (card). The previous nodes are then deleted. 
*/
void War::prepare_next_round()
{
    if(player1)
    {
        W_node * temp1 = player1;
        W_node * temp2 = player2;
        player1 = player1->go_next();
        player2 = player2->go_next();
        delete temp1;
        delete temp2;
    }

    return;
}

/*
    @desc: Checks if one of the lists is empty, if it is then there are no more
           cards and thus the game is over. 
*/
bool War::game_over()
{
    if(!player1) return true;
    return false;
}

/*
    @desc: builds both player's lists. or hand of cards. inserts the first 26
           cards into the player1 list and then the last 26 cards into the 
           player2 list. 
*/
void War::build_players()
{
    for(int i = 0; i < 26; ++i)
    {
        W_node * temp1 = new W_node(*the_deck[i]);   
        insert_w_node(player1, temp1);
    }


    for(int i = 26; i < 52; ++i)
    {
        W_node * temp2 = new W_node(*the_deck[i]);
        insert_w_node(player2, temp2);
    }

    return;
}

/*
    @desc: given a list and a source goes to the end of the list and appends
           the source node to the list. 
*/
void War::insert_w_node(W_node * &head, W_node * &source)
{
    if(!head)
    {
        head = source;
        return;
    }

    insert_w_node(head->go_next(), source);
    return;
}

//******************************************************************************
