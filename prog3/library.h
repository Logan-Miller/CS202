// Logan Miller
// CS 202
// Prog 3

#include "book.h"
#include <time.h>
#include <stdlib.h>

//A library object is essentially a manager of a linear linked list. It allows
//a client to manipulate a linear linked list of binary search trees. Where the
//base data is a Problem object. 
class Library
{
public:
    Library();
    Library(const Library &library);
    ~Library();
    friend ostream & operator << (ostream & out, Library &library);   
    int create_book();
    void remove_all();
    void display_all();   
    int step_through();
    int auto_populate();
    void random_topics();
    bool all_confident();
protected:
    int insert_book(B_node *& head, B_node *& source);
    void display_all(B_node * head);
    int step_through(B_node *& head);
    void remove_all(B_node *& head);
    int copy_list(B_node *& dest, B_node * source);
    bool random_topics(B_node *& head, int index);
    bool all_confident(B_node * head);
    
    B_node * head;
    int num_books;
};
