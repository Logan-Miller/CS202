#include "problem.h"

class Book
{
public:
    Book();
    virtual ~Book();
    int create_problem();
    int set_topic(char * source);
    void remove_all();
    void display_all();
protected:
    int insert_problem(P_node *& root, P_node *& source);
    void remove_all(P_node *& root);
    void display_all(P_node * root);
    //members
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
    B_node *& go_next();
protected:
    B_node * next;
};
