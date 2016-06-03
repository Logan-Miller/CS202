package com.company;


public class Beginner extends Exercise {

    public Beginner(String n, int t) {

        super(n, t);
    }

    public void displayExercise() {
        System.out.println("Beginner level workout: " + name);
        System.out.println("Recommended time: " + time);
    }
}
