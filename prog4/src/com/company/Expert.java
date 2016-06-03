package com.company;

public class Expert extends Exercise {

    public Expert(String n, int t) {

        super(n, t);
    }

    public void displayExercise() {
        System.out.println("Expert level workout: " + name);
        System.out.println("Recommended time: " + time);
    }
}
