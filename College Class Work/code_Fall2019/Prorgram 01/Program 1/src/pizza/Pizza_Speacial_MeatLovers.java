package pizza;

public class Pizza_Speacial_MeatLovers extends PizzaBuilder {
	
	Pizza_Speacial_MeatLovers(){
		super();
	}

	
	public void buildPizza() {
		super.buildPizza();
		super.setCrust("THIN");
		super.addTopping('H');
		super.addTopping('P');
		
	}
	
}
