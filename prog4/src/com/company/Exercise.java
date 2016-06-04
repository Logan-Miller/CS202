/*
    Logan Miller
    CS202
    Program: 4/5
 */

package com.company;

/*
    @desc: an exercise is a name and a recommended amount of time to do that exercise. It has a name and a time
 */
public class Exercise {

    protected String name;
    protected int time;

    /*
        @desc: base constructor
     */
    public Exercise() {
        name = null;
        time = 0;
    }

    /*
        @desc: constructor given a string and an int
     */
    public Exercise(String n, int t) {

        name = n;
        time = t;
    }

    /*
        @desc: sets the name of an exercise
     */
    public void setName(String source) {
        name = source;
    }

    /*
        @desc: sets the time of the exercise
     */
    public void setTime(int source) {
        time = source;
    }

    /*
       @desc: displays the exercise
    */
    public void displayExercise() {
        System.out.println("Workout: " + name);
        System.out.println("Recommended time: " + time);
    }

    /*
       @desc: compares the name of an exercise with a given string
    */
    public boolean compareNames(String source) {
        if(name.equals(source)) return true;
        return false;
    }
}
