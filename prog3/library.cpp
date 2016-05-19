#include "library.h"

//*******************************************************************************
//**********************Library Class Functions**********************************
//*******************************************************************************
//B_node * head
//int num_books

/*
    @desc:
*/
Library::Library()
{
    head = NULL;
    num_books = 0;
}

/*
    @desc:
*/
Library::~Library()
{
    remove_all();
}

/*
    @desc:
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
    @desc: TODO function to autopopulate list of trees.
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
    @desc:
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
    @desc:
*/
void Library::display_all()
{
    display_all(head);
    return;
}

/*
    @desc:
*/
void Library::display_all(B_node * head)
{
    if(!head) return;
    head->display_all();
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
    @desc:
*/
void Library::remove_all()
{
    remove_all(head);
    return;
}

/*
    @desc:
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



