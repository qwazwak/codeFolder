package pizza;

public abstract class DecoratedPizza {
	private DecoratedPizza next_pizza_item;
	
	DecoratedPizza(){
		next_pizza_item = null;
	}
	DecoratedPizza(DecoratedPizza nextPizza){
		System.out.println(nextPizza);
		next_pizza_item = nextPizza;
	}
	
	public double pizzaCost() {
		return next_pizza_item.pizzaCost();
	}
	public String toString() {
		System.out.println(next_pizza_item);
		return next_pizza_item.toString();
	}
	public String getImage(){
		return next_pizza_item.getImage();
	}
	
	
}
