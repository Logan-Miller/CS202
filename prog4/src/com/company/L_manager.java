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
    Class manages a bst of locations
 */
public class L_manager {
    protected L_node root;
    protected int numLocations;
    protected static Scanner inFile;

    /*
        @desc: base constructor
     */
    public L_manager() {
        root = null;
        numLocations = 0;
    }

    /*
        @desc: inserts a Location into the tree
     */
    public int insertLocation(Location source) {
        if(source == null) return 0;

        L_node node = new L_node(source);

        root = insert(root, node);
        return 1;
    }

    /*
        @desc: inserts an L_node into the tree
     */
    protected L_node insert(L_node root, L_node source) {
        if(root == null) {
            return source;
        }

        if( source.location.healthIndex >= root.location.healthIndex) {
            root.right = insert(root.right, source);
        }

        else if( source.location.healthIndex < root.location.healthIndex) {
            root.left = insert(root.left, source);
        }

        return root;
    }

    /*
        @desc: display's the root of the tree
     */
    public void display() {
        display(root);
    }

    protected void display(L_node root) {
        if(root == null) return;

        display(root.right);
        root.location.displayLocation();
        display(root.left);
    }

    /*
        @desc: using an external data file, line by line, loads data from a file. Uses another function to create
        new Locations to be inserted into the tree.
     */
    public int load() {

        try {
            inFile = new Scanner(new File("./src/com/company/locations.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        String line = new String();
        String [] lineData;

        while(inFile.hasNextLine()){
            line = inFile.nextLine();
            if(line.charAt(0) == '1') {
                line = line.substring(1);
                lineData = line.split(":");
                insertLocation(new Store(lineData[0], lineData[1].split("\\|")));
            }

            else if(line.charAt(0) == '0') {
                line = line.substring(1);
                lineData = line.split(":");
                insertLocation(new Restaurant(lineData[0], lineData[1].split("\\|")));
            }
        }

        return 1;
    }

    /*
        @desc: removes all locations from the tree using a recursive function
     */
    public int removeAll() {
        root = removeAll(root);
        numLocations = 0;
        return 1;
    }

    /*
        @desc: removes all locations from the tree
     */
    protected L_node removeAll(L_node root) {
        if(root == null) return null;
        root = removeAll(root.getRight());
        root = removeAll(root.getLeft());
        root = null;
        return null;
    }

    /*
         @desc: wrapper function to retrieve a location from the tree of locations
     */
    public L_node retrieve(String source) {
        return retrieve(source, root);
    }

    /*
        @desc: recursive function to retrieve an L_node from the tree
     */
    protected L_node retrieve(String source, L_node root) {
        L_node temp = null;
        if(root == null) return null;
        if(root.location.compareNames(source)) {
            return root;
        }
        if(root.ifLeft()) {
            temp = retrieve(source, root.getLeft());
        }
        if(temp == null){
            temp = retrieve(source, root.getRight());
        }
        return temp;
    }

    /*
        @desc: wrapper function to remove a location from the tree given a string to search by
     */
    public void removeLocation(String source) {
        remove_Location(source, root);
        return;
    }

    /*
        @desc: recursive function to remove an L_node from the tree
     */
    protected void remove_Location(String source, L_node root) {
        if(root == null) return;
        if(root.compareNames(source)) {

            if(!root.ifLeft() && !root.ifRight()) {
                root = null;
            }

            if(!root.ifLeft() || !root.ifLeft()) {
                if(!root.ifLeft()) root = root.getRight();
                else root = root.getLeft();
            }

            if(root.ifLeft() && root.ifRight()) {

            }
            return;
        }
        remove_Location(source, root.getLeft());
        remove_Location(source, root.getRight());
        return;
    }

    /*
        @desc: wrapper function to find the healthiest location in the tree
     */
    public void findHealthiest() {
        findHealthiest(root);
    }

    /*
        @desc: recursive function to find the healthiest location in the tree
     */
    protected void findHealthiest(L_node root) {
        if(root == null) return;
        if(!root.ifRight()) root.display();
        findHealthiest(root.getRight());
        return;
    }
}
