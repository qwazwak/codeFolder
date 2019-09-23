package headfirst.designpatterns.factory.pizzaaf;

public class PlainPizza extends Pizza {
	PizzaIngredientFactory ingredientFactory;
 
	public PlainPizza(PizzaIngredientFactory ingredientFactory) {
		this.ingredientFactory = ingredientFactory;
	}
 
	void prepare() {
		System.out.println("Preparing " + name);
		dough = ingredientFactory.createDough();
		sauce = ingredientFactory.createSauce();
		cheese = ingredientFactory.createCheese();
	}
}
