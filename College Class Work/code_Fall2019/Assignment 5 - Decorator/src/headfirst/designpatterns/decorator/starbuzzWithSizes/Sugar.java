package headfirst.designpatterns.decorator.starbuzzWithSizes;
 
public class Sugar extends CondimentDecorator {
	Beverage beverage;
 
	public Sugar(Beverage beverage) {
		this.beverage = beverage;
	}
 
	public String getDescription() {
		return this.beverage.getDescription() + ", Sugar";
	}
 
	public double cost() {
		return ((double)0.25) + this.beverage.cost();
	}
}
