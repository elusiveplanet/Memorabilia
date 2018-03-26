import java.util.Scanner;
//change program DONE!
public class Main {
	double QQ;
	double DD;
	double NN;
	double PP;
	double coinshold;
	static double MoneyLeft;
	private static double Q = 0.25;
	private static double D = 0.10;
	private static double N = 0.05;
	private static double P = 0.01;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter Monies: ");
		double Change = in.nextDouble();
		MoneyLeft = Change + 0.01;
		Main changeQ = new Main(MoneyLeft, Q);
		Main changeD = new Main(MoneyLeft, D);
		Main changeN = new Main(MoneyLeft, N);
		Main changeP = new Main(MoneyLeft, P);
		
	}
	
	public Main (double moneyLeft, double coinVal) {
	coinshold = (moneyLeft / coinVal) - ((moneyLeft / coinVal) % 1);
	
	MoneyLeft = moneyLeft - (coinshold * coinVal);
	
	System.out.println(coinshold);
	}
	

}
