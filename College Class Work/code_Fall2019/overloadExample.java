/*
 * By Rustan Hoffman
 * September 7th 2019
 */
import java.util.Random;
import java.time.Instant;

public class overloadExample {

	static class classThatHoldsData {
		int aNumber;

		int getNumber() {
			return aNumber;
		}

		void setNumber(int newNumber) {
			aNumber = newNumber;
		}

		classThatHoldsData() {
			aNumber = 0;
		};

		classThatHoldsData(int startingNumber) {
			aNumber = startingNumber;
		};

		classThatHoldsData(classThatHoldsData copyfrom) {
			aNumber = copyfrom.getNumber();
		};

	}

	public static void main(String[] args) {
		long seed = Instant.now().getEpochSecond() * Instant.now().getEpochSecond();
		//System.out.println("seed: " + seed);
		Random rand = new Random(seed);

		classThatHoldsData exA = new classThatHoldsData();
		classThatHoldsData exB = new classThatHoldsData(rand.nextInt());
		classThatHoldsData exC = new classThatHoldsData(exB);
		System.out.println("Base case:");
		System.out.println("exA: " + exA.getNumber());
		System.out.println("Number set on creation:");
		System.out.println("exB: " + exB.getNumber());
		System.out.println("All of class copied from another instance of the class:");
		System.out.println("exC: " + exC.getNumber());

	}
}
