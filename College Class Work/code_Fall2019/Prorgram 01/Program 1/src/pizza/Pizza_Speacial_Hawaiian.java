package pizza;

public class Pizza_Speacial_Hawaiian extends PizzaBuilder {
	
	Pizza_Speacial_Hawaiian(){
		super();
	}

	
	public void buildPizza() {
		super.buildPizza();
		super.setCrust("THIN");
		super.addTopping('P');
		super.addTopping('H');
		
	}
	
}
