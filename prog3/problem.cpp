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
    @desc:
*/
Problem::Problem()
{
    importance = 0;
    confidence = false;
    question = NULL;
}

/*
    @desc:
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
    @desc:
*/
int Problem::set_importance(int source)
{
    importance = source;
    return 1;
}

/*
    @desc:
*/
int Problem::set_confidence(bool source)
{
    confidence = source;
    return 1;
}

/*
    @desc:
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
    @desc:
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

//*******************************************************************************
//***********************P_node Class Functions**********************************
//*******************************************************************************


