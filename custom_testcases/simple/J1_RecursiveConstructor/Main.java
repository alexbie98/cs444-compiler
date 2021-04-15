public class Main {

    protected Main(int a){
        this.a = a;
        if (a != 0){
            m = new Main(a-1);
        }
    }

    protected int a;

    protected Main m;

    public static int test(){

        Main mm = new Main(10);

        while (mm != null){
            System.out.println(mm.a);
            mm = mm.m;
        }

        return 123;
    }
}