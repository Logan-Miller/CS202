#include "appointment.h"

//******************************************************************************
//********************Class Apt Functions***************************************
//******************************************************************************
Apt::Apt()
{

}

Apt::Apt(Vehicle &source)
{   
    cust_name = NULL;
    cust_phone = NULL;
    location = NULL;
    date = NULL;
    miles = 0;
    drop_off = NULL;

    vehicle = new Vehicle(source);
    set_cust_name();
    set_cust_phone();
    set_date();
    set_location();
    set_drop_off();
    set_miles();
}

Apt::Apt(const Apt &apt)
{

}

//virtual
Apt::~Apt()
{
    if(vehicle)
    {
        delete vehicle;
        vehicle = NULL;
    }

    if(cust_name)
    {
        delete [] cust_name;
        cust_name = NULL;
    }

    if(cust_phone)
    {
        delete [] cust_phone;
        cust_phone = NULL;
    }

    if(location)
    {
        delete [] location;
        location = NULL;
    }

    if(drop_off)
    {
        delete drop_off;
        drop_off = NULL;
    }

    miles = 0;
}


void Apt::set_cust_name()
{
    if(!cust_name)
    {
        cust_name = new char[100];
        cout << "What is the customer's name?: ";
        cin.get(cust_name, 100, '\n');
        cin.ignore(100, '\n');
    }

    else
    {
        delete [] cust_name;

        cust_name = new char[100];
        cout << "What is the customer's name?: ";
        cin.get(cust_name, 100, '\n');
        cin.ignore(100, '\n');
    }

    return;
}

void Apt::set_cust_phone()
{

    if(!cust_phone)
    {
        cust_phone = new char[100];
        cout << "What is the customer's phone number?: ";
        cin.get(cust_phone, 100, '\n');
        cin.ignore(100, '\n');
    }

    else
    {
        delete [] cust_phone;

        cust_phone = new char[100];
        cout << "What is the customer's phone number?: ";
        cin.get(location, 100, '\n');
        cin.ignore(100, '\n');
    }

    return;
}

void Apt::set_location()
{
    if(!location)
    {
        location = new char[100];
        cout << "Where is the pick-up location?: ";
        cin.get(location, 100, '\n');
        cin.ignore(100, '\n');
    }

    else
    {
        delete [] location;

        location = new char[100];
        cout << "Where is the pick-up location?: ";
        cin.get(location, 100, '\n');
        cin.ignore(100, '\n');
    }

    return;
}

void Apt::set_miles()
{
    cout << "How many miles is it to your destination?: ";
    cin >> miles;
    cin.ignore(100, '\n');
}

void Apt::set_drop_off()
{
    if(!drop_off)
    {
        drop_off = new char[100];
        cout << "Where is the destination?: ";
        cin.get(drop_off, 100, '\n');
        cin.ignore(100, '\n');
    }

    else
    {
        delete [] drop_off;

        drop_off = new char[100];
        cout << "Where is the destination?: ";
        cin.get(drop_off, 100, '\n');
        cin.ignore(100, '\n');
    }

    return;
}

void Apt::set_date()
{
    if(!date)
    {
        date = new char[100];
        cout << "When is the date of the appointment?: ";
        cin.get(date, 100, '\n');
        cin.ignore(100, '\n');
    }

    else
    {
        delete [] date;

        date = new char[100];
        cout << "What is the date of the appointment?: ";
        cin.get(date, 100, '\n');
        cin.ignore(100, '\n');
    }

    return;
}


//virtual
int Apt::calc_fare()
{

}

//virtual
void Apt::display_apt()
{
    cout << '\n' << cust_name << '\n' << cust_phone << '\n' 
        << location << '\n' << drop_off  << '\n' << miles << endl;
    vehicle->display();
    return;
}

char * Apt::get_date()
{
    return date;
}

//******************************************************************************
//*********************Class Exp Functions**************************************
//******************************************************************************
/*
   @desc:
 */
Exp::Exp()
{

}

Exp::Exp(Vehicle &source) : Apt(source)
{
    booking_fee = 5;
    cancle_fee = 10;
}

Exp::Exp(const Exp &exp)
{

}

//virtual
Exp::~Exp()
{
    booking_fee = 0;
    cancle_fee = 0;
}

int Exp::calc_fare()
{

}


//******************************************************************************
//**********************Class Standard_exp Functions****************************
//******************************************************************************
/*
   @desc:
 */
Standard_exp::Standard_exp()
{

}

Standard_exp::Standard_exp(Vehicle &source) : Exp(source)
{
    standard_fare = 1;
}

//virtual
Standard_exp::~Standard_exp()
{
    standard_fare = 0;
}

