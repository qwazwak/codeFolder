//Rustan Hoffman and Rebecca Damewood
public class IceCreamCone
{
	private double priceCream;
	private double priceCone;
	private String creamInfo;
	private String coneInfo;
	
	public IceCreamCone(IceCream c1, Cone c2)
	{
	  this.priceCream = c1.getPrice();
	  this.priceCone = c2.getPrice();
	  this.creamInfo = c1.toString();
	  this.coneInfo = c2.toString();
	}
	public double getPrice()
	{
		return 1.99 + priceCream + priceCone;
	}
	public String toString()
	{
		return new String(creamInfo + " " + coneInfo);
	}
}