package headfirst.designpatterns.decorator.starbuzz;
 
public class Salt extends CondimentDecorator {
	Beverage beverage;
 
	public Salt(Beverage beverage) {
		this.beverage = beverage;
	}
 
	public String getDescription() {
		return this.beverage.getDescription() + ", Salt";
	}
 
	public double cost() {
		return ((double)0.05) + this.beverage.cost();
	}
}
