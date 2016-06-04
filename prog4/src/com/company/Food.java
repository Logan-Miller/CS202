/*
    Logan Miller
    CS202
    Program: 4/5
 */

package com.company;

import java.util.Scanner;

/*
          @desc: Class food is an object that handles a name and weight
*/


public class Food {

    protected String name;
    protected int weight;
    protected static Scanner input=null;

    /*
          @desc: Constructor with no arguments
    */
    public Food(){
        name = new String();
        weight = 0;
        input = new Scanner(System.in);
    }

    /*
          @desc: Constructor given a string for the name and an int for the weight
    */
    public Food(String s1, int s2){
        name = new String(s1);
        weight = s2;
        input = new Scanner(System.in);
    }

    /*
          @desc: Copy constructor given another food object
    */
    public Food(Food source){
        name = new String(source.name);
        weight = source.weight;
        input = new Scanner(System.in);
    }

    /*
          @desc: function to set the name
    */
    public int setName(String source){

        name = source;
        return 1;
    }

    /*
          @desc: function to set the weight
    */
    public int setWeight(int source){
        weight = source;
        return 1;
    }

    /*
          @desc: display function to display the name
    */
    public void displayFood(){
        System.out.println("Food Item: " + name);
    }

    /*
          @desc: function to get the objects weight
    */
    public int getHealth() {
        return weight;
    }

    /*
          @desc: function to compare a given food object with this object by weight
    */
    public boolean compareHealth(Food source) {
        if(weight >= source.weight) return true;
        return false;
    }
 }


