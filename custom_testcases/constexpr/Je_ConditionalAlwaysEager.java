// REACHABILITY

public class Je_ConditionalAlwaysEager {
	public Je_ConditionalAlwaysEager() {}

	public int a = 0;
	
	public int method() {
		// Conditional AND and OR (Not Eager) do not short circuit during constant expression evaluation.
        // (true || (a == 0)) does not evaluate to true during constant expression evaluation if a is not final.
		while ((true || a == 0)) {}
	}
	
	public static int test() {
		return 123;
	}
}
