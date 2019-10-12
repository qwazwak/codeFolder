//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

public class Mushrooms extends DecoratedPizza {
	Mushrooms (DecoratedPizza next_pizza_item){
		super(next_pizza_item);
	}

	public double pizzaCost() {
		return super.pizzaCost() + 0.79;
	}
	public String toString() {
		return super.toString() + " Mushrooms";
	}
	public String getImage () {
		return super.getImage() + "M";
	}
}
