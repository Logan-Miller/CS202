#include "book.h"

//*******************************************************************************
//***********************Book Class Functions**********************************
//*******************************************************************************
//char * topic
//P_node * problems
//int num_problems

/*
    @desc: base constructor
*/
Book::Book()
{
    topic = NULL;
    problems = NULL;
    num_problems = 0;
}

/*
    @desc: destructor
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
    @desc: copy constructor
*/
Book::Book(const Book &book)
{
    if(book.topic)
    {
        topic = NULL;
        topic = new char[strlen(book.topic) + 1];
        strcpy(topic, book.topic);
    } 
    else topic = NULL;
    num_problems = book.num_problems;
    copy_tree(problems, book.problems);
}

/*
    @desc: overloaded += operator, allowing for adding a P_node to a book
*/
Book & Book::operator += (P_node *& p_node)
{
    if(!p_node) return *this;
    insert_problem(problems, p_node);
    ++num_problems;
    return *this;
}

/*
    @desc: overloaded + operator allowing for a node to be added toa book
*/
Book operator + (const Book &book, P_node *& p_node)
{
    if(!p_node) return book;
    Book temp1(book);
    P_node * temp2 = new P_node(*p_node);
    temp1.insert_problem(temp1.problems, temp2);
    return temp1;
}

/*
    @desc: overloaded << operator allowing for a book to be output, displaying
           the book's entire tree
*/
ostream & operator << (ostream & out, Book &book)
{
    book.display_all();
    return out;
}

/*
    @desc: function to copy a binary search tree
*/
int Book::copy_tree(P_node *& dest, P_node * source)
{
    if(!source)
    {
        dest = NULL;
        return 0;
    }
    dest = new P_node(*source);
    copy_tree(dest->go_left(), source->go_left());
    copy_tree(dest->go_right(), source->go_right());
    return 1;
}

/*
    @desc: creates a problem and then inserts it to the tree
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
    //TODO
    //insert_problem(problems, temp);
    *this += temp;
    delete [] p;
    ++num_problems;
    return 1;
}

/*
    @desc: TODO automated function for filling a book with given values. 
*/

int Book::auto_populate(char * problem, int importance, bool confidence)
{
    P_node * temp = new P_node(importance, confidence, problem);
    insert_problem(problems, temp);
    ++num_problems;
    return 1;
}

/*
    @desc: sets a book's topic given a char *
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
    @desc: inserts a P_node into the tree
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
    @desc: wrapper function to remove all nodes from the tree
*/
void Book::remove_all()
{
    if(problems) remove_all(problems);
    return;
}

/*
    @desc: removes all nodes from a tree
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
    @desc: wrapper function to display all nodes within a tree
*/
void Book::display_all()
{   
    cout << "Problem set: " << topic << endl 
         << "Number of problems: " << num_problems << endl << endl;
    display_all(problems);
    cout << endl << endl;
    return;
}

/*
    @desc: displays all nodes within a tree
*/
void Book::display_all(P_node * root)
{
    if(!root) return;
    display_all(root->go_right());
    //root->display_problem();
    cout << *root;
    display_all(root->go_left());
    return;
}

/*
    @desc: wrapper function allowing each node in a tree to be checked, allows
           a user to change whether or not they feel comfortable with a given 
           problem
*/
void Book::step_through_problems()
{
    cout << "Problem set: " << topic << endl 
         << "Number of problems: " << num_problems << endl << endl << endl;
    check_problems(problems);
    cout << endl << endl;
    return;
}

/*
    @desc: given the root of a tree, goes to each node in a tree, displays the
           node, and then checks if the user is confident with the given output
*/
void Book::check_problems(P_node *& root)
{
    if(!root) return;
    char response = '\0';
    
    check_problems(root->go_right());
    root->display_problem();
    
    cout << "Do you feel confident with this?(y/n): ";
    cin >> response;
    cin.ignore(100, '\n');
    
    if(response == 'y') root->set_confidence(true);
    else root->set_confidence(false);

    cout << endl;
    
    check_problems(root->go_left());
    return;
}

//*******************************************************************************
//***********************B_node Class Functions**********************************
//*******************************************************************************
//B_node * next

/*
    @desc: constructor
*/
B_node::B_node()
{
    next = NULL;
}

/*
    @desc: copy constructor
*/
B_node::B_node(const B_node &b_node) : Book(b_node)
{
    next = NULL;
}

/*
    @desc: destructor
*/
B_node::~B_node()
{
    next = NULL;
}

/*
    @desc: checks if there is a next
*/
bool B_node::if_next()
{
    if(next) return true;
    return false;
}

/*
    @desc: sets the next pointer
*/
void B_node::set_next(B_node * source)
{
   next = source;
   return;
}

/*
    @desc: returns the next pointer
*/
B_node *& B_node::go_next()
{
    return next;
}

