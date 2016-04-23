#include "appointment.h"

/*
This program allows the user to make appointments to be picked up by a vehicle
of their choice. Different vehicles calculate fares in different ways. Two 
data structures are used, an array of CLL's to keep track of all available 
vehicles, and a self balancing heap to keep track of the next appointment and
all following appointments. 
*/

int main()
{
    Apt_manager appointments;
    bool running = true;
    char choice;
    
    cout << endl << endl;
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
        cout << endl;
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
            cout << endl;
            appointments.new_apt();
        }

        else if(choice == '2')
        {
            cout << endl;
            if(!appointments.display_all())
            {
                cout << "No current appointments." << endl;
            }
        }

        else if(choice == '3')
        {
            cout << endl;
            if(!appointments.display_next_apt())
            {
                cout << "No current appointments." << endl;
            }
        }

        else if(choice == '4')
        {
            cout << endl;
            if(!appointments.pop_apt())
            {
                cout << "No current appointments." << endl;
            }   
        }

        else if(choice == 'q')
        {
            cout << endl;
            running = false;
        }

        else
        {
            cout << endl;
            cout << "Your response could not be verified, please enter a"
                 << " response from the available choices." << endl;
        }
    }

    cout << "The program will now close." << endl;

    return 0;
}
