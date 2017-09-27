package edu.hust.yyk.bintree.tree;

/**
 * Created by alexkun on 17/7/31.
 */
public class BinaryTreeNode {

    private int data;
    private BinaryTreeNode left;
    private BinaryTreeNode right;

    public BinaryTreeNode() {
        data = -1;
        left = null;
        right = null;
    }

    public BinaryTreeNode(int data, BinaryTreeNode left, BinaryTreeNode right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public BinaryTreeNode getLeft() {
        return left;
    }

    public void setLeft(BinaryTreeNode left) {
        this.left = left;
    }

    public BinaryTreeNode getRight() {
        return right;
    }

    public void setRight(BinaryTreeNode right) {
        this.right = right;
    }
}
