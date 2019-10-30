import java.util.ArrayList;

public class ClassRoom {
	private ArrayList<Student> container = new ArrayList<Student>();
	private int index;
	
	public void addStudent(String name){
		int i = index++;
		container.add(new Student(i, name));
	}
	
	public ArrayList<Student> getShapes(){
		return container;
	}
}
