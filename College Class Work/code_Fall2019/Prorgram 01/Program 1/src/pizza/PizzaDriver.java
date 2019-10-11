//Rustan Hoffman

package pizza;

import util.Keyboard;

import java.text.DecimalFormat;

public class PizzaDriver {
	static Keyboard keyboardInput = Keyboard.getKeyboard();
	static PizzaBuilder pizzaBuilderObj;
	final double seniorDiscount = 0.10;
	
	private static int menu() {
		System.out.println("\n");
		System.out.println("1. Meat Lover's");
		System.out.println("2. Veggie Lover's");
		System.out.println("3. Hawaiian");
		System.out.println("4. Build Your Own");
		int choice = 0;
		do {
			choice = keyboardInput.readInt("\nSelect from the above: ");
		} while (choice < 1 || choice > 4);
		return choice;
	}
	
	private static void requestSize(PizzaBuilder builderObj) {
		char pizzaSize;
		while (true) {
			pizzaSize = keyboardInput.readString("\nWhat size pizza (S, M, or L): ").toUpperCase().charAt(0);
			if (builderObj.setSize(pizzaSize)) {
				return;
			}
		}
	}
	
	private static void requestCrust(PizzaBuilder pizza_builder) {
		String crustSelection;
		do {
			crustSelection = keyboardInput.readString("\nWhat type of crust (THIN, HAND, or PAN): ").toUpperCase();
			if (pizza_builder.setCrust(crustSelection)) {
				return;
			}
		} while (true);
	}
	
	private static void requestToppings(PizzaBuilder pizza_builder) {
		String inputBuffer;
		do {
			System.out.println("Enter the specified letter of the selection you would like:");
			System.out.println("\t(P)epperoni");
			System.out.println("\t(O)nions");
			System.out.println("\t(G)reen Peppers");
			System.out.println("\t(S)ausage");
			System.out.println("\t(M)ushrooms");
			System.out.println("\t(H)am");
			System.out.println("\tPine(A)pple");
			System.out.println("(D)one");
			inputBuffer = keyboardInput.readString("Selection: ");
			char choice = inputBuffer.toUpperCase().charAt(0);
			if (choice == 'D' || choice == 'd') {
				return;
			}
			pizza_builder.addTopping(choice);
		} while (true);
	}
	
	private static void showOrder(DecoratedPizza dec_pizza) {
		System.out.println("Your pizza order is: \n" + dec_pizza.toString() + "\n");
		System.out.println("The pizza costs: " + dec_pizza.pizzaCost());
	}
	
	public static void main(String[] args) {
		String inputBuffer = "";
		DecoratedPizza decPizza;
		double totalCost = 0.00;
		long numPizza = 0;
		DecimalFormat doubleF = new DecimalFormat(" #0.00");
		
		inputBuffer = keyboardInput.readString("Would you like to order a pizza(y/n)?: ");
		while (inputBuffer.toUpperCase().charAt(0) == ('Y')) {
			int choice = menu();
			
			
			pizzaBuilderObj = new PizzaBuilder();
			
			
			switch (choice) {
				case 1: {
					pizzaBuilderObj = new Pizza_Special_MeatLovers();
					requestSize(pizzaBuilderObj);
					requestCrust(pizzaBuilderObj);
					break;
				}
				case 2: {
					pizzaBuilderObj = new Pizza_Special_VeggieLover();
					requestSize(pizzaBuilderObj);
					requestCrust(pizzaBuilderObj);
					break;
				}
				case 3: {
					pizzaBuilderObj = new Pizza_Special_Hawaiian();
					requestSize(pizzaBuilderObj);
					requestCrust(pizzaBuilderObj);
					break;
				}
				case 4: {
					pizzaBuilderObj = new PizzaBuilder();
					requestSize(pizzaBuilderObj);
					requestCrust(pizzaBuilderObj);
					requestToppings(pizzaBuilderObj);
					break;
				}
				
			}

			boolean seniorLoopContinue = true;
			do {
				inputBuffer = keyboardInput.readString("Are you eligable for the senior discount? (y/n): ");
				if (inputBuffer.toUpperCase().charAt(0) == 'Y') {
					seniorLoopContinue = false;
					pizzaBuilderObj.addDiscount("senior discount", (double) 0.10);
				}
				else if(inputBuffer.toUpperCase().charAt(0) == 'N') {
					seniorLoopContinue = false;
				}
				else {
					System.out.println("Invalid input, try again");
					seniorLoopContinue = true;
				}
			} while (seniorLoopContinue);
			
			
			//ask about senior discount, 
			boolean deliverLoopContinue = true;
			do {
				inputBuffer = keyboardInput.readString("Would you like the pizza delivered for $2.50? (y/n): ");
				if (inputBuffer.toUpperCase().charAt(0) == 'Y') {
					deliverLoopContinue = false;
					pizzaBuilderObj.addFee("Delivery", (double) 2.50);
				}
				else if(inputBuffer.toUpperCase().charAt(0) == 'N') {
					deliverLoopContinue = false;
				}
				else {
					System.out.println("Invalid input, try again");
					deliverLoopContinue = true;
				}
			} while (deliverLoopContinue);

			decPizza = pizzaBuilderObj.pizzaDone();
			System.out.println(decPizza);
			showOrder(decPizza);
			totalCost += decPizza.pizzaCost();
			System.out.println("Cost of the pizza: $" + doubleF.format(decPizza.pizzaCost()));
			System.out.println("Your total so far is : $" + doubleF.format(totalCost));

			inputBuffer = keyboardInput.readString("Would you like to order another pizza (y/n): ");
		}
		
		System.out.println("You ordered: " + numPizza + " Pizza(s)");
		System.out.println("Your total price: $" + doubleF.format(totalCost));
	}
}
