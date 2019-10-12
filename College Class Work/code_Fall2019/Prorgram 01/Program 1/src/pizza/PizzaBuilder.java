//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

public class PizzaBuilder {
	private Crust crust;
	private DecoratedPizza topLink;
	char crust_size;
	String crust_type;
	
	PizzaBuilder() {
		crust_size = 'S';
		crust_type = "THIN";
		crust = new Crust(crust_type, crust_size);
		topLink = new Pizza(crust);
	}
	
	public boolean setSize(char size) {
		if (size == 'S' || size == 's' || size == 'M' || size == 'm' || size == 'L' || size == 'l') {
			crust_size = size;
			buildPizza();
			return true;
		}
		return false;
	}
	
	protected void buildPizza() {
		crust = new Crust(crust_type, crust_size);
		topLink = new Pizza(crust);
	}
	
	public boolean setCrust(String theCrust) {
		if (theCrust.toUpperCase().equals("THIN") || theCrust.toUpperCase().equals("PAN") || theCrust.toUpperCase().equals("HAND")) {
			crust_type = theCrust;
			buildPizza();
			return true;
		} else {
			return false;
		}
		
	}
	
	public void addTopping(char topChar) {
		if (!(topLink instanceof Pizza || topLink instanceof PizzaTopping)) {
			return;
		}
		switch (topChar) {
			case 'P':
				topLink = PizzaToppingFactory.addPepperoni(topLink);
				break;
			case 'S':
				topLink = PizzaToppingFactory.addSausage(topLink);
				break;
			case 'O':
				topLink = PizzaToppingFactory.addOnions(topLink);
				break;
			case 'G':
				topLink = PizzaToppingFactory.addGreenpeppers(topLink);
				break;
			case 'M':
				topLink = PizzaToppingFactory.addMushrooms(topLink);
				break;
			case 'H':
				topLink = PizzaToppingFactory.addHam(topLink);
				break;
			case 'A':
				topLink = PizzaToppingFactory.addPineapple(topLink);
				break;
		}
	}
	
	
	public void addDiscount(String message, double amount) {
		if (!(topLink instanceof Pizza || topLink instanceof PizzaTopping || topLink instanceof PizzaDiscount))
			return;
		topLink = new PizzaDiscount(topLink, message, amount);
	}
	
	
	public void addFee(String message, double amount) {
		topLink = new PizzaFee(topLink, message, amount);
	}
	
	public DecoratedPizza pizzaDone() {
		DecoratedPizza doneObj = topLink;
		crust_size = 'S';
		crust_type = "THIN";
		buildPizza();
		return doneObj;
	}
	
}
