
public class Pair
{
	private double a;
	private double b;
	public Pair(double aFirst, double aSecond) {
		a = aFirst;
		b = aSecond;
		String str = a + " " + b + "\n Sum = " + findSum() + "\n Difference = " + findDif() + "\n Product = " + findProd() + "\n Average = " + findAvg() + "\n Absolute Value = " + findAbs() + "\n Max = " + findMaxie() + "\n Min = " + findMinnie();
		System.out.println(str);
	}
	
	public double findSum()
	{
		return a + b;
	}

	public double findDif()
	{
		return a - b;
	}
	
	public double findProd()
	{
		return a * b;
	}
	
	public double findAvg()
	{
		return ( a + b ) / 2;
	}
	
	public double findAbs()
	{
		return Math.abs(a - b);
	}
	
	public double findMaxie()
	{
		return Math.max((a), (b));
	}
	
	public double findMinnie()
	{
		return Math.min((a),(b));
	}
	

	

}
