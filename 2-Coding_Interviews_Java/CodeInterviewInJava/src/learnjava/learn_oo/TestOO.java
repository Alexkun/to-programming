package learnjava.learn_oo;

import java.util.*;

/**
 * Created by alexkun on 17/9/6.
 */
public class TestOO extends TestOOBase implements TestOOInterface {

    @Override
    public void testPrint(String msg) {
        System.out.print("msg = " + msg);
        StringBuffer sb = new StringBuffer();
        Vector<TestOO> testVector = new Vector<TestOO>();
        ArrayList<TestOO> list = new ArrayList<TestOO>();
        LinkedList<TestOO> linkList = new LinkedList<TestOO>();
        linkList.add(new TestOO());
        linkList.add(new TestOO());
        linkList.add(new TestOO());
        linkList.get(2);
        HashMap<Integer, TestOO> hashMap = new HashMap<Integer, TestOO>();
        Set<TestOO> set = new HashSet<TestOO>();
        HashSet<Integer> numSet = new HashSet<Integer>();
        for (int i = 0; i < 6; i++)
            numSet.add(i);
        Set<Integer> setCopy = (HashSet<Integer>) numSet.clone();
        Iterator<Integer> iter = setCopy.iterator();
        while (iter.hasNext()) {
            System.out.print(iter.next() + " ");
        }
        LinkedHashMap<Integer, Integer> linkMap = new LinkedHashMap<Integer, Integer>();



    }


    @Override
    public void testPrint2(String msg) {

    }

    public static void main(String [] args) {
        new TestOO().testPrint("Test");
    }
}