void Standard_exp::display_apt()
{

    cout << "Customer name: " <<  cust_name << endl
         << "Phone Number: " << cust_phone << endl
         << "Pick-Up: " << location << endl
         << "Drop-off: " << drop_off << endl
         << "Distance: " << miles << endl
         << "Selected Vehicle:";
    vehicle->display();
    cout << endl << "Total cost for trip is: $" << calc_fare() << endl;
    return;
}

int Standard_exp::calc_fare()
{
    int fare = standard_fare * miles;

    return fare + booking_fee;
}

//******************************************************************************
//***********************Class Premium_exp Functions****************************
//******************************************************************************
/*
   @desc:
 */
Premium_exp::Premium_exp()
{

}

Premium_exp::Premium_exp(Vehicle &source) : Standard_exp(source)
{
    premium_fare = 2;
    min_fare = 20;
}

//virtual
Premium_exp::~Premium_exp()
{
    premium_fare = 2;
    min_fare = 20;
}

void Premium_exp::display_apt()
{

    cout << "Customer name: " << cust_name << endl 
         << "Phone Number: " << cust_phone << endl
         << "Pick-Up: " << location << endl
         << "Drop-off: " << drop_off << endl
         << "Distance: " << miles << endl
         << "Selected Vehicle:";
    vehicle->display();
    cout << endl << "Total cost for trip is: $" << calc_fare() << endl;
    return;   
}

int Premium_exp::calc_fare()
{
    int fare = premium_fare * miles;
    if(fare + booking_fee < min_fare)
    {
        return min_fare;
    }

    return fare + booking_fee;
}

//******************************************************************************
//***********************Class Group_exp Functions******************************
//******************************************************************************
/*
   @desc:
*/
Group_exp::Group_exp()
{

}

Group_exp::Group_exp(Vehicle &source) : Exp(source)
{
    max_riders = 8;
    g_fare = 5;
    cout << "How many passengers will there be?: ";
    cin >> num_riders;
    cin.ignore(100, '\n');

    while(num_riders > max_riders)
    {
        cout << "The maximum allowable number of passengers is 8." << endl
            << "Please select a new number of riders now: ";
        cin >> num_riders;
        cin.ignore(100, '\n');
    }
}

//virtual
Group_exp::~Group_exp()
{
    max_riders = 0;
    num_riders = 0;
    g_fare = 0;
}

void Group_exp::display_apt()
{

    cout << "Customer name: " <<  cust_name << endl
         << "Phone Number: " << cust_phone << endl
         << "Pick-Up: " << location << endl
         << "Drop-off: " << drop_off << endl
         << "Distance: " << miles << endl
         << "Passengers: " << num_riders << endl
         << "Selected Vehicle:";
    vehicle->display();
    cout << endl << "Total cost for trip is: $" << calc_fare() << endl;
    return;   
}

int Group_exp::calc_fare()
{
    return num_riders * g_fare + booking_fee;
}

//******************************************************************************
//***********************Class A_node Functions*********************************
//******************************************************************************

A_node::A_node()
{

}

A_node::A_node(const A_node &a_node)
{

}

A_node::A_node(Apt &source)
{
    apt = &source;
    left = NULL;
    right = NULL;
    left_is_full = true;
    right_is_full = true;
}

A_node::~A_node()
{
    delete apt;
    left = NULL;
    right = NULL;
    left_is_full = true;
    right_is_full = true;
}

void A_node::set_left(A_node * source)
{
    if(source) left = source;

    else left = NULL;

    return;
}

void A_node::set_right(A_node * source)
{
    if(source) right = source;

    else right = NULL;

    return;
}

A_node *& A_node::go_left()
{
    return left;
}

A_node *& A_node::go_right()
{
    return right;
}

bool A_node::if_left() const
{
    if(left) return true;
    return false;
}

bool A_node::if_right() const
{
    if(right) return true;
    return false;
}

bool A_node::is_left_full()
{
    if(left_is_full == true) return true;
    return false;
}

bool A_node::is_right_full()
{
    if(right_is_full == true) return true;
    return false;
}

void A_node::set_left_full(bool is_full)
{
    left_is_full = is_full;
    return;
}

void A_node::set_right_full(bool is_full)
{
    right_is_full = is_full;
    return;
}

void A_node::display_node()
{
    apt->display_apt();
    return;
}


bool A_node::compare_dates(const A_node * source)
{
    if(strcmp(apt->get_date(), source->apt->get_date()) < 0)
    {
        //the root has a less than date than the source node, no swap needed
        return false;
    }

    return true;
}

