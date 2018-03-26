import java.util.Arrays;

public class DonutInserter {

	public static void main(String[] args) {
		String alphabet[] = {"Apple","Banana","Carrot","Egg","Fondue"};
		String alphabet2[] = {"","","","","","",""};
		String insert = "Donut";
		boolean in = false;
		int x = 0;
		
	    for (String i : alphabet)
	    {
	    	if (isDonut(insert,alphabet[x]) && (in == false)) //if is donut and donut isnt in
	    	{
	    		alphabet2[x] = insert;
	    		alphabet2[x+1] = alphabet[x];
	    		x++; in = true;
	    	}
	    	
	    	else if (in == true)  {alphabet2[x+1] = alphabet[x]; x++;}
	    	
	    	else if (in == false) {alphabet2[x] = alphabet[x]; x++;}
	    }	
		
	    for (String i : alphabet2)
		   System.out.println(i);
	}
	
	public static boolean isDonut(String inserting, String testing)
	{
		return (inserting.compareToIgnoreCase(testing) < 0);
	}
	
}

	