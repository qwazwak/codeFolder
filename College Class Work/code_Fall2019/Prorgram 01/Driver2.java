package pizza;
//Rustan Hoffman

import util.Keyboard;

public class Driver2 {
	static Keyboard input = Keyboard.getKeyboard();
	//Scanner keyboard = new Scanner(System.in);
	//Driver(){
		//int myint = keyboard.nextInt();
		
	//}
	
	 //show the menu choices, wait for and return the valid selection
	private static int menu() {
		System.out.println("");
		System.out.println("1. ");
		System.out.println("2. ");
		System.out.println("");
		System.out.println("");
		input.readInt("");
	}
	
	//request the crust size, wait for a valid response confirmation from PizzaBuilder
	private static void requestSize(PizzaBuilder pizza_builder) {
	
	}
	
	
	//request the crust type, wait for a valid response confirmation from PizzaBuilder
	private  static  void  requestCrust(PizzaBuilder  pizza_builder) {
		
	}
	
	//ask for toppings until Done indicated (invalid toppings are ignored)
	private static void requestToppings(PizzaBuilder pizza_builder) {
		
	}
	
	//display the pizza and its total cost
	private static void showOrder(DecoratedPizza dec_pizza) {
		
	}
	
	
	//allow the user to order multiple pizzas if desired, call the other methods, track total cost and number of pizzas
	public static void main(String[] args) {
		double runningTotal = 0;
		long numberOfObjectsOrdered = 0;
		final String no = new String("n");
		String inputBuffer;
		boolean shouldContinue = true;
		
		do {

			//Ask options
			
			
			//create object and increase 
			++numberOfObjectsOrdered;

			System.out.println("");
			System.out.println("Your order:");
			//print out the object

			System.out.println("");
			inputBuffer = input.readString("Would you like to order an ice cream cone? (y/n)");
			while(!(input.equals("y") || input.equals("n"))) {
				System.out.println("Invalid input");
				inputBuffer = input.readString("Would you like to order an ice cream cone? (y/n)");
			}
			if(no.equals(inputBuffer)) {
				shouldContinue = false;
			}
		}while(shouldContinue);
		
		System.out.println("Your total order for " + numberOfObjectsOrdered + " orders is $" + runningTotal);
	}
	
	
	
}
