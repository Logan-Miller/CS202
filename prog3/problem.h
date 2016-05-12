#include <iostream>
using namespace std;

//TODO
class Problem
{
public:
    Problem();
    ~Problem();
    int set_importance(int source);
    int set_confidence(bool source);
    int set_question(char * source);

protected:
    int importance;
    bool confidence;
    char * question;
};
