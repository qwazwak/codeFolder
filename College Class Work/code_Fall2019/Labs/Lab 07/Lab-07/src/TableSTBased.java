import java.util.Iterator;

public class TableSTBased implements TableInterface {
	private SearchTreeInterface st; // binary search tree that contains the table’s items
	private int size; // number of items in the table

	public TableSTBased() {
		st = new AdaptableBinarySearchTree(); // duplicates not allowed with this constructor
		size = 0;
	}

	public boolean tableIsEmpty() {
		return !(size > 0);
	}

	public int tableSize() {
		return size;
	}

	public KeyedItem tableRetrieve(Comparable searchKey) {

	}

	public void tableInsert(KeyedItem item) throws TableException {
		boolean success;
		try {
			st.insert(item);
			size++;
		}
		catch(TreeException e) {
			
		}
		
	}

	public boolean tableDelete(Comparable searchKey) {
		boolean success;
		try {
			st.delete(searchKey);
			success = true;
			size--;
		}
		catch(TreeException e) {
			success = false;
			
		}
		return success;
	}

	public Iterator iterator() {
		TreeIterator iter = st.iterator();
		// do your specific iterator traversal call here
		// do your specific iterator traversal call here

	}
}
