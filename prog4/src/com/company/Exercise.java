package com.company;


public class Exercise {

    protected String name;
    protected int time;

    public Exercise() {
        name = null;
        time = 0;
    }

    public Exercise(String n, int t) {

        name = n;
        time = t;
    }

    public void setName(String source) {
        name = source;
    }

    public void setTime(int source) {
        time = source;
    }

    public void displayExercise() {
        System.out.println("Workout: " + name);
        System.out.println("Recommended time: " + time);
    }

    public boolean compareNames(String source) {
        if(name.equals(source)) return true;
        return false;
    }
}
