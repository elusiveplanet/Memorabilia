import java.util.ArrayList;
import java.util.Scanner;
		
public class BankAccountTest1 {
	static int day,month,year,accountscount;
	static ArrayList<String> accounts = new ArrayList<String>();
	static ArrayList<Double> balance = new ArrayList<Double>();
	public static void main(String[] args) {
		System.out.println("Please enter your date of birth in this format: MM/DD/YYYY. \nAny single digit days or months must be written in this format: May ---> 05, not 5.");
		Scanner DOB = new Scanner(System.in);
		String date = DOB.next();
		
		month = Integer.parseInt(date.substring(0, 2));
		day = Integer.parseInt(date.substring(2, 4));
		year =  Integer.parseInt(date.substring(4, 8));

		//System.out.println(day);
		//System.out.println(month);
		//System.out.println(year);
		
		
		SavingsAccount accountadd = new SavingsAccount(day,month,year);
		
		accounts.add(accountadd.getnum());
		balance.add(accountadd.getbal());
		System.out.println("Would you like to enter another account?");
		
		
		Scanner yeno = new Scanner(System.in);
		String yenope = yeno.next();
		while(!yenope.equals("STOP"))
		{
			
		if (yenope.equals("Yes"))
		{
			main(args);
		}
		System.out.println("Would you like to search for an account?");
		String yenope2 = yeno.next();
		if (yenope2.equals("Yes"))
		{
			System.out.println("Please enter the account number of the account you would like to search for.");
			String yenope3 = yeno.next();
			int hold = 0;
			for (int x = 0; x <= accounts.size()-1; x++)
			{
				hold = x;
				if (accounts.get(x).equals(yenope3))
					break;
			}
			System.out.println("Account found: " + accounts.get(hold) + " $" + balance.get(hold));
		}
		
		
		System.out.println("Would you like to delete an account?");
		String yenope7 = yeno.next();
		if (yenope7.equals("Yes"))
		{
			System.out.println("Please enter the account number of the account you would like to delete.");
			String yenope73 = yeno.next();
			int hold7 = 0;
			for (int x = 0; x <= accounts.size()-1; x++)
			{
				hold7 = x;
				if (accounts.get(x).equals(yenope73))
					break;
			}
			System.out.println("Account found: " + accounts.get(hold7) + " $" + balance.get(hold7));
			System.out.println("Deleting records...");
			accounts.remove(hold7);
			balance.remove(hold7);
			System.out.println("Sucessfully deleted records! Press any key and then enter to continue.");
			yeno.next();
		}
		
		
		System.out.println("Would you like to add or withdraw funds to or from an account?");
		String yenope4 = yeno.next();
		if (yenope4.equals("Yes"))
		{
			System.out.println("Would you like to add or withdraw?");
			String yenope5 = yeno.next();
			if (yenope5.equals("Add"))
			{
				System.out.println("Enter the account number you would like to add funds to.");
				String num1 = yeno.next();
				int hold1 = 0;
				for (int x = 0; x <= accounts.size()-1; x++)
				{
					hold1 = x;
					if (accounts.get(x).equals(num1))
						break;
				}
				System.out.println("Account found: " + accounts.get(hold1) + " $" + balance.get(hold1));
				System.out.println("How much will you add?");
				double sub = Double.parseDouble(yeno.next());
				balance.set(hold1, (balance.get(hold1) + sub));
				System.out.println("Account modified to: " + accounts.get(hold1) + " $" + balance.get(hold1));
			}
			else if (yenope5.equals("Withdraw"))
			{
				System.out.println("Enter the account number you would like to subtract funds from.");
				String num2 = yeno.next();
				int hold2 = 0;
				for (int x = 0; x <= accounts.size()-1; x++)
				{
					hold2 = x;
					if (accounts.get(x).equals(num2))
						break;
				}
				System.out.println("Account found: " + accounts.get(hold2) + " $" + balance.get(hold2));
				System.out.println("How much will you withdraw?");
				double sub1 = Double.parseDouble(yeno.next());
				balance.set(hold2, (balance.get(hold2) - sub1));
				System.out.println("Account modified to: " + accounts.get(hold2) + " $" + balance.get(hold2));
				
			}
			
			
		}
		}
		
		
		
		
		
		
		/*
		
		Employee ComputerProgrammer = new Employee("Alexis Renderos", 55000);
		Employee.getWorkerB();
		Employee.raiseSalary(0.10);
		
		*/
	}

}
