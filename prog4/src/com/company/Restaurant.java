package com.company;


public class Restaurant extends Location {

    public Restaurant(String title, String [] data) {
        super(title, data);
    }

    public void displayLocation() {
        if(root == null) {
            System.out.println("The current location has no food");
        }

        else {
            System.out.print("Restaurant Name: " + name + "\n");
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
}
