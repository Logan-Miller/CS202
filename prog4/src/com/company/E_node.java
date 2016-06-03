package com.company;


public class E_node {

    protected Exercise [] workout;
    protected E_node next;
    protected E_node prev;

    public E_node() {
        workout = new Exercise[3];
        next = null;
        prev = null;
    }

    public E_node(Exercise [] exercise) {
        workout = exercise;
        next = null;
        prev = null;
    }

    public boolean ifNext() {
        if(next != null) return true;
        return false;
    }

    public boolean ifPrev() {
        if(prev != null) return true;
        return false;
    }

    public E_node getNext() {
        return next;
    }

    public E_node getPrev() {
        return prev;
    }

    public void setNext(E_node source) {
        next = source;
    }

    public void setPrev(E_node source) {
        prev = source;
    }

    public void displayData() {
        workout[0].displayExercise();
        workout[1].displayExercise();
        workout[2].displayExercise();
    }

    public boolean checkName(String source) {
        if(workout[0].compareNames(source)) return true;
        return false;
    }

    protected Exercise getExercise(int index) {
        return workout[index];
    }


}
