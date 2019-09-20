
/**
 * Represents one or more decks of cards.
 */
public class Decks {
	/** An array of Cards representing multiple complete decks of the standard 52 deck of cards. */
	private Card[] decks;
	/** The number of Cards remaining in the deck. */
	private int count;
	/** The number of Decks. */
	private int numDecks;
	
	/** The total number of Cards. */
	private final int SIZE;
	/** The size of a standard deck of cards. */
	public final int STANDARD_DECK_SIZE = 52;
	
	/**
	 * Constructor to create several copies of the standard 52 deck of cards and to shuffle them all together.
	 */
	public Decks(int num) {
		if (num > 0 && num < 10) {
			this.numDecks = num;
		} else {
			this.numDecks = 1;
		}
		
		this.SIZE = this.STANDARD_DECK_SIZE * this.numDecks;
		this.count = 0;
		this.decks = new Card[this.SIZE];
		
		//create multiple decks
		for (int i = 0; i < this.numDecks; i++) 
		{
			//DO THIS (create the cards (using the Card constructor), add to the decks array)
			//Note from the Card class that integers from 1 to 52 passed to the Card constructor will create the corresponding Card
			//you will need a counter (the count integer above) to insert the Cards into the decks array
			//because Card is one-based
			for (int y = 1; y <= this.STANDARD_DECK_SIZE; y++) {
				this.decks[(i * 52) + y - 1] = new Card(y);
				
				
				//note that we are starting at index 1 here
				
				
			}
		}
		
		//mix them up
		this.shuffle();
		
		
	}
	
	/**
	 * Shuffles the Cards by selecting a random location for each Card.
	 * Create a new array of Cards.
	 * Move each Card in the original Deck to a random location in the new Deck.
	 * Set count so that all of the cards are available again.
	 */
	public void shuffle() {
		//use the Permutation class to shuffle the Cards
		Card[] shuffled_deck = new Card[SIZE];
		
		Permutation permuteGen = new Permutation(SIZE, SIZE); //p.next() will give you a random index without duplicates
		
		//go through all of the cards in decks and shuffle them into shuffled_deck
		for(int i = 0; i < SIZE; ++i) {
			shuffled_deck[i] = decks[permuteGen.next() - 1];
		}
		
		decks = shuffled_deck;
		//reset the count as all the cards are available to be dealt again 
		count = SIZE - 1; //the entire deck is available again
	}
	
	/**
	 * Returns the next Card in the Deck. If the Deck is empty, the Deck is shuffled.
	 * Use your count instance variable to determine which Card to return.
	 * Decrement count.
	 */
	public Card deal() {
		System.out.println("Decks.deal()");

		Card current = null;
		
//		if (count == -1) {
		if (count < 0) {
			System.out.println("deck deal - count triggered");
			shuffle();
		}
		current = decks[count];
		count = count -1;
		return current;
	}
	
	/**
	 * Returns the number of Cards remaining in the Deck.
	 */
	public int getCount() {
		return this.count + 1;
	}
	
	/**
	 * Returns the number of Decks.
	 */
	public int getNumDecks() {
		return this.numDecks;
	}
	
	/**
	 * Lists the Cards remaining in the Deck.
	 */
	public String toString() {
		String temp = "";
		
		for (int i = count; i >= 0; i--) {
			temp += decks[i] + "\r\n";
		}
		
		return temp;
	}
}
