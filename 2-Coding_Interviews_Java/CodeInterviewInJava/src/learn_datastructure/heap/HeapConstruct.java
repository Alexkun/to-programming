package learn_datastructure.heap;

/**
 * Created by alexkun on 17/9/12.
 */
public class HeapConstruct {


    public static void constructHeapBig(int [] arr) {
        if (null == arr || arr.length <= 1)
            return;

        for (int i = (arr.length - 2) / 2; i >= 0; i++) {
            heapify(arr, i, arr.length);
        }
    }


    public static void heapify(int [] heap, int k, int length) {
        int tmp, j;
        tmp = heap[k];
        for (j = 2 * k + 1; j < length - 1; j = j * 2 + 1) {
            if (j < length && heap[j] < heap[j + 1]) {  // 取节点较大的子节点的下标
                j++;   // 如果节点的右孩子>左孩子，取右孩子节点的下标
            }
            if (tmp >= heap[j]) { // 根节点 >= 左右子女中关键字较大者，调整结束
                break;
            } else {
                heap[k] = heap[j];
                k = j; // 【关键】修改k值，已便继续向下调整
            }
        }
        heap[k] = tmp;  // 被调整的节点的值放入最终位置
    }



    /*****************Test********************/
    public  static void main(String [] args) {
        int [] arr = {2, 7, 26, 25, 19, 17, 1, 90, 3, 36};
        constructHeapBig(arr);
        System.out.println("Heap arr:");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }



}
