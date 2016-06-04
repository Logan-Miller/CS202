/*
    Logan Miller
    CS202
    Program: 4/5
 */

package com.company;

/*
   @desc: class expert inherits from exercise, displays its information differently
*/
public class Expert extends Exercise {

    /*
       @desc: constructor given a string and an int, calls the super's constructor
    */
    public Expert(String n, int t) {

        super(n, t);
    }

    /*
       @desc: displays the exercise
    */
    public void displayExercise() {
        System.out.println("Expert level workout: " + name);
        System.out.println("Recommended time: " + time);
    }
}
