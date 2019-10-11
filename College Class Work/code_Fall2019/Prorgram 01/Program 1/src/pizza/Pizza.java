package pizza;

public class Pizza extends DecoratedPizza {
	private Crust crustObj;
	
	Pizza(Crust newCrustObj){
		super();
		crustObj = newCrustObj;
		System.out.println(crustObj);
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
