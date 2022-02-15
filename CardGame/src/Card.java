
public class Card {

	public static final int HEARTS = 0;
	
	public static final int CLUBS = 2;
	public static final int DIAMONDS = 1;
	
	public static final int SPADES = 4;
	String ranks[] = { "Joker", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King","Ace" };
	String suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
	public int rank;
	public int suit;
	public static final int ACE = 13;

	public static final int KING = 12;
	public static final int QUEEN = 11;
	public static final int JOKER = 0;
	public static void main(String[] args) {

	}

	public Card(int r, int s) {

		this.suit = s;
		this.rank = r;

	}

	public String toString() {
		String s = ranks[rank] + " of " + suits[suit];
		return s;
	}

	
	  public int compareTo( Card c2) { 
		  if (suit < c2.suit) { 
			  return -1;
	  } 
		  if(suit >c2.suit){
			  return 1; } 
		  if (rank < c2.rank) { 
			  return -1; } 
	  if (rank > c2.rank) { 
		  return 1; 
	  }
	  else { 
	  return 0;
	  }
}
}
