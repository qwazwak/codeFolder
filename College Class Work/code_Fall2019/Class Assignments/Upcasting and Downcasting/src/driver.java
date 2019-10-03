//By Rustan Hoffman


public class driver {
	
	public static void changeWater(Fish theObj) {
		theObj.life += theObj.life > 100 ? 0 : 1;
	}
	
	public static void feed(Animal theObj) {
		theObj.life += theObj.life > 100 ? 0 : 5;
	}
	
	public static void giveMilk(Cat theObj) {
		theObj.life += theObj.life > 100 ? 0 : 10;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cat theCat = new Cat();
		Fish theFish = new Fish();
		
		//cannot be done because allthough they are derived from the same superclass, they are different.
		//Fish anotherFish = new Cat();
		
		
		
		//Works, because theFish (instance of a Fish) is implicitly upcasted to Animal
		feed(theFish);


		Animal anAnimal = new Cat();
	
		//Does not work, because while WE know anAnimal is an instance of Cat, the program does not know.
		//giveMilk(anAnimal);
		//It can be done by downcasting it:
		giveMilk((Cat) anAnimal);
		
		
		
		
	
	}

}
