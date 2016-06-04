/*
    Logan Miller
    CS202
    Program: 4/5
 */

package com.company;

/*
    @desc: an L_node is used for building a tree of locations. Each node has a location and the ability to connect
    to other L_nodes
 */
public class L_node {

    protected L_node left;
    protected L_node right;
    protected Location location;

    /*
       @desc: basic constructor
    */
    public L_node() {
        location = null;
        left = null;
        right = null;
    }

    /*
       @desc: constructor given a Location
    */
    public L_node(Location place) {
        location = place;
        left = null;
        right = null;
    }

    /*
       @desc: checks if left is null
    */
    public boolean ifLeft(){
        if(left != null) return true;
        return false;
    }

    /*
       @desc: checks if right is null
    */
    public boolean ifRight() {
        if(right != null) return true;
        return false;
    }

    /*
      @desc: sets left
    */
    public void setLeft(L_node source) {
        left = source;
    }

    /*
       @desc: sets right
    */
    public void setRight(L_node source) {
        right = source;
    }

    /*
       @desc: gets left
    */
    public L_node getLeft() {
        return left;
    }

    /*
       @desc: gets right
    */
    public L_node getRight() {
        return right;
    }

    /*
       @desc: calls the location's display function
    */
    public void display() {
        if(location != null) {
            location.displayLocation();
        }
    }

    /*
       @desc: compare's the name of a location with a given string.
    */
    public boolean compareNames(String source) {
        return location.compareNames(source);
    }
}
