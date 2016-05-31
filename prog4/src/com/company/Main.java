package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Main {



    public static void main(String[] args) {

        L_manager l = new L_manager();
        l.load();
        l.display();
        System.out.println("transfering to linux");

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
    }
}
