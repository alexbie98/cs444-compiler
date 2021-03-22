// REACHABILITY

public class J1_Conditional {
	public J1_Conditional() {}
	
	public int method() {
		while ((true && true) 
			   && !(true && false) 
			   && (false || true) 
			   && !(false || false) 
			   && (true & true) 
			   && !(true & false) 
			   && (false | true) 
			   && !(false | false)
			   && true ^ false && !(true ^ true)) {}
	}
	
	public static int test() {
		return 123;
	}
}
