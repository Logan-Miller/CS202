#include "library.h"

//*******************************************************************************
//**********************Library Class Functions**********************************
//*******************************************************************************
//B_node * head
//int num_books

/*
    @desc: basic constructor
*/
Library::Library()
{
    head = NULL;
    num_books = 0;
}

/*
    @desc: copy constructor 
*/
Library::Library(const Library &library)
{
    num_books = library.num_books;
    copy_list(head, library.head);
}

/*
    @desc: destructor
*/
Library::~Library()
{
    remove_all();
}

/*
    @desc: overloaded << operator, allowing for an entire library's content to 
           be displayed
*/
ostream & operator << (ostream & out, Library &library)
{
   library.display_all();
   return out;
}

/*
    @desc: a book is essentially a manager for a BST. this functions allows the
           the user to create a bst, continually adding problems to the book as
           long as the wish.
*/
int Library::create_book()
{
    B_node * temp = new B_node;
    char * temp2 = new char[50];
    bool running = true;
    char response = '\0';

    cout << "What is the title?: ";
    cin.get(temp2, 50, '\n');
    cin.ignore(50, '\n');
    temp->set_topic(temp2);

    while(running)
    {
        cout << "Would you like to add a problem?(y/n): ";
        cin >> response;
        cin.ignore(100, '\n');

        if(response == 'y')
        {
            temp->create_problem();
        }

        else running = false;
    }

    delete [] temp2;
    
    ++num_books;
    insert_book(head, temp);
    return 1;
}

/*
    @desc: TODO function to autopopulate list of trees. this function is only
           so for testing and grading purposes, Populates the library with 3
           books, each with a tree of 3 problems.
*/
int Library::auto_populate()
{
    //The first BST to be inserted
    B_node * t1 = new B_node;
    char * t1_topic = new char[50];
    strcpy(t1_topic, "Binary Search Trees");
    t1->set_topic(t1_topic);
    char * t1_p1 = new char[100];
    strcpy(t1_p1, "Return the farthest right-leaf's data");
    char * t1_p2 = new char[100];
    strcpy(t1_p2, "Find the roots inorder successor");
    char * t1_p3 = new char[100];
    strcpy(t1_p3, "Display every node in the tree");
    t1->auto_populate(t1_p1, 5, false);
    t1->auto_populate(t1_p2, 4, false);
    t1->auto_populate(t1_p3, 6, false);
    ++num_books;
    insert_book(head, t1);

    //The second BST to be inserted
    B_node * t2 = new B_node;
    char * t2_topic = new char[50];
    strcpy(t2_topic, "Circular Linked Lists");
    t2->set_topic(t2_topic);
    char * t2_p1 = new char[100];
    strcpy(t2_p1, "Turn a CLL into a LLL");
    char * t2_p2 = new char[100];
    strcpy(t2_p2, "Make a deep copy of a CLL");
    char * t2_p3 = new char[100];
    strcpy(t2_p3, "Count the total nodes in a CLL");
    t2->auto_populate(t2_p1, 5, false);
    t2->auto_populate(t2_p2, 4, false);
    t2->auto_populate(t2_p3, 6, false);
    ++num_books;
    insert_book(head, t2);

    //The third BST to be inserted
    B_node * t3 = new B_node;
    char * t3_topic = new char[50];
    strcpy(t3_topic, "Doubly Linked Lists");
    t3->set_topic(t3_topic);
    char * t3_p1 = new char[100];
    strcpy(t3_p1, "Insert a new node in front of every node in a DLL");
    char * t3_p2 = new char[100];
    strcpy(t3_p2, "Find all nodes with unique data in a DLL");
    char * t3_p3 = new char[100];
    strcpy(t3_p3, "Turn a DLL into a doubly CLL");
    t3->auto_populate(t3_p1, 5, false);
    t3->auto_populate(t3_p2, 4, false);
    t3->auto_populate(t3_p3, 6, false);
    ++num_books;
    insert_book(head, t3);

    //Clean up data
    delete [] t1_topic;
    delete [] t1_p1;
    delete [] t1_p2;
    delete [] t1_p3;
    delete [] t2_topic;
    delete [] t2_p1;
    delete [] t2_p2;
    delete [] t2_p3;
    delete [] t3_topic;
    delete [] t3_p1;
    delete [] t3_p2;
    delete [] t3_p3;

    return 1;
}

/*
    @desc: inserts a b_node (a book) into the linear linked list that the 
           library class manages
*/
int Library::insert_book(B_node *& head, B_node *& source)
{
    if(!head)
    {
        head = source;
        return 1;
    }

    return insert_book(head->go_next(), source);
}

/*
    @desc: wrapper function to display all the data within the library
*/
void Library::display_all()
{
    display_all(head);
    return;
}

/*
    @desc: displays all the data within the library
*/
void Library::display_all(B_node * head)
{
    if(!head) return;
    //head->display_all();
    cout << *head;
    display_all(head->go_next());
    return;
}

/*
    @desc: TODO
*/
int Library::step_through()
{
    return step_through(head);
}

/*
    @desc: TODO
*/
int Library::step_through(B_node *& head)
{
    if(!head) return 0;
    head->step_through_problems();
    return step_through(head->go_next());
}

/*
    @desc: wrapper function to remove all data in the library
*/
void Library::remove_all()
{
    remove_all(head);
    return;
}

/*
    @desc: removes all the data within a linear linked list
*/
void Library::remove_all(B_node *& head)
{
    if(!head) return;
    remove_all(head->go_next());
    delete head;
    head = NULL;
    --num_books;
    return;
}

/*
    @desc: Copy function used to copy the library's linear linked list
*/
int Library::copy_list(B_node *& dest, B_node * source)
{
    if(!source)
    {
        dest = NULL;
        return 0;
    }
    
    dest = new B_node(*source);
    copy_list(dest->go_next(), source->go_next());
    return 1;
}

/*
    @desc: 
*/
void Library::random_topics()
{
    srand(time(NULL));
    int index = rand() % num_books;
    if(index == 0) index = num_books;
    random_topics(head, index);
    cout << endl << endl << index << endl << endl;
}

/*
    @desc: 
*/
void Library::random_topics(B_node *& head, int index)
{
    if(!head) return;
    if(index != 1)
    {
        --index;
        random_topics(head->go_next(), index);
    }
    
    else
    {
        if(!head->all_confident())
        {
            head->step_through_problems();            
        }
    }

    return;
}

/*
    @desc: 
*/
bool Library::all_confident()
{
    return all_confident(head);
}

/*
    @desc: 
*/
bool Library::all_confident(B_node * head)
{
    if(!head) return true;
    if(!head->all_confident()) return false;
    return all_confident(head->go_next());
}











