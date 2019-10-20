import queue.*;

class BinaryTreeIterator implements TreeIterator {
	private TreeNode root;
	private QueueInterface globalQ; //global queue      
	
	public BinaryTreeIterator(TreeNode root) {
		this.root = root;
		globalQ = new QueueLinked();
	}
	
	public boolean hasNext() {
		return !globalQ.isEmpty();
	}
	
	public Object next() throws TreeException {
		try {
			return globalQ.dequeue();
		} catch (QueueException e) {
			throw new TreeException("End of tree traversal.");
		}
	}
	
	public void remove() throws UnsupportedOperationException {
		throw new UnsupportedOperationException();
	}
	
	public void setPreorder() {
		globalQ.dequeueAll();
		preorder(root);
	}
	
	public void setInorder() {
		globalQ.dequeueAll();
		inorder(root);
	}
	
	public void setPostorder() {
		globalQ.dequeueAll();
		postorder(root);
	}
	
	private void preorder(TreeNode tNode) {
		if (tNode != null) {
			globalQ.enqueue(tNode.getItem());
			preorder(tNode.getLeft());
			preorder(tNode.getRight());
		}
	}
	
	private void inorder(TreeNode tNode) {
		if (tNode != null) {
			inorder(tNode.getLeft());
			globalQ.enqueue(tNode.getItem());
			inorder(tNode.getRight());
		}
	}
	
	private void postorder(TreeNode tNode) {
		if (tNode != null) {
			postorder(tNode.getLeft());
			postorder(tNode.getRight());
			globalQ.enqueue(tNode.getItem());
		}
	}
	
	
	
	public void setLevelorder() {
		if (root != null) {
			QueueInterface<TreeNode> miniQ = new QueueLinked<TreeNode>(); //local queue
			miniQ.enqueue(root);
			TreeNode currentNode;
			
			while (!miniQ.isEmpty()) {
				currentNode = miniQ.dequeue();
				globalQ.enqueue(currentNode.getItem());
				if (currentNode.getLeft() != null) {
					miniQ.enqueue(currentNode.getLeft());
				}
				if (currentNode.getRight() != null) {
					miniQ.enqueue(currentNode.getRight());
				}
				
				
				
				
				
			}
		}
	}
}
