//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

public class PizzaToppingFactory {
	
	public static DecoratedPizza addPepperoni(DecoratedPizza dec_pizza) {
		return new PizzaTopping(dec_pizza, "pepperoni\n", "P", 0.99);
	}
	
	public static DecoratedPizza addSausage(DecoratedPizza dec_pizza) {
		return new PizzaTopping(dec_pizza, "sausage\n", "S", 0.99);
	}
	
	public static DecoratedPizza addOnions(DecoratedPizza dec_pizza) {
		return new PizzaTopping(dec_pizza, "onions\n", "O", 0.79);
	}
	
	public static DecoratedPizza addGreenpeppers(DecoratedPizza dec_pizza) {
		return new PizzaTopping(dec_pizza, "greenpeppers\n", "G", 0.69);
	}
	
	public static DecoratedPizza addMushrooms(DecoratedPizza dec_pizza) {
		return new PizzaTopping(dec_pizza, "mushrooms\n", "M", 0.79);
	}
	
	public static DecoratedPizza addHam(DecoratedPizza dec_pizza) {
		return new PizzaTopping(dec_pizza, "ham\n", "H", 0.89);
	}
	
	public static DecoratedPizza addPineapple(DecoratedPizza dec_pizza) {
		return new PizzaTopping(dec_pizza, "pineapple\n", "A", 0.89);
	}
	
}
