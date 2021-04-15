package pkg.test;

public class Fib {

    public Fib(){}

    public void printFib(){

        int n = 100;
        
        System.out.print("Upto " + n + ": ");
        int t1 = 1;
        int t2 = 1;


        while (t1 <= n)
        {
            System.out.print(t1 + " + ");

            int sum = t1 + t2;
            t1 = t2;
            t2 = sum;
        }
    }
}