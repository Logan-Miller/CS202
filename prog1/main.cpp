#include "appointment.h"

int main()
{
    Apt_manager appointments;
    bool running = true;
    char choice;

    cout << "Welcome to the appointment manager. This program allows you to\n"
         << "create appointments to catch a ride in a variety of vehicles.\n"
         << "Three types of a vehicles are offered. Our standard vehicles\n"
         << "are run on a pay by the mile fee. Premium vehicles are are\n"
         << "charged by the mile as well, but do to being luxary vehicles\n"
         << "they incur a higher per-mile rate, as well as a minimum fare.\n"
         << "Our group vehicles are offered for larger groups requiring a\n"
         << "little more space than the average ride offers. Group vehicles\n"
         << "are charged per person. The following simple prompts will walk\n"
         << "you through keeping track of all of your appointments." << endl
         << endl;
    
    cout << "The following options are available:" << endl;

    while(running)
    {
        choice = '\n';
        cout << "To create an appointment type      (1)" << endl
             << "To view all appointments type      (2)" << endl
             << "To view the next appointment type  (3)" << endl
             << "If the appointment has passed type (4)" << endl
             << "To end the program type            (q)" << endl
             << "Enter your choice now: ";
    
        cin >> choice;
        cin.ignore(100, '\n');

        if(choice == '1')
        {
            appointments.new_apt();
        }

        else if(choice == '2')
        {
            if(!appointments.display_all())
            {
                cout << "No current appointments." << endl;
            }
        }

        else if(choice == '3')
        {
            if(!appointments.display_next_apt())
            {
                cout << "No current appointments." << endl;
            }
        }

        else if(choice == '4')
        {
            if(!appointments.pop_apt())
            {
                cout << "No current appointments." << endl;
            }   
        }

        else if(choice == 'q')
        {
            running = false;
        }

        else
        {
            cout << "Your response could not be verified, please enter a"
                 << " response from the available choices." << endl;
        }
    }


//TESTING FOR VEHICLE FUNCTIONS
    /*
    Vehicle * vehicle = new Vehicle;
    char * ptr1 = new char[10];
    char * ptr2 = new char[10];
    char * ptr3 = new char[10];
    strcpy(ptr1, "volks");
    strcpy(ptr2, "passaat");
    strcpy(ptr3, "BFW");
    vehicle->set_make(ptr1);
    vehicle->set_model(ptr2);
    vehicle->set_license(ptr3);
    vehicle->display();
    
    Vehicle * another = new Vehicle(*vehicle);
    delete vehicle;
    another->display();
    */
//*********************************

//TESTING FOR V_node functions
 /*   
    V_node * temp = new V_node;
    char * ptr1 = new char[10];
    char * ptr2 = new char[10];
    char * ptr3 = new char[10];
    strcpy(ptr1, "volks");
    strcpy(ptr2, "passaat");
    strcpy(ptr3, "BFW");
    temp->set_make(ptr1);
    temp->set_model(ptr2);
    temp->set_license(ptr3);
    temp->display();
    
    if(temp->if_next() == false) cout << "\nfalse\n";
    
    V_node * temp2 = new V_node(*temp);
    delete temp;
    temp2->display();
   */ 

    /*
    V_node * next = new V_node;
    
    char * ptr4 = new char[10];
    char * ptr5 = new char[10];
    char * ptr6 = new char[10];
    strcpy(ptr4, "v");
    strcpy(ptr5, "p");
    strcpy(ptr6, "B");
    next->set_make(ptr4);
    next->set_model(ptr5);
    next->set_license(ptr6);
    
    temp->set_next(next);
    if(temp->if_next() == true) cout << "\ntrue\n";
    temp = temp->go_next();
    temp->display();
    */

//**********************************

//TESTING FOR V_manager functions
    /*
    cout << "Here" << endl;
    V_manager myTable;
    cout << "Here" << endl;
    myTable.display_all();
    char * temp = new char[20];
    char * temp2 = new char[20];
    strcpy(temp, "volkswagon");
    strcpy(temp2, "passat");
    
    cout << endl << endl << endl;
    //myTable.remove_vehicle(temp, temp2);
    
    
    myTable.display_all();

    cout << endl << endl;

    myTable.remove_all();
    myTable.display_all();
    */
//**********************************

//TESTING FOR Apt class
/*
    char * make = new char[50];
    char * model = new char[50];
    char * license = new char[50];
    strcpy(make, "passat");
    strcpy(model, "volks");
    strcpy(license, "777");
    V_node * node = new V_node;
    node->set_make(make);
    node->set_model(model);
    node->set_license(license);
    
    node->display();

    Apt myApt(*node);
    myApt.display_apt();
    delete node;

    myApt.display_apt();
*/

//***********************************

//TESTING FOR exp class
/*
    char * make = new char[50];
    char * model = new char[50];
    char * license = new char[50];
    strcpy(make, "passat");
    strcpy(model, "volks");
    strcpy(license, "777");
    V_node * node = new V_node;
    node->set_make(make);
    node->set_model(model);
    node->set_license(license);
    
    node->display();

    Exp myExp(*node);
    myExp.display_apt();
*/
//***********************************

//TESTING FOR standard class
/*
    char * make = new char[50];
    char * model = new char[50];
    char * license = new char[50];
    strcpy(make, "passat");
    strcpy(model, "volks");
    strcpy(license, "777");
    V_node * node = new V_node;
    node->set_make(make);
    node->set_model(model);
    node->set_license(license);
    
    node->display();
    Standard_exp myExp(*node);
    myExp.display_apt();
*/
//***********************************

//TESTING FOR premium class
/*
    char * make = new char[50];
    char * model = new char[50];
    char * license = new char[50];
    strcpy(make, "passat");
    strcpy(model, "volks");
    strcpy(license, "777");
    V_node * node = new V_node;
    node->set_make(make);
    node->set_model(model);
    node->set_license(license);

    node->display();
    Premium_exp myExp(*node);
    myExp.display_apt();
*/
//

//TESTING FOR group class
/*
    char * make = new char[50];
    char * model = new char[50];
    char * license = new char[50];
    strcpy(make, "passat");
    strcpy(model, "volks");
    strcpy(license, "777");
    V_node * node = new V_node;
    node->set_make(make);
    node->set_model(model);
    node->set_license(license);

    node->display();
    Group_exp * myExp = new Group_exp(*node);
    myExp->display_apt();
    delete myExp;
*/

//***********************************

//Testing for A_node class
/*
    char * make = new char[50];
    char * model = new char[50];
    char * license = new char[50];
    strcpy(make, "passat");
    strcpy(model, "volks");
    strcpy(license, "777");
    V_node * node = new V_node;
    node->set_make(make);
    node->set_model(model);
    node->set_license(license);

    node->display();
    Group_exp * myExp = new Group_exp(*node);

    A_node * myNode = new A_node(*myExp);
    myNode->display_node();
*/
//************************************

//TESTING FOR APT MANAGER CLASS

    //Apt_manager me;
    //me.new_apt();
    //me.display_all();
    //me.pop_apt();
    //me.display_all();
//************************************

    cout << "The program will now close." << endl;

    return 0;
}
