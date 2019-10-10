package pizza;

public class Pepperoni extends DecoratedPizza {
	Pepperoni (DecoratedPizza next_pizza_item){
		super(next_pizza_item);
	}

	public double pizzaCost() {
		return super.pizzaCost() + 0.99;
	}
	public String toString() {
		return " Pepperoni" + super.toString();
	}
	public String getImage () {
		String buffer = new String();
		return buffer + "FIX ME";
	}
}
