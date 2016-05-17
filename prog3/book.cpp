#include "book.h"

//*******************************************************************************
//***********************Book Class Functions**********************************
//*******************************************************************************
//char * topic
//P_node * problems
//int num_problems

/*
    @desc:
*/
Book::Book()
{
    topic = NULL;
    problems = NULL;
    num_problems = 0;
}

/*
    @desc:
*/
Book::~Book()
{
    if(topic) delete [] topic;
    topic = NULL;
    remove_all();
    problems = NULL;
    num_problems = 0;
}

/*
    @desc:
*/
int Book::create_problem()
{
    int i = 0;
    char * p = new char[500];
    char response = '\0';
    bool c = false;

    cout << "Enter a problem: ";
    cin.get(p, 500, '\n');
    cin.ignore(500, '\n');

    cout << "Enter the problem's importance: ";
    cin >> i;
    cin.ignore(100, '\n');

    cout << "Are you confident with this problem?(y/n): ";
    cin >> response;
    cin.ignore(100, '\n');
    if(response == 'y') c = true;

    P_node * temp = new P_node(i, c, p);
    insert_problem(problems, temp);
    delete [] p;
    ++num_problems;
    return 1;
}

/*
    @desc:
*/
int Book::set_topic(char * source)
{   
    if(!source) return 0;
    if(topic) delete [] topic;
    topic = new char[strlen(source) + 1];
    strcpy(topic, source);
    return 1;
}

/*
    @desc:
*/
int Book::insert_problem(P_node *& root, P_node *& source)
{
    if(!root)
    {
        root = source;
        return 1;
    }
    
    //if the source's importance is greater than or equal to the current
    //problems importance, insert to the right.
    if(!root->compare_importance(*source))
    {
        return insert_problem(root->go_right(), source);
    }

    else
    {
        return insert_problem(root->go_left(), source);
    }
}

/*
    @desc:
*/
void Book::remove_all()
{
    if(problems) remove_all(problems);
    return;
}

/*
    @desc:
*/
void Book::remove_all(P_node *& root)
{   
    if(!root) return;
    remove_all(root->go_left());
    remove_all(root->go_right());
    delete root;
    root = NULL;
    return;
}

/*
    @desc:
*/
void Book::display_all()
{
    display_all(problems);
    return;
}

/*
    @desc:
*/
void Book::display_all(P_node * root)
{
    if(!root) return;
    display_all(root->go_right());
    root->display_problem();
    display_all(root->go_left());
    return;
}
//*******************************************************************************
//***********************B_node Class Functions**********************************
//*******************************************************************************
//B_node * next

/*
    @desc:
*/
B_node::B_node()
{
    next = NULL;
}

/*
    @desc:
*/
B_node::~B_node()
{
    next = NULL;
}

/*
    @desc:
*/
bool B_node::if_next()
{
    if(next) return true;
    return false;
}

/*
    @desc:
*/
void B_node::set_next(B_node * source)
{
   next = source;
   return;
}

/*
    @desc:
*/
B_node *& B_node::go_next()
{
    return next;
}

