//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

import util.Keyboard;
import java.text.DecimalFormat;

public class PizzaDriver {
	static final DecimalFormat doubleF = new DecimalFormat("#0.00");
	static Keyboard keyboardInput = Keyboard.getKeyboard();
	static PizzaBuilder pizzaBuilderObj;
	
	private static int menu() {
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
		do {
			try {
				pizzaSize = keyboardInput.readString("\nWhat size pizza (S, M, or L): ").toUpperCase().charAt(0);
			} catch (StringIndexOutOfBoundsException e) {
				System.out.println("Invalid input, try again");
				pizzaSize = '0';
			}
			
		} while (!(builderObj.setSize(pizzaSize)));
	}
	
	private static void requestCrust(PizzaBuilder pizza_builder) {
		String crustSelection;
		do {
			crustSelection = keyboardInput.readString("\nWhat type of crust (THIN, HAND, or PAN): ").toUpperCase();
		} while (!(pizza_builder.setCrust(crustSelection)));
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
			try {
				inputBuffer = keyboardInput.readString("Selection: ").toUpperCase();
				if (inputBuffer.toUpperCase().charAt(0) == 'D') {
					return;
				}
			} catch (StringIndexOutOfBoundsException e) {
				inputBuffer = "0";
			}
			pizza_builder.addTopping(inputBuffer.toUpperCase().charAt(0));
		} while (true);
	}
	
	private static void showOrder(DecoratedPizza dec_pizza) {
		System.out.println("Your pizza order is: \n" + dec_pizza.toString() + "\n");
		System.out.println("The pizza costs: " + doubleF.format(dec_pizza.pizzaCost()));
	}
	
	public static void main(String[] args) {
		String inputBuffer = "";
		DecoratedPizza decPizza;
		double totalCost = 0.00;
		long numPizza = 0;
		boolean mainLoopControl = true;
		//final double seniorDiscount = 0.10;
		boolean miniLoopControl = true;
		
		miniLoopControl = true;
		do {
			try {
				inputBuffer = keyboardInput.readString("Would you like to order a pizza(y/n)?: ");
				switch (inputBuffer.toUpperCase().charAt(0)) {
					case 'Y':
						miniLoopControl = false;
						mainLoopControl = true;
						break;
					case 'N':
						miniLoopControl = false;
						mainLoopControl = false;
						break;
					default:
						System.out.println("Invalid input, try again");
						miniLoopControl = true;
						break;
				}
			} catch (StringIndexOutOfBoundsException e) {
				System.out.println("Invalid input, try again");
				miniLoopControl = true;
			}
		} while (miniLoopControl);
		while (mainLoopControl) {
			int choice = menu();
			//pizzaBuilderObj = new PizzaBuilder();
			
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
				try {
					inputBuffer = keyboardInput.readString("Are you eligable for the senior discount? (y/n): ");
					switch (inputBuffer.toUpperCase().charAt(0)) {
						case 'Y':
							seniorLoopContinue = false;
							pizzaBuilderObj.addDiscount("Senior-Discount", (double) 0.10);
							break;
						case 'N':
							seniorLoopContinue = false;
							break;
						default:
							System.out.println("Invalid input, try again");
							seniorLoopContinue = true;
							break;
					}
				} catch (StringIndexOutOfBoundsException e) {
					System.out.println("Invalid input, try again");
					seniorLoopContinue = true;
				}
			} while (seniorLoopContinue);
			
			
			
			
			
			
			
			
			
			
			
			
			

			boolean deliverLoopContinue = true;
			do {
				try {
					inputBuffer = keyboardInput.readString("Would you like the pizza delivered for $2.50? (y/n): ");
					switch (inputBuffer.toUpperCase().charAt(0)) {
						case 'Y':
							deliverLoopContinue = false;
							pizzaBuilderObj.addFee("Delivery charge", (double) 2.50);
							break;
						case 'N':
							deliverLoopContinue = false;
							break;
						default:
							System.out.println("Invalid input, try again");
							deliverLoopContinue = true;
							break;
					}
				} catch (StringIndexOutOfBoundsException e) {
					System.out.println("Invalid input, try again");
					deliverLoopContinue = true;
				}
			} while (deliverLoopContinue);
			
			System.out.println("Pizza: \n");
			decPizza = pizzaBuilderObj.pizzaDone();
			showOrder(decPizza);
			totalCost += decPizza.pizzaCost();
			++numPizza;
			System.out.println("Cost of the pizza: $" + doubleF.format(decPizza.pizzaCost()));
			System.out.println("Your total so far is : $" + doubleF.format(totalCost));
			
			
			

			
			miniLoopControl = true;
			do {
				try {
					inputBuffer = keyboardInput.readString("Would you like to order a pizza(y/n)?: ");
					switch (inputBuffer.toUpperCase().charAt(0)) {
						case 'Y':
							miniLoopControl = false;
							mainLoopControl = true;
							break;
						case 'N':
							miniLoopControl = false;
							mainLoopControl = false;
							break;
						default:
							System.out.println("Invalid input, try again");
							miniLoopControl = true;
							break;
					}
				} catch (StringIndexOutOfBoundsException e) {
					System.out.println("Invalid input, try again");
					miniLoopControl = true;
				}
			} while (miniLoopControl);
		}
		
		System.out.println("You ordered: " + numPizza + " Pizza(s)");
		System.out.println("Your total price: $" + doubleF.format(totalCost));
	}
}
