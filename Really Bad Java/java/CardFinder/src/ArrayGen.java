
public class ArrayGen {

    static String[] cardDeck = new String[54];
	
	public static void main(String[] args) {
	
		for (int x = 1; x <= 52; x++)
		{
            cardDeck[x] = getSuit(x) + getVal(x) + " ";
            System.out.print(cardDeck[x]);
            if (x%13==0)
            	System.out.println("");
		}
	}
public static String getSuit(int cardNum)
{
	if (cardNum >= 40)
	{
		return "D";
	}
	else if (cardNum >= 27 && cardNum <= 39)
	{	
		return "C";
	}
	else if (cardNum >= 14 && cardNum <= 26)
	{
		return "H";
	}
	else if (cardNum >= 1 && cardNum <= 13)
	{
		return "S";
	}
	else return null;
}

public static String getVal(int cardNum)
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

}
