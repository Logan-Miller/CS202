#include <iostream>
#include <cstring>
using namespace std;

class Problem
{
public:
    Problem();
    virtual ~Problem();
    int set_importance(int source);
    int set_confidence(bool source);
    int set_question(char * source);
    int display_problem();
    int compare_importance(Problem source);
protected:
    int importance;
    bool confidence;
    char * question;
};

class P_node : public Problem
{
public:
    P_node();
    virtual ~P_node();
    bool if_left();
    bool if_right();
    void set_left(P_node * source);
    void set_right(P_node * source);
    P_node *& get_left();
    P_node *& get_right();

protected:
    P_node * left;
    P_node * right;
};
