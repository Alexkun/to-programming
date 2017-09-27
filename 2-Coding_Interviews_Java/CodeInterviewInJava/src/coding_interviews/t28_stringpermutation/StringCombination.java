package coding_interviews.t28_stringpermutation;

/**
 * Created by alexkun on 17/9/11.
 */
public class StringCombination {

    public static void stringCombination(char []str) {
        if (null == str || str.length == 0)
            return;

        int len = str.length;
        int n = 1 << len;
        StringBuilder sb = null;
        for (int i = 0; i < n; i++) {
            sb = new StringBuilder();
            for (int j = 0; j < len; j++) {
                if ((i & (1 << j)) != 0)
                    sb.append(str[j]);
            }
            String rs = sb.toString();
            if (!"".equals(rs))
                System.out.println(sb.toString());
        }
    }



    /********************Test*****************/
    public static void main(String [] args) {
        char [] str = "123456".toCharArray();
        //stringCombination(str);

        str = "abc".toCharArray();
        stringCombination(str);

    }
}
