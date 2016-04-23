#include "vehicle.h"


//*****************************************************************************
//*********************** Vehicle class ***************************************
//*****************************************************************************
/*
The vehicle class has a make model and license. It has functions to handle its
corresponding memory.
*/

/*
   @desc: initially sets a vehicle's make, model and license to NULL
*/
Vehicle::Vehicle()
{
    make = NULL;
    model = NULL;
    license = NULL;
}

/*
   @desc: Takes another vehicle object, finds the length of the source vehicle
          make, model and license; allocates memory for the a new make, model,
          and license. Strcpys the make model and license to the destination
          vehicle.
 */
Vehicle::Vehicle(const Vehicle &vehicle)
{
    int model_l = strlen(vehicle.model);
    int make_l = strlen(vehicle.make);
    int license_l = strlen(vehicle.license);

    model = new char [model_l + 1];
    make = new char [make_l + 1];
    license = new char [license_l + 1];

    strcpy(model, vehicle.model);
    strcpy(make, vehicle.make);
    strcpy(license, vehicle.license);
}

/*
   @desc: Checks if the make, model and license are not NULL, if they have data
          the data is deallocated. The pointers are then set to NULL.
*/
Vehicle::~Vehicle()
{   
    if(make)
    {
        delete [] make;
    }

    if(model)
    {
        delete [] model;
    }

    if(license)
    {
        delete [] license;
    }

    make = NULL;
    model = NULL;
    license = NULL;
}

/*
   @desc: recieves a char *, proceeds to make a deep copy of the supplied
          array of characters.
*/
void Vehicle::set_make(char * source)
{
    int length = strlen(source);
    make = new char[length];
    strcpy(make, source);
    return;
}

/*
   @desc: recieves a char *, proceeds to make a deep copy of the supplied
          array of characters.
 */
void Vehicle::set_model(char * source)
{
    int length = strlen(source);
    model = new char[length];
    strcpy(model, source);
    return;
}

/*
   @desc: recieves a char *, proceeds to make a deep copy of the supplied
          array of characters.
 */
void Vehicle::set_license(char * source)
{
    int length = strlen(source);
    license = new char[length];
    strcpy(license, source);
    return;
}

/*
   @desc: displays the vehicle's make, model and license.
*/
void Vehicle::display()
{
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "License: " << license << endl;
    return;
}

//*****************************************************************************
//********************** V_node class *****************************************
//*****************************************************************************
/*
A V_node IS A vehicle, plus the ability to link to other V_nodes
*/

/*
   @desc: base constructor for the V_node class. Sets the node's pointer to NULL
 */
V_node::V_node()
{
    next = NULL;
}

/*
    @desc: Copy constructor, copies a supplied V_node. Uses an initialization
           list to copy the base class data. 
*/
V_node::V_node(const V_node &v_node) : Vehicle(v_node)
{
    next = v_node.next;
}


/*
   @desc: base destructor for the V_node class. Deletes dynamic memory.
*/
V_node::~V_node()
{
    next = NULL;
}

/*
   @desc: set_next sets the current V_node's next pointer to the pointer 
   passed into the function.
*/
void V_node::set_next(V_node * source)
{
    if(source) next = source;

    else next = NULL;

    return;
}

/*
   @desc: go_next returns the V_nodes next pointer, allowing for traversal to
   the "next" node.
*/
V_node *& V_node::go_next()
{
    return next;
}

/*
   @desc: if_next checks whether or not there is a next V_node. If the pointer
   null it returns false, otherwise it returns true
*/
bool V_node::if_next() const
{
    if(next) return true;
    return false;
}

/*
   @desc: returns true if the source is the same as the node's make.
*/
bool V_node::compare_make(char * source)
{
    if(!make) return false;
    
    if(strcmp(source, make) == 0)
    {
        return true;
    } 

    return false;
}

/*
   @desc: returns truee if the source is the same as the node's model
*/
bool V_node::compare_model(char * source)
{
    if(!model) return false;
    
    if(strcmp(source, model) == 0)
    {
        return true;
    } 

    return false;
}

