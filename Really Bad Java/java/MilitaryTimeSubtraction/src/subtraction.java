import java.util.Scanner;

//military time subtraction

//What's working: MONTHS, DAYS, YEAR, HOUR, MINUTE

//Format of entry: 091420151458 MON_DAY YEAR HOUR_MIN
//Essentially 2:58 PM, 9/14/2015

public class subtraction {

	public static void main(String[] args) {
		
		//0200 0601 2016 -> 2000 0501 2015-> 395 days    6 hours      0 minutes
		
		//looks for times
		Scanner in1 = new Scanner(System.in);
		
		System.out.println("Present Hour and Minute? ");
		int time1 = in1.nextInt();
		
		System.out.println("Present Month and Day? ");
		int MD1 = in1.nextInt();
		
		System.out.println("Present Year? ");
		int year1 = in1.nextInt();
		
		//looks for times
		Scanner in2 = new Scanner(System.in);
		
		System.out.println("Past Hour and Minute? ");
		int time2 = in2.nextInt();
		
		System.out.println("Past Month and Day? ");
		int MD2 = in2.nextInt();
		
		System.out.println("Past Year? ");
		int year2 = in2.nextInt();
		
			//constructor
			subtraction sub = new subtraction(time1, time2, MD1, MD2, year1, year2);
	}

	public subtraction (int time1, int time2, int MD1, int MD2, int year1, int year2) {
		//converts Hours and Minutes to string
		String HM01 = String.valueOf(time1);
		String HM02 = String.valueOf(time2);
		
		//converts Months and Days to string
		String timeA = String.valueOf(MD1);
		String timeB = String.valueOf(MD2);
		
		
		//adds a 0 to string if string value is less than three
		//BOTTOMLINE: helps to prevent error where leading 0 is removed in string.valueof
		if (timeA.length() <= 3)
		{
			timeA = "0" + timeA;
		}
		
		if (timeB.length() <= 3)
		{
			timeB = "0" + timeB;
		}
		
		if (HM01.length() <= 3)
		{
			HM01 = "0" + HM01;
		}
		
		if (HM02.length() <= 3)
		{
			HM02 = "0" + HM02;
		}

		//Scans HM01 for the Hour and minute value
		
		int HM011 = Integer.parseInt(HM01.substring(0, 2));
		
		int HM012 = Integer.parseInt(HM01.substring(2, 4));
		
		//Scans HM02 for the Hour and minute value
		
		int HM021 = Integer.parseInt(HM02.substring(0, 2));
				
		int HM022 = Integer.parseInt(HM02.substring(2, 4));
		
		//Scans daysA and B for the number of days
		
		int daysA = Integer.parseInt(timeA.substring(2,4));
		
		int daysB = Integer.parseInt(timeB.substring(2,4));
		
		
		
		//actual time subtraction
		int HoursL = HM011 - HM021;
		
		int MinutL = HM012 - HM022;
		
		//converts to string for 0 omission
		String HoursLL = String.valueOf(HoursL);
		String MinutLL = String.valueOf(MinutL);
		
		//adds in missing 0 if needed
		if (HoursLL.length() <= 1)
		{
			HoursLL = "0" + HoursLL;
		}
		
		if (MinutLL.length() <= 1)
		{
			MinutLL = "0" + MinutLL;
		}
		
		
		
		//Scans timeA for month to add to number of days
		if (timeA.substring(0, 2).equals("02")) 
		{
			daysA += 31;
		}
		
		if (timeA.substring(0, 2).equals("03"))
		{
			daysA += 31 + 28;
		}
		
		if (timeA.substring(0, 2).equals("04"))
		{
			daysA += 31 + 28 + 31;
		}
		
		if (timeA.substring(0, 2).equals("05"))
		{
			daysA += 31 + 28 + 31 + 30;
		}
		
		if (timeA.substring(0, 2).equals("06"))
		{
			daysA += 31 + 28 + 31 + 30 + 31;
		}
		
		if (timeA.substring(0, 2).equals("07"))
		{
			daysA += 31 + 28 + 31 + 30 + 31 + 30;
		}
		
		if (timeA.substring(0, 2).equals("08"))
		{
			daysA += 31 + 28 + 31 + 30 + 31 + 30 + 31;
		}
		if (timeA.substring(0, 2).equals("09"))
		{
			daysA += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
		}
		
		if (timeA.substring(0, 2).equals("10"))
		{
			daysA += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
		}
		
		if (timeA.substring(0, 2).equals("11"))
		{
			daysA += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		}
		
		if (timeA.substring(0, 2).equals("12"))
		{
			daysA += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
		}
		
		
        //Scans timeB for month to add to number of days
		if (timeB.substring(0, 2).equals("02")) 
		{
			daysB += 31;
		}
		
		if (timeB.substring(0, 2).equals("03"))
		{
			daysB += 31 + 28;
		}
		
		if (timeB.substring(0, 2).equals("04"))
		{
			daysB += 31 + 28 + 31;
		}
		
		if (timeB.substring(0, 2).equals("05"))
		{
			daysB += 31 + 28 + 31 + 30;
		}
		
		if (timeB.substring(0, 2).equals("06"))
		{
			daysB += 31 + 28 + 31 + 30 + 31;
		}
		
		if (timeB.substring(0, 2).equals("07"))
		{
			daysB += 31 + 28 + 31 + 30 + 31 + 30;
		}
		
		if (timeB.substring(0, 2).equals("08"))
		{
			daysB += 31 + 28 + 31 + 30 + 31 + 30 + 31;
		}
		if (timeB.substring(0, 2).equals("09"))
		{
			daysB += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
		}
		
		if (timeB.substring(0, 2).equals("10"))
		{
			daysB += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
		}
		
		if (timeB.substring(0, 2).equals("11"))
		{
			daysB += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		}
		
		if (timeB.substring(0, 2).equals("12"))
		{
			daysB += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
		}
		
		int daysDiff = daysA - daysB;
		
		int years = year1 - year2;
		
		daysDiff += years * 365;
		
		String DaysLL = String.valueOf(daysDiff);
		
		System.out.println(DaysLL + " " + HoursLL + " " + MinutLL);
	}

}
