package pizza;

public class Onions extends DecoratedPizza {
	Onions (DecoratedPizza next_pizza_item){
		super(next_pizza_item);
	}

	public double pizzaCost() {
		return super.pizzaCost() + 0.79;
	}
	public String toString() {
		return " Onions" + super.toString();
	}
	public String getImage () {
		String buffer = new String();
		return buffer + "FIX ME";
	}
}
