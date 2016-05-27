package com.company;

import java.util.Scanner;

public class Food {
    protected String name;
    protected int weight;
    protected static Scanner input=null;

    public Food(){
        name = new String();
        weight = 0;
        input = new Scanner(System.in);
    }

    public Food(String s1, int s2){
        name = new String(s1);
        weight = s2;
        input = new Scanner(System.in);
    }

    public int setName(String source){

        name = source;
        return 1;
    }

    public int setWeight(int source){
        weight = source;
        return 1;
    }

    public void displayFood(){
        System.out.println(name);
        System.out.println(weight);
    }
}


