package com.company;


public class F_node extends Food {

    protected F_node left;
    protected F_node right;

    /*
          @desc:
    */
    public F_node() {
        left = null;
        right = null;
    }

    /*
          @desc:
    */
    public F_node(String s1, int s2) {
        super(s1, s2);
    }

    /*
          @desc:
    */
    public F_node(F_node source) {
        super(source);
    }

    /*
          @desc:
    */
    public F_node getLeft() {
        return left;
    }

    /*
          @desc:
    */
    public F_node getRight() {
        return right;
    }

    /*
          @desc:
    */
    public boolean ifLeft() {
        if(left != null) return true;
        return false;
    }

    /*
          @desc:
    */
    public boolean ifRight() {
        if(right != null) return true;
        return false;
    }

    /*
          @desc:
    */
    public void setLeft(F_node source) {
        left = source;
    }

    /*
          @desc:
    */
    public void setRight(F_node source) {
        right = source;
    }
}
