
	import java.util.ArrayList;

	public class Primes {
	    public static void main(String[] args) 
	    {
	    	System.out.println(pri(10));
	    }
	    
		public static String pri(int numPri)
		{
			  ArrayList<String> prima = new ArrayList<String>();
			  String ret = "";
			  int s = 1;
		      int num = 3;
		 
		      if (numPri == 1)
		      {
		    	  return "The first "+ numPri + " prime number is : 2";
		      }
		      prima.add("The first "+ numPri + " prime numbers are : 2");
		 
		      
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
		            prima.add(" " + num);
		            count++;
		         }
		         s = 1;
		         num++;
		      }   
		      
		      for (int i = 0; i < prima.size(); i++) {
		            ret += prima.get(i) + " ";
		        }
		        
		        return ret;
		      /*
			int maxA = max;
			
			String ret = "";
	        
	        for (int a = 1; a < a/2; a++) {
	            boolean prime = true;

	            for (int b = 2; b < a; b++) {
	                if (a % b == 0) {
	                prime = false;
	                break;
	                }
	            }
	            
	            if (prime && a != 1) {
	            	
	                prima.add(a);
	                
	            }
	            
	            if (maxA == 0)
	            {
	            	break;
	            }
	        }
	        for (int i = 0; i < prima.size(); i++) {
	            ret += prima.get(i) + " ";
	        }
	        
	        return ret;
	        */
	    }
		
		
}