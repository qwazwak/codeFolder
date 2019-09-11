package qCode;

public abstract class BodgeArray<T> {
	private long currentCapacity;
	private long currentDataCount;
	private T[] theArray;
	
	public BodgeArray(){
		theArray = (T[])new Object[1];

		currentDataCount = 0;
		currentCapacity = 0;
	}
	
	public long getSize() {
		return this.currentDataCount;
	}
}
