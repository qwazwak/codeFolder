package pizza;

public class PizzaTopping extends DecoratedPizza {
	
	private String topping;
	private String letter;
	private double cost;
	
	PizzaTopping(DecoratedPizza obj, String strAlpha, String strBeta, double cost) {
		super(obj);
		topping = strAlpha;
		letter = strBeta.toUpperCase().substring(0, 0);
		this.cost = cost;
	}
	
	
	public double pizzaCost() {
		return super.pizzaCost() + cost;
	}
	
	public String toString() {
		return " " + topping + super.toString();
	}
	
	public String getImage() {
		return super.getImage() + letter.toUpperCase().charAt(0);
	}
	
}
