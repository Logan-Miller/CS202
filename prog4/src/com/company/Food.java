package com.company;

import java.util.Scanner;

public class Food {

    protected String name;
    protected int weight;
    protected static Scanner input=null;

    /*
          @desc:
    */
    public Food(){
        name = new String();
        weight = 0;
        input = new Scanner(System.in);
    }

    /*
          @desc:
    */
    public Food(String s1, int s2){
        name = new String(s1);
        weight = s2;
        input = new Scanner(System.in);
    }

    /*
          @desc:
    */
    public Food(Food source){
        name = new String(source.name);
        weight = source.weight;
        input = new Scanner(System.in);
    }

    /*
          @desc:
    */
    public int setName(String source){

        name = source;
        return 1;
    }

    /*
          @desc:
    */
    public int setWeight(int source){
        weight = source;
        return 1;
    }

    /*
          @desc:
    */
    public void displayFood(){
        System.out.println("Food Item: " + name);
    }

    /*
          @desc:
    */
    public int getHealth() {
        return weight;
    }

    /*
          @desc:
    */
    public boolean compareHealth(Food source) {
        if(weight >= source.weight) return true;
        return false;
    }
 }


