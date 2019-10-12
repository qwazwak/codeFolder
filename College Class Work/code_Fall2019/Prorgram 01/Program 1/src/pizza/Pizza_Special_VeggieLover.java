//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

public class Pizza_Special_VeggieLover extends PizzaBuilder {
	
	Pizza_Special_VeggieLover(){
		super();
	}

	
	public void buildPizza() {
		super.buildPizza();
		super.addTopping('O');
		super.addTopping('G');
		super.addTopping('M');
		
	}
	
}
