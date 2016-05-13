#include "library.h"

int main()
{

    P_node problem;
    problem.set_importance(5);
    problem.set_confidence(true);
    
    char * temp = new char[20];
    strcpy(temp, "Yo its a problem");

    problem.set_question(temp);
    delete [] temp;
    problem.display_problem();

    return 0;
}
