#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;

//TODO
/*
    @desc: A vehicle is an object comprised of a make, a model and a license.
    @func: constructor initially sets the vehicles data members to their 0
        equivalent.
    @func: destructor deallocates the memory for its data members
    @func: set_make(char * make) expects a char *, it then sets the vehicle's
        make to this string.
    @func: set_model(char * model) exepects a char *, it then sets the vehcle's
        model to this string.
    @func: set_license(char * license) expects a char *, it then sets the
        vehicle's license to this value.
    @member: make is a char *
    @member: model is a char *
    @member: license is a char *
*/
class Vehicle
{

public:
    Vehicle();
    Vehicle(const Vehicle &vehicle);
    ~Vehicle();
    void set_make(char * source);
    void set_model(char * source);
    void set_license(char * source);
    void display();
protected:
    char * make;
    char * model;
    char * license;
};

/*
    @desc: A vehicle node IS A vehicle plus the ability to link to other
        vehicles, allowing for the developement of different list-type data 
        structures.
    @func:
    @func:
    @func:
    @func:
    @func:
*/
class V_node: public Vehicle
{

public:
    V_node();
    V_node(const V_node &v_node);
    ~V_node();
    void set_next(V_node * source);
    V_node *& go_next();
    bool if_next() const;
    bool compare_make(char * source);
    bool compare_model(char * source);
protected:
    V_node * next;
};

//TODO
/*
    @desc: is a class managing a array of three circular linked lists. It will
        read in data from an external data file, create new vehicle nodes with 
        this data, 

*/
class V_manager
{

public:
    V_manager();
    ~V_manager();
    void insert_vehicle(char * index, V_node *& source);
    void display_all();
    void display_standard();
    void display_premium();
    void display_group();
    void remove_vehicle(char * v_make, char * v_model);
    int remove_helper(V_node * &head, V_node * &current, char * v_make, 
                      char * v_model);
    void remove_all_helper(V_node * &head);
    void remove_all();
protected:
    void file_read();
    V_node ** table;
    int MAX;
};
