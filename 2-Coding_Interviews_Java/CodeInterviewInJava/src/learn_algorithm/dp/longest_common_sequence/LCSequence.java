package learn_algorithm.dp.longest_common_sequence;

/**
 * Created by alexkun on 17/9/6.
 */
public class LCSequence {

    public static void lcSequence(String a, String b) {
        char [] wordA = a.toCharArray();
        char [] wordB = b.toCharArray();
        int [][] cell = new int[wordA.length][wordB.length];
        int row = wordA.length;
        int col = wordB.length;
        for (int j = 0; j < col; j++) {
            if (wordA[0] == wordB[j]) {
                cell[0][j] = 1;
            }
        }
        for (int i = 0; i < row; i++) {
            if (wordA[i] == wordB[0])
                cell[i][0] = 1;
        }
        int max = 0;
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (wordA[i] == wordB[j]) {
                    cell[i][j] = cell[i-1][j-1] + 1;
                } else {
                    cell[i][j] = (cell[i][j-1] >= cell[i-1][j]) ? cell[i][j-1] : cell[i-1][j];
                }
                if (cell[i][j] > max)
                    max = cell[i][j];
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



    /**********Test***************/
    public static void main(String [] args) {
        String a = "abcdefghijk";
        String b = "bxdngkil";
        lcSequence(a, b);

    }
}
