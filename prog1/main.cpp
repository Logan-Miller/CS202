#include "vehicle.h"

int main()
{
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
    cout << "Here" << endl;
    V_manager myTable;
    cout << "Here" << endl;
    myTable.display_all();
    char * temp = new char[20];
    char * temp2 = new char[20];
    strcpy(temp, "volkswagon");
    strcpy(temp2, "passat");
    myTable.remove_vehicle(temp, temp2);
    myTable.display_all();


//**********************************
    return 0;
}
