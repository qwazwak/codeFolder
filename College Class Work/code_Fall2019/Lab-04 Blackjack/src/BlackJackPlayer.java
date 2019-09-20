import java.util.ArrayList;
import java.awt.Graphics;
import java.awt.Color;

public class BlackJackPlayer {
	private ArrayList<BlackJackHand> hands;
	private BlackJackStrategy strategy;
	private int index; //index of 1 is the first hand
	
	public BlackJackPlayer(String filename) {
		hands = new ArrayList<BlackJackHand>();
		strategy = new BlackJackStrategy(filename);
		index = 1; //keep track of which hand is being operated on by the game
		//maybe set me to 1? idk
	}
	
	public void draw(Graphics g, int width, int height) {
		System.out.println("Blackjack PLayer Hand Draw");
		int intOffset = width / 2 - (int) ((this.numHands() - 1) / 2.0 * 100.0);
		//DO THIS use a for-each loop to draw all of the player hands
		for (int i = 0; i < hands.size(); ++i) {
			hands.get(i).drawPlayerHands(g, intOffset + (hands.size() - 1) * 100 - 50, 300);
			if (hands.size() == index) //indicate the current hand with a yellow dot above the hand
			{
				g.setColor(Color.black);
				g.fillOval(intOffset + (hands.size() - 1) * 100 - 23, 284, 13, 13);
				g.setColor(Color.yellow);
				g.fillOval(intOffset + (hands.size() - 1) * 100 - 21, 285, 10, 10);
				g.setColor(Color.black);
			}
		}
		

		//count = (count + 1) % hands.size();
		
		
	}
	
	/**
	 * The player wants to split.
	 * You need to remove the hand that is being split from the ArrayList.
	 * Create two new hands and insert them into the appropriate place in the ArrayList.
	 */
	public void split(Card card1, Card card2) {
		System.out.println("BlackJackPlayer.split()");
		if (canSplit()) {
			//DO THIS
			//grab the current hand and split it
			//     BlackJackHand current = hands.get(index);
			BlackJackHand[] splitArr;
			splitArr = hands.get(index - 1).split(card1, card2);
			//remove the old hand and add the split hands in its place
			System.out.println("BlackJackPlayer.split() note: index is: " + index + "but minus 1 maybe");
			hands.set(index - 1, splitArr[1]);
			hands.add(splitArr[0]);
		}
		
	}
	
	/**
	 * The player wants to double down.
	 * Obtain the current hand using the index instance var.
	 * Hit the hand.
	 * Remember that you can only double a hand once (call a method in BlackJackHand to ensure this).
	 */
	public void doubleDown(Card dealt) {
		System.out.println("BlackJackPlayer.doubleDown()");
		//BlackJackHand hand = hands.get(index - 1);
		this.hands.get(this.index - 1).hit(dealt);
		this.hands.get(this.index - 1).doubleDown();
		
		//DO THIS (call a method in BlackJackHand)
		
		
	}
	
	public void hit(Card dealt) {
		this.hands.get(index - 1).hit(dealt);
	}
	
	public int result(BlackJackHand dealer) {
		int winnings = 0;
		int dValue = dealer.handValue();
		
		//DO THIS
		//use a for-each loop to compute the player's winnings over all player hands
		for (int i = 0; i < hands.size(); ++i) {
			
			int pValue = hands.get(i).handValue();
			
			//check for player bust first
			if (pValue > 21) {
				if (hands.get(i).isDouble()) {
					winnings -= 1;
				}
				winnings -= 1;
			}
			//only if player did not bust do we check for a dealer bust
			else if (dValue > 21) {
				if (hands.get(i).isDouble()) {
					winnings += 1;
				}
				winnings += 1;
			} else if (pValue > dValue) {
				if (hands.get(i).isDouble()) {
					winnings += 1;
				}
				winnings += 1;
			} else if (dValue > pValue) {
				if (hands.get(i).isDouble()) {
					winnings -= 1;
				}
				winnings -= 1;
			}
		}
		return winnings;
	}
	
	//'S' = stand, 'H' = hit, 'D' = double, 'P' = split
	public char optimal(BlackJackHand dealer) {
		if (index > numHands()) {
			return 0;
		}
		
		BlackJackHand hand = hands.get(index - 1);
		
		//first, determine if a split is possible
		boolean can_split = canSplit();
		if (can_split) {
			//if a split is possible, should we do it?
			boolean should_split = strategy.shouldSplit(hand, dealer);
			if (should_split) {
				return 'P';
			}
		}
		
		char optimal = strategy.getMove(hand, dealer);
		//make sure the player can double if that is the optimal move (else just hit)
		if (optimal == 'D' && hand.numCards() > 2) {
			optimal = 'H';
		}
		
		return optimal;
	}
	
	public int numHands() {
		return this.hands.size();
	}
	
	public boolean isDone() {
		return (this.index > this.numHands());
	}
	
	//starting a new hand
	public void removeAllHands(BlackJackHand playersHand) {
		this.hands.clear();
		this.index = 1;
		this.hands.add(this.index - 1, playersHand);
	}
	
	public void nextHand() {
		this.index++;
		if(this.index > this.numHands()) {
			index = 1;
		}
	}
	
	public boolean canSplit() {
		if (index > numHands()) {
			return false;
		}		
		return this.hands.get(index - 1).canSplit();
	}
	
	public int handValue() {
		return this.hands.get(index - 1).handValue();
	}
}
