package pizza;

public class Pizza extends DecoratedPizza {
	private Crust crustObj;
	
	Pizza(Crust newCrustObj){
		super();
		crustObj = newCrustObj;
	}
	
	public double pizzaCost() {
		return crustObj.crustCost() + super.pizzaCost();
	}
	public String toString() {
		return crustObj.toString() + super.toString();
	}
	public String getImage () {
		String buffer = new String();
		return buffer + crustObj.getSize() + super.getImage();
	}
	
	
}
