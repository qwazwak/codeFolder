package pizza;

public class Pizza_Speacial_VeggieLover extends PizzaBuilder {
	
	Pizza_Speacial_VeggieLover(){
		super();
	}

	
	public void buildPizza() {
		super.buildPizza();
		super.setCrust("THIN");
		super.addTopping('O');
		super.addTopping('G');
		super.addTopping('M');
		
	}
	
}
