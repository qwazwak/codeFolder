//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

public abstract class DecoratedPizza {
	private DecoratedPizza next_pizza_item;
	
	DecoratedPizza(){
		next_pizza_item = null;
	}
	DecoratedPizza(DecoratedPizza nextPizza){
		next_pizza_item = nextPizza;
	}
	
	public double pizzaCost() {
		return next_pizza_item.pizzaCost();
	}
	public String toString() {
		return next_pizza_item.toString();
	}
	public String getImage(){
		return next_pizza_item.getImage();
	}
	
	
}
