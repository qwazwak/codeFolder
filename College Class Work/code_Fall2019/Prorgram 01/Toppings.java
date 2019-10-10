
public class Toppings extends DecoratedPizza {
	Toppings (DecoratedPizza next_pizza_item){
		super(next_pizza_item);
		this.next_pizza_item = next_pizza_item;
	}

	public double pizzaCost() {
		return next_pizza_item.pizzaCost() + 00.00;
	}
	public String toString() {
		return "text" + next_pizza_item.toString();
	}
	public String getImage () {
		String buffer = new String();
		return buffer + "FIX ME";
	}
}
