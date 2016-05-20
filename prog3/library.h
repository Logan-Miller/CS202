#include "book.h"
#include <time.h>
#include <stdlib.h>

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
    void random_topics(B_node *& head, int index);
    bool all_confident(B_node * head);
    B_node * head;
    int num_books;
};
