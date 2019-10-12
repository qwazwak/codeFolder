//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

public class Pizza_Special_Hawaiian extends PizzaBuilder {
	
	Pizza_Special_Hawaiian(){
		super();
	}

	
	public void buildPizza() {
		super.buildPizza();
		super.addTopping('P');
		super.addTopping('H');
		
	}
	
}
