#include "book.h"

class Library
{
public:
    Library();
    ~Library();
    int create_book();
    void remove_all();
    void display_all();
protected:
    int insert_book(B_node *& head, B_node *& source);
    void display_all(B_node * head);
    void remove_all(B_node *& head);
    B_node * head;
    int num_books;
};
