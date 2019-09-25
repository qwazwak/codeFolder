
public enum CrustType {
	THIN(0.00), HAND(0.50), PAN(1.00);
	private double price;
	
	private CrustType(double price) {
		this.price = price;
	}
	
	public double cost() {
		return this.price;
	}
}