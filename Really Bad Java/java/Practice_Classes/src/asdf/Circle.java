package asdf;

public class Circle {

		public double Radius;
		public double circum;
		public double areaC;
		public double Diameter;
		
		public Circle(double r) //constructor method
		{
		Radius = r;
		areaC = (Math.pow(Radius, 2) * Math.PI);
		circum = 2 * Math.PI * Radius;
		Diameter = r * 2;
	    }
		
		public String toString()
		{
			return "Circle::: Radius: " + Radius + " Area: " + areaC + " Circumference: " + circum + " Diameter: " + Diameter;
		}
}
