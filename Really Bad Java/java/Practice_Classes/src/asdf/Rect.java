package asdf;

public class Rect {

	public double sideR1;
	public double sideR2;
	public double areaR;
	public double periR;
	public double diagR;
	
	
	public Rect(double r, double t) //constructor method
	{
	sideR1 = r;
	sideR2 = t;
	areaR = sideR1 * sideR2;
	periR = (sideR1 * 2) + (sideR2 * 2);
	diagR = (Math.sqrt((Math.pow(sideR1, 2) + Math.sqrt((Math.pow(sideR2, 2))))));
    }
	
	public String toString()
	{
		return "Rectangle::: Side1: " + sideR1 + " Side2: " + sideR2 + " Perimiter: " + periR + " Area: " + areaR + " Diagonal: " + diagR;
	}
}
