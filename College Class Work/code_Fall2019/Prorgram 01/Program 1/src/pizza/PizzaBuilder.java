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
			return true;
		}
		return false;
	}
	
	protected void buildPizza() {
		crust = new Crust(crust_type, crust_size);
		topLink = new Pizza(crust);
	}
	
	public boolean setCrust(String theCrust) {
		switch (theCrust) {
			case "THIN":
			case "HAND":
			case "PAN":
				crust_type = theCrust;
				return true;
			default:
				return false;
		}
		
	}
	
	public void addTopping(char topChar) {
		if (!(topLink instanceof Pizza || topLink instanceof PizzaTopping))
			return;
		switch (topChar) {
			case 'P':
				PizzaToppingFactory.addPepperoni(topLink);
				break;
			case 'S':
				PizzaToppingFactory.addSausage(topLink);
				break;
			case 'O':
				PizzaToppingFactory.addOnions(topLink);
				break;
			case 'G':
				PizzaToppingFactory.addGreenpeppers(topLink);
				break;
			case 'M':
				PizzaToppingFactory.addMushrooms(topLink);
				break;
		}
	}
	
	
	public void addDiscount(String message, double amount) {
		if(!(topLink instanceof Pizza ||topLink instanceof PizzaTopping ||topLink instanceof PizzaDiscount))
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
