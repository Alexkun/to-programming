package edu.hust.yyk.bintree.traverse;

import edu.hust.yyk.bintree.tree.BinaryTreeNode;

import java.util.ArrayList;
import java.util.Stack;

/**
 * Created by alexkun on 17/7/31.
 */
public class BinaryTreeTraverse {

    /**
     * 二叉树先序遍历
     * 每次弹出栈顶元素并访问；
     * 采用辅助栈，先将右孩子入栈，后将左孩子入栈；
     * 时间：O(n)
     * 空间：O(n)
     * @param root
     */
    public static void preOrderUnRecursion(BinaryTreeNode root) {
        if (null != root)
        {
            Stack<BinaryTreeNode> stack = new Stack<BinaryTreeNode>();
            stack.add(root);
            while (!stack.empty()) {
                BinaryTreeNode node = stack.pop();
                visitNode(node);
            /* 1，右边不为空，先入栈 */
                if (null != node.getRight()) {
                    stack.add(node.getRight());
                }
                if (null != node.getLeft()) {
                    stack.add(node.getLeft());
                }
            }
        }
        System.out.println();
    }

    /**
     * 二叉树中序遍历
     * 采用辅助栈，在辅助栈为空时循环：
     *   将当前节点入栈，然后循环将其左孩子入栈，直到没有左孩子；
     *   弹出栈顶节点，不为空则访问该节点
     * 时间：O(n)
     * 空间：O(n)
     * @param root
     */
    public static void inOrderUnRecursion(BinaryTreeNode root) {
        if (null != root) {
            Stack<BinaryTreeNode> stack = new Stack<BinaryTreeNode>();
            BinaryTreeNode node = root;
            while (!stack.isEmpty() || null != node) {
                while (null != node) {
                    stack.add(node);
                    node = node.getLeft();
                }
                node = stack.pop();
                if (null != node ) {
                    visitNode(node);
                    node = node.getRight();
                }
            }
        }
        System.out.println();
    }

    /**
     * 二叉树后序遍历1~双栈法
     * 按照先序遍历二叉树，构造中右左的访问顺序，访问时不输出，而将节点入备用栈
     * 将备用栈挨个出栈，即有左右中的访问顺序
     * @param root
     */
    public static void aftOrderUnRecursion1(BinaryTreeNode root) {
        if (null != root) {
            Stack<BinaryTreeNode> fStack = new Stack<BinaryTreeNode>();
            Stack<BinaryTreeNode> lStack = new Stack<BinaryTreeNode>();
            fStack.add(root);
            while (!fStack.isEmpty()) {
                BinaryTreeNode node = fStack.pop();
                lStack.add(node);
                if (node.getLeft() != null) {
                    fStack.add(node.getLeft());
                }
                if (node.getRight() != null) {
                    fStack.add(node.getRight());
                }

            }
            while (!lStack.isEmpty())
                visitNode(lStack.pop());
        }
        System.out.println();
    }

    /**
     * 二叉树后序遍历非递归~双指针法
     * 辅助栈入栈头结点；初始化缓存对象node和新头对向head
     * 栈非空，做下列循环：
     *  判断栈顶节点是否存在左孩子，且左右孩子均不是新头对向，是则将左孩子入栈，否则看下一步：
     *   判断栈顶节点是否存在右孩子，且右孩子不是新头对向，是则将右孩子入栈，否则看下一步：
     *    将栈顶元素出栈，访问它，该节点就是新头结点
     *
     * @param root
     */
    public static void aftOrderUnRecursion2(BinaryTreeNode root) {
        if (null != root) {
            Stack<BinaryTreeNode> stack = new Stack<BinaryTreeNode>();
            stack.add(root);
            BinaryTreeNode node = null;
            BinaryTreeNode head = root;
            while (!stack.isEmpty()) {
                node = stack.peek();
                if (null != node.getLeft() && head != node.getLeft() && head != node.getRight()) {
                    stack.push(node.getLeft());
                } else if (null != node.getRight() && head != node.getRight()) {
                    stack.push(node.getRight());
                } else {
                    node = stack.pop();
                    visitNode(node);
                    head = node;
                }
            }
        }
        System.out.println();
    }


    /*         下面有一种简单易懂，且格式一致的非递归前中后序遍历写法，符合思维顺序。自己想出来的             */

