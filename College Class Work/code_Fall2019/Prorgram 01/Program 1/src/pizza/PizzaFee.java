//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

public class PizzaFee extends DecoratedPizza{
	private String message;
	private double f;
	
	PizzaFee(DecoratedPizza decPizzaObj, String message, double f){
		super(decPizzaObj);
		this.message = message;
		this.f = f;
	}
	
	public String toString() {
		return super.toString() + message;
	}
	
	public double pizzaCost() {
		return super.pizzaCost() + f;
	}
}
