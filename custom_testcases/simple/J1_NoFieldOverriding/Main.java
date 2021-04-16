public class Main extends Base{
    public int field = 23;

    public Main(){}

    public int doTest(){ return getField() + field; }

    public static int test(){
        Main m = new Main();
        return m.doTest();
    }
}