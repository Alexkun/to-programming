package t24_verifysquenceofbst;

/**
 * Created by alexkun on 17/9/4.
 */
public class Solution {

    private static boolean DEBUG = true;

    /*
    根据一个非重复序列，判断该序列是否为一个二叉搜索树的后续遍历序列
     */
    public static boolean verifySquenceOfBST(int [] sequence) {
        // 1，特殊值判断
        if (null == sequence || sequence.length == 0)
            return false;
        if (sequence.length == 1)
            return true;
        return verifySubSquenceOfBST(sequence, 0, sequence.length - 1);
    }

    /*
    递归判断某串是否为BST树一部分
     */
    private static  boolean verifySubSquenceOfBST(int [] sequence, int begin, int end) {
        // 1，特殊值
        if (begin > end || begin < 0 || end >= sequence.length)
            return false;
        else if (begin == end)
            return true;

        // 2，判定树结构
        int root = sequence[end];
        int rightIndex = -1; // 右子树索引
        for (int i = begin; i < end; i++) {
            if (sequence[i] > root) {
                rightIndex = i;
                break;
            }
        }
        if (-1 == rightIndex)
            rightIndex = end; // 无右子树

        // 3，判定左子树
        boolean lFlag = true;
        if (rightIndex > begin) { // 无左子树
            lFlag = verifySubSquenceOfBST(sequence, begin, rightIndex - 1);
        }
        if (!lFlag) {
            ////
            ////debugPrint("lFlag=false   begin=" + begin + "   end=" + end + "   rightIndex=" + rightIndex + "   root=" + root);
            return false;
        }

        // 4，判定右子树
        boolean rFlag = true;
        for (int i = rightIndex; i < end; i++) {
            if (sequence[i] <= root) {
                rFlag = false;
                break;
            }
        }
        if (rFlag && rightIndex < end) {
            rFlag = rFlag && verifySubSquenceOfBST(sequence, rightIndex, end - 1);
        } else {
            ////
            ////debugPrint("rFlag=false; begin=" + begin + "; end=" + end + "; rightIndex=" + rightIndex);
        }

        return lFlag && rFlag;
    }


    public static void debugPrint(String msg) {
        if (DEBUG) {
            System.out.println("DEBUG:  " + msg);
        }
    }

    /**************Test******************/
    public static void main(String []args) {
        int [] arr1 = {5, 7, 6, 9, 11, 10, 8};

        int [] arr2 = {7, 4, 6, 5};

        int [] arr3 = {4, 6, 7, 5};

        System.out.println(verifySquenceOfBST(arr1));
        //System.out.println(verifySquenceOfBST(arr2));
        System.out.println(verifySquenceOfBST(arr3));

    }


}
