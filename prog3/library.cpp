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
        cin.ignore(100, '\0');

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
    return;
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



