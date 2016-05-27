package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Main {

    protected static Scanner inFile;

    public static void main(String[] args) {
        Food david = new Food("David", 5);
        david.displayFood();

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

        System.out.println("I've been transfered!");
    }
}
