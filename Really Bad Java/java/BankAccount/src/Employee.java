
public class Employee 
{

	//3.7 to do
	
	private static double Salary;
	private static String Name;
	
	public Employee(String iName, double iSalary) 
	{
		Salary = iSalary;
		Name = iName;
	}

	public static void getWorkerB() 
	{
		System.out.println("Here is the specified worker: " + Name + "\nHeres the salary of the specified worker: " + Salary);
	}
	
	public static void raiseSalary(double raise) 
	{
		Salary += Salary * raise;
		System.out.println("\nHeres the new salary of the specified worker: " + Salary);
	}
	
	public static void main(String[] args) 
	{

	}


}
