#include "book.h"

class Library
{
public:
    Library();
    Library(const Library &library);
    ~Library();
    int create_book();
    void remove_all();
    void display_all();   
    int step_through();
    int auto_populate();
protected:
    int insert_book(B_node *& head, B_node *& source);
    void display_all(B_node * head);
    int step_through(B_node *& head);
    void remove_all(B_node *& head);
    int copy_list(B_node *& dest, B_node * source);
    B_node * head;
    int num_books;
};
