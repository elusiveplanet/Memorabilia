import java.util.Scanner;


public class year1 {
		    public static void main(String[] args)
		    {
		        System.out.print("year ");
		        Scanner ss = new Scanner(System.in);
		        int s = ss.nextInt();
		        
		        System.out.println(getEasterSundayDate(s));
		    }

		    public static String getEasterSundayDate(int year)
		    {
		        int a = year % 19,
		        	b = year / 100,
		            c = year % 100,
		            d = b / 4,
		            e = b % 4,
		            g = (8 * b + 13) / 25,
		            h = (19 * a + b - d - g + 15) % 30,
		            j = c / 4,
		            k = c % 4,
		            m = (a + 11 * h) / 319,
		            r = (2 * e + 2 * j - k - h + m + 32) % 7,
		            n = (h - m + r + 90) / 25,
		            p = (h - m + r + n + 19) % 32;

		        String month1 = String.valueOf(n);
		        System.out.println(month1);
		        System.out.println(month1.length());
		        switch(month1)
		        {
		            case "1":
		                month1 = "January ";
		            case "2":
		                month1 = "February ";
		            case "3":
		                month1 = "March ";
		            case "4":
		                month1 = "April ";
		            case "5":
		                month1 = "May ";
		            case "6":
		                month1 = "June ";
		            case "7":
		                month1 = "July ";
		            case "8":
		                month1 = "August ";
		            case "9":
		                month1 = "September ";
		            case "10":
		                month1 = "October ";
		            case "11":
		                month1 = "November ";
		            case "12":
		                month1 = "December ";
		        }

		        return month1 + p;
		    }
	}
