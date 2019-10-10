package pizza;

public class Sausage extends DecoratedPizza {
	Sausage (DecoratedPizza next_pizza_item){
		super(next_pizza_item);
	}

	public double pizzaCost() {
		return super.pizzaCost() + 0.99;
	}
	public String toString() {
		return " Sausage" + super.toString();
	}
	public String getImage () {
		String buffer = new String();
		return buffer + "FIX ME";
	}
}
