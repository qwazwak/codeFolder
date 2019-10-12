//CSC2310 Object Oriented Programming
//Project 01 Rustan Hoffman

package pizza;

public class Pizza extends DecoratedPizza {
	private Crust crustObj;
	
	Pizza(Crust newCrustObj){
		super();
		crustObj = newCrustObj;
	}
	
	public double pizzaCost() {
		return crustObj.crustCost();
	}
	public String toString() {
		return crustObj.toString();
	}
	public String getImage () {
		return crustObj.getImage();
	}
	
	
}
