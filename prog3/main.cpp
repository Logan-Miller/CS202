// Logan Miller
// CS 202
// Prog 3

#include "library.h"

//Client program to allow a user to study different materials. They can input
//new materials to be studied, display all the materials given, or be given a 
//topic to study.
int main()
{   
    srand(time(NULL));
    bool running = true;
    char response = '\0';
    Library study;
    
    //This function is not required, it is simply for testing the program. This
    //function populates the object with 3 different books (trees) each with 3
    //problems.
    study.auto_populate();

    cout << "Welcome. This program allows you to create different sets of"
         << " problems and" << endl << "then add however many problems to them." 
         << endl << endl << endl;

    while(running)
    {
        cout << "Enter 1 to study a topic program." << endl;
        cout << "Enter 2 to create a new set of problems." << endl;
        cout << "Enter 3 to display all study materials." << endl;
        cout << "Enter q to quit." << endl;
        cout << "Enter your choice now: ";
        cin >> response;
        cin.ignore(100, '\n');
        
        //Case 1: The user wants to get a random topic to study
        if(response == '1')
        {   
            cout << endl << endl;

            if(study.all_confident())
            {
                cout << endl << endl;
                cout << "You're now confident on all study materials offered!"
                     << endl << endl << endl;
            }
            else
            {
                study.random_topics();
            }
        }
        
        //Case 2: The user wants to create a new set of problems (A new BST of 
        //problems)
        else if(response == '2')
        {
            cout << endl << endl;
            study.create_book();
            cout << endl << endl;
        }
        
        //Case 3: The user wants to view all available study material
        else if(response == '3')
        {   
            cout << endl << endl;
            cout << "All study materials: " << endl << endl;
            cout << study;
        }
        
        //Case 4: The user wishes to quit the program
        else if(response == 'q') running = false;
        
        //Case 5: Invalid input from the user. 
        else
        {
            cout << "Input not recognized." << endl;
        }
    }
    
    cout << endl << endl << "The program will now close." << endl;

    return 0;
}
