#include "problem.h"

//*******************************************************************************
//**********************Problem Class Functions**********************************
//*******************************************************************************
/*
    int imprtance
    bool confidence
    char * question
*/  

/*
    @desc:
*/
Problem::Problem()
{
    importance = 0;
    confidence = false;
    question = NULL;
}

/*
    @desc:
*/
Problem::Problem(int i, bool c, char * q)
{
    importance = i;
    confidence = c;
    if(q)
    {
        question = new char[strlen(q) + 1];
        strcpy(question, q);
    }
}

/*
    @desc:
*/
Problem::~Problem()
{
    importance = 0;
    confidence = false;
    if(question)
    {
        delete [] question;
    }

    question = NULL;
}

/*
    @desc:
*/
int Problem::set_importance(int source)
{
    importance = source;
    return 1;
}

/*
    @desc:
*/
int Problem::set_confidence(bool source)
{
    confidence = source;
    return 1;
}

/*
    @desc:
*/
int Problem::set_question(char * source)
{
    if(!source) return 0;

    if(question)
    {
        delete [] question;
    }

    question = new char[strlen(source) + 1];
    strcpy(question, source);
    return 1;
}

/*
    @desc:
*/
int Problem::display_problem()
{
    if(!question)
    {
        cout << "There's no problem here!" << endl;
        return 0;
    }    
    
    cout << "Problem: " << question << endl;
    if(confidence) cout << "Confident?: Yes" << endl;
    else cout << "Confident?: No" << endl;
    cout << "Importance level: " << importance << endl;
    return 1;
}

int Problem::compare_importance(Problem &source)
{
    if(importance < source.importance) return 0;
    return 1;
}

//*******************************************************************************
//***********************P_node Class Functions**********************************
//*******************************************************************************
//P_node * left
//P_node * right

/*
    @desc:
*/
P_node::P_node()
{
    left = NULL;
    right = NULL;
}

P_node::P_node(int i, bool c, char * q) : Problem(i, c, q)
{
    left = NULL;
    right = NULL;
}

/*
    @desc:
*/
P_node::~P_node()
{
    left = NULL;
    right = NULL;
}

/*
    @desc:
*/
bool P_node::if_left()
{
    if(left) return true;
    return false;
}

/*
    @desc:
*/
bool P_node::if_right()
{
    if(right) return true;
    return false;
}

/*
    @desc:
*/
void P_node::set_left(P_node * source)
{
    left = source;
    return;
}

/*
    @desc:
*/
void P_node::set_right(P_node * source)
{
    right = source;
    return;
}

/*
    @desc:
*/
P_node *& P_node::go_left()
{
    return left;
}

/*
    @desc:
*/
P_node *& P_node::go_right()
{
    return right;
}

