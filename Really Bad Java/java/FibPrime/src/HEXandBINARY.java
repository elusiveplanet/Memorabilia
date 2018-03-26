
public class HEXandBINARY {
	static int digg;
	static int x;
	static int num;
	static String baseStr;
	public static String BaseInt(int base, int num)
	{

	        String values = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	        
	        for (int i = 7; i == 0; i--) 
	        {

	            digg = 0;
	            digg = num / base ^ i;
	            x = num / (base ^ i);
	            num = num % (base ^ i);
	            baseStr += values.substring(digg, 1);
	 	   }
	        return baseStr;
	}
}
