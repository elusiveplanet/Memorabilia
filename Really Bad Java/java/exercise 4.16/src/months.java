import java.util.Scanner;

//exercise 4.17 months DONE!

public class months {

	public static void main(String[] args) {
		//simple scanner looks for month in int val
		Scanner in1 = new Scanner(System.in);
		System.out.println("Month?");
		int month = in1.nextInt();
		months(month);
	}

	public static void months(int monthNum) {
		String getMonth = "January  February March    April    May      June     July     August   SeptemberOctober  November December ";
		String monthText = getMonth.substring((9 * (monthNum - 1)),((9 * (monthNum - 1)) + 9));
		System.out.println(monthText);
		
	}




}
