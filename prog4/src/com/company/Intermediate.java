/*
    Logan Miller
    CS202
    Program: 4/5
 */

package com.company;

/*
       @desc: class intermediate inherits from exercise, displays its information differently
*/
public class Intermediate extends Exercise {

    /*
       @desc: constructor given a string and an int, calls the super's constructor
    */
    public Intermediate(String n, int t) {

        super(n, t);
    }

    /*
       @desc: displays the exercise
    */
    public void displayExercise() {
        System.out.println("Intermediate level workout: " + name);
        System.out.println("Recommended time: " + time);
    }
}
