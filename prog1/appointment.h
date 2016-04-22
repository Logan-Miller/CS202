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
    void set_date();
    void set_miles();
    void set_drop_off();
    virtual int calc_fare();
    virtual void display_apt();
    char * get_date();

protected:
    Vehicle * vehicle;
    char * cust_name;
    char * cust_phone;
    char * location;
    char * date;
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
    void display_apt();
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
    void display_apt();
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
    void display_apt();
    int calc_fare();

protected:
    int max_riders;
    int num_riders;
    int g_fare;
};

class A_node
{
public:
    A_node();
    A_node(const A_node &a_node);
    A_node(Apt &source);
    ~A_node();
    void set_left(A_node * source);
    void set_right(A_node * source);
    A_node *& go_left();
    A_node *& go_right();
    bool if_left() const;
    bool if_right() const;
    bool is_left_full();
    bool is_right_full();
    void set_left_full(bool is_full);
    void set_right_full(bool is_full);
    void display_node();
    bool compare_dates(const A_node * source);
    void swap_apts(A_node * &source);
protected:
    Apt * apt;
    A_node * left;
    A_node * right;
    bool left_is_full;
    bool right_is_full;
};

class Apt_manager
{
public:
    Apt_manager();
    ~Apt_manager();
    void new_apt();
    bool insert_apt(A_node * &root, Apt * myApt);
    void display_all();
    void display_all_helper(A_node * root);
    void pop_apt();
    void pop_full_helper(A_node * &root);
    bool far_right_swap(A_node * &root, A_node * &swapper);
    void rebalance(A_node * &root);
    int find_height(A_node * root);
protected:
    A_node * root;
    //V_manager vehicles;
    int num_nodes;
};
