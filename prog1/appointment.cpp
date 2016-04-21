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

}

int Standard_exp::calc_fare()
{
    return standard_fare * miles;
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

}

//virtual
Premium_exp::~Premium_exp()
{

}

int Premium_exp::calc_fare()
{

}

//******************************************************************************
//***********************Class Group_exp Functions******************************
//******************************************************************************
/*
   int max_riders;
   int num_riders;
 */

/*
   @desc:
 */
Group_exp::Group_exp()
{

}

Group_exp::Group_exp(Vehicle &source) : Exp(source)
{

}

//virtual
Group_exp::~Group_exp()
{

}

int Group_exp::calc_fare()
{

}
