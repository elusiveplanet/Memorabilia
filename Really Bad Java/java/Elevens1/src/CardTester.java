/**
 * This is a class that tests the Card class.
 */
public class CardTester {

	/**
	 * The main method in this class checks the Card operations for consistency.
	 *	@param args is not used.
	 */
	public static void main(String[] args) {
		Card AceSpades1 = new Card("Ace", "Spades", 1);
		Card AceSpades2 = new Card("Ace", "Spades", 1);
		Card TwoSpades1 = new Card("Two", "Spades", 2);
		System.out.println(AceSpades1.rank());
		System.out.println(AceSpades1.suit());
		System.out.println(AceSpades1.pointValue());
		System.out.println(AceSpades1.matches(TwoSpades1));
		System.out.println(AceSpades1.matches(AceSpades2));
	}
}
