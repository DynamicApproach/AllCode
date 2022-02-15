import java.util.Random;

/**
 * A tester application that to test the Card class.  
 * It checks the Card class's public data fields, constructor, toString, and compareTo method.
 * 
 * @author McLaughlin
 * @version 10.4.19
 * 
 *
 */
public class CardTester 
{	
	/**
	 * Application ... has to have main method.
	 * 
	 * @param args Not used.
	 */
	public static void main(String[] args) 
	{
		Card c1 = new Card(4,Card.CLUBS);
		Card c2 = new Card(Card.KING, Card.HEARTS);
		Card c3 = new Card(Card.ACE, Card.DIAMONDS);

		System.out.println( c1 );
		System.out.println("4 of Clubs" + " EXPECTED");
		System.out.println( c2.toString() );
		System.out.println("King of Hearts" + " EXPECTED");

		//compare 4 of clubs (c1) with king of hearts (c2)  (should be smaller: -1)
		System.out.println( "\nComparing cards: " + c1.compareTo(c2) );
		System.out.println( " Expected value: " + -1 );

		//compare king of hearts (c2) with 4 of clubs (c1) (should be larger: 1)
		System.out.println( "\nComparing cards: " + c2.compareTo(c1) );
		System.out.println( " Expected value: " + 1 );

		//compare a king of hearts (c2) with another king of hearts (c2) (should be equal: 0)
		System.out.println( "\nComparing cards: " + c2.compareTo(new Card(Card.KING, Card.HEARTS)) );
		System.out.println( " Expected value: " + 0 );

		//compare a 4 of clubs with a 4 of hearts:  (should be smaller: -1)
		System.out.println( "\nComparing cards: " + c1.compareTo( new Card(4, Card.HEARTS)) );
		System.out.println( " Expected value: " + -1 );
		
		//compare a card with itself:  (should be same/equal: 0)
		System.out.println( "\nComparing card with itself: " + c3.compareTo( c3 ) );
		System.out.println( " Expected value: " + 0 );

		System.out.println( "\n\nCreate a bunch of random cards and compare them ...\n");

		final int A_BUNCH_OF_TESTS = 12;

		Random gen = new Random();

		for(int i=0; i<A_BUNCH_OF_TESTS; i++)
		{

			//create two random cards
			Card temp1 = new Card(gen.nextInt(13)+1, gen.nextInt(4) );
			Card temp2 = new Card(gen.nextInt(13)+1, gen.nextInt(4) );

			if( temp1.compareTo(temp2) > 0)
			{
				System.out.println( temp1 + " is \"bigger\" than " + temp2);
			}
			else if( temp1.compareTo(temp2) == 0)
			{
				System.out.println( temp1 + " is the same as " + temp2);
			}
			else
			{
				System.out.println( temp1 + " is \"smaller\" than " + temp2);	
			}

		}
	}
}