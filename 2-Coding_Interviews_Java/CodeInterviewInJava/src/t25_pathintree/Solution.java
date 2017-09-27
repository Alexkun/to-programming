package t25_pathintree;

import java.util.ArrayList;

/**
 * Created by alexkun on 17/9/4.
 */
public class Solution {

    /**
     public class TreeNode {
     int val = 0;
     TreeNode left = null;
     TreeNode right = null;

     public TreeNode(int val) {
     this.val = val;

     }

     }
     */
    public static ArrayList<ArrayList<Integer>> pathList;

    public static ArrayList<ArrayList<Integer>> FindPath(TreeNode root, int target) {
            pathList = new ArrayList<ArrayList<Integer>>();
            ArrayList<Integer> currentPath = new ArrayList<Integer>();
            if (null != root) {
                  findPath(root, target, 0, currentPath);
            }


            return pathList;
        }

    private static void findPath(TreeNode root, final int target, int current, ArrayList<Integer> currentPath) {

        current += root.val;
        currentPath.add(root.val);
        boolean isLeaf = root.left == null && root.right == null;
        if (isLeaf && target == current) {
            ArrayList<Integer> path = new ArrayList<Integer>();
            path.addAll(currentPath);
            pathList.add(path);
            currentPath.remove(currentPath.size() - 1);
            return ;
        }

        if (null != root.left) {
            findPath(root.left, target, current, currentPath);
        }
        if (null != root.right) {
            findPath(root.right, target, current, currentPath);
        }
        currentPath.remove(currentPath.size() - 1);  //  把刚才加入的子节点移除
        return ;
    }


    /**********Test**************/
    public static  void main(String [] args) {
        TreeNode [] trees = new TreeNode[5];
        TreeNode root = trees[0] = new TreeNode(10);
        trees[1] = new TreeNode(5);
        trees[2] = new TreeNode(12);
        trees[3] = new TreeNode(4);
        trees[4] = new TreeNode(7);
        root.left = trees[1];
        root.right = trees[2];
        trees[1].left = trees[3];
        trees[1].right = trees[4];

        FindPath(root, 19);
        for (ArrayList<Integer> path : pathList) {
            for (int val : path) {
                System.out.print(val + " ");
            }
            System.out.println();
        }

    }
}
