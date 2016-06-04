/*
    Logan Miller
    CS202
    Program: 4/5
 */


package com.company;

/*
          @desc: F_node inherits from food, it adds ability to link to other Food objects with two nodes
*/
public class F_node extends Food {

    protected F_node left;
    protected F_node right;

    /*
          @desc: basic constructor
    */
    public F_node() {
        left = null;
        right = null;
    }

    /*
          @desc: constructor given two strings
    */
    public F_node(String s1, int s2) {
        super(s1, s2);
    }

    /*
          @desc: copy constructor given another f_node
    */
    public F_node(F_node source) {
        super(source);
    }

    /*
          @desc: returns the left node
    */
    public F_node getLeft() {
        return left;
    }

    /*
          @desc: returns the right node
    */
    public F_node getRight() {
        return right;
    }

    /*
          @desc: checks if left is not null
    */
    public boolean ifLeft() {
        if(left != null) return true;
        return false;
    }

    /*
          @desc: checks if right is not null
    */
    public boolean ifRight() {
        if(right != null) return true;
        return false;
    }

    /*
          @desc: sets the left node
    */
    public void setLeft(F_node source) {
        left = source;
    }

    /*
          @desc: sets the right node
    */
    public void setRight(F_node source) {
        right = source;
    }
}
