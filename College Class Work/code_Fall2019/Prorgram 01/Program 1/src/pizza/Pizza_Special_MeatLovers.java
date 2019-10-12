//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

public class Pizza_Special_MeatLovers extends PizzaBuilder {
	
	Pizza_Special_MeatLovers(){
		super();
	}

	
	public void buildPizza() {
		super.buildPizza();
		super.addTopping('H');
		super.addTopping('P');
		super.addTopping('S');
		
	}
	
}
