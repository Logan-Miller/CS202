package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class L_manager {
    protected L_node root;
    protected int numLocations;
    protected static Scanner inFile;

    public L_manager() {
        root = null;
        numLocations = 0;
    }

    public int insertLocation(Location source) {
        if(source == null) return 0;

        L_node node = new L_node(source);

        root = insert(root, node);
        return 1;
    }

    protected L_node insert(L_node root, L_node source) {
        if(root == null) {
            //root = new L_node();
            //root = source;
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

    public void display() {
        display(root);
    }

    protected void display(L_node root) {
        if(root == null) return;

        display(root.right);
        root.location.displayLocation();
        display(root.left);
    }

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

       // System.out.println(line);

        //String delims = "[:]+";
        //String [] tokens = line.split(delims);
        /*for(int i = 0; i < tokens.length; ++i){
            System.out.println(tokens[1]);
            System.out.println(i);
        }
        */

        return 1;
    }
}
