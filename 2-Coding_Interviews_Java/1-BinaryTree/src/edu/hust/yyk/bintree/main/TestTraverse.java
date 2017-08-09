package edu.hust.yyk.bintree.main;

import edu.hust.yyk.bintree.construct.ConstructTree;
import edu.hust.yyk.bintree.traverse.BinaryTreeTraverse;
import edu.hust.yyk.bintree.tree.BinaryTreeNode;

/**
 * Created by alexkun on 17/7/31.
 */
public class TestTraverse {

    public static void main(String []args) {
        BinaryTreeNode btree = ConstructTree.constructBinaryTreeRandom(6);

        System.out.println("Preorder:");
        BinaryTreeTraverse.preOrderUnRecursion(btree);
        BinaryTreeTraverse.preOrderUnRecursionEx(btree);
        BinaryTreeTraverse.preOrderUnRecursionNew(btree);

        System.out.println("\nInorder:");
        BinaryTreeTraverse.inOrderUnRecursion(btree);
        BinaryTreeTraverse.inOrderUnRecursionEx(btree);
        BinaryTreeTraverse.inOrderUnRecursionNew(btree);

        System.out.println("\nAftorder:");
        BinaryTreeTraverse.aftOrderUnRecursion1(btree);
        BinaryTreeTraverse.aftOrderUnRecursion2(btree);
        BinaryTreeTraverse.aftOrderUnRecursionNew(btree);

    }
}
