

import java.util.ArrayList;
import java.util.Iterator;

public class StudentIterator implements Iterator<Student>{

	private Student[] shapes;
	int pos;
	
	public StudentIterator(ArrayList<Student> container){
		shapes = new Student[container.size()];
		for(int i = 0; i < container.size(); ++i) {
			shapes[i] = container.get(i);
		}
	}
	@Override
	public boolean hasNext() {
		if(pos >= shapes.length || shapes[pos] == null)
			return false;
		return true;
	}

	@Override
	public Student next() {
		return shapes[pos++];
	}

	@Override
	public void remove() {
		if(pos <=0 )
			throw new IllegalStateException("Illegal position");
		if(shapes[pos-1] !=null){
			for (int i= pos-1; i<(shapes.length-1);i++){
				shapes[i] = shapes[i+1];
			}
			shapes[shapes.length-1] = null;
		}
	}
}
