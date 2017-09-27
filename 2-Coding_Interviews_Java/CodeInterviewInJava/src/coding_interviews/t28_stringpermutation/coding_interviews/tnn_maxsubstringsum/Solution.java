package coding_interviews.t28_stringpermutation.coding_interviews.tnn_maxsubstringsum;

/**
 * Created by alexkun on 17/9/13.
 */
public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
        if (null == array || array.length <= 0)
            return 0;

        int max = array[0];
        int maxNeg = Integer.MIN_VALUE;
        boolean negAll = true;
        int tmpMax = max;
        for (int i = 1; i < array.length; i++) {
            if (array[i] < 0) {
                if (array[i] > maxNeg)
                    maxNeg = array[i];
            } else {
                negAll = false;
            }

            if (tmpMax >= 0) {
                tmpMax += array[i];
                if (max < tmpMax)
                    max = tmpMax;
            } else {
                tmpMax = array[i];
            }
        }

        if (negAll) {
            return maxNeg;
        } else {
            return max;
        }
    }



    /**********Test****************/
    /*public static void main(String [] args) {
        int [] nums = {6,-3,-2,7,-15,1,2,2};
        System.out.println(new Solution().FindGreatestSumOfSubArray(nums));

    }*/
}
