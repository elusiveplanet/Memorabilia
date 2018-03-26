/**
 * This is a class that tests the Deck class.
 */
public class DeckTester {

	/**
	 * The main method in this class checks the Deck operations for consistency.
	 *	@param args is not used.
	 */
	public static void main(String[] args) {
		//Deck(String[] ranks, String[] suits, int[] values) <-- implementation
		
		/*
		String[] ranks = {"ace", "two", "three"};
		String[] suits = {"blue","white"};
		int[] values = {1,2,3};
		
		Deck Deck1 = new Deck(ranks,suits,values);
		
		System.out.println(Deck1.size());
		System.out.println(Deck1.isEmpty() + "\n"); //newline for dealt card data
		
		Card hold = Deck1.deal(); //card object to hold dealt card
		
		System.out.println(hold.rank()); //retrieves all dealt card data then prints
		System.out.println(hold.suit());
		System.out.println(hold.pointValue());
		
		System.out.println("\n"); //newline for data
		
        Card hold2 = Deck1.deal(); //deals another card
		
		System.out.println(hold2.rank()); //retrieves all dealt card data then prints
		System.out.println(hold2.suit());
		System.out.println(hold2.pointValue());
		*/
		
		String[] ranks21 = {"Ace", "King", "Queen", "Jack", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two"};
		String[] suits21 = {"Hearts","Spades", "Clubs","Diamonds"};
		int[] values21 = {11,10,10,10,10,9,8,7,6,5,4,3,2};
		
		Deck Deck21 = new Deck(ranks21,suits21,values21);

		System.out.println(Deck21.size());
		System.out.println(Deck21.isEmpty() + "\n");
		
        Card hold = Deck21.deal(); //card object to hold dealt card
		
		System.out.println(hold.rank()); //retrieves all dealt card data then prints
		System.out.println(hold.suit());
		System.out.println(hold.pointValue() + "\n");
		
        Card hold2 = Deck21.deal(); //deals another card
		
		System.out.println(hold2.rank()); //retrieves all dealt card data then prints
		System.out.println(hold2.suit());
		System.out.println(hold2.pointValue());
	    
		
	}
}
