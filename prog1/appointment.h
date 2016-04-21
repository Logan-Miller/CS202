#include "vehicle.h"

/*
    @desc:
*/
class Apt
{
public:
    Apt();
    Apt(const Apt &apt);
    Apt(Vehicle &source);
    virtual ~Apt();
    void set_cust_name();
    void set_cust_phone();
    void set_vehicle(Vehicle &source);
    void set_location();
    void set_miles();
    void set_drop_off();
    virtual int calc_fare();
    virtual void display_apt();

protected:
    Vehicle * vehicle;
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
    Exp(Vehicle &source);
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
    Standard_exp(Vehicle &source);
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
    Premium_exp(Vehicle &source);
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
    Group_exp(Vehicle &source);
    virtual ~Group_exp();
    int calc_fare();

protected:
    int max_riders;
    int num_riders;
};
