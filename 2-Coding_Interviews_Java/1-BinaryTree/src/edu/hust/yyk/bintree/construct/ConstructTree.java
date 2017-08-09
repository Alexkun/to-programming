package edu.hust.yyk.bintree.construct;

import edu.hust.yyk.bintree.tree.BinaryTreeNode;

import java.util.*;

/**
 * Created by alexkun on 17/7/31.
 */
public class ConstructTree {

    /* default max node num */
    public static final int DEFAULT_MAX_NODE_NUM = 10;
    public static final int DEFAULT_MAX_RANGE = 100;


    private static Random random = new Random();
    private static Set<Integer> dataSet = new HashSet<Integer>();
    private static int numRange;

    /**
     * 生成一个节点随机、数值随机的二叉树
     * 数值范围： 当DEFAULT_MAX_RANGE > nodeNum + 10时，取DEFAULT_MAX_RANGE；否则取nodeNum * 2（节点数量2倍）
     * 其中，按照层次遍历，每一个孩子的子孩子随机生成；节点数值不重复
     * @return
     */
    public static BinaryTreeNode constructBinaryTreeRandom(int nodeNum) {
        if (nodeNum <= 0) {
            nodeNum = DEFAULT_MAX_NODE_NUM;
        }
        numRange = DEFAULT_MAX_RANGE > nodeNum + 10 ? DEFAULT_MAX_RANGE : nodeNum * 2;

        Queue<BinaryTreeNode> parentQueue = new ArrayDeque<BinaryTreeNode>();
        Queue<BinaryTreeNode> bufferQueue = new ArrayDeque<BinaryTreeNode>();
        Queue<BinaryTreeNode> childQueue = new ArrayDeque<BinaryTreeNode>();
        BinaryTreeNode root = null;

        int count = 0;
        root = getRandomNode();
        while (null == root) {
            root = getRandomNode();
        }
        parentQueue.add(root);
        count++;
        while (count < nodeNum) {
            BinaryTreeNode node = parentQueue.poll();
            if (null != node) bufferQueue.add(node);
            if (null == node) {
                if (childQueue.size() != 0) { // 采用交换队列，然后通过clear清空而不是直接new新的
                    Queue<BinaryTreeNode> tmpQueue = parentQueue;
                    parentQueue = childQueue;
                    childQueue = tmpQueue;
                    childQueue.clear();
                    bufferQueue.clear();
                }else{
                    parentQueue = bufferQueue;
                    bufferQueue = new ArrayDeque<BinaryTreeNode>();
                }
                continue;
            }
            BinaryTreeNode left = getRandomNode();
            node.setLeft(left);
            if (null != left) {
                childQueue.add(left);
                count++;
                if (count >= nodeNum) break;
            }
            BinaryTreeNode right = getRandomNode();
            node.setRight(right);

            if (null != right) {
                childQueue.add(right);
                count++;
            }

            /* 避免出现根节点子孩子均为空的情况 */
            if (node == root && childQueue.size() == 0) {
                parentQueue.add(node);  // 重新将root节点添加进去
            }

        }

        System.out.println("Construct OK~");

        return root;


    }


    /**
     * 子节点生成
     * 随机值大于4则生成节点成功，然后生成的值不重复节点；否则返回null
     * 注：通过控制r > flag中的参数flag，可以调整成功或者失败的大体比例
     */
    private static BinaryTreeNode getRandomNode() {
        // 随机数为偶数则为空
        int r = random.nextInt(10);
        if (r > 4) {
            int data = random.nextInt(numRange);
            while (dataSet.contains(data)) {
                data = random.nextInt(numRange);
            }
            dataSet.add(data);
            return new BinaryTreeNode(data, null, null);
        }else{
            return null;
        }
    }


    public static BinaryTreeNode constructBinaryTreeRandom() {
        return constructBinaryTreeRandom(DEFAULT_MAX_NODE_NUM);
    }
}