void A_node::swap_apts(A_node * &source)
{
    Apt * temp = apt;
    apt = source->apt;
    source->apt = temp;
    return;
}

//******************************************************************************
//***********************Class App_manager Functions****************************
//******************************************************************************

//

Apt_manager::Apt_manager()
{
    root = NULL;
    num_nodes = 0;
}

Apt_manager::~Apt_manager()
{

}

void Apt_manager::new_apt()
{
    char choice = '\n';
    bool running = true;
    Vehicle * temp = NULL;
    cout << "\nWould you like to view standard, premium or group vehicles?" 
         << "\nFor standard type (s), premium (p), group (g): ";
    
    cin >> choice;
    cin.ignore(100, '\n');

    do
    {
        if(choice == 's')
        {
            vehicles.display_standard();
            temp = fetch_vehicle(0);
            if(!temp) return;
            Standard_exp * exp = new Standard_exp(*temp);
            insert_apt(root, exp);
            running = false;
        }

        else if(choice == 'p')
        {
            vehicles.display_premium();
            temp = fetch_vehicle(1);
            if(!temp) return;
            Premium_exp * exp = new Premium_exp(*temp);
            insert_apt(root, exp);
            running = false;
        }

        else if(choice == 'g')
        {
            vehicles.display_group();
            temp = fetch_vehicle(2);
            if(!temp) return;
            Group_exp * exp = new Group_exp(*temp);
            insert_apt(root, exp);
            running = false;
        }

        else
        {
            cout << "Enter (s) for standard vehicles, (p) for premium or (g)"
                 << " for group vehicles: ";
            cin >> choice;
            cin.ignore(100, '\n');
            running = true;
        }

    }while(running);

}

Vehicle * Apt_manager::fetch_vehicle(int i)
{
    char * v_make = new char[100];
    char * v_model = new char[100];
    
    cout << "What make do you want?: ";
    cin.getline(v_make, 100, '\n');
    
    cout << "What model do you want?: ";
    cin.getline(v_model, 100, '\n');
    
    Vehicle * temp = vehicles.get_vehicle(i, v_make, v_model);
    
    if(!temp)
    {
        cout << "No vehicle matching that description found." << endl;
    }

    delete [] v_make;
    delete [] v_model;

    return temp;
}

bool Apt_manager::insert_apt(A_node * &root, Apt * myApt)
{
    if(!root)
    {
        root = new A_node(*myApt);
        ++num_nodes;
        return true;
    }

    if(root->is_left_full() && root->is_right_full())
    {
        root->set_left_full(false);
        root->set_right_full(false);
    }

    if(!root->is_left_full())
    {   
        root->set_left_full(insert_apt(root->go_left(), myApt));
        if(root->compare_dates(root->go_left()))
        {
            root->swap_apts(root->go_left());
        }

        return root->is_left_full() && root->is_right_full();
    }

    if(!root->is_right_full())
    {
        root->set_right_full(insert_apt(root->go_right(), myApt));
        if(root->compare_dates(root->go_right()))
        {
            root->swap_apts(root->go_right());
        }

        return root->is_left_full() && root->is_right_full();
    }
}

bool Apt_manager::display_all()
{
    if(!root) return false;
    display_all_helper(root);
    return true;
}

void Apt_manager::display_all_helper(A_node * root)
{
    if(!root) return;
    root->display_node();
    display_all_helper(root->go_left());
    display_all_helper(root->go_right());
    return;
}


bool Apt_manager::display_next_apt()
{
    if(!root) return false;
    root->display_node();
    return true;
}

