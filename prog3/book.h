#include "problem.h"

class Book
{
public:
    Book();
    virtual ~Book();
protected:
    char * topic;
    int num_problems;
    P_node * problems;
};

class B_node : public Book
{
public:
    B_node();
    virtual ~B_node();
    bool if_next();
    void set_next(B_node * source);
    B_node *& get_next();
protected:
    B_node * next;
};
