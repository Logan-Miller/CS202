package com.company;


public class L_node {

    protected L_node left;
    protected L_node right;
    protected Location location;

    public L_node() {
        location = null;
        left = null;
        right = null;
    }

    public L_node(Location place) {
        location = place;
        left = null;
        right = null;
    }

    public boolean ifLeft(){
        if(left != null) return true;
        return false;
    }

    public boolean ifRight() {
        if(right != null) return true;
        return false;
    }

    public void setLeft(L_node source) {
        left = source;
    }

    public void setRight(L_node source) {
        right = source;
    }

    public L_node getLeft() {
        return left;
    }

    public L_node getRight() {
        return right;
    }

    public void display() {
        if(location != null) {
            location.displayLocation();
        }
    }
}
