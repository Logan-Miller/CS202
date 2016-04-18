#include "vehicle.h"


//*****************************************************************************
//*********************** Vehicle class ***************************************
//*****************************************************************************

/*
   @desc:
 */
Vehicle::Vehicle()
{
    cout << "vehicle constructor" << endl;
    make = NULL;
    model = NULL;
    license = NULL;
}

/*
   @desc:
 */
Vehicle::Vehicle(const Vehicle &vehicle)
{
    cout << "Vehicle copy constructor" << endl;
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
   @desc:
 */
Vehicle::~Vehicle()
{
    if(make)
    {
        delete make;
    }

    if(model)
    {
        delete model;
    }

    if(license)
    {
        delete license;
    }

    make = NULL;
    model = NULL;
    license = NULL;
}

/*
   @desc:
 */
void Vehicle::set_make(char * source)
{
    int length = strlen(source);
    make = new char[length];
    strcpy(make, source);
    return;
}

/*
   @desc:
 */
void Vehicle::set_model(char * source)
{
    int length = strlen(source);
    model = new char[length];
    strcpy(model, source);
    return;
}

/*
   @desc:
 */
void Vehicle::set_license(char * source)
{
    int length = strlen(source);
    license = new char[length];
    strcpy(license, source);
    return;
}

/*
   @desc:
 */
void Vehicle::display()
{
    cout << "\nMake: " << make;
    cout << "\nModel: " << model;
    cout << "\nLicense: " << license;
    return;
}

//*****************************************************************************
//********************** V_node class *****************************************
//*****************************************************************************

/*
   @desc: base constructor for the V_node class.
 */
V_node::V_node()
{
    cout << "V_node constructor" << endl;
    next = NULL;
}

/*
//TODO COPY CONSTRUCTOR?
@desc: Copy constructor
 */
V_node::V_node(const V_node &v_node) : Vehicle(v_node)
{
    cout << " Vnode copy constructor" << endl;
    next = v_node.next;
}


/*
   @desc: base destructor for the V_node class. Deletes dynamic memory.
 */
V_node::~V_node()
{
    /*
    if(next)
    {
        delete next;
        next = NULL;
    }
    */
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
   @desc:
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
   @desc: 
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
   @desc: 
 */
V_manager::V_manager()
{
    MAX = 3;
    table = new V_node * [MAX];
    for(int i = 0; i < MAX; ++i)
    {
        table[i] = NULL;
    }
    
    s_tail = table[0];
    p_tail = table[1];
    g_tail = table[2];

    file_read();
}

/*
   @desc:
 */
//TODO
V_manager::~V_manager()
{

}

/*
   @desc:

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
   @desc:
 */
void V_manager::insert_vehicle(char * index, V_node * &source)
{
    if(strcmp(index, "1") == 0)
    {
        if(!table[0])
        {
            s_tail = source;
            table[0] = s_tail;
            s_tail->set_next(s_tail);
            return;
        }

        V_node * temp = source;
        temp->set_next(s_tail->go_next());
        s_tail->set_next(temp);
        s_tail = temp;
        return;
    }

    else if(strcmp(index, "2") == 0)
    {
        if(!table[1])
        {
            p_tail = source;
            table[1] = p_tail;
            p_tail->set_next(p_tail);
            return;
        }

        V_node * temp = source;
        temp->set_next(p_tail->go_next());
        p_tail->set_next(temp);
        p_tail = temp;
        return;
    }

    else
    {
        if(!table[2])
        {
            g_tail = source;
            table[2] = g_tail;
            g_tail->set_next(g_tail);
            return;
        }

        V_node * temp = source;
        temp->set_next(g_tail->go_next());
        g_tail->set_next(temp);
        g_tail = temp;
        return;
    }
}

/*
   @desc:
 */
void V_manager::display_all()
{
    display_standard();
    display_premium();
    display_group();
    return;
}

/*
   @desc:
 */
void V_manager::display_standard()
{
    if(!table[0]) return;

    V_node * current = table[0];

    if(s_tail)
    {
        s_tail->set_next(NULL);
    }

    while(current)
    {
        current->display();
        current = current->go_next();
    }

    s_tail->set_next(table[0]);

    return;
}

/*
   @desc:
 */
void V_manager::display_premium()
{
    if(!table[1]) return;

    V_node * current = table[1];

    if(p_tail)
    {
        p_tail->set_next(NULL);
    }

    while(current)
    {
        current->display();
        current = current->go_next();
    }

    p_tail->set_next(table[1]);

    return;
}

/*
   @desc:
 */
void V_manager::display_group()
{
    if(!table[2]) return;

    V_node * current = table[2];

    if(g_tail)
    {
        g_tail->set_next(NULL);
    }

    while(current)
    {
        current->display();
        current = current->go_next();
    }

    g_tail->set_next(table[2]);

    return;
}

/*
   @desc:
*/
void V_manager::remove_vehicle(char * v_make, char * v_model)
{
    int count = 0;

    if(s_tail && count == 0)
    {
        V_node * head = s_tail->go_next();
        s_tail->set_next(NULL);
        count += remove_helper(head, v_make, v_model);
        s_tail->set_next(table[0]);
    } 

    if(p_tail && count == 0)
    {
        V_node * head = p_tail->go_next();
        p_tail->set_next(NULL);
        count += remove_helper(head, v_make, v_model);
        p_tail->set_next(table[1]);
    }    

    if(g_tail && count == 0)
    {
        V_node * head = g_tail->go_next();
        g_tail->set_next(NULL);
        count += remove_helper(head, v_make, v_model);
        g_tail->set_next(table[2]);
    }    

    return;
}

/*
   @desc:
*/
int V_manager::remove_helper(V_node * &head, char * v_make, char * v_model)
{
    if(!head) return 0;
    
    if(head->compare_make(v_make) && head->compare_model(v_model))
    {
        V_node * temp = head;
        head = head->go_next();
        delete temp;
        temp = NULL;
        return 1 + remove_helper(head, v_make, v_model);
    }

    return remove_helper(head, v_make, v_model);
} 

/*
void V_manager::remove_vehicle(char * v_make, char * v_model)
{
    for(int i = 0; i < MAX; ++i)
    {
        V_node * current = table[i];

        if(current)
        {
            if(i == 0)
            {
                s_tail->set_next(NULL);
            }

            if(i == 1)
            {
                p_tail->set_next(NULL);
            }

            if(i == 2)
            {
                g_tail->set_next(NULL);
            }

            while(current)
            {
                t_make = current->get_make();
                t_model = current->get_model();
                
                if(strcmp(t_make, v_make) == 0 && strcmp(t_model, v_model == 0)
                {
                    V_node * temp = current->go_next();
                    //TODO stopping point, redo this function with recursion
                }

            }

            if(i == 0)
            {
                s_tail->set_next(table[i]);
            }

            if(i == 1)
            {
                p_tail->set_next(table[i]);
            }

            if(i == 2)
            {
                g_tail->set_next(table[i]);
            }
        }
    }
}
*/

/*
   @desc:
 */
//TODO
void V_manager::remove_all()
{

}





