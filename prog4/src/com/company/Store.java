/*
    Logan Miller
    CS202
    Program: 4/5
 */

package com.company;

/*
   @desc: a store is a location, that handles display differently
*/
public class Store extends Location {

    /*
       @desc: constructor given a string and an array of strings, calls the super's constructor
    */
    public Store(String title, String [] data) {
        super(title, data);
    }

    /*
       @desc: displays the location's data
    */
    public void displayLocation() {
        if(root == null) {
            System.out.println("The current location has no food");
        }

        else {
            System.out.print("Store Name: " + name + "\n");
            System.out.print("Health Index: " + healthIndex + "\n");

            displayAll(root);
        }
    }

    /*
       @desc: recursive function to display all data within the location
    */
    protected void displayAll(F_node root){
        if(root == null) return;
        displayAll(root.getRight());
        root.displayFood();
        displayAll(root.getLeft());
    }

}
