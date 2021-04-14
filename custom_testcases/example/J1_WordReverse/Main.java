public class Main   
{  
    public Main(){}
    public static int test()   
    {  
        String str = "The dog licked the ol and everybody laughed";
        String reversed = Main.reverseString(str);  
        System.out.println(reversed); 
        return 123; 
    }  
    public static String reverseString(String s)  
    {  
        if (s.length() == 0) return s; //checks the string if empty   
        return Main.reverseString(s.substring(1, s.length())) + s.charAt(0); //recursively called function  
    }  
}  