import java.util.ArrayList;
import java.util.List;

public class square {
	static List<Long> possibleValues = new ArrayList<>();
	private static boolean isSquareFinalValue = false;
	

	public static void setup (){
		possibleValues.add((long)1);
		possibleValues.add((long)2);
		possibleValues.add((long)3);
		possibleValues.add((long)4);
		possibleValues.add((long)5);
		possibleValues.add((long)6);
		possibleValues.add((long)7);
		possibleValues.add((long)8);
		possibleValues.add((long)9);
		isSquareFinalValue = false;	
	}
	
	
	public List<Long> getValues (){
		return possibleValues;
	}
	
	boolean isFinal() {
		return isSquareFinalValue;
	}
	
	public void setValue(long newValue) {
		while(!possibleValues.isEmpty()) {
			possibleValues.remove(0);
		}
		possibleValues.add((long)newValue);
		isSquareFinalValue = true;
	}
	
	
	//Attempts to solve this square (and in doing so CAN (not for sure) solve all other squares)
	//If it can it returns true
	public boolean floodSolve() {
		if(this.isFinal()) {
			return true;
		}
		
		
		
		return this.isFinal();
	}
	
	
	
}
