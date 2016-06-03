package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ExerciseManager {
    protected E_node head;
    protected E_node tail;
    protected int numWorkouts;
    protected Scanner inFile;

    public ExerciseManager() {
        head = null;
        tail = null;
        numWorkouts = 0;

    }

    public void load() {
        try {
            inFile = new Scanner(new File("./src/com/company/workouts.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        String line = new String();
        String [] lineData;

        while(inFile.hasNextLine()){
            line = inFile.nextLine();
            lineData = line.split(":");

            parse(lineData);
        }
    }

    protected void parse(String [] source) {
        if(head == null) {
            String [] beg = source[0].split(",");
            String [] inter = source[1].split(",");
            String [] exp = source[2].split(",");

            Exercise [] workouts = new Exercise[3];
            workouts[0] = new Beginner(beg[0], Integer.parseInt(beg[1]));
            workouts[1] = new Intermediate(inter[0], Integer.parseInt(inter[1]));
            workouts[2] = new Expert(exp[0], Integer.parseInt(exp[1]));

            head = new E_node(workouts);
            tail = head;
            ++numWorkouts;
        }

        else {
            String [] beg = source[0].split(",");
            String [] inter = source[1].split(",");
            String [] exp = source[2].split(",");

            Exercise [] workouts = new Exercise[3];
            workouts[0] = new Beginner(beg[0], Integer.parseInt(beg[1]));
            workouts[1] = new Intermediate(inter[0], Integer.parseInt(inter[1]));
            workouts[2] = new Expert(exp[0], Integer.parseInt(exp[1]));

            E_node temp = new E_node(workouts);
            temp.setNext(head);
            head.setPrev(temp);
            head = temp;
            ++numWorkouts;
        }
    }

    public void displayAll() {
        displayAll(head);
    }

    protected void displayAll(E_node current) {
        if(current == null) return;
        current.displayData();
        System.out.println();
        displayAll(current.getNext());
    }

    public Exercise retrieveWorkout(String source, int index) {
        return retrieveExercise(source, index, head);
    }

    protected Exercise retrieveExercise(String name, int index, E_node current) {
        if(current == null) return null;
        if(current.checkName(name)) {
            return current.getExercise(index);
        }

        return retrieveExercise(name, index, current.getNext());
    }

    public boolean removeExercise(String name) {
        removeExercise(name, head);
        return true;

    }

    protected void removeExercise(String name, E_node current) {
        if(current == null) return;
        if(current.checkName(name)) {
            if(!current.ifNext()){
                current = null;
                return;
            }

            else {
                current.getNext().setPrev(current.getPrev());
                current.getPrev().setNext(current.getNext());
                return;
            }
        }

        removeExercise(name, current.getNext());
        return;
    }

    public void removeAll() {
        head = null;
        tail = null;
        numWorkouts = 0;
    }
}
