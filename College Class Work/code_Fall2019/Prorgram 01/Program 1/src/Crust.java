/*
Write a Crust class with a
constructor that accepts and sets the crust size and type and provide a crustCost method.
Write a toString method to report the state of the crust. Write getCrust (returns "THIN", "HAND", or "PAN") and getSize (returns a char 'S', 'M', or 'L'). 
Toppings 
 */

public class Crust {
	CrustSize theSize;
	CrustType theType;
	
	public Crust (){
		
	}
	
	
	public double getCost() {
		return theSize + theType.cost();
	}
	
}
