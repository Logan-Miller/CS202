/*
    Logan Miller
    CS202
    Program: 4/5
 */

package com.company;

import java.util.Scanner;

/*
    @desc: Location class is a manager of a BST of food F_nodes (food)
*/

public abstract class Location {

    protected F_node root;
    protected String name;
    protected int healthIndex;
    protected int numItems;
    protected static Scanner input=null;


    /*
        @desc: basic constructor
    */
    public Location() {
        root = null;
        name = null;
        healthIndex = 0;
        numItems = 0;
        input = new Scanner(System.in);
    }

    /*
        @desc: constructor given a string and an array of strings. Set's the location's name, creates a tree out of the
        array of given strings.
     */
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
          @desc: Given a name and a weight, creates an F_node, calls an insert function to insert it into the BST
    */
    public int insertFood(String name, int weight) {
        F_node source = new F_node(name, weight);
        root = insert(root, source);
        return 1;
    }

    /*
       @desc: Given a root node and a source node, inserts the source node into the root node's tree
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

    /*
        @desc: display function to display the basic info of a location
     */
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

    /*
        @desc: recursive function to display all food objects inside the location
     */
    protected void displayAll(F_node root){
        if(root == null) return;
        displayAll(root.getRight());
        root.displayFood();
        displayAll(root.getLeft());
    }

    /*
        @desc: get's the healths index of the location
     */
    public int getHealthIndex() {
        return healthIndex;
    }

    /*
        @desc: wrapper function to remove all food objects from the location
     */
    public int removeAll() {
        removeAll(root);
        return 1;

    }

    /*
        @desc: recursive function to remove all nodes from a location's tree
     */
    protected F_node removeAll(F_node source) {
        if(root == null) return null;
        root = removeAll(root.getRight());
        root = removeAll(root.getLeft());
        root = null;
        return root;
    }

    /*
        @desc: compares its name with a given string
     */
    public boolean compareNames(String source) {
        if(name.equals(source)) return true;
        return false;
    }
}
