#include "problem.h"

class Book
{
public:
    Book();
    Book(const Book &book);
    virtual ~Book();
    Book & operator += (P_node *& p_node);
    friend Book operator + (const Book &book, P_node *& p_node);
    int create_problem();
    int set_topic(char * source);
    void remove_all();
    void display_all();
    int auto_populate(char * problem, int importance, bool confidence);
    void step_through_problems();
protected:
    int insert_problem(P_node *& root, P_node *& source);
    void remove_all(P_node *& root);
    void display_all(P_node * root);
    void check_problems(P_node *& root);  
    int copy_tree(P_node *& dest, P_node * source);
    //members
    char * topic;
    int num_problems;
    P_node * problems;
};

class B_node : public Book
{
public:
    B_node();
    B_node(const B_node &b_node);
    virtual ~B_node();
    bool if_next();
    void set_next(B_node * source);
    B_node *& go_next();
protected:
    B_node * next;
};