    public static void preOrderUnRecursionEx(BinaryTreeNode root) {
        if (null != root) {
            Stack<BinaryTreeNode> stack = new Stack<BinaryTreeNode>();
            ArrayList<Integer> visitList = new ArrayList<Integer>();
            BinaryTreeNode node = null;
            stack.add(root);
            visitList.add(root.getData());
            visitNode(root);
            while (!stack.isEmpty()) {
                node = stack.peek();
                if (null != node.getLeft() && !visitList.contains(node.getLeft().getData())) {
                    visitNode(node.getLeft());
                    visitList.add(node.getLeft().getData());
                    stack.push(node.getLeft());
                } else if (null != node.getRight() && !visitList.contains(node.getRight().getData())) {
                    visitNode(node.getRight());
                    visitList.add(node.getRight().getData());
                    stack.push(node.getRight());
                } else {
                    stack.pop();
                }
            }
        }
        System.out.println();
    }

    public static void inOrderUnRecursionEx(BinaryTreeNode root) {
        if (null != root) {
            Stack<BinaryTreeNode> stack = new Stack<BinaryTreeNode>();
            ArrayList<Integer> visitList = new ArrayList<Integer>();
            BinaryTreeNode node = null;
            stack.add(root);
            while (!stack.empty()) {
                node = stack.peek();
                if (null != node.getLeft() && !visitList.contains(node.getLeft().getData())) {
                    stack.push(node.getLeft());
                } else {
                    visitNode(node);
                    visitList.add(node.getData());
                    stack.pop();
                    if (null != node.getRight()) {
                        stack.push(node.getRight());
                    }
                }
            }
        }
        System.out.println();
    }

    public static void aftOrderUnRecursionEx(BinaryTreeNode root) {
        if (null != root) {
            Stack<BinaryTreeNode> stack = new Stack<BinaryTreeNode>();
            ArrayList<Integer> visitList = new ArrayList<Integer>();
            BinaryTreeNode node = null;
            stack.add(root);
            while (!stack.empty()) {
                node = stack.peek();
                if (null != node.getLeft() && !visitList.contains(node.getLeft().getData())) {
                    stack.push(node.getLeft());
                } else if (null != node.getRight() && !visitList.contains(node.getRight().getData())) {
                    stack.push(node.getRight());
                } else {
                    visitNode(node);
                    visitList.add(node.getData());
                    stack.pop();
                }
            }
        }
        System.out.println();
    }

    /*   搜了下资料，还有思路大体相似，但是形式更加一致的写法，更加清晰易懂  */

    /**
     * 使用统一的访问状态记录列表
     * 循环直到栈为空：
     *  当栈顶节点标记未访问时，将其标记可访问，然后将当前节点、左右孩子节点按照与遍历顺序相反的顺序入栈；
     *  当栈顶节点标记可访问时，访问该节点
     * @param root
     */
    public static void preOrderUnRecursionNew(BinaryTreeNode root) {
        if (null != root) {
            Stack<BinaryTreeNode> stack = new Stack<BinaryTreeNode>();
            ArrayList<BinaryTreeNode> visitList = new ArrayList<BinaryTreeNode>();
            BinaryTreeNode node = null;
            stack.add(root);
            while (!stack.isEmpty()) {
                node = stack.pop();
                if (visitList.contains(node)) {
                    visitNode(node);
                } else {
                    visitList.add(node);
                    if (null != node.getRight()) stack.push(node.getRight());
                    if (null != node.getLeft())  stack.push(node.getLeft());
                    stack.push(node);
                }
            }
        }
        System.out.println();
    }

    public static void inOrderUnRecursionNew(BinaryTreeNode root) {
        if (null != root) {
            Stack<BinaryTreeNode> stack = new Stack<BinaryTreeNode>();
            ArrayList<BinaryTreeNode> visitList = new ArrayList<BinaryTreeNode>();
            BinaryTreeNode node = null;
            stack.add(root);
            while (!stack.isEmpty()) {
                node = stack.pop();
                if (visitList.contains(node)) {
                    visitNode(node);
                } else {
                    visitList.add(node);
                    if (null != node.getRight()) stack.push(node.getRight());
                    stack.push(node);
                    if (null != node.getLeft())  stack.push(node.getLeft());
                }
            }
        }
        System.out.println();
    }

    public static void aftOrderUnRecursionNew(BinaryTreeNode root) {
        if (null != root) {
            Stack<BinaryTreeNode> stack = new Stack<BinaryTreeNode>();
            ArrayList<BinaryTreeNode> visitList = new ArrayList<BinaryTreeNode>();
            BinaryTreeNode node = null;
            stack.add(root);
            while (!stack.isEmpty()) {
                node = stack.pop();
                if (visitList.contains(node)) {
                    visitNode(node);
                } else {
                    visitList.add(node);
                    stack.push(node);
                    if (null != node.getRight()) stack.push(node.getRight());
                    if (null != node.getLeft())  stack.push(node.getLeft());
                }
            }
        }
        System.out.println();
    }

    private static void visitNode(BinaryTreeNode node) {
        System.out.print(node.getData() + " ");
    }
}
