
public class Student {
	
	private static String Name;
	private static double score;
	private static double numScore;
	
	public Student(String iName) 
	{
		Name = iName;
	}

	public static void getStudentB() 
	{
		System.out.println("Here is the specified student: " + Name + "\nHeres the score of the specified student: " + score);
	}
	
	public static void addQuiz(int score) 
	{
		Student.score += score;
		numScore += 1;
	}
	
	public static void getScore() 
	{
		System.out.println("\nHeres the score of the specified student: " + score);
	}
	
	public static void getAvgScore() 
	{
		System.out.println("\nHeres the average score of the specified student: " + (score / numScore));
	}	
}
