// REACHABILITY

public class J1_Comparison {
	public J1_Comparison() {}
	
	public int method() {
		while (2 <= 2 && 1 <= 2 && !(3 <= 2) 
			   && 2 >= 2 && 3 >= 2 && !(1 >= 2)
			   && 3 > 2 && !(2 > 2)
			   && 2 < 3 && !(3 < 2) 
			   && 1 == 1 && !(1 == 2)
			   && 1 != 2 && !(1 != 1)) {}
	}
	
	public static int test() {
		return 123;
	}
}
