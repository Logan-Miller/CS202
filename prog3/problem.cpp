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
    @desc: Base constructor for the problem class
*/
Problem::Problem()
{
    importance = 0;
    confidence = false;
    question = NULL;
}

/*
    @desc: Copy constructor for the problem class
*/
Problem::Problem(const Problem &problem)
{
    importance = problem.importance;
    confidence = problem.confidence;
    if(problem.question)
    {
        question = new char[strlen(problem.question) + 1];
        strcpy(question, problem.question);
    }

    else question = NULL;
}

/*
    @desc: Constructor with passed in arguments for the problem class
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
    @desc: Destructor
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
    @desc: Overloaded << operator allowing for output of the problem class
*/
ostream & operator << (ostream & out, const Problem &problem)
{   
    if(!problem.question)
    {
        return out << "There's no problem here!" << endl;
    }    
    
    out << "Problem: " << problem.question << endl;
    if(problem.confidence) out << "Confident?: Yes" << endl;
    else out << "Confident?: No" << endl;
    return out << "Importance level: " << problem.importance << endl;
}

/*
    @desc: Overloaded < operator for the problem class, compares one problem to
           another, comparing the problems's importance
*/
bool Problem::operator < (const Problem &problem) const
{
    if(importance < problem.importance) return true;
    return false;
}

/*
    @desc: Overloaded > operator for the problem class, compares one problem to
           another, comparing the problems's importance
*/
bool Problem::operator > (const Problem &problem) const
{
    if(importance > problem.importance) return true;
    return false;
}

/*
    @desc: Overloaded <= operator for the problem class, compares one problem to
           another, comparing the problems's importance
*/
bool Problem::operator <= (const Problem &problem) const
{
    if(importance <= problem.importance) return true;
    return false;
}

/*
    @desc: Overloaded >= operator for the problem class, compares one problem to
           another, comparing the problems's importance
*/
bool Problem::operator >= (const Problem &problem) const
{
    if(importance >= problem.importance) return true;
    return false;
}

/*
    @desc: setter to set a problems importance
*/
int Problem::set_importance(int source)
{
    importance = source;
    return 1;
}

/*
    @desc: setter to set a problems confidence
*/
int Problem::set_confidence(bool source)
{
    confidence = source;
    return 1;
}

/*
    @desc: setter to set a problems question
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
    @desc: Display function to display all of a problems data
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

/*
    @desc: comparison function to compare two problems importance
*/
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
    @desc: base constructor for P_node
*/
P_node::P_node()
{
    left = NULL;
    right = NULL;
}

/*
    @desc: Copy constructor for P_node
*/
P_node::P_node(const P_node &p_node) : Problem(p_node)
{
    left = NULL;
    right = NULL;
}

/*
    @desc: Constructor for P_node given values
*/
P_node::P_node(int i, bool c, char * q) : Problem(i, c, q)
{
    left = NULL;
    right = NULL;
}

/*
    @desc: destructor
*/
P_node::~P_node()
{
    left = NULL;
    right = NULL;
}

/*
    @desc: Overloaded << operator allowing for output of a P_node.
*/
ostream & operator << (ostream & out, const P_node &p_node)
{
    if(!p_node.question)
    {
        return out << "There's no problem here!" << endl;
    }    
    
    out << "Problem: " << p_node.question << endl;
    if(p_node.confidence) out << "Confident?: Yes" << endl;
    else out << "Confident?: No" << endl;
    return out << "Importance level: " << p_node.importance << endl;
}

/*
    @desc: Overloaded >> operator allowing for input to a P_node
*/
istream & operator >> (istream & in, P_node &p_node)
{
    char * q = new char[500];
    int i;
    char c;

    cout << "Enter a problem: ";
    cin.get(q, 500, '\n');
    cin.ignore(500, '\n');

    if(p_node.question)
    {
        delete [] p_node.question;
    }

    p_node.question = new char[strlen(q) + 1];
    strcpy(p_node.question, q);
    
    cout << "Enter importance: ";
    cin >> i;
    cin.ignore(100, '\n');
    p_node.importance = i;
    
    cout << "Confident?(y/n): ";
    cin >> c;
    cin.ignore(100, '\n');
    if(c == 'y') p_node.confidence = true;
    else p_node.confidence = false;
    return in;
}

/*
    @desc: overloaded assignment operator, allowing for copying
*/
P_node & P_node::operator = (const P_node &p_node)
{
    if(this == &p_node) return *this;
    set_question(p_node.question);
    set_confidence(p_node.confidence);
    set_importance(p_node.importance);
    return *this;
}

/*
    @desc: overloaded comparison operator, comparing two P_nodes to see if 
           they're the same
*/
bool P_node::operator == (const P_node &p_node) const
{
    if(confidence == p_node.confidence && importance == p_node.importance && 
       strcmp(question, p_node.question) == 0) return true;
    return false;
}

/*
    @desc: Overloaded != operator allowing for checking if two nodes are not
           equivalent
*/
bool P_node::operator != (const P_node &p_node) const
{
    if(*this == p_node) return false;
    return true;
}

/*
    @desc: checks if there is a left node
*/
bool P_node::if_left()
{
    if(left) return true;
    return false;
}

/*
    @desc: checks if ther is a right node
*/
bool P_node::if_right()
{
    if(right) return true;
    return false;
}

/*
    @desc: sets the left node
*/
void P_node::set_left(P_node * source)
{
    left = source;
    return;
}

/*
    @desc: sets the right node
*/
void P_node::set_right(P_node * source)
{
    right = source;
    return;
}

/*
    @desc: returns the left node
*/
P_node *& P_node::go_left()
{
    return left;
}

/*
    @desc: returns the right node
*/
P_node *& P_node::go_right()
{
    return right;
}

