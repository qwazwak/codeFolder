//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

public class PizzaDiscount extends DecoratedPizza{
	private String message;
	private double dis;
	
	PizzaDiscount(DecoratedPizza decPizzaObj, String message, double f){
		super(decPizzaObj);
		this.message = message;
		this.dis = f;
	}
	
	public String toString() {
		return super.toString() + message;
	}
	
	public double pizzaCost() {
		return super.pizzaCost() * ( 1 - dis);
	}
}
