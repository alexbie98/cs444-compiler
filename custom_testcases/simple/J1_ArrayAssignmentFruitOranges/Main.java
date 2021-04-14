public class Main {
    public Main() {}
    public static int test() {
        Fruit[] fruits = new Fruit[3];
        Orange orange = new Orange();
        fruits[0] = orange;
        return 123;
    }
}
