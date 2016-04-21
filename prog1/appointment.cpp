#include "appointment.h"

//******************************************************************************
//********************Class Apt Functions***************************************
//******************************************************************************
/*
   Vehicle vehicle;
   char * cust_name;
   char * cust_phone;
   char * location;
   int miles;
   char * drop_off;
 */
Apt::Apt()
{

}

Apt::Apt(Vehicle &source)
{   
    cust_name = NULL;
    cust_phone = NULL;
    location = NULL;
    miles = 0;
    drop_off = NULL;

    vehicle = new Vehicle(source);
    set_cust_name();
    set_cust_phone();
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

/*void Apt::set_vehicle(Vehicle &source)
  {
  vehicle = source;
  }
 */

void Apt::set_cust_name()
{
    if(!cust_name)
    {
        cust_name = new char[100];
        cout << "\nWhat is the customer's name?: ";
        cin.get(cust_name, 100, '\n');
        cin.ignore(100, '\n');
    }

    else
    {
        delete [] cust_name;

        cust_name = new char[100];
        cout << "\nWhat is the customer's name?: ";
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
        cout << "\nWhat is the customer's phone number?: ";
        cin.get(cust_phone, 100, '\n');
        cin.ignore(100, '\n');
    }

    else
    {
        delete [] cust_phone;

        cust_phone = new char[100];
        cout << "\nWhat is the customer's phone number?: ";
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
        cout << "\nWhere is the pick-up location?: ";
        cin.get(location, 100, '\n');
        cin.ignore(100, '\n');
    }

    else
    {
        delete [] location;

        location = new char[100];
        cout << "\nWhere is the pick-up location?: ";
        cin.get(location, 100, '\n');
        cin.ignore(100, '\n');
    }

    return;
}

void Apt::set_miles()
{
    cout << "\nHow many miles is it to your destination?: ";
    cin >> miles;
    cin.ignore(100, '\n');
}

void Apt::set_drop_off()
{

    if(!drop_off)
    {
        drop_off = new char[100];
        cout << "\nWhere is the destination?: ";
        cin.get(drop_off, 100, '\n');
        cin.ignore(100, '\n');
    }

    else
    {
        delete [] drop_off;

        drop_off = new char[100];
        cout << "\nWhere is the destination?: ";
        cin.get(drop_off, 100, '\n');
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

//******************************************************************************
//*********************Class Exp Functions**************************************
//******************************************************************************
/*
   int booking_fee;
   int cancle_fee;
 */

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
   int standard_fare;
 */

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

    cout << '\n' << cust_name << '\n' << cust_phone << '\n' 
        << location << '\n' << drop_off  << '\n' << miles << endl;
    vehicle->display();
    cout << "\nTotal cost for trip is: $" << calc_fare();
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
   int premium_fare;
   int min_fare;
 */

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

    cout << '\n' << cust_name << '\n' << cust_phone << '\n' 
        << location << '\n' << drop_off  << '\n' << miles << endl;
    vehicle->display();
    cout << "\nThe cost for the trip is: $" << calc_fare();
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
   int max_riders;
   int num_riders;
   int g_fare;
 */

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
    cout << '\n' << cust_name << '\n' << cust_phone << '\n' 
        << location << '\n' << drop_off  << '\n' << miles << endl;
    cout << '\n' << num_riders;
    vehicle->display();
    cout << "\nTotal cost for trip is: $" << calc_fare();
}

int Group_exp::calc_fare()
{
    return num_riders * g_fare + booking_fee;
}

//******************************************************************************
//***********************Class A_node Functions*********************************
//******************************************************************************
//A_node * left;
//A_node * right;
//Apt * apt

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

void A_node::display_node()
{
    apt->display_apt();
    return;
}

//******************************************************************************
//***********************Class App_manager Functions****************************
//******************************************************************************

//

Apt_manager::Apt_manager()
{

}

Apt_manager::~Apt_manager()
{

}

void Apt_manager::new_apt()
{

}

bool Apt_manager::insert_apt(A_node * &root, Apt * &myApt)
{
    if(!root)
    {
        return true;
    }
}

void Apt_manager::pop_apt()
{

}
