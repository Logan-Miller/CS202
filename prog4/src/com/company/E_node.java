/*
    Logan Miller
    CS202
    Program: 4/5
 */

package com.company;

/*
   @desc: E_node has an exercise, as well as the ability to link to other E_nodes to form a doubly linked list
*/
public class E_node {

    protected Exercise [] workout;
    protected E_node next;
    protected E_node prev;

    /*
       @desc: basic constructor
    */
    public E_node() {
        workout = new Exercise[3];
        next = null;
        prev = null;
    }

    /*
       @desc: constructor given an array of Exercises
    */
    public E_node(Exercise [] exercise) {
        workout = exercise;
        next = null;
        prev = null;
    }

    /*
       @desc: checks if there is a next
    */
    public boolean ifNext() {
        if(next != null) return true;
        return false;
    }

    /*
       @desc: checks if there is a previous
    */
    public boolean ifPrev() {
        if(prev != null) return true;
        return false;
    }

    /*
       @desc: returns the next node
    */
    public E_node getNext() {
        return next;
    }

    /*
       @desc: returns the previous node
    */
    public E_node getPrev() {
        return prev;
    }

    /*
       @desc: sets the next node
    */
    public void setNext(E_node source) {
        next = source;
    }

    /*
       @desc: sets the previous node
    */
    public void setPrev(E_node source) {
        prev = source;
    }

    /*
       @desc: displays the data in the node
    */
    public void displayData() {
        workout[0].displayExercise();
        workout[1].displayExercise();
        workout[2].displayExercise();
    }

    /*
       @desc: checks the name of the first exercise in the array with a given string.
    */
    public boolean checkName(String source) {
        if(workout[0].compareNames(source)) return true;
        return false;
    }

    /*
       @desc: given an index, returns an exercise
    */
    protected Exercise getExercise(int index) {
        return workout[index];
    }


}