bool Apt_manager::pop_apt()
{
//CASE 1: there are no nodes within the heap, immediatly return.
    if(num_nodes == 0) return false;
//CASE 2: there is only one node, delete it and set the root to NULL.
    if(num_nodes == 1)
    {
        delete root;
        root = NULL;
        --num_nodes;
        return true;
    }
    
    //all cases where there is more than 1 node
    else if(num_nodes > 1)
    {
//CASE 3: If both children are not full, then the node to remove will be in
//the left subtree. Do the required swap with the root's successor, send the
//popped root's data to the node to be deleted, delete node, and then rebalance
        if(!root->is_left_full() && !root->is_right_full())
        {
            //A check is need to find with child to swap root's data with.
            if(!root->go_left()->compare_dates(root->go_right()))
            {
                root->swap_apts(root->go_left());
                find_left_node(root->go_left(), root->go_left());
                rebalance(root->go_left());
            }

            else
            {
                root->swap_apts(root->go_right());
                find_left_node(root->go_left(), root->go_right());
                rebalance(root->go_right());
            }
            --num_nodes;
            return true;
        }

//CASE 4: If both children are full, the node that must be removed to keep the
//heap balanced is the node to the farthest right. Call the pop_full_helper 
//function to swap the root node to the successor, send the node to be popped
//to the farthest right node, delete that node and then rebalance. 
        if(root->is_left_full() && root->is_right_full())
        {
            pop_full_helper(root);
            return true;
        }

//CASE 5: case 5 has multiple sub cases. If the left is full and the right is
//not full the node to delete from the heap could be found on either the left
//or the right sub trees.
        if(root->is_left_full() && !root->is_right_full())
        {
            //case 5.1: if there are only two nodes, simply delete the left
            //node, set root's data.
            if(num_nodes == 2)
            {
                root->swap_apts(root->go_left());
                delete root->go_left();
                root->set_left(NULL);
                root->set_left_full(true);
                --num_nodes;
                return true;
            }
            
            //the height of each sub tree will be used to find where the node
            //to delete is located
            int left_height = find_height(root->go_left());
            int right_height = find_height(root->go_right());

            //Case 5.2: The left subtree's height is greater than the right
            //subtree, so the node to delete is within the left subtree.
            if(left_height > right_height)
            {
                //check which child is the successor to the root, make the 
                //swap. Send the swapped node to the bottom of the left subtree 
                //and then delete the node. 
                if(!root->go_left()->compare_dates(root->go_right()))
                {
                    root->swap_apts(root->go_left());
                    find_left_node(root->go_left(), root->go_left());
                    rebalance(root->go_left());
                }

                else
                {
                    root->swap_apts(root->go_right());
                    find_left_node(root->go_left(), root->go_right());
                    rebalance(root->go_right());
                }
            }
           
            //5.3: else the height of the right subtree is equal to the height
            //of the left sub tree. The node to be deleted is within the right
            //subtree.
            else    
            {   
                //Check which child is the successor to the root, make the 
                //swap. Send the swapped node to the bottom of the right
                //subtree and then delete the node and do rebalancing
                if(!root->go_left()->compare_dates(root->go_right()))
                {
                    root->swap_apts(root->go_left());
                    find_left_node(root->go_right(), root->go_left());
                    rebalance(root->go_left());
                }

                else
                {
                    root->swap_apts(root->go_right());
                    find_left_node(root->go_right(), root->go_right());
                    rebalance(root->go_right());
                }
            }

            --num_nodes;
            return true;
        }
    }
}

//If both sides are full, and there is more than one node, then the
//node to pop is all the way to the right. Compare root's children for
//the inorder successor, swap, and then swap the swapped node with the 
//node to be deleted. Then rebalance.
void Apt_manager::pop_full_helper(A_node * &root)
{
    if(!root) return;

    if(!root->go_left()->compare_dates(root->go_right()))
    {
        root->swap_apts(root->go_left());
        far_right_swap(root, root->go_left());
        rebalance(root->go_left());
    }

    else
    {
        root->swap_apts(root->go_right());
        far_right_swap(root, root->go_right());
        rebalance(root->go_right());
    }

    --num_nodes;
    return;
}

bool Apt_manager::find_left_node(A_node * &root, A_node * &swapper)
{
    if(!root) return true;
    
    if(root->if_right())
    {
        if(!find_left_node(root->go_right(), swapper))
        {
            root->set_right_full(false);
            return false;
        }
    }

    else
    {
        if(find_left_node(root->go_left(), swapper))
        {
            root->swap_apts(swapper);
            delete root;
            root = NULL;
            return false;
        }

        else
        {
            root->set_left_full(false);
        }
    }

}

bool Apt_manager::far_right_swap(A_node * &root, A_node * &swapper)
{
    if(!root) return true;
    if(far_right_swap(root->go_right(), swapper))
    {
        root->swap_apts(swapper);
        delete root;
        root = NULL;

        return false;
    }

    root->set_right_full(false);
    return false;
}

void Apt_manager::rebalance(A_node * &root)
{
    if(!root) return;

    if(root->if_left() && root->if_right())
    {
        if(root->go_left()->compare_dates(root->go_right()))
        {
            root->swap_apts(root->go_left());
            rebalance(root->go_left());
        }

        else
        {
            root->swap_apts(root->go_right());
            rebalance(root->go_right());
        }
    }

    if(root->if_left() && !root->if_right())
    {
        root->swap_apts(root->go_left());
        rebalance(root->go_right());
        return;
    }

    if(!root->if_left() && !root->if_right())
    {
        return;
    }

    return;
}

int Apt_manager::find_height(A_node * root)
{
    if(!root) return 0;
    return 1 + find_height(root->go_left());
}