//*****************************************************************************
//******************************* V_manager class *****************************
//*****************************************************************************
/*
A V_manager manages a table of vehicle nodes. It reads in all vehicles from an
external data file.
*/


/*
   @desc: set the array size, set each index to NULL. Calls the file_read
          function to fill the array.
*/
V_manager::V_manager()
{
    MAX = 3;
    table = new V_node * [MAX];
    for(int i = 0; i < MAX; ++i)
    {
        table[i] = NULL;
    }
    
    file_read();
}

/*
   @desc: calls the remove_all function to delete all nodes in the array of CLL
          it then deletes the table and sets the pointer to NULL;
*/
V_manager::~V_manager()
{
    remove_all();

    delete [] table;
    table = NULL;
}

/*
   @desc: Reads in from an external data file, line by line. each line is a 
          colon seperated list. parses the data into a new V_node and an index,
          and then passes this to an insert_function.

*/
void V_manager::file_read()
{
    ifstream file_in;
    file_in.open("vehicles.txt");
    if(file_in)
    {
        while(!file_in.eof())
        {
            V_node * temp = new V_node;
            char * ptr1 = new char[50];
            char * ptr2 = new char[50];
            char * ptr3 = new char[50];
            char * ptr4 = new char[50];

            file_in.getline(ptr1, 50, ':');
            file_in.getline(ptr2, 50, ':');
            file_in.getline(ptr3, 50, ':');
            file_in.getline(ptr4, 50, '\n');

            temp->set_make(ptr2);
            temp->set_model(ptr3);
            temp->set_license(ptr4);

            insert_vehicle(ptr1, temp);

            delete [] ptr1;
            delete [] ptr2;
            delete [] ptr3;
            delete [] ptr4;
            file_in.peek();
        }    
    }

    file_in.close();
    return;
}

/*
   @desc: Given an index of which CLL to insert to and the node to insert, 
          the insert function compares the index to find which array index
          it should insert at. it then checks if a list already exists at the
          index, if so it adds using the tail (table[i]) or creates tail
*/
void V_manager::insert_vehicle(char * index, V_node * &source)
{
    if(strcmp(index, "1") == 0)
    {
        if(!table[0])
        {
            table[0] = source;
            table[0]->set_next(table[0]);
            return;
        }

        V_node * temp = source;
        temp->set_next(table[0]->go_next());
        table[0]->set_next(temp);
        table[0] = temp;
        return;
    }

    else if(strcmp(index, "2") == 0)
    {
        if(!table[1])
        {
            table[1] = source;
            table[1]->set_next(table[1]);
            return;
        }

        V_node * temp = source;
        temp->set_next(table[1]->go_next());
        table[1]->set_next(temp);
        table[1] = temp;
        return;
    }

    else
    {
        if(!table[2])
        {
            table[2] = source;
            table[2]->set_next(table[2]);
            return;
        }

        V_node * temp = source;
        temp->set_next(table[2]->go_next());
        table[2]->set_next(temp);
        table[2] = temp;
        return;
    }
}

/*
   @desc: Calls each display function
*/
void V_manager::display_all()
{   
    display_standard();
    display_premium();
    display_group();
    return;
}

/*
   @desc: If there is no tail, it returns. Breaks the chain, then displays all
          v_nodes. it then reconnects tail to head
*/
void V_manager::display_standard()
{
    if(!table[0]) return;

    V_node * head = table[0]->go_next();
    V_node * current = head;

    table[0]->set_next(NULL);

    while(current)
    {
        current->display();
        current = current->go_next();
    }

    table[0]->set_next(head);

    return;
}

/*
   @desc: If there is no tail, it returns. Breaks the chain, then displays all
          v_nodes. it then reconnects tail to head

*/
void V_manager::display_premium()
{
    if(!table[1]) return;

    V_node * head = table[1]->go_next();
    V_node * current = head;

    table[1]->set_next(NULL);

    while(current)
    {
        current->display();
        current = current->go_next();
    }

    table[1]->set_next(head);

    return;
}

