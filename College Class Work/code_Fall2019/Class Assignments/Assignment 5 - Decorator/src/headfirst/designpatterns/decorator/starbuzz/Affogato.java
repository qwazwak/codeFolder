package headfirst.designpatterns.decorator.starbuzz;
 
public class Affogato extends CondimentDecorator {
	Beverage beverage;
 
	public Affogato(Beverage beverage) {
		this.beverage = beverage;
	}
 
	public String getDescription() {
		return this.beverage.getDescription() + ", Affogato";
	}
 
	public double cost() {
		return ((double)1.50) + this.beverage.cost();
	}
}
