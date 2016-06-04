/*
    Logan Miller
    CS202
    Program: 4/5
 */

package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/*
   @desc: ExerciseManager is a manager of a doubly linked list of arrays of exercises
*/
public class ExerciseManager {
    protected E_node head;
    protected E_node tail;
    protected int numWorkouts;
    protected Scanner inFile;

    /*
       @desc: basic constructor
    */
    public ExerciseManager() {
        head = null;
        tail = null;
        numWorkouts = 0;

    }

    /*
       @desc: loads data from an external text file line by line, calling a parse function to handle parsing and insert
    */
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

    /*
       @desc: parses a given string into three different exercies, creates an E_node, inserts the node into the list
       all insertions happen at head
    */
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

    /*
       @desc: wrapper function to display all nodes in the DLL
    */
    public void displayAll() {
        displayAll(head);
    }

    /*
       @desc: recursive function to display all nodes within the DLL
    */
    protected void displayAll(E_node current) {
        if(current == null) return;
        current.displayData();
        System.out.println();
        displayAll(current.getNext());
    }

    /*
       @desc: given a string and an index, calls another function to find an exercise
    */
    public Exercise retrieveWorkout(String source, int index) {
        return retrieveExercise(source, index, head);
    }

    /*
       @desc: recursive function to find an exercise in a DLL of arrays
    */
    protected Exercise retrieveExercise(String name, int index, E_node current) {
        if(current == null) return null;
        if(current.checkName(name)) {
            return current.getExercise(index);
        }

        return retrieveExercise(name, index, current.getNext());
    }

    /*
       @desc: wrapper function to remove an exercise from a DLL
    */
    public boolean removeExercise(String name) {
        removeExercise(name, head);
        return true;

    }

    /*
       @desc: recursive function to remove an E_node from a DLL
    */
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

    /*
       @desc: function to remove all nodes from a DLL
    */
    public void removeAll() {
        head = null;
        tail = null;
        numWorkouts = 0;
    }
}
