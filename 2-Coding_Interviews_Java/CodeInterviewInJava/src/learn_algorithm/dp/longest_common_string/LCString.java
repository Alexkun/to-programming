package learn_algorithm.dp.longest_common_string;

/**
 * 最长公共子串
 * Created by alexkun on 17/9/6.
 */
public class LCString {
    public static void lCString(String a, String b) {
        if (null == a || null == b || "".equals(a) || "".equals(b)) {
            System.out.println(0);
            return;
        }

        char []wordA = a.toCharArray();
        char []wordB = b.toCharArray();
        int row = wordA.length;
        int col = wordB.length;
        int [][]cell = new int[row][col];
        for (int j = 0; j < col; j++) {
            if (wordA[0] == wordB[j])
                cell[0][j] = 1;
        }
        for (int i = 0; i < col; i++) {
            if (wordA[i] == wordB[0])
                cell[i][0] = 1;
        }

        int max = 0;
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (wordA[i] == wordB[j]) {
                    cell[i][j] = cell[i-1][j-1] + 1;
                    if (cell[i][j] > max)
                        max = cell[i][j];
                }
            }
        }

        System.out.println(max);

        ////
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.print(cell[i][j] + " ");
            }
            System.out.println();
        }

    }



    /****************Test********************/
    public static void main(String [] args) {
        String a = "abcdefghijk";
        String b = "bxdengkij";
        lCString(a, b);
    }
}
