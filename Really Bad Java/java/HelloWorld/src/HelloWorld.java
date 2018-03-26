
public class HelloWorld {

	public static void main(String[] args) {
		System.out.println("Welcome to your second day without Adam! Here's the answer to the quad equation Heltzel gave you!");
	    
	    int a = 12;
		int b = 23;
		int c = 5;
		double sol1 = (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);
		double sol2 = (-b - Math.sqrt(b * b - 4 * a * c)) / (2 * a);
		System.out.println(sol1 + ", " + sol2);
	
		/*
		String r1 = "Mississippi";
		String r2 = "Amazon";
		String r3 = "Amazon";
		if (r2.equals(r3))
				{
			System.out.println("matchmaker, matchmaker");
				}
		    System.out.println("not a match dawg");
		*/   
	}

}
