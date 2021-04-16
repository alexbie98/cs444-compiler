public class Main {
    public Main() {}
    public static int test() {
        D object = new D();
        A a = object;
        B b = object;
        C c = object;

        if(a.hashCode() == 42 
           && b.hashCode() == 42 
           && c.hashCode() == 42 
           && object.hashCode() == 42)
        {
            return a.a() + b.b() + c.c();
        }

        return 0;
    }
}
