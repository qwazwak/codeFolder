package pizza;

public class Sausage extends DecoratedPizza {
	Sausage (DecoratedPizza next_pizza_item){
		super(next_pizza_item);
	}

	public double pizzaCost() {
		return super.pizzaCost() + 0.99;
	}
	public String toString() {
		return super.toString() + " Sausage";
	}
	public String getImage () {
		return super.getImage() + "S";
	}
}
