//Rustan Hoffman and Rebecca Damewood

import java.util.concurrent.TimeUnit;

public class Driver {
	static Keyboard cin;
	
	public static void main(String[] args) {
		double runningTotal = 0;
		IceCreamCone theFullCone;
		long numberOfObjectsOrdered = 0;
		while ((cin.readString("Would you like to order an ice cream cone? (y/n)")).compareTo((String) "y") == 1) {
			theCone = getConeChoice();

			Flavor theFlavor = getFlavorChoice();
			int theScoops = getScoopsChoice();
			Topping theTopping = getToppingChoice();
			Cone theCone = getConeChoice();
			
			
			theFullCone = new IceCreamCone(new IceCream(theScoops, theFlavor, theTopping), theCone);
			runningTotal += theFullCone.getPrice();
			++numberOfObjectsOrdered;
			
		}
		
		System.out.println("Your total order for " + numberOfObjectsOrdered + " is $" + runningTotal);
		System.out.println("ending");
	}
	
	public static Flavor getFlavorChoice() { //look at the methods available in the Flavors class
			
		return Flavors.getFlavor(4);
		
	}
	
	public static Topping getToppingChoice() { //look at the methods available in the Toppings class
	}
	
	public static int getScoopsChoice() {
	}
	
	public static Cone getConeChoice() {
		Flavor theFlavor;
		Topping theTopping;
		int theNumberOfScoops;
		
		return new Cone();
	}
	
	
}
