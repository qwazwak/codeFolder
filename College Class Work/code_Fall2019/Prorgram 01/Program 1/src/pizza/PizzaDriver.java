//Rustan Hoffman

package pizza;

import util.Keyboard;

import java.text.DecimalFormat;

public class PizzaDriver {
	static Keyboard keyboardInput = Keyboard.getKeyboard();
	static PizzaBuilder pizzaBuilderObj;
	static DecoratedPizza decPizza;
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
			if (pizzaSize == 'S' || pizzaSize == 'M' || pizzaSize == 'L') {
				builderObj.setSize(pizzaSize);
				return;
			}
		}
	}
	
	private static void requestCrust(PizzaBuilder pizza_builder) {
		String crustSelection;
		do {
			crustSelection = keyboardInput.readString("\nWhat type of crust (THIN, HAND, or PAN): ").toUpperCase();
			if (crustSelection.equals("THIN") || crustSelection.equals("HAND") || crustSelection.equals("PAN")) {
				pizza_builder.setCrust(crustSelection);
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
		double totalCost = 0.00;
		long numPizza = 0;
		DecimalFormat doubleF = new DecimalFormat(" #0.00");
		
		
		inputBuffer = keyboardInput.readString("Would you like to order a pizza(y/n)?: ");
		while (inputBuffer.toUpperCase().charAt(0) == ('Y')) {
			int choice = menu();
			
			
			pizzaBuilderObj = new PizzaBuilder();
			pizzaBuilderObj.buildPizza();

			requestSize(pizzaBuilderObj);
			requestCrust(pizzaBuilderObj);
			
			switch (choice) {
				case 1: {
					pizzaBuilderObj = new Pizza_Speacial_MeatLovers();			
					break;
				}
				case 2: {
					pizzaBuilderObj = new Pizza_Speacial_VeggieLover();	
					break;
				}
				case 3: {
					pizzaBuilderObj = new Pizza_Speacial_Hawaiian();	
					break;
				}
				case 4: {
					pizzaBuilderObj = new PizzaBuilder();
					requestToppings(pizzaBuilderObj);
					break;
				}
				
			}
/*
 * In PizzaDriver, ask the user if they want delivery. If so, add a $2.50 delivery fee to the order. 
 */
			
			//ask about senior discount, 
			decPizza = pizzaBuilderObj.pizzaDone();
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
