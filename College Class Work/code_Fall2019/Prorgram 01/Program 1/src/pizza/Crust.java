//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

public class Crust {
	private char size;
	private String type;
	
	public Crust(String theType, char theSize) {
		type = theType;
		size = theSize;
	}
	
	
	public double crustCost() {
		double runningTotal = 0;
		switch(size) {
			case 'S':
				runningTotal += CrustSize.S.cost();
				break;
			case 'M':
				runningTotal += CrustSize.S.cost();
				break;
			case 'L':
				runningTotal += CrustSize.S.cost();
				break;
				default:
		}
		switch(type) {
			case "THIN":
				runningTotal += CrustType.THIN.cost();
				break;
			case "HAND":
				runningTotal += CrustType.HAND.cost();
				break;
			case "PAN":
				runningTotal += CrustType.PAN.cost();
				break;
				default:
		}
		return runningTotal;
	}
	
	
	public char getSize() {
		return size;
	}
	
	
	public String getCrust() {
		return type;
	}
	

	public String toString() {
		return new String("Size: " + size + "\n" + "Crust: " + type + "\n");
	}
	
	public String getImage() {
		return type;
	}
	
}
