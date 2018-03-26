import java.util.ArrayList;

import java.util.ArrayList;

public class BankAccount {

	private double balance;
	private int numTransact;
	private int acctN;
	private static int nextAcctN = 1;
	private double interestRates;
	private double dumbATMfees;
	private double freeFees;
	
	ArrayList<String> accounts = new ArrayList<String>();
	
	public BankAccount()
	{
		acctN = nextAcctN;
		balance = 0;
		numTransact = 0;
		nextAcctN += 1;
	}
	
	public BankAccount(double iBal, double iFee)
	{
		acctN = nextAcctN;
		balance = iBal;
		numTransact = 0;
		nextAcctN += 1;
		dumbATMfees = iFee;
		
	}
	
	
	public void withdraw(double iAmount)
	{
		balance -= iAmount;
		numTransact += 1;
		
		if (numTransact <= 2)
		{
		freeFees += 1;
		}
		
	}
	
	public void deposit(double iAmount)
	{
		balance += iAmount;
		numTransact += 1;
		
		if (numTransact <= 2)
		{
		freeFees += 1;
		}
		
	}
	
	public void addInterest(double iRate)
	{
		balance += balance * (iRate / 100);
		interestRates = iRate;
	}
	
	public void addInter()
	{
		balance += balance * (interestRates / 100);
	}
	
	
	public void compileFees()
	{
		balance -= (numTransact - freeFees) * dumbATMfees;
		numTransact = 0;
	}
	
	public String toString()
	{
		return ("Account Number: " + acctN + " Balance: " + balance + "\n Number of Transactions: " + numTransact);
	}
	
}

