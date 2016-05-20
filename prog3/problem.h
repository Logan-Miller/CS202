#include <iostream>
#include <cstring>
using namespace std;

class Problem
{
public:
    Problem();
    Problem(const Problem &problem);
    Problem(int i, bool c, char * q);
    virtual ~Problem();
    friend ostream & operator << (ostream & out, const Problem &problem);   
    bool operator < (const Problem &problem) const;
    bool operator > (const Problem &problem) const;
    bool operator <= (const Problem &problem) const;
    bool operator >= (const Problem &problem) const;
    int set_importance(int source);
    int set_confidence(bool source);
    int set_question(char * source);
    int display_problem();
    int compare_importance(Problem &source);
    bool check_confidence();
protected:
    int importance;
    bool confidence;
    char * question;
};

class P_node : public Problem
{
public:
    P_node();
    P_node(const P_node &p_node);
    P_node(int i, bool c, char * q);
    virtual ~P_node();
    friend ostream & operator << (ostream & out, const P_node &p_node);
    friend istream & operator >> (istream & in, P_node &p_node);
    P_node & operator = (const P_node &p_node);
    bool operator == (const P_node &p_node) const;
    bool operator != (const P_node &p_node) const;
    bool if_left();
    bool if_right();
    void set_left(P_node * source);
    void set_right(P_node * source);
    P_node *& go_left();
    P_node *& go_right();

protected:
    P_node * left;
    P_node * right;
};
