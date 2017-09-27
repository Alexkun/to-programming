package coding_interviews.t46_acummulate;

/**
 * Created by alexkun on 17/9/13.
 */

public class Solution {
    public int Sum_Solution(int n) {
        reSet();

        Solution [] so = new Solution[n];
        return getSum();

    }


    public Solution() {
        N++;
        sum += N;
    }

    private static int sum = 0;
    private static int N = 0;

    public static void reSet() {
        sum = 0;
        N = 0;
    }

    public static int getSum() {
        return sum;
    }

    /*********Test************/
    public static void main(String [] args) {
        System.out.print("Sum(10)=" + new Solution().Sum_Solution(10));
    }
}
