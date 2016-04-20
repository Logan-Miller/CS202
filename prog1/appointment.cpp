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

Apt::Apt(Vehicle &vehicle)
{

}

Apt::Apt(const Apt &apt)
{

}

//virtual
Apt::~Apt()
{

}

int Apt::set_vehicle()
{

}

int Apt::set_location()
{

}

int Apt::set_miles()
{

}

int Apt::set_drop_off()
{

}

//virtual
int Apt::calc_fare()
{

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

Exp::Exp(const Exp &exp)
{

}

//virtual
Exp::~Exp()
{

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

//virtual
Standard_exp::~Standard_exp()
{

}

int Standard_exp::calc_fare()
{

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

//virtual
Group_exp::~Group_exp()
{

}

int Group_exp::calc_fare()
{

}
