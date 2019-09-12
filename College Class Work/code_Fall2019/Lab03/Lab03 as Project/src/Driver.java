//Rustan Hoffman and Rebecca Damewood

import java.util.concurrent.TimeUnit;

public class Driver {
	static Keyboard cin;
	public static Toppings theRealToppings;
	public static Flavors theRealFalvors;
	public static void main(String[] args) {
		double runningTotal = 0;
		IceCreamCone theFullCone;
		long numberOfObjectsOrdered = 0;
		while ((cin.readString("Would you like to order an ice cream cone? (y/n)")).compareTo((String) "y") == 1) {

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
		int theFlavorID;

		theRealFalvors.listFlavors();
		theFlavorID = cin.readInt("Enter the number of the flavor you would like");
		while(theFlavorID < 1 || theFlavorID > theRealFalvors.numFlavors()) {
			theRealFalvors.listFlavors();
			System.out.println("Invalid input, try again");
			theFlavorID = cin.readInt("Enter the number of the flavor you would like");
		}
		
		return theRealFalvors.getFlavor(theFlavorID);
			
		
	}
	
	public static Topping getToppingChoice() { //look at the methods available in the Toppings class
		int theToppingID;

		theRealToppings.listToppings();
		theToppingID = cin.readInt("Enter the number of the topping you would like");
		while(theToppingID < 1 || theToppingID > theRealToppings.numToppings()) {
			theRealToppings.listToppings();
			System.out.println("Invalid input, try again");
			theToppingID = cin.readInt("Enter the number of the topping you would like");
		}
		
		return theRealToppings.getTopping(theToppingID);
	}
	
	public static int getScoopsChoice() {
		
	}
	
	public static Cone getConeChoice() {
		int typeOfCone;

		System.out.println("1. Sugar cone  - $0.59");
		System.out.println("2. Waffle cone - $0.79");
		System.out.println("3. Cup         - $0.00");
		typeOfCone = cin.readInt("Enter the number of the cone you would like");
		while(typeOfCone < 1 || typeOfCone > 3) {
			System.out.println("1. Sugar cone  - $0.59");
			System.out.println("2. Waffle cone - $0.79");
			System.out.println("3. Cup         - $0.00");
			System.out.println("Invalid input, try again");
			typeOfCone = cin.readInt("Enter the number of the cone you would like");
		}
		return new Cone(typeOfCone);
	}
	
	
}
