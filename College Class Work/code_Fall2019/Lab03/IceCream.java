//Rustan Hoffman and Rebecca Damewood

public class IceCream {
	private int numberOfScoops;
  private Flavor theFlavor;
  private Topping theToppings;


	public IceCream(int scoopCountSetup, Flavor theNewFlavor, Topping theNewTopping){
    if(scoopCountSetup < 1 ){
      this.numberOfScoops = 1;
    }
    else
      if(scoopCountSetup > 3 ){
        this.numberOfScoops = 3;
      }
      else{
        this.numberOfScoops = scoopCountSetup;
      }
      this.theFlavor = theNewFlavor;
      this.theToppings = theNewTopping;
  }
  public double getPrice(){
    return (numberOfScoops * (double)0.75) + (theToppings.price());
  }

  public String toString(){
    return new String(numberOfScoops + " scoops of " + theFlavor + ", with " + theToppings);
  }
}
