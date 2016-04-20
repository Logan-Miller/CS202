#include "vehicle.h"

/*
    @desc:
*/
class Apt
{
public:
    Apt();
    Apt(const Apt &apt);
    Apt(Vehicle &vehicle);
    virtual ~Apt();
    int set_vehicle();
    int set_location();
    int set_miles();
    int set_drop_off();
    virtual int calc_fare();

protected:
    Vehicle vehicle;
    char * cust_name;
    char * cust_phone;
    char * location;
    int miles;
    char * drop_off;
};

/*
    @desc:
*/
class Exp : public Apt
{
public:
    Exp();
    Exp(const Exp &exp);
    virtual ~Exp();
    int calc_fare();

protected:
    int booking_fee;
    int cancle_fee;
};

/*
    @desc:
*/
class Standard_exp : public Exp
{
public:
    Standard_exp();
    virtual ~Standard_exp();
    int calc_fare();

protected:
    int standard_fare;

};

/*
    @desc:
*/
class Premium_exp : public Standard_exp
{
public:
    Premium_exp();
    virtual ~Premium_exp();
    int calc_fare();
    
protected:
    int premium_fare;
    int min_fare;
};

/*
    @desc:
*/
class Group_exp : public Exp
{
public:
    Group_exp();
    virtual ~Group_exp();
    int calc_fare();

protected:
    int max_riders;
    int num_riders;
};
