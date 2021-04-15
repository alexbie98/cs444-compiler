public class Main {
    public Main(){}

    protected Main m = new Main();

    public static int test(){
        Main m2 = new Main();
        return 123;
    }

}