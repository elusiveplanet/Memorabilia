package asdf;

public class Square1 {

	public double side;
	public double area;
	public double peri;
	public double diag;
	
	public Square1(double s) //constructor method
	{
		side = s;
		peri = 4 * side;
		area = Math.pow(side,  2);
		diag = Math.sqrt(2 * Math.pow(side,  2));
	}
	
	public String toString()
	{
		return "Square::: Sides: " + side + " Perimiter: " + peri + " Area: " + area + " Diagonal: " + diag;
	}
	
}
