
public enum CrustSize {
	S(5.99), M(7.99), L(9.99);
	private double price;
	
	private CrustSize(double price) {
		this.price = price;
	}
	
	public double cost() {
		return this.price;
	}
}