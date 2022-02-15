public class test {
    public static void main(String[] args) {
        C[] elements = {new A(), new B(), new C(), new D()};
        for(int i = 0; i < elements.length; i++) {
            System.out.println(elements[i]);
            elements[i].method1();
            System.out.println();
            elements[i].method2();
            System.out.println();
            System.out.println();
        }
    }

}
