//Rustan Hoffman


public class AdaptableBinarySearchTree extends BinarySearchTree {
	
	public AdaptableBinarySearchTree() {
		super();
	}
	
	public KeyedItem retrieve(Comparable searchKey) {
		try {
			KeyedItem returnMe = (KeyedItem) (retrieveItemAdapt(super.getRootNode(), searchKey)).getItem();

			if(returnMe == null) {				
				throw new TreeException("Could not find searchKey in tree");
			}
			return returnMe;
		}
		catch(TreeException e) {
			return null;
		}
	}
	
	protected TreeNode retrieveItemAdapt(TreeNode tNode, Comparable searchKey) {
		
		if (tNode == null) {
			throw new TreeException("Could not find searchKey in tree");
		} else {
			KeyedItem nodeItem = (KeyedItem) tNode.getItem();
			int comparison = searchKey.compareTo(nodeItem.getKey());
			
			if (comparison == 0) {
				//item is in the root of some subtree
				//this item will be moved up one level each time it is retrieved
				//the principal of temporal (spatial?) locality of data (retrieved once, likely to be retrieved again)
				return tNode;
				
			} else if (comparison < 0) {
				if(tNode.getRight() == null) {
					throw new TreeException("Could not find searchKey in tree");
				}
				//search the left subtree
				//make sure to set your new left subtree
				//System.out.println("left: " + tNode);
				tNode = rotateLeft(tNode);
				
				
			} else {
				if(tNode.getLeft() == null) {
					throw new TreeException("Could not find searchKey in tree");
				}
				//search the right subtree
				//make sure to set your new right subtree 
				//System.out.println("Right: " + tNode);
				tNode = rotateRight(tNode);
			}
			tNode = retrieveItemAdapt(tNode, searchKey);
		}
		return tNode;
	}
	
}
