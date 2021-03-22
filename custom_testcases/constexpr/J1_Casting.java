// REACHABILITY

public class J1_Casting {
	public J1_Casting() {}
	
	public int method() {
		while(// Widening conversions
			  (int)(short)((byte) 1) == 1
			  && (int)((char) 1) == 1
			  // Narrowing conversions
			  && (byte)128 == -128
			  && (byte)(short)128 == -128
			  && (byte)(char)128 == -128
			  && (short) 32768 == -32768
			  && (short)(char) 32768 == -32768
			  && (char)(int) 65536 == 0
			  && (char)(short) -1 == 65535
			  && (char)(byte) -1 == 65535
			  // Identity conversions
			  && (int) 1 == 1
			  && (byte)(byte) 1 == 1
			  && (short)(short) 1 == 1
			  && (char)(char) 1 == 1
			  && (boolean) true == true) {}
	}
	
	public static int test() {
		return 123;
	}
}
