/*
    Logan Miller
    CS202
    Program: 4/5
 */


package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        String response = new String();
        String search = new String();
        int difficulty = 0;
        boolean running = true;
        boolean diet = true;
        boolean workout = true;

        L_manager dietManager = new L_manager();
        ExerciseManager exerciseManager = new ExerciseManager();
        dietManager.load();
        exerciseManager.load();

        System.out.println("Welcome to the healthy health planner, the program for planning healthy lifestyles");
        System.out.println("the program allows you to make diet and exercise planning easier.");
        System.out.println("The following prompts will help you make choices in your overall lifestyle.");
        while(running) {
            System.out.println("Would you like to focus on diet or exercise?");
            System.out.println("To access our dieting records, please enter (1).");
            System.out.println("To access our workout routines please enter (2).");
            System.out.println("To quit the program please enter (3).");
            System.out.println("Enter your choice now: ");
            response = reader.nextLine();

            if(response.equals("1")) {
                System.out.println("Our diet information includes detailed records of different stores and " +
                        "restaurants within the locality.");

                while(diet) {
                    System.out.println("Enter (1) to Search for the healthiest establishment.");
                    System.out.println("Enter (2) to Search for a location.");
                    System.out.println("Enter (3) to Display all locations.");
                    System.out.println("Enter (4) to Quit the diet program.");
                    response = reader.nextLine();

                    if(response.equals("1")) {
                        System.out.println("The healthiest location with the following items is:");
                        dietManager.findHealthiest();
                    }

                    else if(response.equals("2")) {
                        System.out.print("Please enter a location to search for: ");
                        search = reader.nextLine();
                        L_node found = dietManager.retrieve(search);
                        if(found != null) found.display();
                        else System.out.println("Location not found in our records");
                    }

                    else if(response.equals("3")) {
                        dietManager.display();
                    }

                    else if(response.equals("4")) {
                        diet = false;
                        System.out.println("The diet program will now close.");
                    }

                    else {
                        System.out.println("Response not recognized, please enter another response.");
                    }
                }
            }

            else if(response.equals("2")) {
                System.out.println("our following workouts encompass 3 levels of difficulty, beginner, intermediate" +
                        "and expert.");

                while(workout) {
                    System.out.println("Enter (1) Search for a workout.");
                    System.out.println("Enter (2) Display all workouts.");
                    System.out.println("Enter (3) Quit the workout program.");
                    response = reader.nextLine();

                    if(response.equals("1")) {
                        System.out.println("What workout would you like to do?: ");
                        search = reader.nextLine();
                        System.out.println("How strenuous of a workout do you want?");
                        System.out.println("Enter (1) for beginner, (2) for intermediate or (3) for advanced: ");
                        difficulty = reader.nextInt();
                        difficulty -= 1;
                        Exercise found = exerciseManager.retrieveWorkout(search, difficulty);
                        if(found != null) found.displayExercise();
                        else System.out.println("The desired workout was not found.");

                    }

                    else  if(response.equals("2")) {
                        exerciseManager.displayAll();
                    }

                    else if(response.equals("3")) {
                        workout = false;
                    }

                    else {
                        System.out.println("Response not recognized, please enter another response.");
                    }

                }
            }

            else if(response.equals("3")) {
                running = false;
                System.out.println("The program will now close.");

            }

            else {
                System.out.println("Choice not recognized, please try again.");
            }
        }

        System.out.println("Exiting Program.");
    }
}


 /*
        //TODO TESTING FOR FOOD STUFF
        L_manager l = new L_manager();
        l.load();
        l.display();
        System.out.println("transfering to linux");

        L_node temp = new L_node();
        temp = l.retrieve("walmart");

        if(temp == null) {
            System.out.println("fuck");
        }

        if(temp != null){
            System.out.println("YOOOOO");
            temp.display();
        }
        */

//TODO TESTING FOR EXERCISE STUFF

        /*
        ExerciseManager bob = new ExerciseManager();
        bob.load();
        bob.displayAll();

        Exercise billy = bob.retrieveWorkout("Hiking", 0);
        billy.displayExercise();

        bob.removeExercise("Biking");
        bob.displayAll();
        */

















        /*
        F_node apple = new F_node("apple", 5);
        F_node bag = new F_node("bag", 4);
        F_node bar = new F_node("bar", 6);
        Location place = new Location();
        place.insertFood(apple);
        place.insertFood(bag);
        place.insertFood(bar);
        L_node aa = new L_node(place);


        F_node a = new F_node("a", 4);
        F_node b = new F_node("b", 3);
        F_node c = new F_node("c", 5);
        Location p = new Location();
        p.insertFood(a);
        p.insertFood(b);
        p.insertFood(c);
        L_node bb = new L_node(p);

        F_node a1 = new F_node("a1", 6);
        F_node b2 = new F_node("b2", 7);
        F_node c2 = new F_node("c2", 8);
        Location pl = new Location();
        pl.insertFood(a1);
        pl.insertFood(b2);
        pl.insertFood(c2);
        L_node cc = new L_node(pl);


        L_manager l_manager = new L_manager();
        l_manager.insertLocation(aa);
        l_manager.insertLocation(bb);
        l_manager.insertLocation(cc);
        */
// l_manager.display();


        /*
        try {
            inFile = new Scanner(new File("./src/com/company/locations.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        String line = new String();
        while(inFile.hasNextLine()){
            line = inFile.nextLine();
        }

        System.out.println(line);

        String delims = "[:]+";
        String [] tokens = line.split(delims);
        for(int i = 0; i < tokens.length; ++i){
            System.out.println(tokens[1]);
            System.out.println(i);
        }

        System.out.println("I've been transfered back!");
        */
