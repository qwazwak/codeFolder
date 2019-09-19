//import java.awt.image.ImageObserver;
import java.awt.Graphics;
import java.awt.Image;

// 
// Decompiled by Procyon v0.5.36
// 
//added the <obj>
public class Card implements Comparable<Object> {
	private String face;
	private String suit;
	private Image card_image;
	private static Image[] card_images;
	
	public Card() {
		this(1);
	}
	
	public Card(final int n) {
		int i;
		if (n < 1 || n > 52) {
			this.suit = "Spades";
			i = 1;
		} else if (n <= 13) {
			this.suit = "Spades";
			i = n;
		} else if (n <= 26) {
			this.suit = "Hearts";
			i = n - 13;
		} else if (n <= 39) {
			this.suit = "Clubs";
			i = n - 26;
		} else {
			this.suit = "Diamonds";
			i = n - 39;
		}
		if (i == 11) {
			this.face = "Jack";
		} else if (i == 12) {
			this.face = "Queen";
		} else if (i == 13) {
			this.face = "King";
		} else if (i == 1) {
			this.face = "Ace";
		} else {
			this.face = "" + i;
		}
		this.card_image = Card.card_images[n - 1];
	}
	
	@Override
	public int compareTo(final Object o) {
		final Card card = (Card) o;
		final int n = this.getSuitInt() - card.getSuitInt();
		final int n2 = this.getFaceInt() - card.getFaceInt();
		if (n == 0 && n2 == 0) {
			return 0;
		}
		if (n2 != 0) {
			return n2;
		}
		return n;
	}
	
	public int getFaceInt() {
		if (this.face.equals("Jack")) {
			return 11;
		}
		if (this.face.equals("Queen")) {
			return 12;
		}
		if (this.face.equals("King")) {
			return 13;
		}
		if (this.face.equals("Ace")) {
			return 1;
		}
		return Integer.parseInt(this.face);
	}
	
	public int getSuitInt() {
		if (this.suit.equals("Spades")) {
			return 1;
		}
		if (this.suit.equals("Hearts")) {
			return 2;
		}
		if (this.suit.equals("Clubs")) {
			return 3;
		}
		return 4;
	}
	
	public String getSuit() {
		return this.suit;
	}
	
	public String getFace() {
		return this.face;
	}
	
	public void draw(final Graphics graphics, final int n, final int n2) {
		graphics.drawImage(this.card_image, n, n2, null);
	}
	
	@Override
	public String toString() {
		return "" + this.face + " of " + this.suit;
	}
	
	static {
		Card.card_images = new Image[52];
		int n = 0;
		final ImageLoader imageLoader = ImageLoader.getImageLoader();
		for (int i = 1; i <= 4; ++i) {
			for (int j = 1; j <= 13; ++j) {
				Card.card_images[n] = imageLoader.getImage("images/" + (i + "-" + j + ".gif"));
				++n;
			}
		}
	}
}
