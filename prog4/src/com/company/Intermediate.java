package com.company;

public class Intermediate extends Exercise {

    public Intermediate(String n, int t) {

        super(n, t);
    }

    public void displayExercise() {
        System.out.println("Intermediate level workout: " + name);
        System.out.println("Recommended time: " + time);
    }
}
