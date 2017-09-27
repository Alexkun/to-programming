package coding_interviews.t28_stringpermutation;

import java.util.ArrayList;

/**
 * Created by alexkun on 17/9/14.
 */
public class PermutationTest {


    public ArrayList<String> Permutation(String str) {
            if (null == str || "".equals(str))
                return new ArrayList<String>();

            if (str.length() <1 || str.length() > 9)
                return new ArrayList<String>();

            char [] arr = str.toCharArray();
            ArrayList<String> rsList = new ArrayList<String>();
            permutationSub(arr, 0, rsList);
            return rsList;
    }

    private void permutationSub(char [] arr, int begin, ArrayList<String> rsList) {
            if (begin == arr.length - 1) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0 ; i < arr.length; i++) {
                    sb.append(arr[i]);
                }
                rsList.add(sb.toString());
            }
            else {
                for (int i = begin; i < arr.length; i++) {
                    char tmp = arr[i];
                    arr[i] = arr[begin];
                    arr[begin] = arr[i];

                    permutationSub(arr, begin + 1, rsList);

                    tmp = arr[i];
                    arr[i] = arr[begin];
                    arr[begin] = arr[i];

                }

            }
    }



    /****************Test***************/
    public static void main(String [] args) {
        String str = "abcde";
        ArrayList<String> rsList =  new PermutationTest().Permutation(str);
        for (int i = 0 ; i < rsList.size(); i++) {
            System.out.println(rsList.get(i));
        }

    }



}
