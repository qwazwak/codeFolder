
//Rustan Hoffman and Rebecca Damewood

import java.util.concurrent.TimeUnit;

public class Driver {
	static Keyboard cin;
	
	public static void main(String[] args) {
		double runningTotal = 0;
		Cone theCone;
		while ((cin.readString("Would you like to order an ice cream cone? (y/n)")).compareTo((String) "y") == 1) {
			theCone = getConeChoice();
			runningTotal 
			
		}
		
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
