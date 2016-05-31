package com.company;

import java.util.Scanner;

public class Location {

    protected F_node root;
    protected String name;
    protected int healthIndex;
    protected int numItems;
    protected static Scanner input=null;


    /*
        @desc:
    */
    public Location() {
        root = null;
        name = null;
        healthIndex = 0;
        numItems = 0;
        input = new Scanner(System.in);
    }

    public Location(String title, String [] data) {
        root = null;
        name = title;
        healthIndex = 0;
        numItems = 0;

        for(int i = 0; i < data.length; ++i) {

            String [] food = data[i].split(",");
            insertFood(food[0], Integer.parseInt(food[1]));
        }
    }

    /*
          @desc:
    */
    public int insertFood(String name, int weight) {
        //if(source == null) return 0;
        F_node source = new F_node(name, weight);
        root = insert(root, source);
        return 1;
    }

    /*
       @desc:
   */
    protected F_node insert(F_node root, F_node source) {
        if(root == null) {
            root = new F_node(source);
            ++numItems;
            healthIndex += source.getHealth();
            return root;
        }

        if(!root.compareHealth(source)) {
            root.right = insert(root.getRight(), source);
        }

        if(root.compareHealth(source)) {
            root.left = insert(root.getLeft(), source);
        }

        return root;
    }

    public void displayLocation() {
        if(root == null) {
            System.out.println("The current location has no food");
        }

        else {
            System.out.print("Location: " + name + "\n");
            System.out.print("Health Index: " + healthIndex + "\n");

            displayAll(root);
        }
    }

    protected void displayAll(F_node root){
        if(root == null) return;
        displayAll(root.getRight());
        root.displayFood();
        displayAll(root.getLeft());
    }

    public int getHealthIndex() {
        return healthIndex;
    }
}
