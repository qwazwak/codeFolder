//Rustan Hoffman and Rebecca Damewood


public class Driver {
	static Keyboard cin = Keyboard.getKeyboard();
	static Toppings theRealToppings = Toppings.getToppings();
	static Flavors theRealFalvors = Flavors.getFlavors();
	
	public static void main(String[] args) {
		double runningTotal = 0;
		IceCreamCone theFullCone;
		long numberOfObjectsOrdered = 0;
		final String no = new String("n");
		String input;
		boolean shouldContinue = true;
		
		do {

			Flavor theFlavor = getFlavorChoice();
			Topping theTopping = getToppingChoice();
			int theScoops = getScoopsChoice();
			Cone theCone = getConeChoice();
			
			
			theFullCone = new IceCreamCone(new IceCream(theScoops, theFlavor, theTopping), theCone);
			runningTotal += theFullCone.getPrice();
			++numberOfObjectsOrdered;

			System.out.println("");
			System.out.println("Your order:");
			System.out.println("Cone:    " + theCone.toString());
			System.out.println("Flavor:  " + theFlavor.toString());
			System.out.println("Number of scoops: " + theScoops);
			System.out.println("Topping: " + theTopping.toString());
			System.out.println("Price:   " + theFullCone.getPrice());


			System.out.println("");
			input = cin.readString("Would you like to order an ice cream cone? (y/n)");
			while(!(input.equals("y") || input.equals("n"))) {
				System.out.println("Invalid input");
				input = cin.readString("Would you like to order an ice cream cone? (y/n)");
			}
			if(no.equals(input)) {
				shouldContinue = false;
			}

		}while(shouldContinue);
		
		System.out.println("Your total order for " + numberOfObjectsOrdered + " orders is $" + runningTotal);
	}
	

	public static Topping getToppingChoice() { //look at the methods available in the Toppings class
		int theToppingID;

		System.out.println(theRealToppings.listToppings());

		theToppingID = cin.readInt("Enter the number of the topping you would like: ");
		while(theToppingID < 1 || theToppingID > theRealToppings.numToppings()) {
			theRealToppings.listToppings();
			System.out.println("Invalid input, try again");
			theToppingID = cin.readInt("Enter the number of the topping you would like: ");
		}
		
		return theRealToppings.getTopping(theToppingID);
	}
	
	
	public static Flavor getFlavorChoice() { //look at the methods available in the Flavors class
		int theFlavorID = (int)0;
		
		System.out.println(theRealFalvors.listFlavors());


		
		theFlavorID = cin.readInt("Enter the number of the flavor you would like: ");
		while(theFlavorID < 1 || theFlavorID > theRealFalvors.numFlavors()) {
			theRealFalvors.listFlavors();
			System.out.println("Invalid input, try again");
			theFlavorID = cin.readInt("Enter the number of the flavor you would like: ");
		}
		
		return theRealFalvors.getFlavor(theFlavorID);
		
	}
	
	public static int getScoopsChoice() {
		int numScoops;
	
		numScoops = cin.readInt("How many scoops (1, 2, or 3) would you like? ");
		
		while(numScoops < 1 || numScoops > 3)
		{
			System.out.println("Invalid input, try again");
			numScoops = cin.readInt("How many scoops (1, 2, or 3) would you like? ");
		}
		return numScoops;
	}
	
	public static Cone getConeChoice() {
		int typeOfCone;

		System.out.println("1. Sugar cone  - $0.59");
		System.out.println("2. Waffle cone - $0.79");
		System.out.println("3. Cup         - $0.00");
		typeOfCone = cin.readInt("Enter the number of the cone you would like: ");
		while(typeOfCone < 1 || typeOfCone > 3) {
			System.out.println("1. Sugar cone  - $0.59");
			System.out.println("2. Waffle cone - $0.79");
			System.out.println("3. Cup         - $0.00");
			System.out.println("Invalid input, try again");
			typeOfCone = cin.readInt("Enter the number of the cone you would like: ");
		}
		return new Cone(typeOfCone);
	}
	
	
}
