public class Main {
    public Main(){}

    public static int test(){
        int a = (char)-1;
        int b = (short)32768;
        int c = (byte)128;
        int d = (byte)-1;

        if(a != 65535 || b != (-32768) || c != -128 || d != -1) return 0;

        return 123;
    }

}