/*
   @desc: If there is no tail, it returns. Breaks the chain, then displays all
          v_nodes. it then reconnects tail to head

*/
void V_manager::display_group()
{
    if(!table[2]) return;
    V_node * head = table[2]->go_next();
    V_node * current = table[2];

    table[2]->set_next(NULL);

    while(current)
    {
        current->display();
        current = current->go_next();
    }

    table[2]->set_next(head);

    return;
}

/*
   @desc: Given two search parameters, a make and a model, it breaks each CLL
          calls a recursive helper function to do the actual search and 
          deletion, and then reconnects the chain. If a match to delete is 
          found, it will not search through the other CLL's
*/
void V_manager::remove_vehicle(char * v_make, char * v_model)
{
    int count = 0;

    if(table[0] && count == 0)
    {
        V_node * head = table[0]->go_next();
        V_node * current = head;
        table[0]->set_next(NULL);
        count += remove_helper(head, current, v_make, v_model);
        if(head)
        {
            table[0]->set_next(head);
        }
    }

    if(table[1] && count == 0)
    {
        V_node * head = table[1]->go_next();
        V_node * current = head;
        table[1]->set_next(NULL);
        count += remove_helper(head, current, v_make, v_model);
        if(head)
        {
            table[1]->set_next(head);
        }
    }    

    if(table[2] && count == 0)
    {
        V_node * head = table[2]->go_next();
        V_node * current = head;
        table[2]->set_next(NULL);
        count += remove_helper(head, current, v_make, v_model);
        if(head)
        {
            table[2]->set_next(head);
        }
    }    

    return;
}

/*
   @desc: recursive function, given a head, a current and two search parameters
          it searches for a node to delete.
*/
int V_manager::remove_helper(V_node * &head, V_node * &current, char * v_make, 
                             char * v_model)
{
    if(!current) return 0;
    
    if(current->compare_make(v_make) && current->compare_model(v_model))
    {
        if(current == head)
        {
            head = head->go_next();    
        }

        V_node * temp = current;
        current = current->go_next();
        delete temp;
        temp = NULL;
        return 1 + remove_helper(head, current, v_make, v_model);
    }
    
    return remove_helper(head, current->go_next(), v_make, v_model);
} 


/*
   @desc: removes all nodes from the table
*/
void V_manager::remove_all()
{
    for(int i = 0; i < MAX; ++i)
    {
        if(table[i])
        {
            V_node * head = table[i]->go_next();
            table[i]->set_next(NULL);
            remove_all_helper(head);
            table[i] = NULL;
        }
    }   
}

/*
   @desc: helper function for the remove all function, given a head pointer 
          it recursively deletes all of a CLL
*/
void V_manager::remove_all_helper(V_node * &head)
{
    if(!head) return;
    
    V_node * temp = head->go_next();
    head->set_next(NULL);
    delete head;
    head = NULL;

    remove_all_helper(temp);
    return;
}

/*
    @desc: wrapper function to call the actual function to search for a vehicle
           returns a pointer to a vehicle. Is given the index of the CLL to
           search through.
*/
Vehicle * V_manager::get_vehicle(int i, char * v_make, char * v_model)
{
    if(table[i])
    {
        V_node * temp = table[i]->go_next();
        table[i]->set_next(NULL);

        Vehicle * car = get_vehicle_helper(temp, v_make, v_model);
        
        table[i]->set_next(temp);

        return car;
    }
}

/*
    @desc: recursive function to search for a vehicle, when found it returns
           a pointer to the matched vehicle.
*/
Vehicle * V_manager::get_vehicle_helper(V_node * head, char * v_make,
                                        char * v_model)
{
    if(!head) return NULL;
    if(head->compare_make(v_make) && head->compare_model(v_model))
    {
        return head;
    }

    return get_vehicle_helper(head->go_next(), v_make, v_model);
}






