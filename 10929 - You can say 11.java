import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	private static BigInteger bInt;
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String str = "";
		str = s.nextLine();
		while(!str.equals("0")){
			bInt = new BigInteger(str);
			if(bInt.divideAndRemainder(new BigInteger("11"))[1].compareTo(BigInteger.ZERO) == 0)
				System.out.println(str+" is a multiple of 11.");
			else
				System.out.println(str+" is not a multiple of 11.");
			str = s.nextLine();
		}
	}
}
