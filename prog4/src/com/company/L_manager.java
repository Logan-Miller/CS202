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

        return 1;
    }

    public int removeAll() {
        root = removeAll(root);
        numLocations = 0;
        return 1;
    }

    protected L_node removeAll(L_node root) {
        if(root == null) return null;
        root = removeAll(root.getRight());
        root = removeAll(root.getLeft());
        root = null;
        return null;
    }

    public L_node retrieve(String source) {
        return retrieve(source, root);
    }

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

    public void removeLocation(String source) {
        remove_Location(source, root);
        return;
    }

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

    public void findHealthiest() {
        findHealthiest(root);
    }

    protected void findHealthiest(L_node root) {
        if(root == null) return;
        if(!root.ifRight()) root.display();
        findHealthiest(root.getRight());
        return;
    }
}
