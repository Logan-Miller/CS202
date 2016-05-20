#include "library.h"

int main()
{
/*
    P_node problem;
    problem.set_importance(7);
    problem.set_confidence(true);
    
    char * temp = new char[20];
    strcpy(temp, "Yo its a problem");

    problem.set_question(temp);
    delete [] temp;
    problem.display_problem();
    cout << endl << endl;
    cout << problem;
    
    P_node p2;
    p2.set_importance(8);
    p2.set_confidence(true);
    
    char * t2 = new char[20];
    strcpy(t2, "hey hey david");

    p2.set_question(t2);
    delete [] t2;
    cout << p2;

    if(problem >= p2) cout << "word" << endl;
    else cout << "nope" << endl;
  */ 
   /* 
    if(problem == problem) cout << "They're the same!" << endl;
    else cout << "They're not the same!" << endl;
    
    problem = problem;
    cout << problem;
  */  
    /*
    cout << endl << endl << endl;
    P_node a;
    cin >> a;
    cout << a;
    */

/*
    int i = 5;
    bool c = true;
    char * q = new char[500];
    strcpy(q, "blah blah blah");

    P_node problem(i, c, q);
    problem.display_problem();
*/

    //TODO TRY THIS SHIT
/*
    Book abook;
    abook.create_problem();
    abook.create_problem();
    abook.create_problem();
    cout << "here" << endl;
    abook.display_all();
  
  */
 //TODO Testing the library class
  
    Library dude;
    dude.auto_populate();
    cout << dude;
    cout << endl << endl << endl;
  //  dude.step_through();
    cout << endl << endl << endl;
   // dude.display_all();

    //Library tom(dude);
    //tom.display_all();


    return 0;
}
