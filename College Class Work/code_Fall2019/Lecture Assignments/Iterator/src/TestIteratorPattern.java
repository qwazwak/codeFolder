

public class TestIteratorPattern {

	public static void main(String[] args) {
		ClassRoom storage = new ClassRoom();
 		storage.addStudent("Polygon");
		storage.addStudent("Hexagon");
		storage.addStudent("Circle");
		storage.addStudent("Rectangle");
		storage.addStudent("Square");
		
		StudentIterator iterator = new StudentIterator(storage.getShapes());
		while(iterator.hasNext()){
			System.out.println(iterator.next());
		}
		System.out.println("Apply removing while iterating...");
		iterator = new StudentIterator(storage.getShapes());
		while(iterator.hasNext()){
			System.out.println(iterator.next());
			iterator.remove();
		}
	}

}
