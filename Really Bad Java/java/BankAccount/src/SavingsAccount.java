import java.util.ArrayList;


public class SavingsAccount {

	protected double balance;
	protected int numTransact;
	protected String acctN;
	protected static int nextAcctN = 0;
	protected double interestRates;
	int day,month,year,acctnum;
	String accountnum = "";
	
	
	protected SavingsAccount(int day, int month, int year)
	{
		acctN = "00" + String.valueOf(nextAcctN);
		
		accountnum = nextAcctN(day,month,year,acctN);
		System.out.println(accountnum);
		balance = 0;
		numTransact = 0;
		nextAcctN += 1;
	}
	
	protected String nextAcctN(int day, int month, int year, String acctnum)
	{
		return String.valueOf(month) + String.valueOf(day) + String.valueOf(year) + acctnum;
	}
	
	protected String getnum()
	{
		return(accountnum);
	}
	
	protected double getbal()
	{
		return(balance);
	}
	
	protected void addInterest()
	{
		balance += interestRates * balance;
		System.out.println(balance + "\n");
	}
}
