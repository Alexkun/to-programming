package learnjava.learnclass;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;

/**
 * Created by alexkun on 17/9/5.
 */
public class TestClass {

    private String testField = "test";

    public TestClass(String str, int num) throws ClassNotFoundException {
        Class tclass = Class.forName("TestClass");
        Constructor[] cons = tclass.getConstructors();//得到所有public构造方法对象
        Constructor[] allCons = tclass.getDeclaredConstructors();//得到所有构造方法对象
        //得到默认无参构造方法对象并构建实例：
        Constructor defaultCons = null;
        try {
            defaultCons = tclass.getConstructor();
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }
        try {
            TestClass classNameInstance = (TestClass) defaultCons.newInstance(); //得到实例是Object类型，需要强制转换。
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }

        //得到带参构造对象并构建实例：
        Constructor co = null;
        try {
            co = tclass.getConstructor(new Class[]{String.class, int.class});
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }
        TestClass o = null;
        try {
             o = (TestClass) co.newInstance("str",22);//得到实例是Object类型，需要强制转换。
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }

        //得到private构造对象：不能使用上述方法，而要如下设置：
        try {
            tclass.getDeclaredConstructor(String.class, int.class);
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }
        Field field  = null;
        try {
            field = tclass.getDeclaredField("testField");
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        }
//        field.setAccessable(true);//用于取消访问控制

    }


}
