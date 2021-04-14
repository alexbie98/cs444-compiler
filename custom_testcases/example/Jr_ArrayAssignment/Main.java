public class Main {
    public Main() {}
    public static int test() {
        Apple[] apples = new Apple[1];
        Orange orange = new Orange();
        Fruit[] fruits = apples;
        fruits[0] = orange;
        return 123;
    }
}
