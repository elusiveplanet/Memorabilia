
public class CardSearch {

	int cardNum;

	
	
public String CardSearch1(int cardNum2) {
cardNum = cardNum2; //King of Diamonds
	
	if (cardNum >= 40)
	{
		
		return "D" +  CardFinder113();
		
	}
	else if (cardNum >= 27 && cardNum <= 39)
	{
		
		return "C" +  CardFinder113();
	
	}
	else if (cardNum >= 14 && cardNum <= 26)
	{
		
		return "H" +  CardFinder113();
	
	}
	else if (cardNum >= 1 && cardNum <= 13)
	{
		
		return "S" +  CardFinder113();
	}
	else return null;
}

public void CardSearch5(int CardNumber) {

	cardNum = CardNumber; //King of Diamonds
	
	if (cardNum >= 40)
	{
		
		System.out.println("The Card numbered: " + cardNum + " is the " + CardFinder113() + " of Diamonds!");
		
	}
	else if (cardNum >= 27 && cardNum <= 39)
	{
		
		System.out.println("The Card numbered: " + cardNum + " is the " + CardFinder113() + " of Clubs!");
	
	}
	else if (cardNum >= 14 && cardNum <= 26)
	{
		
		System.out.println("The Card numbered: " + cardNum + " is the " + CardFinder113() + " of Hearts!");
	
	}
	else if (cardNum >= 1 && cardNum <= 13)
	{
		
		System.out.println("The Card numbered: " + cardNum + " is the " + CardFinder113() + " of Spades!");
	
	}
	
}

public String CardFinder113()
{
	if (cardNum % 13 == 0)
	{
	return "King";
	}
	else if (cardNum % 13 == 1)
	{
	return "Ace";
	}
	else if (cardNum % 13 == 2)
	{
	return "2";
	}
	else if (cardNum % 13 == 3)
	{
	return "3";
	}
	else if (cardNum % 13 == 4)
	{
	return "4";
	}
	else if (cardNum % 13 == 5)
	{
	return "5";
	}
	else if (cardNum % 13 == 6)
	{
	return "6";
	}
	else if (cardNum % 13 == 7)
	{
	return "7";
	}
	else if (cardNum % 13 == 8)
	{
	return "8";
	}
	else if (cardNum % 13 == 9)
	{
	return "9";
	}
	else if (cardNum % 13 == 10)
	{
	return "10";
	}
	else if (cardNum % 13 == 11)
	{
	return "Jack";
	}
	else if (cardNum % 13 == 12)
	{
	return "Queen";
	}
	else
	return null;
 }




@SuppressWarnings("null")
public void CardSearch1() {
	
String cardDeck[] = null;
	
	for (int i = 0; i < 52; i++)
	{
		cardDeck[i] = CardSearch1(i);
	}
	for (int i = 0; i < 52; i++)
	{
		System.out.println(cardDeck[i]);
	}

	
}
	
}

