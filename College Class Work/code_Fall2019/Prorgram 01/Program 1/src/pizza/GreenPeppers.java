package pizza;

public class GreenPeppers extends DecoratedPizza {
	GreenPeppers (DecoratedPizza next_pizza_item){
		super(next_pizza_item);
	}

	public double pizzaCost() {
		return super.pizzaCost() + 0.69;
	}
	public String toString() {
		return  super.toString() + " GreenPeppers";
	}
	public String getImage () {
		return super.getImage() + "G";
	}
}
