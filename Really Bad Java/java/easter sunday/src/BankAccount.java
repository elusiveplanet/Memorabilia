import java.util.Scanner;

//Functions approved:
//N = new account asks for number asks for balance later
//A = adds amount asks for number asks for amount later
//S = subtracts amount asks for number asks for amount later

public class BankAccount {

	private double balance;
	
	public BankAccount()
	{
		balance = 0;
		
		Scanner quest = new Scanner(System.in);
		
		System.out.println("What would you like to do? ");
		String question = quest.next();
		
		System.out.println(question);
		
		switch(question)
		{
		case "N":
			Scanner value1 = new Scanner(System.in);
			System.out.println("What is the new balance for your new bank account? ");
			double balance = value1.nextDouble();
			NewBankAccount(balance);
			
		case "A":
			Scanner value2 = new Scanner(System.in);
			System.out.println("What is your current account number? ");
			double acctNumb1 = value2.nextDouble();
			System.out.println("How much are you placing in your account? ");
			double AmountAdd = value2.nextDouble();
			AddBankAccount(AmountAdd, acctNumb1);
			
		case "S":
			Scanner value3 = new Scanner(System.in);
			System.out.println("What is your current account number? ");
			double acctNumb2 = value3.nextDouble();
			System.out.println("How much are you taking out? ");
			double AmountSub = value3.nextDouble();
			SubBankAccount(AmountSub, acctNumb2);
		}
		
	}
	
	public double NewBankAccount(double newbal)
	{
		balance = newbal;
		return balance;
	}
	
	public double AddBankAccount(double subbal, double acctnumb1)
	{
		balance = subbal;
		return balance;
	}
	
	public double SubBankAccount(double addbal, double acctnumb2)
	{
		balance = addbal;
		return balance;
	}
	
}
