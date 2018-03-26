
public class tester {

	public static void main(String[] args) {
		
		
    //System.out.println(pri(10));
    //System.out.println(fib(10));
    //System.out.println(BaseInt(16, 416));
    sarahPalinDrome("raCecar");
	}
	static int a = 1;
	static int b = 0;
	static String retFib = "Here are the requested Fibonacci numbers: ";
	static String retPri = "";
	static String retStr = "";
	final static double millie = 1.3063778838;


	public static String fib(int limit)
	{

	for (int i = 1; i <= limit; i++) 
	   {
	    b = b + a;
	    a = b - a;
	    retFib += b + " ";
	   }
	return retFib;
	}
	
	public static String pri(int numPri)

		   {
		      int s = 1;
		      int num = 3;
		 
		      if (numPri == 1)
		      {
		    	  return "The first "+ numPri + " prime number is : 2";
		      }
		      retPri = "The first "+ numPri + " prime numbers are : 2";
		 
		      for (int count = 2 ; count <= numPri;)
		    	  // count = 2 because 2 is in already count <= numPri to not allow infinite
		      {
		         for (int i = 2 ; i <= Math.sqrt(num) ; i++)
		         {
		            if (num % i == 0)
		            {
		               s = 0;
		               break;
		            }
		         }
		         if (s != 0)
		         {
		            retPri += " " + num;
		            count++;
		         }
		         s = 1;
		         num++;
		      }   
		      return retPri;
		   }
	
	public static String BaseInt(int base, int num)
	{
		if (num == 0) 
			
		return "0";

	       String digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	       String s = "";
	       
	       while (num > 0) {
	          int d = num % base;
	          s = digits.substring(d,d+1) + s;
	          num = num / base;
	       }
	       return s;
     }

	static String hold1 = "";
	static String hold2 = "";
	
	public static void sarahPalinDrome(String drome)
	{
		//abba
		//abka
		drome = drome.toLowerCase();
        hold1 = drome;
		int y = 0;
		int l = drome.length();
		while (l > y)
		{
			hold2 += drome.substring(l - 1, l);
			l -= 1;
		}
		
		System.out.println(drome);
		System.out.println(hold1);
		System.out.println(hold2);
	
		
		
		if (hold1.equals(hold2))
			System.out.println("t");
		
		if (!hold1.equals(hold2))
			System.out.println("f");
	}
}

