import java.util.Scanner;
//easter Sunday DONE!
public class Year
{
    public static void main(String[] args)
    {
        System.out.print("year? ");
        Scanner ss = new Scanner(System.in);
        int s = ss.nextInt();
        
        System.out.println(getEasterSunday(s));
    }

    public static String getEasterSunday(int year)
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

        String month1 = null;
        
        switch(n)
        {
            case 1:
                month1 = "January ";
                break;
            case 2:
                month1 = "February ";
                break;
            case 3:
                month1 = "March ";
                break;
            case 4:
                month1 = "April ";
                break;
            case 5:
                month1 = "May ";
                break;
            case 6:
                month1 = "June ";
                break;
            case 7:
                month1 = "July ";
                break;
            case 8:
                month1 = "August ";
                break;
            case 9:
                month1 = "September ";
                break;
            case 10:
                month1 = "October ";
                break;
            case 11:
                month1 = "November ";
                break;
            case 12:
                month1 = "December ";
                break;
        }

        return month1 + p;
    }
}
