package coding_interviews.t28_stringpermutation;

/**
 * Created by alexkun on 17/9/11.
 */
public class StringPermutation {

    public static void permutation(char [] str) {
        if (null == str || str.length == 0) {
            return;
        }
        permutationSub(str, 0);
    }

    private static void permutationSub(char []str, int begin) {
        if (begin >= str.length) {
            System.err.println("Index 'begin'= " + begin + " is out of range.");
            return ;
        }

        if (begin == str.length - 1) {
            System.out.println(str);
        } else {
            for (int nowInd = begin; nowInd < str.length; nowInd++) {
                char tmp = str[nowInd];
                str[nowInd] = str[begin];
                str[begin] = tmp;

                permutationSub(str, begin + 1);

                tmp = str[nowInd];
                str[nowInd] = str[begin];
                str[begin] = tmp;
            }
        }
    }




    /**************Test*****************/
    public static void main(String [] args) {
        char [] str = "123456".toCharArray();
        permutation(str);

        System.out.println("next: \n");
        str = "abcde".toCharArray();
        permutation(str);

    }
}
