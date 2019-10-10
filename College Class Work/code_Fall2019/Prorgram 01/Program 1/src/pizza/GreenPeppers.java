package pizza;

public class GreenPeppers extends DecoratedPizza {
	GreenPeppers (DecoratedPizza next_pizza_item){
		super(next_pizza_item);
	}

	public double pizzaCost() {
		return super.pizzaCost() + 0.69;
	}
	public String toString() {
		return " GreenPeppers" + super.toString();
	}
	public String getImage () {
		String buffer = new String();
		return buffer + "FIX ME";
	}
}
